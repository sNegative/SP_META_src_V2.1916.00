object frmHdcpKey: TfrmHdcpKey
  Left = 432
  Top = 461
  Width = 576
  Height = 117
  Caption = 'HDCP Key Tool'
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
  object Label1: TLabel
    Left = 8
    Top = 43
    Width = 50
    Height = 17
    Alignment = taCenter
    AutoSize = False
    Caption = '0-15'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label2: TLabel
    Left = 8
    Top = 119
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '64-79'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label3: TLabel
    Left = 8
    Top = 62
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '16-31'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label4: TLabel
    Left = 8
    Top = 81
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '32-47'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label5: TLabel
    Left = 8
    Top = 100
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '48-63'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label6: TLabel
    Left = 8
    Top = 138
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '80-95'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label7: TLabel
    Left = 8
    Top = 157
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '96-111'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label8: TLabel
    Left = 8
    Top = 176
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '112-127'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label9: TLabel
    Left = 8
    Top = 195
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '128-143'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label10: TLabel
    Left = 8
    Top = 214
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '144-159'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label11: TLabel
    Left = 8
    Top = 233
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '160-175'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label12: TLabel
    Left = 8
    Top = 252
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '176-191'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label13: TLabel
    Left = 8
    Top = 271
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '192-207'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label14: TLabel
    Left = 8
    Top = 290
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '208-223'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label15: TLabel
    Left = 8
    Top = 309
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '224-239'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label16: TLabel
    Left = 8
    Top = 328
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '240-255'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label17: TLabel
    Left = 8
    Top = 347
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '256-271'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label18: TLabel
    Left = 8
    Top = 363
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = '272-286'
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object btnUploadHDCPFromFlash: TButton
    Left = 8
    Top = 16
    Width = 105
    Height = 25
    Caption = 'Upload from flash'
    Enabled = False
    TabOrder = 0
    OnClick = btnUploadHDCPFromFlashClick
  end
  object btnDownloadHDCPToFlash: TButton
    Left = 118
    Top = 16
    Width = 105
    Height = 25
    Caption = 'Download to flash'
    Enabled = False
    TabOrder = 1
    OnClick = btnDownloadHDCPToFlashClick
  end
  object btnHDCPSetChangeDB: TButton
    Left = 228
    Top = 16
    Width = 111
    Height = 25
    Caption = 'Change NVRAM DB'
    TabOrder = 2
    OnClick = btnHDCPSetChangeDBClick
  end
  object btnLoadHDCPFromFile: TButton
    Left = 346
    Top = 16
    Width = 137
    Height = 25
    Caption = 'Load Unencrypted Key File '
    Enabled = False
    TabOrder = 3
    OnClick = btnLoadHDCPFromFileClick
  end
  object btnHDCPVerify: TButton
    Left = 496
    Top = 16
    Width = 57
    Height = 25
    Caption = 'Verify'
    Enabled = False
    TabOrder = 4
    OnClick = btnHDCPVerifyClick
  end
  object m_sbHDCPMain: TStatusBar
    Left = 0
    Top = 55
    Width = 568
    Height = 28
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object Memo1: TMemo
    Left = 72
    Top = 56
    Width = 241
    Height = 17
    ReadOnly = True
    TabOrder = 6
    Visible = False
  end
  object m_dlgOpenDB: TOpenDialog
    Title = 'Open NVRAM database file'
    Left = 99
    Top = 739
  end
  object m_dlgOpenHDCPKeyFile: TOpenDialog
    InitialDir = '.'
    Left = 393
    Top = 739
  end
end
