//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_WmMetaTest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWmMetaTest *frmWmMetaTest;
static void CNF_WmCmdSum( void )
{
    frmWmMetaTest->CNF_WmCmdSum();
}

static void CNF_WmCmdQueryIfTargetSupportDvbh( void )
{
    frmWmMetaTest->CNF_WmCmdQueryIfTargetSupportDvbh();
}

static void CNF_WmCmdActiveTimer( void )
{
    frmWmMetaTest->CNF_WmCmdActiveTimer();
}

static void CNF_WmCmdWriteFile( void )
{
    frmWmMetaTest->CNF_WmCmdWriteFile();
}

static void CNF_WmCmdReadFile( void )
{
    frmWmMetaTest->CNF_WmCmdReadFile();
}
//---------------------------------------------------------------------------
__fastcall TfrmWmMetaTest::TfrmWmMetaTest(TComponent* Owner)
    : TForm(Owner)
{
    //tTimerControl->Enabled = false;
    m_bTimerControlChange = false;
}

//---------------------------------------------------------------------------
void TfrmWmMetaTest::CNF_WmCmdSum(void)
{
    int state = WM_METATEST_Object.Get_ConfirmState();
    if( state == STATE_WM_METATEST_OK )
    {
        editSum->Text = IntToStr(WM_METATEST_Object.cnf_sum.nTestSum);
    }
    else  if( state == STATE_WM_METATEST_FAIL )
    {
        Application->MessageBox( "Execution Fail : WM CMD SUM", "FAIL", MB_OK );
    }
    else
    {
        Application->MessageBox( "Execution XXX : WM CMD SUM", "XXX", MB_OK );
    }
}

void TfrmWmMetaTest::CNF_WmCmdQueryIfTargetSupportDvbh(void)
{
    int state = WM_METATEST_Object.Get_ConfirmState();
    if( state == STATE_WM_METATEST_OK )
    {
        AnsiString as_show = WM_METATEST_Object.cnf_dvbh.bSupportDVBH ? "Don't Support DVBH" : "Support DVBH!";
        editQueryIfTargetSupportDVBH->Text = as_show;
    }
    else  if( state == STATE_WM_METATEST_FAIL )
    {
        Application->MessageBox( "Execution Fail : WM CMD QueryIfTargetSupportDvbh", "FAIL", MB_OK );
    }
    else
    {
        Application->MessageBox( "Execution XXX : WM CMD QueryIfTargetSupportDvbh", "XXX", MB_OK );
    }
}

void TfrmWmMetaTest::CNF_WmCmdActiveTimer(void)
{
    //tTimerControl->Enabled = false;

    int state = WM_METATEST_Object.Get_ConfirmState();
    if( state == STATE_WM_METATEST_OK )
    {
        //AnsiString as_show = "";
        //as_show.cat_sprintf("(%d, %d) ",
        //        WM_METATEST_Object.cnf_activetimer.nRecNum,
        //        WM_METATEST_Object.cnf_activetimer.nMs);
        //editActiveTimer->Text = as_show;
    }
    else  if( state == STATE_WM_METATEST_FAIL )
    {
        Application->MessageBox( "Execution Fail : WM CMD ActiveTimer", "FAIL", MB_OK );
    }
    else
    {
        Application->MessageBox( "Execution XXX : WM CMD ActiveTimer", "XXX", MB_OK );
    }
}

void TfrmWmMetaTest::CNF_WmCmdWriteFile(void)
{
    int state = WM_METATEST_Object.Get_ConfirmState();
    if( state == STATE_WM_METATEST_OK )
    {
        //if(WM_METATEST_Object.cnf_writefile.nCnfWriteFileStatus)
        //{
        AnsiString as_show = "Write file to target: ok";
        editWriteFile->Text = as_show;
        //}

    }
    else  if( state == STATE_WM_METATEST_FAIL )
    {
        Application->MessageBox( "Execution Fail : WM CMD WriteFile", "FAIL", MB_OK );
    }
    else
    {
        Application->MessageBox( "Execution XXX : WM CMD WriteFile", "XXX", MB_OK );
    }
}

void TfrmWmMetaTest::CNF_WmCmdReadFile(void)
{
    int state = WM_METATEST_Object.Get_ConfirmState();
    if( state == STATE_WM_METATEST_OK )
    {
        //if(WM_METATEST_Object.cnf_readfile.notUsed)
        //{
        AnsiString as_show = "Read file from target: ok";
        editReadFile->Text = as_show;
        //}

    }
    else  if( state == STATE_WM_METATEST_FAIL )
    {
        Application->MessageBox( "Execution Fail : WM CMD ReadFile", "FAIL", MB_OK );
    }
    else
    {
        Application->MessageBox( "Execution XXX : WM CMD ReadFile", "XXX", MB_OK );
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmMetaTest::btnSumClick(TObject *Sender)
{
    WM_METATEST_Object.ConfirmCallback = ::CNF_WmCmdSum;
    WM_METATEST_Object.REQ_WmCmdSum();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmMetaTest::btnQueryIfTargetSupportDVBHClick(
    TObject *Sender)
{
    WM_METATEST_Object.ConfirmCallback = ::CNF_WmCmdQueryIfTargetSupportDvbh;
    WM_METATEST_Object.REQ_WmCmdQueryIfTargetSupportDVBH();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmMetaTest::btnActiveTimerClick(TObject *Sender)
{
    //tTimerControl->Enabled = true;
    WM_METATEST_Object.ConfirmCallback = ::CNF_WmCmdActiveTimer;
    WM_METATEST_Object.REQ_WmCmdActiveTimer();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmMetaTest::btnWriteFileClick(TObject *Sender)
{
    WM_METATEST_Object.ConfirmCallback = ::CNF_WmCmdWriteFile;
    WM_METATEST_Object.REQ_WmCmdWriteFile();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmMetaTest::btnReadFileClick(TObject *Sender)
{
    WM_METATEST_Object.ConfirmCallback = ::CNF_WmCmdReadFile;
    WM_METATEST_Object.REQ_WmCmdReadFile();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmMetaTest::ControlChange(TObject *Sender)
{
    //if(0 == WM_METATEST_Object.cnf_activetimer.nRecNum)
    //    return;
    AnsiString as_show = "";
    as_show.cat_sprintf("(%d, %d) ",
                        WM_METATEST_Object.cnf_activetimer.nRecNum,
                        WM_METATEST_Object.cnf_activetimer.nMs);
    editActiveTimer->Text = as_show;
}
void __fastcall TfrmWmMetaTest::btnUnitTestClick(TObject *Sender)
{
    unsigned int nArrayTest[5]= {1077, 1078, 1079, 1080, 1081};
    const unsigned int *pArrayTest = nArrayTest;
//    META_UnitTest(pArrayTest, 5);
}
//---------------------------------------------------------------------------

