/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef CFG_GPIO_H
#define CFG_GPIO_H

#include <gpio.h>

/* Pad configuration was generated automatically using intelp2m utility */
static const struct pad_config gpio_table[] = {

	/* ------- GPIO Community 0 ------- */

	/* ------- GPIO Group GPP_A ------- */
	PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_A1, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_A2, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_A3, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_A4, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
	PAD_CFG_GPI_TRIG_OWN(GPP_A7, NONE, PLTRST, OFF, ACPI),
	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_A9, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A10, DN_20K, DEEP, NF1),
	PAD_CFG_GPO(GPP_A11, 0, DEEP),
	PAD_NC(GPP_A12, NONE),
	PAD_CFG_NF(GPP_A13, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_A14, 0, DEEP),
	PAD_CFG_GPO(GPP_A15, 0, DEEP),
	PAD_CFG_GPO(GPP_A16, 0, DEEP),
	PAD_CFG_GPO(GPP_A17, 0, DEEP),
	PAD_CFG_GPO(GPP_A18, 0, DEEP),
	PAD_CFG_GPO(GPP_A19, 0, DEEP),
	PAD_CFG_GPO(GPP_A20, 0, DEEP),
	PAD_CFG_GPO(GPP_A21, 0, DEEP),
	PAD_CFG_GPO(GPP_A22, 0, DEEP),
	PAD_CFG_GPO(GPP_A23, 0, DEEP),

	/* ------- GPIO Group GPP_B ------- */
	PAD_CFG_GPO(GPP_B0, 0, DEEP),
	PAD_CFG_GPO(GPP_B1, 0, DEEP),
	PAD_CFG_GPO(GPP_B2, 0, DEEP),
	PAD_CFG_GPO(GPP_B3, 0, DEEP),
	PAD_CFG_GPO(GPP_B4, 0, DEEP),
	PAD_CFG_NF(GPP_B5, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B6, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B7, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_B8, 0, DEEP),
	PAD_CFG_NF(GPP_B9, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_B10, 0, DEEP),
	PAD_CFG_NF(GPP_B11, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
	PAD_CFG_TERM_GPO(GPP_B14, 1, DN_20K, DEEP),
	PAD_CFG_GPO(GPP_B15, 0, DEEP),
	PAD_CFG_GPO(GPP_B16, 0, DEEP),
	PAD_CFG_GPO(GPP_B17, 0, DEEP),
	PAD_CFG_GPI_SCI(GPP_B18, UP_20K, PLTRST, LEVEL, INVERT),
	PAD_NC(GPP_B19, NONE),
	PAD_CFG_NF(GPP_B20, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_B21, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_B22, DN_20K, DEEP, NF1),
	PAD_CFG_TERM_GPO(GPP_B23, 1, DN_20K, DEEP),

	/* ------- GPIO Community 1 ------- */

	/* ------- GPIO Group GPP_C ------- */
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C1, DN_20K, DEEP, NF1),
	PAD_CFG_TERM_GPO(GPP_C2, 1, DN_20K, DEEP),
	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
	PAD_CFG_GPI_APIC_LOW(GPP_C5, DN_20K, DEEP),
	/* GPP_C6 - RESERVED */
	/* GPP_C7 - RESERVED */
	PAD_CFG_NF(GPP_C8, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C9, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_C10, 0, DEEP),
	PAD_CFG_GPO(GPP_C11, 0, DEEP),
	PAD_CFG_GPO(GPP_C12, 0, DEEP),
	PAD_CFG_GPO(GPP_C13, 0, DEEP),
	PAD_CFG_GPO(GPP_C14, 0, DEEP),
	PAD_CFG_GPO(GPP_C15, 0, DEEP),
	PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_C22, 0, DEEP),
	PAD_CFG_GPO(GPP_C23, 0, DEEP),

	/* ------- GPIO Group GPP_D ------- */
	PAD_CFG_GPO(GPP_D0, 0, DEEP),
	PAD_CFG_GPO(GPP_D1, 0, DEEP),
	PAD_CFG_GPO(GPP_D2, 0, DEEP),
	PAD_CFG_GPO(GPP_D3, 0, DEEP),
	PAD_CFG_GPO(GPP_D4, 0, DEEP),
	PAD_CFG_GPO(GPP_D5, 0, DEEP),
	PAD_CFG_GPO(GPP_D6, 0, DEEP),
	PAD_CFG_GPO(GPP_D7, 0, DEEP),
	PAD_CFG_GPO(GPP_D8, 0, DEEP),
	PAD_CFG_GPO(GPP_D9, 0, DEEP),
	PAD_CFG_GPO(GPP_D10, 0, DEEP),
	PAD_CFG_GPO(GPP_D11, 0, DEEP),
	PAD_CFG_GPO(GPP_D12, 0, DEEP),
	PAD_CFG_GPO(GPP_D13, 0, DEEP),
	PAD_CFG_GPO(GPP_D14, 0, DEEP),
	PAD_CFG_GPO(GPP_D15, 0, DEEP),
	PAD_CFG_GPO(GPP_D16, 0, DEEP),
	PAD_CFG_GPO(GPP_D17, 0, DEEP),
	PAD_CFG_GPO(GPP_D18, 0, DEEP),
	PAD_CFG_GPO(GPP_D19, 0, DEEP),
	PAD_CFG_GPO(GPP_D20, 0, DEEP),
	PAD_CFG_GPO(GPP_D21, 0, DEEP),
	PAD_CFG_GPO(GPP_D22, 0, DEEP),
	PAD_CFG_GPO(GPP_D23, 0, DEEP),

	/* ------- GPIO Group GPP_E ------- */
	PAD_CFG_GPO(GPP_E0, 0, DEEP),
	PAD_CFG_GPO(GPP_E1, 0, DEEP),
	PAD_CFG_NF(GPP_E2, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_E3, 0, DEEP),
	PAD_CFG_GPO(GPP_E4, 0, DEEP),
	PAD_CFG_GPI_SCI(GPP_E5, NONE, PLTRST, EDGE_SINGLE, INVERT),
	PAD_CFG_GPO(GPP_E6, 0, DEEP),
	PAD_CFG_GPI_DUAL_ROUTE(GPP_E7, NONE, PLTRST, LEVEL, NONE, IOAPIC, SCI),
	PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_E9, 0, DEEP),
	PAD_CFG_TERM_GPO(GPP_E10, 1, DN_20K, DEEP),
	PAD_CFG_TERM_GPO(GPP_E11, 1, DN_20K, DEEP),
	PAD_NC(GPP_E12, NONE),
	PAD_CFG_NF(GPP_E13, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
	PAD_CFG_GPI_SMI(GPP_E15, NONE, DEEP, EDGE_SINGLE, INVERT),
	PAD_CFG_GPI_SCI(GPP_E16, NONE, PLTRST, LEVEL, INVERT),
	PAD_CFG_NF(GPP_E17, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_E18, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_E19, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_E20, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_E21, DN_20K, DEEP, NF1),
	PAD_CFG_GPO(GPP_E22, 0, DEEP),
	PAD_CFG_TERM_GPO(GPP_E23, 0, DN_20K, PLTRST),

	/* ------- GPIO Community 2 ------- */

	/* -------- GPIO Group GPD -------- */
	PAD_CFG_NF(GPD0, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD1, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD2, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD3, UP_20K, PWROK, NF1),
	PAD_CFG_NF(GPD4, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD5, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD6, NONE, PWROK, NF1),
	PAD_CFG_GPO(GPD7, 0, DEEP),
	PAD_NC(GPD8, NONE),
	PAD_CFG_NF(GPD9, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD10, NONE, PWROK, NF1),
	PAD_CFG_NF(GPD11, NONE, PWROK, NF1),

	/* ------- GPIO Community 3 ------- */

	/* ------- GPIO Group GPP_F ------- */
	PAD_CFG_GPO(GPP_F0, 0, DEEP),
	PAD_CFG_GPO(GPP_F1, 0, DEEP),
	PAD_CFG_GPO(GPP_F2, 0, DEEP),
	PAD_CFG_GPO(GPP_F3, 0, DEEP),
	PAD_CFG_GPO(GPP_F4, 0, DEEP),
	PAD_CFG_GPO(GPP_F5, 0, DEEP),
	PAD_CFG_GPO(GPP_F6, 0, DEEP),
	PAD_CFG_GPO(GPP_F7, 0, DEEP),
	PAD_CFG_NF(GPP_F8, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_F9, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_F10, 0, DEEP),
	PAD_CFG_GPO(GPP_F11, 0, DEEP),
	PAD_CFG_GPO(GPP_F12, 0, DEEP),
	PAD_CFG_GPI_TRIG_OWN(GPP_F13, NONE, DEEP, OFF, ACPI),
	PAD_CFG_GPI_TRIG_OWN(GPP_F14, NONE, DEEP, OFF, ACPI),
	PAD_CFG_GPI_TRIG_OWN(GPP_F15, NONE, DEEP, OFF, ACPI),
	PAD_CFG_NF(GPP_F16, NONE, DEEP, NF1),
	PAD_CFG_GPO(GPP_F17, 0, DEEP),
	PAD_CFG_GPO(GPP_F18, 0, DEEP),
	PAD_CFG_GPO(GPP_F19, 0, DEEP),
	PAD_CFG_GPO(GPP_F20, 0, DEEP),
	PAD_CFG_GPO(GPP_F21, 0, DEEP),
	PAD_CFG_GPO(GPP_F22, 0, DEEP),
	PAD_CFG_GPO(GPP_F23, 0, DEEP),

	/* ------- GPIO Group GPP_G ------- */
	PAD_CFG_GPO(GPP_G0, 0, DEEP),
	PAD_CFG_GPO(GPP_G1, 0, DEEP),
	PAD_CFG_GPO(GPP_G2, 0, DEEP),
	PAD_CFG_GPO(GPP_G3, 0, DEEP),
	PAD_CFG_GPO(GPP_G4, 0, DEEP),
	PAD_CFG_GPO(GPP_G5, 0, DEEP),
	PAD_CFG_GPO(GPP_G6, 0, DEEP),
	PAD_CFG_GPO(GPP_G7, 0, DEEP),
};

#endif /* CFG_GPIO_H */
