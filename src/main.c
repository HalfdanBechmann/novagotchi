/***************************************************************************//**
 * @file main.c
 * @brief Novagotchi main file
 ******************************************************************************/

// Memcopy
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// EMlib
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_letimer.h"
#include "em_prs.h"
#include "em_cryotimer.h"
#include "em_adc.h"
//#include "em_rtcc.h"

// Configuration
#include "pinout.h"
#include "display.h"

// Display Drivers
#include "dmd.h"
#include "glib.h"

// Graphics
#include "graphics/dog.h"
#include "graphics/dog_dead.h"
#include "graphics/garden.h"
#include "graphics/heart.h"

// ADC defines
#define microvoltsPerStep 1221 // 1322
#define VINATT(ATT_FACTOR) ATT_FACTOR << _ADC_SINGLECTRLX_VINATT_SHIFT
#define VREFATT(ATT_FACTOR)ATT_FACTOR << _ADC_SINGLECTRLX_VREFATT_SHIFT

// Initial power-on state
#define INIT_POS                 10
#define INIT_LOVE                 2

// Limits
#define MAX_LOVE				  5
#define MAX_STR_LEN               48

#define DOG_POS_X_MIN            0
#define DOG_POS_X_MAX            15

//#define TEST

#ifdef TEST
#define HEART0_VAL              1
#define HEART1_VAL              1
#define HEART2_VAL              1
#define HEART3_VAL              1
#define HEART4_VAL              1
#define HEART5_VAL              1
#else
#define HEART0_VAL              2000
#define HEART1_VAL              1000
#define HEART2_VAL              500
#define HEART3_VAL              200
#define HEART4_VAL              100
#define HEART5_VAL              20
#endif

/* Center of display */

#define CENTER_X                  (glibContext.pDisplayGeometry->xSize / 2)
#define CENTER_Y                  (glibContext.pDisplayGeometry->ySize / 2)

#define MAX_X                     (glibContext.pDisplayGeometry->xSize - 1)
#define MAX_Y                     (glibContext.pDisplayGeometry->ySize - 1)

#define MIN_X                     0
#define MIN_Y                     0


GLIB_Font_t bat_font;
GLIB_Font_t clk_font;

#define GLIB_FONT_WIDTH           (glibContext.font.fontWidth \
                                   + glibContext.font.charSpacing)
#define GLIB_FONT_HEIGHT          (glibContext.font.fontHeight)

#define BAT_STR_LEN                5

#define TIME_STR_LEN               5
#define HEART_POS_X               (CENTER_X - (MAX_LOVE*HEART_BITMAP_WIDTH/2))
#define CLK_POS_X                 (CENTER_X - (5*GLIB_FONT_WIDTH/2))

// State variables
static volatile uint32_t pos = INIT_POS;
static volatile uint32_t pos_prev = 0;
static volatile uint32_t love = INIT_LOVE;
static volatile uint32_t love_prev = INIT_LOVE;

static char bat_str[BAT_STR_LEN+1];
static int batteryVoltage;
static uint8_t batteryVoltagePct;

static bool str_opaque = false;
static char time_str[TIME_STR_LEN+1];
static volatile uint8_t time_h;
static volatile uint8_t time_m;

static volatile uint8_t jump = 0;

// The GLIB context
static GLIB_Context_t glibContext;

// Forward static function declarations
static void drawScreen(void);

/***************************************************************************//**
 * @brief Setup GPIO interrupt for pushbuttons.
 ******************************************************************************/
static void GpioSetup(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Configure PB0 as input and enable interrupt
  GPIO_PinModeSet(PB0_PORT, PB0_PIN, gpioModeInputPullFilter, 1);
  GPIO_IntConfig(PB0_PORT, PB0_PIN, false, true, true);

  // Configure PB1 as input and enable interrupt
  GPIO_PinModeSet(PB1_PORT, PB1_PIN, gpioModeInputPullFilter, 1);
  GPIO_IntConfig(PB1_PORT, PB1_PIN, false, true, true);

  // Configure PB2 as input and enable interrupt
  GPIO_PinModeSet(PB2_PORT, PB2_PIN, gpioModeInputPullFilter, 1);
  GPIO_IntConfig(PB2_PORT, PB2_PIN, false, true, true);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);

  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
}


