//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "form_GPS.h"

#include "METAAPP_common.h"
#include "form_main.h"
#include "misc.h"
#include "man_fdm.h"

// message
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

#ifndef form_GPSCWAutoTestH
#include "form_GPSCWAutoTest.h"
#endif

#ifndef  _MISC_GPS_H_
#include "misc_GPS.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmGPS *frmGPS;
bool bCallback812 = false;
bool bCWCallbackResult = false;
bool bCNRCallbackResult = false;
bool g_bCWTestHideEnable = false;

#define TOTAL_SATELLITE_SYS_COUNT  3
static AnsiString g_satellite_sys[TOTAL_SATELLITE_SYS_COUNT] =
{                                                    
    "GPS(1575.42MHz)",
    "GLONASS(1602MHz)",
    "BEIDOU(1561.098MHz)",
};
//---------------------------------------------------------------------------
static void CNF_GPS_OPEN(void)
{
    frmGPS->CNF_GPS_OPEN();
}

static void CNF_GPS_CLOSE(void)
{
    frmGPS->CNF_GPS_CLOSE();
}

static void CNF_GPS_SendCommand_Start(void)
{
    frmGPS->CNF_GPS_SendCommand_Start();
}

//qinqin 2012-01-12
static void CNF_GPS_SendCommand_Stop(void)
{
    frmGPS->CNF_GPS_SendCommand_Stop();
}
//

//qinqin 2012-02-27
static void CNF_GPS_CWSendCommand_Start(void)
{
    frmGPS->CNF_GPS_CWSendCommand_Start();
}

static void CNF_GPS_CWSendCommand_Stop(void)
{
    frmGPS->CNF_GPS_CWSendCommand_Stop();
}
//

//qinqin 20120510
static void CNF_GPS_CNRSendCommand_Start(void)
{
    frmGPS->CNF_GPS_CNRSendCommand_Start();
}

static void CNF_GPS_CNRSendCommand_Stop(void)
{
    frmGPS->CNF_GPS_CNRSendCommand_Stop();
}


//---------------------------------------------------------------------------
__fastcall TfrmGPS::TfrmGPS(TComponent* Owner)
    : TForm(Owner)
{
    m_bInit = false;
    GPSLog->Clear();
    WindowProc = SubClassWndProc;
//qinqin 20120305
    m_GPSCWTestCtlLocker.AddControl(BtnStart);
    m_GPSCWTestCtlLocker.AddControl(BtnStop);
    m_GPSSignalTestCtlLocker.AddControl(Label1);
    m_GPSSignalTestCtlLocker.AddControl(Label2);
    m_GPSSignalTestCtlLocker.AddControl(Label3);
    m_GPSSignalTestCtlLocker.AddControl(Label4);
    m_GPSSignalTestCtlLocker.AddControl(Label5);
    m_GPSSignalTestCtlLocker.AddControl(Label6);
    m_GPSSignalTestCtlLocker.AddControl(Label7);
    m_GPSSignalTestCtlLocker.AddControl(Label8);
    m_GPSSignalTestCtlLocker.AddControl(Label9);
    m_GPSSignalTestCtlLocker.AddControl(cbBit0);
    m_GPSSignalTestCtlLocker.AddControl(cbBit1);
    m_GPSSignalTestCtlLocker.AddControl(cbBit2);
    m_GPSSignalTestCtlLocker.AddControl(cbBit3);
    m_GPSSignalTestCtlLocker.AddControl(EdtSvid);
    m_GPSSignalTestCtlLocker.AddControl(EDAcquisionValue);
    m_GPSSignalTestCtlLocker.AddControl(EDBitSyncValue);
    m_GPSSignalTestCtlLocker.AddControl(EDPhaseRatioValue);
    m_GPSSignalTestCtlLocker.AddControl(EDTCXOOffsetValue);
    m_GPSSignalTestCtlLocker.AddControl(EDTCXODriftValue);
    m_GPSSignalTestCtlLocker.AddControl(EDCNRMeanValue);
    m_GPSSignalTestCtlLocker.AddControl(EDCNRSigmaValue);
    m_GPSSignalTestCtlLocker.AddControl(EDUpdateValue);

    m_GPSCWTestCtlLocker.AddControl(BtnCWStart);
    m_GPSCWTestCtlLocker.AddControl(BtnCWStop);
    m_GPSCWTestCtlLocker.AddControl(BtnCWAutoTest);
    m_GPSCWTestCtlLocker.AddControl(LabelCWCNR);
    m_GPSCWTestCtlLocker.AddControl(LabelCWClockDrift);
    m_GPSCWTestCtlLocker.AddControl(EDCWCNR);
    m_GPSCWTestCtlLocker.AddControl(EDCWClockDrift);
//

    m_GPSCNRTestCtlLocker.AddControl(BtnCNRStart);
    m_GPSCNRTestCtlLocker.AddControl(BtnCNRStop);
    m_GPSCNRTestCtlLocker.AddControl(LabelCNRTest);
    m_GPSCNRTestCtlLocker.AddControl(LabelCNRSvid);
    m_GPSCNRTestCtlLocker.AddControl(LabelBeidouCNR);
    m_GPSCNRTestCtlLocker.AddControl(LabelBeidouSvid);
    m_GPSCNRTestCtlLocker.AddControl(LabelGlonassCNR);
    m_GPSCNRTestCtlLocker.AddControl(LabelGlonassSvid);
    m_GPSCNRTestCtlLocker.AddControl(EdtCNRSvid);
    m_GPSCNRTestCtlLocker.AddControl(EDCNRModeValue);
    m_GPSCNRTestCtlLocker.AddControl(EdtBeidouSvid);
    m_GPSCNRTestCtlLocker.AddControl(EDBeidouModeValue);
    m_GPSCNRTestCtlLocker.AddControl(EdtGlonassSvid);
    m_GPSCNRTestCtlLocker.AddControl(EDGlonassModeValue);
    m_GPSCNRTestCtlLocker.AddControl(cbGPS);
    m_GPSCNRTestCtlLocker.AddControl(cbBEIDOU);
    m_GPSCNRTestCtlLocker.AddControl(cbGLONASS);
//
    Init();
    InitGLSvidMap();
#ifdef GNSS_CNR_TEST
    GPS_Interval      = 0 ;
    GPS_CNR_Value     = 0;
    BEIDOU_Interval    = 0;
    BEIDOU_CNR_Value   = 0;
    GLONASS_Interval  = 0;
    GLONASS_CNR_Value = 0;
    LableInterval->Visible = true;
    EDInterval->Visible = true;
#endif

}

//----------------------------------------------------------------------------
__fastcall TfrmGPS::~TfrmGPS()
{
    m_vec_CNR.clear();
    m_vec_ClockDrift.clear();
    if ( NULL != m_fpAutoTestLog )
    {
        fclose(m_fpAutoTestLog);
        m_fpAutoTestLog = NULL;
    }
}

//---------------------------------------------------------------------------
void TfrmGPS::Init( void )
{
    m_bInit = true;
    bGPSOpen = false;
    BtnOpenGPS->Enabled = true;
    BtnOpenGPS->Caption = "Open";

    shpGPSOpen->Brush->Color = clRed;
    BtnCloseGPS->Enabled = false;
    BtnStart->Enabled = false;
    BtnClearValue->Enabled = false;
    ResetValue();
    BtnStop->Enabled = false;

    SetTestItem();
    stGPSSPECFile->Caption = ".\\META_GPS_Spec.ini" ;
    m_cGPS_Obj.ReadFromIniFile(".\\META_GPS_Spec.ini");

    m_vec_CNR.clear();
    m_vec_ClockDrift.clear();
    m_CNRAverage = 0.0;
    m_ClockDriftAverage = 0.0;
    m_fpAutoTestLog = NULL;
    m_nCWAutoTestNum = 0;
    m_nCWMaxAutoTestNum = 0;
    memset(m_strAutoTestFilePath,0,GPS_CW_TEST_FILE_PATH_LEN);
    BtnCWStart->Enabled = false;
    BtnCWStop->Enabled = false;
    BtnCWAutoTest->Enabled = false;
    RadioBtnSignalTestMode->Checked = true;
    ResetCWValue();
    BtnCNRStart->Enabled = false;
    BtnCNRStop->Enabled = false;
    ResetCNRValue();

    for(int i=0; i<TOTAL_SATELLITE_SYS_COUNT; i++)
    {
        cbxNavigation->Items->Add(g_satellite_sys[i]);
    }
    cbxNavigation->ItemIndex = 0;
}
//----------------------------------------------------------------------------


