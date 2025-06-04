object frmDRMKeyInstall: TfrmDRMKeyInstall
  Left = 555
  Top = 165
  Width = 629
  Height = 563
  Caption = 'DRM Key Install Tool '
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
    Left = 24
    Top = 16
    Width = 561
    Height = 489
    TabOrder = 0
    object BtnLoadKeyBlockFile: TButton
      Left = 16
      Top = 24
      Width = 113
      Height = 25
      Caption = 'Load KeyBlock File'
      TabOrder = 0
      OnClick = BtnLoadKeyBlockFileClick
    end
    object stKeyBlockFile: TStaticText
      Left = 160
      Top = 24
      Width = 361
      Height = 25
      AutoSize = False
      BevelInner = bvLowered
      BorderStyle = sbsSunken
      Color = clSkyBlue
      ParentColor = False
      TabOrder = 1
    end
    object BtnInstall: TButton
      Left = 16
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Install'
      TabOrder = 2
      OnClick = BtnInstallClick
    end
    object DRMLog: TRichEdit
      Left = 15
      Top = 128
      Width = 530
      Height = 305
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
      TabOrder = 3
    end
    object BtnQueryVerify: TButton
      Left = 112
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Query && Verify'
      TabOrder = 4
      OnClick = BtnQueryVerifyClick
    end
    object BtnClearLog: TButton
      Left = 448
      Top = 96
      Width = 75
      Height = 25
      Caption = 'Clear Log'
      TabOrder = 5
      OnClick = BtnClearLogClick
    end
  end
  object stDRMInfo: TStaticText
    Left = 5
    Top = 511
    Width = 457
    Height = 18
    AutoSize = False
    BevelInner = bvNone
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    TabOrder = 1
  end
  object dlg_OpenKeyBlockFile: TOpenDialog
    Left = 320
    Top = 464
  end
end
