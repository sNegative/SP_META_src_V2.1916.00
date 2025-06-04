//---------------------------------------------------------------------------

#ifndef form_GPSH
#define form_GPSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ActnList.hpp>
#include <map>

#ifndef  _GPS_H_
#include "GPS.h"
#endif

#ifndef CONTROLLOCKER_H_
#include "ControlLocker.h"
#endif

#include <stdio.h>
#include <vector>

#define GPS_CW_TEST_FILE_PATH_LEN   2048

typedef std::map<int, int> GLMAP;
#define ITER GLMAP::iterator

//#define GNSS_CNR_TEST
//---------------------------------------------------------------------------
class TfrmGPS : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TButton *BtnOpenGPS;
    TButton *BtnStart;
    TButton *BtnCloseGPS;
    TGroupBox *GBQuery;
    TLabel *Label9;
    TLabel *Label8;
    TLabel *Label7;
    TLabel *Label6;
    TLabel *Label5;
    TLabel *Label4;
    TLabel *Label2;
    TLabel *Label1;
    TEdit *EDUpdateValue;
    TEdit *EDTCXOOffsetValue;
    TEdit *EDTCXODriftValue;
    TEdit *EDPhaseRatioValue;
    TEdit *EDCNRSigmaValue;
    TEdit *EDCNRMeanValue;
    TEdit *EDBitSyncValue;
    TEdit *EDAcquisionValue;
    TButton *BtnClearLog;
    TRichEdit *GPSLog;
    TStaticText *stInfo;
    TCheckBox *cbBit0;
    TCheckBox *cbBit1;
    TCheckBox *cbBit2;
    TCheckBox *cbBit3;
    TTimer *DisplayTimer;
    TEdit *EdtSvid;
    TLabel *Label3;
    TButton *Btntest;
    TStaticText *lblHint;
    TTimer *HintTimer;
    TButton *BtnClearValue;
    TShape *shpGPSOpen;
    TButton *BtnLoadSPEC;
    TStaticText *stGPSSPECFile;
    TOpenDialog *dlg_OpenIniFile;
    TTimer *CallbackTimer;
    TButton *BtnStop;
    TPanel *pnlPhaseRatioResult;
    TPanel *pnlTCXOOffsetResult;
    TPanel *pnlTCXODriftResult;
    TPanel *pnlCNRMeanResult;
    TPanel *pnlCNRSigmaResult;
    TPanel *pnlUpdateResult;
    TPanel *pnlBitSyncResult;
    TPanel *pnlAcquisionResult;
    TRadioButton *RadioBtnSignalTestMode;
    TGroupBox *GBCWTest;
    TRadioButton *RadioBtnCWTestMode;
    TButton *BtnCWStart;
    TButton *BtnCWStop;
    TButton *BtnCWAutoTest;
    TLabel *LabelCWCNR;
    TEdit *EDCWCNR;
    TPanel *pnlCWCNRResult;
    TLabel *LabelCWClockDrift;
    TEdit *EDCWClockDrift;
    TPanel *pnlCWClockDriftResult;
    TTimer *CallbackCWTimer;
    TActionList *ActionList1;
    TAction *CWHideFlag;
    TGroupBox *GBCNRTest;
    TRadioButton *RadioBtnCNRTestMode;
    TButton *BtnCNRStart;
    TEdit *EDCNRModeValue;
    TLabel *LabelCNRTest;
    TPanel *pnlCNRTestResult;
    TButton *BtnCNRStop;
    TLabel *LabelCNRSvid;
    TEdit *EdtCNRSvid;
    TButton *CNRTest;
    TTimer *CallbackCNRTimer;
    TComboBox *cbxNavigation;
    TEdit *EDBeidouModeValue;
    TLabel *LabelBeidouCNR;
    TEdit *EdtBeidouSvid;
    TLabel *LabelBeidouSvid;
    TLabel *LabelGlonassSvid;
    TEdit *EdtGlonassSvid;
    TLabel *LabelGlonassCNR;
    TEdit *EDGlonassModeValue;
    TCheckBox *cbGPS;
    TCheckBox *cbBEIDOU;
    TCheckBox *cbGLONASS;
    TLabel *LableInterval;
    TEdit *EDInterval;
    void __fastcall BtnClearLogClick(TObject *Sender);
    void __fastcall BtnOpenGPSClick(TObject *Sender);
    void __fastcall BtnCloseGPSClick(TObject *Sender);
    void __fastcall BtnStartClick(TObject *Sender);
    void __fastcall BtntestClick(TObject *Sender);
    void __fastcall EdtSvidExit(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall BtnClearValueClick(TObject *Sender);
    void __fastcall BtnLoadSPECClick(TObject *Sender);
    void __fastcall CheckAcqEnable(TObject *Sender);
    void __fastcall CheckBitsyncEnable(TObject *Sender);
    void __fastcall CheckBitsyncAndSignalDisanble(TObject *Sender);
    void __fastcall CallbackTimerTimer(TObject *Sender);
    void __fastcall CheckInfoEnable(TObject *Sender);
    void __fastcall BtnStopClick(TObject *Sender);
    void __fastcall RadioBtnSignalTestModeClick(TObject *Sender);
    void __fastcall RadioBtnCWTestModeClick(TObject *Sender);
    void __fastcall BtnCWStartClick(TObject *Sender);
    void __fastcall CallbackCWTimerTimer(TObject *Sender);
    void __fastcall BtnCWStopClick(TObject *Sender);
    void __fastcall BtnCWAutoTestClick(TObject *Sender);
    void __fastcall CWHideFlagExecute(TObject *Sender);
    void __fastcall RadioBtnCNRTestModeClick(TObject *Sender);
    void __fastcall BtnCNRStartClick(TObject *Sender);
    void __fastcall BtnCNRStopClick(TObject *Sender);
    void __fastcall CNRTestClick(TObject *Sender);
    void __fastcall EdtCNRSvidExit(TObject *Sender);
    void __fastcall CallbackCNRTimerTimer(TObject *Sender);


private:	// User declarations
    bool m_bInit;
    AnsiString m_Cmd;
    AnsiString m_Result;
    unsigned short m_Len;
    bool b_OpenIniFile;
    bool m_bVersionFlag;
    GLMAP m_GlMap;
public:		// User declarations
    __fastcall TfrmGPS(TComponent* Owner);
//qinqin 20120305
    __fastcall ~TfrmGPS();
//
    void _fastcall  SubClassWndProc( Messages::TMessage &Message);
    CGPS    m_cGPS_Obj;
    AnsiString m_GPSVersion;
    void InitGLSvidMap();
    void GnssCtl(bool enable);
    void Init( void );
    void SetStatusBarString(char *strInfo);
    void CNF_GPS_OPEN(void);
    void CNF_GPS_CLOSE(void);
    void CNF_GPS_SendCommand_Start(void);
    bool ComposePMTK810Command(void);
    void GenerateCkSum(char *buf, char *result);
    void OutputLog(AnsiString buf);
    void ShowHintLabel( TControl *sender, char* hint );
    void ResetValue(void) ;
    bool bGPSOpen;
    void __fastcall miOpenGPSInitialFileClick(TObject *Sender);
    void DisableTestItem(void);
    void CustomizeEdtFont(bool bflag,TObject *Sender);
    void CustomizePanelFont(bool bflag,TObject *Sender);
    void SetTestItem( void );
//
    bool TestGNSS();
    bool ComposePMTK811Command(void);
    void CNF_GPS_SendCommand_Stop(void);
//
    std::vector<float> m_vec_CNR;
    std::vector<float> m_vec_ClockDrift;
    float m_CNRAverage;
    float m_ClockDriftAverage;
    FILE *m_fpAutoTestLog;
    int  m_nCWAutoTestNum;
    int  m_nCWMaxAutoTestNum;
    ControlLocker m_GPSSignalTestCtlLocker;
    ControlLocker m_GPSCWTestCtlLocker;
    ControlLocker m_GPSCNRTestCtlLocker;

#ifdef GNSS_CNR_TEST
    int GPS_Interval;
    float GPS_CNR_Value ;
    int BEIDOU_Interval;
    float BEIDOU_CNR_Value;
    int GLONASS_Interval ;
    float GLONASS_CNR_Value;
#endif

    char m_strAutoTestFilePath[GPS_CW_TEST_FILE_PATH_LEN];
    bool ComposePMTK817StartCommand(void);
    bool ComposePMTK817StopCommand(void);
    void CNF_GPS_CWSendCommand_Start(void);
    void CNF_GPS_CWSendCommand_Stop(void);
    void ApplyCWHideProperty(void);
    void ResetCWValue(void);
    void GetCWAutoTestParam(int& nAutoTestNum, char* strAutoTestFilePath );
    void CWAutoTestControl(void);

    void CalcCWAverage(void);

    bool ComposePMTK810CNRStartCommand(void);
    bool ComposePMTK811CNRStopCommand(void);
    void CNF_GPS_CNRSendCommand_Start(void);
    void CNF_GPS_CNRSendCommand_Stop(void);
    void ResetCNRValue(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGPS *frmGPS;
//---------------------------------------------------------------------------
#endif
