/*
 * Copyright (C) 2021-2024, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>

#include <common/debug.h>

#include <ddrphy_phyinit.h>

#include <lib/mmio.h>

#include <platform_def.h>

#if STM32MP_DDR3_TYPE || STM32MP_DDR4_TYPE
#define PRODCODE_SIZE	177

static const uint32_t prodcode_addr[PRODCODE_SIZE] = {
	0x90000U, 0x90001U, 0x90002U, 0x90003U, 0x90004U, 0x90005U, 0x90029U, 0x9002AU, 0x9002BU,
	0x9002CU, 0x9002DU, 0x9002EU, 0x9002FU, 0x90030U, 0x90031U, 0x90032U, 0x90033U, 0x90034U,
	0x90035U, 0x90036U, 0x90037U, 0x90038U, 0x90039U, 0x9003AU, 0x9003BU, 0x9003CU, 0x9003DU,
	0x9003EU, 0x9003FU, 0x90040U, 0x90041U, 0x90042U, 0x90043U, 0x90044U, 0x90045U, 0x90046U,
	0x90047U, 0x90048U, 0x90049U, 0x9004AU, 0x9004BU, 0x9004CU, 0x9004DU, 0x9004EU, 0x9004FU,
	0x90050U, 0x90051U, 0x90052U, 0x90053U, 0x90054U, 0x90055U, 0x90056U, 0x90057U, 0x90058U,
	0x90059U, 0x9005AU, 0x9005BU, 0x9005CU, 0x9005DU, 0x9005EU, 0x9005FU, 0x90060U, 0x90061U,
	0x90062U, 0x90063U, 0x90064U, 0x90065U, 0x90066U, 0x90067U, 0x90068U, 0x90069U, 0x9006AU,
	0x9006BU, 0x9006CU, 0x9006DU, 0x9006EU, 0x9006FU, 0x90070U, 0x90071U, 0x90072U, 0x90073U,
	0x90074U, 0x90075U, 0x90076U, 0x90077U, 0x90078U, 0x90079U, 0x9007AU, 0x9007BU, 0x9007CU,
	0x9007DU, 0x9007EU, 0x9007FU, 0x90080U, 0x90081U, 0x90082U, 0x90083U, 0x90084U, 0x90085U,
	0x90086U, 0x90087U, 0x90088U, 0x90089U, 0x9008AU, 0x9008BU, 0x9008CU, 0x9008DU, 0x9008EU,
	0x9008FU, 0x90090U, 0x90091U, 0x90092U, 0x90093U, 0x90094U, 0x90095U, 0x90096U, 0x90097U,
	0x90098U, 0x90099U, 0x9009AU, 0x9009BU, 0x9009CU, 0x9009DU, 0x9009EU, 0x9009FU, 0x900A0U,
	0x900A1U, 0x900A2U, 0x900A3U, 0x900A4U, 0x900A5U, 0x900A6U, 0x900A7U, 0x900A8U, 0x900A9U,
	0x900AAU, 0x900ABU, 0x900ACU, 0x900ADU, 0x900AEU, 0x900AFU, 0x900B0U, 0x900B1U, 0x900B2U,
	0x900B3U, 0x900B4U, 0x900B5U, 0x900B6U, 0x900B7U, 0x900B8U, 0x900B9U, 0x900BAU, 0x900BBU,
	0x900BCU, 0x900BDU, 0x900BEU, 0x900BFU, 0x900C0U, 0x900C1U, 0x900C2U, 0x900C3U, 0x900C4U,
	0x900C5U, 0x900C6U, 0x900C7U, 0x900C8U, 0x900C9U, 0x900CAU, 0x90006U, 0x90007U, 0x90008U,
	0x90009U, 0x9000AU, 0x9000BU, 0xD00E7U, 0x90017U, 0x90026U,
};

static const uint16_t prodcode_data[PRODCODE_SIZE] = {
	0x0010U, 0x0400U, 0x010EU, 0x0000U, 0x0000U, 0x0008U, 0x000BU, 0x0480U, 0x0109U, 0x0008U,
	0x0448U, 0x0139U, 0x0008U, 0x0478U, 0x0109U, 0x0002U, 0x0010U, 0x0139U, 0x000BU, 0x07C0U,
	0x0139U, 0x0044U, 0x0633U, 0x0159U, 0x014FU, 0x0630U, 0x0159U, 0x0047U, 0x0633U, 0x0149U,
	0x004FU, 0x0633U, 0x0179U, 0x0008U, 0x00E0U, 0x0109U, 0x0000U, 0x07C8U, 0x0109U, 0x0000U,
	0x0001U, 0x0008U, 0x0030U, 0x065AU, 0x0009U, 0x0000U, 0x045AU, 0x0009U, 0x0000U, 0x0448U,
	0x0109U, 0x0040U, 0x0633U, 0x0179U, 0x0001U, 0x0618U, 0x0109U, 0x40C0U, 0x0633U, 0x0149U,
	0x0008U, 0x0004U, 0x0048U, 0x4040U, 0x0633U, 0x0149U, 0x0000U, 0x0004U, 0x0048U, 0x0040U,
	0x0633U, 0x0149U, 0x0000U, 0x0658U, 0x0109U, 0x0010U, 0x0004U, 0x0018U, 0x0000U, 0x0004U,
	0x0078U, 0x0549U, 0x0633U, 0x0159U, 0x0D49U, 0x0633U, 0x0159U, 0x094AU, 0x0633U, 0x0159U,
	0x0441U, 0x0633U, 0x0149U, 0x0042U, 0x0633U, 0x0149U, 0x0001U, 0x0633U, 0x0149U, 0x0000U,
	0x00E0U, 0x0109U, 0x000AU, 0x0010U, 0x0109U, 0x0009U, 0x03C0U, 0x0149U, 0x0009U, 0x03C0U,
	0x0159U, 0x0018U, 0x0010U, 0x0109U, 0x0000U, 0x03C0U, 0x0109U, 0x0018U, 0x0004U, 0x0048U,
	0x0018U, 0x0004U, 0x0058U, 0x000BU, 0x0010U, 0x0109U, 0x0001U, 0x0010U, 0x0109U, 0x0005U,
	0x07C0U, 0x0109U, 0x0000U, 0x8140U, 0x010CU, 0x0010U, 0x8138U, 0x0104U, 0x0008U, 0x0448U,
	0x0109U, 0x000FU, 0x07C0U, 0x0109U, 0x0047U, 0x0630U, 0x0109U, 0x0008U, 0x0618U, 0x0109U,
	0x0008U, 0x00E0U, 0x0109U, 0x0000U, 0x07C8U, 0x0109U, 0x0008U, 0x8140U, 0x010CU, 0x0000U,
	0x0478U, 0x0109U, 0x0000U, 0x0001U, 0x0008U, 0x0008U, 0x0004U, 0x0000U, 0x0008U, 0x07C8U,
	0x0109U, 0x0000U, 0x0400U, 0x0106U, 0x0400U, 0x0000U, 0x002CU,
	};

#else /* STM32MP_LPDDR4_TYPE */
#define PRODCODE_SIZE		481

