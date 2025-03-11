/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef GPIO_NAMES_APOLLOLAKE_H
#define GPIO_NAMES_APOLLOLAKE_H

#include "gpio_groups.h"

/*
 * Names prefixed with an *asterisk are the default.
 * (if it's the first column, GPIO is the default, no matter the name)
 */

static const char *const apl_group_north_names[] = {
	"*GPIO_0",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_1",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_2",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_3",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_4",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_5",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_6",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_7",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_8",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_9",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_10",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_11",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_12",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_13",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_14",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_15",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_16",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_17",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_18",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_19",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_20",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_21",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_22",	"n/a",		"n/a",	"n/a",	"n/a",	"SATA_GP0",
	"*GPIO_23",	"n/a",		"n/a",	"n/a",	"n/a",	"SATA_GP1",
	"*GPIO_24",	"n/a",		"n/a",	"n/a",	"n/a",	"SATA_DEVSLP0",
	"*GPIO_25",	"n/a",		"n/a",	"n/a",	"n/a",	"SATA_DEVSLP1",
	"*GPIO_26",	"n/a",		"n/a",	"n/a",	"n/a",	"SATA_LEDN",
	"*GPIO_27",	"n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_28",	"n/a",	"ISH_GPIO_10",	"n/a",	"n/a",	"n/a",
	"*GPIO_29",	"n/a",	"ISH_GPIO_11",	"n/a",	"n/a",	"n/a",
	"*GPIO_30",	"ISH_GPIO_12",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_31",	"ISH_GPIO_13",	"n/a",	"n/a",	"n/a",	"SUSCLK1",
	"*GPIO_32",	"ISH_GPIO_14",	"n/a",	"n/a",	"n/a",	"SUSCLK2",
	"*GPIO_33",	"ISH_GPIO_15",	"n/a",	"n/a",	"n/a",	"SUSCLK3",
	"*GPIO_34",	"PWM0",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_35",	"PWM1",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_36",	"PWM2",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_37",	"PWM3",		"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_38", "LPSS_UART0_RXD",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_39", "LPSS_UART0_TXD",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_40", "LPSS_UART0_RTS_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_41", "LPSS_UART0_CTS_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_42", "LPSS_UART1_RXD",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_43", "LPSS_UART1_TXD",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_44", "LPSS_UART1_RTS_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_45", "LPSS_UART1_CTS_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_46", "LPSS_UART2_RXD",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_47", "LPSS_UART2_TXD",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_48", "LPSS_UART2_RTS_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_49", "LPSS_UART2_CTS_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_62",	"GP_CAMERASB0",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_63",	"GP_CAMERASB1",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_64",	"GP_CAMERASB2",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_65",	"GP_CAMERASB3",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_66",	"GP_CAMERASB4",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_67",	"GP_CAMERASB5",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_68",	"GP_CAMERASB6",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_69",	"GP_CAMERASB7",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_70",	"GP_CAMERASB8",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_71",	"GP_CAMERASB9",	"n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_72",	"GP_CAMERASB10","n/a",	"n/a",	"n/a",	"n/a",
	"*GPIO_73",	"GP_CAMERASB11","n/a",	"n/a",	"n/a",	"n/a",
	"TCK",		"*JTAG_TCK",	"n/a",	"n/a",	"n/a",	"n/a",
	"TRST_B",	"*JTAG_TRST_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"TMS",		"*JTAG_TMS",	"n/a",	"n/a",	"n/a",	"n/a",
	"TDI",		"*JTAG_TDI",	"n/a",	"n/a",	"n/a",	"n/a",
	"CX_PMODE",	"*JTAG_PMODE",	"n/a",	"n/a",	"n/a",	"n/a",
	"CX_PREQ_B",	"*JTAG_PREQ_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"JTAGX"	,	"*JTAGX",	"n/a",	"n/a",	"n/a",	"n/a",
	"CX_PRDY_B",	"*JTAG_PRDY_N",	"n/a",	"n/a",	"n/a",	"n/a",
	"TDO",		"*JTAG_TDO",	"n/a",	"n/a",	"n/a",	"n/a",
	"CNV_BRI_DT",	"*GPIO_216",	"n/a",	"n/a",	"n/a",	"n/a",
	"CNV_BRI_RSP",	"*GPIO_217",	"n/a",	"n/a",	"n/a",	"n/a",
	"CNV_RGI_DT",	"*GPIO_218",	"n/a",	"n/a",	"n/a",	"n/a",
	"CNV_RGI_RSP",	"*n/a",		"n/a",	"n/a",	"n/a",	"n/a",
	"SVID0_ALERT_B","*SVID0_ALERT_N","n/a",	"n/a",	"n/a",	"n/a",
	"SVID0_DATA",	"*SVID0_DATA",	"n/a",	"n/a",	"n/a",	"n/a",
	"SVID0_CLK",	"*SVID0_CLK",	"n/a",	"n/a",	"n/a",	"n/a",
};

