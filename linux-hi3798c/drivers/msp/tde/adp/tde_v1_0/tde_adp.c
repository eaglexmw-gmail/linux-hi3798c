/******************************************************************************
*
* Copyright (C) 2015 Hisilicon Technologies Co., Ltd.  All rights reserved.
*
******************************************************************************
File Name	    : tde_adp.c
Version		    : Initial Draft
Author		    :
Created		    : 2015/07/11
Description	    :
Function List	    :
History		    :
Date				Author			Modification
2015/07/11						Created file
******************************************************************************/

/* SPDX-License-Identifier: GPL-2.0 */

#include "tde_hal.h"
#include "tde_define.h"
#include "tde_adp.h"

static HI_U32 gs_u32Capability = ROP|ALPHABLEND|COLORIZE|CLUT|COLORKEY|CLIP|DEFLICKER|RESIZE|MIRROR|CSCCOVERT|QUICKFILL|QUICKCOPY|\
PATTERFILL;
HI_S32 TdeHalGetCapability(HI_U32 *pstCapability)
{
    *pstCapability = gs_u32Capability;
    return HI_SUCCESS;
}
