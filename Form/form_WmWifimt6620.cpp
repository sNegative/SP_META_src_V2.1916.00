//---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>                                 
#pragma hdrstop

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

#include "form_WmWifimt6620.h"

#include "METAAPP_common.h"
#include "form_main.h"
#include "misc.h"
#include "man_fdm.h"

#ifndef form_2GH_TX_Power_ProfileH
#include "form_2GH_TX_Power_Profile.h"
#endif

#ifndef form_5GHz_TX_Power_ProfileH
#include "form_5GHz_TX_Power_Profile.h"
#endif

#ifndef form_Crystal_TrimH
#include "form_Crystal_Trim.h"
#endif

#ifndef form_WiFiRSSICOMPH
#include "form_WiFiRSSICOMP.h"
#endif

#ifndef form_WiFi6632RSSICOMPH
#include "form_WiFi6632RSSICOMP.h"
#endif
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#ifndef LOCK_H_
#include "lock.h"
#endif

TfrmWmWifiMT6620 *frmWmWifiMT6620;


extern E_WIFI_STATE g_eWiFiState;

typedef struct _RF_CHANNEL_PROG_ENTRY
{
    unsigned long      chnlNum;
    unsigned long      chnlFreq;
} RF_CHANNEL_PROG_ENTRY, *PRF_CHANNEL_PROG_ENTRY;

typedef struct _DATA_RATE_SETTING
{
    char* pszRate;
    int   i4BBHwVal;
    unsigned char ucRateGruopEep;
    bool  fgIsCCK;
} DATA_RATE_SETTING, *P_DATA_RATE_SETTING;

typedef enum _PARAM_DEVICE_POWER_STATE
{
    ParamDeviceStateUnspecified = 0,
    ParamDeviceStateD0,
    ParamDeviceStateD1,
    ParamDeviceStateD2,
    ParamDeviceStateD3,
    ParamDeviceStateMaximum
} PARAM_DEVICE_POWER_STATE, *PPARAM_DEVICE_POWER_STATE;

typedef struct _GEN2_CHIP_ID
{
    unsigned long DdieChipId;
    unsigned long ComboChipId;
} GEN2_CHIP_ID, *P_GEN2_CHIP_ID;

#define CH_1     0x0
#define CH_2     0x1
#define CH_3     0x2
#define CH_4     0x3
#define CH_5     0x4
#define CH_6     0x5
#define CH_7     0x6
#define CH_8     0x7
#define CH_9     0x8
#define CH_10    0x9
#define CH_11    0xa
#define CH_12    0xb
#define CH_13    0xc
#define CH_14    0xd
#define CH_16    15
#define CH_36    35
#define CH_40    39
#define CH_44    43
#define CH_48    47
#define CH_52    51
#define CH_56    55
#define CH_60    59
#define CH_64    63
#define CH_68    67
#define CH_72    71
#define CH_76    75
#define CH_80    79
#define CH_84    83
#define CH_88    87
#define CH_92    91
#define CH_96    95
#define CH_100   99
#define CH_104   103
#define CH_108   107
#define CH_112   111
#define CH_116   115
#define CH_120   119
#define CH_124   123
#define CH_128   127
#define CH_132   131
#define CH_136   135
#define CH_140   139
#define CH_144   143
#define CH_149   148
#define CH_153   152
#define CH_157   156
#define CH_161   160
#define CH_165   164
#define CH_169   168
#define CH_173   172
#define CH_177   176
#define CH_181   180
#define CH_184   183
#define CH_188   187
#define CH_192   191
#define CH_196   195

//BW20
const RF_CHANNEL_PROG_ENTRY chnlListmt6620_20[] =
{
    { CH_1,    2412000},
    { CH_2,    2417000},
    { CH_3,    2422000},
    { CH_4,    2427000},
    { CH_5,    2432000},
    { CH_6,    2437000},
    { CH_7,    2442000},
    { CH_8,    2447000},
    { CH_9,    2452000},
    { CH_10,   2457000},
    { CH_11,   2462000},
    { CH_12,   2467000},
    { CH_13,   2472000},
    { CH_14,   2484000},
    { CH_184,  4920000},
    { CH_188,  4940000},
    { CH_192,  4960000},
    { CH_196,  4980000},
    { CH_8,    5040000},
    { CH_12,   5060000},
    { CH_16,   5080000},
    { CH_36,   5180000},
    { CH_40,   5200000},
    { CH_44,   5220000},
    { CH_48,   5240000},
    { CH_52,   5260000},
    { CH_56,   5280000},
    { CH_60,   5300000},
    { CH_64,   5320000},
    { CH_68,   5340000},
    { CH_72,   5360000},
    { CH_76,   5380000},
    { CH_80,   5400000},
    { CH_84,   5420000},
    { CH_88,   5440000},
    { CH_92,   5460000},
    { CH_96,   5480000},
    { CH_100,  5500000},
    { CH_104,  5520000},
    { CH_108,  5540000},
    { CH_112,  5560000},
    { CH_116,  5580000},
    { CH_120,  5600000},
    { CH_124,  5620000},
    { CH_128,  5640000},
    { CH_132,  5660000},
    { CH_136,  5680000},
    { CH_140,  5700000},
    { CH_144,  5720000},
    { CH_149,  5745000},
    { CH_153,  5765000},
    { CH_157,  5785000},
    { CH_161,  5805000},
    { CH_165,  5825000},
    { CH_169,  5845000},
    { CH_173,  5865000},
    { CH_177,  5885000},
    { CH_181,  5905000}
};

//BW20
const RF_CHANNEL_PROG_ENTRY chnlListmt6620_20_band1[] =
{
    { CH_184,  4920000},
    { CH_188,  4940000},
    { CH_192,  4960000},
    { CH_196,  4980000},
    { CH_8,    5040000},
    { CH_12,   5060000},
    { CH_16,   5080000},
    { CH_36,   5180000},
    { CH_40,   5200000},
    { CH_44,   5220000},
    { CH_48,   5240000},
    { CH_52,   5260000},
    { CH_56,   5280000},
    { CH_60,   5300000},
    { CH_64,   5320000},
    { CH_68,   5340000},
    { CH_72,   5360000},
    { CH_76,   5380000},
    { CH_80,   5400000},
    { CH_84,   5420000},
    { CH_88,   5440000},
    { CH_92,   5460000},
    { CH_96,   5480000},
    { CH_100,  5500000},
    { CH_104,  5520000},
    { CH_108,  5540000},
    { CH_112,  5560000},
    { CH_116,  5580000},
    { CH_120,  5600000},
    { CH_124,  5620000},
    { CH_128,  5640000},
    { CH_132,  5660000},
    { CH_136,  5680000},
    { CH_140,  5700000},
    { CH_144,  5720000},
    { CH_149,  5745000},
    { CH_153,  5765000},
    { CH_157,  5785000},
    { CH_161,  5805000},
    { CH_165,  5825000},
    { CH_169,  5845000},
    { CH_173,  5865000},
    { CH_177,  5885000},
    { CH_181,  5905000}
};

#define CH_38    37
#define CH_46    45
#define CH_54    53
#define CH_62    61
#define CH_70    69
#define CH_78    77
#define CH_86    85
#define CH_94    93
#define CH_102   101
#define CH_110   109
#define CH_118   117
#define CH_126   125
#define CH_134   133
#define CH_142   141
#define CH_151   150
#define CH_159   158
#define CH_167   166
#define CH_175   174
#define CH_186   185
#define CH_194   193


//BW40
const RF_CHANNEL_PROG_ENTRY chnlListmt6620_40[] =
{
    { CH_1,    2412000},
    { CH_2,    2417000},
    { CH_3,    2422000},
    { CH_4,    2427000},
    { CH_5,    2432000},
    { CH_6,    2437000},
    { CH_7,    2442000},
    { CH_8,    2447000},
    { CH_9,    2452000},
    { CH_10,   2457000},
    { CH_11,   2462000},
    { CH_12,   2467000},
    { CH_13,   2472000},
    { CH_14,   2484000},
    { CH_186,  4930000},
    { CH_194,  4970000},
    { CH_38,   5190000},
    { CH_46,   5230000},
    { CH_54,   5270000},
    { CH_62,   5310000},
    { CH_70,   5350000},
    { CH_78,   5390000},
    { CH_86,   5430000},
    { CH_94,   5470000},
    { CH_102,  5510000},
    { CH_110,  5550000},
    { CH_118,  5590000},
    { CH_126,  5630000},
    { CH_134,  5670000},
    { CH_142,  5710000},
    { CH_151,  5755000},
    { CH_159,  5795000},
    { CH_167,  5835000},
    { CH_175,  5875000}

};

//BW40
const RF_CHANNEL_PROG_ENTRY chnlListmt6620_40_band1[] =
{
    { CH_186,  4930000},
    { CH_194,  4970000},
    { CH_38,   5190000},
    { CH_46,   5230000},
    { CH_54,   5270000},
    { CH_62,   5310000},
    { CH_70,   5350000},
    { CH_78,   5390000},
    { CH_86,   5430000},
    { CH_94,   5470000},
    { CH_102,  5510000},
    { CH_110,  5550000},
    { CH_118,  5590000},
    { CH_126,  5630000},
    { CH_134,  5670000},
    { CH_142,  5710000},
    { CH_151,  5755000},
    { CH_159,  5795000},
    { CH_167,  5835000},
    { CH_175,  5875000}

};

#define CH_42   41
#define CH_58   57
#define CH_74   73
#define CH_90   89
#define CH_106  105
#define CH_122  121
#define CH_138  137
#define CH_155  154
#define CH_171  170

//BW80
const RF_CHANNEL_PROG_ENTRY chnlListmt6620_80[] =
{
    { CH_42,   5210000},
    { CH_58,   5290000},
    { CH_74,   5370000},
    { CH_90,   5450000},
    { CH_106,  5530000},
    { CH_122,  5610000},
    { CH_138,  5690000},
    { CH_155,  5775000},
    { CH_171,  5855000}

};

const RF_CHANNEL_PROG_ENTRY chnlListmt6620_80_band1[] =
{
    { CH_42,   5210000},
    { CH_58,   5290000},
    { CH_74,   5370000},
    { CH_90,   5450000},
    { CH_106,  5530000},
    { CH_122,  5610000},
    { CH_138,  5690000},
    { CH_155,  5775000},
    { CH_171,  5855000}

};

#define CH_50   49
#define CH_82   81
#define CH_114  113
#define CH_163  162

//BW160
const RF_CHANNEL_PROG_ENTRY chnlListmt6620_160[] =
{
    { CH_50,   5250000},
    { CH_82,   5410000},
    { CH_114,  5570000},
    { CH_163,  5815000}

};

#define CH_183   182
#define CH_185   184
#define CH_187   186
#define CH_189   188

//J mode BW5
const RF_CHANNEL_PROG_ENTRY chnlListmt6620_5[] =
{
    { CH_183,    4915000},
    { CH_184,    4920000},
    { CH_185,    4925000},
    { CH_187,    4935000},
    { CH_188,    4940000},
    { CH_189,    4945000},
    { CH_7,      5035000},
    { CH_8,      5040000},
    { CH_9,      5045000},
    { CH_11,     5055000}

};
//J mode BW10
const RF_CHANNEL_PROG_ENTRY chnlListmt6620_10[] =
{
    { CH_183,    4915000},
    { CH_184,    4920000},
    { CH_185,    4925000},
    { CH_187,    4935000},
    { CH_188,    4940000},
    { CH_189,    4945000},
    { CH_7,      5035000},
    { CH_8,      5040000},
    { CH_9,      5045000},
    { CH_11,     5055000}

};


#define EEPROM_RATE_GROUP_CCK              0x0
#define EEPROM_RATE_GROUP_OFDM_6_9M        0x1
#define EEPROM_RATE_GROUP_OFDM_12_18M      0x2
#define EEPROM_RATE_GROUP_OFDM_24_36M      0x3
#define EEPROM_RATE_GROUP_OFDM_48_54M      0x4
#define EEPROM_RATE_GROUP_MCS              0x5


#define TXRXIQCalibration   37
#define TSSICalibration     38
#define DPDCalibration      39
#define RXVentordump        40
#define RXStatistics        41
#define Measurement         42


DATA_RATE_SETTING rateSettingmt6620[] =
{
    {"1M",     0x00000000,  EEPROM_RATE_GROUP_CCK,         TRUE},
    {"2M",     0x00000001,  EEPROM_RATE_GROUP_CCK,         TRUE},
    {"5.5M",   0x00000002,  EEPROM_RATE_GROUP_CCK,         TRUE},
    {"11M",    0x00000003,  EEPROM_RATE_GROUP_CCK,         TRUE},
    {"6M",     0x00000004,  EEPROM_RATE_GROUP_OFDM_6_9M,   FALSE},
    {"9M",     0x00000005,  EEPROM_RATE_GROUP_OFDM_6_9M,   FALSE},
    {"12M",    0x00000006,  EEPROM_RATE_GROUP_OFDM_12_18M, FALSE},
    {"18M",    0x00000007,  EEPROM_RATE_GROUP_OFDM_12_18M, FALSE},
    {"24M",    0x00000008,  EEPROM_RATE_GROUP_OFDM_24_36M, FALSE},
    {"36M",    0x00000009,  EEPROM_RATE_GROUP_OFDM_24_36M, FALSE},
    {"48M",    0x0000000A,  EEPROM_RATE_GROUP_OFDM_48_54M, FALSE},
    {"54M",    0x0000000B,  EEPROM_RATE_GROUP_OFDM_48_54M, FALSE},
    {"MCS0",   0x80000000,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS1",   0x80000001,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS2",   0x80000002,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS3",   0x80000003,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS4",   0x80000004,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS5",   0x80000005,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS6",   0x80000006,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS7",   0x80000007,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS8",   0x80000008,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS9",   0x80000009,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS32",  0x80000020,  EEPROM_RATE_GROUP_MCS,         FALSE}
};

