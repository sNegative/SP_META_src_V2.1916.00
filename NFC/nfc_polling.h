#ifndef  _NFC_POLLING_H_
#define  _NFC_POLLING_H_

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

}NFC_POLLING_RSP_S;
class CNFCPOLLING
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

protected:
        void  Confirm(META_RESULT confirm_state);
public:
    CNFCPOLLING(void);
    ~CNFCPOLLING(void);
        void  (*ConfirmCallback)( void );
    NFC_EM_POLLING_CNF_S m_pollingCnf;
    NFC_EM_POLLING_NTF_S m_pollingNtf;

    NFC_POLLING_RSP_S m_nfc_rsp;
    
    bool m_bAlsReaderModeStart;
    bool REQ_ALS_POLLING_MODE_Start(NFC_POLLING_RSP_S nfc_rsp,NFC_EM_POLLING_REQ_S *readerReq);
    void __stdcall NFC_NOTIFY_POLLING_CNF(const NFC_EM_POLLING_NTF_S*readerNtf);
    META_RESULT Get_ConfirmState(void);
//    void REQ_ALS_READER_MODE_OPT_Reader(NFC_EM_ALS_READERM_OPT_REQ_S readerOptReq, NFC_EM_ALS_READERM_OPT_CNF_S readerOptCnf);
};

#endif
