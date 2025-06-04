#ifndef  _NFC_LOOPBACK_TEST_H_
#include "nfc_loopback_test.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

#ifndef form_NFC_readerH
#include "form_NFC_reader.h"
#endif

static CNFCLOOPBACKTEST *g_nfcPNFCCommand_ptr;

static void __stdcall NFC_POLLING_LOOP_MODE_NOTIFY_CNF(const NFC_EM_POLLING_NTF_S*PollingLoopModeNtf)
{
        g_nfcPNFCCommand_ptr->NFC_POLLING_LOOP_MODE_NOTIFY_CNF(PollingLoopModeNtf);
}

void CNFCLOOPBACKTEST::NFC_POLLING_LOOP_MODE_NOTIFY_CNF(const NFC_EM_POLLING_NTF_S*PollingLoopModeNtf)
{
     int type = PollingLoopModeNtf->detecttype;

     if(1 == type)
     {
        //NFC_EM_ALS_READERM_NTF_S readerNtf;
        //readerNtf = PollingLoopModeNtf->ntf.reader;
        /*
        int result = PollingLoopModeNtf->ntf.reader.result;
        unsigned int isNDEF = PollingLoopModeNtf->ntf.reader.isNDEF;
        unsigned int UidLen = PollingLoopModeNtf->ntf.reader.UidLen;
        AnsiString Uid;
        Uid.sprintf("%s", PollingLoopModeNtf->ntf.reader.Uid);
        form_AIRM_Reader->tl_AIRM_Reader_UID->Caption = Uid;
        if(0 == result)
        {
                if(0 == isNDEF)
                {
                        form_AIRM_Reader->displayReadModule(false);
                        form_AIRM_Reader->displayWriteModule(false);
                        form_AIRM_Reader->displayFormatToNDEF(true);
                        form_AIRM_Reader->Show();
                }
                else if(1 == isNDEF)
                {
                        form_AIRM_Reader->displayReadModule(true);
                        form_AIRM_Reader->displayWriteModule(true);
                        form_AIRM_Reader->displayFormatToNDEF(false);
                        form_AIRM_Reader->Show();
                }
                else if(2 == isNDEF)
                {
                        form_AIRM_Reader->displayReadModule(true);
                        form_AIRM_Reader->displayWriteModule(false);
                        form_AIRM_Reader->displayFormatToNDEF(false);
                        form_AIRM_Reader->Show();
                }
        }
        else if(2 == result)
        {
                form_AIRM_Reader->Hide();
        }
        else
        {
                form_AIRM_Reader->displayReadModule(false);
                form_AIRM_Reader->displayWriteModule(false);
                form_AIRM_Reader->displayFormatToNDEF(false);
                form_AIRM_Reader->Show();
        }
        */
        PostMessage(m_polling_loop_rsp.hPostMsgDestHandle,
                WN_ML_NFC_POLLING_LOOP,
                (WPARAM)PollingLoopModeNtf,
                0
        ); 
     }
     else if(2 == type)
     {
        int link_status = PollingLoopModeNtf->ntf.p2p.link_status;
        PostMessage(m_polling_loop_rsp.hPostMsgDestHandle,
                WN_ML_NFC_POLLING_LOOP,
                link_status,
                0
        );

     }
     else if(4 == type)
     {
          int result = PollingLoopModeNtf->ntf.card.result;
          if(result == 0)
          {
                Application->MessageBox("Card emulate mode ok!", "Success", MB_OK);
          }
          else
          {
                Application->MessageBox("Card emulate mode fail!", "Fail", MB_OK);
          }
     }

     return;
}

bool CNFCLOOPBACKTEST::REQ_Loopback_Test_Start(NFC_LOOPBACK_TEST_REQ_S *loopback_test_Req)
{
    memset(&m_nfc_loopback_test_cnf, 0, sizeof(m_nfc_loopback_test_cnf));
    META_RESULT MetaResult = SP_META_NFC_Loopback_Test_r(m_META_HANDLE_Obj.Get_MainHandle(),
       5000, loopback_test_Req, &m_nfc_loopback_test_cnf);

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
    if(1 == m_nfc_loopback_test_cnf.result)
    {
        return true;
    }
    else
    {
        return false;
    }

}
