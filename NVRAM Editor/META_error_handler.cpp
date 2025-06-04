#include <windows.h>
#pragma hdrstop
#include "meta.h"
#include "meta_msg.h"

//extern
HANDLE hForm_PostMsgTarget;

void __stdcall error_handler(META_CNF_ERR_CODE m_err)
{
    switch(m_err)
    {
    case META_CNF_FRAME_ERROR:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_ERROR_FRAME_ERROR, 0, 0);
        break;
    case META_CNF_NO_CALLBACK:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_ERROR_NO_CALLBACK, 0, 0);
        break;
    case META_CNF_PRIMITIVE_ERROR:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_ERROR_PRIMITIVE_ERROR, 0, 0);
        break;
    default:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_ERROR_UNDEFINE_ERROR, 0, 0);
        break;
    }
}

void META_result_handler(META_RESULT mr)
{
    switch(mr)
    {
    case META_SUCCESS:
        break;
    case META_FAILED:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_FAILED, 0, 0);
        break;
    case META_COMM_FAIL:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_COMM_FAIL, 0, 0);
        break;
    case META_NORESPONSE:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_NORESPONSE, 0, 0);
        break;
    case META_BUFFER_LEN:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_BUFFER_LEN, 0, 0);
        break;
    case META_FILE_BAD:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_FILE_BAD, 0, 0);
        break;
    case META_LID_INVALID:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_LID_INVALID, 0, 0);
        break;
    case META_INTERNAL_DB_ERR:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_INTERNAL_DB_ERR, 0, 0);
        break;
    case META_NO_MEMORY:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_NO_MEMORY, 0, 0);
        break;
    case META_INVALID_ARGUMENTS:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_INVALID_ARGUMENTS, 0, 0);
        break;
    case META_TIMEOUT:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_TIMEOUT, 0, 0);
        break;
    case META_BUSY:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_BUSY, 0, 0);
        break;
    default:
        PostMessage(hForm_PostMsgTarget, WM_META_DLL_ERROR_UNDEFINE_ERROR, 0, 0);
        break;
    }
}
