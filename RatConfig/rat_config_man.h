#ifndef  _RATCONFIG_MAN_H_
#define  _RATCONFIG_MAN_H_


#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#include <string>
#include <vector>


class  CRatConfigMan
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;
public:
    unsigned int m_nRatValid;
    unsigned int m_nRatOptionCount;
    std::vector<std::string>  m_OptionList;

public:
    CRatConfigMan(void);
    ~CRatConfigMan();
    bool Query_RatConfig_Support(void);
    int ParseXMLFile(const char* xmlfile_name, const char* configfile_name, unsigned char* optr, unsigned char* optrseg);
    int ParseConfigFile(const char* configfile_name);
    void RemoveCRLF(char *str);
    META_RESULT RATConfig_ReadOptr(unsigned int ms_timeout, RATCONFIG_READOPTR_CNF *pCnf);
    META_RESULT RATConfig_ReadOptrSeg(unsigned int ms_timeout, RATCONFIG_READOPTRSEG_CNF *pCnf);
    META_RESULT RATConfig_GetCurrentRat(unsigned int ms_timeout, RATCONFIG_GETCURRENTRAT_CNF *pCnf);
    META_RESULT RATConfig_SetNewRat(unsigned int ms_timeout, RATCONFIG_SETNEWRAT_REQ *pReq, RATCONFIG_SETNEWRAT_CNF *pCnf);
    META_RESULT RATConfig_RebootTarget(void);
    META_RESULT RATConfig_FactoryReset(unsigned int ms_timeout, EMMC_CLEAR_CNF_S *pCnf);

};

#endif
