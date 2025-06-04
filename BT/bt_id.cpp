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
 *   bt_id.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   BT chip ID source
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
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#pragma hdrstop

// BT
#ifndef  _BT_ID_H_
#include "bt_id.h"
#endif

// man
#ifndef  _MAN_TIMER_H_
#include "man_timer.h"
#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _BT_HCI_COMMON_H_
#include "bt_hci_common.h"
#endif

static CBTID* gs_bt_id_ptr;
static bool g_bIsRunning = false;

//==============================================================================
static void REQ_Stop(void)
{
    gs_bt_id_ptr->REQ_Stop();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_BT_GET_HW_Version(void)
{
    gs_bt_id_ptr->REQ_BT_GET_HW_Version();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_GET_BT_HW_Version(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_id_ptr->CNF_GET_BT_HW_Version( cnf, token, usrData );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void  REQ_BT_GET_FW_Version( void )
{
    gs_bt_id_ptr->REQ_BT_GET_FW_Version();
}

//---------------------------------------------------------------------------
static void __stdcall CNF_GET_BT_FW_Version(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    gs_bt_id_ptr->CNF_GET_BT_FW_Version( cnf, token, usrData );
}

//===========================================================================
CBTID::CBTID(void)
{
    m_bEventOk = false;
    memset(BT_Version_Buf,0,sizeof(char)*4);
    ConfirmCallback = NULL;
}

//---------------------------------------------------------------------------
CBTID::~CBTID(void)
{
}

/*void  CBTID::REQ_Stop( void )
{
    if (!g_bIsRunning)
    {
        return;
    }

    Confirm( METAAPP_STOP );
}   */

//===========================================================================
//////////////////////////////        Query   BT HW  ID      /////////////////////////
//===========================================================================
void CBTID::REQ_BT_GET_HW_Version_Start(void)
{
    gs_bt_id_ptr  = this;
    g_bIsRunning  = true;

    // ActiveMan->SetActiveFunction(::REQ_BT_GET_HW_Version);
    REQ_BT_GET_HW_Version();
}

void CBTID:: REQ_BT_GET_HW_Version(void)
{
    if (!g_bIsRunning)
        return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    // get bt hw version
    Compose_GET_HW_Versionl_HCI_Command(hci_cmd);

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_GET_BT_HW_Version, NULL, HCE_COMMAND_COMPLETE);

    MetaResult_Confirm(MetaResult);

    g_bIsRunning  = true;

    REQ_BT_GET_FW_Version();
}

void CBTID::CNF_GET_BT_HW_Version(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event)
    {
        return;
    }

    m_bEventOk = DeCompose_GET_HW_Versionl_HCI_Event(*cnf);
}

//===========================================================================
//////////////////////////////        Query   BT FW  ID      /////////////////////////
//===========================================================================
void CBTID::REQ_BT_GET_FW_Version_Start()
{
    gs_bt_id_ptr  = this;
    g_bIsRunning  = true;

    // ActiveMan->SetActiveFunction(::REQ_BT_GET_FW_Version);
    REQ_BT_GET_FW_Version();
}

void CBTID::REQ_BT_GET_FW_Version()
{
    if (!g_bIsRunning)
        return;

    m_bEventOk = false;
    BT_HCI_COMMAND hci_cmd;

    // get bt hw version
    Compose_GET_FW_Versionl_HCI_Command(hci_cmd);

    META_RESULT MetaResult = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &hci_cmd, ::CNF_GET_BT_FW_Version, NULL, HCE_COMMAND_COMPLETE);

    MetaResult_Confirm(MetaResult);

    //g_bIsRunning = true;

    //ActiveMan->SetActiveFunction(::REQ_Stop);
}

