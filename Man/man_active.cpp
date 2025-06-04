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
 *   man_active.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   Active main thread source
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
 * $Modtime:   Oct 25 2005 12:15:50  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Man/man_active.cpp-arc  $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#pragma hdrstop

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

//---------------------------------------------------------------------------
TActiveMan *ActiveMan = 0;

/*---------------------------------------------------------------------------*/

__fastcall TActiveMan::TActiveMan()
    :TThread(true)
{
    Priority = tpNormal;
    ActiveFunction = 0;
    is_suspend = true;
    ActiveFunction2 = NULL;
    ExcuteActiveFunction = NULL;
    ExcuteActiveFunction2 = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TActiveMan::Execute()
{
    void  (*func)(void);

    while(1)
    {
        func = ActiveFunction;
        ExcuteActiveFunction = ActiveFunction;
        if( func )
        {
            ActiveFunction = 0;
            func();
        }
        func = ActiveFunction2;
        ExcuteActiveFunction2 = ActiveFunction2;
        if( func )
        {
            ActiveFunction2 = 0;
            func();
        }
        if( (ActiveFunction==0)&&
                (ActiveFunction2==0) )
        {
            is_suspend = true;
            Suspend();
            is_suspend = false;
        }
    }
}
//---------------------------------------------------------------------------

void  TActiveMan::SetActiveFunction( void  (*func)(void) )
{
    if(func)
    {
        ActiveFunction  = func;
        if(is_suspend)
            Resume();
    }
}
//---------------------------------------------------------------------------

void  TActiveMan::SetActiveFunction2( void  (*func)(void) )
{
    if(func)
    {
        ActiveFunction2  = func;
        if(is_suspend)
            Resume();
    }
}
//---------------------------------------------------------------------------
void __fastcall TActiveMan::TerminateThread(void)
{
    void  (*func)(void);

    func = ExcuteActiveFunction;
    if( func )
    {
        Terminate();
        ExcuteActiveFunction = 0;
    }
    func = ExcuteActiveFunction2;
    if( func )
    {
        Terminate();
        ExcuteActiveFunction2 = 0;
    }


}

//--------------------------------------------------------------------------
