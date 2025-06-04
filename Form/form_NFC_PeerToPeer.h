//---------------------------------------------------------------------------

#ifndef form_NFC_PeerToPeerH
#define form_NFC_PeerToPeerH
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
class TfrmNFCPeerToPeer : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *gbNFC_P2P_Info;
    TLabel *lblNFC_P2P_Type;
    TStaticText *StaticText2;
    TGroupBox *gbNFCP2PText;
    TMemo *mmNFCP2PText;
    TButton *btnNFC_P2P_Send;
    TButton *btnNFC_P2P_Recieve;
    TButton *btnNFC_P2P_Disconnect;
    TStatusBar *sbNFC_PeerToPeer;
    void __fastcall btnNFC_P2P_DisconnectClick(TObject *Sender);
    void __fastcall btnNFC_P2P_SendClick(TObject *Sender);
    void __fastcall btnNFC_P2P_RecieveClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
public:		// User declarations
    __fastcall TfrmNFCPeerToPeer(TComponent* Owner);
    void CurrentPageLock();
    void CurrentPageReset();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNFCPeerToPeer *frmNFCPeerToPeer;
//---------------------------------------------------------------------------
#endif
