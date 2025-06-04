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
 *   form_CFGADC.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  ADC CFG file header
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
 * $Modtime:   Oct 25 2005 11:47:48  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Form/form_CFGADC.h-arc  $
 *
 *    Rev 1.7   Oct 25 2005 14:14:04   mtk00490
 * IP2 calibration support Skyworks 74117, 74400
 *
 *    Rev 1.6   Sep 04 2005 11:04:44   mtk00490
 * 1. ADC calibration support Keithley 2306, Agilent E3631A power supply
 * 2. APC calibration support Skyworks 77328
 * 3. APC calibration support two APC DC offset
 * 4. APC ramp profile runtime setting
 * 5. Graphic APC ramp profile runtime setting
 * 6. Acoustic FIR tuning support Acqua file format
 *
 *    Rev 1.5   Apr 18 2005 15:47:54   mtk00490
 * crystal AFC calibration fine tune
 *
 *    Rev 1.4   Jan 30 2005 17:55:16   mtk00490
 * Audio
 * 1. Apply microphone, sidetone editor value to all element of array
 * 2. resolve number of element in frequency array = 2 * number of element of weight array
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#ifndef form_CFGADCH
#define form_CFGADCH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include "META_factory_cfg.h"
//---------------------------------------------------------------------------
class TfrmCFGAdc : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel3;
    TPanel *Panel1;
    TLabel *Label1;
    TEdit *edtADC_V1;
    TLabel *Label2;
    TEdit *edtADC_V2;
    TLabel *Label3;
    TEdit *edtADC_CHECK_VOLTAGE;
    TLabel *Label4;
    TEdit *edtNORMAL_VOLTAGE;
    TLabel *Label5;
    TEdit *edtMAX_BATTERY_ADC_SLOPE;
    TLabel *Label6;
    TEdit *edtMIN_BATTERY_ADC_SLOPE;
    TLabel *Label7;
    TEdit *edtMAX_BATTERY_ADC_OFFSET;
    TLabel *Label8;
    TEdit *edtMIN_BATTERY_ADC_OFFSET;
    TLabel *Label9;
    TEdit *edtBATTERY_CHANNEL;
    TLabel *Label10;
    TEdit *edtCHARGER_CHANNEL;
    TLabel *Label11;
    TEdit *edtADC_RESISTANCE;
    TLabel *Label12;
    TEdit *edtADC_MEASUREMENT_COUNT;
    TLabel *Label13;
    TLabel *Label14;
    TEdit *edtMAX_VOLTAGE_DIFFERENCE;
    TEdit *edtMAX_CURRENT_DIFFERENCE;
    TButton *btnLoadFromCFGFile;
    TButton *btnSaveToCFGFile;
    TStatusBar *sbCFGAdc;
    TOpenDialog *OpenDlg;
    TSaveDialog *SaveDlg;
    TTimer *HintTimer;
    TStaticText *lblHint;
    TLabel *Label15;
    TEdit *edtCURRENT_LIMIT;
    void __fastcall btnLoadFromCFGFileClick(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall btnSaveToCFGFileClick(TObject *Sender);
    void __fastcall edtADCVoltageCheck(TObject *Sender);
    void __fastcall edtADCSlopeCheck(TObject *Sender);
    void __fastcall edtADCOffsetCheck(TObject *Sender);
    void __fastcall edtADCChannelCheck(TObject *Sender);
    void __fastcall edtADCResistanceCheck(TObject *Sender);
    void __fastcall edtADCMeasurementCountCheck(TObject *Sender);
    void __fastcall edtADCMaxVoltageDifferenceCheck(TObject *Sender);
    void __fastcall edtADCMaxCurrentDifferenceCheck(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall edtCurrentLimitCheck(TObject *Sender);

private:	// User declarations
    TMETA_factory_cfg *cfg;
    int i_ADC_V1;
    int i_ADC_V2;
    int i_ADC_V[4];
    int i_ADC_CHECK_VOLTAGE;
    int i_NORMAL_VOLTAGE;
    int i_CURRENT_LIMIT;
    int i_MAX_BATTERY_ADC_SLOPE;
    int i_MIN_BATTERY_ADC_SLOPE;
    int i_BATTERY_ADC_SLOPE[2];
    int i_MAX_BATTERY_ADC_OFFSET;
    int i_MIN_BATTERY_ADC_OFFSET;
    int i_BATTERY_ADC_OFFSET[2];
    int i_BATTERY_CHANNEL;
    int i_CHARGER_CHANNEL;
    int i_CHANNEL[2];
    int i_ADC_MEASUREMENT_COUNT;
    double d_ADC_RESISTANCE;
    double d_MAX_VOLTAGE_DIFFERENCE;
    double d_MAX_CURRENT_DIFFERENCE;


public:		// User declarations
    __fastcall TfrmCFGAdc(TComponent* Owner);
    bool  CheckFields( void );
    void  ShowHintLabel( TControl *sender, char* hint );
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCFGAdc *frmCFGAdc;
//---------------------------------------------------------------------------
#endif
