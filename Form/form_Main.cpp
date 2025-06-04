#include <vcl.h>
#include <Shellapi.h>

#pragma hdrstop

//---------------------------------------------------------------------------
// form

#ifndef  _MAN_FDM_H_
#include "man_fdm.h"
#endif

#include "form_WmWifi.h"
#include "form_GPS.h"
#include "form_Sensor.h"

#ifndef _FORM_BASEBAND_H_
#include "form_BaseBand.h"
#endif

#include "form_GetVersion.h"

#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

#ifndef form_NFCH
#include "form_NFC.h"
#endif

#include "META_factory_AboutU.h"

#ifndef _FORM_WiFI_H_
#include "form_wifi.h"
#endif

#ifndef _FORM_BT_H_
#include "form_BT.h"
#endif

#ifndef _FORM_FM_H_
#include "form_FM.h"
#endif

#ifndef _FORM_UNITTEST_H_
#include "form_UnitTest.h"
#endif

#ifndef _FORM_HDCP_H_
#include "form_HdcpKey.h"
#endif

#ifndef form_DRMKeyH
#include "form_DRMKey.h"
#endif

#ifndef form_AttestationKeyH
#include "form_AttestationKey.h"
#endif


#include "man_active_boot.h"
#include "meta_utils.h"
#include "man_dll.h"
#include "meta.h"

// man
#ifndef  _MAN_METADLL_H_
#include "man_metadll.h"
#endif

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

// security
#ifndef _SLA_CHALLENGE_H_
#include "sla_challenge.h"
#endif

// baseband
#ifndef  _BB_FLASH_H_
#include "bb_flash.h"
#endif

#ifndef  _FM_RADIO_H_
#include "fm_radio.h"
#endif

//version
#ifndef  _GET_VERSION_H_
#include "get_version.h"
#endif

// USB COM
#ifndef  _USB_COM_COMMON_H_
#include "usb_com_common.h"
#endif

#ifndef form_WmWifimt6620H
#include "form_WmWifimt6620.h"
#endif

#ifndef NFCMainH
#include "NFCMain.h"
#endif

#include "interface.h"

#include "SDCardMonitor.h"
#include "Logger.h"
#include <objbase.h>
#include <initguid.h>
#include <string>
#include <iostream>
#include <sstream>
#include "usb_info.h"

#include <algorithm>

#include  <io.h>
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>



#ifndef form_MainPasswordH
#include "form_MainPassword.h"
#endif

#ifndef form_SpecialTestH
#include "form_SpecialTest.h"
#endif

#ifndef form_MetaConnectTimeH
#include "form_MetaConnectTime.h"
#endif

#ifndef form_RatConfigH
#include "form_RatConfig.h"
#endif

#ifndef form_MultiSIMH
#include "form_MultiSIM.h"
#endif
//---------------------------------------------------------------------------
//#define  IDX_2G   0
//#define  IDX_3G   1

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

bool isAdmomo;

TfrmMainSel *frmMainSel;
static  int usbFinderCount;
static  int usbCOMFinderCount;


// Wei Fang 2012-10-30 add for connect time show in UI
extern LARGE_INTEGER litmp;
extern LONGLONG qt1,qt2;
extern double dft,dff,dfm;
extern char strTime[10];

typedef enum
{
    PreloaderUSB,
    KernalUSB
} USBType;

static AnsiString g_as_Menu_selection_Array[TOTAL_MENU_ITEMS] =
{
    "Baseband Tool",
    "BT Tool",
    "FM Radio Tool",
    "Get version",
    "AP NVRAM Editor",
    "WIFI Tool",
    "GPS Tool" ,
    "Sensor Tool",
    "NFC Tool",
    "HDCP Key Tool",
    "DRM Key Install Tool",
    "NFC New Tool",
    "Radio Access Technology Tool",
    "Multi-SIM Tool",
    "Attestation Key Install Tool"
};

//bool bPowerSupplyOn = true;
bool g_bHideEnable = true;//true;
int g_nConnectMode = 0;  //UART = 0, USB = 1
HANDLE hForm_MainForm;

extern  CNVRAMMan  *NVRAMMan;
extern bool isBootTarget;
extern bool isConnectTarget;
extern bool ConnectTargetok;
extern bool g_bMetaCommStart;
extern HANDLE p_METADLL_Connect_Event;
extern bool IsReconnectByFactory;
HANDLE hForm_MF;
extern bool isFirstOpenComErr;
//rongguo 2011-11-21
extern bool isConnectFail;
extern bool m_isCompositeUSB;
extern bool m_isMDlogging;
extern bool m_bDisableUartlog;

// connect in META mode
WM_META_ConnectInMETA_Req g_ConnectInMETA_Req;
WM_META_ConnectInMETA_Report g_ConnectInMETA_Report;

//version
CGETVERSION    GET_VERSION_Object;
VerInfo_Cnf  VerInfoGlobal;
AnsiString chipVersion;
AnsiString softwareVersion;
unsigned long wifiChipVersion;

//diconnect
bool g_DisconnectFlag = false;
bool g_CloseFlag = false;


//TfrmWmWifiMT6620 *pfrmWmWifiMT6620;   //delete 20120516

//
E_WIFI_STATE g_eWiFiState = WIFI_STATE_CLOSE;
//

static  void  CNF_NVRAMInitial( void )
{
    frmMainSel->CNF_NVRAMInitial();
}
static  void CNF_GetTargetVersion(void)
{
    frmMainSel->CNF_GetTargetVersion();
}

//======================================================================
void TfrmMainSel::Init()
{
    if(!ActiveMan)
    {
        ActiveMan = new TActiveMan();
        ActiveMan->FreeOnTerminate = true;
    }
    if(!ActiveMan_Boot)
    {
        ActiveMan_Boot  = new TActiveMan_Boot();
        ActiveMan_Boot->FreeOnTerminate = true;
    }
    if(!MetaDllMan)
    {
        MetaDllMan = new CMetaDllMan();
    }
    if(!NVRAMMan)
    {
        NVRAMMan = new CNVRAMMan();
    }
    if(!DllMan)
    {
        DllMan = new CDllMan();
    }
}

