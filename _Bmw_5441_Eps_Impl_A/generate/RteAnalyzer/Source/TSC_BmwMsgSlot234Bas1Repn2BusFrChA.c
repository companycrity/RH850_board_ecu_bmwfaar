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
 *          File:  TSC_BmwMsgSlot234Bas1Repn2BusFrChA.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700369 for Nexteer Automotive Corporation
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_BmwMsgSlot234Bas1Repn2BusFrChA.h"
#include "TSC_BmwMsgSlot234Bas1Repn2BusFrChA.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */






Std_ReturnType TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_BmwEpsFctSts_Val(BmwEpsFctSts1 *data)
{
  return Rte_Read_BmwEpsFctSts_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_DrvgDynIfSt_Val(DrvgDynIfSt1 *data)
{
  return Rte_Read_DrvgDynIfSt_Val(data);
}

Std_ReturnType TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Read_HaptcFbSt_Val(HaptcFbSt1 *data)
{
  return Rte_Read_HaptcFbSt_Val(data);
}




Std_ReturnType TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST(const sigGroup_ST_EST1 *data)
{
  return Rte_Write_sigGroup_ST_EST_sigGroup_ST_EST(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Inter-Runnable variables */







     /* BmwMsgSlot234Bas1Repn2BusFrChA */
      /* BmwMsgSlot234Bas1Repn2BusFrChA */

/** Per Instance Memories */
BmwEpsFctSts1 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BmwEpsFctStsPrev(void)
{
  return Rte_Pim_BmwEpsFctStsPrev();
}
uint8 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_BurstModCntr(void)
{
  return Rte_Pim_BurstModCntr();
}
uint8 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_CycCntr(void)
{
  return Rte_Pim_CycCntr();
}
DrvgDynIfSt1 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_DrvgDynIfStPrev(void)
{
  return Rte_Pim_DrvgDynIfStPrev();
}
HaptcFbSt1 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_HaptcFbStPrev(void)
{
  return Rte_Pim_HaptcFbStPrev();
}
uint8 *TSC_BmwMsgSlot234Bas1Repn2BusFrChA_Rte_Pim_PerdCntr(void)
{
  return Rte_Pim_PerdCntr();
}



