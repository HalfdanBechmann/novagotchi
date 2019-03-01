/***************************************************************************//**
 * @file main.c
 * @brief Novagotchi main file
 ******************************************************************************/

// Memcopy
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// EMlib
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_letimer.h"
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


// Initial power-on state
#define INIT_POS                 25
#define INIT_LOVE                 2

// Limits
#define MAX_LOVE				  5
#define MAX_STR_LEN               48


#define HEART0_VAL              2000
#define HEART1_VAL              500
#define HEART2_VAL              300
#define HEART3_VAL              100
#define HEART4_VAL              50
#define HEART5_VAL              20

/*
// Test values
#define HEART0_VAL              7
#define HEART1_VAL              6
#define HEART2_VAL              5
#define HEART3_VAL              4
#define HEART4_VAL              3
#define HEART5_VAL              2
*/

/* Center of display */
/*
#define CENTER_X                  (glibContext.pDisplayGeometry->xSize / 2)
#define CENTER_Y                  (glibContext.pDisplayGeometry->ySize / 2)

#define MAX_X                     (glibContext.pDisplayGeometry->xSize - 1)
#define MAX_Y                     (glibContext.pDisplayGeometry->ySize - 1)

#define MIN_X                     0
#define MIN_Y                     0

#define GLIB_FONT_WIDTH           (glibContext.font.fontWidth \
                                   + glibContext.font.charSpacing)
#define GLIB_FONT_HEIGHT          (glibContext.font.fontHeight)
*/

// State variables
static volatile uint32_t pos = INIT_POS;
static volatile uint32_t pos_prev = 0;
static volatile uint32_t love = INIT_LOVE;
static volatile uint32_t love_prev = INIT_LOVE;


// Buffer
static volatile uint32_t love_buffer = 0;

// The GLIB context
static GLIB_Context_t glibContext;

// Forward static function declararations
static void drawScreen(void);

/***************************************************************************//**
 * @brief Setup GPIO interrupt for pushbuttons.
 ******************************************************************************/
