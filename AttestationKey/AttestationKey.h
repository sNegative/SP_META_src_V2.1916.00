#ifndef  _ATTESTATIONKEY_H_
#define  _ATTESTATIONKEY_H_
#include "LogicalControlBase.h"
#include "meta.h"
#include "man_handle.h"
#include <Classes.hpp>



class  CAttestationKey: public CLogicalControlBase
{
private:
    META_RESULT m_eConfirmState;

public:
    void (*ConfirmCallback)(void);
    void Confirm(META_RESULT confirm_state);
    META_RESULT Get_ConfirmState(void);
    void REQ_AttestationKeyInstall_Start(const AnsiString& file);
    void REQ_AttestationKeyInstall(void);

    AnsiString m_file;



};

#endif
