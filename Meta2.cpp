#include <vcl.h>

#pragma hdrstop

#include "SPMetaUT.h"

#include "ConsoleMode.h"

USEFORM("factory\META_factory_AboutU.cpp", Form_About);
USEFORM("Form\form_BaseBand.cpp", frmBaseBand);
USEFORM("Form\form_GetVersion.cpp", frmGetVersion);
USEFORM("Form\form_Main.cpp", frmMainSel);
USEFORM("Form\WiFi\form_WiFiMCR.cpp", frmWiFiMCR);
USEFORM("Form\WiFi\form_WiFiBBCR.cpp", frmWiFiBBCR);
USEFORM("Form\WiFi\form_WiFiScript.cpp", frmWiFiScript);
USEFORM("Form\WiFi\form_WiFiEEPROM.cpp", frmWiFiEEPROM);
USEFORM("Form\WiFi\form_wifitxprofile.cpp", frmWiFiTxProfile);
USEFORM("Form\WiFi\form_WiFI.cpp", frmWiFi);
USEFORM("NVRAM Editor\NVRAMEditor.cpp", frmNVRAMEditor);
USEFORM("Form\BT\form_BT.cpp", frmBT);
USEFORM("Form\form_PMICReg.cpp", frmPMICReg);
USEFORM("Form\WiFi\form_WiFiALC2400M.cpp", frmWiFiALC2400M);
USEFORM("Form\form_Progress.cpp", m_frmProgress);
USEFORM("Form\FM\form_FM.cpp", frmFM);
USEFORM("Form\form_WmWifi.cpp", frmWmWifi);
USEFORM("Form\form_UnitTest.cpp", frmUnitTest);
USEFORM("Form\form_Sensor.cpp", frmSensor);
USEFORM("Form\form_WmWifimt6620.cpp", frmWmWifiMT6620);
USEFORM("Form\form_2GH_TX_Power_Profile.cpp", frm2GH_TX_Power_Profile);
USEFORM("Form\form_5GHz_TX_Power_Profile.cpp", frm5GHz_TX_Power_Profile);
USEFORM("Form\form_NFC_TagDetected.cpp", frmNFCTagDetected);
USEFORM("Form\form_NFC_PeerToPeer.cpp", frmNFCPeerToPeer);
USEFORM("Form\form_NFC_RawCommand.cpp", frmNFCRawCommand);
USEFORM("Form\form_NFC.cpp", frmNFC);
USEFORM("Form\form_NFC_TagAccessType1.cpp", frmNFCTagAccessType1);
USEFORM("Form\form_NFC_TagAccessType3.cpp", frmNFCTagAccessType3);
USEFORM("Form\form_NFC_TagAccessType2.cpp", frmNFCTagAccessType2);
USEFORM("Form\form_Crystal_Trim.cpp", frmCrystalTrim);
USEFORM("Form\form_MainPassword.cpp", frmMainPassword);
USEFORM("Form\GPS\form_GPS.cpp", frmGPS);
USEFORM("Form\GPS\form_GPSCWAutoTest.cpp", frmGPSAutoTest);
USEFORM("Form\form_HdcpKey.cpp", frmHdcpKey);
USEFORM("Form\DRMKey\form_DRMKey.cpp", frmDRMKeyInstall);
USEFORM("NFC\nfc_reader_mode.cpp", OKRightDlg);
USEFORM("NFC\NFCMain.cpp", frmNFCNew);
USEFORM("NFC\reader_result.cpp", frm_tag_operation);
USEFORM("NFC\form_NFC_reader.cpp", form_AIRM_Reader);
USEFORM("Form\form_SpecialTest.cpp", frmSpecialTest);
USEFORM("Form\form_WiFiRSSICOMP.cpp", frmRSSICOMP);
USEFORM("Form\RatConfig\form_RatConfig.cpp", frmRatConfig);
USEFORM("Form\MultiSIM\form_MultiSIM.cpp", frmMultiSIM);
USEFORM("Form\form_WiFi6632RSSICOMP.cpp", frm6632RSSICOMP);
USEFORM("Form\AttestationKey\form_AttestationKey.cpp", frmAttestationKeyInstall);
USEFORM("Form\form_MetaConnectTime.cpp", frmMetaConnectTime);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR commandLine, int)
{
    try
    {
        if ((commandLine != NULL) && (::strlen(commandLine) != 0))
        {
            int ret;
            ret = ConsoleMode::Run(GetCommandLine());
            return ret;
        }
    }
    catch ( Exception &exception )
    {
        Application->ShowException( &exception );
    }
    try
    {
        Application->Initialize();
        Application->Title = "SP Meta Tool";
         Application->CreateForm(__classid(TfrmMainSel), &frmMainSel);
                 Application->CreateForm(__classid(TfrmPMICReg), &frmPMICReg);
                 Application->CreateForm(__classid(TfrmBaseBand), &frmBaseBand);
                 Application->CreateForm(__classid(TForm_About), &Form_About);
                 Application->CreateForm(__classid(TfrmGetVersion), &frmGetVersion);
                 Application->CreateForm(__classid(TfrmWiFiMCR), &frmWiFiMCR);
                 Application->CreateForm(__classid(TfrmWiFiBBCR), &frmWiFiBBCR);
                 Application->CreateForm(__classid(TfrmWiFiTxProfile), &frmWiFiTxProfile);
                 Application->CreateForm(__classid(TfrmWiFiScript), &frmWiFiScript);
                 Application->CreateForm(__classid(TfrmWiFiEEPROM), &frmWiFiEEPROM);
                 Application->CreateForm(__classid(TfrmWiFiTxProfile), &frmWiFiTxProfile);
                 Application->CreateForm(__classid(TfrmWiFiALC2400M), &frmWiFiALC2400M);
                 Application->CreateForm(__classid(TfrmWiFi), &frmWiFi);
                 Application->CreateForm(__classid(TfrmNVRAMEditor), &frmNVRAMEditor);
                 Application->CreateForm(__classid(TfrmBT), &frmBT);
                 Application->CreateForm(__classid(Tm_frmProgress), &m_frmProgress);
                 Application->CreateForm(__classid(TfrmFM), &frmFM);
                 Application->CreateForm(__classid(TfrmWmWifi), &frmWmWifi);
                 Application->CreateForm(__classid(TfrmUnitTest), &frmUnitTest);
                 Application->CreateForm(__classid(TfrmSensor), &frmSensor);
                 Application->CreateForm(__classid(TfrmWmWifiMT6620), &frmWmWifiMT6620);
                 Application->CreateForm(__classid(Tfrm2GH_TX_Power_Profile), &frm2GH_TX_Power_Profile);
                 Application->CreateForm(__classid(Tfrm5GHz_TX_Power_Profile), &frm5GHz_TX_Power_Profile);
                 Application->CreateForm(__classid(TfrmNFCTagDetected), &frmNFCTagDetected);
                 Application->CreateForm(__classid(TfrmNFCPeerToPeer), &frmNFCPeerToPeer);
                 Application->CreateForm(__classid(TfrmNFCRawCommand), &frmNFCRawCommand);
                 Application->CreateForm(__classid(TfrmNFC), &frmNFC);
                 Application->CreateForm(__classid(TfrmNFCTagAccessType1), &frmNFCTagAccessType1);
                 Application->CreateForm(__classid(TfrmNFCTagAccessType2), &frmNFCTagAccessType2);
                 Application->CreateForm(__classid(TfrmNFCTagAccessType3), &frmNFCTagAccessType3);
                 Application->CreateForm(__classid(TfrmCrystalTrim), &frmCrystalTrim);
                 Application->CreateForm(__classid(TfrmMainPassword), &frmMainPassword);
                 Application->CreateForm(__classid(TfrmGPS), &frmGPS);
                 Application->CreateForm(__classid(TfrmGPSAutoTest), &frmGPSAutoTest);
                 Application->CreateForm(__classid(TfrmHdcpKey), &frmHdcpKey);
                 Application->CreateForm(__classid(TfrmDRMKeyInstall), &frmDRMKeyInstall);
                 Application->CreateForm(__classid(TfrmNFCNew), &frmNFCNew);
                 Application->CreateForm(__classid(Tform_AIRM_Reader), &form_AIRM_Reader);
                 Application->CreateForm(__classid(TOKRightDlg), &OKRightDlg);
                 Application->CreateForm(__classid(TfrmNFCNew), &frmNFCNew);
                 Application->CreateForm(__classid(Tfrm_tag_operation), &frm_tag_operation);
                 Application->CreateForm(__classid(Tform_AIRM_Reader), &form_AIRM_Reader);
                 Application->CreateForm(__classid(TfrmSpecialTest), &frmSpecialTest);
                 Application->CreateForm(__classid(TfrmMetaConnectTime), &frmMetaConnectTime);
                 Application->CreateForm(__classid(TfrmRSSICOMP), &frmRSSICOMP);
                 Application->CreateForm(__classid(TfrmRatConfig), &frmRatConfig);
                 Application->CreateForm(__classid(TfrmMultiSIM), &frmMultiSIM);
                 Application->CreateForm(__classid(Tfrm6632RSSICOMP), &frm6632RSSICOMP);
                 Application->CreateForm(__classid(TfrmAttestationKeyInstall), &frmAttestationKeyInstall);
                 Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
