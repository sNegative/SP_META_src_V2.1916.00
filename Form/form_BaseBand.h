#ifndef _FORM_BASEBAND_H_
#define _FORM_BASEBAND_H_
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>

#include "bb_reg.h"
#include "bb_pmic_reg.h"
#include "bb_cust_hw.h"
#include "bb_x.h"
#include "man_handle.h"

#include "meta_lab_msg.h"

typedef enum
{
    BB_PAGEIDX_ADC = 0,
    BB_PAGEIDX_BB_REG,
    BB_PAGEIDX_PMIC_REG,
    BB_PAGEIDX_BATTERY,
    BB_PAGEIDX_LED,
    BB_PAGEIDX_VBR,
    BB_PAGEIDX_RTC,
    BB_PAGEIDX_SIGNAL_INDICATOR
} E_BB_PAGEIDX_T;

//---------------------------------------------------------------------------
class TfrmBaseBand : public TForm
{
__published:	// IDE-managed Components
    TButton *btnBBRegRead;
    TButton *btnBBRegValue;
    TButton *btnBBRegWrite;
    TEdit *edtBBAddress;
    TEdit *edtBBValue;
    TLabel *lblLabel10;
    TLabel *lblBBRegAddr0X;
    TLabel *lblBBRegValue0X;
    TPageControl *pctlToolSel;
    TStaticText *lblHint;
    TTabSheet *tsADC;
    TTabSheet *tsBBReg;
    TTimer *HintTimer;
    TStatusBar *sbAdc;
    TStatusBar *sbReg;
    TTabSheet *tsBL;
    TStatusBar *sbBG;
    TLabel *Label2;
    TGroupBox *GroupBox1;
    TLabel *Label3;
    TEdit *edtBGShutdown;
    TLabel *Label4;
    TEdit *edtBGNoMoCall;
    TEdit *edtBGLowBatteryWarning;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *edtBGLevel1;
    TLabel *Label7;
    TEdit *edtBGLevel2;
    TLabel *Label8;
    TEdit *edtBGLevel3;
    TButton *btnBGUploadFromFlash;
    TButton *btnBGDownloadToFlash;
    TButton *btnBGChangeDB;
    TButton *btnBGLoadFromFile;
    TButton *btnBGSaveToFile;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TTabSheet *tsPMICReg;
    TLabel *lblPMICRegAddr;
    TEdit *edtPMICAddress;
    TLabel *lblPMICRegAddr0X;
    TButton *btnPMICRegValue;
    TEdit *edtPMICValue;
    TLabel *lblPMICRegValue0X;
    TButton *btnPMICRegRead;
    TButton *btnPMICRegWrite;
    TStatusBar *m_sbPMIC;
    TButton *btnPMICReg;
    TTabSheet *tsLED;
    TLabel *Label17;
    TButton *btnKeypadLEDOn;
    TTabSheet *tsVBR;
    TButton *btnVBROn;
    TButton *btnVBROff;
    TTabSheet *tsRTC;
    TLabel *Label18;
    TEdit *edtRTCYear;
    TLabel *Label19;
    TEdit *edtRTCWDay;
    TEdit *edtRTCMonth;
    TLabel *Label20;
    TLabel *Label21;
    TEdit *edtRTCDay;
    TLabel *Label22;
    TEdit *edtRTCWHour;
    TEdit *edtRTCMinute;
    TEdit *edtRTCSec;
    TLabel *Label23;
    TLabel *Label24;
    TButton *btnRTCQuery;
    TStatusBar *m_sbLED;
    TStatusBar *m_sbVBR;
    TStatusBar *m_sbRTC;
    TEdit *edtLCDLED;
    TLabel *Label25;
    TButton *btnLCDLEDSet;
    TTabSheet *tsSignalIndicator;
    TButton *btnRedLightOn;
    TButton *btnRedLightOff;
    TStatusBar *m_sbSignalIndicator;
    TLabel *Label26;
    TEdit *edtBBBitCount;
    TButton *btnKeypadLEDOff;
    TButton *btnGreenLightOff;
    TButton *btnGreenLightOn;
    TButton *btnBlueLightOff;
    TButton *btnBlueLightOn;
    TEdit *edtKeypadLedDIV;
    TEdit *edtKeypadLedDUTY;
    TLabel *Label27;
    TLabel *Label28;
    TLabel *Label29;
    TLabel *Label30;
    TLabel *Label31;
    TTabSheet *tsBattery;
    TButton *btnDownloadImage;
    TButton *btnUploadImage;
    TStatusBar *m_sbBattery;
    TPanel *Panel2;
    TButton *BtnReadBatteryInfo;
    TEdit *EdtFWValue;
    TEdit *EdtVoltage;
    TStaticText *STFWValue;
    TStaticText *STVoltage;
    TGroupBox *GroupBox2;
    TGroupBox *GroupBox3;
    TButton *BtnReadSOC;
    TButton *BtnWriteSOC;
    TEdit *EdtSOC;
    TStaticText *STSOC;
    TLabel *LBDisplay;
    TStaticText *STDFI;
    TEdit *EdtDFIVersion;
    TStaticText *StaticText1;
    TStaticText *StaticText2;
    TButton *BtnUpdateFW;
    TEdit *EdtSOCClear;
    TStaticText *StaticText3;
    TButton *BtnWriteSOCClear;
    TButton *BtnReadSOCClear;
    TProgressBar *ProgressBar1;
    TLabel *Label32;
    TStaticText *StaticText4;
    TTabSheet *TabSheet1;
    TButton *btnUSB;
    TButton *btnUART;
    TShape *spUSB;
    TShape *spUART;
    TStatusBar *m_sbECCI;
    TButton *btnReset;
    TButton *BtnEnableBQ;
    TLabel *Label33;
    TButton *btnCleanBoot;
        TButton *btnBatteryVol;
        TLabel *Label34;
        TStaticText *stBatteryVol;
        TButton *btnBatteryCap;
        TStaticText *stBatteryCap;
        TLabel *Label35;

