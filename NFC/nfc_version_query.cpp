#ifndef  _NFC_VERSION_QUERY_H_
#include "nfc_version_query.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CNFCVERSIONQUERY *g_nfcPNFCCommand_ptr;

bool CNFCVERSIONQUERY::REQ_Version_Query_Start( NFC_SW_VERSION_CNF_S *version_query_cnf)
{
//    NFC_SW_VERSION_CNF_S version_query_cnf;
//    memset(&version_query_cnf, 0, sizeof(version_query_cnf));
    META_RESULT MetaResult = SP_META_NFC_VERSION_QUERY_r(m_META_HANDLE_Obj.Get_MainHandle(),
       10000, version_query_cnf);

    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            return false;
        }
        else if( META_CANCEL == MetaResult )
        {
            return false;
        }
        else
        {
            return false;
        }
    }
    LOG("%s\n", version_query_cnf->mw_ver);
    LOG("%d\n", version_query_cnf->fw_ver);
    LOG("%d\n", version_query_cnf->hw_ver);
    return true;

}
