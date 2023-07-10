/*
 * Configuration settings for the Realtek 1295 fpga board.
 *
 * Won't include this file.
 * Just type "make <board_name>_config" and will be included in source tree.
 */

#ifndef __CONFIG_RTK_PELICAN_EMMC_BOOT_DS420J_H
#define __CONFIG_RTK_PELICAN_EMMC_BOOT_DS420J_H

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
#define CONFIG_PORT0_POWER_PIN			60
#define CONFIG_PORT1_POWER_PIN			62
#define SSCEN 0
/*#define PHY_SENSITIVITY_B00
 A00 A01 use 0;B00 use 1 
#define PHY_CLOCK_DELAY
B00 must define */


#include "rtd129x_custom_features.h"

#define CONFIG_CHIP_ID            			   "rtd1295"
#define CONFIG_CUSTOMER_ID            		   "demo"
#define CONFIG_CHIP_TYPE            		   "0002"
#define CONFIG_FLASH_WRITER_SETTING            "1296_force_emmc_nS_nE"

#define CONFIG_BOARD_WD_PELICAN
#undef CONFIG_SYS_PROMPT
#define CONFIG_SYS_PROMPT        		"PELICAN> "

/* PWM command interface */
#define CONFIG_CMD_RTKPWM
/* PWM hardware driver */
#define CONFIG_RTD129X_PWM
#define SYS_LED_PWM_PORT_NUM 0
#define FAN_PWM_PORT_NUM 3
#ifdef CONFIG_RTD129X_PWM
    #define PWM_0_PIN_0
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
#define CONFIG_INSTALL_GPIO_NUM    121

/* DS218:  "syno_hdd_detect=4,5 syno_hdd_enable=85,86 HddHotplug=2"
   DS420j: "syno_hdd_detect=4,5,6,7 syno_hdd_enable=85,86,82,81 syno_spinup_group=2,1,1 syno_spinup_group_delay=15 HddHotplug=4"
   DS118:  "syno_hdd_enable=85" */
#define CONFIG_SYNO_HDD_PARAMS   "syno_spinup_group=2,1,1 syno_spinup_group_delay=15"

/* DS218:  "syno_castrated_xhc=xhci-hcd.5.auto@1 syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,17@xhci-hcd.5.auto@0,22@xhci-hcd.8.auto@0"
   DS420j: "syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,22@xhci-hcd.5.auto@0"
   DS118:  "syno_usb_vbus_gpio=23@xhci-hcd.2.auto@0,22@xhci-hcd.5.auto@0" */
#define CONFIG_SYNO_USB_PARAMS  "syno_usb_vbus_gpio=127@xhci-hcd.2.auto@0,135@xhci-hcd.5.auto@0"

#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND                   \
	"run syno_bootargs;run rtk_emmc_boot;run mod_fdt;ping $serverip;go all"


#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS                   \
   "kernel_loadaddr=0x03000000\0"                  \
   "fdt_loadaddr=0x01f00000\0"                  \
   "fdt_high=0xffffffffffffffff\0"                  \
   "rootfs_loadaddr=0x02200000\0"                   \
   "rescue_rootfs_loadaddr=0x02200000\0"                   \
   "audio_loadaddr="STR(CONFIG_FW_LOADADDR)"\0"                 \
   "rtk_emmc_boot=ext4load emmc 0:1 zImage 0x0b000000;ext4load emmc 0:1 rd.bin $rootfs_loadaddr;lzmadec 0x0b000000 $kernel_loadaddr;ext4load emmc 0:1 audio.fw 0x0b000000;lzmadec 0x0b000000 $audio_loadaddr;ext4load emmc 0:1 ds420j.dtb $fdt_loadaddr;\0"                 \
   "syno_bootargs=setenv bootargs \"ip=off console=ttyS0,115200 root=/dev/md0 rw "CONFIG_SYNO_HDD_PARAMS" "CONFIG_SYNO_USB_PARAMS" syno_hw_version=DS420j hd_power_on_seq=4 ihd_num=4 netif_num=1 swiotlb=1 audio_version=1012363 syno_fw_version=M.904\"\0"                 \
   "mtd_part=mtdparts=rtk_nand:\0"                  \
   "tx_driving=<2>\0"                  \
   "rx_sensitivity=<2>\0"                  \
   "tx_path=/sata@9803F000\0"                  \
   "mod_fdt=fdt addr $fdt_loadaddr; fdt resize;fdt set $tx_path tx-driving $tx_driving;fdt set $tx_path rx-sensitivity $rx_sensitivity\0"                  \

#endif /*__CONFIG_RTK_PELICAN_EMMC_BOOT_DS420J_H */