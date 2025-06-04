object frmNFC: TfrmNFC
  Left = 351
  Top = 192
  Width = 783
  Height = 612
  Caption = 'NFC Tool'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pcNFC: TPageControl
    Left = 0
    Top = 0
    Width = 769
    Height = 537
    ActivePage = tsRawData
    TabIndex = 3
    TabOrder = 0
    object tsNFCSetting: TTabSheet
      Caption = 'NFC Setting'
      object sbNFCSettingSet: TSpeedButton
        Left = 51
        Top = 280
        Width = 75
        Height = 30
        Caption = 'Set'
        Glyph.Data = {
          DE010000424DDE01000000000000760000002800000024000000120000000100
          0400000000006801000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
          33333333333F8888883F33330000324334222222443333388F3833333388F333
          000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
          F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
          223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
          3338888300003AAAAAAA33333333333888888833333333330000333333333333
          333333333333333333FFFFFF000033333333333344444433FFFF333333888888
          00003A444333333A22222438888F333338F3333800003A2243333333A2222438
          F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
          22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
          33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
          3333333333338888883333330000333333333333333333333333333333333333
          0000}
        NumGlyphs = 2
        OnClick = sbNFCSettingSetClick
      end
      object sbNFCSettingNext: TSpeedButton
        Left = 50
        Top = 336
        Width = 75
        Height = 30
        Caption = 'Next'
        Enabled = False
        Glyph.Data = {
          F2060000424DF206000000000000360400002800000019000000190000000100
          080000000000BC02000012170000121700000001000000010000000000000101
          0100020202000303030004040400050505000606060007070700080808000909
          09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
          1100121212001313130014141400151515001616160017171700181818001919
          19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
          2100222222002323230024242400252525002626260027272700282828002929
          29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
          3100323232003333330034343400353535003636360037373700383838003939
          39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
          4100424242004343430044444400454545004646460047474700484848004949
          49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
          5100525252005353530054545400555555005656560057575700585858005959
          59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
          6100626262006363630064646400656565006666660067676700686868006969
          69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
          7100727272007373730074747400757575007676760077777700787878007979
          79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
          8100828282008383830084848400858585008686860087878700888888008989
          89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
          9100929292009393930094949400959595009696960097979700989898009999
          99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
          A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
          A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
          B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
          B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
          C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
          C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
          D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
          D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
          E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
          E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
          F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
          F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF00FFFDFAFAFAFA
          FAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFDFE000000FEE2CCCBCBCBCBCBCBCB
          CBCBCBCBCBCBCBCBCBCBCBCBCCE2FD000000FBF5FFFEFEFEFEFEFEFEFEFEFEFE
          FEFEFEFEFEFEFEFEFFF5FB000000FBFAC587898B8C8C8C8C8C8C8C8C8C8C8C8C
          8C8C8C87C5FAFB000000FBFBBE7AAF847A7E7E7E7E7E7E7E7E7E7E7E7E7E7E79
          BEFBFB000000FBFBBF85F6F8BC8B7E7E7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB00
          0000FBFBBF85F981B9F6CD8B787E7F7F7F7F7F7F7F7F7F7ABEFBFB000000FBFB
          BF85FB5F4957C8FFC7837F7F7F7F7F7F7F7F7F7ABEFBFB000000FBFBBF85FB5F
          4A4B4371C6F0C1907B7E7F7F7F7F7F7ABEFBFB000000FBFBBF85FB5F4A4C4B4A
          4C62BAFECE837B7F7F7F7F7ABEFBFB000000FBFBBF85FB5F4A4C4C4C4C4B4662
          D2F7BD8B7E7E7F7ABEFBFB000000FBFBBF85FB5F4A4C4C4C4C4C4C494671BAF6
          CD8B797ABEFBFB000000FBFBBF85FB5F4A4C4C4C4C4C4C4C4C4C4B57C8FFC47A
          BEFBFB000000FBFBBF85FB5F4A4C4C4C4C4C4C4C4C4A476EB0EDC97DBEFBFB00
          0000FBFBBF85FB5F4A4C4C4C4C4C4C4B455DCDF8C18C7E7ABEFBFB000000FBFB
          BF85FB5F4A4C4C4C4B4A4C63B8FFD1837A7E7F7ABEFBFB000000FBFBBF85FB5F
          4A4C4C4B446DC4F0C3927B7E7F7F7F7ABEFBFB000000FBFBBF85FB5F4A4C4B56
          C4FFC9837E7F7F7F7F7F7F7ABEFBFB000000FBFBBF85FB5D456FB6F5CF8D797E
          7F7F7F7F7F7F7F7ABEFBFB000000FBFBBF85FB72CCF8C18C7E7E7F7F7F7F7F7F
          7F7F7F7ABEFBFB000000FBFBBF84F2FDD1837A7E7F7F7F7F7F7F7F7F7F7F7F7A
          BEFBFB000000FBFBBF7BA8937B7E7F7F7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB00
          0000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB000000FDFB
          F8F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F8FBFD000000FEFEFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFE000000}
        Layout = blGlyphRight
        OnClick = sbNFCSettingNextClick
      end
      object gbNFCFeature: TGroupBox
        Left = 16
        Top = 24
        Width = 145
        Height = 73
        Caption = 'NFC Feature'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object rbNFCOn: TRadioButton
          Left = 16
          Top = 24
          Width = 65
          Height = 17
          Caption = 'ON'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = True
          OnClick = rbNFCClick
        end
        object rbNFCOff: TRadioButton
          Left = 16
          Top = 48
          Width = 65
          Height = 17
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = rbNFCClick
        end
      end
      object gbNFCDebug: TGroupBox
        Left = 16
        Top = 104
        Width = 145
        Height = 73
        Caption = 'NFC Debug'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        object rbNFCDebugOn: TRadioButton
          Left = 16
          Top = 24
          Width = 57
          Height = 17
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = rbNFCDebugClick
        end
        object rbNFCDebugOff: TRadioButton
          Left = 16
          Top = 48
          Width = 57
          Height = 17
          Caption = 'OFF'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          TabStop = True
          OnClick = rbNFCDebugClick
        end
      end
      object gbNFCMode: TGroupBox
        Left = 16
        Top = 184
        Width = 145
        Height = 73
        Caption = 'Software Protocol Switch'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        object rbNFCRawData: TRadioButton
          Left = 16
          Top = 48
          Width = 97
          Height = 17
          Caption = 'Raw Data'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = rsNFCSWProtocolSwitchClick
        end
        object rbNFCSoftwareStack: TRadioButton
          Left = 16
          Top = 24
          Width = 97
          Height = 17
          Caption = 'Software Stack'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          TabStop = True
          OnClick = rsNFCSWProtocolSwitchClick
        end
      end
      object gbNFCCapabilities: TGroupBox
        Left = 176
        Top = 24
        Width = 545
        Height = 265
        Caption = 'Capabilities'
        Color = clBtnFace
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 3
        object gbVersion: TGroupBox
          Left = 24
          Top = 24
          Width = 201
          Height = 177
          Caption = 'Version'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object lblNFCFwVersion: TLabel
            Left = 18
            Top = 61
            Width = 61
            Height = 13
            Caption = 'FW Version :'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object lblNFCSwVersion: TLabel
            Left = 17
            Top = 98
            Width = 62
            Height = 13
            Caption = 'SW Version :'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object lblNFCHwVersion: TLabel
            Left = 16
            Top = 136
            Width = 63
            Height = 13
            Caption = 'HW Version :'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object lblNFCVendor: TLabel
            Left = 8
            Top = 24
            Width = 71
            Height = 13
            Caption = 'Vendor Name :'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object stNFCVendor: TStaticText
            Left = 96
            Top = 24
            Width = 89
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSingle
            Caption = 'NXP'
            Color = clCaptionText
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            TabOrder = 0
          end
          object stNFCFwVersion: TStaticText
            Left = 96
            Top = 61
            Width = 89
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSingle
            Color = clCaptionText
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            TabOrder = 1
          end
          object stNFCSwVersion: TStaticText
            Left = 96
            Top = 96
            Width = 89
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSingle
            Color = clCaptionText
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            TabOrder = 2
          end
          object stNFCHwVersion: TStaticText
            Left = 96
            Top = 136
            Width = 89
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSingle
            Color = clCaptionText
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentColor = False
            ParentFont = False
            TabOrder = 3
          end
        end
        object gbNFCSupportedProtocols: TGroupBox
          Left = 248
          Top = 24
          Width = 273
          Height = 217
          Caption = 'Supported Protocols'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object Label7: TLabel
            Left = 37
            Top = 32
            Width = 71
            Height = 13
            Caption = 'Reader Mode :'
          end
          object Label8: TLabel
            Left = 163
            Top = 32
            Width = 58
            Height = 13
            Caption = 'Card Mode :'
          end
          object clbNFC_Support_Prococol_Rm: TCheckListBox
            Left = 24
            Top = 56
            Width = 97
            Height = 129
            Enabled = False
            ItemHeight = 13
            Items.Strings = (
              'MifareUL'
              'MifareStd'
              'ISO14443_4A'
              'ISO14443_4B'
              'Jewel'
              'NFC'
              'Felica'
              'ISO15693')
            TabOrder = 0
          end
          object clbNFC_Support_Prococol_Cm: TCheckListBox
            Left = 144
            Top = 56
            Width = 97
            Height = 129
            Enabled = False
            ItemHeight = 13
            Items.Strings = (
              'MifareUL'
              'MifareStd'
              'ISO14443_4A'
              'ISO14443_4B'
              'Jewel'
              'NFC'
              'Felica'
              'ISO15693')
            TabOrder = 1
          end
        end
      end
    end
    object tsNFCRegisterNotification: TTabSheet
      Caption = 'Register Notification'
      ImageIndex = 1
      object sbNFCRegisterNofificationBack: TSpeedButton
        Left = 63
        Top = 336
        Width = 75
        Height = 30
        Caption = 'Back'
        Glyph.Data = {
          F2060000424DF206000000000000360400002800000019000000190000000100
          080000000000BC02000012170000121700000001000000010000000000000101
          0100020202000303030004040400050505000606060007070700080808000909
          09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
          1100121212001313130014141400151515001616160017171700181818001919
          19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
          2100222222002323230024242400252525002626260027272700282828002929
          29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
          3100323232003333330034343400353535003636360037373700383838003939
          39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
          4100424242004343430044444400454545004646460047474700484848004949
          49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
          5100525252005353530054545400555555005656560057575700585858005959
          59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
          6100626262006363630064646400656565006666660067676700686868006969
          69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
          7100727272007373730074747400757575007676760077777700787878007979
          79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
          8100828282008383830084848400858585008686860087878700888888008989
          89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
          9100929292009393930094949400959595009696960097979700989898009999
          99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
          A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
          A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
          B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
          B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
          C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
          C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
          D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
          D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
          E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
          E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
          F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
          F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF00FFFDFAFAFAFA
          FAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFDFE000000FEE2CCCBCBCBCBCBCBCB
          CBCBCBCBCBCBCBCBCBCBCBCBCCE2FD000000FBF5FFFEFEFEFEFEFEFEFEFEFEFE
          FEFEFEFEFEFEFEFEFFF5FB000000FBFAC5878C8C8C8C8C8C8C8C8C8C8C8C8C8C
          8C8B8987C5FAFB000000FBFBBE797E7E7E7E7E7E7E7E7E7E7E7E7E7E7A83AF7A
          BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7E7E8ABBF8F685BEFBFB00
          0000FBFBBF7A7F7F7F7F7F7F7F7F7F7E798ACCF6BB82F985BEFBFB000000FBFB
          BF7A7F7F7F7F7F7F7F7F7F83C5FFCA59495FFB85BEFBFB000000FBFBBF7A7F7F
          7F7F7F7E7B8FC0F0C873434B4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7B83
          CDFEBC634D4A4B4C4A5FFB85BEFBFB000000FBFBBF7A7F7E7E8ABBF7D364464B
          4C4C4C4C4A5FFB85BEFBFB000000FBFBBF7A798ACCF6BC7246494C4C4C4C4C4C
          4A5FFB85BEFBFB000000FBFBBF79C2FFCA594B4C4C4C4C4C4C4C4C4C4A5FFB85
          BEFBFB000000FBFBBF7CC8EDB26F474A4C4C4C4C4C4C4C4C4A5FFB85BEFBFB00
          0000FBFBBF7A7E8CBFF9CF5F454B4C4C4C4C4C4C4A5FFB85BEFBFB000000FBFB
          BF7A7F7E7B82D0FFBA644C4A4B4C4C4C4A5FFB85BEFBFB000000FBFBBF7A7F7F
          7F7E7B91C2F0C56F444B4C4C4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F
          7E82C7FFC5584A4C4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7E798C
          CEF5B870455DFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7E7E8CBFF9
          CD74FA85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7E7B82D0FDF284
          BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7F7F7E7B92A87CBEFBFB00
          0000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB000000FDFB
          F8F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F8FBFD000000FEFEFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFE000000}
        OnClick = sbNFCRegisterNofificationBackClick
      end
      object sbNFCRegisterNofificationNext: TSpeedButton
        Left = 63
        Top = 376
        Width = 75
        Height = 30
        Caption = 'Next'
        Enabled = False
        Glyph.Data = {
          F2060000424DF206000000000000360400002800000019000000190000000100
          080000000000BC02000012170000121700000001000000010000000000000101
          0100020202000303030004040400050505000606060007070700080808000909
          09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
          1100121212001313130014141400151515001616160017171700181818001919
          19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
          2100222222002323230024242400252525002626260027272700282828002929
          29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
          3100323232003333330034343400353535003636360037373700383838003939
          39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
          4100424242004343430044444400454545004646460047474700484848004949
          49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
          5100525252005353530054545400555555005656560057575700585858005959
          59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
          6100626262006363630064646400656565006666660067676700686868006969
          69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
          7100727272007373730074747400757575007676760077777700787878007979
          79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
          8100828282008383830084848400858585008686860087878700888888008989
          89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
          9100929292009393930094949400959595009696960097979700989898009999
          99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
          A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
          A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
          B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
          B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
          C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
          C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
          D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
          D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
          E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
          E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
          F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
          F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF00FFFDFAFAFAFA
          FAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFDFE000000FEE2CCCBCBCBCBCBCBCB
          CBCBCBCBCBCBCBCBCBCBCBCBCCE2FD000000FBF5FFFEFEFEFEFEFEFEFEFEFEFE
          FEFEFEFEFEFEFEFEFFF5FB000000FBFAC587898B8C8C8C8C8C8C8C8C8C8C8C8C
          8C8C8C87C5FAFB000000FBFBBE7AAF847A7E7E7E7E7E7E7E7E7E7E7E7E7E7E79
          BEFBFB000000FBFBBF85F6F8BC8B7E7E7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB00
          0000FBFBBF85F981B9F6CD8B787E7F7F7F7F7F7F7F7F7F7ABEFBFB000000FBFB
          BF85FB5F4957C8FFC7837F7F7F7F7F7F7F7F7F7ABEFBFB000000FBFBBF85FB5F
          4A4B4371C6F0C1907B7E7F7F7F7F7F7ABEFBFB000000FBFBBF85FB5F4A4C4B4A
          4C62BAFECE837B7F7F7F7F7ABEFBFB000000FBFBBF85FB5F4A4C4C4C4C4B4662
          D2F7BD8B7E7E7F7ABEFBFB000000FBFBBF85FB5F4A4C4C4C4C4C4C494671BAF6
          CD8B797ABEFBFB000000FBFBBF85FB5F4A4C4C4C4C4C4C4C4C4C4B57C8FFC47A
          BEFBFB000000FBFBBF85FB5F4A4C4C4C4C4C4C4C4C4A476EB0EDC97DBEFBFB00
          0000FBFBBF85FB5F4A4C4C4C4C4C4C4B455DCDF8C18C7E7ABEFBFB000000FBFB
          BF85FB5F4A4C4C4C4B4A4C63B8FFD1837A7E7F7ABEFBFB000000FBFBBF85FB5F
          4A4C4C4B446DC4F0C3927B7E7F7F7F7ABEFBFB000000FBFBBF85FB5F4A4C4B56
          C4FFC9837E7F7F7F7F7F7F7ABEFBFB000000FBFBBF85FB5D456FB6F5CF8D797E
          7F7F7F7F7F7F7F7ABEFBFB000000FBFBBF85FB72CCF8C18C7E7E7F7F7F7F7F7F
          7F7F7F7ABEFBFB000000FBFBBF84F2FDD1837A7E7F7F7F7F7F7F7F7F7F7F7F7A
          BEFBFB000000FBFBBF7BA8937B7E7F7F7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB00
          0000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB000000FDFB
          F8F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F8FBFD000000FEFEFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFE000000}
        Layout = blGlyphRight
        OnClick = sbNFCRegisterNofificationNextClick
      end
      object Label1: TLabel
        Left = 552
        Top = 48
        Width = 184
        Height = 48
        Caption = 
          'Register for notifications based technology type it is intereste' +
          'd to discover.'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        WordWrap = True
      end
      object Label2: TLabel
        Left = 552
        Top = 24
        Width = 126
        Height = 16
        Caption = 'Resigter Notification :'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        WordWrap = True
      end
      object gbNFCNofificationSetting: TGroupBox
        Left = 16
        Top = 16
        Width = 169
        Height = 305
        Caption = 'Notification Setting'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object sbNFCRegisterNofificationSet: TSpeedButton
          Left = 47
          Top = 261
          Width = 75
          Height = 30
          Caption = 'Set'
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
            33333333333F8888883F33330000324334222222443333388F3833333388F333
            000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
            F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
            223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
            3338888300003AAAAAAA33333333333888888833333333330000333333333333
            333333333333333333FFFFFF000033333333333344444433FFFF333333888888
            00003A444333333A22222438888F333338F3333800003A2243333333A2222438
            F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
            22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
            33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
            3333333333338888883333330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
          OnClick = sbNFCRegisterNofificationSetClick
        end
        object gbNFCNotificationMode: TGroupBox
          Left = 24
          Top = 24
          Width = 121
          Height = 225
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object cbNFC_RN_MifareUL: TCheckBox
            Left = 16
            Top = 24
            Width = 89
            Height = 17
            Caption = 'MifareUL'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 0
          end
          object cbNFC_RN_ISO144434B: TCheckBox
            Left = 16
            Top = 96
            Width = 89
            Height = 17
            Caption = 'ISO14443_4B'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 1
          end
          object cbNFC_RN_MifareStd: TCheckBox
            Left = 16
            Top = 48
            Width = 89
            Height = 17
            Caption = 'MifareStd'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 2
          end
          object cbNFC_RN_ISO15693: TCheckBox
            Left = 16
            Top = 192
            Width = 89
            Height = 17
            Caption = 'ISO15693'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 3
          end
          object cbNFC_RN_Felica: TCheckBox
            Left = 16
            Top = 168
            Width = 89
            Height = 17
            Caption = 'Felica'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 4
          end
          object cbNFC_RN_ISO144434A: TCheckBox
            Left = 16
            Top = 72
            Width = 89
            Height = 17
            Caption = 'ISO14443_4A'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 5
          end
          object cbNFC_RN_Jewel: TCheckBox
            Left = 16
            Top = 120
            Width = 89
            Height = 17
            Caption = 'Jewel'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 6
          end
          object cbNFC_RN_NFC: TCheckBox
            Left = 16
            Top = 144
            Width = 89
            Height = 17
            Caption = 'NFC'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 7
          end
        end
      end
      object gbNFCSecureElements: TGroupBox
        Left = 208
        Top = 16
        Width = 329
        Height = 385
        Caption = 'Secure Elements'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Visible = False
        object Label9: TLabel
          Left = 24
          Top = 30
          Width = 56
          Height = 13
          Caption = 'Desciption :'
        end
        object Label10: TLabel
          Left = 24
          Top = 102
          Width = 81
          Height = 13
          Caption = 'Event Detected :'
        end
        object mmSecureElements: TMemo
          Left = 24
          Top = 48
          Width = 281
          Height = 33
          Enabled = False
          ReadOnly = True
          TabOrder = 0
        end
        object clbNFC_Secure_Event_Detected: TCheckListBox
          Left = 24
          Top = 120
          Width = 281
          Height = 49
          Align = alCustom
          AutoComplete = False
          Columns = 2
          Enabled = False
          HeaderColor = clDefault
          HeaderBackgroundColor = clMenuHighlight
          ItemHeight = 13
          Items.Strings = (
            'Start Of Transaction'
            'End Of Transaction'
            'Transaction'
            'RF Field ON'
            'RF Field OFF'
            'Connectivity')
          TabOrder = 1
        end
        object gbNFCSecureElementSetMode: TGroupBox
          Left = 24
          Top = 184
          Width = 281
          Height = 177
          Caption = 'Mode'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          object sbNFCSecureElementsSet: TSpeedButton
            Left = 188
            Top = 137
            Width = 75
            Height = 30
            Caption = 'Set'
            Glyph.Data = {
              DE010000424DDE01000000000000760000002800000024000000120000000100
              0400000000006801000000000000000000001000000000000000000000000000
              80000080000000808000800000008000800080800000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
              33333333333F8888883F33330000324334222222443333388F3833333388F333
              000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
              F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
              223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
              3338888300003AAAAAAA33333333333888888833333333330000333333333333
              333333333333333333FFFFFF000033333333333344444433FFFF333333888888
              00003A444333333A22222438888F333338F3333800003A2243333333A2222438
              F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
              22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
              33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
              3333333333338888883333330000333333333333333333333333333333333333
              0000}
            NumGlyphs = 2
            OnClick = sbNFCSecureElementsSetClick
          end
          object gbNFCSecureElement1: TGroupBox
            Left = 16
            Top = 24
            Width = 249
            Height = 49
            Caption = 'Secure Element 1'
            TabOrder = 0
            object cbNFCSecureElement1Off: TRadioButton
              Left = 16
              Top = 24
              Width = 49
              Height = 17
              Caption = 'OFF'
              Checked = True
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clRed
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              TabStop = True
            end
            object cbNFCSecureElement1Virtual: TRadioButton
              Left = 96
              Top = 24
              Width = 49
              Height = 17
              Caption = 'Virtual'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
            end
            object cbNFCSecureElement1Wired: TRadioButton
              Left = 176
              Top = 24
              Width = 49
              Height = 17
              Caption = 'Wired'
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
            end
          end
          object gbNFCSecureElement2: TGroupBox
            Left = 16
            Top = 80
            Width = 249
            Height = 49
            Caption = 'Secure Element 2'
            TabOrder = 1
            object cbNFCSecureElement2Virtual: TRadioButton
              Left = 96
              Top = 24
              Width = 49
              Height = 17
              Caption = 'Virtual'
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
            end
            object cbNFCSecureElement2Off: TRadioButton
              Left = 16
              Top = 24
              Width = 49
              Height = 17
              Caption = 'OFF'
              Checked = True
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clRed
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              TabStop = True
            end
            object cbNFCSecureElement2Wired: TRadioButton
              Left = 176
              Top = 24
              Width = 49
              Height = 17
              Caption = 'Wired'
              Enabled = False
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
            end
          end
        end
        object stNFC_RN_SEDetected: TStaticText
          Left = 148
          Top = 16
          Width = 157
          Height = 20
          Alignment = taCenter
          BorderStyle = sbsSingle
          Caption = 'Secure Element Detected'
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 3
        end
      end
    end
    object tsNFCDiscoveryNotification: TTabSheet
      Caption = 'Discovery Notification'
      ImageIndex = 3
      object Label3: TLabel
        Left = 552
        Top = 24
        Width = 136
        Height = 16
        Caption = 'Discovery Notification : '
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        WordWrap = True
      end
      object Label4: TLabel
        Left = 552
        Top = 48
        Width = 176
        Height = 32
        Caption = 'Configure the technology type it is interested to discover.'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        WordWrap = True
      end
      object sbNFCDiscoveryNotificationBack: TSpeedButton
        Left = 82
        Top = 312
        Width = 75
        Height = 30
        Caption = 'Back'
        Glyph.Data = {
          F2060000424DF206000000000000360400002800000019000000190000000100
          080000000000BC02000012170000121700000001000000010000000000000101
          0100020202000303030004040400050505000606060007070700080808000909
          09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
          1100121212001313130014141400151515001616160017171700181818001919
          19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
          2100222222002323230024242400252525002626260027272700282828002929
          29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
          3100323232003333330034343400353535003636360037373700383838003939
          39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
          4100424242004343430044444400454545004646460047474700484848004949
          49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
          5100525252005353530054545400555555005656560057575700585858005959
          59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
          6100626262006363630064646400656565006666660067676700686868006969
          69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
          7100727272007373730074747400757575007676760077777700787878007979
          79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
          8100828282008383830084848400858585008686860087878700888888008989
          89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
          9100929292009393930094949400959595009696960097979700989898009999
          99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
          A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
          A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
          B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
          B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
          C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
          C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
          D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
          D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
          E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
          E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
          F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
          F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF00FFFDFAFAFAFA
          FAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFDFE000000FEE2CCCBCBCBCBCBCBCB
          CBCBCBCBCBCBCBCBCBCBCBCBCCE2FD000000FBF5FFFEFEFEFEFEFEFEFEFEFEFE
          FEFEFEFEFEFEFEFEFFF5FB000000FBFAC5878C8C8C8C8C8C8C8C8C8C8C8C8C8C
          8C8B8987C5FAFB000000FBFBBE797E7E7E7E7E7E7E7E7E7E7E7E7E7E7A83AF7A
          BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7E7E8ABBF8F685BEFBFB00
          0000FBFBBF7A7F7F7F7F7F7F7F7F7F7E798ACCF6BB82F985BEFBFB000000FBFB
          BF7A7F7F7F7F7F7F7F7F7F83C5FFCA59495FFB85BEFBFB000000FBFBBF7A7F7F
          7F7F7F7E7B8FC0F0C873434B4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7B83
          CDFEBC634D4A4B4C4A5FFB85BEFBFB000000FBFBBF7A7F7E7E8ABBF7D364464B
          4C4C4C4C4A5FFB85BEFBFB000000FBFBBF7A798ACCF6BC7246494C4C4C4C4C4C
          4A5FFB85BEFBFB000000FBFBBF79C2FFCA594B4C4C4C4C4C4C4C4C4C4A5FFB85
          BEFBFB000000FBFBBF7CC8EDB26F474A4C4C4C4C4C4C4C4C4A5FFB85BEFBFB00
          0000FBFBBF7A7E8CBFF9CF5F454B4C4C4C4C4C4C4A5FFB85BEFBFB000000FBFB
          BF7A7F7E7B82D0FFBA644C4A4B4C4C4C4A5FFB85BEFBFB000000FBFBBF7A7F7F
          7F7E7B91C2F0C56F444B4C4C4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F
          7E82C7FFC5584A4C4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7E798C
          CEF5B870455DFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7E7E8CBFF9
          CD74FA85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7E7B82D0FDF284
          BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7F7F7E7B92A87CBEFBFB00
          0000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB000000FDFB
          F8F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F8FBFD000000FEFEFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFE000000}
        OnClick = sbNFCDiscoveryNotificationBackClick
      end
      object gbNFCDiscoveryNotification: TGroupBox
        Left = 16
        Top = 16
        Width = 417
        Height = 273
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object lblNFC_DN_Duration: TLabel
          Left = 219
          Top = 44
          Width = 46
          Height = 13
          Caption = 'Duration :'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblNFC_DN_Durationms: TLabel
          Left = 371
          Top = 44
          Width = 13
          Height = 13
          Caption = 'ms'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object sbNFCDiscoveryNotificationSet: TSpeedButton
          Left = 266
          Top = 221
          Width = 75
          Height = 30
          Caption = 'Set'
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
            33333333333F8888883F33330000324334222222443333388F3833333388F333
            000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
            F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
            223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
            3338888300003AAAAAAA33333333333888888833333333330000333333333333
            333333333333333333FFFFFF000033333333333344444433FFFF333333888888
            00003A444333333A22222438888F333338F3333800003A2243333333A2222438
            F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
            22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
            33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
            3333333333338888883333330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
          OnClick = sbNFCDiscoveryNotificationSetClick
        end
        object gbNFCDicsoverySetting: TGroupBox
          Left = 24
          Top = 24
          Width = 169
          Height = 225
          Caption = 'Dicovery Setting'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object cbNFC_DS_Felica212: TCheckBox
            Left = 16
            Top = 72
            Width = 145
            Height = 17
            Caption = 'Felica 212'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 0
          end
          object cbNFC_DS_ISO14443B: TCheckBox
            Left = 16
            Top = 48
            Width = 145
            Height = 17
            Caption = 'ISO14443 B'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 1
          end
          object cbNFC_DS_Felica424: TCheckBox
            Left = 16
            Top = 96
            Width = 145
            Height = 17
            Caption = 'Felica 424'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 2
          end
          object cbNFC_DS_ISO15693: TCheckBox
            Left = 16
            Top = 120
            Width = 145
            Height = 17
            Caption = 'ISO15693'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 3
          end
          object cbNFC_DS_DisCardEmu: TCheckBox
            Left = 16
            Top = 168
            Width = 145
            Height = 17
            Caption = 'Discard Card Emulation'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 4
          end
          object cbNFC_DS_ISO14443A: TCheckBox
            Left = 16
            Top = 24
            Width = 145
            Height = 17
            Caption = 'ISO14443 A'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 5
          end
          object cbNFC_DS_NFCActive: TCheckBox
            Left = 16
            Top = 144
            Width = 145
            Height = 17
            Caption = 'NFC Active'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 6
          end
          object cbNFC_DS_DisP2PIpTar: TCheckBox
            Left = 16
            Top = 192
            Width = 145
            Height = 17
            Caption = 'Disable P2P Ip Target'
            Checked = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clBlack
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            State = cbChecked
            TabOrder = 7
          end
        end
        object edtNFC_DN_Duration: TEdit
          Left = 280
          Top = 40
          Width = 81
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          MaxLength = 5
          ParentFont = False
          TabOrder = 1
          Text = '500'
        end
      end
    end
    object tsRawData: TTabSheet
      Caption = 'Raw Data'
      ImageIndex = 2
      object Label5: TLabel
        Left = 592
        Top = 24
        Width = 62
        Height = 16
        Caption = 'Raw Data:'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        WordWrap = True
      end
      object Label6: TLabel
        Left = 592
        Top = 48
        Width = 158
        Height = 48
        Caption = 
          'Switch NFC sortware protocol to raw data mode and run by script ' +
          'file'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        WordWrap = True
      end
      object sbNFCRawDataBack: TSpeedButton
        Left = 584
        Top = 464
        Width = 75
        Height = 30
        Caption = 'Back'
        Glyph.Data = {
          F2060000424DF206000000000000360400002800000019000000190000000100
          080000000000BC02000012170000121700000001000000010000000000000101
          0100020202000303030004040400050505000606060007070700080808000909
          09000A0A0A000B0B0B000C0C0C000D0D0D000E0E0E000F0F0F00101010001111
          1100121212001313130014141400151515001616160017171700181818001919
          19001A1A1A001B1B1B001C1C1C001D1D1D001E1E1E001F1F1F00202020002121
          2100222222002323230024242400252525002626260027272700282828002929
          29002A2A2A002B2B2B002C2C2C002D2D2D002E2E2E002F2F2F00303030003131
          3100323232003333330034343400353535003636360037373700383838003939
          39003A3A3A003B3B3B003C3C3C003D3D3D003E3E3E003F3F3F00404040004141
          4100424242004343430044444400454545004646460047474700484848004949
          49004A4A4A004B4B4B004C4C4C004D4D4D004E4E4E004F4F4F00505050005151
          5100525252005353530054545400555555005656560057575700585858005959
          59005A5A5A005B5B5B005C5C5C005D5D5D005E5E5E005F5F5F00606060006161
          6100626262006363630064646400656565006666660067676700686868006969
          69006A6A6A006B6B6B006C6C6C006D6D6D006E6E6E006F6F6F00707070007171
          7100727272007373730074747400757575007676760077777700787878007979
          79007A7A7A007B7B7B007C7C7C007D7D7D007E7E7E007F7F7F00808080008181
          8100828282008383830084848400858585008686860087878700888888008989
          89008A8A8A008B8B8B008C8C8C008D8D8D008E8E8E008F8F8F00909090009191
          9100929292009393930094949400959595009696960097979700989898009999
          99009A9A9A009B9B9B009C9C9C009D9D9D009E9E9E009F9F9F00A0A0A000A1A1
          A100A2A2A200A3A3A300A4A4A400A5A5A500A6A6A600A7A7A700A8A8A800A9A9
          A900AAAAAA00ABABAB00ACACAC00ADADAD00AEAEAE00AFAFAF00B0B0B000B1B1
          B100B2B2B200B3B3B300B4B4B400B5B5B500B6B6B600B7B7B700B8B8B800B9B9
          B900BABABA00BBBBBB00BCBCBC00BDBDBD00BEBEBE00BFBFBF00C0C0C000C1C1
          C100C2C2C200C3C3C300C4C4C400C5C5C500C6C6C600C7C7C700C8C8C800C9C9
          C900CACACA00CBCBCB00CCCCCC00CDCDCD00CECECE00CFCFCF00D0D0D000D1D1
          D100D2D2D200D3D3D300D4D4D400D5D5D500D6D6D600D7D7D700D8D8D800D9D9
          D900DADADA00DBDBDB00DCDCDC00DDDDDD00DEDEDE00DFDFDF00E0E0E000E1E1
          E100E2E2E200E3E3E300E4E4E400E5E5E500E6E6E600E7E7E700E8E8E800E9E9
          E900EAEAEA00EBEBEB00ECECEC00EDEDED00EEEEEE00EFEFEF00F0F0F000F1F1
          F100F2F2F200F3F3F300F4F4F400F5F5F500F6F6F600F7F7F700F8F8F800F9F9
          F900FAFAFA00FBFBFB00FCFCFC00FDFDFD00FEFEFE00FFFFFF00FFFDFAFAFAFA
          FAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFAFDFE000000FEE2CCCBCBCBCBCBCBCB
          CBCBCBCBCBCBCBCBCBCBCBCBCCE2FD000000FBF5FFFEFEFEFEFEFEFEFEFEFEFE
          FEFEFEFEFEFEFEFEFFF5FB000000FBFAC5878C8C8C8C8C8C8C8C8C8C8C8C8C8C
          8C8B8987C5FAFB000000FBFBBE797E7E7E7E7E7E7E7E7E7E7E7E7E7E7A83AF7A
          BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7E7E8ABBF8F685BEFBFB00
          0000FBFBBF7A7F7F7F7F7F7F7F7F7F7E798ACCF6BB82F985BEFBFB000000FBFB
          BF7A7F7F7F7F7F7F7F7F7F83C5FFCA59495FFB85BEFBFB000000FBFBBF7A7F7F
          7F7F7F7E7B8FC0F0C873434B4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7B83
          CDFEBC634D4A4B4C4A5FFB85BEFBFB000000FBFBBF7A7F7E7E8ABBF7D364464B
          4C4C4C4C4A5FFB85BEFBFB000000FBFBBF7A798ACCF6BC7246494C4C4C4C4C4C
          4A5FFB85BEFBFB000000FBFBBF79C2FFCA594B4C4C4C4C4C4C4C4C4C4A5FFB85
          BEFBFB000000FBFBBF7CC8EDB26F474A4C4C4C4C4C4C4C4C4A5FFB85BEFBFB00
          0000FBFBBF7A7E8CBFF9CF5F454B4C4C4C4C4C4C4A5FFB85BEFBFB000000FBFB
          BF7A7F7E7B82D0FFBA644C4A4B4C4C4C4A5FFB85BEFBFB000000FBFBBF7A7F7F
          7F7E7B91C2F0C56F444B4C4C4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F
          7E82C7FFC5584A4C4A5FFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7E798C
          CEF5B870455DFB85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7E7E8CBFF9
          CD74FA85BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7E7B82D0FDF284
          BEFBFB000000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7F7F7E7B92A87CBEFBFB00
          0000FBFBBF7A7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7ABEFBFB000000FDFB
          F8F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F1F8FBFD000000FEFEFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFE000000}
        OnClick = sbNFCRawDataBackClick
      end
      object gbNFCRawData: TGroupBox
        Left = 16
        Top = 224
        Width = 545
        Height = 273
        Caption = 'NFC Script'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object sbNFCRawDataScriptStart: TSpeedButton
          Left = 18
          Top = 59
          Width = 75
          Height = 25
          Caption = 'Start'
          Enabled = False
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
            33333333333F8888883F33330000324334222222443333388F3833333388F333
            000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
            F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
            223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
            3338888300003AAAAAAA33333333333888888833333333330000333333333333
            333333333333333333FFFFFF000033333333333344444433FFFF333333888888
            00003A444333333A22222438888F333338F3333800003A2243333333A2222438
            F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
            22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
            33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
            3333333333338888883333330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
          OnClick = sbNFCRawDataScriptStartClick
        end
        object sbNFCRawDataScriptStop: TSpeedButton
          Left = 98
          Top = 59
          Width = 75
          Height = 25
          Caption = 'Stop'
          Enabled = False
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333333FFFFF333333000033333388888833333333333F888888FFF333
            000033338811111188333333338833FFF388FF33000033381119999111833333
            38F338888F338FF30000339119933331111833338F388333383338F300003391
            13333381111833338F8F3333833F38F3000039118333381119118338F38F3338
            33F8F38F000039183333811193918338F8F333833F838F8F0000391833381119
            33918338F8F33833F8338F8F000039183381119333918338F8F3833F83338F8F
            000039183811193333918338F8F833F83333838F000039118111933339118338
            F3833F83333833830000339111193333391833338F33F8333FF838F300003391
            11833338111833338F338FFFF883F83300003339111888811183333338FF3888
            83FF83330000333399111111993333333388FFFFFF8833330000333333999999
            3333333333338888883333330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
          OnClick = sbNFCRawDataScriptStopClick
        end
        object btnNFC_RD_OpenScript: TButton
          Left = 16
          Top = 28
          Width = 121
          Height = 25
          Caption = 'Open Script File'
          Enabled = False
          TabOrder = 0
          OnClick = btnNFC_RD_OpenScriptClick
        end
        object stNFC_RD_TargetFilePath: TStaticText
          Left = 152
          Top = 30
          Width = 377
          Height = 21
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object mmNFC_RD_DisplayResult: TMemo
          Left = 16
          Top = 96
          Width = 513
          Height = 161
          Enabled = False
          ScrollBars = ssVertical
          TabOrder = 2
        end
      end
      object gbNFCTestMode: TGroupBox
        Left = 16
        Top = 8
        Width = 545
        Height = 201
        Caption = 'NFC Test Mode'
        TabOrder = 1
        object sbNFCRawDataTestStart: TSpeedButton
          Left = 458
          Top = 19
          Width = 75
          Height = 25
          Caption = 'Start'
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
            33333333333F8888883F33330000324334222222443333388F3833333388F333
            000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
            F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
            223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
            3338888300003AAAAAAA33333333333888888833333333330000333333333333
            333333333333333333FFFFFF000033333333333344444433FFFF333333888888
            00003A444333333A22222438888F333338F3333800003A2243333333A2222438
            F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
            22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
            33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
            3333333333338888883333330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
          OnClick = sbNFCRawDataTestStartClick
        end
        object sbNFCRawDataTestStop: TSpeedButton
          Left = 458
          Top = 54
          Width = 75
          Height = 25
          Caption = 'Stop'
          Enabled = False
          Glyph.Data = {
            DE010000424DDE01000000000000760000002800000024000000120000000100
            0400000000006801000000000000000000001000000000000000000000000000
            80000080000000808000800000008000800080800000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333333FFFFF333333000033333388888833333333333F888888FFF333
            000033338811111188333333338833FFF388FF33000033381119999111833333
            38F338888F338FF30000339119933331111833338F388333383338F300003391
            13333381111833338F8F3333833F38F3000039118333381119118338F38F3338
            33F8F38F000039183333811193918338F8F333833F838F8F0000391833381119
            33918338F8F33833F8338F8F000039183381119333918338F8F3833F83338F8F
            000039183811193333918338F8F833F83333838F000039118111933339118338
            F3833F83333833830000339111193333391833338F33F8333FF838F300003391
            11833338111833338F338FFFF883F83300003339111888811183333338FF3888
            83FF83330000333399111111993333333388FFFFFF8833330000333333999999
            3333333333338888883333330000333333333333333333333333333333333333
            0000}
          NumGlyphs = 2
          OnClick = sbNFCRawDataTestStopClick
        end
        object Label11: TLabel
          Left = 8
          Top = 160
          Width = 79
          Height = 13
          Caption = 'Modulation Type'
          Layout = tlCenter
        end
        object Label12: TLabel
          Left = 416
          Top = 160
          Width = 39
          Height = 13
          Caption = 'Protocol'
          Layout = tlCenter
        end
        object Label13: TLabel
          Left = 304
          Top = 160
          Width = 24
          Height = 13
          Caption = 'Type'
          Layout = tlCenter
        end
        object Label14: TLabel
          Left = 168
          Top = 160
          Width = 35
          Height = 13
          Caption = 'BitRate'
          Layout = tlCenter
        end
        object rbNFC_Test_WithASK: TRadioButton
          Left = 8
          Top = 16
          Width = 225
          Height = 25
          Caption = 'NFC TX always on with ASK modulation'
          Checked = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = True
          OnClick = rbNFC_Test_WithASKClick
        end
        object rbNFC_Test_WithoutASK: TRadioButton
          Left = 8
          Top = 40
          Width = 225
          Height = 25
          Caption = 'NFC TX always on without ASK modulation'
          TabOrder = 1
          OnClick = rbNFC_Test_WithASKClick
        end
        object rbNFC_Test_Reader: TRadioButton
          Left = 8
          Top = 88
          Width = 225
          Height = 25
          Caption = 'Always in reader mode'
          TabOrder = 3
          OnClick = rbNFC_Test_ReaderClick
        end
        object rbNFC_Test_Peer: TRadioButton
          Left = 8
          Top = 112
          Width = 225
          Height = 25
          Caption = 'Always in peer to peer mode'
          TabOrder = 4
          OnClick = rbNFC_Test_ReaderClick
        end
        object rbNFC_Test_SWP: TRadioButton
          Left = 249
          Top = 16
          Width = 160
          Height = 25
          Caption = 'SWP self test'
          TabOrder = 5
          OnClick = rbNFC_Test_ReaderClick
        end
        object rbNFC_Test_Antenna: TRadioButton
          Left = 249
          Top = 40
          Width = 160
          Height = 25
          Caption = 'NFC antenna self test'
          TabOrder = 6
          OnClick = rbNFC_Test_ReaderClick
        end
        object rbNFC_Test_Emulation: TRadioButton
          Left = 8
          Top = 64
          Width = 225
          Height = 25
          Caption = 'Always in card emulation mode'
          TabOrder = 2
          OnClick = rbNFC_Test_EmulationClick
        end
        object rbNFC_Test_CardMode: TRadioButton
          Left = 249
          Top = 88
          Width = 160
          Height = 25
          Caption = 'NFC Card mode test'
          TabOrder = 8
          OnClick = rbNFC_Test_EmulationClick
        end
        object rbNFC_Test_UidRD: TRadioButton
          Left = 249
          Top = 64
          Width = 160
          Height = 25
          Caption = 'NFC Tag Uid read/write-RD'
          TabOrder = 7
          OnClick = rbNFC_Test_ReaderClick
        end
        object cbNFC_Raw_Modulation_Type: TComboBox
          Left = 88
          Top = 160
          Width = 73
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 9
          Text = 'type A'
          Items.Strings = (
            'type A'
            'type B'
            'type F'
            'No Modulation')
        end
        object cbNFC_Raw_BitRate: TComboBox
          Left = 216
          Top = 160
          Width = 73
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 10
          Text = '106kbps'
          Items.Strings = (
            '106kbps'
            '212kbps'
            '424kbps')
        end
        object cbNFC_Raw_Type: TComboBox
          Left = 336
          Top = 160
          Width = 73
          Height = 21
          Enabled = False
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 11
          Text = 'MifareUL'
          Items.Strings = (
            'MifareUL'
            'MifareStd'
            'ISO14443_4A'
            'ISO14443_4B'
            'Jewel'
            'Felica'
            'ISO15693')
        end
        object cbNFC_Raw_Protocol: TComboBox
          Left = 464
          Top = 160
          Width = 73
          Height = 21
          Enabled = False
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 12
          Text = 'Iso14443A'
          Items.Strings = (
            'Iso14443A'
            'Iso14443B'
            'Felica212'
            'Felica424'
            'Iso15693')
        end
      end
    end
  end
  object sbNFC: TStatusBar
    Left = 0
    Top = 548
    Width = 775
    Height = 30
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object ActionList1: TActionList
    Left = 728
    Top = 424
    object backdoor: TAction
      Caption = 'backdoor'
      ShortCut = 16452
      OnExecute = backdoorExecute
    end
    object Action1: TAction
      Caption = 'Action1'
      ShortCut = 16453
      OnExecute = Action1Execute
    end
    object Action2: TAction
      Caption = 'Action2'
      ShortCut = 16454
      OnExecute = Action2Execute
    end
    object Action3: TAction
      Caption = 'Action3'
      ShortCut = 112
      OnExecute = Action3Execute
    end
    object Action4: TAction
      Caption = 'Action4'
      ShortCut = 113
      OnExecute = Action4Execute
    end
    object Action5: TAction
      Caption = 'Action5'
      ShortCut = 114
      OnExecute = Action5Execute
    end
  end
  object dlgOpenNFCScipt: TOpenDialog
    Title = 'Open NFC Script'
    Left = 616
    Top = 352
  end
end
