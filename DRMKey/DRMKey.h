#ifndef  _DRMKEY_H_
#define  _DRMKEY_H_
#include "LogicalControlBase.h"
#include "meta.h"
#include "man_handle.h"
#include <Classes.hpp>



class  CDRMKEY: public CLogicalControlBase
{
private:
    META_RESULT m_eConfirmState;
    DRMKEY_INSTALL_QUERY_CNF m_Cnf;

public:
    void (*ConfirmCallback)(void);
    bool ReadFromFile(AnsiString as);
    void Confirm(META_RESULT confirm_state);
    META_RESULT Get_ConfirmState(void);
    void REQ_DRMKeyInstall_Start(const AnsiString& file);
    void REQ_DRMKeyInstall(void);
    void REQ_DRMKeyQuery_Start(void);
    void REQ_DRMKeyQuery(void);
    bool GetDRMKeyQueryResult(char* strQueryResult);

    AnsiString m_file;



};

#endif
