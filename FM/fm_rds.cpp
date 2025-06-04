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
 *   fm_rds.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   FM RDS source
 *
 * Author:
 * -------
 *  YH Sung (mtk02607)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _FM_RDS_H_
#include "fm_rds.h"
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

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif
//===========================================================================
static CFMRDS* g_fm_rds_ptr;
static bool g_bIsRunning = false;

//---------------------------------------------------------------------------
static void REQ_FM_RDS_On(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_On();
}
//---------------------------------------------------------------------------
static void REQ_FM_RDS_Off(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_Off();
}
//---------------------------------------------------------------------------
static void REQ_FM_RDS_Reset_BlockCounter(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_Reset_BlockCounter();
}
//---------------------------------------------------------------------------
static void REQ_FM_RDS_Reset_GroupCounter(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_Reset_GroupCounter();
}
//---------------------------------------------------------------------------
static void REQ_FM_RDS_Get_GoodBlockCounter(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_Get_GoodBlockCounter();
}
//---------------------------------------------------------------------------
static void REQ_FM_RDS_Get_BadBlockCounter(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_Get_BadBlockCounter();
}
//---------------------------------------------------------------------------
static void REQ_FM_RDS_Get_GroupCounter(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_Get_GroupCounter();
}
//---------------------------------------------------------------------------
static void REQ_FM_RDS_Get_RDSBLERRatio(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_Get_RDSBLERRatio();
}
//---------------------------------------------------------------------------
static void REQ_FM_RDS_Get_RDSLogData(void)
{
    g_fm_rds_ptr->REQ_FM_RDS_Get_RDSLogData();
}
//---------------------------------------------------------------------------
void __stdcall CNF_RDSInfoUpdate(const FM_RDS_Info_CNF_T *cnf, const short token, void *usrData)
{
    g_fm_rds_ptr->CNF_RDSInfoUpdate(cnf, token, usrData);
}
//---------------------------------------------------------------------------
void __stdcall CNF_RDSStatusUpdate(const FM_RDS_Status_CNF_T *cnf, const short token, void *usrData)
{
    g_fm_rds_ptr->CNF_RDSStatusUpdate(cnf, token, usrData);
}
//===========================================================================
CFMRDS::CFMRDS(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    m_bFMSupport = false;
    m_u2RDSBLERRatio = 0;
    hPostMsgDestHandle = NULL;
}

//---------------------------------------------------------------------------
CFMRDS::~CFMRDS()
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}
//---------------------------------------------------------------------------
void CFMRDS::Confirm(META_RESULT confirm_state)
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
        short s;
        SP_META_Cancel_r(m_META_HANDLE_Obj.Get_MainHandle(), s);
        SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    }

    if (NULL == ConfirmCallback)
    {
        return;
    }

    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}
//---------------------------------------------------------------------------
META_RESULT CFMRDS::Get_ConfirmState(void)
{
    return m_eConfirmState;
}
//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_On_Start(HANDLE handle)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;
    hPostMsgDestHandle = handle;
    ActiveMan->SetActiveFunction(::REQ_FM_RDS_On);
}

//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_On(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult;
    // register RDS Info Update callback
    MetaResult = SP_META_FM_RegisterRDSInfoUpdateCallback_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_RDSInfoUpdate);
    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    // register RDS Status Update callback
    MetaResult = SP_META_FM_RegisterRDSStatusUpdateCallback_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_RDSStatusUpdate);
    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    // set RDS on
    m_sRDSREQ.m_ucRDSOn = 1;
    RDS_StartTime = Get_CurrentTime();
    MetaResult = SP_META_FM_SetRDS_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sRDSREQ);
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
void CFMRDS::REQ_FM_RDS_Off_Start(void)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_FM_RDS_Off);
}

//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Off(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult;
    // remove RDS Info Update callback
    MetaResult = SP_META_FM_RemoveRDSInfoUpdateCallback_r(m_META_HANDLE_Obj.Get_MainHandle());
    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    // remove RDS Status Update callback
    MetaResult = SP_META_FM_RemoveRDSStatusUpdateCallback_r(m_META_HANDLE_Obj.Get_MainHandle());
    if (MetaResult != META_SUCCESS)
    {
        Confirm(META_FAILED);
        return;
    }
    // set RDS off
    m_sRDSREQ.m_ucRDSOn = 0;
    MetaResult = SP_META_FM_SetRDS_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sRDSREQ);
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
void CFMRDS::REQ_FM_RDS_Reset_BlockCounter_Start(void)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_FM_RDS_Reset_BlockCounter);
}

//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Reset_BlockCounter(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_ResetBlockCounter_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
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
void CFMRDS::REQ_FM_RDS_Reset_GroupCounter_Start(void)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_RDS_Reset_GroupCounter);
}

