#ifndef  _NFC_LOOPBACK_TEST_H_
#define  _NFC_LOOPBACK_TEST_H_

#include <Classes.hpp>
#include "LogicalControlBase.h"

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif
typedef struct
{
        HANDLE hPostMsgDestHandle;

}NFC_POLLING_LOOP_S;
class CNFCLOOPBACKTEST
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

public:
    NFC_POLLING_LOOP_S m_polling_loop_rsp;
    bool m_bAlsP2PModeStart;
    NFC_LOOPBACK_TEST_CNF_S m_nfc_loopback_test_cnf;
    bool REQ_Loopback_Test_Start(NFC_LOOPBACK_TEST_REQ_S *loopback_test_Req);
    void NFC_POLLING_LOOP_MODE_NOTIFY_CNF(const NFC_EM_POLLING_NTF_S*PollingLoopModeNtf);
};

#endif
