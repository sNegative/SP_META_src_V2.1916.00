/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   misc_wifi.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  WiFi Misc. function source
 *
 * Author:
 * -------
 *  Andy Ueng (mtk00490)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 * Apr 24 2008 mtk00490
 * [STP100001693] [META] META ver 5.0816.0
 *
 *
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * May 19 2007 mtk00490
 * [STP100001406] [META] META ver 5.3.8
 *
 *
 * Mar 14 2007 mtk00490
 * [STP100001335] [META] META ver 5.3.6.1
 *
 *
 * Feb 8 2007 mtk00490
 * [STP100001308] [META] META ver 5.3.6.0
 *
 *
 * Jan 1 2007 mtk00490
 * [STP100001274] [META] META ver 5.3.4.2
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <vcl.h>
#include <math.h>

#pragma hdrstop

#ifndef META_DLL_H
#include "meta.h"
#endif

#ifndef  _MAN_ERROR_H_
#include "man_error.h"
#endif

#ifndef  _FT_UTILS_H_
#include "ft_utils.h"
#endif

#ifndef  _WIFI_COMMON_H_
#include "wifi_common.h"
#endif

//============================================================================
double d_WIFI_802_11B_TX_RATE[] =
{
    1,
    2,
    5.5,
    11
};

double d_WIFI_802_11AG_TX_RATE[] =
{
    6,
    9,
    12,
    18,
    24,
    36,
    48,
    54
};

//==============================================================================
//////////////////////////////        WiFi        //////////////////////////////
//==============================================================================
bool  AnsiString_To_MACAddress( AnsiString ansi_str, WiFi_MacAddress_S &out_value)
{
    /* check if each char is valid */
    {
        int   i;
        char  ch;
        char  str[256];
        int   str_len = ansi_str.Length();
        if(str_len==0)  return(false);
        strcpy( str, ansi_str.c_str() );

        for( i=0; i<str_len; i++ )
        {
            ch = str[i];
            if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
            break;
        }
        if( i!=str_len )
            return(false);
    }
    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, 48) )  return false;
    for( int i=0; i<sizeof(out_value.mac_addr)/sizeof(out_value.mac_addr[0]); i++ )
    {
        out_value.mac_addr[i] = ansi_str.SubString(i+1,1).ToInt();
    }

    return true;
}

//---------------------------------------------------------------------------
bool AnsiString_Hex_To_MACAddress(AnsiString ansi_str, WiFi_MacAddress_S &out_value)
{
    char  str[256];
    long  val;
    int   i;
    /* check if each char is valid */

    char  ch;
    int   str_len = ansi_str.Length();
    if(str_len==0)  return(false);
    strcpy( str, ansi_str.c_str() );

    for( i=0; i<str_len; i++ )
    {
        val = 0;
        ch = str[i];
        if( (ch>='0')&&(ch<='9') )
        {
            //val <<= 4;
            val += ch-'0';
        }
        else if( (ch>='A')&&(ch<='F') )
        {
            //val <<= 4;
            val += ch-'A'+10;
        }
        else if( (ch>='a')&&(ch<='f') )
        {
            //val <<= 4;
            val += ch-'a'+10;
        }
        else if( ch==' ' )
        {
        }
        else
        {
            break;
        }
        out_value.mac_addr[i] = val;
        continue;
    }

    if( i!=str_len )
        return(false);


    for( ; i<sizeof(out_value.mac_addr)/sizeof(out_value.mac_addr[0]); i++ )
    {
        out_value.mac_addr[i] = 0;
    }

    return true;
}

