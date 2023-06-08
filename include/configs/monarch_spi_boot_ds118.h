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

#define CONFIG_CMD_SATA
#define CONFIG_SYS_SATA_MAX_DEVICE      1
#define CONFIG_PORT0_POWER_PIN			18
#define SSCEN 0
/* #define PHY_SENSITIVITY_B00*/
/* A00 A01 use 0;B00 use 1 */
/*#define PHY_CLOCK_DELAY*/
/*B00 must define */

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

/* DS218:  "syno_hdd_detect=4,5 syno_hdd_enable=85,86 HddHotplug=2"
   DS420j: "syno_hdd_detect=4,5,6,7 syno_hdd_enable=85,86,82,81 syno_spinup_group=2,1,1 syno_spinup_group_delay=15 HddHotplug=4"
   DS118:  "syno_hdd_enable=85" */
#define CONFIG_SYNO_HDD_PARAMS   "syno_hdd_enable=18"

/* DS218:  "syno_castrated_xhc=xhci-hcd.5.auto@1 syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,17@xhci-hcd.5.auto@0,22@xhci-hcd.8.auto@0"
   DS420j: "syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,22@xhci-hcd.5.auto@0"
   DS118:  "syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,22@xhci-hcd.5.auto@0" */
#define CONFIG_SYNO_USB_PARAMS  "syno_usb_vbus_gpio=19@xhci-hcd.2.auto@0,22@xhci-hcd.5.auto@0"

#undef  CONFIG_HDMITX_MODE
#define CONFIG_HDMITX_MODE				 0 /* 0:Always OFF, 1: Always ON, 2: Auto */

#include <configs/rtd129x_ds118_parameter.h>

#endif /* __CONFIG_RTK_MONARCH_SPI_BOOT_DS118_H */

