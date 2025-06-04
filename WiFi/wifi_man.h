#ifndef  _WIFI_MAN_H_
#define  _WIFI_MAN_H_


#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif


class  CWiFiMan
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;
    char m_strEEbuf[2048];

public:
    CWiFiMan(void);
    ~CWiFiMan();
    void REQ_WIFI_READ_EEPROM_Start(void);
    void REQ_WIFI_READ_EEPROM(void);
    void REQ_WIFI6620_READ_EEPROM_Start(void);
    void REQ_WIFI6620_READ_EEPROM(void);
    void REQ_WIFI_READALL_EEPROM_Start(void);
    void REQ_WIFI_READALL_EEPROM(void);
    void Confirm(META_RESULT confirm_state);
    void (*ConfirmCallback)(void);
    META_RESULT   Get_ConfirmState(void);
    char* GetEEBuffer();

//20120826
    META_RESULT WiFi_readMCR32(unsigned int ms_timeout, unsigned int offset, unsigned long *value);
    META_RESULT WiFi_writeMCR32(unsigned int ms_timeout, unsigned int offset, unsigned int value);
    META_RESULT WiFi_WriteNVRAM(unsigned int ms_timeout, NVRAM_ACCESS_STRUCT * pReq);
    META_RESULT WiFi_ReadNVRAM(unsigned int ms_timeout,NVRAM_ACCESS_STRUCT * pReq);
    META_RESULT WiFi_QueryConfig(unsigned int ms_timeout, ENUM_CFG_SRC_TYPE_T *bufType);
    META_RESULT WiFi_setTestMode(unsigned int ms_timeout);
    META_RESULT WiFi_switchAntenna(unsigned int ms_timeout, unsigned int value);
    META_RESULT WiFi_readEEPRom16(unsigned int ms_timeout, unsigned int offset, unsigned long *value);
    META_RESULT WiFi_writeEEPRom16(unsigned int ms_timeout, unsigned int offset, unsigned int value);
    META_RESULT WiFi_eepromReadByteStr(unsigned int ms_timeout, unsigned int u4Addr, unsigned int u4Length, char *pszStr);
    META_RESULT WiFi_eepromWriteByteStr(unsigned int ms_timeout, unsigned int u4Addr, unsigned int u4Length, char *pszStr);
    META_RESULT WiFi_setChannel(unsigned int ms_timeout, int channelConfig);
    META_RESULT WiFi_readTxPower(unsigned int ms_timeout, unsigned long *value);
    META_RESULT WiFi_setPacketTxEx(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
    META_RESULT WiFi_setOutputPower(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
    META_RESULT WiFi_setDutyCycle(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam, int nCWMode);
    META_RESULT WiFi_setCarrierSuppression(unsigned int ms_timeout, WIFI_TX_PARAM_T * pTxParam);
    META_RESULT WiFi_setLocalFrequecy(unsigned int ms_timeout, int txPower, int txAntenna);
    META_RESULT WiFi_setCWMode(unsigned int ms_timeout, int nTxRate, int nCWModeType);
    META_RESULT WiFi_setNormalMode(unsigned int ms_timeout);
    META_RESULT WiFi_setPnpPower(unsigned int ms_timeout, int i4PowerMode);
    META_RESULT WiFi_setStandBy(unsigned int ms_timeout);
    META_RESULT WiFi_setRate(unsigned int ms_timeout,unsigned long value);
    META_RESULT WiFi_setRxTest(unsigned int ms_timeout);
    META_RESULT WiFi_readEFuseAddr(unsigned int ms_timeout,unsigned int addr,unsigned long *value);
    META_RESULT WiFi_writeEFuseAddr(unsigned int ms_timeout,unsigned int addr,unsigned int value);
    META_RESULT WiFi_setBandwidth(unsigned int ms_timeout,unsigned int value);
    META_RESULT WiFi_setGuardinterval( unsigned int ms_timeout,unsigned int value);
    META_RESULT WiFi_setModeSelect(unsigned int ms_timeout,unsigned int value);
    META_RESULT WiFi_queryThermoInfo(unsigned int ms_timeout, long * pi4Enable, unsigned long * pu4RawVal);
    META_RESULT WiFi_setTxRxIQCalibration( unsigned int ms_timeout);
    META_RESULT WiFi_getCalResult(unsigned int ms_timeout,unsigned int index,unsigned int offset,unsigned long * data);
    META_RESULT WiFi_getTemperatureSensorResult( unsigned int ms_timeout,unsigned long *value);
    META_RESULT WiFi_getVoltageSensorResult(unsigned int ms_timeout,unsigned long *value);
    META_RESULT WiFi_getResultInformation( unsigned int ms_timeout,unsigned int index,unsigned long * length);
    META_RESULT WiFi_setDPDCalibration( unsigned int ms_timeout);
    META_RESULT WiFi_SetATParam(unsigned int ms_timeout, unsigned int offset, unsigned int value);
    META_RESULT WiFi_TSSICalibration( unsigned int ms_timeout);
    META_RESULT WiFi_GetChipVersion( unsigned int ms_timeout,unsigned long * chipVersion);
    META_RESULT WiFi_GetATParam(unsigned int ms_timeout, unsigned int offset, unsigned long *value);
    META_RESULT WiFi_ReceivedErrorCount(unsigned int ms_timeout, unsigned long * value);
    META_RESULT WiFi_ReceivedOKCount(unsigned int ms_timeout, unsigned long * value);
    META_RESULT WiFi_ReceivedRSSI(unsigned int ms_timeout, long * value);
    META_RESULT WiFi_ReceivedRSSI1(unsigned int ms_timeout, long * value);
    META_RESULT WiFi_getChannel(unsigned int ms_timeout, long *channelConfig_p);
    META_RESULT WiFi_readTxPowerFromEEPromEx(unsigned int ms_timeout, int channelFreq,
                                             int rate, long *nTxPwr, long *outputPower, long *targetAlc);
    META_RESULT WiFi_setPacketRx(unsigned int ms_timeout, int condition, int nAntenna);
    META_RESULT WiFi_getPacketRxStatus(unsigned int ms_timeout, WIFI_RXSTATUS_T *pRxStatus);
    META_RESULT WiFi_setXtalTrimToCr(unsigned int ms_timeout, unsigned int u4Value);
    META_RESULT WiFi_setThermoEn(unsigned int ms_timeout, long i4Enable);
    META_RESULT WiFi_setOutputPin(unsigned int ms_timeout, int pinIndex, int outputLevel);
    META_RESULT WiFi_ReadConfigData(unsigned int ms_timeout, unsigned int offset, unsigned long *value, ENUM_CFG_SRC_TYPE_T type);

    META_RESULT WiFi_Open(unsigned int ms_timeout);
    META_RESULT WiFi_Close(unsigned int ms_timeout);

    META_RESULT WiFi_setBandwidthEx(unsigned int ms_timeout, unsigned int nChBandwidth, unsigned int nDataBandwidth, unsigned int nPrimarySetting);
    META_RESULT WiFi_setJMode(unsigned int ms_timeout, unsigned int nMode);

    META_RESULT WiFi_setTXPath(unsigned int ms_timeout, unsigned int nPath);
    META_RESULT WiFi_setTX1Channel(unsigned int ms_timeout, int channelConfig);
    META_RESULT WiFi_setNss(unsigned int ms_timeout, int nNss);
    META_RESULT WiFi_setRXPath(unsigned int ms_timeout, unsigned int nPath);
    META_RESULT WiFi_SendScript(unsigned int ms_timeout, WIFI_SCRIPT_REQ * req,WIFI_SCRIPT_CNF *cnf);
    META_RESULT WiFi_queryAntSwap(unsigned int ms_timeout, unsigned long * value);
    META_RESULT WiFi_setAntSwap(unsigned int ms_timeout, unsigned int  value);
    META_RESULT Wifi_setDBDCIndex(unsigned int ms_timeout, unsigned int  index);
    META_RESULT Wifi_setDBDCEnable(unsigned int ms_timeout, unsigned int enable);

};

#endif
