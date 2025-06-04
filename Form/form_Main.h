/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   form_Main.h
 *
 * Project:
 * --------
 *   SP META APP
 *
 * Description:
 * ------------
 *   Main selection form header
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:   1.12  $
 * $Modtime:   Oct 25 2005 11:57:12  $
 * $Log:   //mtkvs01/vmdata/meta_app/archives/MauiMETA/Form/form_Main.h-arc  $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//---------------------------------------------------------------------------

#ifndef _FORM_MAIN_H_
#define _FORM_MAIN_H_

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Classes.hpp>

#include "meta.h"
#include "mtk_mcu.h"
#include "sp_brom.h"
#include "NVRAMEditor.h"

#include "MfSetupUtil.h"
#include "com_enum.h"
//#include "META_factory_ADC_type.h"


#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

// BT
#ifndef  _BT_ID_H_
#include "bt_id.h"
#endif

// WiFi
#ifndef  _WIFI_GNRL_H_
#include "wifi_gnrl.h"
#endif

#ifndef  _UART_H_
#include "uart.h"
#endif

// security
#ifndef  _AUTH_H_
#include "AUTH.h"
#endif

#ifndef  _SCERT_H_
#include "SCERT.h"
#endif

#include <string>
#include <vector>
#include <set>

#include "IConnectionListener.h"

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif

#ifndef _DIALOG_INITIAL_DIR_
#include "DialogInitialDir.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

//---------------------------------------------------------------------------
//#define  MSEL_MAIN_MENU        -1

typedef enum
{
    BAUD_RATE_AUTO_INDEX=0,
    BAUD_RATE_57600_INDEX,
    BAUD_RATE_115200_INDEX,
    BAUD_RATE_230400_INDEX,
    BAUD_RATE_460800_INDEX,
    BAUD_RATE_921600_INDEX
} E_BAUD_RATE_INDEX;

typedef enum
{
    WIFI_STATE_OPEN=0,
    WIFI_STATE_CLOSE,
} E_WIFI_STATE;

#define  MAX_WAIT_FOR_TARGET_READY_COUNT 150

#define    FM_STEP_MODE_50KHZ     0
#define    FM_STEP_MODE_100KHZ    1
#define    FM_STEP_MODE_200KHZ    2

#define LOG_ROOT_PATH     "C:\\SPMETA_LOG"
#define SP_META_DLL_LOG   "SP_META_DLL.log"
#define SP_BOOT_MODE_LOG  "SP_META_BROM.log"

//---------------------------------------------------------------------------

class TfrmMainSel : public TForm
{
__published:	// IDE-managed Components
    TTimer *glbTimer;
    TComboBox *cbxOperation;
    TComboBox *cbxCOM;
    TShape *shpConnect;
    TMainMenu *MainMenu1;
    TMenuItem *Action1;
    TMenuItem *mnuOpenFDMDatabase;
    TMenuItem *N1;
    TMenuItem *mnuHelp;
    TMenuItem *mnuAbout;
    TPanel *pnlResetTarget;
    TGroupBox *GroupBox3;
    TRadioButton *rbSoftware;
    TRadioButton *rbHardware;
    TActionList *ActionList1;
    TAction *ToggleMETADebug;
    TButton *btnReconnect;
    TComboBox *cbBaudrate;
    TLabel *Label1;
    TTimer *HintTimer;
    TStaticText *lblHint;
    TMenuItem *Option1;
    TAction *LogClear;
    TStaticText *stMETALog;
    TStaticText *stBROMLog;
    TMenuItem *miOpenAuthenticationfile;
    TAction *ToggleHide;
    TMenuItem *miUnitTest;
    TOpenDialog *dlgOpenAuth;
    TOpenDialog *OpenDialog;
    TButton *m_btnDisconnect;
    TMenuItem *m_miConInMetaMode;
    TCheckBox *CbCleanBootFlag;
    TLabel *Label4;
    TCheckBox *cbMetaModeLock;
    TAction *ToggleMetaModeLock;
//    TTimer *usbFinder;
//    TTimer *kernalUSBFinder;
    TMenuItem *m_miOpenCertificatefile;
    TMenuItem *m_miLegacyAutoDetection;
    TMenuItem *m_miDriverInfo;
    TOpenDialog *dlgOpenScert;
    TMenuItem *m_miEnableCompositeUSB;
    TMenuItem *m_miMDlogging;
    TAction *actReconnect;
    TAction *actDisconnect;
    TAction *actAdmemo;
        TLabel *lbConnectionTime;
        TPanel *stConnectionTime;
        TAction *ConnectionTime;
    TMenuItem *m_miDisableMobileLogService;
    TMenuItem *m_miDisableUartLog;
    TMenuItem *miSpecialTest;
    TMenuItem *miMetaConnectTime;
    TAction *ToggleSpecialTest;

