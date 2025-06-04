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
 *   man_active_boot.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   Active main boot thread source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.10  $
 * $Modtime:   Oct 25 2005 12:16:28  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Man/man_active_boot.cpp-arc  $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#include <Classes.hpp>
#pragma hdrstop

#include "man_active_boot.h"
//---------------------------------------------------------------------------

TActiveMan_Boot *ActiveMan_Boot = NULL;

/*---------------------------------------------------------------------------*/

__fastcall TActiveMan_Boot::TActiveMan_Boot()
    :TThread(false)
{
    Priority = tpLower;
    ActiveFunction_Boot = NULL;
    ActiveFunction2_Boot = NULL;
    is_suspend = false;
    ExcuteActiveFunction_Boot = NULL;
    ExcuteActiveFunction2_Boot = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TActiveMan_Boot::Execute()
{
    void  (*func)(void);

    while(1)
    {
        func = ActiveFunction_Boot;
        ExcuteActiveFunction_Boot = ActiveFunction_Boot;
        if( func )
        {
            ActiveFunction_Boot = 0;
            func();
        }
        func = ActiveFunction2_Boot;
        ExcuteActiveFunction2_Boot = ActiveFunction2_Boot;
        if( func )
        {
            ActiveFunction2_Boot = 0;
            func();
        }
        if( (ActiveFunction_Boot==0)&&
                (ActiveFunction2_Boot==0) )
        {
            is_suspend = true;
            Suspend();
            is_suspend = false;
        }
    }
}
//---------------------------------------------------------------------------

void  TActiveMan_Boot::SetActiveFunction_Boot( void  (*func)(void) )
{
    if(func != NULL) // added by Andy Ueng
    {
        ActiveFunction_Boot  = func;
        if(is_suspend)
            Resume();
    }
}
//---------------------------------------------------------------------------

void  TActiveMan_Boot::SetActiveFunction2_Boot( void  (*func)(void) )
{
    if(func != NULL) // added by Andy Ueng
    {
        ActiveFunction2_Boot  = func;
        if(is_suspend)
            Resume();
    }
}
//---------------------------------------------------------------------------
void __fastcall TActiveMan_Boot::TerminateThread_Boot(void)
{
    void  (*func)(void);

    func = ExcuteActiveFunction_Boot;
    if( func )
    {
        Terminate();
        ExcuteActiveFunction_Boot = 0;
    }
    func = ExcuteActiveFunction2_Boot;
    if( func )
    {
        Terminate();
        ExcuteActiveFunction2_Boot = 0;
    }
}
