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
 *   fm_radio.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   FM radio source
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
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Jul 15 2007 mtk00490
 * [STP100001471] [META] META ver 5.5.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _FM_RADIO_H_
#include "fm_radio.h"
#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif


//===========================================================================
static CFMRADIO* g_fm_radio_ptr;
static bool g_bIsRunning = false;

//===========================================================================

//------------------------------------------------------------------------------
//static void REQ_TimeOut(void)
//{
//    g_fm_radio_ptr->REQ_TimeOut();
//}

//------------------------------------------------------------------------------
//static void REQ_Finish(void)
//{
//    g_fm_radio_ptr->REQ_Finish();
//}

//---------------------------------------------------------------------------
static void REQ_FM_Power_On(void)
{
    g_fm_radio_ptr->REQ_FM_Power_On();
}

//---------------------------------------------------------------------------
static void REQ_FM_Power_Off(void)
{
    g_fm_radio_ptr->REQ_FM_Power_Off();
}

//---------------------------------------------------------------------------
static void REQ_Set_Freq(void)
{
    g_fm_radio_ptr->REQ_Set_Freq();
}

//---------------------------------------------------------------------------
static void REQ_Get_FM_Status(void)
{
    g_fm_radio_ptr->REQ_Get_FM_Status();
}

//---------------------------------------------------------------------------
static void REQ_SearchFreq(void)
{
    g_fm_radio_ptr->REQ_SearchFreq();
}

//---------------------------------------------------------------------------
static void REQ_SetAudio(void)
{
    g_fm_radio_ptr->REQ_SetAudio();
}

//----------------------------------------------------------------------------
static void __stdcall CNF_AudioSetVolume(const AUDIO_RESULT status, const short token, void *usrData)
{
    g_fm_radio_ptr->CNF_AudioSetVolume(status, token, usrData);
}

//---------------------------------------------------------------------------
static void REQ_ReadData(void)
{
    g_fm_radio_ptr->REQ_ReadData();
}

//---------------------------------------------------------------------------
static void REQ_WriteData(void)
{
    g_fm_radio_ptr->REQ_WriteData();
}

//---------------------------------------------------------------------------
static void REQ_FM_AutoScan(void)
{
    g_fm_radio_ptr->REQ_FM_AutoScan();
}
static void REQ_FM_Set_DecodeMode(void)
{
    g_fm_radio_ptr->REQ_FM_Set_DecodeMode();
}
static void REQ_FM_Set_DeemphasisLevel(void)
{
    g_fm_radio_ptr->REQ_FM_Set_DeemphasisLevel();
}
static void REQ_FM_Set_StereoBlend(void)
{
    g_fm_radio_ptr->REQ_FM_Set_StereoBlend();
}
static void REQ_FM_Set_HLSide(void)
{
    g_fm_radio_ptr->REQ_FM_Set_HLSide();
}
static void REQ_FM_Set_HCC(void)
{
    g_fm_radio_ptr->REQ_FM_Set_HCC();
}
static void REQ_FM_Set_DemodBandwidth(void)
{
    g_fm_radio_ptr->REQ_FM_Set_DemodBandwidth();
}
static void REQ_FM_Set_PAMDThreshold(void)
{
    g_fm_radio_ptr->REQ_FM_Set_PAMDThreshold();
}
static void REQ_FM_Set_DynamicLimiter(void)
{
    g_fm_radio_ptr->REQ_FM_Set_DynamicLimiter();
}
static void REQ_FM_Set_RSSIThreshold(void)
{
    g_fm_radio_ptr->REQ_FM_Set_RSSIThreshold();
}
static void REQ_FM_Set_SoftmuteRate(void)
{
    g_fm_radio_ptr->REQ_FM_Set_SoftmuteRate();
}
static void REQ_FM_Set_SoftmuteEnable(void)
{
    g_fm_radio_ptr->REQ_FM_Set_SoftmuteEnable();
}

static void REQ_FM_Get_RSSI(void)
{
    g_fm_radio_ptr->REQ_FM_Get_RSSI();
}

static void REQ_FM_Get_RXFilterBW(void)
{
    g_fm_radio_ptr->REQ_FM_Get_RXFilterBW();
}

static void REQ_FM_Get_PAMDLevel(void)
{
    g_fm_radio_ptr->REQ_FM_Get_PAMDLevel();
}

