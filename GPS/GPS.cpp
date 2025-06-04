#pragma hdrstop
#include "meta.h"
#include "metaapp_common.h"
#include "GPS.h"
#include "man_active.h"
#include "LogicalControlBase.h"
#include <math.h>
#include <Classes.hpp>
#include <inifiles.hpp>
#include <syncobjs.hpp>
#ifndef _META_LAB_MSG_H_
#include "meta_lab_msg.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif
#include <stdio.h>       //just for test


/*#define CheckHz 1
#define MinPhaseRatio	0.85	//-130dBm
#define ClockOffset 		40.92
#define ClockDrift		0.05
#define CNRMean			40
#define CNRSigma			1*/

static CGPS*  g_gps_ptr;

static void REQ_GPS_Open(void)
{
    g_gps_ptr->REQ_GPS_Open();
}

static void REQ_GPS_Close(void)
{
    g_gps_ptr->REQ_GPS_Close();
}

static void REQ_GPS_SendCommand_PMTK810(void)
{
    g_gps_ptr->REQ_GPS_SendCommand_PMTK810();
}

//qinqin 20120510
static void REQ_GPS_SendCNRStartCommand_PMTK810(void)
{
    g_gps_ptr->REQ_GPS_SendCNRStartCommand_PMTK810();
}

static void REQ_GPS_SendCNRStopCommand_PMTK811(void)
{
    g_gps_ptr->REQ_GPS_SendCNRStopCommand_PMTK811();
}
//

//qinqin 2012-01-12
static void REQ_GPS_SendCommand_PMTK811(void)
{
    g_gps_ptr->REQ_GPS_SendCommand_PMTK811();
}
//

//qinqin 2012-02-27
static void REQ_GPS_SendStartCommand_PMTK817(void)
{
    g_gps_ptr->REQ_GPS_SendStartCommand_PMTK817();
}

static void REQ_GPS_SendStopCommand_PMTK817(void)
{
    g_gps_ptr->REQ_GPS_SendStopCommand_PMTK817();
}

static void __stdcall CNF_GPSSendStartCommand_PMTK817(const GPS_ACK_BUF*cnf, const short token, void *usrData)
{
    g_gps_ptr->CNF_GPSSendStartCommand_PMTK817(cnf, token, usrData );
}
//

static void __stdcall CNF_GPSSendCommand_PMTK810(const GPS_ACK_BUF*cnf, const short token, void *usrData)
{
    g_gps_ptr->CNF_GPSSendCommand_PMTK810(cnf, token, usrData );
}

static void __stdcall CNF_GPSSendCNRStartCommand_PMTK810(const GPS_ACK_BUF*cnf, const short token, void *usrData)
{
    g_gps_ptr->CNF_GPSSendCNRStartCommand_PMTK810(cnf, token, usrData );
}

//============================================
void CGPS::REQ_GPS_Open(void)
{
    DoMetaResult(SP_META_GPS_Open_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000));
}
void CGPS::REQ_GPS_Close(void)
{
    SP_META_CancelAllBlockingCall_r( m_META_HANDLE_Obj.Get_MainHandle() );

    DoMetaResult(SP_META_GPS_Close_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000));

}

void CGPS::REQ_GPS_Open_Close_HWT(void)
{
    META_RESULT res1,res2;
    res1 = SP_META_GPS_Open_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
    Sleep(1000);
    SP_META_CancelAllBlockingCall_r( m_META_HANDLE_Obj.Get_MainHandle());
    res2 = SP_META_GPS_Close_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000);
    if(META_SUCCESS == res1 && META_SUCCESS == res2)
        m_iConfirmState = META_SUCCESS;
    else
        m_iConfirmState = META_FAILED;
    ConfirmCallback();
}

void CGPS::REQ_GPS_SendCommand_PMTK810(void)
{
    m_bEventOk = false;

    m_bDataOk = true;

    m_bUpdateHz = true;
    m_bAcquisition = true;
    m_bBitSync = true;
    m_bPhase = true;
    m_bTCXO_Offset = true;
    m_bTCXO_Drift = true;
    m_bCNR_Mean = true;
    m_bCNR_Sigma = true;

    META_RESULT MetaResult = SP_META_GPS_SendCommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sGPS.gps_cmd, &m_sGPS.gps_result, ::CNF_GPSSendCommand_PMTK810);

    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }
//rongguo 2011-07-06
//    if (m_bEventOk)
//    {
    Confirm(META_SUCCESS);
//    }

}

//qinqin 2012-01-12
void CGPS::REQ_GPS_SendCommand_PMTK811(void)
{
    m_bDataOk = false;

    m_bUpdateHz = false;
    m_bAcquisition = false;
    m_bBitSync = false;
    m_bPhase = false;
    m_bTCXO_Offset = false;
    m_bTCXO_Drift = false;
    m_bCNR_Mean = false;
    m_bCNR_Sigma = false;

    META_RESULT MetaResult = SP_META_GPS_SendCommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sGPS.gps_cmd, &m_sGPS.gps_result,NULL);

    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    Confirm(META_SUCCESS);
}
//

