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
 *   bb_cv.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Baseband charger constant voltage source
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
#include <IniFiles.hpp>
#include <assert.h>

#pragma hdrstop

#ifndef  _BB_COMMON_H_
#include "bb_common.h"
#endif

#ifndef  _MT6223_COMMON_H_
#include "mt6223_common.h"
#endif

#ifndef  _MT6238_COMMON_H_
#include "mt6238_common.h"
#endif

#ifndef  _BB_REG_H_
#include "bb_reg.h"
#endif

#ifndef  _BB_CV_H_
#include "bb_cv.h"
#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

// misc
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

// NVRAM
#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

//===========================================================================
static CBBCV*  g_bb_cv_ptr;
static bool g_bIsRunning = false;

//===========================================================================
static void  REQ_Set_CV_Cal_Register(void)
{
    g_bb_cv_ptr->REQ_Set_CV_Cal_Register();
}

//---------------------------------------------------------------------------
static void __stdcall  CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData)
{
    g_bb_cv_ptr->CNF_ReadRegister(cnf, token, usrData);
}

//---------------------------------------------------------------------------
//static void  REQ_WriteRegister( void )
//{  g_bb_cv_ptr->REQ_WriteRegister( );
//}

//---------------------------------------------------------------------------
static void __stdcall CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData)
{
    g_bb_cv_ptr->CNF_WriteRegister( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void CNF_ReadFromNVRAM(void)
{
    g_bb_cv_ptr->CNF_ReadFromNVRAM();
}

//---------------------------------------------------------------------------
static void CNF_WriteToNVRAM(void)
{
    g_bb_cv_ptr->CNF_WriteToNVRAM();
}

//===========================================================================
CBBCV::CBBCV( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_sBBID_REG = 0;
    m_bDownloadTrigger = false;
    m_uiAddress = 0;
    m_usValue = 0;
    m_pcBuf = NULL;
    m_uiBufSize = 0;
    m_cPMU = 0;
    m_cCvStep = 0;
    m_bCnfOk = false;
    m_hEvent = NULL;

}

//---------------------------------------------------------------------------
CBBCV::~CBBCV( )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    if(m_pcBuf)
    {
        delete m_pcBuf;
        m_pcBuf = NULL;
    }
}


//---------------------------------------------------------------------------
void CBBCV::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;

    if (m_eConfirmState != META_SUCCESS)
    {
        META_Cancel_r(m_META_HANDLE_Obj.Get_MainHandle(), m_sBBID_REG);
    }
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//===========================================================================
//////////////////////////////   register    ////////////////////////////////
//===========================================================================
void CBBCV::REQ_Set_CV_Cal_Register_Start(BBCHIP_TYPE bb_chip)
{
    g_bb_cv_ptr = this;
    g_bIsRunning = true;
    m_eBbChip = bb_chip;
    ActiveMan->SetActiveFunction(::REQ_Set_CV_Cal_Register);
}

//---------------------------------------------------------------------------
void CBBCV::REQ_Set_CV_Cal_Register(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    switch (m_eBbChip)
    {
    case MT6223:
    case MT6223P:
    {
        if (!REQ_Set_MT6223_CV_Cal_Register())
        {
            Confirm(META_FAILED);
            return;
        }
    }
    break;

    case MT6235:
    case MT6238:
    {
        if (!REQ_Set_MT6235_CV_Cal_Register())
        {
            Confirm(META_FAILED);
            return;
        }
    }
    break;

    default:
    {
        assert(false);
    }
    break;
    }
    Confirm(META_SUCCESS);
}

//-------------------------------------------------------------------------
bool CBBCV::REQ_Set_MT6223_CV_Cal_Register(void)
{
    m_cCvStep = -1;

    // disable charger mode
    CPU_REG_READ_REQ write_req;
    write_req.addr = MT6223_CHARGER_CONTROL_ADDR;
    write_req.value = 0x0000;
    if (!REQ_WriteRegister(write_req))
    {
        return false;
    }

    // enable charger mode
    write_req.value = 0x0081;
    if (!REQ_WriteRegister(write_req))
    {
        return false;
    }

    unsigned char uc_check_cv_cal_reg[3];
    uc_check_cv_cal_reg[0] = 0;
    uc_check_cv_cal_reg[1] = 0;
    unsigned char uc_cv_cal_reg[32][3] =
    {
        {0, 1, 4}, // step 0
        {0, 1, 5}, //  1
        {0, 1, 6}, //  2
        {0, 1, 7}, //  3
        {0, 1, 0}, //  4
        {0, 1, 1}, //  5
        {0, 1, 2}, //  6
        {0, 1, 3}, //  7
        {0, 0, 4}, //  8
        {0, 0, 5}, //  9
        {0, 0, 6}, // 10
        {0, 0, 7}, // 11
        {0, 0, 0}, // 12
        {0, 0, 1}, // 13
        {0, 0, 2}, // 14
        {0, 0, 3}, // 15
        {1, 1, 4}, // 16
        {1, 1, 5}, // 17
        {1, 1, 6}, // 18
        {1, 1, 7}, // 19
        {1, 1, 0}, // 20
        {1, 1, 1}, // 21
        {1, 1, 2}, // 22
        {1, 1, 3}, // 23
        {1, 0, 4}, // 24
        {1, 0, 5}, // 25
        {1, 0, 6}, // 26
        {1, 0, 7}, // 27
        {1, 0, 0}, // 28
        {1, 0, 1}, // 29
        {1, 0, 2}, // 30
        {1, 0, 3}  // 31
    };

    // char c_reg_value[3];
    for (int i=0; i<CV_CAL_STEP_NUM; i++)
    {
        bool b_match = false;
        uc_check_cv_cal_reg[0] = uc_cv_cal_reg[i][0];
        uc_check_cv_cal_reg[1] = uc_cv_cal_reg[i][1];
        for (int chk_idx = i+1; chk_idx < CV_CAL_STEP_NUM; chk_idx++)
        {
            if ((uc_check_cv_cal_reg[0] == uc_cv_cal_reg[chk_idx][0]) &&
                    (uc_check_cv_cal_reg[1] == uc_cv_cal_reg[chk_idx][1]) &&
                    (uc_check_cv_cal_reg[2] == uc_cv_cal_reg[chk_idx][2])
               )
            {
                b_match = true;
                break;
            }
        }

        if (!b_match)
        {
            S_BB_REG_BIT_SET_T set_req;
            set_req.ui_addr  = MT6223_START_UP_ADDR;
            // CKSEL
            set_req.uc_value[0]     = uc_cv_cal_reg[i][0];
            set_req.uc_bit_num[0]   = MT6223_CKSEL_BIT_NUM;
            set_req.uc_start_bit[0] = MT6223_CKSEL_START_BIT;
            // RESET_DRV
            set_req.uc_value[1]     = uc_cv_cal_reg[i][1];
            set_req.uc_bit_num[1]   = MT6223_RESET_DRV_BIT_NUM;
            set_req.uc_start_bit[1] = MT6223_RESET_DRV_START_BIT;
            if (!REQ_SetRegisterBit(set_req))
            {
                return false;
            }

            set_req.ui_addr  = MT6223_CHARGER_CONTROL_ADDR;
            // CHR_AUX
            set_req.uc_value[0]     = uc_cv_cal_reg[i][2];
            set_req.uc_bit_num[0]   = MT6223_CHR_AUX_BIT_NUM;
            set_req.uc_start_bit[0] = MT6223_CHR_AUX_START_BIT;
            // CHR_EN
            set_req.uc_value[1]     = 1;
            set_req.uc_bit_num[1]   = MT6223_CHR_EN_BIT_NUM;
            set_req.uc_start_bit[1] = MT6223_CHR_EN_START_BIT;
            if (!REQ_SetRegisterBit(set_req))
            {
                return false;
            }
        }
        else
        {
            S_BB_REG_BIT_SET_T set_req;
            set_req.ui_addr  = MT6223_CHARGER_CONTROL_ADDR;
            // CHR_AUX
            set_req.uc_value[0]     = uc_cv_cal_reg[i][2];
            set_req.uc_bit_num[0]   = MT6223_CHR_AUX_BIT_NUM;
            set_req.uc_start_bit[0] = MT6223_CHR_AUX_START_BIT;
            // CHR_EN
            set_req.uc_value[1]     = 1;
            set_req.uc_bit_num[1]   = MT6223_CHR_EN_BIT_NUM;
            set_req.uc_start_bit[1] = MT6223_CHR_EN_START_BIT;
            if (!REQ_SetRegisterBit(set_req))
            {
                return false;
            }

            set_req.ui_addr  = MT6223_START_UP_ADDR;
            // CKSEL
            set_req.uc_value[0]     = uc_cv_cal_reg[i][0];
            set_req.uc_bit_num[0]   = MT6223_CKSEL_BIT_NUM;
            set_req.uc_start_bit[0] = MT6223_CKSEL_START_BIT;
            // RESET_DRV
            set_req.uc_value[1]     = uc_cv_cal_reg[i][1];
            set_req.uc_bit_num[1]   = MT6223_RESET_DRV_BIT_NUM;
            set_req.uc_start_bit[1] = MT6223_RESET_DRV_START_BIT;
            if (!REQ_SetRegisterBit(set_req))
            {
                return false;
            }
        }
        uc_check_cv_cal_reg[2] = uc_cv_cal_reg[i][2];

        // get CV flag
        S_BB_REG_BIT_GET_T get_req;
        get_req.ui_addr = MT6223_CHARGER_STATUS_ADDR;
        get_req.uc_bit  = MT6223_CV_START_BIT;
        unsigned char uc_cv_flag;
        if (!REQ_GetRegisterBit(get_req, uc_cv_flag))
        {
            return false;
        }

        if (1 == uc_cv_flag)
        {
            m_cPMU = (uc_cv_cal_reg[i][0] << 4) |
                     (uc_cv_cal_reg[i][1] << 3) |
                     uc_cv_cal_reg[i][2];
            m_cCvStep = i;
            break;
        }
    }

    return true;
}

//-------------------------------------------------------------------------
bool CBBCV::REQ_Set_MT6235_CV_Cal_Register(void)
{
    m_cCvStep = -1;

    // disable charger mode
    CPU_REG_WRITE_REQ write_req;
    write_req.addr = MT6223_CHARGER_CONTROL_ADDR;
    write_req.value = 0x0000;
    if (!REQ_WriteRegister(write_req))
    {
        return false;
    }

    // enable charger mode
    write_req.value = 0x0081;
    if (!REQ_WriteRegister(write_req))
    {
        return false;
    }

    unsigned char uc_check_cv_cal_reg[3];
    uc_check_cv_cal_reg[0] = 0;
    uc_check_cv_cal_reg[1] = 0;
    unsigned char uc_cv_cal_reg[32][3] =
    {
        {0, 1, 4}, // step 0
        {0, 1, 5}, //  1
        {0, 1, 6}, //  2
        {0, 1, 7}, //  3
        {0, 1, 0}, //  4
        {0, 1, 1}, //  5
        {0, 1, 2}, //  6
        {0, 1, 3}, //  7
        {0, 0, 4}, //  8
        {0, 0, 5}, //  9
        {0, 0, 6}, // 10
        {0, 0, 7}, // 11
        {0, 0, 0}, // 12
        {0, 0, 1}, // 13
        {0, 0, 2}, // 14
        {0, 0, 3}, // 15
        {1, 1, 4}, // 16
        {1, 1, 5}, // 17
        {1, 1, 6}, // 18
        {1, 1, 7}, // 19
        {1, 1, 0}, // 20
        {1, 1, 1}, // 21
        {1, 1, 2}, // 22
        {1, 1, 3}, // 23
        {1, 0, 4}, // 24
        {1, 0, 5}, // 25
        {1, 0, 6}, // 26
        {1, 0, 7}, // 27
        {1, 0, 0}, // 28
        {1, 0, 1}, // 29
        {1, 0, 2}, // 30
        {1, 0, 3}  // 31
    };

    // char c_reg_value[3];
    for (int i=0; i<CV_CAL_STEP_NUM; i++)
    {
        bool b_match = false;
        uc_check_cv_cal_reg[0] = uc_cv_cal_reg[i][0];
        uc_check_cv_cal_reg[1] = uc_cv_cal_reg[i][1];
        for (int chk_idx = i+1; chk_idx < CV_CAL_STEP_NUM; chk_idx++)
        {
            if ((uc_check_cv_cal_reg[0] == uc_cv_cal_reg[chk_idx][0]) &&
                    (uc_check_cv_cal_reg[1] == uc_cv_cal_reg[chk_idx][1]) &&
                    (uc_check_cv_cal_reg[2] == uc_cv_cal_reg[chk_idx][2])
               )
            {
                b_match = true;
                break;
            }
        }

        if (!b_match)
        {
            S_BB_REG_BIT_SET_T set_req;
            set_req.ui_addr  = MT6223_START_UP_ADDR;
            // CKSEL
            set_req.uc_value[0]     = uc_cv_cal_reg[i][0];
            set_req.uc_bit_num[0]   = MT6223_CKSEL_BIT_NUM;
            set_req.uc_start_bit[0] = MT6223_CKSEL_START_BIT;
            // RESET_DRV
            set_req.uc_value[1]     = uc_cv_cal_reg[i][1];
            set_req.uc_bit_num[1]   = MT6223_RESET_DRV_BIT_NUM;
            set_req.uc_start_bit[1] = MT6223_RESET_DRV_START_BIT;
            if (!REQ_SetRegisterBit(set_req))
            {
                return false;
            }

            set_req.ui_addr  = MT6223_CHARGER_CONTROL_ADDR;
            // CHR_AUX
            set_req.uc_value[0]     = uc_cv_cal_reg[i][2];
            set_req.uc_bit_num[0]   = MT6223_CHR_AUX_BIT_NUM;
            set_req.uc_start_bit[0] = MT6223_CHR_AUX_START_BIT;
            // CHR_EN
            set_req.uc_value[1]     = 1;
            set_req.uc_bit_num[1]   = MT6223_CHR_EN_BIT_NUM;
            set_req.uc_start_bit[1] = MT6223_CHR_EN_START_BIT;
            if (!REQ_SetRegisterBit(set_req))
            {
                return false;
            }
        }
        else
        {
            S_BB_REG_BIT_SET_T set_req;
            set_req.ui_addr  = MT6223_CHARGER_CONTROL_ADDR;
            // CHR_AUX
            set_req.uc_value[0]     = uc_cv_cal_reg[i][2];
            set_req.uc_bit_num[0]   = MT6223_CHR_AUX_BIT_NUM;
            set_req.uc_start_bit[0] = MT6223_CHR_AUX_START_BIT;
            // CHR_EN
            set_req.uc_value[1]     = 1;
            set_req.uc_bit_num[1]   = MT6223_CHR_EN_BIT_NUM;
            set_req.uc_start_bit[1] = MT6223_CHR_EN_START_BIT;
            if (!REQ_SetRegisterBit(set_req))
            {
                return false;
            }

            set_req.ui_addr  = MT6223_START_UP_ADDR;
            // CKSEL
            set_req.uc_value[0]     = uc_cv_cal_reg[i][0];
            set_req.uc_bit_num[0]   = MT6223_CKSEL_BIT_NUM;
            set_req.uc_start_bit[0] = MT6223_CKSEL_START_BIT;
            // RESET_DRV
            set_req.uc_value[1]     = uc_cv_cal_reg[i][1];
            set_req.uc_bit_num[1]   = MT6223_RESET_DRV_BIT_NUM;
            set_req.uc_start_bit[1] = MT6223_RESET_DRV_START_BIT;
            if (!REQ_SetRegisterBit(set_req))
            {
                return false;
            }
        }
        uc_check_cv_cal_reg[2] = uc_cv_cal_reg[i][2];

        // get CV flag
        S_BB_REG_BIT_GET_T get_req;
        get_req.ui_addr = MT6223_CHARGER_STATUS_ADDR;
        get_req.uc_bit  = MT6223_CV_START_BIT;
        unsigned char uc_cv_flag;
        if (!REQ_GetRegisterBit(get_req, uc_cv_flag))
        {
            return false;
        }

        if (1 == uc_cv_flag)
        {
            m_cPMU = (uc_cv_cal_reg[i][0] << 4) |
                     (uc_cv_cal_reg[i][1] << 3) |
                     uc_cv_cal_reg[i][2];
            m_cCvStep = i;
            break;
        }
    }

    return true;
}

//===========================================================================
bool CBBCV::REQ_GetRegisterBit(S_BB_REG_BIT_GET_T get_req, unsigned char& uc_value)
{
    unsigned short us_value;
    CPU_REG_READ_REQ read_req;
    read_req.addr = get_req.ui_addr;
    if (!REQ_ReadRegister(read_req, us_value))
    {
        return false;
    }

    uc_value = ((us_value & (1 << get_req.uc_bit)) >> get_req.uc_bit) & 0x01;
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CBBCV::REQ_SetRegisterBit(S_BB_REG_BIT_SET_T set_req)
{
    unsigned short us_value;
    CPU_REG_READ_REQ read_req;
    read_req.addr = set_req.ui_addr;
    if (!REQ_ReadRegister(read_req, us_value))
    {
        return false;
    }

    for (int i = 0; i < 2; i++)
    {
        if (set_req.uc_bit_num[i] > 0)
        {
            for (int bit_idx = 0; bit_idx < set_req.uc_bit_num[i]; bit_idx++)
            {
                if (set_req.uc_value[i] & (0x01 << bit_idx))
                {
                    us_value |= (1 << (set_req.uc_start_bit[i] + bit_idx));
                }
                else
                {
                    us_value  &= ~(1 << (set_req.uc_start_bit[i] + bit_idx));
                }
            }
        }
    }

    CPU_REG_WRITE_REQ write_req;
    write_req.addr = set_req.ui_addr;
    write_req.value = us_value;
    if (!REQ_WriteRegister(write_req))
    {
        return false;
    }
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CBBCV::REQ_ReadRegister(CPU_REG_READ_REQ req, unsigned short& us_value)
{
    DWORD wait_result;
    m_hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    ResetEvent(m_hEvent);
    META_RESULT MetaResult = META_SUCCESS;//META_BB_RegRead_r(m_META_HANDLE_Obj.Get_MainHandle(), &req, ::CNF_ReadRegister, &m_sBBID_REG, NULL);
    wait_result = WaitForSingleObject(m_hEvent, 5000);
    if (WAIT_TIMEOUT == wait_result)
    {
        return false;
    }

    if ((MetaResult != META_SUCCESS) || (!m_bCnfOk))
    {
        return false;
    }
    us_value = m_usValue;
    return true;
}

//-------------------------------------
void __stdcall CBBCV::CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData)
{
    if (cnf->status != BB_STATUS_SUCCESS)
    {
        m_bCnfOk = false;
        return;
    }
    m_bCnfOk = true;
    m_usValue = cnf->value;
    SetEvent(m_hEvent);

}

//===========================================================================
bool CBBCV::REQ_WriteRegister(CPU_REG_WRITE_REQ req)
{
    DWORD wait_result;
    m_hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    ResetEvent( m_hEvent );
    META_RESULT MetaResult = META_SUCCESS;//META_BB_RegWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), &req, ::CNF_WriteRegister, &m_sBBID_REG, NULL);
    wait_result = WaitForSingleObject(m_hEvent, 5000);
    if (WAIT_TIMEOUT == wait_result)
    {
        return false;
    }

    if ((MetaResult != META_SUCCESS) || (!m_bCnfOk))
    {
        return false;
    }
    return true;
}

//-------------------------------------
void __stdcall CBBCV::CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData)
{
    if (cnf->status != BB_STATUS_SUCCESS)
    {
        m_bCnfOk = false;
        return;
    }
    m_bCnfOk = true;
    SetEvent(m_hEvent);
}

//===========================================================================
//////////////////////////////   NVRAM    ///////////////////////////////////
//===========================================================================
void CBBCV::REQ_Read_From_NVRAM_Start(void)
{
    g_bb_cv_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = false;
    REQ_Read_From_NVRAM();
}

//---------------------------------------------------------------------------
void CBBCV::REQ_Read_From_NVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult;
    if (NULL == m_pcBuf)
    {
        MetaResult = WM_META_NVRAM_GetRecLen("NVRAM_EF_SYS_CACHE_OCTET_LID",
                                             (int *) &m_uiBufSize);

        if (MetaResult != META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_pcBuf = new char[m_uiBufSize];
    }

    NVRAMMan->ConfirmCallback = ::CNF_ReadFromNVRAM;
    NVRAMMan->REQ_ReadNVRAM_Start("NVRAM_EF_SYS_CACHE_OCTET_LID",
                                  NVRAM_SYS_CV_CALIBRATION_RID,
                                  m_uiBufSize,
                                  m_pcBuf);
}

//-------------------------------------
void CBBCV::CNF_ReadFromNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();

    if (META_SUCCESS == state)
    {
        if (m_bDownloadTrigger)
        {
            REQ_Write_To_NVRAM();
        }
        else
        {
            META_RESULT MetaResult = WM_META_NVRAM_GetRecFieldValue("NVRAM_EF_SYS_CACHE_OCTET_LID",
                                     "CacheByte[0]",
                                     m_pcBuf,
                                     m_uiBufSize,
                                     &m_cPMU,
                                     sizeof(m_cPMU));
            if (MetaResult != META_SUCCESS)
            {
                Confirm(META_FAILED);
                return;
            }

            Confirm(META_SUCCESS);
        }
    }
    else
    {
        Confirm(state);
    }
}

