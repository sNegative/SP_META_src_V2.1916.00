#include <IniFiles.hpp>
#pragma hdrstop

#include "man_active.h"
#include "nvram_lock.h"

static CNVRAMLOCK*  nvram_lock_ptr;
static bool g_bIsRunning;

//===========================================================================
static void  REQ_NVRAMLock( void )
{
    nvram_lock_ptr->REQ_NVRAMLock( );
}


//------------------------------------------------------------------------------
static void  REQ_TimeOut( void )
{
    nvram_lock_ptr->REQ_TimeOut();
}

//------------------------------------------------------------------------------
static void  REQ_Finish( void )
{
    nvram_lock_ptr->REQ_Finish();
}

//===========================================================================
CNVRAMLOCK::CNVRAMLOCK( void )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;
    m_ConfirmState = 0;

}

//---------------------------------------------------------------------------
CNVRAMLOCK::~CNVRAMLOCK( )
{
    g_bIsRunning = false;
    ConfirmCallback = 0;

}

//---------------------------------------------------------------------------
void  CNVRAMLOCK::REQ_Finish( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_NVRAM_LOCK_OK );

}

//---------------------------------------------------------------------------
/*void  CNVRAMLOCK::REQ_Stop( void )
{
   if(!g_bIsRunning)  return;

   Confirm( STATE_NVRAM_LOCK_STOP );

} */

//---------------------------------------------------------------------------
void  CNVRAMLOCK::REQ_TimeOut( void )
{
    if(!g_bIsRunning)  return;

    Confirm( STATE_NVRAM_LOCK_TIMEOUT );

}

//---------------------------------------------------------------------------
void  CNVRAMLOCK::Confirm( int confirm_state )
{
    if(!g_bIsRunning)  return;
    g_bIsRunning = false;

    if(ConfirmCallback==0)  return;
    m_ConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//===========================================================================
void  CNVRAMLOCK::REQ_Start( void )
{
    nvram_lock_ptr = this;
    g_bIsRunning  = true;

    ActiveMan->SetActiveFunction( ::REQ_NVRAMLock );
}


//---------------------------------------------------------------------------
void  CNVRAMLOCK::REQ_NVRAMLock( void )
{
    if( ! g_bIsRunning )
    {
        Confirm( STATE_NVRAM_LOCK_FAIL );
        return;
    }

    META_RESULT  MetaResult = SP_META_NVRAM_LockDown_r( m_META_HANDLE_Obj.Get_MainHandle(), 500 );

    if(MetaResult!=META_SUCCESS)
    {
        if( MetaResult!=META_TIMEOUT )
        {
            Confirm( STATE_NVRAM_LOCK_FAIL );
            return;
        }
        else
        {
            Confirm( STATE_NVRAM_LOCK_TIMEOUT );
            return;
        }
    }

    ActiveMan->SetActiveFunction( ::REQ_Finish );
}

//===========================================================================
/////////////////////////////   Global information  /////////////////////////
//===========================================================================
int   CNVRAMLOCK::Get_ConfirmState( void )
{
    return m_ConfirmState;
}
