//---------------------------------------------------------------------------

#ifndef form_GPSCWAutoTestH
#define form_GPSCWAutoTestH
#ifndef form_GPSH
#include "form_GPS.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#endif
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmGPSAutoTest : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *EDAutoTestNum;
    TLabel *Label2;
    TButton *BtnCWLogPath;
    TStaticText *stAutoTestFilePath;
    TButton *BtnOk;
    TButton *BtnCancel;
    TStaticText *lblHint;
    TTimer *HintTimer;
    TSaveDialog *SaveDialogCWLog;
    void __fastcall BtnCWLogPathClick(TObject *Sender);
    void __fastcall BtnOkClick(TObject *Sender);
    void __fastcall BtnCancelClick(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall EDAutoTestNumExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmGPSAutoTest(TComponent* Owner);
    void ShowHintLabel( TControl *sender, char* hint );
    int  m_nCWAutoTestNum;
    char m_strAutoTestFilePath[GPS_CW_TEST_FILE_PATH_LEN];
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGPSAutoTest *frmGPSAutoTest;
//---------------------------------------------------------------------------
#endif
