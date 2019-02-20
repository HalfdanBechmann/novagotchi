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
//#undef  PAL_RTCC_CLOCK_LFXO
//#define  PAL_RTCC_CLOCK_LFRCO
//#undef  PAL_RTCC_CLOCK_ULFRCO

// Use RTC clock for auto-toggle
#define PAL_CLOCK_RTC
#define PAL_RTC_CLOCK_LFRCO

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
#define PAL_SPI_BAUDRATE       (3500000) /* Max baudrate on EFM32GG. */
//#define PAL_SPI_BAUDRATE       (1000000)

/*
 * On the SLSTK3701A, we can toggle some GPIO pins with hw only,
 * especially the GPIO port A pin 11 signal which is connected to the
 * polarity inversion (EXTCOMIN) pin on the Sharp Memory LCD. By defining
 * INCLUDE_PAL_GPIO_PIN_AUTO_TOGGLE_HW_ONLY the toggling of EXTCOMIN will
 * be handled by hardware, without software intervention, which saves power.
 */
#define INCLUDE_PAL_GPIO_PIN_AUTO_TOGGLE_HW_ONLY

#endif /* __SILICON_LABS_DISPLAYPALCONFIG_H__ */
