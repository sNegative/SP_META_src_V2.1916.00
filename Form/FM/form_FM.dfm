object frmFM: TfrmFM
  Left = 337
  Top = 313
  Width = 861
  Height = 677
  Caption = 'FM Radio Tool'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object m_pgcFMRadio: TPageControl
    Left = 0
    Top = 0
    Width = 849
    Height = 641
    ActivePage = m_tsFMReceiver
    TabIndex = 0
    TabOrder = 1
    object m_tsOldFMUI: TTabSheet
      Caption = 'Legacy FM Radio Tool'
      TabVisible = False
      object Panel9: TPanel
        Left = 8
        Top = 408
        Width = 153
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Station Search'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        Visible = False
      end
      object Panel8: TPanel
        Left = -8
        Top = 344
        Width = 673
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 1
        object Label10: TLabel
          Left = 32
          Top = 8
          Width = 25
          Height = 13
          Caption = 'RSSI'
        end
        object Label11: TLabel
          Left = 112
          Top = 8
          Width = 49
          Height = 13
          Caption = 'IF Counter'
        end
        object Label15: TLabel
          Left = 208
          Top = 8
          Width = 41
          Height = 13
          Caption = 'H/L side'
        end
        object Label16: TLabel
          Left = 296
          Top = 8
          Width = 62
          Height = 13
          Caption = 'Stereo/mono'
        end
        object m_btnGet: TButton
          Left = 424
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Get'
          TabOrder = 0
          OnClick = m_btnGetClick
        end
        object m_stRssi: TStaticText
          Left = 16
          Top = 24
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSingle
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object m_stIfCounter: TStaticText
          Left = 109
          Top = 24
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSingle
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object m_stHLSide: TStaticText
          Left = 202
          Top = 24
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSingle
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object m_stStereoMono: TStaticText
          Left = 296
          Top = 24
          Width = 58
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSingle
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
      end
      object Panel7: TPanel
        Left = 8
        Top = 320
        Width = 153
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Status'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object Panel6: TPanel
        Left = -8
        Top = 232
        Width = 673
        Height = 81
        BevelOuter = bvLowered
        TabOrder = 3
        object Label8: TLabel
          Left = 24
          Top = 24
          Width = 38
          Height = 13
          Caption = 'Address'
        end
        object Label9: TLabel
          Left = 96
          Top = 24
          Width = 67
          Height = 13
          Caption = 'Data (Word 1)'
        end
        object Label17: TLabel
          Left = 184
          Top = 24
          Width = 67
          Height = 13
          Caption = 'Data (Word 0)'
        end
        object m_edtAddr: TEdit
          Left = 8
          Top = 40
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 0
          Text = '0'
        end
        object m_edtWord1: TEdit
          Left = 96
          Top = 40
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 1
          Text = '0'
        end
        object m_btnRead: TButton
          Left = 320
          Top = 40
          Width = 75
          Height = 25
          Caption = 'Read'
          TabOrder = 2
          OnClick = m_btnReadClick
        end
        object m_btnWrite: TButton
          Left = 408
          Top = 40
          Width = 75
          Height = 25
          Caption = 'Write'
          TabOrder = 3
          OnClick = m_btnWriteClick
        end
        object m_edtWord0: TEdit
          Left = 184
          Top = 40
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 4
          Text = '0'
        end
      end
      object Panel5: TPanel
        Left = 8
        Top = 208
        Width = 153
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Register Read/Write'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
      end
      object Panel4: TPanel
        Left = -8
        Top = 120
        Width = 673
        Height = 81
        BevelOuter = bvLowered
        TabOrder = 5
        object Label6: TLabel
          Left = 144
          Top = 40
          Width = 85
          Height = 13
          Caption = 'Stereo blend level'
        end
        object Label4: TLabel
          Left = 440
          Top = 40
          Width = 27
          Height = 13
          Caption = 'Mode'
        end
        object m_cbSoftMute: TCheckBox
          Left = 8
          Top = 16
          Width = 105
          Height = 17
          Caption = 'Soft mute enable'
          TabOrder = 0
        end
        object m_cbStereoBlend: TCheckBox
          Left = 128
          Top = 16
          Width = 121
          Height = 17
          Caption = 'Stereo blend enable'
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
        object m_cbStereoBlendLevel: TComboBox
          Left = 144
          Top = 56
          Width = 81
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 2
          Text = '1'
          Items.Strings = (
            '1'
            '2'
            '3')
        end
        object m_cbMode: TComboBox
          Left = 416
          Top = 56
          Width = 81
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 1
          TabOrder = 3
          Text = 'Stereo'
          OnChange = m_cbModeChange
          Items.Strings = (
            'Mono'
            'Stereo')
        end
        object m_btnSetAudio: TButton
          Left = 552
          Top = 32
          Width = 75
          Height = 25
          Caption = 'Set'
          TabOrder = 4
          OnClick = m_btnSetAudioClick
        end
      end
      object Panel3: TPanel
        Left = 8
        Top = 96
        Width = 153
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Audio Setting'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
      end
      object Panel2: TPanel
        Left = 368
        Top = 8
        Width = 153
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Frequency Setting'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
      end
      object Panel12: TPanel
        Left = 8
        Top = 32
        Width = 305
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 8
        object m_btnReset: TButton
          Left = 64
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Reset'
          TabOrder = 0
          OnClick = m_btnResetClick
        end
      end
      object Panel11: TPanel
        Left = 8
        Top = 8
        Width = 153
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Reset '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 9
      end
      object Panel10: TPanel
        Left = -8
        Top = 436
        Width = 673
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 10
        Visible = False
        object Label12: TLabel
          Left = 20
          Top = 8
          Width = 71
          Height = 13
          Caption = 'RSSI threshold'
        end
        object Label1: TLabel
          Left = 112
          Top = 8
          Width = 74
          Height = 13
          Caption = 'IF counter delta'
        end
        object Label13: TLabel
          Left = 552
          Top = 8
          Width = 33
          Height = 13
          Caption = 'Station'
        end
        object Label14: TLabel
          Left = 616
          Top = 24
          Width = 22
          Height = 13
          Caption = 'MHz'
        end
        object m_btnSearchNextStation: TButton
          Left = 216
          Top = 24
          Width = 129
          Height = 25
          Caption = 'Search next station'
          TabOrder = 0
          OnClick = m_btnSearchNextStationClick
        end
        object m_btnSearchPreStation: TButton
          Left = 360
          Top = 24
          Width = 129
          Height = 25
          Caption = 'Search previous station'
          TabOrder = 1
          OnClick = m_btnSearchPreStationClick
        end
        object m_edtStation: TEdit
          Left = 528
          Top = 24
          Width = 81
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 2
          Text = '90.7'
        end
        object m_cbRssiThreshold: TComboBox
          Left = 16
          Top = 24
          Width = 73
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 3
          Text = 'Level 1'
          Items.Strings = (
            'Level 1'
            'Level 2'
            'Level 3'
            'Level 4'
            'Level 5'
            'Level 6')
        end
        object m_cbIfCounterDelta: TComboBox
          Left = 112
          Top = 24
          Width = 73
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 4
          TabOrder = 4
          Text = '30'
          Items.Strings = (
            '10'
            '15'
            '20'
            '25'
            '30')
        end
      end
      object Panel1: TPanel
        Left = 360
        Top = 32
        Width = 305
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 11
        object Label2: TLabel
          Left = 32
          Top = 8
          Width = 53
          Height = 13
          Caption = 'Frequency '
        end
        object Label3: TLabel
          Left = 112
          Top = 24
          Width = 22
          Height = 13
          Caption = 'MHz'
        end
        object m_edtFreq: TEdit
          Left = 16
          Top = 24
          Width = 89
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 0
          Text = '90.7'
          OnExit = edtFreqCheck
        end
        object m_btnSetFreq: TButton
          Left = 208
          Top = 16
          Width = 75
          Height = 25
          Caption = 'Set'
          TabOrder = 1
          OnClick = m_btnSetFreqClick
        end
      end
      object m_sbFM: TStatusBar
        Left = 0
        Top = 586
        Width = 841
        Height = 27
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object m_tsFMReceiver: TTabSheet
      Caption = 'FM Receiver Main Window'
      ImageIndex = 1
      object m_lblFMReceiver_Frequency_LowerLimit: TLabel
        Left = 4
        Top = 16
        Width = 49
        Height = 13
        Caption = '76.00MHz'
      end
      object m_lblFMReceiver_Frequency_UpperLimit: TLabel
        Left = 331
        Top = 16
        Width = 55
        Height = 13
        Caption = '108.00MHz'
      end
      object m_lblFMReceiver_Tune: TLabel
        Left = 400
        Top = 16
        Width = 25
        Height = 13
        Caption = 'Tune'
      end
      object m_lblFMReceiver_Seek: TLabel
        Left = 346
        Top = 73
        Width = 25
        Height = 13
        Caption = 'Seek'
      end
      object m_lblFMReceiver_CurrentFrequency: TLabel
        Left = 493
        Top = 35
        Width = 22
        Height = 13
        Caption = 'MHz'
      end
      object m_lblFMReceiver_Volume: TLabel
        Left = 512
        Top = 8
        Width = 35
        Height = 13
        Caption = 'Volume'
      end
      object m_sbFMReceiver: TStatusBar
        Left = 0
        Top = 586
        Width = 841
        Height = 27
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object m_gbFMReceiver_RegisterRW: TGroupBox
        Left = 552
        Top = 14
        Width = 289
        Height = 83
        Caption = 'Register R/W'
        TabOrder = 1
        object m_lblFMReceiver_Address: TLabel
          Left = 8
          Top = 26
          Width = 66
          Height = 13
          Caption = 'Address (Hex)'
        end
        object m_lblFMReceiver_Word: TLabel
          Left = 96
          Top = 26
          Width = 54
          Height = 13
          Caption = 'Word (Hex)'
        end
        object m_edtFMRegister_Address: TEdit
          Left = 8
          Top = 42
          Width = 81
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 0
          Text = '0'
          OnExit = m_edtFMRegister_AddressExit
        end
        object m_edtFMReceiver_Word: TEdit
          Left = 96
          Top = 42
          Width = 81
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 1
          Text = '0'
          OnExit = m_edtFMReceiver_WordExit
        end
        object m_btnFMRXRegisterWrite: TButton
          Left = 199
          Top = 48
          Width = 65
          Height = 25
          Caption = 'Write'
          TabOrder = 2
          OnClick = m_btnFMRXRegisterWriteClick
        end
        object m_btnFMRXRegisterRead: TButton
          Left = 199
          Top = 16
          Width = 65
          Height = 25
          Caption = 'Read'
          TabOrder = 3
          OnClick = m_btnFMRXRegisterReadClick
        end
        object GroupBox2: TGroupBox
          Left = 64
          Top = 88
          Width = 185
          Height = 105
          Caption = 'GroupBox2'
          TabOrder = 4
        end
      end
      object m_tbFMReceiver_Frequency: TTrackBar
        Left = 1
        Top = 34
        Width = 395
        Height = 25
        LineSize = 10
        Max = 1080
        Min = 760
        Orientation = trHorizontal
        ParentShowHint = False
        Frequency = 1
        Position = 907
        SelEnd = 0
        SelStart = 0
        ShowHint = False
        TabOrder = 2
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = m_tbFMReceiver_FrequencyChange
        OnKeyDown = m_tbFMReceiver_FrequencyKeyDown
      end
      object m_tbFMReceiver_Volume: TTrackBar
        Left = 520
        Top = 24
        Width = 25
        Height = 73
        Enabled = False
        Max = 255
        Orientation = trVertical
        Frequency = 1
        Position = 100
        SelEnd = 0
        SelStart = 0
        TabOrder = 3
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnKeyDown = m_tbFMReceiver_VolumeKeyDown
      end
      object m_btnFMRXPowerOn: TButton
        Left = 8
        Top = 64
        Width = 65
        Height = 25
        Caption = 'Power On'
        TabOrder = 4
        OnClick = btnFMRXPowerOnClick
      end
      object m_btnFMRXPowerOff: TButton
        Left = 133
        Top = 64
        Width = 65
        Height = 25
        Caption = 'Power Off'
        Enabled = False
        TabOrder = 5
        OnClick = btnFMRXPowerOffClick
      end
      object m_btnFMRXSeekLeft: TButton
        Left = 376
        Top = 64
        Width = 33
        Height = 25
        Caption = '<<'
        Enabled = False
        TabOrder = 6
        OnClick = m_btnFMRXSeekLeftClick
      end
      object m_btnFMRXSeekRight: TButton
        Left = 416
        Top = 64
        Width = 33
        Height = 25
        Caption = '>>'
        Enabled = False
        TabOrder = 7
        OnClick = m_btnFMRXSeekRightClick
      end
      object m_gbFMReceiver_ChannelList: TGroupBox
        Left = 0
        Top = 96
        Width = 545
        Height = 97
        Caption = 'Channel List'
        TabOrder = 8
        object m_lblFMReceiver_ChannelNo: TLabel
          Left = 384
          Top = 16
          Width = 59
          Height = 13
          Caption = 'Channel No.'
        end
        object lbTime: TLabel
          Left = 284
          Top = 64
          Width = 21
          Height = 25
          AutoSize = False
          Layout = tlCenter
        end
        object Label49: TLabel
          Left = 217
          Top = 64
          Width = 65
          Height = 25
          Alignment = taCenter
          AutoSize = False
          Caption = 'TimeSpend:'
          Layout = tlCenter
        end
        object Label50: TLabel
          Left = 307
          Top = 64
          Width = 15
          Height = 25
          AutoSize = False
          Caption = 's'
          Layout = tlCenter
        end
        object m_btnFMRXAutoScan: TButton
          Left = 144
          Top = 64
          Width = 65
          Height = 25
          Caption = 'Auto Scan'
          Enabled = False
          TabOrder = 0
          OnClick = m_btnFMRXAutoScanClick
        end
        object m_cbFMReceiver_ChannelList: TComboBox
          Left = 16
          Top = 32
          Width = 297
          Height = 21
          Style = csDropDownList
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 1
          OnChange = m_cbFMReceiver_ChannelListChange
        end
        object m_edtFMReceiver_ChannelSelect: TEdit
          Left = 384
          Top = 32
          Width = 81
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 2
          OnExit = m_edtFMReceiver_ChannelSelectExit
        end
        object m_btnFMRXGoChannel: TButton
          Left = 384
          Top = 64
          Width = 65
          Height = 25
          Caption = 'Go'
          Enabled = False
          TabOrder = 3
          OnClick = m_btnFMRXGoChannelClick
        end
      end
      object m_gbFMReceiver_RDSData: TGroupBox
        Left = 0
        Top = 192
        Width = 841
        Height = 73
        Caption = 'RDS Data'
        TabOrder = 9
        object m_lblFMReceiver_RDSData_: TLabel
          Left = 8
          Top = 16
          Width = 14
          Height = 13
          Caption = 'PS'
        end
        object m_lblFMReceiver_RDSData_RT: TLabel
          Left = 184
          Top = 16
          Width = 15
          Height = 13
          Caption = 'RT'
        end
        object m_btnFMRXRDSOn: TButton
          Left = 752
          Top = 8
          Width = 65
          Height = 25
          Caption = 'RDS On'
          Enabled = False
          TabOrder = 0
          OnClick = m_btnFMRDS_RDSOnClick
        end
        object m_btnFMRXRDSOff: TButton
          Left = 752
          Top = 40
          Width = 65
          Height = 25
          Caption = 'RDS Off'
          Enabled = False
          TabOrder = 1
          OnClick = m_btnFMRDS_RDSOffClick
        end
        object m_stFMReceiver_RDSData_PS: TStaticText
          Left = 8
          Top = 40
          Width = 129
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object m_stFMReceiver_RDSData_RT: TStaticText
          Left = 184
          Top = 40
          Width = 433
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
      end
      object m_gbFMReceiver_Status: TGroupBox
        Left = 0
        Top = 264
        Width = 833
        Height = 57
        Caption = 'Status'
        TabOrder = 10
        object m_lblFMReceiver_Status_RSSI: TLabel
          Left = 72
          Top = 55
          Width = 25
          Height = 13
          Caption = 'RSSI'
          Visible = False
        end
        object m_lblFMReceiver_Status_BW: TLabel
          Left = 552
          Top = 88
          Width = 18
          Height = 13
          Caption = 'BW'
          Visible = False
        end
        object m_lblFMReceiver_Status_PAMD: TLabel
          Left = 620
          Top = 88
          Width = 31
          Height = 13
          Caption = 'PAMD'
          Visible = False
        end
        object m_lblFMReceiver_Status_MR: TLabel
          Left = 393
          Top = 16
          Width = 17
          Height = 13
          Caption = 'MR'
          Visible = False
        end
        object m_lblFMReceiver_Status_Stereo_Mono: TLabel
          Left = 105
          Top = 16
          Width = 63
          Height = 13
          Caption = 'Stereo/Mono'
        end
        object m_lblFMReceiver_Status_IFCounter: TLabel
          Left = 465
          Top = 16
          Width = 49
          Height = 13
          Caption = 'IF Counter'
          Visible = False
        end
        object m_lblFMReceiver_Status_HLSide: TLabel
          Left = 533
          Top = 16
          Width = 43
          Height = 13
          Caption = 'H/L Side'
          Visible = False
        end
        object Label18: TLabel
          Left = 4
          Top = 54
          Width = 50
          Height = 13
          Caption = 'RSSI(Hex)'
          Visible = False
        end
        object Label19: TLabel
          Left = 8
          Top = 14
          Width = 52
          Height = 13
          Caption = 'RSSI(dBm)'
        end
        object Label20: TLabel
          Left = 140
          Top = 54
          Width = 56
          Height = 13
          Caption = 'PAMD(Hex)'
          Visible = False
        end
        object Label21: TLabel
          Left = 208
          Top = 54
          Width = 19
          Height = 13
          Caption = '(dB)'
          Visible = False
        end
        object Label22: TLabel
          Left = 276
          Top = 54
          Width = 50
          Height = 13
          Caption = 'RSSI HCC'
          Visible = False
        end
        object Label23: TLabel
          Left = 344
          Top = 54
          Width = 56
          Height = 13
          Caption = 'PAMD HCC'
          Visible = False
        end
        object Label24: TLabel
          Left = 412
          Top = 54
          Width = 50
          Height = 13
          Caption = 'RSSI off.B'
          Visible = False
        end
        object Label25: TLabel
          Left = 480
          Top = 54
          Width = 56
          Height = 13
          Caption = 'PAMD off.B'
          Visible = False
        end
        object Label26: TLabel
          Left = 548
          Top = 54
          Width = 51
          Height = 13
          Caption = 'RSSI off.H'
          Visible = False
        end
        object Label27: TLabel
          Left = 620
          Top = 54
          Width = 57
          Height = 13
          Caption = 'PAMD off.H'
          Visible = False
        end
        object Label28: TLabel
          Left = 684
          Top = 54
          Width = 44
          Height = 13
          Caption = 'HCC filter'
          Visible = False
        end
        object Label29: TLabel
          Left = 752
          Top = 54
          Width = 65
          Height = 13
          Caption = 'Softmute step'
          Visible = False
        end
        object Label30: TLabel
          Left = 4
          Top = 96
          Width = 50
          Height = 13
          Caption = 'Blend gain'
          Visible = False
        end
        object Label31: TLabel
          Left = 4
          Top = 120
          Width = 87
          Height = 13
          Caption = 'Blend filter number'
          Visible = False
        end
        object Label32: TLabel
          Left = 344
          Top = 96
          Width = 66
          Height = 13
          Caption = 'Dynamic Gain'
          Visible = False
        end
        object Label33: TLabel
          Left = 344
          Top = 120
          Width = 75
          Height = 13
          Caption = 'Pilot locked flag'
          Visible = False
        end
        object Label34: TLabel
          Left = 556
          Top = 128
          Width = 107
          Height = 13
          Caption = 'Softmute selection flag'
          Visible = False
        end
        object Label35: TLabel
          Left = 564
          Top = 24
          Width = 75
          Height = 13
          Caption = 'Update interval:'
          Visible = False
        end
        object Label36: TLabel
          Left = 4
          Top = 144
          Width = 46
          Height = 13
          Caption = 'LNA Gain'
          Visible = False
        end
        object Label37: TLabel
          Left = 72
          Top = 144
          Width = 62
          Height = 13
          Caption = 'LNA Gain ldx'
          Visible = False
        end
        object Label39: TLabel
          Left = 140
          Top = 144
          Width = 47
          Height = 13
          Caption = 'PGA Gain'
          Visible = False
        end
        object Label40: TLabel
          Left = 208
          Top = 144
          Width = 63
          Height = 13
          Caption = 'PGA Gain ldx'
          Visible = False
        end
        object Label41: TLabel
          Left = 276
          Top = 144
          Width = 61
          Height = 13
          Caption = 'Gain counter'
          Visible = False
        end
        object Label43: TLabel
          Left = 344
          Top = 144
          Width = 66
          Height = 13
          Caption = 'RF Total Gain'
          Visible = False
        end
        object Label42: TLabel
          Left = 412
          Top = 144
          Width = 35
          Height = 13
          Caption = 'Chip ID'
          Visible = False
        end
        object Label44: TLabel
          Left = 480
          Top = 144
          Width = 54
          Height = 13
          Caption = 'Pulse Ratio'
          Visible = False
        end
        object Label45: TLabel
          Left = 548
          Top = 144
          Width = 54
          Height = 13
          Caption = 'Fast PAMD'
          Visible = False
        end
        object Label46: TLabel
          Left = 616
          Top = 144
          Width = 72
          Height = 13
          Caption = 'Power detector'
          Visible = False
        end
        object Label60: TLabel
          Left = 200
          Top = 15
          Width = 64
          Height = 13
          Caption = 'Cap Array(pF)'
        end
        object Label38: TLabel
          Left = 208
          Top = 96
          Width = 66
          Height = 13
          Caption = 'Softmute Gms'
          Visible = False
        end
        object Label62: TLabel
          Left = 208
          Top = 120
          Width = 61
          Height = 13
          Caption = 'Softmute Gfs'
          Visible = False
        end
        object Label55: TLabel
          Left = 288
          Top = 15
          Width = 72
          Height = 13
          Caption = 'Cap Reg Value'
        end
        object m_btnFMRXStatusUpdate: TButton
          Left = 744
          Top = 16
          Width = 81
          Height = 25
          Caption = 'Status Update'
          Enabled = False
          TabOrder = 0
          OnClick = m_btnFMRXStatusUpdateClick
        end
        object m_stFMReceiver_Status_RSSI: TStaticText
          Left = 72
          Top = 71
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 1
          Visible = False
        end
        object m_stFMReceiver_Status_BW: TStaticText
          Left = 552
          Top = 104
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 2
          Visible = False
        end
        object m_stFMReceiver_Status_PAMD: TStaticText
          Left = 620
          Top = 104
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 3
          Visible = False
        end
        object m_stFMReceiver_Status_MR: TStaticText
          Left = 393
          Top = 32
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 4
          Visible = False
        end
        object m_stFMReceiver_Status_Stereo_Mono: TStaticText
          Left = 105
          Top = 32
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 5
        end
        object m_stFMReceiver_Status_IFCounter: TStaticText
          Left = 465
          Top = 32
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 6
          Visible = False
        end
        object stFMRSSIoffH: TStaticText
          Left = 548
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 7
          Visible = False
        end
        object stFMRSSIhex: TStaticText
          Left = 4
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 8
          Visible = False
        end
        object stFMRSSIdbm: TStaticText
          Left = 8
          Top = 32
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 9
        end
        object stFMPAMDhex: TStaticText
          Left = 140
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 10
          Visible = False
        end
        object stFMPAMDdb: TStaticText
          Left = 208
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 11
          Visible = False
        end
        object stFMRSSIH: TStaticText
          Left = 276
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 12
          Visible = False
        end
        object stFMPAMDH: TStaticText
          Left = 344
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 13
          Visible = False
        end
        object stFMRSSIoffB: TStaticText
          Left = 412
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 14
          Visible = False
        end
        object stFMPAMDoffB: TStaticText
          Left = 480
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 15
          Visible = False
        end
        object m_stFMReceiver_Status_HLSide: TStaticText
          Left = 533
          Top = 32
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 16
          Visible = False
        end
        object stFMPAMDoffH: TStaticText
          Left = 616
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 17
          Visible = False
        end
        object stFMHCCFilter: TStaticText
          Left = 684
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 18
          Visible = False
        end
        object stFMSoftmuteStep: TStaticText
          Left = 752
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 19
          Visible = False
        end
        object stFMBlendGain: TStaticText
          Left = 140
          Top = 96
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 20
          Visible = False
        end
        object stFMBFN: TStaticText
          Left = 140
          Top = 120
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 21
          Visible = False
        end
        object stFMDynamicGain: TStaticText
          Left = 480
          Top = 96
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 22
          Visible = False
        end
        object stFMPLF: TStaticText
          Left = 480
          Top = 128
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 23
          Visible = False
        end
        object stFMSSF: TStaticText
          Left = 692
          Top = 128
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 24
          Visible = False
        end
        object StaticText18: TStaticText
          Left = 656
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 25
          Visible = False
        end
        object stFMLNAGain2: TStaticText
          Left = 4
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 26
          Visible = False
        end
        object stFMLNAGainIdx2: TStaticText
          Left = 72
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 27
          Visible = False
        end
        object stFMPGAGain2: TStaticText
          Left = 140
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 28
          Visible = False
        end
        object stFMPGAGainIdx2: TStaticText
          Left = 208
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 29
          Visible = False
        end
        object stFMGainCounter2: TStaticText
          Left = 276
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 30
          Visible = False
        end
        object stFMRfTotalGain2: TStaticText
          Left = 344
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 31
          Visible = False
        end
        object stFMChipID: TStaticText
          Left = 412
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 32
          Visible = False
        end
        object stFMPulseRatio: TStaticText
          Left = 480
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 33
          Visible = False
        end
        object stFMFastPAMD: TStaticText
          Left = 548
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 34
          Visible = False
        end
        object stFMPowerDetector: TStaticText
          Left = 616
          Top = 160
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 35
          Visible = False
        end
        object stCapArray: TStaticText
          Left = 200
          Top = 32
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 36
        end
        object stFMSoftmuteGms: TStaticText
          Left = 276
          Top = 96
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 37
          Visible = False
        end
        object stFMSoftmuteGfs: TStaticText
          Left = 276
          Top = 120
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 38
          Visible = False
        end
        object stCapRegValue: TStaticText
          Left = 288
          Top = 32
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 39
        end
      end
      object m_gbFMReceiver_Settings: TGroupBox
        Left = -8
        Top = 368
        Width = 9
        Height = 9
        Caption = 'Settings'
        TabOrder = 11
        Visible = False
        object m_lblFMReceiver_Setting_DecodeMode: TLabel
          Left = 16
          Top = 24
          Width = 68
          Height = 13
          Caption = 'Decode Mode'
        end
        object m_lblFMReceiver_Setting_StereoBlend: TLabel
          Left = 120
          Top = 24
          Width = 61
          Height = 13
          Caption = 'Stereo Blend'
        end
        object m_lblFMReceiver_Setting_HCC: TLabel
          Left = 224
          Top = 24
          Width = 22
          Height = 13
          Caption = 'HCC'
        end
        object m_lblFMReceiver_Setting_PAMDThreshold: TLabel
          Left = 328
          Top = 24
          Width = 81
          Height = 13
          Caption = 'PAMD Threshold'
        end
        object m_lblFMReceiver_Setting_RSSIThreshold: TLabel
          Left = 432
          Top = 24
          Width = 75
          Height = 13
          Caption = 'RSSI Threshold'
        end
        object m_lblFMReceiver_Setting_SoftMute: TLabel
          Left = 536
          Top = 24
          Width = 46
          Height = 13
          Caption = 'Soft Mute'
        end
        object m_lblFMReceiver_Setting_HLSide: TLabel
          Left = 120
          Top = 88
          Width = 43
          Height = 13
          Caption = 'H/L Side'
        end
        object m_lblFMReceiver_Setting_De_emphasisLevel: TLabel
          Left = 16
          Top = 88
          Width = 90
          Height = 13
          Caption = 'De-emphasis Level'
        end
        object m_lblFMReceiver_Setting_SoftMuteRate: TLabel
          Left = 432
          Top = 88
          Width = 72
          Height = 13
          Caption = 'Soft Mute Rate'
        end
        object m_lblFMReceiver_Setting_DynamicLimiter: TLabel
          Left = 328
          Top = 88
          Width = 74
          Height = 13
          Caption = 'Dynamic Limiter'
        end
        object m_lblFMReceiver_Setting_DemodBandwidth: TLabel
          Left = 224
          Top = 88
          Width = 87
          Height = 13
          Caption = 'Demod Bandwidth'
        end
        object m_lblFMReceiver_Setting_StereoBlendLevel: TLabel
          Left = 536
          Top = 88
          Width = 90
          Height = 13
          Caption = 'Stereo Blend Level'
        end
        object Label47: TLabel
          Left = 640
          Top = 24
          Width = 45
          Height = 13
          Caption = 'Cap array'
        end
        object Label48: TLabel
          Left = 640
          Top = 88
          Width = 57
          Height = 13
          Caption = 'Demod type'
        end
        object Label61: TLabel
          Left = 16
          Top = 160
          Width = 105
          Height = 13
          Caption = 'Calibration mode Type'
        end
        object m_btnFMRXSet: TButton
          Left = 704
          Top = 152
          Width = 65
          Height = 25
          Caption = 'Set'
          TabOrder = 0
          OnClick = m_btnFMRXSetClick
        end
        object m_cbFMReceiver_Setting_DecodeMode: TComboBox
          Left = 16
          Top = 40
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 1
          Text = 'Auto'
          Items.Strings = (
            'Auto'
            'Mono')
        end
        object m_cbFMReceiver_Setting_De_emphasisLevel: TComboBox
          Left = 16
          Top = 104
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 1
          TabOrder = 2
          Text = '50 '#956's'
          Items.Strings = (
            '0 '#956's'
            '50 '#956's'
            '75 '#956's')
        end
        object m_cbFMReceiver_Setting_StereoBlend: TComboBox
          Left = 120
          Top = 40
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 1
          TabOrder = 3
          Text = 'On'
          Items.Strings = (
            'Off'
            'On')
        end
        object m_cbFMReceiver_Setting_HLSide: TComboBox
          Left = 120
          Top = 104
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 4
          Text = 'Auto'
          Items.Strings = (
            'Auto'
            'L-side'
            'H-side')
        end
        object m_cbFMReceiver_Setting_HCC: TComboBox
          Left = 224
          Top = 40
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 1
          TabOrder = 5
          Text = 'On'
          Items.Strings = (
            'Off'
            'On')
        end
        object m_cbFMReceiver_Setting_DemodBandwidth: TComboBox
          Left = 224
          Top = 104
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 2
          TabOrder = 6
          Text = 'Force Wide'
          Items.Strings = (
            'Auto'
            'Force Narrow'
            'Force Wide')
        end
        object m_cbFMReceiver_Setting_DynamicLimiter: TComboBox
          Left = 328
          Top = 104
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 7
          Text = 'Off'
          Items.Strings = (
            'Off'
            'On')
        end
        object m_edtFMReceiver_Setting_PAMDThreshold: TEdit
          Left = 328
          Top = 40
          Width = 89
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 8
          Text = '0'
        end
        object m_edtFMReceiver_Setting_RSSIThreshold: TEdit
          Left = 432
          Top = 40
          Width = 89
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 9
          Text = '0'
        end
        object m_edtFMReceiver_Setting_SoftMuteRate: TEdit
          Left = 432
          Top = 104
          Width = 89
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 10
          Text = '0'
        end
        object m_cbFMReceiver_Setting_SoftMute: TComboBox
          Left = 536
          Top = 40
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 1
          TabOrder = 11
          Text = 'On'
          Items.Strings = (
            'Off'
            'On')
        end
        object m_cbFMReceiver_Setting_StereoBlendLevel: TComboBox
          Left = 536
          Top = 104
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 12
          Text = '1'
          Items.Strings = (
            '1'
            '2'
            '3')
        end
        object edtFMCapArray: TEdit
          Left = 640
          Top = 40
          Width = 89
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 13
          Text = '0'
        end
        object cbFMDemodType: TComboBox
          Left = 640
          Top = 104
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 14
          Text = '1'
          Items.Strings = (
            '1'
            '2'
            '3')
        end
        object ComboBox2: TComboBox
          Left = 16
          Top = 176
          Width = 89
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 0
          TabOrder = 15
          Text = 'Auto'
          Items.Strings = (
            'Auto'
            'Manual')
        end
      end
      object m_edtFMReceiver_CurrentFrequency: TEdit
        Left = 432
        Top = 32
        Width = 57
        Height = 21
        Enabled = False
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 12
        Text = '90.7'
        OnExit = edtFreqCheck
        OnKeyDown = m_edtFMReceiver_CurrentFrequencyKeyDown
      end
      object m_btnFMRXSetFrequency: TButton
        Left = 250
        Top = 64
        Width = 81
        Height = 25
        Caption = 'Set Frequency'
        Enabled = False
        TabOrder = 13
        OnClick = m_btnFMRXSetFrequencyClick
      end
      object m_btnFMRXSetVolume: TButton
        Left = 456
        Top = 64
        Width = 65
        Height = 25
        Caption = 'Set Volume'
        Enabled = False
        TabOrder = 14
        OnClick = m_btnFMRXSetVolumeClick
      end
      object GroupBox3: TGroupBox
        Left = 552
        Top = 96
        Width = 289
        Height = 97
        Caption = 'Antenna Switching'
        TabOrder = 15
        object m_btnSetAntennaType: TButton
          Left = 104
          Top = 48
          Width = 65
          Height = 25
          Caption = 'Set type'
          Enabled = False
          TabOrder = 0
          OnClick = m_btnSetAntennaTypeClick
        end
        object rbEarPhone: TRadioButton
          Left = 8
          Top = 40
          Width = 89
          Height = 25
          Caption = 'Ear phone'
          Checked = True
          Enabled = False
          TabOrder = 1
          TabStop = True
        end
        object rbShortAnt: TRadioButton
          Left = 8
          Top = 64
          Width = 81
          Height = 17
          Caption = 'Short Ant.'
          Enabled = False
          TabOrder = 2
        end
      end
      object m_udFMReceiver_Tune: TUpDown
        Left = 779
        Top = 336
        Width = 17
        Height = 25
        Min = 875
        Max = 1080
        Position = 875
        TabOrder = 16
        Visible = False
        Wrap = False
      end
      object m_btnFMRXTune_Increase: TButton
        Tag = 907
        Left = 399
        Top = 30
        Width = 25
        Height = 14
        Caption = '+'
        Enabled = False
        TabOrder = 17
        OnClick = m_btnFMRXTune_IncreaseClick
      end
      object m_btnFMRXTune_Decrease: TButton
        Tag = 907
        Left = 399
        Top = 48
        Width = 25
        Height = 14
        Caption = '-'
        Enabled = False
        TabOrder = 18
        OnClick = m_btnFMRXTune_DecreaseClick
      end
      object gbAudioTest: TGroupBox
        Left = 0
        Top = 336
        Width = 209
        Height = 65
        Caption = 'Audio Test'
        TabOrder = 19
        object btnAudioTest: TButton
          Left = 16
          Top = 24
          Width = 73
          Height = 25
          Caption = 'Audio Test'
          TabOrder = 0
          OnClick = btnAudioTestClick
        end
        object stAudioTest: TStaticText
          Left = 113
          Top = 28
          Width = 72
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 1
        end
      end
    end
    object m_tsFMRDS: TTabSheet
      Caption = 'RDS Receive Data'
      ImageIndex = 2
      object Label7: TLabel
        Left = 8
        Top = 288
        Width = 143
        Height = 13
        Caption = 'RDS Query Timer Interval (ms)'
      end
      object m_sbFMRDS: TStatusBar
        Left = 0
        Top = 586
        Width = 841
        Height = 27
        Panels = <
          item
            Width = 650
          end>
        SimplePanel = False
      end
      object m_gbFMRDS_RDS: TGroupBox
        Left = 8
        Top = 8
        Width = 641
        Height = 121
        Caption = 'RDS'
        TabOrder = 1
        object m_lblRDSData_RDS_PS: TLabel
          Left = 24
          Top = 24
          Width = 14
          Height = 13
          Caption = 'PS'
        end
        object m_lblRDSData_RDS_RT: TLabel
          Left = 24
          Top = 48
          Width = 15
          Height = 13
          Caption = 'RT'
        end
        object m_lblRDSData_RDS_CT: TLabel
          Left = 24
          Top = 72
          Width = 14
          Height = 13
          Caption = 'CT'
        end
        object m_lblRDSData_RDS_PTY: TLabel
          Left = 240
          Top = 24
          Width = 21
          Height = 13
          Caption = 'PTY'
        end
        object m_lblRDSData_RDS_PI: TLabel
          Left = 368
          Top = 24
          Width = 10
          Height = 13
          Caption = 'PI'
        end
        object m_lblRDSData_RDS_RDSSYNC: TLabel
          Left = 488
          Top = 24
          Width = 55
          Height = 13
          Caption = 'RDS SYNC'
        end
        object m_lblRDSData_RDS_RTDISPLAY: TLabel
          Left = 480
          Top = 48
          Width = 63
          Height = 13
          Caption = 'RT DISPLAY'
        end
        object m_lblRDSData_RDS_PSDISPLAY: TLabel
          Left = 480
          Top = 72
          Width = 62
          Height = 13
          Caption = 'PS DISPLAY'
        end
        object m_lblRDSData_RDS_TP: TLabel
          Left = 368
          Top = 72
          Width = 14
          Height = 13
          Caption = 'TP'
        end
        object m_lblRDSData_RDS_TA: TLabel
          Left = 24
          Top = 96
          Width = 14
          Height = 13
          Caption = 'TA'
        end
        object Label52: TLabel
          Left = 624
          Top = 24
          Width = 13
          Height = 13
          Caption = 'ms'
        end
        object Label53: TLabel
          Left = 624
          Top = 48
          Width = 13
          Height = 13
          Caption = 'ms'
        end
        object Label54: TLabel
          Left = 624
          Top = 72
          Width = 13
          Height = 13
          Caption = 'ms'
        end
        object m_btnFMRDS_RDSOn: TButton
          Left = 480
          Top = 94
          Width = 65
          Height = 22
          Caption = 'RDS On'
          Enabled = False
          TabOrder = 0
          OnClick = m_btnFMRDS_RDSOnClick
        end
        object m_btnFMRDS_RDSOff: TButton
          Left = 552
          Top = 94
          Width = 65
          Height = 22
          Caption = 'RDS Off'
          Enabled = False
          TabOrder = 1
          OnClick = m_btnFMRDS_RDSOffClick
        end
        object m_stRDSData_RDS_PS: TStaticText
          Left = 48
          Top = 24
          Width = 169
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object m_stRDSData_RDS_PTY: TStaticText
          Left = 272
          Top = 24
          Width = 81
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object m_stRDSData_RDS_PI: TStaticText
          Left = 392
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
        object m_stRDSData_RDS_RT: TStaticText
          Left = 48
          Top = 48
          Width = 409
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 5
        end
        object m_stRDSData_RDS_CT: TStaticText
          Left = 48
          Top = 72
          Width = 305
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 6
        end
        object m_stRDSData_RDS_RDSSYNC: TStaticText
          Left = 552
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 7
        end
        object m_stRDSData_RDS_RTDISPLAY: TStaticText
          Left = 552
          Top = 48
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 8
        end
        object m_stRDSData_RDS_PSDISPLAY: TStaticText
          Left = 552
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 9
        end
        object m_stRDSData_RDS_TP: TStaticText
          Left = 392
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 10
        end
        object m_stRDSData_RDS_TA: TStaticText
          Left = 48
          Top = 96
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 11
        end
      end
      object m_gbRDSData_BlockCounter_Accepted: TGroupBox
        Left = 8
        Top = 136
        Width = 641
        Height = 137
        Caption = 'Block Counter'
        TabOrder = 2
        object m_lblRDSData_BlockCounter_TotalRecv: TLabel
          Left = 24
          Top = 72
          Width = 53
          Height = 13
          Caption = 'Total Recv'
        end
        object m_lblRDSData_BlockCounter_Errors: TLabel
          Left = 24
          Top = 48
          Width = 27
          Height = 13
          Caption = 'Errors'
        end
        object m_lblRDSData_BlockCounter_Accepted: TLabel
          Left = 24
          Top = 24
          Width = 46
          Height = 13
          Caption = 'Accepted'
        end
        object m_lblRDSData_BlockCounter_Ratio: TLabel
          Left = 24
          Top = 96
          Width = 45
          Height = 13
          Caption = 'BLER (%)'
        end
        object Label5: TLabel
          Left = 272
          Top = 16
          Width = 40
          Height = 21
          AutoSize = False
          Caption = 'AF List'
          Layout = tlCenter
        end
        object m_btnFMRDS_BlockCounterReset: TButton
          Left = 184
          Top = 96
          Width = 65
          Height = 20
          Caption = 'Reset'
          Enabled = False
          TabOrder = 0
          OnClick = m_btnFMRDS_BlockCounterResetClick
        end
        object m_stRDSData_BlockCounter_TotalRecv: TStaticText
          Left = 96
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object m_stRDSData_BlockCounter_Errors: TStaticText
          Left = 96
          Top = 48
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object m_stRDSData_BlockCounter_Accepted: TStaticText
          Left = 96
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object m_stRDSData_BlockCounter_BLER: TStaticText
          Left = 96
          Top = 96
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
        object m_cbxAFList: TComboBox
          Left = 320
          Top = 16
          Width = 297
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 0
          TabOrder = 5
        end
      end
      object m_gbFMRDS_GroupCounter: TGroupBox
        Left = 8
        Top = 368
        Width = 641
        Height = 209
        Caption = 'Group Counter'
        TabOrder = 3
        object m_lblRDSData_GroupCounter_0A: TLabel
          Left = 24
          Top = 24
          Width = 13
          Height = 13
          Caption = '0A'
        end
        object m_lblRDSData_GroupCounter_0B: TLabel
          Left = 24
          Top = 56
          Width = 13
          Height = 13
          Caption = '0B'
        end
        object m_lblRDSData_GroupCounter_1A: TLabel
          Left = 24
          Top = 88
          Width = 13
          Height = 13
          Caption = '1A'
        end
        object m_lblRDSData_GroupCounter_1B: TLabel
          Left = 24
          Top = 120
          Width = 13
          Height = 13
          Caption = '1B'
        end
        object m_lblRDSData_GroupCounter_2A: TLabel
          Left = 24
          Top = 152
          Width = 13
          Height = 13
          Caption = '2A'
        end
        object m_lblRDSData_GroupCounter_2B: TLabel
          Left = 24
          Top = 184
          Width = 13
          Height = 13
          Caption = '2B'
        end
        object m_lblRDSData_GroupCounter_3A: TLabel
          Left = 128
          Top = 24
          Width = 13
          Height = 13
          Caption = '3A'
        end
        object m_lblRDSData_GroupCounter_3B: TLabel
          Left = 128
          Top = 56
          Width = 13
          Height = 13
          Caption = '3B'
        end
        object m_lblRDSData_GroupCounter_4A: TLabel
          Left = 128
          Top = 88
          Width = 13
          Height = 13
          Caption = '4A'
        end
        object m_lblRDSData_GroupCounter_4B: TLabel
          Left = 128
          Top = 120
          Width = 13
          Height = 13
          Caption = '4B'
        end
        object m_lblRDSData_GroupCounter_5A: TLabel
          Left = 128
          Top = 152
          Width = 13
          Height = 13
          Caption = '5A'
        end
        object m_lblRDSData_GroupCounter_5B: TLabel
          Left = 128
          Top = 184
          Width = 13
          Height = 13
          Caption = '5B'
        end
        object m_lblRDSData_GroupCounter_6A: TLabel
          Left = 232
          Top = 24
          Width = 13
          Height = 13
          Caption = '6A'
        end
        object m_lblRDSData_GroupCounter_6B: TLabel
          Left = 232
          Top = 56
          Width = 13
          Height = 13
          Caption = '6B'
        end
        object m_lblRDSData_GroupCounter_7A: TLabel
          Left = 232
          Top = 88
          Width = 13
          Height = 13
          Caption = '7A'
        end
        object m_lblRDSData_GroupCounter_7B: TLabel
          Left = 232
          Top = 120
          Width = 13
          Height = 13
          Caption = '7B'
        end
        object m_lblRDSData_GroupCounter_8A: TLabel
          Left = 232
          Top = 152
          Width = 13
          Height = 13
          Caption = '8A'
        end
        object m_lblRDSData_GroupCounter_8B: TLabel
          Left = 232
          Top = 184
          Width = 13
          Height = 13
          Caption = '8B'
        end
        object m_lblRDSData_GroupCounter_9A: TLabel
          Left = 336
          Top = 24
          Width = 13
          Height = 13
          Caption = '9A'
        end
        object m_lblRDSData_GroupCounter_9B: TLabel
          Left = 336
          Top = 56
          Width = 13
          Height = 13
          Caption = '9B'
        end
        object m_lblRDSData_GroupCounter_10A: TLabel
          Left = 328
          Top = 88
          Width = 19
          Height = 13
          Caption = '10A'
        end
        object m_lblRDSData_GroupCounter_10B: TLabel
          Left = 328
          Top = 120
          Width = 19
          Height = 13
          Caption = '10B'
        end
        object m_lblRDSData_GroupCounter_11A: TLabel
          Left = 328
          Top = 152
          Width = 19
          Height = 13
          Caption = '11A'
        end
        object m_lblRDSData_GroupCounter_11B: TLabel
          Left = 328
          Top = 184
          Width = 19
          Height = 13
          Caption = '11B'
        end
        object m_lblRDSData_GroupCounter_12A: TLabel
          Left = 432
          Top = 24
          Width = 19
          Height = 13
          Caption = '12A'
        end
        object m_lblRDSData_GroupCounter_12B: TLabel
          Left = 432
          Top = 56
          Width = 19
          Height = 13
          Caption = '12B'
        end
        object m_lblRDSData_GroupCounter_13A: TLabel
          Left = 432
          Top = 88
          Width = 19
          Height = 13
          Caption = '13A'
        end
        object m_lblRDSData_GroupCounter_13B: TLabel
          Left = 432
          Top = 120
          Width = 19
          Height = 13
          Caption = '13B'
        end
        object m_lblRDSData_GroupCounter_14A: TLabel
          Left = 432
          Top = 152
          Width = 19
          Height = 13
          Caption = '14A'
        end
        object m_lblRDSData_GroupCounter_14B: TLabel
          Left = 432
          Top = 184
          Width = 19
          Height = 13
          Caption = '14B'
        end
        object m_lblRDSData_GroupCounter_15A: TLabel
          Left = 584
          Top = 16
          Width = 19
          Height = 13
          Caption = '15A'
        end
        object m_lblRDSData_GroupCounter_15B: TLabel
          Left = 584
          Top = 56
          Width = 19
          Height = 13
          Caption = '15B'
        end
        object m_lblRDSData_GroupCounter_Total: TLabel
          Left = 584
          Top = 96
          Width = 24
          Height = 13
          Caption = 'Total'
        end
        object m_btnFMRDS_GroupCounterReset: TButton
          Left = 560
          Top = 168
          Width = 65
          Height = 25
          Caption = 'Reset'
          Enabled = False
          TabOrder = 0
          OnClick = m_btnFMRDS_GroupCounterResetClick
        end
        object m_stRDSData_GroupCounter_0A: TStaticText
          Left = 40
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object m_stRDSData_GroupCounter_0B: TStaticText
          Left = 40
          Top = 56
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object m_stRDSData_GroupCounter_1A: TStaticText
          Left = 40
          Top = 88
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object m_stRDSData_GroupCounter_1B: TStaticText
          Left = 40
          Top = 120
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
        object m_stRDSData_GroupCounter_2A: TStaticText
          Left = 40
          Top = 152
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 5
        end
        object m_stRDSData_GroupCounter_2B: TStaticText
          Left = 40
          Top = 184
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 6
        end
        object m_stRDSData_GroupCounter_5B: TStaticText
          Left = 144
          Top = 184
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 7
        end
        object m_stRDSData_GroupCounter_5A: TStaticText
          Left = 144
          Top = 152
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 8
        end
        object m_stRDSData_GroupCounter_4B: TStaticText
          Left = 144
          Top = 120
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 9
        end
        object m_stRDSData_GroupCounter_4A: TStaticText
          Left = 144
          Top = 88
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 10
        end
        object m_stRDSData_GroupCounter_3B: TStaticText
          Left = 144
          Top = 56
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 11
        end
        object m_stRDSData_GroupCounter_3A: TStaticText
          Left = 144
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 12
        end
        object m_stRDSData_GroupCounter_8B: TStaticText
          Left = 248
          Top = 184
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 13
        end
        object m_stRDSData_GroupCounter_8A: TStaticText
          Left = 248
          Top = 152
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 14
        end
        object m_stRDSData_GroupCounter_7B: TStaticText
          Left = 248
          Top = 120
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 15
        end
        object m_stRDSData_GroupCounter_7A: TStaticText
          Left = 248
          Top = 88
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 16
        end
        object m_stRDSData_GroupCounter_6B: TStaticText
          Left = 248
          Top = 56
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 17
        end
        object m_stRDSData_GroupCounter_6A: TStaticText
          Left = 248
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 18
        end
        object m_stRDSData_GroupCounter_11B: TStaticText
          Left = 352
          Top = 184
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 19
        end
        object m_stRDSData_GroupCounter_11A: TStaticText
          Left = 352
          Top = 152
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 20
        end
        object m_stRDSData_GroupCounter_10B: TStaticText
          Left = 352
          Top = 120
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 21
        end
        object m_stRDSData_GroupCounter_10A: TStaticText
          Left = 352
          Top = 88
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 22
        end
        object m_stRDSData_GroupCounter_9B: TStaticText
          Left = 352
          Top = 56
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 23
        end
        object m_stRDSData_GroupCounter_9A: TStaticText
          Left = 352
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 24
        end
        object m_stRDSData_GroupCounter_14B: TStaticText
          Left = 456
          Top = 184
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 25
        end
        object m_stRDSData_GroupCounter_14A: TStaticText
          Left = 456
          Top = 152
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 26
        end
        object m_stRDSData_GroupCounter_13B: TStaticText
          Left = 456
          Top = 120
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 27
        end
        object m_stRDSData_GroupCounter_13A: TStaticText
          Left = 456
          Top = 88
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 28
        end
        object m_stRDSData_GroupCounter_12B: TStaticText
          Left = 456
          Top = 56
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 29
        end
        object m_stRDSData_GroupCounter_12A: TStaticText
          Left = 456
          Top = 24
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 30
        end
        object m_stRDSData_GroupCounter_15A: TStaticText
          Left = 560
          Top = 32
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 31
        end
        object m_stRDSData_GroupCounter_15B: TStaticText
          Left = 560
          Top = 72
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 32
        end
        object m_stRDSData_GroupCounter_Total: TStaticText
          Left = 560
          Top = 112
          Width = 65
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BorderStyle = sbsSunken
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 33
        end
      end
      object m_edtRDSQueryTimer: TEdit
        Left = 168
        Top = 288
        Width = 65
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 4
        Text = '3000'
        OnExit = m_edtRDSQueryTimerExit
      end
      object m_gbFMRDS_RDSLogData: TGroupBox
        Left = 280
        Top = 280
        Width = 369
        Height = 81
        Caption = 'RDS Log Data'
        TabOrder = 5
        object m_richedtRDSLog: TRichEdit
          Left = 8
          Top = 16
          Width = 201
          Height = 57
          Font.Charset = GB2312_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ParentFont = False
          ReadOnly = True
          ScrollBars = ssVertical
          TabOrder = 0
        end
      end
    end
    object tsFMTx: TTabSheet
      Caption = 'FM Transmitter Main Window'
      ImageIndex = 3
      object gbFMTxRFandModu: TGroupBox
        Left = 16
        Top = 40
        Width = 377
        Height = 513
        Caption = 'RF and modulation control'
        TabOrder = 0
        object Label171: TLabel
          Left = 8
          Top = 24
          Width = 64
          Height = 13
          Caption = 'RF frequency'
        end
        object Label172: TLabel
          Left = 240
          Top = 24
          Width = 22
          Height = 13
          Caption = 'MHz'
        end
        object Label173: TLabel
          Left = 8
          Top = 57
          Width = 39
          Height = 13
          Caption = 'RF level'
        end
        object Label174: TLabel
          Left = 240
          Top = 57
          Width = 26
          Height = 13
          Caption = 'dBuV'
        end
        object Label223: TLabel
          Left = 8
          Top = 90
          Width = 69
          Height = 13
          Caption = 'Varactor value'
        end
        object Label163: TLabel
          Left = 240
          Top = 223
          Width = 19
          Height = 13
          Caption = 'kHz'
        end
        object Label161: TLabel
          Left = 352
          Top = 187
          Width = 19
          Height = 13
          Caption = 'kHz'
        end
        object Label160: TLabel
          Left = 352
          Top = 153
          Width = 19
          Height = 13
          Caption = 'kHz'
        end
        object Label158: TLabel
          Left = 240
          Top = 123
          Width = 19
          Height = 13
          Caption = 'kHz'
        end
        object Label164: TLabel
          Left = 8
          Top = 223
          Width = 70
          Height = 13
          Caption = 'Total deviation'
        end
        object Label162: TLabel
          Left = 240
          Top = 187
          Width = 43
          Height = 13
          Caption = 'deviation'
        end
        object Label159: TLabel
          Left = 240
          Top = 153
          Width = 43
          Height = 13
          Caption = 'deviation'
        end
        object Label157: TLabel
          Left = 8
          Top = 123
          Width = 73
          Height = 13
          Caption = 'Audio deviation'
        end
        object Label167: TLabel
          Left = 8
          Top = 187
          Width = 55
          Height = 13
          Caption = 'RDS on/off'
        end
        object Label169: TLabel
          Left = 8
          Top = 293
          Width = 63
          Height = 13
          Caption = 'Stereo/Mono'
        end
        object Label166: TLabel
          Left = 8
          Top = 153
          Width = 52
          Height = 13
          Caption = 'Pilot on/off'
        end
        object Label170: TLabel
          Left = 8
          Top = 260
          Width = 84
          Height = 13
          Caption = 'Modulation on/off'
        end
        object Label225: TLabel
          Left = 8
          Top = 326
          Width = 70
          Height = 13
          Caption = 'Pilot frequency'
        end
        object Label226: TLabel
          Left = 240
          Top = 326
          Width = 19
          Height = 13
          Caption = 'kHz'
        end
        object Label168: TLabel
          Left = 8
          Top = 360
          Width = 63
          Height = 13
          Caption = 'Pre-emphasis'
        end
        object Label51: TLabel
          Left = 240
          Top = 89
          Width = 12
          Height = 13
          Caption = 'pF'
        end
        object stFMTxVaractorValue: TStaticText
          Left = 96
          Top = 84
          Width = 137
          Height = 21
          AutoSize = False
          Color = clSkyBlue
          Enabled = False
          ParentColor = False
          TabOrder = 1
        end
        object edtFMTxAudioDeviation: TEdit
          Left = 96
          Top = 119
          Width = 121
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 2
          Text = '68.25'
          OnExit = edtFMTxExit
          OnKeyPress = edtFMTxAudioDeviationKeyPress
        end
        object udFMTxAudioDeviation: TUpDown
          Left = 216
          Top = 119
          Width = 15
          Height = 21
          Enabled = False
          Min = 0
          Max = 9000
          Position = 6825
          TabOrder = 12
          Wrap = False
          OnChanging = udFMTxAudioDeviationChanging
        end
        object udFMTxPilotDeviation: TUpDown
          Left = 328
          Top = 153
          Width = 15
          Height = 21
          Enabled = False
          Min = 0
          Max = 9000
          Position = 675
          TabOrder = 13
          Wrap = False
          OnChanging = udFMTxPilotDeviationChanging
        end
        object edtFMTxPilotDeviation: TEdit
          Left = 296
          Top = 153
          Width = 33
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 4
          Text = '6.75'
          OnExit = edtFMTxExit
          OnKeyPress = edtFMTxPilotDeviationKeyPress
        end
        object edtFMTxRDSDeviation: TEdit
          Left = 296
          Top = 187
          Width = 33
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 6
          Text = '0'
          OnExit = edtFMTxExit
          OnKeyPress = edtFMTxRDSDeviationKeyPress
        end
        object udFMTxRDSDeviation: TUpDown
          Left = 328
          Top = 187
          Width = 15
          Height = 21
          Enabled = False
          Min = 0
          Max = 7500
          Increment = 10
          Position = 0
          TabOrder = 14
          Wrap = False
          OnChanging = udFMTxRDSDeviationChanging
        end
        object stFMTxTotalDeviation: TStaticText
          Left = 96
          Top = 217
          Width = 137
          Height = 21
          AutoSize = False
          Color = clSkyBlue
          Enabled = False
          ParentColor = False
          TabOrder = 7
        end
        object cbFMTxPilotOn: TComboBox
          Left = 96
          Top = 153
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 3
          Text = 'Pilot On'
          OnExit = edtFMTxExit
          OnKeyPress = cbFMTxPilotOnKeyPress
          Items.Strings = (
            'Pilot Off'
            'Pilot On')
        end
        object cbFMTxRDSOn: TComboBox
          Left = 96
          Top = 187
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 5
          Text = 'RDS Off'
          OnExit = edtFMTxExit
          OnKeyPress = cbFMTxRDSOnKeyPress
          Items.Strings = (
            'RDS Off'
            'RDS On')
        end
        object cbFMTxStereoMonoEnable: TComboBox
          Left = 96
          Top = 289
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 1
          TabOrder = 9
          Text = 'Stereo'
          OnExit = edtFMTxExit
          OnKeyPress = cbFMTxStereoMonoEnableKeyPress
          Items.Strings = (
            'Mono'
            'Stereo')
        end
        object cbFMTxModulationOn: TComboBox
          Left = 96
          Top = 256
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 1
          TabOrder = 8
          Text = 'Modulation On'
          OnExit = edtFMTxExit
          OnKeyPress = cbFMTxModulationOnKeyPress
          Items.Strings = (
            'Modulation Off'
            'Modulation On')
        end
        object cbFMTxPreEmphasis: TComboBox
          Left = 96
          Top = 356
          Width = 137
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          ItemIndex = 2
          TabOrder = 11
          Text = '75 us'
          OnExit = edtFMTxExit
          OnKeyPress = cbFMTxPreEmphasisKeyPress
          Items.Strings = (
            'OFF'
            '50 us'
            '75 us')
        end
        object edtFMTxRFFreq: TEdit
          Left = 96
          Top = 20
          Width = 121
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 0
          Text = '94'
          OnExit = edtFMTxExit
          OnKeyPress = edtFMTxRFFreqKeyPress
        end
        object edtFMTxPilotFreq: TEdit
          Left = 96
          Top = 322
          Width = 121
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 10
          Text = '19'
          OnExit = edtFMTxExit
          OnKeyPress = edtFMTxPilotFreqKeyPress
        end
        object udFMTxPilotFreq: TUpDown
          Left = 216
          Top = 322
          Width = 15
          Height = 21
          Enabled = False
          Min = 10
          Max = 32000
          Increment = 10
          Position = 19000
          TabOrder = 15
          Wrap = False
          OnChanging = udFMTxPilotFreqChanging
        end
        object udFMTxRFFreq: TUpDown
          Left = 216
          Top = 20
          Width = 15
          Height = 21
          Enabled = False
          Min = 1520
          Max = 2160
          Position = 1880
          TabOrder = 16
          Wrap = False
          OnChanging = udFMTxRFFreqChanging
        end
        object edtFMTxRFlevel: TEdit
          Left = 96
          Top = 52
          Width = 121
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 17
          Text = '120'
          OnExit = edtFMTxExit
          OnKeyPress = edtFMTxRFlevelKeyPress
        end
        object udFMTxRFlevel: TUpDown
          Left = 216
          Top = 52
          Width = 15
          Height = 21
          Enabled = False
          Min = 90
          Max = 120
          Position = 120
          TabOrder = 18
          Wrap = False
          OnChanging = udFMTxRFlevelChanging
        end
        object readVaractor: TButton
          Left = 296
          Top = 88
          Width = 57
          Height = 17
          Caption = 'Read'
          Enabled = False
          TabOrder = 19
          OnClick = readVaractorClick
        end
      end
      object m_sbFMTX: TStatusBar
        Left = 0
        Top = 580
        Width = 841
        Height = 33
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object btnFMTxPowerOnOff: TButton
        Left = 16
        Top = 8
        Width = 113
        Height = 25
        Caption = 'TX Power On'
        TabOrder = 2
        OnClick = btnFMTxPowerOnOffClick
      end
      object gbFMTxAudioControl: TGroupBox
        Left = 408
        Top = 40
        Width = 385
        Height = 353
        Caption = 'Audio Control'
        TabOrder = 3
        object GroupBox43: TGroupBox
          Left = 16
          Top = 16
          Width = 361
          Height = 81
          Caption = 'Audio dynamic range control'
          TabOrder = 0
          object chkFMTxDRCOn: TCheckBox
            Left = 8
            Top = 24
            Width = 241
            Height = 17
            Caption = 'Control on'
            Checked = True
            Enabled = False
            State = cbChecked
            TabOrder = 0
            OnClick = btnFMTxADRCSETClick
          end
          object btnFMTxADRCSET: TButton
            Left = 280
            Top = 16
            Width = 75
            Height = 25
            Caption = 'Set'
            Enabled = False
            TabOrder = 1
            Visible = False
            OnClick = btnFMTxADRCSETClick
          end
        end
        object GroupBox34: TGroupBox
          Left = 16
          Top = 128
          Width = 361
          Height = 73
          Caption = 'Limiter'
          TabOrder = 1
          object btnFMTxLimiter: TButton
            Left = 280
            Top = 16
            Width = 75
            Height = 25
            Caption = 'Set'
            Enabled = False
            TabOrder = 0
            Visible = False
            OnClick = btnFM
          end
          object chkFMTxEL: TCheckBox
            Left = 8
            Top = 24
            Width = 169
            Height = 17
            Caption = 'Enable'
            Checked = True
            Enabled = False
            State = cbChecked
            TabOrder = 1
            OnClick = btnFMTxADRCSETClick
          end
        end
      end
      object GroupBox4: TGroupBox
        Left = 408
        Top = 400
        Width = 385
        Height = 153
        Caption = 'Audio Source'
        TabOrder = 4
        object cboFrequency: TComboBox
          Left = 104
          Top = 48
          Width = 97
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 0
          Text = '1K Hz'
          Items.Strings = (
            '1K Hz'
            '2K Hz'
            '3K Hz'
            '4K Hz'
            '5K Hz'
            '6K Hz'
            '7K Hz'
            '8K Hz'
            '9K Hz'
            '10K Hz'
            '11K Hz'
            '12K Hz'
            '13K Hz'
            '14K Hz'
            '15K Hz')
        end
        object btnFMSetType: TButton
          Left = 304
          Top = 40
          Width = 75
          Height = 25
          Caption = 'Set type'
          Enabled = False
          TabOrder = 1
          OnClick = btnFMSetTypeClick
        end
        object cbI2S: TRadioButton
          Left = 8
          Top = 32
          Width = 73
          Height = 25
          Caption = 'I2S Input '
          Checked = True
          Enabled = False
          TabOrder = 2
          TabStop = True
        end
        object cbAnalog: TRadioButton
          Left = 8
          Top = 72
          Width = 89
          Height = 17
          Caption = 'Analog Input'
          Enabled = False
          TabOrder = 3
        end
      end
    end
    object tsRDSTx: TTabSheet
      Caption = 'RDS Transmitter Page'
      ImageIndex = 4
      object gbRDSTxGeneral: TGroupBox
        Left = 16
        Top = 8
        Width = 265
        Height = 201
        Caption = 'General'
        TabOrder = 0
        object Label238: TLabel
          Left = 16
          Top = 80
          Width = 66
          Height = 13
          Caption = 'Program Type'
        end
        object Label239: TLabel
          Left = 16
          Top = 144
          Width = 16
          Height = 13
          Caption = 'PI: '
        end
        object Label253: TLabel
          Left = 32
          Top = 144
          Width = 11
          Height = 13
          Caption = '0x'
        end
        object chkRDSTxDynamic: TCheckBox
          Left = 16
          Top = 112
          Width = 97
          Height = 17
          Caption = 'Dynamic'
          TabOrder = 0
        end
        object edtRDSTxPI: TEdit
          Left = 48
          Top = 136
          Width = 57
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 1
        end
        object rgpRDSTxType: TRadioGroup
          Left = 16
          Top = 16
          Width = 153
          Height = 57
          Caption = 'Type'
          ItemIndex = 0
          Items.Strings = (
            'RDS'
            'RBDS')
          TabOrder = 2
          OnClick = rgpRDSTxTypeClick
        end
        object cbRDSTxPTY: TComboBox
          Left = 88
          Top = 80
          Width = 145
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 3
          Items.Strings = (
            'No Prgram type or undefined'
            'News'
            'Current Affairs'
            'Information'
            'Sport'
            'Education '
            'Drama'
            'Culture'
            'Science'
            'Varied'
            'Pop Music'
            'Rock Music'
            'M.O.R. Music'
            'Light classical'
            'Serious classical'
            'Other Music'
            'Weather'
            'Finance'
            'Children'#39's program'
            'Social Affairs'
            'Religion'
            'Phone In'
            'Travel'
            'Leisure'
            'Jazz Music'
            'Country Music'
            'National Music'
            'Oldies Music'
            'Folk Music'
            'Documentary'
            'Alarm Test'
            'Alarm')
        end
      end
      object gbRDSTxPS: TGroupBox
        Left = 16
        Top = 216
        Width = 265
        Height = 265
        Caption = 'Program service'
        TabOrder = 1
        object edtRDSTxPS: TEdit
          Left = 16
          Top = 24
          Width = 169
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 0
        end
        object chkRDSTxAF: TCheckBox
          Left = 16
          Top = 56
          Width = 97
          Height = 17
          Caption = 'Alt. Frequency'
          TabOrder = 1
          OnClick = chkRDSTxAFClick
        end
        object chkRDSTxAH: TCheckBox
          Left = 16
          Top = 84
          Width = 97
          Height = 17
          Caption = 'Artificial Head'
          TabOrder = 2
        end
        object chkRDSTxStereo: TCheckBox
          Left = 16
          Top = 112
          Width = 97
          Height = 17
          Caption = 'Stereo'
          TabOrder = 3
        end
        object chkRDSTxTP: TCheckBox
          Left = 16
          Top = 168
          Width = 97
          Height = 17
          Caption = 'Traffic Program'
          TabOrder = 4
        end
        object chkRDSTxTA: TCheckBox
          Left = 16
          Top = 196
          Width = 177
          Height = 17
          Caption = 'Traffic Announcement'
          TabOrder = 5
        end
        object chkRDSTxSpeech: TCheckBox
          Left = 16
          Top = 224
          Width = 97
          Height = 17
          Caption = 'Speech'
          TabOrder = 6
        end
        object chkRDSTxAudioCompress: TCheckBox
          Left = 16
          Top = 140
          Width = 137
          Height = 17
          Caption = 'Audio Compression'
          TabOrder = 7
        end
        object edtRDSTxAF: TEdit
          Left = 112
          Top = 56
          Width = 49
          Height = 21
          Enabled = False
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 8
          OnKeyPress = edtRDSTxAFKeyPress
        end
        object udRDSTxAF: TUpDown
          Left = 160
          Top = 56
          Width = 15
          Height = 21
          Enabled = False
          Min = 876
          Max = 1079
          Position = 876
          TabOrder = 9
          Wrap = False
          OnChanging = udRDSTxAFChanging
        end
      end
      object btnRDSTxSend: TButton
        Left = 160
        Top = 496
        Width = 121
        Height = 25
        Caption = 'Send'
        TabOrder = 2
        OnClick = btnRDSTxSendClick
      end
      object m_sbRDSTX: TStatusBar
        Left = 0
        Top = 580
        Width = 841
        Height = 33
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
  end
  object lblHint: TStaticText
    Left = 768
    Top = 8
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 0
    Visible = False
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 800
    Top = 128
  end
  object CounterTimer: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = CounterTimerTimer
    Left = 808
    Top = 80
  end
  object tmScan: TTimer
    Interval = 100
    Left = 808
    Top = 168
  end
  object ActionList1: TActionList
    Left = 816
    Top = 360
    object ToggleHide: TAction
      Caption = 'ToggleHide'
      ShortCut = 16454
      OnExecute = ToggleHideExecute
    end
  end
end
