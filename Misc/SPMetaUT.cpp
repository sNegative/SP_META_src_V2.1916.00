/*
 * SPMetaUT.cpp
 *
 *  Created on: Aug 16, 2011
 *      Author: MTK81019
 */

#include "SPMetaUT.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "meta.h"
#include "Logger.h"

namespace UnitTest
{

struct PROCESS_BASIC_INFORMATION
{
    PVOID Reserved1;
    void* PebBaseAddress;
    PVOID Reserved2[2];
    ULONG_PTR UniqueProcessId;
    ULONG_PTR ParentProcessId;
};

// GetParentProcessId will use the NtQueryInformationProcess function
// exported by NtDll to retrieve the parent process id for the current
// process and if for some reason it doesn't work, it returns 0
DWORD GetParentProcessId()
{
    // Much easier in ASM but C/C++ looks so much better
    typedef ULONG NTSTATUS;
    typedef NTSTATUS (WINAPI *pNtQueryInformationProcess)
    (HANDLE ,UINT ,PVOID ,ULONG , PULONG);

    // Some locals
    PROCESS_BASIC_INFORMATION pbi;
    ZeroMemory(&pbi, sizeof(PROCESS_BASIC_INFORMATION));

    // Get NtQueryInformationProcess
    pNtQueryInformationProcess NtQIP = (pNtQueryInformationProcess)
                                       GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")),
                                               "NtQueryInformationProcess");

    // Sanity check although there's no reason for it to have failed
    if (NtQIP == 0)
    {
        return 0;
    }

    // Now we can call NtQueryInformationProcess, the second
    // param 0 == ProcessBasicInformation
    NTSTATUS status = NtQIP(GetCurrentProcess(), 0, (void*) &pbi,
                            sizeof(PROCESS_BASIC_INFORMATION), 0);

    if (status != 0x00000000)
    {
        return 0;
    }
    else
    {
        return pbi.ParentProcessId;
    }
}

SPMetaUT::SPMetaUT()
{
    SP_META_DebugOn();
    Logger::DebugOn();
    LOG("SP META tool debugging on.");

    const DWORD parentProcessID = GetParentProcessId();

    if (parentProcessID == 0)
    {
        LOG("GetParentProcessId failed.");
        return;
    }
    if (!AttachConsole(parentProcessID))
    {
        LOG("AttachConsole(%d) failed.",parentProcessID);
        return;
    }
}

SPMetaUT::~SPMetaUT()
{
    // TODO Auto-generated destructor stub
}

int SPMetaUT::Execute()
{
    std::cout<<"\r\nSP META tool Unit Test\r\n"<<std::endl;
    return 0;
}

} /* namespace UnitTest */
