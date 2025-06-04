object frmBT: TfrmBT
  Left = 353
  Top = 172
  Width = 838
  Height = 606
  Caption = 'MediaTek BT Tool'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object m_pctlToolSel: TPageControl
    Left = 5
    Top = 8
    Width = 817
    Height = 553
    ActivePage = TabSheet1
    TabIndex = 5
    TabOrder = 0
    object tsHCI: TTabSheet
      Caption = 'HCI Commander'
      TabVisible = False
      object GroupBox1: TGroupBox
        Left = 8
        Top = 8
        Width = 761
        Height = 257
        Caption = '  HCI Cmmand  '
        TabOrder = 0
        object lblHCIGroup: TLabel
          Left = 24
          Top = 72
          Width = 29
          Height = 13
          Caption = 'Group'
        end
        object lblHCICommand: TLabel
          Left = 8
          Top = 98
          Width = 47
          Height = 13
          Caption = 'Command'
        end
        object Label1: TLabel
          Left = 16
          Top = 128
          Width = 38
          Height = 13
          Caption = 'Opcode'
        end
        object Label2: TLabel
          Left = 58
          Top = 128
          Width = 11
          Height = 13
          Caption = '0x'
        end
        object Label23: TLabel
          Left = 16
          Top = 40
          Width = 42
          Height = 13
          Caption = 'Category'
        end
        object Label24: TLabel
          Left = 144
          Top = 128
          Width = 50
          Height = 13
          Caption = 'Last event'
        end
        object Label25: TLabel
          Left = 200
          Top = 128
          Width = 11
          Height = 13
          Caption = '0x'
        end
        object Label27: TLabel
          Left = 286
          Top = 128
          Width = 38
          Height = 13
          Caption = 'Timeout'
        end
        object Label28: TLabel
          Left = 392
          Top = 128
          Width = 13
          Height = 13
          Caption = 'ms'
        end
        object stHCIFile: TStaticText
          Left = 72
          Top = 16
          Width = 681
          Height = 17
          AutoSize = False
          BevelInner = bvLowered
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 0
        end
        object btnHCIFile: TButton
          Left = 8
          Top = 16
          Width = 49
          Height = 17
          Caption = 'File'
          TabOrder = 1
          OnClick = btnHCIFileClick
        end
        object cbHCIGroup: TComboBox
          Left = 72
          Top = 68
          Width = 257
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 0
          TabOrder = 2
          OnChange = cbHCIGroupChange
        end
        object cbHCICommand: TComboBox
          Left = 72
          Top = 96
          Width = 257
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 0
          TabOrder = 3
          OnChange = cbHCICommandChange
        end
        object sgSendHCI: TStringGrid
          Left = 8
          Top = 152
          Width = 369
          Height = 97
          ColCount = 4
          DefaultColWidth = 135
          DefaultRowHeight = 20
          FixedCols = 2
          RowCount = 10
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
          ScrollBars = ssVertical
          TabOrder = 4
          OnExit = sgSendHCICheck
          ColWidths = (
            135
            135
            75
            135)
          RowHeights = (
            20
            20
            20
            20
            20
            20
            20
            20
            20
            20)
        end
        object sgReceiveHCI: TStringGrid
          Left = 384
          Top = 152
          Width = 369
          Height = 97
          ColCount = 4
          DefaultColWidth = 135
          DefaultRowHeight = 20
          FixedCols = 2
          RowCount = 10
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
          ScrollBars = ssVertical
          TabOrder = 5
          ColWidths = (
            135
            135
            72
            135)
          RowHeights = (
            20
            20
            20
            14
            20
            20
            20
            20
            20
            20)
        end
        object stHCIOpcode: TStaticText
          Left = 72
          Top = 128
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 6
        end
        object cbHCICategory: TComboBox
          Left = 72
          Top = 40
          Width = 257
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 0
          TabOrder = 7
          OnChange = cbHCICategoryChange
        end
        object GroupBox7: TGroupBox
          Left = 336
          Top = 40
          Width = 89
          Height = 65
          Caption = '  Type  '
          TabOrder = 8
          object rbHCICategory: TRadioButton
            Left = 8
            Top = 16
            Width = 70
            Height = 17
            Caption = 'Category'
            TabOrder = 0
            OnClick = rbHCICategoryClick
          end
          object rbHCIGroup: TRadioButton
            Left = 8
            Top = 40
            Width = 70
            Height = 17
            Caption = 'Group'
            Checked = True
            TabOrder = 1
            TabStop = True
            OnClick = rbHCIGroupClick
          end
        end
        object stHCILastEvent: TStaticText
          Left = 216
          Top = 128
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 9
        end
        object GroupBox9: TGroupBox
          Left = 432
          Top = 40
          Width = 97
          Height = 65
          Caption = '  Format  '
          TabOrder = 10
          object rbHCIDec: TRadioButton
            Left = 8
            Top = 16
            Width = 70
            Height = 17
            Caption = 'Dec'
            TabOrder = 0
            OnClick = rbHCIDecClick
          end
          object rbHCIHex: TRadioButton
            Left = 8
            Top = 40
            Width = 70
            Height = 17
            Caption = 'Hex'
            Checked = True
            TabOrder = 1
            TabStop = True
            OnClick = rbHCIHexClick
          end
        end
        object edtHCITimeout: TEdit
          Left = 328
          Top = 126
          Width = 57
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 11
          Text = '0'
          OnExit = edtHCITimeoutCheck
        end
        object btnHCIStart: TBitBtn
          Left = 608
          Top = 48
          Width = 75
          Height = 25
          Caption = 'Start'
          TabOrder = 12
          OnClick = btnHCIStartClick
          Kind = bkRetry
        end
        object btnHCIStop: TBitBtn
          Left = 608
          Top = 88
          Width = 75
          Height = 25
          Caption = 'Stop'
          TabOrder = 13
          OnClick = btnHCIStopClick
          Kind = bkNo
        end
        object btnHCIClearLog: TButton
          Left = 448
          Top = 120
          Width = 75
          Height = 25
          Caption = 'Clear log'
          TabOrder = 14
          OnClick = btnHCIClearLogClick
        end
      end
      object memHCIResult: TRichEdit
        Left = 8
        Top = 272
        Width = 761
        Height = 129
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 1
      end
      object sbHCI: TStatusBar
        Left = 0
        Top = 496
        Width = 809
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'RF Test'
      ImageIndex = 1
      object sbRF: TStatusBar
        Left = 0
        Top = 496
        Width = 809
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 0
        Width = 761
        Height = 209
        Caption = '  Transmit  '
        TabOrder = 1
        object Label3: TLabel
          Left = 24
          Top = 24
          Width = 37
          Height = 13
          Caption = 'Pattern '
        end
        object cbRFTxPattern: TComboBox
          Left = 64
          Top = 20
          Width = 145
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 0
          Text = '0000'
          Items.Strings = (
            '0000'
            '1111'
            '1010'
            'pseudo random bit sequence'
            '11110000')
        end
        object Panel1: TPanel
          Left = 16
          Top = 48
          Width = 297
          Height = 65
          BevelOuter = bvLowered
          TabOrder = 1
          object rbRFTxSingleFreq: TRadioButton
            Left = 8
            Top = 8
            Width = 113
            Height = 17
            Caption = 'Single Frequency'
            TabOrder = 0
          end
          object rbRFTxFreqHop: TRadioButton
            Left = 8
            Top = 32
            Width = 113
            Height = 17
            Caption = 'Frequency Hopping'
            Checked = True
            TabOrder = 1
            TabStop = True
          end
          object edtRFTxSignleFreq: TEdit
            Left = 120
            Top = 8
            Width = 49
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 2
            Text = '78'
            OnExit = edtRFTxSignleFreqCheck
          end
        end
        object Panel2: TPanel
          Left = 16
          Top = 120
          Width = 297
          Height = 81
          BevelOuter = bvLowered
          TabOrder = 2
          object Label4: TLabel
            Left = 8
            Top = 8
            Width = 61
            Height = 13
            Caption = 'Packet Type'
          end
          object Label5: TLabel
            Left = 10
            Top = 32
            Width = 59
            Height = 13
            Caption = 'Data Length'
          end
          object Label6: TLabel
            Left = 19
            Top = 56
            Width = 50
            Height = 13
            Caption = 'Poll Period'
          end
          object cbRFTxType: TComboBox
            Left = 80
            Top = 8
            Width = 81
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 0
            Text = 'NULL'
            OnChange = cbRFTxTypeChange
            Items.Strings = (
              'NULL'
              'POLL'
              'FHS'
              'DM1'
              'DH1'
              'HV1'
              'HV2'
              'HV3'
              'DV'
              'AUX'
              'DM3'
              'DH3'
              'DM5'
              'DH5'
              'EV3'
              'EV4'
              'EV5'
              '2-DH1'
              '2-EV3'
              '2-DH3'
              '2-EV5'
              '2-DH5'
              '3-EV3'
              '3-DH1'
              '3-DH3'
              '3-EV5'
              '3-DH5')
          end
          object edtRFTxDataLen: TEdit
            Left = 80
            Top = 32
            Width = 81
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 1
            Text = '0'
            OnExit = edtRFTxDataLenCheck
          end
          object edtRFTxPollPeriod: TEdit
            Left = 80
            Top = 56
            Width = 81
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 2
            Text = '2'
            OnExit = edtRFTxPollPeriodCheck
          end
        end
        object Panel3: TPanel
          Left = 320
          Top = 120
          Width = 417
          Height = 81
          BevelOuter = bvLowered
          TabOrder = 3
          object Label9: TLabel
            Left = 32
            Top = 60
            Width = 63
            Height = 13
            Caption = 'Access Code'
          end
          object Label10: TLabel
            Left = 99
            Top = 60
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object Label7: TLabel
            Left = 8
            Top = 26
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object Label8: TLabel
            Left = 64
            Top = 8
            Width = 56
            Height = 13
            Caption = 'BD Address'
          end
          object edtRFTxAccessCode7: TEdit
            Tag = 7
            Left = 115
            Top = 56
            Width = 25
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 0
            Text = '0'
            OnExit = edtRFTxAccessCodeCheck
          end
          object edtRFTxAccessCode6: TEdit
            Tag = 6
            Left = 139
            Top = 56
            Width = 25
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 1
            Text = '0'
          end
          object edtRFTxAccessCode5: TEdit
            Tag = 5
            Left = 163
            Top = 56
            Width = 25
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 2
            Text = '0'
          end
          object edtRFTxAccessCode4: TEdit
            Tag = 4
            Left = 187
            Top = 56
            Width = 25
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 3
            Text = '0'
          end
          object edtRFTxAccessCode3: TEdit
            Tag = 3
            Left = 211
            Top = 56
            Width = 25
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 4
            Text = '0'
          end
          object edtRFTxAccessCode2: TEdit
            Tag = 2
            Left = 235
            Top = 56
            Width = 25
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 5
            Text = '0'
          end
          object edtRFTxAccessCode1: TEdit
            Tag = 1
            Left = 259
            Top = 56
            Width = 25
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 6
            Text = '0'
          end
          object edtRFTxAccessCode0: TEdit
            Left = 283
            Top = 56
            Width = 25
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 7
            Text = '0'
          end
          object btnRFQueryBdAddr: TButton
            Left = 304
            Top = 8
            Width = 105
            Height = 25
            Caption = 'Query BD Address'
            TabOrder = 8
            OnClick = btnRFQueryBdAddrClick
          end
          object edtRFBDAddress: TEdit
            Left = 32
            Top = 24
            Width = 121
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 9
            Text = '00:00:00:00:5A:AD'
            OnExit = edtRFBDAddressCheck
          end
          object cbRFTxAccessCode: TCheckBox
            Left = 8
            Top = 59
            Width = 17
            Height = 17
            TabOrder = 10
          end
        end
        object Panel4: TPanel
          Left = 320
          Top = 48
          Width = 417
          Height = 65
          BevelOuter = bvLowered
          TabOrder = 4
          object Label11: TLabel
            Left = 104
            Top = 12
            Width = 26
            Height = 13
            Caption = 'Level'
          end
          object cbRFTxPowerCtrl: TCheckBox
            Left = 8
            Top = 6
            Width = 89
            Height = 17
            Caption = 'Power Control'
            Checked = True
            State = cbChecked
            TabOrder = 0
            OnClick = cbRFTxPowerCtrlClick
          end
          object edtRFTxLevel: TEdit
            Left = 136
            Top = 8
            Width = 41
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 1
            OnExit = edtRFTxLevelCheck
          end
          object cbRFTxWhiten: TCheckBox
            Left = 8
            Top = 40
            Width = 97
            Height = 17
            Caption = 'Whiten'
            TabOrder = 2
          end
          object btnRFChangeLevel: TButton
            Left = 225
            Top = 7
            Width = 83
            Height = 25
            Caption = 'Change Level'
            TabOrder = 3
            OnClick = btnRFChangeLevelClick
          end
          object StaticText1: TStaticText
            Left = 181
            Top = 12
            Width = 34
            Height = 17
            Caption = '(0'#65374'7)'
            TabOrder = 4
          end
        end
        object btnRFTxStart: TBitBtn
          Left = 552
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Start'
          TabOrder = 5
          OnClick = btnRFTxStartClick
          Kind = bkRetry
        end
        object btnRFTxStop: TBitBtn
          Left = 648
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Stop'
          TabOrder = 6
          OnClick = btnRFTxStopClick
          Kind = bkNo
        end
        object GroupBox3: TGroupBox
          Left = 320
          Top = 8
          Width = 185
          Height = 33
          TabOrder = 7
          object rbRFTx: TRadioButton
            Left = 16
            Top = 10
            Width = 49
            Height = 17
            Caption = 'TX'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object rbRFRx: TRadioButton
            Left = 88
            Top = 10
            Width = 50
            Height = 17
            Caption = 'RX'
            TabOrder = 1
          end
        end
      end
      object memRFResult: TRichEdit
        Left = 8
        Top = 248
        Width = 761
        Height = 161
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 2
      end
      object btnRFClearLog: TButton
        Left = 528
        Top = 216
        Width = 75
        Height = 25
        Caption = 'Clear log'
        TabOrder = 3
        OnClick = btnRFClearLogClick
      end
      object btnRFEnterTestMode: TButton
        Left = 616
        Top = 216
        Width = 113
        Height = 25
        Caption = 'Enter Test Mode'
        TabOrder = 4
        OnClick = btnRFEnterTestModeClick
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Packet Test'
      ImageIndex = 2
      TabVisible = False
      object Label12: TLabel
        Left = 392
        Top = 8
        Width = 89
        Height = 13
        Caption = 'Tester BD Address'
      end
      object Label21: TLabel
        Left = 560
        Top = 8
        Width = 82
        Height = 13
        Caption = 'DUT BD Address'
      end
      object Label29: TLabel
        Left = 376
        Top = 24
        Width = 11
        Height = 13
        Caption = '0x'
      end
      object Label30: TLabel
        Left = 536
        Top = 24
        Width = 11
        Height = 13
        Caption = '0x'
      end
      object sbPKT: TStatusBar
        Left = 0
        Top = 504
        Width = 809
        Height = 21
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object GroupBox4: TGroupBox
        Left = 8
        Top = 49
        Width = 321
        Height = 401
        Caption = '  Config  '
        TabOrder = 1
        object Label13: TLabel
          Left = 8
          Top = 12
          Width = 24
          Height = 13
          Caption = 'Type'
        end
        object Label14: TLabel
          Left = 56
          Top = 12
          Width = 59
          Height = 13
          Caption = 'Data Length'
        end
        object Label15: TLabel
          Left = 128
          Top = 12
          Width = 88
          Height = 13
          Caption = 'Poll Period (625us)'
        end
        object Label16: TLabel
          Left = 238
          Top = 12
          Width = 65
          Height = 13
          Caption = 'Packet Count'
        end
        object cbPKTDM1: TCheckBox
          Left = 8
          Top = 24
          Width = 45
          Height = 17
          Caption = 'DM1'
          Checked = True
          State = cbChecked
          TabOrder = 0
        end
        object edtPKTDM1DataLen: TEdit
          Left = 56
          Top = 24
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 1
          Text = '17'
          OnExit = edtPKTDataLenCheck
        end
        object edtPKTDM1PollPeriod: TEdit
          Left = 144
          Top = 24
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 2
          Text = '2'
          OnExit = edtPKTPollPeriodCheck
        end
        object edtPKTDM1PktCount: TEdit
          Left = 240
          Top = 24
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 3
          Text = '1000'
          OnExit = edtPKTCountCheck
        end
        object cbPKTDH1: TCheckBox
          Tag = 1
          Left = 8
          Top = 41
          Width = 45
          Height = 17
          Caption = 'DH1'
          Checked = True
          State = cbChecked
          TabOrder = 4
        end
        object edtPKTDH1DataLen: TEdit
          Tag = 1
          Left = 56
          Top = 45
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 5
          Text = '27'
          OnExit = edtPKTDataLenCheck
        end
        object edtPKTDH1PollPeriod: TEdit
          Tag = 1
          Left = 144
          Top = 41
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 6
          Text = '2'
        end
        object edtPKTDM3PktCount: TEdit
          Tag = 2
          Left = 240
          Top = 58
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 7
          Text = '1000'
        end
        object cbPKTDM3: TCheckBox
          Tag = 2
          Left = 8
          Top = 58
          Width = 45
          Height = 17
          Caption = 'DM3'
          Checked = True
          State = cbChecked
          TabOrder = 8
        end
        object edtPKTDM3DataLen: TEdit
          Tag = 2
          Left = 56
          Top = 66
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 9
          Text = '121'
          OnExit = edtPKTDataLenCheck
        end
        object edtPKTDM3PollPeriod: TEdit
          Tag = 2
          Left = 144
          Top = 58
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 10
          Text = '4'
        end
        object edtPKTDH3PktCount: TEdit
          Tag = 3
          Left = 240
          Top = 75
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 11
          Text = '1000'
        end
        object cbPKTDH3: TCheckBox
          Tag = 3
          Left = 8
          Top = 75
          Width = 45
          Height = 17
          Caption = 'DH3'
          Checked = True
          State = cbChecked
          TabOrder = 12
        end
        object edtPKTDH3DataLen: TEdit
          Tag = 3
          Left = 56
          Top = 87
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 13
          Text = '183'
          OnExit = edtPKTDataLenCheck
        end
        object edtPKTDH3PollPeriod: TEdit
          Tag = 3
          Left = 144
          Top = 75
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 14
          Text = '4'
        end
        object edtPKTDM5PktCount: TEdit
          Tag = 4
          Left = 240
          Top = 92
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 15
          Text = '1000'
        end
        object cbPKTDM5: TCheckBox
          Tag = 4
          Left = 8
          Top = 92
          Width = 45
          Height = 17
          Caption = 'DM5'
          Checked = True
          State = cbChecked
          TabOrder = 16
        end
        object edtPKTDM5DataLen: TEdit
          Tag = 4
          Left = 56
          Top = 108
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 17
          Text = '224'
          OnExit = edtPKTDataLenCheck
        end
        object edtPKTDM5PollPeriod: TEdit
          Tag = 4
          Left = 144
          Top = 92
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 18
          Text = '6'
        end
        object edtPKTDH5PktCount: TEdit
          Tag = 5
          Left = 240
          Top = 109
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 19
          Text = '1000'
        end
        object cbPKTDH5: TCheckBox
          Tag = 5
          Left = 8
          Top = 109
          Width = 45
          Height = 17
          Caption = 'DH5'
          Checked = True
          State = cbChecked
          TabOrder = 20
        end
        object edtPKTDH5DataLen: TEdit
          Tag = 5
          Left = 56
          Top = 129
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 21
          Text = '339'
          OnExit = edtPKTDataLenCheck
        end
        object edtPKTDH5PollPeriod: TEdit
          Tag = 5
          Left = 144
          Top = 109
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 22
          Text = '6'
        end
        object cbPKTHV1: TCheckBox
          Tag = 7
          Left = 8
          Top = 126
          Width = 45
          Height = 17
          Caption = 'HV1'
          TabOrder = 23
        end
        object cbPKTHV2: TCheckBox
          Tag = 8
          Left = 8
          Top = 143
          Width = 45
          Height = 17
          Caption = 'HV2'
          TabOrder = 24
        end
        object cbPKTHV3: TCheckBox
          Tag = 9
          Left = 8
          Top = 160
          Width = 45
          Height = 17
          Caption = 'HV3'
          TabOrder = 25
        end
        object cbPKTEV3: TCheckBox
          Tag = 10
          Left = 8
          Top = 177
          Width = 45
          Height = 17
          Caption = 'EV3'
          TabOrder = 26
        end
        object cbPKTEV4: TCheckBox
          Tag = 11
          Left = 8
          Top = 194
          Width = 45
          Height = 17
          Caption = 'EV4'
          TabOrder = 27
        end
        object cbPKTEV5: TCheckBox
          Tag = 12
          Left = 8
          Top = 211
          Width = 45
          Height = 17
          Caption = 'EV5'
          TabOrder = 28
        end
        object edtPKTHV1PktCount: TEdit
          Tag = 7
          Left = 240
          Top = 126
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 29
          Text = '1000'
        end
        object edtPKTHV1PollPeriod: TEdit
          Tag = 7
          Left = 144
          Top = 126
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 30
          Text = '2'
        end
        object edtPKTHV2PktCount: TEdit
          Tag = 8
          Left = 240
          Top = 143
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 31
          Text = '1000'
        end
        object edtPKTHV2PollPeriod: TEdit
          Tag = 8
          Left = 144
          Top = 143
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 32
          Text = '4'
        end
        object edtPKTHV3PktCount: TEdit
          Tag = 9
          Left = 240
          Top = 160
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 33
          Text = '1000'
        end
        object edtPKTHV3PollPeriod: TEdit
          Tag = 9
          Left = 144
          Top = 160
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 34
          Text = '6'
        end
        object edtPKTEV3PktCount: TEdit
          Tag = 10
          Left = 240
          Top = 177
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 35
          Text = '1000'
        end
        object edtPKTEV3PollPeriod: TEdit
          Tag = 10
          Left = 144
          Top = 177
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 36
          Text = '6'
        end
        object edtPKTEV4PktCount: TEdit
          Tag = 11
          Left = 240
          Top = 194
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 37
          Text = '1000'
        end
        object edtPKTEV4PollPeriod: TEdit
          Tag = 11
          Left = 144
          Top = 194
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 38
          Text = '16'
        end
        object edtPKTEV5PollPeriod: TEdit
          Tag = 12
          Left = 144
          Top = 211
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 39
          Text = '16'
        end
        object edtPKTDH1PktCount: TEdit
          Tag = 1
          Left = 240
          Top = 41
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 40
          Text = '1000'
        end
        object edtPKTEV5PktCount: TEdit
          Tag = 12
          Left = 240
          Top = 211
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 41
          Text = '1000'
        end
        object cbPK2DH1: TCheckBox
          Left = 8
          Top = 228
          Width = 49
          Height = 17
          Caption = '2-DH1'
          TabOrder = 42
        end
        object edtPKT2DH1PollPeriod: TEdit
          Left = 144
          Top = 228
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 43
          Text = '2'
        end
        object edtPKT2EV3PollPeriod: TEdit
          Left = 144
          Top = 245
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 44
          Text = '6'
        end
        object edtPKT2DH3PollPeriod: TEdit
          Left = 144
          Top = 262
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 45
          Text = '4'
        end
        object edtPKT2EV5PollPeriod: TEdit
          Left = 144
          Top = 279
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 46
          Text = '16'
        end
        object edtPKT2DH5PollPeriod: TEdit
          Left = 144
          Top = 296
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 47
          Text = '6'
        end
        object edtPKT3EV3PollPeriod: TEdit
          Left = 144
          Top = 313
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 48
          Text = '6'
        end
        object edtPKT3DH1PollPeriod: TEdit
          Left = 144
          Top = 330
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 49
          Text = '2'
        end
        object edtPKT3DH3PollPeriod: TEdit
          Left = 144
          Top = 347
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 50
          Text = '4'
        end
        object edtPKT3EV5PollPeriod: TEdit
          Left = 144
          Top = 364
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 51
          Text = '16'
        end
        object edtPKT3DH5PollPeriod: TEdit
          Left = 144
          Top = 381
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 52
          Text = '6'
        end
        object edtPKT2DH1PktCount: TEdit
          Left = 240
          Top = 228
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 53
          Text = '1000'
        end
        object edtPKT2EV3PktCount: TEdit
          Left = 240
          Top = 245
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 54
          Text = '1000'
        end
        object edtPKT2DH3PktCount: TEdit
          Left = 240
          Top = 262
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 55
          Text = '1000'
        end
        object edtPKT2EV5PktCount: TEdit
          Left = 240
          Top = 279
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 56
          Text = '1000'
        end
        object edtPKT2DH5PktCount: TEdit
          Left = 240
          Top = 296
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 57
          Text = '1000'
        end
        object edtPKT3EV3PktCount: TEdit
          Left = 240
          Top = 313
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 58
          Text = '1000'
        end
        object edtPKT3DH1PktCount: TEdit
          Left = 240
          Top = 330
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 59
          Text = '1000'
        end
        object edtPKT3DH3PktCount: TEdit
          Left = 240
          Top = 347
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 60
          Text = '1000'
        end
        object edtPKT3EV5PktCount: TEdit
          Left = 240
          Top = 364
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 61
          Text = '1000'
        end
        object edtPKT3DH5PktCount: TEdit
          Left = 240
          Top = 381
          Width = 49
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 62
          Text = '1000'
        end
        object cbPK2EV3: TCheckBox
          Left = 8
          Top = 245
          Width = 57
          Height = 17
          Caption = '2-EV3'
          TabOrder = 63
        end
        object cbPK2DH3: TCheckBox
          Left = 8
          Top = 262
          Width = 57
          Height = 17
          Caption = '2-DH3'
          TabOrder = 64
        end
        object cbPK2EV5: TCheckBox
          Left = 8
          Top = 279
          Width = 57
          Height = 18
          Caption = '2-EV5'
          TabOrder = 65
        end
        object cbPK2DH5: TCheckBox
          Left = 8
          Top = 296
          Width = 57
          Height = 17
          Caption = '2-DH5'
          TabOrder = 66
        end
        object cbPK3EV3: TCheckBox
          Left = 8
          Top = 313
          Width = 57
          Height = 17
          Caption = '3-EV3'
          TabOrder = 67
        end
        object cbPK3DH1: TCheckBox
          Left = 8
          Top = 330
          Width = 57
          Height = 17
          Caption = '3-DH1'
          TabOrder = 68
        end
        object cbPK3DH3: TCheckBox
          Left = 8
          Top = 347
          Width = 57
          Height = 17
          Caption = '3-DH3'
          TabOrder = 69
        end
        object cbPK3EV5: TCheckBox
          Left = 8
          Top = 364
          Width = 49
          Height = 17
          Caption = '3-EV5'
          TabOrder = 70
        end
        object cbPK3DH5: TCheckBox
          Left = 8
          Top = 381
          Width = 57
          Height = 17
          Caption = '3-DH5'
          TabOrder = 71
        end
      end
      object GroupBox5: TGroupBox
        Tag = 6
        Left = 376
        Top = 48
        Width = 121
        Height = 401
        Caption = '  Tester Monitor  '
        TabOrder = 2
        object Label18: TLabel
          Left = 8
          Top = 12
          Width = 51
          Height = 13
          Caption = 'TX Conunt'
        end
        object Label19: TLabel
          Left = 64
          Top = 12
          Width = 46
          Height = 13
          Caption = 'RX Count'
        end
        object edtPKTTesterDM1TXCount: TEdit
          Left = 8
          Top = 24
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 0
          Text = '0'
        end
        object edtPKTTesterDM1RXCount: TEdit
          Left = 64
          Top = 24
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 1
          Text = '0'
        end
        object edtPKTTesterDH1TXCount: TEdit
          Tag = 1
          Left = 8
          Top = 41
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 2
          Text = '0'
        end
        object edtPKTTesterDH1RXCount: TEdit
          Tag = 1
          Left = 64
          Top = 41
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 3
          Text = '0'
        end
        object edtPKTTesterDM3TXCount: TEdit
          Tag = 2
          Left = 8
          Top = 58
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 4
          Text = '0'
        end
        object edtPKTTesterDM3RXCount: TEdit
          Tag = 2
          Left = 64
          Top = 58
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 5
          Text = '0'
        end
        object edtPKTTesterDH3TXCount: TEdit
          Tag = 3
          Left = 8
          Top = 75
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 6
          Text = '0'
        end
        object edtPKTTesterDH3RXCount: TEdit
          Tag = 3
          Left = 64
          Top = 75
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 7
          Text = '0'
        end
        object edtPKTTesterDM5TXCount: TEdit
          Tag = 4
          Left = 8
          Top = 92
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 8
          Text = '0'
        end
        object edtPKTTesterDM5RXCount: TEdit
          Tag = 4
          Left = 64
          Top = 92
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 9
          Text = '0'
        end
        object edtPKTTesterDH5TXCount: TEdit
          Tag = 5
          Left = 8
          Top = 109
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 10
          Text = '0'
        end
        object edtPKTTesterDH5RXCount: TEdit
          Tag = 5
          Left = 64
          Top = 109
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 11
          Text = '0'
        end
        object edtPKTTesterHV1TXCount: TEdit
          Tag = 7
          Left = 8
          Top = 126
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 12
          Text = '0'
        end
        object edtPKTTesterHV1RXCount: TEdit
          Tag = 7
          Left = 64
          Top = 126
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 13
          Text = '0'
        end
        object edtPKTTesterHV2TXCount: TEdit
          Tag = 8
          Left = 8
          Top = 143
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 14
          Text = '0'
        end
        object edtPKTTesterHV2RXCount: TEdit
          Tag = 8
          Left = 64
          Top = 143
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 15
          Text = '0'
        end
        object edtPKTTesterHV3TXCount: TEdit
          Tag = 9
          Left = 8
          Top = 160
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 16
          Text = '0'
        end
        object edtPKTTesterHV3RXCount: TEdit
          Tag = 9
          Left = 64
          Top = 160
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 17
          Text = '0'
        end
        object edtPKTTesterEV3TXCount: TEdit
          Tag = 10
          Left = 8
          Top = 177
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 18
          Text = '0'
        end
        object edtPKTTesterEV3RXCount: TEdit
          Tag = 10
          Left = 64
          Top = 177
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 19
          Text = '0'
        end
        object edtPKTTesterEV4TXCount: TEdit
          Tag = 11
          Left = 8
          Top = 194
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 20
          Text = '0'
        end
        object edtPKTTesterEV4RXCount: TEdit
          Tag = 11
          Left = 64
          Top = 194
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 21
          Text = '0'
        end
        object edtPKTTesterEV5TXCount: TEdit
          Tag = 12
          Left = 8
          Top = 211
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 22
          Text = '0'
        end
        object edtPKTTesterEV5RXCount: TEdit
          Tag = 12
          Left = 64
          Top = 211
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 23
          Text = '0'
        end
        object edtPKTTester2DH1TXCount: TEdit
          Left = 8
          Top = 228
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 24
          Text = '0'
        end
        object edtPKTTester2EV3TXCount: TEdit
          Left = 8
          Top = 245
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 25
          Text = '0'
        end
        object edtPKTTester2DH3TXCount: TEdit
          Left = 8
          Top = 262
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 26
          Text = '0'
        end
        object edtPKTTester2EV5TXCount: TEdit
          Left = 8
          Top = 279
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 27
          Text = '0'
        end
        object edtPKTTester2DH5TXCount: TEdit
          Left = 8
          Top = 296
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 28
          Text = '0'
        end
        object edtPKTTester3EV3TXCount: TEdit
          Left = 8
          Top = 313
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 29
          Text = '0'
        end
        object edtPKTTester3DH1TXCount: TEdit
          Left = 8
          Top = 330
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 30
          Text = '0'
        end
        object edtPKTTester3DH3TXCount: TEdit
          Left = 8
          Top = 347
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 31
          Text = '0'
        end
        object edtPKTTester3EV5TXCount: TEdit
          Left = 8
          Top = 364
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 32
          Text = '0'
        end
        object edtPKTTester3DH5TXCount: TEdit
          Left = 8
          Top = 381
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 33
          Text = '0'
        end
        object edtPKTTester2DH1RXCount: TEdit
          Left = 64
          Top = 228
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 34
          Text = '0'
        end
        object edtPKTTester2EV3RXCount: TEdit
          Left = 64
          Top = 245
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 35
          Text = '0'
        end
        object edtPKTTester2DH3RXCount: TEdit
          Left = 64
          Top = 262
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 36
          Text = '0'
        end
        object edtPKTTester2EV5RXCount: TEdit
          Left = 64
          Top = 279
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 37
          Text = '0'
        end
        object edtPKTTester2DH5RXCount: TEdit
          Left = 64
          Top = 296
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 38
          Text = '0'
        end
        object edtPKTTester3EV3RXCount: TEdit
          Left = 64
          Top = 313
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 39
          Text = '0'
        end
        object edtPKTTester3DH1RXCount: TEdit
          Left = 64
          Top = 330
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 40
          Text = '0'
        end
        object edtPKTTester3DH3RXCount: TEdit
          Left = 64
          Top = 347
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 41
          Text = '0'
        end
        object edtPKTTester3EV5RXCount: TEdit
          Left = 64
          Top = 364
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 42
          Text = '0'
        end
        object edtPKTTester3DH5RXCount: TEdit
          Left = 64
          Top = 381
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 43
          Text = '0'
        end
      end
      object stPKTTesterBDAddr: TStaticText
        Left = 392
        Top = 24
        Width = 105
        Height = 17
        Alignment = taCenter
        AutoSize = False
        BorderStyle = sbsSunken
        Color = clMoneyGreen
        ParentColor = False
        TabOrder = 3
      end
      object stPKTDUTBDAddr: TStaticText
        Left = 552
        Top = 24
        Width = 105
        Height = 17
        Alignment = taCenter
        AutoSize = False
        BorderStyle = sbsSunken
        Color = clMoneyGreen
        ParentColor = False
        TabOrder = 4
      end
      object GroupBox6: TGroupBox
        Left = 536
        Top = 48
        Width = 121
        Height = 401
        Caption = '  DUT Monitor  '
        TabOrder = 5
        object Label17: TLabel
          Left = 8
          Top = 12
          Width = 45
          Height = 13
          Caption = 'TX Count'
        end
        object Label22: TLabel
          Left = 64
          Top = 12
          Width = 46
          Height = 13
          Caption = 'RX Count'
        end
        object edtPKTDUTDM1TXCount: TEdit
          Left = 8
          Top = 24
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 0
          Text = '0'
        end
        object edtPKTDUTDH1TXCount: TEdit
          Left = 8
          Top = 41
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 1
          Text = '0'
        end
        object edtPKTDUTDM3TXCount: TEdit
          Left = 8
          Top = 58
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 2
          Text = '0'
        end
        object edtPKTDUTDH3TXCount: TEdit
          Left = 8
          Top = 75
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 3
          Text = '0'
        end
        object edtPKTDUTDM5TXCount: TEdit
          Left = 8
          Top = 92
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 4
          Text = '0'
        end
        object edtPKTDUTDH5TXCount: TEdit
          Left = 8
          Top = 109
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 5
          Text = '0'
        end
        object edtPKTDUTHV1TXCount: TEdit
          Left = 8
          Top = 126
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 6
          Text = '0'
        end
        object edtPKTDUTHV2TXCount: TEdit
          Left = 8
          Top = 143
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 7
          Text = '0'
        end
        object edtPKTDUTHV3TXCount: TEdit
          Left = 8
          Top = 160
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 8
          Text = '0'
        end
        object edtPKTDUTEV3TXCount: TEdit
          Left = 8
          Top = 177
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 9
          Text = '0'
        end
        object edtPKTDUTEV4TXCount: TEdit
          Left = 8
          Top = 194
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 10
          Text = '0'
        end
        object edtPKTDUTEV5TXCount: TEdit
          Left = 8
          Top = 211
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 11
          Text = '0'
        end
        object edtPKTDUTDM1RXCount: TEdit
          Left = 64
          Top = 24
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 12
          Text = '0'
        end
        object edtPKTDUTDH1RXCount: TEdit
          Left = 64
          Top = 41
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 13
          Text = '0'
        end
        object edtPKTDUTDM3RXCount: TEdit
          Left = 64
          Top = 58
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 14
          Text = '0'
        end
        object edtPKTDUTDH3RXCount: TEdit
          Left = 64
          Top = 75
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 15
          Text = '0'
        end
        object edtPKTDUTDM5RXCount: TEdit
          Left = 64
          Top = 92
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 16
          Text = '0'
        end
        object edtPKTDUTDH5RXCount: TEdit
          Left = 64
          Top = 109
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 17
          Text = '0'
        end
        object edtPKTDUTHV1RXCount: TEdit
          Left = 64
          Top = 126
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 18
          Text = '0'
        end
        object edtPKTDUTHV2RXCount: TEdit
          Left = 64
          Top = 143
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 19
          Text = '0'
        end
        object edtPKTDUTHV3RXCount: TEdit
          Left = 64
          Top = 160
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 20
          Text = '0'
        end
        object edtPKTDUTEV3RXCount: TEdit
          Left = 64
          Top = 177
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 21
          Text = '0'
        end
        object edtPKTDUTEV4RXCount: TEdit
          Left = 64
          Top = 194
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 22
          Text = '0'
        end
        object edtPKTDUTEV5RXCount: TEdit
          Left = 64
          Top = 211
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 23
          Text = '0'
        end
        object edtPKTDUT2DH1TXCount: TEdit
          Left = 8
          Top = 228
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 24
          Text = '0'
        end
        object edtPKTDUT2EV3TXCount: TEdit
          Left = 8
          Top = 245
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 25
          Text = '0'
        end
        object edtPKTDUT2DH3TXCount: TEdit
          Left = 8
          Top = 262
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 26
          Text = '0'
        end
        object edtPKTDUT2EV5TXCount: TEdit
          Left = 8
          Top = 279
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 27
          Text = '0'
        end
        object edtPKTDUT2DH5TXCount: TEdit
          Left = 8
          Top = 296
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 28
          Text = '0'
        end
        object edtPKTDUT3EV3TXCount: TEdit
          Left = 8
          Top = 313
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 29
          Text = '0'
        end
        object edtPKTDUT3DH1TXCount: TEdit
          Left = 8
          Top = 330
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 30
          Text = '0'
        end
        object edtPKTDUT3DH3TXCount: TEdit
          Left = 8
          Top = 347
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 31
          Text = '0'
        end
        object edtPKTDUT3EV5TXCount: TEdit
          Left = 8
          Top = 364
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 32
          Text = '0'
        end
        object edtPKTDUT3DH5TXCount: TEdit
          Left = 8
          Top = 381
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 33
          Text = '0'
        end
        object edtPKTDUT2DH1RXCount: TEdit
          Left = 64
          Top = 228
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 34
          Text = '0'
        end
        object edtPKTDUT2EV3RXCount: TEdit
          Left = 64
          Top = 245
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 35
          Text = '0'
        end
        object edtPKTDUT2DH3RXCount: TEdit
          Left = 64
          Top = 262
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 36
          Text = '0'
        end
        object edtPKTDUT2EV5RXCount: TEdit
          Left = 64
          Top = 279
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 37
          Text = '0'
        end
        object edtPKTDUT2DH5RXCount: TEdit
          Left = 64
          Top = 296
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 38
          Text = '0'
        end
        object edtPKTDUT3EV3RXCount: TEdit
          Left = 64
          Top = 313
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 39
          Text = '0'
        end
        object edtPKTDUT3DH1RXCount: TEdit
          Left = 64
          Top = 330
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 40
          Text = '0'
        end
        object edtPKTDUT3DH3RXCount: TEdit
          Left = 64
          Top = 347
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 41
          Text = '0'
        end
        object edtPKTDUT3EV5RXCount: TEdit
          Left = 64
          Top = 364
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 42
          Text = '0'
        end
        object edtPKTDUT3DH5RXCount: TEdit
          Left = 64
          Top = 381
          Width = 50
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ReadOnly = True
          TabOrder = 43
          Text = '0'
        end
      end
      object GroupBox8: TGroupBox
        Left = 8
        Top = 0
        Width = 321
        Height = 49
        Caption = '  DUT  '
        TabOrder = 6
        object Label26: TLabel
          Left = 40
          Top = 8
          Width = 46
          Height = 13
          Caption = 'COM Port'
        end
        object Label20: TLabel
          Left = 128
          Top = 8
          Width = 51
          Height = 13
          Caption = 'Baud Rate'
        end
        object shpPKTConnect: TShape
          Left = 8
          Top = 16
          Width = 17
          Height = 20
          Brush.Color = clRed
          Shape = stCircle
        end
        object cbPKTCOM: TComboBox
          Left = 32
          Top = 24
          Width = 65
          Height = 21
          Style = csDropDownList
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 0
          ParentFont = False
          TabOrder = 0
          OnChange = cbPKTCOMChange
        end
        object cbPKTBaudRate: TComboBox
          Left = 120
          Top = 24
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 1
          Text = 'Auto'
          OnChange = cbPKTBaudRateChange
          Items.Strings = (
            'Auto'
            '57600'
            '115200'
            '230400'
            '460800'
            '921600')
        end
        object btnPKTConnectDUT: TButton
          Left = 208
          Top = 16
          Width = 97
          Height = 25
          Caption = 'Enter META mode'
          TabOrder = 2
          OnClick = btnPKTConnectDUTClick
        end
      end
      object btnPKTStart: TBitBtn
        Left = 680
        Top = 24
        Width = 60
        Height = 25
        Caption = 'Start'
        TabOrder = 7
        OnClick = btnPKTStartClick
        Kind = bkRetry
      end
      object btnPKTStop: TBitBtn
        Left = 680
        Top = 56
        Width = 60
        Height = 25
        Caption = 'Stop'
        TabOrder = 8
        OnClick = btnPKTStopClick
        Kind = bkNo
      end
      object memPKTResult: TRichEdit
        Left = 8
        Top = 456
        Width = 761
        Height = 49
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 9
      end
      object btnPKTClearLog: TButton
        Left = 680
        Top = 428
        Width = 50
        Height = 17
        Caption = 'Clear log'
        TabOrder = 10
        OnClick = btnPKTClearLogClick
      end
    end
    object tsSCT: TTabSheet
      Caption = 'Script Test'
      ImageIndex = 3
      TabVisible = False
      object memSCTResult: TRichEdit
        Left = 8
        Top = 304
        Width = 761
        Height = 121
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object sbSCT: TStatusBar
        Left = 0
        Top = 496
        Width = 809
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object stSCTFile: TStaticText
        Left = 64
        Top = 8
        Width = 705
        Height = 17
        AutoSize = False
        BorderStyle = sbsSunken
        Color = clSkyBlue
        ParentColor = False
        TabOrder = 2
      end
      object btnSCTFile: TButton
        Left = 8
        Top = 8
        Width = 49
        Height = 17
        Caption = 'File'
        TabOrder = 3
        OnClick = btnSCTFileClick
      end
      object btnSCTStop: TBitBtn
        Left = 696
        Top = 72
        Width = 75
        Height = 25
        Caption = 'Stop'
        TabOrder = 4
        OnClick = btnSCTStopClick
        Kind = bkNo
      end
      object btnSCTStart: TBitBtn
        Left = 696
        Top = 40
        Width = 75
        Height = 25
        Caption = 'Start'
        TabOrder = 5
        OnClick = btnSCTStartClick
        Kind = bkRetry
      end
      object lbSCT: TListBox
        Left = 8
        Top = 32
        Width = 681
        Height = 265
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 6
      end
      object btnSCTClearLog: TButton
        Left = 696
        Top = 264
        Width = 75
        Height = 25
        Caption = 'Clear log'
        TabOrder = 7
        OnClick = btnSCTClearLogClick
      end
    end
    object m_tsMT: TTabSheet
      Caption = 'Module Test'
      ImageIndex = 6
      TabVisible = False
      DesignSize = (
        809
        525)
      object Label64: TLabel
        Left = 616
        Top = 96
        Width = 84
        Height = 18
        Caption = 'Repeat Times:'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object m_btnMTRun: TSpeedButton
        Left = 680
        Top = 168
        Width = 97
        Height = 33
        Caption = 'Run'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        OnClick = m_btnMTRunClick
      end
      object grpTestItemList: TGroupBox
        Left = 8
        Top = 8
        Width = 241
        Height = 473
        Caption = 'Test Title'
        Color = clSkyBlue
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        TabOrder = 0
        object lblItem1: TStaticText
          Left = 8
          Top = 25
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'Process'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object lblItem2: TStaticText
          Left = 8
          Top = 45
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Visible = False
        end
        object lblItem3: TStaticText
          Left = 8
          Top = 65
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          Visible = False
        end
        object lblItem9: TStaticText
          Left = 8
          Top = 185
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          Visible = False
        end
        object lblItem8: TStaticText
          Left = 8
          Top = 165
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          Visible = False
        end
        object lblItem10: TStaticText
          Left = 8
          Top = 205
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          Visible = False
        end
        object lblItem11: TStaticText
          Left = 8
          Top = 225
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          Visible = False
        end
        object lblItem13: TStaticText
          Left = 8
          Top = 265
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 7
          Visible = False
        end
        object lblItem12: TStaticText
          Left = 8
          Top = 245
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          Visible = False
        end
        object lblItem14: TStaticText
          Left = 8
          Top = 285
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 9
          Visible = False
        end
        object lblItem15: TStaticText
          Left = 8
          Top = 305
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 10
          Visible = False
        end
        object lblItem16: TStaticText
          Left = 8
          Top = 325
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 12
          Visible = False
        end
        object lblItem4: TStaticText
          Left = 8
          Top = 85
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 13
          Visible = False
        end
        object lblItem5: TStaticText
          Left = 8
          Top = 105
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 14
          Visible = False
        end
        object lblItem6: TStaticText
          Left = 8
          Top = 125
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 15
          Visible = False
        end
        object lblItem7: TStaticText
          Left = 8
          Top = 145
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 16
          Visible = False
        end
        object scrTestItemList: TScrollBar
          Left = 224
          Top = 8
          Width = 17
          Height = 465
          Kind = sbVertical
          LargeChange = 18
          Max = 17
          PageSize = 0
          TabOrder = 11
          TabStop = False
          OnChange = scrTestItemListChange
        end
        object lblItem17: TStaticText
          Tag = 16
          Left = 8
          Top = 345
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 17
          Visible = False
        end
        object lblItem18: TStaticText
          Tag = 17
          Left = 8
          Top = 365
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 18
          Visible = False
        end
        object lblItem19: TStaticText
          Tag = 17
          Left = 8
          Top = 385
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 19
          Visible = False
        end
        object lblItem20: TStaticText
          Tag = 17
          Left = 8
          Top = 405
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 20
          Visible = False
        end
        object lblItem21: TStaticText
          Tag = 17
          Left = 8
          Top = 425
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 21
          Visible = False
        end
        object lblItem22: TStaticText
          Tag = 17
          Left = 8
          Top = 445
          Width = 210
          Height = 21
          AutoSize = False
          Caption = 'StaticText1'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 22
          Visible = False
        end
      end
      object m_sbMT: TStatusBar
        Left = 0
        Top = 496
        Width = 809
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object m_lblMTStatus: TStaticText
        Left = 264
        Top = 8
        Width = 249
        Height = 49
        Alignment = taCenter
        AutoSize = False
        BevelKind = bkTile
        Caption = 'Status'
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlue
        Font.Height = -27
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        TabOrder = 2
      end
      object m_edtMTRepeat: TEdit
        Tag = 1
        Left = 616
        Top = 120
        Width = 81
        Height = 23
        Anchors = [akTop, akRight]
        AutoSize = False
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlue
        Font.Height = -15
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
      object GroupBox24: TGroupBox
        Left = 264
        Top = 56
        Width = 249
        Height = 145
        Caption = 'Test Items'
        Color = clMenuBar
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        TabOrder = 4
        object m_rbMTTestItem0: TRadioButton
          Left = 8
          Top = 24
          Width = 230
          Height = 17
          Caption = 'TBD'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object m_rbMTTestItem1: TRadioButton
          Tag = 1
          Left = 8
          Top = 48
          Width = 230
          Height = 17
          Caption = 'TBD'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object m_rbMTTestItem2: TRadioButton
          Tag = 2
          Left = 8
          Top = 72
          Width = 230
          Height = 17
          Caption = 'TBD'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object m_rbMTTestItem3: TRadioButton
          Tag = 3
          Left = 8
          Top = 96
          Width = 230
          Height = 17
          Caption = 'TBD'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object m_rbMTTestItem4: TRadioButton
          Tag = 4
          Left = 8
          Top = 120
          Width = 230
          Height = 17
          Caption = 'TBD'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
        end
      end
      object m_edtMTLog: TRichEdit
        Left = 264
        Top = 232
        Width = 497
        Height = 217
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        HideScrollBars = False
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          'Logging Window')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 5
        WordWrap = False
      end
      object GroupBox26: TGroupBox
        Left = 520
        Top = 4
        Width = 281
        Height = 73
        Caption = '  BT2  '
        TabOrder = 6
        object m_shpMTConnect: TShape
          Left = 8
          Top = 40
          Width = 17
          Height = 17
          Brush.Color = clRed
          Shape = stCircle
        end
        object Label66: TLabel
          Left = 40
          Top = 32
          Width = 46
          Height = 13
          Caption = 'COM Port'
        end
        object Label68: TLabel
          Left = 112
          Top = 32
          Width = 51
          Height = 13
          Caption = 'Baud Rate'
        end
        object m_cbMTBT2COM: TComboBox
          Left = 32
          Top = 48
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 0
          TabOrder = 0
        end
        object m_cbMTBT2Baud: TComboBox
          Left = 104
          Top = 48
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 1
          Text = 'Auto'
          Items.Strings = (
            'Auto'
            '57600'
            '115200'
            '230400'
            '460800'
            '921600')
        end
        object m_btnMTConnect: TButton
          Left = 176
          Top = 40
          Width = 97
          Height = 25
          Caption = 'Enter META mode'
          TabOrder = 2
          OnClick = m_btnMTConnectClick
        end
        object m_cbMETAMode: TCheckBox
          Left = 40
          Top = 8
          Width = 97
          Height = 17
          Caption = 'META mode'
          Checked = True
          State = cbChecked
          TabOrder = 3
          OnClick = m_cbMETAModeClick
        end
      end
      object m_btnMTReload: TButton
        Left = 528
        Top = 168
        Width = 97
        Height = 33
        Caption = 'Reload'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        OnClick = m_btnMTReloadClick
      end
    end
    object tsTT: TTabSheet
      Caption = 'Throughput Test'
      ImageIndex = 4
      TabVisible = False
      object memTTResult: TRichEdit
        Left = 8
        Top = 296
        Width = 761
        Height = 129
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object sbTT: TStatusBar
        Left = 0
        Top = 496
        Width = 809
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object btnTHClearLog: TButton
        Left = 8
        Top = 264
        Width = 75
        Height = 25
        Caption = 'Clear log'
        TabOrder = 2
        OnClick = btnTHClearLogClick
      end
      object GroupBox10: TGroupBox
        Left = 8
        Top = 0
        Width = 361
        Height = 137
        Caption = '  ACL Control   '
        TabOrder = 3
        object Panel5: TPanel
          Left = 8
          Top = 16
          Width = 345
          Height = 113
          BevelOuter = bvLowered
          TabOrder = 0
          object Label43: TLabel
            Left = 216
            Top = 8
            Width = 87
            Height = 13
            Caption = 'Connection Status'
          end
          object Label32: TLabel
            Left = 72
            Top = 4
            Width = 55
            Height = 13
            Caption = 'BD address'
          end
          object Label31: TLabel
            Left = 16
            Top = 16
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object stTTACLStatus: TStaticText
            Left = 208
            Top = 24
            Width = 97
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 0
          end
          object edtTTBDAddr: TEdit
            Left = 32
            Top = 16
            Width = 121
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 1
            Text = '00:00:00:00:5A:AD'
            OnExit = edtTTBdAddrCheck
          end
          object cbTTDM1: TCheckBox
            Left = 2
            Top = 40
            Width = 45
            Height = 17
            Caption = 'DM1'
            Checked = True
            State = cbChecked
            TabOrder = 2
          end
          object cbTTDM3: TCheckBox
            Left = 2
            Top = 64
            Width = 50
            Height = 17
            Caption = 'DM3'
            Checked = True
            State = cbChecked
            TabOrder = 3
          end
          object cbTTDM5: TCheckBox
            Left = 2
            Top = 88
            Width = 45
            Height = 17
            Caption = 'DM5'
            Checked = True
            State = cbChecked
            TabOrder = 4
          end
          object cbTTDH1: TCheckBox
            Left = 52
            Top = 40
            Width = 45
            Height = 17
            Caption = 'DH1'
            Checked = True
            State = cbChecked
            TabOrder = 5
          end
          object cbTTDH3: TCheckBox
            Left = 52
            Top = 64
            Width = 45
            Height = 17
            Caption = 'DH3'
            Checked = True
            State = cbChecked
            TabOrder = 6
          end
          object cbTTDH5: TCheckBox
            Left = 52
            Top = 88
            Width = 45
            Height = 17
            Caption = 'DH5'
            Checked = True
            State = cbChecked
            TabOrder = 7
          end
          object btnTTConnect: TButton
            Left = 208
            Top = 48
            Width = 65
            Height = 25
            Caption = 'Connect'
            TabOrder = 8
            OnClick = btnTTConnectClick
          end
          object btnTTChangeACLPacketType: TButton
            Left = 208
            Top = 80
            Width = 135
            Height = 25
            Caption = 'Change ACL Packet Type'
            Enabled = False
            TabOrder = 9
            OnClick = btnTTChangeACLPacketTypeClick
          end
          object btnTTDisconnect: TButton
            Left = 280
            Top = 48
            Width = 65
            Height = 25
            Caption = 'Disconnect '
            Enabled = False
            TabOrder = 10
            OnClick = btnTTDisconnectClick
          end
          object m_cbTT2DH1: TCheckBox
            Left = 102
            Top = 40
            Width = 49
            Height = 17
            Caption = '2-DH1'
            TabOrder = 11
          end
          object m_cbTT2DH3: TCheckBox
            Left = 102
            Top = 64
            Width = 49
            Height = 17
            Caption = '2-DH3'
            TabOrder = 12
          end
          object m_cbTT2DH5: TCheckBox
            Left = 102
            Top = 88
            Width = 57
            Height = 17
            Caption = '2-DH5'
            TabOrder = 13
          end
          object m_cbTT3DH1: TCheckBox
            Left = 152
            Top = 40
            Width = 53
            Height = 17
            Caption = '3-DH1'
            TabOrder = 14
          end
          object m_cbTT3DH3: TCheckBox
            Left = 152
            Top = 64
            Width = 53
            Height = 17
            Caption = '3-DH3'
            TabOrder = 15
          end
          object m_cbTT3DH5: TCheckBox
            Left = 152
            Top = 88
            Width = 53
            Height = 17
            Caption = '3-DH5'
            TabOrder = 16
          end
        end
      end
      object GroupBox11: TGroupBox
        Left = 376
        Top = 136
        Width = 393
        Height = 121
        Caption = '  RX Throughput Test  '
        TabOrder = 4
        object Panel9: TPanel
          Left = 8
          Top = 64
          Width = 377
          Height = 41
          BevelOuter = bvLowered
          TabOrder = 0
          object Label40: TLabel
            Left = 72
            Top = 4
            Width = 43
            Height = 13
            Caption = 'RX bytes'
          end
          object Label42: TLabel
            Left = 152
            Top = 4
            Width = 108
            Height = 13
            Caption = 'RX throughput (byte/s)'
          end
          object stTTRxBytes: TStaticText
            Left = 64
            Top = 18
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
          object stTTRxThroughput: TStaticText
            Left = 160
            Top = 18
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
        end
        object TPanel
          Left = 8
          Top = 16
          Width = 377
          Height = 41
          BevelOuter = bvLowered
          TabOrder = 1
          object btnTTRxStart: TBitBtn
            Left = 208
            Top = 8
            Width = 75
            Height = 25
            Caption = 'Start'
            Enabled = False
            TabOrder = 0
            OnClick = btnTTRxStartClick
            Kind = bkRetry
          end
          object btnTTRxStop: TBitBtn
            Left = 288
            Top = 8
            Width = 75
            Height = 25
            Caption = 'Stop'
            TabOrder = 1
            OnClick = btnTTRxStopClick
            Kind = bkNo
          end
        end
      end
      object GroupBox12: TGroupBox
        Left = 376
        Top = 0
        Width = 393
        Height = 89
        Caption = '  Scan  '
        TabOrder = 5
        object Label35: TLabel
          Left = 64
          Top = 8
          Width = 52
          Height = 13
          Caption = 'Scan Type'
        end
        object m_cbTTScanType: TComboBox
          Left = 8
          Top = 24
          Width = 177
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 3
          TabOrder = 0
          Text = 'Enable Inquiry/Page Scan'
          Items.Strings = (
            'Disable Scan'
            'Enable Inquiry Scan Only'
            'Enable Page Scan Only'
            'Enable Inquiry/Page Scan')
        end
        object CheckBox1: TCheckBox
          Left = 8
          Top = 48
          Width = 169
          Height = 17
          Caption = 'Interlaced Inquiry Scan'
          TabOrder = 1
        end
        object CheckBox2: TCheckBox
          Left = 8
          Top = 64
          Width = 129
          Height = 17
          Caption = 'Interlaced Page Scan'
          TabOrder = 2
        end
        object btnTTScan: TButton
          Left = 280
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Scan'
          TabOrder = 3
          OnClick = btnTTScanClick
        end
      end
      object GroupBox13: TGroupBox
        Left = 376
        Top = 88
        Width = 393
        Height = 49
        Caption = '  Auto Accept  '
        TabOrder = 6
        object btnTTAutoAccept: TButton
          Left = 280
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Auto Accept'
          TabOrder = 0
          OnClick = btnTTAutoAcceptClick
        end
      end
      object GroupBox23: TGroupBox
        Left = 8
        Top = 136
        Width = 361
        Height = 121
        Caption = '  TX Throughput Test  '
        TabOrder = 7
        object Panel6: TPanel
          Left = 8
          Top = 16
          Width = 345
          Height = 49
          BevelOuter = bvLowered
          TabOrder = 0
          object Label38: TLabel
            Left = 96
            Top = 4
            Width = 65
            Height = 13
            Caption = 'Packet Count'
          end
          object Label37: TLabel
            Left = 8
            Top = 4
            Width = 59
            Height = 13
            Caption = 'Data Length'
          end
          object btnTTTxStart: TBitBtn
            Left = 182
            Top = 8
            Width = 75
            Height = 25
            Caption = 'Start'
            Enabled = False
            TabOrder = 0
            OnClick = btnTTTxStartClick
            Kind = bkRetry
          end
          object btnTTTxStop: TBitBtn
            Left = 262
            Top = 8
            Width = 75
            Height = 25
            Caption = 'Stop'
            TabOrder = 1
            OnClick = btnTTTxStopClick
            Kind = bkNo
          end
          object edtTTPacketCount: TEdit
            Left = 96
            Top = 20
            Width = 57
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 2
            Text = '1000'
            OnExit = edtTTPacketCountCheck
          end
          object edtTTDataLen: TEdit
            Left = 8
            Top = 20
            Width = 57
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 3
            Text = '339'
            OnExit = edtTTDataLenCheck
          end
        end
        object Panel7: TPanel
          Left = 8
          Top = 72
          Width = 345
          Height = 41
          BevelOuter = bvLowered
          TabOrder = 1
          object Label33: TLabel
            Left = 24
            Top = 4
            Width = 44
            Height = 13
            Caption = 'TX count'
          end
          object Label34: TLabel
            Left = 120
            Top = 4
            Width = 111
            Height = 13
            Caption = 'TX Throughput (byte/s)'
          end
          object stTTTxCount: TStaticText
            Left = 16
            Top = 18
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
          object stTTTxThroughput: TStaticText
            Left = 128
            Top = 18
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
        end
      end
    end
    object tsCT: TTabSheet
      Caption = 'Connection Test'
      ImageIndex = 5
      object memCTResult: TRichEdit
        Left = 8
        Top = 336
        Width = 793
        Height = 89
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object sbCT: TStatusBar
        Left = 0
        Top = 496
        Width = 809
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object GroupBox14: TGroupBox
        Left = 0
        Top = 0
        Width = 801
        Height = 297
        TabOrder = 2
        object GroupBox15: TGroupBox
          Left = 8
          Top = 8
          Width = 273
          Height = 105
          Caption = '  Local Device Information  '
          TabOrder = 0
          object Label47: TLabel
            Left = 16
            Top = 34
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object Label48: TLabel
            Left = 48
            Top = 16
            Width = 22
            Height = 13
            Caption = 'NAP'
          end
          object Label49: TLabel
            Left = 118
            Top = 16
            Width = 22
            Height = 13
            Caption = 'UAP'
          end
          object Label50: TLabel
            Left = 192
            Top = 16
            Width = 20
            Height = 13
            Caption = 'LAP'
          end
          object btnCTLDIRead: TButton
            Left = 40
            Top = 64
            Width = 75
            Height = 25
            Caption = 'Read'
            TabOrder = 0
            OnClick = btnCTLDIReadClick
          end
          object btnCTLDIWrite: TButton
            Left = 144
            Top = 64
            Width = 75
            Height = 25
            Caption = 'Write'
            TabOrder = 1
            OnClick = btnCTLDIWriteClick
          end
          object edtCTLDINAP3: TEdit
            Tag = 3
            Left = 32
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 2
            Text = '0'
            OnExit = edtCTLDINAPCheck
          end
          object edtCTLDINAP2: TEdit
            Tag = 2
            Left = 48
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 3
            Text = '0'
            OnExit = edtCTLDINAPCheck
          end
          object edtCTLDINAP1: TEdit
            Tag = 1
            Left = 64
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 4
            Text = '0'
            OnExit = edtCTLDINAPCheck
          end
          object edtCTLDINAP0: TEdit
            Left = 80
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 5
            Text = '0'
            OnExit = edtCTLDINAPCheck
          end
          object edtCTLDIUAP1: TEdit
            Tag = 1
            Left = 112
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 6
            Text = '0'
            OnExit = edtCTLDIUAPCheck
          end
          object edtCTLDIUAP0: TEdit
            Left = 128
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 7
            Text = '0'
            OnExit = edtCTLDIUAPCheck
          end
          object edtCTLDILAP5: TEdit
            Tag = 5
            Left = 160
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 8
            Text = '0'
            OnExit = edtCTLDILAPCheck
          end
          object edtCTLDILAP4: TEdit
            Tag = 4
            Left = 176
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 9
            Text = '0'
            OnExit = edtCTLDILAPCheck
          end
          object edtCTLDILAP3: TEdit
            Tag = 3
            Left = 192
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 10
            Text = '0'
            OnExit = edtCTLDILAPCheck
          end
          object edtCTLDILAP2: TEdit
            Tag = 2
            Left = 208
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 11
            Text = '0'
            OnExit = edtCTLDILAPCheck
          end
          object edtCTLDILAP1: TEdit
            Tag = 1
            Left = 224
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 12
            Text = '0'
            OnExit = edtCTLDILAPCheck
          end
          object edtCTLDILAP0: TEdit
            Left = 240
            Top = 32
            Width = 17
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 13
            Text = '0'
            OnExit = edtCTLDILAPCheck
          end
        end
        object GroupBox16: TGroupBox
          Left = 288
          Top = 120
          Width = 241
          Height = 177
          Caption = '  SCO Control    '
          TabOrder = 1
          object Label51: TLabel
            Left = 40
            Top = 128
            Width = 48
            Height = 13
            Caption = 'PIN code '
          end
          object Label52: TLabel
            Left = 16
            Top = 88
            Width = 61
            Height = 13
            Caption = 'Packet Type'
          end
          object Label59: TLabel
            Left = 140
            Top = 16
            Width = 87
            Height = 13
            Caption = 'Connection Status'
          end
          object Label60: TLabel
            Left = 10
            Top = 34
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object Label63: TLabel
            Left = 56
            Top = 16
            Width = 56
            Height = 13
            Caption = 'BD Address'
          end
          object Label36: TLabel
            Left = 16
            Top = 48
            Width = 70
            Height = 13
            Caption = 'TX Bandwitdth'
          end
          object Label39: TLabel
            Left = 4
            Top = 64
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object Label41: TLabel
            Left = 96
            Top = 48
            Width = 68
            Height = 13
            Caption = 'RX Bandwidth'
          end
          object Label44: TLabel
            Left = 84
            Top = 64
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object Label45: TLabel
            Left = 170
            Top = 48
            Width = 61
            Height = 13
            Caption = 'Max Latency'
          end
          object Label46: TLabel
            Left = 160
            Top = 64
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object Label61: TLabel
            Left = 88
            Top = 88
            Width = 78
            Height = 13
            Caption = 'Retransmit Effort'
          end
          object Label62: TLabel
            Left = 84
            Top = 108
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object btnCTEnterPIN: TButton
            Left = 168
            Top = 144
            Width = 65
            Height = 25
            Caption = 'Enter'
            Enabled = False
            TabOrder = 0
            OnClick = btnCTEnterPINClick
          end
          object edtCTPIN: TEdit
            Left = 16
            Top = 144
            Width = 97
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 1
            Text = '0000'
            OnExit = edtCTPINCheck
          end
          object btnCTConnectSCO: TButton
            Left = 168
            Top = 88
            Width = 65
            Height = 25
            Caption = 'Connect'
            Enabled = False
            TabOrder = 2
            OnClick = btnCTConnectSCOClick
          end
          object cbCTSCOPktType: TComboBox
            Left = 16
            Top = 104
            Width = 65
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            ItemHeight = 13
            ItemIndex = 0
            TabOrder = 3
            Text = 'HV1'
            Items.Strings = (
              'HV1'
              'HV2'
              'HV3'
              'EV3'
              'EV4'
              'EV5'
              '2-EV3'
              '3-EV3'
              '2-EV5'
              '3-EV5')
          end
          object stCTSCOStatus: TStaticText
            Left = 136
            Top = 32
            Width = 97
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 4
          end
          object btnCTDisconnectSCO: TButton
            Left = 168
            Top = 114
            Width = 65
            Height = 25
            Caption = 'Disconnect'
            Enabled = False
            TabOrder = 5
            OnClick = btnCTDisconnectSCOClick
          end
          object m_stCTSCOBDAddr: TStaticText
            Left = 24
            Top = 32
            Width = 105
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 6
          end
          object edtCTTxBandwidth: TEdit
            Left = 16
            Top = 64
            Width = 65
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 7
            Text = '1F40'
            OnExit = edtCTTxBandwidthCheck
          end
          object edtCTRxBandwidth: TEdit
            Left = 96
            Top = 64
            Width = 65
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 8
            Text = '1F40'
            OnExit = edtCTRxBandwidthCheck
          end
          object edtCTMaxLatency: TEdit
            Left = 172
            Top = 64
            Width = 65
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 9
            Text = '05'
            OnExit = edtCTMaxLatencyCheck
          end
          object edtCTRetransmitEffort: TEdit
            Left = 96
            Top = 104
            Width = 65
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 10
            Text = '0'
            OnExit = edtCTRetransmitEffortCheck
          end
        end
        object GroupBox17: TGroupBox
          Left = 288
          Top = 8
          Width = 233
          Height = 105
          Caption = '  Scan  '
          TabOrder = 2
          object Label53: TLabel
            Left = 64
            Top = 8
            Width = 52
            Height = 13
            Caption = 'Scan Type'
          end
          object cbCTScanType: TComboBox
            Left = 8
            Top = 24
            Width = 177
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            ItemHeight = 13
            ItemIndex = 3
            TabOrder = 0
            Text = 'Enable Inquiry/Page Scan'
            Items.Strings = (
              'Disable Scan'
              'Enable Inquiry Scan Only'
              'Enable Page Scan Only'
              'Enable Inquiry/Page Scan')
          end
          object cbCTInterlacedInquiryScan: TCheckBox
            Left = 8
            Top = 56
            Width = 169
            Height = 17
            Caption = 'Interlaced Inquiry Scan'
            TabOrder = 1
          end
          object cbInterlacedPageScan: TCheckBox
            Left = 8
            Top = 80
            Width = 129
            Height = 17
            Caption = 'Interlaced Page Scan'
            TabOrder = 2
          end
          object btnCTScan: TButton
            Left = 144
            Top = 64
            Width = 75
            Height = 25
            Caption = 'Scan'
            TabOrder = 3
            OnClick = btnCTScanClick
          end
        end
        object GroupBox18: TGroupBox
          Left = 544
          Top = 48
          Width = 233
          Height = 81
          Caption = '  Inquiry  '
          TabOrder = 3
          object Label54: TLabel
            Left = 16
            Top = 32
            Width = 38
            Height = 13
            Caption = 'Timeout'
          end
          object Label55: TLabel
            Left = 72
            Top = 48
            Width = 51
            Height = 13
            Caption = 'X 1.28 sec'
          end
          object btnCTInquiryStart: TBitBtn
            Left = 144
            Top = 16
            Width = 75
            Height = 25
            Caption = 'Start'
            TabOrder = 0
            OnClick = btnCTInquiryStartClick
            Kind = bkRetry
          end
          object btnCTInquiryStop: TBitBtn
            Left = 144
            Top = 48
            Width = 75
            Height = 25
            Caption = 'Stop'
            TabOrder = 1
            OnClick = btnCTInquiryStopClick
            Kind = bkNo
          end
          object edtCTInquiryTimeout: TEdit
            Left = 16
            Top = 48
            Width = 49
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 2
            Text = '5'
            OnExit = edtCTInquiryTimeoutCheck
          end
        end
        object GroupBox19: TGroupBox
          Left = 672
          Top = 128
          Width = 121
          Height = 161
          Caption = '  Connected Devices'
          TabOrder = 4
          object lbCTConDevices: TListBox
            Left = 8
            Top = 16
            Width = 105
            Height = 137
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            ItemHeight = 13
            TabOrder = 0
            OnClick = lbCTConDevicesClick
          end
        end
        object GroupBox20: TGroupBox
          Left = 536
          Top = 128
          Width = 121
          Height = 161
          Caption = '  Discovered Devices  '
          TabOrder = 5
          object lbCTDisDevices: TListBox
            Left = 8
            Top = 16
            Width = 105
            Height = 137
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            ItemHeight = 13
            TabOrder = 0
            OnClick = lbCTDisDevicesClick
          end
        end
        object GroupBox21: TGroupBox
          Left = 8
          Top = 120
          Width = 273
          Height = 177
          Caption = '  ACL Control  '
          TabOrder = 6
          object Label56: TLabel
            Left = 8
            Top = 42
            Width = 11
            Height = 13
            Caption = '0x'
          end
          object Label57: TLabel
            Left = 48
            Top = 24
            Width = 56
            Height = 13
            Caption = 'BD Address'
          end
          object Label58: TLabel
            Left = 152
            Top = 24
            Width = 87
            Height = 13
            Caption = 'Connection Status'
          end
          object btnCTConnectACL: TButton
            Left = 8
            Top = 136
            Width = 55
            Height = 25
            Caption = 'Connect'
            Enabled = False
            TabOrder = 0
            OnClick = btnCTConnectACLClick
          end
          object btnCTDisconnectACL: TButton
            Left = 72
            Top = 136
            Width = 63
            Height = 25
            Caption = 'Disconnect'
            Enabled = False
            TabOrder = 1
            OnClick = btnCTDisconnectACLClick
          end
          object btnCTChangeAclPktType: TButton
            Left = 144
            Top = 136
            Width = 121
            Height = 25
            Caption = 'Change Packet Type'
            Enabled = False
            TabOrder = 2
            OnClick = btnCTChangeAclPktTypeClick
          end
          object stCTACLStatus: TStaticText
            Left = 144
            Top = 40
            Width = 97
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Color = clMoneyGreen
            ParentColor = False
            TabOrder = 3
          end
          object cbCTDM1: TCheckBox
            Left = 8
            Top = 64
            Width = 45
            Height = 17
            Caption = 'DM1'
            Checked = True
            State = cbChecked
            TabOrder = 4
          end
          object cbCTDM3: TCheckBox
            Left = 8
            Top = 88
            Width = 50
            Height = 17
            Caption = 'DM3'
            Checked = True
            State = cbChecked
            TabOrder = 5
          end
          object cbCTDM5: TCheckBox
            Left = 8
            Top = 112
            Width = 45
            Height = 17
            Caption = 'DM5'
            Checked = True
            State = cbChecked
            TabOrder = 6
          end
          object cbCTDH1: TCheckBox
            Left = 56
            Top = 64
            Width = 45
            Height = 17
            Caption = 'DH1'
            Checked = True
            State = cbChecked
            TabOrder = 7
          end
          object cbCTDH3: TCheckBox
            Left = 56
            Top = 88
            Width = 45
            Height = 17
            Caption = 'DH3'
            Checked = True
            State = cbChecked
            TabOrder = 8
          end
          object cbCTDH5: TCheckBox
            Left = 56
            Top = 112
            Width = 45
            Height = 17
            Caption = 'DH5'
            Checked = True
            State = cbChecked
            TabOrder = 9
          end
          object m_stCTACLBDAddr: TStaticText
            Left = 24
            Top = 40
            Width = 105
            Height = 17
            Alignment = taCenter
            AutoSize = False
            BorderStyle = sbsSunken
            Color = clSkyBlue
            ParentColor = False
            TabOrder = 10
          end
          object cbCT2DH1: TCheckBox
            Left = 112
            Top = 64
            Width = 57
            Height = 17
            Caption = '2-DH1'
            TabOrder = 11
          end
          object cbCT3DH1: TCheckBox
            Left = 176
            Top = 64
            Width = 57
            Height = 17
            Caption = '3-DH1'
            TabOrder = 12
          end
          object cbCT2DH3: TCheckBox
            Left = 112
            Top = 88
            Width = 57
            Height = 17
            Caption = '2-DH3'
            TabOrder = 13
          end
          object cbCT3DH3: TCheckBox
            Left = 176
            Top = 88
            Width = 57
            Height = 17
            Caption = '3-DH3'
            TabOrder = 14
          end
          object cbCT2DH5: TCheckBox
            Left = 112
            Top = 112
            Width = 57
            Height = 17
            Caption = '2-DH5'
            TabOrder = 15
          end
          object cbCT3DH5: TCheckBox
            Left = 176
            Top = 112
            Width = 65
            Height = 17
            Caption = '3-DH5'
            TabOrder = 16
          end
        end
        object GroupBox22: TGroupBox
          Left = 544
          Top = 8
          Width = 233
          Height = 41
          Caption = '  Auto Accept  '
          TabOrder = 7
          object btnCTAutoAccept: TButton
            Left = 144
            Top = 8
            Width = 75
            Height = 25
            Caption = 'Auto Accept'
            Enabled = False
            TabOrder = 0
            OnClick = btnCTAutoAcceptClick
          end
        end
      end
      object btCTClearLog: TButton
        Left = 584
        Top = 304
        Width = 75
        Height = 25
        Caption = 'Clear Log'
        TabOrder = 3
        OnClick = btCTClearLogClick
      end
      object btnCTResetLD: TButton
        Left = 456
        Top = 304
        Width = 113
        Height = 25
        Caption = 'Reset Local Device'
        TabOrder = 4
        OnClick = btnCTResetLDClick
      end
    end
    object tsBLETest: TTabSheet
      Caption = 'BLE Test Mode'
      ImageIndex = 7
      object gbBLE: TGroupBox
        Left = 24
        Top = 16
        Width = 721
        Height = 441
        TabOrder = 0
        object lbChannel: TLabel
          Left = 16
          Top = 121
          Width = 39
          Height = 13
          Caption = 'Channel'
        end
        object lbPattern: TLabel
          Left = 16
          Top = 160
          Width = 34
          Height = 13
          Caption = 'Pattern'
        end
        object lbTxLevel: TLabel
          Left = 16
          Top = 192
          Width = 41
          Height = 13
          Caption = 'Tx Level'
        end
        object lbPacketCount: TLabel
          Left = 16
          Top = 256
          Width = 65
          Height = 13
          Caption = 'Packet Count'
        end
        object gbTxorRx: TGroupBox
          Left = 16
          Top = 16
          Width = 225
          Height = 41
          TabOrder = 0
          object rbTxTest: TRadioButton
            Left = 8
            Top = 16
            Width = 73
            Height = 17
            Caption = 'Tx Test'
            Checked = True
            TabOrder = 0
            TabStop = True
            OnClick = rbTxTestClick
          end
          object rbRxTest: TRadioButton
            Left = 136
            Top = 16
            Width = 65
            Height = 17
            Caption = 'Rx Test'
            TabOrder = 1
            OnClick = rbRxTestClick
          end
        end
        object gbSingleorHopping: TGroupBox
          Left = 16
          Top = 64
          Width = 225
          Height = 41
          TabOrder = 1
          object rbSingleChannel: TRadioButton
            Left = 8
            Top = 16
            Width = 105
            Height = 17
            Caption = 'Single Channel'
            Checked = True
            TabOrder = 0
            TabStop = True
            OnClick = rbSingleChannelClick
          end
          object rbHopping: TRadioButton
            Left = 136
            Top = 16
            Width = 73
            Height = 17
            Caption = 'Hopping'
            Enabled = False
            TabOrder = 1
            OnClick = rbHoppingClick
          end
        end
        object etChannel: TEdit
          Left = 96
          Top = 120
          Width = 145
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 2
          OnExit = etChannelExit
        end
        object cbPattern: TComboBox
          Left = 96
          Top = 152
          Width = 145
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 3
          Text = 'PRBS9'
          OnSelect = cbPatternSelect
          Items.Strings = (
            'PRBS9'
            '11110000'
            '10101010')
        end
        object cbTxLevel: TComboBox
          Left = 96
          Top = 184
          Width = 145
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 0
          TabOrder = 4
        end
        object cbContinuousTx: TCheckBox
          Left = 16
          Top = 216
          Width = 97
          Height = 25
          Caption = 'Continuous Tx'
          Checked = True
          State = cbChecked
          TabOrder = 5
          OnClick = cbContinuousTxClick
        end
        object edPacketCount: TEdit
          Left = 96
          Top = 256
          Width = 145
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 6
        end
        object btnStart: TButton
          Left = 144
          Top = 312
          Width = 105
          Height = 33
          Caption = 'Start'
          TabOrder = 7
          OnClick = btnStartClick
        end
        object GroupBox25: TGroupBox
          Left = 272
          Top = 16
          Width = 377
          Height = 89
          Caption = 'Read BLE Access Address'
          TabOrder = 8
          object Edit1: TEdit
            Left = 16
            Top = 40
            Width = 161
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 0
          end
          object Button1: TButton
            Left = 208
            Top = 40
            Width = 89
            Height = 21
            Caption = 'Read'
            TabOrder = 1
          end
        end
        object reBLEResult: TRichEdit
          Left = 272
          Top = 128
          Width = 377
          Height = 153
          Font.Charset = GB2312_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          Lines.Strings = (
            '')
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 9
        end
        object btClear: TButton
          Left = 560
          Top = 312
          Width = 89
          Height = 33
          Caption = 'Clear Log'
          TabOrder = 10
          OnClick = btClearClick
        end
      end
      object sbBLE: TStatusBar
        Left = 0
        Top = 500
        Width = 809
        Height = 25
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object tsBLENormal: TTabSheet
      Caption = 'BLE Normal Mode'
      ImageIndex = 8
      object pcBleNormalMode: TPageControl
        Left = 16
        Top = 16
        Width = 769
        Height = 481
        ActivePage = tsAdvertise
        TabIndex = 0
        TabOrder = 0
        object tsAdvertise: TTabSheet
          Caption = 'Advertise'
          OnShow = tsAdvertiseShow
          object GroupBox27: TGroupBox
            Left = 16
            Top = 16
            Width = 345
            Height = 281
            TabOrder = 0
            object Label65: TLabel
              Left = 8
              Top = 24
              Width = 110
              Height = 13
              Caption = 'Advertising Interval Min'
            end
            object Label67: TLabel
              Left = 240
              Top = 24
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object Label69: TLabel
              Left = 8
              Top = 56
              Width = 113
              Height = 13
              Caption = 'Advertising Interval Max'
            end
            object Label70: TLabel
              Left = 240
              Top = 48
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object Label71: TLabel
              Left = 8
              Top = 88
              Width = 79
              Height = 13
              Caption = 'Advertising Type'
            end
            object Label72: TLabel
              Left = 8
              Top = 120
              Width = 90
              Height = 13
              Caption = 'Own Address Type'
            end
            object Label73: TLabel
              Left = 8
              Top = 152
              Width = 96
              Height = 13
              Caption = 'Direct Address Type'
            end
            object Label74: TLabel
              Left = 8
              Top = 184
              Width = 69
              Height = 13
              Caption = 'Direct Address'
            end
            object Label75: TLabel
              Left = 8
              Top = 248
              Width = 100
              Height = 13
              Caption = 'Advertise Filter Policy'
            end
            object edAdvertisingIntervalMin: TEdit
              Left = 128
              Top = 24
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 0
            end
            object edAdvertisingIntervalMax: TEdit
              Left = 128
              Top = 48
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 1
            end
            object cbAdvertisingType: TComboBox
              Left = 128
              Top = 80
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 2
              Text = 'ADV_IND'
              Items.Strings = (
                'ADV_IND'
                'ADV_DIRECT_IND'
                'ADV_DISCOVER_IND'
                'ADV_NONCONN_IND')
            end
            object cbChannel37: TCheckBox
              Left = 16
              Top = 208
              Width = 81
              Height = 25
              Caption = 'Channel37'
              TabOrder = 3
            end
            object cbChannel38: TCheckBox
              Left = 136
              Top = 208
              Width = 81
              Height = 25
              Caption = 'Channel38'
              TabOrder = 4
            end
            object cbChannel39: TCheckBox
              Left = 240
              Top = 208
              Width = 81
              Height = 25
              Caption = 'Channel39'
              TabOrder = 5
            end
            object cbAdvertiseFilterPolicy: TComboBox
              Left = 128
              Top = 248
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 6
              Text = 'All Allow'
              Items.Strings = (
                'All Allow'
                'Scan Request From While List'
                'Connection Request From White'
                'Both From While List')
            end
            object cbOwnAddressType: TComboBox
              Left = 128
              Top = 112
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 7
              Text = 'Public Device Address'
              Items.Strings = (
                'Public Device Address'
                'Random Device Address')
            end
            object cbDirectAddressType: TComboBox
              Left = 128
              Top = 144
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 8
              Text = 'Public Device Address'
              Items.Strings = (
                'Public Device Address'
                'Random Device Address')
            end
            object edDirectAddress: TEdit
              Left = 128
              Top = 176
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 9
            end
            object btChangeMintoHex: TButton
              Left = 296
              Top = 24
              Width = 41
              Height = 17
              Caption = 'Hex'
              TabOrder = 10
              OnClick = btChangeMintoHexClick
            end
            object btChangeMaxtoHex: TButton
              Left = 296
              Top = 48
              Width = 41
              Height = 17
              Caption = 'Hex'
              TabOrder = 11
              OnClick = btChangeMaxtoHexClick
            end
          end
          object reBLEAdvertiseResult: TRichEdit
            Left = 376
            Top = 24
            Width = 377
            Height = 273
            Font.Charset = GB2312_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            Lines.Strings = (
              '')
            ParentFont = False
            ScrollBars = ssVertical
            TabOrder = 1
          end
          object GroupBox28: TGroupBox
            Left = 16
            Top = 304
            Width = 345
            Height = 113
            TabOrder = 2
            object reAdvertiseData: TRichEdit
              Left = 16
              Top = 16
              Width = 305
              Height = 41
              Font.Charset = GB2312_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              Lines.Strings = (
                '')
              ParentFont = False
              TabOrder = 0
            end
            object btSetAdvertiseData: TButton
              Left = 16
              Top = 80
              Width = 97
              Height = 25
              Caption = 'Set Advertise Data'
              TabOrder = 1
              OnClick = btSetAdvertiseDataClick
            end
          end
          object btAdvertiseStar: TButton
            Left = 16
            Top = 424
            Width = 97
            Height = 25
            Caption = 'Start'
            TabOrder = 3
            OnClick = btAdvertiseStarClick
          end
          object GroupBox29: TGroupBox
            Left = 376
            Top = 304
            Width = 377
            Height = 113
            TabOrder = 4
            object edWhiteList: TEdit
              Left = 8
              Top = 16
              Width = 177
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 0
            end
            object cbDeviceAddress: TComboBox
              Left = 192
              Top = 16
              Width = 177
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 1
              Text = 'Public Device Address'
              OnChange = cbDeviceAddressChange
              Items.Strings = (
                'Public Device Address'
                'Random Device Address')
            end
            object btAddDeviceToWhiteList: TButton
              Left = 8
              Top = 48
              Width = 177
              Height = 25
              Caption = 'Add Device To White List'
              TabOrder = 2
              OnClick = btAddDeviceToWhiteListClick
            end
            object btRemoveDeviceToWhiteList: TButton
              Left = 192
              Top = 48
              Width = 177
              Height = 25
              Caption = 'Remove Device To White List'
              TabOrder = 3
              OnClick = btRemoveDeviceToWhiteListClick
            end
            object btBLEClearWhiteList: TButton
              Left = 8
              Top = 80
              Width = 361
              Height = 25
              Caption = 'Clear White List'
              TabOrder = 4
              OnClick = btBLEClearWhiteListClick
            end
          end
          object btHCIReset: TButton
            Left = 560
            Top = 424
            Width = 81
            Height = 25
            Caption = 'HCI Reset'
            TabOrder = 5
            OnClick = btHCIResetClick
          end
          object btAdvertiseClear: TButton
            Left = 672
            Top = 424
            Width = 81
            Height = 25
            Caption = 'Clear Log'
            TabOrder = 6
            OnClick = btAdvertiseClearClick
          end
        end
        object tsScan: TTabSheet
          Caption = 'Scan'
          ImageIndex = 1
          OnShow = tsScanShow
          object GroupBox30: TGroupBox
            Left = 16
            Top = 16
            Width = 345
            Height = 217
            TabOrder = 0
            object Label76: TLabel
              Left = 8
              Top = 24
              Width = 52
              Height = 13
              Caption = 'Scan Type'
            end
            object Label77: TLabel
              Left = 8
              Top = 56
              Width = 79
              Height = 13
              Caption = 'LE Scan Interval'
            end
            object Label78: TLabel
              Left = 8
              Top = 88
              Width = 86
              Height = 13
              Caption = 'LE Scan Window '
            end
            object Label79: TLabel
              Left = 8
              Top = 120
              Width = 95
              Height = 13
              Caption = 'Owm Address Type '
            end
            object Label80: TLabel
              Left = 8
              Top = 152
              Width = 84
              Height = 13
              Caption = 'Scan Filter Policy '
            end
            object Label81: TLabel
              Left = 8
              Top = 184
              Width = 73
              Height = 13
              Caption = 'Filter Duplicate '
            end
            object Label82: TLabel
              Left = 224
              Top = 56
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object Label83: TLabel
              Left = 224
              Top = 88
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object cbScanType: TComboBox
              Left = 112
              Top = 24
              Width = 153
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 0
              Text = 'Passive Scan'
              Items.Strings = (
                'Passive Scan'
                'Active Scan')
            end
            object edLEScanInterval: TEdit
              Left = 112
              Top = 56
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 1
            end
            object edLEScanWindow: TEdit
              Left = 112
              Top = 88
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 2
            end
            object cbOwmAddressType: TComboBox
              Left = 112
              Top = 120
              Width = 153
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 3
              Text = 'Public Device Address'
              Items.Strings = (
                'Public Device Address'
                'Random Device Address')
            end
            object cbScanFilterPolicy: TComboBox
              Left = 112
              Top = 152
              Width = 225
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 4
              Text = 'Accept All Advertise Packet'
              Items.Strings = (
                'Accept All Advertise Packet'
                'Ignore Advertise Packet Not In White List')
            end
            object cbFilterDuplicate: TComboBox
              Left = 112
              Top = 184
              Width = 153
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 5
              Text = 'Disable Duplicate Filtering'
              Items.Strings = (
                'Disable Duplicate Filtering'
                'Enable Duplicate Filtering')
            end
            object btChangeLeScanInterval: TButton
              Left = 280
              Top = 56
              Width = 33
              Height = 17
              Caption = 'Hex'
              TabOrder = 6
              OnClick = btChangeLeScanIntervalClick
            end
            object btChangeLEScanWindow: TButton
              Left = 280
              Top = 88
              Width = 33
              Height = 17
              Caption = 'Hex'
              TabOrder = 7
              OnClick = btChangeLEScanWindowClick
            end
          end
          object reBLEScanResult: TRichEdit
            Left = 376
            Top = 24
            Width = 377
            Height = 385
            Font.Charset = GB2312_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            Lines.Strings = (
              '')
            ParentFont = False
            ScrollBars = ssVertical
            TabOrder = 1
          end
          object GroupBox31: TGroupBox
            Left = 16
            Top = 240
            Width = 345
            Height = 169
            TabOrder = 2
            object reScanResponseData: TRichEdit
              Left = 16
              Top = 16
              Width = 297
              Height = 113
              Font.Charset = GB2312_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              Lines.Strings = (
                '')
              ParentFont = False
              TabOrder = 0
            end
            object btSetScanResponseData: TButton
              Left = 16
              Top = 136
              Width = 137
              Height = 25
              Caption = 'Set Scan Response Data'
              TabOrder = 1
              OnClick = btSetScanResponseDataClick
            end
          end
          object btScanStart: TButton
            Left = 16
            Top = 416
            Width = 97
            Height = 25
            Caption = 'Start'
            TabOrder = 3
            OnClick = btScanStartClick
          end
          object btHCIResetScan: TButton
            Left = 560
            Top = 424
            Width = 81
            Height = 25
            Caption = 'HCI Reset'
            TabOrder = 4
            OnClick = btHCIResetClick
          end
          object btScanClear: TButton
            Left = 664
            Top = 424
            Width = 81
            Height = 25
            Caption = 'Clear Log'
            TabOrder = 5
            OnClick = btScanClearClick
          end
        end
        object tsInitiate: TTabSheet
          Caption = 'Initiate'
          ImageIndex = 2
          OnShow = tsInitiateShow
          object GroupBox32: TGroupBox
            Left = 16
            Top = 16
            Width = 337
            Height = 401
            TabOrder = 0
            object Label84: TLabel
              Left = 8
              Top = 16
              Width = 79
              Height = 13
              Caption = 'LE Scan Interval'
            end
            object Label85: TLabel
              Left = 8
              Top = 48
              Width = 86
              Height = 13
              Caption = 'LE Scan Window '
            end
            object Label86: TLabel
              Left = 240
              Top = 16
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object Label87: TLabel
              Left = 240
              Top = 48
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object Label88: TLabel
              Left = 8
              Top = 80
              Width = 90
              Height = 13
              Caption = 'Initiate Filter Policy '
            end
            object Label89: TLabel
              Left = 8
              Top = 208
              Width = 115
              Height = 13
              Caption = 'Connection Interval Min '
            end
            object Label90: TLabel
              Left = 8
              Top = 112
              Width = 93
              Height = 13
              Caption = 'Peer Address Type '
            end
            object Label91: TLabel
              Left = 8
              Top = 144
              Width = 93
              Height = 13
              Caption = 'Own Address Type '
            end
            object Label92: TLabel
              Left = 8
              Top = 176
              Width = 66
              Height = 13
              Caption = 'Peer Address '
            end
            object Label93: TLabel
              Left = 8
              Top = 240
              Width = 118
              Height = 13
              Caption = 'Connection Interval Max '
            end
            object Label94: TLabel
              Left = 8
              Top = 272
              Width = 95
              Height = 13
              Caption = 'Connection Latency'
            end
            object Label95: TLabel
              Left = 8
              Top = 304
              Width = 96
              Height = 13
              Caption = 'Supervision Timeout'
            end
            object Label96: TLabel
              Left = 8
              Top = 336
              Width = 94
              Height = 13
              Caption = 'Minimum CE Length'
            end
            object Label97: TLabel
              Left = 8
              Top = 368
              Width = 96
              Height = 13
              Caption = 'Msximum CE Length'
            end
            object Label98: TLabel
              Left = 240
              Top = 208
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object Label99: TLabel
              Left = 240
              Top = 240
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object Label100: TLabel
              Left = 240
              Top = 304
              Width = 29
              Height = 13
              Caption = '*10ms'
            end
            object Label101: TLabel
              Left = 240
              Top = 336
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object Label102: TLabel
              Left = 240
              Top = 368
              Width = 44
              Height = 13
              Caption = '*0.625ms'
            end
            object edLEScanIntervalIn: TEdit
              Left = 128
              Top = 16
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 0
            end
            object edLEScanWindowIn: TEdit
              Left = 128
              Top = 48
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 1
            end
            object cbInitiateFilterPolicy: TComboBox
              Left = 128
              Top = 80
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 2
              Text = 'White List Is Not Used'
              Items.Strings = (
                'White List Is Not Used'
                'White List Is Used')
            end
            object cbPeerAddressType: TComboBox
              Left = 128
              Top = 112
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 3
              Text = 'Public Device Address'
              Items.Strings = (
                'Public Device Address'
                'Random Device Address')
            end
            object cbOwnAddressTypeIn: TComboBox
              Left = 128
              Top = 144
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              ItemHeight = 13
              ItemIndex = 0
              TabOrder = 4
              Text = 'Public Device Address'
              Items.Strings = (
                'Public Device Address'
                'Random Device Address')
            end
            object edPeerAddress: TEdit
              Left = 128
              Top = 176
              Width = 161
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 5
            end
            object edConnectionIntervalMin: TEdit
              Left = 128
              Top = 208
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 6
            end
            object edConnectionIntervalMax: TEdit
              Left = 128
              Top = 240
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 7
            end
            object edConnectionLatency: TEdit
              Left = 128
              Top = 272
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 8
            end
            object edSupervisionTimeout: TEdit
              Left = 128
              Top = 304
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 9
            end
            object edMinimumCELength: TEdit
              Left = 128
              Top = 336
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 10
            end
            object edMaximumCELength: TEdit
              Left = 128
              Top = 368
              Width = 105
              Height = 21
              ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
              TabOrder = 11
            end
            object btnLEScanInterval: TButton
              Left = 288
              Top = 16
              Width = 41
              Height = 17
              Caption = 'Hex'
              TabOrder = 12
              OnClick = btnLEScanIntervalClick
            end
            object btnLEScanWindow: TButton
              Left = 288
              Top = 48
              Width = 41
              Height = 17
              Caption = 'Hex'
              TabOrder = 13
              OnClick = btnLEScanWindowClick
            end
          end
          object reBLEInitiateResult: TRichEdit
            Left = 376
            Top = 24
            Width = 377
            Height = 377
            Font.Charset = GB2312_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            Lines.Strings = (
              '')
            ParentFont = False
            ScrollBars = ssVertical
            TabOrder = 1
          end
          object btInitiateStart: TButton
            Left = 16
            Top = 424
            Width = 97
            Height = 25
            Caption = 'Start'
            TabOrder = 2
            OnClick = btInitiateStartClick
          end
          object btHCIResetInitiate: TButton
            Left = 536
            Top = 424
            Width = 81
            Height = 25
            Caption = 'HCI Reset'
            TabOrder = 3
            OnClick = btHCIResetClick
          end
          object btInitiateClear: TButton
            Left = 664
            Top = 424
            Width = 81
            Height = 25
            Caption = 'Clear Log'
            TabOrder = 4
            OnClick = btInitiateClearClick
          end
        end
      end
      object sbBLENormalMode: TStatusBar
        Left = 0
        Top = 500
        Width = 809
        Height = 25
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object tsStandalone: TTabSheet
      Caption = 'Non-Signaling Rx Test'
      ImageIndex = 9
      object GroupBox34: TGroupBox
        Left = 48
        Top = 24
        Width = 337
        Height = 241
        Caption = 'Non-Signaling Rx Test '
        TabOrder = 0
        object Label106: TLabel
          Left = 24
          Top = 40
          Width = 52
          Height = 13
          Caption = 'RX Pattern'
        end
        object Label107: TLabel
          Left = 24
          Top = 80
          Width = 71
          Height = 13
          Caption = 'RX Frequency '
        end
        object Label103: TLabel
          Left = 23
          Top = 124
          Width = 82
          Height = 13
          Caption = 'RX Packet Type '
        end
        object Label104: TLabel
          Left = 23
          Top = 164
          Width = 71
          Height = 13
          Caption = 'Tester Address'
        end
        object lbUserInput: TLabel
          Left = 272
          Top = 128
          Width = 13
          Height = 13
          Caption = '0X'
          Visible = False
        end
        object cbRXPattern: TComboBox
          Left = 120
          Top = 36
          Width = 137
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 0
          Text = '0000 pattern'
          Items.Strings = (
            '0000 pattern'
            '1111 pattern'
            '1010 pattern'
            'Pseudo Random Bit Sequence'
            '11110000 pattern')
        end
        object edRXFre: TEdit
          Left = 120
          Top = 76
          Width = 137
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 1
          Text = '0'
        end
        object edTesterAddress: TEdit
          Left = 120
          Top = 156
          Width = 137
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 2
        end
        object btnEnterTest: TButton
          Left = 76
          Top = 196
          Width = 81
          Height = 25
          Caption = 'Enter Test'
          TabOrder = 3
          OnClick = btnEnterTestClick
        end
        object btnExitTest: TButton
          Left = 180
          Top = 196
          Width = 81
          Height = 25
          Caption = 'Exit Test'
          TabOrder = 4
          OnClick = btnExitTestClick
        end
        object cbRXPacketTypeSub: TComboBox
          Left = 120
          Top = 120
          Width = 137
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 5
          Text = 'DM1'
          OnChange = cbRXPacketTypeSubChange
          Items.Strings = (
            'DM1'
            'DH1'
            'AUX'
            'DM3'
            'DH3'
            'DM5'
            'DH5'
            '2-DH1'
            '3-DH1'
            '2-DH3'
            '3-DH3'
            '2-DH5'
            '3_DH5'
            'User Input')
        end
        object edUserInput: TEdit
          Left = 288
          Top = 120
          Width = 41
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 6
          Visible = False
        end
      end
      object GroupBox33: TGroupBox
        Left = 424
        Top = 24
        Width = 337
        Height = 241
        Caption = 'Non-Signaling RX Test Result'
        TabOrder = 1
        object Label105: TLabel
          Left = 24
          Top = 40
          Width = 86
          Height = 13
          Caption = 'RX Packet Count:'
        end
        object Label108: TLabel
          Left = 24
          Top = 80
          Width = 69
          Height = 13
          Caption = 'RX Error Rate:'
        end
        object Label109: TLabel
          Left = 24
          Top = 120
          Width = 73
          Height = 13
          Caption = 'RX Byte Count:'
        end
        object Label110: TLabel
          Left = 24
          Top = 160
          Width = 66
          Height = 13
          Caption = 'Bit Error Rate:'
        end
        object edPXPacketCount: TEdit
          Left = 144
          Top = 36
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 0
        end
        object edRXErroRate: TEdit
          Left = 144
          Top = 76
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 1
        end
        object edRXByteCount: TEdit
          Left = 144
          Top = 116
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 2
        end
        object edBitErrorRate: TEdit
          Left = 144
          Top = 156
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 3
        end
      end
      object reRXSTD: TRichEdit
        Left = 48
        Top = 280
        Width = 713
        Height = 177
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 2
      end
      object btnSTDClear: TButton
        Left = 671
        Top = 466
        Width = 89
        Height = 25
        Caption = 'Clear Log'
        TabOrder = 3
        OnClick = btnSTDClearClick
      end
      object sbRXSTD: TStatusBar
        Left = 0
        Top = 496
        Width = 809
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object btnResetTest: TButton
        Left = 578
        Top = 466
        Width = 75
        Height = 25
        Caption = 'HCI Reset'
        TabOrder = 5
        OnClick = btnResetTestClick
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'LE Enhanced Test Mode'
      ImageIndex = 10
      object Label115: TLabel
        Left = 64
        Top = 400
        Width = 65
        Height = 13
        Caption = 'Packet Count'
      end
      object Label111: TLabel
        Left = 64
        Top = 129
        Width = 39
        Height = 13
        Caption = 'Channel'
      end
      object Label112: TLabel
        Left = 64
        Top = 169
        Width = 22
        Height = 13
        Caption = 'PHY'
      end
      object lbEnPayloadLength: TLabel
        Left = 64
        Top = 217
        Width = 74
        Height = 13
        Caption = 'Payload Length'
      end
      object lbEnPattern: TLabel
        Left = 64
        Top = 264
        Width = 34
        Height = 13
        Caption = 'Pattern'
      end
      object GroupBox35: TGroupBox
        Left = 64
        Top = 64
        Width = 225
        Height = 41
        TabOrder = 0
        object rbEnTxTest: TRadioButton
          Left = 8
          Top = 16
          Width = 73
          Height = 17
          Caption = 'Tx Test'
          Checked = True
          TabOrder = 0
          TabStop = True
          OnClick = rbEnTxTestClick
        end
        object rbEnRxTest: TRadioButton
          Left = 128
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Rx Test'
          TabOrder = 1
          OnClick = rbEnRxTestClick
        end
      end
      object cbEnPHY: TComboBox
        Left = 120
        Top = 168
        Width = 169
        Height = 21
        ItemHeight = 13
        TabOrder = 1
        Items.Strings = (
          '1M PHY'
          '2M PHY'
          'Coded PHY, S=8'
          'Coded PHY, S=2')
      end
      object edEnPayloadLength: TEdit
        Left = 152
        Top = 216
        Width = 137
        Height = 21
        Hint = '0~255'
        TabOrder = 2
      end
      object cbEnChannel: TComboBox
        Left = 120
        Top = 129
        Width = 169
        Height = 21
        ItemHeight = 13
        ItemIndex = 0
        TabOrder = 3
        Text = '0'
        Items.Strings = (
          '0'
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10'
          '11'
          '12'
          '13'
          '14'
          '15'
          '16'
          '17'
          '18'
          '19'
          '20'
          '21'
          '22'
          '23'
          '24'
          '25'
          '26'
          '27'
          '28'
          '29'
          '30'
          '31'
          '32'
          '33'
          '34'
          '35'
          '36'
          '37'
          '38'
          '39')
      end
      object cbEnPattern: TComboBox
        Left = 120
        Top = 264
        Width = 169
        Height = 21
        Style = csDropDownList
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 4
        OnSelect = cbPatternSelect
        Items.Strings = (
          'PRBS9'
          '11110000'
          '10101010'
          'PRBS15'
          '11111111'
          '00000000'
          '00001111'
          '01010101'
          '')
      end
      object btnEnStart: TButton
        Left = 184
        Top = 320
        Width = 105
        Height = 33
        Caption = 'Start'
        TabOrder = 5
        OnClick = btnEnStartClick
      end
      object edEnPacketCount: TEdit
        Left = 144
        Top = 400
        Width = 145
        Height = 21
        Enabled = False
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 6
      end
      object reBLEEnhancedResult: TRichEdit
        Left = 328
        Top = 72
        Width = 377
        Height = 281
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        Lines.Strings = (
          '')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 7
      end
      object Button3: TButton
        Left = 616
        Top = 384
        Width = 89
        Height = 33
        Caption = 'Clear Log'
        TabOrder = 8
        OnClick = btClearClick
      end
      object sbBLEEN: TStatusBar
        Left = 0
        Top = 500
        Width = 809
        Height = 25
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
  end
  object lblHint: TStaticText
    Left = 725
    Top = 40
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 1
    Visible = False
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Save to ini file'
    Left = 556
    Top = 8
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 624
    Top = 8
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Open ini file'
    Left = 692
    Top = 8
  end
  object dlgOpenHCIFile: TOpenDialog
    DefaultExt = 'hci'
    Filter = 
      'HCI file (*.hci)|*.hci|Text file (*.txt)|*.txt|All files (*.*)|*' +
      '.*'
    InitialDir = '.'
    Title = 'Open BT HCI file'
    Left = 664
    Top = 8
  end
  object glbTimer: TTimer
    Enabled = False
    OnTimer = glbTimerTimer
    Left = 592
    Top = 8
  end
  object MonitorTimer: TTimer
    Enabled = False
    OnTimer = MonitorTimerTimer
    Left = 728
    Top = 8
  end
  object dlgOpenSCTFile: TOpenDialog
    Filter = 
      'HCI script file (*.sct)|*.sct|Text file (*.txt)|*.txt|All files ' +
      '(*.*)|*.*'
    Title = 'Open BT script file'
    Left = 760
    Top = 8
  end
  object actList: TActionList
    Left = 792
    object ToggleHide: TAction
      Caption = 'ToggleHide'
      ShortCut = 49237
      OnExecute = ToggleHideExecute
    end
  end
  object m_tmMT: TTimer
    Enabled = False
    Interval = 1
    OnTimer = m_tmMTTimer
    Left = 784
    Top = 40
  end
end
