#ifndef  _NFC_P2P_H_
#define  _NFC_P2P_H_

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

}NFC_P2P_RSP_S;
class CNFCP2P
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

protected:
    void  Confirm(META_RESULT confirm_state);

public:
        CNFCP2P(void);
    ~CNFCP2P(void);  
    void  (*ConfirmCallback)( void );
    NFC_EM_ALS_P2P_CNF_S m_p2p_cnf;
    NFC_EM_ALS_P2P_NTF_S m_p2p_ntf;
    NFC_P2P_RSP_S m_nfc_rsp;
    bool m_bAlsP2PModeStart;
    bool REQ_ALS_P2P_MODE_Start(NFC_P2P_RSP_S nfc_rsp, NFC_EM_ALS_P2P_REQ_S *p2pReq);
    void __stdcall NFC_P2P_NOTIFY(const NFC_EM_ALS_P2P_NTF_S *p2pNtf);
    META_RESULT Get_ConfirmState(void);
};

#endif
