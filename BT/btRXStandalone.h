#ifndef  _BT_RXStandalone_H_
#define  _BT_RXStandalone_H_

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
    p0000 = 0x01,
    p1111 = 0x02,
    p1010 = 0x03,
    pseudo = 0x04,
    p11110000 = 0x09
} RXPattern;

typedef struct
{
    HANDLE hPostMsgDestHandle;
    TStringList *log;
    RXPattern pattern;
    AnsiString RXFrequency;
    int PXPackettype;
    AnsiString TesterAddress;
} S_BT_Standalone;

typedef struct
{
    unsigned int RX_Packet_Count;
    unsigned int RX_Error_Rate;
    unsigned int RX_Byte_Count;
    unsigned int Bit_Error_Rate;
} S_BT_Standalone_Result;

class  CBTRXStandalone
{

private:
    META_RESULT m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    S_BT_Standalone m_sBTStandalone;

protected:
    void  Confirm(META_RESULT confirm_state);

public:
    S_BT_Standalone_Result m_sRXStandalone_Result;
    void  (*ConfirmCallback)( void );
    META_RESULT Get_ConfirmState(void);
    CBTRXStandalone( void );
    ~CBTRXStandalone();


    void REQ_EnterTest(S_BT_Standalone  bt_std);
//    void REQ_ExitTest();
//    void REQ_ResetTest();
//qinqin 2012-02-01   fix show no log for sending ExitTest command and ResetTest command
    void REQ_ExitTest(S_BT_Standalone  bt_std);
    void REQ_ResetTest(S_BT_Standalone  bt_std);
//

    void REQ_EnterTest_HCI_command( void );
    void REQ_ExitTest_HCI_command( void );
    void REQ_ResetTest_HCI_command();

    void Reset_HCI_Command( BT_HCI_COMMAND &hci_cmd );
    void Compose_Reset_HCI_Command(BT_HCI_COMMAND &hci_cmd );
    void Compose_EnterTest_HCI_Command(BT_HCI_COMMAND &hci_cmd );
    void Compose_ExitTest_HCI_Command(BT_HCI_COMMAND &hci_cmd );


    void _stdcall CNF_ResetTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void _stdcall CNF_EnterTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);
    void _stdcall CNF_ExitTestHCIEvent(const BT_HCI_EVENT *cnf, const short token, void *usrData);

    // log
    void  AddTxLogToStringList(BT_HCI_COMMAND hci_cmd);
    void  AddRxLogToStringList(BT_HCI_EVENT hci_event);
};

#endif
