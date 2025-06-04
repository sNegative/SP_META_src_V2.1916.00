object frmWmWifi: TfrmWmWifi
  Left = 285
  Top = 2
  Width = 828
  Height = 838
  Caption = 'WIFI Tool'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel14: TPanel
    Left = 0
    Top = 0
    Width = 425
    Height = 729
    Color = clMenuBar
    TabOrder = 0
    object Panel1: TPanel
      Left = 8
      Top = 0
      Width = 409
      Height = 57
      BevelOuter = bvLowered
      TabOrder = 0
      object Label1: TLabel
        Left = 5
        Top = 4
        Width = 61
        Height = 13
        Caption = 'MCR access'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 16
        Top = 28
        Width = 36
        Height = 13
        Caption = 'addr (h)'
      end
      object Label3: TLabel
        Left = 152
        Top = 28
        Width = 41
        Height = 13
        Caption = 'value (h)'
      end
      object edtMCRAddr: TEdit
        Left = 88
        Top = 24
        Width = 57
        Height = 21
        Color = cl3DLight
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 0
      end
      object edtMCRValue: TEdit
        Left = 216
        Top = 24
        Width = 57
        Height = 21
        Color = cl3DLight
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 1
      end
      object btnMCRRead: TButton
        Left = 288
        Top = 24
        Width = 49
        Height = 25
        Caption = 'Read'
        TabOrder = 2
        OnClick = btnMCRReadClick
      end
      object btnMCRWrite: TButton
        Left = 344
        Top = 24
        Width = 49
        Height = 25
        Caption = 'Write'
        TabOrder = 3
        OnClick = btnMCRWriteClick
      end
    end
    object Panel4: TPanel
      Left = 8
      Top = 64
      Width = 409
      Height = 241
      BevelOuter = bvLowered
      TabOrder = 1
      object Label4: TLabel
        Left = 4
        Top = 4
        Width = 83
        Height = 13
        Caption = 'EEPROM access'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object btnEESaveAsFile: TButton
        Left = 16
        Top = 174
        Width = 129
        Height = 25
        Caption = 'EEPROM Save As File'
        TabOrder = 2
        OnClick = btnEESaveAsFileClick
      end
      object btnEEBurnFromFile: TButton
        Left = 160
        Top = 174
        Width = 129
        Height = 25
        Caption = 'Burn EEPROM From File'
        TabOrder = 3
        OnClick = btnEEBurnFromFileClick
      end
      object btnEEReadAll: TButton
        Left = 304
        Top = 174
        Width = 89
        Height = 25
        Caption = 'Read All'
        TabOrder = 4
        OnClick = btnEEReadAllClick
      end
      object GroupBox3: TGroupBox
        Left = 8
        Top = 24
        Width = 393
        Height = 49
        Caption = 'WORD Access'
        TabOrder = 0
        object Label5: TLabel
          Left = 8
          Top = 20
          Width = 65
          Height = 13
          Caption = 'addr (h, word)'
        end
        object Label6: TLabel
          Left = 144
          Top = 20
          Width = 41
          Height = 13
          Caption = 'value (h)'
        end
        object edtEEWordAddr: TEdit
          Left = 80
          Top = 20
          Width = 57
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 0
        end
        object edtEEWordValue: TEdit
          Left = 208
          Top = 20
          Width = 57
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 1
        end
        object btnEEWordRead: TButton
          Left = 280
          Top = 16
          Width = 49
          Height = 25
          Caption = 'Read'
          TabOrder = 2
          OnClick = btnEEWordReadClick
        end
        object btnEEWordWrite: TButton
          Left = 336
          Top = 16
          Width = 49
          Height = 25
          Caption = 'Write'
          TabOrder = 3
          OnClick = btnEEWordWriteClick
        end
      end
      object GroupBox4: TGroupBox
        Left = 8
        Top = 80
        Width = 393
        Height = 89
        Caption = 'Byte String Access'
        TabOrder = 1
        object Label9: TLabel
          Left = 8
          Top = 28
          Width = 62
          Height = 13
          Caption = 'addr (h, byte)'
        end
        object Label10: TLabel
          Left = 144
          Top = 28
          Width = 58
          Height = 13
          Caption = 'length (byte)'
        end
        object Label11: TLabel
          Left = 8
          Top = 60
          Width = 41
          Height = 13
          Caption = 'value (h)'
        end
        object edtEEByteStringLength: TEdit
          Left = 208
          Top = 28
          Width = 57
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 1
        end
        object edtEEByteStringAddr: TEdit
          Left = 80
          Top = 28
          Width = 57
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 0
        end
        object btnEEByteStringRead: TButton
          Left = 280
          Top = 24
          Width = 49
          Height = 25
          Caption = 'Read'
          TabOrder = 3
          OnClick = btnEEByteStringReadClick
        end
        object btnEEByteStringWrite: TButton
          Left = 336
          Top = 24
          Width = 49
          Height = 25
          Caption = 'Write'
          TabOrder = 4
          OnClick = btnEEByteStringWriteClick
        end
        object edtEEByteStringValue: TEdit
          Left = 80
          Top = 60
          Width = 305
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 2
        end
      end
      object btnEEToFlash: TButton
        Left = 16
        Top = 208
        Width = 129
        Height = 25
        Caption = 'EEPROM To Flash'
        TabOrder = 5
        Visible = False
        OnClick = btnEEToFlashClick
      end
    end
    object Panel5: TPanel
      Left = 8
      Top = 309
      Width = 409
      Height = 348
      BevelOuter = bvLowered
      TabOrder = 2
      object Label15: TLabel
        Left = 12
        Top = 12
        Width = 39
        Height = 13
        Caption = 'Channel'
      end
      object cbChannel: TComboBox
        Left = 64
        Top = 8
        Width = 97
        Height = 21
        Color = cl3DLight
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 0
        OnChange = cbxChannelChange
      end
      object cbACL: TCheckBox
        Left = 184
        Top = 8
        Width = 217
        Height = 17
        Caption = 'ALC Function for Normal Packet Tx/Rx'
        TabOrder = 1
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 38
        Width = 393
        Height = 171
        Caption = 'TX test'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        object Label12: TLabel
          Left = 8
          Top = 21
          Width = 40
          Height = 13
          Caption = 'Antenna'
        end
        object Label13: TLabel
          Left = 8
          Top = 137
          Width = 23
          Height = 13
          Caption = 'Rate'
        end
        object Label14: TLabel
          Left = 8
          Top = 49
          Width = 52
          Height = 13
          Caption = 'Tx Gain (h)'
        end
        object Label16: TLabel
          Left = 223
          Top = 54
          Width = 74
          Height = 13
          Caption = 'modulation type'
        end
        object Label17: TLabel
          Left = 220
          Top = 68
          Width = 86
          Height = 13
          Caption = ' (used for c.s only)'
        end
        object Label18: TLabel
          Left = 8
          Top = 79
          Width = 33
          Height = 13
          Caption = 'Pkt len'
        end
        object Label19: TLabel
          Left = 8
          Top = 106
          Width = 34
          Height = 13
          Caption = 'Pkt cnt'
        end
        object edtTXAntenna: TEdit
          Left = 80
          Top = 18
          Width = 73
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 1
        end
        object edtTXGain: TEdit
          Left = 80
          Top = 46
          Width = 73
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 2
        end
        object cbRate: TComboBox
          Left = 80
          Top = 133
          Width = 73
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 5
          OnChange = cbRateChange
        end
        object cbTXTestType: TComboBox
          Left = 208
          Top = 99
          Width = 177
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 7
        end
        object btnTXStop: TButton
          Left = 304
          Top = 128
          Width = 81
          Height = 25
          Caption = 'Stop'
          TabOrder = 9
          OnClick = btnTXStopClick
        end
        object btnTXGo: TButton
          Left = 208
          Top = 128
          Width = 89
          Height = 25
          Caption = 'Go'
          TabOrder = 8
          OnClick = btnTXGoClick
        end
        object cbJapanChannel: TCheckBox
          Left = 176
          Top = 20
          Width = 214
          Height = 17
          Caption = 'Tx Filter for Japan Channel (CH14 only)'
          TabOrder = 0
        end
        object cbModuationType: TComboBox
          Left = 312
          Top = 56
          Width = 73
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          ItemHeight = 13
          TabOrder = 6
        end
        object edtTXPktLen: TEdit
          Left = 80
          Top = 75
          Width = 73
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 3
        end
        object edtTXPktCnt: TEdit
          Left = 80
          Top = 103
          Width = 73
          Height = 21
          Color = cl3DLight
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 4
        end
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 216
        Width = 393
        Height = 121
        Caption = 'RX test'
        TabOrder = 3
        object Label20: TLabel
          Left = 9
          Top = 20
          Width = 35
          Height = 13
          Caption = 'FCS err'
        end
        object Label21: TLabel
          Left = 8
          Top = 40
          Width = 33
          Height = 13
          Caption = 'RX OK'
        end
        object Label22: TLabel
          Left = 9
          Top = 59
          Width = 22
          Height = 13
          Caption = 'PER'
        end
        object Label7: TLabel
          Left = 209
          Top = 20
          Width = 57
          Height = 13
          Caption = 'Interval time'
        end
        object Label8: TLabel
          Left = 361
          Top = 20
          Width = 17
          Height = 13
          Caption = 'sec'
        end
        object Label27: TLabel
          Left = 33
          Top = 83
          Width = 20
          Height = 13
          Caption = 'Min.'
        end
        object Label28: TLabel
          Left = 129
          Top = 83
          Width = 23
          Height = 13
          Caption = 'Max.'
        end
        object Label29: TLabel
          Left = 225
          Top = 83
          Width = 27
          Height = 13
          Caption = 'Mean'
        end
        object Label30: TLabel
          Left = 313
          Top = 83
          Width = 42
          Height = 13
          Caption = 'Variance'
        end
        object btnRXGo: TButton
          Left = 208
          Top = 48
          Width = 89
          Height = 25
          Caption = 'Go'
          TabOrder = 0
          OnClick = btnRXGoClick
        end
        object btnRXStop: TButton
          Left = 304
          Top = 48
          Width = 81
          Height = 25
          Caption = 'Stop'
          TabOrder = 1
          OnClick = btnRXStopClick
        end
        object stRXFCSerr: TStaticText
          Left = 80
          Top = 16
          Width = 73
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BevelInner = bvNone
          BorderStyle = sbsSingle
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object stRXOK: TStaticText
          Left = 80
          Top = 37
          Width = 73
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BevelInner = bvNone
          BorderStyle = sbsSingle
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object stRXPER: TStaticText
          Left = 80
          Top = 58
          Width = 73
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BevelInner = bvNone
          BorderStyle = sbsSingle
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
        object edtInterval: TEdit
          Left = 288
          Top = 16
          Width = 73
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
          TabOrder = 5
        end
        object stMin: TStaticText
          Left = 8
          Top = 96
          Width = 73
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BevelInner = bvNone
          BorderStyle = sbsSingle
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 6
        end
        object stMax: TStaticText
          Left = 104
          Top = 96
          Width = 73
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BevelInner = bvNone
          BorderStyle = sbsSingle
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 7
        end
        object stMean: TStaticText
          Left = 200
          Top = 96
          Width = 73
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BevelInner = bvNone
          BorderStyle = sbsSingle
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 8
        end
        object stVar: TStaticText
          Left = 296
          Top = 96
          Width = 73
          Height = 17
          Alignment = taCenter
          AutoSize = False
          BevelInner = bvNone
          BorderStyle = sbsSingle
          Caption = '0'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 9
        end
      end
    end
    object Panel6: TPanel
      Left = 208
      Top = 661
      Width = 209
      Height = 57
      BevelOuter = bvLowered
      TabOrder = 4
      object Label23: TLabel
        Left = 5
        Top = 5
        Width = 162
        Height = 13
        Caption = 'Temperature Sensor measurement'
      end
      object btnTemperatureStop: TButton
        Left = 112
        Top = 24
        Width = 81
        Height = 25
        Caption = 'Stop'
        TabOrder = 1
        OnClick = btnTemperatureStopClick
      end
      object btnTemperatureGo: TButton
        Left = 16
        Top = 24
        Width = 89
        Height = 25
        Caption = 'Go'
        TabOrder = 0
        OnClick = btnTemperatureGoClick
      end
    end
    object Panel7: TPanel
      Left = 8
      Top = 661
      Width = 193
      Height = 57
      BevelOuter = bvLowered
      TabOrder = 3
      object Label24: TLabel
        Left = 5
        Top = 5
        Width = 41
        Height = 13
        Caption = 'Xtal Trim'
      end
      object Label25: TLabel
        Left = 17
        Top = 31
        Width = 41
        Height = 13
        Caption = 'value (h)'
      end
      object btnXtalTrim: TButton
        Left = 136
        Top = 25
        Width = 49
        Height = 25
        Caption = 'Write'
        TabOrder = 1
        OnClick = btnXtalTrimClick
      end
      object edtXtalTrimValue: TEdit
        Left = 72
        Top = 28
        Width = 57
        Height = 21
        Color = cl3DLight
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        TabOrder = 0
      end
    end
  end
  object Panel2: TPanel
    Left = 426
    Top = 0
    Width = 383
    Height = 729
    Color = clMenuBar
    TabOrder = 1
    object Label26: TLabel
      Left = 8
      Top = 16
      Width = 53
      Height = 13
      Caption = 'Log Output'
    end
    object btnClearLog: TButton
      Left = 304
      Top = 8
      Width = 73
      Height = 25
      Caption = 'Clear Log'
      TabOrder = 0
      OnClick = btnClearLogClick
    end
    object redtLog: TRichEdit
      Left = 6
      Top = 40
      Width = 371
      Height = 753
      TabStop = False
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clSkyBlue
      Ctl3D = True
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      Lines.Strings = (
        'RichEdit1')
      ParentCtl3D = False
      ParentFont = False
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 1
    end
  end
  object Button1: TButton
    Left = 176
    Top = 744
    Width = 65
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
    OnClick = Button1Click
  end
  object saveDlgEE: TSaveDialog
    Filter = 'TXT file (*.txt)|*.txt|All files (*.*)|*.*'
    Left = 744
    Top = 752
  end
  object openDlgEE: TOpenDialog
    Filter = 'TXT file (*.txt)|*.txt|All files (*.*)|*.*'
    Left = 776
    Top = 752
  end
  object timerTX: TTimer
    Enabled = False
    OnTimer = TimerTimerTX
    Left = 712
    Top = 752
  end
  object timerRX: TTimer
    Enabled = False
    OnTimer = TimerTimerRX
    Left = 688
    Top = 752
  end
  object timerTemperature: TTimer
    Enabled = False
    OnTimer = TimerTimerTemperature
    Left = 656
    Top = 752
  end
end