//===========================================================================
void CBBCV::REQ_Write_To_NVRAM_Start(void)
{
    g_bb_cv_ptr = this;
    g_bIsRunning = true;
    m_bDownloadTrigger = true;
    REQ_Read_From_NVRAM();
}

//---------------------------------------------------------------------------
void CBBCV::REQ_Write_To_NVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult;

    if (NULL == m_pcBuf)
    {
        MetaResult = WM_META_NVRAM_GetRecLen("NVRAM_EF_SYS_CACHE_OCTET_LID", (int *) &m_uiBufSize);

        if (MetaResult!=META_SUCCESS)
        {
            Confirm(META_FAILED);
            return;
        }
        m_pcBuf = new char[m_uiBufSize];
    }

    MetaResult = WM_META_NVRAM_SetRecFieldValue("NVRAM_EF_SYS_CACHE_OCTET_LID",
                 "CacheByte[0]",
                 m_pcBuf,
                 m_uiBufSize,
                 &m_cPMU,
                 sizeof(m_cPMU)
                                               );
    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }

    NVRAMMan->ConfirmCallback = ::CNF_WriteToNVRAM;
    NVRAMMan->REQ_WriteNVRAM_Start("NVRAM_EF_SYS_CACHE_OCTET_LID",
                                   NVRAM_SYS_CV_CALIBRATION_RID,
                                   m_uiBufSize,
                                   m_pcBuf);
}