DATA_RATE_SETTING rateSettingmt6632[] =
{
    {"1M",     0x00000000,  EEPROM_RATE_GROUP_CCK,         TRUE},
    {"2M",     0x00000001,  EEPROM_RATE_GROUP_CCK,         TRUE},
    {"5.5M",   0x00000002,  EEPROM_RATE_GROUP_CCK,         TRUE},
    {"11M",    0x00000003,  EEPROM_RATE_GROUP_CCK,         TRUE},
    {"6M",     0x00000004,  EEPROM_RATE_GROUP_OFDM_6_9M,   FALSE},
    {"9M",     0x00000005,  EEPROM_RATE_GROUP_OFDM_6_9M,   FALSE},
    {"12M",    0x00000006,  EEPROM_RATE_GROUP_OFDM_12_18M, FALSE},
    {"18M",    0x00000007,  EEPROM_RATE_GROUP_OFDM_12_18M, FALSE},
    {"24M",    0x00000008,  EEPROM_RATE_GROUP_OFDM_24_36M, FALSE},
    {"36M",    0x00000009,  EEPROM_RATE_GROUP_OFDM_24_36M, FALSE},
    {"48M",    0x0000000A,  EEPROM_RATE_GROUP_OFDM_48_54M, FALSE},
    {"54M",    0x0000000B,  EEPROM_RATE_GROUP_OFDM_48_54M, FALSE},
    {"MCS0",   0x80000000,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS1",   0x80000001,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS2",   0x80000002,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS3",   0x80000003,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS4",   0x80000004,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS5",   0x80000005,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS6",   0x80000006,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS7",   0x80000007,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS8",   0x80000008,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS9",   0x80000009,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS10",   0x8000000A,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS11",   0x8000000B,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS12",   0x8000000C,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS13",   0x8000000D,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS14",   0x8000000E,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS15",   0x8000000F,  EEPROM_RATE_GROUP_MCS,         FALSE},
    {"MCS32",  0x80000020,  EEPROM_RATE_GROUP_MCS,         FALSE}
//rongguo 2011-10-28
//                {"MCS32",  0x80000010,  EEPROM_RATE_GROUP_MCS,         FALSE}
};

//The comment is from WIFI FW
//Gen2 Project @20161101 Update
//
//Project Name HW_CODE(ChipID) HW_VER(ECO Version)
//=========================================
//MT6582 0x6582 0x8A00
//MT6572 0x6572 0x8A00
//MT6592 0x6592 0x8A00
//MT6571 0x6571 0x8A00
//MT8127 0x8127 0x8A00
//MT6752 (K2) 0x6752 0x8A00
//Denali 1 0x0321 0x8A00
//Denali 2 0x0335 0x8A00
//Denali 3 0x0337 0x8A00
//MT7623 (Vivaldi) 0x8590 0x8A00
//MT6580 (Rainier) 0x6580 0x8A00 / 0x8A01 / 0x8B01
//MT8163 (Giza) 0x8163 0x8A00
//
//MT6755 (Jade) 0x0326 0x8A00
//MT6750 (Jade-) 0x0326 0x8A00
//
//MT6757 (Olympus) 0x0551 0x8A00
//MT6757 (Kibo/Kibo+) 0x0551 0x8B00
//
//Shasta-L N/A N/A
//Shasta-H N/A N/A
//MT8160 (Lyra) 0x8160 0x8A00
//MT6570(Rushmore) 0x0633 0x8A00
//Bianco 0x0690 0x8A00
//Rosa 0x0326 0x8A00
//Zion 0x0699 0x8A00
#define GEN2_CHIP_ID_NUM  18
GEN2_CHIP_ID gen2ChipId[] =
{
    {0x6582,0x6625},
    {0x6572,0x6625},
    {0x6592,0x6625},
    {0x6571,0x6625},
    {0x8127,0x6625},
    {0x6752,0x6625},
    {0x0321,0x6625},
    {0x0335,0x6625},
    {0x0337,0x6625},
    {0x8590,0x6625},
    {0x6580,0x6625},
    {0x8163,0x6625},
    {0x0326,0x6625},
    {0x0551,0x6625},
    {0x8160,0x6625},
    {0x0633,0x6625},
    {0x0690,0x6625},
    {0x0699,0x6625}
};
/*
MT6631 Chip ID
Project Name	HW_CODE (Chip ID)	HW_VER
Elbrus	0x0598	0x8A00
Everest (2015H2)	0x0279	0x8A00
Alaska (2016H1)	0x0507	0x8A00
Vinson (2016H2)	0x0688	0x8A00
Alaska E2(2016H2)	0x0507	0x8B00
Sylvia  (2017 H1)	0x0788	0x8A00
Cannon  (2017 H1)	0x0713	0x8A00
*/
#define GEN3_CHIP_ID_NUM  6
GEN2_CHIP_ID gen3ChipId[] =
{
     {0x0598,0x6631},
     {0x0279,0x6631},
     {0x0507,0x6631},
     {0x0688,0x6631},
     {0x0788,0x6631},
     {0x0713,0x6631}
};

/*
Cervino 0x3031
Lafiet 0x0035
*/


extern bool g_bHideEnable;


static void CNF_WIFI_READ_EEPROM(void)
{
    frmWmWifiMT6620->CNF_WIFI_READ_EEPROM();
}

static void CNF_WIFI_READALL_EEPROM(void)
{
    frmWmWifiMT6620->CNF_WIFI_READALL_EEPROM();
}

//---------------------------------------------------------------------------
__fastcall TfrmWmWifiMT6620::TfrmWmWifiMT6620(TComponent* Owner)
    : TForm(Owner)
{
    m_bInited = false;
    redtLog->Lines->Clear();
    m_bTXTestFlag = false;
    m_bRXTestFlag = false;
    m_bTSTestFlag = false;
    m_bSwitchAntennaOK = false;
    
    m_bIsNvramFlag = false;
    m_calibrationType = 0;
    m_calibrationLength = 0;
    m_u4ThermoRunNum = 0;
    m_wifiChipVersion = 0;

    InitializeCriticalSection(&m_cs);
}

//---------------------------------------------------------------------------
void TfrmWmWifiMT6620::Init( void )
{
    META_RESULT  mr = META_FAILED;

    unsigned int u4Addr = 0;
    unsigned long u4Value = 0;

    mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, u4Addr, &u4Value);
    OutputMetaResult(" Read MCR u4Addr = 0", mr);

    if(META_SUCCESS != mr)
    {
        return;
    }
    m_wifiChipVersion = u4Value & 0xFFFF;

    LOG("WifiChipVersion = %04x", m_wifiChipVersion);

    // For Gen2 chip we get WCN chip id from MCR 0 is D die chip id,
    // Since we could not get A die chip id from AP side, so we need to map to A die chip id.
    for (int i = 0; i< GEN2_CHIP_ID_NUM; i++)
    {
        if (m_wifiChipVersion == gen2ChipId[i].DdieChipId)
        {
            m_wifiChipVersion = gen2ChipId[i].ComboChipId;
            break;
        }
    }

    for(int i = 0; i< GEN3_CHIP_ID_NUM; i++)
    {
        if (m_wifiChipVersion == gen3ChipId[i].DdieChipId)
        {
            m_wifiChipVersion = gen3ChipId[i].ComboChipId;
            break;
        }
    }

    //if(0x5931 != m_wifiChipVersion)
    if (0x6620 == m_wifiChipVersion) //MT6620
    {
        m_btnCrystalTrim->Visible = false;
        m_btnSet_5GHz_TX_Power_Profile->Visible = true;
    }
    else                              //MT6628/MT5931
    {
        m_btnCrystalTrim->Visible = true;
        if (0x6628 == m_wifiChipVersion || 0x5931 == m_wifiChipVersion)
        {
            m_btnSet_5GHz_TX_Power_Profile->Visible = false;
        }
        else
        {
            m_btnSet_5GHz_TX_Power_Profile->Visible = true;
        }
    }

    char cWifiToolTitle[200] = {0};
    sprintf(cWifiToolTitle, "WIFI Tool for MT%04x", m_wifiChipVersion);
    frmWmWifiMT6620->Caption = cWifiToolTitle;

    if( (0x6628 == m_wifiChipVersion) || (0x6630 == m_wifiChipVersion)) //MT6628 and MT6630
    {
        char  pszBufferRaw[512] = {0};
        pszBufferRaw[0] = (m_wifiChipVersion >>8) & 0x00ff;
        pszBufferRaw[1] = m_wifiChipVersion & 0x00ff;

        NVRAM_ACCESS_STRUCT wifi_nvram;
        wifi_nvram.dataLen = 2;
        wifi_nvram.dataOffset = 0x3c;
        wifi_nvram.data = pszBufferRaw;


        META_RESULT mr = m_WiFi_Man_Obj.WiFi_WriteNVRAM(1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            OutputMetaResult(" Write u2ToolVersion", mr);
        }
    }

    if ((0x6632 == m_wifiChipVersion) || (0x0035 == m_wifiChipVersion) ) //MT6632  //MT0035
    {
        rbBandwidth20->Visible = false;
        rbBandwidth40->Visible = false;
        rbBandwidthU20->Visible = false;
        rbBandwidthL20->Visible = false;
        rbAdvanceSetting->Checked = true;
        rbAdvanceSetting->Visible = false;
        GroupBox9->Visible = true;
        //
        LabelNss->Visible = true;
        cbxNss->Visible = true;
        cbTXRX0->Visible = true;
        cbTXRX1->Visible = true;
        LabelRSSI1->Visible = true;
        stRXRSSI1->Visible = true;

    }
    else
    {
        rbBandwidth20->Visible = true;
        rbBandwidth40->Visible = true;
        rbBandwidthU20->Visible = true;
        rbBandwidthL20->Visible = true;
        rbAdvanceSetting->Visible = true;
        GroupBox9->Visible = false;
        //
        LabelNss->Visible = false;
        cbxNss->Visible = false;
        cbTXRX0->Visible = false;
        cbTXRX1->Visible = false;
        LabelRSSI1->Visible = false;
        stRXRSSI1->Visible = false;
        //
    }

    m_bIsNvramFlag = false;
    ENUM_CFG_SRC_TYPE_T bufType;
    mr = m_WiFi_Man_Obj.WiFi_QueryConfig(5000, &bufType);

    if(META_SUCCESS != mr)
    {
        Label4->Caption = "EEPROM access";
        btnEESaveAsFile->Caption = "EEPROM Save As File";
        btnEEBurnFromFile->Caption = "Burn EEPROM From File";
        return;
    }
    else
    {
        if(CFG_SRC_TYPE_NVRAM == bufType)
        {
            Label4->Caption = "NVRAM access";
            btnEESaveAsFile->Caption = "NVRAM Save As File";
            btnEEBurnFromFile->Caption = "Burn NVRAM From File";
            m_bIsNvramFlag = true;
        }
        else if(CFG_SRC_TYPE_BOTH == bufType)
        {
            Label4->Caption = "NVRAM access";
            btnEESaveAsFile->Caption = "NVRAM Save As File";
            btnEEBurnFromFile->Caption = "Burn NVRAM From File";
            //btnEEToFlash->Visible = true;
            m_bIsNvramFlag = true;
        }
        else
        {
            Label4->Caption = "EEPROM access";
            btnEESaveAsFile->Caption = "EEPROM Save As File";
            btnEEBurnFromFile->Caption = "Burn EEPROM From File";
        }
    }

    mr = m_WiFi_Man_Obj.WiFi_setTestMode(5000);
    OutputMetaResult(" setTestMode", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_switchAntenna(5000, 0);
    OutputMetaResult(" switchAntenna", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_bSwitchAntennaOK = true;
//
    unsigned long antSupport = 0;

    mr = m_WiFi_Man_Obj.WiFi_queryAntSwap(5000, &antSupport);
    OutputMetaResult(" queryAntSwap", mr);
    if(META_SUCCESS == mr && antSupport == 1)
    {
        lbAntSwap->Visible = true;
        cbAntSwap->Visible = true;
        mr = m_WiFi_Man_Obj.WiFi_setAntSwap(5000, 0);
        OutputMetaResult(" setAntSwap", mr);
    }


}

//---------------------------------------------------------------------------
void TfrmWmWifiMT6620::OutputMetaResult(char *strOperator, META_RESULT result)
{
    char strInfo[256] = {0};
    unsigned int strLen = strlen(strOperator);
    if(strLen > 200)
    {
        redtLog->Lines->Add(" Error: size of param strOperator in OutputMetaResult() function is too long!");
        return;
    }
    memcpy(strInfo, strOperator, strLen);
    switch(result)
    {
    case META_SUCCESS:
        strcat(strInfo, " success");
        break;
    case META_FAILED:
        strcat(strInfo, " failed");
        break;
    case META_COMM_FAIL:
        strcat(strInfo, " comm fail");
        break;
    case META_TIMEOUT:
        strcat(strInfo, " time out");
        break;
    case META_INVALID_HANDLE:
        strcat(strInfo, " invalid handle");
        break;
    default:
        strcat(strInfo, " other error");
        break;
    }
    redtLog->Lines->Add(strInfo);
}
//---------------------------------------------------------------------------

void TfrmWmWifiMT6620::CurrentPageLock(unsigned int exceptCtl)
{
    edtMCRAddr->Enabled = false;
    edtMCRValue->Enabled = false;
    btnMCRRead->Enabled = false;
    btnMCRWrite->Enabled = false;
    edtEEWordAddr->Enabled = false;
    edtEEWordValue->Enabled = false;
    btnEEWordRead->Enabled = false;
    btnEEWordWrite->Enabled = false;
    edtEEByteStringAddr->Enabled = false;
    edtEEByteStringLength->Enabled = false;
    btnEEByteStringRead->Enabled = false;
    btnEEByteStringWrite->Enabled = false;
    edtEEByteStringValue->Enabled = false;
    btnEESaveAsFile->Enabled = false;
    btnEEBurnFromFile->Enabled = false;
    btnEEReadAll->Enabled = false;
    edtTXGain->Enabled = false;
    cbChannel->Enabled = false;
    cbRate->Enabled = false;
    cbTXTestType->Enabled = false;
    btnTXGo->Enabled = false;
    cbJapanChannel->Enabled = false;
    edtTXPktLen->Enabled = false;
    edtTXPktCnt->Enabled = false;
    btnRXGo->Enabled = false;
    btnTemperatureGo->Enabled = false;
    btnTXStop->Enabled = false;
    btnRXStop->Enabled = false;
    btnTemperatureStop->Enabled = false;
    //
    cbJMode->Enabled = false;
    cbxCBW->Enabled = false;
    cbxDBW->Enabled = false;
    cbxPrimaryCh->Enabled = false;
    //
    switch(exceptCtl)
    {
    case NONE_STOP:
        break;
    case TX_STOP:
        btnTXStop->Enabled = true;
        break;
    case RX_STOP:
        btnRXStop->Enabled = true;
        break;
    case TEMPERATURE_STOP:
        btnTemperatureStop->Enabled = true;
        break;
    default:
        break;
    }

}

//---------------------------------------------------------------------------
void  TfrmWmWifiMT6620::CurrentPageReset(void)
{
    edtMCRAddr->Enabled = true;
    edtMCRValue->Enabled = true;
    btnMCRRead->Enabled = true;
    btnMCRWrite->Enabled = true;
    edtEEWordAddr->Enabled = true;
    edtEEWordValue->Enabled = true;
    btnEEWordRead->Enabled = true;
    btnEEWordWrite->Enabled = true;
    edtEEByteStringAddr->Enabled = true;
    edtEEByteStringLength->Enabled = true;
    btnEEByteStringRead->Enabled = true;
    btnEEByteStringWrite->Enabled = true;
    edtEEByteStringValue->Enabled = true;
    btnEESaveAsFile->Enabled = true;
    btnEEBurnFromFile->Enabled = true;
    btnEEReadAll->Enabled = true;
    edtTXGain->Enabled = true;
    cbChannel->Enabled = true;
    cbRate->Enabled = true;
    cbTXTestType->Enabled = true;
    btnTXStop->Enabled = true;
    btnTXGo->Enabled = true;
    btnTX1Stop->Enabled = true;
    btnTX1Go->Enabled = true;
    cbJapanChannel->Enabled = true;
    edtTXPktLen->Enabled = true;
    edtTXPktCnt->Enabled = true;
    btnRXGo->Enabled = true;
    btnRXStop->Enabled = true;
    btnTemperatureStop->Enabled = true;
    btnTemperatureGo->Enabled = true;
    cbJMode->Enabled = true;
    cbxCBW->Enabled = true;
    cbxDBW->Enabled = true;
    cbxPrimaryCh->Enabled = true;
}
//---------------------------------------------------------------------------

void TfrmWmWifiMT6620::OutputLog(char *strInfo)
{
    redtLog->Lines->Add(strInfo);
//    redtLog->Perform(EM_SCROLLCARET, 0, 0);
//qinqin 2012-01-05   exception for the richedit in function OutputLog in CNF_WIFI_READALL_EEPROM
    PostMessage(redtLog->Handle,EM_SCROLLCARET, 0, 0);
}

//---------------------------------------------------------------------------
void __fastcall TfrmWmWifiMT6620::FormShow(TObject *Sender)
{
    if(!m_bInited)
    {
        m_bInited = true;

        //set channel
        for(int i = 0 ; i < sizeof(chnlListmt6620_20)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {
            cbChannel->Items->Add(IntToStr(chnlListmt6620_20[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_20[i].chnlFreq/1000)+"MHz)");
        }
        cbChannel->Items->Add((AnsiString)"USER DEFINE");
        cbChannel->ItemIndex = 0;
        labelUserDefine->Enabled = false;
        edtChannel->Enabled = false;
        udChannel->Enabled = false;

        //for MT0035 DBDC
        for(int i = 0 ; i < sizeof(chnlListmt6620_20)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {
            cbChannel1->Items->Add(IntToStr(chnlListmt6620_20[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_20[i].chnlFreq/1000)+"MHz)");
        }
        cbChannel1->Items->Add((AnsiString)"USER DEFINE");
        cbChannel1->ItemIndex = 0;
        labelUserDefine1->Enabled = false;
        edtChannel1->Enabled = false;
        udChannel1->Enabled = false;

        for(int i = 0 ; i < sizeof(chnlListmt6620_80)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {

            cbChannelTX1->Items->Add(IntToStr(chnlListmt6620_80[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_80[i].chnlFreq/1000)+"MHz)");
        }
        cbChannelTX1->Items->Add((AnsiString)"USER DEFINE");
        cbChannelTX1->ItemIndex = 0;
        labelUserDefineTX1->Enabled = false;
        edtChannelTX1->Enabled = false;
        udChannelTX1->Enabled = false;
        //set rate
        for(int i = 0; i < sizeof(rateSettingmt6620) / sizeof(DATA_RATE_SETTING); i++)
        {
            cbRate->Items->Add((AnsiString)(rateSettingmt6620[i].pszRate));
        }
        cbRate->ItemIndex = 0;

        //set rate  MT0035 DBDC
        for(int i = 0; i < sizeof(rateSettingmt6620) / sizeof(DATA_RATE_SETTING); i++)
        {
            cbRate1->Items->Add((AnsiString)(rateSettingmt6620[i].pszRate));
        }
        cbRate1->ItemIndex = 0;

        //set test type
        cbTXTestType->Items->Add((AnsiString)"continuous pkt tx");
        cbTXTestType->Items->Add((AnsiString)"100% Duty Cycle");
        cbTXTestType->Items->Add((AnsiString)"carrier suppression");
        cbTXTestType->Items->Add((AnsiString)"LO single tone");
        cbTXTestType->ItemIndex = 0;

        cbTXTestType1->Items->Add((AnsiString)"continuous pkt tx");
        cbTXTestType1->Items->Add((AnsiString)"100% Duty Cycle");
        cbTXTestType1->Items->Add((AnsiString)"carrier suppression");
        cbTXTestType1->Items->Add((AnsiString)"LO single tone");
        cbTXTestType1->ItemIndex = 0;

        cbxNss->ItemIndex = 0;
        cbxNss1->ItemIndex = 0;

        Panel7->Visible = false;
        Label17->Visible = false;
    }
    Init();
    if(rbMIMO->Checked == true)
    {
        rbMIMOClick(Sender);
    }
    else if(rbDBDC->Checked == true)
    {
        rbDBDCClick(Sender);
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::btnMCRReadClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned long u4Value = 0;
    if(false == IsValidHexWIFIData(edtMCRAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_readMCR32(1200, u4Addr, &u4Value);
    OutputMetaResult(" Read MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    edtMCRValue->Text = IntToHex((int)u4Value, 4);
    CurrentPageReset();
}





void __fastcall TfrmWmWifiMT6620::btnMCRWriteClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Value = 0;
    if(false == IsValidHexWIFIData(edtMCRAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }
    if(false == IsValidHexWIFIData(edtMCRValue->Text, &u4Value))
    {
        OutputLog(" Error: value is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_writeMCR32(1200, u4Addr, u4Value);
    OutputMetaResult(" Write MCR", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnEEWordReadClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned long u4Value = 0;
    if(false == IsValidHexWIFIData(edtEEWordAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_readEEPRom16(1200, u4Addr, &u4Value);
    OutputMetaResult(" Read EEPROM WORD", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    edtEEWordValue->Text = IntToHex((int)u4Value, 4);
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnEEWordWriteClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Value = 0;
    if(false == IsValidHexWIFIData(edtEEWordAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }
    if(false == IsValidHexWIFIData(edtEEWordValue->Text, &u4Value))
    {
        OutputLog(" Error: value is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_writeEEPRom16(1200, u4Addr, u4Value);
    OutputMetaResult(" Write EEPROM WORD", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnEEByteStringReadClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Length = 0;
    char aucSzTmp[512] = {0};

    if(false == IsValidHexWIFIData(edtEEByteStringAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }
    if(false == IsValidDecWIFIData(edtEEByteStringLength->Text, u4Length))
    {
        OutputLog(" Error: length is not valid");
        CurrentPageReset();
        return;
    }
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_eepromReadByteStr(1200, u4Addr, u4Length, aucSzTmp);
    OutputMetaResult(" Read EEPROM byte string", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    edtEEByteStringValue->Text = (AnsiString)aucSzTmp;
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnEEByteStringWriteClick(
    TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Length = 0;

    if(false == IsValidHexWIFIData(edtEEByteStringAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }

    u4Length = strlen((edtEEByteStringValue->Text).c_str());

    if( (u4Length == 0) ||((u4Length) % 2 == 1 ))
    {
        OutputLog(" Error: length is not valid");
        CurrentPageReset();
        return;
    }

    wchar_t *lpsz = new wchar_t[u4Length + 1];
    if(!lpsz)
    {
        OutputLog(" Error: memory allocate fail");
        CurrentPageReset();
        return;
    }
    _wmemset(lpsz, 0, u4Length + 1);
    _wmemcpy(lpsz,(edtEEByteStringValue->Text).c_str(), u4Length);

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_eepromWriteByteStr(1200, u4Addr, u4Length / 2, (char*)lpsz);
    OutputMetaResult(" Write EEPROM byte string", mr);
    delete[] lpsz;
    lpsz = NULL;
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}

//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnEESaveAsFileClick(TObject *Sender)
{
    CurrentPageLock();
    /*    unsigned short  u2EepromSz = 512;
        unsigned short  u2EepromValue = 0;
        unsigned long   u4Tmp = 0;
    //    unsigned long   count = 0;
        char strEEbuf[2048] = {0};
    */
//qinqin 2012-01-05 delete

    if(!(saveDlgEE->Execute()))
    {
        CurrentPageReset();
        return;
    }

    if(FileExists(saveDlgEE->FileName))
    {
        char szFileName[255] = {0};
        fnsplit(saveDlgEE->FileName.c_str(), 0, 0, szFileName, 0);
        strcat(szFileName, ".BAK");
        RenameFile(saveDlgEE->FileName, szFileName);
    }

    /*    for(unsigned int u2Tmp = 0; u2Tmp < u2EepromSz/2; u2Tmp++)
        {

            META_RESULT mr = SP_META_WiFi_readEEPRom16_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, u2Tmp, &u4Tmp);

            if(META_SUCCESS != mr)
            {

                OutputLog(" Error: EEPROM save as file failed");
                CurrentPageReset();
                return ;
            }
            u2EepromValue = (unsigned short) u4Tmp;


            char strBuf[10] = {0};
            sprintf(strBuf, "%04X", u2EepromValue);
            strcat(strEEbuf, strBuf);
        }

        int iFileHandle = FileCreate(saveDlgEE->FileName);
        FileWrite(iFileHandle, strEEbuf, strlen(strEEbuf));
        FileClose(iFileHandle);

        OutputLog(" EEPROM save as file success");
        CurrentPageReset();
    */
// qinqin 2012-01-05
    m_WiFi_Man_Obj.ConfirmCallback = ::CNF_WIFI_READ_EEPROM;
    m_WiFi_Man_Obj.REQ_WIFI6620_READ_EEPROM_Start();
//
}

void TfrmWmWifiMT6620::CNF_WIFI_READ_EEPROM(void)
{
    META_RESULT state = m_WiFi_Man_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        EESaveAsFile(saveDlgEE->FileName);
        OutputLog(" EEPROM save as file success");
    }
    break;

    default:
    {
        OutputLog(" Error: EEPROM save as file failed");
    }
    break;
    }
    CurrentPageReset();
}

void TfrmWmWifiMT6620::EESaveAsFile(AnsiString asSaveFileName)
{
    int iFileHandle = FileCreate(asSaveFileName);
    FileWrite(iFileHandle, m_WiFi_Man_Obj.GetEEBuffer(), strlen(m_WiFi_Man_Obj.GetEEBuffer()));
    FileClose(iFileHandle);
}

//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbChannelChange(TObject *Sender)
{
    DBDCSelect(0);
    //DoChannelChange();
    if (cbChannel->Text == "USER DEFINE")
    {
        labelUserDefine->Enabled = true;
        edtChannel->Enabled = true;
        udChannel->Enabled = true;
    }
    else
    {
        labelUserDefine->Enabled = false;
        edtChannel->Enabled = false;
        udChannel->Enabled = false;
        DoChannelChange();
    }
}
//---------------------------------------------------------------------------

void TfrmWmWifiMT6620::DoChannelChange(void)
{
    META_RESULT mr = META_FAILED;
    int channelConfig = 0;

    if (cbChannel->Text != "USER DEFINE")
    {
        if (rbBandwidth40->Checked == true)
        {
            channelConfig = chnlListmt6620_40[cbChannel->ItemIndex].chnlFreq;
        }
        else if (rbAdvanceSetting->Checked == true)
        {
            if (cbxCBW->Text == "BW5")
            {
                channelConfig = chnlListmt6620_5[cbChannel->ItemIndex].chnlFreq;
            }
            else if (cbxCBW->Text == "BW10")
            {
                channelConfig = chnlListmt6620_10[cbChannel->ItemIndex].chnlFreq;
            }
            else if (cbxCBW->Text == "BW20")
            {
                channelConfig = chnlListmt6620_20[cbChannel->ItemIndex].chnlFreq;
            }
            else if (cbxCBW->Text == "BW40")
            {
                channelConfig = chnlListmt6620_40[cbChannel->ItemIndex].chnlFreq;
            }
            else if (cbxCBW->Text == "BW80")
            {
                channelConfig = chnlListmt6620_80[cbChannel->ItemIndex].chnlFreq;
            }
            else if (cbxCBW->Text == "BW160")
            {
                channelConfig = chnlListmt6620_160[cbChannel->ItemIndex].chnlFreq;
            }
            else
            {
                OutputLog(" Error: please select the right bandwidth");
                return;
            }
        }
        else
        {
            channelConfig = chnlListmt6620_20[cbChannel->ItemIndex].chnlFreq;
        }
        LOG("ItemIndex:%d,chnlFreq:%d",cbChannel->ItemIndex,channelConfig);
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, channelConfig);
    }
    OutputMetaResult(" setChannel", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }
    //uiUpdateTxPower();
}

void TfrmWmWifiMT6620::DoChannelTX1Change(void)
{
    META_RESULT mr = META_FAILED;
    int channelTX1Config = 0;

    //for WiFi refactor
    if (cbChannelTX1->Text != "USER DEFINE")
    {
        channelTX1Config = chnlListmt6620_80[cbChannelTX1->ItemIndex].chnlFreq;
        LOG("ItemIndex:%d,chnlFreq:%d",cbChannelTX1->ItemIndex,channelTX1Config);
        mr = m_WiFi_Man_Obj.WiFi_setTX1Channel(1200, channelTX1Config);
    }
    OutputMetaResult(" setTX1Channel", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }
    //uiUpdateTxPower();
}

bool TfrmWmWifiMT6620::uiUpdateTxPower(void)
{

    unsigned long u4Value = 0;
    m_WiFi_Man_Obj.WiFi_readTxPower(1200, &u4Value);
    edtTXGain->Text = u4Value;

    return true;
}
void __fastcall TfrmWmWifiMT6620::btnEEBurnFromFileClick(TObject *Sender)
{
    CurrentPageLock();
    if( !(openDlgEE->Execute()))
    {
        CurrentPageReset();
        return;
    }
    try
    {
        int iFileHandle = FileOpen(openDlgEE->FileName, fmOpenRead);
        int iFileLength = FileSeek(iFileHandle,0,2);
        FileSeek(iFileHandle,0,0);

        char* pszBuffer = new char[iFileLength+1];
        char* pszBufferRaw = new char[iFileLength / 2 + 1];
        pszBuffer[iFileLength] = '\0';
        pszBufferRaw[iFileLength / 2] = '\0';
        FileRead(iFileHandle, (char*)pszBuffer, iFileLength);
        AnsiString strBuffer = pszBuffer;


        FileClose(iFileHandle);

        int nIndex = 1;
        for (int i = 0; i < iFileLength / 4; i++)
        {
            AnsiString strTemp = strBuffer.SubString(nIndex,4);
            unsigned int tmpValue;
            if(!IsValidHexWIFIData(strTemp,&tmpValue))
            {
                if( pszBuffer != NULL )
                {
                    delete [] pszBuffer;
                    pszBuffer = NULL;
                }
                if( pszBufferRaw != NULL )
                {
                    delete [] pszBufferRaw;
                    pszBufferRaw = NULL;
                }
                CurrentPageReset();
                return;
            }
            *((unsigned short *)(pszBufferRaw + 2 * i)) = (unsigned short)tmpValue;
            nIndex += 4;
        }
        NVRAM_ACCESS_STRUCT wifi_nvram;
        wifi_nvram.dataLen = iFileLength / 2;
        wifi_nvram.dataOffset = 0;
        wifi_nvram.data = pszBufferRaw;


        META_RESULT mr = m_WiFi_Man_Obj.WiFi_WriteNVRAM(1200, &wifi_nvram);
        if(META_SUCCESS != mr)
        {
            OutputLog(" Error: NVRAM Write failed");   //待定
            if( pszBuffer != NULL )
            {
                delete [] pszBuffer;
                pszBuffer = NULL;
            }
            if( pszBufferRaw != NULL )
            {
                delete [] pszBufferRaw;
                pszBufferRaw = NULL;
            }
            CurrentPageReset();
            return;
        }

        if( pszBuffer != NULL )
        {
            delete [] pszBuffer;
            pszBuffer = NULL;
        }
        if( pszBufferRaw != NULL )
        {
            delete [] pszBufferRaw;
            pszBufferRaw = NULL;
        }
    }
    catch(...)
    {
        Application->MessageBox("Can't perform one of the following file operations: Open, Seek, Read, Close.", "File Error", IDOK);
    }

    OutputLog(" EEPROM burn from file success");
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnEEReadAllClick(TObject *Sender)
{
    CurrentPageLock();
    /*    unsigned short  u2EepromSz = 512;
        unsigned short  u2EepromValue = 0;
        unsigned long   u4Tmp = 0;
        unsigned long   count = 0;
        char strEEbuf[2048] = {0};

        for(unsigned int u2Tmp = 0; u2Tmp < u2EepromSz/2; u2Tmp++)
        {

            META_RESULT mr = SP_META_WiFi_readEEPRom16_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, u2Tmp, &u4Tmp);
            if(META_SUCCESS != mr)
            {
                OutputLog(" Error: EEPROM read all failed");
    			CurrentPageReset();
                return ;
            }
            u2EepromValue = (unsigned short) u4Tmp;


            if((u2Tmp % 8) == 0)
            {
                char strBuf2[10] = {0};
                sprintf(strBuf2, "%08X: ", count * 0x0010);
                count++;
                strcat(strEEbuf, strBuf2);
            }

            char strBuf[20] = {0};
            unsigned char highByte = (u2EepromValue >> 8) & 0x00FF;
            unsigned char lowByte = (u2EepromValue) & 0x00FF;
            sprintf(strBuf, "%02X %02X ", highByte, lowByte);
            strcat(strEEbuf, strBuf);

            if((u2Tmp % 8) == 0xF)
            {
                char strBuf3[10] = {0};
                sprintf(strBuf3, "\r\n");
                strcat(strEEbuf, strBuf3);
            }
        }

        OutputLog(strEEbuf);
        OutputLog(" EEPROM read all success");
        CurrentPageReset();
    */
//qinqin 2012-01-05
    m_WiFi_Man_Obj.ConfirmCallback = ::CNF_WIFI_READALL_EEPROM;
    m_WiFi_Man_Obj.REQ_WIFI_READALL_EEPROM_Start();
//
}

void TfrmWmWifiMT6620::CNF_WIFI_READALL_EEPROM(void)
{
    META_RESULT state = m_WiFi_Man_Obj.Get_ConfirmState();

    switch (state)
    {
    case META_SUCCESS:
    {
        OutputLog(m_WiFi_Man_Obj.GetEEBuffer());
        OutputLog(" EEPROM read all success");
    }
    break;

    default:
    {
        OutputLog(" Error: EEPROM read all failed");
    }
    break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnTXGoClick(TObject *Sender)
{
    DBDCSelect(0);
    switch(cbTXTestType->ItemIndex)
    {
    case 0: // continuous packet tx
        goTX0();
        break;
    case 1:// tx output power
        goTX1();
        break;
    case 2:// carrier suppression
        goTX2();
        break;
    case 3:// local leakage
        goTX3();
        break;
/*    case 4:// Enter Power OFF
        goTX4();
        break;  */
    case 4:// CW mode
        goTX5();
        break;
    default:
        //error
        break;
    }
}

bool TfrmWmWifiMT6620::TXParameterCheck(unsigned int &u4TxPktCnt, int &i4TxPktLen, double &u4TxGain,
                                        int &u4TxPower, unsigned int &nLongPreamble)
{
    if(false == IsValidDecWIFIData(edtTXPktCnt->Text, u4TxPktCnt))
    {
        OutputLog(" Error: Pkt cnt is not valid");
        CurrentPageReset();
        return false;
    }

    if(false == IsValidDoubleWIFIData(edtTXGain->Text, u4TxGain))
    {
        OutputLog(" Error: Tx Gain is not valid");
        CurrentPageReset();
        return false;
    }
    else
    {
        u4TxPower = u4TxGain;
        if((u4TxGain - u4TxPower) != 0 && (u4TxGain - u4TxPower) != 0.5 && (u4TxGain - u4TxPower) != -0.5)
        {
            OutputLog(" Error: Tx Gain is not valid");
            CurrentPageReset();
            return false;

        }
        if(u4TxGain < -64 || u4TxGain > 63.5)
        {
            OutputLog(" Error: Tx Gain is not valid");
            CurrentPageReset();
            return false;
        }

    }
    u4TxPower = u4TxGain *2;

    if(false == IsValidIntWIFIData(edtTXPktLen->Text, i4TxPktLen))
    {
        OutputLog(" Error: Pkt Len is not valid");
        CurrentPageReset();
        return false;
    }
    if(i4TxPktLen < 31)
    {
        OutputLog(" Error: Pkt Len is too small");
        CurrentPageReset();
        return false;
    }

    btnTXGo->Enabled = false;

    if(cbRate->ItemIndex < 12)
    {
        nLongPreamble = 0;
    }
    else
    {
        if(rbModeSelectGreenFiled->Checked == true)
        {
            nLongPreamble=3;
        }
        else if(rbModeSelectMixedMode->Checked == true)
        {
            nLongPreamble=2;
        }
        else if(rbModeSelect11AC->Checked == true)
        {
            nLongPreamble=4;
        }
        else
        {
            OutputLog(" Error: Please select Mode Select");
            CurrentPageReset();
            btnTXGo->Enabled = true;
            return false;
        }
    }
    return true;
}

bool TfrmWmWifiMT6620::TXParameter1Check(unsigned int &u4TxPktCnt, int &i4TxPktLen, double &u4TxGain,
                                        int &u4TxPower, unsigned int &nLongPreamble)
{
    if(false == IsValidDecWIFIData(edtTXPktCnt1->Text, u4TxPktCnt))
    {
        OutputLog(" Error: Pkt cnt is not valid");
        CurrentPageReset();
        return false;
    }

    if(false == IsValidDoubleWIFIData(edtTXGain1->Text, u4TxGain))
    {
        OutputLog(" Error: Tx Gain is not valid");
        CurrentPageReset();
        return false;
    }
    else
    {
        u4TxPower = u4TxGain;
        if((u4TxGain - u4TxPower) != 0 && (u4TxGain - u4TxPower) != 0.5 && (u4TxGain - u4TxPower) != -0.5)
        {
            OutputLog(" Error: Tx Gain is not valid");
            CurrentPageReset();
            return false;

        }
        if(u4TxGain < -64 || u4TxGain > 63.5)
        {
            OutputLog(" Error: Tx Gain is not valid");
            CurrentPageReset();
            return false;
        }

    }
    u4TxPower = u4TxGain *2;

    if(false == IsValidIntWIFIData(edtTXPktLen1->Text, i4TxPktLen))
    {
        OutputLog(" Error: Pkt Len is not valid");
        CurrentPageReset();
        return false;
    }
    if(i4TxPktLen < 31)
    {
        OutputLog(" Error: Pkt Len is too small");
        CurrentPageReset();
        return false;
    }

    btnTX1Go->Enabled = false;

    if(cbRate1->ItemIndex < 12)
    {
        nLongPreamble = 0;
    }
    else
    {
        if(rbModeSelectGreenFiled1->Checked == true)
        {
            nLongPreamble=3;
        }
        else if(rbModeSelectMixedMode1->Checked == true)
        {
            nLongPreamble=2;
        }
        else if(rbModeSelect11AC1->Checked == true)
        {
            nLongPreamble=4;
        }
        else
        {
            OutputLog(" Error: Please select Mode Select");
            CurrentPageReset();
            btnTX1Go->Enabled = true;
            return false;
        }
    }
    return true;
}
//---------------------------------------------------------------------------
void TfrmWmWifiMT6620::goTX0(void)
{
    META_RESULT mr = META_FAILED;
    unsigned int u4TxPktCnt = 0;
    unsigned int nChannel = 0;
    int i4TxPktLen = 0;
    double u4TxGain = 0.0;
    int u4TxPower = 0;
    int i4Antenna = 0;
    unsigned int nLongPreamble = 0;
    if(!TXParameterCheck(u4TxPktCnt, i4TxPktLen, u4TxGain,
                         u4TxPower, nLongPreamble))
    {
        return;
    }

    //If channel is user define, set channel here
    if (cbChannel->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        LOG("User define channel fre:%d",nChannel*1000);
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }
    if(cbxCBW->Text == "BW160NC")
    {
        if ((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion) )
        {
            if (cbChannelTX1->Text == "USER DEFINE")
            {
                if(false == IsValidDecWIFIData(edtChannelTX1->Text, nChannel))
                {
                    OutputLog(" Error: User define TX1 channel is not valid");
                    return;
                }
                LOG("User define TX1 channel fre:%d",nChannel*1000);
                mr = m_WiFi_Man_Obj.WiFi_setTX1Channel(1200, nChannel*1000);
                OutputMetaResult(" set User define TX1 channel", mr);
            }
        }
    }
    //

    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.bufSize = i4TxPktLen;
    txParam.bLongPreamble = nLongPreamble;
    if(cbxNss->Text == "2")
    {
        txParam.txRate = rateSettingmt6632[cbRate->ItemIndex].i4BBHwVal;
    }
    else
    {
        txParam.txRate = rateSettingmt6620[cbRate->ItemIndex].i4BBHwVal;
    }
    txParam.pktCount =  u4TxPktCnt;
    //txParam.pktInterval = 50; //delete set wifi Tx off time duration, use default value via wifi firmware
    txParam.bGainControl = TRUE;
    txParam.gainControl = u4TxPower;

    txParam.txAntenna = i4Antenna;


    mr = m_WiFi_Man_Obj.WiFi_setPacketTxEx(1200, &txParam);

    OutputMetaResult(" setPacketTxEx", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    timerTX->Enabled = true;
}

void TfrmWmWifiMT6620::goTX1(void)
{
    META_RESULT mr = META_FAILED;
    unsigned int u4TxPktCnt = 0;
    unsigned int nChannel = 0;
    int i4TxPktLen = 0;
    double u4TxGain = 0.0;
    int u4TxPower = 0;
    int i4Antenna = 0;
    unsigned int nLongPreamble = 0;
    if(!TXParameterCheck(u4TxPktCnt, i4TxPktLen, u4TxGain,
                         u4TxPower, nLongPreamble))
    {
        return;
    }
    //If channel is user define, set channel here
    if (cbChannel->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }
    if(cbxCBW->Text == "BW160NC")
    {
        if ((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion) )
        {
            if (cbChannelTX1->Text == "USER DEFINE")
            {
                if(false == IsValidDecWIFIData(edtChannelTX1->Text, nChannel))
                {
                    OutputLog(" Error: User define TX1 channel is not valid");
                    return;
                }
                LOG("User define TX1 channel fre:%d",nChannel*1000);
                mr = m_WiFi_Man_Obj.WiFi_setTX1Channel(1200, nChannel*1000);
                OutputMetaResult(" set User define TX1 channel", mr);
            }
        }
    }
    //

    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.bufSize = i4TxPktLen;
    txParam.bLongPreamble = nLongPreamble;
    if(cbxNss->Text == "2")
    {
        txParam.txRate = rateSettingmt6632[cbRate->ItemIndex].i4BBHwVal;
    }
    else
    {
        txParam.txRate = rateSettingmt6620[cbRate->ItemIndex].i4BBHwVal;
    }
    txParam.pktCount =  u4TxPktCnt;
    txParam.bGainControl = TRUE;
    txParam.gainControl = u4TxPower;
    txParam.txAntenna = i4Antenna;
    int nCWMode = 3;
    mr = m_WiFi_Man_Obj.WiFi_setDutyCycle(1200, &txParam, nCWMode);

    OutputMetaResult(" set 100% Duty Cycle", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    btnTXGo->Enabled = true;
    CurrentPageReset();
}
void TfrmWmWifiMT6620::goTX2(void)
{
    META_RESULT mr = META_FAILED;
    unsigned int u4TxPktCnt = 0;
    unsigned int nChannel = 0;
    int i4TxPktLen = 0;
    double u4TxGain = 0.0;
    int u4TxPower = 0;
    int i4Antenna = 0;
    unsigned int nLongPreamble = 0;

    if(!TXParameterCheck(u4TxPktCnt, i4TxPktLen, u4TxGain,
                         u4TxPower, nLongPreamble))
    {
        return;
    }

    //If channel is user define, set channel here
    if (cbChannel->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }
    if(cbxCBW->Text == "BW160NC")
    {
        if ((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion))
        {
            if (cbChannelTX1->Text == "USER DEFINE")
            {
                if(false == IsValidDecWIFIData(edtChannelTX1->Text, nChannel))
                {
                    OutputLog(" Error: User define TX1 channel is not valid");
                    return;
                }
                LOG("User define TX1 channel fre:%d",nChannel*1000);
                mr = m_WiFi_Man_Obj.WiFi_setTX1Channel(1200, nChannel*1000);
                OutputMetaResult(" set User define TX1 channel", mr);
            }
        }
    }
    //

    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.bufSize = i4TxPktLen;
    txParam.bLongPreamble = nLongPreamble;
    if(cbxNss->Text == "2")
    {
        txParam.txRate = rateSettingmt6632[cbRate->ItemIndex].i4BBHwVal;
    }
    else
    {
        txParam.txRate = rateSettingmt6620[cbRate->ItemIndex].i4BBHwVal;
    }
    txParam.pktCount =  u4TxPktCnt;
    //txParam.pktInterval = 50;   //delete set wifi Tx off time duration, use default value via wifi firmware
    txParam.bGainControl = TRUE;
    txParam.gainControl = u4TxPower;

    txParam.txAntenna = i4Antenna;
    mr = m_WiFi_Man_Obj.WiFi_setCarrierSuppression(1200, &txParam);

    OutputMetaResult(" setCarrierSuppression", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }
    btnTXGo->Enabled = true;
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifiMT6620::goTX3(void)
{
//    CurrentPageLock(TX_STOP);
    META_RESULT mr = META_FAILED;
    unsigned int u4TxGain = 0;
    unsigned int nChannel = 0;
    int i4Antenna = 0;

    if(false == IsValidHexWIFIData(edtTXGain->Text, &u4TxGain))
    {
        OutputLog(" Error: Tx Gain is not valid");
        CurrentPageReset();
        return;
    }

    //If channel is user define, set channel here
    if (cbChannel->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }
    if(cbxCBW->Text == "BW160NC")
    {
        if ((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion))
        {
            if (cbChannelTX1->Text == "USER DEFINE")
            {
                if(false == IsValidDecWIFIData(edtChannelTX1->Text, nChannel))
                {
                    OutputLog(" Error: User define TX1 channel is not valid");
                    return;
                }
                LOG("User define TX1 channel fre:%d",nChannel*1000);
                mr = m_WiFi_Man_Obj.WiFi_setTX1Channel(1200, nChannel*1000);
                OutputMetaResult(" set User define TX1 channel", mr);
            }
        }
    }
    //
    mr = m_WiFi_Man_Obj.WiFi_setLocalFrequecy(1200, u4TxGain, i4Antenna);
    OutputMetaResult(" setLocalFrequecy", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    //start local frequency  待定
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifiMT6620::goTX4(void)
{
     //If channel is user define, set channel here
    META_RESULT mr = META_FAILED;
    unsigned int nChannel = 0;
    if (cbChannel->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }
    if(cbxCBW->Text == "BW160NC")
    {
        if ((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion))
        {
            if (cbChannelTX1->Text == "USER DEFINE")
            {
                if(false == IsValidDecWIFIData(edtChannelTX1->Text, nChannel))
                {
                    OutputLog(" Error: User define TX1 channel is not valid");
                    return;
                }
                LOG("User define TX1 channel fre:%d",nChannel*1000);
                mr = m_WiFi_Man_Obj.WiFi_setTX1Channel(1200, nChannel*1000);
                OutputMetaResult(" set User define TX1 channel", mr);
            }
        }
    }
    //
//    CurrentPageLock(TX_STOP);
    btnTXGo->Enabled = false;

    mr = m_WiFi_Man_Obj.WiFi_setNormalMode(1200);
    OutputMetaResult(" setNormalMode", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }
    mr = m_WiFi_Man_Obj.WiFi_setPnpPower(1200, ParamDeviceStateD3);
    OutputMetaResult(" setPnpPower", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifiMT6620::goTX5(void)
{
     //If channel is user define, set channel here
    META_RESULT mr = META_FAILED;
    unsigned int nChannel = 0;
    if (cbChannel->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }
    if(cbxCBW->Text == "BW160NC")
    {
        if ((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion))
        {
            if (cbChannelTX1->Text == "USER DEFINE")
            {
                if(false == IsValidDecWIFIData(edtChannelTX1->Text, nChannel))
                {
                    OutputLog(" Error: User define TX1 channel is not valid");
                    return;
                }
                LOG("User define TX1 channel fre:%d",nChannel*1000);
                mr = m_WiFi_Man_Obj.WiFi_setTX1Channel(1200, nChannel*1000);
                OutputMetaResult(" set User define TX1 channel", mr);
            }
        }
    }
    //
    int nTxRate = 0;  //please help to set nTxRate to 0 as 1M;
    int nCWModeType = 4;     //please help to set nCWModeType to 4 as CCK PI/2;
    mr = m_WiFi_Man_Obj.WiFi_setCWMode(1200, nTxRate, nCWModeType);
    OutputMetaResult(" setCWMode", mr);
    if(META_SUCCESS != mr)
    {
        return;
    }
    m_bTXTestFlag = true;
}

void __fastcall TfrmWmWifiMT6620::btnTXStopClick(TObject *Sender)
{
    DBDCSelect(0);
    m_bTXTestFlag = false;
    
    switch(cbTXTestType->ItemIndex)
    {
    case 0: // continuous packet tx
        stopTX0();
        break;
    case 1:// tx output power
        stopTX1();
        break;
    case 2:// carrier suppression
        stopTX2();
        break;
    case 3:// local leakage
        stopTX3();
        break;
/*    case 4:// Enter Power OFF
        stopTX4();
        break;*/
    case 4:     //CW mode
        stopTX5();
        break;
    default:
        //error
        break;
    }
    CurrentPageReset();
}

void TfrmWmWifiMT6620::stopTX0(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
    timerTX->Enabled = false;
}

void TfrmWmWifiMT6620::stopTX1(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
}

void TfrmWmWifiMT6620::stopTX2(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
}

void TfrmWmWifiMT6620::stopTX3(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
}

void TfrmWmWifiMT6620::stopTX4(void)
{
    META_RESULT mr = META_FAILED;
    unsigned int nChannel = 0;
    mr = m_WiFi_Man_Obj.WiFi_setPnpPower(1200, ParamDeviceStateD0);
    OutputMetaResult(" setPnpPower", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        return;
    }
    mr = m_WiFi_Man_Obj.WiFi_setTestMode(1200);
    OutputMetaResult(" setTestMode", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        return;
    }
    if (cbChannel->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" setChannel", mr);
    }
    else
    {
        DoChannelChange();
    }
    if(cbxCBW->Text == "BW160NC")
    {
        if ((0x6632 == m_wifiChipVersion)||(0x0035 == m_wifiChipVersion))
        {
            if (cbChannelTX1->Text == "USER DEFINE")
            {
                if(false == IsValidDecWIFIData(edtChannelTX1->Text, nChannel))
                {
                    OutputLog(" Error: User define TX1 channel is not valid");
                    return;
                }
                LOG("User define TX1 channel fre:%d",nChannel*1000);
                mr = m_WiFi_Man_Obj.WiFi_setTX1Channel(1200, nChannel*1000);
                OutputMetaResult(" set User define TX1 channel", mr);
            }
            else
            {
                DoChannelTX1Change();
            }
        }
    }

    btnTXGo->Enabled = true;
}

void TfrmWmWifiMT6620::stopTX5(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
}

void TfrmWmWifiMT6620::goBand1TX0(void)
{
    META_RESULT mr = META_FAILED;
    unsigned int u4TxPktCnt = 0;
    unsigned int nChannel = 0;
    int i4TxPktLen = 0;
    double u4TxGain = 0.0;
    int u4TxPower = 0;
    int i4Antenna = 0;
    unsigned int nLongPreamble = 0;
    if(!TXParameter1Check(u4TxPktCnt, i4TxPktLen, u4TxGain,
                         u4TxPower, nLongPreamble))
    {
        return;
    }

    //If channel is user define, set channel here
    if (cbChannel1->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel1->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        LOG("User define channel fre:%d",nChannel*1000);
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }

    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.bufSize = i4TxPktLen;
    txParam.bLongPreamble = nLongPreamble;
    if(cbxNss1->Text == "2")
    {
        txParam.txRate = rateSettingmt6632[cbRate1->ItemIndex].i4BBHwVal;
    }
    else
    {
        txParam.txRate = rateSettingmt6620[cbRate1->ItemIndex].i4BBHwVal;
    }
    txParam.pktCount =  u4TxPktCnt;
    //txParam.pktInterval = 50; //delete set wifi Tx off time duration, use default value via wifi firmware
    txParam.bGainControl = TRUE;
    txParam.gainControl = u4TxPower;

    txParam.txAntenna = i4Antenna;


    mr = m_WiFi_Man_Obj.WiFi_setPacketTxEx(1200, &txParam);

    OutputMetaResult(" setPacketTxEx", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    timerTX1->Enabled = true;
}

void TfrmWmWifiMT6620::goBand1TX1(void)
{
    META_RESULT mr = META_FAILED;
    unsigned int u4TxPktCnt = 0;
    unsigned int nChannel = 0;
    int i4TxPktLen = 0;
    double u4TxGain = 0.0;
    int u4TxPower = 0;
    int i4Antenna = 0;
    unsigned int nLongPreamble = 0;
    if(!TXParameter1Check(u4TxPktCnt, i4TxPktLen, u4TxGain,
                         u4TxPower, nLongPreamble))
    {
        return;
    }
    //If channel is user define, set channel here
    if (cbChannel1->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel1->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }

    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.bufSize = i4TxPktLen;
    txParam.bLongPreamble = nLongPreamble;
    if(cbxNss1->Text == "2")
    {
        txParam.txRate = rateSettingmt6632[cbRate1->ItemIndex].i4BBHwVal;
    }
    else
    {
        txParam.txRate = rateSettingmt6620[cbRate1->ItemIndex].i4BBHwVal;
    }
    txParam.pktCount =  u4TxPktCnt;
    txParam.bGainControl = TRUE;
    txParam.gainControl = u4TxPower;
    txParam.txAntenna = i4Antenna;
    int nCWMode = 3;
    mr = m_WiFi_Man_Obj.WiFi_setDutyCycle(1200, &txParam, nCWMode);

    OutputMetaResult(" set 100% Duty Cycle", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    btnTX1Go->Enabled = true;
    CurrentPageReset();
}
void TfrmWmWifiMT6620::goBand1TX2(void)
{
    META_RESULT mr = META_FAILED;
    unsigned int u4TxPktCnt = 0;
    unsigned int nChannel = 0;
    int i4TxPktLen = 0;
    double u4TxGain = 0.0;
    int u4TxPower = 0;
    int i4Antenna = 0;
    unsigned int nLongPreamble = 0;

    if(!TXParameter1Check(u4TxPktCnt, i4TxPktLen, u4TxGain,
                         u4TxPower, nLongPreamble))
    {
        return;
    }

    //If channel is user define, set channel here
    if (cbChannel1->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel1->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }

    WIFI_TX_PARAM_T txParam;
    memset(&txParam, 0, sizeof(txParam));
    txParam.bufSize = i4TxPktLen;
    txParam.bLongPreamble = nLongPreamble;
    if(cbxNss1->Text == "2")
    {
        txParam.txRate = rateSettingmt6632[cbRate1->ItemIndex].i4BBHwVal;
    }
    else
    {
        txParam.txRate = rateSettingmt6620[cbRate1->ItemIndex].i4BBHwVal;
    }
    txParam.pktCount =  u4TxPktCnt;
    //txParam.pktInterval = 50;   //delete set wifi Tx off time duration, use default value via wifi firmware
    txParam.bGainControl = TRUE;
    txParam.gainControl = u4TxPower;

    txParam.txAntenna = i4Antenna;
    mr = m_WiFi_Man_Obj.WiFi_setCarrierSuppression(1200, &txParam);

    OutputMetaResult(" setCarrierSuppression", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        CurrentPageReset();
        return;
    }
    btnTX1Go->Enabled = true;
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifiMT6620::goBand1TX3(void)
{
//    CurrentPageLock(TX_STOP);
    META_RESULT mr = META_FAILED;
    unsigned int u4TxGain = 0;
    unsigned int nChannel = 0;
    int i4Antenna = 0;

    if(false == IsValidHexWIFIData(edtTXGain1->Text, &u4TxGain))
    {
        OutputLog(" Error: Tx Gain is not valid");
        CurrentPageReset();
        return;
    }

    //If channel is user define, set channel here
    if (cbChannel1->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel1->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }

    mr = m_WiFi_Man_Obj.WiFi_setLocalFrequecy(1200, u4TxGain, i4Antenna);
    OutputMetaResult(" setLocalFrequecy", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }

    //start local frequency  待定
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifiMT6620::goBand1TX4(void)
{
     //If channel is user define, set channel here
    META_RESULT mr = META_FAILED;
    unsigned int nChannel = 0;
    if (cbChannel1->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel1->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }

    btnTX1Go->Enabled = false;

    mr = m_WiFi_Man_Obj.WiFi_setNormalMode(1200);
    OutputMetaResult(" setNormalMode", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        CurrentPageReset();
        return;
    }
    mr = m_WiFi_Man_Obj.WiFi_setPnpPower(1200, ParamDeviceStateD3);
    OutputMetaResult(" setPnpPower", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        CurrentPageReset();
        return;
    }
    m_bTXTestFlag = true;
    CurrentPageReset();
}

void TfrmWmWifiMT6620::goBand1TX5(void)
{
     //If channel is user define, set channel here
    META_RESULT mr = META_FAILED;
    unsigned int nChannel = 0;
    if (cbChannel1->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel1->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" set User define channel", mr);
    }

    int nTxRate = 0;  //please help to set nTxRate to 0 as 1M;
    int nCWModeType = 4;     //please help to set nCWModeType to 4 as CCK PI/2;
    mr = m_WiFi_Man_Obj.WiFi_setCWMode(1200, nTxRate, nCWModeType);
    OutputMetaResult(" setCWMode", mr);

    m_bTXTestFlag = true;
}

void __fastcall TfrmWmWifiMT6620::btnTX1StopClick(TObject *Sender)
{
    DBDCSelect(1);
    m_bTXTestFlag = false;
//	CurrentPageLock();
    switch(cbTXTestType1->ItemIndex)
    {
    case 0: // continuous packet tx
        stopBand1TX0();
        break;
    case 1:// tx output power
        stopBand1TX1();
        break;
    case 2:// carrier suppression
        stopBand1TX2();
        break;
    case 3:// local leakage
        stopBand1TX3();
        break;
/*    case 4:// Enter Power OFF
        stopTX4();
        break;*/
    case 4:     //CW mode
        stopBand1TX5();
        break;
    default:
        //error
        break;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------


void TfrmWmWifiMT6620::stopBand1TX0(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
    timerTX1->Enabled = false;
}

void TfrmWmWifiMT6620::stopBand1TX1(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
}

void TfrmWmWifiMT6620::stopBand1TX2(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
}

void TfrmWmWifiMT6620::stopBand1TX3(void)
{
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
}

void TfrmWmWifiMT6620::stopBand1TX4(void)
{
    DBDCSelect(1);
    META_RESULT mr = META_FAILED;
    unsigned int nChannel = 0;
    mr = m_WiFi_Man_Obj.WiFi_setPnpPower(1200, ParamDeviceStateD0);
    OutputMetaResult(" setPnpPower", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        return;
    }
    mr = m_WiFi_Man_Obj.WiFi_setTestMode(1200);
    OutputMetaResult(" setTestMode", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        return;
    }
    if (cbChannel1->Text == "USER DEFINE")
    {
        if(false == IsValidDecWIFIData(edtChannel1->Text, nChannel))
        {
            OutputLog(" Error: User define channel is not valid");
            return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, nChannel*1000);
        OutputMetaResult(" setChannel", mr);
    }
    else
    {
        DoChannelChange();
    }

    btnTXGo->Enabled = true;
}

void TfrmWmWifiMT6620::stopBand1TX5(void)
{
    DBDCSelect(1);
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" setStandBy", mr);
}


//---------------------------------------------------------------------------
void __fastcall TfrmWmWifiMT6620::cbRateChange(TObject *Sender)
{
    DBDCSelect(0);
    //for WiFi refactor
    //META_RESULT mr = SP_META_WiFi_setRate_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, rateSettingmt6620[cbRate->ItemIndex].i4BBHwVal);
    META_RESULT mr = META_FAILED;
    if(cbxNss->Text == "2")
    {
        mr = m_WiFi_Man_Obj.WiFi_setRate(1200, rateSettingmt6632[cbRate->ItemIndex].i4BBHwVal);
    }
    else
    {
        mr = m_WiFi_Man_Obj.WiFi_setRate(1200, rateSettingmt6620[cbRate->ItemIndex].i4BBHwVal);
    }

    OutputMetaResult(" set rate", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnRXGoClick(TObject *Sender)
{
    DBDCSelect(0);
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setRxTest(1200);
    OutputMetaResult(" start Rx Test", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        return;
    }

    int intervalTime = 0;
    if(false == IsValidIntWIFIData(edtInterval->Text, intervalTime) || intervalTime <= 0)
    {
        intervalTime = 1;
        OutputLog(" Error: interval time is not valid, which will be set to default value(1 sec)");
    }

    timerRX->Interval = intervalTime*1000;
    timerRX->Enabled = true;

}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::btnRXStopClick(TObject *Sender)
{
    DBDCSelect(0);
    timerRX->Enabled = false;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" Stop Rx Test", mr);
    if(META_SUCCESS != mr)
    {
        btnTXGo->Enabled = true;
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnEFuseReadClick(TObject *Sender)
{
    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned long u4Value = 0;
    if(false == IsValidHexWIFIData(edtEFuseWordAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_readEFuseAddr(1200, u4Addr, &u4Value);

    OutputMetaResult(" Read E-Fuse WORD", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    edtEFuseWordValue->Text = IntToHex((int)u4Value, 4);
    CurrentPageReset();
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::btnEFuseWriteClick(TObject *Sender)
{

    CurrentPageLock();
    unsigned int u4Addr = 0;
    unsigned int u4Value = 0;
    if(false == IsValidHexWIFIData(edtEFuseWordAddr->Text, &u4Addr))
    {
        OutputLog(" Error: addr is not valid");
        CurrentPageReset();
        return;
    }
    if(false == IsValidHexWIFIData(edtEFuseWordValue->Text, &u4Value))
    {
        OutputLog(" Error: value is not valid");
        CurrentPageReset();
        return;
    }
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_writeEFuseAddr(1200, u4Addr, u4Value);

    OutputMetaResult(" Write E-Fuse WORD", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifiMT6620::btnBandwidthSetClick(TObject *Sender)
{
    DBDCSelect(0);
    CurrentPageLock();
    int bandwidth = 0;
    META_RESULT mr = META_FAILED;
    unsigned int nJMode = 0;
    unsigned int nChBandwidth = 0;
    unsigned int nDataBandwidth = 0;
    unsigned int nPrimarySetting = 0;
    if(rbBandwidth20->Checked == true)
    {
        bandwidth=0;
    }
    else if (rbBandwidth40->Checked == true)
    {
        bandwidth=1;
    }
    else if (rbBandwidthU20->Checked == true)
    {
        bandwidth=2;
    }
    else if (rbBandwidthL20->Checked == true)
    {
        bandwidth=3;
    }
    else if(rbAdvanceSetting->Checked == true)
    {
        GetBandwidthPara(nJMode, nChBandwidth, nDataBandwidth, nPrimarySetting);
        if (cbJMode->Checked == false)
        {
            mr = m_WiFi_Man_Obj.WiFi_setJMode(1200, nJMode);
            OutputMetaResult(" Set JMode", mr);
            if(META_SUCCESS != mr)
            {
                CurrentPageReset();
                return;
            }
            mr = m_WiFi_Man_Obj.WiFi_setBandwidthEx(2000, nChBandwidth, nDataBandwidth, nPrimarySetting);
            OutputMetaResult(" Set BandwidthEx", mr);
        }
        else if(cbJMode->Checked == true)
        {
            mr = m_WiFi_Man_Obj.WiFi_setJMode(1200, nJMode);
            OutputMetaResult(" Set JMode", mr);
        }
        else
        {
            OutputLog(" Error: Wrong JMode setting");
        }
        CurrentPageReset();
        return;
    }
    else
    {
        OutputLog(" Error: Please select BandWidth");
        CurrentPageReset();
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_setBandwidth(1200, bandwidth);
    OutputMetaResult(" Set Bandwidth", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnGuardintervalSetClick(TObject *Sender)
{
    DBDCSelect(0);
    CurrentPageLock();
    int guardinterval;
    if(rbGuardinterval400->Checked == true)
    {
        guardinterval=1;
    }
    else if(rbGuardinterval800->Checked == true)
    {
        guardinterval=0;
    }
    else
    {
        OutputLog(" Error: Please select Guard Interval");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setGuardinterval(1200, guardinterval);
    OutputMetaResult(" Set Guardinterval", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}


//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::rbModeSelectSetClick(TObject *Sender)
{
    DBDCSelect(0);
    CurrentPageLock();
    int modeselect;
    if(rbModeSelectGreenFiled->Checked == true)
    {
        modeselect = 3;   //Green Field
    }
    else if(rbModeSelectMixedMode->Checked == true)
    {
        modeselect = 2;   //Mixed Mode
    }
    else if(rbModeSelect11AC->Checked == true)
    {
        modeselect = 4;   //11AC(VHT)
    }
    else
    {
        OutputLog(" Error: Please select Mode Select");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setModeSelect(1200, modeselect);
    OutputMetaResult(" Set ModeSelect", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnTemperatureGoClick(TObject *Sender)
{
    CurrentPageLock(TEMPERATURE_STOP);
    m_bTSTestFlag = true;
    timerTemperature->Enabled = true;
    btnTemperatureGo->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::timerTemperatureTimer(TObject *Sender)
{
    unsigned long u4ThermoRaw = 0;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_queryThermoInfo(1200, NULL, &u4ThermoRaw);
    OutputMetaResult(" queryThermoInfo", mr);
    if(META_SUCCESS != mr)
    {
        timerTemperature->Enabled = false;
        CurrentPageReset();
        return;
    }

    if (u4ThermoRaw == 0xFFFFFFFF)
    {
        OutputLog(" Hareware report busy after 99 times retry");
    }
    else
    {
        char strTemp[32] = {0};
        sprintf(strTemp, "Run %d, Thermo value: %#04X", ++m_u4ThermoRunNum, u4ThermoRaw);
        OutputLog(strTemp);
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::btnTXRXIQCalibrateClick(TObject *Sender)
{
    CurrentPageLock();
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setTxRxIQCalibration(1200);
    OutputMetaResult("Start Tx/Rx IQ Calibration", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_calibrationType = TXRXIQCalibration;
    timerCalibrator->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnReadIQCalParameterClick(
    TObject *Sender)
{
    unsigned long data = 0;
    META_RESULT mr;
    CurrentPageLock();
    for(int i= 0; i<m_calibrationLength; i+=4)
    {
        mr = m_WiFi_Man_Obj.WiFi_getCalResult(1200 , TXRXIQCalibration , i, &data);
        OutputMetaResult(" get TX/RX Calibration Result", mr);
        if(META_SUCCESS != mr)
        {
            CurrentPageReset();
            return;
        }
        char strTemp[32] = {0};
        sprintf(strTemp, "TX/RX Calibration Result : %#04X", data);
        OutputLog(strTemp);
    }
    m_calibrationLength =0;
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnTemperatureStopClick(TObject *Sender)
{
    timerTemperature->Enabled = false;
    btnTemperatureGo->Enabled = true;
    m_bTSTestFlag = false;
    CurrentPageReset();
}
//---------------------------------------------------------------------------



void __fastcall TfrmWmWifiMT6620::btnReadoutThermalSensorClick(
    TObject *Sender)
{

    CurrentPageLock();
    unsigned long value = 0;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_getTemperatureSensorResult(1200, &value);
    OutputMetaResult("Get Temperature Sensor Result", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    char strTemp[128] = {0};
    sprintf(strTemp, "The Temperature Sensor Result : %#04X", value);
    OutputLog(strTemp);
    CurrentPageReset();

}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnReadoutVoltageSensorClick(
    TObject *Sender)
{
    CurrentPageLock();
    unsigned long value = 0;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_getVoltageSensorResult(1200, &value);
    OutputMetaResult("Get Temperature Sensor Result", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    char strTemp[128] = {0};
    sprintf(strTemp, "The Temperature Sensor Result: %#04X", value);
    OutputLog(strTemp);
    CurrentPageReset();
}
//---------------------------------------------------------------------------




void __fastcall TfrmWmWifiMT6620::timerCalibratorTimer(TObject *Sender)
{
    unsigned long length = 0;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_getResultInformation(1200, m_calibrationType , &length);
    OutputMetaResult("Get Result Information", mr);
    if(META_SUCCESS != mr)
    {
        timerCalibrator->Enabled = false;
        CurrentPageReset();
        return;
    }
    if(length > 0)
    {
        char strTemp[32] = {0};
        sprintf(strTemp, "The length is: %#04X", length);
        OutputLog(strTemp);
        timerCalibrator->Enabled = false;
        m_calibrationLength = length;
        CurrentPageReset();
    }

}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnDPDCalibrateClick(TObject *Sender)
{
    CurrentPageLock();
     META_RESULT mr = m_WiFi_Man_Obj.WiFi_setDPDCalibration(1200);
    OutputMetaResult("Start DPD Calibration", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    m_calibrationType = DPDCalibration;
    timerCalibrator->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::btnReadDPDParametersClick(
    TObject *Sender)
{
    unsigned long data = 0;
    META_RESULT mr;
    CurrentPageLock();
    for(int i= 0; i<m_calibrationLength; i+=4)
    {
        mr = m_WiFi_Man_Obj.WiFi_getCalResult(1200 , DPDCalibration , i, &data);
        OutputMetaResult(" get DPD Calibration Result", mr);
        if(META_SUCCESS != mr)
        {
            CurrentPageReset();
            return;
        }
        char strTemp[32] = {0};
        sprintf(strTemp, "The DPD Calibration Result: %#04X", data);
        OutputLog(strTemp);
    }
    m_calibrationLength =0;
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnImportDPDParametersfromFileClick(
    TObject *Sender)
{
    CurrentPageLock();
    int index = 64 << 16;
    if(!(OpenDlgDPD->Execute()))
    {
        CurrentPageReset();
        return;
    }

    try
    {
        int iFileHandle = FileOpen(OpenDlgDPD->FileName, fmOpenRead);
        int iFileLength = FileSeek(iFileHandle,0,0);

        char* pszBuffer = new char[iFileLength+1];
        pszBuffer[iFileLength] = '\0';
        FileRead(iFileHandle, (char*)pszBuffer, iFileLength);
        AnsiString strBuffer = pszBuffer;


        FileClose(iFileHandle);
        int nIndex = 1;
        for (int i = 0; i < iFileLength; i+=4)
        {
            AnsiString strTemp = strBuffer.SubString(nIndex,4);
            unsigned int tmpValue;
            if(!IsValidHexWIFIData(strTemp,&tmpValue))
            {
                if( pszBuffer != NULL )
                {
                    delete [] pszBuffer;
                    pszBuffer = NULL;
                }
                CurrentPageReset();
                return;
            }

            nIndex += 4;
            index += 4;
            META_RESULT mr = m_WiFi_Man_Obj.WiFi_SetATParam(1200, index, tmpValue);

            if(META_SUCCESS != mr)
            {
                OutputLog(" Error: DPD Write failed");   //待定
                if( pszBuffer != NULL )
                {
                    delete [] pszBuffer;
                    pszBuffer = NULL;
                }
                CurrentPageReset();
                return;
            }

        }

        if( pszBuffer != NULL )
        {
            delete [] pszBuffer;
            pszBuffer = NULL;
        }
    }
    catch(...)
    {
        Application->MessageBox("Can't perform one of the following file operations: Open, Seek, Read, Close.", "File Error", IDOK);
    }

}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnReadoutTSSIClick(TObject *Sender)
{
    //TSSI Enable
    CurrentPageLock();
    unsigned long value = 0;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_TSSICalibration(1200);

    OutputMetaResult("set TSSI Enable", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    mr = m_WiFi_Man_Obj.WiFi_TSSICalibration(1200);
    OutputMetaResult("get TSSI Calibration Result", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    char strTemp[32] = {0};
    sprintf(strTemp, "TSSI Calibration Result : %#04X", value);
    OutputLog(strTemp);

    mr = m_WiFi_Man_Obj.WiFi_TSSICalibration(1200);

    OutputMetaResult("set TSSI Disable", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnClearLogClick(TObject *Sender)
{
    redtLog->Lines->Clear();
}
//---------------------------------------------------------------------------
unsigned long TfrmWmWifiMT6620::GetTargetVersion(void)
{
    unsigned long value = 0;
    OpenWiFi();
       META_RESULT mr = m_WiFi_Man_Obj.WiFi_GetChipVersion(18000,&value);
    if(mr != META_SUCCESS)
    {
        return 0;
    }
    return value;
}


void __fastcall TfrmWmWifiMT6620::timerTXTimer(TObject *Sender)
{
    CLocker locker(m_cs);    
    DBDCSelect(0);

    switch(cbTXTestType->ItemIndex)
    {
    case 0: // continuous packet tx
    {
        unsigned int u4TxPktCnt = 0;
        unsigned long u4Value;
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_GetATParam(1200, 32, &u4Value);
        OutputMetaResult("Band0 GetATParam", mr);
        if(META_SUCCESS != mr)
        {
            timerTX->Enabled = false;
            btnTXGo->Enabled = true;
            CurrentPageReset();
            return;
        }
        IsValidDecWIFIData(edtTXPktCnt->Text, u4TxPktCnt);
        if(u4Value == u4TxPktCnt)
        {
            timerTX->Enabled = false;
            btnTXGo->Enabled = true;
            CurrentPageReset();
            OutputLog(" TX completed");
        }
        break;
    }
    case 1:// tx output power
        break;
    case 2:// carrier suppression
        break;
    case 3:// local leakage
        break;
    case 4:// Enter Power OFF
        break;
    default:
        //error
        break;
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::timerRXTimer(TObject *Sender)
{
    CLocker locker(m_cs);
    DBDCSelect(0);
    unsigned long  fcsErrorValue = 0;
    unsigned long  rxOkValue = 0;
    long  rxRSSI = 0;
    long  rxRSSI1 = 0;

     META_RESULT mr = m_WiFi_Man_Obj.WiFi_ReceivedErrorCount(1200 , &fcsErrorValue);
    OutputMetaResult(" Get Received Error Count", mr);
    if(META_SUCCESS != mr)
    {
        timerRX->Enabled = false;
        CurrentPageReset();
        return;
    }
    mr = m_WiFi_Man_Obj.WiFi_ReceivedOKCount(1200 , &rxOkValue);
    OutputMetaResult(" Get Received OK Count", mr);
    if(META_SUCCESS != mr)
    {
        timerRX->Enabled = false;
        CurrentPageReset();
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_ReceivedRSSI(1200 , &rxRSSI);
    OutputMetaResult(" Get Received RSSI", mr);
    if(META_SUCCESS != mr)
    {
        timerRX->Enabled = false;
        CurrentPageReset();
        return;
    }
    if ((0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        mr = m_WiFi_Man_Obj.WiFi_ReceivedRSSI1(1200 , &rxRSSI1);
        OutputMetaResult(" Get Received RSSI1", mr);
    }

    stRXFCSerr->Caption = IntToStr(fcsErrorValue);
    stRXOK->Caption = IntToStr(rxOkValue);
    if ((fcsErrorValue+rxOkValue) != 0 )
    {
        stRXPER->Caption =  IntToStr(fcsErrorValue *100/(fcsErrorValue+rxOkValue));
    }
    stRXRSSI0->Caption = IntToStr(rxRSSI);
    if ((0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        stRXRSSI01->Caption = IntToStr(rxRSSI1);
    }

}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnSaveDPDParameterstoFileClick(
    TObject *Sender)
{
    CurrentPageLock();
    char strEEbuf[2048] = {0};

    unsigned long u4Tmp;
    if(!(SaveDlgDPD->Execute()))
    {
        CurrentPageReset();
        return;
    }

    if(FileExists(SaveDlgDPD->FileName))
    {
        char szFileName[4096] = {0};
        fnsplit(saveDlgEE->FileName.c_str(), 0, 0, szFileName, 0);
        strcat(szFileName, ".BAK");
        RenameFile(saveDlgEE->FileName, szFileName);
    }

    for(int u2Tmp = 0; u2Tmp < m_calibrationLength/4; u2Tmp+4)
    {
         META_RESULT mr = m_WiFi_Man_Obj.WiFi_getCalResult(1200, DPDCalibration, u2Tmp, &u4Tmp);
        if(META_SUCCESS != mr)
        {

            OutputLog(" Error: DPD save as file failed");
            CurrentPageReset();
            return ;
        }


        char strBuf[10] = {0};
        sprintf(strBuf, "%04X", u4Tmp);
        strcat(strEEbuf, strBuf);
    }

    int iFileHandle = FileCreate(saveDlgEE->FileName);
    FileWrite(iFileHandle, strEEbuf, strlen(strEEbuf));
    FileClose(iFileHandle);

    OutputLog(" EEPROM save as file success");
    CurrentPageReset();
}
//---------------------------------------------------------------------------



void __fastcall TfrmWmWifiMT6620::m_btnSet_2GHz_TX_Power_ProfileClick(TObject *Sender)
{
    frm2GH_TX_Power_Profile->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::m_btnSet_5GHz_TX_Power_ProfileClick(
    TObject *Sender)
{
    frm5GHz_TX_Power_Profile->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifiMT6620::hideFlagExecute(TObject *Sender)
{
    g_bHideEnable = g_bHideEnable ? false : true;
    ApplyHideProperty();
}
//---------------------------------------------------------------------------
void TfrmWmWifiMT6620::ApplyHideProperty()
{
    Panel3->Visible = !g_bHideEnable;
    Label4->Visible = !g_bHideEnable;
    GroupBox1->Visible = !g_bHideEnable;
    GroupBox2->Visible = !g_bHideEnable;
    GroupBox3->Visible = !g_bHideEnable;
    Panel6->Visible = !g_bHideEnable;
}

void __fastcall TfrmWmWifiMT6620::FormActivate(TObject *Sender)
{
    ApplyHideProperty();
}
//---------------------------------------------------------------------------
unsigned long TfrmWmWifiMT6620::GetWifiChipVersion(void)
{
    return m_wifiChipVersion;
}
void __fastcall TfrmWmWifiMT6620::m_btnCrystalTrimClick(TObject *Sender)
{
    frmCrystalTrim->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::FormClose(TObject *Sender,
        TCloseAction &Action)
{
    if( m_bSwitchAntennaOK )
    {
        META_RESULT  mr = META_FAILED;
        mr = m_WiFi_Man_Obj.WiFi_switchAntenna(5000, 1);
        if(META_SUCCESS != mr)
        {
            return;
        }
        m_bSwitchAntennaOK = false;
    }
    CloseWiFi();
}
//
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::FormHide(TObject *Sender)
{
    if( m_bSwitchAntennaOK )
    {
        META_RESULT  mr = META_FAILED;
              mr = m_WiFi_Man_Obj.WiFi_switchAntenna(5000, 1);
        //  OutputMetaResult(" SP_META_WiFi_switchAntenna_r", mr);
        if(META_SUCCESS != mr)
        {
            return;
        }
        m_bSwitchAntennaOK = false;
    }

    CloseWiFi();
}
//---------------------------------------------------------------------------


void TfrmWmWifiMT6620::OpenWiFi(void)
{
    if( g_eWiFiState == WIFI_STATE_CLOSE )
    {
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_Open(10000);
        if( mr == META_FAILED )
        {
            OutputLog(" Open WiFi fail(may be the load version of the phone is old, please help to check it)");
        }
        else
        {
            OutputMetaResult(" Open WiFi", mr);
        }
        g_eWiFiState = WIFI_STATE_OPEN;
    }
}


void TfrmWmWifiMT6620::CloseWiFi(void)
{
    if( g_eWiFiState == WIFI_STATE_OPEN )
    {
       m_WiFi_Man_Obj.WiFi_Close(5000);
       g_eWiFiState = WIFI_STATE_CLOSE;
    }

}
void __fastcall TfrmWmWifiMT6620::rbAdvanceSettingClick(TObject *Sender)
{
    DBDCSelect(0);
    GroupBox9->Visible = true;
    cbJModeClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbJModeClick(TObject *Sender)
{
    DBDCSelect(0);
    if ( cbJMode->Checked )
    {
       cbxDBW->Enabled = false;
       cbxPrimaryCh->Enabled = false;
       cbxCBW->Clear();
       cbxCBW->Items->Add("BW5");
       cbxCBW->Items->Add("BW10");
       cbxCBW->ItemIndex = 0;
    }
    else
    {
        cbxDBW->Enabled = true;
        cbxPrimaryCh->Enabled = true;
        cbxCBW->Clear();
        cbxCBW->Items->Add("BW20");
        cbxCBW->Items->Add("BW40");
        cbxCBW->Items->Add("BW80");
        cbxCBW->Items->Add("BW160");
        cbxCBW->Items->Add("BW160NC");
        cbxCBW->ItemIndex = 0;
        cbxCBWChange(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbxCBWChange(TObject *Sender)
{
    if(cbxCBW->Text == "BW20")
    {
        cbxDBW->Clear();
        cbxDBW->Items->Add("BW20");
        cbxDBW->ItemIndex = 0;
        LabelTX1Channel->Visible = false;
        cbChannelTX1->Visible = false;
        labelUserDefineTX1->Visible = false;
        edtChannelTX1->Visible = false;
        udChannelTX1->Visible = false;
    }
    else if(cbxCBW->Text == "BW40")
    {
        cbxDBW->Clear();
        cbxDBW->Items->Add("BW20");
        cbxDBW->Items->Add("BW40");
        cbxDBW->ItemIndex = 0;
        LabelTX1Channel->Visible = false;
        cbChannelTX1->Visible = false;
        labelUserDefineTX1->Visible = false;
        edtChannelTX1->Visible = false;
        udChannelTX1->Visible = false;
    }
    else if(cbxCBW->Text == "BW80")
    {
        cbxDBW->Clear();
        cbxDBW->Items->Add("BW20");
        cbxDBW->Items->Add("BW40");
        cbxDBW->Items->Add("BW80");
        cbxDBW->ItemIndex = 0;
        LabelTX1Channel->Visible = false;
        cbChannelTX1->Visible = false;
        labelUserDefineTX1->Visible = false;
        edtChannelTX1->Visible = false;
        udChannelTX1->Visible = false;
    }
    else if(cbxCBW->Text == "BW160")
    {
        cbxDBW->Clear();
        cbxDBW->Items->Add("BW20");
        cbxDBW->Items->Add("BW40");
        cbxDBW->Items->Add("BW80");
        cbxDBW->Items->Add("BW160");
        cbxDBW->ItemIndex = 0;
        LabelTX1Channel->Visible = false;
        cbChannelTX1->Visible = false;
        labelUserDefineTX1->Visible = false;
        edtChannelTX1->Visible = false;
        udChannelTX1->Visible = false;
    }
    else if(cbxCBW->Text == "BW160NC")
    {
        cbxDBW->Clear();
        cbxDBW->Items->Add("BW20");
        cbxDBW->Items->Add("BW40");
        cbxDBW->Items->Add("BW80");
        cbxDBW->Items->Add("BW160");
        cbxDBW->ItemIndex = 0;
        if ((0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
        {
            LabelTX1Channel->Visible = true;
            cbChannelTX1->Visible = true;
            labelUserDefineTX1->Visible = true;
            edtChannelTX1->Visible = true;
            udChannelTX1->Visible = true;
        }
    }
    cbxDBWChange(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbxDBWChange(TObject *Sender)
{
    if(cbxDBW->Text == "BW20"  )
    {
        if (cbxCBW->Text == "BW20")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if (cbxCBW->Text == "BW40")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if (cbxCBW->Text == "BW80")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if (cbxCBW->Text == "BW160")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->Items->Add("4");
            cbxPrimaryCh->Items->Add("5");
            cbxPrimaryCh->Items->Add("6");
            cbxPrimaryCh->Items->Add("7");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if (cbxCBW->Text == "BW160NC")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->ItemIndex = 0;
        }
    }
    else if(cbxDBW->Text == "BW40")
    {
        if (cbxCBW->Text == "BW40")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if(cbxCBW->Text == "BW80")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if(cbxCBW->Text == "BW160")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->Items->Add("4");
            cbxPrimaryCh->Items->Add("5");
            cbxPrimaryCh->Items->Add("6");
            cbxPrimaryCh->Items->Add("7");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if(cbxCBW->Text == "BW160NC")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->ItemIndex = 0;
        }
    }
    else if(cbxDBW->Text == "BW80")
    {
        if(cbxCBW->Text == "BW80")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if(cbxCBW->Text == "BW160")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->Items->Add("4");
            cbxPrimaryCh->Items->Add("5");
            cbxPrimaryCh->Items->Add("6");
            cbxPrimaryCh->Items->Add("7");
            cbxPrimaryCh->ItemIndex = 0;
        }
        else if(cbxCBW->Text == "BW160NC")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->ItemIndex = 0;
        }
    }
    else if(cbxDBW->Text == "BW160")
    {
        if(cbxCBW->Text == "BW160")
        {
            cbxPrimaryCh->Clear();
            cbxPrimaryCh->Items->Add("0");
            cbxPrimaryCh->Items->Add("1");
            cbxPrimaryCh->Items->Add("2");
            cbxPrimaryCh->Items->Add("3");
            cbxPrimaryCh->Items->Add("4");
            cbxPrimaryCh->Items->Add("5");
            cbxPrimaryCh->Items->Add("6");
            cbxPrimaryCh->Items->Add("7");
            cbxPrimaryCh->ItemIndex = 0;
        }
    }
}
//---------------------------------------------------------------------------



void __fastcall TfrmWmWifiMT6620::rbBandwidthL20Click(TObject *Sender)
{
     DBDCSelect(0);
     GroupBox9->Visible = false;
     //Reset channel list
     cbChannel->Clear();
     for(int i = 0 ; i < sizeof(chnlListmt6620_20)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
     {
         cbChannel->Items->Add(IntToStr(chnlListmt6620_20[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_20[i].chnlFreq/1000)+"MHz)");
     }
     cbChannel->Items->Add((AnsiString)"USER DEFINE");
     cbChannel->ItemIndex = 0;
     //
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::rbBandwidthU20Click(TObject *Sender)
{
     DBDCSelect(0);
     GroupBox9->Visible = false;
     //Reset channel list
     cbChannel->Clear();
     for(int i = 0 ; i < sizeof(chnlListmt6620_20)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
     {
         cbChannel->Items->Add(IntToStr(chnlListmt6620_20[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_20[i].chnlFreq/1000)+"MHz)");
     }
     cbChannel->Items->Add((AnsiString)"USER DEFINE");
     cbChannel->ItemIndex = 0;
     //
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::rbBandwidth40Click(TObject *Sender)
{
     DBDCSelect(0);
     GroupBox9->Visible = false;
     //Update 5G BW40 channel list
     cbChannel->Clear();
     for(int i = 0 ; i < sizeof(chnlListmt6620_40)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
     {
         cbChannel->Items->Add(IntToStr(chnlListmt6620_40[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_40[i].chnlFreq/1000)+"MHz)");
     }
     cbChannel->Items->Add((AnsiString)"USER DEFINE");
     cbChannel->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::rbBandwidth20Click(TObject *Sender)
{
    DBDCSelect(0);
     GroupBox9->Visible = false;
     //Reset channel list
     cbChannel->Clear();
     for(int i = 0 ; i < sizeof(chnlListmt6620_20)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
     {
         cbChannel->Items->Add(IntToStr(chnlListmt6620_20[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_20[i].chnlFreq/1000)+"MHz)");
     }
     cbChannel->Items->Add((AnsiString)"USER DEFINE");
     cbChannel->ItemIndex = 0;
     //
}
//---------------------------------------------------------------------------

void TfrmWmWifiMT6620::GetBandwidthPara(unsigned int &nJMode, unsigned int &nChBandwidth, unsigned int &nDataBandwidth,
                          unsigned int &nPrimarySetting)
{
    nJMode = 0;
    if (cbJMode->Checked == false)
    {
        nChBandwidth = 0;
        nDataBandwidth = 0;
        nPrimarySetting = 0;
        if ( cbxCBW->ItemIndex >= 0 )
        {
            if (cbxCBW->Text == "BW20")
            {
                nChBandwidth = 0;
            }
            else if(cbxCBW->Text == "BW40")
            {
                nChBandwidth = 1;
            }
            else if(cbxCBW->Text == "BW80")
            {
                nChBandwidth = 2;
            }
            else if(cbxCBW->Text == "BW160")
            {
                nChBandwidth = 3;
            }
            else if(cbxCBW->Text == "BW160NC")
            {
                nChBandwidth = 4;
            }
        }
        if ( cbxDBW->ItemIndex >= 0 )
        {
            if (cbxDBW->Text == "BW20")
            {
                nDataBandwidth = 0;
            }
            else if(cbxDBW->Text == "BW40")
            {
                nDataBandwidth = 1;
            }
            else if(cbxDBW->Text == "BW80")
            {
                nDataBandwidth = 2;
            }
            else if(cbxDBW->Text == "BW160")
            {
                nDataBandwidth = 3;
            }
        }
        if ( cbxPrimaryCh->ItemIndex >= 0 )
        {
            if (cbxPrimaryCh->Text == "0")
            {
                nPrimarySetting = 0;
            }
            else if(cbxPrimaryCh->Text == "1")
            {
                nPrimarySetting = 1;
            }
            else if(cbxPrimaryCh->Text == "2")
            {
                nPrimarySetting = 2;
            }
            else if(cbxPrimaryCh->Text == "3")
            {
                nPrimarySetting = 3;
            }
            else if(cbxPrimaryCh->Text == "4")
            {
                nPrimarySetting = 4;
            }
            else if(cbxPrimaryCh->Text == "5")
            {
                nPrimarySetting = 5;
            }
            else if(cbxPrimaryCh->Text == "6")
            {
                nPrimarySetting = 6;
            }
            else if(cbxPrimaryCh->Text == "7")
            {
                nPrimarySetting = 7;
            }
        }
        nJMode = 0;
    }
    else if(cbJMode->Checked == true)
    {
        if (cbxCBW->Text == "BW5")
        {
            nJMode = 1;
        }
        else if(cbxCBW->Text == "BW10")
        {
            nJMode = 2;
        }
    }
}


void __fastcall TfrmWmWifiMT6620::cbChannelDropDown(TObject *Sender)
{
    //Reset channel list
    int i = 0;
    cbChannel->Clear();
    if (rbBandwidth40->Checked == true)
    {
        for(i = 0 ; i < sizeof(chnlListmt6620_40)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {
            cbChannel->Items->Add(IntToStr(chnlListmt6620_40[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_40[i].chnlFreq/1000)+"MHz)");
        }
    }
    else if (rbAdvanceSetting->Checked == true)
    {
        if (cbxCBW->Text == "BW5")
        {
            for(i = 0 ; i < sizeof(chnlListmt6620_5)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
            {
               cbChannel->Items->Add(IntToStr(chnlListmt6620_5[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_5[i].chnlFreq/1000)+"MHz)");
            }
        }
        else if (cbxCBW->Text == "BW10")
        {
            for(i = 0 ; i < sizeof(chnlListmt6620_10)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
            {
               cbChannel->Items->Add(IntToStr(chnlListmt6620_10[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_10[i].chnlFreq/1000)+"MHz)");
            }
        }
        else if (cbxCBW->Text == "BW20")
        {
            for(i = 0 ; i < sizeof(chnlListmt6620_20)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
            {
                if((rbDBDC->Checked == true) && (chnlListmt6620_20[i].chnlFreq/1000 > 2484))
                {
                    break;
                }
                cbChannel->Items->Add(IntToStr(chnlListmt6620_20[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_20[i].chnlFreq/1000)+"MHz)");
            }
        }
        else if (cbxCBW->Text == "BW40")
        {
            for(i = 0 ; i < sizeof(chnlListmt6620_40)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
            {
               if((rbDBDC->Checked == true) && (chnlListmt6620_20[i].chnlFreq/1000 > 2484))
                    break;
               cbChannel->Items->Add(IntToStr(chnlListmt6620_40[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_40[i].chnlFreq/1000)+"MHz)");
            }
        }
        else if (cbxCBW->Text == "BW80")
        {
            for(i = 0 ; i < sizeof(chnlListmt6620_80)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
            {
               cbChannel->Items->Add(IntToStr(chnlListmt6620_80[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_80[i].chnlFreq/1000)+"MHz)");
            }
        }
        else if (cbxCBW->Text == "BW160" || cbxCBW->Text == "BW160NC")
        {
            for(i = 0 ; i < sizeof(chnlListmt6620_160)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
            {
               cbChannel->Items->Add(IntToStr(chnlListmt6620_160[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_160[i].chnlFreq/1000)+"MHz)");
            }
        }
        else
        {
            OutputLog(" Error: please select the right bandwidth");
            return;
        }
    }
    else
    {
        for(i = 0 ; i < sizeof(chnlListmt6620_20)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {
            cbChannel->Items->Add(IntToStr(chnlListmt6620_20[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_20[i].chnlFreq/1000)+"MHz)");
        }
    }
    cbChannel->Items->Add((AnsiString)"USER DEFINE");
    cbChannel->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::udChannelChanging(TObject *Sender,
      bool &AllowChange)
{
    edtChannel->Text = udChannel->Position;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnRSSICOMPClick(TObject *Sender)
{
    if ((0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        frm6632RSSICOMP->ShowModal();
    }
    else
    {
        frmRSSICOMP->ShowModal();
    }
}
//---------------------------------------------------------------------------

void TfrmWmWifiMT6620::DBDCSelect(int index)
{
    if(rbDBDC->Checked)
    {
       META_RESULT mr =  m_WiFi_Man_Obj.Wifi_setDBDCIndex(1200,index);
       AnsiString indexLog = "Set DBDC index = " + IntToStr(index);
       OutputMetaResult(indexLog.c_str(), mr);
    }
}

void __fastcall TfrmWmWifiMT6620::cbxNssChange(TObject *Sender)
{
    DBDCSelect(0);
    if(cbxNss->Text == "2")
    {
        //set rate
        cbRate->Clear();
        for(int i = 0; i < sizeof(rateSettingmt6632) / sizeof(DATA_RATE_SETTING); i++)
        {
            cbRate->Items->Add((AnsiString)(rateSettingmt6632[i].pszRate));
        }
        cbRate->ItemIndex = 0;
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 2);
        OutputMetaResult(" setNss", mr);
        cbTXRX0 -> Checked = true;
        cbTXRX1 -> Checked = true;
        mr = m_WiFi_Man_Obj.WiFi_setTXPath(1200, 3);
        OutputMetaResult(" set TX0/TX1 Path", mr);
        //mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 3);
        mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 0x00030000);
        OutputMetaResult(" set RX0/RX1 Path", mr);
    }
    else
    {
        //set rate
        cbRate->Clear();
        for(int i = 0; i < sizeof(rateSettingmt6620) / sizeof(DATA_RATE_SETTING); i++)
        {
            cbRate->Items->Add((AnsiString)(rateSettingmt6620[i].pszRate));
        }
        cbRate->ItemIndex = 0;
        cbTXRX0 -> Checked = false;
        cbTXRX1 -> Checked = false;
        //META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 1);
        //OutputMetaResult(" setNss", mr);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbTXRX0Click(TObject *Sender)
{
    DBDCSelect(0);
    setTXRXPath();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbTXRX1Click(TObject *Sender)
{
    DBDCSelect(0);
    setTXRXPath();

}
//---------------------------------------------------------------------------

void TfrmWmWifiMT6620::setTXRXPath()
{
    if(cbxNss->Text == "1")
    {
        if ( cbTXRX0->Checked && cbTXRX1->Checked)
        {
            META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 1);
            OutputMetaResult(" setNss", mr);
            mr = m_WiFi_Man_Obj.WiFi_setTXPath(1200, 0x80000018);
            OutputMetaResult(" set TX0/TX1 Path", mr);
            mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 0x00030000);
            OutputMetaResult(" set RX0/RX1 Path", mr);
        }
        if(cbTXRX0->Checked && !(cbTXRX1->Checked))
        {
            META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 1);
            OutputMetaResult(" setNss", mr);
            mr = m_WiFi_Man_Obj.WiFi_setTXPath(1200, 1);
            OutputMetaResult(" set TX0 Path", mr);
            mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 0x00010000);
            OutputMetaResult(" set RX0 Path", mr);
        }
        if(!(cbTXRX0->Checked) && cbTXRX1->Checked)
        {
            META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 1);
            OutputMetaResult(" setNss", mr);
            mr = m_WiFi_Man_Obj.WiFi_setTXPath(1200, 2);
            OutputMetaResult(" set TX1 Path", mr);
            //mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 2);
            mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 0x00020000);
            OutputMetaResult(" set RX1 Path", mr);
        }
    }
}

void __fastcall TfrmWmWifiMT6620::cbChannelTX1Change(TObject *Sender)
{
     //DoChannelChange();
    if (cbChannelTX1->Text == "USER DEFINE")
    {
        labelUserDefineTX1->Enabled = true;
        edtChannelTX1->Enabled = true;
        udChannelTX1->Enabled = true;
    }
    else
    {
        labelUserDefineTX1->Enabled = false;
        edtChannelTX1->Enabled = false;
        udChannelTX1->Enabled = false;
        DoChannelTX1Change();
    }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbChannelTX1DropDown(TObject *Sender)
{
    //Reset channel list
    int i = 0;
    cbChannelTX1->Clear();

    for(i = 0 ; i < sizeof(chnlListmt6620_80)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
    {
        cbChannelTX1->Items->Add(IntToStr(chnlListmt6620_80[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_80[i].chnlFreq/1000)+"MHz)");
    }
    cbChannelTX1->Items->Add((AnsiString)"USER DEFINE");
    cbChannelTX1->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::udChannelTX1Changing(TObject *Sender,
      bool &AllowChange)
{
    edtChannelTX1->Text = udChannelTX1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnOpenOffsetClick(TObject *Sender)
{
/*    if(!OpenDlgOffset->Execute())
    {
        Application->MessageBox( "Execution Failure : Open offset ini file failed !", "FAILURE", MB_OK );
        return;
    }

    //Check is offset ini file or not
    AnsiString temp = UpperCase(OpenDlgOffset->FileName);
    int pos = temp.AnsiPos("OFFSET");
    if( pos == 0)
    {
        Application->MessageBox( "Please confirm this is a ini file!", "WARNING", MB_OK );
    }

    if(FileExists(OpenDlgOffset->FileName)  && FileExists(OpenDlgValue->FileName) )
    {
        btnDwn->Enabled = true;
        btnSave->Enabled = true;        
    }
*/
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnOpenValueClick(TObject *Sender)
{
    if(!OpenDlgValue->Execute())
    {
        Application->MessageBox( "Execution Failure : Open value ini file failed !", "FAILURE", MB_OK );
        return;
    }

    if(FileExists(OpenDlgValue->FileName))
    {
        btnDwn->Enabled = true;
        //btnSave->Enabled = true;
    }
}
//---------------------------------------------------------------------------

AnsiString FindeTransferFile(AnsiString offsetFile)
{
    AnsiString transferFile;
    AnsiString chip;
    chip = read_field(offsetFile, Application->ExeName, "Chip", "Chip", "");
    transferFile = chip+".ini";
    LOG("Chip is %s config by offset ini file %s ",chip,transferFile);
    return transferFile;

}

AnsiString getOffetFileName(unsigned long wifiChipVersion)
{
    char chipVersion[32]={0};
    AnsiString asPath;

    sprintf(chipVersion,"MT%04x",wifiChipVersion);

    getPathFromStr(Application->ExeName, asPath);
    AnsiString offsetFile =asPath +"wifi_ini\\"+ chipVersion + "_TxRx_Setting_Offset.ini";

    return offsetFile;
}

AnsiString deleteComment(AnsiString valueTemp)
{
        AnsiString value;
        //删掉注释内容
        int pos = valueTemp.AnsiPos(";");

        if(pos != 0)
        {
            value = valueTemp.SubString(0,pos-1);
        }
        else
        {
            value =  valueTemp;
        }
        value = value.Trim();
        return value;
}

void __fastcall TfrmWmWifiMT6620::btnDwnClick(TObject *Sender)
{

    AnsiString offsetFile = getOffetFileName(m_wifiChipVersion);//OpenDlgOffset->FileName;
    AnsiString valueFile = OpenDlgValue->FileName;
    AnsiString transferFile;
    ifstream infile;
    infile.open(offsetFile.c_str());

    char buf[1024]={0};
    AnsiString section;

    LOG("Offset File is %s",offsetFile);
    LOG("Value File File is %s",valueFile);

    while (infile.getline(buf, sizeof(buf)))
    {
        int i = 0;
        while(buf[i]!='\;')
        {
            if(i>sizeof(buf))
            {
                break;
            }

            if(buf[i]=='[')
            {
                int j = 0;
                char temp[1024]={0};
                while(buf[i+1]!=']')
                {
                     temp[j] = buf[i+1];
                     j++;
                     i++;
                }
                section = temp;
                if(section == "Chip")
                {
                    transferFile = FindeTransferFile(offsetFile);
                    LOG("Transfer File File is %s",valueFile);
                }
                break;
            }

            if(buf[i]!='=')
            {
                i++;
                continue;
            }
            else
            {
               //获取等号前的内容作为key
                char key[64]={0};
                strncpy(key,(const char *)buf,i);

                int transferFlag = 0;
                char * p = strstr(key,"\\");
                if(p != NULL && p == key)  //行首有转译字符
                {
                    transferFlag = 1;
                }

                //从offset ini 获取offset,从value ini 获取value
                AnsiString offset = read_field(offsetFile, Application->ExeName, section, key, "");
                AnsiString valueTemp = read_field(valueFile, Application->ExeName, section, key, "");

                offset = deleteComment(offset);
                valueTemp =  deleteComment(valueTemp);

                LOG("section=%s key=%s offset=%s valueTemp=%s",section,key,offset,valueTemp);

/*                if(section==NULL || key==NULL || offset==NULL || valueTemp==NULL)
                {
                    AnsiString  errMsg= " Err: section=" + section + " key=" + key + " offset=" + offset + " valueTemp=" + valueTemp;
                    OutputLog(errMsg.c_str());
                    return;
                }
 */
                //写到Nvram
                NVRAM_ACCESS_STRUCT wifi_nvram;
                char pszBufferRaw[512]={0};
                if(!strcmp(key,"Enable"))
                {
                    pszBufferRaw[0]=StrToInt(valueTemp);
                }
                else if(!strcmp(key,"Chip"))
                {
                    break;
                }
                else if(transferFlag == 0)
                {
                    pszBufferRaw[0] = StrToFloat(valueTemp)*2;
                }
                else
                {
                    AnsiString transferValue = read_field(transferFile, Application->ExeName, "CH Power Offset and Register Vaue", valueTemp, "");
                    LOG("transferValue = %s",transferValue);
                    pszBufferRaw[0]=StrToInt(transferValue);
                }
                wifi_nvram.dataLen = 1;
                wifi_nvram.dataOffset = offset.ToInt();
                wifi_nvram.data = pszBufferRaw;


                META_RESULT mr = m_WiFi_Man_Obj.WiFi_WriteNVRAM(1200, &wifi_nvram);
                if(META_SUCCESS != mr)
                {
                    OutputMetaResult(" Write Nvram", mr);
                    return;
                }


                LOG("Write WIFI NVRAM %s %s %s=%d ",section,key,offset,pszBufferRaw[0]);
                break;
            }
        }
        memset(buf,'\0',sizeof(buf));

    }
    OutputMetaResult(" Write Nvram", META_SUCCESS);
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::btnSaveClick(TObject *Sender)
{

    AnsiString offsetFile =getOffetFileName(m_wifiChipVersion);
    fstream ofile;
    ofile.open(offsetFile.c_str());
    AnsiString transferFile;
    char buf[1024]={0};
    AnsiString section;
    AnsiString chip;
    if(!(saveDlgIni->Execute()))
    {
        Application->MessageBox( "Execution Failure : Open value ini file failed !", "FAILURE", MB_OK );
        return;
    }

    fstream vfile;
    if(!FileExists(saveDlgIni->FileName))
    {
        int iFileHandle = FileCreate(saveDlgIni->FileName);
        FileClose(iFileHandle);
    }
    
    vfile.open(saveDlgIni->FileName.c_str());

    while (ofile.getline(buf, sizeof(buf)))
    {
        int i = 0;
        while(buf[i]!='\;')
        {
            if(i>sizeof(buf))
            {
                break;
            }

            if(buf[i]=='[')
            {
                //copy section
                int j = 0;
                char temp[1024]={0};
                while(buf[i+1]!=']')
                {
                     temp[j] = buf[i+1];
                     j++;
                     i++;
                }
                section = temp;

                if(section == "Chip")
                {
                    transferFile = FindeTransferFile(offsetFile);
                }
                //将section写入文件
                vfile<<"["<<section.c_str()<<"]"<<"\n";

                break;
            }

            if(buf[i]!='=')
            {
                i++;
                continue;
            }
            else
            {
               //获取等号前的内容作为key
                char key[64]={0};
                strncpy(key,(const char *)buf,i);
                vfile<<key<<"=";

                int transferFlag = 0;
                char * p = strstr(key,"\\");
                if(p != NULL && p == key)  //行首有转译字符
                {
                    transferFlag = 1;
                }

                //从offset ini 获取offset
                AnsiString offsetTemp = read_field(offsetFile, Application->ExeName, section, key, "");
                offsetTemp = deleteComment(offsetTemp);
                char  pszBufferRaw[512]={0};
                //从Nvram中读取value
                if(strcmp(key,"Chip"))
                {
                    NVRAM_ACCESS_STRUCT wifi_nvram;
                    wifi_nvram.dataLen = 1;
                    wifi_nvram.dataOffset = offsetTemp.ToInt();
                    wifi_nvram.data = pszBufferRaw;

                    META_RESULT mr = m_WiFi_Man_Obj.WiFi_ReadNVRAM(1200, &wifi_nvram);
                    if(META_SUCCESS != mr)
                    {
                        OutputMetaResult(" Read Nvram", mr);
                        return;
                    }
                }
                LOG("Read WIFI Nvram %s %s %s %s" ,section,key,offsetTemp,FloatToStr(pszBufferRaw[0]));
                float temp;

                if(!strcmp(key,"Enable"))
                {
                    temp =  pszBufferRaw[0];
                }
                else if(!strcmp(key,"Chip"))
                {
                    vfile<<offsetTemp.c_str()<<"\n";
                    break;
                }
                else if(transferFlag == 0)
                {
                    temp =  pszBufferRaw[0]/2.0;
                }
                else
                {
                    AnsiString value = FloatToStr(pszBufferRaw[0]);
                    AnsiString transferValue = read_field(transferFile, Application->ExeName, "Register Vaue and CH Power Offset", value, "");
                    LOG("transferValue = %s",transferValue);
                    vfile<<transferValue.c_str()<<"\n";
                    break;
                }
                vfile<<FloatToStr(temp).c_str()<<"\n";
                break;
             }
        }
        memset(buf,'\0',sizeof(buf));
    }
    vfile.close();
    OutputMetaResult(" Read Nvram", META_SUCCESS);
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::btnScriptClick(TObject *Sender)
{
    if(!OpenDlgScript->Execute())
    {
        Application->MessageBox( "Execution Failure : Open script file failed !", "FAILURE", MB_OK );
        return;
    }

    if(!FileExists(OpenDlgScript->FileName))
    {
        Application->MessageBox( "Execution Failure : Open script file failed !", "FAILURE", MB_OK );
        return;
    }

    AnsiString scriptFile = OpenDlgScript->FileName;

    ifstream infile;
    infile.open(scriptFile.c_str());

    char buf[1024]={0};
    WIFI_SCRIPT_REQ rReq;
    WIFI_SCRIPT_CNF rCnf;

    OutputLog("Load Script File: ");

    OutputLog(scriptFile.c_str());

    while(infile.getline(buf, sizeof(buf)))
    {
        memset(&rReq, 0, sizeof(WIFI_SCRIPT_REQ));
	memset(&rCnf, 0, sizeof(WIFI_SCRIPT_CNF));

        OutputLog("Run CMD: ");
        OutputLog(buf);
        
        memcpy(rReq.script,buf,strlen(buf));

	META_RESULT mr = m_WiFi_Man_Obj.WiFi_SendScript(5000, &rReq, &rCnf);

        OutputLog("Result: ");
        OutputLog(rCnf.confirm);

        memset(&buf, 0, sizeof(buf));
    }

    infile.close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbAntSwapChange(TObject *Sender)
{
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_setAntSwap(5000,cbAntSwap->ItemIndex);
        OutputMetaResult(" setAntSwap", mr);
}

void __fastcall TfrmWmWifiMT6620::rbMIMOClick(TObject *Sender)
{
        Panel7->Visible = false;
        Label17->Visible = false;
        cbTXRX1->Enabled = true;

        META_RESULT mr = m_WiFi_Man_Obj.Wifi_setDBDCEnable(1200,0);
        OutputMetaResult(" Disable DBDC", mr);

        mr = m_WiFi_Man_Obj.Wifi_setDBDCIndex(1200,0);
        OutputMetaResult(" Set DBDC Index 0", mr);

}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::rbDBDCClick(TObject *Sender)
{
        Panel7->Visible = true;
        Label17->Visible = true;
        cbTXRX1->Enabled = false;
        cbTXRX11->Enabled = false;
        META_RESULT mr = m_WiFi_Man_Obj.Wifi_setDBDCEnable(1200,1);
        OutputMetaResult(" Enable DBDC", mr);

        //band0 
        cbxCBW->Clear();
        cbxCBW->Items->Add("BW20");
        cbxCBW->Items->Add("BW40");
        cbxCBW->ItemIndex = 0;
        cbxCBWChange(this);

        //band1
        cbxCBW1->Clear();
        cbxCBW1->Items->Add("BW20");
        cbxCBW1->Items->Add("BW40");
        cbxCBW1->Items->Add("BW80");
        cbxCBW1->ItemIndex = 0;
        cbxCBW1Change(this);

        
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbxNss1Change(TObject *Sender)
{
    DBDCSelect(1);
    if(cbxNss1->Text == "2")
    {
        //set rate
        cbRate1->Clear();
        for(int i = 0; i < sizeof(rateSettingmt6632) / sizeof(DATA_RATE_SETTING); i++)
        {
            cbRate->Items->Add((AnsiString)(rateSettingmt6632[i].pszRate));
        }
        cbRate1->ItemIndex = 0;
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 2);
        OutputMetaResult(" setNss", mr);
        cbTXRX10 -> Checked = true;
        cbTXRX11 -> Checked = true;
        mr = m_WiFi_Man_Obj.WiFi_setTXPath(1200, 3);
        OutputMetaResult(" set TX0/TX1 Path", mr);
        //mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 3);
        mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 0x00030000);
        OutputMetaResult(" set RX0/RX1 Path", mr);
    }
    else
    {
        //set rate
        cbRate1->Clear();
        for(int i = 0; i < sizeof(rateSettingmt6620) / sizeof(DATA_RATE_SETTING); i++)
        {
            cbRate->Items->Add((AnsiString)(rateSettingmt6620[i].pszRate));
        }
        cbRate1->ItemIndex = 0;
        cbTXRX10 -> Checked = false;
        cbTXRX11 -> Checked = false;
        //META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 1);
        //OutputMetaResult(" setNss", mr);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbTXRX10Click(TObject *Sender)
{
    DBDCSelect(1);
    setTXRX1Path();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbTXRX11Click(TObject *Sender)
{
    DBDCSelect(1);
    setTXRX1Path();
}
//---------------------------------------------------------------------------

void TfrmWmWifiMT6620::setTXRX1Path()
{
    if(cbxNss1->Text == "1")
    {
        if ( cbTXRX10->Checked && cbTXRX11->Checked)
        {
            META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 1);
            OutputMetaResult(" setNss", mr);
            mr = m_WiFi_Man_Obj.WiFi_setTXPath(1200, 0x80000018);
            OutputMetaResult(" set TX0/TX1 Path", mr);
            mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 0x00030000);
            OutputMetaResult(" set RX0/RX1 Path", mr);
        }
        if(cbTXRX10->Checked && !(cbTXRX11->Checked))
        {
            META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 1);
            OutputMetaResult(" setNss", mr);
            mr = m_WiFi_Man_Obj.WiFi_setTXPath(1200, 1);
            OutputMetaResult(" set TX0 Path", mr);
            mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 0x00010000);
            OutputMetaResult(" set RX0 Path", mr);
        }
        if(!(cbTXRX10->Checked) && cbTXRX11->Checked)
        {
            META_RESULT mr = m_WiFi_Man_Obj.WiFi_setNss(1200, 1);
            OutputMetaResult(" setNss", mr);
            mr = m_WiFi_Man_Obj.WiFi_setTXPath(1200, 2);
            OutputMetaResult(" set TX1 Path", mr);
            //mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 2);
            mr = m_WiFi_Man_Obj.WiFi_setRXPath(1200, 0x00020000);
            OutputMetaResult(" set RX1 Path", mr);
        }
    }
}
void __fastcall TfrmWmWifiMT6620::btnRX1GoClick(TObject *Sender)
{
    DBDCSelect(1);
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setRxTest(1200);
    OutputMetaResult(" start Rx Test", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        return;
    }

    int intervalTime = 0;
    if(false == IsValidIntWIFIData(edtInterval1->Text, intervalTime) || intervalTime <= 0)
    {
        intervalTime = 1;
        OutputLog(" Error: interval time is not valid, which will be set to default value(1 sec)");
    }

    timerRX1->Interval = intervalTime*1000;
    timerRX1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::timerRX1Timer(TObject *Sender)
{
    CLocker locker(m_cs);
    unsigned long  fcsErrorValue = 0;
    unsigned long  rxOkValue = 0;
    long  rxRSSI = 0;
    long  rxRSSI1 = 0;

    DBDCSelect(1);
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_ReceivedErrorCount(1200 , &fcsErrorValue);
    OutputMetaResult(" Get Received Error Count", mr);
    if(META_SUCCESS != mr)
    {
        timerRX1->Enabled = false;
        CurrentPageReset();
        return;
    }
    mr = m_WiFi_Man_Obj.WiFi_ReceivedOKCount(1200 , &rxOkValue);
    OutputMetaResult(" Get Received OK Count", mr);
    if(META_SUCCESS != mr)
    {
        timerRX1->Enabled = false;
        CurrentPageReset();
        return;
    }

    mr = m_WiFi_Man_Obj.WiFi_ReceivedRSSI(1200 , &rxRSSI);
    OutputMetaResult(" Get Received RSSI", mr);
    if(META_SUCCESS != mr)
    {
        timerRX1->Enabled = false;
        CurrentPageReset();
        return;
    }
    if ((0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        mr = m_WiFi_Man_Obj.WiFi_ReceivedRSSI1(1200 , &rxRSSI1);
        OutputMetaResult(" Get Received RSSI1", mr);
    }

    stRXFCSerr1->Caption = IntToStr(fcsErrorValue);
    stRXOK1->Caption = IntToStr(rxOkValue);
    if ((fcsErrorValue+rxOkValue) != 0 )
    {
        stRXPER1->Caption =  IntToStr(fcsErrorValue *100/(fcsErrorValue+rxOkValue));
    }
    stRXRSSI1->Caption = IntToStr(rxRSSI);
    if ((0x6632 == m_wifiChipVersion)|| (0x0035 == m_wifiChipVersion))
    {
        stRXRSSI11->Caption = IntToStr(rxRSSI1);
    }

}
//---------------------------------------------------------------------------
void __fastcall TfrmWmWifiMT6620::btnRXStop1Click(TObject *Sender)
{
    DBDCSelect(1);
    timerRX1->Enabled = false;
    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setStandBy(1200);
    OutputMetaResult(" Stop Rx Test", mr);
    if(META_SUCCESS != mr)
    {
        btnTX1Go->Enabled = true;
        return;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnGuard1intervalSetClick(
      TObject *Sender)
{
    DBDCSelect(1);
    CurrentPageLock();
    int guardinterval;
    if(rbGuard1interval400->Checked == true)
    {
        guardinterval=1;
    }
    else if(rbGuard1interval800->Checked == true)
    {
        guardinterval=0;
    }
    else
    {
        OutputLog(" Error: Please select Guard Interval");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setGuardinterval(1200, guardinterval);
    OutputMetaResult(" Set Guardinterval", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::rbModeSelect1SetClick(TObject *Sender)
{
    DBDCSelect(1);
    CurrentPageLock();
    int modeselect;
    if(rbModeSelectGreenFiled1->Checked == true)
    {
        modeselect = 3;   //Green Field
    }
    else if(rbModeSelectMixedMode1->Checked == true)
    {
        modeselect = 2;   //Mixed Mode
    }
    else if(rbModeSelect11AC1->Checked == true)
    {
        modeselect = 4;   //11AC(VHT)
    }
    else
    {
        OutputLog(" Error: Please select Mode Select");
        CurrentPageReset();
        return;
    }

    META_RESULT mr = m_WiFi_Man_Obj.WiFi_setModeSelect(1200, modeselect);
    OutputMetaResult(" Set ModeSelect", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbRate1Change(TObject *Sender)
{
    DBDCSelect(1);
    //for WiFi refactor
    //META_RESULT mr = SP_META_WiFi_setRate_r(m_META_HANDLE_Obj.Get_MainHandle(), 1200, rateSettingmt6620[cbRate->ItemIndex].i4BBHwVal);
    META_RESULT mr = META_FAILED;
    if(cbxNss1->Text == "2")
    {
        mr = m_WiFi_Man_Obj.WiFi_setRate(1200, rateSettingmt6632[cbRate1->ItemIndex].i4BBHwVal);
    }
    else
    {
        mr = m_WiFi_Man_Obj.WiFi_setRate(1200, rateSettingmt6620[cbRate1->ItemIndex].i4BBHwVal);
    }

    OutputMetaResult(" set rate", mr);
    if(META_SUCCESS != mr)
    {
        CurrentPageReset();
        return;
    }
    // uiUpdateTxPower();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnTX1GoClick(TObject *Sender)
{
    DBDCSelect(1);
    switch(cbTXTestType1->ItemIndex)
    {
    case 0: // continuous packet tx
        goBand1TX0();
        break;
    case 1:// tx output power
        goBand1TX1();
        break;
    case 2:// carrier suppression
        goBand1TX2();
        break;
    case 3:// local leakage
        goBand1TX3();
        break;
/*    case 4:// Enter Power OFF
        goTX4();
        break;  */
    case 4:// CW mode
        goBand1TX5();
        break;
    default:
        //error
        break;
    }
}

void __fastcall TfrmWmWifiMT6620::cbJMode1Click(TObject *Sender)
{
    DBDCSelect(1);
    if ( cbJMode1->Checked )
    {
       cbxDBW1->Enabled = false;
       cbxPrimaryCh1->Enabled = false;
       cbxCBW1->Clear();
       cbxCBW1->Items->Add("BW5");
       cbxCBW1->Items->Add("BW10");
       cbxCBW1->ItemIndex = 0;
    }
    else
    {
        cbxDBW1->Enabled = true;
        cbxPrimaryCh1->Enabled = true;
        cbxCBW1->Clear();
        cbxCBW1->Items->Add("BW20");
        cbxCBW1->Items->Add("BW40");
        cbxCBW1->Items->Add("BW80");
        cbxCBW1->Items->Add("BW160");
        cbxCBW1->Items->Add("BW160NC");
        cbxCBW1->ItemIndex = 0;
        cbxCBW1Change(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::btnBandwidth1SetClick(TObject *Sender)
{
    DBDCSelect(1);
    CurrentPageLock();
    int bandwidth = 0;
    META_RESULT mr = META_FAILED;
    unsigned int nJMode = 0;
    unsigned int nChBandwidth = 0;
    unsigned int nDataBandwidth = 0;
    unsigned int nPrimarySetting = 0;

    GetBandwidth1Para(nJMode, nChBandwidth, nDataBandwidth, nPrimarySetting);
    if (cbJMode1->Checked == false)
    {
        mr = m_WiFi_Man_Obj.WiFi_setJMode(1200, nJMode);
        OutputMetaResult(" Set JMode", mr);
        if(META_SUCCESS != mr)
        {
                CurrentPageReset();
                return;
        }
        mr = m_WiFi_Man_Obj.WiFi_setBandwidthEx(2000, nChBandwidth, nDataBandwidth, nPrimarySetting);
        OutputMetaResult(" Set BandwidthEx", mr);
    }
    else if(cbJMode1->Checked == true)
    {
        mr = m_WiFi_Man_Obj.WiFi_setJMode(1200, nJMode);
        OutputMetaResult(" Set JMode", mr);
    }
    CurrentPageReset();
}
//---------------------------------------------------------------------------
void TfrmWmWifiMT6620::GetBandwidth1Para(unsigned int &nJMode, unsigned int &nChBandwidth, unsigned int &nDataBandwidth,
                          unsigned int &nPrimarySetting)
{
    nJMode = 0;
    if (cbJMode1->Checked == false)
    {
        nChBandwidth = 0;
        nDataBandwidth = 0;
        nPrimarySetting = 0;
        if ( cbxCBW1->ItemIndex >= 0 )
        {
            if (cbxCBW1->Text == "BW20")
            {
                nChBandwidth = 0;
            }
            else if(cbxCBW1->Text == "BW40")
            {
                nChBandwidth = 1;
            }
            else if(cbxCBW1->Text == "BW80")
            {
                nChBandwidth = 2;
            }
            else if(cbxCBW1->Text == "BW160")
            {
                nChBandwidth = 3;
            }
            else if(cbxCBW1->Text == "BW160NC")
            {
                nChBandwidth = 4;
            }
        }
        if ( cbxDBW1->ItemIndex >= 0 )
        {
            if (cbxDBW1->Text == "BW20")
            {
                nDataBandwidth = 0;
            }
            else if(cbxDBW1->Text == "BW40")
            {
                nDataBandwidth = 1;
            }
            else if(cbxDBW1->Text == "BW80")
            {
                nDataBandwidth = 2;
            }
            else if(cbxDBW1->Text == "BW160")
            {
                nDataBandwidth = 3;
            }
        }
        if ( cbxPrimaryCh1->ItemIndex >= 0 )
        {
            if (cbxPrimaryCh1->Text == "0")
            {
                nPrimarySetting = 0;
            }
            else if(cbxPrimaryCh1->Text == "1")
            {
                nPrimarySetting = 1;
            }
            else if(cbxPrimaryCh1->Text == "2")
            {
                nPrimarySetting = 2;
            }
            else if(cbxPrimaryCh1->Text == "3")
            {
                nPrimarySetting = 3;
            }
            else if(cbxPrimaryCh1->Text == "4")
            {
                nPrimarySetting = 4;
            }
            else if(cbxPrimaryCh1->Text == "5")
            {
                nPrimarySetting = 5;
            }
            else if(cbxPrimaryCh1->Text == "6")
            {
                nPrimarySetting = 6;
            }
            else if(cbxPrimaryCh1->Text == "7")
            {
                nPrimarySetting = 7;
            }
        }
        nJMode = 0;
    }
    else if(cbJMode1->Checked == true)
    {
        if (cbxCBW1->Text == "BW5")
        {
            nJMode = 1;
        }
        else if(cbxCBW1->Text == "BW10")
        {
            nJMode = 2;
        }
    }
}

void __fastcall TfrmWmWifiMT6620::cbChannel1Change(TObject *Sender)
{
    DBDCSelect(1);
    //DoChannelChange();
    if (cbChannel1->Text == "USER DEFINE")
    {
        labelUserDefine1->Enabled = true;
        edtChannel1->Enabled = true;
        udChannel1->Enabled = true;
    }
    else
    {
        labelUserDefine1->Enabled = false;
        edtChannel1->Enabled = false;
        udChannel1->Enabled = false;
        DoChannel1Change();
    }
}
//---------------------------------------------------------------------------
void TfrmWmWifiMT6620::DoChannel1Change(void)
{
    META_RESULT mr = META_FAILED;
    int channelConfig = 0;

    if (cbChannel1->Text != "USER DEFINE")
    {
            if (cbxCBW1->Text == "BW5")
            {
                channelConfig = chnlListmt6620_5[cbChannel1->ItemIndex].chnlFreq;
            }
            else if (cbxCBW1->Text == "BW10")
            {
                channelConfig = chnlListmt6620_10[cbChannel1->ItemIndex].chnlFreq;
            }
            else if (cbxCBW1->Text == "BW20")
            {
                channelConfig = chnlListmt6620_20_band1[cbChannel1->ItemIndex].chnlFreq;
            }
            else if (cbxCBW1->Text == "BW40")
            {
                channelConfig = chnlListmt6620_40_band1[cbChannel1->ItemIndex].chnlFreq;
            }
            else if (cbxCBW1->Text == "BW80")
            {
                channelConfig = chnlListmt6620_80_band1[cbChannel1->ItemIndex].chnlFreq;
            }
            else if (cbxCBW1->Text == "BW160")
            {
                channelConfig = chnlListmt6620_160[cbChannel1->ItemIndex].chnlFreq;
            }
            else
            {
                OutputLog(" Error: please select the right bandwidth");
                return;
            }

        LOG("ItemIndex:%d,chnlFreq:%d",cbChannel1->ItemIndex,channelConfig);
        mr = m_WiFi_Man_Obj.WiFi_setChannel(1200, channelConfig);
    }
    OutputMetaResult(" setChannel", mr);
}

//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::udChannel1Changing(TObject *Sender,
      bool &AllowChange)
{
    edtChannel1->Text = udChannel1->Position;
}
//---------------------------------------------------------------------------


void __fastcall TfrmWmWifiMT6620::cbxCBW1Change(TObject *Sender)
{
    if(cbxCBW1->Text == "BW20")
    {
        cbxDBW1->Clear();
        cbxDBW1->Items->Add("BW20");
        cbxDBW1->ItemIndex = 0;
    }
    else if(cbxCBW1->Text == "BW40")
    {
        cbxDBW1->Clear();
        cbxDBW1->Items->Add("BW20");
        cbxDBW1->Items->Add("BW40");
        cbxDBW1->ItemIndex = 0;
    }
    else if(cbxCBW1->Text == "BW80")
    {
        cbxDBW1->Clear();
        cbxDBW1->Items->Add("BW20");
        cbxDBW1->Items->Add("BW40");
        cbxDBW1->Items->Add("BW80");
        cbxDBW1->ItemIndex = 0;
    }
    else if(cbxCBW1->Text == "BW160")
    {
        cbxDBW1->Clear();
        cbxDBW1->Items->Add("BW20");
        cbxDBW1->Items->Add("BW40");
        cbxDBW1->Items->Add("BW80");
        cbxDBW1->Items->Add("BW160");
        cbxDBW1->ItemIndex = 0;
    }
    else if(cbxCBW1->Text == "BW160NC")
    {
        cbxDBW1->Clear();
        cbxDBW1->Items->Add("BW20");
        cbxDBW1->Items->Add("BW40");
        cbxDBW1->Items->Add("BW80");
        cbxDBW1->Items->Add("BW160");
        cbxDBW1->ItemIndex = 0;
    }
    cbxDBW1Change(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbxDBW1Change(TObject *Sender)
{
    if(cbxDBW1->Text == "BW20"  )
    {
        if (cbxCBW1->Text == "BW20")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if (cbxCBW1->Text == "BW40")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if (cbxCBW1->Text == "BW80")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if (cbxCBW1->Text == "BW160")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->Items->Add("4");
            cbxPrimaryCh1->Items->Add("5");
            cbxPrimaryCh1->Items->Add("6");
            cbxPrimaryCh1->Items->Add("7");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if (cbxCBW1->Text == "BW160NC")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->ItemIndex = 0;
        }
    }
    else if(cbxDBW1->Text == "BW40")
    {
        if (cbxCBW1->Text == "BW40")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if(cbxCBW->Text == "BW80")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if(cbxCBW1->Text == "BW160")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->Items->Add("4");
            cbxPrimaryCh1->Items->Add("5");
            cbxPrimaryCh1->Items->Add("6");
            cbxPrimaryCh1->Items->Add("7");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if(cbxCBW1->Text == "BW160NC")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->ItemIndex = 0;
        }
    }
    else if(cbxDBW1->Text == "BW80")
    {
        if(cbxCBW1->Text == "BW80")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if(cbxCBW1->Text == "BW160")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->Items->Add("4");
            cbxPrimaryCh1->Items->Add("5");
            cbxPrimaryCh1->Items->Add("6");
            cbxPrimaryCh1->Items->Add("7");
            cbxPrimaryCh1->ItemIndex = 0;
        }
        else if(cbxCBW1->Text == "BW160NC")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->ItemIndex = 0;
        }
    }
    else if(cbxDBW1->Text == "BW160")
    {
        if(cbxCBW1->Text == "BW160")
        {
            cbxPrimaryCh1->Clear();
            cbxPrimaryCh1->Items->Add("0");
            cbxPrimaryCh1->Items->Add("1");
            cbxPrimaryCh1->Items->Add("2");
            cbxPrimaryCh1->Items->Add("3");
            cbxPrimaryCh1->Items->Add("4");
            cbxPrimaryCh1->Items->Add("5");
            cbxPrimaryCh1->Items->Add("6");
            cbxPrimaryCh1->Items->Add("7");
            cbxPrimaryCh1->ItemIndex = 0;
        }
    }
}
//---------------------------------------------------------------------------







void __fastcall TfrmWmWifiMT6620::timerTX1Timer(TObject *Sender)
{
   CLocker locker(m_cs);   
   DBDCSelect(1);
   switch(cbTXTestType1->ItemIndex)
    {
    case 0: // continuous packet tx
    {
        unsigned int u4TxPktCnt = 0;
        unsigned long u4Value;
        META_RESULT mr = m_WiFi_Man_Obj.WiFi_GetATParam(1200, 32, &u4Value);
        OutputMetaResult("Band1 GetATParam", mr);
        if(META_SUCCESS != mr)
        {
            timerTX1->Enabled = false;
            btnTX1Go->Enabled = true;
            CurrentPageReset();
            return;
        }
        IsValidDecWIFIData(edtTXPktCnt1->Text, u4TxPktCnt);
        if(u4Value == u4TxPktCnt)
        {
            timerTX1->Enabled = false;
            btnTX1Go->Enabled = true;
            CurrentPageReset();
            OutputLog(" TX completed");
        }
        break;
    }
    case 1:// tx output power
        break;
    case 2:// carrier suppression
        break;
    case 3:// local leakage
        break;
    case 4:// Enter Power OFF
        break;
    default:
        //error
        break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmWmWifiMT6620::cbChannel1DropDown(TObject *Sender)
{
    //Reset channel list
    int i = 0;
    cbChannel1->Clear();

    if (cbxCBW1->Text == "BW20")
    {
        for(i = 0 ; i < sizeof(chnlListmt6620_20)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {
            if((chnlListmt6620_20[i].chnlFreq/1000 < 4920) || (chnlListmt6620_20[i].chnlFreq/1000 > 5905))
                continue;
            cbChannel1->Items->Add(IntToStr(chnlListmt6620_20[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_20[i].chnlFreq/1000)+"MHz)");
        }
    }
    else if (cbxCBW1->Text == "BW40")
    {
        for(i = 0 ; i < sizeof(chnlListmt6620_40)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {
            if((chnlListmt6620_20[i].chnlFreq/1000 < 4920) || (chnlListmt6620_20[i].chnlFreq/1000 > 5905) )
                continue;
            cbChannel1->Items->Add(IntToStr(chnlListmt6620_40[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_40[i].chnlFreq/1000)+"MHz)");
        }
    }
    else if (cbxCBW1->Text == "BW80")
    {
        for(i = 0 ; i < sizeof(chnlListmt6620_80)/ sizeof(RF_CHANNEL_PROG_ENTRY); i++)
        {
            if((chnlListmt6620_20[i].chnlFreq/1000 < 4920) || (chnlListmt6620_20[i].chnlFreq/1000 > 5905))
                continue;
            cbChannel1->Items->Add(IntToStr(chnlListmt6620_80[i].chnlNum + 1)+"  ("+IntToStr(chnlListmt6620_80[i].chnlFreq/1000)+"MHz)");
        }
    }
    cbChannel1->Items->Add((AnsiString)"USER DEFINE");
    cbChannel1->ItemIndex = 0;
}
//---------------------------------------------------------------------------


