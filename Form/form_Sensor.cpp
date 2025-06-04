//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "misc.h"
#include "form_Sensor.h"

#ifndef  _METAAPP_COMMON_H_
#include "METAAPP_common.h"
#endif

#ifndef _LOGGER_H
#include "Logger.h"
#endif

#ifndef FORMPOSITONSETTING_H_
#include "FormPositionSetting.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSensor *frmSensor;

void CNF_GS_Perform_Calibration(void)
{
    frmSensor->CNF_GS_Perform_Calibration();
}

void CNF_GYRO_Perform_Calibration(void)
{
    frmSensor->CNF_GYRO_Perform_Calibration();
}

void CNF_GS_Write_NVRAM(void)
{
    frmSensor->CNF_GS_Write_NVRAM();
}

void CNF_GYRO_Write_NVRAM(void)
{
    frmSensor->CNF_GYRO_Write_NVRAM();
}
//---------------------------------------------------------------------------
__fastcall TfrmSensor::TfrmSensor(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmSensor::SetStatusBarString(char *strInfo)
{
    stInfo->Caption = (AnsiString) strInfo;
}
//---------------------------------------------------------------------------
void TfrmSensor::SetGYROStatusBarString(char *strInfo)
{
    stGYROInfo->Caption = (AnsiString) strInfo;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSensor::btnPerformCalibrationClick(TObject *Sender)
{
    int numSample = 0;
    int samDelay = 0;
    int tolerance = 0;
    if(false == IsValidDecGSensorData(ENumberSample->Text, numSample))
    {
        SetStatusBarString(" Error: Number of Sample value is not valid");
        return;
    }
    if(false == IsValidDecGSensorData(ESampleDelay->Text, samDelay))
    {
        SetStatusBarString(" Error: Sample delay value is not valid");
        return;
    }
    if(false == IsValidDecGSensorData(ETolerance->Text, tolerance))
    {
        SetStatusBarString(" Error: Tolerance value is not valid");
        return;
    }
    SetStatusBarString(" G-Sensor Perform Calibration processing...");

    m_cGSensor_Obj.m_gs_cmd_cali.num = numSample;
    m_cGSensor_Obj.m_gs_cmd_cali.delay = samDelay;
    m_cGSensor_Obj.m_gs_cmd_cali.tolerance = tolerance;


    m_cGSensor_Obj.REQ_Start(GS_Perform_Calibration, ::CNF_GS_Perform_Calibration);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSensor::btnWriteNvramClick(TObject *Sender)
{
    m_cGSensor_Obj.m_gs_cmd_write_nvram.x =  m_cGSensor_Obj.m_gs_ack_caliCnf.x;
    m_cGSensor_Obj.m_gs_cmd_write_nvram.y =  m_cGSensor_Obj.m_gs_ack_caliCnf.y;
    m_cGSensor_Obj.m_gs_cmd_write_nvram.z =  m_cGSensor_Obj.m_gs_ack_caliCnf.z;

    SetStatusBarString(" G-Sensor Write Nvram processing...");
    m_cGSensor_Obj.REQ_Start(GS_Write_NVRAM, ::CNF_GS_Write_NVRAM);
}
//---------------------------------------------------------------------------
float TfrmSensor::GS_InttoFloat(int input)
{
    return(((input*(9.80665f))/65536)) ;
}
//---------------------------------------------------------------------------
float TfrmSensor::GYRO_InttoFloat(int input)
{
    return(((input*(9.80665f))/65536)) ;
}
//---------------------------------------------------------------------------
void TfrmSensor::CNF_GS_Perform_Calibration(void)
{
    int state = m_cGSensor_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
        SetStatusBarString(" G-Sensor Perform Calibration success");
        EXaxis->Caption = FloatToStr(GS_InttoFloat(m_cGSensor_Obj.m_gs_ack_caliCnf.x));
        EYaxis->Caption = FloatToStr(GS_InttoFloat(m_cGSensor_Obj.m_gs_ack_caliCnf.y));
        EZaxis->Caption = FloatToStr(GS_InttoFloat(m_cGSensor_Obj.m_gs_ack_caliCnf.z));
        EStatus->Caption = "OK";
        break;
    case META_FAILED:
        SetStatusBarString(" G-Sensor Perform Calibration Fail");
        EStatus->Caption = "Fail";
        break;
    case META_TIMEOUT:
        SetStatusBarString(" G-Sensor Perform Calibration Time out");
        EStatus->Caption = "Time out";
        break;
    case METAAPP_STOP:
        SetStatusBarString(" G-Sensor Perform Calibration Stop");
        EStatus->Caption = "Stop";
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmSensor::CNF_GYRO_Perform_Calibration(void)
{
    int state = m_cGYROSensor_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
        SetGYROStatusBarString(" GYRO Perform Calibration success");
        GYROEXaxis->Caption = m_cGYROSensor_Obj.m_gyro_ack_caliCnf.x;
        GYROEYaxis->Caption = m_cGYROSensor_Obj.m_gyro_ack_caliCnf.y;
        GYROEZaxis->Caption = m_cGYROSensor_Obj.m_gyro_ack_caliCnf.z;
        GYROEStatus->Caption = "OK";
        break;
    case META_FAILED:
        SetGYROStatusBarString(" GYRO Perform Calibration Fail");
        GYROEStatus->Caption = "Fail";
        break;
    case META_TIMEOUT:
        SetGYROStatusBarString(" GYRO Perform Calibration Time out");
        GYROEStatus->Caption = "Time out";
        break;
    case METAAPP_STOP:
        SetGYROStatusBarString(" GYRO Perform Calibration Stop");
        GYROEStatus->Caption = "Stop";
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmSensor::CNF_GS_Write_NVRAM(void)
{
    int state = m_cGSensor_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
        SetStatusBarString(" G-Sensor Write Nvram success");
        break;
    case META_FAILED:
        SetStatusBarString(" G-Sensor Write Nvram Fail");
        break;
    case META_TIMEOUT:
        SetStatusBarString(" G-Sensor Write Nvram Time out");
        break;
    case METAAPP_STOP:
        SetStatusBarString(" G-Sensor Write Nvram Stop");
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void TfrmSensor::CNF_GYRO_Write_NVRAM(void)
{
    int state = m_cGYROSensor_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
        SetGYROStatusBarString(" GYRO Write Nvram success");
        break;
    case META_FAILED:
        SetGYROStatusBarString(" GYRO Write Nvram Fail");
        break;
    case META_TIMEOUT:
        SetGYROStatusBarString(" GYRO Write Nvram Time out");
        break;
    case METAAPP_STOP:
        SetGYROStatusBarString(" GYRO Write Nvram Stop");
        break;
    default:
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmSensor::btnPerformCalibrationGYROClick(
    TObject *Sender)
{
    int numSample = 0;
    int samDelay = 0;
    int tolerance = 0;
    if(false == IsValidDecGYROSensorData(GYROENumberSample->Text, numSample))
    {
        SetGYROStatusBarString(" Error: Number of Sample value is not valid");
        return;
    }
    if(false == IsValidDecGYROSensorData(GYROESampleDelay->Text, samDelay))
    {
        SetGYROStatusBarString(" Error: Sample delay value is not valid");
        return;
    }
    if(false == IsValidDecGYROSensorData(GYROETolerance->Text, tolerance))
    {
        SetGYROStatusBarString(" Error: Tolerance value is not valid");
        return;
    }
    SetGYROStatusBarString(" GYRO Perform Calibration processing...");

    m_cGYROSensor_Obj.m_gyro_cmd_cali.num = numSample;
    m_cGYROSensor_Obj.m_gyro_cmd_cali.delay = samDelay;
    m_cGYROSensor_Obj.m_gyro_cmd_cali.tolerance = tolerance;


    m_cGYROSensor_Obj.REQ_Start(GYRO_Perform_Calibration, ::CNF_GYRO_Perform_Calibration);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSensor::btnWriteNvramGYROClick(TObject *Sender)
{
    m_cGYROSensor_Obj.m_gyro_cmd_write_nvram.x =  m_cGYROSensor_Obj.m_gyro_ack_caliCnf.x;
    m_cGYROSensor_Obj.m_gyro_cmd_write_nvram.y =  m_cGYROSensor_Obj.m_gyro_ack_caliCnf.y;
    m_cGYROSensor_Obj.m_gyro_cmd_write_nvram.z =  m_cGYROSensor_Obj.m_gyro_ack_caliCnf.z;

    SetGYROStatusBarString(" GYRO Write Nvram processing...");
    m_cGYROSensor_Obj.REQ_Start(GYRO_Write_NVRAM, ::CNF_GYRO_Write_NVRAM);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSensor::FormShow(TObject *Sender)
{
    LOG("Sensor form center the form.");
    FormPositionSetting::CenterForm(this);
}
//---------------------------------------------------------------------------
