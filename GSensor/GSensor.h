#ifndef  _GSensor_H_
#define  _GSensor_H_
#include "LogicalControlBase.h"
#include "meta.h"
#include "man_handle.h"

class  CGSensor: public CLogicalControlBase
{
public:

    void REQ_Start(REQ_CMDTYPE rct, void (*cb)(void));
    void REQ_GS_Perform_Calibration(void);
    void REQ_GS_Write_Nvram(void);
    GS_CMD_CALI m_gs_cmd_cali;
    GS_ACK_CALI m_gs_ack_caliCnf;

    GS_CMD_WRITE_NVRAM m_gs_cmd_write_nvram;
    GS_ACK_WRITE_NVRAM m_gs_ack_write_nvramCnf;


};
#endif