//-------------------------------------
void CBBCV::CNF_WriteToNVRAM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    Confirm(state);

}

//===========================================================================
//////////////////////////////// INI ////////////////////////////////////////
//===========================================================================
static const AnsiString as_SECTION_NAME = "CV calibration";
static const AnsiString as_KEY_NAME = "PMU";

//----------------------------------------------------------------------------
bool CBBCV::CvSectionExist(char *filename)
{
    TIniFile *ini_file = new TIniFile(filename);
    if(!ini_file)
    {
        return false;
    }

    if (!ini_file->SectionExists(as_SECTION_NAME))
    {
        delete ini_file;
        return false;
    }
    delete ini_file;
    return true;
}

//-----------------------------------------------------------------------------
bool CBBCV::REQ_Read_From_File(char *filename)
{
    TIniFile *ini_file = new TIniFile(filename);
    if (!ini_file)
    {
        return  false;
    }

    m_cPMU = ini_file->ReadInteger(as_SECTION_NAME, as_KEY_NAME, 0);

    delete ini_file;
    return true;
}

//===========================================================================
bool CBBCV::REQ_Write_To_File(char *filename)
{
    TIniFile *ini_file = new TIniFile(filename);
    if (NULL == ini_file)
    {
        return  false;
    }

    ini_file->WriteString(as_SECTION_NAME, as_KEY_NAME, IntToStr(m_cPMU));
    delete ini_file;
    return true;
}

//===========================================================================
////////////////////////////  Global information  ///////////////////////////
//===========================================================================
META_RESULT CBBCV::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char CBBCV::Get_PMU(void)
{
    return m_cPMU;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char CBBCV::Get_CvStep(void)
{
    return m_cCvStep;
}
