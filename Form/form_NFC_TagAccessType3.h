//---------------------------------------------------------------------------

#ifndef form_NFC_TagAccessType3H
#define form_NFC_TagAccessType3H
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
class TfrmNFCTagAccessType3 : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbNFC_TagAccess;
    TGroupBox *gbNFC_Info;
    TLabel *lblNFC_TD_RdTag_RecFlags;
    TStaticText *stNFC_TD_RdTag_RecFlags;
    TLabel *Label1;
    TStaticText *stNFC_TD_RdTag_TagType;
    TStaticText *stNFC_TD_RdTag_Lang;
    TLabel *Label2;
    TStaticText *stNFC_TD_RdTag_RecId;
    TLabel *lblNFC_TD_RdTag_RecId;
    TLabel *lblNFC_TD_RdTag_RecTnf;
    TStaticText *stNFC_TD_RdTag_RecTnf;
    TStaticText *stNFC_TD_RdTag_PayLoadLen;
    TLabel *lblNFC_TD_RdTag_PayLoadLen;
    TLabel *lblNFC_TD_RdTag_PayLoad;
    TLabel *lblNFC_TD_RdTag_Hex;
    TStaticText *stNFC_TD_RdTag_Hex;
    TLabel *lblNFC_TD_RdTag_ACSII;
    TStaticText *stNFC_TD_RdTag_ACSII;
    TGroupBox *gbNFC_Outpot;
    TMemo *mmNFC_TD_WrTag;
    TButton *btnNFC_Write;
    void __fastcall btnNFC_WriteClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
public:		// User declarations
    __fastcall TfrmNFCTagAccessType3(TComponent* Owner);
    void CurrentPageLock();
    void CurrentPageReset();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNFCTagAccessType3 *frmNFCTagAccessType3;
//---------------------------------------------------------------------------
#endif
