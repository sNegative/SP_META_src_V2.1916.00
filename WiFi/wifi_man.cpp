#pragma hdrstop

#ifndef  _WIFI_MAN_H_
#include "wifi_man.h"
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

static CWiFiMan*  g_wifiman_ptr;
static bool g_bIsRunning = false;


static void REQ_WIFI_READ_EEPROM(void)
{
    g_wifiman_ptr->REQ_WIFI_READ_EEPROM();
}

static void REQ_WIFI6620_READ_EEPROM(void)
{
    g_wifiman_ptr->REQ_WIFI6620_READ_EEPROM();
}

static void REQ_WIFI_READALL_EEPROM(void)
{
    g_wifiman_ptr->REQ_WIFI_READALL_EEPROM();
}

CWiFiMan::CWiFiMan(void)
{
    memset(m_strEEbuf,0,2048);
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}

CWiFiMan::~CWiFiMan()
{
    g_bIsRunning = false;
    ConfirmCallback = NULL;
}

void CWiFiMan::REQ_WIFI6620_READ_EEPROM_Start(void)
{
    g_wifiman_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_WIFI6620_READ_EEPROM);
}

void CWiFiMan::REQ_WIFI_READ_EEPROM_Start(void)
{
    g_wifiman_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_WIFI_READ_EEPROM);
}


void CWiFiMan::REQ_WIFI6620_READ_EEPROM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    unsigned short  u2EepromSz = 512;
    unsigned short  u2EepromValue = 0;
    unsigned long   u4Tmp = 0;
    memset(m_strEEbuf,0,2048);
    for(int u2Tmp = 0; u2Tmp < u2EepromSz/2; u2Tmp++)
    {

        META_RESULT mr = SP_META_WiFi_readEEPRom16_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, u2Tmp, &u4Tmp);

        if(META_SUCCESS != mr)
        {

            //  OutputLog(" Error: EEPROM save as file failed");
            //  CurrentPageReset();
            Confirm(META_FAILED);
            return ;
        }
        u2EepromValue = (unsigned short) u4Tmp;


        char strBuf[10] = {0};
        sprintf(strBuf, "%04X", u2EepromValue);
        strcat(m_strEEbuf, strBuf);
    }
    Confirm(META_SUCCESS);
}

void CWiFiMan::REQ_WIFI_READ_EEPROM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    unsigned short  u2EepromSz = 512;
    unsigned short  u2EepromValue = 0;
    unsigned long   u4Tmp = 0;
    memset(m_strEEbuf,0,2048);
    for(int u2Tmp = 0; u2Tmp < u2EepromSz/2; u2Tmp++)
    {
#ifdef TEST
        u2EepromValue = (unsigned short) u4Tmp;
        u4Tmp++;
#else
        META_RESULT mr = SP_META_WiFi_readEEPRom16_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, u2Tmp, &u4Tmp);
        if(META_SUCCESS != mr)
        {
            Confirm(META_FAILED);
            return ;
        }
        u2EepromValue = (unsigned short) u4Tmp;
#endif

        char strBuf[10] = {0};
        sprintf(strBuf, "%04X", u2EepromValue);
        strcat(m_strEEbuf, strBuf);
    }
    Confirm(META_SUCCESS);
}


void CWiFiMan::REQ_WIFI_READALL_EEPROM_Start(void)
{
    g_wifiman_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction(::REQ_WIFI_READALL_EEPROM);
}


void CWiFiMan::REQ_WIFI_READALL_EEPROM(void)
{
    if (!g_bIsRunning)
    {
        return;
    }

    unsigned short  u2EepromSz = 512;
    unsigned short  u2EepromValue = 0;
    unsigned long   u4Tmp = 0;
    unsigned long   count = 0;
    memset(m_strEEbuf,0,2048);

    for(int u2Tmp = 0; u2Tmp < u2EepromSz/2; u2Tmp++)
    {

        META_RESULT mr = SP_META_WiFi_readEEPRom16_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, u2Tmp, &u4Tmp);
        if(META_SUCCESS != mr)
        {
            //    OutputLog(" Error: EEPROM read all failed");
            //    CurrentPageReset();
            Confirm(META_FAILED);
            return ;
        }
        u2EepromValue = (unsigned short) u4Tmp;


        if((u2Tmp % 8) == 0)
        {
            char strBuf2[20] = {0};
            sprintf(strBuf2, "%08X: ", count * 0x0010);
            count++;
            strcat(m_strEEbuf, strBuf2);
        }

        char strBuf[20] = {0};
        unsigned char highByte = (u2EepromValue >> 8) & 0x00FF;
        unsigned char lowByte = (u2EepromValue) & 0x00FF;
        sprintf(strBuf, "%02X %02X ", highByte, lowByte);
        strcat(m_strEEbuf, strBuf);

        if((u2Tmp % 8) == 0xF)
        {
            char strBuf3[10] = {0};
            sprintf(strBuf3, "\r\n");
            strcat(m_strEEbuf, strBuf3);
        }
    }
    Confirm(META_SUCCESS);
}

