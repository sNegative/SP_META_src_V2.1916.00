#include <IniFiles.hpp>

#pragma hdrstop

#ifndef  _FM_RDS_H_
#include "fm_tx.h"
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

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CFMTX* g_fm_tx_ptr;
static bool g_bIsRunning = false;

//---------------------------------------------------------------------------
static void REQ_FM_TxPowerOn(void)
{
    g_fm_tx_ptr->REQ_FM_TxPowerOn();
}
//---------------------------------------------------------------------------
static void REQ_FM_TxPowerOff(void)
{
    g_fm_tx_ptr->REQ_FM_TxPowerOff();
}
//---------------------------------------------------------------------------
static void REQ_Set_Freq(void)
{
    g_fm_tx_ptr->REQ_Set_Freq();
}
static void REQ_Write_Byte(void)
{
    g_fm_tx_ptr->REQ_Write_Byte();
}

//---------------------------------------------------------------------------
CFMTX::CFMTX(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}

//---------------------------------------------------------------------------
CFMTX::~CFMTX()
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}
//---------------------------------------------------------------------------
void CFMTX::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (confirm_state != METAAPP_SECTION_OK)
    {
        g_bIsRunning = false;
    }

    if (confirm_state != META_SUCCESS)
    {
        short s;
        SP_META_Cancel_r(m_META_HANDLE_Obj.Get_MainHandle(), s);
        SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    }

    if (NULL == ConfirmCallback)
    {
        return;
    }

    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

META_RESULT CFMTX::Get_ConfirmState(void)
{
    return m_eConfirmState;
}

//---------------------------------------------------------------------------

void CFMTX::REQ_FM_TxPowerOn_Start(void)
{
    g_fm_tx_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_FM_TxPowerOn);
}
//---------------------------------------------------------------------------

void CFMTX::REQ_FM_TxPowerOff_Start(void)
{
    g_fm_tx_ptr = this;
    g_bIsRunning = true;

    ActiveMan->SetActiveFunction(::REQ_FM_TxPowerOff);
}

//---------------------------------------------------------------------------

void CFMTX::REQ_FM_TxPowerOn(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult = SP_META_FM_TXPowerOn_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void CFMTX::REQ_FM_TxPowerOff(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_PowerOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}




void CFMTX::REQ_Write_Byte_Start(FM_WRITE_BYTE_REQ_T freq)
{
    g_fm_tx_ptr = this;
    g_bIsRunning = true;
    m_sFMWrite  = freq;
    ActiveMan->SetActiveFunction(::REQ_Write_Byte);
}
void CFMTX::REQ_Write_Byte(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult = SP_META_FM_WriteByte_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&m_sFMWrite);

    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);

}

void CFMTX::REQ_Set_Freq_Start(FM_FREQ_REQ_T freq)
{
    g_fm_tx_ptr = this;
    g_bIsRunning = true;
    m_sFMFreq  = freq;
    ActiveMan->SetActiveFunction(::REQ_Set_Freq);
}
//---------------------------------------------------------------------------
void CFMTX::REQ_Set_Freq(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    META_RESULT MetaResult= SP_META_FM_TxSetFreq_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &m_sFMFreq);
    if (MetaResult != META_SUCCESS)
    {
        if (META_TIMEOUT == MetaResult)
        {
            Confirm(META_TIMEOUT);
        }
        else
        {
            Confirm(META_FAILED);
        }
        return;
    }
    Confirm(META_SUCCESS);
}
