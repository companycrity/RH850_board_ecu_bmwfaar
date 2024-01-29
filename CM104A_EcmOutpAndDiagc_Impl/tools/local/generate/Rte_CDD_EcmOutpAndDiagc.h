/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDD_EcmOutpAndDiagc.h
 *        Config:  E:/EA4NewTemplate/CM104A_EcmOutpAndDiagc_Impl/tools/Component.dpa
 *     SW-C Type:  CDD_EcmOutpAndDiagc
 *  Generated at:  Wed Jun 14 16:33:24 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.13.0
 *                 RTE Core Version 1.13.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_EcmOutpAndDiagc> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_ECMOUTPANDDIAGC_H
# define _RTE_CDD_ECMOUTPANDDIAGC_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_EcmOutpAndDiagc_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_EcmOutpAndDiagc
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_EcmOutpAndDiagc, RTE_CONST, RTE_CONST) Rte_Inst_CDD_EcmOutpAndDiagc; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_EcmOutpAndDiagc, TYPEDEF, RTE_CONST) Rte_Instance;


# define CDD_EcmOutpAndDiagc_START_SEC_CODE
# include "CDD_EcmOutpAndDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrlErrOut_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <CtrlErrOut>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CtrlErrOut_Oper(boolean PinSt_Arg, TrigReg1 TrigReg_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_CtrlErrOut_Oper CtrlErrOut_Oper
FUNC(void, CDD_EcmOutpAndDiagc_CODE) CtrlErrOut_Oper(boolean PinSt_Arg, TrigReg1 TrigReg_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: EcmOutpAndDiagcInit2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_EcmOutpAndDiagcInit2 EcmOutpAndDiagcInit2
FUNC(void, CDD_EcmOutpAndDiagc_CODE) EcmOutpAndDiagcInit2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_EcmOutpAndDiagc_STOP_SEC_CODE
# include "CDD_EcmOutpAndDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_ECMOUTPANDDIAGC_H */

#include "Rte_Stubs.h"
