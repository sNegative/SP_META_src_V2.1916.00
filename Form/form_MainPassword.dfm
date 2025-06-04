object frmMainPassword: TfrmMainPassword
  Left = 579
  Top = 385
  Width = 304
  Height = 121
  BorderIcons = [biSystemMenu]
  Caption = 'Please enter the password'
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
  object edtPassword: TEdit
    Left = 72
    Top = 16
    Width = 169
    Height = 21
    TabOrder = 0
  end
  object btnVerifyOK: TButton
    Left = 72
    Top = 48
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = btnVerifyOKClick
  end
  object btnVerifyCancel: TButton
    Left = 168
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = btnVerifyCancelClick
  end
end
