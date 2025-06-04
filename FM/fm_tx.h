#ifndef  _FM_TX_H_
#define  _FM_TX_H_

// common
#ifndef  _METAAPP_COMMON_H_
#include "metaapp_common.h"
#endif

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#ifndef  _TIME_UTILS_H_
#include "time_utils.h"
#endif


class CFMTX
{
private:
    // common
    CMETAHANDLE m_META_HANDLE_Obj;
    META_RESULT   m_eConfirmState;

    FM_FREQ_REQ_T m_sFMFreq;
    FM_WRITE_BYTE_REQ_T m_sFMWrite;

protected:
public:

    void Confirm(META_RESULT confirm_state);

    CFMTX(void);
    ~CFMTX();

    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    void  (*ConfirmCallback)(void);

    void REQ_FM_TxPowerOn(void);
    void REQ_FM_TxPowerOff(void);
    void REQ_Set_Freq(void);
    void REQ_Write_Byte(void);


    void REQ_FM_TxPowerOn_Start(void);
    void REQ_FM_TxPowerOff_Start(void);
    void REQ_Set_Freq_Start(FM_FREQ_REQ_T freq);
    void REQ_Write_Byte_Start(FM_WRITE_BYTE_REQ_T byte);



    META_RESULT Get_ConfirmState(void);
};

/*---------------------------------------------------------------------------*/
#endif
