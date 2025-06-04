//---------------------------------------------------------------------------

#ifndef form_NFC_RawCommandH
#define form_NFC_RawCommandH
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
class TfrmNFCRawCommand : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbNFC_RawCommand;
    TLabel *lblNFC_TD_RC_Datas;
    TMemo *mmNFC_TD_RC;
    TButton *btnNFC_Write;
    void __fastcall btnNFC_WriteClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
public:		// User declarations
    __fastcall TfrmNFCRawCommand(TComponent* Owner);
    void CurrentPageLock();
    void CurrentPageReset();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNFCRawCommand *frmNFCRawCommand;
//---------------------------------------------------------------------------
#endif
