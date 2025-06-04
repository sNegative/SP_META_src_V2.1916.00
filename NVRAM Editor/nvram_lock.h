#ifndef  _NVRAM_LOCK_H_
#define  _NVRAM_LOCK_H_
#include "meta.h"
#ifndef  _MAN_HANDLE_H_
#include "man_handle.h"
#endif

#define  STATE_NVRAM_LOCK_OK          0
#define  STATE_NVRAM_LOCK_FAIL        1
#define  STATE_NVRAM_LOCK_TIMEOUT     2
#define  STATE_NVRAM_LOCK_STOP        3

class  CNVRAMLOCK
{
private:
    CMETAHANDLE m_META_HANDLE_Obj;
    int   m_ConfirmState;



protected:
public:


    void  Confirm( int confirm_state );



    CNVRAMLOCK( void );
    ~CNVRAMLOCK( );

    void  REQ_Finish( void );
    void  REQ_TimeOut( void );


    void  (*ConfirmCallback)( void );


    void  REQ_Start( void );
    void  REQ_Stop( void );
    void  REQ_NVRAMLock( void );


    // global information
    int   Get_ConfirmState();


};

/*---------------------------------------------------------------------------*/
#endif
