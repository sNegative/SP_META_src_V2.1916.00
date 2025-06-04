//---------------------------------------------------------------------------

#ifndef form_AttestationKeyH
#define form_AttestationKeyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "AttestationKey.h"
//---------------------------------------------------------------------------
class TfrmAttestationKeyInstall : public TForm
{
__published:	// IDE-managed Components
        TStaticText *strKeyFile;
        TButton *BtnLoadKeyFile;
        TButton *BtnInstall;
        TOpenDialog *dlg_OpenKeyFile;
        TStaticText *strStatusInfo;
        void __fastcall BtnLoadKeyFileClick(TObject *Sender);
        void __fastcall BtnInstallClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        AnsiString m_file_name;
public:		// User declarations
        __fastcall TfrmAttestationKeyInstall(TComponent* Owner);
        void SetStatusBarString(char *strInfo);
        void CurrentPageLock(void);
        void CurrentPageReset(void);  
        void CNF_AttestationKeyInstall(void);

        CAttestationKey m_AttestationKey_Obj;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAttestationKeyInstall *frmAttestationKeyInstall;
//---------------------------------------------------------------------------
#endif
