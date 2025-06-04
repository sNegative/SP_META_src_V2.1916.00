//---------------------------------------------------------------------------

#ifndef form_NFC_TagAccessType2H
#define form_NFC_TagAccessType2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

// man
#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif
//---------------------------------------------------------------------------
class TfrmNFCTagAccessType2 : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbNFC_TagAccess;
    TLabel *lblNFC_Sector;
    TComboBox *cbNFC_Sector;
    TLabel *lblNFC_Block;
    TComboBox *cbNFC_Block;
    TGroupBox *gbNFC_AuthKey;
    TRadioButton *rbNFC_AuthKey_B;
    TRadioButton *rbNFC_AuthKey_A;
    TLabel *edtNFC_Datas;
    TLabel *lblNFC_TD_RdTag_Type2_Byte0;
    TEdit *edtNFC_Byte0;
    TEdit *edtNFC_Byte1;
    TEdit *edtNFC_Byte2;
    TLabel *lblNFC_TD_RdTag_Type2_Byte1;
    TLabel *lblNFC_TD_RdTag_Type2_Byte2;
    TEdit *edtNFC_Byte3;
    TLabel *lblNFC_TD_RdTag_Type2_Byte3;
    TEdit *edtNFC_Byte4;
    TLabel *lblNFC_TD_RdTag_Type2_Byte04;
    TEdit *edtNFC_Byte5;
    TLabel *lblNFC_TD_RdTag_Type2_Byte5;
    TLabel *lblNFC_TD_RdTag_Type2_Byte6;
    TEdit *edtNFC_Byte6;
    TEdit *edtNFC_Byte7;
    TLabel *lblNFC_TD_RdTag_Type2_Byte7;
    TLabel *lblNFC_TD_RdTag_Type2_Byte15;
    TEdit *edtNFC_Byte15;
    TEdit *edtNFC_Byte14;
    TLabel *lblNFC_TD_RdTag_Type2_Byte14;
    TEdit *edtNFC_Byte13;
    TLabel *lblNFC_TD_RdTag_Type2_Byte13;
    TEdit *edtNFC_Byte12;
    TLabel *lblNFC_TD_RdTag_Type2Byte12;
    TLabel *lblNFC_TD_RdTag_Type2_Byte11;
    TEdit *edtNFC_Byte11;
    TEdit *edtNFC_Byte10;
    TLabel *lblNFC_TD_RdTag_Type2_Byte10;
    TEdit *edtNFC_Byte9;
    TLabel *lblNFC_TD_RdTag_Type2_Byte9;
    TLabel *lblNFC_TD_RdTag_Type2_Byte8;
    TEdit *edtNFC_Byte8;
    TButton *btnNFC_Read;
    TButton *btnNFC_Write;
    void __fastcall btnNFC_ReadClick(TObject *Sender);
    void __fastcall btnNFC_WriteClick(TObject *Sender);
    void __fastcall rbNFC_AuthKey_AClick(TObject *Sender);
    void __fastcall rbNFC_AuthKey_BClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
//#if 0
    TEdit * edtNFC_Byte[MIFARE4K_LEN];
//#endif
public:		// User declarations
    __fastcall TfrmNFCTagAccessType2(TComponent* Owner);
    void CurrentPageLock();
    void CurrentPageReset();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNFCTagAccessType2 *frmNFCTagAccessType2;
//---------------------------------------------------------------------------
#endif