static const uint32_t prodcode_addr[PRODCODE_SIZE] = {
	0x90000U, 0x90001U, 0x90002U, 0x90003U, 0x90004U, 0x90005U, 0x90029U, 0x9002AU, 0x9002BU,
	0x9002CU, 0x9002DU, 0x9002EU, 0x9002FU, 0x90030U, 0x90031U, 0x90032U, 0x90033U, 0x90034U,
	0x90035U, 0x90036U, 0x90037U, 0x90038U, 0x90039U, 0x9003AU, 0x9003BU, 0x9003CU, 0x9003DU,
	0x9003EU, 0x9003FU, 0x90040U, 0x90041U, 0x90042U, 0x90043U, 0x90044U, 0x90045U, 0x90046U,
	0x90047U, 0x90048U, 0x90049U, 0x9004AU, 0x9004BU, 0x9004CU, 0x9004DU, 0x9004EU, 0x9004FU,
	0x90050U, 0x90051U, 0x90052U, 0x90053U, 0x90054U, 0x90055U, 0x90056U, 0x90057U, 0x90058U,
	0x90059U, 0x9005AU, 0x9005BU, 0x9005CU, 0x9005DU, 0x9005EU, 0x9005FU, 0x90060U, 0x90061U,
	0x90062U, 0x90063U, 0x90064U, 0x90065U, 0x90066U, 0x90067U, 0x90068U, 0x90069U, 0x9006AU,
	0x9006BU, 0x9006CU, 0x9006DU, 0x9006EU, 0x9006FU, 0x90070U, 0x90071U, 0x90072U, 0x90073U,
	0x90074U, 0x90075U, 0x90076U, 0x90077U, 0x90078U, 0x90079U, 0x9007AU, 0x9007BU, 0x9007CU,
	0x9007DU, 0x9007EU, 0x9007FU, 0x90080U, 0x90081U, 0x90082U, 0x90083U, 0x90084U, 0x90085U,
	0x90086U, 0x90087U, 0x90088U, 0x90089U, 0x9008AU, 0x9008BU, 0x9008CU, 0x9008DU, 0x9008EU,
	0x9008FU, 0x90090U, 0x90091U, 0x90092U, 0x90093U, 0x90094U, 0x90095U, 0x90096U, 0x90097U,
	0x90098U, 0x90099U, 0x9009AU, 0x9009BU, 0x9009CU, 0x9009DU, 0x9009EU, 0x9009FU, 0x900A0U,
	0x900A1U, 0x900A2U, 0x900A3U, 0x900A4U, 0x900A5U, 0x900A6U, 0x900A7U, 0x900A8U, 0x900A9U,
	0x40000U, 0x40020U, 0x40040U, 0x40060U, 0x40001U, 0x40021U, 0x40041U, 0x40061U, 0x40002U,
	0x40022U, 0x40042U, 0x40062U, 0x40003U, 0x40023U, 0x40043U, 0x40063U, 0x40004U, 0x40024U,
	0x40044U, 0x40064U, 0x40005U, 0x40025U, 0x40045U, 0x40065U, 0x40006U, 0x40026U, 0x40046U,
	0x40066U, 0x40007U, 0x40027U, 0x40047U, 0x40067U, 0x40008U, 0x40028U, 0x40048U, 0x40068U,
	0x40009U, 0x40029U, 0x40049U, 0x40069U, 0x4000AU, 0x4002AU, 0x4004AU, 0x4006AU, 0x4000BU,
	0x4002BU, 0x4004BU, 0x4006BU, 0x4000CU, 0x4002CU, 0x4004CU, 0x4006CU, 0x4000DU, 0x4002DU,
	0x4004DU, 0x4006DU, 0x4000EU, 0x4002EU, 0x4004EU, 0x4006EU, 0x4000FU, 0x4002FU, 0x4004FU,
	0x4006FU, 0x40010U, 0x40030U, 0x40050U, 0x40070U, 0x40011U, 0x40031U, 0x40051U, 0x40071U,
	0x40012U, 0x40032U, 0x40052U, 0x40072U, 0x40013U, 0x40033U, 0x40053U, 0x40073U, 0x40014U,
	0x40034U, 0x40054U, 0x40074U, 0x40015U, 0x40035U, 0x40055U, 0x40075U, 0x40016U, 0x40036U,
	0x40056U, 0x40076U, 0x40017U, 0x40037U, 0x40057U, 0x40077U, 0x40018U, 0x40038U, 0x40058U,
	0x40078U, 0x40019U, 0x40039U, 0x40059U, 0x40079U, 0x4001AU, 0x4003AU, 0x4005AU, 0x4007AU,
	0x900AAU, 0x900ABU, 0x900ACU, 0x900ADU, 0x900AEU, 0x900AFU, 0x900B0U, 0x900B1U, 0x900B2U,
	0x900B3U, 0x900B4U, 0x900B5U, 0x900B6U, 0x900B7U, 0x900B8U, 0x900B9U, 0x900BAU, 0x900BBU,
	0x900BCU, 0x900BDU, 0x900BEU, 0x900BFU, 0x900C0U, 0x900C1U, 0x900C2U, 0x900C3U, 0x900C4U,
	0x900C5U, 0x900C6U, 0x900C7U, 0x900C8U, 0x900C9U, 0x900CAU, 0x900CBU, 0x900CCU, 0x900CDU,
	0x900CEU, 0x900CFU, 0x900D0U, 0x900D1U, 0x900D2U, 0x900D3U, 0x900D4U, 0x900D5U, 0x900D6U,
	0x900D7U, 0x900D8U, 0x900D9U, 0x900DAU, 0x900DBU, 0x900DCU, 0x900DDU, 0x900DEU, 0x900DFU,
	0x900E0U, 0x900E1U, 0x900E2U, 0x900E3U, 0x900E4U, 0x900E5U, 0x900E6U, 0x900E7U, 0x900E8U,
	0x900E9U, 0x900EAU, 0x900EBU, 0x900ECU, 0x900EDU, 0x900EEU, 0x900EFU, 0x900F0U, 0x900F1U,
	0x900F2U, 0x900F3U, 0x900F4U, 0x900F5U, 0x900F6U, 0x900F7U, 0x900F8U, 0x900F9U, 0x900FAU,
	0x900FBU, 0x900FCU, 0x900FDU, 0x900FEU, 0x900FFU, 0x90100U, 0x90101U, 0x90102U, 0x90103U,
	0x90104U, 0x90105U, 0x90106U, 0x90107U, 0x90108U, 0x90109U, 0x9010AU, 0x9010BU, 0x9010CU,
	0x9010DU, 0x9010EU, 0x9010FU, 0x90110U, 0x90111U, 0x90112U, 0x90113U, 0x90114U, 0x90115U,
	0x90116U, 0x90117U, 0x90118U, 0x90119U, 0x9011AU, 0x9011BU, 0x9011CU, 0x9011DU, 0x9011EU,
	0x9011FU, 0x90120U, 0x90121U, 0x90122U, 0x90123U, 0x90124U, 0x90125U, 0x90126U, 0x90127U,
	0x90128U, 0x90129U, 0x9012AU, 0x9012BU, 0x9012CU, 0x9012DU, 0x9012EU, 0x9012FU, 0x90130U,
	0x90131U, 0x90132U, 0x90133U, 0x90134U, 0x90135U, 0x90136U, 0x90137U, 0x90138U, 0x90139U,
	0x9013AU, 0x9013BU, 0x9013CU, 0x9013DU, 0x9013EU, 0x9013FU, 0x90140U, 0x90141U, 0x90142U,
	0x90143U, 0x90144U, 0x90145U, 0x90146U, 0x90147U, 0x90148U, 0x90149U, 0x9014AU, 0x9014BU,
	0x9014CU, 0x9014DU, 0x9014EU, 0x9014FU, 0x90150U, 0x90151U, 0x90152U, 0x90153U, 0x90154U,
	0x90155U, 0x90156U, 0x90157U, 0x90158U, 0x90159U, 0x9015AU, 0x9015BU, 0x9015CU, 0x9015DU,
	0x9015EU, 0x9015FU, 0x90160U, 0x90161U, 0x90162U, 0x90163U, 0x90164U, 0x90165U, 0x90166U,
	0x90167U, 0x90168U, 0x90169U, 0x9016AU, 0x9016BU, 0x9016CU, 0x9016DU, 0x9016EU, 0x9016FU,
	0x90170U, 0x90171U, 0x90172U, 0x90173U, 0x90174U, 0x90175U, 0x90176U, 0x90177U, 0x90178U,
	0x90179U, 0x9017AU, 0x9017BU, 0x9017CU, 0x9017DU, 0x9017EU, 0x9017FU, 0x90180U, 0x90181U,
	0x90182U, 0x90183U, 0x90184U, 0x90006U, 0x90007U, 0x90008U, 0x90009U, 0x9000AU, 0x9000BU,
	0xD00E7U, 0x90017U, 0x9001FU, 0x90026U, 0x400D0U, 0x400D1U, 0x400D2U, 0x400D3U, 0x400D4U,
	0x400D5U, 0x400D6U, 0x400D7U, 0x2003AU,
	};

