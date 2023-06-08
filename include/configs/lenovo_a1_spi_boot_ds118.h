/*
 * Configuration settings for the Realtek 1295 fpga board.
 *
 * Won't include this file.
 * Just type "make <board_name>_config" and will be included in source tree.
 */

#ifndef __CONFIG_RTK_LENOVO_A1_SPI_BOOT_DS118_H
#define __CONFIG_RTK_LENOVO_A1_SPI_BOOT_DS118_H

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
#define CONFIG_PORT0_POWER_PIN			56

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

#define CONFIG_BOARD_LENOVO_T1
#undef CONFIG_SYS_PROMPT
#define CONFIG_SYS_PROMPT        		"Lenovo_A1> "

/* FAN */
#define CONFIG_FAN_ENABLE_GPIO_NUM   6
/* PWM command interface */
#define CONFIG_CMD_RTKPWM
/* PWM hardware driver */
#define CONFIG_RTD129X_PWM
#define FAN_PWM_PORT_NUM 0
#ifdef CONFIG_RTD129X_PWM
    #define PWM_0_PIN_0
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

/* DS218:  "syno_hdd_detect=4,5 syno_hdd_enable=85,86 HddHotplug=2"
   DS420j: "syno_hdd_detect=4,5,6,7 syno_hdd_enable=85,86,82,81 syno_spinup_group=2,1,1 syno_spinup_group_delay=15 HddHotplug=4"
   DS118:  "syno_hdd_enable=85" */
#define CONFIG_SYNO_HDD_PARAMS   ""

/* DS218:  "syno_castrated_xhc=xhci-hcd.5.auto@1 syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,17@xhci-hcd.5.auto@0,22@xhci-hcd.8.auto@0"
   DS420j: "syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,22@xhci-hcd.5.auto@0"
   DS118:  "syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,22@xhci-hcd.5.auto@0" */
#define CONFIG_SYNO_USB_PARAMS  "syno_usb_vbus_gpio=102@xhci-hcd.2.auto@0,133@xhci-hcd.5.auto@0"

#define CONFIG_AW2015

#include <configs/rtd129x_ds118_parameter.h>

#endif /*__CONFIG_RTK_LENOVO_T1_SPI_BOOT_DS218_H */