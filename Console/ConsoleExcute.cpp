/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
*
*****************************************************************************/

#include "MfSetupUtil.h"
#include "ConsoleExcute.h"
#include "man_metadll.h"

#ifndef _FORM_MAIN_H_
#include "form_main.h"
#endif

#include "usb_info.h"
#ifndef META_DLL_H
#include "meta.h"
#endif


#include "man_active_boot.h"


using ConsoleMode::ConsoleExcute;
using ConsoleMode::CommandLineArguments;
bool g_ConsoleMode;
const int MAX_KERNEL_FILTER_COUNT = 10;
AnsiString g_asKernelFilterPIDVIDArray[MAX_KERNEL_FILTER_COUNT] = {0};
static CMETAHANDLE g_META_HANDLE_Obj;
AP_FT_NVRAM_READ_CNF m_sNVRAM_ReadCnf;
AP_FT_NVRAM_WRITE_CNF m_psNVRAM_WriteCnf;
bool writeFlag;

 void  SearchPreloaderUSB();

#define BOOT_STOP_C	9876

static ConsoleExcute * g_console_ptr;

ConsoleExcute::ConsoleExcute()
{
    m_bMetaDebugOn=false;
    p_Nvram_Test_Event=NULL;
}

ConsoleExcute::ConsoleExcute(CommandLineArguments *commandLineArguments)
{
    ConsoleExcute();
    SetCommandLine(commandLineArguments);
    g_console_ptr = this;
}

void ConsoleExcute::DebugOnOff(bool onoff)
{

    if(onoff)
    {
        AnsiString logPath = NULL;
        AnsiString bromLogFileName = NULL;
        logPath = read_LogPath(m_commandLineArguments->GetConfigFile(),  Application->ExeName);
        logPath = logPath + "\\";
        std::cout << "LogPath = "<<logPath.c_str()<< endl;
        m_bMetaDebugOn = true;
        SP_META_DebugOnThePath_ex(0,logPath.c_str());
        SP_META_DebugOnThePath_ex(1,logPath.c_str());
        SP_META_DebugClear();

        bromLogFileName = logPath +"BROM_DLL_V5.log";
        std::cout << "bromLogFileName = "<<bromLogFileName.c_str()<< endl;
        SP_Brom_Debug_SetLogFilename(bromLogFileName.c_str());
        SP_Brom_DebugOn();
        Logger::DebugOnPath(logPath.c_str());
        LOG("SP META tool debugging on.");
    }
    else
    {
        m_bMetaDebugOn = false;
        SP_META_DebugOff();
        SP_Brom_DebugOff();
        LOG("SP META tool debugging off.");
        Logger::DebugOff();
    }
}

