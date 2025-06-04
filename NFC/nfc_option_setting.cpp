#ifndef  _NFC_OPTION_SETTING_H_
#include "nfc_option_setting.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CNFCOPTIONSETTING *g_nfcPNFCCommand_ptr;

bool CNFCOPTIONSETTING::REQ_Option_Setting_Start(NFC_TEST_MODE_SETTING_REQ_S *option_setting_Req)
{
    memset(&m_nfc_option_setting_cnf, 0, sizeof(m_nfc_option_setting_cnf));
    META_RESULT MetaResult = SP_META_NFC_Option_r(m_META_HANDLE_Obj.Get_MainHandle(),
       5000, option_setting_Req, &m_nfc_option_setting_cnf);

    if ( META_SUCCESS != MetaResult )
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
    if(1 == m_nfc_option_setting_cnf.result)
    {
        return true;
    }
    else
    {
        return false;
    }

}
