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
 *   form_CFGADC.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  ADC CFG file source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.7  $
 * $Modtime:   Oct 25 2005 11:47:36  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Form/form_CFGADC.cpp-arc  $
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Sep 8 2007 mtk00490
 * [STP100001505] [META] META ver 5.6.0
 *
 *
 * Mar 20 2007 mtk00490
 * [STP100001345] [META] META ver 5.3.6.2
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 * Mar 16 2006 mtk00490
 * re-import flash_tool, meta_app, meta_dll, MCUProfiling  into VOB
 *
 *
 *    Rev 1.7   Oct 25 2005 14:14:02   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.6   Sep 04 2005 11:04:42   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.5   Apr 18 2005 15:47:52   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.4   Jan 30 2005 17:55:14   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_CFGADC.h"
#include "META_Factory.h"

#include "misc.h"

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

#include "meta_utils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCFGAdc *frmCFGAdc;
//---------------------------------------------------------------------------
__fastcall TfrmCFGAdc::TfrmCFGAdc(TComponent* Owner)
    : TForm(Owner)
{
    i_ADC_V[0] = i_ADC_V1;
    i_ADC_V[1] = i_ADC_V2;
    i_ADC_V[2] = i_ADC_CHECK_VOLTAGE;
    i_ADC_V[3] = i_NORMAL_VOLTAGE;
    i_BATTERY_ADC_SLOPE[0] = i_MAX_BATTERY_ADC_SLOPE;
    i_BATTERY_ADC_SLOPE[1] = i_MIN_BATTERY_ADC_SLOPE;
    i_BATTERY_ADC_OFFSET[0] = i_MAX_BATTERY_ADC_OFFSET;
    i_BATTERY_ADC_OFFSET[1] = i_MIN_BATTERY_ADC_OFFSET;
    i_CHANNEL[0] = i_BATTERY_CHANNEL;
    i_CHANNEL[1] = i_CHARGER_CHANNEL;
    cfg = NULL;
    i_ADC_V1 = 0;
    i_ADC_V2 = 0;
    i_ADC_CHECK_VOLTAGE = 0;
    i_NORMAL_VOLTAGE = 0;
    i_CURRENT_LIMIT = 0;
    i_MAX_BATTERY_ADC_SLOPE = 0;
    i_MIN_BATTERY_ADC_SLOPE = 0;
    i_MAX_BATTERY_ADC_OFFSET = 0;
    i_MIN_BATTERY_ADC_OFFSET = 0;
    i_BATTERY_CHANNEL = 0;
    i_CHARGER_CHANNEL = 0;
    i_ADC_MEASUREMENT_COUNT = 0;
    d_ADC_RESISTANCE = 0;
    d_MAX_VOLTAGE_DIFFERENCE = 0;
    d_MAX_CURRENT_DIFFERENCE = 0;
    
     
}
//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::btnLoadFromCFGFileClick(TObject *Sender)
{
    bool ok;
    //int i;
    AnsiString asPath, asFileName;
    static bool isFirstOpen = true;

    if( isFirstOpen )
    {
        isFirstOpen = false;
        if( getPathFromStr( frmFatcory->stCFGFile->Caption, asPath ) )
        {
            OpenDlg->InitialDir = asPath;
            if( getFilenameFromStr( frmFatcory->stCFGFile->Caption, asFileName ) )
            {
                OpenDlg->FileName = asFileName;
            }
        }
        else
        {
            if( getPathFromStr(Application->ExeName, asPath) )
            {
                OpenDlg->InitialDir = asPath;
            }
            else
            {
                OpenDlg->InitialDir = "C:\\";
            }
        }
    }

    ok = OpenDlg->Execute();
    if( !ok )
    {
        sbCFGAdc->Panels->Items[0]->Text = (AnsiString) "  Load ADC setting from file fail";
        Application->MessageBox( "Execution Failure : Load ADC setting from file fail", "FAILURE", MB_OK );
        return;
    }

    if (!cfg->ReadFromIniFile(OpenDlg->FileName))
    {
        sbCFGAdc->Panels->Items[0]->Text = (AnsiString) "  Read CFG file fail";
        Application->MessageBox( "Execution Failure : Read CFG file", "FAILURE", MB_OK );
        return;
    }

    // ADC_V1
    cfg->getADC_V1( i_ADC_V1 );
    edtADC_V1->Text = IntToStr( i_ADC_V1 );

    // ADC_V2
    cfg->getADC_V2( i_ADC_V2 );
    edtADC_V2->Text = IntToStr( i_ADC_V2 );

    // ADC_CHECK_VOLTAGE
    cfg->getADC_CHECK_VOLTAGE( i_ADC_CHECK_VOLTAGE );
    edtADC_CHECK_VOLTAGE->Text = IntToStr( i_ADC_CHECK_VOLTAGE );

    // NORMAL_VOLTAGE
    cfg->get_NORMAL_VOLTAGE( i_NORMAL_VOLTAGE );
    edtNORMAL_VOLTAGE->Text = IntToStr( i_NORMAL_VOLTAGE );

    // CURRENT_LIMIT
    cfg->get_CURRENT_LIMIT( i_CURRENT_LIMIT );
    edtCURRENT_LIMIT->Text = IntToStr( i_CURRENT_LIMIT );

    // MAX_BATTERY_ADC_SLOPE
    cfg->get_MAX_BATTERY_ADC_SLOPE( i_MAX_BATTERY_ADC_SLOPE );
    edtMAX_BATTERY_ADC_SLOPE->Text = IntToStr( i_MAX_BATTERY_ADC_SLOPE );

    // MIN_BATTERY_ADC_SLOPE
    cfg->get_MIN_BATTERY_ADC_SLOPE( i_MIN_BATTERY_ADC_SLOPE );
    edtMIN_BATTERY_ADC_SLOPE->Text = IntToStr( i_MIN_BATTERY_ADC_SLOPE );

    // MAX_BATTERY_ADC_OFFSET
    cfg->get_MAX_BATTERY_ADC_OFFSET( i_MAX_BATTERY_ADC_OFFSET );
    edtMAX_BATTERY_ADC_OFFSET->Text = IntToStr( i_MAX_BATTERY_ADC_OFFSET );

    // MIN_BATTERY_ADC_OFFSET
    cfg->get_MIN_BATTERY_ADC_OFFSET( i_MIN_BATTERY_ADC_OFFSET );
    edtMIN_BATTERY_ADC_OFFSET->Text = IntToStr( i_MIN_BATTERY_ADC_OFFSET );

    // BATTERY_CHANNEL
    cfg->get_BATTERY_CHANNEL( i_BATTERY_CHANNEL );
    edtBATTERY_CHANNEL->Text = IntToStr( i_BATTERY_CHANNEL );

    // CHARGER_CHANNEL
    cfg->get_CHARGER_CHANNEL( i_CHARGER_CHANNEL );
    edtCHARGER_CHANNEL->Text = IntToStr( i_CHARGER_CHANNEL );

    // ADC_RESISTANCE
    cfg->get_ADC_RESISTANCE( d_ADC_RESISTANCE );
    edtADC_RESISTANCE->Text = Double_To_AnsiString( d_ADC_RESISTANCE );

    // MAX_VOLTAGE_DIFFERENCE
    cfg->get_MAX_VOLTAGE_DIFFERENCE( d_MAX_VOLTAGE_DIFFERENCE );
    edtMAX_VOLTAGE_DIFFERENCE->Text = Double_To_AnsiString( d_MAX_VOLTAGE_DIFFERENCE );

    // MAX_CURRENT_DIFFERENCE
    cfg->get_MAX_CURRENT_DIFFERENCE( d_MAX_CURRENT_DIFFERENCE );
    edtMAX_CURRENT_DIFFERENCE->Text = Double_To_AnsiString( d_MAX_CURRENT_DIFFERENCE );

    // ADC_MEASUREMENT_COUNT
    cfg->get_ADC_MEASUREMENT_COUNT( i_ADC_MEASUREMENT_COUNT );
    edtADC_MEASUREMENT_COUNT->Text = IntToStr( i_ADC_MEASUREMENT_COUNT );
}
//---------------------------------------------------------------------------