static void GpioSetup(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Configure PB0 as input and enable interrupt
  GPIO_PinModeSet(PB0_PORT, PB0_PIN, gpioModeInputPull, 1);
  GPIO_IntConfig(PB0_PORT, PB0_PIN, false, true, true);

  // Configure PB1 as input and enable interrupt
  GPIO_PinModeSet(PB1_PORT, PB1_PIN, gpioModeInputPull, 1);
  GPIO_IntConfig(PB1_PORT, PB1_PIN, false, true, true);

  // Configure PB2 as input and enable interrupt
  GPIO_PinModeSet(PB2_PORT, PB2_PIN, gpioModeInputPull, 1);
  GPIO_IntConfig(PB2_PORT, PB2_PIN, false, true, true);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);

  NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
}
/*
void RTCC_setup(void) {

	// Set up rtcc clock
	CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFXO);
	CMU_ClockEnable(cmuClock_RTCC, true);
	CMU_ClockEnable(cmuClock_CORELE, true);

	const RTCC_Init_TypeDef *rtcc_init =
			{
			true,                // Start counting when initialization is done.
			false,               // Disable RTCC during debug halt.
			false,               // Disable pre-counter wrap on ch. 0 CCV value.
			false,               // Disable counter wrap on ch. 1 CCV value.
			rtccCntPresc_32768,  // 1 tick per second.
			rtccCntTickPresc,    // Counter increments according to prescaler value. fixme: ??
			false,               // No RTCC oscillator failure detection.
			rtccCntModeCalendar, // Calendar mode.
		    false                // No leap year correction.
	};
	RTCC_Init(&rtcc_init);

	RTCC->IEN = RTCC_IEN_MINTICK; // Wake up every minute
	NVIC_EnableIRQ(RTCC_IRQn);

	RTCC_Enable(true);
}
*/

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
	pos++;
  }

  if (interruptMask & (1 << PB1_PIN)) {
    // PB1: Pet dog
	if (love < MAX_LOVE) {
     love++;
	}
	love_buffer = 0;
  }

  if (interruptMask & (1 << PB2_PIN)) {
    // PB2: Go left
	pos--;
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

	if (((love == 0) && (love_buffer > HEART0_VAL)) ||
		((love == 1) && (love_buffer > HEART1_VAL)) ||
        ((love == 2) && (love_buffer > HEART2_VAL)) ||
		((love == 3) && (love_buffer > HEART3_VAL)) ||
		((love == 4) && (love_buffer > HEART4_VAL)) ||
		((love == 5) && (love_buffer > HEART5_VAL))) {
			love--;
			love_buffer = 0;
	} else {
		love_buffer++;
	}
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
      int y_dog = 0;

      if (love >= 0) {
    	for (int i_dog = 0; i_dog < DOG_BITMAP_HEIGHT; i_dog++){
    	  for (int j = 0; j < DOG_BITMAP_WIDTH*3/8; j++){
    		  if (dogBitmap[y_dog] < TRANSPARENT_LIM) {
    			  fullScreenBitmap[y_fullscreen+j+3*pos] = dogBitmap[y_dog];
    		  }
    		  y_dog++;
    	  }
    	  y_fullscreen += SCREEN_WIDTH*3/8;
       }
      } else {
      	for (int i_dog = 0; i_dog < DOG_DEAD_BITMAP_HEIGHT; i_dog++){
      	  for (int j = 0; j < DOG_DEAD_BITMAP_WIDTH*3/8; j++){
      		  if (dog_deadBitmap[y_dog] < TRANSPARENT_LIM) {
      			  fullScreenBitmap[y_fullscreen+j] = dog_deadBitmap[y_dog];
      		  }
      		  y_dog++;
      	  }
      	  y_fullscreen += SCREEN_WIDTH*3/8;
         }

      }
      for (int i = 0; i < love; i++) {
    	  y_fullscreen = SCREEN_BYTE_WIDTH/2 + (i-MAX_LOVE/2)*HEART_BYTE_WIDTH;
    	  int y_heart = 0;
    	  for (int i_heart = 0; i_heart < HEART_BITMAP_HEIGHT; i_heart++){
    		  for (int j = 0; j < HEART_BITMAP_WIDTH*3/8; j++){
    			  fullScreenBitmap[y_fullscreen+j] = heartBitmap[y_heart];
    			  y_heart++;
    		  }
    		  y_fullscreen += SCREEN_BYTE_WIDTH;
    	  }
      }

      GLIB_clear(&glibContext);
      GLIB_drawBitmap(&glibContext,
                      0,
                      0,
                      GARDEN_BITMAP_WIDTH,
                      GARDEN_BITMAP_HEIGHT,
					  fullScreenBitmap);

      DMD_updateDisplay();
}

static void setupLetimer(void)
{
	CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_ULFRCO);
	CMU_ClockEnable(cmuClock_LETIMER0, true);
	CMU_ClockEnable(cmuClock_CORELE, true);

	LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

	letimerInit.enable = false;
	letimerInit.comp0Top = true;
	letimerInit.repMode = letimerRepeatFree;

	LETIMER_Init(LETIMER0, &letimerInit );

	LETIMER_CompareSet(LETIMER0, 0, 0xFFFF);

	/* Enabling Interrupt from RTC */
	LETIMER_IntEnable(LETIMER0, LETIMER_IF_COMP0);
	NVIC_EnableIRQ(LETIMER0_IRQn);

	/* Initialize the RTC */
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
  EMSTATUS status;

  /* Chip errata */
  CHIP_Init();

  setupLetimer();

  // LFXO setup
  const CMU_LFXOInit_TypeDef *lfxo_init = CMU_LFXOINIT_DEFAULT;
  CMU_LFXOInit(lfxo_init);

  // Setup GPIO for pushbuttons.
  GpioSetup();
  NVIC_ClearPendingIRQ(LETIMER0_IRQn);
  NVIC_EnableIRQ(LETIMER0_IRQn);
  // Initialize the DMD module for the DISPLAY device driver.
  status = DMD_init(0);
  if (DMD_OK != status) {
    while (1) {
    }
  }

  status = GLIB_contextInit(&glibContext);
  if (GLIB_OK != status) {
    while (1) {
    }
  }

  while (1) {
	if (state_changed()) {
      drawScreen();
	}
    EMU_EnterEM2(true);
  }
}