//----------------------------------------------------------------------------
bool IsValidDecWiFiBBChipID(AnsiString ansi_str, unsigned short &chip_id)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, chip_id, 0, 65535), RANGE_ERR_WIFI_BB_CHIP_ID);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiBBChipID(AnsiString ansi_str, unsigned short &chip_id)
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedShort( ansi_str, chip_id ) , RANGE_ERR_WIFI_BB_CHIP_ID );

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool IsValidDecWiFiRFChipID(AnsiString ansi_str, unsigned short &chip_id)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, chip_id, 0, 65535), RANGE_ERR_WIFI_RF_CHIP_ID);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiRFChipID(AnsiString ansi_str, unsigned short &chip_id)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedShort(ansi_str, chip_id), RANGE_ERR_WIFI_RF_CHIP_ID);

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool IsValidDecWiFiSN(AnsiString ansi_str, unsigned int &sn)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, sn, 0, 4294967295), RANGE_ERR_WIFI_SN);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiSN(AnsiString ansi_str, unsigned int *sn)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, sn), RANGE_ERR_WIFI_SN);

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool IsValidDecWiFiMACAddress(AnsiString ansi_str, unsigned char &mac_addr_char)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, mac_addr_char, 0, 255), RANGE_ERR_WIFI_MAC_ADDRESS);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiMACAddress(AnsiString ansi_str, unsigned char &mac_addr_char)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, mac_addr_char, 0, 255), RANGE_ERR_WIFI_MAC_ADDRESS);

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool IsValidDecWiFiBBRegAddr(AnsiString ansi_str, unsigned int &addr)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, addr, 0, 4294967295), RANGE_ERR_WIFI_BB_REG_ADDR);

    return  true;
}

//---------------------------------------------------------------------------
bool IsValidHexWiFiBBRegAddr(AnsiString ansi_str, unsigned char &addr)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, addr, 0, 255), RANGE_ERR_WIFI_BB_REG_ADDR);

    return  true;
}

//---------------------------------------------------------------------------
bool IsValidDecWiFiBBRegValue(AnsiString ansi_str, unsigned char &value)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, value, 0, 255) , RANGE_ERR_WIFI_BB_REG_VALUE);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidHexWiFiBBRegValue(AnsiString ansi_str, unsigned char &value)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, value, 0, 255), RANGE_ERR_WIFI_BB_REG_VALUE);

    return true;
}

//--------------------------------------------------------------------------
bool IsValidHexWiFiMacRegAddr(AnsiString ansi_str, unsigned int *addr)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, addr ), RANGE_ERR_WIFI_MAC_REG_ADDR);

    return  true;
}

//---------------------------------------------------------------------------
bool IsValidDecWiFiMacRegValue(AnsiString ansi_str, unsigned int &value)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, value, 0, 4294967295), RANGE_ERR_WIFI_MAC_REG_VALUE);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidHexWiFiMacRegValue(AnsiString ansi_str, unsigned int *value)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, value), RANGE_ERR_WIFI_MAC_REG_VALUE);

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool IsValidDecWiFiMacReg16Value(AnsiString ansi_str, unsigned short &value)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedShort(ansi_str, value, 0, 65536), RANGE_ERR_WIFI_MAC_REG_VALUE);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidHexWiFiMacReg16Value(AnsiString ansi_str, unsigned short &value)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedShort(ansi_str, value), RANGE_ERR_WIFI_MAC_REG_VALUE);

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool IsValidHexWiFiEERegAddr(AnsiString ansi_str, unsigned int *addr)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedInt(ansi_str, addr), RANGE_ERR_WIFI_EE_ADDR);

    return  true;
}

