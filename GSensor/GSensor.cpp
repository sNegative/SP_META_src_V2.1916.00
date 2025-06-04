
#pragma hdrstop
#include "metaapp_common.h"
#include "GSensor.h"
#include "man_active.h"
#include "LogicalControlBase.h"
static CGSensor*  g_gsensor_ptr;

static void REQ_GS_Perform_Calibration(void)
{
    g_gsensor_ptr->REQ_GS_Perform_Calibration();
}
static void REQ_GS_Write_Nvram(void)
{
    g_gsensor_ptr->REQ_GS_Write_Nvram();
}
void CGSensor::REQ_Start(REQ_CMDTYPE rct, void (*cb)(void))
{
    ConfirmCallback = cb;
    g_gsensor_ptr = this;
    m_bIsRunning = true;

    switch(rct)
    {
    case GS_Perform_Calibration:
        ActiveMan->SetActiveFunction(::REQ_GS_Perform_Calibration);
        break;
    case GS_Write_NVRAM:
        ActiveMan->SetActiveFunction(::REQ_GS_Write_Nvram);
        break;
    default:
        break;
    }
}
void CGSensor::REQ_GS_Perform_Calibration(void)
{
    DoMetaResult(SP_META_GS_Perform_Calibration_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &m_gs_cmd_cali, &m_gs_ack_caliCnf));
}

void CGSensor::REQ_GS_Write_Nvram(void)
{
    DoMetaResult(SP_META_GS_Write_NVRAM_r(m_META_HANDLE_Obj.Get_MainHandle(), 3000, &m_gs_cmd_write_nvram, &m_gs_ack_write_nvramCnf));
}

