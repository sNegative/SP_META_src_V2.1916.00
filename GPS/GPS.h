#ifndef  _GPS_H_
#define  _GPS_H_
#include "LogicalControlBase.h"
#include "meta.h"
#include "man_handle.h"
#include <Classes.hpp>

typedef struct
{
    HANDLE		hPostMsgDestHandle;
    GPS_CMD 		gps_cmd;
    GPS_ACK_BUF	gps_result;
} S_GPS;

typedef enum
{
    PAGEIDX_GPS_PMTK500=0,
    PAGEIDX_GPS_PMTK705,
    PAGEIDX_GPS_PMTK514,
    PAGEIDX_GPS_PMTK813,
    PAGEIDX_GPS_PMTK814,
    PAGEIDX_GPS_PMTK815,
    PAGEIDX_GPS_PMTK812,
    PAGEIDX_GPS_PMTK811,
    PAGEIDX_GPS_PMTK810,
    PAGEIDX_GPS_PMTK817,
    PAGEIDX_GPS_GPGSV
} E_GPS_PAGEIDX;

typedef enum
{
    PAGEIDX_GPS_PMTK500_ERROR=0,
    PAGEIDX_GPS_PMTK705_ERROR,
    PAGEIDX_GPS_PMTK514_ERROR,
    PAGEIDX_GPS_PMTK813_ERROR,
    PAGEIDX_GPS_PMTK814_ERROR,
    PAGEIDX_GPS_PMTK815_CNR_MEAN_ERROR,
    PAGEIDX_GPS_PMTK815_CNR_SIGMA_ERROR,
    PAGEIDX_GPS_PMTK815_TCXO_OFFSET_ERROR,
    PAGEIDX_GPS_PMTK815_TCXO_DRIFT_ERROR,
    PAGEIDX_GPS_PMTK815_Phase_ERROR,
    PAGEIDX_GPS_PMTK812_ERROR,
    PAGEIDX_GPS_PMTK811_ERROR,
    PAGEIDX_GPS_PMTK810_ERROR,
    PAGEIDX_GPS_PKG_ERROR,
    PAGEIDX_GPS_PMTK001_ERROR,
    PAGEIDX_GPS_PMTK817_CNR_ERROR,
    PAGEIDX_GPS_PMTK817_CLOCK_DRIFT_ERROR,
    PAGEIDX_GPS_GPGSV_CNR_ERROR,
} E_GPS_PAGEIDX_ERROR;

typedef enum 
{
	SATELLITE_GPS = 0,
	SATELLITE_BEIDOU,
	SATELLITE_GLONASS,
	SATELLITE_END = 0xffffffff

}SATELLITE_SYS;

#define SATELLITE_COUNT 3

#define NUM_CH  20

typedef struct SVInfo
{
    int SVid;            // PRN
    float SNR;
    int elv;             // elevation angle : 0~90
    int azimuth;         // azimuth : 0~360
    unsigned char Fix;   // 0:None , 1:FixSV
} SVInfo;

class  CGPS: public CLogicalControlBase
{
private:
    AnsiString as_Phase;
    AnsiString as_TCXO_Offset;
    AnsiString as_TCXO_Drift;
    AnsiString as_CNR_Mean;
    AnsiString as_CNR_Sigma;
    AnsiString as_UpdateHz;
    AnsiString as_BitSync;
    AnsiString as_Acquisition;
    AnsiString as_GPSVersion;
    AnsiString as_CWCNR;
    AnsiString as_CWCNRVariation;

    AnsiString as_CNRModeCNR;
    AnsiString as_CNRModeCNRVariation;
//
public:
    void REQ_Start(REQ_CMDTYPE rct, void (*cb)(void));
    void REQ_GPS_Open(void);
    void REQ_GPS_Close(void);
    void REQ_GPS_SendCommand_PMTK810(void);

    void REQ_GPS_SendCommand_PMTK811(void);
//
    void REQ_GPS_Open_Close_HWT(void);

    bool				m_bOk;
    GPS_CMD		m_OpenReq;
    GPS_ACK_BUF	m_OpenCnf;
    GPS_CMD		m_CloseReq;
    GPS_ACK_BUF	m_CloseCnf;
    S_GPS			m_sGPS;
    bool				m_bEventOk;
    bool				m_bDataOk;

    float 	        m_UpdateHz;
    int 		m_Acquisition;
    int		m_BitSync;
    float		m_Phase;
    float		m_TCXO_Offset;
    float		m_TCXO_Drift;
    float		m_CNR_Mean;
    float		m_CNR_Sigma;
    bool		m_bUpdateHz;
    bool		m_bAcquisition;
    bool		m_bBitSync;
    bool		m_bPhase;
    bool		m_bTCXO_Offset;
    bool		m_bTCXO_Drift;
    bool		m_bCNR_Mean;
    bool		m_bCNR_Sigma;
    unsigned int 	m_len;
    bool 	        m_bVersionFlag;

    bool            m_bCWNR;
    bool            m_bCWClockDrift;
    float		m_CWCNR;
    float		m_CWClockDrift;
    bool DeCompose_GPS_PMTK817(char *gps_buf);
    void REQ_GPS_SendStartCommand_PMTK817(void);
    void REQ_GPS_SendStopCommand_PMTK817(void);
    void __stdcall CNF_GPSSendStartCommand_PMTK817(const GPS_ACK_BUF*cnf, const short token, void *usrData);

    bool           m_bCNRModeCNR[SATELLITE_COUNT];
    float          m_CNRMode_CNR[SATELLITE_COUNT];
    int            m_CNRMode_Svid[SATELLITE_COUNT];
    int            m_GPSSV_cnt[SATELLITE_COUNT];
    SVInfo         m_svInfo[SATELLITE_COUNT][NUM_CH];
    unsigned char GPSCNRCheckSum(char *buf, int size);
    void SetCNRModeSvid(int sys_idx, int Svid);
    bool DeCompose_GPS_GPGSV(int sys_idx, char *gps_buf);
    void REQ_GPS_SendCNRStartCommand_PMTK810(void);
    void REQ_GPS_SendCNRStopCommand_PMTK811(void);
    void __stdcall CNF_GPSSendCNRStartCommand_PMTK810(const GPS_ACK_BUF*cnf, const short token, void *usrData);

    bool DeCompose_GPS_PMTK500(char *gps_buf);
    bool DeCompose_GPS_PMTK813(char *gps_buf);
    bool DeCompose_GPS_PMTK814(char *gps_buf);
    bool DeCompose_GPS_PMTK815(char *gps_buf);
    bool DeCompose_GPS_PMTK705(char * gps_buf);

    void __stdcall CNF_GPSSendCommand_PMTK810(const GPS_ACK_BUF*cnf, const short token, void *usrData);

    bool FetchField(char *start, char *result);

    bool ReadFromIniFile(AnsiString as);
    AnsiString GetGPSVersion(void);
    void SetGPSVersion(AnsiString as);
    void CWTest(void);
    void JudgeCNRValue(float CNRAverage,float ClockDriftAverage);

    bool TestGNSS_DeCompose_GPS_GPGSV(int sys_idx, char *gps_buf);
//
};

#endif
