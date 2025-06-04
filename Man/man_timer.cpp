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
 *   man_timer.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *   Timer handling source
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
 * $Modtime:   Oct 25 2005 12:19:54  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Man/man_timer.cpp-arc  $
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 *    Rev 1.10   Oct 25 2005 14:15:18   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.9   Sep 04 2005 11:06:50   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.8   Apr 18 2005 15:49:14   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.7   Jan 30 2005 17:57:56   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *    Rev 1.6   Jan 10 2005 11:14:30   mtk00490
 * 1. Automatic BB chip and external clock rate detection
 * 2. Support baud rate 57600 (for FPGA test)
 * 3. RF tool
 * a.Trim IQ, offset IQ sweep (get phase error, original offset, IQ imbalance information from equipment)
 * 4. Audio
 * a.Acoustic FIR tuning and melody FIR tuning integrate with AFTDLL.dll (provide freqz and firls function, user does not to install MATLAB for FIR tuning)
 * 5. Update parameter
 * a.add barcode and IMEI read/write
 * 6. Factory
 * a.support DCS, PCS, GSM850 AFC calibration
 * b.phase error calibration
 * c.user configurable current limit
 * d.add APC DAC to result file
 * e.add AFC_BAND, AFC_ARFCN to TCVCXO AFC CFG editor
 * f.add CURRENT_LIMIT to ADC CFG editor
 * g.add phase error CFG editor
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/

#pragma hdrstop

#include "man_timer.h"
//---------------------------------------------------------------------------


TTimerMan  *TimerMan;


//---------------------------------------------------------------------------
static  void  TimeOut( void )
{
    TimerMan->TimeOut( );
}

/*---------------------------------------------------------------------------*/

__fastcall TTimerMan::TTimerMan()
    :TThread(true)
{
    Priority = tpNormal;
    TimeOutFunction = 0;
    VCLTimer = 0;
}
//---------------------------------------------------------------------------

void __fastcall TTimerMan::Execute()
{
    void  (*func)(void);

    while(1)
    {
        func = TimeOutFunction;
        if( func )
        {
            TimeOutFunction = 0;
            func();
        }
        if(TimeOutFunction==0)
        {
            Suspend();
        }
    }
}
//---------------------------------------------------------------------------

void  TTimerMan::CounterStart( int timeout_in_ms, void (*callback)(void) )
{
    if(VCLTimer==0)  return;

    TimerMan = this; // Andy
    VCLTimer->Enabled  = false;
    VCLTimer->Interval = timeout_in_ms;
    TimeOutFunction = callback;
    // VCLTimer->OnTimer  = (void)(_fastcall *(_closure)(TObject *))(TObject *) TimeOutFunction; // Andy
    //VCLTimer->Enabled  = true;
}
//---------------------------------------------------------------------------

void  TTimerMan::CounterRestart( int timeout_in_ms )
{
    if(VCLTimer==0)  return;

    VCLTimer->Enabled  = false;
    VCLTimer->Interval = timeout_in_ms;
    // VCLTimer->Enabled  = true;
}
//---------------------------------------------------------------------------

void  TTimerMan::CounterStop( void )
{
    if(VCLTimer==0)  return;

    VCLTimer->Enabled  = false;
}
//---------------------------------------------------------------------------

void  TTimerMan::TimeOut( void )
{
    if(VCLTimer==0)  return;

    VCLTimer->Enabled  = false;
    Resume();
}
//---------------------------------------------------------------------------