//---------------------------------------------------------------------------
void CWiFiMan::Confirm(META_RESULT confirm_state)
{
    if (!g_bIsRunning)
    {
        return;
    }
    if (NULL == ConfirmCallback)
    {
        return;
    }
    m_eConfirmState = confirm_state;
    ActiveMan->SetActiveFunction(ConfirmCallback);
}

META_RESULT CWiFiMan::Get_ConfirmState(void)
{
    return m_eConfirmState;
}

char* CWiFiMan::GetEEBuffer()
{
    return m_strEEbuf;
}


META_RESULT CWiFiMan::WiFi_readMCR32(unsigned int ms_timeout, unsigned int offset, unsigned long *value)
{
    return SP_META_WiFi_readMCR32_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, offset, value);
}

META_RESULT CWiFiMan::WiFi_writeMCR32(unsigned int ms_timeout, unsigned int offset, unsigned int value)
{
    return SP_META_WiFi_writeMCR32_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, offset, value);
}

META_RESULT CWiFiMan::WiFi_WriteNVRAM(unsigned int ms_timeout, NVRAM_ACCESS_STRUCT * pReq)
{
    return SP_META_WiFi_WriteNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pReq);
}

META_RESULT CWiFiMan::WiFi_ReadNVRAM(unsigned int ms_timeout,NVRAM_ACCESS_STRUCT * pReq)
{
    return SP_META_WiFi_ReadNVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pReq);
}


META_RESULT CWiFiMan::WiFi_QueryConfig(unsigned int ms_timeout, ENUM_CFG_SRC_TYPE_T *bufType)
{
    return SP_META_WiFi_QueryConfig_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, bufType);
}

META_RESULT CWiFiMan::WiFi_setTestMode(unsigned int ms_timeout)
{
    return SP_META_WiFi_setTestMode_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_switchAntenna(unsigned int ms_timeout, unsigned int value)
{
    return SP_META_WiFi_switchAntenna_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}


META_RESULT CWiFiMan::WiFi_readEEPRom16(unsigned int ms_timeout, unsigned int offset, unsigned long *value)
{
    return SP_META_WiFi_readEEPRom16_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, offset, value);
}

META_RESULT CWiFiMan::WiFi_writeEEPRom16(unsigned int ms_timeout, unsigned int offset, unsigned int value)
{
    return SP_META_WiFi_writeEEPRom16_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, offset, value);
}

META_RESULT CWiFiMan::WiFi_eepromReadByteStr(unsigned int ms_timeout, unsigned int u4Addr, unsigned int u4Length, char *pszStr)
{
    return SP_META_WiFi_eepromReadByteStr_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, u4Addr, u4Length, pszStr);
}

META_RESULT CWiFiMan::WiFi_eepromWriteByteStr(unsigned int ms_timeout, unsigned int u4Addr, unsigned int u4Length, char *pszStr)
{
    return SP_META_WiFi_eepromWriteByteStr_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, u4Addr, u4Length, pszStr);
}

META_RESULT CWiFiMan::WiFi_setChannel(unsigned int ms_timeout, int channelConfig)
{
    return SP_META_WiFi_setChannel_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, channelConfig);
}

META_RESULT CWiFiMan::WiFi_readTxPower(unsigned int ms_timeout, unsigned long *value)
{
    return SP_META_WiFi_readTxPower_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_setPacketTxEx(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam)
{
    return SP_META_WiFi_setPacketTxEx_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pTxParam);
}

META_RESULT  CWiFiMan::WiFi_setOutputPower(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam)
{
    return SP_META_WiFi_setOutputPower_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pTxParam);
}

META_RESULT CWiFiMan::WiFi_setDutyCycle(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam, int nCWMode)
{
    return SP_META_WiFi_setDutyCycle_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pTxParam, nCWMode);
}

META_RESULT CWiFiMan::WiFi_setCarrierSuppression(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam)
{
    return SP_META_WiFi_setCarrierSuppression_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pTxParam);
}