static void REQ_FM_Get_MR(void)
{
    g_fm_radio_ptr->REQ_FM_Get_MR();
}

static void REQ_FM_Get_Stereo(void)
{
    g_fm_radio_ptr->REQ_FM_Get_Stereo();
}

static void REQ_FM_Get_IFCounter(void)
{
    g_fm_radio_ptr->REQ_FM_Get_IFCounter();
}

static void REQ_FM_Get_HLSide(void)
{
    g_fm_radio_ptr->REQ_FM_Get_HLSide();
}

static void REQ_FM_HWSeek(void)
{
    g_fm_radio_ptr->REQ_FM_HWSeek();
}

static void REQ_FM_Set_Volume(void)
{
    g_fm_radio_ptr->REQ_FM_Set_Volume();
}

static void REQ_FM_Set_Softmute(void)
{
    g_fm_radio_ptr->REQ_FM_Set_Softmute();
}
static void REQ_FM_Set_MonoOrStereoBlend(void)
{
    g_fm_radio_ptr->REQ_FM_Set_MonoOrStereoBlend();
}
static void REQ_FM_Set_StereoBlendStage(void)
{
    g_fm_radio_ptr->REQ_FM_Set_StereoBlendStage();
}
static void REQ_FM_GET_STATUS(void)
{
    g_fm_radio_ptr->REQ_FM_GET_STATUS();
}

static void REQ_FM_SET_PARAMETER(void)
{
    g_fm_radio_ptr->REQ_FM_SET_PARAMETER();
}

static void REQ_FM_Audio_Test(void)
{
    g_fm_radio_ptr->REQ_FM_Audio_Test();
}

//===========================================================================
CFMRADIO::CFMRADIO(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    m_bFMSupport = false;
    m_sSETVOLUME = 0;
    m_hEvent = NULL;
    m_ucAddr= 0;
    m_usData = 0;
}

//---------------------------------------------------------------------------
CFMRADIO::~CFMRADIO()
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}

//---------------------------------------------------------------------------
//void CFMRADIO::REQ_Finish(void)
//{
//    if (!g_bIsRunning)
//    {
//        return;
//    }
//
//    Confirm(META_SUCCESS);
//}

//---------------------------------------------------------------------------
//void CFMRADIO::REQ_TimeOut(void)
//{
//    if (!g_bIsRunning)
//    {
//        return;
//    }
//
//    META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
//    Confirm(META_TIMEOUT);
//}

//---------------------------------------------------------------------------
void CFMRADIO::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (confirm_state != METAAPP_SECTION_OK)
    {
        g_bIsRunning = false;
    }

    if (confirm_state != META_SUCCESS)
    {
        SP_META_Cancel_r(m_META_HANDLE_Obj.Get_MainHandle(), m_sSETVOLUME);
        SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    }

    if (NULL == ConfirmCallback)
    {
        return;
    }

    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//===========================================================================
void CFMRADIO::REQ_FM_Power_On_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_FM_Power_On);
}

//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Power_On(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult = SP_META_FM_PowerOn_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CFMRADIO::REQ_FM_Power_Off_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_FM_Power_Off);
}

//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Power_Off(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    /*
    META_RESULT MetaResult = META_FM_PowerOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 10);
    Confirm(META_SUCCESS);
    */
    META_RESULT MetaResult = SP_META_FM_PowerOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}

//===========================================================================
void CFMRADIO::REQ_Set_Freq_Start(FM_FREQ_REQ_T freq)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    m_sFMFreq = freq;
    ActiveMan->SetActiveFunction(::REQ_Set_Freq);
}

//---------------------------------------------------------------------------
void CFMRADIO::REQ_Set_Freq(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult = SP_META_FM_SetFreq_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sFMFreq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}

//===========================================================================
void CFMRADIO::REQ_SearchFreq_Start(S_FM_SEARCH_STATION_T search_station)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    m_sSearchStation = search_station;
    ActiveMan->SetActiveFunction(::REQ_SearchFreq);
}

