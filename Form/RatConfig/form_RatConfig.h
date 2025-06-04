//---------------------------------------------------------------------------

#ifndef form_RatConfigH
#define form_RatConfigH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>


#ifndef  _RATCONFIG_MAN_H_
#include "rat_config_man.h"
#endif
//---------------------------------------------------------------------------
class TfrmRatConfig : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBoxRATConfig;
    TLabel *LabelCurRAT;
    TButton *BtnUpdate;
    TStatusBar *m_sbRATStatus;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall BtnUpdateClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    TRadioButton **m_ppRadioBtn;
    int m_nRadioBtnNum;
    int m_nRadioBtnFreeNum;
    CRatConfigMan m_RatConfig_Man_Obj;
    void Init( void );
    void FreeRadioResource(void);
public:		// User declarations
    __fastcall TfrmRatConfig(TComponent* Owner);
public:


};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRatConfig *frmRatConfig;
//---------------------------------------------------------------------------
#endif
