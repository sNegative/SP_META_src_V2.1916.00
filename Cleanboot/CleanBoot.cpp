#pragma hdrstop
#include "metaapp_common.h"
#include "CleanBoot.h"
#include "man_active.h"
//#include "LogicalControlBase.h"

static CCLEANBOOT*  g_cleanboot_ptr;


//============================================
bool CCLEANBOOT::REQ_SET_CleanBootFlag_Start()
{
    META_RESULT mr = META_SetCleanBootFlag_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &m_SetCleanBootFlagReq, &m_SetCleanBootFlagCnf);
    if (META_SUCCESS != mr)
        return false;

    return true;
}

