/*
 * novagotchi_revB_pinout.h
 *      Author: habechma
 */
#ifndef INC_NOVAGOTCHI_REVB_PINOUT_H_
#define INC_NOVAGOTCHI_REVB_PINOUT_H_

// Push Button pins
#define PB0_PORT       (gpioPortD)
#define PB0_PIN                (4)
#define PB1_PORT       (gpioPortD)
#define PB1_PIN                (5)
#define PB2_PORT       (gpioPortD)
#define PB2_PIN                (6)

// Display Pins
#define PINOUT_DISPLAY_EN_PORT   (gpioPortB)
#define PINOUT_DISPLAY_EN_PIN           (11)

#define PINOUT_SPI_SCLK_PORT     (gpioPortC)
#define PINOUT_SPI_SCLK_PIN             (15)
#define PINOUT_SPI_SCLK_LOC              (3)

#define PINOUT_SPI_SCS_PORT      (gpioPortC)
#define PINOUT_SPI_SCS_PIN              (14)
#define PINOUT_SPI_SCS_LOC               (3)

#define PINOUT_SPI_TX_PORT       (gpioPortD)
#define PINOUT_SPI_TX_PIN                (7)
#define PINOUT_SPI_TX_LOC                (2)

#define PINOUT_PRS_EXTCOM_PORT   (gpioPortB)
#define PINOUT_PRS_EXTCOM_PIN           (13)
#define PINOUT_PRS_EXTCOM_CH             (7)
#define PINOUT_PRS_EXTCOM_LOC            (0)
#define PINOUT_PRS_EXTCOM_ROUTE           \
    PRS->ROUTELOC1 = \
  ((PRS->ROUTELOC1 & ~_PRS_ROUTELOC1_CH7LOC_MASK) | PINOUT_PRS_EXTCOM_LOC)


// LFXO Pins
#define PINOUT_LFXTAL_P_PORT (gpioPortB)
#define PINOUT_LFXTAL_P_PIN          (7)
#define PINOUT_LFXTAL_N_PORT (gpioPortB)
#define PINOUT_LFXTAL_N_PIN          (8)

#endif /* INC_NOVAGOTCHI_REVB_PINOUT_H_ */