META_RESULT CWiFiMan::WiFi_setLocalFrequecy(unsigned int ms_timeout, int txPower, int txAntenna)
{
    return SP_META_WiFi_setLocalFrequecy_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, txPower, txAntenna);
}

META_RESULT CWiFiMan::WiFi_setCWMode(unsigned int ms_timeout, int nTxRate, int nCWModeType)
{
    return SP_META_WiFi_setCWMode_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, nTxRate, nCWModeType);
}

META_RESULT CWiFiMan::WiFi_setNormalMode(unsigned int ms_timeout)
{
    return SP_META_WiFi_setNormalMode_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_setPnpPower(unsigned int ms_timeout, int i4PowerMode)
{
    return SP_META_WiFi_setPnpPower_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, i4PowerMode);
}

META_RESULT CWiFiMan::WiFi_setStandBy(unsigned int ms_timeout)
{
    return SP_META_WiFi_setStandBy_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_setRate(unsigned int ms_timeout,unsigned long value)
{
    return SP_META_WiFi_setRate_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_setRxTest(unsigned int ms_timeout)
{
    return SP_META_WiFi_setRxTest_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_readEFuseAddr(unsigned int ms_timeout,unsigned int addr,unsigned long *value)
{
    return SP_META_WiFi_readEFuseAddr_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, addr, value);
}


META_RESULT CWiFiMan::WiFi_writeEFuseAddr(unsigned int ms_timeout,unsigned int addr,unsigned int value)
{
    return SP_META_WiFi_writeEFuseAddr_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, addr, value);
}

META_RESULT CWiFiMan::WiFi_setBandwidth(unsigned int ms_timeout,unsigned int value)
{
    return SP_META_WiFi_setBandwidth_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_setGuardinterval(unsigned int ms_timeout,unsigned int value)
{
    return SP_META_WiFi_setGuardinterval_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_setModeSelect(unsigned int ms_timeout,unsigned int value)
{
    return SP_META_WiFi_setModeSelect_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_queryThermoInfo(unsigned int ms_timeout, long * pi4Enable, unsigned long * pu4RawVal)
{
    return SP_META_WiFi_queryThermoInfo_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pi4Enable, pu4RawVal);
}

META_RESULT CWiFiMan::WiFi_setTxRxIQCalibration( unsigned int ms_timeout)
{
    return SP_META_WiFi_setTxRxIQCalibration_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_getCalResult(unsigned int ms_timeout, unsigned int index, unsigned int offset, unsigned long * data)
{
    return SP_META_WiFi_getCalResult_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout , index , offset, data);
}

META_RESULT CWiFiMan::WiFi_getTemperatureSensorResult( unsigned int ms_timeout, unsigned long *value)
{
    return SP_META_WiFi_getTemperatureSensorResult_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_getVoltageSensorResult(unsigned int ms_timeout, unsigned long *value)
{
    return SP_META_WiFi_getVoltageSensorResult_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_getResultInformation( unsigned int ms_timeout, unsigned int index, unsigned long * length)
{
    return SP_META_WiFi_getResultInformation_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, index , length);
}

META_RESULT CWiFiMan::WiFi_setDPDCalibration( unsigned int ms_timeout)
{
    return SP_META_WiFi_setDPDCalibration_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_SetATParam(unsigned int ms_timeout, unsigned int offset, unsigned int value)
{
    return SP_META_WiFi_SetATParam_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, offset, value);
}

META_RESULT CWiFiMan::WiFi_TSSICalibration( unsigned int ms_timeout)
{
    return SP_META_WiFi_TSSICalibration_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_GetChipVersion( unsigned int ms_timeout,unsigned long * chipVersion)
{
    return SP_META_WiFi_GetChipVersion_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, chipVersion);
}

META_RESULT CWiFiMan::WiFi_GetATParam(unsigned int ms_timeout, unsigned int offset, unsigned long *value)
{
    return SP_META_WiFi_GetATParam_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, offset, value);
}

META_RESULT CWiFiMan::WiFi_ReceivedErrorCount(unsigned int ms_timeout, unsigned long * value)
{
    return SP_META_WiFi_ReceivedErrorCount_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_ReceivedOKCount(unsigned int ms_timeout, unsigned long * value)
{
    return SP_META_WiFi_ReceivedOKCount_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout , value);
}

META_RESULT CWiFiMan::WiFi_ReceivedRSSI(unsigned int ms_timeout, long * value)
{
    return SP_META_WiFi_ReceivedRSSI_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout , value);
}

META_RESULT CWiFiMan::WiFi_ReceivedRSSI1(unsigned int ms_timeout, long * value)
{
    return SP_META_WiFi_ReceivedRSSI1_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout , value);
}

META_RESULT CWiFiMan::WiFi_getChannel(unsigned int ms_timeout, long *channelConfig_p)
{
    return SP_META_WiFi_getChannel_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, channelConfig_p);
}

