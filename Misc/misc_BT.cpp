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
 *   misc_BT.cpp
 *
 * Project:
 * --------
 *   Maui META APP
 *
 * Description:
 * ------------
 *  BT Misc. function source
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
 * Feb 22 2008 mtk00490
 * [STP100001646] [META] META ver 5.0808.0
 *
 *
 * Dec 3 2007 mtk00490
 * [STP100001570] [META] META ver 5.0748.0
 *
 *
 * Mar 20 2007 mtk00490
 * [STP100001345] [META] META ver 5.3.6.2
 *
 *
 * Mar 14 2007 mtk00490
 * [STP100001335] [META] META ver 5.3.6.1
 *
 *
 * Oct 15 2006 mtk00490
 * [STP100001171] [META] META ver 5.3.1.0
 *
 *
 * Jul 18 2006 mtk00490
 * [STP100001005] [META]META ver 3.7.05
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

// BT
#ifndef  _BT_COMMON_H_
#include "bt_common.h"
#endif

#ifndef  _BT_HCI_H_
#include "bt_hci.h"
#endif


//==============================================================================
//////////////////////////////   Format transform  /////////////////////////////
//==============================================================================
bool  BTHCIValue_To_AnsiString( S_BT_HCI_VALUE hci_value, AnsiString &ansi_str )
{

    double value=0;
    unsigned char  uc_value[BT_HCI_VALUE_SIZE*2];
    int   i;
    for( i=0; i<BT_HCI_VALUE_SIZE*2; i++ )
    {
        if( 0 == i % 2 )
            uc_value[i] = hci_value.uc_value[i/2] & 0x0F;
        else
            uc_value[i] = (hci_value.uc_value[i/2] & 0xF0) >> 4;
    }

    for(  i=BT_HCI_VALUE_SIZE*2-1; i>=0; i-- )
    {
        value = value * 16 + uc_value[i];
    }

    ansi_str = Double_To_AnsiString( value );



    return true;
}

//----------------------------------------------------------------------------
bool  BTHCIValue_To_Hex_AnsiString( S_BT_HCI_VALUE hci_value, AnsiString &ansi_str )
{
    unsigned char  str[BT_HCI_VALUE_SIZE*2+1];
    char  *ptr = str;
    unsigned char  uc_value[BT_HCI_VALUE_SIZE*2];
    unsigned char nz_byte=2*BT_HCI_VALUE_SIZE;
    int   i;
    for( i=0; i<BT_HCI_VALUE_SIZE*2; i++ )
    {
        if( 0 == i % 2 )
            uc_value[i] = hci_value.uc_value[i/2] & 0x0F;
        else
            uc_value[i] = (hci_value.uc_value[i/2] & 0xF0) >> 4;
    }


    for( i=BT_HCI_VALUE_SIZE*2-1; i>=0; i-- )
    {
        if( 0 == uc_value[i] )
            nz_byte--;
        else
            break;
    }

    for( i=0; i<nz_byte; i++ )
    {
        //  sprintf( &str[nz_byte-i-1], "%X",  uc_value[i] );
        ptr += sprintf( ptr, "%X", uc_value[nz_byte-i-1] );
    }
    str[nz_byte] = '\0';
    ansi_str = (char *)str;

    if( 0 == nz_byte )
        ansi_str = "0";

    return true;
}

//----------------------------------------------------------------------------
bool  BDAddress_To_Hex_AnsiString( S_BD_ADDR bd_addr, AnsiString &ansi_str )
{
    int i;
    char str[2*BD_ADDRESS_LEN+1];
    char  *ptr = str;
    for( i=0; i<BD_ADDRESS_LEN*2; i++ )
    {
        if( 0 == i%2 )
        {
            ptr += sprintf( ptr, "%X", (bd_addr.uc_BD_Addr[BD_ADDRESS_LEN-i/2-1] & 0xF0) >> 4 );
        }
        else
        {
            ptr += sprintf( ptr, "%X", bd_addr.uc_BD_Addr[BD_ADDRESS_LEN-i/2-1] & 0x0F );
        }
    }
    str[2*BD_ADDRESS_LEN] = '\0';
    ansi_str = str;
    return true;
}

