#ifndef  _BT_MAN_H_
#define  _BT_MAN_H_


#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif


class  CBTMan
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;

public:
    CBTMan(void);
    ~CBTMan();

    META_RESULT BT_GetChipID(unsigned int ms_timeout, unsigned int * pID);
    META_RESULT BT_Open(unsigned int ms_timeout);
    META_RESULT BT_Close(unsigned int ms_timeout);

};

#endif
