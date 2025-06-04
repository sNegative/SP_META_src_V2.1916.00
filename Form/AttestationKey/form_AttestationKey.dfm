object frmAttestationKeyInstall: TfrmAttestationKeyInstall
  Left = 409
  Top = 472
  Width = 516
  Height = 136
  Caption = 'Attestation Key Install Tool'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object strKeyFile: TStaticText
    Left = 120
    Top = 16
    Width = 369
    Height = 25
    AutoSize = False
    BevelInner = bvLowered
    BorderStyle = sbsSunken
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 0
  end
  object BtnLoadKeyFile: TButton
    Left = 16
    Top = 16
    Width = 97
    Height = 25
    Caption = 'Load Key File'
    TabOrder = 1
    OnClick = BtnLoadKeyFileClick
  end
  object BtnInstall: TButton
    Left = 17
    Top = 56
    Width = 96
    Height = 25
    Caption = 'Install'
    TabOrder = 2
    OnClick = BtnInstallClick
  end
  object strStatusInfo: TStaticText
    Left = 120
    Top = 56
    Width = 369
    Height = 25
    AutoSize = False
    BevelInner = bvLowered
    BorderStyle = sbsSunken
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 3
  end
  object dlg_OpenKeyFile: TOpenDialog
    Left = 208
    Top = 64
  end
end
