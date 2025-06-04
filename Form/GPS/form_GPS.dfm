object frmGPS: TfrmGPS
  Left = 793
  Top = 0
  Width = 487
  Height = 664
  Caption = 'GPS'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 16
    Top = 8
    Width = 449
    Height = 593
    TabOrder = 0
    object shpGPSOpen: TShape
      Left = 289
      Top = 53
      Width = 17
      Height = 20
      Brush.Color = clRed
      Shape = stCircle
    end
    object GBQuery: TGroupBox
      Left = 24
      Top = 80
      Width = 402
      Height = 247
      TabOrder = 3
      object Label9: TLabel
        Left = 264
        Top = 182
        Width = 72
        Height = 13
        Caption = 'Acqusition(sec)'
      end
      object Label8: TLabel
        Left = 136
        Top = 182
        Width = 62
        Height = 13
        Caption = 'Bit Sync(sec)'
      end
      object Label7: TLabel
        Left = 136
        Top = 138
        Width = 55
        Height = 13
        Caption = 'CNR Sigma'
      end
      object Label6: TLabel
        Left = 264
        Top = 138
        Width = 54
        Height = 13
        Caption = 'Update(Hz)'
      end
      object Label5: TLabel
        Left = 136
        Top = 88
        Width = 121
        Height = 13
        Caption = 'Clock Drift Rate(ppb/sec)'
      end
      object Label4: TLabel
        Left = 264
        Top = 88
        Width = 53
        Height = 13
        Caption = 'CNR Mean'
      end
      object Label2: TLabel
        Left = 264
        Top = 42
        Width = 75
        Height = 13
        Caption = 'Clock Drift(ppm)'
      end
      object Label1: TLabel
        Left = 136
        Top = 42
        Width = 52
        Height = 13
        Caption = 'phase ratio'
      end
      object Label3: TLabel
        Left = 16
        Top = 208
        Width = 24
        Height = 13
        Caption = 'Svid:'
      end
      object EDUpdateValue: TEdit
        Left = 264
        Top = 154
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 0
      end
      object EDTCXOOffsetValue: TEdit
        Left = 264
        Top = 58
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 1
      end
      object EDTCXODriftValue: TEdit
        Left = 136
        Top = 106
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 2
      end
      object EDPhaseRatioValue: TEdit
        Left = 137
        Top = 58
        Width = 81
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ParentFont = False
        TabOrder = 3
      end
      object EDCNRSigmaValue: TEdit
        Left = 136
        Top = 154
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 4
      end
      object EDCNRMeanValue: TEdit
        Left = 264
        Top = 106
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 5
      end
      object EDBitSyncValue: TEdit
        Left = 136
        Top = 198
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 6
      end
      object EDAcquisionValue: TEdit
        Left = 264
        Top = 198
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 7
      end
      object cbBit0: TCheckBox
        Left = 24
        Top = 110
        Width = 65
        Height = 17
        Caption = 'Test Info'
        Checked = True
        State = cbChecked
        TabOrder = 8
        OnClick = CheckInfoEnable
      end
      object cbBit1: TCheckBox
        Left = 24
        Top = 134
        Width = 65
        Height = 17
        Caption = 'Test acq'
        TabOrder = 9
        OnClick = CheckBitsyncAndSignalDisanble
      end
      object cbBit2: TCheckBox
        Left = 24
        Top = 158
        Width = 81
        Height = 17
        Caption = 'Test bitsync'
        TabOrder = 10
        OnClick = CheckAcqEnable
      end
      object cbBit3: TCheckBox
        Left = 24
        Top = 182
        Width = 81
        Height = 17
        Caption = 'Test Signal'
        TabOrder = 11
        OnClick = CheckBitsyncEnable
      end
      object EdtSvid: TEdit
        Left = 48
        Top = 200
        Width = 49
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 12
        Text = '29'
        OnExit = EdtSvidExit
      end
      object Btntest: TButton
        Left = 139
        Top = 219
        Width = 65
        Height = 17
        Caption = 'test'
        TabOrder = 13
        Visible = False
        OnClick = BtntestClick
      end
      object BtnClearValue: TButton
        Left = 48
        Top = 220
        Width = 81
        Height = 25
        Caption = 'Clear Value'
        TabOrder = 14
        Visible = False
        OnClick = BtnClearValueClick
      end
      object BtnStop: TButton
        Left = 24
        Top = 77
        Width = 81
        Height = 25
        Caption = 'Stop'
        TabOrder = 15
        OnClick = BtnStopClick
      end
      object pnlPhaseRatioResult: TPanel
        Left = 221
        Top = 50
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 16
      end
      object pnlTCXOOffsetResult: TPanel
        Left = 349
        Top = 50
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 17
      end
      object pnlTCXODriftResult: TPanel
        Left = 220
        Top = 103
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 18
      end
      object pnlCNRMeanResult: TPanel
        Left = 349
        Top = 103
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 19
      end
      object pnlCNRSigmaResult: TPanel
        Left = 221
        Top = 144
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 20
      end
      object pnlUpdateResult: TPanel
        Left = 349
        Top = 144
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 21
      end
      object pnlBitSyncResult: TPanel
        Left = 221
        Top = 189
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 22
      end
      object pnlAcquisionResult: TPanel
        Left = 349
        Top = 189
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 23
      end
      object RadioBtnSignalTestMode: TRadioButton
        Left = 8
        Top = 12
        Width = 137
        Height = 17
        Caption = 'GPS signal test mode'
        TabOrder = 24
        OnClick = RadioBtnSignalTestModeClick
      end
    end
    object BtnOpenGPS: TButton
      Left = 25
      Top = 50
      Width = 81
      Height = 25
      Caption = 'Open'
      TabOrder = 0
      OnClick = BtnOpenGPSClick
    end
    object BtnStart: TButton
      Left = 48
      Top = 121
      Width = 81
      Height = 25
      Caption = 'Start'
      TabOrder = 1
      OnClick = BtnStartClick
    end
    object BtnCloseGPS: TButton
      Left = 145
      Top = 50
      Width = 81
      Height = 25
      Caption = 'Close'
      TabOrder = 2
      OnClick = BtnCloseGPSClick
    end
    object BtnLoadSPEC: TButton
      Left = 24
      Top = 16
      Width = 81
      Height = 25
      Caption = 'Load Spec File'
      TabOrder = 4
      OnClick = BtnLoadSPECClick
    end
    object stGPSSPECFile: TStaticText
      Left = 112
      Top = 16
      Width = 289
      Height = 25
      AutoSize = False
      BevelInner = bvLowered
      BorderStyle = sbsSunken
      Color = clSkyBlue
      ParentColor = False
      TabOrder = 5
    end
    object GBCWTest: TGroupBox
      Left = 24
      Top = 330
      Width = 402
      Height = 125
      TabOrder = 6
      object LabelCWCNR: TLabel
        Left = 27
        Top = 72
        Width = 58
        Height = 13
        Caption = 'CNR(dB-Hz)'
      end
      object LabelCWClockDrift: TLabel
        Left = 191
        Top = 72
        Width = 78
        Height = 13
        Caption = 'Clock Drift(ppm) '
      end
      object RadioBtnCWTestMode: TRadioButton
        Left = 8
        Top = 13
        Width = 113
        Height = 17
        Caption = 'CW test mode'
        TabOrder = 0
        OnClick = RadioBtnCWTestModeClick
      end
      object BtnCWStart: TButton
        Left = 23
        Top = 37
        Width = 81
        Height = 25
        Caption = 'Start'
        TabOrder = 1
        OnClick = BtnCWStartClick
      end
      object BtnCWStop: TButton
        Left = 143
        Top = 37
        Width = 81
        Height = 25
        Caption = 'Stop'
        TabOrder = 2
        OnClick = BtnCWStopClick
      end
      object BtnCWAutoTest: TButton
        Left = 262
        Top = 37
        Width = 81
        Height = 25
        Caption = 'Auto Test'
        TabOrder = 3
        OnClick = BtnCWAutoTestClick
      end
      object EDCWCNR: TEdit
        Left = 27
        Top = 88
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 4
      end
      object pnlCWCNRResult: TPanel
        Left = 112
        Top = 77
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
      end
      object EDCWClockDrift: TEdit
        Left = 192
        Top = 88
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 6
      end
      object pnlCWClockDriftResult: TPanel
        Left = 276
        Top = 77
        Width = 36
        Height = 38
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
      end
    end
    object GBCNRTest: TGroupBox
      Left = 24
      Top = 460
      Width = 402
      Height = 133
      TabOrder = 7
      object LabelCNRTest: TLabel
        Left = 16
        Top = 90
        Width = 58
        Height = 13
        Caption = 'CNR(dB-Hz)'
      end
      object LabelCNRSvid: TLabel
        Left = 16
        Top = 50
        Width = 24
        Height = 13
        Caption = 'Svid:'
      end
      object LabelBeidouCNR: TLabel
        Left = 113
        Top = 90
        Width = 58
        Height = 13
        Caption = 'CNR(dB-Hz)'
      end
      object LabelBeidouSvid: TLabel
        Left = 113
        Top = 50
        Width = 24
        Height = 13
        Caption = 'Svid:'
      end
      object LabelGlonassSvid: TLabel
        Left = 208
        Top = 50
        Width = 70
        Height = 13
        Caption = 'RF chnl (-7...6)'
      end
      object LabelGlonassCNR: TLabel
        Left = 208
        Top = 90
        Width = 58
        Height = 13
        Caption = 'CNR(dB-Hz)'
      end
      object LableInterval: TLabel
        Left = 288
        Top = 32
        Width = 38
        Height = 13
        Caption = 'Interval:'
        Visible = False
      end
      object RadioBtnCNRTestMode: TRadioButton
        Left = 8
        Top = 10
        Width = 136
        Height = 17
        Caption = 'GPS CNR test mode'
        TabOrder = 0
        OnClick = RadioBtnCNRTestModeClick
      end
      object BtnCNRStart: TButton
        Left = 305
        Top = 59
        Width = 81
        Height = 25
        Caption = 'Start'
        TabOrder = 1
        OnClick = BtnCNRStartClick
      end
      object EDCNRModeValue: TEdit
        Left = 16
        Top = 106
        Width = 61
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 2
      end
      object pnlCNRTestResult: TPanel
        Left = 279
        Top = 8
        Width = 36
        Height = 20
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clActiveCaption
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        Visible = False
      end
      object BtnCNRStop: TButton
        Left = 305
        Top = 92
        Width = 81
        Height = 25
        Caption = 'Stop'
        TabOrder = 4
        OnClick = BtnCNRStopClick
      end
      object EdtCNRSvid: TEdit
        Left = 16
        Top = 66
        Width = 63
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 5
        Text = '29'
        OnExit = EdtCNRSvidExit
      end
      object CNRTest: TButton
        Left = 320
        Top = 8
        Width = 75
        Height = 25
        Caption = 'CNRTest'
        TabOrder = 6
        Visible = False
        OnClick = CNRTestClick
      end
      object EDBeidouModeValue: TEdit
        Left = 113
        Top = 106
        Width = 61
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 7
      end
      object EdtBeidouSvid: TEdit
        Left = 113
        Top = 66
        Width = 63
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 8
        Text = '29'
        OnExit = EdtCNRSvidExit
      end
      object EdtGlonassSvid: TEdit
        Left = 208
        Top = 66
        Width = 63
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 9
        Text = '0'
        OnExit = EdtCNRSvidExit
      end
      object EDGlonassModeValue: TEdit
        Left = 208
        Top = 106
        Width = 61
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 10
      end
      object cbGPS: TCheckBox
        Left = 16
        Top = 31
        Width = 57
        Height = 17
        Caption = 'GPS'
        Checked = True
        State = cbChecked
        TabOrder = 11
      end
      object cbBEIDOU: TCheckBox
        Left = 114
        Top = 31
        Width = 71
        Height = 17
        Caption = 'BEIDOU'
        TabOrder = 12
      end
      object cbGLONASS: TCheckBox
        Left = 209
        Top = 30
        Width = 72
        Height = 17
        Caption = 'GLONASS'
        TabOrder = 13
      end
      object EDInterval: TEdit
        Left = 328
        Top = 30
        Width = 33
        Height = 21
        TabOrder = 14
        Text = '5'
        Visible = False
      end
    end
  end
  object BtnClearLog: TButton
    Left = 376
    Top = 352
    Width = 81
    Height = 25
    Caption = 'Clear Log'
    TabOrder = 1
    Visible = False
    OnClick = BtnClearLogClick
  end
  object GPSLog: TRichEdit
    Left = 7
    Top = 602
    Width = 425
    Height = 8
    Font.Charset = GB2312_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
    Lines.Strings = (
      '')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
    Visible = False
  end
  object stInfo: TStaticText
    Left = 2
    Top = 606
    Width = 457
    Height = 19
    AutoSize = False
    BevelInner = bvNone
    Caption = 'GPS tool init'
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    TabOrder = 3
  end
  object lblHint: TStaticText
    Left = 300
    Top = 352
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 4
    Visible = False
  end
  object cbxNavigation: TComboBox
    Left = 160
    Top = 352
    Width = 137
    Height = 21
    ItemHeight = 13
    TabOrder = 5
  end
  object DisplayTimer: TTimer
    Left = 144
    Top = 376
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 176
    Top = 376
  end
  object dlg_OpenIniFile: TOpenDialog
    DefaultExt = 'ini'
    Filter = 'ini file [*.ini]|*.ini'
    Title = 'Open ini file'
    Left = 338
    Top = 350
  end
  object CallbackTimer: TTimer
    Enabled = False
    Interval = 20000
    OnTimer = CallbackTimerTimer
    Left = 149
    Top = 402
  end
  object CallbackCWTimer: TTimer
    Enabled = False
    Interval = 5000
    OnTimer = CallbackCWTimerTimer
    Left = 183
    Top = 409
  end
  object ActionList1: TActionList
    Left = 368
    Top = 424
    object CWHideFlag: TAction
      Caption = 'CWHideFlag'
      ShortCut = 16455
      OnExecute = CWHideFlagExecute
    end
  end
  object CallbackCNRTimer: TTimer
    Enabled = False
    Interval = 5000
    OnTimer = CallbackCNRTimerTimer
    Left = 392
    Top = 480
  end
end