//---------------------------------------------------------------------------
bool IsValidDecWiFiEERegValue(AnsiString ansi_str, unsigned short &value)
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedShort(ansi_str, value, 0, 65535), RANGE_ERR_WIFI_EE_VALUE);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidHexWiFiEERegValue(AnsiString ansi_str, unsigned short &value)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedShort(ansi_str, value), RANGE_ERR_WIFI_EE_VALUE);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidWiFiPacketLength(AnsiString ansi_str, unsigned int &pkt_length)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, pkt_length, 0, 6000), RANGE_ERR_WIFI_PACKET_LENGTH);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidWiFiPacketCount(AnsiString ansi_str, unsigned int &pkt_count)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, pkt_count, 0, 4294967295), RANGE_ERR_WIFI_PACKET_COUNT);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidWiFiPacketInterval(AnsiString ansi_str, unsigned int &pkt_interval)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, pkt_interval, 0, 4294967295), RANGE_ERR_WIFI_PACKET_INTERVAL);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidDecWiFiTxPowerDac(AnsiString ansi_str, unsigned char &dac)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, dac, 0, 63), RANGE_ERR_WIFI_TX_POWER_DAC);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiTxPowerDac(AnsiString ansi_str, unsigned char &dac)
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedChar(ansi_str, dac, 0, 63), RANGE_ERR_WIFI_TX_POWER_DAC);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidDecWiFiTxDcOffset(AnsiString ansi_str, unsigned char &txdc)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, txdc, 0, 255), RANGE_ERR_WIFI_TX_DC_OFFSET);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiTxDcOffset(AnsiString ansi_str, unsigned char &txdc)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, txdc, 0, 255), RANGE_ERR_WIFI_TX_DC_OFFSET);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiMacHeaderFrameCtrl(AnsiString ansi_str, unsigned char &frame_ctrl)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, frame_ctrl, 0, 255), RANGE_ERR_WIFI_MAC_HEADER_FRAME_CTRL);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiMacHeaderDuration(AnsiString ansi_str, unsigned char &duration)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, duration, 0, 255), RANGE_ERR_WIFI_MAC_HEADER_DURATION);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiMacHeaderAddress(AnsiString ansi_str, unsigned char &addr)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, addr, 0, 255), RANGE_ERR_WIFI_MAC_HEADER_ADDRESS);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidHexWiFiMacHeaderSeqCtrl(AnsiString ansi_str, unsigned char &seq_ctrl)
{
    RANGE_CHECK_ERROR(!AnsiString_Hex_To_UnsignedChar(ansi_str, seq_ctrl, 0, 255), RANGE_ERR_WIFI_MAC_HEADER_SEQ_CTRL);

    return true;
}
//rongguo 2011-06-18
//---------------------------------------------------------------------------
bool IsValidWiFiRegisterValue(AnsiString ansi_str, float &registerValue)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Float(ansi_str, registerValue, -128 / 2.0, 127 / 2.0), RANGE_ERR_WIFI_REGISTER_VALUE);
    return true;
}
//rongguo 2011-10-23
//---------------------------------------------------------------------------
bool IsValidWiFiCrystalValue(AnsiString ansi_str, int &registerValue)
{
    RANGE_CHECK_ERROR(!AnsiString_To_Integer(ansi_str, registerValue, -63, 63), RANGE_ERR_WIFI_CRYSTAL_VALUE);
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ALC
bool IsValidWiFiTxAlcCCK(AnsiString ansi_str, unsigned char &tx_alc)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, tx_alc, 0, 255), RANGE_ERR_WIFI_TX_ALC_CCK);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidWiFiTxOutputPowerDbCCK(AnsiString ansi_str, unsigned char &output_power)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, output_power, 0, 255), RANGE_ERR_WIFI_TX_OUTPUT_POWER_DB_CCK);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidWiFiTxAlcOFDM(AnsiString ansi_str, unsigned char &tx_alc)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, tx_alc, 0, 255), RANGE_ERR_WIFI_TX_ALC_OFDM);

    return true;
}

//----------------------------------------------------------------------------
bool IsValidWiFiTxOutputPowerDbOFDM(AnsiString ansi_str, unsigned char &output_power)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, output_power, 0, 255), RANGE_ERR_WIFI_TX_OUTPUT_POWER_DB_OFDM);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidWiFiAlcOffset(AnsiString ansi_str, char &offset)
{
    RANGE_CHECK_ERROR(!AnsiString_To_char(ansi_str, offset, -128, 127), RANGE_ERR_WIFI_ALC_OFFSET);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidWiFiTargetALC(AnsiString ansi_str, unsigned int &alc)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedInteger(ansi_str, alc, 0, 255), RANGE_ERR_WIFI_TARGET_ALC);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidWiFiAlcSlopeDivider(AnsiString ansi_str, unsigned char &alc_slope_divider)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, alc_slope_divider, 1, 100), RANGE_ERR_WIFI_ALC_SLOPE_DIVIDER);

    return true;
}

