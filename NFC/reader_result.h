//---------------------------------------------------------------------------

#ifndef reader_resultH
#define reader_resultH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tfrm_tag_operation : public TForm
{
__published:	// IDE-managed Components
        TLabel *nfc_reader_uid;
        TButton *read_result_read;
        TButton *Read_result_write;
        TButton *read_result_format;
private:	// User declarations
public:		// User declarations
        __fastcall Tfrm_tag_operation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_tag_operation *frm_tag_operation;
//---------------------------------------------------------------------------
#endif
