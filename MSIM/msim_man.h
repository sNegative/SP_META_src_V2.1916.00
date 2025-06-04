#ifndef  _MSIM_MAN_H_
#define  _MSIM_MAN_H_


#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif


class  CMSIMMan
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;

public:
    CMSIMMan(void);
    ~CMSIMMan();
    bool Query_MSIM_Support(void);
    META_RESULT MSIM_GetValue(unsigned int ms_timeout, MSIM_GETVALUE_CNF *pCnf);
    META_RESULT MSIM_SetValue(unsigned int ms_timeout, MSIM_SETVALUE_REQ *pReq, MSIM_SETVALUE_CNF *pCnf);
    META_RESULT MSIM_FactoryReset(unsigned int ms_timeout, EMMC_CLEAR_CNF_S *pCnf);
};

#endif
