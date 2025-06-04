//---------------------------------------------------------------------------

#ifndef _FORM_WMMETATEST_H_
#define _FORM_WMMETATEST_H_
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Wm_Metatest.h"
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TfrmWmMetaTest : public TForm
{
__published:	// IDE-managed Components
    TButton *btnSum;
    TButton *btnQueryIfTargetSupportDVBH;
    TButton *btnActiveTimer;
    TButton *btnWriteFile;
    TButton *btnReadFile;
    TEdit *editSum;
    TEdit *editQueryIfTargetSupportDVBH;
    TEdit *editActiveTimer;
    TEdit *editWriteFile;
    TEdit *editReadFile;
    TTimer *tTimerControl;
    TButton *btnUnitTest;
    void __fastcall btnSumClick(TObject *Sender);
    void __fastcall btnQueryIfTargetSupportDVBHClick(TObject *Sender);
    void __fastcall btnActiveTimerClick(TObject *Sender);
    void __fastcall btnWriteFileClick(TObject *Sender);
    void __fastcall btnReadFileClick(TObject *Sender);
    void __fastcall ControlChange(TObject *Sender);
    void __fastcall btnUnitTestClick(TObject *Sender);

private:	// User declarations
    CWMMETATEST    WM_METATEST_Object;
    bool m_bTimerControlChange;

public:		// User declarations
    __fastcall TfrmWmMetaTest(TComponent* Owner);
    // call back
    void CNF_WmCmdSum( void );
    void CNF_WmCmdQueryIfTargetSupportDvbh( void );
    void CNF_WmCmdActiveTimer( void );
    void CNF_WmCmdWriteFile( void );
    void CNF_WmCmdReadFile( void );

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWmMetaTest *frmWmMetaTest;
//---------------------------------------------------------------------------
#endif

