//---------------------------------------------------------------------------

#ifndef NFCMainH
#define NFCMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>

#ifndef _NFC_READER_H_
#include "nfc_reader.h"
#endif

#ifndef _NFC_POLLING_H_
#include "nfc_polling.h"
#endif

#ifndef  _NFC_P2P_H_
#include "nfc_p2p.h"
#endif

#ifndef _NFC_CARD_MODE_H_
#include "nfc_card_mode.h"
#endif

#ifndef _NFC_TX_CARRIER_ALS_ON_H_
#include "nfc_tx_carrier_als_on.h"
#endif

#ifndef form_NFC_readerH
#include "form_NFC_reader.h"
#endif

#ifndef _NFC_VIRTUAL_CARD_FUNCTION_H_
#include "nfc_virtual_card_function.h"
#endif

#ifndef  _NFC_PNFC_COMMAND_H_
#include "nfc_pnfc_command.h"
#endif

#ifndef  _NFC_VERSION_QUERY_H_
#include "nfc_version_query.h"
#endif

#ifndef  _NFC_OPTION_SETTING_H_
#include "nfc_option_setting.h"
#endif

#ifndef  _NFC_LOOPBACK_TEST_H_
#include "nfc_loopback_test.h"
#endif

#ifndef  _NFC_SWP_TEST_H_
#include "nfc_swp_test.h"
#endif

#ifndef reader_resultH
#include "reader_result.h"
#endif

/* BITMAP OF EM_ALS_CARD_M_SW_NUM */
#define EM_ALS_CARD_M_SW_NUM_SWIO1        (1 << 0) 
#define EM_ALS_CARD_M_SW_NUM_SWIO2        (1 << 1)
#define EM_ALS_CARD_M_SW_NUM_SWIOSE       (1 << 2)

/* BITMAP OF EM_ENABLE_FUNC */
#define EM_ENABLE_FUNC_READER_MODE        (1 << 0) 
#define EM_ENABLE_FUNC_CARD_MODE          (1 << 1)
#define EM_ENABLE_FUNC_P2P_MODE           (1 << 2)


#define EM_ALS_READER_M_TYPE_A        (1 << 0) 
#define EM_ALS_READER_M_TYPE_B        (1 << 1)
#define EM_ALS_READER_M_TYPE_F        (1 << 2)
#define EM_ALS_READER_M_TYPE_V        (1 << 3) 
#define EM_ALS_READER_M_TYPE_BPrime   (1 << 4)
#define EM_ALS_READER_M_TYPE_KOVIO    (1 << 5)

#define EM_ALS_READER_START "Start"
#define EM_ALS_READER_STOP "Stop"
 
#define EM_ALS_READER_M_SPDRATE_106        (1 << 0) 
#define EM_ALS_READER_M_SPDRATE_212        (1 << 1)
#define EM_ALS_READER_M_SPDRATE_424        (1 << 2)
#define EM_ALS_READER_M_SPDRATE_848        (1 << 3) 
#define EM_ALS_READER_M_SPDRATE_662        (1 << 4) 
#define EM_ALS_READER_M_SPDRATE_2648       (1 << 5)

/* BITMAP OF EM_P2P_ROLE */
#define EM_P2P_ROLE_INITIATOR_MODE        (1 << 0) 
#define EM_P2P_ROLE_TARGET_MODE           (1 << 1)

/* BITMAP OF EM_P2P_MODE */
#define EM_P2P_MODE_PASSIVE_MODE          (1 << 0)
#define EM_P2P_MODE_ACTIVE_MODE           (1 << 1)

typedef enum {
   NFC_EM_ACT_START = 0,
   NFC_EM_ACT_STOP,
   NFC_EM_ACT_RUNINGB,
} EM_ACTION;

