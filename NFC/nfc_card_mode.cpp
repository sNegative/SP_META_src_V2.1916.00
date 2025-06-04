
#ifndef _NFC_CARD_MODE_H_
#include "nfc_card_mode.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CNFCCARDMODE *g_nfccardm_ptr;

bool CNFCCARDMODE::REQ_ALS_CARD_MODE_SET_SE(NFC_EM_SE_GET_LIST *se_list)
{
    META_RESULT MetaResult = SP_META_NFC_CardMode_SetSE_r(m_META_HANDLE_Obj.Get_MainHandle(),
       10000, se_list);
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
    if(0 == se_list->status)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CNFCCARDMODE::REQ_ALS_CARD_MODE_Start(NFC_EM_ALS_CARDM_REQ_S *cardmReq)
{
    memset(&m_nfc_card_mode, 0, sizeof(m_nfc_card_mode));
    META_RESULT MetaResult = SP_META_NFC_CardMode_r(m_META_HANDLE_Obj.Get_MainHandle(),
       10000, cardmReq, &m_nfc_card_mode);

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
    if(m_nfc_card_mode.result)
    {
        return false;
    }
    else
    {
        return true;
    }
}
