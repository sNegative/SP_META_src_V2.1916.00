/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
*
*****************************************************************************/
#include <vcl.h>
#pragma hdrstop

#include <atlbase.h>
#include <exception>
#include <iostream>
#include <string> 

#include "Logger.h"
#include "Utility.h"
#include "ConsoleMode.h"

extern bool g_ConsoleMode;

namespace ConsoleMode
{
    int Run(const std::string &commandLine)
    {
        g_ConsoleMode = true;
        
        const DWORD parentProcessID = GetParentProcessId();

        if (parentProcessID == 0)
        {
            Logger::GetLogger()<<Logger::Error<<endl
                <<"[console mode fail] return 1"<<endl;
            return 1;
        }

        if (!AttachConsole(parentProcessID))
        {
            Logger::GetLogger()<<Logger::Error<<endl
                <<"[console mode fail] return 2, process ID: "<<parentProcessID
                <<endl;
                return 2;
        }

        try
        {
            USES_CONVERSION;
            //Logger::DebugOn();
            commandLineArguments=new CommandLineArguments(A2CW(commandLine.c_str()));
            consoleExcute=new ConsoleExcute(commandLineArguments);
            consoleExcute->DebugOnOff(true);
            consoleExcute->ExcuteCommand();
            consoleExcute->DebugOnOff(false);
            //Logger::DebugOff();

            Sleep(3000);
        }
        catch (std::exception &ex)
        {
            LOG(ex.what());
            return 4;
        }
        catch (Exception &ex)
        {
            LOG(ex.Message.c_str());
            return 5;
        }
        return 0;
    }

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


}