static const char *const apl_group_northwest_names[] = {
	"GPIO_187",	 "*DDI0_DDC_SDA",	"n/a",		"n/a",
	"GPIO_188",	 "*DDI0_DDC_SCL",	"n/a",		"n/a",
	"GPIO_189",	 "*DDI1_DDC_SDA",	"n/a",		"n/a",
	"GPIO_190",	 "*DDI1_DDC_SCL",	"n/a",		"n/a",
	"GPIO_191",	 "*MIPI_I2C_SDA",	"n/a",		"n/a",
	"GPIO_192",	 "*MIPI_I2C_SCL",	"n/a",		"n/a",
	"GPIO_193",	 "*PNL0_VDDEN",		"n/a",		"n/a",
	"GPIO_194",	 "*PNL0_BKLTEN",	"n/a",		"n/a",
	"GPIO_195",	 "*PNL0_BKLTCTL",	"n/a",		"n/a",
	"GPIO_196",	 "*PNL1_VDDEN",		"n/a",		"n/a",
	"GPIO_197",	 "*PNL1_BKLTEN",	"n/a",		"n/a",
	"GPIO_198",	 "*PNL1_BKLTCTL",	"n/a",		"n/a",
	"GPIO_199",	 "*GPIO_199",		"DDI1_HPD",	"n/a",
	"GPIO_200",	 "*GPIO_200",		"DDI0_HPD",	"n/a",
	"GPIO_201",	 "*MDSI_A_TE",		"n/a",		"n/a",
	"GPIO_202",	 "*MDSI_C_TE",		"n/a",		"n/a",
	"GPIO_203",	 "*USB_OC0_N",		"n/a",		"n/a",
	"GPIO_204",	 "*USB_OC1_N",		"n/a",		"n/a",
	"PMC_SPI_FS0",	 "*PMC_SPI_FS0",	"n/a",		"n/a",
	"PMC_SPI_FS1",	 "*PMC_SPI_FS1",	"DDI2_HPD",	"n/a",
	"PMC_SPI_FS2",	 "*PMC_SPI_FS2",	"FST_SPI_CS2_N","n/a",
	"PMC_SPI_RXD",	 "*PMC_SPI_RXD",	"n/a",		"n/a",
	"PMC_SPI_TXD",	 "*PMC_SPI_TXD",	"n/a",		"n/a",
	"PMC_SPI_CLK",	 "*PMC_SPI_CLK",	"n/a",		"n/a",
	"PMIC_PWRGOOD",	 "*n/a",		"n/a",		"n/a",
	"PMIC_RESET_B",	 "*GPIO_223",		"n/a",		"n/a",
	"GPIO_213",	 "*GPIO_213",		"n/a",		"n/a",
	"GPIO_214",	 "*GPIO_214",		"n/a",		"n/a",
	"GPIO_215",	 "*GPIO_215",		"n/a",		"n/a",
	"PMIC_THERMTRIP_B", "*THERMTRIP_N",	"n/a",		"n/a",
	"PMIC_STDBY",	 "*GPIO_224",		"n/a",		"n/a",
	"PROCHOT_B",	 "*PROCHOT_N",		"n/a",		"n/a",
	"PMIC_I2C_SCL",	 "*PMIC_I2C_SCL",	"n/a",		"n/a",
	"PMIC_I2C_SDA",	 "*PMIC_I2C_SDA",	"n/a",		"n/a",
	"*GPIO_74",	 "AVS_I2S1_MCLK" ,	"n/a",		"n/a",
	"*GPIO_75",	 "AVS_I2S1_BCLK",	"n/a",		"n/a",
	"*GPIO_76",	 "AVS_I2S1_WS_SYNC",	"n/a",		"n/a",
	"*GPIO_77",	 "AVS_I2S1_SDI",	"n/a",		"n/a",
	"*GPIO_78",	 "AVS_I2S1_SDO",	"n/a",		"n/a",
	"*GPIO_79",	 "AVS_DMIC_CLK_A1",	"AVS_I2S4_BCLK","n/a",
	"*GPIO_80",	 "AVS_DMIC_CLK_B1",	"AVS_I2S4_WS_SYNC","n/a",
	"*GPIO_81",	 "AVS_DMIC_DATA_1",	"AVS_I2C4_SDI",	"n/a",
	"*GPIO_82",	 "AVS_DMIC_CLK_AB2",	"AVS_I2S4_SDO",	"n/a",
	"*GPIO_83",	 "AVS_DMIC_DATA_2",	"n/a",		"n/a",
	"*GPIO_84",	 "AVS_I2S2_MCLK",	"AVS_HDA_RST_N","n/a",
	"*GPIO_85",	 "AVS_I2S2_BCLK",	"n/a",		"n/a",
	"*GPIO_86",	 "AVS_I2S2_WS_SYNC",	"n/a",		"n/a",
	"*GPIO_87",	 "AVS_I2S2_SDI",	"n/a",		"n/a",
	"*GPIO_88",	 "AVS_I2S2_SDO",	"n/a",		"n/a",
	"*GPIO_89",	 "AVS_I2S3_BCLK",	"n/a",		"n/a",
	"*GPIO_90",	 "AVS_I2S3_WS_SYNC",	"n/a",		"n/a",
	"*GPIO_91",	 "AVS_I2S3_SDI",	"n/a",		"n/a",
	"*GPIO_92",	 "AVS_I2S3_SDO",	"n/a",		"n/a",
	"GPIO_97",	 "*FST_SPI_CS0_N",	"n/a",		"n/a",
	"GPIO_98",	 "*FST_SPI_CS1_N",	"n/a",		"n/a",
	"GPIO_99",	 "*FST_SPI_MOSI_IO0",	"n/a",		"n/a",
	"GPIO_100",	 "*FST_SPI_MISO_IO1",	"n/a",		"n/a",
	"GPIO_101",	 "*FST_SPI_IO2",	"n/a",		"n/a",
	"GPIO_102",	 "*FST_SPI_IO3",	"n/a",		"n/a",
	"GPIO_103",	 "*FST_SPI_CLK",	"n/a",		"n/a",
	"FST_SPI_CLK_FB", "*n/a",		"n/a",		"n/a",
	"*GPIO_104",	 "SIO_SPI_0_CLK",	"n/a",		"n/a",
	"*GPIO_105",	 "SIO_SPI_0_FS0",	"n/a",		"n/a",
	"*GPIO_106",	 "SIO_SPI_0_FS1",	"n/a",		"FST_SPI_CS2_N",
	"*GPIO_109",	 "SIO_SPI_0_RXD",	"n/a",		"n/a",
	"*GPIO_110",	 "SIO_SPI_0_TXD",	"n/a",		"n/a",
	"*GPIO_111",	 "SIO_SPI_1_CLK",	"n/a",		"n/a",
	"*GPIO_112",	 "SIO_SPI_1_FS0",	"n/a",		"n/a",
	"*GPIO_113",	 "SIO_SPI_1_FS1",	"n/a",		"n/a",
	"*GPIO_116",	 "SIO_SPI_1_RXD",	"n/a",		"n/a",
	"*GPIO_117",	 "SIO_SPI_1_TXD",	"n/a",		"n/a",
	"*GPIO_118",	 "SIO_SPI_2_CLK",	"n/a",		"n/a",
	"*GPIO_119",	 "SIO_SPI_2_FS0",	"n/a",		"n/a",
	"*GPIO_120",	 "SIO_SPI_2_FS1",	"n/a",		"n/a",
	"*GPIO_121",	 "SIO_SPI_2_FS2",	"n/a",		"n/a",
	"*GPIO_122",	 "SIO_SPI_2_RXD",	"n/a",		"n/a",
	"*GPIO_123",	 "SIO_SPI_2_TXD",	"n/a",		"n/a",
};

