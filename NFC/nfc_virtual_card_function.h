#ifndef  _NFC_VIRTUAL_CARD_FUNCTION_H_
#define  _NFC_VIRTUAL_CARD_FUNCTION_H_

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

class CNFCVIRTUALCARDFUNC
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

protected:
        void  Confirm(META_RESULT confirm_state);
public:
    CNFCVIRTUALCARDFUNC(void);
    ~CNFCVIRTUALCARDFUNC(void);
    void  (*ConfirmCallback)( void );
    bool m_bAlsP2PModeStart;
//    NFC_EM_VIRTUAL_CARD_CNF_S m_nfc_virtual_card_cnf;
    bool REQ_VIRTUAL_CARD_FUNC_Start(NFC_EM_VIRTUAL_CARD_REQ_S *virtual_card_func_Req, NFC_EM_VIRTUAL_CARD_CNF_S *m_nfc_virtual_card_cnf);
};

#endif
