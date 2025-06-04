//---------------------------------------------------------------------------

#ifndef UUIDOpH
#define UUIDOpH

#include "meta.h"
#include "man_active.h"

#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

typedef enum
{
    STATE_READ_UUID_OK = 0,
    STATE_READ_UUID_FAILED,
    STATE_READ_UUID_TIMEOUT,
    STATE_READ_UUID_STOP,

    STATE_WRITE_UUID_OK = 4,
    STATE_WRITE_UUID_FAILED,
    STATE_WRITE_UUID_TIMEOUT,
    STATE_WRITE_UUID_STOP
} ConfirmType;

class UUIDOp
{
private:
    int   m_iConfirmState;
    CMETAHANDLE m_META_HANDLE_Obj;
    short        GETID_UUID;
    META_RESULT   MetaResult;
    unsigned int m_ihigh;
    unsigned int m_ilow;

protected:

public:
    UUIDOp( void );
    ~UUIDOp( void );
    void  Confirm( int confirm_state );
    void  (*ConfirmCallback)( void );

    unsigned int GetUUIDHigh(void)
    {
        return m_ihigh;
    }
    unsigned int GetUUIDLow(void)
    {
        return m_ilow;
    }
    void SetUUIDHigh(const unsigned int high)
    {
        m_ihigh = high;
    }
    void SetUUIDLow(const unsigned int low)
    {
        m_ilow = low;
    }

    void  ReadUUID(void);
    void  WriteUUID(const unsigned int high,const unsigned int low);

    void ReadUUID_Start(void);
    void WriteUUID_Start(void);
    // Global information
    int  Get_ConfirmState( void );

};
//---------------------------------------------------------------------------
#endif
