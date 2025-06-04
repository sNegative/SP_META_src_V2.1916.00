#pragma hdrstop
#include "metaapp_common.h"
#include "bb_common.h"
#include "bb_x.h"
#include "man_active.h"
#include "LogicalControlBase.h"
#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif


#ifndef  _MAN_ERROR_H_
#include "man_error.h"
#endif
extern AnsiString chipVersion;
extern AnsiString softwareVersion;

static CBaseBand*  g_bb_ptr;

static void REQ_QueryRTCTime(void)
{
    g_bb_ptr->REQ_QueryRTCTime();
}
static void  REQ_SetVibratorOnOff(void)
{
    g_bb_ptr->REQ_SetVibratorOnOff();
}
static void  REQ_SetKeypadLEDOnOff(void)
{
    g_bb_ptr->REQ_SetKeypadLEDOnOff();
}
static void  REQ_SetLCDLEDLightLevel(void)
{
    g_bb_ptr->REQ_SetLCDLEDLightLevel();
}
static void  REQ_SetSignalIndicatorOnOff(void)
{
    g_bb_ptr->REQ_SetSignalIndicatorOnOff();
}

static void REQ_ReadRegister(void)
{
    g_bb_ptr->REQ_ReadRegister();
}

static void REQ_ECCIPortTest(void)
{
   // g_bb_ptr->REQ_ECCIPortTest();
}

static void __stdcall CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData)
{
    g_bb_ptr->CNF_ReadRegister(cnf, token, usrData);
}

static void REQ_WriteRegister(void)
{
    g_bb_ptr->REQ_WriteRegister();
}

static void REQ_CleanBoot(void)
{
    g_bb_ptr->REQ_CleanBoot();
}

static void __stdcall CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData)
{
    g_bb_ptr->CNF_WriteRegister(cnf, token, usrData);
}

//============================================
void CBaseBand::REQ_QueryRTCTime(void)
{
    DoMetaResult(SP_META_QueryLocalTime_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sRTC));
}

void  CBaseBand::REQ_SetVibratorOnOff(void)
{
    DoMetaResult(SP_META_SetVibratorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &m_sVBROnOff));

}


//void  CBaseBand::REQ_ECCIPortTest(void)
//{
 //   DoMetaResult(SP_META_EciPortTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, m_tIndex));

//}

META_RESULT CBaseBand::ADC_GetBatVol(int* pVol)
{
    return SP_META_ADC_GetBatVol_r(m_META_HANDLE_Obj.Get_MainHandle(), 2000 , pVol);
}

META_RESULT CBaseBand::ADC_GetBatCapacity(int* pCapacity)
{
    return SP_META_ADC_GetBatCapacity_r(m_META_HANDLE_Obj.Get_MainHandle(), 2000 , pCapacity);
}

void  CBaseBand::REQ_SetVibratorOnOff_HWT(void)
{

    m_sVBROnOff.LedNum = 0;
    m_sVBROnOff.OFFON = 1;
    META_RESULT res1,res2;
    res1 = SP_META_SetVibratorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &m_sVBROnOff);   // The time is just for hw test
    Sleep(2000);
    m_sVBROnOff.OFFON = 0;
    res2 = SP_META_SetVibratorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &m_sVBROnOff);

    if(META_SUCCESS == res1 && META_SUCCESS == res2)
        m_iConfirmState = META_SUCCESS;
    else
        m_iConfirmState = META_FAILED;
    ConfirmCallback();


}

void CBaseBand::REQ_SetLCMDefaultImage_HWT(void)
{
    m_sLCDLevel.lcd_light_level = 2;
    LCDFt_REQ req;
    LCDFt_CNF cnf;
    req.time_duration = 2000;
    META_RESULT res1;
    res1 = SP_META_LcdColorTest_r(m_META_HANDLE_Obj.Get_MainHandle(),5000, &req, &cnf);
    Sleep(2000);

    if(META_SUCCESS == res1)
        m_iConfirmState = META_SUCCESS;
    else
        m_iConfirmState = META_FAILED;
    ConfirmCallback();
}


void  CBaseBand::REQ_SetKPLEDOnOff_HWT(void)
{

    m_sLEDKeypad.onoff = 1;
    unsigned char level;
    AnsiString ansi_str = "8";
    AnsiString_To_UnsignedChar(ansi_str, level, 0, 255);
    m_sLEDKeypad.DUTY = level;
    m_sLEDKeypad.DIV = level;
    META_RESULT res1,res2;
    res1 = SP_META_SetLEDLightLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sLEDKeypad);
    Sleep(2000);
    m_sLEDKeypad.onoff = 0;
    res2 = SP_META_SetLEDLightLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sLEDKeypad);
    if(META_SUCCESS == res1 && META_SUCCESS == res2)
        m_iConfirmState = META_SUCCESS;
    else
        m_iConfirmState = META_FAILED;
    ConfirmCallback();

}


void  CBaseBand::REQ_SetLCMBLOnOff_HWT(void)
{

    m_sLCDLevel.lcd_light_level = 2;
    META_RESULT res1,res2,res3;
    res1 = SP_META_SetMainSubLCDLightLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sLCDLevel);
    Sleep(500);
    m_sLCDLevel.lcd_light_level = 8;
    res2 = SP_META_SetMainSubLCDLightLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sLCDLevel);
    Sleep(500);
    m_sLCDLevel.lcd_light_level = 5;
    res3 = SP_META_SetMainSubLCDLightLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sLCDLevel);
    if(META_SUCCESS == res1 && META_SUCCESS == res2 && META_SUCCESS == res3)
        m_iConfirmState = META_SUCCESS;
    else
        m_iConfirmState = META_FAILED;
    ConfirmCallback();

}


