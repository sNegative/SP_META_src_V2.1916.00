object frmMultiSIM: TfrmMultiSIM
  Left = 536
  Top = 176
  Width = 563
  Height = 404
  Caption = 'Multi-SIM'
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
  object m_sbMultiSIMStatus: TStatusBar
    Left = 0
    Top = 341
    Width = 547
    Height = 25
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object GroupBoxMSIM: TGroupBox
    Left = 16
    Top = 16
    Width = 425
    Height = 257
    Caption = 'Multi-SIM Configuration'
    TabOrder = 1
    object radioBtnSs: TRadioButton
      Left = 24
      Top = 40
      Width = 153
      Height = 17
      Caption = 'Single SIM single standby'
      TabOrder = 0
    end
    object radioBtnDsds: TRadioButton
      Left = 24
      Top = 72
      Width = 137
      Height = 17
      Caption = 'Dual SIM dual standby'
      TabOrder = 1
    end
  end
  object btnMSIMUpdate: TButton
    Left = 456
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Update'
    TabOrder = 2
    OnClick = btnMSIMUpdateClick
  end
end
