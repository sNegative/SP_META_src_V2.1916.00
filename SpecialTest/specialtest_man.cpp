#pragma hdrstop

#ifndef  _SPECIALTEST_MAN_H_
#include "specialtest_man.h"
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

#include <stdio.h>

CSpecialTestMan::CSpecialTestMan(void)
{
    
}

CSpecialTestMan::~CSpecialTestMan()
{
    
}

META_RESULT CSpecialTestMan::SpecialTest_HugeData(unsigned int ms_timeout, unsigned int datasize)
{
    return SP_META_SpecialTest_HugeData_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, datasize);
}

META_RESULT CSpecialTestMan::SpecialTest_RawData(unsigned int ms_timeout, unsigned char *dest, unsigned char *src, unsigned int datasize)
{
    return SP_META_SpecialTest_RawData_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, dest, src, datasize);
}
