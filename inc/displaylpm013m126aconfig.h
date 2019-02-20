/***************************************************************************//**
 * @file displaylpm013m126aconfig.h
 * @brief configuration for the display driver for
 *        the Japan Display Memory LCD model LPM013M126A.
 ******************************************************************************/
#ifndef __SILICON_LABS_DISPLAYLPM013M126ACONFIG_H__
#define __SILICON_LABS_DISPLAYLPM013M126ACONFIG_H__

#include <novagotchi_revA_pinout.h>
#include "displayconfigapp.h"
#include "em_gpio.h"
/* Display device name. */
#define JAPAN_DISPLAY_MEMLCD_DEVICE_NAME   "Japan Display LPM013M126A"

/* LCD and SPI GPIO pin connections */

#define LCD_PORT_SCLK             (PINOUT_SPI_SCLK_PORT)
#define LCD_PIN_SCLK              (PINOUT_SPI_SCLK_PIN)
#define LCD_PORT_SCS              (PINOUT_SPI_SCS_PORT)
#define LCD_PIN_SCS               (PINOUT_SPI_SCS_PIN)
#define LCD_PORT_SI               (PINOUT_SPI_TX_PORT)
#define LCD_PIN_SI                (PINOUT_SPI_TX_PIN)
#define LCD_PORT_EXTCOMIN         (PINOUT_PRS_EXTCOM_PORT)
#define LCD_PIN_EXTCOMIN          (PINOUT_PRS_EXTCOM_PIN)

#define LCD_AUTO_TOGGLE_PRS_ROUTELOC()  PINOUT_PRS_EXTCOM_ROUTE

/* PRS settings for polarity inversion extcomin auto toggle.  */
#define LCD_AUTO_TOGGLE_PRS_CH    (PINOUT_PRS_EXTCOM_CH)

#define LCD_AUTO_TOGGLE_PRS_ROUTEPEN    (1 << PINOUT_PRS_EXTCOM_CH)

#define LCD_PORT_DISP_SEL         (PINOUT_DISPLAY_EN_PORT)
#define LCD_PIN_DISP_SEL          (PINOUT_DISPLAY_EN_PIN)
//#define LCD_ENABLE_PORT           (PINOUT_DISPLAY_EN_PORT)
//#define LCD_ENABLE_PIN            (PINOUT_DISPLAY_EN_PIN)


/*
 * Select how LCD polarity inversion should be handled:
 *
 * If POLARITY_INVERSION_EXTCOMIN is defined,
 * and the polarity inversion is armed for every rising edge of the EXTCOMIN
 * pin. The actual polarity inversion is triggered at the next transision of
 * SCS. This mode is recommended because it causes less CPU and SPI load than
 * the alternative mode, see below.
 * If POLARITY_INVERSION_EXTCOMIN is undefined,
 * the polarity inversion is toggled by sending an SPI command. This mode
 * causes more CPU and SPI load than using the EXTCOMIN pin mode.
 */
#define POLARITY_INVERSION_EXTCOMIN

/* Define POLARITY_INVERSION_EXTCOMIN_PAL_AUTO_TOGGLE if you want the PAL
 * (Platform Abstraction Layer interface) to automatically toggle the EXTCOMIN
 *  pin.
 * If the PAL_TIMER_REPEAT function is defined the EXTCOMIN toggling is handled
 * by a timer repeat system, therefore we must undefine
 * POLARITY_INVERSION_EXTCOMIN_PAL_AUTO_TOGGLE;
 */
#ifndef PAL_TIMER_REPEAT_FUNCTION
  #define POLARITY_INVERSION_EXTCOMIN_PAL_AUTO_TOGGLE
#endif

#endif /* __SILICON_LABS_DISPLAYLPM013M126ACONFIG_H__ */