//---------------------------------------------------------------------------
void CFMRADIO::REQ_SearchFreq(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult;

    // set RSSI threshold
    MetaResult = SP_META_FM_SetRssiThreold_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sSearchStation.s_rssi_thrsh);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    // set IF counter delta
    MetaResult = SP_META_FM_SetIfCntDelta_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sSearchStation.s_if_cnt_delta);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    // search station
    if (m_sSearchStation.s_freq_range.m_i2StartFreq < m_sSearchStation.s_freq_range.m_i2StopFreq)
    {
        MetaResult = SP_META_FM_SearchNextFreq_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sSearchStation.s_freq_range, &m_sValidFreq);
    }
    else
    {
        MetaResult = SP_META_FM_SearchPrevFreq_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sSearchStation.s_freq_range, &m_sValidFreq);
    }

    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    if ((!m_sValidFreq.m_ucExit) || (m_sValidFreq.m_i2ValidFreq <= 0))
    {
        Confirm(META_FAILED);
        return;
    }

    FM_FREQ_REQ_T freq_req;
    freq_req.m_i2CurFreq = m_sValidFreq.m_i2ValidFreq;
    MetaResult = SP_META_FM_SetFreq_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &freq_req);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    Confirm(META_SUCCESS);
}

//===========================================================================
void CFMRADIO::REQ_Get_FM_Status_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_Get_FM_Status);
}

//---------------------------------------------------------------------------
void CFMRADIO::REQ_Get_FM_Status(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    // RSSI
    META_RESULT MetaResult = SP_META_FM_GetRSSI_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sFMFreq, &(m_sStatus.s_rssi));
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    // IF counter
    MetaResult = SP_META_FM_GetIfCnt_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sFMFreq, &(m_sStatus.s_if_cnt));
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    // H/L state
    MetaResult = SP_META_FM_GetHighOrLowSide_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sFMFreq, &(m_sStatus.s_hl_side));
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    // stereo/mono
    MetaResult = SP_META_FM_GetStereoOrMono_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &(m_sStatus.s_stero_mono));
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    Confirm(META_SUCCESS);
}



//===========================================================================
void CFMRADIO::REQ_SetAudio_Start(S_FM_AUDIO_T audio)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    m_sAudio = audio;
    ActiveMan->SetActiveFunction(::REQ_SetAudio);
}

//---------------------------------------------------------------------------
void CFMRADIO::REQ_SetAudio(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    // set volume
    // META_RESULT MetaResult = META_Audio_Set_Volume_r(m_META_HANDLE_Obj.Get_MainHandle(), &m_sAudio.s_vol, ::CNF_AudioSetVolume, &m_sSETVOLUME, NULL);
    // if (MetaResult != META_SUCCESS)
    // {
    //     if (META_TIMEOUT == MetaResult)
    //     {
    //         Confirm(META_TIMEOUT);
    //     }
    //     else
    //     {
    //         Confirm(META_FAILED);
    //     }
    //     return;
    // }
    // DWORD wait_result;
    // m_hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    // ResetEvent(m_hEvent);
    // wait_result = WaitForSingleObject(m_hEvent, 5000);
    // if (WAIT_TIMEOUT == wait_result)
    // {
    //     Confirm(META_TIMEOUT);
    //     return;
    // }

    // set mono or stereo blend
    m_sAudio.s_mono_stereo_blend.m_u4ItemValue = FM_ENABLE;
    META_RESULT MetaResult = SP_META_FM_SetMonoOrStereo_Blend_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sAudio.s_mono_stereo_blend);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    // set soft mute
    MetaResult = SP_META_FM_SetSoftMute_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sAudio.s_soft_mute_onoff);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    // set soft mute stage
    //MetaResult = META_FM_SelectSoftMuteStage_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sAudio.s_soft_mute_level);
    //if (MetaResult != META_SUCCESS)
    //{
    //    if (META_TIMEOUT == MetaResult)
    //    {
    //        Confirm(META_TIMEOUT);
    //    }
    //    else
    //    {
    //        Confirm(META_FAILED);
    //    }
    //    return;
    //}

    // set blend stage
    MetaResult = SP_META_FM_SelectSBlendStage_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sAudio.s_stereo_blend_level);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    Confirm(META_SUCCESS);
}

//--------------------------------------------------------------------------
void __stdcall CFMRADIO::CNF_AudioSetVolume(const AUDIO_RESULT status, const short token, void *usrData)
{
    if (status != AUD_RES_OK)
    {
        Confirm(META_FAILED);
        return;
    }
    SetEvent(m_hEvent);
}