void Time_Init() {
	 time_h = 2;
	 time_m = 0;
	 str_opaque = true;
	 int init_love = love;
	 int init_pos = pos;

	 while (love < init_love + 1){ // Set clock mode until first click on middle button
		 time_h += pos - init_pos;
		 pos = init_pos;
		 if (time_h > 23){
			 time_h = 23;
		 } else if (time_h < 0) {
			 time_h = 0;
		 }
		 drawScreen();
		 EMU_EnterEM2(true);
	 };
	 while (love < init_love + 2){ // Set clock mode until second click on middle button
		 time_m += pos - init_pos;

		 if (time_m > 59){
			 time_m = 59;
		 } else if (time_h < 0) {
			 time_m = 0;
		 }
		 pos = init_pos;
		 drawScreen();
		 EMU_EnterEM2(true);
	 };
	 love = INIT_LOVE;
	 str_opaque = false;
}

void Time_MinuteTick() {
	if (time_m < 59) {
		time_m++;
	} else {
		time_m = 0;
		if (time_h < 23) {
			time_h++;
		} else {
			time_h = 0;
		}
	}
}



// Health functions
static volatile uint32_t love_buffer = 0;

void addLove(){
	if (love < MAX_LOVE) {
		love++;
	}
	love_buffer = 0;
}

void removeLove(){
	if (((love == 0) && (love_buffer > HEART0_VAL)) ||
	    ((love == 1) && (love_buffer > HEART1_VAL)) ||
        ((love == 2) && (love_buffer > HEART2_VAL)) ||
	    ((love == 3) && (love_buffer > HEART3_VAL)) ||
  	    ((love == 4) && (love_buffer > HEART4_VAL)) ||
	    ((love == 5) && (love_buffer > HEART5_VAL))) {
		 	love--;
			love_buffer = 0;
		}
}


// Measure battery
void InitADCforSupplyMeasurement()
{
  ADC_Init_TypeDef ADC_Defaults =ADC_INIT_DEFAULT;

  ADC_InitSingle_TypeDef init =ADC_INITSINGLE_DEFAULT ;
  init.negSel = adcNegSelVSS;
  init.posSel = adcPosSelAVDD;
  init.reference = adcRef5V ;

  //CMU_ClockEnable(cmuClock_ADC0, true);

  /*start with defaults */
  ADC_Init(ADC0,&ADC_Defaults);

  ADC_InitSingle(ADC0, &init);
  ADC0->SINGLECTRLX = VINATT(12) | VREFATT(6);
}

int voltage2capacity(int mvolts) { // Discrete linear approximation
	if (mvolts >= 3000){
		return 100;
	} else if (mvolts > 2900) {
	    return 100 - ((3000 - mvolts) * 58) / 100;
	} else if (mvolts > 2740){
	    return 42 - ((2900 - mvolts) * 24) / 160;
	} else if (mvolts > 2440){
	    return 18 - ((2740 - mvolts) * 12) / 300;
	} else if (mvolts > 2100){
	    return 6 - ((2440 - mvolts) * 6) / 340;
	} else {
	    return 0;
	}
}

void readSupplyVoltage()
{
   unsigned int raw=0;
   unsigned int supplyVoltagemV=0;

   //CMU_ClockEnable(cmuClock_ADC0, true);
   ADC0->CMD = ADC_CMD_SINGLESTART;
   /* wait for conversion to complete.*/

   while (!(ADC0->STATUS & (ADC_STATUS_SINGLEDV | ADC_STATUS_SINGLEACT)));
   raw = ADC0->SINGLEDATA;

   //CMU_ClockEnable(cmuClock_ADC0, false);

   supplyVoltagemV = raw*microvoltsPerStep/1000UL;

   batteryVoltage = supplyVoltagemV;

   batteryVoltagePct = voltage2capacity(supplyVoltagemV);

}