static const char *const apl_group_west_names[] = {
	"*GPIO_124",	"LPSS_I2C0_SDA",	"n/a",		"n/a",
	"*GPIO_125",	"LPSS_I2C0_SCL",	"n/a",		"n/a",
	"*GPIO_126",	"LPSS_I2C1_SDA",	"n/a",		"n/a",
	"*GPIO_127",	"LPSS_I2C1_SCL",	"n/a",		"n/a",
	"*GPIO_128",	"LPSS_I2C2_SDA",	"n/a",		"n/a",
	"*GPIO_129",	"LPSS_I2C2_SCL",	"n/a",		"n/a",
	"*GPIO_130",	"LPSS_I2C3_SDA",	"n/a",		"n/a",
	"*GPIO_131",	"LPSS_I2C3_SCL",	"n/a",		"n/a",
	"*GPIO_132",	"LPSS_I2C4_SDA",	"n/a",		"n/a",
	"*GPIO_133",	"LPSS_I2C4_SCL",	"n/a",		"n/a",
	"*GPIO_134",	"LPSS_I2C5_SDA","ISH_I2C0_SDA",		"n/a",
	"*GPIO_135",	"LPSS_I2C5_SCL","ISH_I2C0_SCL",		"n/a",
	"*GPIO_136",	"LPSS_I2C6_SDA","ISH_I2C1_SDA",		"n/a",
	"*GPIO_137",	"LPSS_I2C6_SCL","ISH_I2C1_SCL",		"n/a",
	"*GPIO_138",	"LPSS_I2C7_SDA","ISH_I2C2_SDA",		"n/a",
	"*GPIO_139",	"LPSS_I2C7_SCL","ISH_I2C2_SCL",		"n/a",
	"*GPIO_146",	"ISH_GPIO_0",	"AVS_I2S6_BCLK",	"AVS_HDA_BCLK",
	"*GPIO_147",	"ISH_GPIO_1",	"AVS_I2S6_WS_SYNC",	"AVS_HDA_WS_SYNC",
	"*GPIO_148",	"ISH_GPIO_2",	"AVS_I2S6_SDI",		"AVS_HDA_SDI",
	"*GPIO_149",	"ISH_GPIO_3",	"AVS_I2S6_SDO",		"AVS_HDA_SDO",
	"*GPIO_150",	"ISH_GPIO_4",	"AVS_I2S5_BCLK",	"LPSS_UART2_RXD",
	"*GPIO_151",	"ISH_GPIO_5",	"AVS_I2S5_WS_SYNC",	"LPSS_UART2_TXD",
	"*GPIO_152",	"ISH_GPIO_6",	"AVS_I2S5_SDI",		"LPSS_UART2_RTS_B",
	"*GPIO_153",	"ISH_GPIO_7",	"AVS_I2S5_SDO",		"LPSS_UART2_CTS_B",
	"*GPIO_154",	"ISH_GPIO_8",		"n/a",		"n/a",
	"*GPIO_155",	"ISH_GPIO_9",		"SPKR",		"n/a",
	"GPIO_209",	"*PCIE_CLKREQ0_N",	"MODEM_CLKREQ", "n/a",
	"GPIO_210",	"*PCIE_CLKREQ1_N",	"n/a",		"n/a",
	"GPIO_211",	"*PCIE_CLKREQ2_N",	"n/a",		"n/a",
	"GPIO_212",	"*PCIE_CLKREQ3_N",	"n/a",		"n/a",
	"OSC_CLK_OUT_0","*OSC_CLK_OUT_0",	"n/a",		"n/a",
	"OSC_CLK_OUT_1","*OSC_CLK_OUT_1",	"n/a",		"n/a",
	"OSC_CLK_OUT_2","*OSC_CLK_OUT_2",	"n/a",		"n/a",
	"OSC_CLK_OUT_3","*OSC_CLK_OUT_3",	"n/a",		"n/a",
	"OSC_CLK_OUT_4","*OSC_CLK_OUT_4",	"n/a",		"n/a",
	"*PMU_AC_PRESENT","PMU_AC_PRESENT",	"n/a",		"n/a",
	"PMU_BATLOW_B",	"*PMU_BATLOW_N",	"n/a",		"n/a",
	"PMU_PLTRST_B",	"*PMU_PLTRST_N",	"n/a",		"n/a",
	"PMU_PWRBTN_B",	"*PMU_PWRBTN_N",	"n/a",		"n/a",
	"PMU_RESETBUTTON_B",	"*PMU_RSTBTN_N",	"n/a",	"n/a",
	"PMU_SLP_S0_B",	"*PMU_SLP_S0_N",	"n/a",		"n/a",
	"PMU_SLP_S3_B",	"*PMU_SLP_S3_N",	"n/a",		"n/a",
	"PMU_SLP_S4_B",	"*PMU_SLP_S4_N",	"n/a",		"n/a",
	"PMU_SUSCLK",	"*PMU_SUSCLK",		"n/a",		"n/a",
	"*PMU_WAKE_B",	"PMU_WAKE_B/EMMC_PWR_EN_N","n/a",	"n/a",
	"SUS_STAT_B",	"*SUS_STAT_B",		"n/a",		"n/a",
	"SUSPWRDNACK",	"*SUSPWRDNACK",		"n/a",		"n/a",
};

