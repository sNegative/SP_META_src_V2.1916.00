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
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   form_UnitTest.h
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Unit test form header
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
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#ifndef _FORM_UNITTEST_H_
#define _FORM_UNITTEST_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "NVRAMEditor.h"
#ifndef  _HW_TEST_H_
#include "hw_test.h"
#endif
#define HCE_COMMAND_COMPLETE               0x0E
static int TestPassNum;
//---------------------------------------------------------------------------
class TfrmUnitTest : public TForm
{
__published:	// IDE-managed Components
    TEdit *edtTestCase;
    TButton *btnTest;
    TStaticText *lblHint;
    TTimer *HintTimer;
    TButton *btnTestAll;
    TButton *btnTestDVB;
    TButton *btnTestWmWiFi;
    TButton *btnTestNVRAM;
        TGroupBox *GroupBox1;
        TMemo *HWTestInfo;
        TButton *HWTest;
        TButton *ClearInfo;
        TButton *btnReceiver;
        TButton *btnPass;
        TButton *btnFail;
        TButton *btnSpeakerR;
        TButton *btnSpeakerL;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TCheckBox *cb_wifi;
        TCheckBox *cb_bt;
        TCheckBox *cb_fm;
        TCheckBox *cb_gps;
        TCheckBox *cb_gsensor;
        TCheckBox *cb_msensor;
        TCheckBox *cb_sdcard;
        TCheckBox *cb_ctp;
        TCheckBox *cb_gyrosensor;
        TCheckBox *cb_alsps;
        TCheckBox *cb_cancelAll;
        TButton *btnEnATM;
        TButton *btnDisATM;
    void __fastcall edtTestCaseCheck(TObject *Sender);
    void __fastcall btnTestClick(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall btnTestAllClick(TObject *Sender);
    void __fastcall btnTestDVBClick(TObject *Sender);
    void __fastcall btnTestWmWiFiClick(TObject *Sender);
    void __fastcall btnTestNVRAMClick(TObject *Sender);
        void __fastcall HWTestClick(TObject *Sender);
        void __fastcall ClearInfoClick(TObject *Sender);
        void __fastcall btnReceiverClick(TObject *Sender);
        void __fastcall btnSpeakerLClick(TObject *Sender);
        void __fastcall btnSpeakerRClick(TObject *Sender);
        void __fastcall btnPassClick(TObject *Sender);
        void __fastcall btnFailClick(TObject *Sender);
        void __fastcall btnEnATMClick(TObject *Sender);
        void __fastcall btnDisATMClick(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
    AnsiString  TestResultStr;
    bool TestResult;
    HW_TEST_HANDLE m_hwTestHandle;
public:		// User declarations
    __fastcall TfrmUnitTest(TComponent* Owner);
    void  ShowHintLabel( TControl *sender, char* hint );
    void _fastcall SubClassWndProc( Messages::TMessage &Message);
    void AddStatusBarString(int testType, char *strInfo);
    HwTest m_HwTestObj;
    void enableBtnAuto();
    void disableBtnAuto();
    void enableBtnManual();
    void disableBtnManual();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmUnitTest *frmUnitTest;
//---------------------------------------------------------------------------
#endif
