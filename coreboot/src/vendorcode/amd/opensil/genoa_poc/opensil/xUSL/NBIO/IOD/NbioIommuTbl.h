/**
 * @file  NbioIommuTbl.h
 * @brief This file contains the Nbio Iommu configurations
 *
 */
/* Copyright 2022-2023 Advanced Micro Devices, Inc. All rights reserved.    */
// SPDX-License-Identifier: MIT

#pragma once

// --------------------------------------------------
// 15.3.1.2.1 : This table initializes IOMMU
// --------------------------------------------------

  // Disable INTx in IOMMU
  // IOMMU::L2::IOMMU_CAP_MISC[IOMMU_HT_ATS_RESV] = 0h
  #define NBIO_IOMMU_INIT_TBL \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_IOMMU_CONTROL_W_ADDRESS, \
      IOMMU_CONTROL_W_INTERRUPT_PIN_W_MASK, \
      0x0 << IOMMU_CONTROL_W_INTERRUPT_PIN_W_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_IOMMU_CAP_MISC_ADDRESS, \
      IOMMU_CAP_MISC_IOMMU_HT_ATS_RESV_MASK, \
      (0 << IOMMU_CAP_MISC_IOMMU_HT_ATS_RESV_OFFSET) \
      ),
  // End of NBIO_IOMMU_INIT_TBL

