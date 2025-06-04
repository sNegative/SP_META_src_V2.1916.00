#ifndef  _NFC_SWP_TEST_H_
#define  _NFC_SWP_TEST_H_

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

class CNFCSWPTEST
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

public:

    bool m_bAlsP2PModeStart;
    NFC_FM_SWP_TEST_CNF_S m_nfc_swp_test_cnf;
    bool REQ_SWP_Test_Start(NFC_FM_SWP_TEST_REQ_S *swp_test_Req);
};

#endif