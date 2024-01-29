/**
*  \file
*
*  \brief       Read and write ECU data.
*
*  This file contains functions to read and write ECU related data.
*
*  \project     BMW Platform Software
*
*  \copyright   BMW AG 2015 - 2017
*
*  \version     5.3.1
*
*/

#ifndef DLOG_ECU_H
#define DLOG_ECU_H


/*------------------------------------------------------------------------------
                      Include Section
-------------------------------------------------------------------------------*/

#include <Std_Types.h>                      /* AUTOSAR Standard Types         */
#include "DlogClassic_Cfg.h"
#include "Dlog_Data.h"                      /* for DLOG_FINGERPRINTLENGTH            */
#if ( DLOG_ENABLE_RTE == STD_ON )
#include <Rte_Dlog_Type.h>
#else
#include "Dcm_Types.h"                      /* AUTOSAR DCM Types              */
#endif


/*------------------------------------------------------------------------------
                      MISRA-Deviations
------------------------------------------------------------------------------*/

/* Violation of MISRA rule 19.1, Reason: Including Dlog_MemMap.h is necessary throughout
   the file according to memory abstraction, see PRQA: 5087 */


/*------------------------------------------------------------------------------
                      Macros
-------------------------------------------------------------------------------*/

/* check version of the module */
#if (!DlogClassic_CHECK_VERSION(5,3,1))
   #error "Version of Dlog_Ecu.h does not match the version of the module!"
#endif

#define DLOG_VINLENGTH           17u    /**< Length of the VIN number         */


/*------------------------------------------------------------------------------
                      Data Types
-------------------------------------------------------------------------------*/

/** The following enum type contains the 'testerKennungType' types            */
typedef enum
{
   DLOG_TESTERTYPFREEREPAIRSHOP    = 0x9u,
   DLOG_TESTERTYPSERVICEBMWHO      = 0xAu,
   DLOG_TESTERTYPSYSTEMSUPPLIER    = 0xBu,
   DLOG_TESTERTYPCARFACTORY        = 0xDu,
   DLOG_TESTERTYPSPAREPARTFACTORY  = 0xEu,
   DLOG_TESTERTYPDEVELOPMENT       = 0xFu
} Dlog_TesterKennungType;

/** This type is used to store Bootloading dependent data non-volatile */
typedef struct
{
   uint8     FingerPrint [DLOG_FINGERPRINTLENGTH];  /**< FingerPrint            */
   uint8     VIN         [DLOG_VINLENGTH];          /**< Vehicle Identification */
} Dlog_ProgDataType;


/*------------------------------------------------------------------------------
                      Global Variables
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

extern VAR(Dlog_ProgDataType, Dlog_VAR_NOINIT) Dlog_ProgData;

#define Dlog_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "Dlog_MemMap.h"  /* PRQA S 5087 */


/*------------------------------------------------------------------------------
                      Global Function Declarations
-------------------------------------------------------------------------------*/

#define Dlog_START_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

/* Function declarations are generated by the RTE if the RTE is enabled */
#if ( DLOG_ENABLE_RTE != STD_ON )

extern Std_ReturnType Dlog_InitProgData( void );

extern Std_ReturnType Dlog_ReadDataByIdentifierManufacturingDate(uint8* Data);
extern Std_ReturnType Dlog_ReadDataByIdentifierEcuSerialNumber(uint8* Data);
extern Std_ReturnType Dlog_ReadDataByIdentifierEcuUid(uint8* Data);
extern Std_ReturnType Dlog_ReadDataByIdentifierHWModificationIndex(uint8* Data);

extern Std_ReturnType Dlog_ConditionCheckVin(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType* ErrorCode);

extern Std_ReturnType Dlog_ReadDataByIdentifierVin(Dcm_OpStatusType OpStatus, uint8* Data);

extern Std_ReturnType Dlog_GetVin(uint8* Vin);

#endif /* #if ( DLOG_ENABLE_RTE != STD_ON ) */

/* Function declarations are generated by the RTE if the RTE is enabled */
#if ( DLOG_ENABLE_RTE != STD_ON )

#if (DLOG_ENABLE_ECU_WRITE_VIN == STD_ON)

extern Std_ReturnType Dlog_WriteDataByIdentifierVin(
    const uint8* Data,
    Dcm_OpStatusType OpStatus,
    Dcm_NegativeResponseCodeType* ErrorCode
);

#endif /* #if (DLOG_ENABLE_ECU_WRITE_VIN == STD_ON) */
#endif /* #if ( DLOG_ENABLE_RTE != STD_ON ) */

#if ( DLOG_ENABLE_RTE != STD_ON )
extern Std_ReturnType Dlog_GetEcuId(uint8* ecuId);
#endif /* #if ( DLOG_ENABLE_RTE != STD_ON ) */

#define Dlog_STOP_SEC_CODE
#include "Dlog_MemMap.h"  /* PRQA S 5087 */

#endif  /* DLOG_ECU_H                                                          */
