#ifndef  _NFC_CARD_MODE_H_
#define  _NFC_CARD_MODE_H_

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

class CNFCCARDMODE
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

public:

    bool m_bAlsP2PModeStart;
    NFC_EM_ALS_CARDM_CNF_S m_nfc_card_mode;
    NFC_EM_SE_GET_LIST m_nfc_card_mode_set_se;
    bool REQ_ALS_CARD_MODE_SET_SE(NFC_EM_SE_GET_LIST *se_list);
    bool REQ_ALS_CARD_MODE_Start(NFC_EM_ALS_CARDM_REQ_S *cardmReq);
};

#endif
