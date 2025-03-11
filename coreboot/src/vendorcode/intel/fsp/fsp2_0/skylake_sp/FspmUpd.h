/** @file

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.
* Neither the name of Intel Corporation nor the names of its contributors may
  be used to endorse or promote products derived from this software without
  specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.

  This file is automatically generated. Please do NOT modify !!!

**/

#ifndef __FSPMUPD_H__
#define __FSPMUPD_H__

#include <FspUpd.h>

#pragma pack(1)

/**
 FSP Header Version Number
**/
#define FSP_UPD_VERSION (0x1947)

#define MAX_CHANNEL               6     /* Maximum Number of Memory Channels    */
#define MAX_DIMM                  2     /* Maximum Number of DIMMs per Channel  */

#define HIDE                      1
#define NOT_HIDE                  0

#define IIO_BIFURCATE_AUTO      0xFF

/* Ports 1D-1A, 2D-2A, 3D-3A */
#define IIO_BIFURCATE_x4x4x4x4  0
#define IIO_BIFURCATE_x4x4xxx8  1
#define IIO_BIFURCATE_xxx8x4x4  2
#define IIO_BIFURCATE_xxx8xxx8  3
#define IIO_BIFURCATE_xxxxxx16  4
#define IIO_BIFURCATE_xxxxxxxx  0xF


typedef enum {
	IioPortA = 0,
	IioPortB = 1,
	IioPortC = 2,
	IioPortD = 3
} IIO_PORTS;

/**
 * Enums and Macro definitions needed for reference RVP and CRB
 * table declarations
**/
typedef enum {
	Iio_Socket0 = 0,
	Iio_Socket1,
	Iio_Socket2,
	Iio_Socket3,
	Iio_Socket4,
	Iio_Socket5,
	Iio_Socket6,
	Iio_Socket7
} IIO_SOCKETS;

typedef enum {
	Iio_Iou0 = 0,
	Iio_Iou1,
	Iio_Iou2,
	Iio_Mcp0,
	Iio_Mcp1,
	Iio_IouMax
} IIO_IOUS;

/**
 IIO PCIe Ports
 **/
typedef enum {
	PORT_0 = 0,
	// IOU2
	PORT_1A,
	PORT_1B,
	PORT_1C,
	PORT_1D,
	// IOU0
	PORT_2A,
	PORT_2B,
	PORT_2C,
	PORT_2D,
	// IOU1
	PORT_3A,
	PORT_3B,
	PORT_3C,
	PORT_3D,
	// MCP0
	PORT_4A,
	PORT_4B,
	PORT_4C,
	PORT_4D,
	// MCP1
	PORT_5A,
	PORT_5B,
	PORT_5C,
	PORT_5D,
	MAX_PORTS
} PCIE_PORTS;

/**
 IIO Stacks
 **/
typedef enum {
	CSTACK = 0,
	PSTACK0,
	PSTACK1,
	PSTACK2,
	PSTACK3,
	PSTACK4,
	MAX_STACKS
} IIO_STACKS;

#define IioStack0 CSTACK
#define MAX_LOGIC_IIO_STACK MAX_STACKS

/**
 NTB Per Port Definition
 **/
typedef enum {
	NTB_PORT_TRANSPARENT = 0,
	NTB_PORT_NTB_NTB
} NTB_PPD;

/**
 NTB Upstream/Downstream Configuration
 **/
typedef enum {
	NTB_XLINK_DSD_USP = 2,
	NTB_XLINK_USD_DSP
} NTB_XLINK;

/**
 PCIe Link Speed Selection
 **/
typedef enum {
	PcieAuto = 0,
	PcieGen1,
	PcieGen2,
	PcieGen3
} PCIE_LINK_SPEED;

/**
 GPIO Pad Number
**/

typedef UINT32 UPD_GPIO_PAD;