void CGPS::REQ_Start(REQ_CMDTYPE rct, void (*cb)(void))
{
    ConfirmCallback = cb;
    g_gps_ptr = this;
    m_bIsRunning = true;

    switch(rct)
    {
    case GPS_Open:
        ActiveMan->SetActiveFunction(::REQ_GPS_Open);
        break;
    case GPS_Close:
        ActiveMan->SetActiveFunction(::REQ_GPS_Close);
        break;
    case GPS_SendCommand_PMTK810:
        ActiveMan->SetActiveFunction(::REQ_GPS_SendCommand_PMTK810);
        break;
    case GPS_SendCommand_PMTK811:
        ActiveMan->SetActiveFunction(::REQ_GPS_SendCommand_PMTK811);
        break;
//qinqin 20120305
    case GPS_SendStartCommand_PMTK817:
        ActiveMan->SetActiveFunction(::REQ_GPS_SendStartCommand_PMTK817);
        break;
    case GPS_SendStopCommand_PMTK817:
        ActiveMan->SetActiveFunction(::REQ_GPS_SendStopCommand_PMTK817);
        break;
//
    case GPS_SendCNRStartCommand_PMTK810:
        ActiveMan->SetActiveFunction(::REQ_GPS_SendCNRStartCommand_PMTK810);
        break;
    case GPS_SendCNRStopCommand_PMTK811:
        ActiveMan->SetActiveFunction(::REQ_GPS_SendCNRStopCommand_PMTK811);
        break;
    default:
        break;
    }
}

void __stdcall CGPS::CNF_GPSSendCommand_PMTK810(const GPS_ACK_BUF*cnf, const short token, void *usrData)
{
    if (cnf->len == 0)
        return;
    char *pkghead = (char *)cnf->buff;
    char *tail = (char *)cnf->buff + cnf->len -1;
    if(!pkghead)
        return;
    char *pkgtail = strstr(pkghead,"\r\n");
    if(!pkgtail)
        return;
    m_len = pkgtail-pkghead;

//rongguo 2011-07-06
    memset(tail + 1, 0, sizeof(cnf->buff) - cnf->len);

    while(pkghead)
    {
        char *cpkgBuf = new char[m_len];
        memset(cpkgBuf,0,m_len);
        memcpy(cpkgBuf,pkghead, m_len);

        if(strncmp(cpkgBuf,"$PMTK500",8)==0)
        {
            if(!DeCompose_GPS_PMTK500( cpkgBuf))
            {
                if( cpkgBuf != NULL )
                {
                    delete []cpkgBuf;
                    cpkgBuf = NULL;
                }
                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_ERROR_MSG,
                            PAGEIDX_GPS_PKG_ERROR,0);
                return;
            }
        }
        else if(strncmp(cpkgBuf,"$PMTK705",8)==0)
        {
            if(!DeCompose_GPS_PMTK705(cpkgBuf))
                return;
        }
        else if(strncmp(cpkgBuf,"$PMTK813",8)==0)
        {
            if(!DeCompose_GPS_PMTK813( cpkgBuf ))
            {
                if( cpkgBuf != NULL )
                {
                    delete []cpkgBuf;
                    cpkgBuf = NULL;
                }
                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_ERROR_MSG,
                            PAGEIDX_GPS_PKG_ERROR,
                            0);
                return;
            }
        }
        else if(strncmp(cpkgBuf,"$PMTK814",8)==0)
        {
            if(!DeCompose_GPS_PMTK814( cpkgBuf))
            {
                if( cpkgBuf != NULL )
                {
                    delete []cpkgBuf;
                    cpkgBuf = NULL;
                }
                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_ERROR_MSG,
                            PAGEIDX_GPS_PKG_ERROR,
                            0);
                return;
            }
        }
        else if(strncmp(cpkgBuf,"$PMTK815",8)==0)
        {
            if(!DeCompose_GPS_PMTK815(cpkgBuf ))
            {
                if( cpkgBuf != NULL )
                {
                    delete []cpkgBuf;
                    cpkgBuf = NULL;
                }
                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_ERROR_MSG,
                            PAGEIDX_GPS_PKG_ERROR,
                            0);
                return;
            }
        }
        else if(strncmp(cpkgBuf,"$PMTK812",8)==0)
        {
            if (m_bAcquisition&&m_bBitSync&&m_bCNR_Mean&&m_bCNR_Sigma&&m_bPhase&&m_bTCXO_Drift&&m_bTCXO_Offset&&m_bUpdateHz)
                m_bDataOk = true;
            else
                m_bDataOk = false;

            if (m_bDataOk)
            {
                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_PRINT_MSG,
                            PAGEIDX_GPS_PMTK812,
                            0);
                m_bEventOk = true;
            }
            else
            {
                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_ERROR_MSG,
                            PAGEIDX_GPS_PMTK812_ERROR,
                            0);
            }
        }

        if( cpkgBuf != NULL )
        {
            delete []cpkgBuf;
            cpkgBuf = NULL;
        }

        pkghead = strstr(pkgtail,"$");
        if (!pkghead)
            return;
