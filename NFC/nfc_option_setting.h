#ifndef  _NFC_OPTION_SETTING_H_
#define  _NFC_OPTION_SETTING_H_

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

class CNFCOPTIONSETTING
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

public:

    bool m_bAlsP2PModeStart;
    NFC_TEST_MODE_SETTING_CNF_S m_nfc_option_setting_cnf;
    bool REQ_Option_Setting_Start(NFC_TEST_MODE_SETTING_REQ_S *option_setting_Req);
};

#endif
