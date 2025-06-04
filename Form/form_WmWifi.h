//---------------------------------------------------------------------------

#ifndef form_WmWifiH
#define form_WmWifiH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>

#include "man_handle.h"
#include <Dialogs.hpp>

#ifndef  _WIFI_MAN_H_
#include "wifi_man.h"
#endif


#define NONE_STOP			0
#define TX_STOP				1
#define RX_STOP				2
#define TEMPERATURE_STOP	3


//---------------------------------------------------------------------------
class TfrmWmWifi : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel14;
    TPanel *Panel1;
    TPanel *Panel2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *edtMCRAddr;
    TEdit *edtMCRValue;
    TButton *btnMCRRead;
    TButton *btnMCRWrite;
    TPanel *Panel4;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *edtEEWordAddr;
    TEdit *edtEEWordValue;
    TButton *btnEEWordRead;
    TButton *btnEEWordWrite;
    TLabel *Label9;
    TEdit *edtEEByteStringAddr;
    TLabel *Label10;
    TEdit *edtEEByteStringLength;
    TButton *btnEEByteStringRead;
    TButton *btnEEByteStringWrite;
    TLabel *Label11;
    TEdit *edtEEByteStringValue;
    TButton *btnEESaveAsFile;
    TButton *btnEEBurnFromFile;
    TButton *btnEEReadAll;
    TPanel *Panel5;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TEdit *edtTXAntenna;
    TEdit *edtTXGain;
    TLabel *Label15;
    TComboBox *cbChannel;
    TCheckBox *cbACL;
    TGroupBox *GroupBox1;
    TComboBox *cbRate;
    TComboBox *cbTXTestType;
    TButton *btnTXStop;
    TButton *btnTXGo;
    TCheckBox *cbJapanChannel;
    TComboBox *cbModuationType;
    TLabel *Label16;
    TLabel *Label17;
    TEdit *edtTXPktLen;
    TEdit *edtTXPktCnt;
    TLabel *Label18;
    TLabel *Label19;
    TGroupBox *GroupBox2;
    TLabel *Label20;
    TLabel *Label21;
    TButton *btnRXGo;
    TButton *btnRXStop;
    TLabel *Label22;
    TPanel *Panel6;
    TButton *btnTemperatureStop;
    TButton *btnTemperatureGo;
    TLabel *Label23;
    TPanel *Panel7;
    TLabel *Label24;
    TButton *btnXtalTrim;
    TLabel *Label25;
    TEdit *edtXtalTrimValue;
    TLabel *Label26;
    TButton *btnClearLog;
    TRichEdit *redtLog;
    TGroupBox *GroupBox3;
    TGroupBox *GroupBox4;
    TStaticText *stRXFCSerr;
    TStaticText *stRXOK;
    TStaticText *stRXPER;
    TSaveDialog *saveDlgEE;
    TOpenDialog *openDlgEE;
    TTimer *timerTX;
    TTimer *timerRX;
    TTimer *timerTemperature;
    TButton *btnEEToFlash;
    TEdit *edtInterval;
    TLabel *Label7;
    TLabel *Label8;
    TStaticText *stMin;
    TStaticText *stMax;
    TStaticText *stMean;
    TStaticText *stVar;
    TLabel *Label27;
    TLabel *Label28;
    TLabel *Label29;
    TLabel *Label30;
    TButton *Button1;
    void __fastcall btnMCRReadClick(TObject *Sender);
    void __fastcall btnMCRWriteClick(TObject *Sender);
    void __fastcall btnClearLogClick(TObject *Sender);
    void __fastcall btnEEWordReadClick(TObject *Sender);
    void __fastcall btnEEWordWriteClick(TObject *Sender);
    void __fastcall btnEEByteStringReadClick(TObject *Sender);
    void __fastcall btnEEByteStringWriteClick(TObject *Sender);
    void __fastcall btnEESaveAsFileClick(TObject *Sender);
    void __fastcall btnEEReadAllClick(TObject *Sender);
    void __fastcall btnEEBurnFromFileClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnTXGoClick(TObject *Sender);
    void __fastcall TimerTimerTX(TObject *Sender);
    void __fastcall btnTXStopClick(TObject *Sender);
    void __fastcall cbxChannelChange(TObject *Sender);
    void __fastcall btnRXGoClick(TObject *Sender);
    void __fastcall TimerTimerRX(TObject *Sender);
    void __fastcall btnRXStopClick(TObject *Sender);
    void __fastcall btnXtalTrimClick(TObject *Sender);
    void __fastcall btnTemperatureGoClick(TObject *Sender);
    void __fastcall TimerTimerTemperature(TObject *Sender);
    void __fastcall btnTemperatureStopClick(TObject *Sender);
    void __fastcall cbRateChange(TObject *Sender);
    void __fastcall btnEEToFlashClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormHide(TObject *Sender);
private:	// User declarations
    bool m_bInited;
    long m_i4InitRxOKCnt;
    long m_i4InitRxFcsErrCnt;
    bool m_bTXTestFlag;
    bool m_bRXTestFlag;
    bool m_bTSTestFlag;
    bool m_bSwitchAntennaOK;

    CWiFiMan m_WiFi_Man_Obj;

    unsigned int m_u4ThermoRunNum;

    unsigned long m_u4InitEdPass;
    unsigned long m_u4InitOfdmOsdPass;
    unsigned long m_u4InitCckSq;
    unsigned long m_u4InitCckSfdPass;
    unsigned long m_u4InitOfdmSig;
    unsigned long m_u4InitCckSig;

    bool m_fgOriThermoEn;
    bool m_bIsNvramFlag;
    CMETAHANDLE m_META_HANDLE_Obj;


    void OutputLog(char *strInfo);
    void OutputMetaResult(char *strOperator, META_RESULT result);
    bool uiUpdateTxPower(void);
    void goTX0(void);
    void goTX1(void);
    void goTX2(void);
    void goTX3(void);
    void goTX4(void);
    void stopTX0(void);
    void stopTX1(void);
    void stopTX2(void);
    void stopTX3(void);
    void stopTX4(void);
    void RXQuery();

    void CurrentPageLock(unsigned int exceptCtl = NONE_STOP);
    void CurrentPageReset(void);

    void DoChannelChange(void);
    void CloseWiFi();

public:		// User declarations
    __fastcall TfrmWmWifi(TComponent* Owner);
    void Init( void );
    void CNF_WIFI_READALL_EEPROM(void);
    void CNF_WIFI_READ_EEPROM(void);
    void EESaveAsFile(AnsiString asSaveFileName);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWmWifi *frmWmWifi;
//---------------------------------------------------------------------------
#endif