void __fastcall TfrmGPS::BtnClearLogClick(TObject *Sender)
{
    GPSLog->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::BtnOpenGPSClick(TObject *Sender)
{
    SetStatusBarString(" Open GPS processing...");
    ResetValue();
    ResetCWValue();
    ResetCNRValue();
    m_cGPS_Obj.REQ_Start(GPS_Open,::CNF_GPS_OPEN);
}
void TfrmGPS::CNF_GPS_OPEN(void)
{
    int state = m_cGPS_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        BtnCloseGPS->Enabled = true;
        if(RadioBtnSignalTestMode->Checked )
        {
            BtnStart->Enabled = true;
            BtnStop->Enabled = true;
        }
        if( RadioBtnCWTestMode->Checked )
        {
            BtnCWStart->Enabled = true;
            BtnCWStop->Enabled = true;
            BtnCWAutoTest->Enabled = true;
        }
        if( RadioBtnCNRTestMode->Checked )
        {
            BtnCNRStart->Enabled = true;
            BtnCNRStop->Enabled = true;
        }
        BtnOpenGPS->Enabled = false;
        shpGPSOpen->Brush->Color = clGreen;
	    cbxNavigation->Enabled = true;
        BtnClearValue->Enabled = true;
        bGPSOpen = true;
        m_bVersionFlag = false;
        SetStatusBarString("Open GPS success");
        break;
    case META_FAILED:
        SetStatusBarString("Open GPS Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString("Open GPS Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString("Open GPS Stop");
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPS::BtnCloseGPSClick(TObject *Sender)
{
    SetStatusBarString(" Close GPS processing...");
//rongguo 2011-07-05
    CallbackTimer->Enabled = false;
//qinqin 2012-03-05
    CallbackCWTimer->Enabled = false;
//
    CallbackCNRTimer->Enabled = false;

    m_cGPS_Obj.REQ_Start(GPS_Close, ::CNF_GPS_CLOSE);
}
//---------------------------------------------------------------------------
void TfrmGPS::CNF_GPS_CLOSE(void)
{
    int state = m_cGPS_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        shpGPSOpen->Brush->Color = clRed;
        BtnCloseGPS->Enabled = false;
        BtnOpenGPS->Enabled = true;
        BtnStart->Enabled = false;
        BtnStop->Enabled = false;
        BtnCWStart->Enabled = false;
        BtnCWStop->Enabled = false;
        BtnCWAutoTest->Enabled = false;
        RadioBtnCWTestMode->Enabled = true;
        RadioBtnSignalTestMode->Enabled = true;
        RadioBtnCNRTestMode->Enabled = true;
        m_nCWAutoTestNum = 0;
        m_nCWMaxAutoTestNum = 0;
        if ( NULL != m_fpAutoTestLog )
        {
            fclose(m_fpAutoTestLog);
            m_fpAutoTestLog = NULL;
        }

        BtnClearValue->Enabled = false;
        bGPSOpen = false;

        SetStatusBarString("Close GPS success");
        break;
    case META_FAILED:
        SetStatusBarString("Close GPS Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString("Close GPS Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString("Close GPS Stop");
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPS::BtnStartClick(TObject *Sender)
{
    ResetValue();
    m_cGPS_Obj.m_sGPS.hPostMsgDestHandle = this->Handle;
    if(!ComposePMTK810Command())
    {
        SetStatusBarString("Compose PMTK810 Command error");
        return;
    }

    m_cGPS_Obj.m_sGPS.gps_cmd.len = m_Len;
    sprintf(m_cGPS_Obj.m_sGPS.gps_cmd.buff,m_Cmd.c_str());
    if(cbBit3->Checked)
    {
        CallbackTimer->Interval = 20000;
    }
    else if(cbBit1->Checked)
    {
        CallbackTimer->Interval = 10000;
    }
    else
    {
        CallbackTimer->Interval = 5000;
    }

    m_cGPS_Obj.REQ_Start(GPS_SendCommand_PMTK810,::CNF_GPS_SendCommand_Start);
}

//---------------------------------------------------------------------------
void TfrmGPS::CNF_GPS_SendCommand_Start(void)
{
    int state = m_cGPS_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        SetStatusBarString("GPS send signal test command success");
        SetStatusBarString(" Receive GPS signal test data processing...");
        bCallback812 = false;
        CallbackTimer->Enabled = true;
        break;
    case META_FAILED:
        SetStatusBarString("GPS send signal test command Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString("GPS send signal test command Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString("GPS send signal test command Stop");
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmGPS::CNF_GPS_SendCommand_Stop(void)
{
    int state = m_cGPS_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        SetStatusBarString("Stop GPS signal test success");
        CallbackTimer->Enabled = false;
        break;
    case META_FAILED:
        SetStatusBarString("Stop GPS signal test Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString("Stop GPS signal test Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString("Stop GPS signal test Stop");
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmGPS::SetStatusBarString(char *strInfo)
{
    stInfo->Caption = (AnsiString) strInfo;
}

bool TfrmGPS::ComposePMTK810Command(void)
{
    char checksum[3] = {0};
    unsigned int CmdTest = 0;
    unsigned char SVid = 29;
    SVid = EdtSvid->Text.ToInt(); //the value is between 1~ 20 in HEX format.
    if (cbBit0->Checked) //test info
    {
        CmdTest |=(1<<0);
    }
    if (cbBit1->Checked) //test acq
    {
        CmdTest |=(1<<1);
    }
    if (cbBit2->Checked) //test bitsync
    {
        CmdTest |=(1<<2);
    }
    if (cbBit3->Checked)
    {
        CmdTest |=(1<<3);
    }

    m_Cmd ="$PMTK810,";
    m_Cmd +=IntToHex((int)CmdTest,4);
    m_Cmd +=",";
    m_Cmd +=IntToHex(SVid,2);
    GenerateCkSum(m_Cmd.c_str(),checksum);
    m_Cmd =m_Cmd+"*"+(AnsiString)checksum;
    OutputLog(m_Cmd.c_str());
    m_Cmd = m_Cmd+"\r\n";
    m_Len = m_Cmd.Length();

    return true;
}

bool TfrmGPS::ComposePMTK811Command(void)
{
    char checksum[3] = {0};
    m_Cmd ="$PMTK811";
    GenerateCkSum(m_Cmd.c_str(),checksum);
    m_Cmd =m_Cmd+"*"+(AnsiString)checksum;
    m_Cmd = m_Cmd+"\r\n";
    m_Len = m_Cmd.Length();
    return true;
}
//---------------------------------------------------------------------------
void TfrmGPS::GenerateCkSum(char *buf, char *result)
{
    char chksum;
    int i,size;

    chksum = buf[1];
    size = strlen(buf);

    for(i=2; i<size ; i++)
        chksum ^= buf[i];

    sprintf(result, "%02X", chksum);
}

void TfrmGPS::OutputLog(AnsiString buf)
{
    AnsiString tempStr = buf;
    tempStr ="["+ TimeToStr(Time())+ "]" +  tempStr + "\r\n";
    GPSLog->Lines->Add(tempStr);
}

void _fastcall TfrmGPS::SubClassWndProc( Messages::TMessage &Message)
{
    switch ( Message.Msg )
    {
    case WM_ML_GPS_PKG_PRINT_MSG:
    {
        switch( (E_GPS_PAGEIDX) Message.WParam )
        {
        case PAGEIDX_GPS_PMTK500:
            CustomizeEdtFont(m_cGPS_Obj.m_bUpdateHz, EDUpdateValue);
            EDUpdateValue->Text = FloatToStrF(m_cGPS_Obj.m_UpdateHz, ffFixed, 7, 3);
            CustomizePanelFont(m_cGPS_Obj.m_bUpdateHz, pnlUpdateResult);
            //
            break;
        case PAGEIDX_GPS_PMTK813:
            CustomizeEdtFont(m_cGPS_Obj.m_bAcquisition, EDAcquisionValue);
            EDAcquisionValue->Text = IntToStr(m_cGPS_Obj.m_Acquisition);
            CustomizePanelFont(m_cGPS_Obj.m_bAcquisition, pnlAcquisionResult);
            //
            break;
        case PAGEIDX_GPS_PMTK814:
            CustomizeEdtFont(m_cGPS_Obj.m_bBitSync, EDBitSyncValue);
            EDBitSyncValue->Text = IntToStr(m_cGPS_Obj.m_BitSync);
            CustomizePanelFont(m_cGPS_Obj.m_bBitSync, pnlBitSyncResult);
            //
            break;
        case PAGEIDX_GPS_PMTK815:
            CustomizeEdtFont(m_cGPS_Obj.m_bPhase, EDPhaseRatioValue);
            EDPhaseRatioValue->Text = FloatToStrF(m_cGPS_Obj.m_Phase,ffFixed,7,3);
            CustomizeEdtFont(m_cGPS_Obj.m_bCNR_Mean, EDCNRMeanValue);
            EDCNRMeanValue->Text = FloatToStrF(m_cGPS_Obj.m_CNR_Mean,ffFixed,7,3);
            CustomizeEdtFont(m_cGPS_Obj.m_bCNR_Sigma, EDCNRSigmaValue);
            EDCNRSigmaValue->Text = FloatToStrF(m_cGPS_Obj.m_CNR_Sigma,ffFixed,7,3);
            CustomizeEdtFont(m_cGPS_Obj.m_bTCXO_Offset, EDTCXOOffsetValue);
            EDTCXOOffsetValue->Text = FloatToStrF(m_cGPS_Obj.m_TCXO_Offset,ffFixed,7,3);
            CustomizeEdtFont(m_cGPS_Obj.m_bTCXO_Drift, EDTCXODriftValue);
            EDTCXODriftValue->Text = FloatToStrF(m_cGPS_Obj.m_TCXO_Drift,ffFixed,7,3);
            CustomizePanelFont(m_cGPS_Obj.m_bPhase, pnlPhaseRatioResult);
            CustomizePanelFont(m_cGPS_Obj.m_bCNR_Mean, pnlCNRMeanResult);
            CustomizePanelFont(m_cGPS_Obj.m_bCNR_Sigma, pnlCNRSigmaResult);
            CustomizePanelFont(m_cGPS_Obj.m_bTCXO_Offset, pnlTCXOOffsetResult);
            CustomizePanelFont(m_cGPS_Obj.m_bTCXO_Drift, pnlTCXODriftResult);
            //
            break;
        case PAGEIDX_GPS_PMTK705:
            if (!m_bVersionFlag)
            {
                m_GPSVersion = "Version:" + m_cGPS_Obj.GetGPSVersion();
                int i = m_GPSVersion.Pos("*");
                i=i+2;
                m_GPSVersion.SetLength(i);
                OutputLog(m_GPSVersion);
                m_bVersionFlag = true;
            }
            break;
        case PAGEIDX_GPS_PMTK812:
            OutputLog("$PMTK812*39");
            SetStatusBarString("Meta GPS Signal Test PASS");
            bCallback812 = true;
            CallbackTimer->Enabled = false;
            RadioBtnCWTestMode->Enabled = true;
            break;
        case PAGEIDX_GPS_PMTK817:
            bCWCallbackResult = true;
            CallbackCWTimer->Enabled = false;
	        cbxNavigation->Enabled = true;
            CustomizeEdtFont(m_cGPS_Obj.m_bCWNR, EDCWCNR);
            EDCWCNR->Text = FloatToStrF(m_cGPS_Obj.m_CWCNR,ffFixed,7,3);
            CustomizePanelFont(m_cGPS_Obj.m_bCWNR, pnlCWCNRResult);
            CustomizeEdtFont(m_cGPS_Obj.m_bCWClockDrift, EDCWClockDrift);
            EDCWClockDrift->Text = FloatToStrF(m_cGPS_Obj.m_CWClockDrift,ffFixed,7,3);
            CustomizePanelFont(m_cGPS_Obj.m_bCWClockDrift, pnlCWClockDriftResult);
            if( m_fpAutoTestLog != NULL)
            {
                if( m_nCWAutoTestNum > 0 && m_nCWMaxAutoTestNum > 0  )
                {
                    if( m_cGPS_Obj.m_bCWNR && m_cGPS_Obj.m_bCWClockDrift)
                    {
                        fprintf(m_fpAutoTestLog, "%4d  PASS CNR = %s, Clock Drift = %s\n",
                                m_nCWMaxAutoTestNum - m_nCWAutoTestNum + 1,EDCWCNR->Text,EDCWClockDrift->Text);
                    }
                    else
                    {
                        fprintf(m_fpAutoTestLog, "%4d  FAIL CNR = %s, Clock Drift = %s\n",
                                m_nCWMaxAutoTestNum - m_nCWAutoTestNum + 1,EDCWCNR->Text,EDCWClockDrift->Text);
                    }
                    m_vec_CNR.push_back(StrToFloat(EDCWCNR->Text));     //qinqin 2012-03-13
                    m_vec_ClockDrift.push_back(StrToFloat(EDCWClockDrift->Text));
                }
            }
            if( m_nCWAutoTestNum > 0 && m_nCWMaxAutoTestNum > 0 )
            {
                m_nCWAutoTestNum--;
                if( m_nCWAutoTestNum == 0 )
                {
                    CalcCWAverage();
                    ResetCWValue();
                    m_cGPS_Obj.JudgeCNRValue(m_CNRAverage,m_ClockDriftAverage);      //judge average value pass or fail
                    EDCWCNR->Text = FloatToStrF(m_CNRAverage,ffFixed,7,3);
                    EDCWClockDrift->Text = FloatToStrF(m_ClockDriftAverage,ffFixed,7,3);
                    CustomizePanelFont(m_cGPS_Obj.m_bCWNR, pnlCWCNRResult);
                    CustomizePanelFont(m_cGPS_Obj.m_bCWClockDrift, pnlCWClockDriftResult);
                }
            }

            if( m_cGPS_Obj.m_bCWNR && m_cGPS_Obj.m_bCWClockDrift)
            {
                SetStatusBarString("Meta GPS CW Mode Test PASS");
            }
            else
            {
                SetStatusBarString("Meta GPS CW Mode Test FAIL");
            }
            PostMessage(this->Handle,
                        WM_ML_GPS_PKG_CW_AUTO_TEST_MSG,
                        0,0);

            break;
        case PAGEIDX_GPS_GPGSV:
	     {
            int interval = EDInterval->Text.ToInt();
			int sys_idx = (int)Message.LParam;
            float value = 0.0;
			if(sys_idx == SATELLITE_GPS)
            {
#ifdef GNSS_CNR_TEST
                GPS_Interval++;
                GPS_CNR_Value += m_cGPS_Obj.m_CNRMode_CNR[sys_idx];
		        LOG("------>GPS Interval = %d, CNR = %f", GPS_Interval, GPS_CNR_Value);
                if((interval > 0) && (GPS_Interval == interval))
                {
                   value = GPS_CNR_Value/interval;
                   LOG("------>GPS value = %f", value);
                  // CustomizeEdtFont(m_cGPS_Obj.m_bCNRModeCNR[sys_idx], EDCNRModeValue);
                   EDCNRModeValue->Text = FloatToStrF(value,ffFixed,5,1);
                   GPS_Interval = 0;
	               GPS_CNR_Value = 0;
                }
#else
                if(cbGPS->Checked)
                {
                    //CustomizeEdtFont(m_cGPS_Obj.m_bCNRModeCNR[sys_idx], EDCNRModeValue);
                    EDCNRModeValue->Text = FloatToStrF(m_cGPS_Obj.m_CNRMode_CNR[sys_idx],ffFixed,5,1);
                }
#endif
			}
			else if(sys_idx == SATELLITE_BEIDOU)
            {
#ifdef GNSS_CNR_TEST
                BEIDOU_Interval++;
                BEIDOU_CNR_Value += m_cGPS_Obj.m_CNRMode_CNR[sys_idx];
                if((interval > 0) && (BEIDOU_Interval == interval))
                {
                   value = BEIDOU_CNR_Value/interval;
                   //CustomizeEdtFont(m_cGPS_Obj.m_bCNRModeCNR[sys_idx], EDBeidouModeValue);
                   EDBeidouModeValue->Text = FloatToStrF(value,ffFixed,5,1);
                   BEIDOU_Interval = 0;
                   BEIDOU_CNR_Value = 0;
                }
#else
                if(cbBEIDOU->Checked)
                {
                   // CustomizeEdtFont(m_cGPS_Obj.m_bCNRModeCNR[sys_idx], EDBeidouModeValue);
                    EDBeidouModeValue->Text = FloatToStrF(m_cGPS_Obj.m_CNRMode_CNR[sys_idx],ffFixed,5,1);
                }
#endif
            }
			else if(sys_idx == SATELLITE_GLONASS)
			{
#ifdef GNSS_CNR_TEST
                GLONASS_Interval++;
                GLONASS_CNR_Value += m_cGPS_Obj.m_CNRMode_CNR[sys_idx];
		        LOG("------>GLONASS Interval = %d, CNR = %f", GLONASS_Interval, GLONASS_CNR_Value);
                if((interval > 0) && (GLONASS_Interval == interval))
                {
                    value = GLONASS_CNR_Value/interval;
		            LOG("------>GLONASS value = %f", value);
                    //CustomizeEdtFont(m_cGPS_Obj.m_bCNRModeCNR[sys_idx], EDGlonassModeValue);
                    EDGlonassModeValue->Text = FloatToStrF(value,ffFixed,5,1);
                    GLONASS_Interval = 0;
		            GLONASS_CNR_Value = 0;
                }
#else
                if(cbGLONASS->Checked)
                {
                    //CustomizeEdtFont(m_cGPS_Obj.m_bCNRModeCNR[sys_idx], EDGlonassModeValue);
                    EDGlonassModeValue->Text = FloatToStrF(m_cGPS_Obj.m_CNRMode_CNR[sys_idx],ffFixed,5,1);
                }
#endif
            }
            CustomizePanelFont(m_cGPS_Obj.m_bCNRModeCNR[sys_idx], pnlCNRTestResult);
            bCNRCallbackResult = true;
            CallbackCNRTimer->Enabled = false;
            if(m_cGPS_Obj.m_bCNRModeCNR[sys_idx])
            {
                SetStatusBarString("Meta CNR Mode Test PASS");
            }
            else
            {
                SetStatusBarString("Meta CNR Mode Test FAIL");
            }
            }
            break;
        default:
            break;
        }
    }
    break;
    case WM_ML_GPS_PKG_ERROR_MSG:
    {
        switch( (E_GPS_PAGEIDX) Message.WParam )
        {
        case PAGEIDX_GPS_PMTK500_ERROR:
            OutputLog("UpdataHz value error") ;
            break;
        case PAGEIDX_GPS_PMTK813_ERROR:
            OutputLog("Acquisition value error");
            break;
        case PAGEIDX_GPS_PMTK814_ERROR:
            OutputLog("BitSync value error");
            break;
        case PAGEIDX_GPS_PMTK815_CNR_MEAN_ERROR:
            OutputLog("CNR Mean value error");
            break;
        case PAGEIDX_GPS_PMTK815_CNR_SIGMA_ERROR:
            OutputLog("CNR Sigma value error");
            break;
        case PAGEIDX_GPS_PMTK815_Phase_ERROR:
            OutputLog("Phase ratio value error");
            break;
        case PAGEIDX_GPS_PMTK815_TCXO_OFFSET_ERROR:
            OutputLog("TCXO Offset value error");
            break;
        case PAGEIDX_GPS_PMTK815_TCXO_DRIFT_ERROR:
            OutputLog("TCXO Drift value error");
            break;
        case PAGEIDX_GPS_PMTK001_ERROR:
            SetStatusBarString("No available Satellite signal");
            break;
        case PAGEIDX_GPS_PMTK812_ERROR:
            OutputLog("$PMTK812*39");
            SetStatusBarString("Meta GPS Signal Test Fail");
            bCallback812 = true;
            CallbackTimer->Enabled = false;
            RadioBtnCWTestMode->Enabled = true;
            break;
        case PAGEIDX_GPS_PMTK817_CNR_ERROR:
            OutputLog("CNR value error");
            break;
        case PAGEIDX_GPS_PMTK817_CLOCK_DRIFT_ERROR:
            OutputLog("Clock Drift value error");
            break;
        case PAGEIDX_GPS_GPGSV_CNR_ERROR:
            GnssCtl(true);
            bCNRCallbackResult = true;
            CallbackCNRTimer->Enabled = false;
            OutputLog("CNR Mode CNR value error");
            SetStatusBarString("Meta CNR Test Fail");
            break;
        case PAGEIDX_GPS_PKG_ERROR:
            SetStatusBarString("Decompose package error\r\n");
            break;
        default:
            SetStatusBarString("GPS unknown error");
            break;
        }
    }
    break;
    case WM_ML_GPS_PKG_CW_AUTO_TEST_MSG:
        CWAutoTestControl();
        break;
    default:
        this->WndProc( Message );
        break;
    }
}



void __fastcall TfrmGPS::BtntestClick(TObject *Sender)
{
    ResetValue();
    GPS_ACK_BUF buf;
    char a[]= "$PMTK705,AXN_1.2,0840,MNL_VER_09030301651602*35\r\n$PMTK813,29,11*01\r\n$PMTK514,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0*2E\r\n$PMTK500,1000,0,0,0.0,0.0*1A\r\n\r$PMTK814,29,6*05\r\n$PMTK815,29,16,84,10000,30,4100,1*18\r\n$PMTK812*39\r\n";
    int i = sizeof(a);
    sprintf(buf.buff,a,i);
    buf.len =  i;
    int usedata = 1;
    m_cGPS_Obj.CNF_GPSSendCommand_PMTK810(&buf, 10, &usedata);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPS::EdtSvidExit(TObject *Sender)
{
    unsigned int n_data = 0;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = {" value should be 1~32 "};

    text = EdtSvid->Text;
    if( !IsValidGPSSvid( text, n_data ) )
    {
        edit->Text = 29;
        ShowHintLabel( edit, hint );
        EdtSvid->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------
void  TfrmGPS::ShowHintLabel( TControl *sender, char* hint )
{
    TPoint pt0 = this->ClientOrigin;
    TPoint pt1 = sender->ClientOrigin;
    lblHint->Left = (pt1.x-pt0.x);
    lblHint->Top  = (pt1.y-pt0.y)+sender->Height+3;
    lblHint->Caption = hint;
    lblHint->Visible = true;
    HintTimer->Enabled = true;
}

void __fastcall TfrmGPS::HintTimerTimer(TObject *Sender)
{
    HintTimer->Enabled = false;
    lblHint->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::BtnClearValueClick(TObject *Sender)
{
    ResetValue();
}
//---------------------------------------------------------------------------
void TfrmGPS::ResetValue(void)
{

    EDUpdateValue->Font->Color = clWindowText;
    EDAcquisionValue->Font->Color = clWindowText;
    EDBitSyncValue->Font->Color = clWindowText;
    EDPhaseRatioValue->Font->Color = clWindowText;
    EDCNRMeanValue->Font->Color = clWindowText;
    EDCNRSigmaValue->Font->Color = clWindowText;
    EDTCXOOffsetValue->Font->Color = clWindowText;
    EDTCXODriftValue->Font->Color = clWindowText;
    EDUpdateValue->Text = "0";
    EDAcquisionValue->Text = "0";
    EDBitSyncValue->Text = "0";
    EDPhaseRatioValue->Text = "0";
    EDCNRMeanValue->Text = "0";
    EDCNRSigmaValue->Text = "0";
    EDTCXOOffsetValue->Text = "0";
    EDTCXODriftValue->Text = "0";
    pnlUpdateResult->Caption = "";
    pnlAcquisionResult->Caption = "";
    pnlBitSyncResult->Caption = "";
    pnlPhaseRatioResult->Caption = "";
    pnlCNRMeanResult->Caption = "";
    pnlCNRSigmaResult->Caption = "";
    pnlTCXOOffsetResult->Caption = "";
    pnlTCXODriftResult->Caption = "";
}


void __fastcall TfrmGPS::BtnLoadSPECClick(TObject *Sender)
{
    miOpenGPSInitialFileClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPS::miOpenGPSInitialFileClick(TObject *Sender)
{
    if ( dlg_OpenIniFile->Execute() )
    {
        b_OpenIniFile = false;
        if( m_cGPS_Obj.ReadFromIniFile( dlg_OpenIniFile->FileName ) == false )
        {
            Application->MessageBox( "Read ini file fail", "FAILURE", MB_OK );
            return;
        }
        stGPSSPECFile->Caption = dlg_OpenIniFile->FileName.c_str();
        // write_GPS_SPEC_File( "MF_setup.txt", Application->ExeName, stIniFile->Caption );
    }
}
void TfrmGPS::DisableTestItem(void)
{
    cbBit0->State = cbChecked;
    cbBit1->State = cbChecked;
    cbBit2->State = cbChecked;
    cbBit3->State = cbChecked;
    cbBit0->Enabled = false;
    cbBit1->Enabled = false;
    cbBit2->Enabled = false;
    cbBit3->Enabled = false;
}
void TfrmGPS::CustomizeEdtFont(bool bflag,TObject *Sender)
{
    TEdit *edit = (TEdit*)Sender;
    if(bflag)
    {
        edit->Font->Color = clWindowText;
    }
    else
    {
        edit->Font->Color = clRed;
    }

}

//qinqin 2012-01-06
void TfrmGPS::CustomizePanelFont(bool bflag,TObject *Sender)
{
    TPanel *panel = (TPanel*)Sender;
    if(bflag)
    {
        panel->Font->Color = clActiveCaption;
        panel->Caption = "PASS";

    }
    else
    {
        panel->Font->Color = clRed;
        panel->Caption = "Fail";
    }
}
//


//qinqin 2012-01-06
void TfrmGPS::SetTestItem( void )
{
    if( cbBit0->State == cbChecked )
    {
//        Label6->Enabled = true;
        EDUpdateValue->Enabled = true;
    }
    else
    {
//        Label6->Enabled = false;
        EDUpdateValue->Enabled = false;
    }
    if( cbBit1->State == cbChecked )
    {
//        Label9->Enabled = true;
        EDAcquisionValue->Enabled = true;
    }
    else
    {
//        Label9->Enabled = false;
        EDAcquisionValue->Enabled = false;
    }
    if( cbBit2->State == cbChecked )
    {
//        Label8->Enabled = true;
        EDBitSyncValue->Enabled = true;
    }
    else
    {
//        Label8->Enabled = false;
        EDBitSyncValue->Enabled = false;
    }
    if( cbBit3->State == cbChecked )
    {
//        Label1->Enabled = true;
        EDPhaseRatioValue->Enabled = true;
//        Label2->Enabled = true;
        EDTCXOOffsetValue->Enabled = true;
//        Label5->Enabled = true;
        EDTCXODriftValue->Enabled = true;
//        Label4->Enabled = true;
        EDCNRMeanValue->Enabled = true;
//        Label7->Enabled = true;
        EDCNRSigmaValue->Enabled = true;
    }
    else
    {
//         Label1->Enabled = false;
        EDPhaseRatioValue->Enabled = false;
//         Label2->Enabled = false;
        EDTCXOOffsetValue->Enabled = false;
//         Label5->Enabled = false;
        EDTCXODriftValue->Enabled = false;
//         Label4->Enabled = false;
        EDCNRMeanValue->Enabled = false;
//         Label7->Enabled = false;
        EDCNRSigmaValue->Enabled = false;
    }

}
//

//---------------------------------------------------------------------------

void __fastcall TfrmGPS::CheckAcqEnable(TObject *Sender)
{
    if (cbBit2->State == cbChecked)
    {
        cbBit1->State = cbChecked;
    }
    else if (cbBit2->State == cbUnchecked)
    {
        cbBit3->State = cbUnchecked;
    }
//qinqin 2012-01-06
    SetTestItem();
//
    return;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::CheckBitsyncEnable(TObject *Sender)
{
    if (cbBit3->State == cbChecked)
    {
        cbBit2->State = cbChecked;
    }
//qinqin 2012-01-06
    SetTestItem();
//
    return;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPS::CheckBitsyncAndSignalDisanble(TObject *Sender)
{
    if (cbBit1->State == cbUnchecked)
    {
        cbBit2->State = cbUnchecked;
        cbBit3->State = cbUnchecked;
    }
//qinqin 2012-01-06
    SetTestItem();
//
    return;
}
//rongguo 2011-07-05
//---------------------------------------------------------------------------
void __fastcall TfrmGPS::CallbackTimerTimer(TObject *Sender)
{
    if(false == bCallback812)
    {
        BtnCloseGPSClick(Sender);
        Application->MessageBox( "Meta GPS Test timeout", "Timeout", MB_OK );

    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::CheckInfoEnable(TObject *Sender)
{
    SetTestItem();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGPS::BtnStopClick(TObject *Sender)
{
    ResetValue();
    m_cGPS_Obj.m_sGPS.hPostMsgDestHandle = this->Handle;
    if(!ComposePMTK811Command())
    {
        SetStatusBarString("Compose PMTK811 Command error");
        return;
    }
    m_cGPS_Obj.m_sGPS.gps_cmd.len = m_Len;
    sprintf(m_cGPS_Obj.m_sGPS.gps_cmd.buff,m_Cmd.c_str());
    m_cGPS_Obj.REQ_Start(GPS_SendCommand_PMTK811,::CNF_GPS_SendCommand_Stop);
}
//---------------------------------------------------------------------------

void TfrmGPS::GetCWAutoTestParam(int& nAutoTestNum, char* strAutoTestFilePath )
{
    m_nCWAutoTestNum = nAutoTestNum;
    memset(m_strAutoTestFilePath,0,GPS_CW_TEST_FILE_PATH_LEN);
    memcpy(m_strAutoTestFilePath,strAutoTestFilePath,strlen(strAutoTestFilePath));
}


void __fastcall TfrmGPS::RadioBtnSignalTestModeClick(TObject *Sender)
{
    if(RadioBtnSignalTestMode->Checked)
    {
        m_GPSSignalTestCtlLocker.Unlock();
        m_GPSCWTestCtlLocker.Unlock();
        m_GPSCNRTestCtlLocker.Unlock();
        RadioBtnCWTestMode->Checked = false;
        RadioBtnCNRTestMode->Checked = false;
        m_GPSCWTestCtlLocker.Lock();
        m_GPSCNRTestCtlLocker.Lock();
        if ( bGPSOpen )
        {
            BtnStart->Enabled = true;
            BtnStop->Enabled = true;
        }
        else
        {
            BtnStart->Enabled = false;
            BtnStop->Enabled = false;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::RadioBtnCWTestModeClick(TObject *Sender)
{
    if(RadioBtnCWTestMode->Checked)
    {
        m_GPSCWTestCtlLocker.Unlock();
        m_GPSSignalTestCtlLocker.Unlock();
        m_GPSCNRTestCtlLocker.Unlock();
        RadioBtnSignalTestMode->Checked = false;
        RadioBtnCNRTestMode->Checked = false;
        m_GPSSignalTestCtlLocker.Lock();
        m_GPSCNRTestCtlLocker.Lock();
        if ( bGPSOpen )
        {
            BtnCWStart->Enabled = true;
            BtnCWStop->Enabled = true;
            BtnCWAutoTest->Enabled = true;
        }
        else
        {
            BtnCWStart->Enabled = false;
            BtnCWStop->Enabled = false;
            BtnCWAutoTest->Enabled = false;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::BtnCWStartClick(TObject *Sender)
{
    ResetCWValue();
    m_cGPS_Obj.m_sGPS.hPostMsgDestHandle = this->Handle;
    if(!ComposePMTK817StartCommand())
    {
        SetStatusBarString("Compose PMTK817 Start Command error");
        return;
    }
//qinqin
    m_cGPS_Obj.m_sGPS.gps_cmd.len = m_Len;
    sprintf(m_cGPS_Obj.m_sGPS.gps_cmd.buff,m_Cmd.c_str());
    if( !(m_nCWAutoTestNum > 0 && m_nCWMaxAutoTestNum > 0)  )
    {
        BtnCWAutoTest->Enabled = false;
    }
    cbxNavigation->Enabled = false;
//qinqin 2012-03-04
//     RadioBtnSignalTestMode->Enabled = false;
//     RadioBtnCNRTestMode->Enabled = false;
//
    CallbackCWTimer->Interval = 5000;
    m_cGPS_Obj.REQ_Start(GPS_SendStartCommand_PMTK817,::CNF_GPS_CWSendCommand_Start);
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::CallbackCWTimerTimer(TObject *Sender)
{
    if(false == bCWCallbackResult)
    {
        if( m_nCWAutoTestNum > 0 && m_nCWMaxAutoTestNum > 0 )
        {
            bCWCallbackResult = true;
            CallbackCWTimer->Enabled = false;
            if( m_fpAutoTestLog != NULL)
            {
                fprintf(m_fpAutoTestLog, "%4d  GPS CW test timeout\n", m_nCWMaxAutoTestNum - m_nCWAutoTestNum + 1);
            }

            char strCWAutoTestPrompt[100] = {0};
            sprintf(strCWAutoTestPrompt,"%d times GPS CW test timeout",m_nCWMaxAutoTestNum - m_nCWAutoTestNum + 1);
            SetStatusBarString(strCWAutoTestPrompt);
            m_nCWAutoTestNum--;
            PostMessage(this->Handle,WM_ML_GPS_PKG_CW_AUTO_TEST_MSG,0,0);
        }
        else if( m_nCWMaxAutoTestNum == 0 && m_nCWAutoTestNum == 0)
        {
            BtnCloseGPSClick(Sender);
            Application->MessageBox( "Meta CW test timeout", "Timeout", MB_OK );
        }

    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::BtnCWStopClick(TObject *Sender)
{
    ResetCWValue();
    m_cGPS_Obj.m_sGPS.hPostMsgDestHandle = this->Handle;
    if(!ComposePMTK817StopCommand())
    {
        SetStatusBarString("Compose PMTK817 Stop Command error");
        return;
    }

    m_nCWMaxAutoTestNum = 0;
    m_nCWAutoTestNum = 0;
    BtnCWStart->Enabled = true;
    BtnCWAutoTest->Enabled = true;
    cbxNavigation->Enabled = true;

    if ( NULL != m_fpAutoTestLog )
    {
        fclose(m_fpAutoTestLog);
        m_fpAutoTestLog = NULL;

        CalcCWAverage();
        ResetCWValue();
        EDCWCNR->Text = FloatToStrF(m_CNRAverage,ffFixed,7,3);
        EDCWClockDrift->Text = FloatToStrF(m_ClockDriftAverage,ffFixed,7,3);
    }

    m_cGPS_Obj.m_sGPS.gps_cmd.len = m_Len;
    sprintf(m_cGPS_Obj.m_sGPS.gps_cmd.buff,m_Cmd.c_str());
    m_cGPS_Obj.REQ_Start(GPS_SendStopCommand_PMTK817,::CNF_GPS_CWSendCommand_Stop);
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::BtnCWAutoTestClick(TObject *Sender)
{
    frmGPSAutoTest->ShowModal();
    if ( m_nCWAutoTestNum > 0 )
    {
        if ( NULL != m_fpAutoTestLog )
        {
            fclose(m_fpAutoTestLog);
            m_fpAutoTestLog = NULL;
        }
        m_fpAutoTestLog = fopen(m_strAutoTestFilePath, "w");
        if ( NULL == m_fpAutoTestLog )
        {
            Application->MessageBox( "Create CW test mode auto test file fail", "FAILURE", MB_OK );
            return;
        }
        m_nCWMaxAutoTestNum = m_nCWAutoTestNum;
        m_vec_CNR.clear();
        m_vec_ClockDrift.clear();
        m_CNRAverage = 0.0;
        m_ClockDriftAverage = 0.0;
        //
        PostMessage(this->Handle,WM_ML_GPS_PKG_CW_AUTO_TEST_MSG,0,0);

    }
    else
    {
        m_nCWMaxAutoTestNum = 0;
        m_nCWAutoTestNum = 0;
        if ( NULL != m_fpAutoTestLog )
        {
            fclose(m_fpAutoTestLog);
            m_fpAutoTestLog = NULL;
        }
    }
}

//---------------------------------------------------------------------------
void TfrmGPS::ApplyCWHideProperty(void)
{
    GBCWTest->Visible = !g_bCWTestHideEnable;
    BtnCWStart->Visible = !g_bCWTestHideEnable;
    BtnCWStop->Visible = !g_bCWTestHideEnable;
    BtnCWAutoTest->Visible = !g_bCWTestHideEnable;
    LabelCWCNR->Visible = !g_bCWTestHideEnable;
    LabelCWClockDrift->Visible = !g_bCWTestHideEnable;
    EDCWCNR->Visible = !g_bCWTestHideEnable;
    EDCWClockDrift->Visible = !g_bCWTestHideEnable;
}

//---------------------------------------------------------------------------
void __fastcall TfrmGPS::CWHideFlagExecute(TObject *Sender)
{
    g_bCWTestHideEnable = g_bCWTestHideEnable ? false : true;
    ApplyCWHideProperty();
}
//---------------------------------------------------------------------------
bool TfrmGPS::ComposePMTK817StartCommand(void)
{
    char checksum[3] = {0};
    m_Cmd ="$PMTK817,1";
    if(cbxNavigation->ItemIndex > 0)
    	m_Cmd += "," + IntToStr(cbxNavigation->ItemIndex);
    GenerateCkSum(m_Cmd.c_str(),checksum);   
    m_Cmd += "*"+(AnsiString)checksum + "\r\n";
    OutputLog(m_Cmd.c_str());
    m_Len = m_Cmd.Length();
    return true;
}

bool TfrmGPS::ComposePMTK817StopCommand(void)
{
    char checksum[3] = {0};
    m_Cmd ="$PMTK817,0";
    GenerateCkSum(m_Cmd.c_str(),checksum);
    if(cbxNavigation->ItemIndex > 0)
	    m_Cmd += "," + IntToStr(cbxNavigation->ItemIndex);
    m_Cmd += "*"+(AnsiString)checksum + "\r\n";
    OutputLog(m_Cmd.c_str());
    m_Len = m_Cmd.Length();
    return true;
}

void TfrmGPS::CNF_GPS_CWSendCommand_Start(void)
{
    int state = m_cGPS_Obj.Get_ConfirmState();
    char strCWTestResult[100] = {0};
    switch (state)
    {
    case META_SUCCESS:
        SetStatusBarString("Start GPS CW test success");
        if( m_nCWAutoTestNum > 0 && m_nCWMaxAutoTestNum > 0  )
        {
            char  strCWAutoTestPrompt[100] = {0};
            if( m_nCWMaxAutoTestNum - m_nCWAutoTestNum == 0)
            {
                sprintf(strCWAutoTestPrompt,"%d time receive GPS CW test data processing...",m_nCWMaxAutoTestNum - m_nCWAutoTestNum + 1);
            }
            else
            {
                sprintf(strCWAutoTestPrompt,"%d times receive GPS CW test data processing...",m_nCWMaxAutoTestNum - m_nCWAutoTestNum + 1);
            }
            SetStatusBarString(strCWAutoTestPrompt);

        }
        else if( m_nCWMaxAutoTestNum == 0 )
        {
            SetStatusBarString(" Receive signal test data processing...");
        }
        sprintf(strCWTestResult,"Start CW test success");
        bCWCallbackResult = false;
        CallbackCWTimer->Enabled = true;
        break;
    case META_FAILED:
        SetStatusBarString("Start CW test Fail");
        sprintf(strCWTestResult,"Start CW test Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString("Start CW test Time out");
        sprintf(strCWTestResult,"Start CW test Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString("Start CW test Stop");
        sprintf(strCWTestResult,"Start CW test Stop");
        break;
    default:
        break;
    }

}

void TfrmGPS::CNF_GPS_CWSendCommand_Stop(void)
{
    int state = m_cGPS_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        SetStatusBarString("Stop CW test success");
//                    RadioBtnSignalTestMode->Enabled = true;
//                    RadioBtnCNRTestMode->Enabled = true;
        CallbackCWTimer->Enabled = false;
        break;
    case META_FAILED:
        SetStatusBarString("Stop CW test Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString("Stop CW test Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString("Stop CW test Stop");
        break;
    default:
        break;
    }

}

void TfrmGPS::ResetCWValue(void)
{
//qinqin 2012-03-07
    EDCWCNR->Font->Color = clWindowText;
    EDCWClockDrift->Font->Color = clWindowText;
//
    EDCWCNR->Text = "0";
    EDCWClockDrift->Text = "0";
    pnlCWCNRResult->Caption = "";
    pnlCWClockDriftResult->Caption = "";

}


void TfrmGPS::CWAutoTestControl(void)
{
    if( m_nCWAutoTestNum > 0 && m_nCWMaxAutoTestNum > 0  )
    {
        BtnCWStartClick(NULL);
        BtnCWStart->Enabled = false;
    }
    else
    {
        if( m_nCWMaxAutoTestNum > 0 )
        {
            if ( NULL != m_fpAutoTestLog )
            {
                fclose(m_fpAutoTestLog);
                m_fpAutoTestLog = NULL;
            }
            m_nCWMaxAutoTestNum = 0;
            BtnCWStart->Enabled = true;
        }
        BtnCWAutoTest->Enabled = true;

        RadioBtnSignalTestMode->Enabled = true;
    }

}


void TfrmGPS::CalcCWAverage(void)
{
    unsigned int i = 0;
    float sum = 0.0;
    m_CNRAverage = 0.0;
    m_ClockDriftAverage = 0.0;
    for ( i=0; i< m_vec_CNR.size(); i++ )
    {
        sum += m_vec_CNR[i];
    }
    if( m_vec_CNR.size()> 0)
    {
        m_CNRAverage = sum/m_vec_CNR.size();
    }
    else
    {
        m_CNRAverage = 0.0;
    }
    sum = 0.0;
    for ( i=0; i< m_vec_ClockDrift.size(); i++ )
    {
        sum += m_vec_ClockDrift[i];
    }
    if( m_vec_ClockDrift.size() > 0)
    {
        m_ClockDriftAverage = sum/m_vec_ClockDrift.size();
    }
    else
    {
        m_ClockDriftAverage = 0.0;
    }

}
void __fastcall TfrmGPS::RadioBtnCNRTestModeClick(TObject *Sender)
{
    if(RadioBtnCNRTestMode->Checked)
    {
        m_GPSCNRTestCtlLocker.Unlock();
        m_GPSCWTestCtlLocker.Unlock();
        m_GPSSignalTestCtlLocker.Unlock();
        RadioBtnCWTestMode->Checked = false;
        m_GPSCWTestCtlLocker.Lock();
        RadioBtnSignalTestMode->Checked = false;
        m_GPSSignalTestCtlLocker.Lock();
        if ( bGPSOpen )
        {
            BtnCNRStart->Enabled = true;
            BtnCNRStop->Enabled = true;
        }
        else
        {
            BtnCNRStart->Enabled = false;
            BtnCNRStop->Enabled = false;
        }
    }
}
//---------------------------------------------------------------------------


void TfrmGPS::ResetCNRValue(void)
{
    EDCNRModeValue->Font->Color = clWindowText;
    EDCNRModeValue->Text = "0";
    pnlCNRTestResult->Caption = "";

   EDBeidouModeValue->Text = "0";
   EDGlonassModeValue->Text = "0";
}
void __fastcall TfrmGPS::BtnCNRStartClick(TObject *Sender)
{
    ResetCNRValue();
    m_cGPS_Obj.m_sGPS.hPostMsgDestHandle = this->Handle;
//rongguo 2011-07-06
//     SetStatusBarString(" Receive GPS data processing...");
    if(!ComposePMTK810CNRStartCommand())
    {
        SetStatusBarString("Compose PMTK810 Command error");
        return;
    }

//    RadioBtnCWTestMode->Enabled = false;
//    RadioBtnSignalTestMode->Enabled = false;
    GnssCtl(false);
    m_cGPS_Obj.m_sGPS.gps_cmd.len = m_Len;
    sprintf(m_cGPS_Obj.m_sGPS.gps_cmd.buff,m_Cmd.c_str());

    CallbackCNRTimer->Interval = 5000;

    m_cGPS_Obj.REQ_Start(GPS_SendCNRStartCommand_PMTK810,::CNF_GPS_CNRSendCommand_Start);
}
//---------------------------------------------------------------------------
bool TfrmGPS::TestGNSS()
{
    unsigned char GlonassSVid  = 69;
    unsigned char GPSSVid  = 29;
//    char buf1[] = "$GLGSV,2,1,6,69,76,077,27.8,83,40,088,31.5,70,38,196,24.8,68,26,031,28.2*57";
//    char buf2[] = "$GLGSV,2,2,6,75,07,297,,74,06,249,*50,31.5,70,38,196,24.8,68,26,031,28.2*57";

    char buf1[] = "$GLGSV,2,1,7,67,71,157,33.5,78,55,315,35.0,68,50,330,37.9,77,28,023,32.0*524E5";
    char buf2[] = "$GLGSV,2,2,7,79,27,253,32.3,66,16,153,32.5,87,01,080,20.9*78,28,023,32.0*524E5";

    char buf3[] = "$GLGSV,2,1,7,67,71,157,34.4,78,55,315,36.4,68,50,330,37.6,77,28,023,31.5*5A435";
    char buf4[] = "$GLGSV,2,2,7,79,27,253,32.1,66,16,153,32.0,87,01,080,21.7*70,28,023,31.5*5A435";

    char buf5[] = "$GLGSV,2,1,7,67,71,157,34.4,78,55,315,33.6,68,50,330,37.3,77,28,023,31.7*5A455";
    char buf6[] = "$GLGSV,2,2,7,79,27,253,32.2,66,16,153,33.0,87,01,080,22.3*75,28,023,31.7*5A455";

    char buf7[] = "$GLGSV,2,1,7,67,71,157,34.6,78,55,315,33.7,68,50,330,36.4,77,28,023,31.4*5C485";
    char buf8[] = "$GLGSV,2,2,7,79,27,253,31.4,66,16,153,32.6,87,01,080,22.2*76,28,023,31.4*5C485";

    char buf9[]   ="$GLGSV,2,1,7,67,71,157,34.1,78,55,315,34.3,68,50,330,36.9,77,28,023,29.9*51485";
    char buf10[] = "$GLGSV,2,2,7,79,27,253,30.8,66,16,153,32.0,87,01,080,22.0*7F,28,023,29.9*51485";

	
    char buf11[] = "$GPGSV,3,1,10,14,57,118,33.0,31,50,005,35.1,32,39,271,32.8,16,37,232,33.0*76";
    char buf12[] = "$GPGSV,3,2,10,29,30,069,32.3,193,18,174,24.0,22,16,181,27.1,25,13,040,*5E*76";
    char buf13[] = "$GPGSV,3,3,10,20,10,307,25.2,27,04,193,17.3*752,16,181,27.1,25,13,040,*5E*76";

    char buf14[] = "$GPGSV,3,1,10,14,57,118,33.0,31,50,005,35.1,32,39,271,32.8,16,37,232,33.0*76";
    char buf15[] = "$GPGSV,3,2,10,29,30,069,32.3,193,18,174,24.0,22,16,181,27.1,25,13,040,*5E*76";
    char buf16[] = "$GPGSV,3,3,10,20,10,307,25.2,27,04,193,17.3*752,16,181,27.1,25,13,040,*5E*76";

    char buf17[] = "$GPGSV,3,1,10,14,57,118,33.0,31,50,005,35.1,32,39,271,32.8,16,37,232,33.0*76";
    char buf18[] = "$GPGSV,3,2,10,29,30,069,32.3,193,18,174,24.0,22,16,181,27.1,25,13,040,*5E*76";
    char buf19[] = "$GPGSV,3,3,10,20,10,307,25.2,27,04,193,17.3*752,16,181,27.1,25,13,040,*5E*76";

    char buf20[] = "$GPGSV,3,1,10,14,57,118,33.0,31,50,005,35.1,32,39,271,32.8,16,37,232,33.0*76";
    char buf21[] = "$GPGSV,3,2,10,29,30,069,32.3,193,18,174,24.0,22,16,181,27.1,25,13,040,*5E*76";
    char buf22[] = "$GPGSV,3,3,10,20,10,307,25.2,27,04,193,17.3*752,16,181,27.1,25,13,040,*5E*76";

    char buf23[] = "$GPGSV,3,1,10,14,57,118,33.0,31,50,005,35.1,32,39,271,32.8,16,37,232,33.0*76";
    char buf24[] = "$GPGSV,3,2,10,29,30,069,32.3,193,18,174,24.0,22,16,181,27.1,25,13,040,*5E*76";
    char buf25[] = "$GPGSV,3,3,10,20,10,307,25.2,27,04,193,17.3*752,16,181,27.1,25,13,040,*5E*76";
	

    GlonassSVid = EdtGlonassSvid->Text.ToInt(); //the value is between 1~ 20 in HEX format.
    m_cGPS_Obj.SetCNRModeSvid(SATELLITE_GLONASS, GlonassSVid);

    GlonassSVid = EdtCNRSvid->Text.ToInt(); //the value is between 1~ 20 in HEX format.
    m_cGPS_Obj.SetCNRModeSvid(SATELLITE_GPS, GPSSVid);


    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf11);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf12);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf13);

    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf1);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf2);
    Sleep(3);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf14);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf15);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf16);

    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf3);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf4);
    Sleep(3);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf17);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf18);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf19);

    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf5);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf6);
    Sleep(3);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf20);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf21);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf22);

    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf7);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf8);
    Sleep(3);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf23);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf24);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(0, buf25);

    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf9);
    m_cGPS_Obj.DeCompose_GPS_GPGSV(2, buf10);
}

void TfrmGPS::InitGLSvidMap()
{
	m_GlMap.insert(std::make_pair(-7,74));
	m_GlMap.insert(std::make_pair(-6,85));
	m_GlMap.insert(std::make_pair(-5,86));
	m_GlMap.insert(std::make_pair(-4,66));
	m_GlMap.insert(std::make_pair(-3,82));
	m_GlMap.insert(std::make_pair(-2,73));
	m_GlMap.insert(std::make_pair(-1,76));
	m_GlMap.insert(std::make_pair(0,75));
	m_GlMap.insert(std::make_pair(1,65));
	m_GlMap.insert(std::make_pair(2,84));
	m_GlMap.insert(std::make_pair(3,83));
	m_GlMap.insert(std::make_pair(4,81));
	m_GlMap.insert(std::make_pair(5,67));
	m_GlMap.insert(std::make_pair(6,68));
	
}

void TfrmGPS::GnssCtl(bool enable)
{
	cbGPS->Enabled          = enable;
	cbBEIDOU->Enabled       = enable;
	cbGLONASS->Enabled      = enable;
	EdtCNRSvid->Enabled     = enable;
	EdtBeidouSvid->Enabled  = enable;
	EdtGlonassSvid->Enabled = enable;
}

bool TfrmGPS::ComposePMTK810CNRStartCommand(void)
{
#ifdef GNSS_CNR_TEST
    TestGNSS();
    return 0;
#endif

    char checksum[3] = {0};
    unsigned int CmdTest = 0;
    unsigned char GPSSVid      = 0;
    unsigned char BedioSVid    = 0;
    int GlonassSVid  = 0;
    int GlonassRFChl = 0;

    GPSSVid = EdtCNRSvid->Text.ToInt(); //the value is between 1~ 20 in HEX format.
    m_cGPS_Obj.SetCNRModeSvid(SATELLITE_GPS, GPSSVid);

    BedioSVid = EdtBeidouSvid->Text.ToInt(); //the value is between 1~ 20 in HEX format.
    m_cGPS_Obj.SetCNRModeSvid(SATELLITE_BEIDOU, BedioSVid);

    GlonassRFChl = EdtGlonassSvid->Text.ToInt(); //the value is between 1~ 20 in HEX format.
    if(GlonassRFChl >= -7 && GlonassRFChl <=6)
    {
	    ITER it = m_GlMap.find(GlonassRFChl);
    	if(it != m_GlMap.end())
	    	GlonassSVid = it->second;
    }
    m_cGPS_Obj.SetCNRModeSvid(SATELLITE_GLONASS, GlonassSVid);

    m_Cmd ="$PMTK810,";
    m_Cmd +=IntToHex((int)CmdTest,4);

    if(!cbGPS->Checked)
    {
        GPSSVid = 0;
    }

    m_Cmd +=",";
    m_Cmd +=IntToHex(GPSSVid,2);

    if(!cbGLONASS->Checked)
    {
        GlonassRFChl = 0;
    }
    else
    {
        GlonassRFChl += 7;
    }
    m_Cmd +=",";
    m_Cmd +=IntToHex(GlonassRFChl,2);

    if(!cbBEIDOU->Checked)
    {
       BedioSVid = 0;
    }
    m_Cmd +=",";
   	m_Cmd +=IntToHex(BedioSVid,2);

    GenerateCkSum(m_Cmd.c_str(),checksum);
    m_Cmd =m_Cmd+"*"+(AnsiString)checksum;
    OutputLog(m_Cmd.c_str());
    m_Cmd = m_Cmd+"\r\n";
    m_Len = m_Cmd.Length();

    LOG("[CNR Test]Semd GPS command = %s", m_Cmd.c_str());
    return true;
}


bool TfrmGPS::ComposePMTK811CNRStopCommand(void)
{
    char checksum[3] = {0};
    m_Cmd ="$PMTK811";
    GenerateCkSum(m_Cmd.c_str(),checksum);
    m_Cmd =m_Cmd+"*"+(AnsiString)checksum;
    m_Cmd = m_Cmd+"\r\n";
    m_Len = m_Cmd.Length();
    return true;
}

void TfrmGPS::CNF_GPS_CNRSendCommand_Start(void)
{
    int state = m_cGPS_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        SetStatusBarString("GPS send CNR test command success");
        SetStatusBarString(" Receive GPS CNR test data processing...");
        bCNRCallbackResult = false;
        CallbackCNRTimer->Enabled = true;
        break;
    case META_FAILED:
        SetStatusBarString("GPS send CNR test command Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString("GPS send CNR test command Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString("GPS send CNR test command Stop");
        break;
    default:
        break;
    }
}


void TfrmGPS::CNF_GPS_CNRSendCommand_Stop(void)
{
    int state = m_cGPS_Obj.Get_ConfirmState();
    switch (state)
    {
    case META_SUCCESS:
        SetStatusBarString("Stop GPS CNR test success");
//            RadioBtnCWTestMode->Enabled = true;
//            RadioBtnSignalTestMode->Enabled = true;
        CallbackCNRTimer->Enabled = false;
        break;
    case META_FAILED:
        SetStatusBarString("Stop GPS CNR test Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString("Stop GPS CNR test Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString("Stop GPS CNR test Stop");
        break;
    default:
        break;
    }
}
//


void __fastcall TfrmGPS::BtnCNRStopClick(TObject *Sender)
{
    ResetValue();
    m_cGPS_Obj.m_sGPS.hPostMsgDestHandle = this->Handle;
    if(!ComposePMTK811CNRStopCommand())
    {
        SetStatusBarString("Compose PMTK811 Command error");
        return;
    }
//     RadioBtnCWTestMode->Enabled = true;
//     RadioBtnSignalTestMode->Enabled = true;
    GnssCtl(true);
    m_cGPS_Obj.m_sGPS.gps_cmd.len = m_Len;
    sprintf(m_cGPS_Obj.m_sGPS.gps_cmd.buff,m_Cmd.c_str());
    m_cGPS_Obj.REQ_Start(GPS_SendCNRStopCommand_PMTK811,::CNF_GPS_CNRSendCommand_Stop);
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::CNRTestClick(TObject *Sender)
{
    ResetCNRValue();
    m_cGPS_Obj.m_sGPS.hPostMsgDestHandle = this->Handle;
    GPS_ACK_BUF buf;
    char a[]= "$GPGGA,184030.000,2446.4754,N,12100.0371,E,1,9,0.86,135.5,M,15.0,M,,*52\r\n$GPGSA,A,3,23,27,13,11,16,03,19,15,08,,,,1.70,0.86,1.46*0F\r\n$GPGSV,3,1,9,19,71,347,42,03,49,027,42,11,35,187,42,13,31,256,42*4E,*52\r\n$GPGSV,3,2,9,27,31,319,42,23,27,219,42,16,24,077,42,15,17,048,42*4C,*52\r\n$GPGSV,3,3,9,08,06,321,42*78..$GPRMC,184030.000,A,2446.4754,N,12100.0371,E,0.000,0.00,010505,,A*7C\r\n$GPVTG,0.00,T,,M,0.000,N,0.000,K,A*3D..$GPACCURACY,2.9*03\r\n";
    int i = sizeof(a);
    sprintf(buf.buff,a,i);
//	unsigned short token = 10;
    buf.len =  i;
    int usedata = 1;
    unsigned char SVid = 29;
    SVid = EdtCNRSvid->Text.ToInt(); //the value is between 1~ 20 in HEX format.
    m_cGPS_Obj.SetCNRModeSvid(SATELLITE_GPS, SVid);
    m_cGPS_Obj.CNF_GPSSendCNRStartCommand_PMTK810(&buf, 10, &usedata);
//
}
//---------------------------------------------------------------------------

void __fastcall TfrmGPS::EdtCNRSvidExit(TObject *Sender)
{
    unsigned int n_data = 0;
    AnsiString  text;
    TEdit *edit = (TEdit*)Sender;
    char  hint[] = {" value should be 1~32 "};

    text = EdtCNRSvid->Text;
    if( !IsValidGPSSvid( text, n_data ) )
    {
        edit->Text = 29;
        ShowHintLabel( edit, hint );
        EdtCNRSvid->SetFocus();
        return;
    }
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------





void __fastcall TfrmGPS::CallbackCNRTimerTimer(TObject *Sender)
{
    if(false == bCNRCallbackResult)
    {
        BtnCNRStopClick(Sender);
        Application->MessageBox( "Meta GPS CNR Test timeout", "Timeout", MB_OK );

    }
}
//---------------------------------------------------------------------------

