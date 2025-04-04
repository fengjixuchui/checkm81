/**
 * @file  ApobLib.c
 * @brief OpenSIL APOB functions
 *
 */

/* Copyright 2021-2023 Advanced Micro Devices, Inc. All rights reserved.    */
// SPDX-License-Identifier: MIT


#include <SilCommon.h>
#include <ApobCmn.h>
#include <string.h>

APOBLIB_INFO gApobLibInfo = {false, 0, 0};
uint32_t ApobGetMaxChannelsPerDie(uint32_t ApobInstanceId, uint8_t *MaxChannelsPerDie)
{
  return 0;
}

uint32_t
ApobGetEccEnable(uint32_t ApobInstanceId, uint32_t ChannelIndex, bool *EccEnable)
{
  return 0;
}

/**
 * ApobInit
 * @brief Get APOB address, and save to the global variable
 *
 * @details  Passing the APOB base address as a parameter is optional.
 *           ApobBaseAddress will not set the address beyond this Time Point.
 *           If the APOB address has been initialized in this time point then
 *           this argument will not be used.
 *
 * @param[in]  ApobBaseAddress  location of the APOB optional
 *
 * @return     SIL_STATUS       The APOB save to gApobLibInfo successfully
 *
 **/
static SIL_STATUS
ApobInit (
  uintptr_t  ApobBaseAddress
  )
{

  APOB_BASE_HEADER *ApobHeaderPtr;

  APOB_TRACEPOINT (SIL_TRACE_ENTRY, "ApobInit\n");

  if (gApobLibInfo.Supported == false) {
    //
    // Check if the caller provided the APOB Address
    //
    ApobHeaderPtr = (ApobBaseAddress != 0) ? (APOB_BASE_HEADER *)(size_t)ApobBaseAddress :
                                      (APOB_BASE_HEADER *)(size_t)APOB_BASE_ADDRESS;
    //APOB Info data haven't been initialized
    APOB_TRACEPOINT (SIL_TRACE_INFO, "Init APOB HOB Info struct\n");
    APOB_TRACEPOINT (SIL_TRACE_INFO, "APOB header Addr 0x%x\n", ApobHeaderPtr);
    APOB_TRACEPOINT (SIL_TRACE_INFO, "APOB header size 0x%x\n", ApobHeaderPtr->Size);

    //Signature verification failed
    if (ApobHeaderPtr->Signature != APOB_SIGNATURE) {
      APOB_TRACEPOINT (SIL_TRACE_INFO, "APOB SIG Check fail, APOB is not supported\n");
      return SilUnsupported;
    }

    // Check APOB Size
    if ((ApobHeaderPtr->Size == 0) ||
        (ApobHeaderPtr->Size == 0xFFFFFFFFul)) {
      APOB_TRACEPOINT (SIL_TRACE_INFO, "APOB Size Check fail\n");
      return SilOutOfResources;
    }

    gApobLibInfo.Supported = true;
    gApobLibInfo.ApobAddr = (uintptr_t)ApobHeaderPtr;
    gApobLibInfo.ApobSize = ApobHeaderPtr->Size;
  }

  return SilPass;
}

/**
 * AmdGetApobInfo
 * @brief Get APOBLib Info Data based on APOB base address
 *
 * @param  ApobInfo             Input buffer to fill the APOB Info
 *
 * @retval SilPass              The APOB info retrieved successfully
 * @retval SilInvalidParameter  Paramter input is invalid
 * @retval SilOutOfResources    ApobInit returned out of resources
 *
 **/
static SIL_STATUS AmdGetApobInfo (APOBLIB_INFO *ApobInfo)
{
  assert (ApobInfo != NULL);
  if (ApobInfo == NULL) {
    return SilUnsupported;
  }

  if (gApobLibInfo.Supported == false) {
    if (ApobInit ((uintptr_t)ApobInfo->ApobAddr) != SilPass)
      return SilOutOfResources;
  }

  ApobInfo->Supported = gApobLibInfo.Supported;
  ApobInfo->ApobAddr  = gApobLibInfo.ApobAddr;
  ApobInfo->ApobSize  = gApobLibInfo.ApobSize;

  return SilPass;
}

