/* Copyright 2023 Advanced Micro Devices, Inc. All rights reserved. */
// SPDX-License-Identifier: MIT
/**
 * @file
 * @brief xSIM-Host  API definitions
 *
 * @details This file is used to declare the API functions, variables and
 * macros needed by the Host to perform the early initialization
 * of the AMD silicon.
 */
/**
 * @cond API_Doc
 * @page TopXsim  Silicon Initialization Module (xSIM)
 *   'xSIM' is the AMD x86 Silicon Initialization Module.
 *   This module is responsible for the very early (basic) Si initialization
 *   comming off of reset. It places the silicon into a state where more
 *   general activities can be performed.
 *
 *   The xSIM folder contains the general infrastructure functions,
 *   the early initialization functions and is also the central translation
 *   point for 'SoC' to list of 'IP's. Actual IP programming is done by the xUSL.
 *
 *   See the 'Files - @ref xsim-api.h' section of this document for
 *   further details.
 *
 *   SocList - The platform maysupport one or more SoC's in it socket(s). This
 *   is a list of the SoC's to be supported.
 *   IpBlkList - Each SoC is comprised of several IP blocks. This is a list of
 *   the IP blocks contained within the SoC. There is one list per SoC.
 *   This list contains pointers to the IP support routines in the xUSL.
 *
 * @endcond
 */
#pragma once

#include <stddef.h>
#include <stdint.h>   // needed for declarations later in this file
#include <stdbool.h>
#include <Sil-api.h>

/** @brief Data Block Identifiers
 *
 *  @details These are unique identifiers used by the xSIM and the Host
 *  sides to locate an IPblock Input or Output data structure. See @ref SilFindStructure.
 *  Each block type must have a unique identifier, so an IP  may have several
 *  block IDs defined for the sections of memory it uses (input, output, private)
 *  and each may have multiple instances. For example, a UART port may use one
 *  ID for 'UART Port' but have several instances, one per port.
 */
typedef enum {
  SilId_SocCommon = 0,
  SilId_DfClass,
  SilId_CcxClass,
  SilId_FchClass,
  SilId_MultiFchClass,
  SilId_FchHwAcpiP,
  SilId_FchAb,
  SilId_FchSpi,
  SilId_FchHwAcpi,
  SilId_FchSata,
  SilId_FchEspi,
  SilId_FchUsb,
  SilId_MemClass,
  SilId_MultiFch,
  SilId_NorthBridgePcie,
  SilId_NbioClass,
  SilId_XmpClass,
  SilId_RcManager,
  SilId_SmuClass,
  SilId_MpioClass,
  SilId_SdciClass,
  SilId_CxlClass,
  SilId_RasClass,
                            // Add new elements above this line ^^^
  SilId_ListEnd             ///< Value to bound the list
} SIL_DATA_BLOCK_ID;


/** @brief Header structure for openSIL Input & Output Blocks
 *
 *  @details This header is included at the front of each block assigned. It is
 *  used to manage the space and locate the assigned blocks,
 *  see @ref SilFindStructure.
 */
typedef struct  {
  uint32_t Id;                ///< Information block identifier, see @ref SIL_DATA_BLOCK_ID
  uint16_t Instance;          ///< Instance # of this ID (0..N) Instance '0'
                              ///<  is reserved for the top level (class level)
                              ///<  and values 1..N are for the ports.
  uint8_t  RevMajor;          ///< Structure Major revision number. This is
                              ///<  incremented when a non-backward compatible
                              ///<  change is made.
  uint8_t  RevMinor;          ///< Structure Minor revision number. This is
                              ///<  is incremented for every change.
  uint32_t InfoBlockDataSize; ///< Information block size. This is the
                              ///<  size of block assigned, including the header,
                              ///<  rounded up to the next full DWORD.
  uint8_t  InfoBlockData[];   ///< start of the IP input block data struct.
                              ///<  Cast this point to the IP structure type to
                              ///<  reference the structure elements.
} SIL_INFO_BLOCK_HEADER;

typedef enum {
  SIL_TP1,                    ///< In TP1 openSIL assign the memory to the Each IPs
  SIL_TP2,                    ///< In TP2 Each Ips get the address of the memory
                              ///< location which was assign in the TP1
  SIL_TP3                     ///< In TP3 Each Ips get the address of the memory
                              ///< location which was assign in the TP1
} SIL_TIMEPOINT;
/*********************************************************************
 * API Function prototypes
 *********************************************************************/

/** @brief Gather Memory Requirements
 *
 *  @anchor HostSIL_Mem
 * @details This is the Host's request to xSIM for the amount of memory needed.
 * The function body will collect information from all of its
 * sub-modules as to the size they need. The aggregated total will be
 * returned to the Host caller.
 *
 * @return The return value is the minimum size, in bytes,
 * needed by all xSIM components to complete their job.
 */
size_t
xSimQueryMemoryRequirements ( void );


