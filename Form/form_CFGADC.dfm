object frmCFGAdc: TfrmCFGAdc
  Left = 106
  Top = 163
  Width = 918
  Height = 413
  Caption = 'ADC CFG editor'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 7
    Top = 8
    Width = 137
    Height = 33
    BevelOuter = bvLowered
    Caption = 'ADC table'
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 8
    Top = 40
    Width = 897
    Height = 249
    BevelOuter = bvLowered
    TabOrder = 1
    object Label1: TLabel
      Left = 72
      Top = 16
      Width = 41
      Height = 13
      Caption = 'ADC_V1'
    end
    object Label2: TLabel
      Left = 240
      Top = 16
      Width = 41
      Height = 13
      Caption = 'ADC_V2'
    end
    object Label3: TLabel
      Left = 376
      Top = 16
      Width = 120
      Height = 13
      Caption = 'ADC_CHECK_VOLTAGE'
    end
    object Label4: TLabel
      Left = 560
      Top = 16
      Width = 102
      Height = 13
      Caption = 'NORMAL_VOLTAGE'
    end
    object Label5: TLabel
      Left = 16
      Top = 72
      Width = 148
      Height = 13
      Caption = 'MAX_BATTERY_ADC_SLOPE'
    end
    object Label6: TLabel
      Left = 184
      Top = 72
      Width = 145
      Height = 13
      Caption = 'MIN_BATTERY_ADC_SLOPE'
    end
    object Label7: TLabel
      Left = 360
      Top = 72
      Width = 154
      Height = 13
      Caption = 'MAX_BATTERY_ADC_OFFSET'
    end
    object Label8: TLabel
      Left = 544
      Top = 72
      Width = 151
      Height = 13
      Caption = 'MIN_BATTERY_ADC_OFFSET'
    end
    object Label9: TLabel
      Left = 40
      Top = 120
      Width = 107
      Height = 13
      Caption = 'BATTERY_CHANNEL'
    end
    object Label10: TLabel
      Left = 208
      Top = 120
      Width = 110
      Height = 13
      Caption = 'CHARGER_CHANNEL'
    end
    object Label11: TLabel
      Left = 384
      Top = 120
      Width = 96
      Height = 13
      Caption = 'ADC_RESISTANCE'
    end
    object Label12: TLabel
      Left = 544
      Top = 120
      Width = 156
      Height = 13
      Caption = 'ADC_MEASUREMENT_COUNT'
    end
    object Label13: TLabel
      Left = 184
      Top = 168
      Width = 155
      Height = 13
      Caption = 'MAX_CURRENT_DIFFERENCE'
    end
    object Label14: TLabel
      Left = 16
      Top = 168
      Width = 152
      Height = 13
      Caption = 'MAX_VOLTAGE_DIFFERENCE'
    end
    object Label15: TLabel
      Left = 760
      Top = 16
      Width = 87
      Height = 13
      Caption = 'CURRENT_LIMIT'
    end
    object edtADC_V1: TEdit
      Left = 16
      Top = 32
      Width = 153
      Height = 21
      TabOrder = 0
      Text = '3400'
      OnExit = edtADCVoltageCheck
    end
    object edtADC_V2: TEdit
      Tag = 1
      Left = 184
      Top = 32
      Width = 153
      Height = 21
      TabOrder = 1
      Text = '4200'
      OnExit = edtADCVoltageCheck
    end
    object edtADC_CHECK_VOLTAGE: TEdit
      Tag = 2
      Left = 360
      Top = 32
      Width = 153
      Height = 21
      TabOrder = 2
      Text = '3600'
      OnExit = edtADCVoltageCheck
    end
    object edtNORMAL_VOLTAGE: TEdit
      Tag = 3
      Left = 544
      Top = 32
      Width = 153
      Height = 21
      TabOrder = 3
      Text = '3800'
      OnExit = edtADCVoltageCheck
    end
    object edtMAX_BATTERY_ADC_SLOPE: TEdit
      Left = 16
      Top = 88
      Width = 153
      Height = 21
      TabOrder = 4
      Text = '5550'
      OnExit = edtADCSlopeCheck
    end
    object edtMIN_BATTERY_ADC_SLOPE: TEdit
      Tag = 1
      Left = 184
      Top = 88
      Width = 153
      Height = 21
      TabOrder = 5
      Text = '5250'
      OnExit = edtADCSlopeCheck
    end
    object edtMAX_BATTERY_ADC_OFFSET: TEdit
      Left = 360
      Top = 88
      Width = 153
      Height = 21
      TabOrder = 6
      Text = '1000000'
      OnExit = edtADCOffsetCheck
    end
    object edtMIN_BATTERY_ADC_OFFSET: TEdit
      Tag = 1
      Left = 544
      Top = 88
      Width = 153
      Height = 21
      TabOrder = 7
      Text = '-1000000'
      OnExit = edtADCOffsetCheck
    end
    object edtBATTERY_CHANNEL: TEdit
      Left = 16
      Top = 136
      Width = 153
      Height = 21
      TabOrder = 8
      Text = '0'
      OnExit = edtADCChannelCheck
    end
    object edtCHARGER_CHANNEL: TEdit
      Tag = 1
      Left = 184
      Top = 136
      Width = 153
      Height = 21
      TabOrder = 9
      Text = '3'
      OnExit = edtADCChannelCheck
    end
    object edtADC_RESISTANCE: TEdit
      Left = 360
      Top = 136
      Width = 153
      Height = 21
      TabOrder = 10
      Text = '0.33'
      OnExit = edtADCResistanceCheck
    end
    object edtADC_MEASUREMENT_COUNT: TEdit
      Left = 544
      Top = 136
      Width = 153
      Height = 21
      TabOrder = 11
      Text = '1000'
      OnExit = edtADCMeasurementCountCheck
    end
    object edtMAX_VOLTAGE_DIFFERENCE: TEdit
      Left = 16
      Top = 184
      Width = 153
      Height = 21
      TabOrder = 12
      Text = '0.04'
      OnExit = edtADCMaxVoltageDifferenceCheck
    end
    object edtMAX_CURRENT_DIFFERENCE: TEdit
      Left = 184
      Top = 184
      Width = 153
      Height = 21
      TabOrder = 13
      Text = '0.04'
      OnExit = edtADCMaxCurrentDifferenceCheck
    end
    object edtCURRENT_LIMIT: TEdit
      Left = 728
      Top = 32
      Width = 153
      Height = 21
      TabOrder = 14
      Text = '3000'
      OnExit = edtCurrentLimitCheck
    end
  end
  object btnLoadFromCFGFile: TButton
    Left = 439
    Top = 300
    Width = 105
    Height = 25
    Caption = 'Load from CFG file'
    TabOrder = 2
    OnClick = btnLoadFromCFGFileClick
  end
  object btnSaveToCFGFile: TButton
    Left = 559
    Top = 300
    Width = 105
    Height = 25
    Caption = 'Save to CFG file'
    TabOrder = 3
    OnClick = btnSaveToCFGFileClick
  end
  object sbCFGAdc: TStatusBar
    Left = 0
    Top = 353
    Width = 910
    Height = 26
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object lblHint: TStaticText
    Left = 551
    Top = 8
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 5
    Visible = False
  end
  object OpenDlg: TOpenDialog
    DefaultExt = 'cfg'
    Filter = 'Config file (*.cfg)|*.cfg|All files (*.*)|*.*'
    Title = 'Open configuration file'
    Left = 416
  end
  object SaveDlg: TSaveDialog
    DefaultExt = 'cfg'
    Filter = 'Config file (*.cfg)|*.cfg|All files (*.*)|*.*'
    Title = 'Save to configuration file'
    Left = 480
    Top = 8
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 520
    Top = 8
  end
end