/**
 * AmdGetApobEntry
 * @brief Return Array of Entry instance as specified GroupId, DataTypeId
 *
 * @details  Passing the APOB base address as a parameter is optional.
 *           ApobBaseAddress will not set the address beyond this Time Point.
 *           If the APOB address has been initialized in this time point then
 *           this argument will not be used.
 *
 *  @param[in]  GroupID          GroupId of Apob entry
 *  @param[in]  DataTypeID       DataTypeID of Apob entry
 *  @param[out] NumofEntry       Number of entry found of specific GroupId, DataTypeId
 *  @param[in]  ApobBaseAddress  location of the APOB optional
 *  @param[out] ApobEntries      Point to the arrary which used to hold the ApobEntries
 *                               The array need be allocated outside of the routine
 *
 *  @retval       SilPass           Function succeed
 *  @retval       NON-ZERO          Error occurs
*/
static SIL_STATUS
AmdGetApobEntry (
  uint32_t          GroupID,
  uint32_t          DataTypeID,
  uint32_t          *NumofEntry,
  uint32_t          ApobBaseAddress,
  APOB_TYPE_HEADER  **ApobEntries
  )
{
  uint8_t           *ApobEntryBin;
  APOB_TYPE_HEADER  *ApobEntry;
  uint32_t          LclNumofEntry;
  APOB_BASE_HEADER  *ApobHeaderPtr;
  APOBLIB_INFO      ApobInfoPtr;
  SIL_STATUS        Status;

  *NumofEntry = 0;
  *ApobEntries = NULL;
  ApobEntryBin = NULL;
  APOB_TRACEPOINT (SIL_TRACE_INFO, "AmdGetApobEntry %x %x\n", GroupID, DataTypeID);

  ApobInfoPtr.ApobAddr = 0;
  //
  // If the APOB ADDRESS provided by the caller is not 0
  // then use then pass it to the next step
  //
  if (ApobBaseAddress != 0) {
    ApobInfoPtr.ApobAddr =  (uint64_t)ApobBaseAddress;
  }
  Status = AmdGetApobInfo (&ApobInfoPtr);
  if (Status != SilPass) {
    APOB_TRACEPOINT (SIL_TRACE_ERROR, "APOBLIB Info data uninitialized.\n");
    return Status;
  }

  if (ApobInfoPtr.Supported == false) {
    APOB_TRACEPOINT (SIL_TRACE_ERROR, "Error detected in the APOB DATA\n");
    return SilUnsupported;
  }

  ApobHeaderPtr = (APOB_BASE_HEADER *) (size_t) ApobInfoPtr.ApobAddr;
  APOB_TRACEPOINT (SIL_TRACE_INFO, "ApobInfo Supported %x ApobAddr %x ApobSize %x\n",
        ApobInfoPtr.Supported, ApobInfoPtr.ApobAddr, ApobInfoPtr.ApobSize);

  APOB_TRACEPOINT (SIL_TRACE_INFO, "AmdGetApobEntry %x %x\n", GroupID, DataTypeID);
  APOB_TRACEPOINT (SIL_TRACE_INFO, "APOB Addr %x\n", ApobHeaderPtr);

  if (ApobHeaderPtr->Version >= 5) {
    ApobEntryBin = (uint8_t *) ApobHeaderPtr;
    ApobEntryBin += ApobHeaderPtr->OffsetOfFirstEntry;
  } else {
    APOB_TRACEPOINT (SIL_TRACE_ERROR, "APOB version is not supported\n");
    return SilUnsupported;
  }

  ApobEntry = (APOB_TYPE_HEADER *) ApobEntryBin;
  LclNumofEntry = 0;

  while (ApobEntryBin  < ((uint8_t *) ApobHeaderPtr + ApobHeaderPtr->Size)) {
    if ((ApobEntry->GroupID == GroupID) &&
        (ApobEntry->DataTypeID == DataTypeID)) {
      //Found a matched entry
      LclNumofEntry++;
      *ApobEntries = ApobEntry;
      ApobEntries++;
      APOB_TRACEPOINT (SIL_TRACE_INFO, "Type found @0x%x\n", ApobEntry);
    }
    ApobEntryBin += (ApobEntry->TypeSize);
    ApobEntry = (APOB_TYPE_HEADER *) ApobEntryBin;
  }

  *NumofEntry = LclNumofEntry;
  APOB_TRACEPOINT (SIL_TRACE_INFO, "Total  %d entries found\n", LclNumofEntry);

  if (LclNumofEntry == 0) {
    APOB_TRACEPOINT (SIL_TRACE_INFO, "ApobEntry NOT found.\n");
    return SilNotFound;
  }

  return SilPass;
}

