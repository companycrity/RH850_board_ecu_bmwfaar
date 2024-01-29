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
 *          File:  TSC_McalErrHndlg.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nexteer Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_McalErrHndlg.h"
#include "TSC_McalErrHndlg.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_McalErrHndlg_Rte_Call_MCalReadVrfyFailFltInfo_Oper(uint8 PrphlId_Arg, uint16 ErrId_Arg)
{
  return Rte_Call_MCalReadVrfyFailFltInfo_Oper(PrphlId_Arg, ErrId_Arg);
}
Std_ReturnType TSC_McalErrHndlg_Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
{
  return Rte_Call_SetNtcSts_Oper(NtcNr_Arg, NtcStInfo_Arg, NtcSts_Arg, DebStep_Arg);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* McalErrHndlg */
      /* McalErrHndlg */

/** Per Instance Memories */
uint8 *TSC_McalErrHndlg_Rte_Pim_CritErrCod(void)
{
  return Rte_Pim_CritErrCod();
}
uint8 *TSC_McalErrHndlg_Rte_Pim_NonCritErrCod(void)
{
  return Rte_Pim_NonCritErrCod();
}