//rongguo 2011-07-06
        if(pkghead > tail)
            return;

        pkgtail = strstr(pkghead,"\r\n");
        if (!pkgtail)
            return;
        m_len = pkgtail -pkghead;
    }
    return;
}

bool CGPS::DeCompose_GPS_PMTK500(char *gps_buf)
{
    char *head = gps_buf;
    char result[20];
    char * start =strstr(head,",")+1;
    float Fix_Int = 0;
    FetchField(start,result);
    Fix_Int =atoi(result);
    if( Fix_Int != 0)
    {
        m_UpdateHz = 1000/Fix_Int;
    }
    if((fabs(m_UpdateHz-atoi(as_UpdateHz.c_str())))>1e-5)
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK500_ERROR,
                    0);
        m_bUpdateHz = false;
    }
    else
    {
        m_bUpdateHz = true;
    }
//
    PostMessage(m_sGPS.hPostMsgDestHandle,
                WM_ML_GPS_PKG_PRINT_MSG,
                PAGEIDX_GPS_PMTK500,0);
    return true;
}
bool CGPS::DeCompose_GPS_PMTK705(char * gps_buf)
{
    SetGPSVersion(gps_buf);
    PostMessage(m_sGPS.hPostMsgDestHandle,
                WM_ML_GPS_PKG_PRINT_MSG,
                PAGEIDX_GPS_PMTK705,
                0);
    return true;
}

bool CGPS::DeCompose_GPS_PMTK813(char * gps_buf)
{
    char *head = gps_buf;
    char result[20];
    char * start =strstr(head,",")+1;
    start =strstr(start,",")+1;
    FetchField(start,result);
    m_Acquisition = atoi(result);
    if (m_Acquisition > atoi(as_Acquisition.c_str()))
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK813_ERROR,
                    0);
        m_bAcquisition = false;
    }
    else
    {
        m_bAcquisition = true;
    }  //
    PostMessage(m_sGPS.hPostMsgDestHandle,
                WM_ML_GPS_PKG_PRINT_MSG,
                PAGEIDX_GPS_PMTK813,
                0);
    return true;
}

bool CGPS::DeCompose_GPS_PMTK814(char * gps_buf)
{
    char *head = gps_buf;
    char result[20];
    char * start =strstr(head,",")+1;
    start = strstr(start,",")+1;
    if (!start)
        return false;
    FetchField(start,result);
    m_BitSync = atoi(result);
    if (m_BitSync > atoi(as_BitSync.c_str()))
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK814_ERROR,
                    0);
        m_bBitSync = false;
    }
    else
    {
        m_bBitSync = true;
    }//
    PostMessage(m_sGPS.hPostMsgDestHandle,
                WM_ML_GPS_PKG_PRINT_MSG,
                PAGEIDX_GPS_PMTK814,
                0);
    return true;
}

bool CGPS::DeCompose_GPS_PMTK815(char * gps_buf)
{
    char *head = gps_buf;
    char result[20];
    char * start =strstr(head,",")+1;
    start =strstr(head,",")+1;
    start =strstr(start,",")+1;   // SV
    start =strstr(start,",")+1;   // Testing time
    if (!start)
        return false;
    FetchField(start,result);      // Phase
    m_Phase =(double)atoi(result)/100.0;						//phase ratio
    if(m_Phase <atof(as_Phase.c_str()))
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK815_Phase_ERROR,
                    0);
        Confirm( META_FAILED );
        m_bPhase = false;
    }
    else
    {
        m_bPhase = true;
    } //

    //TCXO
    start =strstr(start,",")+1;
    if (!start)
        return false;
    FetchField(start,result);
    m_TCXO_Offset = (double)atoi(result)/1000.0;		       //TCXO offset  //  modified as Clock Drift
    start =strstr(start,",")+1;
    if (!start)
        return false;
    FetchField(start,result);
    m_TCXO_Drift = (double)atoi(result)/1000.0;			       //TCXO drift   // modified as Clock Drift Rate

    if(!(fabs(m_TCXO_Offset) < atof(as_TCXO_Offset.c_str())))
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK815_TCXO_OFFSET_ERROR,
                    0);
        Confirm( META_FAILED );
        m_bTCXO_Offset= false;
    }
    else
    {
        m_bTCXO_Offset= true;
    }

    if(!(fabs(m_TCXO_Drift) < atof(as_TCXO_Drift.c_str())))
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK815_TCXO_DRIFT_ERROR,
                    0);
        Confirm( META_FAILED );
        m_bTCXO_Drift = false;
    }
    else
    {
        m_bTCXO_Drift = true;
    }

    // CNR
    start =strstr(start,",")+1;
    if (!start)
        return false;
    FetchField(start,result);
    m_CNR_Mean = (double)atoi(result)/100.0;
    if(m_CNR_Mean < atof(as_CNR_Mean.c_str()))
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK815_CNR_MEAN_ERROR,
                    0);

        Confirm( META_FAILED );
        m_bCNR_Mean = false;
    }
    else
    {
        m_bCNR_Mean = true;
    }

    start =strstr(start,",")+1;
    if (!start)
        return false;
    FetchField(start,result);
    m_CNR_Sigma =(double)atoi(result)/100.0;

    if(m_CNR_Sigma>atof(as_CNR_Sigma.c_str()))
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK815_CNR_SIGMA_ERROR,
                    0);

        Confirm( META_FAILED );
        m_bCNR_Sigma = false;
    }
    else
    {
        m_bCNR_Sigma = true;
    }

    PostMessage(m_sGPS.hPostMsgDestHandle,
                WM_ML_GPS_PKG_PRINT_MSG,
                PAGEIDX_GPS_PMTK815,
                0
               );
    return true;
}

