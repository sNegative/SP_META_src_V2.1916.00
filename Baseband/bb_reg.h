#ifndef  _BB_REG_H_
#define  _BB_REG_H_

#include "meta.h"
#include "man_handle.h"
#include "metaapp_common.h"

class CBBREG
{
private:
    META_RESULT m_eConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    short  m_sBBID_REG;
    unsigned int m_uiAddress;
    unsigned short m_usValue;
    unsigned int m_uibitCount;
    bool m_bCnfOk;
    HANDLE  m_hEvent;

protected:
    void  Confirm(META_RESULT confirm_state);

public:
    CBBREG(void);
    ~CBBREG();
    void  (*ConfirmCallback)( void );

//   void  REQ_Stop(void);
    void  REQ_ReadRegister_Start(unsigned int addr, unsigned int bitCount);
    void  REQ_WriteRegister_Start(unsigned int addr, unsigned int bitCount, unsigned short value);
    void  REQ_ReadRegister(void);
    void  REQ_WriteRegister(void);
    void __stdcall CNF_ReadRegister(const CPU_REG_READ_CNF *cnf, const short token, void *usrData);
    void __stdcall CNF_WriteRegister(const CPU_REG_WRITE_CNF *cnf, const short token, void *usrData);


    META_RESULT Get_ConfirmState(void);
    unsigned short Get_RegValue(void);
};
#endif
