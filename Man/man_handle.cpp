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
 *   man_handle.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   META_DLL handle management source
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/

#include <vcl.h>
#pragma hdrstop

// man
#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#include "Logger.h"

#define INVALID_HANDLE  -1

//int CMETAHANDLE::m_iMainHandle   = INVALID_HANDLE;
//int CMETAHANDLE::m_iSecondHandle = INVALID_HANDLE;
static int g_iMainHandle = INVALID_HANDLE;
static int g_iSecondHandle = INVALID_HANDLE;
//---------------------------------------------------------------------------
static CMETAHANDLE*  meta_handle_ptr;
static bool g_bIsRunning;
//----------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    meta_handle_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    meta_handle_ptr->REQ_Finish();
}

//----------------------------------------------------------------------------
static void __stdcall ErrorHandler(const META_CNF_ERR_CODE err)
{
    meta_handle_ptr->ErrorHandler(err);
}

//------------------------------------------------------------------------------
static void REQ_AllocateMainHandle( void )
{
    meta_handle_ptr->REQ_AllocateMainHandle();
}

//------------------------------------------------------------------------------
static void REQ_AllocateSecondHandle( void )
{
    meta_handle_ptr->REQ_AllocateSecondHandle();
}

//------------------------------------------------------------------------------
static void REQ_ReleaseMainHandle( void )
{
    meta_handle_ptr->REQ_ReleaseMainHandle();
}

//------------------------------------------------------------------------------
static void REQ_ReleaseSecondHandle( void )
{
    meta_handle_ptr->REQ_ReleaseSecondHandle();
}

//===========================================================================
CMETAHANDLE::CMETAHANDLE( void )
{
    g_bIsRunning    = false;
    // m_iMainHandle   = INVALID_HANDLE;
    // m_iSecondHandle = INVALID_HANDLE;
    ConfirmCallback = NULL;
    m_iConfirmState = 0;

}

//---------------------------------------------------------------------------
CMETAHANDLE::~CMETAHANDLE( )
{




}

//---------------------------------------------------------------------------
void  CMETAHANDLE::REQ_Finish( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_HANDLE_OK );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
/*void  CMETAHANDLE::REQ_Stop( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_HANDLE_STOP );
    g_bIsRunning = false;
}       */

//---------------------------------------------------------------------------
void  CMETAHANDLE::REQ_TimeOut( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_HANDLE_TIMEOUT );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
void  CMETAHANDLE::Confirm( int confirm_state )
{
    if(!g_bIsRunning)  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//---------------------------------------------------------------------------
void __stdcall CMETAHANDLE::ErrorHandler(const META_CNF_ERR_CODE err)
{
}

//===========================================================================
bool CMETAHANDLE::REQ_AllocateMainHandle_Start( void )
{
    meta_handle_ptr = this;
    g_bIsRunning    = true;
    return REQ_AllocateMainHandle();
}

//---------------------------------------------------------------------------
bool CMETAHANDLE::REQ_AllocateMainHandle( void )
{
    int meta_handle = 0;
    if(META_SUCCESS != SP_META_GetAvailableHandle(&meta_handle))
    {
        LOG("SP_META_GetAvailableHandle Fail");
        return false;
    }
    LOG("SP_META_GetAvailableHandle Success");
    if(META_SUCCESS != SP_META_Init_r( meta_handle, ::ErrorHandler ) )
    {
        LOG("SP_META_Init_r Fail");
        return false;
    }
    LOG("SP_META_GetAvailableHandle Success g_iMainHandle = %d", g_iMainHandle);
    g_iMainHandle = meta_handle;
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool CMETAHANDLE::REQ_AllocateSecondHandle_Start( void )
{
    meta_handle_ptr = this;
    g_bIsRunning    = true;

    if(!REQ_AllocateSecondHandle())
    {
        return false;
    }

    return false;
}

//---------------------------------------------------------------------------
bool CMETAHANDLE::REQ_AllocateSecondHandle( void )
{
    int meta_handle;
    META_RESULT  MetaResult;

    MetaResult = SP_META_GetAvailableHandle( &meta_handle );
    if( META_SUCCESS != MetaResult )
    {
        return false;
    }

    MetaResult = SP_META_Init_r( meta_handle, ::ErrorHandler );
    if( META_SUCCESS != MetaResult )
        return false;

    g_iSecondHandle = meta_handle;

    return true;
}

//===========================================================================
void CMETAHANDLE::REQ_ReleaseMainHandle_Start( void )
{
    meta_handle_ptr = this;
    g_bIsRunning    = true;

    REQ_ReleaseMainHandle();
}

//---------------------------------------------------------------------------
void CMETAHANDLE::REQ_ReleaseMainHandle( void )
{
    if( INVALID_HANDLE != g_iMainHandle )
    {
        SP_META_Deinit_r( &g_iMainHandle );
        g_iMainHandle = INVALID_HANDLE;
    }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CMETAHANDLE::REQ_ReleaseSecondHandle_Start( void )
{
    meta_handle_ptr = this;
    g_bIsRunning    = true;

    REQ_ReleaseSecondHandle();
}

//---------------------------------------------------------------------------
void CMETAHANDLE::REQ_ReleaseSecondHandle( void )
{
    if( INVALID_HANDLE != g_iSecondHandle )
    {
        SP_META_Deinit_r( &g_iSecondHandle );
        g_iSecondHandle = INVALID_HANDLE;
    }
}

//===========================================================================
////////////////////////////////  Global information  ///////////////////////
//===========================================================================
int   CMETAHANDLE::Get_ConfirmState( void )
{
    return m_iConfirmState;
}

//--------------------------------------------------------------------------
int CMETAHANDLE::Get_SecondHandle( void )
{
    return g_iSecondHandle;
}

//--------------------------------------------------------------------------
int CMETAHANDLE::Get_MainHandle( void )
{
    return g_iMainHandle;
}
