object frmWiFiBBCR: TfrmWiFiBBCR
  Left = 17
  Top = 20
  Width = 976
  Height = 752
  Caption = 'Baseband Control Registers'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 953
    Height = 657
    ActivePage = tsBBPC
    TabIndex = 1
    TabOrder = 0
    object tsIPTR: TTabSheet
      Tag = 13
      Caption = 'Initialization, PHY Configuration and TX/RX'
      object Shape1: TShape
        Left = 376
        Top = 12
        Width = 9
        Height = 9
        Brush.Color = clMaroon
      end
      object Label40: TLabel
        Left = 392
        Top = 10
        Width = 48
        Height = 13
        Caption = 'Read only'
      end
      object Shape2: TShape
        Left = 488
        Top = 12
        Width = 9
        Height = 9
        Brush.Color = clGreen
      end
      object Label1: TLabel
        Left = 512
        Top = 8
        Width = 20
        Height = 13
        Caption = 'R/C'
      end
      object pnlIPCHeader: TPanel
        Left = 8
        Top = 8
        Width = 249
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Initialization and PHY-Configuration'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object cbIPCHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbIPCHeaderClick
        end
      end
      object pnlIPC: TPanel
        Left = 8
        Top = 32
        Width = 889
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 1
        object lblIPC0: TLabel
          Left = 24
          Top = 8
          Width = 39
          Height = 13
          Caption = 'DEV_ID'
          Font.Charset = ANSI_CHARSET
          Font.Color = clMaroon
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblIPCn0: TLabel
          Left = 16
          Top = 26
          Width = 6
          Height = 13
          Caption = '0'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblIPC1: TLabel
          Tag = 1
          Left = 124
          Top = 8
          Width = 53
          Height = 13
          Caption = 'IO_POLAR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblIPCn1: TLabel
          Tag = 1
          Left = 116
          Top = 26
          Width = 6
          Height = 13
          Caption = '1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblIPC2: TLabel
          Tag = 2
          Left = 224
          Top = 8
          Width = 48
          Height = 13
          Caption = 'TR_CFG1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblIPCn2: TLabel
          Tag = 2
          Left = 216
          Top = 26
          Width = 6
          Height = 13
          Caption = '2'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblIPC3: TLabel
          Tag = 3
          Left = 325
          Top = 8
          Width = 48
          Height = 13
          Caption = 'TR_CFG2'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblIPCn3: TLabel
          Tag = 3
          Left = 316
          Top = 26
          Width = 6
          Height = 13
          Caption = '3'
        end
        object lblIPC4: TLabel
          Tag = 4
          Left = 424
          Top = 8
          Width = 46
          Height = 13
          Caption = 'INT_CSR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblIPCn4: TLabel
          Tag = 4
          Left = 416
          Top = 26
          Width = 6
          Height = 13
          Caption = '4'
        end
        object edtIPC0: TEdit
          Left = 24
          Top = 24
          Width = 41
          Height = 21
          ReadOnly = True
          TabOrder = 0
          Text = '0'
          OnExit = edtIPCCheck
        end
        object edtIPC1: TEdit
          Tag = 1
          Left = 124
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtIPCCheck
        end
        object edtIPC2: TEdit
          Tag = 2
          Left = 224
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtIPCCheck
        end
        object edtIPC3: TEdit
          Tag = 3
          Left = 324
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtIPCCheck
        end
        object edtIPC4: TEdit
          Tag = 4
          Left = 424
          Top = 24
          Width = 41
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          ReadOnly = True
          TabOrder = 4
          Text = '0'
          OnExit = edtIPCCheck
        end
        object cbIPC0: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 5
          OnClick = cbIPCClick
        end
        object cbIPC1: TCheckBox
          Tag = 1
          Left = 108
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 6
          OnClick = cbIPCClick
        end
        object cbIPC2: TCheckBox
          Tag = 2
          Left = 208
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 7
          OnClick = cbIPCClick
        end
        object cbIPC3: TCheckBox
          Tag = 3
          Left = 308
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 8
          OnClick = cbIPCClick
        end
        object cbIPC4: TCheckBox
          Tag = 4
          Left = 408
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 9
          OnClick = cbIPCClick
        end
      end
      object Panel4: TPanel
        Left = 8
        Top = 96
        Width = 249
        Height = 25
        BevelOuter = bvLowered
        Caption = 'TX-related'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        object cbTXHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbTXHeaderClick
        end
      end
      object pnlTX: TPanel
        Left = 8
        Top = 120
        Width = 889
        Height = 105
        BevelOuter = bvLowered
        TabOrder = 3
        object lblTX2: TLabel
          Tag = 2
          Left = 222
          Top = 8
          Width = 53
          Height = 13
          Caption = 'TX_LEN_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTXn2: TLabel
          Tag = 2
          Left = 206
          Top = 26
          Width = 12
          Height = 13
          Caption = '10'
        end
        object lblTX3: TLabel
          Tag = 3
          Left = 322
          Top = 8
          Width = 62
          Height = 13
          Caption = 'TX_SV_O_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTXn3: TLabel
          Tag = 3
          Left = 304
          Top = 26
          Width = 12
          Height = 13
          Caption = '11'
        end
        object lblTX4: TLabel
          Tag = 4
          Left = 422
          Top = 8
          Width = 60
          Height = 13
          Caption = 'TX_SV_O_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTXn4: TLabel
          Tag = 4
          Left = 404
          Top = 26
          Width = 12
          Height = 13
          Caption = '12'
        end
        object lblTX5: TLabel
          Tag = 4
          Left = 522
          Top = 8
          Width = 61
          Height = 13
          Caption = 'TX_SV_CCK'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTXn5: TLabel
          Tag = 4
          Left = 503
          Top = 26
          Width = 12
          Height = 13
          Caption = '13'
        end
        object lblTX6: TLabel
          Tag = 5
          Left = 624
          Top = 8
          Width = 68
          Height = 13
          Caption = 'TXPWR_OFD'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTXn6: TLabel
          Tag = 5
          Left = 608
          Top = 26
          Width = 12
          Height = 13
          Caption = '14'
        end
        object lblTX7: TLabel
          Tag = 6
          Left = 723
          Top = 8
          Width = 67
          Height = 13
          Caption = 'TXPWR_CCK'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTXn7: TLabel
          Tag = 6
          Left = 709
          Top = 26
          Width = 12
          Height = 13
          Caption = '15'
        end
        object lblTXn0: TLabel
          Left = 16
          Top = 26
          Width = 6
          Height = 13
          Caption = '8'
        end
        object lblTX0: TLabel
          Left = 24
          Top = 8
          Width = 51
          Height = 13
          Caption = 'TX_STAT '
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTXn1: TLabel
          Tag = 1
          Left = 111
          Top = 26
          Width = 6
          Height = 13
          Caption = '9'
        end
        object lblTX1: TLabel
          Tag = 1
          Left = 122
          Top = 8
          Width = 55
          Height = 13
          Caption = 'TX_LEN_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTX8: TLabel
          Tag = 7
          Left = 824
          Top = 8
          Width = 54
          Height = 13
          Caption = 'PAPWR_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clMaroon
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTX9: TLabel
          Tag = 8
          Left = 24
          Top = 53
          Width = 52
          Height = 13
          Caption = 'PAPWR_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clMaroon
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblTXn8: TLabel
          Tag = 7
          Left = 808
          Top = 26
          Width = 12
          Height = 13
          Caption = '16'
        end
        object lblTXn9: TLabel
          Tag = 8
          Left = 8
          Top = 72
          Width = 12
          Height = 13
          Caption = '17'
        end
        object edtTX2: TEdit
          Tag = 2
          Left = 224
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtTXCheck
        end
        object edtTX3: TEdit
          Tag = 3
          Left = 324
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtTXCheck
        end
        object edtTX4: TEdit
          Tag = 4
          Left = 424
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtTXCheck
        end
        object edtTX5: TEdit
          Tag = 4
          Left = 524
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtTXCheck
        end
        object edtTX6: TEdit
          Tag = 5
          Left = 624
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtTXCheck
        end
        object edtTX7: TEdit
          Tag = 6
          Left = 724
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtTXCheck
        end
        object edtTX0: TEdit
          Left = 24
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtTXCheck
        end
        object edtTX1: TEdit
          Tag = 1
          Left = 124
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtTXCheck
        end
        object cbTX0: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 8
          OnClick = cbTXClick
        end
        object cbTX1: TCheckBox
          Tag = 1
          Left = 108
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 9
          OnClick = cbTXClick
        end
        object cbTX2: TCheckBox
          Tag = 2
          Left = 208
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 10
          OnClick = cbTXClick
        end
        object cbTX3: TCheckBox
          Tag = 3
          Left = 308
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 11
          OnClick = cbTXClick
        end
        object cbTX4: TCheckBox
          Tag = 4
          Left = 408
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 12
          OnClick = cbTXClick
        end
        object cbTX5: TCheckBox
          Tag = 4
          Left = 508
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 13
          OnClick = cbTXClick
        end
        object cbTX6: TCheckBox
          Tag = 5
          Left = 608
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 14
          OnClick = cbTXClick
        end
        object cbTX7: TCheckBox
          Tag = 6
          Left = 708
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 15
          OnClick = cbTXClick
        end
        object cbTX8: TCheckBox
          Tag = 7
          Left = 808
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 16
          OnClick = cbTXClick
        end
        object cbTX9: TCheckBox
          Tag = 8
          Left = 8
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 17
          OnClick = cbTXClick
        end
        object edtTX8: TEdit
          Tag = 7
          Left = 824
          Top = 24
          Width = 41
          Height = 21
          ReadOnly = True
          TabOrder = 18
          Text = '0'
          OnExit = edtTXCheck
        end
        object edtTX9: TEdit
          Tag = 8
          Left = 24
          Top = 69
          Width = 41
          Height = 21
          ReadOnly = True
          TabOrder = 19
          Text = '0'
          OnExit = edtTXCheck
        end
      end
      object pnlRXHeader: TPanel
        Left = 8
        Top = 232
        Width = 249
        Height = 25
        BevelOuter = bvLowered
        Caption = 'RX-related'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        object cbRXHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbRXHeaderClick
        end
      end
      object pnlRX: TPanel
        Tag = 13
        Left = 8
        Top = 256
        Width = 889
        Height = 105
        BevelOuter = bvLowered
        TabOrder = 5
        object lblRX00: TLabel
          Left = 24
          Top = 8
          Width = 49
          Height = 13
          Caption = 'RX_STAT'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn00: TLabel
          Left = 8
          Top = 26
          Width = 12
          Height = 13
          Caption = '24'
        end
        object lblRXn01: TLabel
          Tag = 1
          Left = 108
          Top = 26
          Width = 12
          Height = 13
          Caption = '25'
        end
        object lblRX01: TLabel
          Tag = 1
          Left = 124
          Top = 8
          Width = 56
          Height = 13
          Caption = 'RX_LEN_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRX02: TLabel
          Tag = 2
          Left = 224
          Top = 8
          Width = 54
          Height = 13
          Caption = 'RX_LEN_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn02: TLabel
          Tag = 2
          Left = 208
          Top = 26
          Width = 12
          Height = 13
          Caption = '26'
        end
        object lblRX03: TLabel
          Tag = 3
          Left = 325
          Top = 8
          Width = 57
          Height = 13
          Caption = 'RX_SVR_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn03: TLabel
          Tag = 3
          Left = 308
          Top = 26
          Width = 12
          Height = 13
          Caption = '27'
        end
        object lblRXn04: TLabel
          Tag = 4
          Left = 408
          Top = 26
          Width = 12
          Height = 13
          Caption = '28'
        end
        object lblRX04: TLabel
          Tag = 4
          Left = 426
          Top = 8
          Width = 55
          Height = 13
          Caption = 'RX_SVR_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn05: TLabel
          Tag = 5
          Left = 508
          Top = 26
          Width = 12
          Height = 13
          Caption = '29'
        end
        object lblRX05: TLabel
          Tag = 5
          Left = 526
          Top = 8
          Width = 25
          Height = 13
          Caption = 'RSSI'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRX06: TLabel
          Tag = 6
          Left = 624
          Top = 8
          Width = 34
          Height = 13
          Caption = 'SQ_B5'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn06: TLabel
          Tag = 6
          Left = 608
          Top = 26
          Width = 12
          Height = 13
          Caption = '30'
        end
        object lblRXn07: TLabel
          Tag = 7
          Left = 708
          Top = 26
          Width = 12
          Height = 13
          Caption = '31'
        end
        object lblRX07: TLabel
          Tag = 7
          Left = 724
          Top = 8
          Width = 34
          Height = 13
          Caption = 'SQ_B4'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn08: TLabel
          Tag = 8
          Left = 808
          Top = 26
          Width = 12
          Height = 13
          Caption = '32'
        end
        object lblRX08: TLabel
          Tag = 8
          Left = 824
          Top = 8
          Width = 34
          Height = 13
          Caption = 'SQ_B3'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRX09: TLabel
          Tag = 9
          Left = 24
          Top = 53
          Width = 34
          Height = 13
          Caption = 'SQ_B2'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn09: TLabel
          Tag = 9
          Left = 8
          Top = 72
          Width = 12
          Height = 13
          Caption = '33'
        end
        object lblRXn10: TLabel
          Tag = 10
          Left = 108
          Top = 72
          Width = 12
          Height = 13
          Caption = '34'
        end
        object lblRX10: TLabel
          Tag = 10
          Left = 124
          Top = 53
          Width = 34
          Height = 13
          Caption = 'SQ_B1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRX11: TLabel
          Tag = 11
          Left = 224
          Top = 53
          Width = 34
          Height = 13
          Caption = 'SQ_B0'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn11: TLabel
          Tag = 11
          Left = 208
          Top = 72
          Width = 12
          Height = 13
          Caption = '35'
        end
        object lblRXn12: TLabel
          Tag = 12
          Left = 308
          Top = 72
          Width = 12
          Height = 13
          Caption = '36'
        end
        object lblRX12: TLabel
          Tag = 12
          Left = 324
          Top = 53
          Width = 62
          Height = 13
          Caption = 'RADAR_PW'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRX13: TLabel
          Tag = 13
          Left = 424
          Top = 52
          Width = 70
          Height = 13
          Caption = 'RADAR_PWR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn13: TLabel
          Tag = 13
          Left = 408
          Top = 72
          Width = 12
          Height = 13
          Caption = '37'
        end
        object lblRX14: TLabel
          Tag = 14
          Left = 524
          Top = 52
          Width = 27
          Height = 13
          Caption = 'CR38'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblRXn14: TLabel
          Tag = 14
          Left = 508
          Top = 72
          Width = 12
          Height = 13
          Caption = '38'
        end
        object edtRX00: TEdit
          Left = 24
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX01: TEdit
          Tag = 1
          Left = 124
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX02: TEdit
          Tag = 2
          Left = 224
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX03: TEdit
          Tag = 3
          Left = 324
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX04: TEdit
          Tag = 4
          Left = 424
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX05: TEdit
          Tag = 5
          Left = 524
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX06: TEdit
          Tag = 6
          Left = 624
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX07: TEdit
          Tag = 7
          Left = 724
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX08: TEdit
          Tag = 8
          Left = 824
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 8
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX09: TEdit
          Tag = 9
          Left = 24
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 9
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX10: TEdit
          Tag = 10
          Left = 124
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 10
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX11: TEdit
          Tag = 11
          Left = 224
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 11
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX12: TEdit
          Tag = 12
          Left = 324
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 12
          Text = '0'
          OnExit = edtRXCheck
        end
        object cbRX00: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 13
          OnClick = cbRXClick
        end
        object cbRX01: TCheckBox
          Tag = 1
          Left = 108
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 14
          OnClick = cbRXClick
        end
        object cbRX02: TCheckBox
          Tag = 2
          Left = 208
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 15
          OnClick = cbRXClick
        end
        object cbRX03: TCheckBox
          Tag = 3
          Left = 308
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 16
          OnClick = cbRXClick
        end
        object cbRX04: TCheckBox
          Tag = 4
          Left = 408
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 17
          OnClick = cbRXClick
        end
        object cbRX05: TCheckBox
          Tag = 5
          Left = 508
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 18
          OnClick = cbRXClick
        end
        object cbRX06: TCheckBox
          Tag = 6
          Left = 608
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 19
          OnClick = cbRXClick
        end
        object cbRX07: TCheckBox
          Tag = 7
          Left = 708
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 20
          OnClick = cbRXClick
        end
        object cbRX08: TCheckBox
          Tag = 8
          Left = 808
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 21
          OnClick = cbRXClick
        end
        object cbRX09: TCheckBox
          Tag = 9
          Left = 8
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 22
          OnClick = cbRXClick
        end
        object cbRX10: TCheckBox
          Tag = 10
          Left = 108
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 23
          OnClick = cbRXClick
        end
        object cbRX11: TCheckBox
          Tag = 11
          Left = 208
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 24
          OnClick = cbRXClick
        end
        object cbRX12: TCheckBox
          Tag = 12
          Left = 308
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 25
          OnClick = cbRXClick
        end
        object edtRX13: TEdit
          Tag = 13
          Left = 424
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 26
          Text = '0'
          OnExit = edtRXCheck
        end
        object edtRX14: TEdit
          Tag = 14
          Left = 524
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 27
          Text = '0'
          OnExit = edtRXCheck
        end
        object cbRX13: TCheckBox
          Tag = 13
          Left = 408
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 28
          OnClick = cbRXClick
        end
        object cbRX14: TCheckBox
          Tag = 14
          Left = 508
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 29
          OnClick = cbRXClick
        end
      end
      object btnIPTRBBCRData: TButton
        Tag = 1
        Left = 270
        Top = 2
        Width = 89
        Height = 23
        Caption = 'BBCR Data (Hex)'
        TabOrder = 6
        OnClick = btnIPTRBBCRDataClick
      end
    end
    object tsBBPC: TTabSheet
      Caption = 'BBP Configuration'
      ImageIndex = 1
      object Shape3: TShape
        Left = 376
        Top = 12
        Width = 9
        Height = 9
        Brush.Color = clMaroon
      end
      object Label2: TLabel
        Left = 392
        Top = 10
        Width = 48
        Height = 13
        Caption = 'Read only'
      end
      object Shape4: TShape
        Left = 488
        Top = 12
        Width = 9
        Height = 9
        Brush.Color = clGreen
      end
      object Label3: TLabel
        Left = 512
        Top = 8
        Width = 20
        Height = 13
        Caption = 'R/C'
      end
      object pnlBBPCHeader: TPanel
        Left = 8
        Top = 8
        Width = 249
        Height = 25
        BevelOuter = bvLowered
        Caption = 'BBP Configuration'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object cbBBPCHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbBBPCHeaderClick
        end
      end
      object Panel9: TPanel
        Left = 8
        Top = 32
        Width = 929
        Height = 593
        BevelOuter = bvLowered
        TabOrder = 1
        object lblBBPC000: TLabel
          Left = 24
          Top = 8
          Width = 86
          Height = 13
          Caption = 'ODTX_BF_ADDR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Microsoft Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn000: TLabel
          Left = 9
          Top = 28
          Width = 12
          Height = 13
          Caption = '39'
        end
        object lblBBPC001: TLabel
          Tag = 1
          Left = 181
          Top = 8
          Width = 84
          Height = 13
          Caption = 'ODTX_BF_DATA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Microsoft Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn001: TLabel
          Tag = 1
          Left = 166
          Top = 28
          Width = 12
          Height = 13
          Caption = '40'
        end
        object lblBBPCn002: TLabel
          Tag = 2
          Left = 324
          Top = 28
          Width = 12
          Height = 13
          Caption = '41'
        end
        object lblBBPC002: TLabel
          Tag = 2
          Left = 339
          Top = 8
          Width = 86
          Height = 13
          Caption = 'ODTX_FT_ADDR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Microsoft Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn003: TLabel
          Tag = 3
          Left = 481
          Top = 28
          Width = 12
          Height = 13
          Caption = '42'
        end
        object lblBBPC003: TLabel
          Tag = 3
          Left = 496
          Top = 8
          Width = 84
          Height = 13
          Caption = 'ODTX_FT_DATA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Microsoft Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn004: TLabel
          Tag = 4
          Left = 639
          Top = 28
          Width = 12
          Height = 13
          Caption = '43'
        end
        object lblBBPC004: TLabel
          Tag = 4
          Left = 654
          Top = 8
          Width = 84
          Height = 13
          Caption = 'CCKTX_F_ADDR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn005: TLabel
          Tag = 5
          Left = 797
          Top = 28
          Width = 12
          Height = 13
          Caption = '44'
        end
        object lblBBPC005: TLabel
          Tag = 5
          Left = 812
          Top = 8
          Width = 82
          Height = 13
          Caption = 'CCKTX_F_DATA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn006: TLabel
          Tag = 6
          Left = 9
          Top = 73
          Width = 12
          Height = 13
          Caption = '45'
        end
        object lblBBPC006: TLabel
          Tag = 6
          Left = 24
          Top = 53
          Width = 59
          Height = 13
          Caption = 'AGC_ADDR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn007: TLabel
          Tag = 7
          Left = 166
          Top = 73
          Width = 12
          Height = 13
          Caption = '46'
        end
        object lblBBPC007: TLabel
          Tag = 7
          Left = 181
          Top = 53
          Width = 57
          Height = 13
          Caption = 'AGC_DATA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn008: TLabel
          Tag = 8
          Left = 324
          Top = 73
          Width = 12
          Height = 13
          Caption = '47'
        end
        object lblBBPC008: TLabel
          Tag = 8
          Left = 339
          Top = 53
          Width = 89
          Height = 13
          Caption = 'OFDM_TR_ADDR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn009: TLabel
          Tag = 9
          Left = 481
          Top = 73
          Width = 12
          Height = 13
          Caption = '48'
        end
        object lblBBPC009: TLabel
          Tag = 9
          Left = 496
          Top = 53
          Width = 87
          Height = 13
          Caption = 'OFDM_TR_DATA'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn010: TLabel
          Tag = 10
          Left = 639
          Top = 73
          Width = 12
          Height = 13
          Caption = '49'
        end
        object lblBBPC010: TLabel
          Tag = 10
          Left = 654
          Top = 53
          Width = 54
          Height = 13
          Caption = 'CCK_SQ_1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC011: TLabel
          Tag = 11
          Left = 812
          Top = 53
          Width = 54
          Height = 13
          Caption = 'CCK_SQ_2'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn011: TLabel
          Tag = 11
          Left = 797
          Top = 73
          Width = 12
          Height = 13
          Caption = '50'
        end
        object lblBBPCn012: TLabel
          Tag = 12
          Left = 9
          Top = 118
          Width = 12
          Height = 13
          Caption = '56'
        end
        object lblBBPC012: TLabel
          Tag = 12
          Left = 24
          Top = 98
          Width = 65
          Height = 13
          Caption = 'CCK_CE_TH '
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC013: TLabel
          Tag = 13
          Left = 181
          Top = 98
          Width = 63
          Height = 13
          Caption = 'CCK_L_PRM'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn013: TLabel
          Tag = 13
          Left = 166
          Top = 118
          Width = 12
          Height = 13
          Caption = '59'
        end
        object lblBBPC014: TLabel
          Tag = 14
          Left = 339
          Top = 98
          Width = 64
          Height = 13
          Caption = 'CCK_S_PRM'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn014: TLabel
          Tag = 14
          Left = 324
          Top = 118
          Width = 12
          Height = 13
          Caption = '60'
        end
        object lblBBPCn015: TLabel
          Tag = 15
          Left = 481
          Top = 118
          Width = 12
          Height = 13
          Caption = '61'
        end
        object lblBBPC015: TLabel
          Tag = 15
          Left = 496
          Top = 98
          Width = 99
          Height = 13
          Caption = 'CCK_PREAMB_LEN'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC016: TLabel
          Tag = 16
          Left = 654
          Top = 98
          Width = 65
          Height = 13
          Caption = 'CCK_MISC_1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn016: TLabel
          Tag = 16
          Left = 639
          Top = 118
          Width = 12
          Height = 13
          Caption = '62'
        end
        object lblBBPCn017: TLabel
          Tag = 17
          Left = 797
          Top = 118
          Width = 12
          Height = 13
          Caption = '63'
        end
        object lblBBPC017: TLabel
          Tag = 17
          Left = 812
          Top = 98
          Width = 65
          Height = 13
          Caption = 'CCK_MISC_2'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC018: TLabel
          Tag = 18
          Left = 24
          Top = 143
          Width = 65
          Height = 13
          Caption = 'CCK_MISC_3'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn018: TLabel
          Tag = 18
          Left = 9
          Top = 163
          Width = 12
          Height = 13
          Caption = '64'
        end
        object lblBBPC019: TLabel
          Tag = 19
          Left = 181
          Top = 143
          Width = 86
          Height = 13
          Caption = 'MPDU_ANT_CTL'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn019: TLabel
          Tag = 19
          Left = 166
          Top = 163
          Width = 12
          Height = 13
          Caption = '68'
        end
        object lblBBPC020: TLabel
          Tag = 20
          Left = 339
          Top = 143
          Width = 90
          Height = 13
          Caption = 'MPDU_ANT_TMO'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn020: TLabel
          Tag = 20
          Left = 324
          Top = 163
          Width = 12
          Height = 13
          Caption = '69'
        end
        object lblBBPC021: TLabel
          Tag = 21
          Left = 496
          Top = 143
          Width = 64
          Height = 13
          Caption = 'AP_ADDRB5'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn021: TLabel
          Tag = 21
          Left = 481
          Top = 163
          Width = 12
          Height = 13
          Caption = '70'
        end
        object lblBBPCn022: TLabel
          Tag = 22
          Left = 639
          Top = 163
          Width = 12
          Height = 13
          Caption = '71'
        end
        object lblBBPC022: TLabel
          Tag = 22
          Left = 654
          Top = 143
          Width = 64
          Height = 13
          Caption = 'AP_ADDRB4'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn023: TLabel
          Tag = 23
          Left = 797
          Top = 163
          Width = 12
          Height = 13
          Caption = '72'
        end
        object lblBBPC023: TLabel
          Tag = 23
          Left = 812
          Top = 143
          Width = 64
          Height = 13
          Caption = 'AP_ADDRB3'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC024: TLabel
          Tag = 24
          Left = 24
          Top = 188
          Width = 64
          Height = 13
          Caption = 'AP_ADDRB2'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn024: TLabel
          Tag = 24
          Left = 9
          Top = 208
          Width = 12
          Height = 13
          Caption = '73'
        end
        object lblBBPC025: TLabel
          Tag = 25
          Left = 181
          Top = 188
          Width = 64
          Height = 13
          Caption = 'AP_ADDRB1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn025: TLabel
          Tag = 25
          Left = 166
          Top = 208
          Width = 12
          Height = 13
          Caption = '74'
        end
        object lblBBPCn026: TLabel
          Tag = 26
          Left = 324
          Top = 208
          Width = 12
          Height = 13
          Caption = '75'
        end
        object lblBBPC026: TLabel
          Tag = 26
          Left = 339
          Top = 188
          Width = 64
          Height = 13
          Caption = 'AP_ADDRB0'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn027: TLabel
          Tag = 27
          Left = 481
          Top = 208
          Width = 12
          Height = 13
          Caption = '76'
        end
        object lblBBPC027: TLabel
          Tag = 27
          Left = 496
          Top = 188
          Width = 95
          Height = 13
          Caption = 'OFDM_MISC1_CTL'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC028: TLabel
          Tag = 28
          Left = 654
          Top = 188
          Width = 95
          Height = 13
          Caption = 'OFDM_MISC2_CTL'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn028: TLabel
          Tag = 28
          Left = 639
          Top = 208
          Width = 12
          Height = 13
          Caption = '77'
        end
        object lblBBPC029: TLabel
          Tag = 29
          Left = 812
          Top = 188
          Width = 103
          Height = 13
          Caption = 'OFDM_ACQ_SHORT'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn029: TLabel
          Tag = 29
          Left = 797
          Top = 208
          Width = 12
          Height = 13
          Caption = '78'
        end
        object lblBBPCn030: TLabel
          Tag = 30
          Left = 9
          Top = 253
          Width = 12
          Height = 13
          Caption = '79'
        end
        object lblBBPC030: TLabel
          Tag = 30
          Left = 24
          Top = 233
          Width = 95
          Height = 13
          Caption = 'OFDM_ACQ_LONG'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC031: TLabel
          Tag = 31
          Left = 181
          Top = 233
          Width = 67
          Height = 13
          Caption = 'AFEBandGAP'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -9
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn031: TLabel
          Tag = 31
          Left = 166
          Top = 253
          Width = 12
          Height = 13
          Caption = '81'
        end
        object lblBBPC032: TLabel
          Tag = 32
          Left = 339
          Top = 233
          Width = 85
          Height = 13
          Caption = 'AFEPowerDOWN'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn032: TLabel
          Tag = 32
          Left = 324
          Top = 253
          Width = 12
          Height = 13
          Caption = '82'
        end
        object lblBBPCn033: TLabel
          Tag = 33
          Left = 481
          Top = 253
          Width = 12
          Height = 13
          Caption = '83'
        end
        object lblBBPC033: TLabel
          Tag = 33
          Left = 496
          Top = 233
          Width = 60
          Height = 13
          Caption = 'AFETx_DAC'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn034: TLabel
          Tag = 34
          Left = 639
          Top = 253
          Width = 12
          Height = 13
          Caption = '84'
        end
        object lblBBPC034: TLabel
          Tag = 34
          Left = 654
          Top = 233
          Width = 60
          Height = 13
          Caption = 'AFETx_DAC'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn035: TLabel
          Tag = 35
          Left = 797
          Top = 253
          Width = 12
          Height = 13
          Caption = '85'
        end
        object lblBBPC035: TLabel
          Tag = 35
          Left = 812
          Top = 233
          Width = 80
          Height = 13
          Caption = 'AFETx_DAC_FD'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC036: TLabel
          Tag = 36
          Left = 24
          Top = 278
          Width = 65
          Height = 13
          Caption = 'Test_MODE1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn036: TLabel
          Tag = 36
          Left = 9
          Top = 298
          Width = 12
          Height = 13
          Caption = '88'
        end
        object lblBBPC037: TLabel
          Tag = 37
          Left = 181
          Top = 278
          Width = 65
          Height = 13
          Caption = 'Test_MODE2'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn037: TLabel
          Tag = 37
          Left = 166
          Top = 298
          Width = 12
          Height = 13
          Caption = '89'
        end
        object lblBBPC038: TLabel
          Tag = 38
          Left = 339
          Top = 278
          Width = 65
          Height = 13
          Caption = 'Test_MODE3'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn038: TLabel
          Tag = 38
          Left = 324
          Top = 298
          Width = 12
          Height = 13
          Caption = '90'
        end
        object lblBBPCn039: TLabel
          Tag = 39
          Left = 481
          Top = 298
          Width = 12
          Height = 13
          Caption = '91'
        end
        object lblBBPC039: TLabel
          Tag = 39
          Left = 496
          Top = 278
          Width = 65
          Height = 13
          Caption = 'Test_MODE4'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC040: TLabel
          Tag = 40
          Left = 654
          Top = 278
          Width = 67
          Height = 13
          Caption = 'AFE_Rx_ADC'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn040: TLabel
          Tag = 40
          Left = 639
          Top = 298
          Width = 12
          Height = 13
          Caption = '92'
        end
        object lblBBPCn041: TLabel
          Tag = 41
          Left = 797
          Top = 298
          Width = 12
          Height = 13
          Caption = '93'
        end
        object lblBBPC041: TLabel
          Tag = 41
          Left = 812
          Top = 278
          Width = 67
          Height = 13
          Caption = 'AFE_Rx_ADC'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn042: TLabel
          Tag = 42
          Left = 9
          Top = 343
          Width = 12
          Height = 13
          Caption = '94'
        end
        object lblBBPC042: TLabel
          Tag = 42
          Left = 24
          Top = 323
          Width = 48
          Height = 13
          Caption = 'AFE_ADC'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn043: TLabel
          Tag = 43
          Left = 166
          Top = 343
          Width = 12
          Height = 13
          Caption = '95'
        end
        object lblBBPC043: TLabel
          Tag = 43
          Left = 181
          Top = 323
          Width = 74
          Height = 13
          Caption = 'AFE_ALC_ADC'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn044: TLabel
          Tag = 44
          Left = 324
          Top = 343
          Width = 12
          Height = 13
          Caption = '96'
        end
        object lblBBPC044: TLabel
          Tag = 44
          Left = 339
          Top = 323
          Width = 74
          Height = 13
          Caption = 'AFE_ALC_ADC'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn045: TLabel
          Tag = 45
          Left = 481
          Top = 343
          Width = 12
          Height = 13
          Caption = '97'
        end
        object lblBBPC045: TLabel
          Tag = 45
          Left = 496
          Top = 323
          Width = 56
          Height = 13
          Caption = 'CNTR_CTL'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn046: TLabel
          Tag = 46
          Left = 639
          Top = 343
          Width = 12
          Height = 13
          Caption = '98'
        end
        object lblBBPC046: TLabel
          Tag = 46
          Left = 654
          Top = 323
          Width = 77
          Height = 13
          Caption = 'N_ED_PASS_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn047: TLabel
          Tag = 47
          Left = 797
          Top = 343
          Width = 12
          Height = 13
          Caption = '99'
        end
        object lblBBPC047: TLabel
          Tag = 47
          Left = 812
          Top = 323
          Width = 75
          Height = 13
          Caption = 'N_ED_PASS_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC048: TLabel
          Tag = 48
          Left = 24
          Top = 368
          Width = 85
          Height = 13
          Caption = 'N_OSD_PASS_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn048: TLabel
          Tag = 48
          Left = 3
          Top = 388
          Width = 18
          Height = 13
          Caption = '100'
        end
        object lblBBPCn049: TLabel
          Tag = 49
          Left = 160
          Top = 388
          Width = 18
          Height = 13
          Caption = '101'
        end
        object lblBBPC049: TLabel
          Tag = 49
          Left = 181
          Top = 368
          Width = 83
          Height = 13
          Caption = 'N_OSD_PASS_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC050: TLabel
          Tag = 50
          Left = 339
          Top = 368
          Width = 90
          Height = 13
          Caption = 'N_mdrdy_PASS_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn050: TLabel
          Tag = 50
          Left = 318
          Top = 388
          Width = 18
          Height = 13
          Caption = '102'
        end
        object lblBBPC051: TLabel
          Tag = 51
          Left = 496
          Top = 368
          Width = 88
          Height = 13
          Caption = 'N_mdrdy_PASS_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn051: TLabel
          Tag = 51
          Left = 475
          Top = 388
          Width = 18
          Height = 13
          Caption = '103'
        end
        object lblBBPC052: TLabel
          Tag = 52
          Left = 654
          Top = 368
          Width = 83
          Height = 13
          Caption = 'N_SQ1_PASS_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn052: TLabel
          Tag = 52
          Left = 633
          Top = 388
          Width = 18
          Height = 13
          Caption = '104'
        end
        object lblBBPCn053: TLabel
          Tag = 53
          Left = 791
          Top = 388
          Width = 18
          Height = 13
          Caption = '105'
        end
        object lblBBPC053: TLabel
          Tag = 53
          Left = 812
          Top = 368
          Width = 81
          Height = 13
          Caption = 'N_SQ1_PASS_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn054: TLabel
          Tag = 54
          Left = 3
          Top = 433
          Width = 18
          Height = 13
          Caption = '106'
        end
        object lblBBPC054: TLabel
          Tag = 54
          Left = 24
          Top = 413
          Width = 82
          Height = 13
          Caption = 'RxADCI_prob_O '
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn055: TLabel
          Tag = 55
          Left = 160
          Top = 433
          Width = 18
          Height = 13
          Caption = '107'
        end
        object lblBBPC055: TLabel
          Tag = 55
          Left = 181
          Top = 413
          Width = 84
          Height = 13
          Caption = 'RxADCQ_prob_O'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC056: TLabel
          Tag = 56
          Left = 339
          Top = 413
          Width = 96
          Height = 13
          Caption = 'N_CRC16_PASS_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn056: TLabel
          Tag = 56
          Left = 318
          Top = 433
          Width = 18
          Height = 13
          Caption = '108'
        end
        object lblBBPCn057: TLabel
          Tag = 57
          Left = 475
          Top = 433
          Width = 18
          Height = 13
          Caption = '109'
        end
        object lblBBPC057: TLabel
          Tag = 57
          Left = 496
          Top = 413
          Width = 94
          Height = 13
          Caption = 'N_CRC16_PASS_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC058: TLabel
          Tag = 58
          Left = 654
          Top = 413
          Width = 110
          Height = 13
          Caption = 'N_CCK_SFD_PASS_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn058: TLabel
          Tag = 58
          Left = 633
          Top = 433
          Width = 18
          Height = 13
          Caption = '110'
        end
        object lblBBPCn059: TLabel
          Tag = 59
          Left = 791
          Top = 433
          Width = 18
          Height = 13
          Caption = '111'
        end
        object lblBBPC059: TLabel
          Tag = 59
          Left = 812
          Top = 413
          Width = 108
          Height = 13
          Caption = 'N_CCK_SFD_PASS_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn060: TLabel
          Tag = 60
          Left = 3
          Top = 478
          Width = 18
          Height = 13
          Caption = '112'
        end
        object lblBBPC060: TLabel
          Tag = 60
          Left = 24
          Top = 458
          Width = 109
          Height = 13
          Caption = 'N_CCK_FCS_PASS_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn061: TLabel
          Tag = 61
          Left = 160
          Top = 478
          Width = 18
          Height = 13
          Caption = '113'
        end
        object lblBBPC061: TLabel
          Tag = 61
          Left = 181
          Top = 458
          Width = 107
          Height = 13
          Caption = 'N_CCK_FCS_PASS_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn062: TLabel
          Tag = 62
          Left = 318
          Top = 478
          Width = 18
          Height = 13
          Caption = '114'
        end
        object lblBBPC062: TLabel
          Tag = 62
          Left = 339
          Top = 458
          Width = 67
          Height = 13
          Caption = 'Noise_floor_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn063: TLabel
          Tag = 63
          Left = 475
          Top = 478
          Width = 18
          Height = 13
          Caption = '115'
        end
        object lblBBPC063: TLabel
          Tag = 63
          Left = 496
          Top = 458
          Width = 65
          Height = 13
          Caption = 'Noise_floor_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC064: TLabel
          Tag = 64
          Left = 654
          Top = 458
          Width = 83
          Height = 13
          Caption = 'Instant_Rx_PWR'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn064: TLabel
          Tag = 64
          Left = 633
          Top = 478
          Width = 18
          Height = 13
          Caption = '116'
        end
        object lblBBPC065: TLabel
          Tag = 65
          Left = 812
          Top = 458
          Width = 114
          Height = 13
          Caption = 'CCK_CMF_ERR_RDBK'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn065: TLabel
          Tag = 65
          Left = 791
          Top = 478
          Width = 18
          Height = 13
          Caption = '117'
        end
        object lblBBPC066: TLabel
          Tag = 66
          Left = 24
          Top = 503
          Width = 101
          Height = 13
          Caption = 'PostAGC_ACCUM_H'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn066: TLabel
          Tag = 66
          Left = 3
          Top = 523
          Width = 18
          Height = 13
          Caption = '118'
        end
        object lblBBPCn067: TLabel
          Tag = 67
          Left = 160
          Top = 523
          Width = 18
          Height = 13
          Caption = '119'
        end
        object lblBBPC067: TLabel
          Tag = 67
          Left = 181
          Top = 503
          Width = 99
          Height = 13
          Caption = 'PostAGC_ACCUM_L'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC073: TLabel
          Tag = 73
          Left = 181
          Top = 548
          Width = 67
          Height = 13
          Caption = 'RDD_Counter'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn073: TLabel
          Tag = 73
          Left = 160
          Top = 568
          Width = 18
          Height = 13
          Caption = '125'
        end
        object lblBBPC072: TLabel
          Tag = 72
          Left = 24
          Top = 548
          Width = 68
          Height = 13
          Caption = 'RPI_TH_Data'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn072: TLabel
          Tag = 72
          Left = 3
          Top = 568
          Width = 18
          Height = 13
          Caption = '124'
        end
        object lblBBPCn071: TLabel
          Tag = 71
          Left = 791
          Top = 523
          Width = 18
          Height = 13
          Caption = '123'
        end
        object lblBBPC071: TLabel
          Tag = 71
          Left = 812
          Top = 503
          Width = 67
          Height = 13
          Caption = 'RPI_TH_Addr'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC070: TLabel
          Tag = 70
          Left = 654
          Top = 503
          Width = 73
          Height = 13
          Caption = 'RPI_CTL_REG'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn070: TLabel
          Tag = 70
          Left = 633
          Top = 523
          Width = 18
          Height = 13
          Caption = '122'
        end
        object lblBBPCn069: TLabel
          Tag = 69
          Left = 475
          Top = 523
          Width = 18
          Height = 13
          Caption = '121'
        end
        object lblBBPC069: TLabel
          Tag = 69
          Left = 496
          Top = 503
          Width = 92
          Height = 13
          Caption = 'RPI_CNT_L_BYTE'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPC068: TLabel
          Tag = 68
          Left = 339
          Top = 503
          Width = 94
          Height = 13
          Caption = 'RPI_CNT_H_BYTE'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblBBPCn068: TLabel
          Tag = 68
          Left = 318
          Top = 523
          Width = 18
          Height = 13
          Caption = '120'
        end
        object cbBBPC004: TCheckBox
          Tag = 4
          Left = 638
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbBBPCClick
        end
        object cbBBPC005: TCheckBox
          Tag = 5
          Left = 796
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 1
          OnClick = cbBBPCClick
        end
        object cbBBPC006: TCheckBox
          Tag = 6
          Left = 8
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 2
          OnClick = cbBBPCClick
        end
        object cbBBPC007: TCheckBox
          Tag = 7
          Left = 165
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 3
          OnClick = cbBBPCClick
        end
        object edtBBPC000: TEdit
          Left = 24
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC001: TEdit
          Tag = 1
          Left = 181
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC002: TEdit
          Tag = 2
          Left = 339
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC003: TEdit
          Tag = 3
          Left = 496
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC004: TEdit
          Tag = 4
          Left = 654
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 8
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC005: TEdit
          Tag = 5
          Left = 812
          Top = 24
          Width = 41
          Height = 21
          TabOrder = 9
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC006: TEdit
          Tag = 6
          Left = 24
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 10
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC007: TEdit
          Tag = 7
          Left = 181
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 11
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC008: TEdit
          Tag = 8
          Left = 339
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 12
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC009: TEdit
          Tag = 9
          Left = 496
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 13
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC010: TEdit
          Tag = 10
          Left = 654
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 14
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC000: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 15
          OnClick = cbBBPCClick
        end
        object cbBBPC001: TCheckBox
          Tag = 1
          Left = 165
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 16
          OnClick = cbBBPCClick
        end
        object cbBBPC002: TCheckBox
          Tag = 2
          Left = 323
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 17
          OnClick = cbBBPCClick
        end
        object cbBBPC003: TCheckBox
          Tag = 3
          Left = 480
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 18
          OnClick = cbBBPCClick
        end
        object cbBBPC010: TCheckBox
          Tag = 10
          Left = 638
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 19
          OnClick = cbBBPCClick
        end
        object cbBBPC009: TCheckBox
          Tag = 9
          Left = 480
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 20
          OnClick = cbBBPCClick
        end
        object cbBBPC008: TCheckBox
          Tag = 8
          Left = 323
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 21
          OnClick = cbBBPCClick
        end
        object edtBBPC011: TEdit
          Tag = 11
          Left = 812
          Top = 69
          Width = 41
          Height = 21
          TabOrder = 22
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC012: TEdit
          Tag = 12
          Left = 24
          Top = 114
          Width = 41
          Height = 21
          TabOrder = 23
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC013: TEdit
          Tag = 13
          Left = 181
          Top = 114
          Width = 41
          Height = 21
          TabOrder = 24
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC014: TEdit
          Tag = 14
          Left = 339
          Top = 114
          Width = 41
          Height = 21
          TabOrder = 25
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC015: TEdit
          Tag = 15
          Left = 496
          Top = 114
          Width = 41
          Height = 21
          TabOrder = 26
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC011: TCheckBox
          Tag = 11
          Left = 796
          Top = 51
          Width = 15
          Height = 17
          TabOrder = 27
          OnClick = cbBBPCClick
        end
        object cbBBPC012: TCheckBox
          Tag = 12
          Left = 8
          Top = 96
          Width = 15
          Height = 17
          TabOrder = 28
          OnClick = cbBBPCClick
        end
        object cbBBPC013: TCheckBox
          Tag = 13
          Left = 165
          Top = 96
          Width = 15
          Height = 17
          TabOrder = 29
          OnClick = cbBBPCClick
        end
        object cbBBPC014: TCheckBox
          Tag = 14
          Left = 323
          Top = 96
          Width = 15
          Height = 17
          TabOrder = 30
          OnClick = cbBBPCClick
        end
        object cbBBPC015: TCheckBox
          Tag = 15
          Left = 480
          Top = 96
          Width = 15
          Height = 17
          TabOrder = 31
          OnClick = cbBBPCClick
        end
        object edtBBPC016: TEdit
          Tag = 16
          Left = 654
          Top = 114
          Width = 41
          Height = 21
          TabOrder = 32
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC017: TEdit
          Tag = 17
          Left = 812
          Top = 114
          Width = 41
          Height = 21
          TabOrder = 33
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC018: TEdit
          Tag = 18
          Left = 24
          Top = 159
          Width = 41
          Height = 21
          TabOrder = 34
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC016: TCheckBox
          Tag = 16
          Left = 638
          Top = 96
          Width = 15
          Height = 17
          TabOrder = 35
          OnClick = cbBBPCClick
        end
        object cbBBPC017: TCheckBox
          Tag = 17
          Left = 796
          Top = 96
          Width = 15
          Height = 17
          TabOrder = 36
          OnClick = cbBBPCClick
        end
        object cbBBPC018: TCheckBox
          Tag = 18
          Left = 8
          Top = 141
          Width = 15
          Height = 17
          TabOrder = 37
          OnClick = cbBBPCClick
        end
        object edtBBPC019: TEdit
          Tag = 19
          Left = 181
          Top = 159
          Width = 41
          Height = 21
          TabOrder = 38
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC020: TEdit
          Tag = 20
          Left = 339
          Top = 159
          Width = 41
          Height = 21
          TabOrder = 39
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC021: TEdit
          Tag = 21
          Left = 496
          Top = 159
          Width = 41
          Height = 21
          TabOrder = 40
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC022: TEdit
          Tag = 22
          Left = 654
          Top = 159
          Width = 41
          Height = 21
          TabOrder = 41
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC023: TEdit
          Tag = 23
          Left = 812
          Top = 159
          Width = 41
          Height = 21
          TabOrder = 42
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC019: TCheckBox
          Tag = 19
          Left = 165
          Top = 141
          Width = 15
          Height = 17
          TabOrder = 43
          OnClick = cbBBPCClick
        end
        object cbBBPC020: TCheckBox
          Tag = 20
          Left = 323
          Top = 141
          Width = 15
          Height = 17
          TabOrder = 44
          OnClick = cbBBPCClick
        end
        object cbBBPC021: TCheckBox
          Tag = 21
          Left = 480
          Top = 141
          Width = 15
          Height = 17
          TabOrder = 45
          OnClick = cbBBPCClick
        end
        object cbBBPC022: TCheckBox
          Tag = 22
          Left = 638
          Top = 141
          Width = 15
          Height = 17
          TabOrder = 46
          OnClick = cbBBPCClick
        end
        object cbBBPC023: TCheckBox
          Tag = 23
          Left = 796
          Top = 141
          Width = 15
          Height = 17
          TabOrder = 47
          OnClick = cbBBPCClick
        end
        object edtBBPC024: TEdit
          Tag = 24
          Left = 24
          Top = 204
          Width = 41
          Height = 21
          TabOrder = 48
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC025: TEdit
          Tag = 25
          Left = 181
          Top = 204
          Width = 41
          Height = 21
          TabOrder = 49
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC026: TEdit
          Tag = 26
          Left = 339
          Top = 204
          Width = 41
          Height = 21
          TabOrder = 50
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC027: TEdit
          Tag = 27
          Left = 496
          Top = 204
          Width = 41
          Height = 21
          TabOrder = 51
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC028: TEdit
          Tag = 28
          Left = 654
          Top = 204
          Width = 41
          Height = 21
          TabOrder = 52
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC029: TEdit
          Tag = 29
          Left = 812
          Top = 204
          Width = 41
          Height = 21
          TabOrder = 53
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC030: TEdit
          Tag = 30
          Left = 24
          Top = 249
          Width = 41
          Height = 21
          TabOrder = 54
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC024: TCheckBox
          Tag = 24
          Left = 8
          Top = 186
          Width = 15
          Height = 17
          Caption = '1'
          TabOrder = 55
          OnClick = cbBBPCClick
        end
        object cbBBPC025: TCheckBox
          Tag = 25
          Left = 165
          Top = 186
          Width = 15
          Height = 17
          Caption = '1'
          TabOrder = 56
          OnClick = cbBBPCClick
        end
        object cbBBPC026: TCheckBox
          Tag = 26
          Left = 323
          Top = 186
          Width = 15
          Height = 17
          Caption = '1'
          TabOrder = 57
          OnClick = cbBBPCClick
        end
        object cbBBPC027: TCheckBox
          Tag = 27
          Left = 480
          Top = 186
          Width = 15
          Height = 17
          Caption = '1'
          TabOrder = 58
          OnClick = cbBBPCClick
        end
        object cbBBPC028: TCheckBox
          Tag = 28
          Left = 638
          Top = 186
          Width = 15
          Height = 17
          Caption = '1'
          TabOrder = 59
          OnClick = cbBBPCClick
        end
        object cbBBPC029: TCheckBox
          Tag = 29
          Left = 796
          Top = 186
          Width = 15
          Height = 17
          Caption = '1'
          TabOrder = 60
          OnClick = cbBBPCClick
        end
        object cbBBPC030: TCheckBox
          Tag = 30
          Left = 8
          Top = 231
          Width = 15
          Height = 17
          Caption = '1'
          TabOrder = 61
          OnClick = cbBBPCClick
        end
        object edtBBPC031: TEdit
          Tag = 31
          Left = 181
          Top = 249
          Width = 41
          Height = 21
          TabOrder = 62
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC031: TCheckBox
          Tag = 31
          Left = 165
          Top = 231
          Width = 15
          Height = 17
          TabOrder = 63
          OnClick = cbBBPCClick
        end
        object edtBBPC032: TEdit
          Tag = 32
          Left = 339
          Top = 249
          Width = 41
          Height = 21
          TabOrder = 64
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC033: TEdit
          Tag = 33
          Left = 496
          Top = 249
          Width = 41
          Height = 21
          TabOrder = 65
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC034: TEdit
          Tag = 34
          Left = 654
          Top = 249
          Width = 41
          Height = 21
          TabOrder = 66
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC035: TEdit
          Tag = 35
          Left = 812
          Top = 249
          Width = 41
          Height = 21
          TabOrder = 67
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC036: TEdit
          Tag = 36
          Left = 24
          Top = 294
          Width = 41
          Height = 21
          TabOrder = 68
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC037: TEdit
          Tag = 37
          Left = 181
          Top = 294
          Width = 41
          Height = 21
          TabOrder = 69
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC038: TEdit
          Tag = 38
          Left = 339
          Top = 294
          Width = 41
          Height = 21
          TabOrder = 70
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC039: TEdit
          Tag = 39
          Left = 496
          Top = 294
          Width = 41
          Height = 21
          TabOrder = 71
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC032: TCheckBox
          Tag = 32
          Left = 323
          Top = 231
          Width = 15
          Height = 17
          TabOrder = 72
          OnClick = cbBBPCClick
        end
        object cbBBPC033: TCheckBox
          Tag = 33
          Left = 480
          Top = 231
          Width = 15
          Height = 17
          TabOrder = 73
          OnClick = cbBBPCClick
        end
        object cbBBPC034: TCheckBox
          Tag = 34
          Left = 638
          Top = 231
          Width = 15
          Height = 17
          TabOrder = 74
          OnClick = cbBBPCClick
        end
        object cbBBPC035: TCheckBox
          Tag = 35
          Left = 796
          Top = 231
          Width = 15
          Height = 17
          TabOrder = 75
          OnClick = cbBBPCClick
        end
        object cbBBPC036: TCheckBox
          Tag = 36
          Left = 8
          Top = 276
          Width = 15
          Height = 17
          TabOrder = 76
          OnClick = cbBBPCClick
        end
        object cbBBPC037: TCheckBox
          Tag = 37
          Left = 165
          Top = 276
          Width = 15
          Height = 17
          TabOrder = 77
          OnClick = cbBBPCClick
        end
        object cbBBPC038: TCheckBox
          Tag = 38
          Left = 323
          Top = 276
          Width = 15
          Height = 17
          TabOrder = 78
          OnClick = cbBBPCClick
        end
        object cbBBPC039: TCheckBox
          Tag = 39
          Left = 480
          Top = 276
          Width = 15
          Height = 17
          TabOrder = 79
          OnClick = cbBBPCClick
        end
        object edtBBPC040: TEdit
          Tag = 40
          Left = 654
          Top = 294
          Width = 41
          Height = 21
          TabOrder = 80
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC041: TEdit
          Tag = 41
          Left = 812
          Top = 294
          Width = 41
          Height = 21
          TabOrder = 81
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC042: TEdit
          Tag = 42
          Left = 24
          Top = 339
          Width = 41
          Height = 21
          TabOrder = 82
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC043: TEdit
          Tag = 43
          Left = 181
          Top = 339
          Width = 41
          Height = 21
          TabOrder = 83
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC044: TEdit
          Tag = 44
          Left = 339
          Top = 339
          Width = 41
          Height = 21
          TabOrder = 84
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC045: TEdit
          Tag = 45
          Left = 496
          Top = 339
          Width = 41
          Height = 21
          TabOrder = 85
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC046: TEdit
          Tag = 46
          Left = 654
          Top = 339
          Width = 41
          Height = 21
          TabOrder = 86
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC047: TEdit
          Tag = 47
          Left = 812
          Top = 339
          Width = 41
          Height = 21
          TabOrder = 87
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC040: TCheckBox
          Tag = 40
          Left = 638
          Top = 276
          Width = 15
          Height = 17
          TabOrder = 88
          OnClick = cbBBPCClick
        end
        object cbBBPC041: TCheckBox
          Tag = 41
          Left = 796
          Top = 276
          Width = 15
          Height = 17
          TabOrder = 89
          OnClick = cbBBPCClick
        end
        object cbBBPC042: TCheckBox
          Tag = 42
          Left = 8
          Top = 321
          Width = 15
          Height = 17
          TabOrder = 90
          OnClick = cbBBPCClick
        end
        object cbBBPC043: TCheckBox
          Tag = 43
          Left = 165
          Top = 321
          Width = 15
          Height = 17
          TabOrder = 91
          OnClick = cbBBPCClick
        end
        object cbBBPC044: TCheckBox
          Tag = 44
          Left = 323
          Top = 321
          Width = 15
          Height = 17
          TabOrder = 92
          OnClick = cbBBPCClick
        end
        object cbBBPC045: TCheckBox
          Tag = 45
          Left = 480
          Top = 321
          Width = 15
          Height = 17
          TabOrder = 93
          OnClick = cbBBPCClick
        end
        object cbBBPC046: TCheckBox
          Tag = 46
          Left = 638
          Top = 321
          Width = 15
          Height = 17
          TabOrder = 94
          OnClick = cbBBPCClick
        end
        object cbBBPC047: TCheckBox
          Tag = 47
          Left = 796
          Top = 321
          Width = 15
          Height = 17
          TabOrder = 95
          OnClick = cbBBPCClick
        end
        object edtBBPC048: TEdit
          Tag = 48
          Left = 24
          Top = 384
          Width = 41
          Height = 21
          TabOrder = 96
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC049: TEdit
          Tag = 49
          Left = 181
          Top = 384
          Width = 41
          Height = 21
          TabOrder = 97
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC050: TEdit
          Tag = 50
          Left = 339
          Top = 384
          Width = 41
          Height = 21
          TabOrder = 98
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC051: TEdit
          Tag = 51
          Left = 496
          Top = 384
          Width = 41
          Height = 21
          TabOrder = 99
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC052: TEdit
          Tag = 52
          Left = 654
          Top = 384
          Width = 41
          Height = 21
          TabOrder = 100
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC053: TEdit
          Tag = 53
          Left = 812
          Top = 384
          Width = 41
          Height = 21
          TabOrder = 101
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC054: TEdit
          Tag = 54
          Left = 24
          Top = 429
          Width = 41
          Height = 21
          TabOrder = 102
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC055: TEdit
          Tag = 55
          Left = 181
          Top = 429
          Width = 41
          Height = 21
          TabOrder = 103
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC048: TCheckBox
          Tag = 48
          Left = 8
          Top = 366
          Width = 15
          Height = 17
          TabOrder = 104
          OnClick = cbBBPCClick
        end
        object cbBBPC049: TCheckBox
          Tag = 49
          Left = 165
          Top = 366
          Width = 15
          Height = 17
          TabOrder = 105
          OnClick = cbBBPCClick
        end
        object cbBBPC050: TCheckBox
          Tag = 50
          Left = 323
          Top = 366
          Width = 15
          Height = 17
          TabOrder = 106
          OnClick = cbBBPCClick
        end
        object cbBBPC051: TCheckBox
          Tag = 51
          Left = 480
          Top = 366
          Width = 15
          Height = 17
          TabOrder = 107
          OnClick = cbBBPCClick
        end
        object cbBBPC052: TCheckBox
          Tag = 52
          Left = 638
          Top = 366
          Width = 15
          Height = 17
          TabOrder = 108
          OnClick = cbBBPCClick
        end
        object cbBBPC053: TCheckBox
          Tag = 53
          Left = 796
          Top = 366
          Width = 15
          Height = 17
          TabOrder = 109
          OnClick = cbBBPCClick
        end
        object cbBBPC054: TCheckBox
          Tag = 54
          Left = 8
          Top = 411
          Width = 15
          Height = 17
          TabOrder = 110
          OnClick = cbBBPCClick
        end
        object cbBBPC055: TCheckBox
          Tag = 55
          Left = 165
          Top = 411
          Width = 15
          Height = 17
          TabOrder = 111
          OnClick = cbBBPCClick
        end
        object edtBBPC056: TEdit
          Tag = 56
          Left = 339
          Top = 429
          Width = 41
          Height = 21
          TabOrder = 112
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC057: TEdit
          Tag = 57
          Left = 496
          Top = 429
          Width = 41
          Height = 21
          TabOrder = 113
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC058: TEdit
          Tag = 58
          Left = 654
          Top = 429
          Width = 41
          Height = 21
          TabOrder = 114
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC059: TEdit
          Tag = 59
          Left = 812
          Top = 429
          Width = 41
          Height = 21
          TabOrder = 115
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC060: TEdit
          Tag = 60
          Left = 24
          Top = 474
          Width = 41
          Height = 21
          TabOrder = 116
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC061: TEdit
          Tag = 61
          Left = 181
          Top = 474
          Width = 41
          Height = 21
          TabOrder = 117
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC062: TEdit
          Tag = 62
          Left = 339
          Top = 474
          Width = 41
          Height = 21
          TabOrder = 118
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC063: TEdit
          Tag = 63
          Left = 496
          Top = 474
          Width = 41
          Height = 21
          TabOrder = 119
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC064: TEdit
          Tag = 64
          Left = 654
          Top = 474
          Width = 41
          Height = 21
          TabOrder = 120
          Text = '0'
        end
        object edtBBPC065: TEdit
          Tag = 65
          Left = 812
          Top = 474
          Width = 41
          Height = 21
          TabOrder = 121
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC056: TCheckBox
          Tag = 56
          Left = 323
          Top = 411
          Width = 15
          Height = 17
          TabOrder = 122
          OnClick = cbBBPCClick
        end
        object cbBBPC057: TCheckBox
          Tag = 57
          Left = 480
          Top = 411
          Width = 15
          Height = 17
          TabOrder = 123
          OnClick = cbBBPCClick
        end
        object cbBBPC058: TCheckBox
          Tag = 58
          Left = 638
          Top = 411
          Width = 15
          Height = 17
          TabOrder = 124
          OnClick = cbBBPCClick
        end
        object cbBBPC059: TCheckBox
          Tag = 59
          Left = 796
          Top = 411
          Width = 15
          Height = 17
          TabOrder = 125
          OnClick = cbBBPCClick
        end
        object cbBBPC060: TCheckBox
          Tag = 60
          Left = 8
          Top = 456
          Width = 15
          Height = 17
          TabOrder = 126
          OnClick = cbBBPCClick
        end
        object cbBBPC061: TCheckBox
          Tag = 61
          Left = 165
          Top = 456
          Width = 15
          Height = 17
          TabOrder = 127
          OnClick = cbBBPCClick
        end
        object cbBBPC062: TCheckBox
          Tag = 62
          Left = 323
          Top = 456
          Width = 15
          Height = 17
          TabOrder = 128
          OnClick = cbBBPCClick
        end
        object cbBBPC063: TCheckBox
          Tag = 63
          Left = 480
          Top = 456
          Width = 15
          Height = 17
          TabOrder = 129
          OnClick = cbBBPCClick
        end
        object edtBBPC066: TEdit
          Tag = 66
          Left = 24
          Top = 519
          Width = 41
          Height = 21
          TabOrder = 130
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC067: TEdit
          Tag = 67
          Left = 181
          Top = 519
          Width = 41
          Height = 21
          TabOrder = 131
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC073: TEdit
          Tag = 73
          Left = 181
          Top = 564
          Width = 41
          Height = 21
          TabOrder = 132
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC072: TEdit
          Tag = 72
          Left = 24
          Top = 564
          Width = 41
          Height = 21
          TabOrder = 133
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC071: TEdit
          Tag = 71
          Left = 812
          Top = 519
          Width = 41
          Height = 21
          TabOrder = 134
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC070: TEdit
          Tag = 70
          Left = 654
          Top = 519
          Width = 41
          Height = 21
          TabOrder = 135
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC069: TEdit
          Tag = 69
          Left = 496
          Top = 519
          Width = 41
          Height = 21
          TabOrder = 136
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object edtBBPC068: TEdit
          Tag = 68
          Left = 339
          Top = 519
          Width = 41
          Height = 21
          TabOrder = 137
          Text = '0'
          OnExit = edtBBPCCheck
        end
        object cbBBPC064: TCheckBox
          Tag = 64
          Left = 638
          Top = 456
          Width = 15
          Height = 17
          TabOrder = 138
          OnClick = cbBBPCClick
        end
        object cbBBPC065: TCheckBox
          Tag = 65
          Left = 796
          Top = 456
          Width = 15
          Height = 17
          TabOrder = 139
          OnClick = cbBBPCClick
        end
        object cbBBPC071: TCheckBox
          Tag = 71
          Left = 796
          Top = 501
          Width = 15
          Height = 17
          TabOrder = 140
          OnClick = cbBBPCClick
        end
        object cbBBPC070: TCheckBox
          Tag = 70
          Left = 638
          Top = 501
          Width = 15
          Height = 17
          TabOrder = 141
          OnClick = cbBBPCClick
        end
        object cbBBPC069: TCheckBox
          Tag = 69
          Left = 480
          Top = 501
          Width = 15
          Height = 17
          TabOrder = 142
          OnClick = cbBBPCClick
        end
        object cbBBPC068: TCheckBox
          Tag = 68
          Left = 323
          Top = 501
          Width = 15
          Height = 17
          TabOrder = 143
          OnClick = cbBBPCClick
        end
        object cbBBPC067: TCheckBox
          Tag = 67
          Left = 165
          Top = 501
          Width = 15
          Height = 17
          TabOrder = 144
          OnClick = cbBBPCClick
        end
        object cbBBPC066: TCheckBox
          Tag = 66
          Left = 8
          Top = 501
          Width = 15
          Height = 17
          TabOrder = 145
          OnClick = cbBBPCClick
        end
        object cbBBPC072: TCheckBox
          Tag = 72
          Left = 8
          Top = 546
          Width = 15
          Height = 17
          TabOrder = 146
          OnClick = cbBBPCClick
        end
        object cbBBPC073: TCheckBox
          Tag = 73
          Left = 165
          Top = 546
          Width = 15
          Height = 17
          TabOrder = 147
          OnClick = cbBBPCClick
        end
      end
      object btnBBPCBBCRData: TButton
        Tag = 1
        Left = 270
        Top = 2
        Width = 89
        Height = 23
        Caption = 'BBCR Data (Hex)'
        TabOrder = 2
        OnClick = btnBBPCBBCRDataClick
      end
    end
  end
  object sbWiFiBBCR: TStatusBar
    Left = 0
    Top = 697
    Width = 961
    Height = 29
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object btnReadFromRegister: TButton
    Left = 29
    Top = 672
    Width = 100
    Height = 25
    Caption = 'Read from register'
    TabOrder = 2
    OnClick = btnReadFromRegisterClick
  end
  object btnWriteToRegister: TButton
    Left = 137
    Top = 672
    Width = 100
    Height = 25
    Caption = 'Write to register'
    TabOrder = 3
    OnClick = btnWriteToRegisterClick
  end
  object btnLoadFromFile: TButton
    Left = 246
    Top = 672
    Width = 80
    Height = 25
    Caption = 'Load fom file'
    TabOrder = 4
    OnClick = btnLoadFromFileClick
  end
  object btnSaveToFile: TButton
    Left = 332
    Top = 672
    Width = 80
    Height = 25
    Caption = 'Save to file'
    TabOrder = 5
    OnClick = btnSaveToFileClick
  end
  object lblHint: TStaticText
    Left = 400
    Top = 2
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 6
    Visible = False
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 336
    Top = 16
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Save to ini file'
    Left = 440
    Top = 16
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Open ini file'
    Left = 488
    Top = 16
  end
end
