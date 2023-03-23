/*
 * Configuration settings for the Realtek 1295 fpga board.
 *
 * Won't include this file.
 * Just type "make <board_name>_config" and will be included in source tree.
 */

#ifndef __CONFIG_RTK_CM360_SPI_BOOT_DS218_H
#define __CONFIG_RTK_CM360_SPI_BOOT_DS218_H

/*
 * Include the common settings of RTD1295 platform.
 */
#include <configs/rtd1295_common.h>

/* ========================================================== */
/* Flash type is SPI or NAND or eMMC */
#define CONFIG_SYS_RTK_SPI_FLASH
/* #define CONFIG_SYS_RTK_NAND_FLASH */
/* #define CONFIG_SYS_RTK_EMMC_FLASH */

#define CONFIG_CMD_SATA
#define CONFIG_SYS_SATA_MAX_DEVICE      2
#define CONFIG_PORT0_POWER_PIN			56
#define CONFIG_PORT1_POWER_PIN			19
#define SSCEN 0
#define PHY_SENSITIVITY_B00
/* A00 A01 use 0;B00 use 1 */
#define PHY_CLOCK_DELAY
/*B00 must define */

#include "rtd129x_custom_features.h"

#define CONFIG_CHIP_ID            			   "rtd1295"
#define CONFIG_CUSTOMER_ID            		   "demo"
#define CONFIG_CHIP_TYPE            		   "0002"
#define CONFIG_FLASH_WRITER_SETTING            "1296_force_spi_nS_nE"

#define CONFIG_BOARD_CM360
#undef CONFIG_SYS_PROMPT
#define CONFIG_SYS_PROMPT        		"CM360_DS218> "

/* PWM command interface */
#define CONFIG_CMD_RTKPWM
/* PWM hardware driver */
#define CONFIG_RTD129X_PWM
#define SYS_LED_PWM_PORT_NUM 1
#define FAN_PWM_PORT_NUM 3
#ifdef CONFIG_RTD129X_PWM
    #define PWM_1_PIN_1
    #define PWM_3_PIN_1
#endif /* CONFIG_RTD129X_PWM */

#if defined(CONFIG_TARGET_RTD1296) && defined(CONFIG_NAS_ENABLE)
	#define CONFIG_DPTX_MODE               1
	#define CONFIG_DPTX_HPD_IGPIO_NUM      7
	#define CONFIG_DPTX_DEFAULT_RESOLUTION 2
#endif

/* GPIO */
#undef CONFIG_INSTALL_GPIO_NUM
#undef CONFIG_LED_RED_GPIO_NUM
#define CONFIG_INSTALL_GPIO_NUM    8

#define CONFIG_HDD1_DETECT   4 
/* ds218 default 4 */
#define CONFIG_HDD2_DETECT    5
/* ds218 default 5 */

#define CONFIG_HDD1_ENABLE    85
/* ds218 default 85 */
#define CONFIG_HDD2_ENABLE    86
/* ds218 default 86 */


#define CONFIG_HDD1_BLINK    127
/* ds218 default 119 */
#define CONFIG_HDD2_BLINK    122
/* ds218 default 120 */

#define CONFIG_USB_CTYPE_VBUS    102
/* ds218 default 23 */
#define CONFIG_USB_U2HOST_VBUS    132
/* ds218 u2host default 17 */
/* actually gpio122 is the green led,use as gpio can achieve led on/off sync with power on/off */
#define CONFIG_U3HOST_VBUS    133
/* ds218 u3host default 22 */


#include <configs/rtd129x_ds218_parameter.h>

#endif /*__CONFIG_RTK_CM360_SPI_BOOT_DS218_H */