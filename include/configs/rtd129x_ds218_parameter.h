/*
 * Configuration settings for the Realtek 1295 customized feature.
 *
 * Won't include this file.
 * Just type "make <board_name>_config" and will be included in source tree.
 */

#ifndef __CONFIG_RTK_RTD129x_DS218_PARAMETER_H
#define __CONFIG_RTK_RTD129x_DS218_PARAMETER_H


#define CONFIG_SPI_MTD_STATIC
#define CONFIG_SYNO_SPI_LAYOUT

#define CONFIG_DTS_BASE                        0x0000000
#define CONFIG_DTS_SIZE                        0x00010000


#define CONFIG_UBOOT_ADDR					   0x020800
#define CONFIG_UBOOT_SIZE                      0x09F800

#define CONFIG_FWIMG_ADDR                      0x0c0000
#define CONFIG_FWIMG_SIZE                      0x740000

#define CONFIG_LOGO_ADDR                       0x0c0000
#define CONFIG_LOGO_SIZE                       0x000000

#define CONFIG_AFW_ADDR                        0x0c0000
#define CONFIG_AFW_SIZE                        0x040000

#define CONFIG_KERNEL_ADDR                     0x100000
#define CONFIG_KERNEL_SIZE                     0x2F0000

#define CONFIG_ROOTFS_ADDR                     0x3f0000
#define CONFIG_ROOTFS_SIZE                     0x3ff000
#define CONFIG_INITRD_SIZE                     0x3ff000


#undef CONFIG_BOOTCOMMAND
#define CONFIG_BOOTCOMMAND                   \
	"run syno_bootargs;run rtk_spi_boot;run mod_fdt;ping $serverip;go all"


#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS                   \
   "kernel_loadaddr=0x03000000\0"                  \
   "fdt_loadaddr=0x01f00000\0"                  \
   "fdt_high=0xffffffffffffffff\0"                  \
   "rootfs_loadaddr=0x02200000\0"                   \
   "rescue_rootfs_loadaddr=0x02200000\0"                   \
   "audio_loadaddr="STR(CONFIG_FW_LOADADDR)"\0"                 \
   "rtk_spi_boot=rtkspi read "STR(CONFIG_KERNEL_ADDR)" 0x0b000000 "STR(CONFIG_KERNEL_SIZE)";lzmadec 0x0b000000 $kernel_loadaddr "STR(CONFIG_KERNEL_SIZE)";rtkspi read "STR(CONFIG_AFW_ADDR)" 0x0b000000 "STR(CONFIG_AFW_SIZE)";lzmadec 0x0b000000 $audio_loadaddr "STR(CONFIG_AFW_SIZE)";rtkspi read "STR(CONFIG_DTS_BASE)" $fdt_loadaddr "STR(CONFIG_DTS_SIZE)";rtkspi read "STR(CONFIG_ROOTFS_ADDR)" $rootfs_loadaddr "STR(CONFIG_ROOTFS_SIZE)"\0"                 \
   "syno_bootargs=setenv bootargs \"ip=off console=ttyS0,115200 root=/dev/md0 rw syno_hdd_detect="STR(CONFIG_HDD1_DETECT)","STR(CONFIG_HDD2_DETECT)" syno_hdd_enable="STR(CONFIG_HDD1_ENABLE)","STR(CONFIG_HDD2_ENABLE)" HddHotplug=2 syno_usb_vbus_gpio="STR(CONFIG_USB_CTYPE_VBUS)"@xhci-hcd.2.auto@0,"STR(CONFIG_USB_U2HOST_VBUS)"@xhci-hcd.5.auto@0,"STR(CONFIG_U3HOST_VBUS)"@xhci-hcd.8.auto@0 syno_hw_version=DS218 hd_power_on_seq=2 ihd_num=2 netif_num=1 audio_version=1012363 syno_fw_version=M.506\"\0"                 \
   "mtd_part=mtdparts=rtk_nand:\0"                  \
   "tx_driving=<2>\0"                  \
   "rx_sensitivity=<2>\0"                  \
   "tx_path=/sata@9803F000\0"                  \
   "mod_fdt=fdt addr $fdt_loadaddr; fdt resize;fdt set $tx_path tx-driving $tx_driving;fdt set $tx_path rx-sensitivity $rx_sensitivity\0"                  \


/* Bootcode Feature: Rescue linux read from USB */
#ifdef CONFIG_RESCUE_FROM_USB
	#define CONFIG_UBOOT_FILE                   "rtd129x_uboot_checksum.bin"
	#define CONFIG_DSM_FIRMWARE                 "rtd129x_syno_dsm.bin"
	#define CONFIG_SYNO_DTB                     "rtd129x_syno_dtb.bin"
#endif /* CONFIG_RESCUE_FROM_USB */

#endif /* __CONFIG_RTK_RTD129x_DS218_PARAMETER */

