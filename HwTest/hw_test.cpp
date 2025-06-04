#pragma hdrstop

#ifndef  _HW_TEST_H_
#include "hw_test.h"
#endif

#include "man_active.h"
#include "meta_lab_msg.h"
#include <stdio.h>
#include "form_UnitTest.h"
#include "Logger.h"

static HwTest  *get_hw_test_ptr;
static bool g_bIsRunning; 
E_HWT_AUTO_ITEM_TYPE g_index;
//---------------------------------------------------------------------------
static void __stdcall CNF_GetTargetVersion(const VerInfo_Cnf  *cnf, const short token, void *usrData)
{
    get_hw_test_ptr->CNF_GetTargetVersion( cnf, token, usrData );
}

//---------------------------------------------------------------------------
static void TestAllAuto()
{
    get_hw_test_ptr->InternalTestAllAuto();
}
//---------------------------------------------------------------------------
static void TestSpeakerL()
{
    get_hw_test_ptr->InternalAudioLoudspkLTest();
}
//---------------------------------------------------------------------------
static void TestSpeakerR()
{
    get_hw_test_ptr->InternalAudioLoudspkRTest();
}
//---------------------------------------------------------------------------
static void TestReceiver()
{
    get_hw_test_ptr->InternalAudioReceiverTest();
} 
//---------------------------------------------------------------------------
static void TestAudioSuffix()
{
    get_hw_test_ptr->InternalSpeakerTest_suffix();
}
HwTest::HwTest(void)
    :CLogicalControlBase()
{
     m_pInternalTestFuncList[0] = &HwTest::InternalVersionTest;
     m_pInternalTestFuncList[1] = &HwTest::InternalWiFiTest;
     m_pInternalTestFuncList[2] = &HwTest::InternalBtTest;
     m_pInternalTestFuncList[3] = &HwTest::InternalFmOnTest;
     m_pInternalTestFuncList[4] = &HwTest::InternalFmOffTest;
     m_pInternalTestFuncList[5] = &HwTest::InternalGpsOpenTest;
     m_pInternalTestFuncList[6] = &HwTest::InternalGpsCloseTest;
     m_pInternalTestFuncList[7] = &HwTest::InternalCancelAllTest;
     m_pInternalTestFuncList[8] = &HwTest::InternalGsReadTest;
     m_pInternalTestFuncList[9] = &HwTest::InternalAudioLoudspkLTest;
     m_pInternalTestFuncList[10] = &HwTest::InternalAudioLoudspkRTest;
     m_pInternalTestFuncList[11] = &HwTest::InternalAudioReceiverTest;
     m_pInternalTestFuncList[12] = &HwTest::InternalMSensorTest;
     m_pInternalTestFuncList[13] = &HwTest::InternalSdCardQueryTest;
     m_pInternalTestFuncList[14] = &HwTest::InternalAudioGetSupportAfeRegAccessTest;
     m_pInternalTestFuncList[15] = &HwTest::InternalCtpTest;
     m_pInternalTestFuncList[16] = &HwTest::InternalAlsPsTest;
     m_pInternalTestFuncList[17] = &HwTest::InternalGyroTest;

}

