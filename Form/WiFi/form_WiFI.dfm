object frmWiFi: TfrmWiFi
  Left = 328
  Top = 202
  Width = 854
  Height = 560
  Caption = 'WiFi Tool'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pctlToolSel: TPageControl
    Tag = 1
    Left = 0
    Top = 0
    Width = 846
    Height = 526
    ActivePage = tsBB
    Align = alClient
    MultiLine = True
    TabIndex = 3
    TabOrder = 0
    OnChange = pctlToolSelChange
    object tsTX: TTabSheet
      Caption = 'TX'
      object gbCPTInput: TGroupBox
        Left = 0
        Top = 6
        Width = 825
        Height = 427
        Caption = '  Input  '
        TabOrder = 0
        object btnTXStart: TBitBtn
          Left = 680
          Top = 8
          Width = 75
          Height = 25
          Caption = 'Start'
          TabOrder = 0
          OnClick = btnTXStartClick
          Kind = bkRetry
        end
        object btnTXStop: TBitBtn
          Left = 680
          Top = 40
          Width = 75
          Height = 25
          Caption = 'Stop'
          TabOrder = 1
          OnClick = btnTXStopClick
          Kind = bkNo
        end
        object gbTXType: TGroupBox
          Left = 656
          Top = 104
          Width = 153
          Height = 105
          Caption = '  Type  '
          TabOrder = 2
          object rbCPT: TRadioButton
            Left = 8
            Top = 58
            Width = 140
            Height = 17
            Caption = 'Continuous packet TX'
            Checked = True
            TabOrder = 0
            TabStop = True
            OnClick = rbCPTClick
          end
          object rbTXOP: TRadioButton
            Left = 8
            Top = 16
            Width = 113
            Height = 17
            Caption = 'TX output power'
            TabOrder = 1
            OnClick = rbTXOPClick
          end
          object rbTXCS: TRadioButton
            Left = 8
            Top = 37
            Width = 129
            Height = 17
            Caption = 'TX carrier suppression'
            TabOrder = 2
            OnClick = rbTXCSClick
          end
          object rbTXLF: TRadioButton
            Left = 8
            Top = 80
            Width = 113
            Height = 17
            Caption = 'Local Frequency'
            TabOrder = 3
            OnClick = rbTXLFClick
          end
        end
        object pnlCPT: TPanel
          Left = 8
          Top = 216
          Width = 809
          Height = 201
          BevelOuter = bvLowered
          TabOrder = 3
          object lblTXPacketLength: TLabel
            Left = 18
            Top = 112
            Width = 66
            Height = 13
            Caption = 'Packet length'
          end
          object lblTXPacketCount: TLabel
            Left = 116
            Top = 112
            Width = 64
            Height = 13
            Caption = 'Packet count'
          end
          object lblTXPacketInterval: TLabel
            Left = 200
            Top = 112
            Width = 91
            Height = 13
            Caption = 'Packet interval (us)'
          end
          object lblTXBitPattern: TLabel
            Left = 440
            Top = 112
            Width = 48
            Height = 13
            Caption = 'Bit pattern'
          end
          object lblTXPreamble: TLabel
            Left = 312
            Top = 112
            Width = 44
            Height = 13
            Caption = 'Preamble'
          end
          object lblTXPacketSent: TLabel
            Left = 120
            Top = 160
            Width = 57
            Height = 13
            Caption = 'Packet sent'
          end
          object lblTXAckCount: TLabel
            Left = 216
            Top = 160
            Width = 49
            Height = 13
            Caption = 'Ack count'
          end
          object m_lblAverageALC: TLabel
            Left = 308
            Top = 160
            Width = 63
            Height = 13
            Caption = 'Average ALC'
          end
          object m_lblTXCCKGainControl: TLabel
            Left = 396
            Top = 160
            Width = 79
            Height = 13
            Caption = 'CCK gain control'
          end
          object m_lblTXOFDMGainControl: TLabel
            Left = 488
            Top = 160
            Width = 89
            Height = 13
            Caption = 'OFDM gain control'
          end
          object edtTXPacketLength: TEdit
            Left = 16
            Top = 128
            Width = 73
            Height = 21
            TabOrder = 0
            Text = '128'
            OnExit = edtCPTPacketLengthCheck
          end
          object edtTXPacketCount: TEdit
            Left = 112
            Top = 128
            Width = 73
            Height = 21
            TabOrder = 1
            Text = '0'
            OnExit = edtCPTPacketCountCheck
          end
          object edtTXPacketInterval: TEdit
            Left = 208
            Top = 128
            Width = 73
            Height = 21
            TabOrder = 2
            Text = '100'
            OnExit = edtCPTPacketIntervalCheck
          end
          object cbTXBitPattern: TComboBox
            Left = 400
            Top = 128
            Width = 145
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 3
            Text = 'All 0'
            Items.Strings = (
              'All 0'
              'All 1'
              'Alternate bits (010101)'
              'Pseudo random')
          end
          object cbTXPreamble: TComboBox
            Left = 304
            Top = 128
            Width = 73
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 4
            Text = 'long'
            Items.Strings = (
              'long'
              'short')
          end
          object stTXPacketSent: TStaticText
            Left = 112
            Top = 176
            Width = 73
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 5
          end
          object stTXAckCount: TStaticText
            Left = 208
            Top = 176
            Width = 73
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 6
          end
          object StaticText1: TStaticText
            Left = 8
            Top = 8
            Width = 199
            Height = 17
            BevelKind = bkTile
            BevelOuter = bvSpace
            Caption = 'Continuous packet TX specific parameter'
            Color = clCream
            ParentColor = False
            TabOrder = 7
          end
          object Panel10: TPanel
            Left = 8
            Top = 32
            Width = 617
            Height = 73
            BevelOuter = bvLowered
            TabOrder = 8
            object lblTXFrameCtrl0x: TLabel
              Left = 2
              Top = 52
              Width = 11
              Height = 13
              Caption = '0x'
            end
            object lblTXFrameCtrl: TLabel
              Left = 16
              Top = 32
              Width = 47
              Height = 13
              Caption = 'Frame Ctrl'
            end
            object lblTXAddress1: TLabel
              Left = 168
              Top = 32
              Width = 47
              Height = 13
              Caption = 'Address 1'
            end
            object lblTXAddress2: TLabel
              Left = 312
              Top = 32
              Width = 47
              Height = 13
              Caption = 'Address 2'
            end
            object lblTXAddress3: TLabel
              Left = 448
              Top = 32
              Width = 47
              Height = 13
              Caption = 'Address 3'
            end
            object lblTXSeqCtrl: TLabel
              Left = 544
              Top = 32
              Width = 67
              Height = 13
              Caption = 'Sequence Ctrl'
            end
            object lblTXDuration: TLabel
              Left = 72
              Top = 32
              Width = 40
              Height = 13
              Caption = 'Duration'
            end
            object StaticText4: TStaticText
              Left = 8
              Top = 6
              Width = 69
              Height = 17
              BevelKind = bkTile
              Caption = '  MAC header'
              Color = clMoneyGreen
              ParentColor = False
              TabOrder = 0
            end
            object edtTXFramCtrl1: TEdit
              Tag = 4
              Left = 16
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 1
              Text = '08'
              OnExit = edtTXFramCtrlCheck
            end
            object edtTXFramCtrl0: TEdit
              Tag = 3
              Left = 38
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 2
              Text = '02'
              OnExit = edtTXFramCtrlCheck
            end
            object edtTXAddress13: TEdit
              Tag = 3
              Left = 170
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 3
              Text = 'FF'
              OnExit = edtTXAddress1Check
            end
            object edtTXAddress15: TEdit
              Tag = 5
              Left = 128
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 4
              Text = 'FF'
              OnExit = edtTXAddress1Check
            end
            object edtTXAddress14: TEdit
              Tag = 4
              Left = 148
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 5
              Text = 'FF'
              OnExit = edtTXAddress1Check
            end
            object edtTXAddress12: TEdit
              Tag = 2
              Left = 192
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 6
              Text = 'FF'
              OnExit = edtTXAddress1Check
            end
            object edtTXAddress11: TEdit
              Tag = 1
              Left = 214
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 7
              Text = 'FF'
              OnExit = edtTXAddress1Check
            end
            object edtTXAddress10: TEdit
              Left = 236
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 8
              Text = 'FF'
              OnExit = edtTXAddress1Check
            end
            object edtTXAddress25: TEdit
              Tag = 5
              Left = 272
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 9
              Text = '00'
              OnExit = edtTXAddress2Check
            end
            object edtTXAddress24: TEdit
              Tag = 4
              Left = 294
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 10
              Text = '08'
              OnExit = edtTXAddress2Check
            end
            object edtTXAddress23: TEdit
              Tag = 3
              Left = 316
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 11
              Text = '22'
              OnExit = edtTXAddress2Check
            end
            object edtTXAddress22: TEdit
              Tag = 2
              Left = 338
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 12
              Text = '00'
              OnExit = edtTXAddress2Check
            end
            object edtTXAddress21: TEdit
              Tag = 1
              Left = 360
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 13
              Text = '00'
              OnExit = edtTXAddress2Check
            end
            object edtTXAddress20: TEdit
              Left = 382
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 14
              Text = '01'
              OnExit = edtTXAddress2Check
            end
            object edtTXAddress35: TEdit
              Tag = 5
              Left = 416
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 15
              Text = 'FF'
              OnExit = edtTXAddress3Check
            end
            object edtTXAddress34: TEdit
              Tag = 4
              Left = 438
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 16
              Text = 'FF'
              OnExit = edtTXAddress3Check
            end
            object edtTXAddress33: TEdit
              Tag = 3
              Left = 460
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 17
              Text = 'FF'
              OnExit = edtTXAddress3Check
            end
            object edtTXAddress32: TEdit
              Tag = 2
              Left = 482
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 18
              Text = 'FF'
              OnExit = edtTXAddress3Check
            end
            object edtTXAddress31: TEdit
              Tag = 1
              Left = 504
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 19
              Text = 'FF'
              OnExit = edtTXAddress3Check
            end
            object edtTXAddress30: TEdit
              Left = 526
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 20
              Text = 'FF'
              OnExit = edtTXAddress3Check
            end
            object edtTXSeqCtrl1: TEdit
              Tag = 1
              Left = 560
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 21
              Text = '10'
              OnExit = edtTXSeqCtrlCheck
            end
            object edtTXSeqCtrl0: TEdit
              Left = 582
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 22
              Text = '00'
              OnExit = edtTXSeqCtrlCheck
            end
            object edtTXDuration1: TEdit
              Left = 72
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 23
              Text = '00'
              OnExit = edtTXDurationCheck
            end
            object edtTXDuration0: TEdit
              Left = 94
              Top = 48
              Width = 22
              Height = 21
              TabOrder = 24
              Text = '00'
              OnExit = edtTXDurationCheck
            end
          end
          object m_stAverageALC: TStaticText
            Left = 304
            Top = 176
            Width = 73
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 9
          end
          object m_stTXCCKGainControl: TStaticText
            Left = 400
            Top = 176
            Width = 73
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 10
          end
          object m_stTXOFDMGainControl: TStaticText
            Left = 496
            Top = 176
            Width = 73
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 11
          end
        end
        object Panel8: TPanel
          Left = 8
          Top = 112
          Width = 641
          Height = 97
          BevelOuter = bvLowered
          TabOrder = 4
          object lblTXIDC0x: TLabel
            Left = 8
            Top = 66
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object lblTXQDC0x: TLabel
            Left = 112
            Top = 66
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object StaticText2: TStaticText
            Left = 8
            Top = 8
            Width = 124
            Height = 17
            BevelKind = bkTile
            Caption = '  TX DC offset parameter '
            Color = clCream
            ParentColor = False
            TabOrder = 0
          end
          object btnTXCalTxDC: TButton
            Left = 216
            Top = 8
            Width = 121
            Height = 25
            Caption = 'Calibrate TX DC offset'
            TabOrder = 1
            OnClick = btnTXCalTxDCClick
          end
          object edtTXIDC: TEdit
            Left = 24
            Top = 64
            Width = 57
            Height = 21
            TabOrder = 2
            Text = '0'
            OnExit = edtTXIDcOffsetCheck
          end
          object edtTXQDC: TEdit
            Left = 128
            Top = 64
            Width = 57
            Height = 21
            TabOrder = 3
            Text = '0'
            OnExit = edtTXQDCOffsetCheck
          end
          object btnTXIDC: TButton
            Tag = 1
            Left = 16
            Top = 36
            Width = 75
            Height = 25
            Caption = 'I_DC (Hex)'
            TabOrder = 4
            OnClick = btnTXIDCClick
          end
          object btnTXQDC: TButton
            Tag = 1
            Left = 120
            Top = 36
            Width = 75
            Height = 25
            Caption = 'Q_DC (Hex)'
            TabOrder = 5
            OnClick = btnTXQDCClick
          end
        end
        object Panel9: TPanel
          Left = 8
          Top = 16
          Width = 641
          Height = 89
          BevelOuter = bvLowered
          TabOrder = 5
          object lblTXChannelID: TLabel
            Left = 24
            Top = 40
            Width = 67
            Height = 13
            Caption = 'Channel (kHz)'
          end
          object lblTXTxFilter: TLabel
            Left = 152
            Top = 40
            Width = 36
            Height = 13
            Caption = 'TX filter'
          end
          object lblTXTxRate: TLabel
            Left = 234
            Top = 40
            Width = 66
            Height = 13
            Caption = 'TX rate (MHz)'
          end
          object lblTXTxPowerDac0X: TLabel
            Left = 328
            Top = 58
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object m_lblTXTargetAlc: TLabel
            Left = 448
            Top = 40
            Width = 54
            Height = 13
            Caption = 'Target ALC'
          end
          object cbTXChannelID: TComboBox
            Left = 8
            Top = 56
            Width = 97
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 0
            Text = '1 (2412000)'
            OnChange = cbTXChannelIDChange
            Items.Strings = (
              '1 (2412000)'
              '2 (2417000)'
              '3 (2422000)'
              '4 (2427000)'
              '5 (2432000)'
              '6 (2437000)'
              '7 (2442000)'
              '8 (2447000)'
              '9 (2452000)'
              '10 (2457000)'
              '11 (2462000)'
              '12 (2467000)'
              '13 (2472000)'
              '14 (2484000)')
          end
          object cbTXTxFilter: TComboBox
            Left = 120
            Top = 56
            Width = 97
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 1
            Text = 'North America'
            OnChange = cbTXTxFilterChange
            Items.Strings = (
              'North America'
              'Japan')
          end
          object cbTXTxRate: TComboBox
            Left = 232
            Top = 56
            Width = 73
            Height = 21
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 2
            Text = '1'
            OnChange = cbTXTxRateChange
            Items.Strings = (
              '1'
              '2'
              '5.5'
              '11')
          end
          object btnTXTxPowerDac: TButton
            Tag = 1
            Left = 318
            Top = 30
            Width = 107
            Height = 25
            Caption = 'TX power DAC (Hex)'
            TabOrder = 3
            OnClick = btnTXTxPowerDacClick
          end
          object edtTXTxPowerDAC: TEdit
            Left = 344
            Top = 56
            Width = 73
            Height = 21
            TabOrder = 4
            Text = '0'
            OnExit = edtCPTTxPowerDACCheck
          end
          object StaticText3: TStaticText
            Left = 8
            Top = 8
            Width = 103
            Height = 17
            BevelKind = bkTile
            Caption = '  General parameter  '
            Color = clCream
            ParentColor = False
            TabOrder = 5
          end
          object m_cbTXTargetGain: TCheckBox
            Left = 528
            Top = 16
            Width = 97
            Height = 17
            Caption = 'Target gain'
            Checked = True
            State = cbChecked
            TabOrder = 6
          end
          object m_cbTXAlcTracking: TCheckBox
            Left = 528
            Top = 40
            Width = 97
            Height = 17
            Caption = 'ALC tracking'
            TabOrder = 7
          end
          object m_cbTargetAlc: TCheckBox
            Left = 528
            Top = 64
            Width = 97
            Height = 17
            Caption = 'Target ALC'
            TabOrder = 8
          end
          object m_edtTXTargetAlc: TEdit
            Left = 440
            Top = 56
            Width = 73
            Height = 21
            TabOrder = 9
            Text = '0'
          end
        end
      end
      object sbTX: TStatusBar
        Left = 0
        Top = 469
        Width = 838
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object btnTXUploadFromFlash: TButton
        Left = 8
        Top = 440
        Width = 91
        Height = 25
        Caption = 'Upload from flash'
        TabOrder = 2
        OnClick = btnTXUploadFromFlashClick
      end
      object btnTXDownloadToFlash: TButton
        Left = 104
        Top = 440
        Width = 91
        Height = 25
        Caption = 'Download to flash'
        TabOrder = 3
        OnClick = btnTXDownloadToFlashClick
      end
      object btnTXChangeDB: TButton
        Left = 200
        Top = 440
        Width = 105
        Height = 25
        Caption = 'Change NVRAM DB'
        TabOrder = 4
        OnClick = btnTXChangeDBClick
      end
      object btnTXLoadFromFile: TButton
        Left = 312
        Top = 440
        Width = 75
        Height = 25
        Caption = 'Load from file'
        TabOrder = 5
        OnClick = btnTXLoadFromFileClick
      end
      object btnTXSaveToFile: TButton
        Left = 392
        Top = 440
        Width = 75
        Height = 25
        Caption = 'Save to file'
        TabOrder = 6
        OnClick = btnTXSaveToFileClick
      end
      object btnTXTxChannelPower: TButton
        Left = 600
        Top = 440
        Width = 105
        Height = 25
        Caption = 'TX channel power'
        TabOrder = 7
        OnClick = btnTXTxChannelPowerClick
      end
      object btnLoadTxPowerFromEE: TButton
        Left = 472
        Top = 440
        Width = 121
        Height = 25
        Caption = 'Load from EEPROM'
        TabOrder = 8
        OnClick = btnLoadTxPowerFromEEClick
      end
      object m_btnTxAlc: TButton
        Left = 712
        Top = 440
        Width = 105
        Height = 25
        Caption = 'TX ALC'
        TabOrder = 9
        OnClick = m_btnTxAlcClick
      end
    end
    object tsCPR: TTabSheet
      Caption = 'Continuous packet RX'
      ImageIndex = 1
      object gbCPRInput: TGroupBox
        Left = 8
        Top = 0
        Width = 633
        Height = 73
        Caption = '  Input  '
        TabOrder = 0
        object lblCPRChannelID: TLabel
          Left = 40
          Top = 16
          Width = 53
          Height = 13
          Caption = 'Channel ID'
        end
        object lblCPRRxAntenna: TLabel
          Left = 168
          Top = 16
          Width = 58
          Height = 13
          Caption = 'RX Antenna'
        end
        object cbCPRChannelID: TComboBox
          Left = 24
          Top = 32
          Width = 97
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 0
          Text = '1 (2412000)'
          OnChange = cbCPRChannelIDChange
          Items.Strings = (
            '1 (2412000)'
            '2 (2417000)'
            '3 (2422000)'
            '4 (2427000)'
            '5 (2432000)'
            '6 (2437000)'
            '7 (2442000)'
            '8 (2447000)'
            '9 (2452000)'
            '10 (2457000)'
            '11 (2462000)'
            '12 (2467000)'
            '13 (2472000)'
            '14 (2484000)')
        end
        object btnCPRStop: TBitBtn
          Left = 536
          Top = 38
          Width = 75
          Height = 25
          Caption = 'Stop'
          TabOrder = 1
          OnClick = btnCPRStopClick
          Kind = bkNo
        end
        object btnCPRStart: TBitBtn
          Left = 536
          Top = 10
          Width = 75
          Height = 25
          Caption = 'Start'
          TabOrder = 2
          OnClick = btnCPRStartClick
          Kind = bkRetry
        end
        object cbCPRRxAntenna: TComboBox
          Left = 152
          Top = 32
          Width = 97
          Height = 21
          ItemHeight = 13
          ItemIndex = 2
          TabOrder = 3
          Text = 'Always 0'
          Items.Strings = (
            'Diversity AGC'
            'Diversity MPDU'
            'Always 0'
            'Always 1')
        end
      end
      object gbCPRRxPacketStatistics: TGroupBox
        Left = 8
        Top = 72
        Width = 633
        Height = 345
        Caption = '  RX packets statistics  '
        TabOrder = 1
        object btnCPRReset: TButton
          Left = 584
          Top = 16
          Width = 43
          Height = 25
          Caption = 'Reset'
          TabOrder = 0
          OnClick = btnCPRResetClick
        end
        object Panel4: TPanel
          Left = 8
          Top = 112
          Width = 329
          Height = 225
          BevelOuter = bvLowered
          TabOrder = 1
          object lblCPRRxRate: TLabel
            Left = 8
            Top = 8
            Width = 58
            Height = 13
            Caption = 'RX rate (Hz)'
          end
          object lblCPRSum: TLabel
            Left = 88
            Top = 8
            Width = 21
            Height = 13
            Caption = 'Sum'
          end
          object lblCPRGood: TLabel
            Left = 152
            Top = 8
            Width = 26
            Height = 13
            Caption = 'Good'
          end
          object lblCPRBad: TLabel
            Left = 220
            Top = 8
            Width = 19
            Height = 13
            Caption = 'Bad'
          end
          object lblCPRFerRate: TLabel
            Left = 272
            Top = 8
            Width = 38
            Height = 13
            Caption = 'FER (%)'
          end
          object stCPR1MSum: TStaticText
            Left = 72
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 0
          end
          object stCPR1MGood: TStaticText
            Left = 136
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 1
          end
          object stCPR1MBad: TStaticText
            Left = 200
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 2
          end
          object stCPR1MFer: TStaticText
            Left = 264
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 3
          end
          object stCPR2MSum: TStaticText
            Tag = 1
            Left = 72
            Top = 40
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 4
          end
          object stCPR2MGood: TStaticText
            Tag = 1
            Left = 136
            Top = 40
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 5
          end
          object stCPR2MBad: TStaticText
            Tag = 1
            Left = 200
            Top = 40
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 6
          end
          object stCPR2MFer: TStaticText
            Tag = 1
            Left = 264
            Top = 40
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 7
          end
          object stCPR5_5MSum: TStaticText
            Tag = 2
            Left = 72
            Top = 56
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 8
          end
          object stCPR5_5MGood: TStaticText
            Tag = 2
            Left = 136
            Top = 56
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 9
          end
          object stCPR5_5MBad: TStaticText
            Tag = 2
            Left = 200
            Top = 56
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 10
          end
          object stCPR5_5MFer: TStaticText
            Tag = 2
            Left = 264
            Top = 56
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 11
          end
          object stCPR11MSum: TStaticText
            Tag = 3
            Left = 72
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 12
          end
          object stCPR11MGood: TStaticText
            Tag = 3
            Left = 136
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 13
          end
          object stCPR11MBad: TStaticText
            Tag = 3
            Left = 200
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 14
          end
          object stCPR11MFer: TStaticText
            Tag = 3
            Left = 264
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 15
          end
          object stCPR6MSum: TStaticText
            Tag = 4
            Left = 72
            Top = 88
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 16
          end
          object stCPR6MGood: TStaticText
            Tag = 4
            Left = 136
            Top = 88
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 17
          end
          object stCPR6MBad: TStaticText
            Tag = 4
            Left = 200
            Top = 88
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 18
          end
          object stCPR6MFer: TStaticText
            Tag = 4
            Left = 264
            Top = 88
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 19
          end
          object stCPR9MSum: TStaticText
            Tag = 5
            Left = 72
            Top = 104
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 20
          end
          object stCPR9MGood: TStaticText
            Tag = 5
            Left = 136
            Top = 104
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 21
          end
          object stCPR9MBad: TStaticText
            Tag = 5
            Left = 200
            Top = 104
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 22
          end
          object stCPR9MFer: TStaticText
            Tag = 5
            Left = 264
            Top = 104
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 23
          end
          object stCPR12MSum: TStaticText
            Tag = 6
            Left = 72
            Top = 120
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 24
          end
          object stCPR12MGood: TStaticText
            Tag = 6
            Left = 136
            Top = 120
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 25
          end
          object stCPR12MBad: TStaticText
            Tag = 6
            Left = 200
            Top = 120
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 26
          end
          object stCPR12MFer: TStaticText
            Tag = 6
            Left = 264
            Top = 120
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 27
          end
          object stCPR18MSum: TStaticText
            Tag = 7
            Left = 72
            Top = 136
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 28
          end
          object stCPR18MGood: TStaticText
            Tag = 7
            Left = 136
            Top = 136
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 29
          end
          object stCPR18MBad: TStaticText
            Tag = 7
            Left = 200
            Top = 136
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 30
          end
          object stCPR18MFer: TStaticText
            Tag = 7
            Left = 264
            Top = 136
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 31
          end
          object stCPR24MSum: TStaticText
            Tag = 8
            Left = 72
            Top = 152
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 32
          end
          object stCPR24MGood: TStaticText
            Tag = 8
            Left = 136
            Top = 152
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 33
          end
          object stCPR24MBad: TStaticText
            Tag = 8
            Left = 200
            Top = 152
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 34
          end
          object stCPR24MFer: TStaticText
            Tag = 8
            Left = 264
            Top = 152
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 35
          end
          object stCPR36MSum: TStaticText
            Tag = 9
            Left = 72
            Top = 168
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 36
          end
          object stCPR36MGood: TStaticText
            Tag = 9
            Left = 136
            Top = 168
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 37
          end
          object stCPR36MBad: TStaticText
            Tag = 9
            Left = 200
            Top = 168
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 38
          end
          object stCPR36MFer: TStaticText
            Tag = 9
            Left = 264
            Top = 168
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 39
          end
          object stCPR48MSum: TStaticText
            Tag = 10
            Left = 72
            Top = 184
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 40
          end
          object stCPR48MGood: TStaticText
            Tag = 10
            Left = 136
            Top = 184
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 41
          end
          object stCPR48MBad: TStaticText
            Tag = 10
            Left = 200
            Top = 184
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 42
          end
          object stCPR48MFer: TStaticText
            Tag = 10
            Left = 264
            Top = 184
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 43
          end
          object stCPR54MSum: TStaticText
            Tag = 11
            Left = 72
            Top = 200
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 44
          end
          object stCPR54MGood: TStaticText
            Tag = 11
            Left = 136
            Top = 200
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 45
          end
          object stCPR54MBad: TStaticText
            Tag = 11
            Left = 200
            Top = 200
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 46
          end
          object stCPR54MFer: TStaticText
            Tag = 11
            Left = 264
            Top = 200
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 47
          end
          object stCPR1M: TStaticText
            Left = 8
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '1M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 48
          end
          object stCPR2M: TStaticText
            Left = 8
            Top = 40
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '2M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 49
          end
          object stCPR5_5M: TStaticText
            Left = 8
            Top = 56
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '5.5M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 50
          end
          object stCPR11M: TStaticText
            Left = 8
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '11M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 51
          end
          object stCPR6M: TStaticText
            Left = 8
            Top = 88
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '6M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 52
          end
          object stCPR9M: TStaticText
            Left = 8
            Top = 104
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '9M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 53
          end
          object stCPR12M: TStaticText
            Left = 8
            Top = 120
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '12M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 54
          end
          object stCPR18M: TStaticText
            Left = 8
            Top = 136
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '18M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 55
          end
          object stCPR24M: TStaticText
            Left = 8
            Top = 152
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '24M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 56
          end
          object stCPR36M: TStaticText
            Left = 8
            Top = 168
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '36M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 57
          end
          object stCPR48M: TStaticText
            Left = 8
            Top = 184
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '48M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 58
          end
          object stCPR54M: TStaticText
            Left = 8
            Top = 200
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BevelKind = bkTile
            Caption = '54M'
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 59
          end
        end
        object Panel5: TPanel
          Left = 8
          Top = 16
          Width = 569
          Height = 89
          BevelOuter = bvLowered
          TabOrder = 2
          object lblCPRTotal: TLabel
            Left = 24
            Top = 8
            Width = 24
            Height = 13
            Caption = 'Total'
          end
          object lblCPRSuccess: TLabel
            Left = 112
            Top = 8
            Width = 41
            Height = 13
            Caption = 'Success'
          end
          object lblCPRFER: TLabel
            Left = 312
            Top = 8
            Width = 38
            Height = 13
            Caption = 'FER (%)'
          end
          object lblCPRCRCErr: TLabel
            Left = 211
            Top = 8
            Width = 46
            Height = 13
            Caption = 'CRC error'
          end
          object lblCPRint_rx_ok_num: TLabel
            Left = 2
            Top = 48
            Width = 72
            Height = 13
            Caption = ' int_rx_ok_num'
          end
          object lblCPRint_crc_err_num: TLabel
            Left = 96
            Top = 48
            Width = 76
            Height = 13
            Caption = 'int_crc_err_num'
          end
          object lblCPRpau_rx_ok_count: TLabel
            Left = 187
            Top = 48
            Width = 86
            Height = 13
            Caption = 'pau_rx_pkt_count'
          end
          object lblCPRpau_crc_err_count: TLabel
            Left = 279
            Top = 48
            Width = 90
            Height = 13
            Caption = 'pau_crc_err_count'
          end
          object lblCPRpau_cca_count: TLabel
            Left = 382
            Top = 48
            Width = 75
            Height = 13
            Caption = 'pau_cca_count'
          end
          object lblCPRpau_rx_fifo_full_count: TLabel
            Left = 462
            Top = 48
            Width = 104
            Height = 13
            Caption = 'pau_rx_fifo_full_count'
          end
          object stCPRTotal: TStaticText
            Left = 8
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 0
          end
          object stCPRSuccess: TStaticText
            Left = 104
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 1
          end
          object stCPRFER: TStaticText
            Left = 300
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 2
          end
          object stCPRCRCErr: TStaticText
            Left = 202
            Top = 24
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 3
          end
          object stCPRint_rx_ok_num: TStaticText
            Left = 7
            Top = 64
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 4
          end
          object stCPRint_crc_err_num: TStaticText
            Left = 104
            Top = 64
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 5
          end
          object stCPRpau_rx_ok_count: TStaticText
            Left = 202
            Top = 64
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 6
          end
          object stCPRpau_crc_err_count: TStaticText
            Left = 300
            Top = 64
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 7
          end
          object stCPRpau_cca_count: TStaticText
            Left = 398
            Top = 64
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 8
          end
          object stCPRpau_rx_fifo_full_count: TStaticText
            Left = 496
            Top = 64
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 9
          end
        end
        object Panel6: TPanel
          Left = 344
          Top = 112
          Width = 281
          Height = 109
          BevelOuter = bvLowered
          TabOrder = 3
          object lblCPRMin: TLabel
            Left = 32
            Top = 56
            Width = 20
            Height = 13
            Caption = 'Min.'
          end
          object lblCPRMax: TLabel
            Left = 96
            Top = 56
            Width = 26
            Height = 13
            Caption = 'Max. '
          end
          object lblCPRMean: TLabel
            Left = 160
            Top = 56
            Width = 27
            Height = 13
            Caption = 'Mean'
          end
          object lblCPRVariance: TLabel
            Left = 224
            Top = 56
            Width = 42
            Height = 13
            Caption = 'Variance'
          end
          object stCPRMin: TStaticText
            Left = 8
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 0
          end
          object stCPRMax: TStaticText
            Left = 80
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 1
          end
          object stCPRMean: TStaticText
            Left = 152
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 2
          end
          object stCPRVariance: TStaticText
            Left = 216
            Top = 72
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 3
          end
          object stCPRRssi: TStaticText
            Left = 16
            Top = 16
            Width = 29
            Height = 17
            BevelKind = bkTile
            Caption = 'RSSI'
            Color = clWhite
            ParentColor = False
            TabOrder = 4
          end
        end
        object Panel7: TPanel
          Left = 344
          Top = 228
          Width = 281
          Height = 109
          BevelOuter = bvLowered
          TabOrder = 4
          object lblCPRLong: TLabel
            Left = 24
            Top = 64
            Width = 24
            Height = 13
            Caption = 'Long'
          end
          object lblCPRShort: TLabel
            Left = 96
            Top = 64
            Width = 25
            Height = 13
            Caption = 'Short'
          end
          object stCPRPreamble: TStaticText
            Left = 16
            Top = 16
            Width = 48
            Height = 17
            BevelKind = bkTile
            Caption = 'Preamble'
            Color = clCream
            ParentColor = False
            TabOrder = 0
          end
          object stCPRLong: TStaticText
            Left = 8
            Top = 80
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 1
          end
          object stCPRShort: TStaticText
            Left = 80
            Top = 80
            Width = 58
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = '0'
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 2
          end
        end
      end
      object gbCPRRxCounter: TGroupBox
        Left = 8
        Top = 416
        Width = 633
        Height = 57
        Caption = '  RX counter  '
        TabOrder = 2
        object lblCPRED: TLabel
          Left = 40
          Top = 16
          Width = 15
          Height = 13
          Alignment = taCenter
          Caption = 'ED'
        end
        object lblCPROSD: TLabel
          Left = 128
          Top = 16
          Width = 23
          Height = 13
          Caption = 'OSD'
        end
        object lblCPRSQ1: TLabel
          Left = 232
          Top = 16
          Width = 21
          Height = 13
          Caption = 'SQ1'
        end
        object lblCPRSFD: TLabel
          Left = 328
          Top = 16
          Width = 21
          Height = 13
          Caption = 'SFD'
        end
        object lblCPRCRC16: TLabel
          Left = 424
          Top = 16
          Width = 34
          Height = 13
          Caption = 'CRC16'
        end
        object stCPRED: TStaticText
          Left = 16
          Top = 32
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 0
        end
        object stCPROSD: TStaticText
          Left = 114
          Top = 32
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object stCPRSQ1: TStaticText
          Left = 213
          Top = 32
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object stCPRSFD: TStaticText
          Left = 312
          Top = 32
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object stCPRCRC16: TStaticText
          Left = 408
          Top = 32
          Width = 64
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
        object btnCPRQueryRxCounter: TButton
          Left = 536
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Query'
          TabOrder = 5
          OnClick = btnCPRQueryRxCounterClick
        end
      end
      object sbCPR: TStatusBar
        Left = 0
        Top = 469
        Width = 838
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object tsPS: TTabSheet
      Caption = 'Power save'
      ImageIndex = 5
      object gbPSInput: TGroupBox
        Left = 8
        Top = 8
        Width = 617
        Height = 105
        Caption = '  Input  '
        TabOrder = 0
        object Label1: TLabel
          Left = 48
          Top = 24
          Width = 59
          Height = 13
          Caption = 'Power mode'
        end
        object cbPSPowerMode: TComboBox
          Left = 40
          Top = 40
          Width = 81
          Height = 21
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 0
          Text = 'Idle'
          Items.Strings = (
            'Idle'
            'Sleep')
        end
        object btnPSStart: TBitBtn
          Left = 496
          Top = 24
          Width = 75
          Height = 25
          Caption = 'Start'
          TabOrder = 1
          OnClick = btnPSStartClick
          Kind = bkRetry
        end
        object btnPSStop: TBitBtn
          Left = 496
          Top = 64
          Width = 75
          Height = 25
          Caption = 'Stop'
          TabOrder = 2
          OnClick = btnPSStopClick
          Kind = bkNo
        end
      end
      object sbPS: TStatusBar
        Left = 0
        Top = 471
        Width = 838
        Height = 27
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object tsBB: TTabSheet
      Caption = 'BB register access'
      ImageIndex = 6
      object sbBB: TStatusBar
        Left = 0
        Top = 471
        Width = 838
        Height = 27
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object memBBResult: TRichEdit
        Left = 0
        Top = 150
        Width = 838
        Height = 321
        Align = alClient
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Fixedsys'
        Font.Style = []
        ParentFont = False
        PopupMenu = pmWiFi
        ScrollBars = ssBoth
        TabOrder = 1
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 838
        Height = 150
        Align = alTop
        Caption = 'Panel1'
        TabOrder = 2
        object Label4: TLabel
          Left = 208
          Top = 104
          Width = 73
          Height = 13
          Caption = 'Begin CR index'
        end
        object Label7: TLabel
          Left = 338
          Top = 104
          Width = 68
          Height = 13
          Caption = 'End CR index '
        end
        object gbBBInput: TGroupBox
          Left = 1
          Top = 1
          Width = 836
          Height = 96
          Align = alTop
          Caption = '  BB register single R/W  '
          TabOrder = 0
          object lblBBCRIndex: TLabel
            Left = 64
            Top = 32
            Width = 43
            Height = 13
            Caption = 'CR index'
          end
          object lblBBCRData0X: TLabel
            Left = 160
            Top = 50
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object edtBBCRIndex: TEdit
            Left = 40
            Top = 48
            Width = 105
            Height = 21
            TabOrder = 0
            Text = '0'
            OnExit = edtBBCRIndexCheck
          end
          object edtBBCRData: TEdit
            Left = 176
            Top = 48
            Width = 105
            Height = 21
            TabOrder = 1
            Text = '0'
            OnExit = edtBBCRDataCheck
          end
          object btnBBRead: TButton
            Left = 312
            Top = 40
            Width = 89
            Height = 25
            Caption = 'Read'
            TabOrder = 2
            OnClick = btnBBReadClick
          end
          object btnBBWrite: TButton
            Left = 408
            Top = 40
            Width = 89
            Height = 25
            Caption = 'Write'
            TabOrder = 3
            OnClick = btnBBWriteClick
          end
          object btnBBCRData: TButton
            Tag = 1
            Left = 192
            Top = 18
            Width = 75
            Height = 25
            Caption = 'CR Data (Hex)'
            TabOrder = 4
            OnClick = btnBBCRDataClick
          end
          object btnBBStop: TButton
            Left = 504
            Top = 40
            Width = 89
            Height = 25
            Caption = 'Stop'
            TabOrder = 5
            OnClick = btnBBStopClick
          end
        end
        object btnBBDumpBBReg: TButton
          Left = 16
          Top = 106
          Width = 137
          Height = 25
          Caption = 'Dump BB registers'
          TabOrder = 1
          OnClick = btnBBDumpBBRegClick
        end
        object btnBBRegSetting: TButton
          Left = 472
          Top = 106
          Width = 137
          Height = 25
          Caption = 'BB register setting'
          TabOrder = 2
          OnClick = btnBBRegSettingClick
        end
        object edtBBBeginCRIndex: TEdit
          Left = 192
          Top = 120
          Width = 105
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtBBBeginCRIndexCheck
        end
        object edtBBEndCRIndex: TEdit
          Left = 320
          Top = 120
          Width = 105
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtBBEndCRIndexCheck
        end
      end
    end
    object tsMAC: TTabSheet
      Caption = 'MAC register access'
      ImageIndex = 7
      object sbMAC: TStatusBar
        Left = 0
        Top = 471
        Width = 838
        Height = 27
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object lbl: TStaticText
        Left = 600
        Top = 1
        Width = 14
        Height = 17
        BorderStyle = sbsSingle
        Caption = 'lbl'
        Color = clYellow
        ParentColor = False
        TabOrder = 1
        Visible = False
      end
      object memMACResult: TRichEdit
        Left = 0
        Top = 161
        Width = 838
        Height = 310
        Align = alClient
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Fixedsys'
        Font.Style = []
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 2
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 838
        Height = 161
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 3
        object Label2: TLabel
          Left = 8
          Top = 104
          Width = 122
          Height = 13
          Caption = 'Begin MCR address (Hex)'
        end
        object Label3: TLabel
          Left = 0
          Top = 122
          Width = 11
          Height = 13
          Caption = '0x'
        end
        object lblMACEndMCRAddr: TLabel
          Left = 160
          Top = 104
          Width = 114
          Height = 13
          Caption = 'End MCR address (Hex)'
        end
        object Label5: TLabel
          Left = 152
          Top = 122
          Width = 11
          Height = 13
          Caption = '0x'
        end
        object gbMACInput: TGroupBox
          Left = 0
          Top = 0
          Width = 838
          Height = 81
          Align = alTop
          Caption = '  MAC register single R/W  '
          TabOrder = 0
          object lblMACMCRAddress: TLabel
            Left = 32
            Top = 32
            Width = 92
            Height = 13
            Caption = 'MCR address (Hex)'
          end
          object lblMACMCRAddress0X: TLabel
            Left = 8
            Top = 50
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object lblMACMCRData0X: TLabel
            Tag = 1
            Left = 144
            Top = 50
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object edtMACMCRAddress: TEdit
            Left = 24
            Top = 48
            Width = 105
            Height = 21
            TabOrder = 0
            Text = '0'
            OnExit = edtMACMCRAddressCheck
          end
          object edtMACMCRData: TEdit
            Left = 160
            Top = 48
            Width = 105
            Height = 21
            TabOrder = 1
            Text = '0'
            OnExit = edtMACMCRDataCheck
          end
          object btnMACRead: TButton
            Left = 312
            Top = 32
            Width = 75
            Height = 25
            Caption = 'Read'
            TabOrder = 2
            OnClick = btnMACReadClick
          end
          object btnMACWrite: TButton
            Left = 408
            Top = 32
            Width = 75
            Height = 25
            Caption = 'Write'
            TabOrder = 3
            OnClick = btnMACWriteClick
          end
          object btnMACMCRData: TButton
            Tag = 1
            Left = 166
            Top = 18
            Width = 89
            Height = 25
            Caption = 'MCR Data (Hex)'
            TabOrder = 4
            OnClick = btnMACMCRDataClick
          end
        end
        object btnMACDumpAllMacReg: TButton
          Left = 384
          Top = 112
          Width = 121
          Height = 25
          Caption = 'Dump MAC register'
          TabOrder = 1
          OnClick = btnMACDumpAllMacRegClick
        end
        object btnMACRegSetting: TButton
          Left = 616
          Top = 112
          Width = 121
          Height = 25
          Caption = 'MAC register settting'
          TabOrder = 2
          OnClick = btnMACRegSettingClick
        end
        object edtMACBeginMCRAddr: TEdit
          Left = 16
          Top = 120
          Width = 105
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtMACBeginMCRAddrCheck
        end
        object edtMACEndMCRAddr: TEdit
          Left = 168
          Top = 120
          Width = 105
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtMACEndMCRAddrCheck
        end
        object GroupBox2: TGroupBox
          Left = 288
          Top = 88
          Width = 73
          Height = 70
          TabOrder = 5
          object rbMAC16bits: TRadioButton
            Left = 8
            Top = 16
            Width = 60
            Height = 17
            Caption = '16 bits'
            TabOrder = 0
            OnClick = rbMAC16bitsClick
          end
          object rbMAC32bits: TRadioButton
            Left = 8
            Top = 40
            Width = 60
            Height = 17
            Caption = '32 bits'
            Checked = True
            TabOrder = 1
            TabStop = True
            OnClick = rbMAC32bitsClick
          end
        end
        object btnMACStop: TButton
          Left = 520
          Top = 112
          Width = 75
          Height = 25
          Caption = 'Stop'
          TabOrder = 6
          OnClick = btnMACStopClick
        end
      end
    end
    object tsEE: TTabSheet
      Caption = 'EEPROM access '
      ImageIndex = 8
      object sbEE: TStatusBar
        Left = 0
        Top = 471
        Width = 838
        Height = 27
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object memEEResult: TRichEdit
        Left = 0
        Top = 161
        Width = 838
        Height = 310
        Align = alClient
        Font.Charset = CHINESEBIG5_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Fixedsys'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 1
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 838
        Height = 161
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 2
        object Label9: TLabel
          Left = 168
          Top = 112
          Width = 132
          Height = 13
          Caption = 'Begin EEPROM index (Hex)'
        end
        object Label10: TLabel
          Left = 328
          Top = 112
          Width = 124
          Height = 13
          Caption = 'End EEPROM index (Hex)'
        end
        object Label11: TLabel
          Left = 160
          Top = 132
          Width = 11
          Height = 13
          Caption = '0x'
        end
        object Label12: TLabel
          Left = 320
          Top = 132
          Width = 11
          Height = 13
          Caption = '0x'
        end
        object GroupBox5: TGroupBox
          Left = 0
          Top = 0
          Width = 838
          Height = 89
          Align = alTop
          Caption = ' EEPRom single R/W  '
          TabOrder = 0
          object lblEEIndex: TLabel
            Left = 24
            Top = 32
            Width = 102
            Height = 13
            Caption = 'EEPROM index (Hex)'
          end
          object lblEEIndex0X: TLabel
            Left = 8
            Top = 50
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object lblEEData0X: TLabel
            Left = 144
            Top = 50
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object edtEEIndex: TEdit
            Left = 24
            Top = 48
            Width = 105
            Height = 21
            TabOrder = 0
            Text = '0'
            OnExit = edtEEIndexCheck
          end
          object btnEEData: TButton
            Tag = 1
            Left = 160
            Top = 18
            Width = 105
            Height = 25
            Caption = 'EEPROM data (Hex)'
            TabOrder = 1
            OnClick = btnEEDataClick
          end
          object edtEEData: TEdit
            Left = 160
            Top = 48
            Width = 105
            Height = 21
            TabOrder = 2
            Text = '0'
            OnExit = edtEEDataCheck
          end
          object btnEERead: TButton
            Left = 392
            Top = 16
            Width = 75
            Height = 25
            Caption = 'Read'
            TabOrder = 3
            OnClick = btnEEReadClick
          end
          object btnEEWrite: TButton
            Left = 480
            Top = 16
            Width = 75
            Height = 25
            Caption = 'Write'
            TabOrder = 4
            OnClick = btnEEWriteClick
          end
          object btnEEStop: TButton
            Left = 568
            Top = 16
            Width = 75
            Height = 25
            Caption = 'Stop'
            TabOrder = 5
            OnClick = btnEEStopClick
          end
        end
        object btnEE: TButton
          Left = 8
          Top = 120
          Width = 137
          Height = 25
          Caption = 'Dump EEPROM'
          TabOrder = 1
          OnClick = btnEEClick
        end
        object btnEEPROMSetting: TButton
          Left = 680
          Top = 112
          Width = 97
          Height = 25
          Caption = 'EEPROM setting'
          TabOrder = 2
          OnClick = btnEEPROMSettingClick
        end
        object edtEEBeginIndex: TEdit
          Left = 176
          Top = 128
          Width = 105
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtBeginEEIndexCheck
        end
        object edtEEEndIndex: TEdit
          Left = 336
          Top = 128
          Width = 105
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtEndEEIndexCheck
        end
        object GroupBox3: TGroupBox
          Left = 496
          Top = 96
          Width = 89
          Height = 61
          Caption = '  Data format  '
          TabOrder = 5
          object rbEEByte: TRadioButton
            Left = 8
            Top = 16
            Width = 50
            Height = 17
            Caption = 'byte'
            TabOrder = 0
            OnClick = rbEEByteClick
          end
          object rbEEWord: TRadioButton
            Left = 8
            Top = 32
            Width = 50
            Height = 17
            Caption = 'word'
            Checked = True
            TabOrder = 1
            TabStop = True
            OnClick = rbEEWordClick
          end
        end
      end
    end
    object tsSC: TTabSheet
      Caption = 'Script test'
      ImageIndex = 6
      object GroupBox1: TGroupBox
        Left = 1
        Top = 8
        Width = 650
        Height = 105
        Caption = '  WiFi script  '
        TabOrder = 0
        object btnSCScriptFile: TBitBtn
          Left = 8
          Top = 16
          Width = 97
          Height = 17
          Caption = 'Script file'
          TabOrder = 0
          OnClick = btnSCScriptFileClick
        end
        object stSCScriptFile: TStaticText
          Left = 112
          Top = 16
          Width = 537
          Height = 17
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object btnSCStart: TBitBtn
          Left = 552
          Top = 40
          Width = 75
          Height = 25
          Caption = 'Start'
          TabOrder = 2
          OnClick = btnSCStartClick
          Kind = bkRetry
        end
        object btnSCStop: TBitBtn
          Left = 552
          Top = 72
          Width = 75
          Height = 25
          Caption = 'Stop'
          TabOrder = 3
          OnClick = btnSCStopClick
          Kind = bkNo
        end
      end
      object memSCResult: TMemo
        Left = 1
        Top = 128
        Width = 650
        Height = 273
        Lines.Strings = (
          '')
        TabOrder = 1
      end
      object stSC: TStatusBar
        Left = 0
        Top = 469
        Width = 838
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
  end
  object lblHint: TStaticText
    Left = 296
    Top = 480
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 1
    Visible = False
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 184
    Top = 496
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Open ini file'
    Left = 228
    Top = 496
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Save to ini file'
    Left = 92
    Top = 496
  end
  object TimerWiFi: TTimer
    Enabled = False
    OnTimer = TimerWiFiTimer
    Left = 136
    Top = 496
  end
  object pmWiFi: TPopupMenu
    Left = 40
    Top = 496
    object miCopy: TMenuItem
      Caption = 'Copy'
      ShortCut = 16451
      OnClick = miCopyClick
    end
  end
  object dlgOpenScriptFile: TOpenDialog
    DefaultExt = 'ws'
    Filter = 
      'WiFi script file (*.ws)|*.ws|Text file (*.txt)|*.txt|All files (' +
      '*.*)|*.*'
    InitialDir = '.'
    Title = 'Open WiFi script file'
    Left = 264
    Top = 496
  end
  object actList: TActionList
    Left = 616
    Top = 360
    object ToggleHide: TAction
      Caption = 'ToggleHide'
      ShortCut = 49237
      OnExecute = ToggleHideExecute
    end
  end
end
