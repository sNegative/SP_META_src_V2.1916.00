//---------------------------------------------------------------------------

#ifndef form_WiFi6632RSSICOMPH
#define form_WiFi6632RSSICOMPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

#include "man_handle.h"
//---------------------------------------------------------------------------
class Tfrm6632RSSICOMP : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox6632RSSIComp;
        TGroupBox *GroupBox2GWF0;
        TComboBox *m_cb2GWF0RSSI;
        TListView *m_lv2GWF0RSSI;
        TComboBox *m_edt2GWF0RSSI;
        TGroupBox *GroupBox5GWF0;
        TListView *m_lv5GWF0RSSI;
        TComboBox *m_edt5GWF0RSSI;
        TComboBox *m_cb5GWF0RSSI;
        TGroupBox *GroupBox2GWF1;
        TListView *m_lv2GWF1RSSI;
        TComboBox *m_edt2GWF1RSSI;
        TComboBox *m_cb2GWF1RSSI;
        TGroupBox *GroupBox5GWF1;
        TListView *m_lv5GWF1RSSI;
        TComboBox *m_edt5GWF1RSSI;
        TComboBox *m_cb5GWF1RSSI;
        TButton *m_btnReadFromNVRAM;
        TButton *m_btnWriteToNVRAM;
        TStatusBar *m_sb6632RSSICOMP;
        void __fastcall m_btnReadFromNVRAMClick(TObject *Sender);
        void __fastcall m_btnWriteToNVRAMClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall m_edt2GWF0RSSIExit(TObject *Sender);
        void __fastcall m_edt5GWF0RSSIExit(TObject *Sender);
        void __fastcall m_edt2GWF1RSSIExit(TObject *Sender);
        void __fastcall m_edt5GWF1RSSIExit(TObject *Sender);
        void __fastcall m_lv2GWF0RSSIAdvancedCustomDrawSubItem(
          TCustomListView *Sender, TListItem *Item, int SubItem,
          TCustomDrawState State, TCustomDrawStage Stage,
          bool &DefaultDraw);
        void __fastcall m_lv5GWF0RSSIAdvancedCustomDrawSubItem(
          TCustomListView *Sender, TListItem *Item, int SubItem,
          TCustomDrawState State, TCustomDrawStage Stage,
          bool &DefaultDraw);
        void __fastcall m_lv2GWF1RSSIAdvancedCustomDrawSubItem(
          TCustomListView *Sender, TListItem *Item, int SubItem,
          TCustomDrawState State, TCustomDrawStage Stage,
          bool &DefaultDraw);
        void __fastcall m_lv5GWF1RSSIAdvancedCustomDrawSubItem(
          TCustomListView *Sender, TListItem *Item, int SubItem,
          TCustomDrawState State, TCustomDrawStage Stage,
          bool &DefaultDraw);
        void __fastcall m_lv2GWF0RSSIClick(TObject *Sender);
        void __fastcall m_lv5GWF0RSSIClick(TObject *Sender);
        void __fastcall m_lv2GWF1RSSIClick(TObject *Sender);
        void __fastcall m_lv5GWF1RSSIClick(TObject *Sender);
private:	// User declarations
        void CurrentPageLock();
        void CurrentPageReset();
        CMETAHANDLE m_META_HANDLE_Obj;
public:		// User declarations
        __fastcall Tfrm6632RSSICOMP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm6632RSSICOMP *frm6632RSSICOMP;
//---------------------------------------------------------------------------
#endif