bool CGPS::FetchField(char *start, char *result)
{
    char *end;
    if(start == NULL)
        return false;
    end = strstr( start, ",");
    // the end of sentence
    if(end == NULL)
        end = strstr(start, "*");

    if(end-start>0)
    {
        strncpy( result, start, end-start);
        result[end-start]='\0';
    }
    else   // no data
    {
        result[0]='\0';
        return false;
    }
    return true;
}
bool CGPS::ReadFromIniFile(AnsiString as)
{
    TIniFile *ini;
    ini = new TIniFile( as );
    if(ini != NULL)
    {
        as_Phase = ini->ReadString("GPS Spec table","Phase ratio","0.85");
        //as_TCXO_Offset = ini->ReadString("GPS Spec table","TCXO Offset","40.92");  //modified 20120312 qinqin
        //as_TCXO_Drift = ini->ReadString("GPS Spec table","TCXO Drift","0.8184");
        as_TCXO_Offset = ini->ReadString("GPS Spec table","TCXO Clock Drift","2.5");
        as_TCXO_Drift = ini->ReadString("GPS Spec table","TCXO Clock Drift Rate","2.5");
        as_CNR_Mean = ini->ReadString("GPS Spec table","CNR Mean","40");
        as_CNR_Sigma = ini->ReadString("GPS Spec table","CNR Sigma","1");
        as_UpdateHz = ini->ReadString("GPS Spec table","Update HZ","1");
        as_BitSync = ini->ReadString("GPS Spec table","BitSync","5");
        as_Acquisition= ini->ReadString("GPS Spec table","Acquision","10");
        as_CWCNR = ini->ReadString("GPS Spec table","CW CNR","65");
        as_CWCNRVariation = ini->ReadString("GPS Spec table","CW CNR variation","5");

        as_CNRModeCNR = ini->ReadString("GPS Spec table","CNR Mode CNR","40");
        as_CNRModeCNRVariation = ini->ReadString("GPS Spec table","CNR Mode CNR variation","5");
        delete ini;
        ini = NULL;
    }
    return true;
}  // function
AnsiString CGPS::GetGPSVersion(void)
{
    return as_GPSVersion;
}
void CGPS::SetGPSVersion(AnsiString as)
{
    as_GPSVersion = as;
}

void CGPS::REQ_GPS_SendStartCommand_PMTK817(void)
{
    m_bCWNR = true;
    m_bCWClockDrift = true;
    META_RESULT MetaResult = SP_META_GPS_SendCommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sGPS.gps_cmd, &m_sGPS.gps_result,::CNF_GPSSendStartCommand_PMTK817);

    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }
    Confirm(META_SUCCESS);
}
//

void __stdcall CGPS::CNF_GPSSendStartCommand_PMTK817(const GPS_ACK_BUF*cnf, const short token, void *usrData)
{
    if (cnf->len == 0)
        return;
    char *pkghead = (char *)cnf->buff;
    char *tail = (char *)cnf->buff + cnf->len -1;
    if(!pkghead)
        return;
    char *pkgtail = strstr(pkghead,"\r\n");
    if(!pkgtail)
        return;
    m_len = pkgtail-pkghead;

    memset(tail + 1, 0, sizeof(cnf->buff) - cnf->len);

    while(pkghead)
    {
        char *cpkgBuf = new char[m_len];
        memset(cpkgBuf,0,m_len);
        memcpy(cpkgBuf,pkghead, m_len);
        if(strncmp(cpkgBuf,"$PMTK817",8)==0)
        {
            if(!DeCompose_GPS_PMTK817( cpkgBuf))
            {
                if( cpkgBuf != NULL )
                {
                    delete []cpkgBuf;
                    cpkgBuf = NULL;
                }
                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_ERROR_MSG,
                            PAGEIDX_GPS_PKG_ERROR,0);
                return;
            }
        }


        if( cpkgBuf != NULL )
        {
            delete []cpkgBuf;
            cpkgBuf = NULL;
        }

        pkghead = strstr(pkgtail,"$");
        if (!pkghead)
            return;
        if(pkghead > tail)
            return;

        pkgtail = strstr(pkghead,"\r\n");
        if (!pkgtail)
            return;
        m_len = pkgtail -pkghead;
    }
    return;
}


