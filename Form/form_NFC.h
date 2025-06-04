//---------------------------------------------------------------------------

#ifndef form_NFCH
#define form_NFCH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include <CheckLst.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>

// man
#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif
#define NFC_PROTOCOL_TYPE_NUM 9
#define NFC_EVENT_DETECTED_NUM 6
#define NFC_REGISTER_PROTOCOL_NUM 8
#define NFC_DISCOVERY_PROTOCOL_NUM 8
typedef enum
{
    NFC_MIFAREUL =   0x00000001,
    NFC_MIFARESTD =  0x00000002,
    NFC_ISO1443_4A = 0x00000004,
    NFC_ISO1443_4B = 0x00000008,
    NFC_JEWEL =      0x00000010,
    NFC_NFC =        0x00000020,
    NFC_FELICA =     0x00000040,
    NFC_ISO15693 =   0x00000080,
    NFC_NDEF =   0x00000100
} E_NFC_SUPPORT_PROTOCOL;

typedef enum
{
    NFC_EVENT_START  =       0x00000001,
    NFC_EVENT_END =          0x00000002,
    NFC_EVENT_TRANSACTION =  0x00000004,
    NFC_EVENT_RFON =         0x00000008,
    NFC_EVENT_RFOFF =        0x00000010,
    NFC_EVENT_CONNECTIVITY = 0x00000020
} E_NFC_EVENT_DETECTED;

typedef enum
{
    NFC_DISCOVERY_ISO14443A =              0x00000001,
    NFC_DISCOVERY_ISO14443B =              0x00000002,
    NFC_DISCOVERY_FELICA212 =              0x00000004,
    NFC_DISCOVERY_FELICA424 =              0x00000008,
    NFC_DISCOVERY_ISO15693 =               0x00000010,
    NFC_DISCOVERY_NFC_ACTIVE =             0x00000020,
    NFC_DISCOVERY_DISCARD_CARD_EMULATION = 0x00000040,
    NFC_DISCOVERY_DISABLE_P2P_IP_TARGET =  0x00000080
} E_NFC_DISCOVERY_SETTING;

typedef enum
{
    NFC_TAB_SETTING  =               0x00000001,
    NFC_TAB_REGISTER_NOTIFICATION =  0x00000002,
    NFC_TAB_DISCOVERY_NOTIFICATION = 0x00000004,
    NFC_TAB_RAW_DATA =               0x00000008,
} E_NFC_TAB;
//---------------------------------------------------------------------------
class TfrmNFC : public TForm
{
__published:	// IDE-managed Components
    TPageControl *pcNFC;
    TTabSheet *tsNFCSetting;
    TTabSheet *tsNFCRegisterNotification;
    TTabSheet *tsRawData;
    TStatusBar *sbNFC;
    TGroupBox *gbNFCFeature;
    TGroupBox *gbNFCDebug;
    TRadioButton *rbNFCOn;
    TRadioButton *rbNFCOff;
    TRadioButton *rbNFCDebugOn;
    TRadioButton *rbNFCDebugOff;
    TGroupBox *gbNFCMode;
    TRadioButton *rbNFCRawData;
    TRadioButton *rbNFCSoftwareStack;
    TGroupBox *gbNFCCapabilities;
    TGroupBox *gbVersion;
    TGroupBox *gbNFCSupportedProtocols;
    TLabel *lblNFCFwVersion;
    TLabel *lblNFCSwVersion;
    TLabel *lblNFCHwVersion;
    TLabel *lblNFCVendor;
    TTabSheet *tsNFCDiscoveryNotification;
    TActionList *ActionList1;
    TAction *backdoor;
    TGroupBox *gbNFCNofificationSetting;
    TGroupBox *gbNFCNotificationMode;
    TCheckBox *cbNFC_RN_MifareUL;
    TCheckBox *cbNFC_RN_ISO144434B;
    TCheckBox *cbNFC_RN_MifareStd;
    TCheckBox *cbNFC_RN_ISO15693;
    TCheckBox *cbNFC_RN_Felica;
    TCheckBox *cbNFC_RN_ISO144434A;
    TCheckBox *cbNFC_RN_Jewel;
    TCheckBox *cbNFC_RN_NFC;
    TGroupBox *gbNFCSecureElements;
    TMemo *mmSecureElements;
    TGroupBox *gbNFCDiscoveryNotification;
    TGroupBox *gbNFCDicsoverySetting;
    TCheckBox *cbNFC_DS_Felica212;
    TCheckBox *cbNFC_DS_ISO14443B;
    TCheckBox *cbNFC_DS_Felica424;
    TCheckBox *cbNFC_DS_ISO15693;
    TCheckBox *cbNFC_DS_DisCardEmu;
    TCheckBox *cbNFC_DS_ISO14443A;
    TCheckBox *cbNFC_DS_NFCActive;
    TCheckBox *cbNFC_DS_DisP2PIpTar;
    TGroupBox *gbNFCRawData;
    TButton *btnNFC_RD_OpenScript;
    TStaticText *stNFC_RD_TargetFilePath;
    TMemo *mmNFC_RD_DisplayResult;
    TAction *Action1;
    TAction *Action2;
    TAction *Action3;
    TAction *Action4;
    TAction *Action5;
    TStaticText *stNFCVendor;
    TStaticText *stNFCFwVersion;
    TStaticText *stNFCSwVersion;
    TStaticText *stNFCHwVersion;
    TLabel *lblNFC_DN_Duration;
    TEdit *edtNFC_DN_Duration;
    TLabel *lblNFC_DN_Durationms;
    TCheckListBox *clbNFC_Secure_Event_Detected;
    TSpeedButton *sbNFCRegisterNofificationBack;
    TSpeedButton *sbNFCRegisterNofificationNext;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TSpeedButton *sbNFCDiscoveryNotificationBack;
    TLabel *Label7;
    TCheckListBox *clbNFC_Support_Prococol_Rm;
    TCheckListBox *clbNFC_Support_Prococol_Cm;
    TLabel *Label8;
    TLabel *Label9;
    TSpeedButton *sbNFCSettingSet;
    TSpeedButton *sbNFCRegisterNofificationSet;
    TSpeedButton *sbNFCDiscoveryNotificationSet;
    TGroupBox *gbNFCSecureElementSetMode;
    TSpeedButton *sbNFCSecureElementsSet;
    TGroupBox *gbNFCSecureElement1;
    TRadioButton *cbNFCSecureElement1Off;
    TRadioButton *cbNFCSecureElement1Virtual;
    TRadioButton *cbNFCSecureElement1Wired;
    TGroupBox *gbNFCSecureElement2;
    TRadioButton *cbNFCSecureElement2Virtual;
    TRadioButton *cbNFCSecureElement2Off;
    TRadioButton *cbNFCSecureElement2Wired;
    TLabel *Label10;
    TStaticText *stNFC_RN_SEDetected;
    TGroupBox *gbNFCTestMode;
    TRadioButton *rbNFC_Test_WithASK;
    TRadioButton *rbNFC_Test_WithoutASK;
    TRadioButton *rbNFC_Test_Reader;
    TRadioButton *rbNFC_Test_Peer;
    TRadioButton *rbNFC_Test_SWP;
    TSpeedButton *sbNFCRawDataTestStart;
    TSpeedButton *sbNFCRawDataTestStop;
    TSpeedButton *sbNFCRawDataScriptStart;
    TSpeedButton *sbNFCRawDataScriptStop;
    TRadioButton *rbNFC_Test_Emulation;
    TRadioButton *rbNFC_Test_CardMode;
    TRadioButton *rbNFC_Test_UidRD;
    TComboBox *cbNFC_Raw_Modulation_Type;
    TComboBox *cbNFC_Raw_BitRate;
    TComboBox *cbNFC_Raw_Type;
    TComboBox *cbNFC_Raw_Protocol;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TSpeedButton *sbNFCRawDataBack;
    TSpeedButton *sbNFCSettingNext;
    TRadioButton *rbNFC_Test_Antenna;
    TOpenDialog *dlgOpenNFCScipt;
    void __fastcall rbNFCClick(TObject *Sender);
    void __fastcall rbNFCDebugClick(TObject *Sender);
    void __fastcall rsNFCSWProtocolSwitchClick(TObject *Sender);
    void __fastcall backdoorExecute(TObject *Sender);
    void __fastcall btnSoftwareStackClick(TObject *Sender);
    void __fastcall btnNFCRawDataClick(TObject *Sender);
    void __fastcall btnNFC_RN_NFCSettingClick(TObject *Sender);
    void __fastcall btnNFC_RN_DiscoveryNotificationClick(TObject *Sender);
    void __fastcall btnNFC_DN_regNotificationClick(TObject *Sender);
    void __fastcall Action1Execute(TObject *Sender);
    void __fastcall Action2Execute(TObject *Sender);
    void __fastcall Action3Execute(TObject *Sender);
    void __fastcall Action4Execute(TObject *Sender);
    void __fastcall Action5Execute(TObject *Sender);

