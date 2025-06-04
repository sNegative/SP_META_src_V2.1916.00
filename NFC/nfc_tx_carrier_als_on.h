#ifndef  _NFC_TX_CARRIER_ALS_ON_H_
#define  _NFC_TX_CARRIER_ALS_ON_H_

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

class CNFCTXCARRIERALSON
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

public:

    bool m_bAlsP2PModeStart;
    NFC_EM_TX_CARR_ALS_ON_CNF_S m_nfc_tx_carr_als_on_cnf;
    bool REQ_ALS_TX_CARRIER_Start(NFC_EM_TX_CARR_ALS_ON_REQ_S *tx_carr_als_on_Req);
};

#endif
