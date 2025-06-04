#ifndef  _BT_BLE_H_
#define  _BT_BLE_H_

#include <vcl.h>

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

// BT
#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

typedef enum
{
    BT_TX_Test=0,
    BT_RX_Test
} BT_BLE_TEST_TYPE;

typedef enum
{
    PRBS9=0x00,
    P11110000=0x01,
    P10101010=0x02
} BT_BLE_TX_PATTERN;

typedef enum
{
    EPRBS9=0x00,
    EP11110000=0x01,
    EP10101010=0x02,
    EPPRBS15=0x03,
    EP11111111=0x04,
    EP00000000=0x05,
    EP00001111=0x06,
    EP01010101=0x07
}BT_BLE_ENHANCED_TX_PATTERN;

typedef enum
{
    P1MPHY = 0x01,
    P2MPHY = 0x02,
    PCodedPHYS8 = 0x03,
    PCodedPHYS2 = 0x04
}BT_BLE_ENHANCED_TX_PHY;

typedef enum
{
    EP1MPHY = 0x01,
    EP2MPHY = 0x02,
    EPCodedPHY = 0x03
}BT_BLE_ENHANCED_RX_PHY;

typedef enum
{
    BT_SINGLE=0,
    BT_HOPPING
} E_BT_CHANNEL_TYPE;

typedef enum
{
    Public_Device_Address=0,
    Random_Device_Address
} E_BT_Device_Address;

typedef enum
{
    ADV_IND=0,
    ADV_DIRECT_IND ,
    ADV_DISCOVER_IND,
    ADV_NONCONN_IND
} E_BT_Advertising_Type;

typedef enum
{
    Passive_Scan=0,
    Active_Scan
} E_BT_Scan_Type;

typedef enum
{
    Accept_All_Advertise_Packet=0,
    Ignore_Advertise_Packet_Not_In_White_List
} E_BT_Scan_Filter_Policy;

typedef enum
{
    Disable_Duplicate_Filtering=0,
    Enable_Duplicate_Filtering
} E_BT_Scan_Filter_Duplicate;

typedef enum
{
    White_List_Is_Not_Used = 0,
    White_List_Is_Used
} E_BT_Initiate_Filter_Policy;

typedef enum
{
    All_Allow=0,
    Scan_Request_From_While_List,
    Connection_Request_From_White,
    Both_From_While_List
} E_BT_Advertise_Filter_Policy;

typedef struct
{
    HANDLE hPostMsgDestHandle;
    TStringList *log;
    BT_BLE_TEST_TYPE  ble_test_type;
    int Channel;
    int PayloadLength;
    BT_BLE_ENHANCED_TX_PATTERN ble_tx_patten;
    BT_BLE_ENHANCED_TX_PHY ble_tx_phy;
    BT_BLE_ENHANCED_RX_PHY ble_rx_phy;

}S_BT_BLE_ENHANCED;

typedef struct
{
    HANDLE hPostMsgDestHandle;
    TStringList *log;
    BT_BLE_TEST_TYPE  ble_test_type;
    int Channel;
    E_BT_CHANNEL_TYPE ble_channel_type;
    BT_BLE_TX_PATTERN ble_tx_patten;
    int PacketCount;
} S_BT_BLE;

typedef struct
{
    HANDLE hPostMsgDestHandle;
    TStringList *log;
    E_BT_Device_Address ble_device_address;
    AnsiString ble_strWhiteList;
    AnsiString ble_strAdvertiseData;
    AnsiString ble_strAdvertisingIntervalMin;
    AnsiString ble_strAdvertisingIntervalMax;
    E_BT_Advertising_Type ble_advertising_type;
    E_BT_Device_Address ble_own_address_type;
    E_BT_Device_Address ble_direct_address_type;
    AnsiString ble_strDirectAddress ;
    int channel;
    E_BT_Advertise_Filter_Policy ble_advertise_filter_policy;

    AnsiString ble_strSetScanResponseData;
    E_BT_Scan_Type ble_scan_type;
    AnsiString ble_strLEScanInterval;
    AnsiString ble_strLEScanWindow;
    E_BT_Device_Address ble_scan_own_address_type;
    E_BT_Scan_Filter_Policy ble_scan_filter_policy;
    E_BT_Scan_Filter_Duplicate ble_scan_filter_duplicate;

    AnsiString ble_strLEScanIntervalIn;
    AnsiString ble_strLEScanWindowIn;
    E_BT_Initiate_Filter_Policy ble_initiate_filter_policy;
    E_BT_Device_Address ble_PeerAddressType;
    E_BT_Device_Address ble_OwnAddressTypeIn;
    AnsiString strPeerAddress;
    AnsiString strConnectionIntervalMin;
    AnsiString strConnectionIntervalMax;
    AnsiString strConnectionLatency;
    AnsiString strSupervisionTimeout;
    AnsiString strMinimumCELength;
    AnsiString strMaximumCELength;

} S_BT_BLE_Normal;



class  CBTBLE
{
private:
    META_RESULT m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    S_BT_BLE  m_sBtBle;
    S_BT_BLE_Normal m_sBleNormal;
    S_BT_BLE_ENHANCED m_sBleEnhanced;
    AnsiString 	m_conf;

protected:
    void  Confirm(META_RESULT confirm_state);
public:

    E_BT_PAGEIDX eBTPage;
    CBTBLE( void );
    ~CBTBLE();

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );

    void  REQ_BLEClearWhiteList(S_BT_BLE_Normal  bt_ble);
    void  REQ_Start( S_BT_BLE  bt_ble );
    void  REQ_StartStop( S_BT_BLE  bt_ble );
    void  REQ_BLEResetHCI(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLEAddDeviceToWhiteList(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLERemoveDeviceToWhiteList(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLESetAdvertiseData(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLEAdvertiseStart(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLEAdvertiseStop(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLESetScanResponseData(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLEScanStart(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLEScanStop(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLEInitiateStart(S_BT_BLE_Normal  bt_ble);
    void  REQ_BLEInitiateStop(S_BT_BLE_Normal  bt_ble);
    void REQ_BLEEnhancedStart(S_BT_BLE_ENHANCED bt_ble);
    void REQ_BLEEnhancedStop(S_BT_BLE_ENHANCED bt_ble);




    META_RESULT Get_ConfirmState(void);
    void  (*ConfirmCallback)( void );
    void  Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd );




    void  REQ_BLE_START_HCI_command( void );
    void  REQ_BLE_STARTSTOP_HCI_command (void);
    void  REQ_Send_TxParameter_HCI_command( void );
    void  REQ_Send_RxParameter_HCI_command( void );
    void  REQ_BLE_RESET_HCI_command(void);
    void  REQ_BLE_ClearWhiteList_HCI_command(void);
    void  REQ_BLE_AddDeviceToWhiteList_HCI_command( void );
    void  REQ_BLE_RemoveDeviceToWhiteList_HCI_command( void );
    void  REQ_BLE_SetAdvertiseData_HCI_command(void);
    void  REQ_BLE_AdvertiseStart_HCI_command(void);
    void  REQ_BLE_AdvertiseEnable_HCI_command(void);
    void  REQ_BLE_AdvertiseStop_HCI_command(void);
    void  REQ_BLE_SetScanResponseData_HCI_command(void);
    void  REQ_BLE_ScanStart_HCI_command(void);
    void  REQ_BLE_ScanEnable_HCI_command(void);
    void  REQ_BLE_ScanStop_HCI_command(void);
    void  REQ_BLE_InitiateStart_HCI_command(void);
    void  REQ_BLE_InitiateStop_HCI_command(void);
    void  REQ_BLE_EnhancedStart_HCI_command(void);
    void  REQ_BLE_EnhancedStop_HCI_command(void);
    void  REQ_Send_EnhancedTxParameter_HCI_command(void);
    void  REQ_Send_EnhancedRxParameter_HCI_command(void);


    AnsiString
    GetBLEResult(void);

    void  Compose_Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void  Compose_Stop_HCI_Command(BT_HCI_COMMAND &hci_cmd );
    void  Compose_TxParameter_HCI_command( S_BT_BLE bt_ble_tx, BT_HCI_COMMAND &hci_cmd );
    void  Compose_RxParameter_HCI_command( S_BT_BLE bt_ble_rx, BT_HCI_COMMAND &hci_cmd );
    void  Compose_Clear_White_List_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void  Compose_AddDeviceToWhiteList_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd );
    void  Compose_RemoveDeviceToWhiteList_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd );
    void  Compose_SetAdvertiseData_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd );
    void  Compose_AdvertiseStart_HCI_Command (S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd);
    void  Compose_AdvertiseEnable_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    void  Compose_AdvertiseStop_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    void  Compose_SetScanResponseData_HCI_Command(S_BT_BLE_Normal bt_ble_normal ,BT_HCI_COMMAND &hci_cmd);
    void  Compose_ScanStart_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd);
    void  Compose_ScanEnable_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd);
    void  Compose_ScanStop_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd);
    void  Compose_InitiateStart_HCI_Command(S_BT_BLE_Normal bt_ble_normal,BT_HCI_COMMAND &hci_cmd);
    void  Compose_InitiateStop_HCI_Command(BT_HCI_COMMAND &hci_cmd);
    void  Compose_EnhancedTxParameter_HCI_command( S_BT_BLE_ENHANCED bt_ble_tx, BT_HCI_COMMAND &hci_cmd );
    void  Compose_EnhancedRxParameter_HCI_command( S_BT_BLE_ENHANCED bt_ble_rx, BT_HCI_COMMAND &hci_cmd );
    void  Compose_EnhancedStop_HCI_Command(BT_HCI_COMMAND &hci_cmd );

    void __stdcall CNF_SendTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_ResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_StopHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_CommonHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_TestResetHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendEnhancedTxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_SendEnhancedRxParameterHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void __stdcall CNF_EnhancedStopHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);



    void AddTxLogToStringList(BT_HCI_COMMAND hci_cmd);
    void AddRxLogToStringList(BT_HCI_EVENT hci_event);
    void AddNormalTxLogToStringList(BT_HCI_COMMAND hci_cmd);
    void AddNormalRxLogToStringList(BT_HCI_EVENT hci_event);

    void AddEnhancedTxLogToStringList(BT_HCI_COMMAND hci_cmd);
    void AddEnhancedRxLogToStringList(BT_HCI_EVENT hci_event);





};



#endif
