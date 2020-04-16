/******************************************************************************
*
* Copyright (C) 2016 Hisilicon Technologies Co., Ltd.  All rights reserved.
*
******************************************************************************
File Name	    : tde_api.h
Version		    : Initial Draft
Author		    :
Created		    : 2014/06/20
Description	    :
Function List	    :
History		    :
Date			    Author		    Modification
2014/06/20				   Created file
******************************************************************************/

/* SPDX-License-Identifier: GPL-2.0 */

#ifndef _TDE_ADP_H_
#define _TDE_ADP_H_

#if defined(CONFIG_GFX_STB_SDK)
#include "hi_drv_mmz.h"
#include "hi_drv_dev.h"
#endif
#include "drv_tde_ext.h"

#define TDE_INTNUM  (91+32)
#define TDE_REG_BASEADDR 0xf8c10000

#define SIZE_256BYTE_ALIGN
#define CONFIG_TDE_BLIT_EX
#ifndef SIZE_256BYTE_ALIGN
#define CMD_SIZE 64
#define JOB_SIZE 96
#define NODE_SIZE 208
#define FILTER_SIZE 960
#else
#define CMD_SIZE 64
#define JOB_SIZE 96
#define NODE_SIZE 256
#define FILTER_SIZE 1024
#endif

#ifdef CONFIG_GFX_MMU_SUPPORT
#define HI_TDE_FILTER_NUM   16	/*Filter buf && Clut temp buf*/
#else
#define HI_TDE_FILTER_NUM   2
#endif


#define CONFIG_TDE_USE_SDK_CRG_ENABLE
#define CONFIG_TDE_TDE_EXPORT_FUNC
#define CONFIG_TDE_PM_ENABLE
#define MPP_LICENSE "GPL"
#define DESCRIPTION "Hisilicon TDE Device driver"
#define AUTHOR "Digital Media Team, Hisilicon crop."
#define TDE_VERSION "V1.0.0.0" /** revise by y00181162 in compile miniboot **/




#define TDE_NO_SCALE_STEP 0x1000
#define TDE_FLOAT_BITLEN 12
#define TDE_MAX_SLICE_WIDTH 256
#define TDE_MAX_SLICE_NUM 20
#define TDE_MAX_RECT_WIDTH 0xfff
#define TDE_MAX_RECT_HEIGHT 0xfff
#define TDE_MAX_SURFACE_PITCH 0xffff
#define TDE_MAX_ZOOM_OUT_STEP 8
#define TDE_MAX_RECT_WIDTH_EX 0x2000
#define TDE_MAX_RECT_HEIGHT_EX 0x2000


#define TDE_MAX_MINIFICATION_H	255
#define TDE_MAX_MINIFICATION_V	255



#define	  ROP	     (0x1)/*Rop*/
#define	  ALPHABLEND	 (0x1<<1) /* AlphaBlend */
#define	  COLORIZE    (0x1<<2)/* Colorize */
#define	  CLUT	 (0x1<<3) /* Clut */
#define	  COLORKEY  (0x1<<4) /* ColorKey */
#define	  CLIP	(0x1<<5) /* Clip */
#define	  DEFLICKER  (0x1<<6) /* Deflicker */
#define	  RESIZE  (0x1<<7) /* Resize */
#define	  MIRROR  (0x1<<8) /* Mirror */
#define	  CSCCOVERT  (0x1<<9) /* CSC */
#define	  QUICKCOPY  (0x1<<10)/*���ٿ���*/
#define	  QUICKFILL  (0x1<<11)/*�������*/
#define	  PATTERFILL  (0x1<<12)/*ģʽ���*/
#define	  MASKROP  (0x1<<13)/*MaskRop*/
#define	  MASKBLEND  (0x1<<14)/*MaskBlend*/

/*******************************************************************************
* Function:	 TdeHalGetCapability
* Description:	 Get the capability of TDE
* Input:	 the pointer of the capability
* Output:	 none
* Return:	 success
* Others:	 none
*******************************************************************************/
HI_S32 TdeHalGetCapability(HI_U32 *pstCapability);

#endif	/*_TDE_ADP_H_*/
