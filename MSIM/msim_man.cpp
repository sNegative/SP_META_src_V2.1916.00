#ifndef  _MSIM_MAN_H_
#include "msim_man.h"
#endif

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif



CMSIMMan::CMSIMMan(void)
{

}

CMSIMMan::~CMSIMMan()
{
}

bool CMSIMMan::Query_MSIM_Support(void)
{
    META_RESULT MetaResult = SP_META_QueryIfFunctionSupportedByTarget_r(m_META_HANDLE_Obj.Get_MainHandle(), 2000, "SP_META_MSIM_GetValue_r");
    if(MetaResult!=META_SUCCESS)
    {
        return false;
    }
    return true;
}

META_RESULT CMSIMMan::MSIM_GetValue(unsigned int ms_timeout, MSIM_GETVALUE_CNF *pCnf)
{
    return SP_META_MSIM_GetValue_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pCnf);
}

META_RESULT CMSIMMan::MSIM_SetValue(unsigned int ms_timeout, MSIM_SETVALUE_REQ *pReq, MSIM_SETVALUE_CNF *pCnf)
{
    return SP_META_MSIM_SetValue_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pReq, pCnf);
}

META_RESULT CMSIMMan::MSIM_FactoryReset(unsigned int ms_timeout, EMMC_CLEAR_CNF_S *pCnf)
{
    return SP_META_ClearValue_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pCnf);
}

