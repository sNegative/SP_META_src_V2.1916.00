#ifndef  _GYROSensor_H_
#define  _GYROSensor_H_
#include "LogicalControlBase.h"
#include "meta.h"
#include "man_handle.h"

class  CGYROSensor: public CLogicalControlBase
{
public:

    void REQ_Start(REQ_CMDTYPE rct, void (*cb)(void));
    void REQ_GYRO_Perform_Calibration(void);
    void REQ_GYRO_Write_Nvram(void);
    GYRO_CMD_CALI m_gyro_cmd_cali;
    GYRO_ACK_CALI m_gyro_ack_caliCnf;

    GYRO_CMD_WRITE_NVRAM m_gyro_cmd_write_nvram;
    GYRO_ACK_WRITE_NVRAM m_gyro_ack_write_nvramCnf;
};
#endif



