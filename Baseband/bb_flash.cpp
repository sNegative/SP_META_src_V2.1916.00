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
 *   bb_flash.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Baseband flash related source
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
 * Nov 7 2006 mtk00490
 * [STP100001203] [META] META ver 5.3.3.0
 *
 *
 * Oct 17 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#pragma hdrstop

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _BB_FLASH_H_
#include "bb_flash.h"
#endif
//===========================================================================

static CBBFLASH*  bb_flash_ptr;
static bool g_bIsRunning;
//---------------------------------------------------------------------------
//===========================================================================
static void  REQ_TimeOut( void )
{
    bb_flash_ptr->REQ_TimeOut();
}

//---------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    bb_flash_ptr->REQ_Finish();
}

//===========================================================================
CBBFLASH::CBBFLASH( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_iConfirmState = 0;
    m_bSingleBankSupport = false;
}

//---------------------------------------------------------------------------
CBBFLASH::~CBBFLASH( )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;


}

//---------------------------------------------------------------------------
void  CBBFLASH::REQ_Finish( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_FLASH_OK );
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
/*void  CBBFLASH::REQ_Stop( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_FLASH_STOP );
    g_bIsRunning = false;
}  */

//---------------------------------------------------------------------------
void  CBBFLASH::REQ_TimeOut( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_FLASH_TIMEOUT );

}

//---------------------------------------------------------------------------
void  CBBFLASH::Confirm( int confirm_state )
{
    if(!g_bIsRunning)  return;
    g_bIsRunning = false;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
bool  CBBFLASH::Query_SingleBankFlash_Support_Start( void )
{
    META_RESULT MetaResult = SP_META_QueryIfTargetIsLowCostSingleBankFlash_r( m_META_HANDLE_Obj.Get_MainHandle(), 300 );
    if( META_SUCCESS != MetaResult )
    {
        m_bSingleBankSupport = false;
        return false;
    }
    m_bSingleBankSupport = true;
    return true;
}

//===========================================================================
//////////////////////////// inport/export information  /////////////////////
//===========================================================================
bool CBBFLASH::Get_SingleBankFlashSupport( void )
{
    return m_bSingleBankSupport;
}
