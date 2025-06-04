//---------------------------------------------------------------------------

#ifndef form_NFC_TagAccessType1H
#define form_NFC_TagAccessType1H
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
class TfrmNFCTagAccessType1 : public TForm
{
__published:	// IDE-managed Components
    TButton *btnNFC_Write;
    TStatusBar *sbNFC_TagAccess;
    TEdit *edtNFC_Byte0;
    TLabel *lblNFC_TD_RdTag_Type2_Byte0;
    TEdit *edtNFC_Byte1;
    TLabel *lblNFC_TD_RdTag_Type2_Byte1;
    TEdit *edtNFC_Byte2;
    TLabel *lblNFC_TD_RdTag_Type2_Byte2;
    TEdit *edtNFC_Byte3;
    TLabel *lblNFC_TD_RdTag_Type2_Byte3;
    TLabel *edtNFC_Datas;
    TComboBox *cbNFC_PageAddress;
    TLabel *lblNFC_PageAddress;
    TButton *btnNFC_Read;
    void __fastcall btnNFC_ReadClick(TObject *Sender);
    void __fastcall btnNFC_WriteClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
    TEdit *edtNFC_Byte[MIFARE1K_LEN];
public:		// User declarations
    __fastcall TfrmNFCTagAccessType1(TComponent* Owner);
    void CurrentPageLock();
    void CurrentPageReset();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNFCTagAccessType1 *frmNFCTagAccessType1;
//---------------------------------------------------------------------------
#endif