//----------------------------------------------------------------------------
bool  BDAddress_To_Hex_Colon_AnsiString( S_BD_ADDR bd_addr, AnsiString &ansi_str )
{
    int i;
    char str[3*BD_ADDRESS_LEN];
    char  *ptr = str;
    for( i=0; i<BD_ADDRESS_LEN*2; i++ )
    {
        if( 0 == i%2 )
        {
            ptr += sprintf( ptr, "%X", (bd_addr.uc_BD_Addr[BD_ADDRESS_LEN-i/2-1] & 0xF0) >> 4 );
        }
        else
        {
            ptr += sprintf( ptr, "%X", bd_addr.uc_BD_Addr[BD_ADDRESS_LEN-i/2-1] & 0x0F );
            ptr += sprintf( ptr, ":" );
        }
    }
    str[3*BD_ADDRESS_LEN-1] = '\0';
    ansi_str = str;
    return true;
}

//----------------------------------------------------------------------------
bool  AnsiString_To_Hex_BDAddress( AnsiString ansi_str, S_BD_ADDR &bd_addr )
{
    char  str[256];
    unsigned  char  val;
    unsigned char  uc_value[BD_ADDRESS_LEN*2];

    /* check if each char is valid */
    int   i;
    char  ch;
    int   str_len = ansi_str.Length();
    if(str_len==0)  return(false);
    strcpy( str, ansi_str.c_str() );

    for( i=0; i<BD_ADDRESS_LEN; i++ )
    {
        bd_addr.uc_BD_Addr[i] = 0;
    }

    for( i=0; i<BD_ADDRESS_LEN*2; i++ )
    {
        uc_value[i] = 0;
    }

    for( i=0; i<str_len; i++ )
    {
        val = 0;
        ch = str[i];
        if( (ch>='0')&&(ch<='9') )
        {
            val <<= 4;
            val += ch-'0';
        }
        else if( (ch>='A')&&(ch<='F') )
        {
            val <<= 4;
            val += ch-'A'+10;
        }
        else if( (ch>='a')&&(ch<='f') )
        {
            val <<= 4;
            val += ch-'a'+10;
        }
        else if( ch==' ' )
        {
        }
        else
        {
            return false;
        }
        uc_value[str_len-i-1] = val;
    }




    for( i=0; i<BD_ADDRESS_LEN; i++ )
    {
        bd_addr.uc_BD_Addr[i] = uc_value[2*i] + 16 * uc_value[2*i+1];

    }



    return( true );
}

//----------------------------------------------------------------------------
bool  Colon_AnsiString_To_Hex_BDAddress( AnsiString ansi_str, S_BD_ADDR &bd_addr )
{
    char  str[256];
    unsigned  char  val;
    unsigned char  uc_value[BD_ADDRESS_LEN*2];

    /* check if each char is valid */
    int   i;
    char  ch;
    int   str_len = ansi_str.Length();
    if(str_len!=(BD_ADDRESS_LEN*3-1))  return(false);
    strcpy( str, ansi_str.c_str() );

    for( i=0; i<BD_ADDRESS_LEN; i++ )
    {
        bd_addr.uc_BD_Addr[i] = 0;
    }

    for( i=0; i<BD_ADDRESS_LEN*2; i++ )
    {
        uc_value[i] = 0;
    }

    int count=0;
    for( i=0; i<str_len; i++ )
    {
        val = 0;
        ch = str[i];
        if( (ch>='0')&&(ch<='9') )
        {
            val <<= 4;
            val += ch-'0';
            count++;
        }
        else if( (ch>='A')&&(ch<='F') )
        {
            val <<= 4;
            val += ch-'A'+10;
            count++;
        }
        else if( (ch>='a')&&(ch<='f') )
        {
            val <<= 4;
            val += ch-'a'+10;
            count++;
        }
        else if( ch==' ' || ch==':')
        {
            continue;
        }
        else
        {
            return false;
        }
        uc_value[BD_ADDRESS_LEN*2-count] = val;
    }

    for( i=0; i<BD_ADDRESS_LEN; i++ )
    {
        bd_addr.uc_BD_Addr[i] = uc_value[2*i] + 16 * uc_value[2*i+1];
    }

    return true;
}

