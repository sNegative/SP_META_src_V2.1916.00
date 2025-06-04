//---------------------------------------------------------------------------


#pragma hdrstop

#include "UUIDOp.h"

#pragma package(smart_init)

//==============================================================================
static UUIDOp  *uuidop_ptr;
static bool g_bIsRunning;
//---------------------------------------------------------------------------

static void ReadUUID_Start(void)
{
    uuidop_ptr->ReadUUID_Start();
}
static void WriteUUID_Start(void)
{
    uuidop_ptr->WriteUUID_Start();
}
//=============================================================================
UUIDOp::UUIDOp( void ):m_ihigh(0),m_ilow(0)
{
	  m_iConfirmState = 0;
	  GETID_UUID = 0;
	  ConfirmCallback = NULL;
}

//----------------------------------------------------------------------------
UUIDOp::~UUIDOp( void )
{
}
//---------------------------------------------------------------------------
void  UUIDOp::Confirm( int confirm_state )
{
    if(!g_bIsRunning)  return;

    if(ConfirmCallback==0)  return;
    m_iConfirmState = confirm_state;
    ActiveMan->SetActiveFunction( ConfirmCallback );
}

//------------------------------------------------------------------------------
void  UUIDOp::ReadUUID(void)
{
    uuidop_ptr = this;
    g_bIsRunning = true;
    ActiveMan->SetActiveFunction( ::ReadUUID_Start );
}
//------------------------------------------------------------------------------
void  UUIDOp::WriteUUID(const unsigned int high,const unsigned int low)
{
    uuidop_ptr = this;
    g_bIsRunning = true;
    m_ihigh = high;
    m_ilow = low;
    ActiveMan->SetActiveFunction( ::WriteUUID_Start );
}

void UUIDOp::ReadUUID_Start(void)
{
    if(!g_bIsRunning)  return;
    MetaResult = SP_META_ReadUuid_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,&m_ihigh,&m_ilow);
    if(MetaResult!=META_SUCCESS)
    {
        if(MetaResult == META_TIMEOUT)
        {
            Confirm( STATE_READ_UUID_TIMEOUT );
            return;
        }
        else
        {
            Confirm( STATE_READ_UUID_FAILED );
            return;
        }
    }

    Confirm( STATE_READ_UUID_OK );
}
//------------------------------------------------------------------------------

void UUIDOp::WriteUUID_Start(void)
{
    if(!g_bIsRunning)  return;
    MetaResult = SP_META_WriteUuid_r(m_META_HANDLE_Obj.Get_MainHandle(),5000,m_ihigh,m_ilow);
    if(MetaResult!=META_SUCCESS)
    {
        if(MetaResult == META_TIMEOUT)
        {
            Confirm( STATE_WRITE_UUID_TIMEOUT );
            return;
        }
        else
        {
            Confirm( STATE_WRITE_UUID_FAILED );
            return;
        }
    }

    Confirm( STATE_WRITE_UUID_OK );

}
//------------------------------------------------------------------------------

//===========================================================================
////////////////////////////  Global information  ///////////////////////////
//===========================================================================
int  UUIDOp::Get_ConfirmState( void )
{
    return  m_iConfirmState;
}
//----------------------------------------------------------------------------
