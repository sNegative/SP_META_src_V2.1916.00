#include <IniFiles.hpp>
#pragma hdrstop

#include "meta.h"
#include "bb_common.h"
#include "bb_pmic_reg.h"
#include "man_active.h"
extern AnsiString chipVersion;
//===========================================================================
static CBBPMICREG*  g_pmic_reg_ptr;
static bool g_bIsRunning;

//===========================================================================
static void REQ_ReadRegister(void)
{
    g_pmic_reg_ptr->REQ_ReadRegister();
}

//---------------------------------------------------------------------------
static void REQ_WriteRegister(void)
{
    g_pmic_reg_ptr->REQ_WriteRegister();
}

//===========================================================================
CBBPMICREG::CBBPMICREG(void)
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_sBBID_REG = 0;
    m_uiRegNumber = 0;
    m_usValue = 0;
    m_pvPmicReg = NULL;

}

//---------------------------------------------------------------------------
CBBPMICREG::~CBBPMICREG()
{
    g_bIsRunning = false;
    ConfirmCallback = 0;

    EraseVector();
    DeAllocateVector();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void  CBBPMICREG::AllocateVector(void)
{
    if (!m_pvPmicReg)
    {
        m_pvPmicReg = new vector<S_BB_PMIC_REG_T>;
    }
}

//--------------------------------------------------------------------------
void  CBBPMICREG::DeAllocateVector(void)
{
    if (m_pvPmicReg)
    {
        delete m_pvPmicReg;
        m_pvPmicReg = NULL;
    }
}

//--------------------------------------------------------------------------
void  CBBPMICREG::EraseVector(void)
{
    if (m_pvPmicReg)
    {
        if (! m_pvPmicReg->empty())
        {
            m_pvPmicReg->erase(m_pvPmicReg->begin(), m_pvPmicReg->end());
        }
    }
}

//---------------------------------------------------------------------------
void  CBBPMICREG::REQ_Finish(void)
{
    if (!g_bIsRunning)
        return;

    Confirm(META_SUCCESS);
    g_bIsRunning = false;
}

//---------------------------------------------------------------------------
/*void  CBBPMICREG::REQ_Stop(void)
{
    if (!g_bIsRunning)
		return;

    SP_META_Cancel_r(m_META_HANDLE_Obj.Get_MainHandle(), m_sBBID_REG);
    Confirm(METAAPP_STOP);
    g_bIsRunning = false;
}  */

//---------------------------------------------------------------------------
void  CBBPMICREG::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
        return;

    if(!ConfirmCallback)
        return;
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

//===========================================================================
void  CBBPMICREG::REQ_ReadRegister_Start(unsigned int addr)
{
    g_pmic_reg_ptr = this;
    g_bIsRunning  = true;

    m_uiRegNumber = addr;

    ActiveMan->SetActiveFunction(::REQ_ReadRegister);
}

//-------------------------------------
void CBBPMICREG::REQ_ReadRegister(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult ;
    if(chipVersion == "MT6573")
    {
        WM_CMD_ReadPMICRegister_DWORD_REQ_T req;
        WM_CMD_ReadRegister_DWORD_CNF_T cnf;
        req.registernumber = m_uiRegNumber;
        cnf.status = 1;
        cnf.value = 0;
        //MetaResult = SP_META_PMIC_RegRead_DWORD_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req, &cnf);
        if (MetaResult !=META_SUCCESS || STATUS_OK_DIRVER != cnf.status)
        {
            Confirm( META_FAILED );
            return;
        }

        m_usValue = cnf.value;

        Confirm(META_SUCCESS);
    }
    else
    {
        WM_CMD_ReadPMICRegister_REQ_T req;
        WM_CMD_ReadRegister_CNF_T cnf;
        req.registernumber = m_uiRegNumber;
        cnf.status = 1;
        cnf.value = 0;
        META_RESULT MetaResult;// = SP_META_PMIC_RegRead_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req, &cnf);

        if (MetaResult !=META_SUCCESS || STATUS_OK_DIRVER != cnf.status)
        {
            Confirm( META_FAILED );
            return;
        }

        m_usValue = cnf.value;

        Confirm(META_SUCCESS);

    }


}

//===========================================================================
void  CBBPMICREG::REQ_WriteRegister_Start(unsigned int addr, unsigned short value)
{
    g_pmic_reg_ptr = this;
    g_bIsRunning  = true;

    m_uiRegNumber = addr;
    m_usValue   = value;

    ActiveMan->SetActiveFunction(::REQ_WriteRegister);
}

//-------------------------------------
void CBBPMICREG::REQ_WriteRegister(void)
{
    if (!g_bIsRunning)
    {
        return;
    }
    META_RESULT MetaResult;
    if(chipVersion == "MT6573")
    {
        WM_CMD_WritePMICRegister_DWORD_REQ_T req;
        WM_CMD_WriteRegister_DWORD_CNF_T cnf;
        req.registernumber = m_uiRegNumber;
        req.registervalue = m_usValue;
        cnf.status = 1;
        cnf.value = 0;
        //MetaResult = SP_META_PMIC_RegWrite_DWORD_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req, &cnf);

        if (MetaResult !=META_SUCCESS || STATUS_OK_DIRVER != cnf.status)
        {
            Confirm(META_FAILED);
            return;
        }

        Confirm(META_SUCCESS);
    }
    else
    {
        WM_CMD_WritePMICRegister_REQ_T req;
        WM_CMD_WriteRegister_CNF_T cnf;
        req.registernumber = m_uiRegNumber;
        req.registervalue = m_usValue;
        cnf.status = 1;
        cnf.value = 0;
        META_RESULT MetaResult;// = SP_META_PMIC_RegWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req, &cnf);

        if (MetaResult !=META_SUCCESS || STATUS_OK_DIRVER != cnf.status)
        {
            Confirm(META_FAILED);
            return;
        }

        Confirm(META_SUCCESS);
    }


}

void  CBBPMICREG::REQ_SetRegister_HWT(void)
{
    WM_CMD_WritePMICRegister_REQ_T req;
    WM_CMD_WriteRegister_CNF_T cnf;
    req.registernumber = 81;
    req.registervalue = 80;
    cnf.status = 1;
    cnf.value = 0;
    META_RESULT res1;// = SP_META_PMIC_RegWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req, &cnf);
    /*    req.registernumber = 82;
        req.registervalue = 8;
        META_RESULT res2 = META_PMIC_RegWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req, &cnf);
        req.registernumber = 82;
        req.registervalue = 0;
        META_RESULT res3 = META_PMIC_RegWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &req, &cnf);
    */
    if (res1 != META_SUCCESS)
        m_eConfirmState = META_FAILED;
    else
        m_eConfirmState = META_SUCCESS;
    ConfirmCallback();

}

//===========================================================================
////////////////////////////        INI file      ///////////////////////////
//===========================================================================
static AnsiString as_SECTION_NAME = "PMIC register";
static AnsiString as_KEY_NAME_COUNT = "register count";
//---------------------------------------------------------------------------
bool  CBBPMICREG::PMICRegisterSectionExist(char *filename)
{
    TIniFile *ini_file = new TIniFile( filename );
    if (!ini_file)
        return false;

    if (ini_file->SectionExists(as_SECTION_NAME))
    {
        delete ini_file;
        return true;
    }
    delete ini_file;
    return false;
}

//---------------------------------------------------------------------------
bool  CBBPMICREG::REQ_Read_From_File(char *filename)
{
    TIniFile   *ini_file = new TIniFile(filename);
    if (ini_file)
        return false;

    if (!m_pvPmicReg)
    {
        AllocateVector();
    }

    EraseVector();

    AnsiString as;
    unsigned int ui_count;
    ui_count = ini_file->ReadInteger(as_SECTION_NAME, as_KEY_NAME_COUNT, 0);

    for (unsigned int i=0; i<ui_count; i++)
    {
        S_BB_PMIC_REG_T pmic_reg;
        as = "register " + IntToStr(i) + " index";
        pmic_reg.us_index = ini_file->ReadInteger(as_SECTION_NAME, as, 0);

        as = "register " + IntToStr(i) + " name";
        pmic_reg.as_name  = ini_file->ReadString(as_SECTION_NAME, as, "");

        as = "register " + IntToStr(i) + " value";
        pmic_reg.uc_value = ini_file->ReadInteger(as_SECTION_NAME, as, 0);

        m_pvPmicReg->push_back(pmic_reg);
    }

    delete  ini_file;
    return  true;
}

//---------------------------------------------------------------------------
bool  CBBPMICREG::REQ_Write_To_File(char *filename)
{

    return true;
}

//===========================================================================
////////////////////////////         Query        ///////////////////////////
//===========================================================================
bool CBBPMICREG::Query_PMIC_ID_Start(void)
{
    META_RESULT MetaResult;// = SP_META_QueryPMICID_r(m_META_HANDLE_Obj.Get_MainHandle(), 300, &m_sPmicId);
    if (META_SUCCESS != MetaResult)
    {
        return false;
    }
    return true;
}



//===========================================================================
////////////////////////////  Global information  ///////////////////////////
//===========================================================================
META_RESULT CBBPMICREG::Get_ConfirmState(void)
{
    return  m_eConfirmState;
}

//---------------------------------------------------------------------------
unsigned short CBBPMICREG::Get_RegValue(void)
{
    return  m_usValue;
}

//---------------------------------------------------------------------------
PMIC_ID* CBBPMICREG::Get_PMIC_ID(void)
{
    return  &m_sPmicId;
}

//---------------------------------------------------------------------------
vector<S_BB_PMIC_REG_T>* CBBPMICREG::Get_PMICRegVector(void)
{
    return m_pvPmicReg;
}
