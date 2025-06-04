#ifndef  _NFC_SWP_TEST_H_
#include "nfc_swp_test.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CNFCSWPTEST *g_nfcPNFCCommand_ptr;

bool CNFCSWPTEST::REQ_SWP_Test_Start(NFC_FM_SWP_TEST_REQ_S *swp_test_Req)
{
    memset(&m_nfc_swp_test_cnf, 0, sizeof(m_nfc_swp_test_cnf));
    META_RESULT MetaResult = SP_META_NFC_SWP_Test_r(m_META_HANDLE_Obj.Get_MainHandle(),
		10000, swp_test_Req, &m_nfc_swp_test_cnf);
	
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
    if(0 == m_nfc_swp_test_cnf.result)
    {
        return true;
    }
    else
    {
        return false;
    }
	
}