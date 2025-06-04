//---------------------------------------------------------------------------

#ifndef form_NFC_TagDetectedH
#define form_NFC_TagDetectedH
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
class TfrmNFCTagDetected : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbNFC_TagDetected;
    TGroupBox *gbNFC_TD_Info;
    TLabel *lblNFC_TD_MaxDataRate;
    TLabel *lblNFC_TD_AppData;
    TLabel *lblNFC_TD_AtqA;
    TLabel *lblNFC_TD_Sak;
    TLabel *lblNFC_TD_Uid;
    TLabel *lblNFC_TD_CardType;
    TStaticText *stNFC_TD_CardType;
    TStaticText *stNFC_TD_Uid;
    TStaticText *stNFC_TD_AtqA;
    TStaticText *stNFC_TD_AppData;
    TStaticText *stNFC_TD_MaxDataRate;
    TStaticText *stNFC_TD_Sak;
    TButton *btnNFC_TD_RdWr;
    TButton *btnNFC_TD_RawCommand;
    TButton *btnNFC_TD_Disconnect;
    TButton *btnNFC_TD_FormatToNDEF;
    TLabel *lblNFC_TD_Protocol;
    TStaticText *stNFC_TD_Protocol;
    TLabel *lblNFC_TD_TagDetected;
    TStaticText *stNFC_TD_TagType;
    void __fastcall btnNFC_TD_RdWrClick(TObject *Sender);
    void __fastcall btnNFC_TD_RawCommandClick(TObject *Sender);
    void __fastcall btnNFC_TD_DisconnectClick(TObject *Sender);
    void __fastcall btnNFC_TD_FormatToNDEFClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
public:		// User declarations
    __fastcall TfrmNFCTagDetected(TComponent* Owner);

    void CurrentPageLock();
    void CurrentPageReset();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNFCTagDetected *frmNFCTagDetected;
//---------------------------------------------------------------------------
#endif
