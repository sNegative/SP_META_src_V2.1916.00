#ifndef  _HW_TEST_H_
#define  _HW_TEST_H_

#include "LogicalControlBase.h"
#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

typedef enum
{
    HWT_VERSION = 0,
    HWT_WIFI,
    HWT_BT,
    HWT_FM_ON,
    HWT_FM_OFF,
    HWT_GPS_OPEN,
    HWT_GPS_CLOSE,
    HWT_CANCEL_ALL,
    HWT_GS_READ,
    HWT_AUDIO_LOUDSPKL, 
    HWT_AUDIO_LOUDSPKR,
    HWT_AUDIO_RECEIVER,
    HWT_MSENSOR_TEST,
    HWT_SDCARD_QUERY,
    HWT_AUDIO_GET_SUPPORT_AFE_REG_ACCESS,
    HWT_CTP_TEST,
    HWT_GYRO_READ,
    HWT_ALSPS_TEST,
    HWT_AUTO_TEST_ITEM_NUM
} E_HWT_AUTO_ITEM_TYPE;

typedef enum
{
    WM_META_HWT_SUCCESS = WM_USER+500,
    WM_META_HWT_FAILED,
    WM_META_HWT_TIMEOUT,
    WM_META_HWT_STOP,
    WM_META_HWT_FINISHED,
    WM_META_HWT_RUNNING,
    WM_META_HWT_NO_SD_CARD
} META_HWT_MESSAGE;
typedef struct
{
        HANDLE hPostMsgDestHandle;

} HW_TEST_HANDLE;

class  HwTest: public CLogicalControlBase
{
public:
    HwTest(void);
    ~HwTest();
    void Confirm(META_RESULT confirm_state);
    void (*ConfirmCallback)(void);
    void InternalVersionTest();
    void CNF_GetTargetVersion(const VerInfo_Cnf  *cnf, const short token, void *usrData);
    void InternalWiFiTest();
    void InternalBtTest();
    void InternalFmOnTest();
    void InternalFmOffTest();
    void InternalGpsOpenTest();
    void InternalGpsCloseTest();
    void InternalCancelAllTest();
    void InternalGsReadTest();
    void InternalAudioLoudspkLTest();
    void InternalAudioLoudspkRTest();
    void InternalAudioReceiverTest();
    void InternalMSensorTest();
    void InternalSdCardQueryTest();
    void InternalAudioGetSupportAfeRegAccessTest();
    void InternalCtpTest();
    void InternalGyroTest();
    void InternalAlsPsTest();
    void InternalTestAllAuto();
    void TestAllReq(int type);
    void InternalSpeakerTest_suffix();
    E_HWT_AUTO_ITEM_TYPE getTestIndex();

private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;
    HW_TEST_HANDLE m_hwTestHandle;
    VerInfo_Cnf   VerInfo;
    short        GETID_VERSION;
protected:
    typedef void (HwTest::*FuncHandler)(void);
    FuncHandler m_test;
    FuncHandler m_pInternalTestFuncList[HWT_AUTO_TEST_ITEM_NUM];
};
#endif
