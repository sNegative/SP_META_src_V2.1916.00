/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bb_cv.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Baseband charger constant voltage header
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef  _BB_CV_H_
#define  _BB_CV_H_

// common
#ifndef META_DLL_H
#include "wmmeta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

// bb
#ifndef	_MTK_MCU_H_
#include "mtk_mcu.h"
#endif
/*---------------------------------------------------------------------------*/
#define NVRAM_SYS_CV_CALIBRATION_RID 7
#define CV_CAL_STEP_NUM 32

/*---------------------------------------------------------------------------*/
typedef struct
{
    unsigned int ui_addr;
    unsigned char uc_bit;
} S_BB_REG_BIT_GET_T;

typedef struct
{
    unsigned int ui_addr;
    unsigned char uc_value[2];
    unsigned char uc_bit_num[2];
    unsigned char uc_start_bit[2];
} S_BB_REG_BIT_SET_T;

/*---------------------------------------------------------------------------*/
class  CBBCV
{
private:
    BBCHIP_TYPE m_eBbChip;
    META_RESULT  m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    short m_sBBID_REG;//token
    bool m_bDownloadTrigger;
    unsigned int  m_uiAddress;
    unsigned short m_usValue;
    char *m_pcBuf;
    unsigned int m_uiBufSize;
    char m_cPMU;
    char m_cCvStep;
    bool m_bCnfOk;
    HANDLE  m_hEvent;

protected:

    void  Confirm(META_RESULT confirm_state);

public:

    CBBCV(void);
    ~CBBCV();
    // register
    void  REQ_Set_CV_Cal_Register(void);
    bool  REQ_GetRegisterBit(S_BB_REG_BIT_GET_T get_req, unsigned char& uc_value);
    bool  REQ_SetRegisterBit(S_BB_REG_BIT_SET_T set_req);
    bool  REQ_ReadRegister(CPU_REG_READ_REQ req, unsigned short& us_value);
    bool  REQ_WriteRegister(CPU_REG_WRITE_REQ req);
    bool  REQ_Set_MT6223_CV_Cal_Register(void);
    bool  REQ_Set_MT6235_CV_Cal_Register(void);

    // NVRAM
    void  REQ_Read_From_NVRAM(void);
    void  REQ_Write_To_NVRAM(void);
    void  CNF_ReadFromNVRAM(void);
    void  CNF_WriteToNVRAM(void);

    // callback
    void __stdcall CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData);
    void __stdcall CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData);


    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    // Public member


    void  (*ConfirmCallback)(void);





    // Public interface
    void  REQ_Set_CV_Cal_Register_Start(BBCHIP_TYPE bb_chip);
    void  REQ_Read_From_NVRAM_Start(void);
    void  REQ_Write_To_NVRAM_Start(void);
    bool  CvSectionExist(char *filename);
    bool  REQ_Read_From_File(char *filename);
    bool  REQ_Write_To_File(char *filename);


    // Export information
    META_RESULT Get_ConfirmState(void);
    char Get_PMU(void);
    char Get_CvStep(void);
};

/*---------------------------------------------------------------------------*/
#endif