/***************************************************************************//**
 * @brief Unified GPIO Interrupt handler (pushbuttons)
 *        PB0 Go right
 *        PB1 Pet dog
 *        PB2 Go left
 ******************************************************************************/
void GPIO_Unified_IRQ(void)
{
  // Get and clear all pending GPIO interrupts
  uint32_t interruptMask = GPIO_IntGet();
  GPIO_IntClear(interruptMask);

  // Act on interrupts
  if (interruptMask & (1 << PB0_PIN)) {
    // PB0: Go right
	if (pos < DOG_POS_X_MAX){
	  pos++;
	}
  }

  if (interruptMask & (1 << PB1_PIN)) {
    // PB1: Pet dog
	addLove();
  }

  if (interruptMask & (1 << PB2_PIN)) {
    // PB2: Go left
	if (pos > DOG_POS_X_MIN) {
		pos--;
	}
  }

}
/*
void RTCC_IRQHandler(void)
{
	uint32_t interruptMask = RTCC_IntGet();
	RTCC_IntClear(interruptMask);
}
*/
void LETIMER0_IRQHandler(void)
{
	uint32_t interruptMask = LETIMER_IntGet(LETIMER0);
	LETIMER_IntClear(LETIMER0, interruptMask);
	love_buffer++;
    Time_MinuteTick();
}

/***************************************************************************//**
 * @brief GPIO Interrupt handler (PB0)
 *        Previous test
 ******************************************************************************/
void GPIO_EVEN_IRQHandler(void)
{
  GPIO_Unified_IRQ();
}

/***************************************************************************//**
 * @brief GPIO Interrupt handler (PB1)
 *        Next test
 ******************************************************************************/
void GPIO_ODD_IRQHandler(void)
{
  GPIO_Unified_IRQ();
}

#define FULLSCREEN_BMP_SIZE 15488
#define TRANSPARENT_LIM 0xfc
#define SCREEN_WIDTH  LPM013M126A_WIDTH
#define SCREEN_HEIGHT LPM013M126A_HEIGHT

#define SCREEN_BYTE_WIDTH SCREEN_WIDTH*3/8
#define HEART_BYTE_WIDTH HEART_BITMAP_WIDTH*3/8

uint8_t fullScreenBitmap[FULLSCREEN_BMP_SIZE];

static void drawScreen(void)
{
      memcpy(fullScreenBitmap, gardenBitmap, sizeof(gardenBitmap)/sizeof(uint8_t));

      int y_fullscreen = 120*66;
      y_fullscreen -= (SCREEN_WIDTH*3/8)*jump;

      int y_dog = 0;

      if (love >= 0) { // Living Dog
    	for (int i_dog = 0; i_dog < DOG_BITMAP_HEIGHT; i_dog++){
    	  for (int j = 0; j < DOG_BITMAP_WIDTH*3/8; j++){
    		  if (dogBitmap[y_dog] < TRANSPARENT_LIM) { // Lazy mans alpha-blending (is byte-wise, should be 3bit, causes artifacts)
    			  fullScreenBitmap[y_fullscreen+j+3*pos] = dogBitmap[y_dog];
    		  }
    		  y_dog++;
    	  }
    	  y_fullscreen += SCREEN_WIDTH*3/8;
       }
      } else { // Dead dog
      	for (int i_dog = 0; i_dog < DOG_DEAD_BITMAP_HEIGHT; i_dog++){
      	  for (int j = 0; j < DOG_DEAD_BITMAP_WIDTH*3/8; j++){
      		  if (dog_deadBitmap[y_dog] < TRANSPARENT_LIM) { // Lazy mans alpha-blending  (is byte-wise, should be 3bit, causes artifacts)
      			  fullScreenBitmap[y_fullscreen+j] = dog_deadBitmap[y_dog];
      		  }
      		  y_dog++;
      	  }
      	  y_fullscreen += SCREEN_WIDTH*3/8;
         }
      }

      // Draw background and "alpha-blended" dog
      GLIB_drawBitmap(&glibContext,
                      0,
                      0,
                      GARDEN_BITMAP_WIDTH,
                      GARDEN_BITMAP_HEIGHT,
					  fullScreenBitmap);

      // Draw hearts
      for (int i = 0; i < love; i++) {
    	  GLIB_drawBitmap(&glibContext,
    			          HEART_POS_X + (i*HEART_BITMAP_WIDTH),
    	                  0,
    	                  HEART_BITMAP_WIDTH,
    	                  HEART_BITMAP_HEIGHT,
						  heartBitmap);
      }

      // Draw Clock
      sprintf(time_str, "%02d:%02d", time_h, time_m);
      GLIB_setFont(&glibContext, &clk_font);
      GLIB_drawString(&glibContext,
    		          time_str,
					  TIME_STR_LEN,
					  CLK_POS_X,
					  20,
					  str_opaque);

      sprintf(bat_str, "%3d%%", batteryVoltagePct);
      GLIB_setFont(&glibContext, &bat_font);
      GLIB_drawString(&glibContext,
    		          bat_str,
					  BAT_STR_LEN,
					  0,
					  5,
					  false);

      DMD_updateDisplay();
}