/**
 * AmdGetApobEntryInstance
 * @brief   Return Entry instance as specified GroupId, DataTypeId, InstanceId
 *
 * @details  Passing the APOB base address as a parameter is optional.
 *           ApobBaseAddress will not set the address beyond this Time Point.
 *           If the APOB address has been initialized in this time point then
 *           this argument will not be used.
 *
 * @param[in]  GroupID          GroupId of Apob entry
 * @param[in]  DataTypeID       DataTypeID of Apob entry
 * @param[in]  InstanceID       InstanceID of Apob entry
 * @param[in]  ApobBaseAddress  Location the the APOB optional
 * @param[out] ApobEntry        Point to the array which used to hold the ApobEntries
 *                              The array need be allocated outside of the routine
 *
 * @retval       SilPass        Function succeed
 * @retval       NON-ZERO       Error occurs
 */
SIL_STATUS
AmdGetApobEntryInstance (
  uint32_t          GroupID,
  uint32_t          DataTypeID,
  uint32_t          InstanceID,
  uint32_t          ApobBaseAddress,
  APOB_TYPE_HEADER  **ApobEntry
  )
{
  uint32_t          Index;
  uint32_t          NumofInstance;
  APOB_TYPE_HEADER  *LclApobEntries[APOB_ENTRY_INSTANCE_MAX];
  uint32_t          LclNumofEntry;
  APOB_TYPE_HEADER  *LclApobEntry;

  *ApobEntry = NULL;
  LclApobEntry = NULL;
  APOB_TRACEPOINT (SIL_TRACE_ENTRY, "\n");
  APOB_TRACEPOINT (SIL_TRACE_INFO,
    "AmdGetApobEntryInstance 0x%x 0x%x 0x%x\n",
    GroupID,
    DataTypeID,
    InstanceID);

  LclNumofEntry = 0;
  AmdGetApobEntry (GroupID, DataTypeID, &LclNumofEntry, ApobBaseAddress, &LclApobEntries[0]);
  if (LclNumofEntry == 0) {
    APOB_TRACEPOINT (SIL_TRACE_INFO, "No entry found\n");
    return SilNotFound;
  }

  //Scan the Arrary to get the specific instance
  NumofInstance = 0;
  for (Index = 0; Index < LclNumofEntry; Index++) {
    if (LclApobEntries[Index]->InstanceID == InstanceID) {
      NumofInstance++;
      LclApobEntry = LclApobEntries[Index];
    }
  }

  //Instance ID can't be duplicated
  if (NumofInstance == 0) {
    return SilNotFound;
  } else if (NumofInstance == 1) {
    APOB_TRACEPOINT (SIL_TRACE_INFO, "Instance found @0x%x\n", LclApobEntry);
    *ApobEntry = LclApobEntry;
    return SilPass;
  } else {
    return SilUnsupported;
  }
}

/**
 * ApobGetPhysCcdNumber
 * @brief Get the physical CCD number by reading APOB APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE
 *
 *  @param[in] ApobInstanceId
 *  @param[in] CcxIndex used access ComplexMap
 *  @param[in, out] PhysComplexNumber
 *
 *  @retval       SilPass           Function succeed
 *  @retval       NON-ZERO          Error occurs
*/
SIL_STATUS
ApobGetPhysCcdNumber (
  uint32_t ApobInstanceId,
  uint32_t CcdIndex,
  uint8_t *PhysCcdNumber
)
{
  SIL_STATUS Status;

  APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT *ApobEntry = NULL;

  Status = AmdGetApobEntryInstance (APOB_CCX,
      APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE,
      ApobInstanceId,
      0,
      (APOB_TYPE_HEADER **) &ApobEntry);

  if (Status == SilPass) {
    *PhysCcdNumber = ApobEntry->CcdMap[CcdIndex].PhysCcdNumber;
  }
  return Status;
}

