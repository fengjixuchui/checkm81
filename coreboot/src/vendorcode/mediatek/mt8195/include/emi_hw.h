/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __EMI_HW_H__
#define __EMI_HW_H__

/* from EMI golden setting */
//#define EMI_MP_SETTING
#define REAL_CHIP_EMI_GOLDEN_SETTING
#define INFRA_DRAMC_REG_CONFIG      (0x100010b4)
#define INFRACFG_AO_MEM_BASE        (0x10002000)
#define SUB_INFRACFG_AO_MEM_BASE    (0x1030E000)
#define MCUSYS_PAR_WRAP_BASE        (0x0C530000)

#define EMI_BASE                    (0x10219000)
#define SUB_EMI_BASE                (0x1021D000)
#define EMI_MPU_BASE                (0x10226000)
#define SUB_EMI_MPU_BASE            (0x10225000)
#define CHN0_EMI_BASE               (0x10235000)
#define CHN1_EMI_BASE               (0x10245000)

#define EMI_CONA                    (EMI_BASE+0x000)
#define EMI_CONB                    (EMI_BASE+0x008)
#define EMI_CONC                    (EMI_BASE+0x010)
#define EMI_COND                    (EMI_BASE+0x018)
#define EMI_CONE                    (EMI_BASE+0x020)
#define EMI_CONF                    (EMI_BASE+0x028)
#define EMI_CONG                    (EMI_BASE+0x030)
#define EMI_CONH                    (EMI_BASE+0x038)
#define EMI_CONH_2ND                (EMI_BASE+0x03C)
#define EMI_CONI                    (EMI_BASE+0x040)
#define EMI_CONJ                    (EMI_BASE+0x048)
#define EMI_CONK                    (EMI_BASE+0x050)
#define EMI_CONM                    (EMI_BASE+0x060)
#define EMI_CONN                    (EMI_BASE+0x068)
#define EMI_CONO                    (EMI_BASE+0x070)
#define EMI_MDCT                    (EMI_BASE+0x078)
#define EMI_MDCT_2ND                (EMI_BASE+0x07C)
#define EMI_IOCL                    (EMI_BASE+0x0D0)
#define EMI_IOCL_2ND                (EMI_BASE+0x0D4)
#define EMI_IOCM                    (EMI_BASE+0x0D8)
#define EMI_IOCM_2ND                (EMI_BASE+0x0DC)
#define EMI_TESTB                   (EMI_BASE+0x0E8)
#define EMI_TESTC                   (EMI_BASE+0x0F0)
#define EMI_TESTD                   (EMI_BASE+0x0F8)
#define EMI_ARBA                    (EMI_BASE+0x100)
#define EMI_ARBB                    (EMI_BASE+0x108)
#define EMI_ARBC                    (EMI_BASE+0x110)
#define EMI_ARBD                    (EMI_BASE+0x118)
#define EMI_ARBE                    (EMI_BASE+0x120)
#define EMI_ARBF                    (EMI_BASE+0x128)
#define EMI_ARBG                    (EMI_BASE+0x130)
#define EMI_ARBH                    (EMI_BASE+0x138)
#define EMI_ARBI                    (EMI_BASE+0x140)
#define EMI_ARBI_2ND                (EMI_BASE+0x144)
#define EMI_ARBJ_2ND                (EMI_BASE+0x14C)
#define EMI_ARBK                    (EMI_BASE+0x150)
#define EMI_ARBK_2ND                (EMI_BASE+0x154)
#define EMI_SLCT                    (EMI_BASE+0x158)
#define EMI_MPUD0_ST                (EMI_BASE+0x160)
#define EMI_MPUD1_ST                (EMI_BASE+0x164)
#define EMI_MPUD2_ST                (EMI_BASE+0x168)
#define EMI_MPUD3_ST                (EMI_BASE+0x16C)
#define EMI_MPUD4_ST                (EMI_BASE+0x170)
#define EMI_MPUD5_ST                (EMI_BASE+0x174)
#define EMI_MPUD6_ST                (EMI_BASE+0x178)
#define EMI_MPUD7_ST                (EMI_BASE+0x17C)
#define EMI_MPUD8_ST                (EMI_BASE+0x180)
#define EMI_MPUD9_ST                (EMI_BASE+0x184)
#define EMI_MPUD10_ST               (EMI_BASE+0x188)
#define EMI_MPUD11_ST               (EMI_BASE+0x18C)
#define EMI_MPUD12_ST               (EMI_BASE+0x190)
#define EMI_MPUD13_ST               (EMI_BASE+0x194)
#define EMI_MPUD14_ST               (EMI_BASE+0x198)
#define EMI_MPUD15_ST               (EMI_BASE+0x19C)
#define EMI_MPUD16_ST               (EMI_BASE+0x1A0)
#define EMI_MPUD17_ST               (EMI_BASE+0x1A4)
#define EMI_MPUD18_ST               (EMI_BASE+0x1A8)
#define EMI_MPUD19_ST               (EMI_BASE+0x1AC)
#define EMI_MPUD20_ST               (EMI_BASE+0x1B0)
#define EMI_MPUD21_ST               (EMI_BASE+0x1B4)
#define EMI_MPUD22_ST               (EMI_BASE+0x1B8)
#define EMI_MPUD23_ST               (EMI_BASE+0x1BC)
#define EMI_MPUD24_ST               (EMI_BASE+0x1C0)
#define EMI_MPUD25_ST               (EMI_BASE+0x1C4)
#define EMI_MPUD26_ST               (EMI_BASE+0x1C8)
#define EMI_MPUD27_ST               (EMI_BASE+0x1CC)
#define EMI_MPUD28_ST               (EMI_BASE+0x1D0)
#define EMI_MPUD29_ST               (EMI_BASE+0x1D4)
#define EMI_MPUD30_ST               (EMI_BASE+0x1D8)
#define EMI_MPUD31_ST               (EMI_BASE+0x1DC)
#define EMI_MPUS                    (EMI_BASE+0x1F0)
#define EMI_MPUT                    (EMI_BASE+0x1F8)
#define EMI_MPUT_2ND                (EMI_BASE+0x1FC)
#define EMI_D0_ST2                  (EMI_BASE+0x200)
#define EMI_D1_ST2                  (EMI_BASE+0x204)
#define EMI_D2_ST2                  (EMI_BASE+0x208)
#define EMI_D3_ST2                  (EMI_BASE+0x20C)
#define EMI_D4_ST2                  (EMI_BASE+0x210)
#define EMI_D5_ST2                  (EMI_BASE+0x214)
#define EMI_D6_ST2                  (EMI_BASE+0x218)
#define EMI_D7_ST2                  (EMI_BASE+0x21C)
#define EMI_D8_ST2                  (EMI_BASE+0x220)
#define EMI_D9_ST2                  (EMI_BASE+0x224)
#define EMI_D10_ST2                 (EMI_BASE+0x228)
#define EMI_D11_ST2                 (EMI_BASE+0x22C)
#define EMI_D12_ST2                 (EMI_BASE+0x230)
#define EMI_D13_ST2                 (EMI_BASE+0x234)
#define EMI_D14_ST2                 (EMI_BASE+0x238)
#define EMI_D15_ST2                 (EMI_BASE+0x23C)
#define EMI_D16_ST2                 (EMI_BASE+0x240)
#define EMI_D17_ST2                 (EMI_BASE+0x244)
#define EMI_D18_ST2                 (EMI_BASE+0x248)
#define EMI_D19_ST2                 (EMI_BASE+0x24C)
#define EMI_D20_ST2                 (EMI_BASE+0x250)
#define EMI_D21_ST2                 (EMI_BASE+0x254)
#define EMI_D22_ST2                 (EMI_BASE+0x258)
#define EMI_D23_ST2                 (EMI_BASE+0x25C)
#define EMI_D24_ST2                 (EMI_BASE+0x260)
#define EMI_D25_ST2                 (EMI_BASE+0x264)
#define EMI_D26_ST2                 (EMI_BASE+0x268)
#define EMI_D27_ST2                 (EMI_BASE+0x26C)
#define EMI_D28_ST2                 (EMI_BASE+0x270)
#define EMI_D29_ST2                 (EMI_BASE+0x274)
#define EMI_D30_ST2                 (EMI_BASE+0x278)
#define EMI_D31_ST2                 (EMI_BASE+0x27C)
#define EMI_BMEN                    (EMI_BASE+0x400)
#define EMI_BSTP                    (EMI_BASE+0x404)
#define EMI_BCNT                    (EMI_BASE+0x408)
#define EMI_TACT                    (EMI_BASE+0x410)
#define EMI_TSCT                    (EMI_BASE+0x418)
#define EMI_WACT                    (EMI_BASE+0x420)
#define EMI_WSCT                    (EMI_BASE+0x428)
#define EMI_BACT                    (EMI_BASE+0x430)
#define EMI_BSCT                    (EMI_BASE+0x438)
#define EMI_MSEL                    (EMI_BASE+0x440)
#define EMI_TSCT2                   (EMI_BASE+0x448)
#define EMI_TSCT3                   (EMI_BASE+0x450)
#define EMI_WSCT2                   (EMI_BASE+0x458)
#define EMI_WSCT3                   (EMI_BASE+0x460)
#define EMI_WSCT4                   (EMI_BASE+0x464)
#define EMI_MSEL2                   (EMI_BASE+0x468)
#define EMI_MSEL3                   (EMI_BASE+0x470)
#define EMI_MSEL4                   (EMI_BASE+0x478)
#define EMI_MSEL5                   (EMI_BASE+0x480)
#define EMI_MSEL6                   (EMI_BASE+0x488)
#define EMI_MSEL7                   (EMI_BASE+0x490)
#define EMI_MSEL8                   (EMI_BASE+0x498)
#define EMI_MSEL9                   (EMI_BASE+0x4A0)
#define EMI_MSEL10                  (EMI_BASE+0x4A8)
#define EMI_BMID0                   (EMI_BASE+0x4B0)
#define EMI_BMID1                   (EMI_BASE+0x4B4)
#define EMI_BMID2                   (EMI_BASE+0x4B8)
#define EMI_BMID3                   (EMI_BASE+0x4BC)
#define EMI_BMID4                   (EMI_BASE+0x4C0)
#define EMI_BMID5                   (EMI_BASE+0x4C4)
#define EMI_BMID6                   (EMI_BASE+0x4C8)
#define EMI_BMID7                   (EMI_BASE+0x4CC)
#define EMI_BMID8                   (EMI_BASE+0x4D0)
#define EMI_BMID9                   (EMI_BASE+0x4D4)
#define EMI_BMID10                  (EMI_BASE+0x4D8)
#define EMI_BMEN1                   (EMI_BASE+0x4E0)
#define EMI_BMEN2                   (EMI_BASE+0x4E8)
#define EMI_BMRW0                   (EMI_BASE+0x4F8)
#define EMI_BMRW1                   (EMI_BASE+0x4FC)
#define EMI_TTYPE1                  (EMI_BASE+0x500)
#define EMI_TTYPE2                  (EMI_BASE+0x508)
#define EMI_TTYPE3                  (EMI_BASE+0x510)
#define EMI_TTYPE4                  (EMI_BASE+0x518)
#define EMI_TTYPE5                  (EMI_BASE+0x520)
#define EMI_TTYPE6                  (EMI_BASE+0x528)
#define EMI_TTYPE7                  (EMI_BASE+0x530)
#define EMI_TTYPE8                  (EMI_BASE+0x538)
#define EMI_TTYPE9                  (EMI_BASE+0x540)
#define EMI_TTYPE10                 (EMI_BASE+0x548)
#define EMI_TTYPE11                 (EMI_BASE+0x550)
#define EMI_TTYPE12                 (EMI_BASE+0x558)
#define EMI_TTYPE13                 (EMI_BASE+0x560)
#define EMI_TTYPE14                 (EMI_BASE+0x568)
#define EMI_TTYPE15                 (EMI_BASE+0x570)
#define EMI_TTYPE16                 (EMI_BASE+0x578)
#define EMI_TTYPE17                 (EMI_BASE+0x580)
#define EMI_TTYPE18                 (EMI_BASE+0x588)
#define EMI_TTYPE19                 (EMI_BASE+0x590)
#define EMI_TTYPE20                 (EMI_BASE+0x598)
#define EMI_TTYPE21                 (EMI_BASE+0x5A0)
#define EMI_BWCT0                   (EMI_BASE+0x5B0)
#define EMI_BWCT1                   (EMI_BASE+0x5B4)
#define EMI_BWCT2                   (EMI_BASE+0x5B8)
#define EMI_BWCT3                   (EMI_BASE+0x5BC)
#define EMI_BWCT4                   (EMI_BASE+0x5C0)
#define EMI_BWST0                   (EMI_BASE+0x5C4)
#define EMI_BWST1                   (EMI_BASE+0x5C8)
#define EMI_EX_CON                  (EMI_BASE+0x5D0)
#define EMI_EX_ST0                  (EMI_BASE+0x5D4)
#define EMI_EX_ST1                  (EMI_BASE+0x5D8)
#define EMI_EX_ST2                  (EMI_BASE+0x5DC)
#define EMI_WP_ADR                  (EMI_BASE+0x5E0)
#define EMI_WP_ADR_2ND              (EMI_BASE+0x5E4)
#define EMI_WP_CTRL                 (EMI_BASE+0x5E8)
#define EMI_CHKER                   (EMI_BASE+0x5F0)
#define EMI_CHKER_TYPE              (EMI_BASE+0x5F4)
#define EMI_CHKER_ADR               (EMI_BASE+0x5F8)
#define EMI_CHKER_ADR_2ND           (EMI_BASE+0x5FC)
#define EMI_BWCT0_2ND               (EMI_BASE+0x6A0)
#define EMI_LTCT0_2ND               (EMI_BASE+0x750)
#define EMI_LTCT1_2ND               (EMI_BASE+0x754)
#define EMI_LTCT2_2ND               (EMI_BASE+0x758)
#define EMI_LTCT3_2ND               (EMI_BASE+0x75C)
#define EMI_BWCT0_3RD               (EMI_BASE+0x770)
#define EMI_BWCT0_4TH               (EMI_BASE+0x780)
#define EMI_BWCT0_5TH               (EMI_BASE+0x7B0)
#define EMI_BWCT0_6TH               (EMI_BASE+0x7C8)
#define EMI_SNST                    (EMI_BASE+0x7F8)
#define EMI_SLVA                    (EMI_BASE+0x800)
#define EMI_AXI_BIST_ADR0           (EMI_BASE+0x98c)
#define EMI_AXI_BIST_ADR1           (EMI_BASE+0x990)
#define EMI_AXI_BIST_ADR2           (EMI_BASE+0x994)

