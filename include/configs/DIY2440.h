/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <garyj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the SAMSUNG SMDK2410 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* LED Configuration Options */
#define CONFIG_DIY2440_LED 1

/* ASM Debug Options */
#define CONFIG_ASM_DEBUG 1
//#define DEBUG

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM920T		1	/* This is an ARM920T Core	*/
//#define	CONFIG_S3C2440		1	/* in a SAMSUNG S3C2410 SoC     */
//#define CONFIG_DIY2440		1	/* on a SAMSUNG SMDK2410 Board  */

#define	CONFIG_S3C2440		1	/* in a SAMSUNG S3C2440 SoC     */
#define CONFIG_DIY2440		1	/* on a SAMSUNG DIY2440 Board  */

/* input clock of PLL */
#define CONFIG_SYS_CLK_FREQ	12000000/* the SMDK2410 has 12MHz input clock */


//#define USE_920T_MMU		1
//#undef CONFIG_USE_IRQ			/* we don't need IRQ/FIQ stuff */
#define CONFIG_ENABLE_MMU
#define CONFIG_USE_IRQ
#define CONFIG_USB_DEVICE
#define CONFIG_CMD_DNW

#define CONFIG_USB_OHCI
#define CONFIG_USB_STORAGE
#define CONFIG_CMD_USB

#define CONFIG_CMD_DATE
/*
 * Size of malloc() pool
 */
//#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 128*1024)
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 1*1024*1024)
#define CONFIG_SYS_GBL_DATA_SIZE	512 /* size in bytes reserved for initial data */

/*
 * Hardware drivers
 */
//#define CONFIG_CMD_NET 1
#define CONFIG_NET_MULTI
#define CONFIG_NET_RETRY_COUNT	20
#define CONFIG_DRIVER_DM9000	1
#define CONFIG_DM9000_BASE	0x20000000
#define DM9000_IO	CONFIG_DM9000_BASE
#define DM9000_DATA	(CONFIG_DM9000_BASE + 4)
#define CONFIG_DM9000_USE_16BIT	1
#define CONFIG_DM9000_NO_SROM	1

/*
 * select serial console configuration
 */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1          1	/* we use SERIAL 1 on SMDK2410 */

/************************************************************
 * RTC
 ************************************************************/
#define	CONFIG_RTC_S3C24X0	1

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200


/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME


/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#define CONFIG_CMD_CACHE
#define CONFIG_CMD_DATE
#define CONFIG_CMD_ELF
#define CONFIG_CMD_PING
#define CONFIG_CMD_NAND
#define CONFIG_CMD_YAFFS
#define CONFIG_YAFFS_SKIPFB

#define CONFIG_CMD_MTDPARTS
//#define CONFIG_CMD_UBI 1
//#define CONFIG_CMD_UBIFS 1
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
//#define CONFIG_LZO 1
//#define CONFIG_RBTREE 1
#define MTDIDS_DEFAULT "nand0=nandflash0"
#define MTDPARTS_DEFAULT "mtdparts=nandflash0:512k(u-boot),512k(param),5m(kernel),-(file-system)"

/* support SD card */
#define CONFIG_CMD_MMC
#define CONFIG_MMC
#define CONFIG_MMC_S3C
#define CONFIG_MMC_WIDE
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION

/* tag list */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_CMDLINE_TAG