/**
 UPD_GPIO_CONFIG:
 64 bit struct defining GPIO PAD configuration
**/
typedef struct {
	/**
	Pad Mode
	Pad can be set as GPIO or one of its native functions.
	When in native mode setting Direction (except Inversion), OutputState,
	InterruptConfig and Host Software Pad Ownership are unnecessary.
	Refer to definition of GPIO_PAD_MODE.
	Refer to EDS for each native mode according to the pad.
	**/
	UINT32 PadMode            : 4;
	/**
	Host Software Pad Ownership
	Set pad to ACPI mode or GPIO Driver Mode.
	Refer to definition of GPIO_HOSTSW_OWN.
	**/
	UINT32 HostSoftPadOwn     : 2;
	/**
	GPIO Direction
	Can choose between In, In with inversion Out, both In and Out,
		both In with inversion and out or disabling both.
	Refer to definition of GPIO_DIRECTION for supported settings.
	**/
	UINT32 Direction           : 5;
	/**
	Output State
	Set Pad output value.
	Refer to definition of GPIO_OUTPUT_STATE for supported settings.
	This setting takes place when output is enabled.
	**/
	UINT32 OutputState         : 2;
	/**
	GPIO Interrupt Configuration
	Set Pad to cause one of interrupts (IOxAPIC/SCI/SMI/NMI). This setting
		is applicable only if GPIO is in input mode.
	If GPIO is set to cause an SCI then also Gpe is enabled for this pad.
	Refer to definition of GPIO_INT_CONFIG for supported settings.
	**/
	UINT32 InterruptConfig     : 8;
	/**
	GPIO Power Configuration.
	This setting controls Pad Reset Configuration.
	Refer to definition of GPIO_RESET_CONFIG for supported settings.
	**/
	UINT32 PowerConfig        : 4;

	/**
	GPIO Electrical Configuration
	This setting controls pads termination and voltage tolerance.
	Refer to definition of GPIO_ELECTRICAL_CONFIG for supported settings.
	**/
	UINT32 ElectricalConfig   : 7;

	/**
	GPIO Lock Configuration
	This setting controls pads lock.
	Refer to definition of GPIO_LOCK_CONFIG for supported settings.
	**/
	UINT32 LockConfig         : 3;
	/**
	Additional GPIO configuration
	Refer to definition of GPIO_OTHER_CONFIG for supported settings.
	**/
	UINT32 OtherSettings     :  2;

	UINT32 RsvdBits          : 27;    ///< Reserved bits for future extension

	UINT32 RsvdBits1;                 ///< Reserved bits for future extension
} UPD_GPIO_CONFIG;

/**
 UPD_GPIO_INIT_CONFIG:
 Defines a GPIO Pad and its respective configuration
 Constitutes one entry in the GPIO config table
 Reference FSP implementation:
 AndersonLakePlatPkg\Uba\UbaMain\Pei\TypeAndersonCreek\GpioTable.c
 Bootloaders can include the following to define GPIO PADs/other macros:
 PurleySktPkg\SouthClusterLbg\Include\Library\GpioLib.h
**/
typedef struct {
	UPD_GPIO_PAD        GpioPad;
	UPD_GPIO_CONFIG     GpioConfig;
} UPD_GPIO_INIT_CONFIG;

/**
 GPIOTABLE_CONFIG:
 GpioTable -       Base Address of the Gpio Table declared by the
		bootloader.
		Default: NULL
 NumberofEntries - Number of Entries in the GPIO Table provided
		Default: 0
 If GpioTable is Null or NumberofEntries is 0, then FSP will handle Gpio Pad
 configuration using default GPIO_INIT_CONFIG tables
**/
typedef struct {
	UPD_GPIO_INIT_CONFIG  *GpioTable;
	UINT32                NumberOfEntries;
} GPIOTABLE_CONFIG;

/**
 UPD_IIO_BIFURCATION_DATA_ENTRY:
 Defines IIO Bifurcation for IIO Units
 Constitutes one entry in the IIO Bifurcation table, describing bifurcation entries as:
 Socket | IOU | Bifurcation
 Valid IouNumbers are from 0 to 4
 Reference FSP Implementation :
 AndersonLakePlatPkg\Uba\UbaMain\Pei\TypeAndersonCreek\IioBifurInit.c
 Definitions for relevant bifurcation macros:
 NumberCpRcPkg\Library\BaseMemoryCoreLib\Chip\Skx\Include\Iio\IioRegs.h
**/
typedef struct {
	UINT8 Socket;
	UINT8 IouNumber;
	UINT8 Bifurcation;
} UPD_IIO_BIFURCATION_DATA_ENTRY;

