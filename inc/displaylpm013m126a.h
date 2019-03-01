/***************************************************************************//**
 * @file displaylpm013m126a.h
 * @brief Configuration for the display driver for the Japan Display Memory LCD
 *        LPM013M126A
 ******************************************************************************/
#ifndef _DISPLAY_LPM013M126A_H_
#define _DISPLAY_LPM013M126A_H_

#include "emstatus.h"

/** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 ********************************  DEFINES  ************************************
 ******************************************************************************/

/* Display geometry */
#define LPM013M126A_WIDTH           (176)
#define LPM013M126A_HEIGHT          (176)
#define LPM013M126A_BITS_PER_PIXEL    (3)

/*******************************************************************************
 **************************    FUNCTION PROTOTYPES    **************************
 ******************************************************************************/

/* Initialization function for the LPM013M126A device driver. */
EMSTATUS DISPLAY_Lpm013m126aInit(void);

#ifdef __cplusplus
}
#endif

/** @endcond */

#endif /* _DISPLAY_LPM013M126A_H_ */
