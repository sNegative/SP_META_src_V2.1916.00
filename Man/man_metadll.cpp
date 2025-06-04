#include <vcl.h>
#include <SyncObjs.hpp>

#pragma hdrstop

#include "form_main.h"
#include "man_active_boot.h"
#include "man_metadll.h"
#include "misc.h"



#ifndef  _USB_COM_COMMON_H_
#include "usb_com_common.h"
#endif
#include <objbase.h>
#include <initguid.h>
#include <string>
#include <iostream>
#include <sstream>
#include "usb_info.h"
#include "interface.h"
#include "Logger.h"
#include <algorithm>


#include <string>
#include <vector>
#include <set>
//---------------------------------------------------------------------------

//-- for Meta Factory ----//
HANDLE       hCOM;
//---------------------------------------------------------------------------
CMetaDllMan *MetaDllMan;
extern TfrmMainSel *frmMainSel;
static CMetaDllMan*  metadllman_ptr;
//rongguo 2011-11-10
char buf[2048];

extern int g_nConnectMode;

bool ConnectTargetok = false;
bool isBootTarget = false;
bool isConnectTarget = false;
bool isMETAInit = false;
bool g_bMetaCommStart = false;
bool isEndExcuted = 0x00;
bool IsRunning = false;
HANDLE p_METADLL_Connect_Event;
bool isFirstOpenComErr = true;
static CMETAHANDLE g_META_HANDLE_Obj;

volatile bool isConnectFail = false;

// connect in META mode
extern WM_META_ConnectInMETA_Req g_ConnectInMETA_Req;
extern WM_META_ConnectInMETA_Report g_ConnectInMETA_Report;

bool m_isUSB;
bool m_isMetaMode;
bool m_isLegacyAutoDetection;
bool m_isCompositeUSB;
bool m_isMDlogging;
bool m_bDisableUartlog;
int m_comnum;
std::string   s_com_symbol;
std::string   s_com_symbol_tst;
std::set<std::string> m_exist_com_port_str;
std::set<std::string> m_exist_com_port_str_tst;

//Qin Qin 20120718
const int MAX_KERNEL_FILTER_COUNT = 10;
AnsiString g_asKernelFilterPIDVIDArray[MAX_KERNEL_FILTER_COUNT] = {0};

//20130417
const int PRELOADER_COM_FILTER_COUNT = 2;     //include single preloader and composite preloader com port
const int PRELOADER_BROM_COM_FILTER_COUNT = 3;     //include single preloader and composite preloader com port and BootROM com port

// Wei Fang 2012-10-30 add for connect time show in UI
LARGE_INTEGER litmp;
LONGLONG qt1,qt2;
double dft,dff,dfm;
char *filename = "c:\\Time_Test.txt";
FILE *fs;
char strTime[10] = {0};

const  double EPSINON = 0.000001; //