//---------------------------------------------------------------------------
class TfrmNFCNew : public TForm
{
__published:	// IDE-managed Components
        TPageControl *tabNFC;
        TTabSheet *tsRM;
        TTabSheet *tsP2P;
        TTabSheet *tsCEM;
        TTabSheet *TSPLM;
        TTabSheet *TSTXCSAO;
        TTabSheet *TSVCF;
        TTabSheet *TSPNFC;
        TTabSheet *TSVQ;
        TTabSheet *TSOption;
        TGroupBox *GroupBox1;
        TCheckBox *cb_AIRM_TypeA;
        TCheckBox *cb_AIRM_TypeB;
        TCheckBox *cb_AIRM_TypeF;
        TCheckBox *cb_AIRM_TypeV;
        TCheckBox *cb_AIRM_TypeB_plus;
        TCheckBox *cb_AIRM_Kovio;
        TRadioButton *rb_AIRM_TypeA_106kbps;
        TRadioButton *rb_AIRM_TypeA_212kbps;
        TRadioButton *rb_AIRM_TypeA_424kbps;
        TRadioButton *rb_AIRM_TypeA_848kbps;
        TRadioButton *rb_AIRM_TypeF_424kbps;
        TRadioButton *rb_AIRM_TypeF_212kbps;
        TGroupBox *GroupBox2;
        TRadioButton *rb_AIRM_TypeV_Subcarrier;
        TRadioButton *rb_AIRM_TypeV_DualSubcarrie;
        TRadioButton *rb_AIRM_TypeV_CodingMode_4;
        TRadioButton *rb_AIRM_TypeV_CodingMode_256;
        TButton *tb_AIRM_Start;
        TButton *tb_AIRM_SelectAll;
        TButton *tb_AIRM_ClearAll;
        TGroupBox *GroupBox3;
        TCheckBox *cb_P2PM_TypeA;
        TRadioButton *rb_P2PM_TypeA_106kbps;
        TRadioButton *rb_P2PM_TypeA_212kbps;
        TRadioButton *rb_P2PM_TypeA_424kbps;
        TRadioButton *rb_P2PM_TypeA_848kbps;
        TCheckBox *cb_P2PM_TypeF;
        TRadioButton *rb_P2PM_TypeF_212kbps;
        TRadioButton *rb_P2PM_TypeF_424kbps;
        TButton *tb_P2PM_Start;
        TButton *tb_P2PM_ClearAll;
        TButton *tb_P2PM_SelectAll;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox5;
        TButton *tb_AICEM_Start;
        TButton *tb_AICEM_ClearAll;
        TButton *tb_AICEM_SelectAll;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TCheckBox *cb_AICEM_TypeA;
        TCheckBox *cb_AICEM_TypeB;
        TCheckBox *cb_AICEM_TypeB_plus;
        TCheckBox *cb_AICEM_TypeF;
        TGroupBox *GroupBox10;
        TGroupBox *GroupBox11;
        TRadioButton *rb_AIRM_TypeB_106kbps;
        TRadioButton *rb_AIRM_TypeB_212kbps;
        TRadioButton *rb_AIRM_TypeB_424kbps;
        TRadioButton *rb_AIRM_TypeB_848kbps;
        TGroupBox *GroupBox12;
        TGroupBox *GroupBox13;
        TGroupBox *GroupBox14;
        TGroupBox *GroupBox17;
        TCheckBox *cb_P2PM_DisableCardEmulation;
        TGroupBox *rb_PLM_RM_6_62kbps;
        TGroupBox *GroupBox18;
        TRadioButton *cb_PLM_RM_TypeF_212kbps;
        TRadioButton *cb_PLM_RM_TypeF_424kbps;
        TGroupBox *GroupBox19;
        TRadioButton *cb_PLM_RM_TypeA_106kbps;
        TRadioButton *cb_PLM_RM_TypeA_212kbps;
        TRadioButton *cb_PLM_RM_TypeA_424kbps;
        TRadioButton *cb_PLM_RM_TypeA_848kbps;
        TCheckBox *cb_PLM_RM_TypeA;
        TCheckBox *cb_PLM_RM_TypeB;
        TCheckBox *cb_PLM_RM_TypeF;
        TCheckBox *cb_PLM_RM_TypeV;
        TCheckBox *cb_PLM_RM_TypeB_plus;
        TCheckBox *cb_PLM_RM_Kovio;
        TGroupBox *GroupBox20;
        TRadioButton *cb_PLM_RM_TypeV_CodingMode_256;
        TRadioButton *cb_PLM_RM_TypeV_Subcarrier;
        TRadioButton *cb_PLM_RM_TypeV_DualSubcarrier;
        TRadioButton *cb_PLM_RM_TypeV_CodingMode_4;
        TGroupBox *GroupBox21;
        TRadioButton *cb_PLM_RM_TypeB_106kbps;
        TRadioButton *cb_PLM_RM_TypeB_212kbps;
        TRadioButton *cb_PLM_RM_TypeB_424kbps;
        TRadioButton *cb_PLM_RM_TypeB_848kbps;
        TCheckBox *cb_PLM_RM;
        TCheckBox *cb_PLM_P2PM;
        TGroupBox *GroupBox22;
        TGroupBox *GroupBox23;
        TRadioButton *rb_PLM_P2PM_TypeF_212kbps;
        TRadioButton *rb_PLM_P2PM_TypeF_424kbps;
        TGroupBox *GroupBox24;
        TRadioButton *rb_PLM_P2PM_TypeA_106kbps;
        TRadioButton *rb_PLM_P2PM_TypeA_212kbps;
        TRadioButton *rb_PLM_P2PM_TypeA_424kbps;
        TRadioButton *rb_PLM_P2PM_TypeA_848kbps;
        TGroupBox *GroupBox25;
        TGroupBox *GroupBox26;
        TGroupBox *GroupBox27;
        TGroupBox *GroupBox28;
        TCheckBox *cb_PLM_P2PM_DisableCardEmulation;
        TCheckBox *cb_PLM_P2PM_TypeA;
        TCheckBox *cb_PLM_P2PM_TypeF;
        TCheckBox *cb_PLM_CEM;
        TGroupBox *GroupBox29;
        TGroupBox *GroupBox30;
        TGroupBox *GroupBox31;
        TCheckBox *cb_PLM_CEM_TypeA;
        TCheckBox *cb_PLM_CEM_TypeB;
        TCheckBox *cb_PLM_CEM_TypeB_plus;
        TCheckBox *cb_PLM_CEM_TypeF;
        TRadioButton *rb_PLM_Listen;
        TRadioButton *rb_PLM_Pause;
        TLabel *Label1;
        TEdit *te_PLM_Period;
        TLabel *Label2;
        TButton *tb_TXCSAO_Start;
        TGroupBox *GroupBox33;
        TCheckBox *cb_VCF_TypeA;
        TCheckBox *cb_VCF_TypeB;
        TCheckBox *cb_VCF_TypeF;
        TGroupBox *GroupBox34;
        TRadioButton *rb_VCF_TypeF_212kbps;
        TRadioButton *rb_VCF_TypeF_424kbps;
        TButton *tb_VCF_Start;
        TButton *tb_SelectAll;
        TButton *tb_ClearAll;
        TGroupBox *GroupBox35;
        TLabel *Label3;
        TEdit *te_PNFC_Command;
        TLabel *Label4;
        TButton *tb_PNFC_Start;
        TButton *tb_PNFC_Clean;
        TGroupBox *GroupBox36;
        TLabel *Label5;
        TEdit *te_VQ_NFC_MW_Version;
        TEdit *te_VQ_NFC_FW_Version;
        TLabel *Label6;
        TEdit *te_VQ_NFC_HW_Version;
        TLabel *Label7;
        TButton *tb_VQ_Query;
        TGroupBox *GroupBox37;
        TCheckBox *cb_Option_EnableForceDownload;
        TCheckBox *cb_Option_EnableAutoCheckPresence;
        TButton *tb_Option_Set;
        TRichEdit *tre_PNFC_ReceivingMessage;
        TGroupBox *GroupBox44;
        TGroupBox *GroupBox45;
        TButton *tb_PLM_Start;
        TButton *tb_PLM_SelectAll;
        TButton *tb_PLM_ClearAll;
        TGroupBox *GroupBox46;
        TGroupBox *GroupBox47;
        TGroupBox *GroupBox48;
        TRadioButton *cb_PLM_RM_6_62kbps;
        TRadioButton *cb_PLM_RM_26_48kbps;
        TTabSheet *TSLoopback;
        TButton *tb_Loopback_Start_Stop;
        TTabSheet *SWT;
        TButton *tb_SWPTest_Start_Stop;
        TLabel *tl_AIP2PM_Link_Status_up;
        TGroupBox *GroupBox9;
        TCheckBox *cb_P2PM_PassiveMode;
        TCheckBox *cb_P2PM_ActiveMode;
        TGroupBox *GroupBox15;
        TCheckBox *cb_P2PM_Initator;
        TCheckBox *cb_P2PM_Target;
        TLabel *tl_Loopback_test;
        TRadioButton *rb_AICEM_SWIO1;
        TRadioButton *rb_AICEM_SWIO2;
        TRadioButton *rb_AICEM_SWIOSE;
        TCheckBox *cb_PLM_P2PM_PassiveMode;
        TCheckBox *cb_PLM_P2PM_ActiveMode;
        TCheckBox *cb_PLM_P2PM_Initiator;
        TCheckBox *cb_PLM_P2PM_Target;
        TRadioButton *rb_PLM_CEM_SWIO1;
        TRadioButton *rb_PLM_CEM_SWIO2;
        TRadioButton *rb_PLM_CEM_SWIOSE;
        TButton *rb_PLM_CEM_SetSE;
        TLabel *cb_PLM_P2PM_LinkStatus_up;
        TRadioButton *rb_AIRM_TypeV_6_62kbps;
        TRadioButton *rb_AIRM_TypeV_26_48kbps;
        TLabel *tl_AIP2PM_Link_Status_down;
        TLabel *cb_PLM_P2PM_LinkStatus_down;
        TButton *Button2;
        TCheckBox *cb_SWPT_SWIO1;
        TCheckBox *cb_SWPT_SWIO2;
        TCheckBox *cb_SWPT_SWIOSE;
    TCheckBox *cb_VCF_TypeB_plus;
        TLabel *Label8;

