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
 *   sla.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   Serial link authentication source
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
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
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

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _SLA_H_
#include "sla.h"
#endif

//===========================================================================

static CSLA*  g_sla_ptr;

//===========================================================================
static void  REQ_TimeOut( void )
{
    g_sla_ptr->REQ_TimeOut();
}

//---------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    g_sla_ptr->REQ_Finish();
}

//===========================================================================
CSLA::CSLA( void )
{
    m_bIsRunning = false;
    ConfirmCallback = 0;
    m_sAuthHandle = NULL;
    m_iConfirmState = 0;
}

//---------------------------------------------------------------------------
CSLA::~CSLA()
{

}

//---------------------------------------------------------------------------
void  CSLA::REQ_Finish( void )
{
    if(!m_bIsRunning)  return;

    Confirm( STATE_SLA_OK );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
/*void  CSLA::REQ_Stop( void )
{
    if(!m_bIsRunning)  return;

    Confirm( STATE_SLA_STOP );
    m_bIsRunning = false;
}*/

//---------------------------------------------------------------------------
void  CSLA::REQ_TimeOut( void )
{
    if(!m_bIsRunning)  return;

    Confirm( STATE_SLA_TIMEOUT );
    m_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CSLA::Confirm( int confirm_state )
{
    if(!m_bIsRunning)  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
bool  CSLA::REQ_AUTH_Create( void )
{
    g_sla_ptr = this;
    m_bIsRunning = true;

    int ret = AUTH_Create( &m_sAuthHandle );
    if( ret != 0 )
        return false;
    return true;
}

//---------------------------------------------------------------------------
bool  CSLA::REQ_AUTH_Destroy( void )
{
    g_sla_ptr = this;
    m_bIsRunning = true;

    if( NULL == m_sAuthHandle )
        return false;

    int ret = AUTH_Destroy( &m_sAuthHandle );
    if( ret != 0 )
        return false;
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  CSLA::REQ_AUTH_Load( const char *auth_filepath )
{
    g_sla_ptr = this;
    m_bIsRunning = true;

    if( NULL == m_sAuthHandle )
        return false;

    int ret = AUTH_Load( m_sAuthHandle, auth_filepath );
    if( ret != 0 )
        return false;
    return true;
}

//--------------------------------------------------------------------------
bool  CSLA::REQ_AUTH_Unload( void )
{
    g_sla_ptr = this;
    m_bIsRunning = true;

    if( NULL == m_sAuthHandle )
        return false;

    int ret = AUTH_Unload( m_sAuthHandle );
    if( ret != 0 )
        return false;
    return true;
}

//===========================================================================
int  CSLA::Get_ConfirmState( void )
{
    return m_iConfirmState;
}

//--------------------------------------------------------------------------
AUTH_HANDLE_T CSLA::Get_AuthHandle( void )
{
    return m_sAuthHandle;
}
