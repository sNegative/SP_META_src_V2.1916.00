object frmBaseBand: TfrmBaseBand
  Left = 427
  Top = 261
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Baseband'
  ClientHeight = 370
  ClientWidth = 715
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pctlToolSel: TPageControl
    Left = 7
    Top = 5
    Width = 706
    Height = 364
    ActivePage = tsLED
    MultiLine = True
    TabIndex = 3
    TabOrder = 0
    OnChange = pctlToolSelChange
    object tsADC: TTabSheet
      Caption = 'Battery Voltage/Capacity'
      ImageIndex = 2
      object Label34: TLabel
        Left = 232
        Top = 32
        Width = 15
        Height = 13
        Caption = 'mV'
      end
      object Label35: TLabel
        Left = 234
        Top = 87
        Width = 8
        Height = 13
        Caption = '%'
      end
      object sbAdc: TStatusBar
        Left = 0
        Top = 307
        Width = 698
        Height = 29
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object btnBatteryVol: TButton
        Left = 16
        Top = 24
        Width = 105
        Height = 25
        Caption = 'Get Battery Voltage'
        TabOrder = 1
        OnClick = btnBatteryVolClick
      end
      object stBatteryVol: TStaticText
        Left = 142
        Top = 27
        Width = 85
        Height = 21
        Alignment = taCenter
        AutoSize = False
        BorderStyle = sbsSingle
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlue
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 2
      end
      object btnBatteryCap: TButton
        Left = 16
        Top = 80
        Width = 105
        Height = 25
        Caption = 'Get Battery Capacity'
        TabOrder = 3
        OnClick = btnBatteryCapClick
      end
      object stBatteryCap: TStaticText
        Left = 142
        Top = 83
        Width = 85
        Height = 21
        Alignment = taCenter
        AutoSize = False
        BorderStyle = sbsSingle
        Color = clWhite
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlue
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 4
      end
    end
    object tsBBReg: TTabSheet
      Caption = 'Baseband Register Read/Write'
      ImageIndex = 1
      object lblBBRegAddr0X: TLabel
        Left = 9
        Top = 52
        Width = 11
        Height = 13
        Caption = '0x'
      end
      object lblBBRegValue0X: TLabel
        Left = 114
        Top = 52
        Width = 11
        Height = 13
        Caption = '0x'
      end
      object lblLabel10: TLabel
        Left = 32
        Top = 24
        Width = 66
        Height = 13
        Caption = 'Address (Hex)'
      end
      object Label26: TLabel
        Left = 240
        Top = 24
        Width = 43
        Height = 13
        Caption = 'Bit Count'
      end
      object Label33: TLabel
        Left = 32
        Top = 168
        Width = 482
        Height = 13
        Caption = 
          'The taget only can be cleaned one time.If you want to clean the ' +
          'target again.Please format the target. '
        Visible = False
      end
      object edtBBAddress: TEdit
        Left = 24
        Top = 48
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 0
        Text = '20'
        OnExit = edtRegAddrCheck
      end
      object edtBBValue: TEdit
        Left = 128
        Top = 48
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 1
        Text = '20'
        OnExit = edtRegValueCheck
      end
      object btnBBRegRead: TButton
        Tag = 1
        Left = 328
        Top = 88
        Width = 65
        Height = 25
        Caption = 'Read'
        TabOrder = 2
        OnClick = btnBBRegReadClick
      end
      object btnBBRegWrite: TButton
        Tag = 1
        Left = 400
        Top = 88
        Width = 65
        Height = 25
        Caption = 'Write'
        TabOrder = 3
        OnClick = btnBBRegWriteClick
      end
      object btnBBRegValue: TButton
        Tag = 1
        Left = 128
        Top = 16
        Width = 81
        Height = 25
        Caption = 'Value (Hex)'
        TabOrder = 4
        OnClick = btnBBRegValueClick
      end
      object sbReg: TStatusBar
        Left = 0
        Top = 304
        Width = 698
        Height = 32
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object edtBBBitCount: TEdit
        Left = 232
        Top = 48
        Width = 65
        Height = 21
        Enabled = False
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 6
        Text = '32'
      end
      object btnCleanBoot: TButton
        Left = 216
        Top = 208
        Width = 97
        Height = 33
        Caption = 'Clean Boot'
        TabOrder = 7
        Visible = False
        OnClick = btnCleanBootClick
      end
    end
    object tsPMICReg: TTabSheet
      Caption = 'PMIC Register Read/Write'
      ImageIndex = 3
      object lblPMICRegAddr: TLabel
        Left = 48
        Top = 32
        Width = 79
        Height = 13
        Caption = 'Register Number'
      end
      object lblPMICRegAddr0X: TLabel
        Left = 24
        Top = 52
        Width = 11
        Height = 13
        Caption = '0x'
      end
      object lblPMICRegValue0X: TLabel
        Left = 146
        Top = 52
        Width = 11
        Height = 13
        Caption = '0x'
      end
      object edtPMICAddress: TEdit
        Left = 40
        Top = 48
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 0
        Text = '0'
        OnExit = edtPMICAddressCheck
      end
      object btnPMICRegValue: TButton
        Tag = 1
        Left = 160
        Top = 16
        Width = 75
        Height = 25
        Caption = 'Value (Hex)'
        TabOrder = 1
        OnClick = btnPMICRegValueClick
      end
      object edtPMICValue: TEdit
        Left = 160
        Top = 48
        Width = 81
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 2
        Text = '0'
        OnExit = edtPMICValueCheck
      end
      object btnPMICRegRead: TButton
        Left = 280
        Top = 48
        Width = 65
        Height = 25
        Caption = 'Read'
        TabOrder = 3
        OnClick = btnPMICRegReadClick
      end
      object btnPMICRegWrite: TButton
        Left = 368
        Top = 48
        Width = 65
        Height = 25
        Caption = 'Write'
        TabOrder = 4
        OnClick = btnPMICRegWriteClick
      end
      object m_sbPMIC: TStatusBar
        Left = 0
        Top = 312
        Width = 698
        Height = 24
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object btnPMICReg: TButton
        Left = 280
        Top = 160
        Width = 185
        Height = 25
        Caption = 'PMIC register setting ...'
        TabOrder = 6
        Visible = False
        OnClick = btnPMICRegClick
      end
    end
    object tsBL: TTabSheet
      Caption = 'Battery Level'
      ImageIndex = 2
      TabVisible = False
      object Label2: TLabel
        Left = 32
        Top = 16
        Width = 3
        Height = 13
      end
      object sbBG: TStatusBar
        Left = 0
        Top = 310
        Width = 546
        Height = 32
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 8
        Width = 513
        Height = 169
        Caption = '  Input  '
        TabOrder = 1
        object Label3: TLabel
          Left = 16
          Top = 32
          Width = 65
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = 'Shutdown '
        end
        object Label4: TLabel
          Left = 152
          Top = 32
          Width = 65
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = 'No MO call'
        end
        object Label5: TLabel
          Left = 280
          Top = 32
          Width = 89
          Height = 13
          AutoSize = False
          Caption = 'Low battery waring'
        end
        object Label6: TLabel
          Left = 16
          Top = 104
          Width = 65
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = 'Level 1'
        end
        object Label7: TLabel
          Left = 152
          Top = 104
          Width = 65
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = 'Leve 2'
        end
        object Label8: TLabel
          Left = 288
          Top = 104
          Width = 65
          Height = 13
          Alignment = taCenter
          AutoSize = False
          Caption = 'Level 3'
        end
        object Label9: TLabel
          Left = 88
          Top = 48
          Width = 13
          Height = 13
          Caption = 'uV'
        end
        object Label10: TLabel
          Left = 224
          Top = 48
          Width = 13
          Height = 13
          Caption = 'uV'
        end
        object Label11: TLabel
          Left = 360
          Top = 48
          Width = 13
          Height = 13
          Caption = 'uV'
        end
        object Label12: TLabel
          Left = 88
          Top = 120
          Width = 13
          Height = 13
          Caption = 'uV'
        end
        object Label13: TLabel
          Left = 224
          Top = 120
          Width = 13
          Height = 13
          Caption = 'uV'
        end
        object Label14: TLabel
          Left = 360
          Top = 120
          Width = 13
          Height = 13
          Caption = 'uV'
        end
        object edtBGShutdown: TEdit
          Left = 16
          Top = 48
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 0
          Text = '0'
        end
        object edtBGNoMoCall: TEdit
          Tag = 1
          Left = 152
          Top = 48
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 1
          Text = '0'
        end
        object edtBGLowBatteryWarning: TEdit
          Tag = 2
          Left = 288
          Top = 48
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 2
          Text = '0'
        end
        object edtBGLevel1: TEdit
          Tag = 3
          Left = 16
          Top = 120
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 3
          Text = '0'
        end
        object edtBGLevel2: TEdit
          Tag = 4
          Left = 152
          Top = 120
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 4
          Text = '0'
        end
        object edtBGLevel3: TEdit
          Tag = 5
          Left = 288
          Top = 120
          Width = 65
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 5
          Text = '0'
        end
      end
      object btnBGUploadFromFlash: TButton
        Left = 8
        Top = 187
        Width = 100
        Height = 25
        Caption = 'Upload from flash'
        TabOrder = 2
      end
      object btnBGDownloadToFlash: TButton
        Left = 122
        Top = 187
        Width = 100
        Height = 25
        Caption = 'Download to flash'
        TabOrder = 3
      end
      object btnBGChangeDB: TButton
        Left = 236
        Top = 187
        Width = 100
        Height = 25
        Caption = 'Change NVRAM DB'
        TabOrder = 4
      end
      object btnBGLoadFromFile: TButton
        Left = 350
        Top = 187
        Width = 80
        Height = 25
        Caption = 'Load from file'
        TabOrder = 5
      end
      object btnBGSaveToFile: TButton
        Left = 440
        Top = 187
        Width = 80
        Height = 25
        Caption = 'Save to file'
        TabOrder = 6
      end
    end
    object tsLED: TTabSheet
      Caption = 'Light'
      ImageIndex = 4
      OnShow = tsLEDShow
      object Label17: TLabel
        Left = 32
        Top = 16
        Width = 113
        Height = 13
        Caption = 'LED light level (Keypad)'
      end
      object Label25: TLabel
        Left = 33
        Top = 144
        Width = 68
        Height = 13
        Caption = 'LCD light level'
      end
      object Label27: TLabel
        Left = 48
        Top = 41
        Width = 18
        Height = 13
        Caption = 'DIV'
      end
      object Label28: TLabel
        Left = 48
        Top = 65
        Width = 30
        Height = 13
        Caption = 'DUTY'
      end
      object btnKeypadLEDOn: TButton
        Left = 160
        Top = 64
        Width = 75
        Height = 25
        Caption = 'Turn On'
        TabOrder = 0
        OnClick = btnKeypadLEDOnClick
      end
      object m_sbLED: TStatusBar
        Left = 0
        Top = 306
        Width = 698
        Height = 30
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object edtLCDLED: TEdit
        Left = 88
        Top = 172
        Width = 49
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 2
        Text = '0'
        OnExit = edtLCDLEDCheck
      end
      object btnLCDLEDSet: TButton
        Left = 160
        Top = 172
        Width = 75
        Height = 25
        Caption = 'Set'
        TabOrder = 3
        OnClick = btnLCDLEDSetClick
      end
      object btnKeypadLEDOff: TButton
        Left = 248
        Top = 64
        Width = 73
        Height = 25
        Caption = 'Turn Off'
        TabOrder = 4
        OnClick = btnKeypadLEDOffClick
      end
      object edtKeypadLedDIV: TEdit
        Left = 88
        Top = 41
        Width = 49
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 5
        Text = '0'
        OnExit = edtKeypadLEDDivCheck
      end
      object edtKeypadLedDUTY: TEdit
        Left = 88
        Top = 65
        Width = 49
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        TabOrder = 6
        Text = '0'
        OnExit = edtKeypadLEDDutyCheck
      end
    end
    object tsVBR: TTabSheet
      Caption = 'Vibrator'
      ImageIndex = 5
      object btnVBROn: TButton
        Left = 48
        Top = 40
        Width = 121
        Height = 33
        Caption = 'Turn on'
        TabOrder = 0
        OnClick = btnVBROnClick
      end
      object btnVBROff: TButton
        Left = 184
        Top = 40
        Width = 121
        Height = 33
        Caption = 'Turn off'
        TabOrder = 1
        OnClick = btnVBROffClick
      end
      object m_sbVBR: TStatusBar
        Left = 0
        Top = 306
        Width = 698
        Height = 30
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object tsRTC: TTabSheet
      Caption = 'RTC'
      ImageIndex = 6
      object Label18: TLabel
        Left = 48
        Top = 24
        Width = 22
        Height = 13
        Caption = 'Year'
      end
      object Label19: TLabel
        Left = 256
        Top = 24
        Width = 63
        Height = 13
        Caption = 'Day of Week'
      end
      object Label20: TLabel
        Left = 128
        Top = 24
        Width = 30
        Height = 13
        Caption = 'Month'
      end
      object Label21: TLabel
        Left = 200
        Top = 24
        Width = 19
        Height = 13
        Caption = 'Day'
      end
      object Label22: TLabel
        Left = 48
        Top = 72
        Width = 23
        Height = 13
        Caption = 'Hour'
      end
      object Label23: TLabel
        Left = 120
        Top = 72
        Width = 32
        Height = 13
        Caption = 'Minute'
      end
      object Label24: TLabel
        Left = 208
        Top = 72
        Width = 19
        Height = 13
        Caption = 'Sec'
      end
      object edtRTCYear: TEdit
        Left = 32
        Top = 40
        Width = 57
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ReadOnly = True
        TabOrder = 0
      end
      object edtRTCWDay: TEdit
        Left = 261
        Top = 40
        Width = 57
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ReadOnly = True
        TabOrder = 1
      end
      object edtRTCMonth: TEdit
        Left = 109
        Top = 40
        Width = 57
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ReadOnly = True
        TabOrder = 2
      end
      object edtRTCDay: TEdit
        Left = 186
        Top = 40
        Width = 57
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ReadOnly = True
        TabOrder = 3
      end
      object edtRTCWHour: TEdit
        Left = 32
        Top = 88
        Width = 57
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ReadOnly = True
        TabOrder = 4
      end
      object edtRTCMinute: TEdit
        Left = 109
        Top = 88
        Width = 57
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ReadOnly = True
        TabOrder = 5
      end
      object edtRTCSec: TEdit
        Left = 186
        Top = 88
        Width = 57
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
        ReadOnly = True
        TabOrder = 6
      end
      object btnRTCQuery: TButton
        Left = 352
        Top = 40
        Width = 75
        Height = 25
        Caption = 'Query'
        TabOrder = 7
        OnClick = btnRTCQueryClick
      end
      object m_sbRTC: TStatusBar
        Left = 0
        Top = 306
        Width = 698
        Height = 30
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object tsSignalIndicator: TTabSheet
      Caption = 'Signal Indicator'
      ImageIndex = 7
      object Label29: TLabel
        Left = 40
        Top = 56
        Width = 49
        Height = 13
        Caption = 'Red Light:'
      end
      object Label30: TLabel
        Left = 40
        Top = 152
        Width = 50
        Height = 13
        Caption = 'Blue Light:'
      end
      object Label31: TLabel
        Left = 40
        Top = 104
        Width = 55
        Height = 13
        Caption = 'GreenLight:'
      end
      object btnRedLightOn: TButton
        Left = 128
        Top = 48
        Width = 73
        Height = 25
        Caption = 'Turn On'
        TabOrder = 0
        OnClick = btnRedLightOnClick
      end
      object btnRedLightOff: TButton
        Left = 224
        Top = 48
        Width = 73
        Height = 25
        Caption = ' Turn Off'
        TabOrder = 1
        OnClick = btnRedLightOffClick
      end
      object m_sbSignalIndicator: TStatusBar
        Left = 0
        Top = 306
        Width = 698
        Height = 30
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object btnGreenLightOff: TButton
        Left = 224
        Top = 97
        Width = 73
        Height = 25
        Caption = 'Turn Off'
        TabOrder = 3
        OnClick = btnGreenLightOffClick
      end
      object btnGreenLightOn: TButton
        Left = 128
        Top = 97
        Width = 73
        Height = 25
        Caption = 'Turn On'
        TabOrder = 4
        OnClick = btnGreenLightOnClick
      end
      object btnBlueLightOff: TButton
        Left = 224
        Top = 144
        Width = 73
        Height = 25
        Caption = 'Turn Off'
        TabOrder = 5
        OnClick = btnBlueLightOffClick
      end
      object btnBlueLightOn: TButton
        Left = 128
        Top = 144
        Width = 73
        Height = 25
        Caption = 'Turn On'
        TabOrder = 6
        OnClick = btnBlueLightOnClick
      end
    end
    object tsBattery: TTabSheet
      Caption = 'Battery'
      ImageIndex = 8
      TabVisible = False
      object Panel2: TPanel
        Left = 40
        Top = 0
        Width = 465
        Height = 305
        Color = clMenuBar
        TabOrder = 3
        object GroupBox3: TGroupBox
          Left = 16
          Top = 92
          Width = 433
          Height = 209
          Caption = 'Read Battery Info'
          TabOrder = 6
          object LBDisplay: TLabel
            Left = 48
            Top = 64
            Width = 351
            Height = 16
            Caption = 'The version of  DFI and BQ27500 firmware does not match!!!'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clRed
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
          object BtnReadSOC: TButton
            Left = 24
            Top = 80
            Width = 89
            Height = 33
            Caption = 'ReadSOC'
            TabOrder = 0
          end
          object BtnWriteSOC: TButton
            Left = 120
            Top = 80
            Width = 89
            Height = 33
            Caption = 'WriteSOC'
            TabOrder = 1
          end
          object EdtSOC: TEdit
            Left = 336
            Top = 88
            Width = 73
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 2
            Text = '0'
            OnExit = EdtExit
          end
          object STSOC: TStaticText
            Left = 248
            Top = 88
            Width = 75
            Height = 17
            Caption = 'SOC1threshold'
            TabOrder = 3
          end
          object STDFI: TStaticText
            Left = 240
            Top = 4
            Width = 59
            Height = 17
            Caption = 'DFI Version'
            TabOrder = 4
          end
          object EdtDFIVersion: TEdit
            Left = 240
            Top = 27
            Width = 57
            Height = 21
            Enabled = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clActiveCaption
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            ParentFont = False
            TabOrder = 5
            Text = '0'
          end
          object StaticText1: TStaticText
            Left = 126
            Top = 32
            Width = 15
            Height = 17
            Caption = '0x'
            TabOrder = 6
          end
          object StaticText2: TStaticText
            Left = 400
            Top = 32
            Width = 18
            Height = 17
            Caption = 'mv'
            TabOrder = 7
          end
          object EdtSOCClear: TEdit
            Left = 336
            Top = 128
            Width = 81
            Height = 21
            ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
            TabOrder = 8
            Text = '0'
            OnExit = EdtExit
          end
          object StaticText3: TStaticText
            Left = 224
            Top = 128
            Width = 99
            Height = 17
            Caption = 'SOC1Clearthreshold'
            TabOrder = 9
          end
          object BtnWriteSOCClear: TButton
            Left = 120
            Top = 120
            Width = 89
            Height = 33
            Caption = 'WriteSOCClear'
            TabOrder = 10
          end
          object BtnReadSOCClear: TButton
            Left = 24
            Top = 120
            Width = 89
            Height = 33
            Caption = 'ReadSOCClear'
            TabOrder = 11
          end
          object StaticText4: TStaticText
            Left = 222
            Top = 32
            Width = 15
            Height = 17
            Caption = '0x'
            TabOrder = 12
          end
          object BtnEnableBQ: TButton
            Left = 24
            Top = 160
            Width = 89
            Height = 33
            Caption = 'Enable BQ IT'
            TabOrder = 13
          end
        end
        object BtnReadBatteryInfo: TButton
          Left = 40
          Top = 112
          Width = 89
          Height = 33
          Caption = 'ReadBatteryInfo'
          TabOrder = 0
        end
        object EdtFWValue: TEdit
          Left = 160
          Top = 120
          Width = 57
          Height = 21
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clActiveCaption
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ParentFont = False
          TabOrder = 1
          Text = '0'
        end
        object EdtVoltage: TEdit
          Left = 354
          Top = 118
          Width = 57
          Height = 21
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clActiveCaption
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          ParentFont = False
          TabOrder = 2
          Text = '0'
          OnExit = EdtExit
        end
        object STFWValue: TStaticText
          Left = 162
          Top = 96
          Width = 59
          Height = 17
          Caption = 'FW Version'
          TabOrder = 3
        end
        object STVoltage: TStaticText
          Left = 360
          Top = 96
          Width = 40
          Height = 17
          Caption = 'Voltage'
          TabOrder = 4
        end
        object GroupBox2: TGroupBox
          Left = 16
          Top = 8
          Width = 433
          Height = 83
          Caption = 'Download DFI'
          TabOrder = 5
          object Label32: TLabel
            Left = 8
            Top = 59
            Width = 33
            Height = 13
            Caption = 'Status:'
          end
          object BtnUpdateFW: TButton
            Left = 248
            Top = 16
            Width = 121
            Height = 33
            Caption = 'Update FW'
            TabOrder = 0
          end
          object ProgressBar1: TProgressBar
            Left = 48
            Top = 60
            Width = 337
            Height = 13
            Min = 0
            Max = 100
            TabOrder = 1
          end
        end
      end
      object btnDownloadImage: TButton
        Left = 112
        Top = 24
        Width = 121
        Height = 33
        Caption = 'Download Image'
        TabOrder = 0
      end
      object btnUploadImage: TButton
        Left = 432
        Top = 184
        Width = 105
        Height = 33
        Caption = 'Upload Image'
        TabOrder = 1
        Visible = False
      end
      object m_sbBattery: TStatusBar
        Left = 0
        Top = 306
        Width = 698
        Height = 30
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'ECCI'
      ImageIndex = 9
      object spUSB: TShape
        Left = 136
        Top = 40
        Width = 25
        Height = 33
        Brush.Color = clSilver
        Shape = stCircle
      end
      object spUART: TShape
        Left = 136
        Top = 72
        Width = 25
        Height = 33
        Brush.Color = clSilver
        Shape = stCircle
      end
      object btnUSB: TButton
        Left = 32
        Top = 40
        Width = 75
        Height = 25
        Caption = 'USB Test'
        TabOrder = 0
        OnClick = btnUSBClick
      end
      object btnUART: TButton
        Left = 32
        Top = 80
        Width = 75
        Height = 25
        Caption = 'UART Test'
        TabOrder = 1
        OnClick = btnUARTClick
      end
      object m_sbECCI: TStatusBar
        Left = 0
        Top = 306
        Width = 698
        Height = 30
        Panels = <
          item
            Width = 50
          end>
        SimplePanel = False
      end
      object btnReset: TButton
        Left = 32
        Top = 120
        Width = 75
        Height = 25
        Caption = 'Reset'
        TabOrder = 3
        OnClick = btnResetClick
      end
    end
  end
  object lblHint: TStaticText
    Left = 512
    Top = 328
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
    Left = 400
    Top = 328
  end
end
