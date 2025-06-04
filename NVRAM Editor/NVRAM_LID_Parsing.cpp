#include <vcl.h>
#pragma hdrstop

#include "NVRAM_LID_Parsing.h"

char LID_String[][50] =
{
    // system LID
    "NVRAM_EF_SYS_EXCEPTION_LID", // 0
    "NVRAM_EF_SYS_STATISTICS_LID",// 1
    "NVRAM_EF_SYS_RESERVED0_LID", // 2
    "NVRAM_EF_SYS_RESERVED1_LID", // 3
    "NVRAM_EF_SYS_RESERVED2_LID", // 4
    "NVRAM_EF_SYS_RESERVED3_LID", // 5
    "NVRAM_EF_SYS_RESERVED4_LID", // 6
    "NVRAM_EF_SYS_RESERVED5_LID", // 7
    "NVRAM_EF_SYS_RESERVED6_LID", // 8
    "NVRAM_EF_SYS_RESERVED7_LID", // 9
    "NVRAM_EF_SYS_RESERVED8_LID", // 10
    "NVRAM_EF_SYS_RESERVED9_LID", // 11

    // L1 LID
    "NVRAM_EF_L1_AGCPATHLOSS_LID", // 12
    "NVRAM_EF_L1_RAMPTABLE_GSM900_LID", // 13
    "NVRAM_EF_L1_RAMPTABLE_DCS1800_LID", // 14
    "NVRAM_EF_L1_RAMPTABLE_PCS1900_LID", // 15
    "NVRAM_EF_L1_AFCDATA_LID", // 15
    "NVRAM_EF_L1_L1SPFC_LID",  // 16
    "NVRAM_EF_L1_TXIQ_LID",    // 17

    // other LID
    "NVRAM_EF_TST_FILTER_LID", // 18
    "NVRAM_EF_MSCAP_LID",      // 19
    "NVRAM_EF_IMEI_IMEISV_LID",// 20
    "NVRAM_EF_IMSI_LID",       // 21
    "NVRAM_EF_CLASSMARK1_LID", // 22
    "NVRAM_EF_CLASSMARK2_LID", // 23
    "NVRAM_EF_CLASSMARK3_LID", // 24
    "NVRAM_EF_EXTBCCH1_LID",   // 25
    "NVRAM_EF_EXTBCCH2_LID",   // 26
    "NVRAM_EF_MS_SECURITY_LID",// 27
    "NVRAM_EF_DRX_PARAM_LID",  // 28
    "NVRAM_EF_MS_RA_CAP_LID",  // 29
    "NVRAM_EF_MS_NW_CAP_LID",  // 30
    "AP_CFG_RDCL_FILE_AUXADC_LID", //"NVRAM_EF_ADC_LID",        // 31



    "NVRAM_EF_PHB_LID",        // 32
    "NVRAM_EF_UEM_MANUFACTURE_DATA_LID", // 33
    "NVRAM_EF_UEM_RMI_DATA_LID", // 34
    "NVRAM_EF_UEM_ACOUSTIC_DATA_LID", // 35
    "NVRAM_EF_SMSAL_COMMON_PARAM_LID", // 36
    "NVRAM_EF_SMSAL_MWIS_LID",         // 37
    "NVRAM_EF_SMSAL_MAILBOX_ADDR_LID", // 38
    "NVRAM_EF_SMSAL_SMS_LID",          // 39
    "NVRAM_EF_SMS_LIB_LID",            // 40
    "NVRAM_EF_RAC_PREFERENCE_LID",     // 41
    "NVRAM_EF_TCM_STATISTICS_LID",     // 42
    "NVRAM_EF_TCM_PDP_PROFILE_LID",    // 43

    "NVRAM_EF_LAST_LID_VENDOR"         // 44
} ;

int Determine_LID_Category(char *LID_Name_para)
{
    AnsiString as_LID_Name = LID_Name_para;

    if( as_LID_Name.Pos("AP_CFG_RDEB") )
    {
        return RDEB_LID_CATEGORY;//SYSTEM_RELATED_LID_CATEGORY;
    }
    else if( as_LID_Name.Pos("AP_CFG_RDCL") )
    {
        return RDCL_LID_CATEGORY;//L1_CALIBRATION_LID_CATEGORY;
    }
    else
        return OTHER_LID_CATEGORY;
}
