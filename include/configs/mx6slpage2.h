/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2021 Andreas Kemnade
 *
 * Configuration settings for the Kobo Nia board.
 */
#ifndef __CONFIG_H
#define __CONFIG_H
#include "mx6_common.h"
/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(16 * SZ_1M)
#if 0
#define CONFIG_MXC_UART
#endif
#define CONFIG_MXC_UART_BASE		UART1_BASE
/* I2C Configs */
#ifdef CONFIG_CMD_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_MXC_I2C1		/* enable I2C bus 1 */
#define CONFIG_SYS_I2C_MXC_I2C2		/* enable I2C bus 2 */
#define CONFIG_SYS_I2C_MXC_I2C3		/* enable I2C bus 3 */
#define CONFIG_SYS_I2C_SPEED		  100000
#endif
#define CONFIG_EXTRA_ENV_SETTINGS \
	BOOTENV \
	"console=ttymxc0\0" \
	"fdt_addr_r=0x83000000\0" \
	"kernel_addr_r=0x82000000\0" \
	"loadaddr=0x82000000\0" \
	"ramdisk_addr_r=0x83100000\0" \
	"scriptaddr=0x87000000\0" \
	"initrd_high=0xffffffff\0" \
	"fdt_file=imx6sl-tolino-page2.dtb\0"
/* Physical Memory Map */
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR
#define PHYS_SDRAM_SIZE			SZ_512M
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE
#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)
#define CONFIG_MMCROOT			"/dev/mmcblk0p2"  /* USDHC1 */
/* MMC Configs */
#define CONFIG_SYS_FSL_ESDHC_ADDR	USDHC2_BASE_ADDR
#define CONFIG_SYS_FSL_USDHC_NUM	3
#define CONFIG_SYS_MMC_ENV_DEV		0  /* USDHC2 */
#if 0
#define CONFIG_IMX_THERMAL
#endif
#define CONFIG_IOMUX_LPSR
/* USB Configs */
#ifdef CONFIG_USB
#define CONFIG_MXC_USB_PORTSC		(PORT_PTS_UTMI | PORT_PTS_PTW)
#endif
#include <linux/stringify.h>
#endif				/* __CONFIG_H */