/**
 IIOBIFURCATION_CONFIG:
 IIoBifurcationTable - Base Address of the IIO Bifurcation table
		declared by the bootloader
		Default: NULL
 NumberofEntries -     Number of Entries in the IIO Bifurcation Table
		Default: 0
 If IIoBifurcationTable is Null or NumberofEntries is 0, then FSP will handle IIO
 bifurcation using default IIO_BIFURCATION_DATA_ENTRY tables
**/
typedef struct {
	UPD_IIO_BIFURCATION_DATA_ENTRY  *IIoBifurcationTable;
	UINT32                          NumberOfEntries;
} IIOBIFURCATION_CONFIG;

/**
 VTD_CONFIG :
 VT direct IO Configuration Support
 VTdSupport       - Enable/Disable VTd Support
 CoherencySupport - Enable/Disable Coherency Support
 ATS              - Enable/Disable Address Translation Services
 FSP Will Disable VTd by default
**/
typedef struct {
	UINT8 VTdSupport;
	UINT8 CoherencySupport;
	UINT8 ATS;
} VTD_CONFIG;

/**
 UPD_PCIE_PORT_CONFIG
 PCIe port configuration
 PortIndex           - Index of the port to be configured as defined by PCI_PORTS
 HidePort            - Hide the selected port
 DeEmphasis          - DeEmphasis of the selected PCIe port
 PortLinkSpeed       - Port Link Speed. Use PCIE_LINK_SPEED to set
 DfxDnTxPreset       - PCIe Downstream Tx Preset, valid values (0x00 - 0x09,
		0xFF is Auto, Auto sets 0x07)
 DfxRxPreset         - PCIe Downstream Rx Preset, valid values (0x00 - 0x06, 0xFF is Auto)
 DfxUpTxPreset       - PCIe Upstream Tx Preset, valid values (0x00 - 0x09, 0xFF is Auto)
 Sris                - Enable/Disable SRIS (0x00 - Disable, 0x01 - Enable)
 PcieCommonClock     - Configure port clocking. (0x00 - Distinct, 0x01 - Common)
 MaxPayload          - PCIe Max Payload Size on the port
 NtbPpd              - NTB port Configuration as defined in NTB_PPD
 NtbSplitBar         - 0: Use one 64, 1: Use two 32-bit split bars
 NtbSBar01Prefetch   - Configure Split BAR 0/1 as prefetchable
 NtbXlinkCtlOverride - NTB Cross-link as defined in NTB_XLINK
 NtbBarSizePBar4     - Set Prefetchable BAR 4 size for the primary NTB side in case
		Split Bar is Enabled
 NtbBarSizePBar5     - Set Prefetchable BAR 5 size for the primary NTB side in case
		Split Bar is Enabled
 FSP_WA: Till FSP fixes NtbBarSizeOverride, parameters below are MANDATORY!:
 These BAR size registers are write once registers and will be programmed with 0
		if not passed as FSP is
 hardcoding NtbBarSizeOverride to 0x01 for now.
 Split BAR sizes would need to be programmed mandatorily as well in case split bars
		are enabled.
	NtbBarSizePBar23    - Set Prefetchable BAR 23 size for the primary NTB side
	NtbBarSizePBar45    - Used to set bar 4 and 5 sizes in case Split Bar is Disabled
	NtbBarSizeSBar23    - Set Prefetchable BAR 23 size for the secondary NTB side
	NtbBarSizeSBar45    - Set Prefetchable BAR 45 size for the secondary NTB side in case
		Split Bar is disabled
**/
typedef struct {
	UINT32  PortIndex;
	UINT8   HidePort;
	UINT8   DeEmphasis;
	UINT8   PortLinkSpeed;
	UINT8   MaxPayload;
	UINT8   DfxDnTxPreset;
	UINT8   DfxRxPreset;
	UINT8   DfxUpTxPreset;
	UINT8   Sris;
	UINT8   PcieCommonClock;
	UINT8   NtbPpd;
	UINT8   NtbSplitBar;
	UINT8   NtbBarSizePBar23;
	UINT8   NtbBarSizePBar4;
	UINT8   NtbBarSizePBar5;
	UINT8   NtbBarSizePBar45;
	UINT8   NtbBarSizeSBar23;
	UINT8   NtbBarSizeSBar4;
	UINT8   NtbBarSizeSBar5;
	UINT8   NtbBarSizeSBar45;
	UINT8   NtbSBar01Prefetch;
	UINT8   NtbXlinkCtlOverride;
} UPD_PCI_PORT_CONFIG;

