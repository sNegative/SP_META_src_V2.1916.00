#pragma hdrstop
#include "bb_common.h"
#include "bb_reg.h"
#include "man_active.h"

static CBBREG*  bb_reg_ptr;
static bool g_bIsRunning = false;

static void REQ_ReadRegister(void)
{
    bb_reg_ptr->REQ_ReadRegister();
}

static void __stdcall CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData)
{
    bb_reg_ptr->CNF_ReadRegister(cnf, token, usrData);
}

static void REQ_WriteRegister(void)
{
    bb_reg_ptr->REQ_WriteRegister();
}

static void __stdcall CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData)
{
    bb_reg_ptr->CNF_WriteRegister(cnf, token, usrData);
}


CBBREG::CBBREG(void)
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
    m_sBBID_REG = 0;
    m_uiAddress = 0;
    m_usValue = 0;
    m_uibitCount = 0;
    m_bCnfOk = false;
    m_hEvent = NULL;

}

CBBREG::~CBBREG( )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
}

void CBBREG::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }
    g_bIsRunning = false;
    if (!ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

/*void CBBREG::REQ_Stop(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    SP_META_Cancel_r(m_META_HANDLE_Obj.Get_MainHandle(), m_sBBID_REG);
    Confirm(METAAPP_STOP);
}*/

void  CBBREG::REQ_ReadRegister_Start(unsigned int addr, unsigned int bitCount)
{
    bb_reg_ptr = this;
    g_bIsRunning  = true;
    m_uiAddress = addr;
    m_uibitCount = bitCount;
    ActiveMan->SetActiveFunction(::REQ_ReadRegister);
}

void CBBREG::REQ_ReadRegister(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

    CPU_REG_READ_REQ req;
    req.addr  = m_uiAddress;
    req.bytenum = m_uibitCount;
    META_RESULT MetaResult;// = SP_META_BB_RegRead_r(m_META_HANDLE_Obj.Get_MainHandle(), &req, ::CNF_ReadRegister, &m_sBBID_REG, NULL);

    DWORD wait_result = WaitForSingleObject(m_hEvent, 5000);
    CloseHandle(m_hEvent);
    if (WAIT_TIMEOUT == wait_result)
    {
        Confirm(META_TIMEOUT);
        return;
    }

    if ((MetaResult != META_SUCCESS) || (!m_bCnfOk))
    {
        Confirm(META_FAILED);
        return;
    }
    Confirm(META_SUCCESS);
}

void __stdcall CBBREG::CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (cnf->status != BB_STATUS_SUCCESS)
    {
        m_bCnfOk = false;
        return;
    }
    m_bCnfOk = true;
    m_usValue = cnf->value;
    SetEvent(m_hEvent);
}

void  CBBREG::REQ_WriteRegister_Start(unsigned int addr, unsigned int bitCount, unsigned short value)
{
    bb_reg_ptr = this;
    g_bIsRunning  = true;
    m_uiAddress = addr;
    m_uibitCount   = bitCount;
    m_usValue   = value;
    ActiveMan->SetActiveFunction(::REQ_WriteRegister);
}

void CBBREG::REQ_WriteRegister(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

    CPU_REG_WRITE_REQ req;
    req.addr  = m_uiAddress;
    req.value = m_usValue;
    META_RESULT MetaResult;// = SP_META_BB_RegWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), &req, ::CNF_WriteRegister, &m_sBBID_REG, NULL);

    DWORD wait_result = WaitForSingleObject(m_hEvent, 5000);
    CloseHandle(m_hEvent);
    if (WAIT_TIMEOUT == wait_result)
    {
        Confirm(META_TIMEOUT);
        return;
    }

    if ((MetaResult != META_SUCCESS) || (!m_bCnfOk))
    {
        Confirm(META_FAILED);
        return;
    }
    Confirm(META_SUCCESS);
}

void __stdcall CBBREG::CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData)
{
    if (!g_bIsRunning)
    {
        return;
    }

    if (cnf->status != BB_STATUS_SUCCESS)
    {
        m_bCnfOk = false;
        return;
    }
    m_bCnfOk = true;
    SetEvent(m_hEvent);
}

META_RESULT CBBREG::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

unsigned short CBBREG::Get_RegValue( void )
{
    return  m_usValue;
}