void __fastcall TfrmCFGAdc::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::FormClose(TObject *Sender,
                                      TCloseAction &Action)
{
    if(cfg != NULL)
    {
        delete cfg;
        cfg = NULL;
    }
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::btnSaveToCFGFileClick(TObject *Sender)
{
    bool ok;
    //int i;
    AnsiString asPath, asFileName;
    static bool isFirstSave = true;

    if( isFirstSave )
    {
        isFirstSave = false;

        if( getPathFromStr( frmFatcory->stCFGFile->Caption, asPath ) )
        {
            SaveDlg->InitialDir = asPath;
            if( getFilenameFromStr( frmFatcory->stCFGFile->Caption, asFileName ) )
            {
                SaveDlg->FileName = asFileName;
            }
        }
        else
        {
            if( getPathFromStr(Application->ExeName, asPath) )
            {
                SaveDlg->InitialDir = asPath;
            }
            else
            {
                SaveDlg->InitialDir = "C:\\";
            }
        }
    }
    if( ! CheckFields() )
    {
        sbCFGAdc->Panels->Items[0]->Text = (AnsiString) "  Save ADC setting to file fail";
        Application->MessageBox( "Execution Failure : Save ADC setting to file", "FAILURE", MB_OK );
        return;
    }

    ok = SaveDlg->Execute();
    if( !ok )
    {
        sbCFGAdc->Panels->Items[0]->Text = (AnsiString) "  Save ADC setting to file fail";
        Application->MessageBox( "Execution Failure : Save ADC setting to file", "FAILURE", MB_OK );
        return;
    }

    cfg->SaveAdcToCfgFile( SaveDlg->FileName );
}

//---------------------------------------------------------------------------
bool  TfrmCFGAdc::CheckFields( void )
{
    AnsiString  text;

    text = edtADC_V1->Text;
    if( !IsValidADCVoltage( text, i_ADC_V1 ) )
    {
        edtADCVoltageCheck(edtADC_V1);
        return false;
    }
    cfg->setADC_V1( i_ADC_V1 );

    text = edtADC_V2->Text;
    if( !IsValidADCVoltage( text, i_ADC_V2 ) )
    {
        edtADCVoltageCheck(edtADC_V2);
        return false;
    }
    cfg->setADC_V2( i_ADC_V2 );

    text = edtADC_CHECK_VOLTAGE->Text;
    if( !IsValidADCVoltage( text, i_ADC_CHECK_VOLTAGE ) )
    {
        edtADCVoltageCheck(edtADC_CHECK_VOLTAGE);
        return false;
    }
    cfg->setADC_CHECK_VOLTAGE( i_ADC_CHECK_VOLTAGE );

    text = edtNORMAL_VOLTAGE->Text;
    if( !IsValidADCVoltage( text, i_NORMAL_VOLTAGE ) )
    {
        edtADCVoltageCheck(edtNORMAL_VOLTAGE);
        return false;
    }
    cfg->set_NORMAL_VOLTAGE( i_NORMAL_VOLTAGE );

    text = edtCURRENT_LIMIT->Text;
    if( !IsValidCurrentLimit( text, i_CURRENT_LIMIT ) )
    {
        edtCurrentLimitCheck(edtCURRENT_LIMIT);
        return false;
    }
    cfg->set_CURRENT_LIMIT( i_CURRENT_LIMIT );

    text = edtMAX_BATTERY_ADC_SLOPE->Text;
    if( !IsValidADCSlope( text, i_MAX_BATTERY_ADC_SLOPE ) )
    {
        edtADCSlopeCheck(edtMAX_BATTERY_ADC_SLOPE);
        return false;
    }
    cfg->set_MAX_BATTERY_ADC_SLOPE( i_MAX_BATTERY_ADC_SLOPE );

    text = edtMIN_BATTERY_ADC_SLOPE->Text;
    if( !IsValidADCSlope( text, i_MIN_BATTERY_ADC_SLOPE ) )
    {
        edtADCSlopeCheck(edtMIN_BATTERY_ADC_SLOPE);
        return false;
    }
    cfg->set_MIN_BATTERY_ADC_SLOPE( i_MIN_BATTERY_ADC_SLOPE );

    text = edtMAX_BATTERY_ADC_OFFSET->Text;
    if( !IsValidADCOffset( text, i_MAX_BATTERY_ADC_OFFSET ) )
    {
        edtADCOffsetCheck(edtMAX_BATTERY_ADC_OFFSET);
        return false;
    }
    cfg->set_MAX_BATTERY_ADC_OFFSET( i_MAX_BATTERY_ADC_OFFSET );

    text = edtMIN_BATTERY_ADC_OFFSET->Text;
    if( !IsValidADCOffset( text, i_MIN_BATTERY_ADC_OFFSET ) )
    {
        edtADCOffsetCheck(edtMIN_BATTERY_ADC_OFFSET);
        return false;
    }
    cfg->set_MIN_BATTERY_ADC_OFFSET( i_MIN_BATTERY_ADC_OFFSET );

    text = edtBATTERY_CHANNEL->Text;
    if( !IsValidADCChannel( text, i_BATTERY_CHANNEL ) )
    {
        edtADCChannelCheck(edtBATTERY_CHANNEL);
        return false;
    }
    cfg->set_BATTERY_CHANNEL( i_BATTERY_CHANNEL );

    text = edtCHARGER_CHANNEL->Text;
    if( !IsValidADCChannel( text, i_CHARGER_CHANNEL ) )
    {
        edtADCChannelCheck(edtCHARGER_CHANNEL);
        return false;
    }
    cfg->set_CHARGER_CHANNEL( i_CHARGER_CHANNEL );

    text = edtADC_RESISTANCE->Text;
    if( !IsValidADCResistance( text, d_ADC_RESISTANCE ) )
    {
        edtADCResistanceCheck(edtADC_RESISTANCE);
        return false;
    }
    cfg->set_ADC_RESISTANCE( d_ADC_RESISTANCE );

    text = edtMAX_VOLTAGE_DIFFERENCE->Text;
    if( !IsValidADCMaxVoltageDifference( text, d_MAX_VOLTAGE_DIFFERENCE ) )
    {
        edtADCMaxVoltageDifferenceCheck(edtMAX_VOLTAGE_DIFFERENCE);
        return false;
    }
    cfg->set_MAX_VOLTAGE_DIFFERENCE( d_MAX_VOLTAGE_DIFFERENCE );

    text = edtMAX_CURRENT_DIFFERENCE->Text;
    if( !IsValidADCMaxCurrentDifference( text, d_MAX_CURRENT_DIFFERENCE ) )
    {
        edtADCMaxCurrentDifferenceCheck(edtMAX_CURRENT_DIFFERENCE);
        return false;
    }
    cfg->set_MAX_CURRENT_DIFFERENCE( d_MAX_CURRENT_DIFFERENCE );

    text = edtADC_MEASUREMENT_COUNT->Text;
    if( !IsValidADCMeasurementCount( text, i_ADC_MEASUREMENT_COUNT ) )
    {
        edtADCChannelCheck(edtADC_MEASUREMENT_COUNT);
        return false;
    }
    cfg->set_ADC_MEASUREMENT_COUNT( i_ADC_MEASUREMENT_COUNT );

    return true;

}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::edtADCVoltageCheck(TObject *Sender)
{
    AnsiString  text;
    int  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input voltage is not valid ";

    text = edit->Text;
    if( !IsValidADCVoltage( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    i_ADC_V[edit->Tag] = data;
}

//---------------------------------------------------------------------------
void TfrmCFGAdc::ShowHintLabel( TControl *sender, char* hint )
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::edtADCSlopeCheck(TObject *Sender)
{
    AnsiString  text;
    int  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input slope is not valid ";

    text = edit->Text;
    if( !IsValidADCSlope( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    i_BATTERY_ADC_SLOPE[edit->Tag] = data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::edtADCOffsetCheck(TObject *Sender)
{
    AnsiString  text;
    int  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input offset is not valid ";

    text = edit->Text;
    if( !IsValidADCOffset( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    i_BATTERY_ADC_OFFSET[edit->Tag] = data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::edtADCChannelCheck(TObject *Sender)
{
    AnsiString  text;
    int  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input channel is not valid ";

    text = edit->Text;
    if( !IsValidADCChannel( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    i_CHANNEL[edit->Tag] = data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::edtADCResistanceCheck(TObject *Sender)
{
    AnsiString  text;
    double  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input resistance is not valid ";

    text = edit->Text;
    if( !IsValidADCResistance( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    d_ADC_RESISTANCE = data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::edtADCMeasurementCountCheck(TObject *Sender)
{
    AnsiString  text;
    int  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input measurement count is not valid ";

    text = edit->Text;
    if( !IsValidADCMeasurementCount( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    i_ADC_MEASUREMENT_COUNT = data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::edtADCMaxVoltageDifferenceCheck(
    TObject *Sender)
{
    AnsiString  text;
    double  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input max voltage difference is not valid ";

    text = edit->Text;
    if( !IsValidADCMaxVoltageDifference( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    d_MAX_VOLTAGE_DIFFERENCE = data;
}

//---------------------------------------------------------------------------
void __fastcall TfrmCFGAdc::edtADCMaxCurrentDifferenceCheck(
    TObject *Sender)
{
    AnsiString  text;
    double  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input max current difference is not valid ";

    text = edit->Text;
    if( !IsValidADCMaxVoltageDifference( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    d_MAX_CURRENT_DIFFERENCE = data;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCFGAdc::FormShow(TObject *Sender)
{
    if(cfg == NULL)
    {
        cfg = new TMETA_factory_cfg();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCFGAdc::edtCurrentLimitCheck(TObject *Sender)
{
    AnsiString  text;
    int  data;
    //int  band;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = " input current is not valid ";

    text = edit->Text;
    if( !IsValidCurrentLimit( text, data ) )
    {
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
    i_CURRENT_LIMIT = data;
}
//---------------------------------------------------------------------------

