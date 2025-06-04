
#ifndef _NFC_TX_CARRIER_ALS_ON_H_
#include "nfc_tx_carrier_als_on.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CNFCTXCARRIERALSON *g_nfctxcarrieralson_ptr;

bool CNFCTXCARRIERALSON::REQ_ALS_TX_CARRIER_Start(NFC_EM_TX_CARR_ALS_ON_REQ_S *tx_carr_als_on_Req)
{
    memset(&m_nfc_tx_carr_als_on_cnf, 0, sizeof(m_nfc_tx_carr_als_on_cnf));
    META_RESULT MetaResult = SP_META_NFC_TX_Carrier_Signal_AlsOn_r(m_META_HANDLE_Obj.Get_MainHandle(),
       10000, tx_carr_als_on_Req, &m_nfc_tx_carr_als_on_cnf);

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
    if(m_nfc_tx_carr_als_on_cnf.result)
    {
        return false;
    }
    else
    {
        return true;
    }
}