void  CBaseBand::REQ_SetIndicatorOnOff_HWT(void)
{
    META_RESULT res1,res2,res3;
    res1 = SP_META_SetSignalIndicatorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sSignalIndicatorOnOff);
    Sleep(2000);

    m_sSignalIndicatorOnOff.OFFON = 1;
    m_sSignalIndicatorOnOff.LedNum = 1;
    res1 = SP_META_SetSignalIndicatorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sSignalIndicatorOnOff);
    Sleep(1000);
    m_sSignalIndicatorOnOff.OFFON = 0;
    res1 = SP_META_SetSignalIndicatorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sSignalIndicatorOnOff);
    Sleep(500);

    m_sSignalIndicatorOnOff.OFFON = 1;
    m_sSignalIndicatorOnOff.LedNum = 2;
    res2 = SP_META_SetSignalIndicatorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sSignalIndicatorOnOff);
    Sleep(1000);
    m_sSignalIndicatorOnOff.OFFON = 0;
    res2 = SP_META_SetSignalIndicatorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sSignalIndicatorOnOff);
    Sleep(500);

    m_sSignalIndicatorOnOff.OFFON = 1;
    m_sSignalIndicatorOnOff.LedNum = 3;
    res3 = SP_META_SetSignalIndicatorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sSignalIndicatorOnOff);
    Sleep(1000);
    m_sSignalIndicatorOnOff.OFFON = 0;
    res3 = SP_META_SetSignalIndicatorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sSignalIndicatorOnOff);

    if(META_SUCCESS == res1 && META_SUCCESS == res2 && META_SUCCESS == res3)
        m_iConfirmState = META_SUCCESS;
    else
        m_iConfirmState = META_FAILED;
    ConfirmCallback();
}

void CBaseBand::REQ_SetKeypadLEDOnOff(void)
{
//        if(chipVersion == "MT6573")
    if(chipVersion!="MT6516")
    {
        //DoMetaResult(SP_META_SetLEDLightLevelforMT6573_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sVBROnOff));
    }
    else
    {
        //DoMetaResult(SP_META_SetLEDLightLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sLEDKeypad));
    }
}

void CBaseBand::REQ_SetLCDLEDLightLevel(void)
{
    DoMetaResult(SP_META_SetMainSubLCDLightLevel_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sLCDLevel));
}

void  CBaseBand::REQ_SetSignalIndicatorOnOff(void)
{
    DoMetaResult(SP_META_SetSignalIndicatorOnOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 1000, &m_sSignalIndicatorOnOff));
}

void CBaseBand::REQ_ReadRegister(void)
{
    m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    m_bCnfOk = false;

    META_RESULT MetaResult;// = SP_META_BB_RegRead_r(m_META_HANDLE_Obj.Get_MainHandle(), &m_sRegReadReq, ::CNF_ReadRegister, &m_sBBID_REG, NULL);
    DWORD wait_result = WaitForSingleObject(m_hEvent, 3000);
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

void __stdcall CBaseBand::CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData)
{
    if (!m_bIsRunning)
    {
        return;
    }

    if (STATUS_OK_DIRVER != cnf->status)
    {
        m_bCnfOk = false;
    }
    else
    {
        m_bCnfOk = true;
        m_usValue = cnf->value;
    }
    SetEvent(m_hEvent);
}

void CBaseBand::REQ_WriteRegister(void)
{
    m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
    META_RESULT MetaResult;// = SP_META_BB_RegWrite_r(m_META_HANDLE_Obj.Get_MainHandle(), &m_sRegWriteReq, ::CNF_WriteRegister, &m_sBBID_REG, NULL);

    DWORD wait_result = WaitForSingleObject(m_hEvent, 3000);
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

void CBaseBand::REQ_CleanBoot(void)
{
    DoMetaResult(SP_META_Clean_Boot_r(m_META_HANDLE_Obj.Get_MainHandle(), 2000));
}

void __stdcall CBaseBand::CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData)
{
    if (!m_bIsRunning)
    {
        return;
    }

    if (STATUS_OK_DIRVER != cnf->status)
    {
        m_bCnfOk = false;
    }
    else
    {
        m_bCnfOk = true;
    }

    SetEvent(m_hEvent);
}

void CBaseBand::REQ_Start(REQ_CMDTYPE rct, void (*cb)(void))
{
    ConfirmCallback = cb;
    g_bb_ptr = this;
    m_bIsRunning = true;

    switch(rct)
    {
    case BB_SET_VIBRATOR_ONOFF:
        ActiveMan->SetActiveFunction(::REQ_SetVibratorOnOff);
        break;
    case BB_QUERY_RTC_TIME:
        ActiveMan->SetActiveFunction(::REQ_QueryRTCTime);
        break;
    case BB_SET_KEYPADLED_ONOFF:
        ActiveMan->SetActiveFunction(::REQ_SetKeypadLEDOnOff);
        break;
    case BB_SET_LCDLED_LIGHTLEVEL:
        ActiveMan->SetActiveFunction(::REQ_SetLCDLEDLightLevel);
        break;
    case BB_SET_SIGNAL_INDICATOR_ONOFF:
        ActiveMan->SetActiveFunction(::REQ_SetSignalIndicatorOnOff);
        break;
    case BB_READ_REGISTER:
        ActiveMan->SetActiveFunction(::REQ_ReadRegister);
        break;
    case BB_WRITE_REGISTER:
        ActiveMan->SetActiveFunction(::REQ_WriteRegister);
        break;
    case CLEAN_BOOT:
        ActiveMan->SetActiveFunction(::REQ_CleanBoot);
        break;
    case ECCI_TEST:
        ActiveMan->SetActiveFunction(::REQ_ECCIPortTest);
        break;

    default:
        break;
    }
}

