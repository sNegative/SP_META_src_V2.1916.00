#ifndef LOCK_H_
#define LOCK_H_

#include <Windows.h>
//#include <vcl.h>
#pragma hdrstop

class CLocker
{
public:
      CLocker( CRITICAL_SECTION  &cs ):m_cs(cs) { EnterCriticalSection(&m_cs); }
      ~CLocker() {     LeaveCriticalSection(&m_cs); }
private:
      CRITICAL_SECTION  &m_cs;
};

#endif
