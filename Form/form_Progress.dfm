object m_frmProgress: Tm_frmProgress
  Left = 427
  Top = 388
  Width = 544
  Height = 71
  Caption = 'NVRAM Database File Initilization Status'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object m_pbStatus: TProgressBar
    Left = 16
    Top = 16
    Width = 505
    Height = 16
    Min = 0
    Max = 100
    Smooth = True
    TabOrder = 0
  end
  object m_Timer: TTimer
    OnTimer = m_TimerTimer
    Left = 168
    Top = 8
  end
end
