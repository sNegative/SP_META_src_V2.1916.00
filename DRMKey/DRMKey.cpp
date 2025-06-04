#pragma hdrstop
#include "meta.h"
#include "metaapp_common.h"
#include "DRMKey.h"
#include "man_active.h"
#include "LogicalControlBase.h"
#include <math.h>
#include <Classes.hpp>
#include <inifiles.hpp>
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#include <stdio.h>

static CDRMKEY*  g_drmkey_ptr;

static bool g_bIsRunning = false;


static void REQ_DRMKeyInstall(void)
{
    g_drmkey_ptr->REQ_DRMKeyInstall();
}

static void REQ_DRMKeyQuery(void)
{
    g_drmkey_ptr->REQ_DRMKeyQuery();
}

void  CDRMKEY::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }

    g_bIsRunning = false;
    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

META_RESULT CDRMKEY::Get_ConfirmState(void)
{
    return m_eConfirmState;
}

void  CDRMKEY::REQ_DRMKeyInstall_Start(const AnsiString& file)
{
    g_drmkey_ptr = this;
    g_bIsRunning = true;
    m_file = file;
    ActiveMan->SetActiveFunction( ::REQ_DRMKeyInstall );
}

void CDRMKEY::REQ_DRMKeyInstall(void)
{
    if(!g_bIsRunning)  return;

    DRMKEY_INSTALL_SET_CNF Cnf;
    memset(&Cnf,0,sizeof(DRMKEY_INSTALL_SET_CNF));

    META_RESULT MetaResult =  SP_META_DRMKey_Install_Set_r(m_META_HANDLE_Obj.Get_MainHandle(),
                              10000,
                              m_file.c_str(),
                              &Cnf);
    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }
    Confirm(META_SUCCESS);
}

void CDRMKEY::REQ_DRMKeyQuery_Start()
{
    g_drmkey_ptr = this;
    g_bIsRunning = true;
    //m_file = file;
    ActiveMan->SetActiveFunction( ::REQ_DRMKeyQuery );
}

void CDRMKEY::REQ_DRMKeyQuery(void)
{
    if(!g_bIsRunning)  return;

    DRMKEY_INSTALL_QUERY_REQ Req;
    memset(&Req,0,sizeof(DRMKEY_INSTALL_QUERY_REQ));
    memset(&m_Cnf,0,sizeof(DRMKEY_INSTALL_QUERY_CNF));

    META_RESULT MetaResult =  SP_META_DRMKey_Install_Query_r(m_META_HANDLE_Obj.Get_MainHandle(),
                              5000,
                              &Req,
                              &m_Cnf);

   if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }
    Confirm(META_SUCCESS);
}

bool CDRMKEY::GetDRMKeyQueryResult(char* strQueryResult)
{
    if( m_Cnf.keycount >0 )
    {
       unsigned int i = 0;
       int nLen = sprintf(strQueryResult,"keycount = %d\n", m_Cnf.keycount);
       for(i=0; i<m_Cnf.keycount;i++)
       {
          nLen += sprintf(strQueryResult + nLen, "keytype[%d] = %d\n",i,m_Cnf.keytype[i]);
       }
       return true;
    }
    return false;
}