/**
 PCIEPORT_CONFIG:
 PciePortConfiguration - Pointer to an array of PCIe port configuration structures
	as declared above
 NumberOfEntries       - Number of elements in the PciePortConfiguration Array
**/
typedef struct {
	UPD_PCI_PORT_CONFIG  *ConfigurationTable;

	UINT16                NumberOfEntries;
} IIOPCIPORT_CONFIG;

/**
 UPD_IIO_STACK_RESOURCE_CONFIG:
 StackIndex             - Index of the CPU IIO Stack to be configured as defined by IIO_STACKS
 PciResourceIoBase
 PciResourceIoLimit
 PciResourceMem32Base
 PciResourceMem32Limit
 PciResourceMem64Base
 PciResourceMem64Limit
**/
typedef struct {
	UINT8   StackIndex;
	UINT16  PciResourceIoBase;
	UINT16  PciResourceIoLimit;
	UINT32  PciResourceMem32Base;
	UINT32  PciResourceMem32Limit;
	UINT64  PciResourceMem64Base;
	UINT64  PciResourceMem64Limit;
} UPD_IIO_STACK_RESOURCE_CONFIG;

/**
 IIORESOURCE_CONFIG:
 ResourceConfigTable   - Pointer to an Iio Stack Resource Configuration Structure Array
 NumberOfEntries       - Number of Entries in the Iio Stack Resource Configuration Array
**/
typedef struct {
	UPD_IIO_STACK_RESOURCE_CONFIG  *ResourceTable;
	UINT16                         NumberOfEntries;
} IIORESOURCE_CONFIG;

/**
 UPD_PCH_PCIE_PORT:
 PortIndex             -  PCH PCIe Port Index.
		Valid Port Numbers are: 0 to 19.
 Enable                -  Enable/Disable PCH PCIe port
 PortLinkSpeed         -  Port Link Speed. Use PCIE_LINK_SPEED to set
**/
typedef struct {
	UINT8    PortIndex;
	UINT8    ForceEnable;
	UINT8    PortLinkSpeed;
} UPD_PCH_PCIE_PORT;

/**
 PCHPCIPORT_CONFIG:
 PciPortConfig            - Pointer to an array of PCH PCI Ports to be configured
 RootPortFunctionSwapping - Disable root port swapping based on device
		connection status
 PciePllSsc               - Specifies the Pcie Pll Spread Spectrum Percentage
		The value of this policy is in 1/10th percent units.
		Valid spread range: 0-20. Auto: 0xFE (sets it to hardware default)
		Completely Disable PCIe PLL SSC: 0xFF
		A value of 0 is SSC of 0.0%. A value of 20 is SSC of 2.0%
 NumberOfEntries          - Number of entries in the PCH PCI Port configuration
**/
typedef struct {
	UPD_PCH_PCIE_PORT   *PciPortConfig;
	UINT8               RootPortFunctionSwapping;
	UINT8               PciePllSsc;
	UINT16              NumberOfEntries;
} PCHPCIPORT_CONFIG;