//----------------------------------------------------------------------------
bool  AnsiString_To_BTHCIValue( AnsiString ansi_str, S_BT_HCI_VALUE &out_value )
{
    /* check if each char is valid */
    unsigned char  uc_value[BT_HCI_VALUE_SIZE*2];
    int   i;
    char  ch;
    char  str[256];
    int   str_len = ansi_str.Length();
    if(str_len==0)  return(false);
    strcpy( str, ansi_str.c_str() );

    for( i=0; i<BT_HCI_VALUE_SIZE; i++ )
    {
        out_value.uc_value[i] = 0;
    }

    for( i=0; i<BT_HCI_VALUE_SIZE*2; i++ )
    {
        uc_value[i] = 0;
    }

    for( i=0; i<str_len; i++ )
    {
        ch = str[i];
        if( ((ch>='0')&&(ch<='9')) || (ch=='+') || (ch=='-') || (ch==' ') )   continue;
        break;
    }
    if( i!=str_len )
        return(false);

    /* convert string to integer */
    double d_out_value = atof(ansi_str.c_str());
    if( d_out_value >= pow(2.0, 160) )  return false;

    for( i=0; i<str_len; i++ )
    {
        uc_value[str_len-i-1] = ansi_str.SubString(i+1,1).ToInt();
    }

    out_value.uc_nz_byte = 0;
    for( i=0; i<sizeof(out_value.uc_value)/sizeof(out_value.uc_value[0]); i++ )
    {
        out_value.uc_value[i] = uc_value[2*i] + 16 * uc_value[2*i+1];
        // out_value.uc_nz_byte++;
    }

    for( i=sizeof(out_value.uc_value)/sizeof(out_value.uc_value[0])-1; i>=0; i-- )
    {
        if( out_value.uc_value[i] != 0 )
        {
            out_value.uc_nz_byte = i+1;
            break;
        }
    }

    return true;
}

//----------------------------------------------------------------------------
bool  AnsiString_Hex_To_BTHCIValue( AnsiString ansi_str, S_BT_HCI_VALUE &out_value )
{
    char  str[256];
    unsigned  char  val;
    unsigned char  uc_value[BT_HCI_VALUE_SIZE*2];

    /* check if each char is valid */
    int   i;
    char  ch;
    int   str_len = ansi_str.Length();
    if(str_len==0)  return(false);
    strcpy( str, ansi_str.c_str() );

    for( i=0; i<sizeof(out_value.uc_value)/sizeof(out_value.uc_value[0]); i++ )
    {
        out_value.uc_value[i] = 0;
    }

    for( i=0; i<BT_HCI_VALUE_SIZE*2; i++ )
    {
        uc_value[i] = 0;
    }

    for( i=0; i<str_len; i++ )
    {
        val = 0;
        ch = str[i];
        if( (ch>='0')&&(ch<='9') )
        {
            val <<= 4;
            val += ch-'0';
        }
        else if( (ch>='A')&&(ch<='F') )
        {
            val <<= 4;
            val += ch-'A'+10;
        }
        else if( (ch>='a')&&(ch<='f') )
        {
            val <<= 4;
            val += ch-'a'+10;
        }
        else if( ch==' ' )
        {
        }
        else
        {
            return false;
        }
        uc_value[str_len-i-1] = val;
    }



    out_value.uc_nz_byte = 0;
    for( i=0; i<sizeof(out_value.uc_value)/sizeof(out_value.uc_value[0]); i++ )
    {
        out_value.uc_value[i] = uc_value[2*i] + 16 * uc_value[2*i+1];
        // if( out_value.uc_value[i] != 0 )
        //     out_value.uc_nz_byte++;
    }

    for( i=sizeof(out_value.uc_value)/sizeof(out_value.uc_value[0])-1; i>=0; i-- )
    {
        if( out_value.uc_value[i] != 0 )
        {
            out_value.uc_nz_byte = i+1;
            break;
        }
    }

    return true;
}

