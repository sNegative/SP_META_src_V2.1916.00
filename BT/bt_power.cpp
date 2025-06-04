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
 *   bt_power.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT power on source
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
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 * Nov 23 2006 mtk00490
 * [STP100001231] [META] META ver 5.3.4.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _BT_POWER_H_
#include "bt_power.h"
#endif

// man
#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

//===========================================================================
static CBTPOWER*  g_bt_power_ptr;
static bool g_bIsRunning = false;

//===========================================================================
CBTPOWER::CBTPOWER(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}

//---------------------------------------------------------------------------
CBTPOWER::~CBTPOWER(void)
{
    ConfirmCallback = NULL;
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
/*void  CBTPOWER::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    Confirm(METAAPP_STOP);
} */


//---------------------------------------------------------------------------
void  CBTPOWER::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }
    g_bIsRunning = false;
    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//===========================================================================
bool  CBTPOWER::REQ_Power_On_Main_BT_Start(void)
{
    g_bt_power_ptr = this;
    g_bIsRunning = true;

    META_RESULT  MetaResult = SP_META_BTPowerOn_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);

    if(MetaResult!=META_SUCCESS)
    {
        return false;
    }

    return true;
}

//--------------------------------------------------------------------------
bool  CBTPOWER::REQ_Power_On_Second_BT_Start(void)
{
    g_bt_power_ptr = this;
    g_bIsRunning = true;

    META_RESULT  MetaResult = SP_META_BTPowerOn_r(m_META_HANDLE_Obj.Get_SecondHandle(), 5000);

    if(MetaResult!=META_SUCCESS)
    {
        return false;
    }

    return true;
}


//===========================================================================
/////////////////////////        Query         //////////////////////////////
//===========================================================================
bool CBTPOWER::REQ_Query_Power_On_Start(void)
{
    g_bt_power_ptr = this;
    g_bIsRunning = true;

    META_RESULT  MetaResult = SP_META_QueryIfBTPowerOn_r(m_META_HANDLE_Obj.Get_MainHandle(), 300);

    if(MetaResult!=META_SUCCESS)
    {
        return false;
    }

    return true;
}


//===========================================================================
/////////////////////////  Global information  //////////////////////////////
//===========================================================================
META_RESULT CBTPOWER::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}