static const uint16_t prodcode_data[PRODCODE_SIZE] = {
	0x0010U, 0x0400U, 0x010EU, 0x0000U, 0x0000U, 0x0008U, 0x000BU, 0x0480U, 0x0109U, 0x0008U,
	0x0448U, 0x0139U, 0x0008U, 0x0478U, 0x0109U, 0x0000U, 0x00E8U, 0x0109U, 0x0002U, 0x0010U,
	0x0139U, 0x000BU, 0x07C0U, 0x0139U, 0x0044U, 0x0633U, 0x0159U, 0x014FU, 0x0630U, 0x0159U,
	0x0047U, 0x0633U, 0x0149U, 0x004FU, 0x0633U, 0x0179U, 0x0008U, 0x00E0U, 0x0109U, 0x0000U,
	0x07C8U, 0x0109U, 0x0000U, 0x0001U, 0x0008U, 0x0030U, 0x065AU, 0x0009U, 0x0000U, 0x045AU,
	0x0009U, 0x0000U, 0x0448U, 0x0109U, 0x0040U, 0x0633U, 0x0179U, 0x0001U, 0x0618U, 0x0109U,
	0x40C0U, 0x0633U, 0x0149U, 0x0008U, 0x0004U, 0x0048U, 0x4040U, 0x0633U, 0x0149U, 0x0000U,
	0x0004U, 0x0048U, 0x0040U, 0x0633U, 0x0149U, 0x0000U, 0x0658U, 0x0109U, 0x0010U, 0x0004U,
	0x0018U, 0x0000U, 0x0004U, 0x0078U, 0x0549U, 0x0633U, 0x0159U, 0x0D49U, 0x0633U, 0x0159U,
	0x094AU, 0x0633U, 0x0159U, 0x0441U, 0x0633U, 0x0149U, 0x0042U, 0x0633U, 0x0149U, 0x0001U,
	0x0633U, 0x0149U, 0x0000U, 0x00E0U, 0x0109U, 0x000AU, 0x0010U, 0x0109U, 0x0009U, 0x03C0U,
	0x0149U, 0x0009U, 0x03C0U, 0x0159U, 0x0018U, 0x0010U, 0x0109U, 0x0000U, 0x03C0U, 0x0109U,
	0x0018U, 0x0004U, 0x0048U, 0x0018U, 0x0004U, 0x0058U, 0x000BU, 0x0010U, 0x0109U, 0x0001U,
	0x0010U, 0x0109U, 0x0005U, 0x07C0U, 0x0109U, 0x0811U, 0x0880U, 0x0000U, 0x0000U, 0x4008U,
	0x0083U, 0x004FU, 0x0000U, 0x4040U, 0x0083U, 0x0051U, 0x0000U, 0x0811U, 0x0880U, 0x0000U,
	0x0000U, 0x0720U, 0x000FU, 0x1740U, 0x0000U, 0x0016U, 0x0083U, 0x004BU, 0x0000U, 0x0716U,
	0x000FU, 0x2001U, 0x0000U, 0x0716U, 0x000FU, 0x2800U, 0x0000U, 0x0716U, 0x000FU, 0x0F00U,
	0x0000U, 0x0720U, 0x000FU, 0x1400U, 0x0000U, 0x0E08U, 0x0C15U, 0x0000U, 0x0000U, 0x0625U,
	0x0015U, 0x0000U, 0x0000U, 0x4028U, 0x0080U, 0x0000U, 0x0000U, 0x0E08U, 0x0C1AU, 0x0000U,
	0x0000U, 0x0625U, 0x001AU, 0x0000U, 0x0000U, 0x4040U, 0x0080U, 0x0000U, 0x0000U, 0x2604U,
	0x0015U, 0x0000U, 0x0000U, 0x0708U, 0x0005U, 0x0000U, 0x2002U, 0x0008U, 0x0080U, 0x0000U,
	0x0000U, 0x2604U, 0x001AU, 0x0000U, 0x0000U, 0x0708U, 0x000AU, 0x0000U, 0x2002U, 0x4040U,
	0x0080U, 0x0000U, 0x0000U, 0x060AU, 0x0015U, 0x1200U, 0x0000U, 0x061AU, 0x0015U, 0x1300U,
	0x0000U, 0x060AU, 0x001AU, 0x1200U, 0x0000U, 0x0642U, 0x001AU, 0x1300U, 0x0000U, 0x4808U,
	0x0880U, 0x0000U, 0x0000U, 0x0000U, 0x0790U, 0x011AU, 0x0008U, 0x07AAU, 0x002AU, 0x0010U,
	0x07B2U, 0x002AU, 0x0000U, 0x07C8U, 0x0109U, 0x0010U, 0x0010U, 0x0109U, 0x0010U, 0x02A8U,
	0x0129U, 0x0008U, 0x0370U, 0x0129U, 0x000AU, 0x03C8U, 0x01A9U, 0x000CU, 0x0408U, 0x0199U,
	0x0014U, 0x0790U, 0x011AU, 0x0008U, 0x0004U, 0x0018U, 0x000EU, 0x0408U, 0x0199U, 0x0008U,
	0x8568U, 0x0108U, 0x0018U, 0x0790U, 0x016AU, 0x0008U, 0x01D8U, 0x0169U, 0x0010U, 0x8558U,
	0x0168U, 0x1FF8U, 0x85A8U, 0x01E8U, 0x0050U, 0x0798U, 0x016AU, 0x0060U, 0x07A0U, 0x016AU,
	0x0008U, 0x8310U, 0x0168U, 0x0008U, 0xA310U, 0x0168U, 0x000AU, 0x0408U, 0x0169U, 0x006EU,
	0x0000U, 0x0068U, 0x0000U, 0x0408U, 0x0169U, 0x0000U, 0x8310U, 0x0168U, 0x0000U, 0xA310U,
	0x0168U, 0x1FF8U, 0x85A8U, 0x01E8U, 0x0068U, 0x0798U, 0x016AU, 0x0078U, 0x07A0U, 0x016AU,
	0x0068U, 0x0790U, 0x016AU, 0x0008U, 0x8B10U, 0x0168U, 0x0008U, 0xAB10U, 0x0168U, 0x000AU,
	0x0408U, 0x0169U, 0x0058U, 0x0000U, 0x0068U, 0x0000U, 0x0408U, 0x0169U, 0x0000U, 0x8B10U,
	0x0168U, 0x0001U, 0xAB10U, 0x0168U, 0x0000U, 0x01D8U, 0x0169U, 0x0080U, 0x0790U, 0x016AU,
	0x0018U, 0x07AAU, 0x006AU, 0x000AU, 0x0000U, 0x01E9U, 0x0008U, 0x8080U, 0x0108U, 0x000FU,
	0x0408U, 0x0169U, 0x000CU, 0x0000U, 0x0068U, 0x0009U, 0x0000U, 0x01A9U, 0x0000U, 0x0408U,
	0x0169U, 0x0000U, 0x8080U, 0x0108U, 0x0008U, 0x07AAU, 0x006AU, 0x0000U, 0x8568U, 0x0108U,
	0x00B7U, 0x0790U, 0x016AU, 0x001FU, 0x0000U, 0x0068U, 0x0008U, 0x8558U, 0x0168U, 0x000FU,
	0x0408U, 0x0169U, 0x000DU, 0x0000U, 0x0068U, 0x0000U, 0x0408U, 0x0169U, 0x0000U, 0x8558U,
	0x0168U, 0x0008U, 0x03C8U, 0x01A9U, 0x0003U, 0x0370U, 0x0129U, 0x0020U, 0x02AAU, 0x0009U,
	0x0008U, 0x00E8U, 0x0109U, 0x0000U, 0x8140U, 0x010CU, 0x0010U, 0x8138U, 0x0104U, 0x0008U,
	0x0448U, 0x0109U, 0x000FU, 0x07C0U, 0x0109U, 0x0000U, 0x00E8U, 0x0109U, 0x0047U, 0x0630U,
	0x0109U, 0x0008U, 0x0618U, 0x0109U, 0x0008U, 0x00E0U, 0x0109U, 0x0000U, 0x07C8U, 0x0109U,
	0x0008U, 0x8140U, 0x010CU, 0x0000U, 0x0478U, 0x0109U, 0x0000U, 0x0001U, 0x0008U, 0x0008U,
	0x0004U, 0x0000U, 0x0008U, 0x07C8U, 0x0109U, 0x0000U, 0x0400U, 0x0106U, 0x0400U, 0x0000U,
	0x002BU, 0x0069U, 0x0000U, 0x0101U, 0x0105U, 0x0107U, 0x010FU, 0x0202U, 0x020AU, 0x020BU,
	0x0002U,
	};
#endif /* STM32MP_DDR3_TYPE || STM32MP_DDR4_TYPE */

/*
 * Loads PIE instruction sequence PHY registers
 * @returns void
 */
void ddrphy_phyinit_loadpieprodcode(void)
{
	int i;

	for (i = 0; i < PRODCODE_SIZE; i++) {
		mmio_write_16((uintptr_t)(DDRPHYC_BASE + (4U * prodcode_addr[i])),
			      prodcode_data[i]);
	}
}
