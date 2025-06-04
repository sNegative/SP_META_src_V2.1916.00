//---------------------------------------------------------------------------

#ifndef form_MultiSIMH
#define form_MultiSIMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#ifndef  _MSIM_MAN_H_
#include "msim_man.h"
#endif
//---------------------------------------------------------------------------
class TfrmMultiSIM : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *m_sbMultiSIMStatus;
        TGroupBox *GroupBoxMSIM;
        TButton *btnMSIMUpdate;
        TRadioButton *radioBtnDsds;
        TRadioButton *radioBtnSs;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btnMSIMUpdateClick(TObject *Sender);
private:	// User declarations
    CMSIMMan m_MSIM_Man_Obj;
public:		// User declarations
        __fastcall TfrmMultiSIM(TComponent* Owner);
        void Init( void );
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMultiSIM *frmMultiSIM;
//---------------------------------------------------------------------------
#endif
