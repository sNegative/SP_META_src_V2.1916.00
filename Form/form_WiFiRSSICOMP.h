//---------------------------------------------------------------------------

#ifndef form_WiFiRSSICOMPH
#define form_WiFiRSSICOMPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include "man_handle.h"
//---------------------------------------------------------------------------
class TfrmRSSICOMP : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *m_sbRSSICOMP;
    TGroupBox *GroupBoxRSSIComp;
    TComboBox *m_cbRSSI_Compensation;
    TListView *m_lvRSSI_Compensation;
    TComboBox *m_cbRSSI_Compensation_Edit;
    TButton *m_btnReadFromNVRAM;
    TButton *m_btnWriteToNVRAM;
    void __fastcall m_btnReadFromNVRAMClick(TObject *Sender);
    void __fastcall m_btnWriteToNVRAMClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall m_lvRSSI_CompensationAdvancedCustomDrawSubItem(
          TCustomListView *Sender, TListItem *Item, int SubItem,
          TCustomDrawState State, TCustomDrawStage Stage,
          bool &DefaultDraw);
    void __fastcall m_lvRSSI_CompensationClick(TObject *Sender);
    void __fastcall m_cbRSSI_Compensation_EditExit(TObject *Sender);
private:	// User declarations
    void CurrentPageLock();
    void CurrentPageReset();
    CMETAHANDLE m_META_HANDLE_Obj;
public:		// User declarations
    __fastcall TfrmRSSICOMP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRSSICOMP *frmRSSICOMP;
//---------------------------------------------------------------------------
#endif