        void __fastcall cb_AIRM_TypeAClick(TObject *Sender);
        void __fastcall cb_AIRM_TypeBClick(TObject *Sender);
        void __fastcall cb_AIRM_TypeFClick(TObject *Sender);
        void __fastcall cb_AIRM_TypeVClick(TObject *Sender);
        void __fastcall tb_AIRM_SelectAllClick(TObject *Sender);
        void __fastcall tb_AIRM_ClearAllClick(TObject *Sender);
        void __fastcall cb_P2PM_TypeAClick(TObject *Sender);
        void __fastcall cb_P2PM_TypeFClick(TObject *Sender);
        void __fastcall tb_P2PM_SelectAllClick(TObject *Sender);
        void __fastcall tb_P2PM_ClearAllClick(TObject *Sender);
        void __fastcall tb_AICEM_SelectAllClick(TObject *Sender);
        void __fastcall tb_AICEM_ClearAllClick(TObject *Sender);
        void __fastcall tb_PLM_SelectAllClick(TObject *Sender);
        void __fastcall tb_PLM_ClearAllClick(TObject *Sender);
        void __fastcall cb_PLM_RMClick(TObject *Sender);
        void __fastcall cb_PLM_RM_TypeAClick(TObject *Sender);
        void __fastcall cb_PLM_RM_TypeBClick(TObject *Sender);
        void __fastcall cb_PLM_RM_TypeFClick(TObject *Sender);
        void __fastcall cb_PLM_RM_TypeVClick(TObject *Sender);
        void __fastcall cb_PLM_P2PMClick(TObject *Sender);
        void __fastcall cb_PLM_CEMClick(TObject *Sender);
        void __fastcall cb_PLM_P2PM_TypeAClick(TObject *Sender);
        void __fastcall cb_PLM_P2PM_TypeFClick(TObject *Sender);
        void __fastcall tb_SelectAllClick(TObject *Sender);
        void __fastcall tb_ClearAllClick(TObject *Sender);
        void __fastcall cb_VCF_TypeFClick(TObject *Sender);
/*        void __fastcall cb_Others_VCF_SelectAllClick(TObject *Sender);
        void __fastcall cb_Others_VCF_ClearAllClick(TObject *Sender);
        void __fastcall cb_Others_VCF_TypeFClick(TObject *Sender);    */
        void __fastcall tb_AIRM_StartClick(TObject *Sender);
        void __fastcall tb_P2PM_StartClick(TObject *Sender);
        void __fastcall tb_AICEM_StartClick(TObject *Sender);
        void __fastcall tb_TXCSAO_StartClick(TObject *Sender);
        void __fastcall tb_VCF_StartClick(TObject *Sender);
        void __fastcall tb_PNFC_StartClick(TObject *Sender);
        void __fastcall tb_VQ_QueryClick(TObject *Sender);
        void __fastcall tb_Option_SetClick(TObject *Sender);
        void __fastcall tb_Loopback_Start_StopClick(TObject *Sender);
        void __fastcall tb_SWPTest_Start_StopClick(TObject *Sender);
        void __fastcall tb_AICEM_SetSWIOClick(TObject *Sender);
        void __fastcall tb_PLM_StartClick(TObject *Sender);
        void __fastcall rb_PLM_CEM_SetSEClick(TObject *Sender);
        void __fastcall tabNFCChange(TObject *Sender);
        void __fastcall tb_PNFC_CleanClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall tb_SWPT_SetSEClick(TObject *Sender);
        void __fastcall cb_SWPT_SWIO1Click(TObject *Sender);
        void __fastcall cb_SWPT_SWIO2Click(TObject *Sender);
        void __fastcall cb_SWPT_SWIOSEClick(TObject *Sender);
private:	// User declarations
        CNFCREADER m_NfcReaderObj;
        CNFCP2P m_NfcP2PObj;
        CNFCCARDMODE m_NfcCardMObj;
        CNFCTXCARRIERALSON m_NfcTxCarrAlsOnObj;
        CNFCVIRTUALCARDFUNC m_NfcVirtualCardFuncObj;
        CNFCPNFCCOMMAND m_NfcPNFCCommandObj;
        CNFCVERSIONQUERY m_NfcVersionQueryObj;
        CNFCOPTIONSETTING m_NfcOptionSettingObj;
        CNFCLOOPBACKTEST m_NfcLoopbackTestObj;
        CNFCSWPTEST m_NfcSWPTestObj;
        CNFCPOLLING m_NfcPOLLINGObj;
        