    void __fastcall sbNFCRegisterNofificationSetClick(TObject *Sender);
    void __fastcall sbNFCSecureElementsSetClick(TObject *Sender);
    void __fastcall sbNFCDiscoveryNotificationSetClick(TObject *Sender);
    void __fastcall sbNFCRawDataTestStartClick(TObject *Sender);
    void __fastcall sbNFCRawDataTestStopClick(TObject *Sender);
    void __fastcall sbNFCRegisterNofificationBackClick(TObject *Sender);
    void __fastcall sbNFCSettingNextClick(TObject *Sender);
    void __fastcall sbNFCDiscoveryNotificationBackClick(TObject *Sender);
    void __fastcall rbNFC_Test_WithASKClick(TObject *Sender);
    void __fastcall rbNFC_Test_EmulationClick(TObject *Sender);
    void __fastcall rbNFC_Test_ReaderClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall sbNFCRawDataBackClick(TObject *Sender);
    void __fastcall sbNFCSettingSetClick(TObject *Sender);
    void __fastcall sbNFCRegisterNofificationNextClick(TObject *Sender);
    void __fastcall btnNFC_RD_OpenScriptClick(TObject *Sender);
    void __fastcall sbNFCRawDataScriptStartClick(TObject *Sender);
    void __fastcall sbNFCRawDataScriptStopClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);


private:	// User declarations
    CMETAHANDLE m_META_HANDLE_Obj;
    TRadioButton *rbNFC_Test[NFC_PROTOCOL_TYPE_NUM];
    TCheckBox *cbNFC_RN[NFC_REGISTER_PROTOCOL_NUM];
    TCheckBox *cbNFC_DS[NFC_DISCOVERY_PROTOCOL_NUM];

public:		// User declarations
    __fastcall TfrmNFC(TComponent* Owner);

    void TabVisible(E_NFC_TAB tab);
    void CurrentPageLock(E_NFC_TAB nfc_tab);
    void CurrentPageReset(E_NFC_TAB nfc_tab);
    void NFCTestItemSelect(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNFC *frmNFC;
//---------------------------------------------------------------------------
#endif