/**
 * ApobGetPhysComplexNumber
 * @brief Get the physical complex number by reading APOB APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE
 *
 *  @param[in] ApobInstanceId
 *  @param[in] CcxIndex used to access ComplexMap
 *  @param[in, out] PhysComplexNumber
 *
 *  @retval       SilPass           Function succeed
 *  @retval       NON-ZERO          Error occurs
*/
SIL_STATUS
ApobGetPhysComplexNumber (
  uint32_t ApobInstanceId,
  uint32_t CcdIndex,
  uint32_t CcxIndex,
  uint8_t *PhysComplexNumber
)
{
  SIL_STATUS Status;

  APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT *ApobEntry = NULL;

  Status = AmdGetApobEntryInstance (APOB_CCX,
    APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE,
    ApobInstanceId,
    0,
    (APOB_TYPE_HEADER **) &ApobEntry);

  if (Status == SilPass) {
    *PhysComplexNumber = ApobEntry->CcdMap[CcdIndex].ComplexMap[CcxIndex].PhysComplexNumber;
  }
  return Status;
}

/**
 * ApobGetPhysCoreNumber
 * @brief Get the physical core number by reading
 *        APOB APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE
 *
 *  @param[in] ApobInstanceId
 *  @param[in] CcxIndex             Index to access ComplexMap
 *  @param[in] CoreIndex            Index to access CoreInfo
 *  @param[in, out] PhysCoreNumber
 *
 *  @retval       SilPass           Function succeed
 *  @retval       NON-ZERO          Error occurs
*/
SIL_STATUS
ApobGetPhysCoreNumber (
  uint32_t ApobInstanceId,
  uint32_t CcdIndex,
  uint32_t CcxIndex,
  uint32_t CoreIndex,
  uint8_t *PhysCoreNumber
)
{
  SIL_STATUS Status;
  APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT *ApobEntry = NULL;

  Status = AmdGetApobEntryInstance (APOB_CCX,
    APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE,
    ApobInstanceId,
    0,
    (APOB_TYPE_HEADER **) &ApobEntry);

  if (Status == SilPass) {
    *PhysCoreNumber = ApobEntry->CcdMap[CcdIndex].ComplexMap[CcxIndex].CoreInfo[CoreIndex].PhysCoreNumber;
  }

  return Status;
}

/**
 * ApobGetIsThreadEnabled
 * @brief Check if the thread is enable by reading
 *        APOB APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE
 *
 *  @param[in] ApobInstanceId
 *  @param[in] CcxIndex             Index to access ComplexMap
 *  @param[in] CoreIndex            Index to access CoreInfo
 *  @param[in] ThreadIndex          Index to access IsThreadEnabled
 *  @param[in, out] IsThreadEnabled
 *
 *  @retval       SilPass           Function succeed
 *  @retval       NON-ZERO          Error occurs
*/
SIL_STATUS
ApobGetIsThreadEnabled (
  uint32_t ApobInstanceId,
  uint32_t CcdIndex,
  uint32_t CcxIndex,
  uint32_t CoreIndex,
  uint32_t ThreadIndex,
  bool *IsThreadEnabled
  )
{
  SIL_STATUS Status;
  APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT *ApobEntry = NULL;

  Status = AmdGetApobEntryInstance (APOB_CCX,
    APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE,
    ApobInstanceId,
    0,
    (APOB_TYPE_HEADER **) &ApobEntry);

  if (Status == SilPass) {
    *IsThreadEnabled =
      ApobEntry->CcdMap[CcdIndex].ComplexMap[CcxIndex].CoreInfo[CoreIndex].IsThreadEnabled[ThreadIndex];
  }
  return Status;
}

/**
 * ApobGetCcdLogToPhysMap
 *
 * @brief This retrieves the CCD logical to physical from the APOB.
 *
 * @param  Socket               Zero-based socket number to check.
 * @param  Die                  The target die's identifier within Socket.
 * @param  ApobCcdLogToPhysMap  Pointer to return the CCD Logical to physical
 *                              map.
 *
 * @retval SilPass    The CCD log to phys map was retrieved successfully.
 * @retval NON-ZERO   Error occurs
 *
 **/
