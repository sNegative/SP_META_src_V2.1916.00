#include "CommandExecutor.h"

#include <fstream>
#include <string>
#include "Logger.h"


CommandExecutor::CommandExecutor(const std::string& command,
                                 const std::string& outputFile)
    : mCommand(command), mOutFile(outputFile), mLastErr(0), mExitCode(0)
{
}

CommandExecutor::~CommandExecutor()
{
    mCommand = "";
    mOutFile = "";
    mLastErr = 0;
    mExitCode = 0;
}

bool CommandExecutor::Execute()
{
    PROCESS_INFORMATION piProcInfo;
    HANDLE h = INVALID_HANDLE_VALUE;
    STARTUPINFO siStartInfo;
    siStartInfo.cb = sizeof(STARTUPINFO);
    siStartInfo.lpTitle = NULL;
    siStartInfo.lpReserved = NULL;
    siStartInfo.lpReserved2 = NULL;
    siStartInfo.cbReserved2 = 0;
    siStartInfo.lpDesktop = NULL;
    siStartInfo.dwFlags = 0;
    ////////////
    _SECURITY_ATTRIBUTES  sec;
    sec.bInheritHandle = TRUE;
    sec.lpSecurityDescriptor = NULL;

    LOG(mOutFile.c_str());
    /////////////
    h = CreateFile( mOutFile.c_str(),
                    GENERIC_READ | GENERIC_WRITE,// open for reading and writing
                    FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                    &sec, //   <---------------------------------------------------
                    CREATE_ALWAYS, //
                    FILE_ATTRIBUTE_NORMAL, // normal file
                    NULL );

    LOG("the file handle is %d", h);
    if(h == INVALID_HANDLE_VALUE)
    {
        /*        SetFilePointer(h, 0L, NULL, FILE_END);
                siStartInfo.dwFlags |= STARTF_USESTDHANDLES;
                siStartInfo.hStdOutput = h;
                siStartInfo.hStdError = h;  */
        return false;
    }

    ZeroMemory(&siStartInfo, sizeof(siStartInfo));
    siStartInfo.cb = sizeof(siStartInfo);
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;
    // siStartInfo.dwFlags      =   STARTF_USESHOWWINDOW;
    siStartInfo.wShowWindow  =   SW_HIDE;
    siStartInfo.hStdOutput = h;
    siStartInfo.hStdError = h;
    // ----- Create the child process.
    BOOL pSuccess = CreateProcess(
                        NULL, // Application name
                        const_cast<LPSTR>(mCommand.c_str()), // command line
                        NULL, // process security attributes
                        NULL, // primary thread security attributes
                        TRUE, // handles are inherited
                        CREATE_NO_WINDOW,// creation flags
                        NULL, // use parent's environment
                        NULL, // use parent's current directory
                        &siStartInfo, // STARTUPINFO pointer
                        &piProcInfo); // receives PROCESS_INFORMATION

    DWORD dwExitCode;
    if(pSuccess)
    {
        ResumeThread(piProcInfo.hThread);
        CloseHandle(piProcInfo.hThread);
        WaitForSingleObject(piProcInfo.hProcess, INFINITE);
        GetExitCodeProcess(piProcInfo.hProcess, &dwExitCode);
        CloseHandle(piProcInfo.hProcess);
        //Error = (dwExitCode == 0) ? false : true;
        mExitCode = dwExitCode;
    }

    else
    {
        mLastErr = GetLastError();
    }

    if(h != INVALID_HANDLE_VALUE)
        CloseHandle(h);

    LOG("pSuccess is %d", pSuccess);
    LOG("dwExitCode is %d", dwExitCode);

    return pSuccess && (mExitCode==0);
}