HwTest::~HwTest(void)
{
}
void HwTest::CNF_GetTargetVersion(const VerInfo_Cnf  *cnf, const short token, void *usrData)
{
    VerInfo = *cnf;
}
void HwTest::InternalVersionTest()
{
    META_RESULT mr = SP_META_GetTargetVerInfo_r(m_META_HANDLE_Obj.Get_MainHandle(), ::CNF_GetTargetVersion, &GETID_VERSION, NULL);
    if(mr!=META_SUCCESS)
        PostMessage(frmUnitTest->Handle, WM_META_HWT_FAILED,HWT_VERSION, 0);
    else
        PostMessage(frmUnitTest->Handle, WM_META_HWT_SUCCESS,HWT_VERSION, 0);
}
//---------------------------------------------------------------------------
void HwTest::InternalWiFiTest()
{
    unsigned int u4Addr = 0;
    unsigned long u4Value = 0;
    unsigned long value = 0;
    META_RESULT mr = SP_META_WiFi_GetChipVersion_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &value);
    if(META_SUCCESS != mr)
    {
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_WIFI,0);
        return;
    }

    mr = SP_META_WiFi_readMCR32_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, u4Addr, &u4Value);
    if(META_SUCCESS != mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_WIFI,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_WIFI,0);
}   
//---------------------------------------------------------------------------
void HwTest::InternalBtTest()
{
    unsigned int u4Addr = 0;
    unsigned long u4Value = 0;

    unsigned int ms_timeout = 5000;
    BT_HCI_COMMAND hci_cmd;
    memset(&hci_cmd, 0, sizeof(BT_HCI_COMMAND));

    //Read BDAdrress
    hci_cmd.m_opcode = 0x1009;
    hci_cmd.m_len    = 0;
    for( int i=0; i<(sizeof(hci_cmd.m_cmd)/sizeof(hci_cmd.m_cmd[0])); i++ )
    {
        hci_cmd.m_cmd[i] = 0;
    }
	
    META_RESULT mr = SP_META_BT_SendHCICommand_r(m_META_HANDLE_Obj.Get_MainHandle(), ms_timeout, &hci_cmd, NULL, NULL, 0x0E);
    if(META_SUCCESS != mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_BT,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_BT,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalFmOnTest()
{
    META_RESULT mr = SP_META_FM_PowerOn_r(m_META_HANDLE_Obj.Get_MainHandle(), 15000);

    if(META_SUCCESS == mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_FM_ON,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_FM_ON,0);
    return;
}
//---------------------------------------------------------------------------
void HwTest::InternalFmOffTest()
{
    META_RESULT mr = SP_META_FM_PowerOff_r(m_META_HANDLE_Obj.Get_MainHandle(), 15000);

    if(META_SUCCESS == mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_FM_OFF,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_FM_OFF,0);
    return;
}
//---------------------------------------------------------------------------
void HwTest::InternalGpsOpenTest()
{
    META_RESULT mr = SP_META_GPS_Open_r(m_META_HANDLE_Obj.Get_MainHandle(), 10000);

    if(META_SUCCESS == mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_GPS_OPEN,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_GPS_OPEN,0);

}
//---------------------------------------------------------------------------
void HwTest::InternalGpsCloseTest()
{
    META_RESULT mr = SP_META_GPS_Close_r(m_META_HANDLE_Obj.Get_MainHandle(), 10000);
    if(META_SUCCESS == mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_GPS_CLOSE,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_GPS_CLOSE,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalCancelAllTest()
{
    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_CANCEL_ALL,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalGsReadTest()
{
    GS_CMD_READ_RAW m_gs_cmd_readraw;
    GS_ACK_READ_RAW m_gs_ack_readrawCnf;
    memset(&m_gs_cmd_readraw, 0, sizeof(GS_CMD_READ_RAW));
    memset(&m_gs_ack_readrawCnf, 0, sizeof(GS_ACK_READ_RAW));

    META_RESULT mr = SP_META_GS_Read_Raw_r(m_META_HANDLE_Obj.Get_MainHandle(),3000,&m_gs_cmd_readraw, &m_gs_ack_readrawCnf);

    if(META_SUCCESS != mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_GS_READ,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_GS_READ,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalAudioLoudspkLTest()
{
    META_RESULT res;
    g_index = HWT_AUDIO_LOUDSPKL;
    g_bIsRunning = true;
    ft_l4aud_loudspk req;
    req.left_channel = 1;
    req.right_channel = 0;
    //res = SP_META_Audio_LoudSpk_Test_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &req);
    //if(META_SUCCESS == res)
        //PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_AUDIO_LOUDSPKL,1);
    //else
        //PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_AUDIO_LOUDSPKL,1);
}  
//---------------------------------------------------------------------------
void HwTest::InternalAudioLoudspkRTest()
{
    META_RESULT res;
    g_index = HWT_AUDIO_LOUDSPKR;
    ft_l4aud_loudspk req;
    req.left_channel = 0;
    req.right_channel = 1;
    g_bIsRunning = true;
    //res = SP_META_Audio_LoudSpk_Test_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &req);
    //if(META_SUCCESS == res)
        //PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_AUDIO_LOUDSPKR,1);
    //else
        //PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_AUDIO_LOUDSPKR,1);
}
//---------------------------------------------------------------------------
void HwTest::InternalAudioReceiverTest()
{
    META_RESULT res;
    g_index = HWT_AUDIO_RECEIVER;
    ft_l4aud_receiver_test req;
    req.receiver_test = true;
    g_bIsRunning = true;
   // res = SP_META_Audio_Receiver_Test_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &req);
    //if(META_SUCCESS == res)
        //PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_AUDIO_RECEIVER,1);
    //else
        //PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_AUDIO_RECEIVER,1);
} 
//---------------------------------------------------------------------------
void HwTest::InternalSpeakerTest_suffix()
{
    //META_RESULT res;
    ft_l4aud_loudspk req;
    req.left_channel = 0;
    req.right_channel = 0;
    /*res = */
    //SP_META_Audio_LoudSpk_Test_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &req); 
    g_bIsRunning = false;
    return;
}
//---------------------------------------------------------------------------
void HwTest::InternalMSensorTest()
{
    META_RESULT mr = SP_META_MSensorTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 1500);

    if(META_SUCCESS != mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_MSENSOR_TEST,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_MSENSOR_TEST,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalSdCardQueryTest()
{
    FT_SDCARD_REQ req;
    req.dwSDHCIndex = 1;
    FT_SDCARD_CNF cnf;
    META_RESULT MetaResult = SP_META_SDCARD_Query_r(m_META_HANDLE_Obj.Get_MainHandle(),3000,&req, &cnf);

    if (MetaResult !=META_SUCCESS)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_NO_SD_CARD,HWT_SDCARD_QUERY,0);
    else
	PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_SDCARD_QUERY,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalAudioGetSupportAfeRegAccessTest()
{
    META_RESULT mr;// = SP_META_Audio_GetSupportAfeRegAccess_r(m_META_HANDLE_Obj.Get_MainHandle(), 30000);
    if(META_SUCCESS != mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_AUDIO_GET_SUPPORT_AFE_REG_ACCESS,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_AUDIO_GET_SUPPORT_AFE_REG_ACCESS,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalCtpTest()
{
    META_RESULT mr = SP_META_CTPTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200);

    if(META_SUCCESS != mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_CTP_TEST,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_CTP_TEST,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalGyroTest()
{
    GYRO_CMD_READ_RAW rReq;
    GYRO_ACK_READ_RAW rCnf;
    memset(&rReq, 0, sizeof(GYRO_CMD_READ_RAW));
    memset(&rCnf, 0, sizeof(GYRO_ACK_READ_RAW));
	
    META_RESULT mr = SP_META_GYRO_Read_Raw_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &rReq, &rCnf);
    if(META_SUCCESS != mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_GYRO_READ,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_GYRO_READ,0);
}
//---------------------------------------------------------------------------
E_HWT_AUTO_ITEM_TYPE HwTest::getTestIndex()
{
    return g_index;
}
//---------------------------------------------------------------------------
void HwTest::InternalAlsPsTest()
{
     META_RESULT mr = SP_META_ALSPSTest_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200);

    if(META_SUCCESS != mr)
        PostMessage(frmUnitTest->Handle,WM_META_HWT_FAILED,HWT_ALSPS_TEST,0);
    else
        PostMessage(frmUnitTest->Handle,WM_META_HWT_SUCCESS,HWT_ALSPS_TEST,0);
}
//---------------------------------------------------------------------------
void HwTest::InternalTestAllAuto()
{
    //InternalVersionTest();
    if (frmUnitTest->cb_wifi->Checked == true)
    {
        InternalWiFiTest();
    }  
    if (frmUnitTest->cb_bt->Checked == true)
    {
        InternalBtTest();
    }     
    if (frmUnitTest->cb_fm->Checked == true)
    {
        InternalFmOnTest();
        InternalFmOffTest();
    }
    if (frmUnitTest->cb_gps->Checked == true)
    {
        InternalGpsOpenTest();
        InternalGpsCloseTest();
    }
    if (frmUnitTest->cb_gsensor->Checked == true)
    {
        InternalGsReadTest();
    }
    //InternalAudioLoudspkTest();
    //InternalAudioReceiverTest();
    if (frmUnitTest->cb_msensor->Checked == true)
    {
        InternalMSensorTest();
    }
    //InternalSendMdCmdTest();
    if (frmUnitTest->cb_sdcard->Checked == true)
    {
        InternalSdCardQueryTest();
    }
    //InternalAudioGetSupportAfeRegAccessTest();
    if (frmUnitTest->cb_ctp->Checked == true)
    {
        InternalCtpTest();
    }
    if (frmUnitTest->cb_gyrosensor->Checked == true)
    {
        InternalGyroTest();
    }
    if (frmUnitTest->cb_alsps->Checked == true)
    {
        InternalAlsPsTest();
    }
    if (frmUnitTest->cb_cancelAll->Checked == true)
    {
        InternalCancelAllTest();
    }
    PostMessage(frmUnitTest->Handle,WM_META_HWT_FINISHED,HWT_AUTO_TEST_ITEM_NUM,0);
}

//---------------------------------------------------------------------------
void HwTest::TestAllReq(int type)
{  
    LOG("TestAllReq type:%d", type);
    switch (type)
    {
     case 0:
        ActiveMan->SetActiveFunction(::TestAllAuto);
        break;
    case 1:
        ActiveMan->SetActiveFunction(::TestSpeakerL);
        break;
    case 2:
        ActiveMan->SetActiveFunction(::TestSpeakerR);
        break;
    case 3:
        ActiveMan->SetActiveFunction(::TestReceiver);
        break;
    case 4:
        if (g_bIsRunning)
        {
            ActiveMan->SetActiveFunction(::TestAudioSuffix);
        }
        break;
    default:
        break;
    }
}