//===========================================================================
void CFMRADIO::REQ_ReadData_Start(unsigned char addr)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    m_ucAddr = addr;
    ActiveMan->SetActiveFunction(::REQ_ReadData);
}

//---------------------------------------------------------------------------
void CFMRADIO::REQ_ReadData(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    FM_READ_BYTE_ADDR_REQ_T req;
    FM_READ_BYTE_CNF_T cnf;
    req.m_ucAddr = m_ucAddr;

    META_RESULT MetaResult = SP_META_FM_ReadByte_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req, &cnf);

    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    m_usData = cnf.m_u2ReadByte;
    Confirm(META_SUCCESS);
}

//===========================================================================
void CFMRADIO::REQ_WriteData_Start(unsigned char addr, unsigned short data)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    m_ucAddr = addr;
    m_usData = data;
    ActiveMan->SetActiveFunction(::REQ_WriteData);
}

//---------------------------------------------------------------------------
void CFMRADIO::REQ_WriteData(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    FM_WRITE_BYTE_REQ_T req;
    req.m_ucAddr = m_ucAddr;
    req.m_u2WriteByte = m_usData;

    META_RESULT MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req);

    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }

    Confirm(META_SUCCESS);
}

//===========================================================================
/////////////////////////////         Query         /////////////////////////
//===========================================================================
// For old version target load compatible, return true always?
bool CFMRADIO::Query_FMSupport_Start(void)
{
    if(m_META_HANDLE_Obj.Get_MainHandle() <0){
        m_bFMSupport = false;
    }else{
    META_RESULT MetaResult = SP_META_QueryIfFunctionSupportedByTarget_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, "SP_META_FM_GetChipId_r");
    if (MetaResult != META_SUCCESS)
    {
        m_bFMSupport = false;
    }
    else
    {
        m_bFMSupport = true;
    }
    }
    return m_bFMSupport;
}

//---------------------------------------------------------------------------
bool CFMRADIO::REQ_Query_FMChipID_Start(FM_CHIP_ID_CNF_T& fm_chip_id)
{
    META_RESULT MetaResult = SP_META_FM_GetChipId_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sFMChipId);
    if (MetaResult != META_SUCCESS)
    {
        return false;
    }
    fm_chip_id = m_sFMChipId;
    return true;
}


bool CFMRADIO::REQ_Query_FMStepMode_Start(FM_STEP_MODE_CNF_T& fm_step_mode)
{
    META_RESULT MetaResult = SP_META_FM_GetStepMode_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sFMStepMode);
    if (MetaResult != META_SUCCESS)
    {
        return false;
    }
    fm_step_mode = m_sFMStepMode;
    return true;
}

//===========================================================================
/////////////////////////////   Global information  /////////////////////////
//===========================================================================
META_RESULT CFMRADIO::Get_ConfirmState(void)
{
    return m_eConfirmState;
}

//---------------------------------------------------------------------------
bool CFMRADIO::Get_FMSupport(void)
{
    return m_bFMSupport;
}

//---------------------------------------------------------------------------
FM_CHIP_ID_CNF_T* CFMRADIO::Get_FMChipID(void)
{
    return &m_sFMChipId;
}

//---------------------------------------------------------------------------
S_FM_STATUS_T* CFMRADIO::Get_FMStatus(void)
{
    return &m_sStatus;
}

//---------------------------------------------------------------------------
FM_VAILD_FREQ_CNF_T* CFMRADIO::Get_ValidFreq(void)
{
    return &m_sValidFreq;
}

