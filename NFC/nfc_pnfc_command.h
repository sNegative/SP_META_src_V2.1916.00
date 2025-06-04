#ifndef  _NFC_PNFC_COMMAND_H_
#define  _NFC_PNFC_COMMAND_H_

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

class CNFCPNFCCOMMAND
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

public:

    bool m_bAlsP2PModeStart;
    NFC_EM_PNFC_CNF_S m_nfc_pnfc_cnf;
    bool REQ_PNFC_Command_Start(NFC_EM_PNFC_REQ_S *pnfc_command_Req, NFC_EM_PNFC_CNF_S *pnfc_command_Cnf);
};

#endif
