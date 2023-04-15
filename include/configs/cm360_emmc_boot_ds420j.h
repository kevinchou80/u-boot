/*
 * Configuration settings for the Realtek 1295 fpga board.
 *
 * Won't include this file.
 * Just type "make <board_name>_config" and will be included in source tree.
 */

#ifndef __CONFIG_RTK_CM360_EMMC_BOOT_DS420J_H
#define __CONFIG_RTK_CM360_EMMC_BOOT_DS420J_H

/*
 * Include the common settings of RTD1295 platform.
 */
#include <configs/rtd1295_common.h>

/* ========================================================== */
/* Flash type is SPI or NAND or eMMC */
/* #define CONFIG_SYS_RTK_SPI_FLASH */
/* #define CONFIG_SYS_RTK_NAND_FLASH */
#define CONFIG_SYS_RTK_EMMC_FLASH
#define CONFIG_EMMC_SYNO_DUAL_BOOT

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
#define CONFIG_FLASH_WRITER_SETTING            "1296_force_emmc_nS_nE"

#define CONFIG_BOARD_CM360
#undef CONFIG_SYS_PROMPT
#define CONFIG_SYS_PROMPT        		"CM360> "

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

#define CONFIG_HDD1_DETECT   
/* ds420j default 4 */
#define CONFIG_HDD2_DETECT    
/* ds420j default 5 */
#define CONFIG_HDD3_DETECT    
/* ds420j default 6 */
#define CONFIG_HDD4_DETECT    
/* ds420j default 7 */

#define CONFIG_HDD1_ENABLE    
/* ds420j default 85 */
#define CONFIG_HDD2_ENABLE    
/* ds420j default 86 */
#define CONFIG_HDD3_ENABLE    
/* ds420j default 81 */
#define CONFIG_HDD4_ENABLE    
/* ds420j default 82 */


#define CONFIG_HDD1_BLINK    127
/* ds420j default 119 */
#define CONFIG_HDD2_BLINK    122
/* ds420j default 120 */

#define CONFIG_USB_CTYPE_VBUS    102
/* ds420j default 23 */
#define CONFIG_U3HOST_VBUS    133
/* ds420j u3host default 22 */


#include <configs/rtd129x_ds420j_parameter.h>

#endif /*__CONFIG_RTK_CM360_EMMC_BOOT_DS420J_H */