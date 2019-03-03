/***************************************************************************//**
 * @file displaypalconfig.h
 * @brief Configuration file for PAL (Platform Abstraction Layer)
 * @version 5.5.0
 *******************************************************************************
 * # License
 * <b>Copyright 2015 Silicon Labs, Inc. http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/
#ifndef __SILICON_LABS_DISPLAYPALCONFIG_H__
#define __SILICON_LABS_DISPLAYPALCONFIG_H__

/*
 * Select which oscillator should source the RTC clock.
 */
#define PAL_RTCC_CLOCK_LFXO
#undef  PAL_RTCC_CLOCK_LFRCO
#undef  PAL_RTCC_CLOCK_ULFRCO

// Use RTC clock for auto-toggle
//#define PAL_CLOCK_RTC
//#define PAL_RTC_CLOCK_LFRCO

/*
 * PAL SPI / USART configuration for the SLSTK3701A.
 * Select which USART and location is connected to the device via SPI.
 */
#define PAL_SPI_USART_UNIT          (USART1)
#define PAL_SPI_USART_CLOCK         (cmuClock_USART1)
#define PAL_SPI_USART_LOCATION_TX   (PINOUT_SPI_TX_LOC)
#define PAL_SPI_USART_LOCATION_CS   (PINOUT_SPI_SCS_LOC)
#define PAL_SPI_USART_LOCATION_SCLK (PINOUT_SPI_SCLK_LOC)

/*
 * Specify the SPI baud rate:
 */
#define PAL_SPI_BAUDRATE       (3500000)
//#define PAL_SPI_BAUDRATE       (1000000)

#define POLARITY_INVERSION_EXTCOMIN_MANUAL

#endif /* __SILICON_LABS_DISPLAYPALCONFIG_H__ */