//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Reset_GroupCounter(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_ResetGroupCounter_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
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
void CFMRDS::REQ_FM_RDS_Get_GoodBlockCounter_Start(void)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_RDS_Get_GoodBlockCounter);
}
//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Get_GoodBlockCounter(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetGoodBlockCounter_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sRDSGoodBlockCounter);
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
void CFMRDS::REQ_FM_RDS_Get_BadBlockCounter_Start(void)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_RDS_Get_BadBlockCounter);
}
//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Get_BadBlockCounter(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetBadBlockCounter_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sRDSBadBlockCounter);
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
void CFMRDS::REQ_FM_RDS_Get_GroupCounter_Start(void)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_RDS_Get_GroupCounter);
}
//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Get_GroupCounter(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
//rongguo 2011-06-24
//    META_RESULT MetaResult = SP_META_FM_GetGroupCounter_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sRDSGroupCounter);
    META_RESULT MetaResult = SP_META_FM_GetRDSGroupCounter_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sRDSGroupCounter);
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
FM_RDS_Good_Block_Counter_CNF_T CFMRDS::Get_FM_RDS_GoodBlockCounter(void)
{
    return m_sRDSGoodBlockCounter;
}
//---------------------------------------------------------------------------
FM_RDS_Bad_Block_Counter_CNF_T CFMRDS::Get_FM_RDS_BadBlockCounter(void)
{
    return m_sRDSBadBlockCounter;
}
//---------------------------------------------------------------------------
//rongguo 2011-06-24
//FM_RDS_Group_Counter_CNF_T CFMRDS::Get_FM_RDS_GroupCounter(void)
FM_RDS_GROUPCOUNTER_T CFMRDS::Get_FM_RDS_GroupCounter(void)
{
    return m_sRDSGroupCounter;
}
//---------------------------------------------------------------------------
void __stdcall CFMRDS::CNF_RDSInfoUpdate(const FM_RDS_Info_CNF_T *cnf, const short token, void *usrData)
{
//rongguo 2011-06-15
//    m_sRDSInfo = *cnf;
    memcpy(&m_sRDSInfo, cnf, sizeof(m_sRDSInfo));

    RDS_EventSyncTime = Get_CurrentTime();
    //RdsEvent e = *((short*)usrData);
    // post message
    PostMessage(hPostMsgDestHandle,
                WM_ML_FM_RDS_INFO_UPDATE,
                (unsigned int)&m_sRDSInfo,
                *((long*)usrData)
               );
}
//---------------------------------------------------------------------------
void __stdcall CFMRDS::CNF_RDSStatusUpdate(const FM_RDS_Status_CNF_T *cnf, const short token, void *usrData)
{
//rongguo 2011-06-15
//    m_sRDSStatus = *cnf;
    memcpy(&m_sRDSStatus, cnf, sizeof(m_sRDSStatus));
    RDS_EventSyncTime = Get_CurrentTime();
    //RdsEvent e = *((short*)usrData);
    // post message
    PostMessage(hPostMsgDestHandle,
                WM_ML_FM_RDS_STATUS_UPDATE,
                (unsigned int)&m_sRDSStatus,
                *((long*)usrData)
               );
}
//---------------------------------------------------------------------------
S_TIME* CFMRDS::Get_FM_RDS_StartTime()
{
    return &RDS_StartTime;
}
//---------------------------------------------------------------------------
S_TIME* CFMRDS::Get_FM_RDS_EventSyncTime()
{
    return &RDS_EventSyncTime;
}
//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Get_RDSBLERRatio_Start(void)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_RDS_Get_RDSBLERRatio);
}
//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Get_RDSBLERRatio(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
//rongguo 2011-06-24
//    META_RESULT MetaResult = SP_META_FM_GetRDSBLERRatio_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_u2RDSBLERRatio);
    META_RESULT MetaResult = SP_META_FM_GetRDSBlerRatio_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_u2RDSBLERRatio);
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
void CFMRDS::REQ_FM_RDS_Get_RDSLogData_Start(void)
{
    g_fm_rds_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_FM_RDS_Get_RDSLogData);
}
//---------------------------------------------------------------------------
void CFMRDS::REQ_FM_RDS_Get_RDSLogData(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_GetRDSLogData_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sRDSLogData);
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
unsigned short CFMRDS::Get_FM_RDS_BLER(void)
{
    return m_u2RDSBLERRatio;
}
//---------------------------------------------------------------------------
//rongguo 2011-06-24
//FM_RDS_Block_CNF_T* CFMRDS::Get_FM_RDS_LogData(void)
FM_RDS_LOGDATA_T * CFMRDS::Get_FM_RDS_LogData(void)
{
    return &m_sRDSLogData;
}
