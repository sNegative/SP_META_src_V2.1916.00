//---------------------------------------------------------------------------

#ifndef form_Crystal_TrimH
#define form_Crystal_TrimH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>


#include "man_handle.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmCrystalTrim : public TForm
{
__published:	// IDE-managed Components
    TListView *m_lvCrystal_Trim;
    TGroupBox *GroupBox1;
    TComboBox *m_cbCrystal_Trim;
    TButton *m_btnCrystal_Trim_Read;
    TButton *m_btnCrystal_Trim_Write;
    TEdit *m_edtCrystal_Trim;
    TStatusBar *m_sbCrystallTrim;
    void __fastcall m_btnCrystal_Trim_ReadClick(TObject *Sender);
    void __fastcall m_btnCrystal_Trim_WriteClick(TObject *Sender);
    void __fastcall m_lvCrystal_TrimClick(TObject *Sender);
    void __fastcall m_edtCrystal_TrimExit(TObject *Sender);
    void __fastcall m_lvCrystal_TrimAdvancedCustomDrawSubItem(
        TCustomListView *Sender, TListItem *Item, int SubItem,
        TCustomDrawState State, TCustomDrawStage Stage,
        bool &DefaultDraw);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
public:		// User declarations
    __fastcall TfrmCrystalTrim(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCrystalTrim *frmCrystalTrim;
//---------------------------------------------------------------------------
#endif