#define CONFIG_BOOTDELAY	5	
/*#define CONFIG_BOOTARGS	"root=ramfs devfs=mount console=ttySA0,9600" */
/*#define CONFIG_ETHADDR	08:00:3e:26:0a:5b */
//#define CONFIG_BOOTARGS	"root=/dev/nfs nfsroot=192.168.199.154:/home/shift/work/nfs/rootfs \ 
#define CONFIG_BOOTARGS	"noinitrd root=/dev/mtdblock3 init=/linuxrc console=ttySAC0,115200" 
#define CONFIG_ETHADDR	08:90:00:A0:90:90 
#define CONFIG_NETMASK          255.255.255.0
#define CONFIG_IPADDR		192.168.199.110
#define CONFIG_SERVERIP		192.168.199.154
#define CONFIG_GATEWAYIP	192.168.199.1
//#define CONFIG_DM9000_DEBUG 1
#define CONFIG_BOOTFILE	"uImage"
#define CONFIG_BOOTCOMMAND	"mmc init; sleep 5;fatload mmc 0:1 30008000 uImage; bootm"
/*#define CONFIG_BOOTFILE	"elinos-lart" */
/*#define CONFIG_BOOTCOMMAND	"tftp; bootm" */

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200		/* speed to run kgdb serial port */
/* what's this ? it's not used anywhere */
#define CONFIG_KGDB_SER_INDEX	1		/* which serial port to use */
#endif

/*
 * Miscellaneous configurable options
 */
#define	CONFIG_SYS_LONGHELP				/* undef to save memory		*/
#define	CONFIG_SYS_PROMPT		"DIY2440 # "	/* Monitor Command Prompt	*/
#define	CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size	*/
#define	CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16) /* Print Buffer Size */
#define	CONFIG_SYS_MAXARGS		16		/* max number of command args	*/
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size	*/
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE


#define CONFIG_SYS_MEMTEST_START	0x30000000	/* memtest works on	*/
#define CONFIG_SYS_MEMTEST_END		0x33F00000	/* 63 MB in DRAM	*/

#define	CONFIG_SYS_LOAD_ADDR		0x30008000	/* default load address	*/

#define	CONFIG_SYS_HZ			1000

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(512*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1	   /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1		0x30000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x04000000 /* 64 MB */

#define PHYS_FLASH_1		0x00000000 /* Flash Bank #1 */

#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

#if 0
#define CONFIG_AMD_LV400	1	/* uncomment this if you have a LV400 flash */
#endif
#if 0
#define CONFIG_AMD_LV800	1	/* uncomment this if you have a LV800 flash */
#endif
#define CONFIG_MX_LV160 1

#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of memory banks */

#ifdef CONFIG_MX_LV160
#define PHYS_FLASH_SIZE		0x00200000
#define CONFIG_SYS_MAX_FLASH_SECT	(35)
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + 0x080000)
#endif

#ifdef CONFIG_AMD_LV800
#define PHYS_FLASH_SIZE		0x00100000 /* 1MB */
#define CONFIG_SYS_MAX_FLASH_SECT	(19)	/* max number of sectors on one chip */
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + 0x0F0000) /* addr of environment */
#endif
#ifdef CONFIG_AMD_LV400
#define PHYS_FLASH_SIZE		0x00080000 /* 512KB */
#define CONFIG_SYS_MAX_FLASH_SECT	(11)	/* max number of sectors on one chip */
#define CONFIG_ENV_ADDR		(CONFIG_SYS_FLASH_BASE + 0x070000) /* addr of environment */
#endif

/* timeout values are in ticks */
#define CONFIG_SYS_FLASH_ERASE_TOUT	(5*CONFIG_SYS_HZ) /* Timeout for Flash Erase */
#define CONFIG_SYS_FLASH_WRITE_TOUT	(5*CONFIG_SYS_HZ) /* Timeout for Flash Write */

//#define	CONFIG_ENV_IS_IN_FLASH	1
//#define CONFIG_ENV_SIZE		0x10000	/* Total Size of Environment Sector */
#define	CONFIG_ENV_IS_IN_NAND	1
#define	CONFIG_ENV_OFFSET	0x80000
#define CONFIG_ENV_SIZE	0x80000
#if defined(CONFIG_CMD_NAND)
#define CONFIG_NAND_S3C2440
#define CONFIG_SYS_NAND_BASE	0x4E000000
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_64BIT_VSPRINTF
#define CONFIG_MTD_NAND_BERIFY_WRITE
//#define CONFIG_NAND_HWECC
#endif
#define CONFIG_UBOOT_SIZE	0x80000

#endif	/* __CONFIG_H */
