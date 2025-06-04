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
 *   form_UnitTest.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  Unit test form source
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
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
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
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_UnitTest.h"
#include "meta.h"

#ifndef  _MISC_UT_H_
#include "misc_ut.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmUnitTest *frmUnitTest;

#define NVRAM_STRESS_TEST_UTID 2015

static AnsiString hw_test_api[HWT_AUTO_TEST_ITEM_NUM+1] =
    {
        "SP_META_GetTargetVerInfo_r",  /*41002*/
        "SP_META_WiFi_readMCR32_r",/*11002*/
        "SP_META_BT_SendHCICommand_r",  /*13004*/
        "SP_META_FM_PowerOn_r",  /*14002*/
        "SP_META_FM_PowerOff_r",  /*14010*/
        "SP_META_GPS_Open_r",  /*12001*/
        "SP_META_GPS_Close_r",  /*12003*/
        "SP_META_CancelAllBlockingCall_r",/**/ 
        "SP_META_GS_Read_Raw_r",  /*51001*/
        "SP_META_Audio_LoudSpkL_Test_r",  /*21001*/ 
        "SP_META_Audio_LoudSpkR_Test_r",  /*21001*/
        "SP_META_Audio_Receiver_Test_r",  /*21002*/ 
        "SP_META_MSensorTest_r",  /*52001*/
        "SP_META_SDCARD_Query_r",/*71001*/
        "SP_META_Audio_GetSupportAfeRegAccess_r",  /**/
        "SP_META_CTPTest_r",  /*91001*/ 
        "SP_META_GYRO_Read_Raw_r",  /**/
        "SP_META_ALSPSTest_r",  /*53001*/
        ""
    };