// --------------------------------------------------
// 15.3.1.2.2       IOMMU L1 Initialization
// --------------------------------------------------
  // Program these values on PCIEx and NBIFx and IOAGR (in that order)
  //
  // IOMMUL1::L1_CNTRL_4[ATS_multiple_resp_en] = 1h.
  // IOMMUL1::L1_CNTRL_4[Timeout_pulse_ext_En] = 1h.
  // IOMMUL1::L1_MISC_CNTRL_1[REG_enable_nw] = 1h.
  // IOMMUL1::L1_MISC_CNTRL_1[REG_force_invalid_filter] = 1h.
  // IOMMUL1::L1_MISC_CNTRL_1[REG_Block_On_4K_wait_dis] = 1h.
  // IOMMUL1::L1_FEATURE_CNTRL[EXE_lock_bit] = 1h.
  // IOMMUL1::L1_FEATURE_CNTRL[PMR_lock_bit] = 1h.
  // IOMMUL1::L1_CNTRL_0[Unfilter_dis] = 1h.
  // Program IOMMUL1::L1_CNTRL_2[CPD_RESP_MODE],
  // IOMMUL1::L1_CNTRL_2[L1NonConsumedDataErrorSignalEn]
  // Depeding on parity settings program:
  // IOMMUL1::L1_CNTRL_2[L1ConsumedDataErrorSignalEn] = 1h.
  // IOMMUL1::L1_SDP_CLKREQ_CNTRL[HW_PG_WAKEUP_EN_DMA] = 1h.
  // IOMMUL1::L1_SDP_CLKREQ_CNTRL[HW_PG_WAKEUP_EN_DMA] = 1h.
  #define NBIO_IOMMU_L1_INIT_TBL \
    SMN_ENTRY_RMW ( \
      SMN_PCIE0_IOHUB0NBIO0_L1_CNTRL_4_ADDRESS, \
      L1_CNTRL_4_ATS_multiple_resp_en_MASK | \
      L1_CNTRL_4_Timeout_pulse_ext_En_MASK, \
      (0x1 << L1_CNTRL_4_ATS_multiple_resp_en_OFFSET) | \
      (0x1 << L1_CNTRL_4_Timeout_pulse_ext_En_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_PCIE1_IOHUB0NBIO0_L1_CNTRL_4_ADDRESS, \
      L1_CNTRL_4_ATS_multiple_resp_en_MASK | \
      L1_CNTRL_4_Timeout_pulse_ext_En_MASK, \
      (0x1 << L1_CNTRL_4_ATS_multiple_resp_en_OFFSET) | \
      (0x1 << L1_CNTRL_4_Timeout_pulse_ext_En_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_CNTRL_4_ADDRESS, \
      L1_CNTRL_4_ATS_multiple_resp_en_MASK | \
      L1_CNTRL_4_Timeout_pulse_ext_En_MASK, \
      (0x1 << L1_CNTRL_4_ATS_multiple_resp_en_OFFSET) | \
      (0x1 << L1_CNTRL_4_Timeout_pulse_ext_En_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_CNTRL_4_ADDRESS, \
      L1_CNTRL_4_ATS_multiple_resp_en_MASK | \
      L1_CNTRL_4_Timeout_pulse_ext_En_MASK, \
      (0x1 << L1_CNTRL_4_ATS_multiple_resp_en_OFFSET) | \
      (0x1 << L1_CNTRL_4_Timeout_pulse_ext_En_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SIL_RESERVED3_1497, \
      SIL_RESERVED3_1495 | \
      SIL_RESERVED3_1491 | \
      SIL_RESERVED3_1493, \
      (0x1 << SIL_RESERVED3_1494) | \
      (0x1 << SIL_RESERVED3_1490) | \
      (0x1 << SIL_RESERVED3_1492) \
      ), \
    SMN_ENTRY_RMW ( \
      SIL_RESERVED3_1498, \
      SIL_RESERVED3_1495 | \
      SIL_RESERVED3_1491 | \
      SIL_RESERVED3_1493, \
      (0x1 << SIL_RESERVED3_1494) | \
      (0x1 << SIL_RESERVED3_1490) | \
      (0x1 << SIL_RESERVED3_1492) \
      ), \
    SMN_ENTRY_RMW ( \
      SIL_RESERVED3_1496, \
      SIL_RESERVED3_1495 | \
      SIL_RESERVED3_1491 | \
      SIL_RESERVED3_1493, \
      (0x1 << SIL_RESERVED3_1494) | \
      (0x1 << SIL_RESERVED3_1490) | \
      (0x1 << SIL_RESERVED3_1492) \
      ), \
    SMN_ENTRY_RMW ( \
      SIL_RESERVED3_1496, \
      SIL_RESERVED3_1495 | \
      SIL_RESERVED3_1491 | \
      SIL_RESERVED3_1493, \
      (0x1 << SIL_RESERVED3_1494) | \
      (0x1 << SIL_RESERVED3_1490) | \
      (0x1 << SIL_RESERVED3_1492) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_PCIE0_IOHUB0NBIO0_L1_FEATURE_CNTRL_ADDRESS, \
      L1_FEATURE_CNTRL_EXE_lock_bit_MASK | \
      L1_FEATURE_CNTRL_PMR_lock_bit_MASK, \
      1 << L1_FEATURE_CNTRL_EXE_lock_bit_OFFSET | \
      1 << L1_FEATURE_CNTRL_PMR_lock_bit_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_PCIE1_IOHUB0NBIO0_L1_FEATURE_CNTRL_ADDRESS, \
      L1_FEATURE_CNTRL_EXE_lock_bit_MASK | \
      L1_FEATURE_CNTRL_PMR_lock_bit_MASK, \
      1 << L1_FEATURE_CNTRL_EXE_lock_bit_OFFSET | \
      1 << L1_FEATURE_CNTRL_PMR_lock_bit_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_FEATURE_CNTRL_ADDRESS, \
      L1_FEATURE_CNTRL_EXE_lock_bit_MASK | \
      L1_FEATURE_CNTRL_PMR_lock_bit_MASK, \
      1 << L1_FEATURE_CNTRL_EXE_lock_bit_OFFSET | \
      1 << L1_FEATURE_CNTRL_PMR_lock_bit_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_FEATURE_CNTRL_ADDRESS, \
      L1_FEATURE_CNTRL_EXE_lock_bit_MASK | \
      L1_FEATURE_CNTRL_PMR_lock_bit_MASK, \
      1 << L1_FEATURE_CNTRL_EXE_lock_bit_OFFSET | \
      1 << L1_FEATURE_CNTRL_PMR_lock_bit_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_PCIE0_IOHUB0NBIO0_L1_CNTRL_2_ADDRESS, \
      L1_CNTRL_2_CPD_RESP_MODE_MASK | \
      L1_CNTRL_2_L1NonConsumedDataErrorSignalEn_MASK | \
      L1_CNTRL_2_L1ConsumedDataErrorSignalEn_MASK, \
      1 << L1_CNTRL_2_CPD_RESP_MODE_OFFSET | \
      1 << L1_CNTRL_2_L1NonConsumedDataErrorSignalEn_OFFSET | \
      1 << L1_CNTRL_2_L1ConsumedDataErrorSignalEn_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_PCIE1_IOHUB0NBIO0_L1_CNTRL_2_ADDRESS, \
      L1_CNTRL_2_CPD_RESP_MODE_MASK | \
      L1_CNTRL_2_L1NonConsumedDataErrorSignalEn_MASK | \
      L1_CNTRL_2_L1ConsumedDataErrorSignalEn_MASK, \
      1 << L1_CNTRL_2_CPD_RESP_MODE_OFFSET | \
      1 << L1_CNTRL_2_L1NonConsumedDataErrorSignalEn_OFFSET | \
      1 << L1_CNTRL_2_L1ConsumedDataErrorSignalEn_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_CNTRL_2_ADDRESS, \
      L1_CNTRL_2_CPD_RESP_MODE_MASK | \
      L1_CNTRL_2_L1NonConsumedDataErrorSignalEn_MASK | \
      L1_CNTRL_2_L1ConsumedDataErrorSignalEn_MASK, \
      1 << L1_CNTRL_2_CPD_RESP_MODE_OFFSET | \
      1 << L1_CNTRL_2_L1NonConsumedDataErrorSignalEn_OFFSET | \
      1 << L1_CNTRL_2_L1ConsumedDataErrorSignalEn_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_CNTRL_2_ADDRESS, \
      L1_CNTRL_2_CPD_RESP_MODE_MASK | \
      L1_CNTRL_2_L1NonConsumedDataErrorSignalEn_MASK | \
      L1_CNTRL_2_L1ConsumedDataErrorSignalEn_MASK, \
      1 << L1_CNTRL_2_CPD_RESP_MODE_OFFSET | \
      1 << L1_CNTRL_2_L1NonConsumedDataErrorSignalEn_OFFSET | \
      1 << L1_CNTRL_2_L1ConsumedDataErrorSignalEn_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_PCIE0_IOHUB0NBIO0_L1_SDP_CLKREQ_CNTRL_ADDRESS, \
      L1_SDP_CLKREQ_CNTRL_HW_PG_WAKEUP_EN_DMA_MASK, \
      (1 << L1_SDP_CLKREQ_CNTRL_HW_PG_WAKEUP_EN_DMA_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_PCIE1_IOHUB0NBIO0_L1_SDP_CLKREQ_CNTRL_ADDRESS, \
      L1_SDP_CLKREQ_CNTRL_HW_PG_WAKEUP_EN_DMA_MASK, \
      (1 << L1_SDP_CLKREQ_CNTRL_HW_PG_WAKEUP_EN_DMA_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_CLKREQ_CNTRL_ADDRESS, \
      L1_SDP_CLKREQ_CNTRL_HW_PG_WAKEUP_EN_DMA_MASK, \
      (1 << L1_SDP_CLKREQ_CNTRL_HW_PG_WAKEUP_EN_DMA_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_CLKREQ_CNTRL_ADDRESS, \
      L1_SDP_CLKREQ_CNTRL_HW_PG_WAKEUP_EN_DMA_MASK, \
      (1 << L1_SDP_CLKREQ_CNTRL_HW_PG_WAKEUP_EN_DMA_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_MAXCRED_0_ADDRESS, \
      L1_SDP_MAXCRED_0_L1_DYNAMIC_CRED_RELOCATION_EN_MASK, \
      (1 << L1_SDP_MAXCRED_0_L1_DYNAMIC_CRED_RELOCATION_EN_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_DMA_REQ_CREDIT_1_ADDRESS, \
      L1_SDP_DMA_REQ_CREDIT_1_VC7_DMA_REQ_CREDIT_MASK, \
      (1 << L1_SDP_DMA_REQ_CREDIT_1_VC7_DMA_REQ_CREDIT_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_DMA_DATA_CREDIT_1_ADDRESS, \
      L1_SDP_DMA_DATA_CREDIT_1_VC7_DMA_DATA_CREDIT_MASK, \
      (1 << L1_SDP_DMA_DATA_CREDIT_1_VC7_DMA_DATA_CREDIT_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_DMA_RDRSP_CREDIT_ADDRESS, \
      L1_SDP_DMA_RDRSP_CREDIT_VC4_DMA_RDRSP_CREDIT_MASK, \
      (1 << L1_SDP_DMA_RDRSP_CREDIT_VC4_DMA_RDRSP_CREDIT_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_DMA_WRRSP_CREDIT_ADDRESS, \
      L1_SDP_DMA_WRRSP_CREDIT_VC4_DMA_WRRSP_CREDIT_MASK, \
      (1 << L1_SDP_DMA_WRRSP_CREDIT_VC4_DMA_WRRSP_CREDIT_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_DMA_WRRSP_CREDIT_ADDRESS, \
      L1_SDP_DMA_WRRSP_CREDIT_VC6_DMA_WRRSP_CREDIT_MASK, \
      (1 << L1_SDP_DMA_WRRSP_CREDIT_VC6_DMA_WRRSP_CREDIT_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOAGR_IOHUB0NBIO0_L1_SDP_MAXCRED_0_ADDRESS, \
      L1_SDP_MAXCRED_0_L1_DYNAMIC_CRED_RELOCATION_EN_MASK, \
      (0 << L1_SDP_MAXCRED_0_L1_DYNAMIC_CRED_RELOCATION_EN_OFFSET) \
      ),
  // End of NBIO_IOMMU_L1_INIT_TBL

// --------------------------------------------------
// 15.3.1.2.3  : IOMMU L2 Initialization
// --------------------------------------------------
  // Program IOMMUL2::L2_ERR_RULE_CONTROL_0[ERRRuleLock0] = 1h
  // IOMMUL2::L2_ERR_RULE_CONTROL_3[ERRRuleLock1] = 1h.
  // IOMMUL2::L2_L2A_PGSIZE_CONTROL[L2AREG_HOST_PGSIZE] = 49h.
  // IOMMUL2::L2_L2A_PGSIZE_CONTROL[L2AREG_GST_PGSIZE] = 49h.
  // IOMMUL2::L2_L2B_PGSIZE_CONTROL[L2BREG_HOST_PGSIZE] = 49h.
  // IOMMUL2::L2_L2B_PGSIZE_CONTROL[L2BREG_GST_PGSIZE] = 49h.
  // IOMMUL2::L2_CONTROL_5[GST_partial_ptc_cntrl] = 49h.
  // IOMMUL2::L2_MISC_CNTRL_3[REG_atomic_filter_en] = 1h.
  // IOMMUL2::L2_MISC_CNTRL_3[REG_mask_l2_nw] = 1h.
  // IOMMUL2::L2_MISC_CNTRL_3[REG_ats_iw] = 1h.
  // IOMMUL2::L2_CP_CONTROL[CPFlushOnWait] = 1h.
  // IOMMUL2::L2_CP_CONTROL[CPFlushOnInv] = 0h.
  // IOMMUL2::L2B_UPDATE_FILTER_CNTL[L2b_Update_Filter_Bypass] = 0h.
  // IOMMUL2::L2A_UPDATE_FILTER_CNTL[L2a_Update_Filter_Bypass] = 0h.
  // IOMMUL2::L2_TW_CONTROL[TWPrefetchRange] = 7h.
  // IOMMUL2::L2_TW_CONTROL[TWPrefetchEn] = 1h.
  // IOMMUL2::L2_TW_CONTROL[TWCacheNestedPTE] = 1h.
  // IOMMUL2::L2_TW_CONTROL[TWForceCoherent] = 1h to force all Page Table Walker requests to be
  // coherent. The DTE SD bit and PTE FC bit will be ignored.
  #define NBIO_IOMMU_L2_INIT_TBL \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2_ERR_RULE_CONTROL_0_ADDRESS, \
      L2_ERR_RULE_CONTROL_0_ERRRuleLock0_MASK, \
      0x1 << L2_ERR_RULE_CONTROL_0_ERRRuleLock0_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2_ERR_RULE_CONTROL_3_ADDRESS, \
      L2_ERR_RULE_CONTROL_3_ERRRuleLock1_MASK, \
      0x1 << L2_ERR_RULE_CONTROL_3_ERRRuleLock1_OFFSET \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2_L2A_PGSIZE_CONTROL_ADDRESS, \
      L2_L2A_PGSIZE_CONTROL_L2AREG_HOST_PGSIZE_MASK | \
      L2_L2A_PGSIZE_CONTROL_L2AREG_GST_PGSIZE_MASK, \
      (0x49 << L2_L2A_PGSIZE_CONTROL_L2AREG_HOST_PGSIZE_OFFSET) | \
      (0x49 << L2_L2A_PGSIZE_CONTROL_L2AREG_GST_PGSIZE_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2_L2B_PGSIZE_CONTROL_ADDRESS, \
      L2_L2B_PGSIZE_CONTROL_L2BREG_GST_PGSIZE_MASK | \
      L2_L2B_PGSIZE_CONTROL_L2BREG_HOST_PGSIZE_MASK, \
      (0x49 << L2_L2B_PGSIZE_CONTROL_L2BREG_GST_PGSIZE_OFFSET) | \
      (0x49 << L2_L2B_PGSIZE_CONTROL_L2BREG_HOST_PGSIZE_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2_CONTROL_5_ADDRESS, \
      L2_CONTROL_5_GST_partial_ptc_cntrl_MASK, \
      (0x49 << L2_CONTROL_5_GST_partial_ptc_cntrl_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2_MISC_CNTRL_3_ADDRESS, \
      L2_MISC_CNTRL_3_REG_atomic_filter_en_MASK | \
      L2_MISC_CNTRL_3_REG_mask_l2_nw_MASK | \
      L2_MISC_CNTRL_3_REG_ats_iw_MASK, \
      (0x1 << L2_MISC_CNTRL_3_REG_atomic_filter_en_OFFSET) | \
      (0x1 << L2_MISC_CNTRL_3_REG_mask_l2_nw_OFFSET) | \
      (0x1 << L2_MISC_CNTRL_3_REG_ats_iw_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2_CP_CONTROL_ADDRESS, \
      L2_CP_CONTROL_CPFlushOnWait_MASK | \
      L2_CP_CONTROL_CPFlushOnInv_MASK, \
      (0x1 << L2_CP_CONTROL_CPFlushOnWait_OFFSET) | \
      (0x0 << L2_CP_CONTROL_CPFlushOnInv_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2B_UPDATE_FILTER_CNTL_ADDRESS, \
      L2B_UPDATE_FILTER_CNTL_L2b_Update_Filter_Bypass_MASK, \
      (0x0 << L2B_UPDATE_FILTER_CNTL_L2b_Update_Filter_Bypass_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2A_UPDATE_FILTER_CNTL_ADDRESS, \
      L2A_UPDATE_FILTER_CNTL_L2a_Update_Filter_Bypass_MASK, \
      (0x0 << L2A_UPDATE_FILTER_CNTL_L2a_Update_Filter_Bypass_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_L2_TW_CONTROL_ADDRESS, \
      L2_TW_CONTROL_TWPrefetchRange_MASK | \
      L2_TW_CONTROL_TWPrefetchEn_MASK | \
      L2_TW_CONTROL_TWCacheNestedPTE_MASK | \
      L2_TW_CONTROL_TWForceCoherent_MASK, \
      (0x7 << L2_TW_CONTROL_TWPrefetchRange_OFFSET) | \
      (0x1 << L2_TW_CONTROL_TWPrefetchEn_OFFSET) | \
      (0x1 << L2_TW_CONTROL_TWCacheNestedPTE_OFFSET) | \
      (0x1 << L2_TW_CONTROL_TWForceCoherent_OFFSET) \
      ), \
    SMN_ENTRY_RMW ( \
      SMN_IOHUB0NBIO0_IOMMU_MMIO_CONTROL1_W_ADDRESS, \
      IOMMU_MMIO_CONTROL1_W_InvIotlbTypeSup_W_MASK, \
      (0x0 << IOMMU_MMIO_CONTROL1_W_InvIotlbTypeSup_W_OFFSET) \
      ),
// --------------------------------------------------
// IOMMU Clock Gating
// --------------------------------------------------
    // IOMMU L1 clock gating
    // IOAGR
    // NBIF
    // PCIE0
    // PCIE1
  #define NBIO_IOMMU_CLOCK_GATING_TBL \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L2CLKGATING_ENABLED, \
      SMN_IOHUB0NBIO0_L2_L2A_CK_GATE_CONTROL_ADDRESS, \
      L2_L2A_CK_GATE_CONTROL_CKGateL2ARegsDisable_MASK | L2_L2A_CK_GATE_CONTROL_CKGateL2ADynamicDisable_MASK | L2_L2A_CK_GATE_CONTROL_CKGateL2ACacheDisable_MASK, \
      (0x0 << L2_L2A_CK_GATE_CONTROL_CKGateL2ARegsDisable_OFFSET) | \
      (0x0 << L2_L2A_CK_GATE_CONTROL_CKGateL2ADynamicDisable_OFFSET) | \
      (0x0 << L2_L2A_CK_GATE_CONTROL_CKGateL2ACacheDisable_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L2CLKGATING_DISABLED, \
      SMN_IOHUB0NBIO0_L2_L2A_CK_GATE_CONTROL_ADDRESS, \
      L2_L2A_CK_GATE_CONTROL_CKGateL2ARegsDisable_MASK | L2_L2A_CK_GATE_CONTROL_CKGateL2ADynamicDisable_MASK | L2_L2A_CK_GATE_CONTROL_CKGateL2ACacheDisable_MASK, \
      (0x1 << L2_L2A_CK_GATE_CONTROL_CKGateL2ARegsDisable_OFFSET) | \
      (0x1 << L2_L2A_CK_GATE_CONTROL_CKGateL2ADynamicDisable_OFFSET) | \
      (0x1 << L2_L2A_CK_GATE_CONTROL_CKGateL2ACacheDisable_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L2CLKGATING_ENABLED, \
      SMN_IOHUB0NBIO0_L2_L2B_CK_GATE_CONTROL_ADDRESS, \
      L2_L2B_CK_GATE_CONTROL_CKGateL2BRegsDisable_MASK | L2_L2B_CK_GATE_CONTROL_CKGateL2BDynamicDisable_MASK | \
      L2_L2B_CK_GATE_CONTROL_CKGateL2BMiscDisable_MASK | L2_L2B_CK_GATE_CONTROL_CKGateL2BCacheDisable_MASK, \
      (0x0 << L2_L2B_CK_GATE_CONTROL_CKGateL2BRegsDisable_OFFSET) | \
      (0x0 << L2_L2B_CK_GATE_CONTROL_CKGateL2BDynamicDisable_OFFSET) | \
      (0x0 << L2_L2B_CK_GATE_CONTROL_CKGateL2BMiscDisable_OFFSET) | \
      (0x0 << L2_L2B_CK_GATE_CONTROL_CKGateL2BCacheDisable_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L2CLKGATING_DISABLED, \
      SMN_IOHUB0NBIO0_L2_L2B_CK_GATE_CONTROL_ADDRESS, \
      L2_L2B_CK_GATE_CONTROL_CKGateL2BRegsDisable_MASK | L2_L2B_CK_GATE_CONTROL_CKGateL2BDynamicDisable_MASK | \
      L2_L2B_CK_GATE_CONTROL_CKGateL2BMiscDisable_MASK | L2_L2B_CK_GATE_CONTROL_CKGateL2BCacheDisable_MASK, \
      (0x1 << L2_L2B_CK_GATE_CONTROL_CKGateL2BRegsDisable_OFFSET) | \
      (0x1 << L2_L2B_CK_GATE_CONTROL_CKGateL2BDynamicDisable_OFFSET) | \
      (0x1 << L2_L2B_CK_GATE_CONTROL_CKGateL2BMiscDisable_OFFSET) | \
      (0x1 << L2_L2B_CK_GATE_CONTROL_CKGateL2BCacheDisable_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L1CLKGATING_ENABLED, \
      SMN_IOAGR_IOHUB0NBIO0_L1_CLKCNTRL_0_ADDRESS, \
      L1_CLKCNTRL_0_L1_CLKGATE_HYSTERESIS_MASK | \
      L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_MASK, \
      (0x20 << L1_CLKCNTRL_0_L1_CLKGATE_HYSTERESIS_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L1CLKGATING_DISABLED, \
      SMN_IOAGR_IOHUB0NBIO0_L1_CLKCNTRL_0_ADDRESS, \
      L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_MASK, \
      (0x0 << L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L1CLKGATING_ENABLED, \
      SMN_IOAGR_IOHUB0NBIO0_L1_CLKCNTRL_0_ADDRESS, \
      L1_CLKCNTRL_0_L1_CLKGATE_HYSTERESIS_MASK | \
      L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_MASK, \
      (0x20 << L1_CLKCNTRL_0_L1_CLKGATE_HYSTERESIS_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L1CLKGATING_DISABLED, \
      SMN_IOAGR_IOHUB0NBIO0_L1_CLKCNTRL_0_ADDRESS, \
      L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_MASK, \
      (0x0 << L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L1CLKGATING_ENABLED, \
      SMN_PCIE0_IOHUB0NBIO0_L1_CLKCNTRL_0_ADDRESS, \
      L1_CLKCNTRL_0_L1_CLKGATE_HYSTERESIS_MASK | \
      L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_MASK, \
      (0x20 << L1_CLKCNTRL_0_L1_CLKGATE_HYSTERESIS_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L1CLKGATING_DISABLED, \
      SMN_PCIE0_IOHUB0NBIO0_L1_CLKCNTRL_0_ADDRESS, \
      L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_MASK, \
      (0x0 << L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L1CLKGATING_ENABLED, \
      SMN_PCIE1_IOHUB0NBIO0_L1_CLKCNTRL_0_ADDRESS, \
      L1_CLKCNTRL_0_L1_CLKGATE_HYSTERESIS_MASK | \
      L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_MASK, \
      (0x20 << L1_CLKCNTRL_0_L1_CLKGATE_HYSTERESIS_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_OFFSET) | \
      (0x1 << L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_OFFSET) \
      ), \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_L1CLKGATING_DISABLED, \
      SMN_PCIE1_IOHUB0NBIO0_L1_CLKCNTRL_0_ADDRESS, \
      L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_MASK | \
      L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_MASK | L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_MASK, \
      (0x0 << L1_CLKCNTRL_0_L1_DMA_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_CACHE_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_CPSLV_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_PERF_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_MEMORY_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_REG_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_HOSTREQ_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_DMARSP_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_HOSTRSP_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_SION_PERF_CLKGATE_EN_OFFSET) | \
      (0x0 << L1_CLKCNTRL_0_L1_L2_CLKGATE_EN_OFFSET) \
      ),
  #define NBIO_IOMMU_SMI_FILTERING_TBL \
    SMN_ENTRY_PROPERTY_RMW ( \
      PROPERTY_IOMMU_DISABLED, \
      SMN_IOHUB0NBIO0_CFG_IOHC_PCI_ADDRESS, \
      SIL_RESERVED_53, \
      0x0 \
      ),

