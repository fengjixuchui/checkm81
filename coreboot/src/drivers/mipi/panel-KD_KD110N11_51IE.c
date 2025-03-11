/* SPDX-License-Identifier: GPL-2.0-only */

#include <mipi/panel.h>

struct panel_serializable_data KD_KD110N11_51IE = {
	.edid = {
		.ascii_string = "KD110N11-51IE",
		.manufacturer_name = "KD",
		.panel_bits_per_color = 8,
		.panel_bits_per_pixel = 24,
		.mode = {
			.pixel_clock = 182888,
			.lvds_dual_channel = 0,
			.refresh = 60,
			.ha = 1200, .hbl = 284, .hso = 124, .hspw = 80,
			.va = 1920, .vbl = 134, .vso = 88, .vspw = 8,
			.phsync = '-', .pvsync = '-',
			.x_mm = 147, .y_mm = 235,
		},
	},

	.init = {
		PANEL_DELAY(24),
		PANEL_DCS(0x11),
		PANEL_DCS(0xB9, 0x83, 0x10, 0x21, 0x55, 0x00),
		PANEL_DCS(0xE9, 0xC4),
		PANEL_DCS(0xD9, 0xD1),
		PANEL_DCS(0xE9, 0x3F),
		PANEL_DCS(0xB1, 0x2C, 0xB3, 0xB3, 0x31, 0xF1, 0x33, 0xE0, 0x54,
			0x36, 0x36, 0x3A, 0x3A, 0x32, 0x8B, 0x11, 0xE5, 0x98),
		PANEL_DCS(0xE9, 0xD9),
		PANEL_DCS(0xB1, 0x8B, 0x33),
		PANEL_DCS(0xE9, 0x3F),
		PANEL_DCS(0xB2, 0x00, 0x47, 0xB0, 0x80, 0x00, 0x2C, 0x80, 0x3C,
			0x9F, 0x22, 0x20, 0x00, 0x00, 0x98, 0x51),
		PANEL_DCS(0xB4, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x40, 0x84,
			0x64, 0x84, 0x01, 0x9D, 0x01, 0x02, 0x01, 0x00, 0x00),
		PANEL_DCS(0xBC, 0x1B, 0x04),
		PANEL_DCS(0xBE, 0x20),
		PANEL_DCS(0xBF, 0xFC, 0xC4, 0x80, 0x9C, 0x36, 0x00, 0x0D, 0x04),
		PANEL_DCS(0xC0, 0x32, 0x32, 0x22, 0x11, 0x22, 0xA0, 0x31, 0x08,
			0xF5, 0x03),
		PANEL_DCS(0xE9, 0xCC),
		PANEL_DCS(0xC7, 0x80),
		PANEL_DCS(0xE9, 0x3F),
		PANEL_DCS(0xE9, 0xC6),
		PANEL_DCS(0xC8, 0x97),
		PANEL_DCS(0xE9, 0x3F),
		PANEL_DCS(0xC9, 0x00, 0x1E, 0x13, 0x88, 0x01),
		PANEL_DCS(0xCB, 0x08, 0x13, 0x07, 0x00, 0x0F, 0x36),
		PANEL_DCS(0xCC, 0x02, 0x03, 0x44),
		PANEL_DCS(0xD1, 0x07, 0x06, 0x00, 0x02, 0x04, 0x2C, 0xFF),
		PANEL_DCS(0xD3, 0x06, 0x00, 0x00, 0x00, 0x40, 0x04, 0x08, 0x04,
			0x08, 0x37, 0x07, 0x44, 0x37, 0x2B, 0x2B, 0x03, 0x03, 0x32,
			0x10, 0x22, 0x00, 0x25, 0x32, 0x10, 0x29, 0x00, 0x29, 0x32,
			0x10, 0x08, 0x00, 0x08, 0x00, 0x00),
		PANEL_DCS(0xD5, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
			0x18, 0x18, 0x07, 0x06, 0x07, 0x06, 0x05, 0x04, 0x05, 0x04,
			0x03, 0x02, 0x03, 0x02, 0x01, 0x00, 0x01, 0x00, 0x18, 0x18,
			0x25, 0x24, 0x25, 0x24, 0x1F, 0x1F, 0x1F, 0x1F, 0x1E, 0x1E,
			0x1E, 0x1E, 0x20, 0x20, 0x20, 0x20),
		PANEL_DCS(0xD8, 0x0A, 0x2A, 0xAA, 0x8A, 0xAA, 0xA0, 0x0A, 0x2A,
			0xAA, 0x8A, 0xAA, 0xA0),
		PANEL_DCS(0xE7, 0xE0, 0x10, 0x10, 0x0D, 0x1E, 0x9D, 0x02, 0x52,
			0x9D, 0x14, 0x14),
		PANEL_DCS(0xBD, 0x01),
		PANEL_DCS(0xB1, 0x01, 0x7F, 0x11, 0xFD),
		PANEL_DCS(0xE9, 0xC5),
		PANEL_DCS(0xBA, 0x4F),
		PANEL_DCS(0xE9, 0x3F),
		PANEL_DCS(0xCB, 0x86),
		PANEL_DCS(0xD2, 0x64),
		PANEL_DCS(0xE9, 0xC5),
		PANEL_DCS(0xD3, 0x00),
		PANEL_DCS(0xE9, 0x3F),
		PANEL_DCS(0xD8, 0x0A, 0x2A, 0xAA, 0x8A, 0xAA, 0xA0, 0x0A, 0x2A,
			0xAA, 0x8A, 0xAA, 0xA0, 0x05, 0x15, 0x55, 0x45, 0x55, 0x50,
			0x05, 0x15, 0x55, 0x45, 0x55, 0x50),
		PANEL_DCS(0xE7, 0x02, 0x00, 0x24, 0x01, 0x7E, 0x0F, 0x7C, 0x10,
			0xA0, 0x00, 0x00),
		PANEL_DCS(0xBD, 0x02),
		PANEL_DCS(0xCB, 0x03, 0x07, 0x00, 0x10, 0x7B),
		PANEL_DCS(0xD8, 0x0F, 0x3F, 0xFF, 0xCF, 0xFF, 0xF0, 0x0F, 0x3F,
			0xFF, 0xCF, 0xFF, 0xF0),
		PANEL_DCS(0xE7, 0xFE, 0x01, 0xFE, 0x01, 0xFE, 0x01, 0x00, 0x00,
			0x00, 0x23, 0x00, 0x23, 0x81, 0x02, 0x40, 0x00, 0x20, 0x9D,
			0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00),
		PANEL_DCS(0xBD, 0x03),
		PANEL_DCS(0xB2, 0x66, 0x81),
		PANEL_DCS(0xE9, 0xC6),
		PANEL_DCS(0xB4, 0x03, 0xFF, 0xF8),
		PANEL_DCS(0xE9, 0x3F),
		PANEL_DCS(0xD8, 0x0A, 0x2A, 0xAA, 0x8A, 0xAA, 0xA0, 0x0A, 0x2A,
			0xAA, 0x8A, 0xAA, 0xA0, 0x0F, 0x2A, 0xAA, 0x8A, 0xAA, 0xF0,
			0x0F, 0x2A, 0xAA, 0x8A, 0xAA, 0xF0, 0x0A, 0x2A, 0xAA, 0x8A,
			0xAA, 0xA0, 0x0A, 0x2A, 0xAA, 0x8A, 0xAA, 0xA0),
		PANEL_DCS(0xBD, 0x00),
		PANEL_DCS(0xB9, 0x00, 0x00, 0x00, 0x00),

		PANEL_DCS(0x11),
		PANEL_DELAY(120),
		PANEL_DCS(0x29),
		PANEL_DELAY(20),
		PANEL_END,
	},
};