//---------------------------------------------------------------------------
__fastcall TfrmUnitTest::TfrmUnitTest(TComponent* Owner)
    : TForm(Owner)
{
    TestResult = true;
    WindowProc = SubClassWndProc;
    HWTestInfo->Text = "";
    TestPassNum = 0;
}
//---------------------------------------------------------------------------
void _fastcall TfrmUnitTest::SubClassWndProc( Messages::TMessage &Message)
{
    int state = Message.Msg;
    //int testType = Message.LParam;
    E_HWT_AUTO_ITEM_TYPE type = (E_HWT_AUTO_ITEM_TYPE)(Message.WParam);
    switch (state)
    {
    case WM_META_HWT_SUCCESS:
        TestPassNum++;
        AddStatusBarString(type, " Success");
        break;
    case WM_META_HWT_FAILED:
        TestResult = false;
        AddStatusBarString(type, " Fail");
        break;
    case WM_META_HWT_TIMEOUT:
        TestResult = false;
        AddStatusBarString(type, " Time out");
        break;
    case WM_META_HWT_FINISHED:
        AddStatusBarString(type, " Finished");
        enableBtnAuto();   
        if (TestResult)
        {
            Application->MessageBoxA("All Pass!", "SUCCESS", MB_OK);
        } else {
            Application->MessageBoxA("some cases Failed! please check", "FAIL", MB_OK);
        }
        break;
    case WM_META_HWT_NO_SD_CARD:
        TestResult = false;
        AddStatusBarString(type, " No SD Card or Fail");
        break;
    default:
        this->WndProc( Message );
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmUnitTest::AddStatusBarString(int testType, char *strInfo)
{
    TestResultStr += hw_test_api[testType];
    LOG("hw_test_api[%d] is %s", testType, hw_test_api[testType]);
    TestResultStr += " : ";
    TestResultStr += strInfo;  
    TestResultStr += "\r\n";
    HWTestInfo->Text = TestResultStr;
}
//---------------------------------------------------------------------------
void  TfrmUnitTest::ShowHintLabel( TControl *sender, char* hint )
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
void __fastcall TfrmUnitTest::edtTestCaseCheck(TObject *Sender)
{
    unsigned int  ui_data;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[256] =
    {
        " value is not valid "
    };

    text = edit->Text;
    if( !IsValidTestCaseID( text, ui_data ) )
    {
        edit->Text = IntToStr( 0 );
        ShowHintLabel( edit, hint );
        edit->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmUnitTest::btnTestClick(TObject *Sender)
{
    unsigned int TestCaseID;
    TestCaseID = edtTestCase->Text.ToInt();
    if(TestCaseID == NVRAM_STRESS_TEST_UTID)
        btnTestNVRAM->Click();
    else
    SP_META_UnitTest(&TestCaseID, 1);
}
//---------------------------------------------------------------------------
void __fastcall TfrmUnitTest::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmUnitTest::btnTestAllClick(TObject *Sender)
{
    WM_META_UT_TestCaseID_T  *pTestCase = NULL;
    unsigned int TestCaseCount = 0;

    SP_META_QueryTestCase(&pTestCase, &TestCaseCount);
    if(!pTestCase || 0 == TestCaseCount)
        return;

    unsigned int *p_TestCaseID_Array = new unsigned int[TestCaseCount];
    if(!p_TestCaseID_Array)
        return;
    for(unsigned int i = 0; i < TestCaseCount; i++)
    {
        p_TestCaseID_Array[i] = pTestCase[i].m_TestCaseID;
    }

    SP_META_UnitTest(p_TestCaseID_Array, TestCaseCount);

    delete []p_TestCaseID_Array;
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnTestDVBClick(TObject *Sender)
{
    for(unsigned int TestCaseID = 12; TestCaseID < 27; TestCaseID++)
    {
        SP_META_UnitTest(&TestCaseID, 1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnTestWmWiFiClick(TObject *Sender)
{
    for(unsigned int TestCaseID = 28; TestCaseID < 60; TestCaseID++)
    {
        SP_META_UnitTest(&TestCaseID, 1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnTestNVRAMClick(TObject *Sender)
{
    frmNVRAMEditor->Show();
    frmNVRAMEditor->ReadWriteStressTest();
    frmNVRAMEditor->Hide();
}
//---------------------------------------------------------------------------
void TfrmUnitTest::disableBtnAuto()
{
    HWTest->Enabled = false;
    btnSpeakerL->Enabled = false;
    btnSpeakerR->Enabled = false;
    btnReceiver->Enabled = false;
    btnPass->Enabled = false;
    btnFail->Enabled = false;
    ClearInfo->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmUnitTest::enableBtnAuto()
{
    HWTest->Enabled = true;
    btnSpeakerL->Enabled = true;
    btnSpeakerR->Enabled = true;
    btnReceiver->Enabled = true;
    btnPass->Enabled = true;
    btnFail->Enabled = true;
    ClearInfo->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::ClearInfoClick(TObject *Sender)
{
    HWTestInfo->Text = "";
    TestResultStr = "";
}

//---------------------------------------------------------------------------
void TfrmUnitTest::disableBtnManual()
{
    HWTest->Enabled = false;
    btnSpeakerL->Enabled = false;
    btnSpeakerR->Enabled = false;
    btnReceiver->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmUnitTest::enableBtnManual()
{
    HWTest->Enabled = true;
    btnSpeakerL->Enabled = true;
    btnSpeakerR->Enabled = true;
    btnReceiver->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::HWTestClick(TObject *Sender)
{
    TestResultStr = "";
    TestPassNum = 0;
    TestResult = true;
    disableBtnAuto();
    m_HwTestObj.TestAllReq(0);
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnReceiverClick(TObject *Sender)
{
    disableBtnManual();
    m_HwTestObj.TestAllReq(3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnSpeakerLClick(TObject *Sender)
{
    disableBtnManual();
    m_HwTestObj.TestAllReq(1);
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnSpeakerRClick(TObject *Sender)
{
    disableBtnManual();
    m_HwTestObj.TestAllReq(2);
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnPassClick(TObject *Sender)
{
    enableBtnManual();
    E_HWT_AUTO_ITEM_TYPE index = m_HwTestObj.getTestIndex(); 
    m_HwTestObj.TestAllReq(4);
    PostMessage(this->Handle,WM_META_HWT_SUCCESS,index,0);
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnFailClick(TObject *Sender)
{
    enableBtnManual();
    E_HWT_AUTO_ITEM_TYPE index = m_HwTestObj.getTestIndex();
    m_HwTestObj.TestAllReq(4);
    PostMessage(this->Handle,WM_META_HWT_FAILED,index,0);
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnEnATMClick(TObject *Sender)
{
    SET_ATM_FLAG_REQ req;
    SET_ATM_FLAG_CNF cnf;
    req.flag = 1;
    META_RESULT mr = SP_META_Set_ATMFlag_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, &req, &cnf);
    if(mr == META_SUCCESS)
    {
        Application->MessageBox( "Enable ATM Success!", "Notice", MB_OK );
    }
    else
    {
        Application->MessageBox( "Enable ATM Fail!", "Notice", MB_OK );
    }

}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitTest::btnDisATMClick(TObject *Sender)
{
    SET_ATM_FLAG_REQ req;
    SET_ATM_FLAG_CNF cnf;
    req.flag = 0;
    META_RESULT mr = SP_META_Set_ATMFlag_r(m_META_HANDLE_Obj.Get_MainHandle(), 500, &req, &cnf);
    if(mr == META_SUCCESS)
    {
        Application->MessageBox( "Disable ATM Success!", "Notice", MB_OK );
    }
    else
    {
        Application->MessageBox( "Disable ATM Fail!", "Notice", MB_OK );
    }
}
//---------------------------------------------------------------------------

