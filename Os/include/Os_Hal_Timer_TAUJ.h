/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \ingroup    Os_Hal
 *  \addtogroup Os_Hal_Timer_TAUJ
 *
 *  \{
 *
 *  \file       Os_Hal_Timer_TAUJ.h
 *  \brief
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#if !defined(OS_HAL_TIMER_TAUJ_H)                                                                                       /* PRQA S 0883 */ /* MD_Os_Hal_0883 */
# define OS_HAL_TIMER_TAUJ_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Os_Hal_Timer_TAUJInt.h"
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Interrupt.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_TimerPitInit_TAUJ()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Hal_3219 */
Os_Hal_TimerPitInit_TAUJ,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))                                                                                                                      /* COV_OS_HALTIMERTAUJUNSUPPORTED_XX */
{
  /* #10 Initialize timer's hardware. */
  Os_Hal_TAUJRefType TimerRef = (Os_Hal_TAUJRefType)(TimerConfig->TimerBaseAddr);                                       /* PRQA S 0303 */ /* MD_Os_Hal_0303 */
  TimerRef->osTAUJnTT = (uint8)(1UL << TimerConfig->TimerChannel);                                                      /* SBSW_OS_HAL_PWA_PITCONFIG */
  TimerRef->osTAUJnTPS &= (uint16)0xFFF0U;                                                                              /* SBSW_OS_HAL_PWA_PITCONFIG */
  TimerRef->osTAUJnCMOR[TimerConfig->TimerChannel*2] = 0;                                                               /* SBSW_OS_HAL_PWA_PITCONFIG */
  TimerRef->osTAUJnCMUR[TimerConfig->TimerChannel*4] = 0;                                                               /* SBSW_OS_HAL_PWA_PITCONFIG */
  TimerRef->osTAUJnCDR[TimerConfig->TimerChannel] = (uint32)(TimerConfig->CompareValue-1);                              /* SBSW_OS_HAL_PWA_PITCONFIG */
  TimerRef->osTAUJnTS = (uint8)(1UL << TimerConfig->TimerChannel);                                                      /* SBSW_OS_HAL_PWA_PITCONFIG */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* OS_HAL_TIMER_TAUJ_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_TAUJ.h
 **********************************************************************************************************************/
