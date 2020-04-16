/*
 * Copyright (C) 2017, Hisilicon Tech. Co., Ltd.
 * SPDX-License-Identifier: GPL-2.0
 */
#ifndef __DRV_GPIO_H__
#define __DRV_GPIO_H__

#include "hi_type.h"
#include "hi_drv_gpio.h"

HI_S32 DRV_GPIO_QueryInt (GPIO_INT_S * pGpioIntValue);
HI_S32 DRV_GPIO_Open(struct inode *inode, struct file *filp);
HI_S32 DRV_GPIO_Close(struct inode *inode, struct file *filp);
HI_S32 DRV_GPIO_SetOutputType(HI_U32 u32GpioNo, HI_UNF_GPIO_OUTPUTTYPE_E  enOutputType);
HI_S32 DRV_GPIO_GetOutputType(HI_U32 u32GpioNo, HI_UNF_GPIO_OUTPUTTYPE_E  *penOutputType);

#endif