void GraphicsInit()
{
	EMSTATUS status;

	// Initialize the DMD module for the DISPLAY device driver.
	status = DMD_init(0);
	if (DMD_OK != status) {
		while (1);
	}

	status = GLIB_contextInit(&glibContext);
	if (GLIB_OK != status) {
		while (1);
	}

	bat_font = GLIB_FontNarrow6x8;
	clk_font = GLIB_FontNumber16x20;
}

static void setupLetimer(void)
{
	CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFXO);
	CMU_ClockDivSet(cmuClock_LETIMER0, cmuClkDiv_32768);
	CMU_ClockEnable(cmuClock_LETIMER0, true);
	CMU_ClockEnable(cmuClock_CORELE, true);

	LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

	letimerInit.enable = false;
	letimerInit.comp0Top = true;
	letimerInit.repMode = letimerRepeatFree;

	LETIMER_Init(LETIMER0, &letimerInit );

	LETIMER_CompareSet(LETIMER0, 0, 59); // Counts to 59 seconds

	NVIC_ClearPendingIRQ(LETIMER0_IRQn);
	NVIC_EnableIRQ(LETIMER0_IRQn);
	LETIMER0->IFC = ~_LETIMER_IFC_MASK;
	LETIMER0->IEN = LETIMER_IEN_COMP0;

	LETIMER_Enable(LETIMER0, true);
}

int state_changed(void) {
	if ((pos  != pos_prev) ||
	    (love != love_prev)) {
		pos_prev  = pos;
		love_prev = love;
		return 1;
	} else {
		return 0;
	}
}

/***************************************************************************//**
 * @brief  Main function.
 ******************************************************************************/
int main(void)
{

  /* Chip errata */
  CHIP_Init();

  // LFXO setup
  const CMU_LFXOInit_TypeDef *lfxo_init = CMU_LFXOINIT_DEFAULT;
  CMU_LFXOInit(lfxo_init);

  // Setup GPIO for pushbuttons.
  GpioSetup();

  GraphicsInit();

  CMU_ClockEnable(cmuClock_ADC0, true);
  InitADCforSupplyMeasurement();

  // Set initial time
  Time_Init();

  // Start time keeping
  setupLetimer();

  RMU->CTRL = RMU_CTRL_PINRMODE_DISABLED; // Disable pin reset
  glibContext.foregroundColor = Black;

  readSupplyVoltage();

  while (1) {
	//if (state_changed()) {
    //drawScreen();
	//}
	// Fixme: Needs cleanup
	int new_pos = pos;
	pos = pos_prev;
	jump = (time_m % 3) + 3;
    drawScreen();
    jump += 2;
    pos = new_pos;
    drawScreen();
    jump -= 2;
    removeLove();
    drawScreen();
    jump -= 3;
    drawScreen();
    state_changed();

    CMU_ClockEnable(cmuClock_ADC0, true);
    readSupplyVoltage();
    CMU_ClockEnable(cmuClock_ADC0, false);

    EMU_EnterEM2(true);


  }
}
