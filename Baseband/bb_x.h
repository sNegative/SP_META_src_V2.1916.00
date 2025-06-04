#ifndef  _BB_RTC_H_
#define  _BB_RTC_H_
#include "LogicalControlBase.h"
#include "meta.h"
#include "man_handle.h"

class  CBaseBand: public CLogicalControlBase
{
public:
    void REQ_Start(REQ_CMDTYPE rct, void (*cb)(void));

    void REQ_QueryRTCTime(void);
    void REQ_SetVibratorOnOff(void);
    void REQ_SetKeypadLEDOnOff(void);
    void REQ_SetLCDLEDLightLevel(void);
    void REQ_SetSignalIndicatorOnOff(void);
    void REQ_SetVibratorOnOff_HWT(void);
    void REQ_SetKPLEDOnOff_HWT(void);
    void REQ_SetIndicatorOnOff_HWT(void);
    void REQ_SetLCMBLOnOff_HWT(void);
    void REQ_SetLCMDefaultImage_HWT(void);
    void REQ_ReadRegister(void);
    void REQ_WriteRegister(void);
    void REQ_CleanBoot(void);
    void REQ_ECCIPortTest(void);

    META_RESULT ADC_GetBatVol(int* pVol);
    META_RESULT ADC_GetBatCapacity(int* pCapacity);

    void __stdcall CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData);
    void __stdcall CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData);

    DWORD m_tIndex;
    short  m_sBBID_REG;
    unsigned int m_uiAddress;
    unsigned int m_usValue;
    unsigned int m_uibitCount;
    bool m_bCnfOk;
    HANDLE  m_hEvent;

    CPU_REG_READ_REQ m_sRegReadReq;
    CPU_REG_WRITE_REQ m_sRegWriteReq;
    CPU_REG_READ_CNF m_sRegReadCnf;
    CPU_REG_WRITE_CNF m_sRegWriteCnf;
    WatchDog_CNF m_sRTC;
    NLED_REQ  m_sVBROnOff;
    KeypadBK_REQ m_sLEDKeypad;
    LCDLevel_REQ m_sLCDLevel;

    NLED_REQ  m_sSignalIndicatorOnOff;

    WM_Bat_DLImage_REQ_T		m_rWmCmdDLImageReq;
    WM_Bat_UPImage_REQ_T		m_rWmCmdUpImageReq;
    WM_Bat_DLImage_CNF_T		m_rWmCmdDLImageCnf;
    WM_Bat_UPImage_CNF_T		m_rWmCmdUpImageCnf;
    char m_strFileAddress[512];

};

#endif