static const char *const apl_group_southwest_names[] = {
	"*GPIO_205",		"PCIE_WAKE0_N",		"n/a",
	"*GPIO_206",		"PCIE_WAKE1_N",		"n/a",
	"*GPIO_207",		"PCIE_WAKE2_N",		"n/a",
	"*GPIO_208",		"PCIE_WAKE3_N",		"n/a",
	"GPIO_156",		"*EMMC_CLK",		"n/a",
	"GPIO_157",		"*EMMC_D0",		"n/a",
	"GPIO_158",		"*EMMC_D1",		"n/a",
	"GPIO_159",		"*EMMC_D2",		"n/a",
	"GPIO_160",		"*EMMC_D3",		"n/a",
	"GPIO_161",		"*EMMC_D4",		"n/a",
	"GPIO_162",		"*EMMC_D5",		"n/a",
	"GPIO_163",		"*EMMC_D6",		"n/a",
	"GPIO_164",		"*EMMC_D7",		"n/a",
	"GPIO_165",		"*EMMC_CMD",		"n/a",
	"*GPIO_166",		"GPIO_166",		"n/a",
	"*GPIO_167",		"GPIO_167",		"n/a",
	"*GPIO_168",		"GPIO_168",		"n/a",
	"*GPIO_169",		"GPIO_169",		"n/a",
	"*GPIO_170",		"GPIO_170",		"n/a",
	"*GPIO_171",		"GPIO_171",		"n/a",
	"*GPIO_172",		"SDCARD_CLK",		"n/a",
	"*GPIO_179",		"n/a",			"n/a",
	"*GPIO_173",		"SDCARD_D0",		"n/a",
	"*GPIO_174",		"SDCARD_D1",		"n/a",
	"*GPIO_175",		"SDCARD_D2",		"n/a",
	"*GPIO_176",		"SDCARD_D3",		"n/a",
	"*GPIO_177",		"SDCARD_CD_B",		"n/a",
	"*GPIO_178",		"SDCARD_CMD",		"n/a",
	"*GPIO_186",		"SDCARD_LVL_WP",	"n/a",
	"GPIO_182",		"*EMMC_RCLK",		"n/a",
	"GPIO_183",		"GPIO_183",		"n/a",
	"*SMB_ALERTB",		"SMB_ALERT_N",		"n/a",
	"*SMB_CLK",		"SMB_CLK",		"LPSS_I2C7_SCL",
	"*SMB_DATA",		"SMB_DATA",		"LPSS_I2C7_SDA",
	"*LPC_ILB_SERIRQ",	"LPC_ILB_SERIRQ",	"n/a",
	"*LPC_CLKOUT0",		"LPC_CLKOUT0",		"n/a",
	"*LPC_CLKOUT1",		"LPC_CLKOUT1",		"n/a",
	"*LPC_AD0",		"LPC_AD0",		"n/a",
	"*LPC_AD1",		"LPC_AD1",		"n/a",
	"*LPC_AD2",		"LPC_AD2",		"n/a",
	"*LPC_AD3",		"LPC_AD3",		"n/a",
	"*LPC_CLKRUNB",		"LPC_CLKRUNB",		"n/a",
	"*LPC_FRAMEB",		"LPC_FRAMEB",		"n/a",
};