SIL_STATUS
ApobGetCcdLogToPhysMap (
  uint32_t                                      Socket,
  uint32_t                                      Die,
  APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT  *ApobCcdLogToPhysMap
  )
{
  uint32_t          ApobInstanceId;
  APOB_TYPE_HEADER  *ApobEntry = NULL;
  SIL_STATUS        Status;

  APOB_TRACEPOINT (SIL_TRACE_ENTRY, "\n");
  ApobInstanceId = ((uint32_t) Socket << 8) | (uint32_t) Die;
  Status = AmdGetApobEntryInstance (APOB_CCX,
    APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE,
    ApobInstanceId,
    0,
    &ApobEntry);

  if (Status != SilPass) {
    APOB_TRACEPOINT (
      SIL_TRACE_ERROR,
      "Failed to retrieve Apob Instance (InstanceId = 0x%x)\n",
      ApobInstanceId
      );
    return Status;
  }

  memcpy (ApobCcdLogToPhysMap,
    ApobEntry,
    sizeof (APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT));

  APOB_TRACEPOINT (SIL_TRACE_EXIT, "\n");
  return Status;
}

/**
 * ApobGetCoreTopologyOnDie
 * @brief This retrieves information about the layout of the cores on the given die.
 *
 * @param[in]  Socket                         Zero-based socket number to check.
 * @param[in]  Die                            The target die's identifier within Socket.
 * @param[in]  NumberOfCcds                   Pointer to number of core complex die.
 * @param[out] NumberOfComplexes              Pointer to the number of enabled complexes on
 *                                            the given socket / die.
 * @param[out] NumberOfCores                  Pointer to the number of enabled cores per
 *                                            complex on the given socket / die.
 * @param[out] NumberOfThreads                Pointer to the number of enabled threads per
 *                                            core on the given socket / die.
 *
 * @retval SilPass                          The core topology information was successfully retrieved.
 * @retval SilInvalidParameter              Socket is non-existent.
 * @retval SilInvalidParameter              Die is non-existent.
 * @retval SilInvalidParameter              All output parameter pointers are NULL.
 *
 **/
SIL_STATUS
ApobGetCoreTopologyOnDie (
  uint32_t Socket,
  uint32_t Die,
  uint32_t *NumberOfCcds,
  uint32_t *NumberOfComplexes,
  uint32_t *NumberOfCores,
  uint32_t *NumberOfThreads
  )
{
  APOB_CCD_LOGICAL_TO_PHYSICAL_MAP_TYPE_STRUCT  ApobCcdLogToPhysMap;
  uint32_t                                      Index;
  SIL_STATUS                                    SilStatus;

  APOB_TRACEPOINT (SIL_TRACE_ENTRY, "\n");
  SilStatus = ApobGetCcdLogToPhysMap (Socket, Die, &ApobCcdLogToPhysMap);

  if (SilStatus != SilPass) {
    APOB_TRACEPOINT (SIL_TRACE_ERROR,
      "Failed to get Ccd Logical to Physical Map\n"
      );
    return SilStatus;
  }

  *NumberOfCcds = 0;
  *NumberOfComplexes = 0;
  *NumberOfCores = 0;
  *NumberOfThreads = 0;

  for (Index = 0;Index < MAX_CCDS_PER_DIE; Index++) {
    if (ApobCcdLogToPhysMap.CcdMap[Index].PhysCcdNumber != CCX_NOT_PRESENT) {
      (*NumberOfCcds)++;
    } else {
      break;
    }
  }

  for (Index = 0;Index < MAX_COMPLEXES_PER_CCD; Index++) {
    if (ApobCcdLogToPhysMap.CcdMap[0].ComplexMap[Index].PhysComplexNumber != CCX_NOT_PRESENT) {
      (*NumberOfComplexes)++;
    } else {
      break;
    }
  }

  for (Index = 0;Index < MAX_CORES_PER_COMPLEX; Index++) {
    if (ApobCcdLogToPhysMap.CcdMap[0].ComplexMap[0].CoreInfo[Index].PhysCoreNumber != CCX_NOT_PRESENT) {
      (*NumberOfCores)++;
    } else {
      break;
    }
  }

  for (Index = 0;Index < MAX_THREADS_PER_CORE; Index++) {
    if (ApobCcdLogToPhysMap.CcdMap[0].ComplexMap[0].CoreInfo[0].IsThreadEnabled[Index] == true) {
      (*NumberOfThreads)++;
    } else {
      break;
    }
  }

  APOB_TRACEPOINT (SIL_TRACE_EXIT, "\n");
  return SilPass;
}

