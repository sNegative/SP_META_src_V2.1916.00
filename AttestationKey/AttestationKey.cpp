#pragma hdrstop
#include "meta.h"
#include "metaapp_common.h"
#include "AttestationKey.h"
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

static CAttestationKey*  g_AttestationKey_ptr;

static bool g_bIsRunning = false;


static void REQ_AttestationKeyInstall(void)
{
    g_AttestationKey_ptr->REQ_AttestationKeyInstall();
}

void  CAttestationKey::Confirm(META_RESULT confirm_state)
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

META_RESULT CAttestationKey::Get_ConfirmState(void)
{
    return m_eConfirmState;
}

void  CAttestationKey::REQ_AttestationKeyInstall_Start(const AnsiString& file)
{
    g_AttestationKey_ptr = this;
    g_bIsRunning = true;
    m_file = file;
    ActiveMan->SetActiveFunction( ::REQ_AttestationKeyInstall );
}

void CAttestationKey::REQ_AttestationKeyInstall(void)
{
    if(!g_bIsRunning)  return;

    ATTESTATIONKEY_INSTALL_SET_CNF Cnf;
    memset(&Cnf,0,sizeof(ATTESTATIONKEY_INSTALL_SET_CNF));

    META_RESULT MetaResult =  SP_META_AttestationKey_Install_Set_r(m_META_HANDLE_Obj.Get_MainHandle(),
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