/**
 * xSimAssignMemoryTp1
 *
 * @brief Assign The Host Supplied Memory for timepoint 1
 *
 * @anchor HostSIL_Assign1
 * @details Host informs xSIM of the allocated memory; gets defaults.
 * The xUSL layer may record this base address for reference.
 * The function body will call sub-modules (dependent upon the Soc design)
 * to initialize IP related structures. Each sub module will assign the next
 * piece of the buffer by instantiating its input block and any needed output
 * blocks. Each instance contains the IP module identifier (a unique structure ID),
 * information about the instance and the configuration data  (structure)
 * for that block.
 *
 * Multiple instances (both input and output) can/will be assigned per the
 * SoC design. Each instance must have access information for that instance
 * (e.g. register base).
 * The sub-module is also responsible for filling the configuration data
 * section of the input block(s) with the defaults predefined at build time.
 * The output blocks must be initialized and all response values filled with 0s.
 * These will be updated when the IP module initializes the silicon.
 *
 * During TimePoint 1, openSIL is responsible for:
 *
 * 1. Initializing the global pointer to the Host allocated openSIL
 *    memory block.
 * 2. Initializing its internal APIs
 * 3. Assigning necessary memory to each IP block.
 *
 * @param   BaseAddress Starting address of the block
 *                      allocated by the Host FW.
 * @param   MemorySize  Value containing the size of the
 *                      allocated block (size in bytes).
 *
 * @return This routine provides two responses,
 *  1. {memory block}:  filled with IP sub-modules structures and default values.
 *  2. Completion status:
 *   @retval OK             function completed successfully
 *   @retval ResourceError  the block provided was insufficient for
 *                            the quantity requested by the sub-modules.
 */
SIL_STATUS
xSimAssignMemoryTp1 (
  void*         BaseAddress,
  size_t        MemorySize
  );

/**
 * xSimAssignMemoryTp2
 *
 * @brief Assign The Host Supplied Memory for timepoint 2
 *
 * @anchor HostSIL_Assign2
 * @details Host informs xSIM of the allocated memory; gets defaults.
 * The xUSL layer may record this base address for reference.
 * The function body will call sub-modules (dependent upon the Soc design)
 * to initialize IP related structures. Each sub module will assign the next
 * piece of the buffer by instantiating its input block and any needed output
 * blocks. Each instance contains the IP module identifier (a unique structure ID),
 * information about the instance and the configuration data  (structure)
 * for that block.
 *
 * Multiple instances (both input and output) can/will be assigned per the
 * SoC design. Each instance must have access information for that instance
 * (e.g. register base).
 * The sub-module is also responsible for filling the configuration data
 * section of the input block(s) with the defaults predefined at build time.
 * The output blocks must be initialized and all response values filled with 0s.
 * These will be updated when the IP module initializes the silicon.
 *
 * During TimePoint 2, openSIL is responsible for:
 *
 * 1. Initializing the global pointer to the Host allocated openSIL
 *    memory block.
 * 2. Initializing its internal APIs
 *
 * @param   BaseAddress Starting address of the block
 *                      allocated by the Host FW.
 * @param   MemorySize  Value containing the size of the
 *                      allocated block (size in bytes).
 *
 * @return This routine provides two responses,
 *  1. {memory block}:  filled with IP sub-modules structures and default values.
 *  2. Completion status:
 *   @retval OK             function completed successfully
 *   @retval ResourceError  the block provided was insufficient for
 *                            the quantity requested by the sub-modules.
 */
SIL_STATUS
xSimAssignMemoryTp2 (
  void*         BaseAddress,
  size_t        MemorySize
  );

/**
 * xSimAssignMemoryTp3
 *
 * @brief Assign The Host Supplied Memory for timepoint 3
 *
 * @anchor HostSIL_Assign3
 * @details Host informs xSIM of the allocated memory; gets defaults.
 * The xUSL layer may record this base address for reference.
 * The function body will call sub-modules (dependent upon the Soc design)
 * to initialize IP related structures. Each sub module will assign the next
 * piece of the buffer by instantiating its input block and any needed output
 * blocks. Each instance contains the IP module identifier (a unique structure ID),
 * information about the instance and the configuration data  (structure)
 * for that block.
 *
 * Multiple instances (both input and output) can/will be assigned per the
 * SoC design. Each instance must have access information for that instance
 * (e.g. register base).
 * The sub-module is also responsible for filling the configuration data
 * section of the input block(s) with the defaults predefined at build time.
 * The output blocks must be initialized and all response values filled with 0s.
 * These will be updated when the IP module initializes the silicon.
 *
 * During TimePoint 2, openSIL is responsible for:
 *
 * 1. Initializing the global pointer to the Host allocated openSIL
 *    memory block.
 * 2. Initializing its internal APIs
 *
 * @param   BaseAddress Starting address of the block
 *                      allocated by the Host FW.
 * @param   MemorySize  Value containing the size of the
 *                      allocated block (size in bytes).
 *
 * @return This routine provides two responses,
 *  1. {memory block}:  filled with IP sub-modules structures and default values.
 *  2. Completion status:
 *   @retval OK             function completed successfully
 *   @retval ResourceError  the block provided was insufficient for
 *                            the quantity requested by the sub-modules.
 */