void ConsoleExcute::Connect(bool setcomm,bool flagport)
{
    AnsiString m_ConnectType;
    unsigned int m_comnum;

    bool m_setcom =  false;
    m_stArg=new SP_BOOT_ARG_S();
    frmMainSel->Init();

    LOG("StartConnectTarget");

   // MetaDllMan->StartConnectTarget(false, true, false, 0, 0);

    //Sleep(1000*20);
    int i = 10;
    m_setcom = setcomm;
        
    m_ConnectType = read_Console_ConnectType(m_commandLineArguments->GetConfigFile(), Application->ExeName);

    std::cout << "Connect Test: Please plug in your phone!" << endl;

    if(m_ConnectType == "USB")
    {
        LOG(TAG_CONSOLE "Connect Test: Connect by USB ");
        m_isUSB = true;
        while(i--)
        {
            if(!SearchPreloaderUSB())
            {
                LOG(TAG_CONSOLE "Connect Test: Search Preloader/BROM USB Fail %d",i);
                if(i==0)
                {
                     std::cout << "Connect Test: Search Preloader/BROM USB Fail " << endl;
                     return;
                }
            }
            else
            {
                LOG(TAG_CONSOLE "Connect Test: Search Preloader/BROM USB Success. PortNumber=%d",m_stArg->m_uPortNumber);
                std::cout << "Connect Test: Search Preloader/BROM USB Success. PortNumber="<<m_stArg->m_uPortNumber<< endl;
                if(m_setcom ==true && m_pcom == m_stArg->m_uPortNumber)
                {
                    LOG(TAG_CONSOLE "Connect Test: Already Search the flag Preloader/BROM Port");
                    std::cout << "Connect Test: Already Search the flag Preloader/BROM Port"<< endl;
                    break;
                }
                else if(flagport == true)
                {
                   std::cout << "Connect Test: Please Flag Preloader/BROM Port. PortNumber="<< m_stArg->m_uPortNumber <<endl;
                   break;
                }
                else if(m_setcom == false)
                {
                    break;
                }
            }
        }//end while
        Sleep(1000);
    }//end if(m_ConnectType == "USB")
    else
    {
        LOG(TAG_CONSOLE "Connect by UART");
        std::cout << "Connect Test: Please power on your phone!" << endl;
        m_isUSB = false;
        m_comnum = m_ConnectType.ToInt();
        m_stArg->m_uPortNumber = m_comnum;
        eType = PreloaderUSB;
        std::cout << "Connect Test: COM Port Number "<<m_comnum<< endl;
    }

    SetMETAModeArg();

    if(!BootIntoMetaMode())
    {
        LOG(TAG_CONSOLE "Connect Test Fail: Boot Into Meta Mode Fail");
        std::cout << "Connect Test Fail: Boot Into Meta Mode Fail!" << endl;
        return;
    }
    else
    {
        LOG(TAG_CONSOLE "Connect Test: Boot Into Meta Mode Success");
        std::cout << "Connect Test: Boot Into Meta Mode Success!" << endl;
    }


    if(m_isUSB == true)
    {
        i = 10;
        while(i--)
        {
            if(!SerachKernelComport())
            {
                LOG(TAG_CONSOLE "Connect Test Fail: Search Kernel USB COM Port Fail!");
                std::cout << "Connect Test Fail: Search Kernel USB COM Port Fail!" << endl;
                if(i==0)
                {
                    std::cout << "Connect Test Fail: Search Kernel USB COM Port Fail" << endl;
                    return;
                }
            }
            else
            {
                LOG(TAG_CONSOLE "Connect Test: Search Kernel USB COM Port Success. PortNumber=%d",m_kernelUSB);
                std::cout << "Connect Test: Search Kernel USB COM Port Success. PortNumber= "<<m_kernelUSB<< endl;
                if(m_setcom == true && m_kcom == m_kernelUSB )
                {
                    LOG(TAG_CONSOLE "Connect Test: Already Search the flag Kernel Port");
                    std::cout << "Connect Test: Already Search the flag Kernel Port"<< endl;
                    break;
                }
                else if(flagport == true)
                {
                   std::cout << "Connect Test: Please Flag kernel Port. PortNumber="<< m_kernelUSB <<endl;
                   break;
                }
                else if(m_setcom == false)
                {
                    break;
                }
            }
        }//end while

        if(!ConnectInMetaModeByUSB())
        {
            std::cout << "Connect Test Fail: Connect Meta Mode by USB Fail!" << endl;
        }
        else
        {
            std::cout << "Connect Test Success: Connect Meta Mode by USB Success!" << endl;
            if(flagport == true)
            {
                std::cout << "Flag Com Port Success" << endl;
            }
        }
    }
    else
    {
        if(!ConnectInMetaModeByUART())
        {
                std::cout << "Connect Test Fail: Connect Meta Mode by UART Fail!" << endl;
        }
        else
        {
                std::cout << "Connect Test Success: Connect Meta Mode by UART Success!" << endl;
        }
    }

}

void ConsoleExcute::SetCommandLine(CommandLineArguments *commandLineArguments)
{
    m_commandLineArguments = commandLineArguments;
}

