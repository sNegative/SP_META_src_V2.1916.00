#include "nfc_reader.h"
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
static CNFCREADER *g_nfcreader_ptr;
static void __stdcall NFC_NOTIFY_CNF(const NFC_EM_ALS_READERM_NTF_S*readerNtf);
static bool g_bIsRunning;
 //===========================================================================
CNFCREADER::CNFCREADER( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

//---------------------------------------------------------------------------
CNFCREADER::~CNFCREADER( void )
{
    ConfirmCallback = 0;
    g_bIsRunning = false;
}
bool CNFCREADER::REQ_ALS_READER_MODE_Start(NFC_READER_RSP_S nfc_rsp,NFC_EM_ALS_READERM_REQ_S *readerReq)
{
        g_nfcreader_ptr = this;
        g_bIsRunning = true;
        m_nfc_rsp = nfc_rsp;
        LOG("REQ_ALS_READER_MODE_Start\n");
        META_RESULT MetaResult;
        memset(&m_readerCnf, 0, sizeof(m_readerCnf));
        if(readerReq->action == 0)
        {
                MetaResult = SP_META_NFC_Em_Als_Reader_Mode_r(m_META_HANDLE_Obj.Get_MainHandle(),
                15000, readerReq, &m_readerCnf, ::NFC_NOTIFY_CNF, 0);
       }
       else
       {
                MetaResult = SP_META_NFC_Em_Als_Reader_Mode_r(m_META_HANDLE_Obj.Get_MainHandle(),
                        15000, readerReq, &m_readerCnf, NULL, 1);
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
    else if(m_readerCnf.result == 0)
    {
        Confirm(META_SUCCESS);
    }
    else
    {
        Confirm(META_FAILED);
    }
        LOG("META_SUCCESS = MetaResult\n");
}
void __stdcall NFC_NOTIFY_CNF(const NFC_EM_ALS_READERM_NTF_S*readerNtf)
{
        g_nfcreader_ptr->NFC_NOTIFY_CNF(readerNtf);
}
void __stdcall CNFCREADER::NFC_NOTIFY_CNF(const NFC_EM_ALS_READERM_NTF_S*readerNtf)
{
     LOG("NFC_NOTIFY_CNF\n");
     PostMessage(m_nfc_rsp.hPostMsgDestHandle,
                WM_ML_NFC_AIRM,
                (WPARAM)readerNtf,
                0
                );
     return;
}

void CNFCREADER::Confirm(META_RESULT confirm_state)
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

META_RESULT CNFCREADER::Get_ConfirmState( void )
{
    return  m_eConfirmState;
}