//---------------------------------------------------------------------------
bool IsValidWiFiAlcSlopeDividend(AnsiString ansi_str, unsigned char &alc_slope_dividend)
{
    RANGE_CHECK_ERROR(!AnsiString_To_UnsignedChar(ansi_str, alc_slope_dividend, 1, 100), RANGE_ERR_WIFI_ALC_SLOPE_DIVIDEND);

    return true;
}

//===========================================================================
//////////////////////////////  Format transform   //////////////////////////
//===========================================================================
bool MACAddress_To_Str(WiFi_MacAddress_S mac_addr, AnsiString &as_str)
{
    as_str = "";
    int mac_addr_size = sizeof(mac_addr.mac_addr)/sizeof(mac_addr.mac_addr[0]);
    for( int i=0; i<mac_addr_size; i++ )
    {
        if( i != mac_addr_size-1 )
        {
            as_str += IntToStr( mac_addr.mac_addr[mac_addr_size-i-1] )+":";
        }
        else
        {
            as_str += IntToStr( mac_addr.mac_addr[mac_addr_size-i-1] );
        }
    }

    return true;
}

//---------------------------------------------------------------------------
bool Str_To_MACAddress(AnsiString as_str, WiFi_MacAddress_S &mac_addr)
{
    char str[256];
    WiFi_MacAddress_S temp_mac_addr;

    strcpy( str, as_str.c_str() );
    int mac_address_len = sizeof(mac_addr.mac_addr)/sizeof(mac_addr.mac_addr[0]);

    String_To_Array_UnsignedChar( str, temp_mac_addr.mac_addr, mac_address_len );

    for( int i=0; i<mac_address_len; i++ )
    {
        mac_addr.mac_addr[i] = temp_mac_addr.mac_addr[mac_address_len-i-1];
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
unsigned int GetWiFiChannelFreqFromStr(AnsiString as_str)
{
    unsigned int ch_freq;

    int begin_pos, end_pos;
    begin_pos = as_str.AnsiPos( "(" ) + 1;
    end_pos   = as_str.AnsiPos( ")" ) - 1;
    as_str = as_str.SubString( begin_pos, end_pos - begin_pos + 1 );
    ch_freq = as_str.ToInt();

    return ch_freq;
}

const unsigned int WIFI_802_11BG_CHANNEL_FREQ_KHZ[] =
{
    2412000,
    2417000,
    2422000,
    2427000,
    2432000,
    2437000,
    2442000,
    2447000,
    2452000,
    2457000,
    2462000,
    2467000,
    2472000,
    2484000
};

const unsigned int WIFI_802_11A_CHANNEL_FREQ_KHZ[] =
{
    5040000,
    5060000,
    5080000,
    5170000,
    5180000,
    5190000,
    5200000,
    5210000,
    5220000,
    5230000,
    5240000,
    5260000,
    5280000,
    5300000,
    5320000,
    5500000,
    5520000,
    5540000,
    5560000,
    5580000,
    5600000,
    5620000,
    5640000,
    5660000,
    5680000,
    5700000,
    5745000,
    5765000,
    5785000,
    5805000,
    4920000,
    4940000,
    4960000,
    4980000
};

//---------------------------------------------------------------------------
unsigned int GetWiFiChannelFrequency(E_WIFI_GENERATION _802_11_type, int idx)
{
    unsigned int freq;
    if( WIFI_802_11A_IDX != _802_11_type ) // 802.11b, 802.11g
    {
        freq = WIFI_802_11BG_CHANNEL_FREQ_KHZ[idx];
    }
    else
    {
        freq = WIFI_802_11A_CHANNEL_FREQ_KHZ[idx];
    }
    return freq;
}
//---------------------------------------------------------------------------
bool GetWiFiChannelIndexFromStr(AnsiString as_channel, AnsiString as_txrate, E_WIFI_GENERATION &wifi_802_11_idx, unsigned int &chan_idx)
{
    AnsiString asWIFI_802_11B_TX_RATE_MHZ[] =
    {
        "1",
        "2",
        "5.5",
        "11"
    };

    unsigned int chan_freq = GetWiFiChannelFreqFromStr( as_channel );

    for (int i=0; i<sizeof(WIFI_802_11BG_CHANNEL_FREQ_KHZ)/sizeof(WIFI_802_11BG_CHANNEL_FREQ_KHZ[0]); i++ )
    {
        if( chan_freq == WIFI_802_11BG_CHANNEL_FREQ_KHZ[i] )
        {
            chan_idx = i;
            for (int j=0; j<4; j++)
            {
                if (as_txrate.AnsiCompareIC(asWIFI_802_11B_TX_RATE_MHZ[j]) == 0)
                {
                    wifi_802_11_idx = WIFI_802_11B_IDX;
                    return true;
                }
            }
            wifi_802_11_idx = WIFI_802_11G_IDX;
            return true;
        }
    }

    for (int i=0; i<sizeof(WIFI_802_11A_CHANNEL_FREQ_KHZ)/sizeof(WIFI_802_11A_CHANNEL_FREQ_KHZ[0]); i++)
    {
        if (chan_freq == WIFI_802_11A_CHANNEL_FREQ_KHZ[i])
        {
            chan_idx = i;
            wifi_802_11_idx = WIFI_802_11A_IDX;
            return true;
        }
    }

    return false;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static AnsiString asWIFI_802_11ABG_TX_RATE_MHZ[] =
{
    "1",
    "2",
    "5.5",
    "11",
    "6",
    "9",
    "12",
    "18",
    "24",
    "36",
    "48",
    "54"
};

//---------------------------------------------------------------------------
unsigned int GetWiFiTxRateFromStr(AnsiString as_str)
{
    unsigned int tx_rate=0;

    for( int i=0; i<WIFI_OFDM_TX_RATE_NUM; i++ )
    {
        if( as_str.AnsiCompareIC(asWIFI_802_11ABG_TX_RATE_MHZ[i]) == 0 )
        {
            tx_rate = i;
            break;
        }
    }

    return tx_rate;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool IsValidWiFiTxRate(E_WIFI_GENERATION wifi_gen, double d_tx_rate)
{
    bool match = false;
    switch (wifi_gen)
    {
    case WIFI_802_11A_IDX:
    case WIFI_802_11G_IDX:
    {
        for (int i=0; i<sizeof(d_WIFI_802_11AG_TX_RATE)/sizeof(d_WIFI_802_11AG_TX_RATE[0]); i++)
        {
            if (d_tx_rate == d_WIFI_802_11AG_TX_RATE[i])
            {
                match = true;
            }
        }
    }
    break;

    case WIFI_802_11B_IDX:
    {
        for (int i=0; i<sizeof(d_WIFI_802_11B_TX_RATE)/sizeof(d_WIFI_802_11B_TX_RATE[0]); i++)
        {
            if (d_tx_rate == d_WIFI_802_11B_TX_RATE[i])
            {
                match = true;
            }
        }
    }
    break;

    default:
    {
        return false;
    }
    }

    return match;
}

//===========================================================================
bool IsWiFiSupported(AnsiString as_802_11, E_WIFI_GENERATION e_802_11_idx)
{
    int i = as_802_11.ToInt();
    bool b_support;
    switch (e_802_11_idx)
    {
    case WIFI_802_11A_IDX:
    {
        if (i & 0x01)
        {
            b_support = true;
        }
        else
        {
            b_support = false;
        }
    }
    break;

    case WIFI_802_11B_IDX:
    {
        if (i & 0x02)
        {
            b_support = true;
        }
        else
        {
            b_support = false;
        }
    }
    break;

    case WIFI_802_11G_IDX:
    {
        if (i & 0x04)
        {
            b_support = true;
        }
        else
        {
            b_support = false;
        }
    }
    break;

    default:
    {
        b_support = false;
    }
    break;
    } // switch
    return b_support;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool GetWiFiTxRate(double d_tx_rate_mhz, WiFi_TestRate_E &e_tx_rate)
{
    if (1 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_1M;
    }
    else if (2 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_2M;
    }
    else if (5.5 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_5_5M;
    }
    else if (11 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_11M;
    }
    else if (6 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_6M;
    }
    else if (9 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_9M;
    }
    else if (12 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_12M;
    }
    else if (18 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_18M;
    }
    else if (24 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_24M;
    }
    else if (36 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_36M;
    }
    else if (48 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_48M;
    }
    else if (54 == d_tx_rate_mhz)
    {
        e_tx_rate = WIFI_TEST_RATE_54M;
    }
    else
    {
        return false;
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int GetWiFiRemainChannels(E_WIFI_GENERATION wifi_gen, S_WIFI_CH_FREQ_MHZ org_ch_freq_mhz, S_WIFI_CH_FREQ_MHZ &remain_ch_freq_mhz)
{
    int ch_num = 0;
    bool match;

    switch (wifi_gen)
    {
    case WIFI_802_11A_IDX:
    {
        for (int i=0; i<sizeof(WIFI_802_11A_CHANNEL_FREQ_KHZ)/sizeof(WIFI_802_11A_CHANNEL_FREQ_KHZ[0]); i++)
        {
            for (int j=0; j<org_ch_freq_mhz.ch_num; j++)
            {
                match = false;

                if ((org_ch_freq_mhz.ch_freq_MHz[j]*1000) == WIFI_802_11A_CHANNEL_FREQ_KHZ[i])
                {
                    match = true;
                    break;
                }
            }

            if (!match)
            {
                remain_ch_freq_mhz.ch_freq_MHz[ch_num] = WIFI_802_11A_CHANNEL_FREQ_KHZ[i]/1000;
                ch_num++;
            }
        }
    }
    break;

    case WIFI_802_11B_IDX:
    case WIFI_802_11G_IDX:
    {
        for (int i=0; i<sizeof(WIFI_802_11BG_CHANNEL_FREQ_KHZ)/sizeof(WIFI_802_11BG_CHANNEL_FREQ_KHZ[0]); i++)
        {
            for (int j=0; j<org_ch_freq_mhz.ch_num; j++)
            {
                match = false;

                if ((org_ch_freq_mhz.ch_freq_MHz[j]*1000) == WIFI_802_11BG_CHANNEL_FREQ_KHZ[i])
                {
                    match = true;
                    break;
                }
            }

            if (!match)
            {
                remain_ch_freq_mhz.ch_freq_MHz[ch_num] = WIFI_802_11BG_CHANNEL_FREQ_KHZ[i]/1000;
                ch_num++;
            }
        }
    }
    break;

    default:
    {
        ch_num = 0;
    }
    break;
    }

    return ch_num;
}

//--------------------------------------------------------------------------
int GetWiFiNVRAMChannelIndex(E_WIFI_GENERATION wifi_gen, unsigned int ch_freq_mhz)
{
    int nvram_ch_index = -1;
    unsigned int ch_freq_kHz = ch_freq_mhz * 1000;
    switch (wifi_gen)
    {
    case WIFI_802_11A_IDX:
    {
        for (int j=0; j<sizeof(WIFI_802_11A_CHANNEL_FREQ_KHZ)/sizeof(WIFI_802_11A_CHANNEL_FREQ_KHZ[0]); j++)
        {
            if (ch_freq_kHz == WIFI_802_11A_CHANNEL_FREQ_KHZ[j])
            {
                nvram_ch_index = j;
                break;
            }
        }
    }
    break;

    case WIFI_802_11B_IDX:
    case WIFI_802_11G_IDX:
    {
        for (int j=0; j<sizeof(WIFI_802_11BG_CHANNEL_FREQ_KHZ)/sizeof(WIFI_802_11BG_CHANNEL_FREQ_KHZ[0]); j++)
        {
            if(ch_freq_kHz == WIFI_802_11BG_CHANNEL_FREQ_KHZ[j])
            {
                nvram_ch_index = j;
                break;
            }
        }
    }
    break;

    default:
    {
        nvram_ch_index = -1;
    }
    break;
    }

    return nvram_ch_index;
}

//----------------------------------------------------------------------------
bool GetWiFiTwoClosetNVRAMChannelIndex(E_WIFI_GENERATION wifi_gen, unsigned int ch_freq_MHz, S_WIFI_CH_FREQ_MHZ s_ch_freq_MHz, int &first_ch_index, int &second_ch_index)
{
    int nvram_ch_index = GetWiFiNVRAMChannelIndex(wifi_gen, ch_freq_MHz);
    bool found_first = false;
    bool found_second = false;
    unsigned int ui_first_ch_MHz;
    unsigned int ui_second_ch_MHz;
    int ch_num;
    int i;
    switch (wifi_gen)
    {
    case WIFI_802_11A_IDX:
    {
        ch_num = NUM_TX_POWER_5000M_CH;
    }
    break;

    case WIFI_802_11B_IDX:
    case WIFI_802_11G_IDX:
    {
        ch_num = NUM_TX_POWER_2400M_CH;
    }
    break;

    default:
    {
        return false;
    }
    }

    if (0 == nvram_ch_index)
    {
        first_ch_index  = GetWiFiNVRAMChannelIndex(wifi_gen, s_ch_freq_MHz.ch_freq_MHz[0]);
        second_ch_index = GetWiFiNVRAMChannelIndex(wifi_gen, s_ch_freq_MHz.ch_freq_MHz[1]);
    }
    else if (ch_num-1 == nvram_ch_index)
    {
        first_ch_index  = GetWiFiNVRAMChannelIndex(wifi_gen, s_ch_freq_MHz.ch_freq_MHz[s_ch_freq_MHz.ch_num-2]);
        second_ch_index = GetWiFiNVRAMChannelIndex(wifi_gen, s_ch_freq_MHz.ch_freq_MHz[s_ch_freq_MHz.ch_num-1]);
    }
    else
    {
        found_first = false;
        for (i=0; i<s_ch_freq_MHz.ch_num; i++)
        {
            if (s_ch_freq_MHz.ch_freq_MHz[i] > ch_freq_MHz)
            {
                found_first = true;
                break;
            }
        }

        if (found_first)
        {
            ui_first_ch_MHz = s_ch_freq_MHz.ch_freq_MHz[i];
            first_ch_index  = GetWiFiNVRAMChannelIndex(wifi_gen, ui_first_ch_MHz);

            found_second = false;
            for (i=s_ch_freq_MHz.ch_num-1; i>=0; i--)
            {
                if (s_ch_freq_MHz.ch_freq_MHz[i] < ch_freq_MHz)
                {
                    found_second = true;
                    break;
                }
            }

            if (found_second)
            {
                ui_second_ch_MHz = s_ch_freq_MHz.ch_freq_MHz[i];
                second_ch_index  = GetWiFiNVRAMChannelIndex(wifi_gen, ui_second_ch_MHz);
            }
            else
            {
                for (i=0; i<s_ch_freq_MHz.ch_num; i++)
                {
                    if (s_ch_freq_MHz.ch_freq_MHz[i] > ui_first_ch_MHz)
                    {
                        found_second = true;
                        break;
                    }
                }
                ui_second_ch_MHz = s_ch_freq_MHz.ch_freq_MHz[i];
                second_ch_index  = GetWiFiNVRAMChannelIndex(wifi_gen, ui_second_ch_MHz);
            }
        }
        else // not found_first
        {
            for (i=s_ch_freq_MHz.ch_num-1; i>=0; i--)
            {
                if (s_ch_freq_MHz.ch_freq_MHz[i] < ch_freq_MHz)
                {
                    found_first = true;
                    break;
                }
            }
            ui_first_ch_MHz = s_ch_freq_MHz.ch_freq_MHz[i];
            first_ch_index  = GetWiFiNVRAMChannelIndex(wifi_gen, ui_first_ch_MHz);

            found_second = false;
            for (i=s_ch_freq_MHz.ch_num-1; i>=0; i--)
            {
                if (s_ch_freq_MHz.ch_freq_MHz[i] < ui_first_ch_MHz)
                {
                    found_second = true;
                    break;
                }
            }

            if (found_second)
            {
                ui_second_ch_MHz = s_ch_freq_MHz.ch_freq_MHz[i];
                second_ch_index  = GetWiFiNVRAMChannelIndex(wifi_gen, ui_second_ch_MHz);
            }
        }
    }

    return (found_first && found_second);
}
