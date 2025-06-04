//---------------------------------------------------------------------------

#ifndef form_2GH_TX_Power_ProfileH
#define form_2GH_TX_Power_ProfileH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>


//#ifndef META_DLL_H
//#include "meta.h"
//#endif

#include "man_handle.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class Tfrm2GH_TX_Power_Profile : public TForm
{
__published:	// IDE-managed Components
    TListView *m_lv2GH_TX_Power_Register;
    TListView *m_lv2GH_TX_Power_Compensation;
    TListView *m_lv2GH_TX_Power_FCC;
    TGroupBox *GroupBox1;
    TComboBox *m_cb2GH_TX_Power_Compensation;
    TComboBox *m_cb2GH_TX_Power_FCC;
    TGroupBox *GroupBox2;
    TButton *m_btnReadFromNVRAM;
    TButton *m_btnWriteToNVRAM;
    TStatusBar *m_sb2GH;
    TComboBox *m_cb2GH_TX_Power_Compensation_Edit;
    TEdit *m_edt2GH_TX_Power_Register;
    TEdit *m_edt2GH_TX_Power_FCC;
    TGroupBox *GroupBox3;
    TComboBox *m_cb2GH_TX_Power_Compensation_AllChannel;
    TListView *m_lv2GH_TX_Power_CompensationAllChannel;
    TComboBox *m_cb2GH_TX_Power_Compensation_AllChannel_Edit;
    TGroupBox *GroupBox4;
    TComboBox *m_cb2GH_TX_Power_BackOff;
    TListView *m_lv2GH_TX_Power_BackOff;
    TEdit *m_edt2GH_TX_Power_BackOff;
    TGroupBox *GroupBox5;
    TListView *m_lv2GH_TX_Power_Offset;
    TEdit *m_edt2GHTX_Power_Offset;
        TTabControl *m_tc2GH_TX_Power_Compensation;
        TListView *m_lvTXPowerCom;
        TComboBox *m_cbEnable;
        TComboBox *m_cb_2GHTXPowerCompEdit;
        TComboBox *m_cb_2GH_EnableEdit;
        TButton *m_btnWriteToNvram_MT6632;
    void __fastcall m_edt2GH_TX_Power_RegisterExit(TObject *Sender);
    void __fastcall m_lv2GH_TX_Power_RegisterClick(TObject *Sender);
    void __fastcall m_lv2GH_TX_Power_CompensationClick(TObject *Sender);
    void __fastcall m_lv2GH_TX_Power_Compensation_AllChannel_Click(TObject *Sender);
    void __fastcall m_lv2GH_TX_Power_FCCClick(TObject *Sender);
    void __fastcall m_btnReadFromNVRAMClick(TObject *Sender);
    void __fastcall m_cb2GH_TX_Power_Compensation_EditChange(
        TObject *Sender);
    void __fastcall m_cb2GH_TX_Power_Compensation_AllChannel_EditChange(
        TObject *Sender);
    void __fastcall m_btnWriteToNVRAMClick(TObject *Sender);
    void __fastcall m_edt2GH_TX_Power_FCCExit(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall m_lv2GH_TX_Power_RegisterAdvancedCustomDrawSubItem(
        TCustomListView *Sender, TListItem *Item, int SubItem,
        TCustomDrawState State, TCustomDrawStage Stage,
        bool &DefaultDraw);
    void __fastcall m_lv2GH_TX_Power_CompensationAdvancedCustomDrawSubItem(
        TCustomListView *Sender, TListItem *Item, int SubItem,
        TCustomDrawState State, TCustomDrawStage Stage,
        bool &DefaultDraw);
    void __fastcall m_lv2GH_TX_Power_Compensation_AllChannel_AdvancedCustomDrawSubItem(
        TCustomListView *Sender, TListItem *Item, int SubItem,
        TCustomDrawState State, TCustomDrawStage Stage,
        bool &DefaultDraw);
    void __fastcall m_lv2GH_TX_Power_FCCAdvancedCustomDrawSubItem(
        TCustomListView *Sender, TListItem *Item, int SubItem,
        TCustomDrawState State, TCustomDrawStage Stage,
        bool &DefaultDraw);
    void __fastcall m_edt2GH_TX_Power_BackOffExit(TObject *Sender);
    void __fastcall m_lv2GH_TX_Power_BackOffClick(TObject *Sender);
    void __fastcall m_lv2GH_TX_Power_OffsetClick(TObject *Sender);
    void __fastcall m_edt2GHTX_Power_OffsetExit(TObject *Sender);
        void __fastcall m_lvTXPowerComClick(TObject *Sender);
        void __fastcall m_cb_2GHTXPowerCompEditChange(TObject *Sender);
        void __fastcall m_cb_2GH_EnableEditChange(TObject *Sender);
        void __fastcall m_tc2GH_TX_Power_CompensationChange(
          TObject *Sender);
        void __fastcall m_btnWriteToNvram_MT6632Click(TObject *Sender);

        
private:	// User declarations
//    TListView * m_clickListView;
//    int m_subItemIndex;
    CMETAHANDLE m_META_HANDLE_Obj;
    unsigned long m_wifiChipVersion;
    bool m_bDisplayTXPowerBackOff;
    void CheckDisplayTXPowerBackOff();

    void __fastcall Update_TX_Power_Register();
    void __fastcall Update_TX_Power_Compensation();
    void __fastcall Update_TX_Power_Compensation_AllChannels();
    void __fastcall Update_TX_Power_Compensation_MT6632();
    void __fastcall Update_TX_Power_FCC();

    void __fastcall Download_TX_Power_Register();
    void __fastcall Download_TX_Power_Compensation();
    void __fastcall Download_TX_Power_Compensation_AllChannels();
    void __fastcall Download_TX_Power_FCC();
    void __fastcall Download_TX_Power_BackOff();
    void __fastcall Download_TX_Power_Compensation_MT6632();
    int flag_6632;
public:		// User declarations
    __fastcall Tfrm2GH_TX_Power_Profile(TComponent* Owner);


    void CurrentPageLock();
    void CurrentPageReset();

};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm2GH_TX_Power_Profile *frm2GH_TX_Power_Profile;
//---------------------------------------------------------------------------
#endif
