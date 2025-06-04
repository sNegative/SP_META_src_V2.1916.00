#ifndef  _SPECIALTEST_MAN_H_
#define  _SPECIALTEST_MAN_H_


#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif


class  CSpecialTestMan
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;

public:
    CSpecialTestMan(void);
    ~CSpecialTestMan();
  
    META_RESULT SpecialTest_HugeData(unsigned int ms_timeout, unsigned int datasize);
    META_RESULT SpecialTest_RawData(unsigned int ms_timeout, unsigned char *dest, unsigned char *src, unsigned int datasize);
    
};

#endif