META_RESULT CWiFiMan::WiFi_readTxPowerFromEEPromEx(unsigned int ms_timeout, int channelFreq,
                                             int rate, long *nTxPwr, long *outputPower, long *targetAlc)
{
    return SP_META_WiFi_readTxPowerFromEEPromEx_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout,
                     channelFreq, rate, nTxPwr, outputPower, targetAlc);
}

META_RESULT CWiFiMan::WiFi_setPacketRx(unsigned int ms_timeout, int condition, int nAntenna)
{
    return SP_META_WiFi_setPacketRx_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, condition, nAntenna);
}

META_RESULT CWiFiMan::WiFi_getPacketRxStatus(unsigned int ms_timeout, WIFI_RXSTATUS_T *pRxStatus)
{
    return SP_META_WiFi_getPacketRxStatus_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pRxStatus);
}

META_RESULT CWiFiMan::WiFi_setXtalTrimToCr(unsigned int ms_timeout, unsigned int u4Value)
{
    return SP_META_WiFi_setXtalTrimToCr_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, u4Value);
}

META_RESULT CWiFiMan::WiFi_setThermoEn(unsigned int ms_timeout, long i4Enable)
{
    return SP_META_WiFi_setThermoEn_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, i4Enable);
}

META_RESULT CWiFiMan::WiFi_setOutputPin(unsigned int ms_timeout, int pinIndex, int outputLevel)
{
    return SP_META_WiFi_setOutputPin_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, pinIndex, outputLevel); //IO_PIN_LCR
}

META_RESULT CWiFiMan::WiFi_ReadConfigData(unsigned int ms_timeout, unsigned int offset, unsigned long *value, ENUM_CFG_SRC_TYPE_T type)
{
    return SP_META_WiFi_ReadConfigData_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, offset, value, type);
}

META_RESULT CWiFiMan::WiFi_Open(unsigned int ms_timeout)
{
    return SP_META_WIFI_OPEN_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_Close(unsigned int ms_timeout)
{
    return SP_META_WIFI_CLOSE_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout);
}

META_RESULT CWiFiMan::WiFi_setBandwidthEx(unsigned int ms_timeout, unsigned int nChBandwidth, unsigned int nDataBandwidth, unsigned int nPrimarySetting)
{
    return SP_META_WiFi_setBandwidthEx_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, nChBandwidth, nDataBandwidth, nPrimarySetting);
}

META_RESULT CWiFiMan::WiFi_setJMode(unsigned int ms_timeout, unsigned int nMode)
{
    return SP_META_WiFi_setJMode_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, nMode);
}

META_RESULT CWiFiMan::WiFi_setTX1Channel(unsigned int ms_timeout, int channelConfig)
{
    return SP_META_WiFi_setTX1Channel_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, channelConfig);
}

META_RESULT CWiFiMan::WiFi_setNss(unsigned int ms_timeout, int nNss)
{
    return SP_META_WiFi_setNss_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, nNss);
}

META_RESULT CWiFiMan::WiFi_setTXPath(unsigned int ms_timeout, unsigned int nPath)
{
    return SP_META_WiFi_setTXPath_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, nPath);
}

META_RESULT CWiFiMan::WiFi_setRXPath(unsigned int ms_timeout, unsigned int nPath)
{
    return SP_META_WiFi_setRXPath_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, nPath);
}

META_RESULT CWiFiMan::WiFi_SendScript(unsigned int ms_timeout, WIFI_SCRIPT_REQ * req,WIFI_SCRIPT_CNF *cnf)
{
    return SP_META_WiFi_SendScript_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, req, cnf);
}

META_RESULT CWiFiMan::WiFi_queryAntSwap(unsigned int ms_timeout, unsigned long * value)
{
     return SP_META_WiFi_QueryAntSwap_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::WiFi_setAntSwap(unsigned int ms_timeout, unsigned int  value)
{
     return SP_META_WiFi_SetAntSwap_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, value);
}

META_RESULT CWiFiMan::Wifi_setDBDCIndex(unsigned int ms_timeout, unsigned int index)
{
    return SP_META_WiFi_SetDBDCIndex_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, index);
}

META_RESULT CWiFiMan::Wifi_setDBDCEnable(unsigned int ms_timeout, unsigned int enable)
{
    return SP_META_WiFi_SetDBDCEnable_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, enable);
}


