/*******************************************************************************
  MPLAB Harmony System Configuration Header

  File Name:
    system_config.h

  Summary:
    Build-time configuration header for the system defined by this MPLAB Harmony
    project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options that are not instantiated
    until used by another MPLAB Harmony module or application.

    Created with MPLAB Harmony Version 1.09
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Common System Service Configuration Options
*/
#define SYS_VERSION_STR           "1.09"
#define SYS_VERSION               10900

// *****************************************************************************
/* Clock System Service Configuration Options
*/
#define SYS_CLK_FREQ                        40000000ul
#define SYS_CLK_BUS_PERIPHERAL_1            40000000ul
#define SYS_CLK_UPLL_BEFORE_DIV2_FREQ       96000000ul
#define SYS_CLK_CONFIG_PRIMARY_XTAL         4000000ul
#define SYS_CLK_CONFIG_SECONDARY_XTAL       32768ul
   
/*** Interrupt System Service Configuration ***/
#define SYS_INT                     true

/*** Ports System Service Configuration ***/

#define SYS_PORT_A_ANSEL        0xf
#define SYS_PORT_A_TRIS         0x69f
#define SYS_PORT_A_LAT          0x0
#define SYS_PORT_A_ODC          0x0
#define SYS_PORT_A_CNPU         0x0
#define SYS_PORT_A_CNPD         0x0
#define SYS_PORT_A_CNEN         0x0

#define SYS_PORT_B_ANSEL        0xec00
#define SYS_PORT_B_TRIS         0xefbf
#define SYS_PORT_B_LAT          0x0
#define SYS_PORT_B_ODC          0x0
#define SYS_PORT_B_CNPU         0x0
#define SYS_PORT_B_CNPD         0x0
#define SYS_PORT_B_CNEN         0x0

#define SYS_PORT_C_ANSEL        0x0
#define SYS_PORT_C_TRIS         0x21c
#define SYS_PORT_C_LAT          0x0
#define SYS_PORT_C_ODC          0x0
#define SYS_PORT_C_CNPU         0x8
#define SYS_PORT_C_CNPD         0x0
#define SYS_PORT_C_CNEN         0x0


// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************
/*** OSAL Configuration ***/
#define OSAL_USE_RTOS          9

/*** USB Driver Configuration ***/


/* Enables Device Support */
#define DRV_USBFS_DEVICE_SUPPORT      true

/* Disable Device Support */
#define DRV_USBFS_HOST_SUPPORT      false

/* Maximum USB driver instances */
#define DRV_USBFS_INSTANCES_NUMBER    1


/* Interrupt mode enabled */
#define DRV_USBFS_INTERRUPT_MODE      true


/* Number of Endpoints used */
#define DRV_USBFS_ENDPOINTS_NUMBER    5




/*** USB Device Stack Configuration ***/










/* The USB Device Layer will not initialize the USB Driver */
#define USB_DEVICE_DRIVER_INITIALIZE_EXPLICIT

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER     1

/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE      8










/* Maximum instances of CDC function driver */
#define USB_DEVICE_CDC_INSTANCES_NUMBER     2










/* CDC Transfer Queue Size for both read and
   write. Applicable to all instances of the
   function driver */
#define USB_DEVICE_CDC_QUEUE_DEPTH_COMBINED 6



/*** OSAL Configuration ***/
#define OSAL_USE_RTOS          9



// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************

/*** Application Instance 0 Configuration ***/

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END


#endif // _SYSTEM_CONFIG_H
/*******************************************************************************
 End of File
*/