void ConsoleExcute::ExcuteCommand()
{
    LOG(TAG_CONSOLE "ExcuteCommand");
    DWORD wait_result;

    //Flag Com Port 
    if(m_commandLineArguments->GetFlagComPort())
    {
        std::cout << "[Flag Com Port]..." << endl;
        Connect(false,true);
    }
  
    //Connect 
    if(m_commandLineArguments->GetConnect())
    {
        std::cout << "[Connect Test]..." << endl;
        if(read_Console_ComFindType(m_commandLineArguments->GetConfigFile(), Application->ExeName)=="yes")
        {
            LOG(TAG_CONSOLE "Connect Test: Find com port by number=yes");
            m_pcom = read_Console_PreloaderComPort(m_commandLineArguments->GetConfigFile(),Application->ExeName).ToInt();
            m_kcom = read_Console_KernelComPort(m_commandLineArguments->GetConfigFile(),Application->ExeName).ToInt();
            LOG(TAG_CONSOLE "Connect Test: Already flag Preloader COM Port Number is %d",m_pcom);
            std::cout << "Connect Test: Already flag Preloader COM Port Number is "<<m_pcom<< endl;
            LOG(TAG_CONSOLE "Connect Test: Already flag Kernel COM Port Number is %d",m_kcom);
            std::cout << "Connect Test: Already flag Kernel COM Port Number is "<<m_kcom<< endl;
            Connect(true,false);
        }
        else
        {
            LOG(TAG_CONSOLE "Connect Test: Find com port by number=no");
            Connect(false,false);
        }

    }

     //Test Nvram
    if(m_commandLineArguments->GetNvramTest())
    {
        std::cout << "[Nvram Test]..." << endl;
        AnsiString m_NvramPath=read_Console_NvramDBPath(m_commandLineArguments->GetConfigFile(), Application->ExeName);
        OpenDatabaseCommon(m_NvramPath.c_str());

        AnsiString m_ModifyCount = read_Console_ModifyCount(m_commandLineArguments->GetConfigFile(), Application->ExeName);
        m_count = m_ModifyCount.ToInt();
        int count =  m_count;
        LOG(TAG_CONSOLE "ModifyCount=%d",m_count);
        while(count)
        {
            ModifyNvram(count);
            count--;
        }

 /*       wait_result = WaitForSingleObject( p_Nvram_Test_Event, 50000 );

        if (WAIT_TIMEOUT == wait_result)
        {
                LOG(TAG_CONSOLE "Nvram Test Fail: Test time out");
                std::cout << "Nvram Test Fail: Test time out" << endl;

        }
        else if(WAIT_OBJECT_0 == wait_result)
        {
            LOG(TAG_CONSOLE "Nvram Test Success");
            std::cout << "Nvram Test Success" << endl;
        }

        std::cout << "Nvram Test Complete" << endl;
        CloseHandle(p_Nvram_Test_Event);
  */

        while(1)
        {
            if(writeFlag==true)
            {
                writeFlag=false;
                std::cout << "Nvram Test Complete" << endl;
                break;
            }
            Sleep(200);
        }

        LOG(TAG_CONSOLE "Nvram Test Success");
        std::cout << "Nvram Test Success" << endl;

    }

 /*   if(m_commandLineArguments->GetRemoveDriver())
    {
        std::cout << "[Remove Broken Drivers ]..." << endl;
        HINSTANCE hInstance; 


        hInstance = ShellExecute(NULL, NULL, "DriverCheck.exe","-r" , NULL, SW_HIDE);
        //If the function(ShellExecute) fails, the return value is an error value that is less than or equal to 32.
        if ( (int)hInstance <= 32)
        {
            std::cout << "Check illegal port driver information and remove fail" << endl;
        }

        hInstance = ShellExecute(NULL, NULL, "DriverCheck.exe","-u" , NULL, SW_HIDE);
        //If the function(ShellExecute) fails, the return value is an error value that is less than or equal to 32.
        if ( (int)hInstance <= 32)
        {
            std::cout << "Check unclassed drivers and remove fail" << endl;
        }
    }
 */
    //Disconnect
    if(m_commandLineArguments->GetDisconnect())
    {
        std::cout << "[DisConnect Test]..." << endl;
        BackupNvram();
        Disconnect();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////

void ConsoleExcute::SetMETAModeArg()
{

    LOG(TAG_CONSOLE "Set Meta Mode parameter");
    CAUTH  m_cAuthObj;
    CSCERT  m_cScertObj;
    if(!m_cAuthObj.AUTH_Create())
    {
        LOG(TAG_CONSOLE "Create authentication handle fail");
    }

    if(!m_cScertObj.SCERT_Create())
    {
        LOG(TAG_CONSOLE "Create certificate handle fail");
    }

    m_stArg->m_bbchip_type = SP_AUTO_DETECT_BBCHIP;
    m_stArg->m_ext_clock = SP_AUTO_DETECT_EXT_CLOCK;
    m_stArg->m_ms_boot_timeout = SP_BOOT_INFINITE;
    m_stArg->m_max_start_cmd_retry_count = SP_DEFAULT_BROM_START_CMD_RETRY_COUNT;
    m_stArg->m_bIsUSBEnable = m_isUSB;
    m_stArg->m_bIsSymbolicEnable = false;
    m_stArg->m_bIsCompositeDeviceEnable = true;
    m_stArg->m_euBootMode = SP_META_BOOT;
    m_stArg->m_uTimeout = 20000;
    m_stArg->m_uRetryTime = 2000;
    m_stArg->m_uInterval = 10;
    m_stArg->m_uBaudrate = CBR_115200;
    m_stArg->m_auth_handle = m_cAuthObj.Get_AuthHandle();
    m_stArg->m_scert_handle = m_cScertObj.Get_ScertHandle();
    m_stArg->m_cb_sla_challenge = SLA_Challenge;
    m_stArg->m_cb_sla_challenge_arg = NULL;
    m_stArg->m_cb_sla_challenge_end = SLA_Challenge_END;
    m_stArg->m_cb_sla_challenge_end_arg = NULL;
    m_stArg->m_uMDMode = 0;
    m_stArg->m_pStopFlag = &BootStop;

    LOG(TAG_CONSOLE "Set Meta Mode parameter Done");
}
bool ConsoleExcute::FetchFilterPIDVID(char *start, char *result)
{
    char *end = NULL;
    if(start == NULL)
        return false;

    end = strstr( start, "/");
    if(end == NULL)
        end = start;
	
    if(end-start>0)
    {
        strncpy( result, start, end-start);
        result[end-start]='\0';
    }
    else if(end-start==0)
    {
        strncpy( result, start, strlen(start));
        result[strlen(start)]='\0';
    }
    else   // no data
    {
        result[0]='\0';
        return false;
    }
    return true;
}
void ConsoleExcute::Parse_KernelFilterPIDVID(char* pKernelFilterPIDVID,unsigned int nFilterCount,unsigned int& nFilterPIDVIDCount)
{
    if( pKernelFilterPIDVID == NULL)
    {
        return;
    }

    if( strlen(pKernelFilterPIDVID) == 0 || nFilterCount == 0)
    {
        nFilterPIDVIDCount = 0;
        return;
    }

    unsigned int nPIDVIDCount = 0;
    unsigned int i = 1;
    for(i=1; i< strlen(pKernelFilterPIDVID); i++)
    {
        if(pKernelFilterPIDVID[i] == '/')
        {
            nPIDVIDCount++;
        }
    }

    nFilterPIDVIDCount = nPIDVIDCount + 1;

    if( nFilterPIDVIDCount > MAX_KERNEL_FILTER_COUNT )
    {
        nFilterPIDVIDCount = MAX_KERNEL_FILTER_COUNT;
    }

    if( nFilterCount < nFilterPIDVIDCount )
    {
        nFilterPIDVIDCount = nFilterCount;
    }

    char* strParse = NULL;
    unsigned int nIndex = 0;
    char result[128] = {0};
    strParse = pKernelFilterPIDVID;
    for( nIndex = 0; nIndex < nFilterPIDVIDCount; nIndex++)
    {
        g_asKernelFilterPIDVIDArray[nIndex] = "";
        if(FetchFilterPIDVID(strParse,result))
        {
             g_asKernelFilterPIDVIDArray[nIndex] = result;
             if( nIndex != nFilterPIDVIDCount -1 )
             {
                 strParse = strstr( strParse, "/");
                 if(strParse != NULL)
                 {
                   strParse = strParse +1;
                 }
             }
        }
    }
}

int ConsoleExcute::SerachKernelComport()
{
    std::cout << "Connect Test: Seraching Kernel Comport..." << endl;

    SP_COM_FILTER_LIST_S sCOMFilter;
    SP_COM_PROPERTY_S sCOMProperty;
    int retFlashToolLib;
    AnsiString asSecondStageTimeout = read_SecondStage_Timeout(m_commandLineArguments->GetConfigFile(),Application->ExeName);
    unsigned int uTimeout = StrToInt(asSecondStageTimeout.c_str());

    AnsiString asKernelFilterCount = read_Kernel_Filter_Count(m_commandLineArguments->GetConfigFile(),Application->ExeName);
    AnsiString asKernelFilterType = read_Kernel_Filter_Type(m_commandLineArguments->GetConfigFile(),Application->ExeName);
    AnsiString asKernelFilterPIDVID = read_Kernel_Filter_PIDVID(m_commandLineArguments->GetConfigFile(),Application->ExeName);

    sCOMFilter.m_uCount = StrToInt(asKernelFilterCount.c_str());
    if(sCOMFilter.m_uCount > 10)
    {
        LOG("The Kernel Filter count value is 0~10,please reset the Kernel COM port filter count!");
        return false;
    }

    unsigned int nFilterPIDVIDCount = 0;
    char* ppFilter[10] = {0};
    Parse_KernelFilterPIDVID(asKernelFilterPIDVID.c_str(),sCOMFilter.m_uCount,nFilterPIDVIDCount);

    if( sCOMFilter.m_uCount > nFilterPIDVIDCount )
    {
        sCOMFilter.m_uCount = nFilterPIDVIDCount;
    }

    if( strcmp(asKernelFilterType.c_str(),"WhiteList") == 0 )
    {
        sCOMFilter.m_eType = SP_WHITE_LIST;
    }
    else
    {
        sCOMFilter.m_eType = SP_BLACK_LIST;
    }
    for(unsigned int i=0; i< sCOMFilter.m_uCount; i++)
    {
        ppFilter[i] = g_asKernelFilterPIDVIDArray[i].c_str();
        LOG(TAG_CONSOLE "ppFilter[%d]:%s",i,ppFilter[i]);
    }
    sCOMFilter.m_ppFilterID = ppFilter;


    retFlashToolLib = SP_GetIncrementCOMPortWithFilter(&sCOMFilter, &sCOMProperty, &GUID_PORT_CLASS_USB2SER, false, &BootStop, uTimeout/1000);
    switch(retFlashToolLib)
    {
        case SP_S_DONE:
            m_kernelUSB = sCOMProperty.m_uNumber;
            LOG("Search Kernel USB COM port success! Comport number = %d",m_kernelUSB);
            std::cout << "Connect Test: Kernel USB COM Port !" <<m_kernelUSB<< endl;
            break;
        case SP_S_STOP:
            return false;
        case SP_S_TIMEOUT:
        {
            LOG("Connect Test: Search Kernel USB COM port timout!");
            return false;
        }
        case SP_S_INVALID_ARGUMENTS:
        {
            LOG("Connect Test: Invalid arguments for searching COM port!");
            return false;
        }
        default:
        {
            LOG("Connect Test: Search Kernel USB COM port fail!");
            return false;
        }
    }

    return true;

}
int ConsoleExcute::ConnectInMetaModeByUART()
{
    std::cout << "Connecting Meta Mode by UART..." << endl;
    WM_META_ConnectInMETA_Req p_req;
    META_RESULT ret;
    WM_META_ConnectInMETA_Report META_connect_report;
    AnsiString as_METAConnectTimeout = read_META_Connect_timeout(m_commandLineArguments->GetConfigFile(), Application->ExeName);
    p_req.ms_connect_timeout= as_METAConnectTimeout.ToInt();
    g_META_HANDLE_Obj.REQ_AllocateMainHandle_Start();
    ret = SP_META_ConnectInMetaMode_r(g_META_HANDLE_Obj.Get_MainHandle(), &p_req, &BootStop, &META_connect_report);
    
    if((ret != META_SUCCESS) && (ret != META_MAUI_DB_INCONSISTENT) )
    {
        if(ret == META_STOP_BOOTUP_PROCEDURE)
        {
            LOG(TAG_CONSOLE "Connect Meta Mode by UART Stop");
            return false;
        }
        else
        {
            LOG(TAG_CONSOLE "Connect Meta Mode by UART Fail");
            return false;
        }
    }
    else
    {
        LOG(TAG_CONSOLE "Connect Meta Mode by UART Success");
        return true;
    }
}
int ConsoleExcute::ConnectInMetaModeByUSB()
{
    META_RESULT ret;
    META_ConnectByUSB_Req USBReq;
    META_ConnectByUSB_Report  USBReport;
    //Delay for target ready
    AnsiString asSecondStageDelay = read_SecondStage_Delay(m_commandLineArguments->GetConfigFile(),Application->ExeName);
    unsigned int uDelay = StrToInt(asSecondStageDelay.c_str());
    Sleep(uDelay);

    USBReq.com_port = m_kernelUSB;

    AnsiString as_METAConnectTimeout = read_META_Connect_timeout(m_commandLineArguments->GetConfigFile(), Application->ExeName);
    USBReq.ms_connect_timeout= as_METAConnectTimeout.ToInt();
    g_META_HANDLE_Obj.REQ_AllocateMainHandle_Start();
    ret = SP_META_ConnectInMetaModeByUSB_r(g_META_HANDLE_Obj.Get_MainHandle(), &USBReq, &BootStop, &USBReport);
    
    if((ret != META_SUCCESS) && (ret != META_MAUI_DB_INCONSISTENT) )
    {
        if(ret == META_STOP_BOOTUP_PROCEDURE)
        {
            LOG(TAG_CONSOLE "Connect Test Fail: Connect Meta Mode by USB Stop");
            return false;
        }
        else
        {
            LOG(TAG_CONSOLE "Connect Test Fail: Connect Meta Mode by USB Fail");
            return false;
        }
    }
    else
    {
        LOG(TAG_CONSOLE "Connect Meta Mode by USB Success");
        return true;
    }
}

int ConsoleExcute::SearchPreloaderUSB()
{
    std::cout << "Connect Test: Searching Preloader/BROM USB ..." << endl;
    SP_COM_FILTER_LIST_S m_sCOMFilter;
    SP_COM_PROPERTY_S m_sCOMProperty;
    char * m_ppFilter[4]={0};
    int iRet;
    bool guids[10]={0};
    MetaDllMan->METADLL_DisconnectWithTarget(false);

    //Get Filter                                             //m_commandLineArguments->GetConfigFile()
    AnsiString asBROMPortFilter = read_BROM_COMPort_Filter(m_commandLineArguments->GetConfigFile(),Application->ExeName);
    AnsiString asPreloaderSinglePortFilter = read_Preloader_Single_COMPort_Filter(m_commandLineArguments->GetConfigFile(),Application->ExeName);
    AnsiString asPreloaderCompositePortFilter = read_Preloader_Composite_COMPort_Filter(m_commandLineArguments->GetConfigFile(),Application->ExeName);

    m_ppFilter[0] = asPreloaderSinglePortFilter.c_str();
    m_ppFilter[1] = asPreloaderCompositePortFilter.c_str();
    m_ppFilter[2] = asBROMPortFilter.c_str();
    m_sCOMFilter.m_ppFilterID = m_ppFilter;

    m_sCOMFilter.m_eType = SP_WHITE_LIST;

    guids[0] = true;
    guids[1] = false;
    guids[2] = true;
    m_sCOMFilter.m_bInterface = guids;

    //Get Time Out
    LOG(TAG_CONSOLE "Get Time Out");
    AnsiString asFirstStageTimeout = read_FirstStage_Timeout(m_commandLineArguments->GetConfigFile(),Application->ExeName);
    unsigned int uTimout = StrToInt(asFirstStageTimeout.c_str())/1000;

    m_sCOMFilter.m_uCount = 3; //???

    AnsiString asDeviceType = read_DeviceType(m_commandLineArguments->GetConfigFile(),Application->ExeName);

    BootStop = SP_BOOT_INFINITE;

    //mark for build error
    //iRet = SP_GetCOMPortWithFilter(&m_sCOMFilter, &m_sCOMProperty, &BootStop, uTimout);

 /*   if( asDeviceType == "1" )  //Composite
    {
       iRet = SP_GetIncrementCOMPortWithFilter(&m_sCOMFilter, &m_sCOMProperty, NULL, false, &BootStop, uTimout) ;
    }
    else                       //Single
    {
        iRet = SP_GetIncrementCOMPortWithFilter(&m_sCOMFilter, &m_sCOMProperty, NULL, true, &BootStop, uTimout);
    }
 */
    if(0 == iRet)
    {
        switch(m_sCOMProperty.m_iFilterIndex)
        {
            case 0:
                LOG(TAG_CONSOLE "PreloaderUSB0");
                eType = PreloaderUSB;
                break;
            case 1:
                LOG(TAG_CONSOLE "PreloaderUSB1");
                eType = PreloaderUSB;
                break;
            case 2:
                LOG(TAG_CONSOLE "BootROMUSB");
                eType = BootROMUSB;
                break;
            default:
                LOG(TAG_CONSOLE "Search filter index error!");
                return false;
        }
    }
    else
    {
        switch(iRet)
        {
            case SP_S_STOP:
                LOG(TAG_CONSOLE "Search Preloader/BootROM USB COM port stop!");
                break;
            case SP_S_TIMEOUT:
                LOG(TAG_CONSOLE "Search Preloader/BootROM USB COM port timout!");
                break;
            case SP_S_INVALID_ARGUMENTS:
                LOG(TAG_CONSOLE "Invalid arguments for searching Preloader/BootROM USB COM port!");
                break;
            default:
                LOG(TAG_CONSOLE "Search Preloader/BootROM USB COM port fail!");
        }
        return false;
    }
    
    
    LOG(TAG_CONSOLE "Connect Test: Preloader COM Port Number %d",m_sCOMProperty.m_uNumber);
    std::cout << "Connect Test: Preloader COM Port Number "<<m_sCOMProperty.m_uNumber<< endl;
    m_stArg->m_uPortNumber = m_sCOMProperty.m_uNumber;
    return true;
}

int ConsoleExcute::BootIntoMetaMode()
{
 //3. Do META connection
    LOG(TAG_CONSOLE "BootIntoMetaMode");
    int iRet;

    if(BootROMUSB == eType)
    {
        iRet = SP_BootROM_BootMode(m_stArg);
        if(0 != iRet)
        {
            if(SP_S_STOP == iRet)
            {
                return false;
            }
            //isConnectFail = true;
            LOG("Connect Test Fail: Do handshake with BootROM fail", "Fail", MB_OK);
            std::cout << "Connect Test Fail: Do handshake with BootROM fail "<< endl;
            return false;
        }
    }
    else if(PreloaderUSB == eType)
    {
        iRet = SP_Preloader_BootMode(m_stArg);
        if(0 != iRet)
        {
            if(SP_S_STOP == iRet)
            {
                return false;
            }
            //isConnectFail = true;
            LOG("Do handshake with Preloader fail!", "Fail", MB_OK);
            std::cout << "Connect Test Fail: Do handshake with Preloader fail "<< endl;
            return false;
        }
    }
    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void ConsoleExcute::BackupNvram()
{
    SetCleanBootFlag_REQ 	m_SetCleanBootFlagReq;
    SetCleanBootFlag_CNF	m_SetCleanBootFlagCnf;
    m_SetCleanBootFlagCnf. drv_status = 0;
    
    META_RESULT mr = SP_META_SetCleanBootFlag_r(g_META_HANDLE_Obj.Get_MainHandle(), 6000, &m_SetCleanBootFlagReq, &m_SetCleanBootFlagCnf);
    if (mr)
    {
        LOG(TAG_CONSOLE "Disconnect Test Fail: Set clean boot flag fail");
        std::cout << "Disconnect Test Fail: Set clean boot flag fail" << endl;
    }
    else
    {
        LOG(TAG_CONSOLE "Disconnect Test: Set clean boot flag success");
        std::cout << "Disconnect Test: Set clean boot flag success" << endl;
    }
}

void ConsoleExcute::Disconnect()
{
    int iRet=0;
    iRet = SP_META_CloseComPortReboot_r(g_META_HANDLE_Obj.Get_MainHandle());
    if(iRet != META_SUCCESS)
    {
        LOG(TAG_CONSOLE "Disconnect Test Fail: SP_META_CloseComPortReboot_r return fail");
        std::cout << "Disconnect Test Fail: SP_META_CloseComPortReboot_r return fail" << endl;    
    }
    else
    {
        LOG(TAG_CONSOLE "Disconnect Test Success");
        std::cout << "Disconnect Test Success" << endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
static void  __stdcall CNF_ReadNVRAM( const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{
    g_console_ptr->CNF_ReadNVRAM( cnf, token, usrData);
}

void  ConsoleExcute::CNF_ReadNVRAM(const AP_FT_NVRAM_READ_CNF *cnf, const short token, void *usrData)
{
    m_sNVRAM_ReadCnf = *cnf;

    m_pcCustHwBuf = m_sNVRAM_ReadCnf.buf;
    m_iCustHwBufSize = m_sNVRAM_ReadCnf.len;
    
    if (cnf->status != NVRAM_STATUS_SUCCESS || cnf->read_status != 1)
    {
        LOG(TAG_CONSOLE "Nvram Test Fail: Read Nvram fail");
        std::cout << "Nvram Test Fail: Read Nvram fail" <<endl;
    }
    else
    {
        SetRecFieldValue();
        WriteNvram();
    }

}
static void  __stdcall CNF_WriteNVRAM( const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    g_console_ptr->CNF_WriteNVRAM( cnf, token, usrData);
}

 void  ConsoleExcute::CNF_WriteNVRAM( const AP_FT_NVRAM_WRITE_CNF *cnf, const short token, void *usrData)
{
    m_psNVRAM_WriteCnf = *cnf;

    if(cnf->status != NVRAM_STATUS_SUCCESS || cnf->write_status != 1)
    {
        LOG(TAG_CONSOLE "Nvram Test Fail: Write Nvram fail");
        std::cout << "Nvram Test Fail: Write Nvram fail" <<endl;
    }
    else
    {
        LOG(TAG_CONSOLE "Nvram Test: Write Nvram success");
        std::cout << "Nvram Test: Write Nvram success" <<endl;
    }

    m_count --;
    if(m_count == 0)
    {
        //p_Nvram_Test_Event = CreateEvent(NULL, FALSE, FALSE, NULL);
        //SetEvent(p_Nvram_Test_Event);
        writeFlag = true;
    }

}

void ConsoleExcute::SetRecFieldValue()
{
    META_RESULT MetaResult;
    g_console_ptr=this;

    MetaResult = SP_META_NVRAM_SetRecFieldValue( m_LID.c_str(),
                         as_str.c_str(),
                         m_pcCustHwBuf,
                         m_iCustHwBufSize,
                         &value,
                         sizeof(value));

     if(MetaResult!=META_SUCCESS)
     {
        LOG(TAG_CONSOLE "Nvram Test Fail : Set Nvram fail");
        std::cout << "Nvram Test Fail: Set Nvram fail" <<endl;
     }
     else
     {
        LOG(TAG_CONSOLE "Nvram Test: Set Nvram sucess");
     }
}
void ConsoleExcute::WriteNvram()
{
    META_RESULT MetaResult;
    short m_sNVRAM_OPID;
    g_console_ptr=this;
    unsigned short RID_para = 1;
    AP_FT_NVRAM_WRITE_REQ    *m_psNVRAM_WriteReq = new AP_FT_NVRAM_WRITE_REQ;
    m_psNVRAM_WriteReq->LID = m_LID.c_str();
    m_psNVRAM_WriteReq->RID = RID_para;
    m_psNVRAM_WriteReq->len = m_iCustHwBufSize;
    m_psNVRAM_WriteReq->buf = m_pcCustHwBuf;

    MetaResult = SP_META_NVRAM_Write_r(g_META_HANDLE_Obj.Get_MainHandle(),
                             m_psNVRAM_WriteReq,
                             ::CNF_WriteNVRAM,
                             &m_sNVRAM_OPID,
                             NULL);
    if(MetaResult!=META_SUCCESS)
    {
        LOG(TAG_CONSOLE "Nvram Test Fail: Write Nvram fail");
        std::cout << "Nvram Test Fail: Write Nvram fail" <<endl;
    }
    else
    {
        LOG(TAG_CONSOLE "Nvram Test Fail: Write Nvram sucess");
    }
}
void ConsoleExcute::ReadNvram()
{
    META_RESULT MetaResult;
    AP_FT_NVRAM_READ_REQ *m_psNVRAM_ReadReq = new AP_FT_NVRAM_READ_REQ;
    short m_sNVRAM_OPID;
    unsigned short RID_para = 1;
    
    if(META_SUCCESS != SP_META_NVRAM_GetRecLen(m_LID.c_str() , &m_iCustHwBufSize))
    {
        LOG(TAG_CONSOLE "Nvram Test Fail : Get NVRAM LID %s length fail",m_LID);
        std::cout << "Nvram Test Fail:  Get NVRAM LID %s length fail" <<m_LID.c_str()<<endl;
    }
     m_pcCustHwBuf = new  char[m_iCustHwBufSize];

     memset(m_pcCustHwBuf,'\0',m_iCustHwBufSize);
     m_psNVRAM_ReadReq->LID = m_LID.c_str();
     m_psNVRAM_ReadReq->RID = RID_para;

     m_sNVRAM_ReadCnf.len = m_iCustHwBufSize; //change name
     m_sNVRAM_ReadCnf.buf = m_pcCustHwBuf;

     //Get
     MetaResult = SP_META_NVRAM_Read_r(g_META_HANDLE_Obj.Get_MainHandle(),
                             m_psNVRAM_ReadReq,
                             &m_sNVRAM_ReadCnf,
                             ::CNF_ReadNVRAM,
                             &m_sNVRAM_OPID,
                             NULL);

     if(MetaResult!=META_SUCCESS)
     {
        LOG(TAG_CONSOLE "Nvram Test Fail :Read Nvram fail");
        std::cout << "Nvram Test Fail: Read Nvram fail" <<endl;
     }
     else
     {
        LOG(TAG_CONSOLE "Nvram Test: Read Nvram sucess");
        std::cout << "Nvram Test: Read Nvram sucess" <<endl;
     }
}

void ConsoleExcute::ModifyNvram(int id)
{
    META_RESULT MetaResult;


    m_LID=read_Console_ModifyLID(id,m_commandLineArguments->GetConfigFile(), Application->ExeName);
    if(m_LID==NULL)
    {
        LOG(TAG_CONSOLE "Nvram Test Fail: Read modify LID from config file fail");
        std::cout << "Nvram Test Fail: Read modify LID from config file fail" << endl;
    }
    else
    {
        LOG(TAG_CONSOLE "LID=%s",m_LID);
    }
    as_str=read_Console_ModifyVariable(id,m_commandLineArguments->GetConfigFile(), Application->ExeName);
    as_value=read_Console_ModifyValue(id,m_commandLineArguments->GetConfigFile(), Application->ExeName);

    value= (unsigned char)as_value.ToInt();

    ReadNvram();
}

 void CNF_NVRAMInitial( void )
{
    switch( NVRAMMan->Get_ConfirmState() )
    {
    case META_SUCCESS:
        LOG(TAG_CONSOLE "Execution success : Initial NVRAM database" );
        break;
    case META_FAILED:
        LOG(TAG_CONSOLE "Execution Failure : Initial NVRAM database" );
        break;
    case META_MAUI_DB_INCONSISTENT:
        LOG(TAG_CONSOLE "Execution Warning : NVRAM database and target load version is inconsistent");
        break;
    case META_TIMEOUT:
        LOG(TAG_CONSOLE "Execution Timeout : Initial NVRAM database" );
        break;
    case METAAPP_STOP:
        break;
    }
}

int ConsoleExcute::OpenDatabaseCommon(char* str )/// file path to db file
{
    AnsiString as_NVRAM_database_file_name;
    as_NVRAM_database_file_name = str;
    LOG(TAG_CONSOLE "The NVRAM database file name: %s", str);
    NVRAMMan->ConfirmCallback = ::CNF_NVRAMInitial;
    NVRAMMan->Init( str );
    META_RESULT state = NVRAMMan->Get_ConfirmState();
    if (META_SUCCESS != state )
    {
        if (META_MAUI_DB_INCONSISTENT == state )
        {
            LOG(TAG_CONSOLE "Nvram Test Fail: NVRAM database file is inconsistent with target load");
            std::cout << "Nvram Test Fail: NVRAM database file is inconsistent with target load" << endl;
        }
        else if (META_FILE_BAD == state)
        {
            LOG(TAG_CONSOLE "Nvram Test Fail: Load NVRAM database file fail");
            std::cout << "Nvram Test Fail: Load NVRAM database file fail" << endl;
        }
        else
        {
            LOG(TAG_CONSOLE "Nvram Test Fail: Initialize NVRAM database file fail");
            std::cout << "Nvram Test Fail: Initialize NVRAM database file fail" << endl;
        }
    }
    else
    {
        LOG(TAG_CONSOLE "Nvram Test: Initialize NVRAM database file success");
        std::cout << "Nvram Test: Initialize NVRAM database file success" << endl;
    }
    return 0;
}