bool CGPS::DeCompose_GPS_PMTK817(char * gps_buf)
{
    char *head = gps_buf;
    char result[20] = {0};
    char * start =strstr(head,",")+1;
    float CWCNRUpperlimit = 0.0;
    float CWCNRowerlimit = 0.0;
    if (!start)
        return false;
    FetchField(start,result);
    int nFlag = atoi(result);
    if( nFlag != 2 )
    {
        return false;
    }
    start =strstr(start,",")+1;
    if (!start)
    {
        return false;
    }
    FetchField(start,result);
    m_CWCNR =(double)atof(result);                                  	//CNR
    CWCNRUpperlimit = atof(as_CWCNR.c_str()) + atof(as_CWCNRVariation.c_str());
    CWCNRowerlimit = atof(as_CWCNR.c_str()) - atof(as_CWCNRVariation.c_str());
    if(m_CWCNR > CWCNRUpperlimit || m_CWCNR < CWCNRowerlimit)
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK817_CNR_ERROR,
                    0);
        m_bCWNR = false;
    }
    else        //because the criteria is not sure,so it is not checked.
    {
        m_bCWNR = true;
    } //
    start =strstr(start,",")+1;
    if (!start)
        return false;
    FetchField(start,result);
    m_CWClockDrift = (double)atof(result);					//Clock Drift

//    if(m_CWClockDrift > atof(as_TCXO_Offset.c_str()))
    if(!(fabs(m_CWClockDrift) < atof(as_TCXO_Offset.c_str())))     //qinqin 20120319  PASS: fabs(Clock Drift) < TCXO Clock Drift(from ini file)
    {
        PostMessage(m_sGPS.hPostMsgDestHandle,
                    WM_ML_GPS_PKG_ERROR_MSG,
                    PAGEIDX_GPS_PMTK817_CLOCK_DRIFT_ERROR,
                    0);
        m_bCWClockDrift = false;
    }
    else
    {
        m_bCWClockDrift= true;
    }

    PostMessage(m_sGPS.hPostMsgDestHandle,
                WM_ML_GPS_PKG_PRINT_MSG,
                PAGEIDX_GPS_PMTK817,
                0);
    return true;
}

void CGPS::REQ_GPS_SendStopCommand_PMTK817(void)
{
    m_bCWNR = false;
    m_bCWClockDrift = false;
    META_RESULT MetaResult = SP_META_GPS_SendCommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sGPS.gps_cmd, &m_sGPS.gps_result,NULL);

    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    Confirm(META_SUCCESS);
}


void CGPS::CWTest(void)
{
    GPS_ACK_BUF buf;
    char a[]= "$PMTK817,2,0030,-0.636*21\r\n";
    int i = sizeof(a);
    sprintf(buf.buff,a,i);
    //unsigned short token = 10;
    buf.len =  i;
    int usedata = 1;
    CNF_GPSSendStartCommand_PMTK817(&buf, 10, &usedata);
}


void CGPS::JudgeCNRValue(float CNRAverage,float ClockDriftAverage)
{
    float CWCNRAverage = 0.0;
    float CWClockDriftAverage = 0.0;
    float CWCNRUpperlimit = 0.0;
    float CWCNRowerlimit = 0.0;
    CWCNRAverage = CNRAverage;
    CWCNRUpperlimit = atof(as_CWCNR.c_str()) + atof(as_CWCNRVariation.c_str());
    CWCNRowerlimit = atof(as_CWCNR.c_str()) - atof(as_CWCNRVariation.c_str());
    if(CWCNRAverage > CWCNRUpperlimit || m_CWCNR < CWCNRowerlimit)
    {
        m_bCWNR = false;
    }
    else
    {
        m_bCWNR = true;
    } //

    CWClockDriftAverage = ClockDriftAverage;

    if(CWClockDriftAverage > atof(as_TCXO_Offset.c_str()))
    {
        m_bCWClockDrift = false;
    }
    else
    {
        m_bCWClockDrift= true;
    }

}