typedef enum
{
    BootROMUSB,
    PreloaderUSB,
    KernalUSB
} USBType;
//---------------------------------------------------------------------------
//void scan_exist_com_port_str(std::set<std::string>  &exist_com_ports_str /*out*/,char * PID_Scan,char * VID_Scan,GUID guid,int USBType)
/*{
    unsigned long	device_number = 0;
    char			device_path[512];
    unsigned long	path_real_length;
    char			friend_name[512];
    unsigned long	friend_name_real_length;

//	int iLastDel=0;
//	int nCom=0;

    device_number =  GetDeviceNumber(guid, PID_Scan, VID_Scan);

    if( device_number == 0)
    {
        return;
    }

    for(unsigned int i=0; i<device_number; i++)
    {
        if(GetPresentDevicePath(guid, PID_Scan, VID_Scan, i,
                                friend_name, 512, (unsigned long *) &friend_name_real_length,
                                device_path, 512, (unsigned long *) &path_real_length))

        {
            if(USBType==PreloaderUSB)
            {
                exist_com_ports_str.insert(device_path);
            }
            else if(USBType==KernalUSB)
            {
                exist_com_ports_str.insert(friend_name);
            }
        }
    }
}
//---------------------------------------------------------------------------
bool get_new_created_com_port_str(std::string &usb_com_port_str,
                                  std::set<std::string> &exist_com_port_str,char * PID_Scan,char * VID_Scan,GUID guid,int USBType)
{
    std::set<std::string>       current_exist_com_port_str;
    std::vector<std::string>::iterator  it_last_result_str;
    std::string   result_port_str_test[10];
    //char log[128];

    //Get current exist com port
    scan_exist_com_port_str(current_exist_com_port_str,PID_Scan,VID_Scan,guid,USBType);

    it_last_result_str = set_difference(current_exist_com_port_str.begin(), current_exist_com_port_str.end(),
                                        exist_com_port_str.begin(), exist_com_port_str.end(),
                                        result_port_str_test);

    if(result_port_str_test == it_last_result_str)
    {
        return false;
    }

    usb_com_port_str =  *result_port_str_test;

    return true;
} */
//---------------------------------------------------------------------------
//Qin Qin 20120712
bool FetchFilterPIDVID(char *start, char *result)
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
//---------------------------------------------------------------------------
//pKernelFilterPIDVID: input parameter
//nFilterCount: input parameter
//nFilterPIDVIDCount:output parameter
//It will update g_asKernelFilterPIDVIDArray which is for kernel com port filter PIDVID.
void Parse_KernelFilterPIDVID(char* pKernelFilterPIDVID,unsigned int nFilterCount,unsigned int& nFilterPIDVIDCount)
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
//
//---------------------------------------------------------------------------
void  METADLL_Connect(WM_META_ConnectInMETA_Req* p_req, int* BootStop, WM_META_ConnectInMETA_Report* META_connect_report)
{
    int retFlashToolLib;
    META_RESULT ret;
    if(m_isUSB==true)
    {
        //unsigned short usbPort;
        META_ConnectByUSB_Req USBReq;
        META_ConnectByUSB_Report  USBReport;

        //Use USB port, necessary to scan
        SP_COM_FILTER_LIST_S sCOMFilter;
        SP_COM_PROPERTY_S sCOMProperty;
        AnsiString asBROMPortFilter = read_BROM_COMPort_Filter("MF_setup.txt",Application->ExeName);
        AnsiString asPreloaderPortFilter = read_Preloader_Single_COMPort_Filter("MF_setup.txt",Application->ExeName);
        AnsiString asSecondStageTimeout = read_SecondStage_Timeout("MF_setup.txt",Application->ExeName);
        unsigned int uTimeout = StrToInt(asSecondStageTimeout.c_str());
        /*char * ppFilter[2];

        ppFilter[0] = asPreloaderPortFilter.c_str();
        ppFilter[1] = asBROMPortFilter.c_str();
        sCOMFilter.m_uCount = 2;
        sCOMFilter.m_eType = SP_BLACK_LIST;
        sCOMFilter.m_ppFilterID = ppFilter;  */

        //Qin Qin 20120711
        AnsiString asKernelFilterCount = read_Kernel_Filter_Count("MF_setup.txt",Application->ExeName);
        AnsiString asKernelFilterType = read_Kernel_Filter_Type("MF_setup.txt",Application->ExeName);
        AnsiString asKernelFilterPIDVID = read_Kernel_Filter_PIDVID("MF_setup.txt",Application->ExeName);

        sCOMFilter.m_uCount = StrToInt(asKernelFilterCount.c_str());
        if(sCOMFilter.m_uCount > MAX_KERNEL_FILTER_COUNT)
        {
            Application->MessageBox("The Kernel Filter count value is 0~10,please reset the Kernel COM port filter count!", "Fail", MB_OK);
            return;
        }

        unsigned int nFilterPIDVIDCount = 0;
        char* ppFilter[MAX_KERNEL_FILTER_COUNT] = {0};
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
            LOG("ppFilter[%d]:%s",i,ppFilter[i]);
        }
        sCOMFilter.m_ppFilterID = ppFilter;
        //

        retFlashToolLib = SP_GetIncrementCOMPortWithFilter(&sCOMFilter, &sCOMProperty, &GUID_PORT_CLASS_USB2SER, false, BootStop, uTimeout/1000);
        switch(retFlashToolLib)
        {
        case SP_S_DONE:
            USBReq.com_port = sCOMProperty.m_uNumber;
            break;
        case SP_S_STOP:
            return;
        case SP_S_TIMEOUT:
        {
            isConnectFail = true;
            Application->MessageBox("Search Kernel USB COM port timout!", "Fail", MB_OK);


            return;
        }
        case SP_S_INVALID_ARGUMENTS:
        {
            isConnectFail = true;
            Application->MessageBox("Invalid arguments for searching COM port!", "Fail", MB_OK);
            return;
        }
        default:
        {
            isConnectFail = true;
            Application->MessageBox("Search Kernel USB COM port fail!", "Fail", MB_OK);

            return;
        }
        }


        //Delay for target ready
        AnsiString asSecondStageDelay = read_SecondStage_Delay("MF_setup.txt",Application->ExeName);
        unsigned int uDelay = StrToInt(asSecondStageDelay.c_str());
        Sleep(uDelay);

        USBReq.ms_connect_timeout = p_req->ms_connect_timeout;
        ret = SP_META_ConnectInMetaModeByUSB_r(g_META_HANDLE_Obj.Get_MainHandle(), &USBReq, BootStop, &USBReport);
    }
    else
    {
        ret = SP_META_ConnectInMetaMode_r(g_META_HANDLE_Obj.Get_MainHandle(), p_req, BootStop, META_connect_report);
    }


    if((ret != META_SUCCESS) && (ret != META_MAUI_DB_INCONSISTENT) )
    {
        if(ret == META_STOP_BOOTUP_PROCEDURE)
        {
            return;
        }
        else
        {
            isConnectFail = true;
            Application->MessageBox("Connect with target fail", "Fail", MB_OK);

        }
    }
    else
    {
        QueryPerformanceCounter(&litmp);
        qt2=litmp.QuadPart;
        dfm=(double)(qt2-qt1);
        if(!(dff < EPSINON  && dff > - EPSINON))
        {
            dft=dfm/dff;
        }
        else
        {
            dft = 0.0;
        }

        sprintf(strTime,"%.3lf sec",dft);
        ConnectTargetok = true;

        if(ret == META_MAUI_DB_INCONSISTENT)
        {
             Application->MessageBox( "Execution Warning : NVRAM database file is inconsistent with target load", "WARNING", MB_OK );
        }
    }
}
//---------------------------------------------------------------------------
void METADLL_Connect_Thread()
{
    METADLL_Connect(&g_ConnectInMETA_Req, &(frmMainSel->BootStop),&g_ConnectInMETA_Report);
    SetEvent(p_METADLL_Connect_Event);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void METADLL_ConnectInMetaMode(WM_META_ConnectInMETA_Req* p_req, int* BootStop, WM_META_ConnectInMETA_Report* META_connect_report)
{
    SP_BOOT_ARG_S stArg;
    int iRet;
    //int iAuthLoaded;
    USBType eType;
    AnsiString asDeviceType = "0";

    //1. Get META arguments
    frmMainSel->SetMETAArg();
    memcpy(&stArg, frmMainSel->GetMETAArg(), sizeof(SP_BOOT_ARG_S));
    stArg.m_pStopFlag = BootStop;
    *BootStop = SP_BOOT_INFINITE;
    stArg.m_bIsUSBEnable = m_isUSB;
    stArg.m_bIsSymbolicEnable = false;
    stArg.m_bIsCompositeDeviceEnable = m_isCompositeUSB;
    stArg.m_bDisableMobileLogService = frmMainSel->m_bDisableMobileLog;
    stArg.m_bMDlogging = m_isMDlogging;
    stArg.m_bUartLogDisable = m_bDisableUartlog;
    stArg.m_uMDMode = 0; 


    stArg.m_euBootMode = SP_META_BOOT;

    //2. Set COM port for META connection
    if(!m_isUSB)
    {
        //Use UART port, unnecessary to scan
        stArg.m_uPortNumber = m_comnum;
        //When user select Authentication file or Certificate file, it means it is security chip
        //For security chip, we should use BROM connect in to meta mode
        if ((frmMainSel->m_bOpenAuthenticationfile == true) || (frmMainSel->m_bOpenCertificatefile == true))
        {
            LOG("BootROM UART connection");
            eType = BootROMUSB;
        }
        else
        {
            LOG("preloader UART connection");
            eType = PreloaderUSB;
        }
    }
    else
    {
        //Use USB port, necessary to scan
        SP_COM_FILTER_LIST_S sCOMFilter;
        SP_COM_PROPERTY_S sCOMProperty;
        AnsiString asBROMPortFilter = read_BROM_COMPort_Filter("MF_setup.txt",Application->ExeName);
        AnsiString asPreloaderSinglePortFilter = read_Preloader_Single_COMPort_Filter("MF_setup.txt",Application->ExeName);
        AnsiString asPreloaderCompositePortFilter = read_Preloader_Composite_COMPort_Filter("MF_setup.txt",Application->ExeName);
        AnsiString asFirstStageTimeout = read_FirstStage_Timeout("MF_setup.txt",Application->ExeName);
        asDeviceType = read_DeviceType("MF_setup.txt",Application->ExeName);
        unsigned int uTimout = StrToInt(asFirstStageTimeout.c_str());
        char * ppFilter[3];

        ppFilter[0] = asPreloaderSinglePortFilter.c_str();
        ppFilter[1] = asPreloaderCompositePortFilter.c_str();
        ppFilter[2] = asBROMPortFilter.c_str();
        //sCOMFilter.m_uCount = (m_isLegacyAutoDetection) ? 1: 2;
        sCOMFilter.m_uCount = (m_isLegacyAutoDetection) ? PRELOADER_COM_FILTER_COUNT: PRELOADER_BROM_COM_FILTER_COUNT;
        sCOMFilter.m_eType = SP_WHITE_LIST;
        sCOMFilter.m_ppFilterID = ppFilter;

        //iRet = SP_GetNewCOMPortWithFilter(&sCOMFilter, &sCOMProperty, NULL, BootStop);
        //iRet = SP_GetIncrementCOMPortWithFilter(&sCOMFilter, &sCOMProperty, NULL, true, BootStop, uTimout);
        if( asDeviceType == "1" )  //Composite
        {
            iRet = SP_GetIncrementCOMPortWithFilter(&sCOMFilter, &sCOMProperty, NULL, false, BootStop, uTimout/1000);
        }
        else                       //Single
        {
            iRet = SP_GetIncrementCOMPortWithFilter(&sCOMFilter, &sCOMProperty, NULL, true, BootStop, uTimout/1000);
        }

        if(0 == iRet)
        {
            switch(sCOMProperty.m_iFilterIndex)
            {
            case 0:
                eType = PreloaderUSB;
                break;
            case 1:
                eType = PreloaderUSB;
                break;
            case 2:
                eType = BootROMUSB;
                break;
            default:
                Application->MessageBox("Search filter index error!", "Fail", MB_OK);
                return;
            }

            stArg.m_uPortNumber = sCOMProperty.m_uNumber;

           //   Wei Fang add for show conncection time
           QueryPerformanceFrequency(&litmp);
           dff=(double)litmp.QuadPart;
           QueryPerformanceCounter(&litmp);
           qt1=litmp.QuadPart;
        }
        else
        {
            switch(iRet)
            {
            case SP_S_STOP:
                return;
            case SP_S_TIMEOUT:
                Application->MessageBox("Search Preloader/BootROM USB COM port timout!", "Fail", MB_OK);
                break;
            case SP_S_INVALID_ARGUMENTS:
                Application->MessageBox("Invalid arguments for searching COM port!", "Fail", MB_OK);
                break;
            default:
                Application->MessageBox("Search Preloader/BootROM USB COM port fail!", "Fail", MB_OK);
            }

            isConnectFail = true;
            return;
        }
    }

    if( asDeviceType == "1" )   //Composite
    {
        Sleep(500);
    }

    //3. Do META connection
    if(BootROMUSB == eType)
    {
        iRet = SP_BootROM_BootMode(&stArg);
        if(0 != iRet)
        {
            if(SP_S_STOP == iRet)
            {
                return;
            }
            isConnectFail = true;

            Application->MessageBox("Do handshake with BootROM fail!", "Fail", MB_OK);

            return;
        }
    }
    else if(PreloaderUSB == eType)
    {
        iRet = SP_Preloader_BootMode(&stArg);
        if(0 != iRet)
        {
            if(SP_S_STOP == iRet)
            {
                return;
            }
            isConnectFail = true;

            Application->MessageBox("Do handshake with Preloader fail!", "Fail", MB_OK);

            return;
        }
    }

    ActiveMan_Boot->SetActiveFunction_Boot(METADLL_Connect_Thread);
}
//---------------------------------------------------------------------------
void METADLL_ConnectInMetaMode_Thread()
{
    METADLL_ConnectInMetaMode(&g_ConnectInMETA_Req, &(frmMainSel->BootStop),&g_ConnectInMETA_Report);
    SetEvent(p_METADLL_Connect_Event);
}
//----------------------------------------------------------------------------
void  CMetaDllMan::METADLL_DisconnectWithTarget( bool alreadyInMetaMode )
{
/*    if( ConnectTargetok )
    {
        SP_META_ShutDownTarget_r(m_META_HANDLE_Obj.Get_MainHandle());
        SP_META_DisconnectWithTarget_r( m_META_HANDLE_Obj.Get_MainHandle() );
    }   */
    if( ConnectTargetok )
    {
        if(!alreadyInMetaMode)
        {
            LOG("SP_META_ShutDownTarget_r");
            SP_META_ShutDownTarget_r(m_META_HANDLE_Obj.Get_MainHandle());
            LOG("SP_META_DisconnectWithTarget_r");
            SP_META_DisconnectWithTarget_r( m_META_HANDLE_Obj.Get_MainHandle() );
        }
        else
        {
            SP_META_DisconnectInMetaMode_r(m_META_HANDLE_Obj.Get_MainHandle());
        }
    }
    
    ConnectTargetok = false;
    isConnectTarget = false;
    isConnectFail = false;
}
//==============================================================================
/*void  UartDisconnect( void )
{
    frmMainSel->UartDisconnect();
}  */
//----------------------------------------------------------------------------
static void __stdcall ErrorHandler(const META_CNF_ERR_CODE err)
{
    metadllman_ptr->ErrorHandler(err);
}
//----------------------------------------------------------------------------
void __stdcall SystemHandler(const char *sys_trace)
{
    metadllman_ptr->SystemHandler(sys_trace);
}
//==============================================================================
bool CMetaDllMan::StartConnectTarget(bool isUSB, bool isMetaMode, bool isLegacyAutoDetection, int comnum)
{
    m_isUSB = isUSB;
    m_isMetaMode = isMetaMode;
    m_isLegacyAutoDetection = isLegacyAutoDetection;
    m_comnum = comnum;

    if(!ConnectTargetok)
    {
        if(!isConnectTarget)
        {
            if(!p_METADLL_Connect_Event)
            {
                p_METADLL_Connect_Event = CreateEvent(NULL, TRUE, FALSE, NULL);
            }
            ResetEvent(p_METADLL_Connect_Event);
            isConnectTarget = true;

            if(isMetaMode==true)//already in meta mode
            {
                ActiveMan_Boot->SetActiveFunction_Boot(METADLL_Connect_Thread);
            }
            else
            {
                ActiveMan_Boot->SetActiveFunction_Boot(METADLL_ConnectInMetaMode_Thread);
            }
        }
        return false;
    }
    return true;
}
//---------------------------------------------------------------------------
void __stdcall CMetaDllMan::ErrorHandler(const META_CNF_ERR_CODE err)
{
}
//----------------------------------------------------------------------------
void __stdcall CMetaDllMan::SystemHandler(const char *sys_trace)
{
    Application->MessageBox( sys_trace, "System trace", MB_OK );
}
//===========================================================================
CMetaDllMan::CMetaDllMan( void )
{
    IsRunning = false;
    hCom = NULL;
    metadllman_ptr = this;
    unsigned int  major_ver = 0;
    unsigned int  minor_ver = 0;
    unsigned int  build_num = 0;
    unsigned int  patch_num = 0;
    Version = 0;
    SP_META_GetDLLVer( &major_ver, &minor_ver, &build_num, &patch_num);
    m_asMETADLLVer = IntToStr(major_ver) + "." + IntToStr(minor_ver) + "." + IntToStr(build_num) + "." + IntToStr(patch_num);
}
//---------------------------------------------------------------------------
CMetaDllMan::~CMetaDllMan( )
{
    if(p_METADLL_Connect_Event)
    {
        CloseHandle(p_METADLL_Connect_Event);
        p_METADLL_Connect_Event = NULL;
    }

    if(IsRunning)
    {
        End();
        IsRunning = false;
    }
}
//---------------------------------------------------------------------------
bool CMetaDllMan::MetaInit( void )
{
    m_META_HANDLE_Obj.REQ_AllocateMainHandle_Start();
    return true;
}
//---------------------------------------------------------------------------
bool CMetaDllMan::End(void)
{
    META_RESULT meta_result;

    if (g_bMetaCommStart)
    {
        meta_result = SP_META_COMM_Stop_r(m_META_HANDLE_Obj.Get_MainHandle());
        if (meta_result != META_SUCCESS)
        {

        }
        g_bMetaCommStart = false;
    }

    SP_META_CancelAllBlockingCall_r(m_META_HANDLE_Obj.Get_MainHandle());
    if (ConnectTargetok)
    {
        SP_META_DisconnectWithTarget_r(m_META_HANDLE_Obj.Get_MainHandle());
        ConnectTargetok = false;
    }

    if (isMETAInit)
    {
        m_META_HANDLE_Obj.REQ_ReleaseMainHandle_Start();
        m_META_HANDLE_Obj.REQ_ReleaseSecondHandle_Start();
        isMETAInit = false;
    }
    IsRunning = false;
    return(true);
}
//==============================================================================
bool  CMetaDllMan::isMetaVerRequiredByTargetOk( unsigned int meta_ver_required_by_target )
{
    return  true;
}
//---------------------------------------------------------------------------
void  CMetaDllMan::getMetaVerRequiredByTarget( unsigned int meta_ver_required_by_target, char* p_cmeta_ver_required_by_target )
{
    unsigned int x, y,z;


    x = ( (meta_ver_required_by_target) & 0xFF000000 ) >> 24;
    y = ( (meta_ver_required_by_target) & 0x00FF0000 ) >> 16;
    z = ( (meta_ver_required_by_target) & 0x0000FFFF );
    sprintf(p_cmeta_ver_required_by_target, "%d.%d.%d", x, y, z);

}
//===========================================================================
////////////////////////////////  information  //////////////////////////////
//===========================================================================
AnsiString CMetaDllMan::Get_METADLLVersion( void )
{
    return m_asMETADLLVer;
}
//---------------------------------------------------------------------------
AnsiString CMetaDllMan::Get_METADLLBuildDate( void )
{
    return m_asMETADLLBuildDate;
}






