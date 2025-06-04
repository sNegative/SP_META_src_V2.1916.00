
#pragma hdrstop
#include "metaapp_common.h"
#include "GYROSensor.h"
#include "man_active.h"
#include "LogicalControlBase.h"
static CGYROSensor*  g_gyrosensor_ptr;

static void REQ_GYRO_Perform_Calibration(void)
{
    g_gyrosensor_ptr->REQ_GYRO_Perform_Calibration();
}
static void REQ_GYRO_Write_Nvram(void)
{
    g_gyrosensor_ptr->REQ_GYRO_Write_Nvram();
}
void CGYROSensor::REQ_Start(REQ_CMDTYPE rct, void (*cb)(void))
{
    ConfirmCallback = cb;
    g_gyrosensor_ptr = this;
    m_bIsRunning = true;

    switch(rct)
    {
    case GYRO_Perform_Calibration:
        ActiveMan->SetActiveFunction(::REQ_GYRO_Perform_Calibration);
        break;
    case GYRO_Write_NVRAM:
        ActiveMan->SetActiveFunction(::REQ_GYRO_Write_Nvram);
        break;
    default:
        break;
    }
}
void CGYROSensor::REQ_GYRO_Perform_Calibration(void)
{
    DoMetaResult(SP_META_GYRO_Perform_Calibration_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &m_gyro_cmd_cali, &m_gyro_ack_caliCnf));
}

void CGYROSensor::REQ_GYRO_Write_Nvram(void)
{
    DoMetaResult(SP_META_GYRO_Write_NVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 4000, &m_gyro_cmd_write_nvram, &m_gyro_ack_write_nvramCnf));
}