/** FSP-M Configuration
**/
typedef struct {

/** Offset 0x0040 - MRC Debug Print Level
	Select the FSP MRC debug message print level. Options are a bitmask, so you can
	combine options. BIT0:MIN DEBUG, BIT1:MAX DEBUG, BIT2:TRACE, BIT3:MEM TRAIN, BIT4:TEST,
	BIT5:CPGC, BIT6:REG ACCESS
**/
	UINT8                       PcdFspMrcDebugPrintErrorLevel;

/** Offset 0x0041 - KTI Debug Print Level
	Select the FSP KTI debug message print level. Options are a bitmask, so you can
	combine options. BIT0:ERROR, BIT1:WARNING, BIT2:INFO0, BIT3:INFO1
**/
	UINT8                       PcdFspKtiDebugPrintErrorLevel;

/** Offset 0x0042 - HSUART Device
	Select the PCI High Speed UART Device for Serial Port.
	0:HSUART0, 1:HSUART1, 2:HSUART2
**/
	UINT8                       PcdHsuartDevice;

/** Offset 0x0043 - Customer Revision
	The Customer can set this revision string for their own purpose.
**/
	UINT8                       PcdCustomerRevision[32];

/** Offset 0x0063 - GpioConfig
	GpioConfig Struct. Defaults: GpioTable:NULL, NumberOfEntries:0x00
**/
	GPIOTABLE_CONFIG            GpioConfig;

/** Offset 0x006B - IioBifurcationConfig
	IioBifurcationConfig Table Struct. Defaults: IioBifurcationTable:NULL,
		NumberOfEntries:0x00
**/
	IIOBIFURCATION_CONFIG       IioBifurcationConfig;

/** Offset 0x0073
**/
	UINT8                       UnusedUpdSpace0[16];

/** Offset 0x0083 - VTdConfig
	VTdConfig Struct. Defaults: All values are set to 0. VTd Disabled.
**/
	VTD_CONFIG                VTdConfig;

	UINT8                     reserved1[35];

/** Offset 0x00A9 - Board ID Number
	Select the BoardId based on the target Platform. Default assumes an unknown board.
**/
	UINT8                     BoardId;

	UINT8                     reserved2[24];

/** Offset 0x00C2 **/
	VOID                      *SetupStructPtr;

	UINT8                     reserved3[20];

/** Offset 0x00DA - IioPciConfig
	IIO Pci Port Config Struct. Defaults: All pointers are NULL. All values are set to zero.
**/
	IIOPCIPORT_CONFIG         IioPciConfig;

/** Offset 0x00E0 - PchPciConfig
	PCH Pci Port Config Struct. Defaults: All pointers are NULL. All values are set to zero.
**/
	PCHPCIPORT_CONFIG         PchPciConfig;

/** Offset 0x00E8 - IioResourceConfig
	IIO Resource Struct. Defaults: All pointers are NULL. All values are set to zero.
**/
	IIORESOURCE_CONFIG        IioResourceConfig;

	UINT8                     reserved4[3];

/** Offset 0x00F1 - DCI Enable
	Enable / Disable DCI
	$EN_DIS
**/
	UINT8                     PchDciEn;

/** Offset 0x00F2 - IO Margining Tool (IOMT) Enable
	Enable / Disable Io Margining Tool
	$EN_DIS
**/
	UINT8                     IomtEnable;

/** Offset 0x00F3 - Hyper Threading (HT) disable
	Disable Hyper threading. Disable: 0x01 | Enable: 0x00 | Default - HT enabled
	$EN_DIS
**/
	UINT8                     HyperThreadingDisable;

/** Offset 0x00F4
**/
	UINT8                     UnusedUpdSpace1[236];

/** Offset 0x01E0
**/
	UINT8                     ReservedMemoryInitUpd[16];
} FSPM_CONFIG;

/** Fsp M UPD Configuration
**/
typedef struct {

/** Offset 0x0000
**/
	FSP_UPD_HEADER            FspUpdHeader;

/** Offset 0x0020
**/
	FSPM_ARCH_UPD             FspmArchUpd;

/** Offset 0x0040
**/
	FSP_M_CONFIG              FspmConfig;

/** Offset 0x01F0 - FspmVersion
	FSP-M UPD Version Number
**/
	UINT16                    FspmUpdVersion;

/** Offset 0x01F2
**/
	UINT8                     UnusedUpdSpace2[12];

/** Offset 0x01FE
**/
	UINT16                    UpdTerminator;
} FSPM_UPD;

#pragma pack()

#endif