//------------------------------------------------------------------------------
bool  AnsiString_Hex_To_BTPIN( AnsiString ansi_str, S_BT_PIN &pt_pin )
{
    //char  str[256];
    //unsigned char  val;
    //unsigned char  uc_value[BT_PIN_LEN*2];

    /* check if each char is valid */
    //int   i;
    //char  ch;
    int   str_len = ansi_str.Length();
    if(str_len==0)  return(false);
    pt_pin.uc_pin_len = str_len;
    //   strcpy( str, ansi_str.c_str() );
    strcpy( pt_pin.uc_PIN, ansi_str.c_str() );
#if 0
    for( i=0; i<BT_PIN_LEN; i++ )
    {
        pt_pin.uc_PIN[i] = 0;
    }

    for( i=0; i<BT_PIN_LEN*2; i++ )
    {
        uc_value[i] = 0;
    }

    for( i=0; i<str_len; i++ )
    {
        val = 0;
        ch = str[i];
        if( (ch>='0')&&(ch<='9') )
        {
            val <<= 4;
            val += ch-'0';
        }
        else if( (ch>='A')&&(ch<='F') )
        {
            val <<= 4;
            val += ch-'A'+10;
        }
        else if( (ch>='a')&&(ch<='f') )
        {
            val <<= 4;
            val += ch-'a'+10;
        }
        else if( ch==' ' )
        {
        }
        else
        {
            return false;
        }
        uc_value[str_len-i-1] = val;
    }


    for( i=0; i<BT_PIN_LEN; i++ )
    {
        pt_pin.uc_PIN[i] = uc_value[2*i] + 16 * uc_value[2*i+1];
    }
#endif
    return true;
}

//==============================================================================
//////////////////////////////    range check      /////////////////////////////
//==============================================================================
//----------------------------------------------------------------------------
bool  IsValidHexBTHCIValue( AnsiString ansi_str, unsigned char bytes, S_BT_HCI_VALUE &hci_value, S_BT_HCI_VALUE &min_hci_value, S_BT_HCI_VALUE &max_hci_value )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_BTHCIValue( ansi_str, hci_value ) , RANGE_ERR_BT_HCI_VALUE );

    if( hci_value.uc_nz_byte > bytes )  return false;

    AnsiString as_hci_value;
    AnsiString as_min_hci_value;
    AnsiString as_max_hci_value;
    char str_hci_value[BT_HCI_VALUE_SIZE+1];
    char str_min_hci_value[BT_HCI_VALUE_SIZE+1];
    char str_max_hci_value[BT_HCI_VALUE_SIZE+1];
    BTHCIValue_To_Hex_AnsiString( hci_value, as_hci_value );
    BTHCIValue_To_Hex_AnsiString( min_hci_value, as_min_hci_value );
    BTHCIValue_To_Hex_AnsiString( max_hci_value, as_max_hci_value );


    strcpy( str_hci_value, as_hci_value.c_str() );
    strcpy( str_min_hci_value, as_min_hci_value.c_str() );
    strcpy( str_max_hci_value, as_max_hci_value.c_str() );

    double d_hci_value = 0;
    double d_min_hci_value = 0;
    double d_max_hci_value = 0;
    for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
    {
        char val = 0;
        if( str_hci_value[i] == 0 )
            break;

        if( (str_hci_value[i]>='0')&&(str_hci_value[i]<='9') )
        {
            val = str_hci_value[i]-'0';
        }
        else if( (str_hci_value[i]>='A')&&(str_hci_value[i]<='F') )
        {
            val = str_hci_value[i]-'A'+10;
        }
        else if( (str_hci_value[i]>='a')&&(str_hci_value[i]<='f') )
        {
            val = str_hci_value[i]-'a'+10;
        }
        d_hci_value = d_hci_value*16 + val;
    }

    for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
    {
        char val = 0;
        if( str_min_hci_value[i] == 0 )
            break;

        if( (str_min_hci_value[i]>='0')&&(str_min_hci_value[i]<='9') )
        {
            val = str_min_hci_value[i]-'0';
        }
        else if( (str_min_hci_value[i]>='A')&&(str_min_hci_value[i]<='F') )
        {
            val = str_min_hci_value[i]-'A'+10;
        }
        else if( (str_min_hci_value[i]>='a')&&(str_min_hci_value[i]<='f') )
        {
            val = str_min_hci_value[i]-'a'+10;
        }
        d_min_hci_value = d_min_hci_value*16 + val;
    }

    for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
    {
        char val = 0;
        if( str_max_hci_value[i] == 0 )
            break;

        if( (str_max_hci_value[i]>='0')&&(str_max_hci_value[i]<='9') )
        {
            val = str_max_hci_value[i]-'0';
        }
        else if( (str_max_hci_value[i]>='A')&&(str_max_hci_value[i]<='F') )
        {
            val = str_max_hci_value[i]-'A'+10;
        }
        else if( (str_max_hci_value[i]>='a')&&(str_max_hci_value[i]<='f') )
        {
            val = str_max_hci_value[i]-'a'+10;
        }
        d_max_hci_value = d_max_hci_value*16 + val;
    }


    if( ( d_hci_value > d_max_hci_value ) ||
            ( d_hci_value < d_min_hci_value )
      )
        return false;
    return true;
}

