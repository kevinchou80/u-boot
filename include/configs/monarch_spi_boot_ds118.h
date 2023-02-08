/*
 * Configuration settings for the Realtek 1295 fpga board.
 *
 * Won't include this file.
 * Just type "make <board_name>_config" and will be included in source tree.
 */

#ifndef __CONFIG_RTK_MONARCH_SPI_BOOT_DS118_H
#define __CONFIG_RTK_MONARCH_SPI_BOOT_DS118_H

/*
 * Include the common settings of RTD1295 platform.
 */
#include <configs/rtd1295_common.h>

/* ========================================================== */
/* Flash type is SPI or NAND or eMMC */
#define CONFIG_SYS_RTK_SPI_FLASH
/* #define CONFIG_SYS_RTK_NAND_FLASH */
/* #define CONFIG_SYS_RTK_EMMC_FLASH */

#include "rtd129x_custom_features.h"

#define CONFIG_CHIP_ID            			   "rtd1295"
#define CONFIG_CUSTOMER_ID            		   "demo"
#define CONFIG_CHIP_TYPE            		   "0001"
#define CONFIG_FLASH_WRITER_SETTING            "1295_force_spi_nS_nE_monarch"

#define CONFIG_BOARD_WD_MONARCH
#undef CONFIG_SYS_PROMPT
#define CONFIG_SYS_PROMPT        		"Monarch> "

/* PWM command interface */
#define CONFIG_CMD_RTKPWM
/* PWM hardware driver */
#define CONFIG_RTD129X_PWM
#define SYS_LED_PWM_PORT_NUM 3
#ifdef CONFIG_RTD129X_PWM
    #define PWM_3_PIN_0
#endif /* CONFIG_RTD129X_PWM */

/* GPIO */
#undef CONFIG_INSTALL_GPIO_NUM
#undef CONFIG_LED_RED_GPIO_NUM
#define CONFIG_INSTALL_GPIO_NUM    135
/*#define FACTORY_RST_BTN 34		// igpio34 is the factory reset button for Monarch*/

#define CONFIG_HDD_ENABLE    18
/* ds118 default 85 */

#define CONFIG_HDD_BLINK    23
/* ds118 default 18 */

#define CONFIG_USB_CTYPE_VBUS    19
/* ds118 default 23 */
#define CONFIG_U3HOST_VBUS    22
/* ds218 u3host default 22 */

#undef  CONFIG_HDMITX_MODE
#define CONFIG_HDMITX_MODE				 0 /* 0:Always OFF, 1: Always ON, 2: Auto */

#include <configs/rtd129x_ds118_parameter.h>

#endif /* __CONFIG_RTK_MONARCH_SPI_BOOT_DS118_H */

