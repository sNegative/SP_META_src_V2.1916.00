//---------------------------------------------------------------------------

#ifndef form_DRMKeyH
#define form_DRMKeyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "DRMKey.h"
//---------------------------------------------------------------------------
class TfrmDRMKeyInstall : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TButton *BtnLoadKeyBlockFile;
        TStaticText *stKeyBlockFile;
        TButton *BtnInstall;
        TRichEdit *DRMLog;
        TButton *BtnQueryVerify;
        TStaticText *stDRMInfo;
        TOpenDialog *dlg_OpenKeyBlockFile;
        TButton *BtnClearLog;
        void __fastcall BtnLoadKeyBlockFileClick(TObject *Sender);
        void __fastcall BtnInstallClick(TObject *Sender);
        void __fastcall BtnQueryVerifyClick(TObject *Sender);
        void __fastcall BtnClearLogClick(TObject *Sender);
private:	// User declarations

      //bool m_bOpenKeyBlockFile;
      AnsiString m_file_name;
public:		// User declarations
        __fastcall TfrmDRMKeyInstall(TComponent* Owner);
        void CNF_DRMKeyInstall();
        void CNF_DRMKeyQuery();
        void SetStatusBarString(char *strInfo);

        void OutputLog(char *strInfo);
        void CurrentPageLock(void);
        void CurrentPageReset(void);


        CDRMKEY m_cDRMKey_Obj;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDRMKeyInstall *frmDRMKeyInstall;
//---------------------------------------------------------------------------
#endif