SIL_STATUS
xSimAssignMemoryTp3 (
  void*         BaseAddress,
  size_t        MemorySize
  );

/** @brief Find a structure
 *
 *  @anchor HostSIL_Find
 * @details Locate an assigned modules data block. Once the allocated
 * memory block has been assigned to the IP blocks and filled with
 * structure data, the Host will use this function to locate a structure
 * within the memory block that was assigned by an IP block.
 *
 * The Host firmware may then inspect default settings and make any desired
 * configuration content changes.
 *
 * @param   StructureID  value obtained from an enum list in the
 *          API.H file which identifies the specific IP block to
 *          be targeted.
 * @param   InstanceNum  Always starting with 0, this value indicates which
 *          one of many possible instances of an IP block is to be located.
 *
 * @return  A pointer to the address of the data block
 *          requested. The address is within the Host allocated
 *          memory block; e.g. writable area.
 *   @retval  0x0000    indicates the requested block was not found.
 */
void*
SilFindStructure (
  SIL_DATA_BLOCK_ID  StructureID,
  uint16_t InstanceNum
  );

/**--------------------------------------------------------------------
 * SilDebugSetup
 *
 *  @anchor HostSIL_Debug
 * @brief  Record pointer to host debug service routine
 * @details The Host provides all debug output services. The openSIL code
 * uses macros to implement tracing functions and call the Host service
 * routine.
 *
 * The routine provided by the host must fit the prototype
 * defined here: @ref xUslTracePoint .
 * This is the fuction definition called by the macros.
 *
 * @param HostDbgService        Pointer to the host debug service routine
 *
 * @returns SilPass             The process completed successfully
 * @returns SilInvalidParameter The HostDbgService pointer was invalid
 **/
SIL_STATUS
SilDebugSetup (
  HOST_DEBUG_SERVICE HostDbgService
  );

/**
 * InitializeSiTp1
 *
 * @brief Initialize the Silicon at timepoint 1
 *
 * @details This is the primary Host API call to initialize all of the AMD silicon.
 * The input parameter block(s) have been allocated and assigned to IP
 * blocks. Input parameters that need dynamic adjustment have been modified; now
 * is it time to say "GO". This call starts the IP block initializations.
 * This function proceeds through each sub-module of the SoC to initialize
 * it's related silicon modules and all instances (port) thereunder.
 *
 * @return  This routine provides two responses,
 *  1. {IP output block}  each IPs output block will provide extended result information.
 *  2. Completion status  indicates the general outcome of the process:
 *   @retval    OK      The process completed successfully
 *   @retval    Error   One or more of the sub-modules reported an error in
 *              their initialization process. Please inspect the IP block
 *              output blocks for information.
 */
SIL_STATUS
InitializeSiTp1 (void);

/**
 * InitializeSiTp2
 *
 * @brief Initialize the Silicon at timepoint 2
 *
 * @details This is the primary Host API call to initialize all of the AMD silicon.
 * The input parameter block(s) have been allocated and assigned to IP
 * blocks. Input parameters that need dynamic adjustment have been modified; now
 * is it time to say "GO". This call starts the IP block initializations.
 * This function proceeds through each sub-module of the SoC to initialize
 * it's related silicon modules and all instances (port) thereunder.
 *
 * @return  This routine provides two responses,
 *  1. {IP output block}  each IPs output block will provide extended result information.
 *  2. Completion status  indicates the general outcome of the process:
 *   @retval    OK      The process completed successfully
 *   @retval    Error   One or more of the sub-modules reported an error in
 *              their initialization process. Please inspect the IP block
 *              output blocks for information.
 */
SIL_STATUS
InitializeSiTp2 (void);

/**
 * InitializeSiTp3
 *
 * @brief Initialize the Silicon at timepoint 3
 *
 * @details This is the primary Host API call to initialize all of the AMD silicon.
 * The input parameter block(s) have been allocated and assigned to IP
 * blocks. Input parameters that need dynamic adjustment have been modified; now
 * is it time to say "GO". This call starts the IP block initializations.
 * This function proceeds through each sub-module of the SoC to initialize
 * it's related silicon modules and all instances (port) thereunder.
 *
 * @return  This routine provides two responses,
 *  1. {IP output block}  each IPs output block will provide extended result information.
 *  2. Completion status  indicates the general outcome of the process:
 *   @retval    OK      The process completed successfully
 *   @retval    Error   One or more of the sub-modules reported an error in
 *              their initialization process. Please inspect the IP block
 *              output blocks for information.
 */
SIL_STATUS
InitializeSiTp3 (void);
