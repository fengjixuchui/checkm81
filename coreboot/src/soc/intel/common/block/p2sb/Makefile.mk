## SPDX-License-Identifier: GPL-2.0-only
bootblock-$(CONFIG_SOC_INTEL_COMMON_BLOCK_BASE_P2SB) += p2sblib.c
romstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_BASE_P2SB) += p2sblib.c
ramstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_BASE_P2SB) += p2sblib.c
smm-$(CONFIG_SOC_INTEL_COMMON_BLOCK_BASE_P2SB) += p2sblib.c

# p2sb.c for PCH and SoC die P2SB IP
bootblock-$(CONFIG_SOC_INTEL_COMMON_BLOCK_P2SB) += p2sb.c
romstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_P2SB) += p2sb.c
ramstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_P2SB) += p2sb.c
smm-$(CONFIG_SOC_INTEL_COMMON_BLOCK_P2SB) += p2sb.c

# ioe_p2sb.c for IOE die P2SB IP
bootblock-$(CONFIG_SOC_INTEL_COMMON_BLOCK_IOE_P2SB) += ioe_p2sb.c
romstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_IOE_P2SB) += ioe_p2sb.c
ramstage-$(CONFIG_SOC_INTEL_COMMON_BLOCK_IOE_P2SB) += ioe_p2sb.c
smm-$(CONFIG_SOC_INTEL_COMMON_BLOCK_IOE_P2SB) += ioe_p2sb.c