void CBTID::CNF_GET_BT_FW_Version(const BT_HCI_EVENT *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (0xFF == cnf->m_event)
    {
        return;
    }

    m_bEventOk = DeCompose_GET_FW_Versionl_HCI_Event(*cnf);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTID::Compose_GET_HW_Versionl_HCI_Command( BT_HCI_COMMAND &hci_cmd)
{
    hci_cmd.m_opcode = 0xFCD1;
    hci_cmd.m_len    = 4;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x00;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = 0x00;
    hci_cmd.m_cmd[3] = 0x80;
}

//--------------------------------------------------------------------------
bool  CBTID::DeCompose_GET_HW_Versionl_HCI_Event( BT_HCI_EVENT hci_event )
{
    if (0x00 != hci_event.m_parms[3])
        return false;

    BT_Version_Buf[0] = hci_event.m_parms[4];
    BT_Version_Buf[1] = hci_event.m_parms[5];

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTID::Compose_GET_FW_Versionl_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    hci_cmd.m_opcode = 0xFCD1;
    hci_cmd.m_len    = 4;
    Reset_HCI_Command( hci_cmd );
    hci_cmd.m_cmd[0] = 0x04;
    hci_cmd.m_cmd[1] = 0x00;
    hci_cmd.m_cmd[2] = 0x00;
    hci_cmd.m_cmd[3] = 0x80;
}

//--------------------------------------------------------------------------
bool  CBTID::DeCompose_GET_FW_Versionl_HCI_Event( BT_HCI_EVENT hci_event )
{
    if (0x00 != hci_event.m_parms[3])
        return false;

    BT_Version_Buf[2] = hci_event.m_parms[4];
    BT_Version_Buf[3] = hci_event.m_parms[5];

    return true;
}
bool CBTID::Set_BT_ModuleID()
{
    unsigned char buf_A[4] = {0x02,0x8A,0x02,0x8A};
    unsigned char buf_B[4] = {0x02,0x8B,0x02,0x8B};

    if (Compare_Buf(BT_Version_Buf,buf_A,4) || Compare_Buf(BT_Version_Buf,buf_B,4))
        m_sBTModuleID.id = BTMODULE_MT6611;
    else
        m_sBTModuleID.id = BT_NOT_SUPPORT;
    return true;
}
bool CBTID::Compare_Buf(unsigned char *pSourceBuf, unsigned char *pDestBuf,unsigned int bufLen)
{
    try
    {
        if ((!pSourceBuf)||(!pDestBuf))
            return false;

        for (unsigned int i = 0; i < bufLen; i++)
        {
            if(pSourceBuf[i] != pDestBuf[i])
                return false;
        }
        return true;
    }
    catch(...)
    {
        return false;
    }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBTID::Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd )
{
    for( int i=0; i<(sizeof(hci_cmd.m_cmd)/sizeof(hci_cmd.m_cmd[0])); i++ )
    {
        hci_cmd.m_cmd[i] = 0;
    }
}

void  CBTID::Confirm(META_RESULT confirm_state)
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
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

void CBTID::MetaResult_Confirm(META_RESULT MetaResult)
{
    if ((META_SUCCESS != MetaResult) || (!m_bEventOk))
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
            return;
        }
        else if (META_CANCEL == MetaResult)
        {
            Confirm(META_CANCEL);
            return;
        }
        else
        {
            Confirm(META_FAILED);
            return;
        }
    }
    Confirm(META_SUCCESS);
}

//===========================================================================
//////////////////////////////        Query         /////////////////////////
//===========================================================================
bool CBTID::REQ_Query_MoudleID_Start(void)
{
    META_RESULT  MetaResult = SP_META_BT_QueryModuleID_r(m_META_HANDLE_Obj.Get_MainHandle(), 300, &m_sBTModuleID);


    if(MetaResult!=META_SUCCESS)
    {
        m_sBTModuleID.id = BT_NOT_SUPPORT;
        return false;
    }

    return true;
}


//===========================================================================
/////////////////////////////   Export information  /////////////////////////
//===========================================================================
void CBTID::Get_BTMoudleID(BT_ModuleID_S& bt_module_id)
{
    bt_module_id = m_sBTModuleID;
}

//compose command