#define EMI_MPU_CTRL                (EMI_MPU_BASE+0x000)
#define EMI_MPU_DBG                 (EMI_MPU_BASE+0x004)
#define EMI_MPU_SA0                 (EMI_MPU_BASE+0x100)
#define EMI_MPU_EA0                 (EMI_MPU_BASE+0x200)
#define EMI_MPU_SA(region)          (EMI_MPU_SA0 + (region*4))
#define EMI_MPU_EA(region)          (EMI_MPU_EA0 + (region*4))
#define EMI_MPU_APC0                (EMI_MPU_BASE+0x300)
#define EMI_MPU_APC(region, dgroup) (EMI_MPU_APC0 + (region*4) + ((dgroup)*0x100))
#define EMI_MPU_CTRL_D0             (EMI_MPU_BASE+0x800)
#define EMI_MPU_CTRL_D(domain)      (EMI_MPU_CTRL_D0 + (domain*4))
#define EMI_RG_MASK_D0              (EMI_MPU_BASE+0x900)
#define EMI_RG_MASK_D(domain)       (EMI_RG_MASK_D0 + (domain*4))

#define SUB_EMI_MPU_CTRL                 (SUB_EMI_MPU_BASE+0x000)
#define SUB_EMI_MPU_DBG                  (SUB_EMI_MPU_BASE+0x004)
#define SUB_EMI_MPU_SA0                  (SUB_EMI_MPU_BASE+0x100)
#define SUB_EMI_MPU_EA0                  (SUB_EMI_MPU_BASE+0x200)
#define SUB_EMI_MPU_SA(region)           (SUB_EMI_MPU_SA0 + (region*4))
#define SUB_EMI_MPU_EA(region)           (SUB_EMI_MPU_EA0 + (region*4))
#define SUB_EMI_MPU_APC0                 (SUB_EMI_MPU_BASE+0x300)
#define SUB_EMI_MPU_APC(region, dgroup)  (SUB_EMI_MPU_APC0 + (region*4) + ((dgroup)*0x100))
#define SUB_EMI_MPU_CTRL_D0              (SUB_EMI_MPU_BASE+0x800)
#define SUB_EMI_MPU_CTRL_D(domain)       (SUB_EMI_MPU_CTRL_D0 + (domain*4))
#define SUB_EMI_RG_MASK_D0               (SUB_EMI_MPU_BASE+0x900)
#define SUB_EMI_RG_MASK_D(domain)        (SUB_EMI_RG_MASK_D0 + (domain*4))

#define CHN_EMI_CONA(base)          (base + 0x000)
#define CHN_EMI_CONC(base)          (base + 0x010)

#endif	// __EMI_HW_H__
