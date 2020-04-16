/*
 * Copyright (C) 2017, Hisilicon Tech. Co., Ltd.
 * SPDX-License-Identifier: GPL-2.0
 */
#ifndef __DRV_GPIOI2C_H_
#define __DRV_GPIOI2C_H_

#include "hi_type.h"

HI_S32 DRV_GPIOI2C_Config(HI_U32 I2cNum, HI_U32 whichGpioClock, HI_U32 whichGpioData, HI_U32 clockBit, HI_U32 dataBit);
HI_S32 DRV_GPIOI2C_IsUsed(HI_U32 I2cNum, HI_BOOL *bUsed);

#endif