//----------------------------------------------------------------------------
bool  IsValidHexBDAddress( AnsiString ansi_str, S_BD_ADDR &bd_addr )
{
    if( ansi_str.AnsiPos(":") == 0 )
    {
        RANGE_CHECK_ERROR( !AnsiString_To_Hex_BDAddress( ansi_str, bd_addr ) , RANGE_ERR_BT_BD_ADDRESS );
    }
    else
    {
        RANGE_CHECK_ERROR( !Colon_AnsiString_To_Hex_BDAddress( ansi_str, bd_addr ) , RANGE_ERR_BT_BD_ADDRESS );
    }

    return true;
}

//----------------------------------------------------------------------------
bool  IsValidDecBTHCIValue( AnsiString ansi_str, unsigned char bytes, S_BT_HCI_VALUE &hci_value, S_BT_HCI_VALUE &min_hci_value, S_BT_HCI_VALUE &max_hci_value )
{
    RANGE_CHECK_ERROR( !AnsiString_To_BTHCIValue( ansi_str, hci_value ) , RANGE_ERR_BT_HCI_VALUE );

    if( hci_value.uc_nz_byte > bytes )  return false;

    for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
    {
        if(  (hci_value.uc_value[i] > max_hci_value.uc_value[i]) ||
                (hci_value.uc_value[i] < min_hci_value.uc_value[i])
          )
            return false;
    }

    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool  IsValidHexBTHCIOpcode( AnsiString ansi_str, unsigned short &opcode )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedShort( ansi_str, opcode ) , RANGE_ERR_BT_HCI_OPCODE );

    return true;
}

//----------------------------------------------------------------------------
bool  IsValidHexBTHCIEventIndex( AnsiString ansi_str, unsigned char &event_idx )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedChar( ansi_str, event_idx ) , RANGE_ERR_BT_HCI_EVENT_INDEX );

    return true;
}

//---------------------------------------------------------------------------
bool  IsValidBTFreq( AnsiString ansi_str, unsigned char &freq )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedChar( ansi_str, freq, 0, 255 ) , RANGE_ERR_BT_FREQ );

    return true;
}

//---------------------------------------------------------------------------
bool  IsValidBTTxDataLength( AnsiString ansi_str, unsigned short &len, unsigned short range_min, unsigned short range_max )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedShort( ansi_str, len, range_min, range_max ) , RANGE_ERR_BT_TX_DATA_LENGTH );

    return true;
}
//---------------------------------------------------------------------------
bool  IsValidBTTxPollPeriod( AnsiString ansi_str, unsigned char &period )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedChar( ansi_str, period, 0, 255 ) , RANGE_ERR_BT_TX_POLL_PERIOD );

    return true;
}

//---------------------------------------------------------------------------
bool  IsValidBTTxPacketCount( AnsiString ansi_str, unsigned int &count )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedInteger( ansi_str, count, 0, 4294967295 ) , RANGE_ERR_BT_TX_PACKET_COUNT );

    return true;
}

