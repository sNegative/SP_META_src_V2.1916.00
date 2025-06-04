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
 *   LogicalControlBase.cpp
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   .
 * Author:
 * -------
 *  Rongguo Zhang (mtk80761)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.11  $
 * $Modtime:   Oct 25 2005 11:45:30  $
 * $Log:    $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------
#pragma hdrstop
#include "LogicalControlBase.h"
#include "metaapp_common.h"
#include "bb_common.h"
#include "man_active.h"

static CLogicalControlBase*  g_cl_ptr;

static void  REQ_TimeOut(void)
{
    g_cl_ptr->REQ_TimeOut();
}

static void  REQ_Finish(void)
{
    g_cl_ptr->REQ_Finish();
}

static void  REQ_Stop( void )
{
    g_cl_ptr->REQ_Stop();
}

CLogicalControlBase::CLogicalControlBase(void)
{
    g_cl_ptr = this; //??????????????????????????
    m_bIsRunning = false;
    ConfirmCallback = 0;
    m_iConfirmState = 0;
}

CLogicalControlBase::~CLogicalControlBase(void)
{
    m_bIsRunning = false;
    ConfirmCallback = 0;
}

void  CLogicalControlBase::REQ_Finish( void )
{
    if(!m_bIsRunning)
        return;

    Confirm(META_SUCCESS);
    m_bIsRunning = false;
}

/*void  CLogicalControlBase::REQ_Stop( void )
{
	if(!m_bIsRunning)
		return;
	m_bIsRunning = false;

	SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
	Confirm(METAAPP_STOP);
}*/

void  CLogicalControlBase::REQ_TimeOut( void )
{
    if(!m_bIsRunning)
        return;
    m_bIsRunning = false;

    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    Confirm(META_TIMEOUT);
}

void  CLogicalControlBase::Confirm( int confirm_state )
{
    if(!m_bIsRunning)
        return;
    m_bIsRunning = false;

    if(!ConfirmCallback)
        return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

void CLogicalControlBase::DoMetaResult(META_RESULT mr)
{
    switch(mr)
    {
    case META_SUCCESS:
        Confirm(META_SUCCESS);
        break;
    case META_TIMEOUT:
        Confirm(META_TIMEOUT);
        break;
    default:
        Confirm(META_FAILED);
        break;
    }
}


int  CLogicalControlBase::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}