    void __fastcall HintTimerTimer(TObject *Sender);

    void __fastcall edtRegAddrCheck(TObject *Sender);
    void __fastcall edtRegValueCheck(TObject *Sender);
    void __fastcall pctlToolSelChange(TObject *Sender);
    void __fastcall btnBBRegReadClick(TObject *Sender);
    void __fastcall btnBBRegWriteClick(TObject *Sender);
    void __fastcall btnBBRegValueClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnPMICRegValueClick(TObject *Sender);
    void __fastcall btnPMICRegReadClick(TObject *Sender);
    void __fastcall btnPMICRegWriteClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall edtPMICAddressCheck(TObject *Sender);
    void __fastcall edtPMICValueCheck(TObject *Sender);
    void __fastcall btnPMICRegClick(TObject *Sender);
    void __fastcall btnKeypadLEDOnClick(TObject *Sender);
    void __fastcall btnVBROnClick(TObject *Sender);
    void __fastcall edtKeypadLEDDivCheck(TObject *Sender);
    void __fastcall edtKeypadLEDDutyCheck(TObject *Sender);
    void __fastcall btnVBROffClick(TObject *Sender);
    void __fastcall btnRTCQueryClick(TObject *Sender);
    void __fastcall edtLCDLEDCheck(TObject *Sender);
    void __fastcall btnLCDLEDSetClick(TObject *Sender);
    void __fastcall btnRedLightOnClick(TObject *Sender);
    void __fastcall btnRedLightOffClick(TObject *Sender);
    void __fastcall btnKeypadLEDOffClick(TObject *Sender);
    void __fastcall btnGreenLightOnClick(TObject *Sender);
    void __fastcall btnGreenLightOffClick(TObject *Sender);
    void __fastcall btnBlueLightOnClick(TObject *Sender);
    void __fastcall btnBlueLightOffClick(TObject *Sender);
    void __fastcall EdtExit(TObject *Sender);
    void __fastcall btnUSBClick(TObject *Sender);
    void __fastcall btnUARTClick(TObject *Sender);
    void __fastcall btnResetClick(TObject *Sender);
    void __fastcall btnCleanBootClick(TObject *Sender);
    void __fastcall tsLEDShow(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
        void __fastcall btnBatteryVolClick(TObject *Sender);
        void __fastcall btnBatteryCapClick(TObject *Sender);
private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
    bool       m_bInit;
    int        m_iFinalBBChip;

    //CBBREG     m_BB_REG_Obj;
    CBBPMICREG m_cBB_PMIC_REG_Obj;
    CBBCUSTHW  m_BB_CUSTHW_Obj;
    CBaseBand     m_cBaseBand_Obj;

    // BB register
    unsigned int   m_uiBBRegAddr;
    unsigned int   m_usBBRegValue;
    unsigned int   m_uiBBRegBitCount;

    // PMIC register
    PMIC_ID m_sPmicId;
    unsigned int   m_uiPMICRegNumber;
    unsigned short  m_usPMICRegValue;

    unsigned char m_cLCDLEDLevel;


public:		// User declarations
    // common
    __fastcall TfrmBaseBand(TComponent* Owner);
    void  CurrentPageReset(void);
    void  CurrentPageLock(void);
    void  ShowHintLabel(TControl *sender, char* hint);
    void  ReDrawFields(E_BB_PAGEIDX_T pageidx);
    bool  CheckFields(void );
    void  Init(void);


    // BB register
    void  CNF_ReadRegister( void );
    void  CNF_WriteRegister( void );


    void CNF_LED_KeypadLEDOnOff(void);
    void CNF_LED_LCDLightLevel(void);
    void CNF_VBR_TurnOn(void);
    void CNF_VBR_TurnOff(void);
    void CNF_SignalIndicator_TurnOn(void);
    void CNF_SignalIndicator_TurnOff(void);
    void CNF_RTC_Query(void);
    void CNF_PMIC_ReadRegister( void );
    void CNF_PMIC_WriteRegister( void );
    void CNF_Clean_Boot(void);
    void CNF_ECCIUSBTest(void);
    void CNF_ECCIUARTTest(void);


    PMIC_ID* Get_PMIC_ID(void);

    int m_Len;
    char m_RowBuf[96];
    int m_Type;
    //UI
    void _fastcall SubClassWndProc( Messages::TMessage &Message);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmBaseBand *frmBaseBand;
//---------------------------------------------------------------------------
#endif
