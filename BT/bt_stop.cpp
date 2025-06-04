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
 *   rf_stop.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   RF stop source
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

#ifndef  _BT_STOP_H_
#include "bt_stop.h"
#endif

#include "man_active.h"
#include "man_fdm.h"

//===========================================================================
static CBTSTOP*  g_bt_stop_ptr;
static bool g_bIsRunning = false;

//===========================================================================
void __stdcall CNF_BTStop(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    g_bt_stop_ptr->CNF_BTStop( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void __stdcall CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    g_bt_stop_ptr->CNF_ResetHCIEvent( cnf, token, usrData );
}

//===========================================================================
CBTSTOP::CBTSTOP( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

//---------------------------------------------------------------------------
CBTSTOP::~CBTSTOP( void )
{
    ConfirmCallback = 0;
    g_bIsRunning = false;
}
//---------------------------------------------------------------------------
void CBTSTOP::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    Confirm(METAAPP_STOP);
}
//---------------------------------------------------------------------------
void CBTSTOP::Confirm(META_RESULT confirm_state)
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
bool  CBTSTOP::REQ_Start( bool reset )
{
    g_bt_stop_ptr = this;
    g_bIsRunning = true;

    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    META_RESULT  MetaResult = SP_META_BT_CancelHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000 );

    if(MetaResult!=META_SUCCESS)
    {
        return false;
    }

    if( reset )
    {
        BT_HCI_COMMAND hci_cmd;
        Compose_Reset_HCI_Command( hci_cmd );

        META_RESULT MetaResult = SP_META_BT_SendHCICommand_r( m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_ResetHCIEvent, NULL, HCE_COMMAND_COMPLETE );

        if( META_SUCCESS != MetaResult )
        {
            return false;
        }
    }

    return true;
}


//-------------------------------------
void __stdcall CBTSTOP::CNF_BTStop(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if(!g_bIsRunning)  return;

    if( cnf->m_status != BT_STATUS_SUCCESS )
    {
        Confirm( META_FAILED );
        return;
    }
}

//---------------------------------------------------------------------------
void __stdcall CBTSTOP::CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    // 0E,04,01,03,0C,00
    if(!g_bIsRunning)  return;

    if( (cnf->m_len      != 0x04) ||
            (cnf->m_parms[0] != 0x01) ||
            (cnf->m_parms[1] != 0x03) ||
            (cnf->m_parms[2] != 0x0C) ||
            (cnf->m_parms[3] != 0x00)
      )
    {
        Confirm( META_FAILED );
        return;
    }
}

//-------------------------------------
void CBTSTOP::Compose_Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0x0C03;
    hci_cmd.m_len    = 0x00;

}

//===========================================================================
/////////////////////////  Global information  //////////////////////////////
//===========================================================================
META_RESULT CBTSTOP::Get_ConfirmState( void )
{
    return  m_eConfirmState;
}
