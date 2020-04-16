/******************************************************************************
*
* Copyright (C) 2015 Hisilicon Technologies Co., Ltd.  All rights reserved.
*
*****************************************************************************


  File Name	: pq_hal_gfxbt2020.h
  Version	: Initial Draft
  Author	: d00241380
  Created	: 2016/03/22
  Description	:

******************************************************************************/

/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __PQ_HAL_GFXBT2020_H__
#define __PQ_HAL_GFXBT2020_H__


#include "pq_hal_gfxcsc.h"

#define GDM_GMM_LUT_SIZE      64

HI_S32	PQ_HAL_GfxBT2020MemInit(HI_VOID);
HI_VOID PQ_HAL_GfxGamLutInit(HI_VOID);
HI_S32	PQ_HAL_GfxBT2020DeInit(HI_VOID);
HI_VOID PQ_HAL_SetGfxBt2020Mode(PQ_HAL_GFX_CSC_MODE_S* pstPqCscMode);
HI_VOID PQ_HAL_SetGfxRgbtYuvMode(PQ_HAL_GFX_CSC_MODE_S* pstPqCscMode);

#endif
