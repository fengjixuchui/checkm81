#
# Copyright (c) 2024, MediaTek Inc. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

# Separate text code and read only data
SEPARATE_CODE_AND_RODATA := 1

# ARMv8.2 and above need enable HW assist coherence
HW_ASSISTED_COHERENCY := 1

# No need coherency memory because of HW assistency
USE_COHERENT_MEM := 0

# GIC600
GICV3_SUPPORT_GIC600 := 1

#
# MTK options
#
PLAT_EXTRA_RODATA_INCLUDES := 1
USE_PMIC_WRAP_INIT_V2 := 1

# Configs for A78 and A55
CTX_INCLUDE_AARCH32_REGS := 0

CONFIG_ARCH_ARM_V9 := y
CONFIG_MTK_MCUSYS := y
MCUSYS_VERSION := v1
CONFIG_MTK_PM_SUPPORT := y
CONFIG_MTK_PM_ARCH := 9_0
CONFIG_MTK_CPU_PM_SUPPORT := y
CONFIG_MTK_CPU_PM_ARCH := 5_4
CONFIG_MTK_SMP_EN := n
CONFIG_MTK_CPU_SUSPEND_EN := y
CONFIG_MTK_SPM_VERSION := mt8196
CONFIG_MTK_SUPPORT_SYSTEM_SUSPEND := y
CPU_PM_TINYSYS_SUPPORT := y
MTK_PUBEVENT_ENABLE := y

ENABLE_FEAT_AMU := 1
ENABLE_FEAT_ECV := 1
ENABLE_FEAT_FGT := 1
ENABLE_FEAT_HCX := 1
ENABLE_SVE_FOR_SWD := 1
