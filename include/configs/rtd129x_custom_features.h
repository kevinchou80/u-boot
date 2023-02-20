#ifndef __CONFIG_RTD129X_CUSTOM_FEATURES_H
#define __CONFIG_RTD129X_CUSTOM_FEATURES_H

#if defined(CONFIG_SYS_RTK_EMMC_FLASH)
#define CONFIG_FLASH_TYPE					   "RTK_FLASH_EMMC"
#define CONFIG_TEE_OS_DRM					   "FALSE"
#endif

#if defined(CONFIG_SYS_RTK_SPI_FLASH)
#define CONFIG_FLASH_TYPE					   "RTK_FLASH_SPI"
#endif

#if defined(CONFIG_SYS_RTK_EMMC_FLASH)
/* Factory start address and size in eMMC */
#define CONFIG_FACTORY_START	0x220000	/* For eMMC */
#define CONFIG_FACTORY_SIZE	0x400000	/* For eMMC */
#define CONFIG_FW_TABLE_SIZE    0x8000		/* For eMMC */
#endif

#ifdef CONFIG_SYS_RTK_SPI_FLASH
	#define CONFIG_FACTORY_BASE                    0x7f0000
	#define CONFIG_FACTORY_SIZE                    0x00f000
#endif

#ifndef CONFIG_SYS_PANEL_PARAMETER
	#define CONFIG_SYS_PANEL_PARAMETER
#endif

/* MMC */
#ifdef CONFIG_RTK_MMC_DRIVER
	#define CONFIG_MMC
/* 	#ifdef CONFIG_SYS_RTK_SPI_FLASH*/
 	#define CONFIG_RTK_EMMC_TRADITIONAL_MODE 
/* 	#endif*/
	#ifndef CONFIG_PARTITIONS
		#define CONFIG_PARTITIONS
	#endif
	#define CONFIG_DOS_PARTITION
	#define CONFIG_GENERIC_MMC
	#define CONFIG_RTK_MMC
	#define CONFIG_CMD_MMC
	#define USE_SIMPLIFY_READ_WRITE
	#define CONFIG_SHA256
#endif

/* ENV */
#if defined(CONFIG_SYS_RTK_EMMC_FLASH)
#undef	CONFIG_ENV_IS_NOWHERE
#ifdef CONFIG_SYS_FACTORY
	#define CONFIG_ENV_IS_IN_FACTORY
	/* #define CONFIG_SYS_FACTORY_READ_ONLY */
#endif
#endif

#ifdef CONFIG_SYS_RTK_SPI_FLASH
	#undef CONFIG_ENV_IS_NOWHERE
	#undef CONFIG_ENV_SIZE
	#define CONFIG_ENV_IS_IN_SPI
	#undef CONFIG_ENV_ADDR
	#define CONFIG_SYS_FLASH_BASE                  SPI_RBUS_BASE_ADDR
	#define CONFIG_ENV_OFFSET                      0x10000
	#define CONFIG_ENV_ADDR                        (CONFIG_SYS_FLASH_BASE + CONFIG_ENV_OFFSET)
	#define CONFIG_ENV_SIZE                        0x10000
	#define ENV_IS_EMBEDDED
#endif

/* SPI */
#define CONFIG_RTKSPI
#define CONFIG_CMD_RTKSPI
#ifndef CONFIG_LZMA
	#define CONFIG_LZMA
#endif
#define CONFIG_CMD_LZMADEC

/* SATA */
#define CONFIG_RTK_AHSATA
#define CONFIG_CMD_SATA

#ifdef CONFIG_CMD_SATA
	#define CONFIG_RTK_AHSATA
	#define CONFIG_SYS_SATA_MAX_DEVICE      1
	#define CONFIG_DWC_AHSATA_BASE_ADDR     0x9803F000
	#define CONFIG_LBA48
	#define CONFIG_SYS_64BIT_LBA
	#define CONFIG_LIBATA
	#define CONFIG_PORT0_POWER_PIN			56
#endif

#define CONFIG_SYS_NO_BL31

/* Boot Revision */
#define CONFIG_COMPANY_ID 		"0000"
#define CONFIG_BOARD_ID         "0705"
#define CONFIG_VERSION          "0000"
/* ========================================================== */
/*
 * SDRAM Memory Map
 * Even though we use two CS all the memory
 * is mapped to one contiguous block
 */
#undef CONFIG_NR_DRAM_BANKS
#undef CONFIG_SYS_SDRAM_BASE
#undef CONFIG_SYS_RAM_DCU1_SIZE

#define ARM_ROMCODE_SIZE			(124*1024)
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE		0x0
#define CONFIG_SYS_RAM_DCU1_SIZE	0x40000000	/* FIXME */
#define CONFIG_FT_RESCUE

#undef  V_NS16550_CLK
#define V_NS16550_CLK			27000000	/* FIXME */


/* Bootcode Feature: Rescue linux read from USB */
#define CONFIG_RESCUE_FROM_USB
#ifdef CONFIG_RESCUE_FROM_USB
	#ifdef CONFIG_SYS_RTK_SPI_FLASH
		#define CONFIG_RESCUE_FROM_USB_VMLINUX		"spi.uImage"
		#define CONFIG_RESCUE_FROM_USB_DTB		    "rescue.spi.dtb"
		#define CONFIG_RESCUE_FROM_USB_ROOTFS		"rescue.root.spi.cpio.gz_pad.img"
		#define CONFIG_RESCUE_FROM_USB_AUDIO_CORE	"bluecore.audio"
	#elif defined(CONFIG_SYS_RTK_EMMC_FLASH)
		#define CONFIG_RESCUE_FROM_USB_VMLINUX		"emmc.uImage"
		#define CONFIG_RESCUE_FROM_USB_DTB		"rescue.emmc.dtb"
		#define CONFIG_RESCUE_FROM_USB_ROOTFS		"rescue.root.emmc.cpio.gz_pad.img"
		#define CONFIG_RESCUE_FROM_USB_AUDIO_CORE	"bluecore.audio"
	#endif
#endif /* CONFIG_RESCUE_FROM_USB */

/*The partition format and file system of ext4*/
#define CONFIG_EFI_PARTITION
#define CONFIG_CMD_GPT
#define CONFIG_PARTITION_UUIDS
#define CONFIG_CMD_EXT4

#define COUNTER_FREQUENCY               27000000 /* FIXME, need to know what impact it will cause */

#define CONFIG_VERSION			"0000"

#undef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE		0x00020000

#define CONFIG_CMD_SHOWVAR

#ifdef CONFIG_CMD_NET
	#undef  CONFIG_IPADDR
	#undef  CONFIG_GATEWAYIP
	#undef  CONFIG_SERVERIP
	/* Network setting */
	#define CONFIG_IPADDR				192.168.1.100
	#define CONFIG_GATEWAYIP			192.168.1.254
	#define CONFIG_SERVERIP				192.168.1.254
#endif


#endif /*__CONFIG_RTD129X_CUSTOM_FEATURES_H */