SIL_STATUS
ApobGetSubProgram (uint32_t *SubProgram)
{
  SIL_STATUS Status;
  APOB_GEN_INFO_TYPE_STRUCT *ApobEntry = NULL;
  Status = AmdGetApobEntryInstance (APOB_GEN,
    APOB_GEN_CONFIGURATION_INFO_TYPE,
    0,
    0,
    (APOB_TYPE_HEADER **) &ApobEntry);

  if (Status == SilPass) {
    *SubProgram = ApobEntry->ApobParamInfo.SubProgram;
  }

  return Status;
}

/**
 * ApobGetActionOnBistFailure
 * @brief This retrieves information about memory bist failure for apob type APOB_APCB_BOOT_INFO_TYPE
 *
 * @param[out] ActionOnBistFailure         Bist Failure Action
 *
 *
 * @return SIL_STATUS                      Bist Failue information status.
 *
 **/
SIL_STATUS ApobGetActionOnBistFailure (uint8_t *ActionOnBistFailure)
{
  SIL_STATUS Status;
  APOB_APCB_BOOT_INFO_STRUCT *ApobEntry = NULL;

  Status = AmdGetApobEntryInstance (APOB_MEM,
    APOB_APCB_BOOT_INFO_TYPE,
    0,
    0,
    (APOB_TYPE_HEADER **) &ApobEntry);

  if (Status != SilPass)
    return Status;

  APOB_TRACEPOINT (SIL_TRACE_INFO,
    "APCB_TOKEN_UID_ACTION_ON_BIST_FAILURE = 0x%x\n",
    ApobEntry->ActionOnBistFailure);

  *ActionOnBistFailure = ApobEntry->ActionOnBistFailure;
  return Status;
}

/**
 * @brief Get specific SPD data by reading APOB APOB_MEM_DIMM_SPD_DATA_TYPE
 *
 * @param ApobInstanceId
 * @param Socket
 * @param Channel
 * @param Dimm
 * @param BufSize
 * @param SpdBufPtr Point to buffer to hold SPD data
 *
 * @retval       SilPass           Function succeed
 * @retval       NON-ZERO          Error occurs
 */
SIL_STATUS
ApobGetDimmSpdData (
  uint32_t ApobInstanceId,
  uint8_t  Socket,
  uint8_t  Channel,
  uint8_t  Dimm,
  uint32_t BufSize,
  uint8_t  *SpdBufPtr
  )
{
  uint8_t           Index;
  uint32_t          IndexCount;
  uint32_t          TypeSize;
  SIL_STATUS        Status;
  APOB_TYPE_HEADER  *ApobTypeHeader;
  APOB_MEM_DIMM_D5_SPD_DATA_STRUCT *ApobEntry = NULL;

  Status = AmdGetApobEntryInstance (APOB_MEM,
                                    APOB_MEM_DIMM_SPD_DATA_TYPE,
                                    ApobInstanceId,
                                    0,
                                    (APOB_TYPE_HEADER **) &ApobEntry
                                    );
  ApobTypeHeader = (APOB_TYPE_HEADER *)ApobEntry;
  if (Status == SilPass) {
    TypeSize = ApobTypeHeader->TypeSize;
    IndexCount    = (TypeSize - offsetof(APOB_MEM_DIMM_D5_SPD_DATA_STRUCT, DimmSmbusInfo))
                    / sizeof (APOB_D5_SPD_STRUCT);
    Status = SilNotFound;
    for (Index = 0; Index < IndexCount; Index ++) {
      if (ApobEntry->DimmSmbusInfo[Index].SocketNumber == Socket &&
          ApobEntry->DimmSmbusInfo[Index].ChannelNumber == Channel &&
          ApobEntry->DimmSmbusInfo[Index].DimmNumber == Dimm &&
          ApobEntry->DimmSmbusInfo[Index].DimmPresent) {
        memcpy (SpdBufPtr, ApobEntry->DimmSmbusInfo[Index].Data, (BufSize > 1024) ? 1024 : BufSize);
        Status = SilPass;
      }
    }
  }
  return Status;
}
