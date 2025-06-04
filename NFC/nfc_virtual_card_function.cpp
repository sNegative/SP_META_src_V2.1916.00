
#ifndef _NFC_VIRTUAL_CARD_FUNCTION_H_
#include "nfc_virtual_card_function.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#include "man_active.h"

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CNFCVIRTUALCARDFUNC *g_nfcvirtualcardfunc_ptr;
static bool g_bIsRunning;
 //===========================================================================
CNFCVIRTUALCARDFUNC::CNFCVIRTUALCARDFUNC( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

//---------------------------------------------------------------------------
CNFCVIRTUALCARDFUNC::~CNFCVIRTUALCARDFUNC( void )
{
    ConfirmCallback = 0;
    g_bIsRunning = false;
}

bool CNFCVIRTUALCARDFUNC::REQ_VIRTUAL_CARD_FUNC_Start(NFC_EM_VIRTUAL_CARD_REQ_S *virtual_card_func_Req,
                                                        NFC_EM_VIRTUAL_CARD_CNF_S *nfc_virtual_card_cnf)
{
//    memset(&m_nfc_virtual_card_cnf, 0, sizeof(m_nfc_virtual_card_cnf));
    META_RESULT MetaResult = SP_META_NFC_Virtural_Card_Func_r(m_META_HANDLE_Obj.Get_MainHandle(),
       10000, virtual_card_func_Req, nfc_virtual_card_cnf);

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
    LOG("nfc_virtual_card_cnf.result=%d", nfc_virtual_card_cnf->result);
    if((0 == nfc_virtual_card_cnf->result) || (nfc_virtual_card_cnf->result == 0xE3))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CNFCVIRTUALCARDFUNC::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }

    g_bIsRunning = false;
    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}
