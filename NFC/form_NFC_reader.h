//---------------------------------------------------------------------------

#ifndef form_NFC_readerH
#define form_NFC_readerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "meta.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif
/* ENUM OF EM_OPT_ACTION */
typedef enum {
   NFC_EM_OPT_ACT_READ = 0,
   NFC_EM_OPT_ACT_WRITE,
   NFC_EM_OPT_ACT_FORMAT, 
   NFC_EM_OPT_ACT_WRITE_RAW
} EM_OPT_ACTION;
//---------------------------------------------------------------------------
class Tform_AIRM_Reader : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *tl_AIRM_Reader_UID;
        TButton *tb_AIRM_NTF_Read;
        TButton *tb_AIRM_NTF_Write;
        TGroupBox *gb_AIRM_Reader_read;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label14;
        TLabel *Label15;
        TEdit *te_AIRM_Reader_recordFlag;
        TEdit *te_AIRM_Reader_recordID;
        TEdit *te_AIRM_Reader_recordInfo;
        TEdit *te_AIRM_Reader_payloadLength;
        TEdit *te_AIRM_Reader_payloadHEX;
        TCheckBox *cb_AIRM_Reader_tagType_URI;
        TCheckBox *cb_AIRM_Reader_tagType_Text;
        TCheckBox *cb_AIRM_Reader_tagType_SmartPoster;
        TEdit *te_AIRM_Reader_lang;
        TGroupBox *gb_AIRM_Reader_write;
        TLabel *Label16;
        TLabel *Label18;
        TLabel *Label17;
        TRadioButton *rb_AIRM_NTF_Write_tagType_URI;
        TRadioButton *rb_AIRM_NTF_Write_tagType_Text;
        TEdit *te_AIRM_NTF_Write_tagType_Text;
        TGroupBox *gb_AIRM_Reader_format;
        TEdit *te_AIRM_Reader_payloadASCII;
        TButton *tb_AIRM_Reader_formatToNDEF;
        void __fastcall tb_AIRM_NTF_WriteClick(TObject *Sender);
        void __fastcall tb_AIRM_NTF_ReadClick(TObject *Sender);
        void __fastcall rb_AIRM_NTF_Write_tagType_TextClick(
          TObject *Sender);
        void __fastcall rb_AIRM_NTF_Write_tagType_URIClick(
          TObject *Sender);
        void __fastcall tb_AIRM_Reader_formatToNDEFClick(TObject *Sender);

private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;

public:		// User declarations
        int m_module_status;
        __fastcall Tform_AIRM_Reader(TComponent* Owner);
        void displayModule(TControl *comp, bool isVisible);
        void displayReadModule(bool isVisible);
        void displayWriteModule(bool isVisible);
        void displayFormatToNDEF(bool isVisible);
        void resetUI();
        NFC_EM_ALS_READERM_OPT_REQ_S m_readm_opt_req;
        NFC_EM_ALS_READERM_OPT_CNF_S m_readm_opt_cnf;
};
//---------------------------------------------------------------------------
extern PACKAGE Tform_AIRM_Reader *form_AIRM_Reader;
//---------------------------------------------------------------------------
#endif
