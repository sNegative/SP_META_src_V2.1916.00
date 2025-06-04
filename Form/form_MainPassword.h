//---------------------------------------------------------------------------

#ifndef form_MainPasswordH
#define form_MainPasswordH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmMainPassword : public TForm
{
__published:	// IDE-managed Components
    TEdit *edtPassword;
    TButton *btnVerifyOK;
    TButton *btnVerifyCancel;
    void __fastcall btnVerifyOKClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnVerifyCancelClick(TObject *Sender);
private:	// User declarations
    AnsiString m_InputStr;
    bool m_Success;
    bool m_OkPressed;
public:		// User declarations
    __fastcall TfrmMainPassword(TComponent* Owner);
    AnsiString * GetPassword(void);
    bool GetPasswordResult(void);
    bool GetOkPressed(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMainPassword *frmMainPassword;
//---------------------------------------------------------------------------
#endif
