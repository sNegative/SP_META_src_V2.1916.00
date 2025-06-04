#ifndef  _CLEANBOOT_H_
#define  _CLEANBOOT_H_
#include "LogicalControlBase.h"
#include "wmmeta.h"
#include "man_handle.h"

class  CCLEANBOOT: public CLogicalControlBase
{
public:
    bool REQ_SET_CleanBootFlag_Start(void);
    //META_RESULT REQ_SET_CleanBootFlag(void);

    SetCleanBootFlag_REQ		m_SetCleanBootFlagReq;
    SetCleanBootFlag_CNF		m_SetCleanBootFlagCnf;

};

#endif