        NFC_EM_ALS_READERM_REQ_S m_AIRM_reader_req;
        NFC_EM_ALS_P2P_REQ_S m_P2PM_req;
        NFC_EM_ALS_CARDM_REQ_S m_CardMode_req;
        NFC_EM_TX_CARR_ALS_ON_REQ_S m_tx_carr_als_on_req;
        NFC_EM_VIRTUAL_CARD_REQ_S m_Virtual_Card_req;
        NFC_EM_PNFC_REQ_S m_pnfc_command_req;
        NFC_TEST_MODE_SETTING_REQ_S m_option_setting_req;
        NFC_LOOPBACK_TEST_REQ_S m_loopback_test_req;
        NFC_FM_SWP_TEST_REQ_S m_swp_test_req;
        NFC_EM_POLLING_REQ_S m_polling_loop_req;
        NFC_READER_RSP_S nfc_rsp;
        NFC_POLLING_RSP_S m_nfc_polling_rsp;
        NFC_P2P_RSP_S m_nfc_p2p_rsp;
        int polling_loop_status;
public:		// User declarations
        __fastcall TfrmNFCNew(TComponent* Owner);
        void _fastcall SubClassWndProc( Messages::TMessage &Message);
        void composeReaderReq(void);
        void composeP2PReq(void);
        void compositeAICEMReq(void);
        void compositeVirtualCardReq(void);
        void composePollingLoopReq(void);
        void resetAIRMUI(void);     
        void resetP2PMUI(void);   
        void resetAICEMUI(void);   
        void resetPLMUI(void);     
        void resetTXCSAOUI(void);      
        void resetVCFUI(void);
        void resetPNFCUI(void); 
        void resetVQUI(void);         
        void resetOptionUI(void);       
        void resetLoopbackUI(void);   
        void resetSWPTestUI(void);
        void ConfirmCallback_Reader(void); 
        void ConfirmCallback_Polling(void); 
        void ConfirmCallback_P2P(void);
        void composeSWPTestUI(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNFCNew *frmNFCNew;
//---------------------------------------------------------------------------
#endif