//---------------------------------------------------------------------------
unsigned short CFMRADIO::Get_Data(void)
{
    return m_usData;
}
//---------------------------------------------------------------------------
// for MT6616 new API
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_AutoScan_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_FM_AutoScan);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_AutoScan(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_AutoScan_r(m_META_HANDLE_Obj.Get_MainHandle(), 25000, &m_sAutoScanCnf);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            MetaResult = SP_META_FM_HWSearch_Stop_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000);
            if(MetaResult != META_SUCCESS)
            {
                Confirm(META_TIMEOUT);
            }
            Confirm(META_TIMEOUT);
        }
        else
        {
            MetaResult = SP_META_FM_HWSearch_Stop_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000);
            if(MetaResult != META_SUCCESS)
            {
                Confirm(META_FAILED);
            }
            Confirm(META_FAILED);
        }
        return;
    }
    MetaResult = SP_META_FM_HWSearch_Stop_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000);
    if(MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_DecodeMode_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_DecodeMode);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_DecodeMode(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetDecodeMode_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sDecodeModeReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_DeemphasisLevel_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_DeemphasisLevel);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_DeemphasisLevel(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetDeemphasisLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sDeemphasisLevelReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_StereoBlend_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_StereoBlend);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_StereoBlend(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetStereoBlend_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sStereoBlendControlReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_HLSide_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_HLSide);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_HLSide(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetHLSide_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sHLSideReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_HCC_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_HCC);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_HCC(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetHCC_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sHCCReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_DemodBandwidth_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_DemodBandwidth);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_DemodBandwidth(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetDemodBW_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sDemodBandwidthReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_PAMDThreshold_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_PAMDThreshold);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_PAMDThreshold(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetPAMDThreshold_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sPAMDThresholdReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_DynamicLimiter_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_DynamicLimiter);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_DynamicLimiter(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetDynamicLimiter_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sDynamicLimiterReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_RSSIThreshold_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_RSSIThreshold);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_RSSIThreshold(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetRssiThreold_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sRSSIThresholdReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_SoftmuteRate_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_SoftmuteRate);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_SoftmuteRate(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetSoftmuteRate_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sSoftmuteRateReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_SoftmuteEnable_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_SoftmuteEnable);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_SoftmuteEnable(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_YUSU_SetSoftmute_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sSoftmuteEnableReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_RSSI_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Get_RSSI);
}



//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_RSSI(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetRSSI_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sFMFreq, &(m_sStatus.s_rssi));
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_SET_PARAMETER_Start(AnsiString xmlFile,FM_SETStatus_REQ_T req)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    m_fileName = xmlFile;
    m_req = req;

    ActiveMan->SetActiveFunction(::REQ_FM_SET_PARAMETER);

}
void CFMRADIO::REQ_FM_SET_PARAMETER(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetStatus_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, m_fileName.c_str(),m_req);

    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}

void CFMRADIO::REQ_FM_GET_STATUS_Start(AnsiString filename)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    m_fileName = filename;
    ActiveMan->SetActiveFunction(::REQ_FM_GET_STATUS);
}

void CFMRADIO::REQ_FM_GET_STATUS(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetStatus_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, m_fileName.c_str(),&cnf);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}

