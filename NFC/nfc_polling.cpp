#include "nfc_polling.h"
#include "man_active.h"
 
#ifndef _NFC_READER_H_
#include "nfc_reader.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef form_NFC_readerH
#include "form_NFC_reader.h"
#endif

#ifndef reader_resultH
#include "reader_result.h"
#endif
      
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif
static CNFCPOLLING *g_nfcpolling_ptr;
static void __stdcall NFC_NOTIFY_POLLING_CNF(const NFC_EM_POLLING_NTF_S*pollingNtf);
static bool g_bIsRunning;
 //===========================================================================
CNFCPOLLING::CNFCPOLLING( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

//---------------------------------------------------------------------------
CNFCPOLLING::~CNFCPOLLING( void )
{
    ConfirmCallback = 0;
    g_bIsRunning = false;
}
bool CNFCPOLLING::REQ_ALS_POLLING_MODE_Start(NFC_POLLING_RSP_S nfc_rsp,NFC_EM_POLLING_REQ_S *pollingReq)
{
        g_nfcpolling_ptr = this;
        g_bIsRunning = true;
        m_nfc_rsp = nfc_rsp;
        LOG("REQ_ALS_POLLING_MODE_Start\n");
        META_RESULT MetaResult;
        memset(&m_pollingCnf, 0, sizeof(m_pollingCnf));
        if(pollingReq->action == 0)
        {
                MetaResult = SP_META_NFC_PollingLoopMode_r(m_META_HANDLE_Obj.Get_MainHandle(),
                10000, pollingReq, &m_pollingCnf, ::NFC_NOTIFY_POLLING_CNF);
       }
       else
       {
                MetaResult = SP_META_NFC_PollingLoopMode_r(m_META_HANDLE_Obj.Get_MainHandle(),
                        10000, pollingReq, &m_pollingCnf, NULL);
       }

    if (META_SUCCESS != MetaResult)
    {
        LOG("META_SUCCESS != MetaResult\n");
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return false;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return false;
        }
        else
        {
            Confirm( META_FAILED );
            return false;
        }
    }
    else if(m_pollingCnf.result == 0)
    {
        Confirm(META_SUCCESS);
    }
    else
    {
        Confirm(META_FAILED);
    }
        LOG("META_SUCCESS = MetaResult\n");

}
void __stdcall NFC_NOTIFY_POLLING_CNF(const NFC_EM_POLLING_NTF_S*pollingNtf)
{
        g_nfcpolling_ptr->NFC_NOTIFY_POLLING_CNF(pollingNtf);
}
void __stdcall CNFCPOLLING::NFC_NOTIFY_POLLING_CNF(const NFC_EM_POLLING_NTF_S*pollingNtf)
{
     LOG("NFC_NOTIFY_POLLING_CNF\n");

     PostMessage(m_nfc_rsp.hPostMsgDestHandle,
                WN_ML_NFC_POLLING_LOOP,
                (WPARAM)pollingNtf,
                0
                );
     return;
}

void CNFCPOLLING::Confirm(META_RESULT confirm_state)
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

META_RESULT CNFCPOLLING::Get_ConfirmState( void )
{
    return  m_eConfirmState;
}
