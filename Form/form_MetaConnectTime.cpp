
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_MetaConnectTime.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMetaConnectTime *frmMetaConnectTime;
//---------------------------------------------------------------------------
__fastcall TfrmMetaConnectTime::TfrmMetaConnectTime(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMetaConnectTime::btnLoadBootprofClick(TObject *Sender)
{
        if(!(sdBootprof->Execute()))
        {
            return;
        }
        if(FileExists(sdBootprof->FileName))
        {
            FILE_OPERATION_PARSE_REQ parseReq;
            FILE_OPERATION_PARSE_CNF parseCnf;
            memset(&parseReq, 0, sizeof(parseReq));
            memset(&parseCnf, 0, sizeof(parseCnf));
            memcpy(parseReq.path_name, "proc/",strlen("proc"));
            memcpy(parseReq.filename_substr, "bootprof", strlen("bootprof"));
            META_RESULT mr = META_FAILED;
            AnsiString asDestFileNamePath = sdBootprof->FileName;
            AnsiString asSrcFilePath = (AnsiString)"proc/bootprof";
            mr = SP_META_File_Operation_ReceiveFile_r(m_META_HANDLE_Obj.Get_MainHandle(), 10000, asSrcFilePath.c_str(),
                   asDestFileNamePath.c_str());
            if (mr == META_SUCCESS)
            {
                 Application->MessageBox( "Save Success", "Success", MB_OK );
            }
            else
            {
                Application->MessageBox( "Save Fail", "Fail", MB_OK );
            }
        }
}
//---------------------------------------------------------------------------