FM_Status_CNF_T CFMRADIO::REQ_FM_GetStatusMT6620()
{
    return cnf;
}
void CFMRADIO::REQ_FM_Get_RXFilterBW_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Get_RXFilterBW);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_RXFilterBW(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetRXFilterBW_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sStatus.s_rxfilterbw);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_PAMDLevel_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Get_PAMDLevel);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_PAMDLevel(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetPAMDLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sFMFreq, &m_sStatus.s_pamdlevel);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_MR_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Get_MR);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_MR(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetMR_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sStatus.s_mr);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_Stereo_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Get_Stereo);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_Stereo(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetStereoOrMono_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &(m_sStatus.s_stero_mono));
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_IFCounter_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Get_IFCounter);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_IFCounter(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetIfCnt_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sFMFreq, &(m_sStatus.s_if_cnt));
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_HLSide_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Get_HLSide);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Get_HLSide(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetHighOrLowSide_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sFMFreq, &(m_sStatus.s_hl_side));
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_HWSeek_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_HWSeek);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_HWSeek(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_HWSeek_r(m_META_HANDLE_Obj.Get_MainHandle(), 15000, &m_sHWSeekReq, &m_sHWSeekCnf);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            MetaResult = SP_META_FM_HWSearch_Stop_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000);
            if(MetaResult != META_SUCCESS)
            {
                Confirm(META_FAILED);
            }
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_Volume_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_Volume);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_Volume(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_SetVolume_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sVolumeSettingReq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_DecodeModeReq(unsigned int decode_mode)
{
    m_sDecodeModeReq.m_u4DecodeMode = decode_mode;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_DeemphasisLevelReq(unsigned int deemphasis_level)
{
    m_sDeemphasisLevelReq.m_u4DeemphasisLevel = deemphasis_level;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_HLSideReq(unsigned int hl_side)
{
    m_sHLSideReq.m_u4HLSide = hl_side;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_HCCReq(unsigned int hcc)
{
    m_sHCCReq.m_u4HCC = hcc;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_DemodBandwidthReq(unsigned int demod_bandwidth)
{
    m_sDemodBandwidthReq.m_u4DemodBandwidth = demod_bandwidth;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_PAMDThresholdReq(unsigned int pamd_threshold)
{
    m_sPAMDThresholdReq.m_u4PAMDThreshold = pamd_threshold;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_DynamicLimiterReq(unsigned int dynamic_limiter)
{
    m_sDynamicLimiterReq.m_u4DynamicLimiter = dynamic_limiter;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_SoftmuteRateReq(unsigned int softmute_rate)
{
    m_sSoftmuteRateReq.m_u4SoftmuteRate = softmute_rate;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_SoftmuteEnableReq(unsigned int softmute_enable)
{
    m_sSoftmuteEnableReq.m_u4SoftmuteEnable = softmute_enable;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_VolumeSettingReq(unsigned char volume, char digital_gain_index)
{
    m_sVolumeSettingReq.m_ucVolume = volume;
    m_sVolumeSettingReq.m_cDigitalGainIndex = digital_gain_index;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_RSSIThresholdReq(unsigned int rssi_threshold)
{
    m_sRSSIThresholdReq.m_u4RssiThreshold = rssi_threshold;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_HWSeekReq(short start_freq, unsigned char seek_direction)
{
    m_sHWSeekReq.m_i2StartFreq = start_freq;
    m_sHWSeekReq.m_ucDirection = seek_direction;
}
//---------------------------------------------------------------------------
void CFMRADIO::Get_ValidSeekFreq(FM_HWSeek_CNF_T &cnf)
{
    cnf = m_sHWSeekCnf;
}
//---------------------------------------------------------------------------
void CFMRADIO::Get_AutoScan(FM_AutoScan_CNF_T &cnf)
{
    cnf = m_sAutoScanCnf;
}
//---------------------------------------------------------------------------
unsigned int CFMRADIO::REQ_FM_Query_Version_Start(void)
{
    unsigned int version = 0;
    META_RESULT MetaResult = SP_META_QueryIfFunctionSupportedByTarget_r(m_META_HANDLE_Obj.Get_MainHandle(), 300, "SP_META_FM_AutoScan_r");
    if(MetaResult!=META_SUCCESS)
    {
        // old
        version = 0;
    }
    else if(MetaResult == META_SUCCESS)
    {
        // new MT6616
        version = 1;
    }
    return version;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_StereoBlendControl(unsigned short stereoblend_enable)
{
    m_sStereoBlendControlReq.m_u2StereoBlendControl = stereoblend_enable;
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_Softmute_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_Softmute);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_Softmute(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    // set soft mute
    META_RESULT MetaResult = SP_META_FM_SetSoftMute_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sAudio.s_soft_mute_onoff);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_MonoOrStereoBlend_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_MonoOrStereoBlend);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_MonoOrStereoBlend(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    // set mono or stereo blend
    m_sAudio.s_mono_stereo_blend.m_u4ItemValue = FM_ENABLE;
    META_RESULT MetaResult = SP_META_FM_SetMonoOrStereo_Blend_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sAudio.s_mono_stereo_blend);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_StereoBlendStage_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Set_StereoBlendStage);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Set_StereoBlendStage(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    // set blend stage
    META_RESULT MetaResult = SP_META_FM_SelectSBlendStage_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sAudio.s_stereo_blend_level);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_MonoOrStereoBlendReq(unsigned short stereoblend)
{
    m_sAudio.s_mono_stereo_blend.m_u2MonoOrStereo = stereoblend;
    m_sAudio.s_mono_stereo_blend.m_u2SblendOnOrOff = stereoblend;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_StereoBlendStageReq(unsigned char stage)
{
    m_sAudio.s_stereo_blend_level.m_ucStage = stage;
}
//---------------------------------------------------------------------------
void CFMRADIO::Set_SoftmuteReq(unsigned char enable)
{
    m_sAudio.s_soft_mute_onoff.m_bOnOff = enable;
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Audio_Test_Start(void)
{
    g_fm_radio_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_Audio_Test);
}
//---------------------------------------------------------------------------
void CFMRADIO::REQ_FM_Audio_Test(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult = SP_META_FM_AudioTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
//---------------------------------------------------------------------------
