/* SPDX-License-Identifier: GPL-2.0-or-later */

/*
 * NOTE: The layout of the GNVS structure below must match the layout in
 * soc/amd/stoneyridge/include/soc/nvs.h !!!
 *
 */

Field (GNVS, ByteAcc, NoLock, Preserve)
{
	/* Miscellaneous */
	PM1I,	64,	// 0x00 - 0x07 - System Wake Source - PM1 Index
	GPEI,	64,	// 0x08 - 0x0f - GPE Wake Source
	TMPS,	8,	// 0x10 - Temperature Sensor ID
	TCRT,	8,	// 0x11 - Critical Threshold
	TPSV,	8,	// 0x12 - Passive Threshold
	Offset (0x20),  // 0x20 - AOAC Device Enables
	, 5,
	IC0E,	1,	//        I2C0, 5
	IC1E,	1,	//        I2C1, 6
	IC2E,	1,	//        I2C2, 7
	IC3E,	1,	//        I2C3, 8
	, 2,
	UT0E,	1,	//        UART0, 11
	UT1E,	1,	//        UART1, 12
	, 2,
	ST_E,	1,	//        SATA, 15
	, 2,
	EHCE,	1,	//        EHCI, 18
	, 4,
	XHCE,	1,	//        XCHI, 23
	SD_E,	1,	//        SD, 24
	, 2,
	ESPI,	1,	//        ESPI, 27
	, 4,
	FW00,	16,	// 0x24 - xHCI FW ROM addr, boot RAM
	FW02,	16,	// 0x26 - xHCI FW ROM addr, Instruction RAM
	FW01,	32,	// 0x28 - xHCI FW RAM addr, boot RAM
	FW03,	32,	// 0x2c - xHCI FW RAM addr, Instruction RAM
	EH10,	32,	// 0x30 - EHCI BAR
}
