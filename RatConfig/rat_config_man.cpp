#ifndef  _RATCONFIG_MAN_H_
#include "rat_config_man.h"
#endif

#include <fstream.h>
#include <io.h>

#ifndef  _MAN_ACTIVE_H_
#include "man_active.h"
#endif

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  XML_LIB_H
#include "XMLLib.h"
#endif


CRatConfigMan::CRatConfigMan(void)
{
    m_OptionList.clear();
    m_nRatValid = 0;
    m_nRatOptionCount = 0;
}

CRatConfigMan::~CRatConfigMan()
{
}
int CRatConfigMan::ParseXMLFile(const char* xmlfile_name, const char* configfile_name, unsigned char* optr, unsigned char* optrseg)
{
    int nRet = LoadXMLFile(xmlfile_name, configfile_name, optr, optrseg, &m_nRatValid, &m_nRatOptionCount);
    if(nRet == 0)
    {
         ParseConfigFile(configfile_name);
    }
    else
    {
        return nRet;
    }
}

void CRatConfigMan::RemoveCRLF(char *str)
{
    char *p = &str[strlen(str)-1];
    while (*p == '\r' || *p == '\n')
        *p-- = '\0';
}


int CRatConfigMan::ParseConfigFile(const char* configfile_name)
{
    char buffer[128] = {0};
    ifstream ifs;
    ifs.open(configfile_name, ios::in);
    m_OptionList.clear();
    while(!ifs.eof())
    {
        ifs.getline(buffer, 128,'\n');
        RemoveCRLF(buffer);
        m_OptionList.push_back(buffer);
    }
    ifs.close();

    return 0;
}

bool CRatConfigMan::Query_RatConfig_Support(void)
{
    META_RESULT MetaResult = SP_META_QueryIfFunctionSupportedByTarget_r(m_META_HANDLE_Obj.Get_MainHandle(), 2000, "SP_META_RATConfig_ReadOptr_r");
    if(MetaResult!=META_SUCCESS)
    {
        return false;
    }
    return true;
}

META_RESULT CRatConfigMan::RATConfig_ReadOptr(unsigned int ms_timeout, RATCONFIG_READOPTR_CNF *pCnf)
{
    return SP_META_RATConfig_ReadOptr_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pCnf);
}

META_RESULT CRatConfigMan::RATConfig_ReadOptrSeg(unsigned int ms_timeout, RATCONFIG_READOPTRSEG_CNF *pCnf)
{
    return SP_META_RATConfig_ReadOptrSeg_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pCnf);
}

META_RESULT CRatConfigMan::RATConfig_GetCurrentRat(unsigned int ms_timeout, RATCONFIG_GETCURRENTRAT_CNF *pCnf)
{
    return SP_META_RATConfig_GetCurrentRat_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pCnf);
}

META_RESULT CRatConfigMan::RATConfig_SetNewRat(unsigned int ms_timeout, RATCONFIG_SETNEWRAT_REQ *pReq, RATCONFIG_SETNEWRAT_CNF *pCnf)
{
    return SP_META_RATConfig_SetNewRat_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pReq, pCnf);
}

META_RESULT CRatConfigMan::RATConfig_RebootTarget(void)
{
    return SP_META_CloseComPortReboot_r(m_META_HANDLE_Obj.Get_MainHandle());
}

META_RESULT CRatConfigMan::RATConfig_FactoryReset(unsigned int ms_timeout, EMMC_CLEAR_CNF_S *pCnf)
{
    return SP_META_ClearValue_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pCnf);
}