//======================================================================
__fastcall TfrmMainSel::TfrmMainSel(TComponent* Owner)
    : TForm(Owner)
{
    m_bMetaDebugOn = false;
    m_bBRomDebugOn = false;
    m_bMetaModeLockOn = false;
    m_iComPort  = 1;
    isUserPress = 0;

    Init();

    if(!m_cAuthObj.AUTH_Create())
    {
        Application->MessageBox( "Create authentication handle fail", "Fail", MB_OK );
    }

    if(!m_cScertObj.SCERT_Create())
    {
        Application->MessageBox( "Create certificate handle fail", "Fail", MB_OK );
    }


    hForm_MainForm = this->Handle;
    
    int i = 0;
    for(i=0; i<TOTAL_MENU_ITEMS; i++)
    {
    	   m_ActForm[i] = NULL;
    }
    m_iActFormCount = 0;
    m_bInit = false;
    b_open_NVRAM_database = false;
    m_bMetaModeLockChecked = false;
    for(i=0; i< BBCHIP_TYPE_END - 1; i++)
    {
        m_bLastMenuItemBBCheck[i] = false;
    }
    m_bLastMenuItemAutoDetectBBCheck = false;
    
    m_lastMenuItem13MHzCheck = false;
    m_lastMenuItem26MHzCheck = false;
    m_lastMenuItem39MHzCheck = false;
    m_lastMenuItem52MHzCheck = false;
    m_lastMenuItemAutodetectExtCheck = false;
    m_lastrbHardwareCheck = false;
    m_lastrbSoftwareCheck = false;
    nComPortCount = 0;
    meta_ver_required_by_target = 0;
    currentBaudRateIndex = 0;

    i_NORMAL_VOLTAGE = 0;
    i_CURRENT_LIMIT = 0;
    i_OFF_VOLTAGE = 0;
    m_bWiFiSupport = false;
    m_ucPmSupportNum = 0;
    connecting = false;
    BootResult = 0;
    BootStop = 0;
    iCOM = 0;
    NeedToReboot = 0;
    isReconnect = false;
    ResetCount = 0;

    //20130818
    m_bOpenAuthenticationfile = false;
    m_bOpenCertificatefile = false;
    //

    //20131129
    m_bDisableMobileLog = false;
    //

    
    for(i=0; i<BBCHIP_TYPE_END - 1; i++)
    {
        m_bLastMenuItemBBCheck[i] = false;
        pTMenuItem[i] = NULL;
    }
    
    for(i=0; i<MAX_SUPPORT_COM_NUM; i++)
    {
        ComPortArray[i] = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::FormCreate(TObject *Sender)
{
    WindowProc = SubClassWndProc;
    AnsiString asPath;
    getPathFromStr(Application->ExeName, asPath);

    AnsiString as_par = "/s \"" + asPath + "controls.dll\"";
    HINSTANCE hInstance = ShellExecute(this->Handle, NULL, "regsvr32.exe", as_par.c_str(), NULL, SW_HIDE);
    //If the function(ShellExecute) fails, the return value is an error value that is less than or equal to 32.
    if ( (int)hInstance <= 32)
    {
        HINSTANCE hInstanceEx = ShellExecute(this->Handle, NULL, "regsvr32.exe", as_par.c_str(), NULL, SW_HIDE);
        if( (int)hInstanceEx <= 32 )
        {
            Application->MessageBox(" Register controls.dll fail", "Warning", MB_OK);
            return;
        }
    }
    if(!(DllMan->LoadControlsDllFunctions(this->Handle)))
    {
        Application->MessageBox(" Load controls.dll fail", "Warning", MB_OK);
        return;
    }
    if (cbxCOM->Text == "USB")
    {
        m_exist_com_port_str.erase(m_exist_com_port_str.begin(), m_exist_com_port_str.end());
        m_exist_com_port_str.begin();
        scan_exist_com_port_str(m_exist_com_port_str,PID,VID,m_InterfaceClassGuidConstant,PreloaderUSB);

        m_exist_com_port_str_tst.erase(m_exist_com_port_str_tst.begin(), m_exist_com_port_str_tst.end());
        m_exist_com_port_str_tst.begin();
        scan_exist_com_port_str(m_exist_com_port_str_tst,PIDTST,VIDTST,InterfaceClassGuidConstantTST,KernalUSB);
    }
}
//---------------------------------------------------------------------------
void TfrmMainSel::CNF_GetTargetVersion(void)
{
    GET_VERSION_Object.Get_VerInfo(VerInfoGlobal);
    if(VerInfoGlobal.BB_CHIP != NULL)
    {
        chipVersion = VerInfoGlobal.BB_CHIP;
        chipVersion.SetLength(6);
    }
    if(VerInfoGlobal.SW_VER != NULL)
    {
        softwareVersion =  VerInfoGlobal.SW_VER;
        softwareVersion.SetLength(4);
    }

    PostMessage(this->Handle, WM_ML_MAIN_GET_CHIP_VERSION_DONE, 0, 0);
}
//---------------------------------------------------------------------------
void TfrmMainSel::GetTargetVersionDone(void)
{
    cbxOperationChange(this);
}
//---------------------------------------------------------------------------
void TfrmMainSel::ToolReset()
{
    glbTimer->Enabled = false;

    frmMainSel->Left = 182;
    frmMainSel->Top = 1;
    frmMainSel->AutoScroll = true;

    int  n = 0;
    m_ActForm[n++] = frmBaseBand;
    m_ActForm[n++] = frmBT;
    m_ActForm[n++] = frmFM;
    m_ActForm[n++] = frmGetVersion;
    m_ActForm[n++] = frmNVRAMEditor;

    if(wifiChipVersion == 0x5921)
    {
        m_ActForm[n++] = frmWmWifi;
    }
    else
    {
        m_ActForm[n++] = frmWmWifiMT6620;
    }

    m_ActForm[n++] = frmGPS;
    m_ActForm[n++] = frmSensor;

    m_ActForm[n++] = frmNFC;
    m_ActForm[n++] = frmHdcpKey;
    m_ActForm[n++] = frmDRMKeyInstall;
    m_ActForm[n++] = frmNFCNew;
    m_ActForm[n++] = frmRatConfig;
    m_ActForm[n++] = frmMultiSIM;
    m_ActForm[n++] = frmAttestationKeyInstall;

    m_iActFormCount = n;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::FormShow(TObject *Sender)
{
    this->Height = 150;
    this->Width  = 540;
    
    static bool bInit = true;
    if( bInit )
    {
        bInit = false;
        glbTimer->Enabled = false;

        LOG("Main form center the form.");
        FormPositionSetting::CenterForm(this);

        frmMainSel->AutoScroll = true;

        for(int i = 0; i < TOTAL_MENU_ITEMS; i++)
        {
            cbxOperation->Items->Add(g_as_Menu_selection_Array[i]);
        }
        cbxOperation->ItemIndex = 0;

        int  n = 0;

        m_ActForm[n++] = frmBaseBand;
        m_ActForm[n++] = frmBT;
        m_ActForm[n++] = frmFM;
        m_ActForm[n++] = frmGetVersion;
        m_ActForm[n++] = frmNVRAMEditor;

        if(wifiChipVersion == 0x5921)
        {
            m_ActForm[n++] = frmWmWifi;
        }
        else
        {
            m_ActForm[n++] = frmWmWifiMT6620;
        }

        m_ActForm[n++] = frmGPS;
        m_ActForm[n++] = frmSensor;

        m_ActForm[n++] = frmNFC;

        m_ActForm[n++] = frmHdcpKey;
        m_ActForm[n++] = frmDRMKeyInstall;
        m_ActForm[n++] = frmNFCNew;
        m_ActForm[n++] = frmRatConfig;
        m_ActForm[n++] = frmMultiSIM;
        m_ActForm[n++] = frmAttestationKeyInstall;

        m_iActFormCount = n;

        S_FORM_HANDLE_T s_form_handle;
        for (int i = 0; i < m_iActFormCount; i++)
        {
            s_form_handle.handle[i] = m_ActForm[i]->Handle;
        }

        NVRAMMan->Set_FormHandle(s_form_handle);

        DisplayMainMenuSetting();

        AnsiString as_PowerSupplyOnCount = read_PowerSupplyOnCount( "MF_setup.txt", Application->ExeName );
        m_iPowerSupplyOnCount = as_PowerSupplyOnCount.ToInt();
        AnsiString as_PowerSupplyOffCount = read_PowerSupplyOffCount( "MF_setup.txt", Application->ExeName );
        m_iPowerSupplyOffCount = as_PowerSupplyOffCount.ToInt();
        AnsiString as_PowerSupplyTriggerTime = read_PowerSupplyTriggerTime( "MF_setup.txt", Application->ExeName );
        m_iPowerSupplyTriggerTime = as_PowerSupplyTriggerTime.ToInt();

        AnsiString as_NVRAMBackupRestoreTimeout = read_NVRAMBackupRestoreTimeout( "MF_setup.txt", Application->ExeName );
        m_nNVRAMBackupRestoreTimeout = as_NVRAMBackupRestoreTimeout.ToInt();

        SetConnectReqType();

        ApplyHideProperty();

        //Add for show Special test
        ApplyShowSpecialTest();

        // 20130708 activate SP META DLL log at boot up
        ToggleMETADebugExecute(this);
    }
    if (cbxCOM->Text == "USB")
    {
        m_exist_com_port_str.erase(m_exist_com_port_str.begin(), m_exist_com_port_str.end());
        m_exist_com_port_str.begin();
        scan_exist_com_port_str(m_exist_com_port_str,PID,VID,m_InterfaceClassGuidConstant,PreloaderUSB);

        m_exist_com_port_str_tst.erase(m_exist_com_port_str_tst.begin(), m_exist_com_port_str_tst.end());
        m_exist_com_port_str_tst.begin();
        scan_exist_com_port_str(m_exist_com_port_str_tst,PIDTST,VIDTST,InterfaceClassGuidConstantTST,KernalUSB);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::FormClose(TObject *Sender,  TCloseAction &Action)
{
    g_CloseFlag = true;
    PostMessage(this->Handle, WM_FM_DISCONNECT_CLEAN_DONE, 100, 0);
}
//---------------------------------------------------------------------------
void TfrmMainSel::FormClose_Handler(TObject *Sender)
{
    //Security
    if(!m_cAuthObj.AUTH_Unload() )
    {
        Application->MessageBox( "Unload authentication handle fail", "Fail", MB_OK );
    }

    if(!m_cAuthObj.AUTH_Destroy() )
    {
        Application->MessageBox( "Destroy authentication handle fail", "Fail", MB_OK );
    }

    if(!m_cScertObj.SCERT_Unload() )
    {
        Application->MessageBox( "Unload certificate handle fail", "Fail", MB_OK );
    }

    if(!m_cScertObj.SCERT_Destroy() )
    {
        Application->MessageBox( "Destroy certificate handle fail", "Fail", MB_OK );
    }


    SaveMainMenuSetting();
    glbTimer->Enabled = false;
    BootStop = BOOT_STOP;

    if(p_METADLL_Connect_Event)
    {
        WaitForSingleObject( p_METADLL_Connect_Event, 5000 );
    }

    for (int i = 0; i < TOTAL_MENU_ITEMS; i++)
    {
        if (m_ActForm[i]->Visible)
        {
            m_ActForm[i]->Close();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::FormDestroy(TObject *Sender)
{
    ExitMainMenu();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::glbTimerTimer(TObject *Sender)
{
    glbTimer->Enabled = false;
    static bool firstTime = true;
    bool bConnected=false;
    bool isAdmemo=false;
    bool isUSB=false;
    bool isMetaMode=false;
    bool isLegacyAutoDetection = false;
    int  comnum;

    if(cbxCOM->Text == "USB")
    {
        isUSB = true;
    }
    else
    {
        comnum = ComPortArray[cbxCOM->ItemIndex];
    }

    if(m_miConInMetaMode->Checked==true)
    {
        if(cbxCOM->Text == "USB")
        {
            Application->MessageBox( " Please select Gadget com port number " , "Warning", MB_OK );
            glbTimer->Enabled = false;
            SPMetaLogOff();
            return;
        }
        isMetaMode = true;
    }

    if(firstTime)
    {
        firstTime = false;
        if( ! MetaDllMan->MetaInit() )
        {
            Application->MessageBox( " META init fail " , "Warning", MB_OK );
        }
    }

    isLegacyAutoDetection = m_miLegacyAutoDetection->Checked;
    m_isCompositeUSB = m_miEnableCompositeUSB->Checked;
    m_bDisableMobileLog = m_miDisableMobileLogService->Checked;
    m_bDisableUartlog = m_miDisableUartLog->Checked;
    m_isMDlogging = m_miMDlogging->Checked;

    bConnected = MetaDllMan->StartConnectTarget(isUSB, isMetaMode, isLegacyAutoDetection, comnum);

    if(true == isConnectFail)
    {
        glbTimer->Enabled = false;
        shpConnect->Brush->Color = clRed;
		SPMetaLogOff();
        return;
    }

    if( bConnected )
    {
        EnableComponents( true );
        glbTimer->Enabled = false;
        return;
    }
    else
    {
        shpConnect->Brush->Color = (shpConnect->Brush->Color == clRed) ? clLime : clRed;
    }
    glbTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}
//---------------------------------------------------------------------------
void TfrmMainSel::DisableGlbTimer(void)
{
    glbTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void TfrmMainSel::ExitMainMenu( void )
{
    glbTimer->Enabled = false;
    if(ActiveMan_Boot != NULL)
    {
        ActiveMan_Boot->Terminate();
        ActiveMan_Boot = NULL;
    }
    if(ActiveMan !=NULL)
    {
        ActiveMan->Terminate();
        //delete ActiveMan;
        ActiveMan =NULL;
    }
    if(MetaDllMan)
    {
        MetaDllMan->End();
        delete  MetaDllMan;
        MetaDllMan = NULL;
    }
    
    if(DllMan)
    {
        DllMan->FreeControlsDll(this->Handle);
        delete  DllMan;
        DllMan = NULL;
    }
    if(NVRAMMan)
    {
        delete  NVRAMMan;
        NVRAMMan = NULL;
    }
    SaveMainMenuSetting();
    Application->Terminate();
}
//---------------------------------------------------------------------------
void  TfrmMainSel::EnableComponents( bool bEnable )
{
    if(bEnable)
    {
//        CRYPTFS_QUERYSUPPORT_REQ cryptfs_Support_req;
        CRYPTFS_QUERYSUPPORT_CNF cryptfs_Support_cnf;
        bool isCryptfsSupport = GET_VERSION_Object.GetEncryptSupport(&cryptfs_Support_cnf);
        LOG("isCryptfsSupport is: %d", isCryptfsSupport);
        LOG("cryptfs_Support_cnf.support is: %d", cryptfs_Support_cnf.support);
        if(isCryptfsSupport && (cryptfs_Support_cnf.support == 1))
        {
            frmMainPassword->ShowModal();
            if(!frmMainPassword->GetPasswordResult())
            {
                if(frmMainPassword->GetOkPressed())
                {
                    Application->MessageBox( " Password is wrong " , "Error", MB_OK );
                }
                for(int i=0; i<m_iActFormCount; i++)
                {
                    m_ActForm[i]->Hide();
                }
                cbxOperation->Enabled = false;
                mnuOpenFDMDatabase->Enabled = false;
                return;
            }
        }

        pnlResetTarget->Caption = "Connected with target";
        pnlResetTarget->Font->Color = clBlue;
        shpConnect->Brush->Color = clYellow;
        stConnectionTime->Caption =  strTime;
        stConnectionTime->Font->Color = clBlue;
        cbxCOM->Enabled = false;
        cbBaudrate->Enabled = false;
        cbxOperation->Enabled = true;
        mnuOpenFDMDatabase->Enabled = true;

        if(read_Query_WCNDriver_Ready("MF_setup.txt",Application->ExeName) == '1')
        {
           QueryWCNDriverReady();
        }
        GET_VERSION_Object.ConfirmCallback = ::CNF_GetTargetVersion;
        GET_VERSION_Object.GetTargetVersion();
    }
    else
    {
        for(int i=0; i<m_iActFormCount; i++)
        {
            m_ActForm[i]->Hide();
        }

        pnlResetTarget->Caption = "Please reset target";
        pnlResetTarget->Font->Color = clRed;
        shpConnect->Brush->Color = clRed;

        rbSoftware->Enabled = true;
        cbxCOM->Enabled = true;
        cbBaudrate->Enabled = true;
        cbxOperation->Enabled = false;
        mnuOpenFDMDatabase->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void  TfrmMainSel::ChangeComPort( int com_port )
{
    m_iComPort = com_port;
    SetConnectReqType();
#ifdef  AUTODETECT
    isBootTarget = false;
    SetConnectReqType();
    BootStop = BOOT_STOP;
    glbTimer->Enabled = false;
    glbTimer->Interval = 10;
    glbTimer->Enabled = true;
    EnableComponents( false );
#endif
}
//==============================================================================
void  TfrmMainSel::ShowHintLabel( TControl *sender, char* hint )
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}
//---------------------------------------------------------------------------
bool TfrmMainSel::GetCurrentCOMPort(void)
{
    int nRet = SP_S_DONE;
    SP_COM_FILTER_LIST_S ComFilter;
    nComPortCount = MAX_SUPPORT_COM_NUM;
    char* ppFilter[2] = {0};

    memset(&ComFilter,0,sizeof(ComFilter));
    ComFilter.m_eType = SP_WHITE_LIST;
    ComFilter.m_uCount = 0;
    ComFilter.m_ppFilterID = ppFilter;

    SP_COM_PROPERTY_S * pCOMPorperty = new SP_COM_PROPERTY_S[nComPortCount];
    if (pCOMPorperty == NULL)
    {
        return false;
    }
    memset(pCOMPorperty,0,sizeof(SP_COM_PROPERTY_S)*nComPortCount);
    if (nRet != SP_GetCurrentCOMPortInfoWithFilter(&ComFilter, NULL, false, pCOMPorperty, &nComPortCount))
    {
        delete[] pCOMPorperty;
        pCOMPorperty = NULL;
        return false;
    }
    int i = 0;
    int j = 0;
    for(i = 0; i < nComPortCount; i++)
    {
        if ( (pCOMPorperty[i].m_uNumber > 0) &&  (pCOMPorperty[i].m_uNumber < 256) )
        {
            ComPortArray[j++] = pCOMPorperty[i].m_uNumber;
        }
    }
    nComPortCount = j;
    delete[] pCOMPorperty;
    pCOMPorperty = NULL;  
    return true;
}
//---------------------------------------------------------------------------
void TfrmMainSel::DisplayMainMenuSetting( void )
{
    bool com_match = false;

    // show menu selection seetting
    AnsiString as_MenuSelection =  read_Menu_selection( "MF_setup.txt", Application->ExeName );

    int i = 0;
    for (i = 0; i < TOTAL_MENU_ITEMS; i++)
    {
        if (g_as_Menu_selection_Array[i].AnsiCompareIC(as_MenuSelection) == 0 )
        {
            cbxOperation->ItemIndex = i;
            break;
        }
    }
    if (i==TOTAL_MENU_ITEMS)
    {
        cbxOperation->ItemIndex = 0;
    }

    if (!GetCurrentCOMPort())
    {
        Application->MessageBox("Enumerate COM port failed", "FAIL", MB_OK);
    }
    
    for (int i=0; i<nComPortCount; i++)
    {
        cbxCOM->Items->Add( (AnsiString) "COM" + IntToStr( ComPortArray[i] ));
    }  

    cbxCOM->Items->Add("USB");
    m_asCOM =  read_COM_PORT_SETTING("MF_setup.txt", Application->ExeName);

    if (!m_asCOM.AnsiPos("USB"))
    {
        for (i=0; i<=nComPortCount; i++)
        {
            if (m_asCOM.AnsiCompareIC("com" + IntToStr(ComPortArray[i])) == 0)
            {
                if (i <= nComPortCount)
                {
                    cbxCOM->ItemIndex = i;
                    com_match = true;
                    break;
                }
                else
                {
                    com_match = false;
                    break;
                }
            }
        }

        if (!com_match) // no match
        {
            cbxCOM->ItemIndex = 0; // set to COM1
        }
        iCOM = ComPortArray[cbxCOM->ItemIndex];
        Label1->Visible = true;
        cbBaudrate->Visible = true;
    }
    else
    {
        iCOM = USB_COM;
        cbxCOM->ItemIndex = nComPortCount;
        Label1->Visible = false;
        cbBaudrate->Visible = false;
    }
    ChangeComPort(iCOM);
    
    // show baudrate
    m_asBaudrate = read_Baudrate( "MF_setup.txt", Application->ExeName );

    if( m_asBaudrate.AnsiCompareIC("57600") == 0 )
    {
        cbBaudrate->ItemIndex = BAUD_RATE_57600_INDEX;
    }
    else if ( m_asBaudrate.AnsiCompareIC("115200") == 0 )
    {
        cbBaudrate->ItemIndex = BAUD_RATE_115200_INDEX;
    }
    else if( m_asBaudrate.AnsiCompareIC("230400") == 0 )
    {
        cbBaudrate->ItemIndex = BAUD_RATE_230400_INDEX;
    }
    else if ( m_asBaudrate.AnsiCompareIC("460800") == 0 )
    {
        cbBaudrate->ItemIndex = BAUD_RATE_460800_INDEX;
    }
    else if( m_asBaudrate.AnsiCompareIC("921600") == 0 )
    {
        cbBaudrate->ItemIndex = BAUD_RATE_921600_INDEX;
    }
    else // default set to auto
    {
        cbBaudrate->ItemIndex = BAUD_RATE_AUTO_INDEX;
        m_asBaudrate = (AnsiString) "Auto";
    }

    //Security
    m_asAuthFileName = read_AuthenticationFile( "MF_setup.txt", Application->ExeName );
    m_cAuthObj.AUTH_Load(m_asAuthFileName.c_str());
    m_asScertFileName = read_CertificateFile( "MF_setup.txt", Application->ExeName );
    m_cScertObj.SCERT_Load(m_asScertFileName.c_str());

    //GUID
    AnsiString str;
    str = read_GUID( "MF_setup.txt", Application->ExeName );
    if(str.IsEmpty())
    {
        m_InterfaceClassGuidConstant = InterfaceClassGuidConstant;
        return;
    }

    m_InterfaceClassGuidConstant = Sysutils::StringToGUID(str);
}
//---------------------------------------------------------------------------
void TfrmMainSel::SaveMainMenuSetting(void)
{
    // save main menu setting
    write_Menu_selection("MF_setup.txt", Application->ExeName, g_as_Menu_selection_Array[cbxOperation->ItemIndex]);
    write_COM_PORT_SETTING("MF_setup.txt", Application->ExeName, cbxCOM->Text);
    write_Baudrate("MF_setup.txt", Application->ExeName, m_asBaudrate);
    write_AuthenticationFile("MF_setup.txt", Application->ExeName, m_asAuthFileName);
    write_CertificateFile("MF_setup.txt", Application->ExeName, m_asScertFileName);
}

//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_btnDisconnectClick(TObject *Sender)
{
    g_DisconnectFlag = true;
    PostMessage(this->Handle, WM_FM_DISCONNECT_CLEAN_DONE, 100, 0);
}
//---------------------------------------------------------------------------
void TfrmMainSel::Disconnect(TObject *Sender)
{
    if (ConnectTargetok)
    {
        SetCleanBootFlag_REQ 	m_SetCleanBootFlagReq;
        SetCleanBootFlag_CNF	m_SetCleanBootFlagCnf;
        memset(&m_SetCleanBootFlagReq, 0, sizeof(SetCleanBootFlag_REQ));
        memset(&m_SetCleanBootFlagCnf, 0, sizeof(SetCleanBootFlag_CNF));

        if(cbMetaModeLock->Checked == true)
        {
            META_RESULT mr = SP_META_Mode_Lock_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000);
            if (mr)
            {
                if(Application->MessageBox("Set Meta Mode Lock flag fail. Do you want to disconnect?","Attention",MB_YESNO) == IDNO)
                {
                    return;
                }
            }
        }

        if (CbCleanBootFlag->Checked == true)
        {
            //20160819 modify timeout value to 40000
            META_RESULT mr = SP_META_SetCleanBootFlag_r(m_META_HANDLE_Obj.Get_MainHandle(), m_nNVRAMBackupRestoreTimeout, &m_SetCleanBootFlagReq, &m_SetCleanBootFlagCnf);
            if (mr)
            {
                Application->MessageBox("Set clean boot flag fail",MB_OK);
                //            return;
            }
        }
    }

    MetaDllMan->METADLL_DisconnectWithTarget(m_miConInMetaMode->Checked);
    
    glbTimer->Enabled = false;
    frmNVRAMEditor->SetFirstOpenNvramEditor(true);
    SetConnectReqType();
    EnableComponents(false);
    BootStop = BOOT_STOP;
	SPMetaLogOff();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::btnReconnectClick(TObject *Sender)
{
  SPMetaLogOn();
    LOG("Main form title:%s",frmMainSel->Caption);   //Qin Qin 20120720
    Reconnect();
}
//---------------------------------------------------------------------------
void TfrmMainSel::Reconnect(void)
{
    glbTimer->Interval = 1000;
    glbTimer->Enabled = false;
    m_bInit = true;
    if( ConnectTargetok )
    {
        if(!(m_miConInMetaMode->Checked))
        {
            frmFM->CleanFMStatus();
        }
    }
    MetaDllMan->METADLL_DisconnectWithTarget(m_miConInMetaMode->Checked);

    SetConnectReqType();
    EnableComponents(false);
    BootStop = BOOT_STOP;
    glbTimer->Enabled = true;


}
//---------------------------------------------------------------------------
bool TfrmMainSel::SPMetaLogOn()
{
    char dirPath[128] = {0};
    char logPath[256] = {0};

    SYSTEMTIME time;

    if(m_bMetaDebugOn == false)
        return false;

    int ret = access(LOG_ROOT_PATH, 0);
    if(ret != 0)
    {
        ret = mkdir(LOG_ROOT_PATH);
        if(ret < 0)
            return false;
    }

    GetLocalTime(&time);
    sprintf(dirPath, "%s\\%04d-%02d-%02d-%02d-%02d-%02d", LOG_ROOT_PATH, time.wYear, time.wMonth,
        time.wDay, time.wHour, time.wMinute, time.wSecond);

    ret = mkdir(dirPath);
    if(ret != 0)
        return false;

    sprintf(logPath, "%s\\%s", dirPath, SP_META_DLL_LOG);
    SP_META_DebugOnThePath(logPath);

    memset(logPath, 0, 256);
    sprintf(logPath, "%s\\%s", dirPath, SP_BOOT_MODE_LOG);
    SP_Brom_Debug_SetLogFilename(logPath);
    SP_Brom_DebugOn();

    memset(logPath, 0, 256);
    sprintf(logPath, "%s\\", dirPath);
    Logger::DebugOnPath(logPath);

    return true;
}

void TfrmMainSel::SPMetaLogOff()
{
    if(m_bMetaDebugOn == false)
        return;

    SP_META_DebugOffThePath();
    SP_Brom_DebugOff();
    Logger::DebugOff();

}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::cbxCOMChange(TObject *Sender)
{
    isFirstOpenComErr = true;
    if (cbxCOM->Text == "USB")
    {
        Label1->Visible = false;
        cbBaudrate->Visible = false;
        m_exist_com_port_str.erase(m_exist_com_port_str.begin(), m_exist_com_port_str.end());
        m_exist_com_port_str.begin();
        scan_exist_com_port_str(m_exist_com_port_str,PID,VID,m_InterfaceClassGuidConstant,PreloaderUSB);

        m_exist_com_port_str_tst.erase(m_exist_com_port_str_tst.begin(), m_exist_com_port_str_tst.end());
        m_exist_com_port_str_tst.begin();
        scan_exist_com_port_str(m_exist_com_port_str_tst,PIDTST,VIDTST,InterfaceClassGuidConstantTST,KernalUSB);
    }
    else
    {
        iCOM = ComPortArray[cbxCOM->ItemIndex];
        Label1->Visible = true;
        cbBaudrate->Visible = true;
        ChangeComPort( iCOM );
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::cbxOperationChange(TObject *Sender)
{
    if(cbxOperation->ItemIndex == MSEL_WMWIFI_TOOL)
    {
        for (int i = 0; i < TOTAL_MENU_ITEMS; i++)
        {
            if (m_ActForm[i]->Visible)
            {
                m_ActForm[i]->Close();
            }
        }
        wifiChipVersion = frmWmWifiMT6620->GetTargetVersion(); //pfrmWmWifiMT6620->GetTargetVersion();
        ToolReset();
    }

    for(int i = 0; i < m_iActFormCount; i++)
    {
        if( i != (int) cbxOperation->ItemIndex )
        {
            m_ActForm[i]->Hide();
        }
    }

    int left = 0;
    int top = 0;
    getMenuPopupLocation( cbxOperation->ItemIndex, &left, &top );
    m_ActForm[cbxOperation->ItemIndex]->Left = left;
    m_ActForm[cbxOperation->ItemIndex]->Top  = top;
    m_ActForm[cbxOperation->ItemIndex]->Show();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::cbBaudrateChange(TObject *Sender)
{
    static AnsiString g_as_baudrate[] =
    {
        "auto",  /*0*/
        "57600",/*1*/
        "115200",  /*2*/
        "230400",  /*3*/
        "460800",  /*4*/
        "921600"  /*5*/
    };

    if(BAUD_RATE_AUTO_INDEX >= cbBaudrate->ItemIndex || BAUD_RATE_921600_INDEX < cbBaudrate->ItemIndex)
    {
        m_asBaudrate = (AnsiString) "auto";
        currentBaudRateIndex = BAUD_RATE_AUTO_INDEX;
        return;
    }

    m_asBaudrate = g_as_baudrate[cbBaudrate->ItemIndex];
    currentBaudRateIndex  = cbBaudrate->ItemIndex;

    Reconnect();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::miOpenAuthenticationfileClick(TObject *Sender)
{
    if( !(dlgOpenAuth->Execute()))
        return;

    m_asAuthFileName = dlgOpenAuth->FileName;

    if(!m_cAuthObj.AUTH_Load(m_asAuthFileName.c_str()))
    {
        isConnectTarget = false;
        ConnectTargetok = false;
        Application->MessageBox( "Load authentication handle fail", "Fail", MB_OK );
        return;
    }
    else
    {
        m_bOpenAuthenticationfile = true;
        Reconnect();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_miConInMetaModeClick(TObject *Sender)
{
    m_miConInMetaMode->Checked = !m_miConInMetaMode->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::miUnitTestClick(TObject *Sender)
{
    frmUnitTest->Top  = 178;
    frmUnitTest->Left = 263;
    frmUnitTest->Show();
}
//rongguo 2011-04-08
//---------------------------------------------------------------------------
int TfrmMainSel::OpenDatabaseCommon(
    char* str /// file path to db file
)
{
//rongguo 2011-09-27
    // check if NVRAM editor has modified data
    if(NVRAMMan->Get_IsInit() )
    {
        if(!frmNVRAMEditor->ReplaceDatabaseClean())
        {
            Application->MessageBox( "Change database operation is cancelled.", "INFO", MB_OK );
            return -1;
        }
    }

    as_NVRAM_database_file_name = str;
    LOG("The NVRAM database file name: %s", str);
    NVRAMMan->ConfirmCallback = ::CNF_NVRAMInitial;
    NVRAMMan->Init( str );

    if(NVRAMMan->Get_IsInit() )
    {
        b_open_NVRAM_database = true;

        frmNVRAMEditor->InitializeNVRAMEditor();
    }

    META_RESULT state = NVRAMMan->Get_ConfirmState();
    if (META_SUCCESS != state )
    {
        if (META_MAUI_DB_INCONSISTENT == state )
        {
            Application->MessageBox( "Execution Warning : NVRAM database file is inconsistent with target load", "WARNING", MB_OK );
        }
        else
        {
            Application->MessageBox( "Execution Failure : Initialize NVRAM database file ", "FAILURE", MB_OK );
        }
    }
    else
    {
        DialogInitialDir::SetInitialDir(str, frmMainSel->OpenDialog,              DIALOG_TYPE_OPEN);
    }
    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::mnuFDMDatabaseClick(TObject *Sender)
{
    //check whether can auto load AP database from target
    if (NVRAMMan->QueryAPDBPath())
    {
        char loadAPDBStr[1024] = {0};
        sprintf(loadAPDBStr, "Tool can load AP NVRAM database from target.\nClick Yes to load or click No to select the database by yourself.");
        if(Application->MessageBox(loadAPDBStr,"Confirm",MB_YESNO) == IDYES)
        {
            if (NVRAMMan->CopyAPDBToPC())
            {
                OpenDatabaseCommon(NVRAMMan->GetPCSideAPDBPath());
                return;
            }
            else
            {
                Application->MessageBox("Load AP NVRAM database from Target fail, please select the database by yourself.", "Notice", MB_OK);
            }
        }
    }
    //
    bool ok = OpenDialog->Execute();
    if( !ok )
    {
        return;
    }
    OpenDatabaseCommon(OpenDialog->FileName.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::mnuAboutClick(TObject *Sender)
{
    Form_About->Left = this->Left + (this->Width-Form_About->Width)/2;
    Form_About->Top  = this->Top + this->Height + 5;
    Form_About->Show();
}
//---------------------------------------------------------------------------
//For other forms.
BBCHIP_TYPE TfrmMainSel::Get_FinalBBChip( void )
{
    if(chipVersion == "MT6573")
    {
        return MT6573;
    }
    else
    {
        return MT6516_AP;
    }
}
//---------------------------------------------------------------------------
void TfrmMainSel::getMenuPopupLocation(int menu_index, int* left, int* top)
{
    unsigned int frmPosition[TOTAL_MENU_ITEMS][2] =
    {
//{109,3},
//{226,175},
        {235,175},
        {173,159},
//{104,175},
        {142,175},
//{102,3},
        {197,159},
//{173,159},
//{217,175},
//{181,175},
        {139,175},
//{173,159},
        {227,175},
        {197,159},
        {239,175},
        {93,159},
        {100,159},

        {100,159},
        {100,159},
        {100,159},
        {100,159},
    };

    if(0 > menu_index || TOTAL_MENU_ITEMS <= menu_index)
    {
        *left = 104;
        *top = 3;
    }
    else
    {
        *left = frmPosition[menu_index][0];
        * top = frmPosition[menu_index][1];
    }
}

BT_ModuleID_S* TfrmMainSel::Get_BTMoudleID(void)
{
    return &m_sBTModuleID;
}
//---------------------------------------------------------------------------
WiFi_ChipCapability_S TfrmMainSel::Get_FinalWiFiCap( void )
{
    return m_sWiFiCap;
}
AnsiString TfrmMainSel::Get_AuthFileName( void )
{
    return m_asAuthFileName;
}
//---------------------------------------------------------------------------
AnsiString TfrmMainSel::Get_ScertFileName( void )
{
    return m_asScertFileName;
}
//---------------------------------------------------------------------------
void TfrmMainSel::SetConnectReqType(void)
{
    SetConnectInMETAModeReq();
}
//---------------------------------------------------------------------------
void TfrmMainSel::SetMETAArg()
{
    //Old parameters
//    m_stModeArg.m_bbchip_type = Get_BBChipType(m_asBaseband_chip);
//    m_stModeArg.m_ext_clock = Get_ExternalClockType(m_asClock_rate);
    m_stModeArg.m_bbchip_type = SP_AUTO_DETECT_BBCHIP;
    m_stModeArg.m_ext_clock = SP_AUTO_DETECT_EXT_CLOCK;
    m_stModeArg.m_ms_boot_timeout = SP_BOOT_INFINITE;
    m_stModeArg.m_max_start_cmd_retry_count = SP_DEFAULT_BROM_START_CMD_RETRY_COUNT;

    //New parameters
    m_stModeArg.m_uTimeout = 20000;
    m_stModeArg.m_uRetryTime = 2000;
    m_stModeArg.m_uInterval = 10;
    m_stModeArg.m_uBaudrate = CBR_115200;

    //=============================
    // Serial Link Authentication
    m_stModeArg.m_auth_handle = m_cAuthObj.Get_AuthHandle();
    m_stModeArg.m_scert_handle = m_cScertObj.Get_ScertHandle();
    m_stModeArg.m_cb_sla_challenge = SLA_Challenge;
    m_stModeArg.m_cb_sla_challenge_arg = NULL;
    m_stModeArg.m_cb_sla_challenge_end = SLA_Challenge_END;
    m_stModeArg.m_cb_sla_challenge_end_arg = NULL;
}
//---------------------------------------------------------------------------
SP_BOOT_ARG_S * TfrmMainSel::GetMETAArg()
{
    return &m_stModeArg;
}
//---------------------------------------------------------------------------
void TfrmMainSel::SetConnectInMETAModeReq(void)
{
    g_ConnectInMETA_Req.com_port = iCOM;

    switch ((E_BAUD_RATE_INDEX) cbBaudrate->ItemIndex)
    {
    case BAUD_RATE_57600_INDEX:
        g_ConnectInMETA_Req.baudrate[0] = META_BAUD57600;
        g_ConnectInMETA_Req.baudrate[1] = META_BAUD_END;
        break;
    case BAUD_RATE_115200_INDEX:
        g_ConnectInMETA_Req.baudrate[0] = META_BAUD115200;
        g_ConnectInMETA_Req.baudrate[1] = META_BAUD_END;
        break;
    case BAUD_RATE_230400_INDEX:
        g_ConnectInMETA_Req.baudrate[0] = META_BAUD230400;
        g_ConnectInMETA_Req.baudrate[1] = META_BAUD_END;
        break;
    case BAUD_RATE_460800_INDEX:
        g_ConnectInMETA_Req.baudrate[0] = META_BAUD460800;
        g_ConnectInMETA_Req.baudrate[1] = META_BAUD_END;
        break;
    case BAUD_RATE_921600_INDEX:
        g_ConnectInMETA_Req.baudrate[0] = META_BAUD921600;
        g_ConnectInMETA_Req.baudrate[1] = META_BAUD_END;
        break;
    case BAUD_RATE_AUTO_INDEX:
    default:
        g_ConnectInMETA_Req.baudrate[0] = META_BAUD57600;
        g_ConnectInMETA_Req.baudrate[1] = META_BAUD115200;
        g_ConnectInMETA_Req.baudrate[2] = META_BAUD230400;
        g_ConnectInMETA_Req.baudrate[3] = META_BAUD460800;
        g_ConnectInMETA_Req.baudrate[4] = META_BAUD921600;
        g_ConnectInMETA_Req.baudrate[5] = META_BAUD_END;
        break;
    }

    g_ConnectInMETA_Req.flowctrl = META_NO_FLOWCTRL; //META_SW_FLOWCTRL;
    AnsiString as_METAConnectTimeout = read_META_Connect_timeout("MF_setup.txt", Application->ExeName);
    g_ConnectInMETA_Req.ms_connect_timeout = as_METAConnectTimeout.ToInt();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TfrmMainSel::CNF_NVRAMInitial( void )
{
    switch( NVRAMMan->Get_ConfirmState() )
    {
    case META_SUCCESS:
        break;
    case META_FAILED:
        Application->MessageBox( "Execution Failure : Initial NVRAM database", "FAILURE", MB_OK );
        break;
    case META_MAUI_DB_INCONSISTENT:
        Application->MessageBox( "Execution Warning : NVRAM database and target load version is inconsistent", "WARNING", MB_OK );
        break;
    case META_TIMEOUT:
        Application->MessageBox( "Execution Timeout : Initial NVRAM database", "TIMEOUT", MB_OK );
        break;
    case METAAPP_STOP:
        break;
    }
}
//---------------------------------------------------------------------------
void _fastcall TfrmMainSel::SubClassWndProc( Messages::TMessage &Message)
{
    int flag = Message.WParam;
    switch ( Message.Msg )
    {
    case WM_LOAD_AGE1960_DLL_FAILED:
    case WM_LOAD_AGE1960_DLL_FUNCTION_FAILED:
    case WM_LOAD_HP661X_DLL_FAILED:
    case WM_LOAD_HP661X_DLL_FUNCTION_FAILED:
    case WM_LOAD_HP663X2_DLL_FAILED:
    case WM_LOAD_HP663X2_DLL_FUNCTION_FAILED:
    case WM_LOAD_HPE3631A_DLL_FAILED:
    case WM_LOAD_HPE3631A_DLL_FUNCTION_FAILED:
    case WM_FREE_HPE3631A_DLL_FAILED:
    case WM_LOAD_VISA32_DLL_FAILED:
    case WM_LOAD_VISA32_DLL_FUNCTION_FAILED:
        Application->MessageBox("Please install GPIB card driver and VISA32.", "Warning", MB_OK );
        break;
    case WM_FM_DISCONNECT_CLEAN_DONE:
        if(100 == flag)
        {
            frmFM->DisconnectClean(0);
        }
        else if(0 == flag)
        {
            frmFM->DisconnectClean(1);
        }
        else if(2 == flag)
        {
            if(true == g_DisconnectFlag)
            {
                g_DisconnectFlag = false;
                Disconnect(NULL);
            }
            if(true == g_CloseFlag)
            {
                g_CloseFlag = false;
                FormClose_Handler(NULL);
                Disconnect(NULL);
            }
        }
        else if(1 == flag || 3 == flag)
        {
            g_DisconnectFlag = false;
            g_CloseFlag = false;
            Application->MessageBox("FM Radio Tool TX/RX power off fail, and can not disconnect.", "Error", MB_OK );
        }
        break;
    case WM_ML_MAIN_GET_CHIP_VERSION_DONE:
        GetTargetVersionDone();
        break;
    default:
        this->WndProc( Message );
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::cbMetaModeLockClick(TObject *Sender)
{
    if(cbMetaModeLock->Checked == true)
    {
        if((Application->MessageBox( "This feature can lead to the target can not re-entry meta mode.Do you continue to choose this feature?","Attention",MB_YESNO)) == IDYES)
        {
            m_bMetaModeLockChecked = true;
        }
        else
        {
            m_bMetaModeLockChecked = false;
            cbMetaModeLock->Checked = false;
        }
    }
}
//-----------------------------------------------------------------------------
template<typename T>
T StringToNumber(const std::string &text)    //Usage: StringToNumber<Type> ( String );
{
    std::istringstream ss(text);
    T result;
    //return ss >> result ? result : 0;
    return (ss >> result) ? result : 0;
}
//-----------------------------------------------------------------------------
bool IsDigitChar(const char character)
{
    if( '0' <= character &&
            '9' >= character)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//---------------------------------------------------------------------------
unsigned char GetUSBVCOMNumByPortName(const std::string& usb_port)
{
    if(usb_port.empty() || (std::string::npos == usb_port.find("COM")))
    {
        return 0;
    }

    unsigned int com_num_start_addr = 0;
    unsigned int COM_NUM_MAX_LEN = 3;
    unsigned char usb_com_num = 0;

    do
    {
        com_num_start_addr = usb_port.find("COM", com_num_start_addr, COM_NUM_MAX_LEN) + COM_NUM_MAX_LEN;
        if( IsDigitChar(usb_port.at(com_num_start_addr)) )
        {
            break;
        }
        else
        {
            continue;
        }

    }
    while(std::string::npos != com_num_start_addr);


    std::string::size_type com_num_len = 0;

    for(std::string::const_iterator it = usb_port.begin() + com_num_start_addr;
            it != usb_port.begin() + COM_NUM_MAX_LEN; ++it)
    {
        if( IsDigitChar(*it))
        {
            com_num_len += 1;
        }
        else
        {
            break;
        }
    }

    std::string s_com_num = usb_port.substr(com_num_start_addr, com_num_len);

    usb_com_num = StringToNumber<unsigned short>(s_com_num);

    return usb_com_num;
}
//---------------------------------------------------------------------------
void TfrmMainSel::scan_exist_com_port_str(std::set<std::string>  &exist_com_ports_str /*out*/,char * PID_Scan,char * VID_Scan,GUID guid,int USBType)
{
    unsigned long	device_number = 0;
    char			device_path[512];
    unsigned long	path_real_length;
    char			friend_name[512];
    unsigned long	friend_name_real_length;

    device_number =  GetDeviceNumber(guid, PID_Scan, VID_Scan);

    if( device_number == 0)
    {
        return;
    }

    for(unsigned int i = 0; i < device_number; i++)
    {
        if(GetPresentDevicePath(guid, PID_Scan, VID_Scan, i,
                                friend_name, 512, (unsigned long *) &friend_name_real_length,
                                device_path, 512, (unsigned long *) &path_real_length))
        {
            if(USBType==PreloaderUSB)
            {
                exist_com_ports_str.insert(device_path);
            }
            else if(USBType==KernalUSB)
            {
                exist_com_ports_str.insert(friend_name);
            }
            else
            {

            }
        }
        else
        {

        }
    }
}
//---------------------------------------------------------------------------
bool TfrmMainSel::get_new_created_com_port_str(std::string &usb_com_port_str,
        std::set<std::string> &exist_com_port_str,char * PID_Scan,char * VID_Scan,GUID guid,int USBType)
{
    std::set<std::string>       current_exist_com_port_str;
    std::vector<std::string>::iterator  it_last_result_str;
    std::string   result_port_str_test[10];
    //char log[128];

    //Get current exist com port
    scan_exist_com_port_str(current_exist_com_port_str,PID_Scan,VID_Scan,guid,USBType);

    it_last_result_str = set_difference(current_exist_com_port_str.begin(), current_exist_com_port_str.end(),
                                        exist_com_port_str.begin(), exist_com_port_str.end(),
                                        result_port_str_test);

    if(result_port_str_test == it_last_result_str)
    {
        return false;
    }

    usb_com_port_str =  *result_port_str_test;

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_miOpenCertificatefileClick(TObject *Sender)
{
    if(!(dlgOpenScert->Execute()))
        return;

    m_asScertFileName = dlgOpenScert->FileName;

    if(!m_cScertObj.SCERT_Load(m_asScertFileName.c_str()))
    {
        isConnectTarget = false;
        ConnectTargetok = false;
        Application->MessageBox( "Load certificate handle fail", "Fail", MB_OK );
        return;
    }
    m_bOpenCertificatefile = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_miLegacyAutoDetectionClick(TObject *Sender)
{
    m_miLegacyAutoDetection->Checked = !m_miLegacyAutoDetection->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_miDeviceManagerClick(TObject *Sender)
{
    ShellExecute(NULL, "open", "devmgmt.bat", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_miDriverInfoClick(TObject *Sender)
{
    SP_GetAllInterfaceInfo(NULL, false);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_miEnableCompositeUSBClick(TObject *Sender)
{
    m_miEnableCompositeUSB->Checked = !m_miEnableCompositeUSB->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_miMDloggingClick(TObject *Sender)
{
    m_miMDlogging->Checked = !m_miMDlogging->Checked;
}


//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::cbxCOMDropDown(TObject *Sender)
{
    bool bUSB = false;
    bool bComExist = false;
    int iOldCOM = 0;
    int nIndex = cbxCOM->ItemIndex;
    if(cbxCOM->Text == "USB")
    {
        bUSB = true;
    }
    else
    {
        iOldCOM = ComPortArray[nIndex];      //record the COM port number
    }
    
    if (!GetCurrentCOMPort())
    {
        Application->MessageBox("Enumerate COM port failed", "FAIL", MB_OK);
    }
    cbxCOM->Clear();
    for (int i=0; i<nComPortCount; i++)
    {
        cbxCOM->Items->Add( (AnsiString) "COM" + IntToStr( ComPortArray[i] ));
    }
    for(int i=0; i<nComPortCount; i++)
    {
        if( iOldCOM == ComPortArray[i])         //judge the COM port number exist or not
        {
            bComExist = true;
            nIndex = i;
            break;
        }
    }
    cbxCOM->Items->Add("USB");
    if(bUSB)
    {
        cbxCOM->ItemIndex = nComPortCount;
    }
    else
    {
        if( bComExist )
        {
            cbxCOM->ItemIndex = nIndex;
        }
        else
        {
            cbxCOM->ItemIndex = 0;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::ToggleMETADebugExecute(TObject *Sender)
{
    if (m_bMetaDebugOn)
    {
        m_bMetaDebugOn = false;
        stMETALog->Visible = false;
/*
        SP_META_DebugOff();
        SP_Brom_DebugOff();
        LOG("SP META tool debugging off.");
        Logger::DebugOff();              
*/
    }
    else
    {
        m_bMetaDebugOn = true;
        stMETALog->Visible = true;
/*		
        SP_META_DebugOn_ex(0);
        SP_META_DebugOn_ex(1);
        SP_META_DebugClear();
        SP_Brom_DebugOn();
        Logger::DebugOn();
        LOG("SP META tool debugging on.");
*/
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::LogClearExecute(TObject *Sender)
{
//    Brom_DebugClear();
    SP_META_DebugClear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::ToggleHideExecute(TObject *Sender)
{
    g_bHideEnable = g_bHideEnable ? false : true;
    ApplyHideProperty();
}
//---------------------------------------------------------------------------
void TfrmMainSel::ApplyHideProperty( void )
{
    bool visible = g_bHideEnable ? false : true;
    miUnitTest->Visible = visible;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::ToggleMetaModeLockExecute(TObject *Sender)
{
    if(m_bMetaModeLockOn)
    {
        m_bMetaModeLockOn = false;
        cbMetaModeLock->Visible = false;
    }
    else
    {
        m_bMetaModeLockOn = true;
        cbMetaModeLock->Visible = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::actReconnectExecute(TObject *Sender)
{
    btnReconnectClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::actDisconnectExecute(TObject *Sender)
{
    m_btnDisconnectClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::ConnectionTimeExecute(TObject *Sender)
{
   if(stConnectionTime->Visible == false){
      stConnectionTime->Visible = true;
      lbConnectionTime->Visible = true;
   }
   else{
      stConnectionTime->Visible = false;
      lbConnectionTime->Visible = false;
   }        
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::m_miDisableMobileLogServiceClick(
      TObject *Sender)
{
    m_miDisableMobileLogService->Checked = !m_miDisableMobileLogService->Checked;
}

void __fastcall TfrmMainSel::m_miDisableUartLogClick(
      TObject *Sender)
{
    m_miDisableUartLog->Checked = !m_miDisableUartLog->Checked;
}

//---------------------------------------------------------------------------
void __fastcall TfrmMainSel::ToggleSpecialTestExecute(TObject *Sender)
{
    g_bHideEnable = g_bHideEnable ? false : true;
    ApplyShowSpecialTest();
}
//---------------------------------------------------------------------------
void TfrmMainSel::ApplyShowSpecialTest( void )
{
    bool visible = g_bHideEnable ? false : true;
    miSpecialTest->Visible = visible;
}

//---------------------------------------------------------------------------

void __fastcall TfrmMainSel::miSpecialTestClick(TObject *Sender)
{
    frmSpecialTest->Show();
}

//---------------------------------------------------------------------------

void __fastcall TfrmMainSel::miMetaConnectTimeClick(TObject *Sender)
{
    frmMetaConnectTime->Show();
}
//---------------------------------------------------------------------------
void TfrmMainSel::QueryWCNDriverReady(void)
{
    META_RESULT mr = SP_META_QueryIfFunctionSupportedByTarget_r(m_META_HANDLE_Obj.Get_MainHandle(), 300, "SP_META_Query_WCNDriver_Ready_r");
    if(mr!=META_SUCCESS)
    {
        // old version
        return;
    }
    int retry = 0;
    QUERY_WCNDRIVER_READY_CNF cnf;
    memset(&cnf, 0, sizeof(QUERY_WCNDRIVER_READY_CNF));
    while(1)
	{
		if(retry == 10)
		{
			LOG( "Check WCN driver not ready!!!");
			return;
		}
		mr = SP_META_Query_WCNDriver_Ready_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &cnf);
		if( mr == META_SUCCESS && cnf.result == 1)
        {
            LOG( "Check WCN driver ready!!!");
            break;
        }
        else
        {
			Sleep(2500);
			++retry;
		}
	}
}
