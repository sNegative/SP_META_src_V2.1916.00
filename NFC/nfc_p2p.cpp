#include "man_active.h"
#ifndef _NFC_P2P_H_
#include "nfc_p2p.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CNFCP2P *g_nfcp2p_ptr;
static bool g_bIsRunning;
 //===========================================================================
CNFCP2P::CNFCP2P( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

//---------------------------------------------------------------------------
CNFCP2P::~CNFCP2P( void )
{
    ConfirmCallback = 0;
    g_bIsRunning = false;
}

void __stdcall NFC_P2P_NOTIFY(const NFC_EM_ALS_P2P_NTF_S*p2pNtf)
{
        g_nfcp2p_ptr->NFC_P2P_NOTIFY(p2pNtf);
}

void __stdcall CNFCP2P::NFC_P2P_NOTIFY(const NFC_EM_ALS_P2P_NTF_S*p2pNtf)
{
     int link_status = p2pNtf->link_status;
     LOG("NFC_P2P_NOTIFY\n");
     PostMessage(m_nfc_rsp.hPostMsgDestHandle,
                WM_ML_NFC_P2P,
                (WPARAM)link_status,
                0
                );
    
}  
bool CNFCP2P::REQ_ALS_P2P_MODE_Start(NFC_P2P_RSP_S nfc_rsp, NFC_EM_ALS_P2P_REQ_S *p2pReq)
{

        m_nfc_rsp = nfc_rsp;
        META_RESULT MetaResult;
        memset(&m_p2p_cnf, 0, sizeof(m_p2p_cnf));
        g_nfcp2p_ptr = this;
        g_bIsRunning = true;
        if(p2pReq->action == 0){
                MetaResult = SP_META_NFC_Em_Als_P2P_Mode_r(m_META_HANDLE_Obj.Get_MainHandle(),
                        15000, p2pReq, &m_p2p_cnf, ::NFC_P2P_NOTIFY);
       }
       else
       {
                MetaResult = SP_META_NFC_Em_Als_P2P_Mode_r(m_META_HANDLE_Obj.Get_MainHandle(),
                        15000, p2pReq, &m_p2p_cnf, NULL);
//                g_bIsRunning = false;
       }

    if (META_SUCCESS != MetaResult)
    {
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
    Confirm(META_SUCCESS);

}
void CNFCP2P::Confirm(META_RESULT confirm_state)
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

META_RESULT CNFCP2P::Get_ConfirmState( void )
{
    return  m_eConfirmState;
}