//---------------------------------------------------------------------------
bool CGPS::TestGNSS_DeCompose_GPS_GPGSV(int sys_idx, char *gps_buf)
{
    // $GPGSV,3,1,09,03,63,020,43,19,76,257,37,27,14,320,30,23,39,228,37*79
    // $GPGSV,3,2,09,13,38,274,38,16,31,058,37,15,16,055,34,11,16,192,32*76
    // $GPGSV,3,3,09,07,15,043,26*40
    char *head = gps_buf;
    char *start = NULL;
    char result[20] = {0};
    int sv_cnt = 0;
    int base = 0;
    int i = 0;
    int CNRModeCNRUpperlimit = 0;
    int CNRModeCNRowerlimit = 0;
    // check checksum
    if(GPSCNRCheckSum(head, strlen(head)))
    {
        // ignore
        start = strstr( head, ",");
        if(start != NULL)
            start = start +1;
        else
            return false;

        //first Message
        if(*(start+2)=='1')
        {
            memset( &m_svInfo, 0, sizeof(m_svInfo));
        }

        // Last Message
        //if(*start == *(start+2))
        //   g_fgSVUpdate = true;

        //base  //sentence number.
        start = strstr( start, ",");
        if(start != NULL)
            start = start +1;
        else
            return false;
        if(!FetchField( start, result))
            return false;
        base = (atoi(result)-1)*4;
        
        //total
        start = strstr( start, ",");
        if(start != NULL)
            start = start +1;
        else
            return false;
        if(!FetchField( start, result))
            return false;
        m_GPSSV_cnt[sys_idx] = atoi(result);
        if(m_GPSSV_cnt[sys_idx] == 0)
        {
            return false;
        }
        for( i=0 ; i<4 ; i++)
        {
            //SVid
            start = strstr( start, ",");
            if(start != NULL)
                start = start +1;
            else
                return false;
            FetchField( start, result);
            if(strlen(result)>0)
                m_svInfo[sys_idx][base+sv_cnt].SVid = atof(result);
            else
                m_svInfo[sys_idx][base+sv_cnt].SVid = 0;

            //elev
            start = strstr( start, ",");
            if(start != NULL)
                start = start +1;
            else
                return false;
            FetchField( start, result);
            //azimuth
           //azimuth
            start = strstr( start, ",");
            if(start != NULL)
                start = start +1;
            else
                return false;
            FetchField( start, result);

        //SNR
            start = strstr( start, ",");
            if(start != NULL)
                start = start +1;
            else
                return false;
            if(*start == '*')
                m_svInfo[sys_idx][base+sv_cnt].SNR = 0;
            else
            {
                //LOG("To parse SNR- (%s)", start);
                FetchField( start, result);
                if(strlen(result)>0)
                    m_svInfo[sys_idx][base+sv_cnt].SNR = atof(result);
                else
                    m_svInfo[sys_idx][base+sv_cnt].SNR = 0;
            }

            LOG("m_svInfo[%d][base:%d+sv_cnt:%d].SNR:%f", sys_idx,base,sv_cnt,m_svInfo[sys_idx][base+sv_cnt].SNR);

            if( m_svInfo[sys_idx][base+sv_cnt].SVid == m_CNRMode_Svid[sys_idx])
            {
                m_CNRMode_CNR[sys_idx] = m_svInfo[sys_idx][base+sv_cnt].SNR;          //CNR mode CNR
                CNRModeCNRUpperlimit = atoi(as_CNRModeCNR.c_str()) + atoi(as_CNRModeCNRVariation.c_str());
                CNRModeCNRowerlimit = atoi(as_CNRModeCNR.c_str()) - atoi(as_CNRModeCNRVariation.c_str());
                LOG("m_CNRMode_CNR:%d,CNRModeCNRUpperlimit:%d,CNRModeCNRowerlimit:%d",m_CNRMode_CNR,CNRModeCNRUpperlimit,CNRModeCNRowerlimit);
                if(m_CNRMode_CNR[sys_idx] > CNRModeCNRUpperlimit || m_CNRMode_CNR[sys_idx] < CNRModeCNRowerlimit)
                {
                    PostMessage(m_sGPS.hPostMsgDestHandle,
                                WM_ML_GPS_PKG_ERROR_MSG,
                                PAGEIDX_GPS_GPGSV_CNR_ERROR,
                                sys_idx);

                    Confirm( META_FAILED );
                    m_bCNRModeCNR[sys_idx] = false;
                }
                else
                {
                    m_bCNRModeCNR[sys_idx] = true;
                }

                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_PRINT_MSG,
                            PAGEIDX_GPS_GPGSV,
                            sys_idx);

		LOG("------>sys_idx = %d, SNR = %f", sys_idx, m_CNRMode_CNR[sys_idx]);
                return true;
            }
            sv_cnt++;

            if(base+sv_cnt == m_GPSSV_cnt[sys_idx])
                break;
        }
    }
    return false;
}

