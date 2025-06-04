object frmWiFiALC2400M: TfrmWiFiALC2400M
  Left = 236
  Top = 126
  Width = 696
  Height = 561
  Caption = 'WiFi 2.4G ALC Setting'
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
    Left = 8
    Top = 8
    Width = 153
    Height = 25
    BevelOuter = bvLowered
    Caption = 'CCK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 8
    Top = 32
    Width = 673
    Height = 89
    BevelOuter = bvLowered
    TabOrder = 1
    object Label1: TLabel
      Left = 112
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '0'
    end
    object Label2: TLabel
      Left = 152
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '1'
    end
    object Label3: TLabel
      Left = 192
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '2'
    end
    object Label4: TLabel
      Left = 232
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '3'
    end
    object Label5: TLabel
      Left = 272
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '4'
    end
    object Label6: TLabel
      Left = 312
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '5'
    end
    object Label7: TLabel
      Left = 352
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '6'
    end
    object Label8: TLabel
      Left = 392
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '7'
    end
    object Label9: TLabel
      Left = 432
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '8'
    end
    object Label10: TLabel
      Left = 472
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '9'
    end
    object Label11: TLabel
      Left = 512
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '10'
    end
    object Label12: TLabel
      Left = 552
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '11'
    end
    object Label13: TLabel
      Left = 592
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '12'
    end
    object Label14: TLabel
      Left = 632
      Top = 8
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '13'
    end
    object Label29: TLabel
      Left = 70
      Top = 26
      Width = 37
      Height = 13
      Caption = 'TX ALC'
    end
    object Label30: TLabel
      Left = 8
      Top = 56
      Width = 100
      Height = 13
      Caption = 'TX Output Power DB'
    end
    object m_edtTxAlcCCK00: TEdit
      Left = 112
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 0
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK01: TEdit
      Tag = 1
      Left = 152
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 1
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK02: TEdit
      Tag = 2
      Left = 192
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 2
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK03: TEdit
      Tag = 3
      Left = 232
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 3
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK04: TEdit
      Tag = 4
      Left = 272
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 4
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK05: TEdit
      Tag = 5
      Left = 312
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 5
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK06: TEdit
      Tag = 6
      Left = 352
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 6
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK07: TEdit
      Tag = 7
      Left = 392
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 7
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK08: TEdit
      Tag = 8
      Left = 432
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 8
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK09: TEdit
      Tag = 9
      Left = 472
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 9
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK10: TEdit
      Tag = 10
      Left = 512
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 10
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK11: TEdit
      Tag = 11
      Left = 552
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 11
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK12: TEdit
      Tag = 12
      Left = 592
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 12
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxAlcCCK13: TEdit
      Tag = 13
      Left = 632
      Top = 24
      Width = 32
      Height = 21
      TabOrder = 13
      Text = '0'
      OnExit = edtTxAlcCCKCheck
    end
    object m_edtTxOutputPowerDbCCK00: TEdit
      Left = 112
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 14
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK01: TEdit
      Tag = 1
      Left = 152
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 15
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK02: TEdit
      Tag = 2
      Left = 192
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 16
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK03: TEdit
      Tag = 3
      Left = 232
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 17
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK04: TEdit
      Tag = 4
      Left = 272
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 18
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK05: TEdit
      Tag = 5
      Left = 312
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 19
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK06: TEdit
      Tag = 6
      Left = 352
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 20
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK07: TEdit
      Tag = 7
      Left = 392
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 21
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK08: TEdit
      Tag = 8
      Left = 432
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 22
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK09: TEdit
      Tag = 9
      Left = 472
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 23
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK10: TEdit
      Tag = 10
      Left = 512
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 24
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK11: TEdit
      Tag = 11
      Left = 552
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 25
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK12: TEdit
      Tag = 12
      Left = 592
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 26
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
    object m_edtTxOutputPowerDbCCK13: TEdit
      Tag = 13
      Left = 632
      Top = 56
      Width = 32
      Height = 21
      TabOrder = 27
      Text = '0'
      OnExit = edtTxOutputPowerDbCCKCheck
    end
  end
  object Panel5: TPanel
    Left = 8
    Top = 128
    Width = 153
    Height = 25
    BevelOuter = bvLowered
    Caption = 'OFDM '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object Panel6: TPanel
    Left = 8
    Top = 152
    Width = 673
    Height = 97
    BevelOuter = bvLowered
    TabOrder = 3
    object Label15: TLabel
      Left = 104
      Top = 16
      Width = 40
      Height = 13
      Caption = 'TX Rate'
    end
    object Label16: TLabel
      Left = 72
      Top = 42
      Width = 74
      Height = 13
      Caption = 'Offset (TX ALC)'
    end
    object Label35: TLabel
      Left = 8
      Top = 70
      Width = 137
      Height = 13
      Caption = 'Offset (TX Output Power DB)'
    end
    object m_btnOFDMTxRate0: TButton
      Left = 152
      Top = 8
      Width = 32
      Height = 25
      Caption = '0'
      TabOrder = 0
      OnClick = btnOFDMTxRateClick
    end
    object m_btnOFDMTxRate1: TButton
      Tag = 1
      Left = 192
      Top = 8
      Width = 32
      Height = 25
      Caption = '1'
      TabOrder = 1
      OnClick = btnOFDMTxRateClick
    end
    object m_btnOFDMTxRate2: TButton
      Tag = 2
      Left = 232
      Top = 8
      Width = 32
      Height = 25
      Caption = '2'
      TabOrder = 2
      OnClick = btnOFDMTxRateClick
    end
    object m_btnOFDMTxRate3: TButton
      Tag = 3
      Left = 272
      Top = 8
      Width = 32
      Height = 25
      Caption = '3'
      TabOrder = 3
      OnClick = btnOFDMTxRateClick
    end
    object m_btnOFDMTxRate4: TButton
      Tag = 4
      Left = 312
      Top = 8
      Width = 32
      Height = 25
      Caption = '4'
      TabOrder = 4
      OnClick = btnOFDMTxRateClick
    end
    object m_btnOFDMTxRate5: TButton
      Tag = 5
      Left = 352
      Top = 8
      Width = 32
      Height = 25
      Caption = '5'
      TabOrder = 5
      OnClick = btnOFDMTxRateClick
    end
    object m_btnOFDMTxRate6: TButton
      Tag = 6
      Left = 392
      Top = 8
      Width = 32
      Height = 25
      Caption = '6'
      TabOrder = 6
      OnClick = btnOFDMTxRateClick
    end
    object m_btnOFDMTxRate7: TButton
      Tag = 7
      Left = 432
      Top = 8
      Width = 32
      Height = 25
      Caption = '7'
      TabOrder = 7
      OnClick = btnOFDMTxRateClick
    end
    object m_edtOFDMTxAlcOffset0: TEdit
      Left = 152
      Top = 40
      Width = 32
      Height = 21
      TabOrder = 8
      Text = '0'
      Visible = False
      OnExit = edtOFDMTxAlcOffsetCheck
    end
    object m_edtOFDMTxAlcOffset1: TEdit
      Tag = 1
      Left = 192
      Top = 40
      Width = 32
      Height = 21
      TabOrder = 9
      Text = '0'
      OnExit = edtOFDMTxAlcOffsetCheck
    end
    object m_edtOFDMTxAlcOffset2: TEdit
      Tag = 2
      Left = 232
      Top = 40
      Width = 32
      Height = 21
      TabOrder = 10
      Text = '0'
      OnExit = edtOFDMTxAlcOffsetCheck
    end
    object m_edtOFDMTxAlcOffset3: TEdit
      Tag = 3
      Left = 272
      Top = 40
      Width = 32
      Height = 21
      TabOrder = 11
      Text = '0'
      OnExit = edtOFDMTxAlcOffsetCheck
    end
    object m_edtOFDMTxAlcOffset4: TEdit
      Tag = 4
      Left = 312
      Top = 40
      Width = 32
      Height = 21
      TabOrder = 12
      Text = '0'
      OnExit = edtOFDMTxAlcOffsetCheck
    end
    object m_edtOFDMTxAlcOffset5: TEdit
      Tag = 5
      Left = 352
      Top = 40
      Width = 32
      Height = 21
      TabOrder = 13
      Text = '0'
      OnExit = edtOFDMTxAlcOffsetCheck
    end
    object m_edtOFDMTxAlcOffset6: TEdit
      Tag = 6
      Left = 392
      Top = 40
      Width = 32
      Height = 21
      TabOrder = 14
      Text = '0'
      OnExit = edtOFDMTxAlcOffsetCheck
    end
    object m_edtOFDMTxAlcOffset7: TEdit
      Tag = 7
      Left = 432
      Top = 40
      Width = 32
      Height = 21
      TabOrder = 15
      Text = '0'
      OnExit = edtOFDMTxAlcOffsetCheck
    end
    object m_btnApply: TButton
      Left = 520
      Top = 40
      Width = 75
      Height = 25
      Caption = 'Apply'
      TabOrder = 16
      OnClick = m_btnApplyClick
    end
    object m_edtOFDMTxOutputPowerOffset0: TEdit
      Left = 152
      Top = 64
      Width = 32
      Height = 21
      TabOrder = 17
      Text = '0'
      Visible = False
      OnExit = edtOFDMTxOutputPowerOffsetCheck
    end
    object m_edtOFDMTxOutputPowerOffset1: TEdit
      Tag = 1
      Left = 192
      Top = 64
      Width = 32
      Height = 21
      TabOrder = 18
      Text = '0'
      OnExit = edtOFDMTxOutputPowerOffsetCheck
    end
    object m_edtOFDMTxOutputPowerOffset2: TEdit
      Tag = 2
      Left = 232
      Top = 64
      Width = 32
      Height = 21
      TabOrder = 19
      Text = '0'
      OnExit = edtOFDMTxOutputPowerOffsetCheck
    end
    object m_edtOFDMTxOutputPowerOffset3: TEdit
      Tag = 3
      Left = 272
      Top = 64
      Width = 32
      Height = 21
      TabOrder = 20
      Text = '0'
      OnExit = edtOFDMTxOutputPowerOffsetCheck
    end
    object m_edtOFDMTxOutputPowerOffset4: TEdit
      Tag = 4
      Left = 312
      Top = 64
      Width = 32
      Height = 21
      TabOrder = 21
      Text = '0'
      OnExit = edtOFDMTxOutputPowerOffsetCheck
    end
    object m_edtOFDMTxOutputPowerOffset5: TEdit
      Tag = 5
      Left = 352
      Top = 64
      Width = 32
      Height = 21
      TabOrder = 22
      Text = '0'
      OnExit = edtOFDMTxOutputPowerOffsetCheck
    end
    object m_edtOFDMTxOutputPowerOffset6: TEdit
      Tag = 6
      Left = 392
      Top = 64
      Width = 32
      Height = 21
      TabOrder = 23
      Text = '0'
      OnExit = edtOFDMTxOutputPowerOffsetCheck
    end
    object m_edtOFDMTxOutputPowerOffset7: TEdit
      Tag = 7
      Left = 432
      Top = 64
      Width = 32
      Height = 21
      TabOrder = 24
      Text = '0'
      OnExit = edtOFDMTxOutputPowerOffsetCheck
    end
  end
  object Panel4: TPanel
    Left = 8
    Top = 248
    Width = 673
    Height = 121
    BevelOuter = bvLowered
    TabOrder = 4
    object Label17: TLabel
      Left = 112
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '0'
    end
    object Label18: TLabel
      Left = 152
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '1'
    end
    object Label19: TLabel
      Left = 192
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '2'
    end
    object Label20: TLabel
      Left = 232
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '3'
    end
    object Label21: TLabel
      Left = 272
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '4'
    end
    object Label22: TLabel
      Left = 312
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '5'
    end
    object Label23: TLabel
      Left = 352
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '6'
    end
    object Label24: TLabel
      Left = 392
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '7'
    end
    object Label25: TLabel
      Left = 432
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '8'
    end
    object Label26: TLabel
      Left = 472
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '9'
    end
    object Label27: TLabel
      Left = 512
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '10'
    end
    object Label28: TLabel
      Left = 552
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '11'
    end
    object Label31: TLabel
      Left = 592
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '12'
    end
    object Label32: TLabel
      Left = 632
      Top = 44
      Width = 32
      Height = 13
      Alignment = taCenter
      AutoSize = False
      Caption = '13'
    end
    object Label33: TLabel
      Left = 70
      Top = 64
      Width = 37
      Height = 13
      Caption = 'TX ALC'
    end
    object Label34: TLabel
      Left = 8
      Top = 88
      Width = 100
      Height = 13
      Caption = 'TX Output Power DB'
    end
    object m_pnlOFDMTxRate: TPanel
      Left = 8
      Top = 16
      Width = 121
      Height = 25
      BevelOuter = bvSpace
      Caption = 'TX Rate 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object m_edtTxAlcOFDM00: TEdit
      Left = 112
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 1
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM01: TEdit
      Tag = 1
      Left = 152
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 2
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM02: TEdit
      Tag = 2
      Left = 192
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 3
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM03: TEdit
      Tag = 3
      Left = 232
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 4
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM06: TEdit
      Tag = 6
      Left = 352
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 5
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM07: TEdit
      Tag = 7
      Left = 392
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 6
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM09: TEdit
      Tag = 9
      Left = 472
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 7
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object Edit8: TEdit
      Left = 744
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 8
      Text = 'Edit8'
    end
    object m_edtTxAlcOFDM04: TEdit
      Tag = 4
      Left = 272
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 9
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM05: TEdit
      Tag = 5
      Left = 312
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 10
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM08: TEdit
      Tag = 8
      Left = 432
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 11
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM10: TEdit
      Tag = 10
      Left = 512
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 12
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM11: TEdit
      Tag = 11
      Left = 552
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 13
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM12: TEdit
      Tag = 12
      Left = 592
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 14
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxAlcOFDM13: TEdit
      Tag = 13
      Left = 632
      Top = 60
      Width = 32
      Height = 21
      TabOrder = 15
      Text = '0'
      OnExit = edtTxAlcOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM01: TEdit
      Tag = 1
      Left = 152
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 16
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM02: TEdit
      Tag = 2
      Left = 192
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 17
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM03: TEdit
      Tag = 3
      Left = 232
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 18
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM04: TEdit
      Tag = 4
      Left = 272
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 19
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM05: TEdit
      Tag = 5
      Left = 312
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 20
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM06: TEdit
      Tag = 6
      Left = 352
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 21
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM07: TEdit
      Tag = 7
      Left = 392
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 22
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM08: TEdit
      Tag = 8
      Left = 432
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 23
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM09: TEdit
      Tag = 9
      Left = 472
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 24
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM10: TEdit
      Tag = 10
      Left = 512
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 25
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM11: TEdit
      Tag = 11
      Left = 552
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 26
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM12: TEdit
      Tag = 12
      Left = 592
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 27
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM13: TEdit
      Tag = 13
      Left = 632
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 28
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
    object m_edtTxOutputPowerDbOFDM00: TEdit
      Left = 112
      Top = 88
      Width = 32
      Height = 21
      TabOrder = 29
      Text = '0'
      OnExit = edtTxOutputPowerDbOFDMCheck
    end
  end
  object btnUploadFromFlash: TButton
    Left = 8
    Top = 472
    Width = 100
    Height = 25
    Caption = 'Upload from flash'
    TabOrder = 5
    OnClick = btnUploadFromFlashClick
  end
  object btnDownloadToFlash: TButton
    Left = 120
    Top = 472
    Width = 100
    Height = 25
    Caption = 'Download to flash'
    TabOrder = 6
    OnClick = btnDownloadToFlashClick
  end
  object btnChangeDB: TButton
    Left = 232
    Top = 472
    Width = 105
    Height = 25
    Caption = 'Change NVRAM DB'
    TabOrder = 7
    OnClick = btnChangeDBClick
  end
  object btnLoadFromFile: TButton
    Left = 344
    Top = 472
    Width = 80
    Height = 25
    Caption = 'Load fom file'
    TabOrder = 8
    OnClick = btnLoadFromFileClick
  end
  object btnSaveToFile: TButton
    Left = 432
    Top = 472
    Width = 80
    Height = 25
    Caption = 'Save to file'
    TabOrder = 9
    OnClick = btnSaveToFileClick
  end
  object m_sbALC: TStatusBar
    Left = 0
    Top = 499
    Width = 688
    Height = 28
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object lblHint: TStaticText
    Left = 384
    Top = 0
    Width = 33
    Height = 17
    BorderStyle = sbsSingle
    Caption = 'lblHint'
    Color = clYellow
    ParentColor = False
    TabOrder = 11
    Visible = False
  end
  object Panel3: TPanel
    Left = 8
    Top = 384
    Width = 153
    Height = 25
    BevelOuter = bvLowered
    Caption = 'ALC Slope'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 12
  end
  object Panel7: TPanel
    Left = 8
    Top = 408
    Width = 673
    Height = 57
    BevelOuter = bvLowered
    TabOrder = 13
    object Label36: TLabel
      Left = 32
      Top = 8
      Width = 80
      Height = 13
      Caption = 'ALCSlop1Divider'
    end
    object Label37: TLabel
      Left = 158
      Top = 8
      Width = 89
      Height = 13
      Caption = 'ALCSlop1Dividend'
    end
    object TLabel
      Left = 296
      Top = 8
      Width = 80
      Height = 13
      Caption = 'ALCSlop2Divider'
    end
    object Label39: TLabel
      Left = 434
      Top = 8
      Width = 89
      Height = 13
      Caption = 'ALCSlop2Dividend'
    end
    object m_edtALCSlop1Divider: TEdit
      Left = 32
      Top = 24
      Width = 81
      Height = 21
      TabOrder = 0
      Text = '10'
      OnExit = m_edtALCSlopDividerCheck
    end
    object m_edtALCSlop1Dividend: TEdit
      Left = 160
      Top = 24
      Width = 81
      Height = 21
      TabOrder = 1
      Text = '1'
      OnExit = m_edtALCSlopDividendCheck
    end
    object m_edtALCSlop2Divider: TEdit
      Tag = 1
      Left = 296
      Top = 24
      Width = 81
      Height = 21
      TabOrder = 2
      Text = '15'
      OnExit = m_edtALCSlopDividerCheck
    end
    object m_edtALCSlop2Dividend: TEdit
      Tag = 1
      Left = 440
      Top = 24
      Width = 81
      Height = 21
      TabOrder = 3
      Text = '10'
      OnExit = m_edtALCSlopDividendCheck
    end
  end
  object m_btnLoadFromEEPROM: TButton
    Left = 520
    Top = 472
    Width = 105
    Height = 25
    Caption = 'Load from EEPROM'
    TabOrder = 14
    OnClick = m_btnLoadFromEEPROMClick
  end
  object HintTimer: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = HintTimerTimer
    Left = 336
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Save to ini file'
    Left = 440
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'ini'
    Filter = 
      'Ini file (*.ini)|*.ini|Cal file (*.cal)|*.cal|All files (*.*)|*.' +
      '*'
    InitialDir = '.'
    Title = 'Open ini file'
    Left = 488
  end
end