static const struct gpio_group apl_group_north = {
	.display	= "------- GPIO Group North -------",
	.pad_count	= ARRAY_SIZE(apl_group_north_names) / 6,
	.func_count	= 6,
	.pad_names	= apl_group_north_names,
};

static const struct gpio_group *const apl_community_north_groups[] = {
	&apl_group_north,
};

static const struct gpio_community apl_community_north = {
	.name		= "----- GPIO Community North -----",
	.pcr_port_id	= 0xc5,
	.group_count	= ARRAY_SIZE(apl_community_north_groups),
	.groups		= apl_community_north_groups,
};

static const struct gpio_group apl_group_northwest = {
	.display	= "----- GPIO Group NorthWest -----",
	.pad_count	= ARRAY_SIZE(apl_group_northwest_names) / 4,
	.func_count	= 4,
	.pad_names	= apl_group_northwest_names,
};

static const struct gpio_group *const apl_community_northwest_groups[] = {
	&apl_group_northwest,
};

static const struct gpio_community apl_community_northwest = {
	.name		= "--- GPIO Community NorthWest ---",
	.pcr_port_id	= 0xc4,
	.group_count	= ARRAY_SIZE(apl_community_northwest_groups),
	.groups		= apl_community_northwest_groups,
};

static const struct gpio_group apl_group_west = {
	.display	= "-------- GPIO Group West -------",
	.pad_count	= ARRAY_SIZE(apl_group_west_names) / 4,
	.func_count	= 4,
	.pad_names	= apl_group_west_names,
};

static const struct gpio_group *const apl_community_west_groups[] = {
	&apl_group_west,
};

static const struct gpio_community apl_community_west = {
	.name		= "------ GPIO Community West -----",
	.pcr_port_id	= 0xc7,
	.group_count	= ARRAY_SIZE(apl_community_west_groups),
	.groups		= apl_community_west_groups,
};

static const struct gpio_group apl_group_southwest = {
	.display	= "----- GPIO Group SouthWest -----",
	.pad_count	= ARRAY_SIZE(apl_group_southwest_names) / 3,
	.func_count	= 3,
	.pad_names	= apl_group_southwest_names,
};

static const struct gpio_group *const apl_community_southwest_groups[] = {
	&apl_group_southwest,
};

static const struct gpio_community apl_community_southwest = {
	.name		= "--- GPIO Community SouthWest ---",
	.pcr_port_id	= 0xc0,
	.group_count	= ARRAY_SIZE(apl_community_southwest_groups),
	.groups		= apl_community_southwest_groups,
};

static const struct gpio_community *const apl_communities[] = {
	&apl_community_north, &apl_community_northwest,
	&apl_community_west, &apl_community_southwest,
};

#endif