bool CGPS::DeCompose_GPS_GPGSV(int sys_idx, char *gps_buf)
{
    // $GPGSV,3,1,09,03,63,020,43,19,76,257,37,27,14,320,30,23,39,228,37*79
    // $GPGSV,3,2,09,13,38,274,38,16,31,058,37,15,16,055,34,11,16,192,32*76
    // $GPGSV,3,3,09,07,15,043,26*40
    char *head = gps_buf;
    char *start = NULL;
    char result[20] = {0};
    int sv_cnt = 0;
    int base = 0;
    int i = 0;
    int CNRModeCNRUpperlimit = 0;
    int CNRModeCNRowerlimit = 0;
    // check checksum
    if(GPSCNRCheckSum(head, strlen(head)))
    {
        LOG("head = %s",head);
        // ignore
        start = strstr( head, ",");
        if(start != NULL)
            start = start +1;
        else
            return false;

        //first Message
        if(*(start+2)=='1')
        {
            memset( &m_svInfo, 0, sizeof(m_svInfo));
        }

		// Last Message
        //if(*start == *(start+2))
        //   g_fgSVUpdate = true;

        //base  //sentence number.
        start = strstr( start, ",");
        if(start != NULL)
            start = start +1;
        else
            return false;
        if(!FetchField( start, result))
            return false;
        base = (atoi(result)-1)*4;
        LOG("base = %d result = %s",base,result);
        //total
        start = strstr( start, ",");
        if(start != NULL)
            start = start +1;
        else
            return false;
        if(!FetchField( start, result))
            return false;
        m_GPSSV_cnt[sys_idx] = atoi(result);
        if(m_GPSSV_cnt[sys_idx] == 0)
        {
            return false;
        }
        for( i=0 ; i<4 ; i++)
        {
            //SVid
            start = strstr( start, ",");
            if(start != NULL)
                start = start +1;
            else
                return false;
            FetchField( start, result);
            if(strlen(result)>0)
                m_svInfo[sys_idx][base+sv_cnt].SVid = atoi(result);
            else
                m_svInfo[sys_idx][base+sv_cnt].SVid = 0;

            //LOG("m_svInfo[base:%d+sv_cnt:%d].SVid:%d",base,sv_cnt,m_svInfo[base+sv_cnt].SVid);

            //elev
            start = strstr( start, ",");
            if(start != NULL)
                start = start +1;
            else
                return false;
            FetchField( start, result);
            /*if(strlen(result)>0)
               m_svInfo[base+sv_cnt].elv = atoi(result);
            else
               m_svInfo[base+sv_cnt].elv = 0;

            LOG("m_svInfo[base:%d+sv_cnt:%d].elv:%d",base,sv_cnt,m_svInfo[base+sv_cnt].elv); */
            //azimuth
            start = strstr( start, ",");
            if(start != NULL)
                start = start +1;
            else
                return false;
            FetchField( start, result);
            /*if(strlen(result)>0)
               m_svInfo[base+sv_cnt].azimuth = atoi(result);
            else
               m_svInfo[base+sv_cnt].azimuth = 0;

            LOG("m_svInfo[base:%d+sv_cnt:%d].azimuth:%d",base,sv_cnt,m_svInfo[base+sv_cnt].azimuth);  */
            //SNR
            start = strstr( start, ",");
            if(start != NULL)
                start = start +1;
            else
                return false;
            if(*start == '*')
                m_svInfo[sys_idx][base+sv_cnt].SNR = 0;
            else
            {
                LOG("To parser SNR = (%s)", start);
                FetchField( start, result);
                if(strlen(result)>0)
                {
                    m_svInfo[sys_idx][base+sv_cnt].SNR = atof(result);
                }
                else
                    m_svInfo[sys_idx][base+sv_cnt].SNR = 0;
            }

            LOG("m_svInfo[%d][base:%d+sv_cnt:%d].SNR:%d", sys_idx,base,sv_cnt,m_svInfo[sys_idx][base+sv_cnt].SNR);

            if( m_svInfo[sys_idx][base+sv_cnt].SVid == m_CNRMode_Svid[sys_idx])
            {
                m_CNRMode_CNR[sys_idx] = m_svInfo[sys_idx][base+sv_cnt].SNR;          //CNR mode CNR
                CNRModeCNRUpperlimit = atoi(as_CNRModeCNR.c_str()) + atoi(as_CNRModeCNRVariation.c_str());
                CNRModeCNRowerlimit = atoi(as_CNRModeCNR.c_str()) - atoi(as_CNRModeCNRVariation.c_str());
                LOG("m_CNRMode_CNR:%d,CNRModeCNRUpperlimit:%d,CNRModeCNRowerlimit:%d",m_CNRMode_CNR,CNRModeCNRUpperlimit,CNRModeCNRowerlimit);
                if(m_CNRMode_CNR[sys_idx] > CNRModeCNRUpperlimit || m_CNRMode_CNR[sys_idx] < CNRModeCNRowerlimit)
                {
                    PostMessage(m_sGPS.hPostMsgDestHandle,
                                WM_ML_GPS_PKG_ERROR_MSG,
                                PAGEIDX_GPS_GPGSV_CNR_ERROR,
                                sys_idx);

                    Confirm( META_FAILED );
                    m_bCNRModeCNR[sys_idx] = false;
                }
                else
                {
                    m_bCNRModeCNR[sys_idx] = true;
                }

                PostMessage(m_sGPS.hPostMsgDestHandle,
                            WM_ML_GPS_PKG_PRINT_MSG,
                            PAGEIDX_GPS_GPGSV,
                            sys_idx);
                return true;
            }
            sv_cnt++;

            if(base+sv_cnt == m_GPSSV_cnt[sys_idx])
                break;
        }
    }
    return false;
}

