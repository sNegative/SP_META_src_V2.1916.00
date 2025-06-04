//---------------------------------------------------------------------------

#ifndef form_5GHz_TX_Power_ProfileH
#define form_5GHz_TX_Power_ProfileH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include "man_handle.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class Tfrm5GHz_TX_Power_Profile : public TForm
{
__published:	// IDE-managed Components
    TListView *m_lv5GHz_TX_Power_Register;
    TEdit *m_edt5GHz_TX_Power_Register;
    TGroupBox *GroupBox1;
    TComboBox *m_cb5GHz_TX_Power_Compensation;
    TListView *m_lv5GHz_TX_Power_Compensation;
    TButton *m_btnReadFromNVRAM;
    TButton *m_btnWriteToNVRAM;
    TStatusBar *m_sb5GH;
    TComboBox *m_cb5GH_TX_Power_Compensation_Edit;
    TGroupBox *GroupBox5GHzBandEdgeLimit;
    TComboBox *m_cb5GH_TX_Power_FCC;
    TListView *m_lv5GH_TX_Power_FCC;
    TEdit *m_edt5GH_TX_Power_FCC;
    TGroupBox *GroupBox2;
    TListView *m_lv5GH_TX_Power_BackOff;
    TEdit *m_edt5GH_TX_Power_BackOff;
    TComboBox *m_cb5GH_TX_Power_BackOff;
        TTabControl *m_tc5GH_TX_Power_Compensation;
        TListView *m_lv5GTXPowerCom;
        TComboBox *m_cb5GEnable;
        TComboBox *m_cb_5GHTXPowerCompEdit;
        TComboBox *m_cb_5GH_EnableEdit;
        TButton *m_btn5GWriteToNvram_MT6632;
    void __fastcall m_lv5GHz_TX_Power_RegisterClick(
        TObject *Sender);
    void __fastcall m_lv5GHz_TX_Power_CompensationClick(
        TObject *Sender);
    void __fastcall m_edt5GHz_TX_Power_RegisterExit(
        TObject *Sender);
    void __fastcall m_btnWriteToNVRAMClick(TObject *Sender);
    void __fastcall m_btnReadFromNVRAMClick(TObject *Sender);
    void __fastcall m_cb5GH_TX_Power_Compensation_EditChange(
        TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall m_lv5GHz_TX_Power_RegisterAdvancedCustomDrawSubItem(
        TCustomListView *Sender, TListItem *Item, int SubItem,
        TCustomDrawState State, TCustomDrawStage Stage,
        bool &DefaultDraw);
    void __fastcall m_lv5GHz_TX_Power_CompensationAdvancedCustomDrawSubItem(
        TCustomListView *Sender, TListItem *Item, int SubItem,
        TCustomDrawState State, TCustomDrawStage Stage,
        bool &DefaultDraw);
    void __fastcall m_lv5GH_TX_Power_FCCClick(TObject *Sender);
    void __fastcall m_lv5GH_TX_Power_FCCAdvancedCustomDrawSubItem(
          TCustomListView *Sender, TListItem *Item, int SubItem,
          TCustomDrawState State, TCustomDrawStage Stage,
          bool &DefaultDraw);
    void __fastcall m_edt5GH_TX_Power_FCCExit(TObject *Sender);
    void __fastcall m_edt5GH_TX_Power_BackOffExit(TObject *Sender);
    void __fastcall m_lv5GH_TX_Power_BackOffClick(TObject *Sender);
        void __fastcall m_lv5GTXPowerComClick(TObject *Sender);
        void __fastcall m_cb_5GHTXPowerCompEditExit(TObject *Sender);
        void __fastcall m_cb_5GH_EnableEditExit(TObject *Sender);
        void __fastcall m_tc5GH_TX_Power_CompensationChange(
          TObject *Sender);
        void __fastcall m_btn5GWriteToNvram_MT6632Click(TObject *Sender);
private:	// User declarations
    TListView * m_clickListView;
    int m_subItemIndex;
    CMETAHANDLE m_META_HANDLE_Obj;
    unsigned long m_wifiChipVersion;
    bool m_bDisplayTXPowerBackOff;
    void CheckDisplayTXPowerBackOff();
public:		// User declarations
    __fastcall Tfrm5GHz_TX_Power_Profile(TComponent* Owner);
    
    void __fastcall Update_5GTX_Power_Compensation_MT6632();
    void __fastcall Update_5GTX_Power_Register();
    void __fastcall Update_5GTX_Power_Compensation();
    void __fastcall Update_5GTX_Power_FCC();
    void __fastcall Update_5GTX_Power_BackOff();

    void __fastcall Download_5GTX_Power_Register();
    void __fastcall Download_5GTX_Power_Compensation();
    void __fastcall Download_5GTX_Power_FCC();
    void __fastcall Download_5GTX_Power_BackOff();
    void __fastcall Download_5GTX_Power_Compensation_MT6632();
    
    void Init(void);

    void CurrentPageLock();
    void CurrentPageReset();
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm5GHz_TX_Power_Profile *frm5GHz_TX_Power_Profile;
//---------------------------------------------------------------------------
#endif
