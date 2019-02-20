/*
 * novagotchi_revA_pinout.h
 *
 *  Created on: Feb 19, 2019
 *      Author: habechma
 */

#ifndef INC_NOVAGOTCHI_REVA_PINOUT_H_
#define INC_NOVAGOTCHI_REVA_PINOUT_H_

// Push Button pins
#define PB0_PORT       (gpioPortE)
#define PB0_PIN                (4)
#define PB1_PORT       (gpioPortE)
#define PB1_PIN                (5)
#define PB2_PORT       (gpioPortE)
#define PB2_PIN                (6)

// Display Pins
#define PINOUT_DISPLAY_EN_PORT   (gpioPortD)
#define PINOUT_DISPLAY_EN_PIN            (4)

#define PINOUT_SPI_SCLK_PORT     (gpioPortB)
#define PINOUT_SPI_SCLK_PIN              (7)
#define PINOUT_SPI_SCLK_LOC              (0)

#define PINOUT_SPI_SCS_PORT      (gpioPortB)
#define PINOUT_SPI_SCS_PIN               (8)
#define PINOUT_SPI_SCS_LOC               (0)

#define PINOUT_SPI_TX_PORT       (gpioPortA)
#define PINOUT_SPI_TX_PIN               (14)
#define PINOUT_SPI_TX_LOC                (6)

#define PINOUT_PRS_EXTCOM_PORT   (gpioPortD)
#define PINOUT_PRS_EXTCOM_PIN            (5)
#define PINOUT_PRS_EXTCOM_CH            (11)
#define PINOUT_PRS_EXTCOM_LOC            (2)
#define PINOUT_PRS_EXTCOM_ROUTE           \
    PRS->ROUTELOC2 = \
  ((PRS->ROUTELOC2 & ~_PRS_ROUTELOC2_CH11LOC_MASK) | PINOUT_PRS_EXTCOM_LOC)


// LFXO Pins
#define PINOUT_LFXTAL_P_PORT (gpioPortB)
#define PINOUT_LFXTAL_P_PIN          (7)
#define PINOUT_LFXTAL_N_PORT (gpioPortB)
#define PINOUT_LFXTAL_INC_NOVAGOTCHI_RAVA_PINOUT_H_  (8)

#endif /* INC_NOVAGOTCHI_REVA_PINOUT_H_ */
