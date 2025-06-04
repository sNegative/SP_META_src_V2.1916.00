#pragma hdrstop

#ifndef  _BT_MAN_H_
#include "bt_man.h"
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

static CBTMan*  g_btman_ptr;



CBTMan::CBTMan(void)
{

}

CBTMan::~CBTMan()
{
}


META_RESULT CBTMan::BT_GetChipID(unsigned int ms_timeout, unsigned int * pID)
{
    return SP_META_BT_GetChipID_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pID);
}

META_RESULT CBTMan::BT_Open(unsigned int ms_timeout)
{
    return SP_META_BT_OPEN_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CBTMan::BT_Close(unsigned int ms_timeout)
{
    return SP_META_BT_CLOSE_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