    void __fastcall cbxOperationChange(TObject *Sender);
    void __fastcall cbxCOMChange(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall mnuFDMDatabaseClick(TObject *Sender);
//    void __fastcall mnuCOMClick(TObject *Sender);
//    void __fastcall mnuExitClick(TObject *Sender);
    void __fastcall mnuAboutClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    //void __fastcall ToggleBromDebugExecute(TObject *Sender);
    void __fastcall ToggleMETADebugExecute(TObject *Sender);
//    void __fastcall rbSoftwareClick(TObject *Sender);
//    void __fastcall rbHardwareClick(TObject *Sender);
    void __fastcall btnReconnectClick(TObject *Sender);
    void __fastcall cbBaudrateChange(TObject *Sender);
    void __fastcall HintTimerTimer(TObject *Sender);
    void __fastcall glbTimerTimer(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
//    void __fastcall miAutodetectBBClick(TObject *Sender);
    void __fastcall LogClearExecute(TObject *Sender);
    void __fastcall miOpenAuthenticationfileClick(TObject *Sender);
    void __fastcall ToggleHideExecute(TObject *Sender);
    void __fastcall miUnitTestClick(TObject *Sender);
    void __fastcall m_btnDisconnectClick(TObject *Sender);
//        void __fastcall m_miMT6516Click(TObject *Sender);
//        void __fastcall m_miTK6516MDClick(TObject *Sender);
    void __fastcall m_miConInMetaModeClick(TObject *Sender);
    void __fastcall ToggleMetaModeLockExecute(TObject *Sender);
//        void __fastcall m_miMT6573Click(TObject *Sender);
    void __fastcall cbMetaModeLockClick(TObject *Sender);
//    void __fastcall usbFinderTimer(TObject *Sender);
//    void __fastcall kernalUSBFinderTimer(TObject *Sender);
    void __fastcall m_miOpenCertificatefileClick(TObject *Sender);
    void __fastcall m_miLegacyAutoDetectionClick(TObject *Sender);
    void __fastcall m_miDeviceManagerClick(TObject *Sender);
    void __fastcall m_miDriverInfoClick(TObject *Sender);
    void __fastcall m_miEnableCompositeUSBClick(TObject *Sender);
    void __fastcall m_miMDloggingClick(TObject *Sender);
    void __fastcall cbxCOMDropDown(TObject *Sender);
    void __fastcall actReconnectExecute(TObject *Sender);
    void __fastcall actDisconnectExecute(TObject *Sender);
    void __fastcall ConnectionTimeExecute(TObject *Sender);
    void __fastcall m_miDisableMobileLogServiceClick(TObject *Sender);
    void __fastcall m_miDisableUartLogClick(TObject *Sender);
    void __fastcall ToggleSpecialTestExecute(TObject *Sender);
    void __fastcall miSpecialTestClick(TObject *Sender);
    void __fastcall miMetaConnectTimeClick(TObject *Sender);

private:	// User declarations
    int  m_iComPort;
    TForm  *m_ActForm[TOTAL_MENU_ITEMS];
    int    m_iActFormCount;
    // initilization
    bool m_bInit;
    CMETAHANDLE m_META_HANDLE_Obj;
    bool b_open_NVRAM_database;
    AnsiString as_DELAY_TIME_BEFORE_ACCESS_NVRAM;

    // debug
    bool m_bMetaDebugOn;
    bool m_bBRomDebugOn;

    //meta mode lock for JRD
    bool m_bMetaModeLockOn;
    bool m_bMetaModeLockChecked;

    // Main menu item
    AnsiString m_asMenuSelection;
    AnsiString m_asCOM;
    AnsiString m_asBaseband_chip;
    AnsiString m_asClock_rate;
    AnsiString m_asDisable_HW_flow_control;
    AnsiString m_asFlow_control;
    AnsiString m_asTstMsgFormat;
    AnsiString m_asGSM850_support;
    AnsiString m_asAuto_control_power_supply;
    AnsiString m_asBaudrate;
    GUID m_InterfaceClassGuidConstant;

    // UI setting

    bool m_bLastMenuItemBBCheck[BBCHIP_TYPE_END - 1];
    bool m_bLastMenuItemAutoDetectBBCheck;

    void * pTMenuItem[BBCHIP_TYPE_END - 1];

    bool m_lastMenuItem13MHzCheck;
    bool m_lastMenuItem26MHzCheck;
    bool m_lastMenuItem39MHzCheck;
    bool m_lastMenuItem52MHzCheck;
    bool m_lastMenuItemAutodetectExtCheck;
    bool m_lastrbHardwareCheck;
    bool m_lastrbSoftwareCheck;

    // syn with target
    unsigned short ComPortArray[MAX_SUPPORT_COM_NUM];
    //unsigned short ComPortCount;
    int nComPortCount;    //change variable type 20120903
    unsigned int meta_ver_required_by_target;
    int currentBaudRateIndex;

    // Power supply control
    // AnsiString as_Power_Supply_GPIB_Addr;
    int m_iPowerSupplyOnCount;
    int m_iPowerSupplyOffCount;
    int m_iPowerSupplyTriggerTime;

    //bool result;
    //TYPE_META_FACTORY_ADC_CONTROL MF_ADC_ctrl;
    int i_NORMAL_VOLTAGE;
    int i_CURRENT_LIMIT;
    int i_OFF_VOLTAGE;
    int isUserPress;

    // RF ID
    //CRFID  RF_ID_Obj;
//    unsigned int  m_uiFinalRFID;

    // capability
    RfMsCapabilityEx2_S m_sFinalMSCAP;

    CWIFIGNRL    WIFI_GNRL_Obj;

    bool m_bWiFiSupport;
    WiFi_ChipCapability_S m_sWiFiCap;
    unsigned char m_ucPmSupportNum;

    // two APC DC offset
    //bool m_bTadoSupport;
    //CRFAPC   RF_APC_Obj;

    // BT
    CBTID  m_BT_ID_Obj;
    BT_ModuleID_S  m_sBTModuleID;

    // audio
    // security
    CAUTH  m_cAuthObj;
    CSCERT  m_cScertObj;
    AnsiString  m_asAuthFileName;
    AnsiString  m_asScertFileName;

    SPMETA::BootMode m_BootMode;
    bool connecting;

    bool GetCurrentCOMPort(void);
    //

protected:

public:
    // syn with target
    int BootResult;
    int BootStop;
    int iCOM;
    META_Connect_Req META_connect_req;
    META_Connect_Report META_connect_report;
    META_RESULT META_connect_result;
    int   NeedToReboot;
    bool isReconnect;

    //Wei for secured META entry
    SP_BOOT_ARG_S m_stModeArg;


    //20130818 add for secured UART meta entry
    bool m_bOpenAuthenticationfile;
    bool m_bOpenCertificatefile;
    //
    //20131129 add for set mobile log service
    bool m_bDisableMobileLog;
    int ResetCount;
    META_COMM_BAUDRATE  META_baudrate;
    AnsiString as_NVRAM_database_file_name;

    //20160819
    int m_nNVRAMBackupRestoreTimeout;

    // function
    __fastcall TfrmMainSel(TComponent* Owner);
//    void __fastcall FDMDatabaseInit(AnsiString  asFileName);
    void  ChangeComPort( int com_port );
//    void  UartDisconnect( void );
    void __fastcall tb_Init_NVRAMClick(TObject *Sender);

    // timer
    void  TimerStart( int timeout_count );
    void  TimerStop();
    void  ExitMainMenu( void );

    // sync with target
    void DisableGlbTimer(void);
    void SetConnectReqType(void);
    void SetMetaConnectReq(void);
    void SetConnectInMETAModeReq(void);
//    void get_META_baudrate(void);
//    void RestartBootPolling(void);
//    void RestartCommStart(void);

    // query
    void  QuerySingleBankFlash(void);
    void  QueryRfMsCap(void);
    void  QueryRfId(void);
    void  Query_TwoApcDcOffset_Support(void);
    void  QueryWiFiSupport(void);
    void  QueryWiFiCapbility(void);
    void  QueryBTMoudleID(void);
    void  QueryPmSupportNum(void);

    // UI
    void _fastcall SubClassWndProc( Messages::TMessage &Message);
    void  ApplyHideProperty( void );
    void  EnableComponents( bool bEnable );
    void  ShowHintLabel( TControl *sender, char* hint );
    void  getMenuPopupLocation( int menu_index, int* left, int* top );

    void  DisplayMainMenuSetting( void );
    void  DisplayFinalBaseBandChip(BBCHIP_TYPE bbchip);
    void  DisplayFinalExternalClock(EXT_CLOCK ext_clock);
    void  DisplayFinalTargetBaudrate(META_COMM_BAUDRATE baudrate);
    void  DisplayWiFiCapbility(WiFi_ChipCapability_S  &wifi_cap);
    void  DisplayBTBbChip(void);
    void  DisplayFMChip(void);
    void  SaveMainMenuSetting(void);
    void  Reconnect(void);
    // global information
    BBCHIP_TYPE Get_FinalBBChip(void);
    WiFi_ChipCapability_S Get_FinalWiFiCap(void);
    BT_ModuleID_S* Get_BTMoudleID(void);

    void ToolReset();

    // call back
    void  CNF_NVRAMInitial( void );
    void  __fastcall on_QueryRfMsCap_Fail(TObject *Sender);
    void  __fastcall on_QueryRfMsCap_TerminateSuccess(TObject *Sender);
    void  __fastcall on_QueryRFID_Fail(TObject *Sender);
    void  __fastcall on_QueryRFID_TerminateSuccess(TObject *Sender);
    AnsiString Get_AuthFileName( void );
    AnsiString Get_ScertFileName( void );

    //Clean boot

    std::string   s_com_symbol;
    std::string   s_com_symbol_tst;
    std::set<std::string> m_exist_com_port_str;
    std::set<std::string> m_exist_com_port_str_tst;
    void scan_exist_com_port_str(std::set<std::string>  &exist_com_ports_str /*out*/,char * PID_Scan,char * VID_Scan,GUID guid,int USBType);
    bool get_new_created_com_port_str(std::string &usb_com_port_str,
                                      std::set<std::string> &exist_com_port_str,char * PID_Scan,char * VID_Scan,GUID guid,int USBType);
    int OpenDatabaseCommon(char* str);
//    int OpenDatabase(void);


    //Wei for secured META entry
    void SetMETAArg();
    SP_BOOT_ARG_S * GetMETAArg();
    void Disconnect(TObject *Sender);
    void FormClose_Handler(TObject *Sender);

    void GetTargetVersionDone(void);
    void CNF_GetTargetVersion(void);

    void Init(void);
    //For Special Test 20130707
    void ApplyShowSpecialTest( void );
    //
    void QueryWCNDriverReady(void);

    bool SPMetaLogOn();
    void SPMetaLogOff();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMainSel *frmMainSel;
//---------------------------------------------------------------------------
#endif