void CGPS::REQ_GPS_SendCNRStartCommand_PMTK810(void)
{
    for(int i=0; i<SATELLITE_COUNT; i++)
    {    
    	m_bCNRModeCNR[i] = true;
    }

    META_RESULT MetaResult = SP_META_GPS_SendCommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sGPS.gps_cmd, &m_sGPS.gps_result, ::CNF_GPSSendCNRStartCommand_PMTK810);

    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    Confirm(META_SUCCESS);

}

void CGPS::REQ_GPS_SendCNRStopCommand_PMTK811(void)
{
    for(int i=0; i<SATELLITE_COUNT; i++)
    {    
    	m_bCNRModeCNR[i] = false;
    }
	
    META_RESULT MetaResult = SP_META_GPS_SendCommand_r(m_META_HANDLE_Obj.Get_MainHandle(), 5000, &m_sGPS.gps_cmd, &m_sGPS.gps_result,NULL);

    if (META_SUCCESS != MetaResult)
    {
        if( META_TIMEOUT == MetaResult )
        {
            Confirm( META_TIMEOUT );
            return;
        }
        else if( META_CANCEL == MetaResult )
        {
            Confirm( META_CANCEL );
            return;
        }
        else
        {
            Confirm( META_FAILED );
            return;
        }
    }

    Confirm(META_SUCCESS);
}


void __stdcall CGPS::CNF_GPSSendCNRStartCommand_PMTK810(const GPS_ACK_BUF*cnf, const short token, void *usrData)
{
    TCriticalSection *pLockX = new TCriticalSection();
    char *pkghead;
    char *tail;
    char *pkgtail;
    int idx;
    char *cpkgBuf;
    pLockX->Acquire();
    if (cnf->len == 0)
       goto _exit_func;

    pkghead = (char *)cnf->buff;
    tail = (char *)cnf->buff + cnf->len -1;
    if(!pkghead)
        goto _exit_func;
    pkgtail = strstr(pkghead,"\r\n");
    if(!pkgtail)
        goto _exit_func;

    m_len = pkgtail-pkghead;

    memset(tail + 1, 0, sizeof(cnf->buff) - cnf->len);

    while(pkghead)
    {
        idx = SATELLITE_END;
        cpkgBuf = new char[m_len+1];
        memset(cpkgBuf,0,m_len+1);
        memcpy(cpkgBuf,pkghead, m_len);

        LOG("cpkgBuf:%s",cpkgBuf);
        if(strncmp(cpkgBuf,"$GPGSV",6)==0)
        {
            idx = SATELLITE_GPS;
            LOG("satellite idx = %d",idx);
        }
        else if(strncmp(cpkgBuf,"$GLGSV",6)==0)
        {
            idx = SATELLITE_GLONASS;
            LOG("satellite idx = %d",idx);
        }
        else if(strncmp(cpkgBuf,"$BDGSV",6)==0)
        {
            idx = SATELLITE_BEIDOU;
            LOG("satellite idx = %d",idx);
        }

        if(idx != SATELLITE_END)
        {
            LOG("[CNR Test]Recv GPS data = %s, idx = %d", cpkgBuf, idx);
            if(!DeCompose_GPS_GPGSV( idx, cpkgBuf))
            {
                if( cpkgBuf != NULL )
                {
                    delete []cpkgBuf;
                    cpkgBuf = NULL;
                }
            }
        }

        if( cpkgBuf != NULL )
        {
            delete []cpkgBuf;
            cpkgBuf = NULL;
        }

        pkghead = strstr(pkgtail,"$");

        if (!pkghead)
            goto _exit_func;

        if(pkghead > tail)
            goto _exit_func;

        pkgtail = strstr(pkghead,"\r\n");
        if (!pkgtail)
            goto _exit_func;

        m_len = pkgtail -pkghead;
        LOG("m_len2 = %d",m_len);

    }
_exit_func:
    pLockX->Release();
    return;

}


unsigned char CGPS::GPSCNRCheckSum(char *buf, int size)
{
    int i = 0 ;
    char chksum=0, chksum2=0;

    if(size < 5)
        return false;

    chksum = buf[1];
    for(i = 2; i < (size - 2); i++)
    {
        if(buf[i] != '*')
        {
            chksum ^= buf[i];
        }
        else
        {
            if(buf[i + 1] >= 'A')
            {
                chksum2 = (buf[i+1]-'A'+10)<<4;
            }
            else
            {
                chksum2 = (buf[i+1]-'0')<<4;
            }

            if(buf[i + 2] >= 'A')
            {
                chksum2 += buf[i+2]-'A'+10;
            }
            else
            {
                chksum2 += buf[i+2]-'0';
            }
            break;
        }
    }

    /* if not found character '*' */
    if(i == (size - 2))
    {
        return (false);
    }

    if(chksum == chksum2)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}


void CGPS::SetCNRModeSvid(int sys_idx, int Svid)
{
    m_CNRMode_Svid[sys_idx] = Svid;
}





