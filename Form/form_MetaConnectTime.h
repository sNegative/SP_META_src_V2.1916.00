//---------------------------------------------------------------------------

#ifndef form_MetaConnectTiemH
#define form_MetaConnectTiemH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

//---------------------------------------------------------------------------
class TfrmMetaConnectTime : public TForm
{
__published:	// IDE-managed Components
        TButton *btnLoadBootprof;
        TSaveDialog *sdBootprof;
        void __fastcall btnLoadBootprofClick(TObject *Sender);
private:	// User declarations
        CMETAHANDLE m_META_HANDLE_Obj;
public:		// User declarations
        __fastcall TfrmMetaConnectTime(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMetaConnectTime *frmMetaConnectTime;
//---------------------------------------------------------------------------
#endif