//---------------------------------------------------------------------------
bool  IsValidBTTxPcl( AnsiString ansi_str, unsigned char &pcl )
{
//rongguo 2011-11-22
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedChar( ansi_str, pcl, 0, 7 ) , RANGE_ERR_BT_TX_PCL );

    return true;
}
//---------------------------------------------------------------------------
bool  IsValidBTBLEChannel( AnsiString ansi_str, unsigned char &pcl )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedChar( ansi_str, pcl, 0, 39 ) , RANGE_ERR_BT_BLE_CHANNEL );

    return true;
}

//---------------------------------------------------------------------------
bool  IsValidHexBTLAP( AnsiString ansi_str, unsigned int *lap )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedInt( ansi_str, lap ) , RANGE_ERR_BT_TX_LAP );

    return true;
}

//---------------------------------------------------------------------------
bool  IsValidHexBTTxAccessCode( AnsiString ansi_str, unsigned char &code )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedChar( ansi_str, code, 0, 255  ) , RANGE_ERR_BT_TX_ACCESS_CODE );

    return true;
}

//---------------------------------------------------------------------------
bool IsValidDecBTHCIValue( AnsiString ansi_str, unsigned char bytes, S_BT_HCI_VALUE &value )
{
    RANGE_CHECK_ERROR( !AnsiString_To_BTHCIValue( ansi_str, value ) , RANGE_ERR_BT_HCI_VALUE );

    // unsigned char nz_count = 0;
    // for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
    // {
    //     if(  value.uc_value[i] != 0 )
    //         nz_count++;
    // }

    if( value.uc_nz_byte > bytes )  return false;

    // value.uc_nz_byte = nz_count;
    return true;
}

//---------------------------------------------------------------------------
bool IsValidHexBTHCIValue( AnsiString ansi_str, unsigned char bytes, S_BT_HCI_VALUE &value )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_BTHCIValue( ansi_str, value ) , RANGE_ERR_BT_HCI_VALUE );

    // unsigned char nz_count = 0;
    // for( int i=0; i<BT_HCI_VALUE_SIZE; i++ )
    // {
    //     if(  value.uc_value[i] != 0 )
    //         nz_count++;
    // }

    if( value.uc_nz_byte > bytes )  return false;

    // value.uc_nz_byte = nz_count;
    return true;
}


//---------------------------------------------------------------------------
bool IsValidHexBTPIN( AnsiString ansi_str, S_BT_PIN &pin )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_BTPIN( ansi_str, pin ) , RANGE_ERR_BT_PIN );

    return true;
}

//---------------------------------------------------------------------------
bool IsValidHexBDAddress( AnsiString ansi_str, unsigned char &address )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedChar( ansi_str, address, 0, 15  ) , RANGE_ERR_BT_BD_ADDRESS );

    return true;
}

//---------------------------------------------------------------------------
bool  IsValidBTTimeout( AnsiString ansi_str, unsigned int &timeout )
{
    RANGE_CHECK_ERROR( !AnsiString_To_UnsignedInteger( ansi_str, timeout, 0, 10000000 ) , RANGE_ERR_BT_TIMEOUT );

    return true;
}

//============================================================================
//////////////////////////      ESCO     /////////////////////////////////////
//============================================================================
bool IsValidTxBandwidth( AnsiString ansi_str, unsigned int *ui_bandwidth )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedInt( ansi_str, ui_bandwidth  ) , RANGE_ERR_BT_TX_BANDWIDTH );

    return true;
}

//---------------------------------------------------------------------------
bool IsValidRxBandwidth( AnsiString ansi_str, unsigned int *ui_bandwidth )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedInt( ansi_str, ui_bandwidth ) , RANGE_ERR_BT_RX_BANDWIDTH );

    return true;
}

//---------------------------------------------------------------------------
bool IsValidMaxLatency( AnsiString ansi_str, unsigned short &us_latency )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedShort( ansi_str, us_latency  ) , RANGE_ERR_BT_MAX_LATENCY );

    return true;
}

//---------------------------------------------------------------------------
bool IsValidRetransmissionEffort( AnsiString ansi_str, unsigned char &uc_effort )
{
    RANGE_CHECK_ERROR( !AnsiString_Hex_To_UnsignedChar( ansi_str, uc_effort, 0, 0x02  ) , RANGE_ERR_BT_RETRANSMISSION_EFFORT );

    return true;
}
//---------------------------------------------------------------------------
