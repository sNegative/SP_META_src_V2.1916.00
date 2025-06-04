object frmMainSel: TfrmMainSel
  Left = 540
  Top = 341
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'SP META Tool'
  ClientHeight = 104
  ClientWidth = 641
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object shpConnect: TShape
    Left = 232
    Top = 3
    Width = 17
    Height = 20
    Brush.Color = clRed
    Shape = stCircle
  end
  object Label1: TLabel
    Left = 408
    Top = 60
    Width = 43
    Height = 21
    AutoSize = False
    Caption = 'Baudrate'
    Layout = tlCenter
  end
  object Label4: TLabel
    Left = 0
    Top = 43
    Width = 61
    Height = 20
    AutoSize = False
    Caption = 'Smart Phone'
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Layout = tlCenter
  end
  object lbConnectionTime: TLabel
    Left = 0
    Top = 72
    Width = 80
    Height = 20
    AutoSize = False
    Caption = 'Connection Time'
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Layout = tlCenter
    Visible = False
  end
  object pnlResetTarget: TPanel
    Left = 88
    Top = 43
    Width = 169
    Height = 20
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Please reset target'
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
  end
  object cbxOperation: TComboBox
    Left = 9
    Top = 9
    Width = 137
    Height = 21
    Style = csDropDownList
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ItemHeight = 13
    ParentFont = False
    TabOrder = 0
    OnChange = cbxOperationChange
  end
  object cbxCOM: TComboBox
    Left = 153
    Top = 9
    Width = 73
    Height = 21
    Style = csDropDownList
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ItemHeight = 13
    ParentFont = False
    TabOrder = 1
    OnChange = cbxCOMChange
    OnDropDown = cbxCOMDropDown
  end
  object GroupBox3: TGroupBox
    Left = 280
    Top = 208
    Width = 75
    Height = 65
    Caption = ' Flow control '
    TabOrder = 8
    Visible = False
    object rbSoftware: TRadioButton
      Left = 8
      Top = 16
      Width = 65
      Height = 17
      Caption = 'Software'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object rbHardware: TRadioButton
      Left = 8
      Top = 40
      Width = 65
      Height = 17
      Caption = 'Hardware'
      TabOrder = 1
    end
  end
  object btnReconnect: TButton
    Left = 320
    Top = 35
    Width = 70
    Height = 22
    Caption = 'Reconnect'
    TabOrder = 3
    OnClick = btnReconnectClick
  end
  object cbBaudrate: TComboBox
    Left = 456
    Top = 60
    Width = 65
    Height = 21
    ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ItemHeight = 13
    ItemIndex = 5
    TabOrder = 6
    Text = '921600'
    OnChange = cbBaudrateChange
    Items.Strings = (
      'Auto'
      '57600'
      '115200'
      '230400'
      '460800'
      '921600')
  end
  object lblHint: TStaticText
    Left = 280
    Top = 184
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 9
    Visible = False
  end
  object stMETALog: TStaticText
    Left = 232
    Top = 23
    Width = 53
    Height = 17
    AutoSize = False
    BorderStyle = sbsSunken
    Caption = 'META log'
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 10
    Visible = False
  end
  object stBROMLog: TStaticText
    Left = 216
    Top = 240
    Width = 53
    Height = 17
    AutoSize = False
    BorderStyle = sbsSunken
    Caption = 'BROM log'
    Color = clWhite
    ParentColor = False
    TabOrder = 11
    Visible = False
  end
  object m_btnDisconnect: TButton
    Left = 320
    Top = 7
    Width = 70
    Height = 22
    Caption = 'Disconnect'
    TabOrder = 2
    OnClick = m_btnDisconnectClick
  end
  object CbCleanBootFlag: TCheckBox
    Left = 408
    Top = 3
    Width = 113
    Height = 17
    Caption = 'Backup NVRam'
    Checked = True
    State = cbChecked
    TabOrder = 4
  end
  object cbMetaModeLock: TCheckBox
    Left = 408
    Top = 40
    Width = 105
    Height = 17
    Caption = 'Meta Mode Lock'
    TabOrder = 5
    Visible = False
    OnClick = cbMetaModeLockClick
  end
  object stConnectionTime: TPanel
    Left = 88
    Top = 75
    Width = 169
    Height = 20
    BevelOuter = bvNone
    BorderStyle = bsSingle
    Caption = 'Unknown'
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 12
    Visible = False
  end
  object glbTimer: TTimer
    Enabled = False
    OnTimer = glbTimerTimer
    Left = 352
    Top = 184
  end
  object MainMenu1: TMainMenu
    Left = 320
    Top = 184
    object Action1: TMenuItem
      Caption = '&Action'
      ShortCut = 16449
      object mnuOpenFDMDatabase: TMenuItem
        Caption = 'Open NVRAM Database ...'
        OnClick = mnuFDMDatabaseClick
      end
      object miOpenAuthenticationfile: TMenuItem
        Caption = 'Open Authentication file ...'
        OnClick = miOpenAuthenticationfileClick
      end
      object m_miOpenCertificatefile: TMenuItem
        Caption = 'Open Certificate file'
        OnClick = m_miOpenCertificatefileClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
    end
    object Option1: TMenuItem
      Caption = '&Option'
      ShortCut = 16463
      object m_miConInMetaMode: TMenuItem
        Caption = 'Connect target already in META mode'
        OnClick = m_miConInMetaModeClick
      end
      object m_miLegacyAutoDetection: TMenuItem
        Caption = 'Smart phone Legacy USB auto detection'
        OnClick = m_miLegacyAutoDetectionClick
      end
      object m_miEnableCompositeUSB: TMenuItem
        Caption = 'Enable composite Kernel USB'
        Checked = True
        OnClick = m_miEnableCompositeUSBClick
      end
      object m_miMDlogging: TMenuItem
        Caption = 'Enable MD Logging and Pop up ELT USB'
        OnClick = m_miMDloggingClick
      end
      object m_miDisableMobileLogService: TMenuItem
        Caption = 'Disable mobile log service'
        OnClick = m_miDisableMobileLogServiceClick
      end
      object m_miDisableUartLog: TMenuItem
        Caption = 'Disable Uart Log'
        OnClick = m_miDisableUartLogClick
      end
    end
    object mnuHelp: TMenuItem
      Caption = '&Help'
      ShortCut = 16456
      object mnuAbout: TMenuItem
        Caption = '&About'
        ShortCut = 16449
        OnClick = mnuAboutClick
      end
      object miUnitTest: TMenuItem
        Caption = 'Unit Test ...'
        OnClick = miUnitTestClick
      end
      object m_miDriverInfo: TMenuItem
        Caption = 'Driver Information'
        OnClick = m_miDriverInfoClick
      end
      object miSpecialTest: TMenuItem
        Caption = 'Special Test'
        OnClick = miSpecialTestClick
      end
      object miMetaConnectTime: TMenuItem
        Caption = 'Meta Connect Time'
        OnClick = miMetaConnectTimeClick
      end
    end
  end
  object ActionList1: TActionList
    Left = 384
    Top = 176
    object ToggleMETADebug: TAction
      Caption = 'ToggleMETADebug'
      ShortCut = 49229
      OnExecute = ToggleMETADebugExecute
    end
    object LogClear: TAction
      Caption = 'LogClear'
      ShortCut = 49219
      OnExecute = LogClearExecute
    end
    object ToggleHide: TAction
      Caption = 'ToggleHide'
      ShortCut = 49237
      OnExecute = ToggleHideExecute
    end
    object ToggleMetaModeLock: TAction
      Caption = 'ToggleMetaModeLock'
      ShortCut = 49226
      OnExecute = ToggleMetaModeLockExecute
    end
    object actReconnect: TAction
      Caption = 'actReconnect'
      ShortCut = 16466
      OnExecute = actReconnectExecute
    end
    object actDisconnect: TAction
      Caption = 'actDisconnect'
      ShortCut = 16452
      OnExecute = actDisconnectExecute
    end
    object actAdmemo: TAction
      Caption = 'actAdmemo'
      ShortCut = 16472
    end
    object ConnectionTime: TAction
      Caption = 'ConnectionTime'
      ShortCut = 49236
      Visible = False
      OnExecute = ConnectionTimeExecute
    end
    object ToggleSpecialTest: TAction
      Caption = 'ToggleSpecialTest'
      ShortCut = 49235
      OnExecute = ToggleSpecialTestExecute
    end
  end
  object HintTimer: TTimer
    OnTimer = HintTimerTimer
    Left = 416
    Top = 176
  end
  object dlgOpenAuth: TOpenDialog
    DefaultExt = 'auth'
    Filter = 'Auth file|*.auth|All files (*.*)|*.*'
    Left = 216
    Top = 184
  end
  object OpenDialog: TOpenDialog
    Left = 248
    Top = 184
  end
  object usbFinder: TTimer
    Enabled = False
    Left = 456
    Top = 176
  end
  object kernalUSBFinder: TTimer
    Enabled = False
    Left = 512
    Top = 200
  end
  object dlgOpenScert: TOpenDialog
    Left = 256
    Top = 72
  end
end
