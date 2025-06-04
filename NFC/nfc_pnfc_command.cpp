#ifndef  _NFC_PNFC_COMMAND_H_
#include "nfc_pnfc_command.h"
#endif

#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

static CNFCPNFCCOMMAND *g_nfcPNFCCommand_ptr;

bool CNFCPNFCCOMMAND::REQ_PNFC_Command_Start(NFC_EM_PNFC_REQ_S *pnfc_command_Req, NFC_EM_PNFC_CNF_S *pnfc_command_Cnf)
{

    META_RESULT MetaResult = SP_META_NFC_PNFC_COMMAND_r(m_META_HANDLE_Obj.Get_MainHandle(),
       10000, pnfc_command_Req, pnfc_command_Cnf);

    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            return false;
        }
        else if( META_CANCEL == MetaResult )
        {
            return false;
        }
        else
        {
            return false;
        }
    }
    if(m_nfc_pnfc_cnf.result)
    {
        return false;
    }
    else
    {
        return true;
    }
}
