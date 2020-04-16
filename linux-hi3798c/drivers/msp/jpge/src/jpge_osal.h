/******************************************************************************
*
* Copyright (C) 2016 Hisilicon Technologies Co., Ltd.  All rights reserved.
*
******************************************************************************
File Name	   : jpge_osal.h
Version		   : Initial Draft
Author		   :
Created		   : 2016/03/03
Description	   :
Function List	   :


History		   :
Date		      Author		    Modification
2016/03/03	      y00181162		     Created file
******************************************************************************/

/* SPDX-License-Identifier: GPL-2.0 */

#ifndef	 __JPGE_OSAL_H__
#define	 __JPGE_OSAL_H__


/*********************************add include here******************************/
#include "hi_type.h"
#include <linux/spinlock.h>

#include <linux/semaphore.h>

/***************************** Macro Definition ******************************/

#define JPGE_REG_BASE_ADDR 0xF8C90000
#define JPGE_IRQ_ID	   (102+32)

typedef unsigned long  JPGE_LOCK_FLAG;

/********************** Global Variable declaration **************************/

typedef spinlock_t	    JPGE_LOCK_S;
typedef struct semaphore    JPGE_SEM_S;


/******************************* API declaration *****************************/
HI_S32	   JpgeOsal_IrqFree	      ( HI_U32	Irq );
HI_S32	   JpgeOsal_IrqInit	      ( HI_U32	Irq, HI_VOID (*ptrCallBack)(HI_VOID) );

HI_S32	   JpgeOsal_LockInit	      ( JPGE_LOCK_S *pLock );
HI_VOID	   JpgeOsal_Lock	      ( JPGE_LOCK_S *pLock, JPGE_LOCK_FLAG *pFlag );
HI_VOID	   JpgeOsal_Unlock	      ( JPGE_LOCK_S *pLock, JPGE_LOCK_FLAG *pFlag );

HI_S32	   JpgeOsal_MutexInit	      ( JPGE_SEM_S *pMutex );
HI_S32	   JpgeOsal_MutexLock	      ( JPGE_SEM_S *pMutex );
HI_S32	   JpgeOsal_MutexUnlock	      ( JPGE_SEM_S *pMutex );

HI_VOID*   JpgeOsal_MapRegisterAddr   ( HI_U32	phyAddr, HI_U32 len );
HI_VOID	   JpgeOsal_UnmapRegisterAddr ( HI_VOID *pVir );

#endif /*__JPGE_OSAL_H__ */
