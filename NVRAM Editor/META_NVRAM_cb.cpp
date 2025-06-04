#include <windows.h>
#pragma hdrstop

#include "wmmeta.h"
#include "meta_msg.h"

extern HANDLE  hForm_PostMsgTarget;

void __stdcall NVRAM_node_read_rec_cnf_cb( const FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{
    PostMessage(hForm_PostMsgTarget, WM_FDM_READ_REC_CNF, cnf->status, cnf->len);
}

void __stdcall NVRAM_node_write_rec_cnf_cb( const FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    PostMessage(hForm_PostMsgTarget, WM_FDM_WRITE_REC_CNF,  cnf->status,  0);
}