#ifndef  _NFC_VERSION_QUERY_H_
#define  _NFC_VERSION_QUERY_H_

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

class CNFCVERSIONQUERY
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

public:

    bool m_bAlsP2PModeStart;
    NFC_SW_VERSION_CNF_S m_nfc_version_query_cnf;
    bool REQ_Version_Query_Start(NFC_SW_VERSION_CNF_S *version_query_cnf);
};

#endif
