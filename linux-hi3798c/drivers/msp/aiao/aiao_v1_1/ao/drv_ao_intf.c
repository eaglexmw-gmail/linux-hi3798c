/*
 * Copyright (C) 2017, Hisilicon Tech. Co., Ltd.
 * SPDX-License-Identifier: GPL-2.0
 */
#include "hi_drv_ao.h"
#include "drv_ao_ioctl.h"
#include "drv_ao_ext.h"
#include "drv_ao_private.h"

#include "hi_drv_proc.h"

static struct file_operations s_stDevFileOpts =
{
    .owner = THIS_MODULE,
    .unlocked_ioctl   = AO_DRV_Ioctl,
    .open	      = AO_DRV_Open,
    .release	      = AO_DRV_Release,
#ifdef CONFIG_COMPAT
    .compat_ioctl     = AO_DRV_Ioctl,
#endif
};

static PM_BASEOPS_S s_stDrvOps = {
    .probe	  = NULL,
    .remove	  = NULL,
    .shutdown	  = NULL,
    .prepare	  = NULL,
    .complete	  = NULL,
    .suspend	  = AO_DRV_Suspend,
    .suspend_late = NULL,
    .resume_early = NULL,
    .resume	  = AO_DRV_Resume,
};

/* the attribute struct of ao device */
static UMAP_DEVICE_S s_stAoUmapDev;

static __inline__ HI_S32 AO_DRV_RegisterDev(HI_VOID)
{
    /*register ao device*/
    snprintf(s_stAoUmapDev.devfs_name, sizeof(s_stAoUmapDev.devfs_name), UMAP_DEVNAME_AO);
    s_stAoUmapDev.fops	 = &s_stDevFileOpts;
    s_stAoUmapDev.minor	 = UMAP_MIN_MINOR_AO;
    s_stAoUmapDev.owner	 = THIS_MODULE;
    s_stAoUmapDev.drvops = &s_stDrvOps;
    if (HI_DRV_DEV_Register(&s_stAoUmapDev) < 0)
    {
	HI_FATAL_AO("AO register device failed\n");
	return HI_FAILURE;
    }

    return HI_SUCCESS;
}

static __inline__ HI_VOID AO_DRV_UnregisterDev(HI_VOID)
{
    /*unregister ao device*/
    HI_DRV_DEV_UnRegister(&s_stAoUmapDev);
}

HI_S32 AO_DRV_ModInit(HI_VOID)
{
    HI_S32 s32Ret = HI_SUCCESS;

    s32Ret = AO_DRV_Init();
    if (HI_SUCCESS != s32Ret)
    {
	HI_FATAL_AO("Init ao drv fail!\n");
	return s32Ret;
    }

    s32Ret = AO_DRV_RegisterProc();
    if (HI_SUCCESS != s32Ret)
    {
	HI_FATAL_AO("Reg proc fail!\n");
	AO_DRV_Exit();

	return s32Ret;
    }

    s32Ret = AO_DRV_RegisterDev();
    if (HI_SUCCESS != s32Ret)
    {
	AO_DRV_UnregisterProc();
	AO_DRV_Exit();
	HI_FATAL_AO("Reg dev fail!\n");
	return s32Ret;
    }

    return s32Ret;
}

HI_VOID AO_DRV_ModExit(HI_VOID)
{
    AO_DRV_UnregisterDev();

    AO_DRV_UnregisterProc();

    AO_DRV_Exit();
}

MODULE_AUTHOR("HISILICON");
MODULE_LICENSE("GPL");
