//---------------------------------------------------------------------------

#ifndef form_WmWifimt6620H
#define form_WmWifimt6620H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>


#include "man_handle.h"
#include <Dialogs.hpp>
#include <ActnList.hpp>

#ifndef  _WIFI_MAN_H_
#include "wifi_man.h"
#endif


#define NONE_STOP			0
#define TX_STOP				1
#define RX_STOP				2
#define TEMPERATURE_STOP	        3
//---------------------------------------------------------------------------
class TfrmWmWifiMT6620 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel4;
    TButton *btnEESaveAsFile;
    TButton *btnEEBurnFromFile;
    TButton *btnEEReadAll;
    TGroupBox *GroupBox3;
    TLabel *Label10;
    TEdit *edtEFuseWordAddr;
    TLabel *Label11;
    TEdit *edtEFuseWordValue;
    TButton *btnEFuseRead;
    TButton *btnEFuseWrite;
    TPanel *Panel5;
    TGroupBox *GroupBox4;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label18;
    TLabel *Label19;
    TEdit *edtTXGain;
    TComboBox *cbRate;
    TComboBox *cbTXTestType;
    TButton *btnTXStop;
    TButton *btnTXGo;
    TEdit *edtTXPktLen;
    TEdit *edtTXPktCnt;
    TPanel *Panel3;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *edtMCRAddr;
    TEdit *edtMCRValue;
    TButton *btnMCRRead;
    TButton *btnMCRWrite;
    TLabel *Label4;
    TGroupBox *GroupBox1;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *edtEEWordAddr;
    TEdit *edtEEWordValue;
    TButton *btnEEWordRead;
    TButton *btnEEWordWrite;
    TGroupBox *GroupBox2;
    TLabel *Label9;
    TLabel *Label7;
    TLabel *Label8;
    TEdit *edtEEByteStringLength;
    TEdit *edtEEByteStringAddr;
    TButton *btnEEByteStringRead;
    TButton *btnEEByteStringWrite;
    TEdit *edtEEByteStringValue;
    TGroupBox *GroupBox5;
    TLabel *Label20;
    TLabel *Label21;
    TLabel *Label22;
    TLabel *Label12;
    TLabel *Label16;
    TButton *btnRXGo;
    TButton *btnRXStop;
    TStaticText *stRXFCSerr;
    TStaticText *stRXOK;
    TStaticText *stRXPER;
    TEdit *edtInterval;
    TGroupBox *GroupBox7;
    TRadioButton *rbGuardinterval400;
    TRadioButton *rbGuardinterval800;
    TButton *btnGuardintervalSet;
    TGroupBox *GroupBox8;
    TRadioButton *rbModeSelectGreenFiled;
    TRadioButton *rbModeSelectMixedMode;
    TButton *rbModeSelectSet;
    TLabel *Label26;
    TButton *btnClearLog;
    TRichEdit *redtLog;
    TPanel *Panel6;
    TTimer *timerTemperature;
    TTimer *timerRX;
    TTimer *timerTX;
    TSaveDialog *saveDlgEE;
    TOpenDialog *openDlgEE;
    TTimer *timerCalibrator;
    TOpenDialog *OpenDlgDPD;
    TSaveDialog *SaveDlgDPD;
    TButton *m_btnSet_2GHz_TX_Power_Profile;
    TButton *m_btnSet_5GHz_TX_Power_Profile;
    TButton *m_btnCrystalTrim;
        TLabel *Label27;
        TStaticText *stRXRSSI0;
    TRadioButton *rbModeSelect11AC;
    TCheckBox *cbJapanChannel;
    TButton *btnRSSICOMP;
    TLabel *LabelRSSI1;
        TStaticText *stRXRSSI01;
        TButton *btnOpenValue;
        TButton *btnDwn;
        TButton *btnSave;
        TOpenDialog *OpenDlgOffset;
        TOpenDialog *OpenDlgValue;
        TSaveDialog *saveDlgIni;
        TButton *btnScript;
        TOpenDialog *OpenDlgScript;
        TActionList *ActionList1;
        TAction *WIFIPER;
        TAction *hideFlag;
        TLabel *LabelNss;
        TComboBox *cbxNss;
        TCheckBox *cbTXRX0;
        TCheckBox *cbTXRX1;
        TGroupBox *GroupBox6;
        TRadioButton *rbBandwidth20;
        TRadioButton *rbBandwidth40;
        TRadioButton *rbBandwidthU20;
        TRadioButton *rbBandwidthL20;
        TButton *btnBandwidthSet;
        TGroupBox *GroupBox9;
        TLabel *Label32;
        TLabel *Label29;
        TLabel *Label30;
        TLabel *Label31;
        TCheckBox *cbJMode;
        TComboBox *cbxCBW;
        TComboBox *cbxDBW;
        TComboBox *cbxPrimaryCh;
        TRadioButton *rbAdvanceSetting;
        TGroupBox *GroupBox10;
        TLabel *Label15;
        TComboBox *cbChannel;
        TLabel *LabelTX1Channel;
        TComboBox *cbChannelTX1;
        TLabel *labelUserDefine;
        TLabel *labelUserDefineTX1;
        TEdit *edtChannel;
        TUpDown *udChannel;
        TEdit *edtChannelTX1;
        TUpDown *udChannelTX1;
        TGroupBox *GroupBox18;
        TButton *btnReadoutThermalSensor;
        TButton *btnReadoutVoltageSensor;
        TButton *btnReadoutTSSI;
        TGroupBox *GroupBox19;
        TButton *btnDPDCalibrate;
        TButton *btnImportDPDParametersfromFile;
        TButton *btnReadDPDParameters;
        TButton *btnSaveDPDParameterstoFile;
        TGroupBox *GroupBox20;
        TButton *btnTXRXIQCalibrate;
        TButton *btnReadIQCalParameter;
        TGroupBox *GroupBox21;
        TButton *btnTemperatureGo;
        TButton *btnTemperatureStop;
        TRadioButton *rbMIMO;
        TRadioButton *rbDBDC;
        TLabel *Label17;
        TPanel *Panel7;
        TLabel *Label23;
        TLabel *Label24;
        TGroupBox *GroupBox11;
        TLabel *Label25;
        TLabel *Label28;
        TLabel *Label33;
        TLabel *Label34;
        TEdit *edtTXGain1;
        TComboBox *cbRate1;
        TComboBox *cbTXTestType1;
        TButton *btnTX1Stop;
        TButton *btnTX1Go;
        TEdit *edtTXPktLen1;
        TEdit *edtTXPktCnt1;
        TGroupBox *GroupBox12;
        TRadioButton *rbGuard1interval400;
        TRadioButton *rbGuard1interval800;
        TButton *btnGuard1intervalSet;
        TGroupBox *GroupBox13;
        TRadioButton *rbModeSelectGreenFiled1;
        TRadioButton *rbModeSelectMixedMode1;
        TButton *rbModeSelect1Set;
        TRadioButton *rbModeSelect11AC1;
        TCheckBox *cbJapanChannel1;
        TGroupBox *GroupBox14;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TLabel *Label39;
        TLabel *Label40;
        TLabel *Label41;
        TButton *btnRX1Go;
        TButton *btnRXStop1;
        TStaticText *stRXFCSerr1;
        TStaticText *stRXOK1;
        TStaticText *stRXPER1;
        TEdit *edtInterval1;
        TStaticText *stRXRSSI1;
        TStaticText *stRXRSSI11;
        TComboBox *cbxNss1;
        TCheckBox *cbTXRX10;
        TCheckBox *cbTXRX11;
        TGroupBox *GroupBox15;
        TButton *btnBandwidth1Set;
        TGroupBox *GroupBox16;
        TLabel *Label42;
        TLabel *Label43;
        TLabel *Label44;
        TLabel *Label45;
        TCheckBox *cbJMode1;
        TComboBox *cbxCBW1;
        TComboBox *cbxDBW1;
        TComboBox *cbxPrimaryCh1;
        TGroupBox *GroupBox17;
        TLabel *Label46;
        TLabel *labelUserDefine1;
        TComboBox *cbChannel1;
        TEdit *edtChannel1;
        TUpDown *udChannel1;
        TLabel *lbAntSwap;
        TComboBox *cbAntSwap;
        TTimer *timerRX1;
        TTimer *timerTX1;

    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnMCRReadClick(TObject *Sender);
    void __fastcall btnMCRWriteClick(TObject *Sender);
    void __fastcall btnEEWordReadClick(TObject *Sender);
    void __fastcall btnEEWordWriteClick(TObject *Sender);
    void __fastcall btnEEByteStringReadClick(TObject *Sender);
    void __fastcall btnEEByteStringWriteClick(TObject *Sender);
    void __fastcall btnEESaveAsFileClick(TObject *Sender);
    void __fastcall cbChannelChange(TObject *Sender);
    void __fastcall btnEEBurnFromFileClick(TObject *Sender);
    void __fastcall btnEEReadAllClick(TObject *Sender);
    void __fastcall btnTXGoClick(TObject *Sender);
    void __fastcall btnTXStopClick(TObject *Sender);
    void __fastcall cbRateChange(TObject *Sender);
    void __fastcall btnRXGoClick(TObject *Sender);
    void __fastcall btnRXStopClick(TObject *Sender);
    void __fastcall btnEFuseReadClick(TObject *Sender);
    void __fastcall btnEFuseWriteClick(TObject *Sender);
    void __fastcall btnBandwidthSetClick(TObject *Sender);
    void __fastcall btnGuardintervalSetClick(TObject *Sender);
    void __fastcall rbModeSelectSetClick(TObject *Sender);
    void __fastcall btnTemperatureGoClick(TObject *Sender);
    void __fastcall timerTemperatureTimer(TObject *Sender);
    void __fastcall btnTXRXIQCalibrateClick(TObject *Sender);
    void __fastcall btnReadIQCalParameterClick(TObject *Sender);
    void __fastcall btnTemperatureStopClick(TObject *Sender);
    void __fastcall btnReadoutThermalSensorClick(TObject *Sender);
    void __fastcall btnReadoutVoltageSensorClick(TObject *Sender);
    void __fastcall timerCalibratorTimer(TObject *Sender);
    void __fastcall btnDPDCalibrateClick(TObject *Sender);
    void __fastcall btnReadDPDParametersClick(TObject *Sender);
    void __fastcall btnImportDPDParametersfromFileClick(
        TObject *Sender);
    void __fastcall btnReadoutTSSIClick(TObject *Sender);
    void __fastcall btnClearLogClick(TObject *Sender);
    void __fastcall timerTXTimer(TObject *Sender);
    void __fastcall timerRXTimer(TObject *Sender);
    void __fastcall btnSaveDPDParameterstoFileClick(TObject *Sender);
    void __fastcall m_btnSet_2GHz_TX_Power_ProfileClick(TObject *Sender);
    void __fastcall m_btnSet_5GHz_TX_Power_ProfileClick(TObject *Sender);
    void __fastcall hideFlagExecute(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall m_btnCrystalTrimClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormHide(TObject *Sender);
    void __fastcall rbAdvanceSettingClick(TObject *Sender);
    void __fastcall cbJModeClick(TObject *Sender);
    void __fastcall cbxCBWChange(TObject *Sender);
    void __fastcall cbxDBWChange(TObject *Sender);
    void __fastcall rbBandwidthL20Click(TObject *Sender);
    void __fastcall rbBandwidthU20Click(TObject *Sender);
    void __fastcall rbBandwidth40Click(TObject *Sender);
    void __fastcall rbBandwidth20Click(TObject *Sender);
    void __fastcall cbChannelDropDown(TObject *Sender);
    void __fastcall udChannelChanging(TObject *Sender, bool &AllowChange);
    void __fastcall btnRSSICOMPClick(TObject *Sender);
    void __fastcall cbxNssChange(TObject *Sender);
    void __fastcall cbTXRX0Click(TObject *Sender);
    void __fastcall cbTXRX1Click(TObject *Sender);
    void __fastcall cbChannelTX1Change(TObject *Sender);
    void __fastcall cbChannelTX1DropDown(TObject *Sender);
    void __fastcall udChannelTX1Changing(TObject *Sender,
          bool &AllowChange);
        void __fastcall btnOpenOffsetClick(TObject *Sender);
        void __fastcall btnOpenValueClick(TObject *Sender);
        void __fastcall btnDwnClick(TObject *Sender);
        void __fastcall btnSaveClick(TObject *Sender);
        void __fastcall btnScriptClick(TObject *Sender);
        void __fastcall rbMIMOClick(TObject *Sender);
        void __fastcall rbDBDCClick(TObject *Sender);
        void __fastcall cbAntSwapChange(TObject *Sender);
        void __fastcall cbxNss1Change(TObject *Sender);
        void __fastcall cbTXRX10Click(TObject *Sender);
        void __fastcall cbTXRX11Click(TObject *Sender);
        void __fastcall btnRX1GoClick(TObject *Sender);
        void __fastcall timerRX1Timer(TObject *Sender);
        void __fastcall btnRXStop1Click(TObject *Sender);
        void __fastcall btnGuard1intervalSetClick(TObject *Sender);
        void __fastcall rbModeSelect1SetClick(TObject *Sender);
        void __fastcall cbRate1Change(TObject *Sender);
        void __fastcall btnTX1GoClick(TObject *Sender);
        void __fastcall cbJMode1Click(TObject *Sender);
        void __fastcall btnBandwidth1SetClick(TObject *Sender);
        void __fastcall cbChannel1Change(TObject *Sender);
        void __fastcall udChannel1Changing(TObject *Sender,
          bool &AllowChange);
        void __fastcall cbxCBW1Change(TObject *Sender);
        void __fastcall cbxDBW1Change(TObject *Sender);
        void __fastcall btnTX1StopClick(TObject *Sender);
        void __fastcall timerTX1Timer(TObject *Sender);
        void __fastcall cbChannel1DropDown(TObject *Sender);

private:
// User declarations
    bool m_bInited;
    bool m_bIsNvramFlag;
    CRITICAL_SECTION  m_cs;
    bool m_bTXTestFlag;
    bool m_bTSTestFlag;
    bool m_bRXTestFlag;
    bool m_bSwitchAntennaOK;
    CWiFiMan m_WiFi_Man_Obj;
    CMETAHANDLE m_META_HANDLE_Obj;
    int m_calibrationType;
    int m_calibrationLength;
    unsigned int m_u4ThermoRunNum;
    unsigned long m_wifiChipVersion;
    void OutputMetaResult(char *strOperator, META_RESULT result);
    void CurrentPageReset(void);
    void CurrentPageLock(unsigned int exceptCtl= NONE_STOP);
    void OutputLog(char *strInfo);
    void DoChannelChange(void);
    void DoChannel1Change(void);
    void DoChannelTX1Change(void);
    bool uiUpdateTxPower(void);
    void setTXRXPath(void);
    void setTXRX1Path(void);

    void goTX0(void);
    void goTX1(void);
    void goTX2(void);
    void goTX3(void);
    void goTX4(void);
    void goTX5(void);
    void stopTX0(void);
    void stopTX1(void);
    void stopTX2(void);
    void stopTX3(void);
    void stopTX4(void);
    void stopTX5(void);

    void goBand1TX0(void);
    void goBand1TX1(void);
    void goBand1TX2(void);
    void goBand1TX3(void);
    void goBand1TX4(void);
    void goBand1TX5(void);
    void stopBand1TX0(void);
    void stopBand1TX1(void);
    void stopBand1TX2(void);
    void stopBand1TX3(void);
    void stopBand1TX4(void);
    void stopBand1TX5(void);   

    bool TXParameterCheck(unsigned int &u4TxPktCnt, int &i4TxPktLen, double &u4TxGain,
                          int &u4TxPower, unsigned int &nLongPreamble);
    bool TXParameter1Check(unsigned int &u4TxPktCnt, int &i4TxPktLen, double &u4TxGain,
                          int &u4TxPower, unsigned int &nLongPreamble);
    void GetBandwidthPara(unsigned int &nJMode, unsigned int &nChBandwidth, unsigned int &nDataBandwidth,
                          unsigned int &nPrimarySetting);
    void GetBandwidth1Para(unsigned int &nJMode, unsigned int &nChBandwidth, unsigned int &nDataBandwidth,
                          unsigned int &nPrimarySetting);
    void OpenWiFi(void);
    void CloseWiFi(void);

public:

// User declarations
    __fastcall TfrmWmWifiMT6620(TComponent* Owner);
    unsigned long GetTargetVersion(void);

    void Init( void );
    void ApplyHideProperty();
    unsigned long GetWifiChipVersion(void);
    void CNF_WIFI_READALL_EEPROM(void);
    void CNF_WIFI_READ_EEPROM(void);
    void EESaveAsFile(AnsiString asSaveFileName);
    void DBDCSelect(int index);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWmWifiMT6620 *frmWmWifiMT6620;
//---------------------------------------------------------------------------
#endif
