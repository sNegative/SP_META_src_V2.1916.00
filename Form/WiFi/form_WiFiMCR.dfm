object frmWiFiMCR: TfrmWiFiMCR
  Left = 27
  Top = 57
  Width = 931
  Height = 661
  Caption = 'WiFi MAC Control Register Editor'
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
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 913
    Height = 553
    ActivePage = TabSheet1
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'System Control'
      object Shape1: TShape
        Left = 352
        Top = 12
        Width = 9
        Height = 9
        Brush.Color = clMaroon
      end
      object Label40: TLabel
        Left = 368
        Top = 10
        Width = 48
        Height = 13
        Caption = 'Read only'
      end
      object pnlSC: TPanel
        Left = 0
        Top = 8
        Width = 225
        Height = 25
        BevelOuter = bvLowered
        Caption = 'System Control'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object Panel2: TPanel
          Left = 0
          Top = 40
          Width = 185
          Height = 41
          Caption = 'Panel2'
          TabOrder = 0
        end
        object cbSCHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 17
          Height = 17
          TabOrder = 1
          OnClick = cbSCHeaderClick
        end
      end
      object Panel3: TPanel
        Left = 0
        Top = 32
        Width = 905
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 1
        object lblSC0: TLabel
          Left = 32
          Top = 8
          Width = 22
          Height = 13
          Caption = 'SCR'
        end
        object lblSC1: TLabel
          Tag = 1
          Left = 96
          Top = 8
          Width = 31
          Height = 13
          Caption = 'MRBS'
        end
        object lblSC2: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 33
          Height = 13
          Caption = 'DEVID'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object lblSC3: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 41
          Height = 13
          Caption = 'GPIOCR'
        end
        object edtSC0: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtSCCheck
        end
        object edtSC1: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtSCCheck
        end
        object edtSC2: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          ReadOnly = True
          TabOrder = 2
          Text = '0'
          OnExit = edtSCCheck
        end
        object edtSC3: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtSCCheck
        end
        object cbSC0: TCheckBox
          Left = 8
          Top = 6
          Width = 17
          Height = 17
          TabOrder = 4
        end
        object cbSC1: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 17
          Height = 17
          TabOrder = 5
        end
        object cbSC2: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 17
          Height = 17
          TabOrder = 6
        end
        object cbSC3: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 17
          Height = 17
          TabOrder = 7
        end
      end
      object pnlMDP: TPanel
        Left = 0
        Top = 96
        Width = 225
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Miscellaneous and Debug Port'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        object cbMDPHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 17
          Height = 17
          TabOrder = 0
          OnClick = cbMDPHeaderClick
        end
      end
      object Panel5: TPanel
        Left = 0
        Top = 120
        Width = 905
        Height = 97
        BevelOuter = bvLowered
        TabOrder = 3
        object lblMDP00: TLabel
          Left = 24
          Top = 8
          Width = 37
          Height = 13
          Caption = 'PRBCR'
        end
        object lblMDP01: TLabel
          Tag = 1
          Left = 96
          Top = 8
          Width = 37
          Height = 13
          Caption = 'PRBSR'
        end
        object lblMDP02: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 40
          Height = 13
          Caption = 'PFWDR'
        end
        object lblMDP03: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 38
          Height = 13
          Caption = 'PRBDR'
        end
        object lblMDP04: TLabel
          Tag = 4
          Left = 312
          Top = 8
          Width = 35
          Height = 13
          Caption = 'CTPR1'
        end
        object lblMDP05: TLabel
          Tag = 5
          Left = 392
          Top = 8
          Width = 23
          Height = 13
          Caption = 'QCR'
        end
        object lblMDP06: TLabel
          Tag = 6
          Left = 464
          Top = 8
          Width = 25
          Height = 13
          Caption = 'ISAR'
        end
        object lblMDP07: TLabel
          Tag = 7
          Left = 536
          Top = 8
          Width = 18
          Height = 13
          Caption = 'IER'
        end
        object lblMDP08: TLabel
          Tag = 8
          Left = 600
          Top = 8
          Width = 40
          Height = 13
          Caption = 'DRNGR'
        end
        object lblMDP09: TLabel
          Tag = 9
          Left = 672
          Top = 8
          Width = 31
          Height = 13
          Caption = 'AIFSR'
        end
        object lblMDP10: TLabel
          Tag = 10
          Left = 736
          Top = 8
          Width = 41
          Height = 13
          Caption = 'TQCWR'
        end
        object lblMDP11: TLabel
          Tag = 11
          Left = 816
          Top = 8
          Width = 46
          Height = 13
          Caption = 'AC0CWR'
        end
        object lblMDP12: TLabel
          Tag = 12
          Left = 24
          Top = 48
          Width = 46
          Height = 13
          Caption = 'AC1CWR'
        end
        object lblMDP13: TLabel
          Tag = 13
          Left = 96
          Top = 48
          Width = 46
          Height = 13
          Caption = 'AC2CWR'
        end
        object lblMDP14: TLabel
          Tag = 14
          Left = 168
          Top = 48
          Width = 46
          Height = 13
          Caption = 'AC3CWR'
        end
        object lblMDP15: TLabel
          Tag = 15
          Left = 240
          Top = 48
          Width = 39
          Height = 13
          Caption = 'LNUIR0'
        end
        object lblMDP16: TLabel
          Tag = 16
          Left = 312
          Top = 48
          Width = 39
          Height = 13
          Caption = 'LNUIR1'
        end
        object lblMDP17: TLabel
          Tag = 17
          Left = 384
          Top = 48
          Width = 39
          Height = 13
          Caption = 'LNUIR2'
        end
        object edtMDP00: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP01: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP02: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP03: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP04: TEdit
          Tag = 4
          Left = 296
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP05: TEdit
          Tag = 5
          Left = 368
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP06: TEdit
          Tag = 6
          Left = 440
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP07: TEdit
          Tag = 7
          Left = 512
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP08: TEdit
          Tag = 8
          Left = 584
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 8
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP09: TEdit
          Tag = 9
          Left = 656
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 9
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP10: TEdit
          Tag = 10
          Left = 728
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 10
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP11: TEdit
          Tag = 11
          Left = 800
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 11
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP12: TEdit
          Tag = 12
          Left = 8
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 12
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP13: TEdit
          Tag = 13
          Left = 80
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 13
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP14: TEdit
          Tag = 14
          Left = 152
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 14
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP15: TEdit
          Tag = 15
          Left = 224
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 15
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP16: TEdit
          Tag = 16
          Left = 296
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 16
          Text = '0'
          OnExit = edtMDPCheck
        end
        object edtMDP17: TEdit
          Tag = 17
          Left = 368
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 17
          Text = '0'
          OnExit = edtMDPCheck
        end
        object cbMDP00: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 18
        end
        object cbMDP01: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 19
        end
        object cbMDP02: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 20
        end
        object cbMDP03: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 21
        end
        object cbMDP04: TCheckBox
          Tag = 4
          Left = 296
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 22
        end
        object cbMDP05: TCheckBox
          Tag = 5
          Left = 368
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 23
        end
        object cbMDP06: TCheckBox
          Tag = 6
          Left = 440
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 24
        end
        object cbMDP07: TCheckBox
          Tag = 7
          Left = 512
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 25
        end
        object cbMDP08: TCheckBox
          Tag = 8
          Left = 584
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 26
        end
        object cbMDP09: TCheckBox
          Tag = 9
          Left = 656
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 27
        end
        object cbMDP10: TCheckBox
          Tag = 10
          Left = 728
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 28
        end
        object cbMDP11: TCheckBox
          Tag = 11
          Left = 800
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 29
        end
        object cbMDP12: TCheckBox
          Tag = 12
          Left = 8
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbMDP12'
          TabOrder = 30
        end
        object cbMDP13: TCheckBox
          Tag = 13
          Left = 80
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbMDP13'
          TabOrder = 31
        end
        object cbMDP14: TCheckBox
          Tag = 14
          Left = 152
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbMDP14'
          TabOrder = 32
        end
        object cbMDP15: TCheckBox
          Tag = 15
          Left = 224
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbMDP15'
          TabOrder = 33
        end
        object cbMDP16: TCheckBox
          Tag = 16
          Left = 296
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbMDP16'
          TabOrder = 34
        end
        object cbMDP17: TCheckBox
          Tag = 17
          Left = 368
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbMDP17'
          TabOrder = 35
        end
      end
      object pnlPLCI: TPanel
        Left = 0
        Top = 224
        Width = 225
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Phyical Layer Control Interface'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        object Panel7: TPanel
          Left = 0
          Top = 40
          Width = 185
          Height = 41
          Caption = 'Panel7'
          TabOrder = 0
        end
        object cbPLCIHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 1
          OnClick = cbPLCIHeaderClick
        end
      end
      object Panel8: TPanel
        Left = 0
        Top = 248
        Width = 905
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 5
        object lblPLCI00: TLabel
          Left = 32
          Top = 8
          Width = 32
          Height = 13
          Caption = 'PCICR'
        end
        object lblPLCI01: TLabel
          Tag = 1
          Left = 104
          Top = 8
          Width = 29
          Height = 13
          Caption = 'PBAR'
        end
        object lblPLCI02: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 51
          Height = 13
          Caption = 'PPORCR0'
        end
        object lblPLCI03: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 51
          Height = 13
          Caption = 'PPORCR1'
        end
        object lblPLCI04: TLabel
          Tag = 4
          Left = 312
          Top = 8
          Width = 51
          Height = 13
          Caption = 'PPDRCR0'
        end
        object lblPLCI05: TLabel
          Tag = 5
          Left = 384
          Top = 8
          Width = 51
          Height = 13
          Caption = 'PPDRCR1'
        end
        object lblPLCI06: TLabel
          Tag = 6
          Left = 456
          Top = 8
          Width = 51
          Height = 13
          Caption = 'PPDRCR2'
        end
        object lblPLCI07: TLabel
          Tag = 7
          Left = 528
          Top = 8
          Width = 38
          Height = 13
          Caption = 'PPMCR'
        end
        object lblPLCI08: TLabel
          Tag = 8
          Left = 608
          Top = 8
          Width = 29
          Height = 13
          Caption = 'PSCR'
        end
        object lblPLCI09: TLabel
          Tag = 9
          Left = 680
          Top = 8
          Width = 29
          Height = 13
          Caption = 'PSPR'
        end
        object lblPLCI10: TLabel
          Tag = 10
          Left = 752
          Top = 8
          Width = 21
          Height = 13
          Caption = 'LCR'
        end
        object lblPLCI11: TLabel
          Tag = 11
          Left = 824
          Top = 8
          Width = 22
          Height = 13
          Caption = 'ACR'
        end
        object edtPLCI00: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI01: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI02: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI03: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI04: TEdit
          Tag = 4
          Left = 296
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI05: TEdit
          Tag = 5
          Left = 368
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI06: TEdit
          Tag = 6
          Left = 440
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI07: TEdit
          Tag = 7
          Left = 512
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI08: TEdit
          Tag = 8
          Left = 584
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 8
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI09: TEdit
          Tag = 9
          Left = 656
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 9
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI10: TEdit
          Tag = 10
          Left = 728
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 10
          Text = '0'
          OnExit = edtPLCICheck
        end
        object edtPLCI11: TEdit
          Tag = 11
          Left = 800
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 11
          Text = '0'
          OnExit = edtPLCICheck
        end
        object cbPLCI00: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 12
        end
        object cbPLCI01: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 13
        end
        object cbPLCI02: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 14
        end
        object cbPLCI03: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI03'
          TabOrder = 15
        end
        object cbPLCI04: TCheckBox
          Tag = 4
          Left = 296
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI04'
          TabOrder = 16
        end
        object cbPLCI05: TCheckBox
          Tag = 5
          Left = 368
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI05'
          TabOrder = 17
        end
        object cbPLCI06: TCheckBox
          Tag = 6
          Left = 440
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI06'
          TabOrder = 18
        end
        object cbPLCI07: TCheckBox
          Tag = 7
          Left = 512
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI07'
          TabOrder = 19
        end
        object cbPLCI08: TCheckBox
          Tag = 8
          Left = 584
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI08'
          TabOrder = 20
        end
        object cbPLCI09: TCheckBox
          Tag = 9
          Left = 656
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI09'
          TabOrder = 21
        end
        object cbPLCI10: TCheckBox
          Tag = 10
          Left = 728
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI10'
          TabOrder = 22
        end
        object cbPLCI11: TCheckBox
          Tag = 11
          Left = 800
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbPLCI11'
          TabOrder = 23
        end
      end
      object pnlMPTC: TPanel
        Left = 0
        Top = 312
        Width = 225
        Height = 25
        BevelOuter = bvLowered
        Caption = 'MAC Protocol Timing Control'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        object cbMPTCHeader: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbMPTCHeaderClick
        end
      end
      object Panel10: TPanel
        Left = 0
        Top = 336
        Width = 905
        Height = 97
        BevelOuter = bvLowered
        TabOrder = 7
        object lblMPTC00: TLabel
          Left = 24
          Top = 8
          Width = 33
          Height = 13
          Caption = 'CWBR'
        end
        object lblMPTC01: TLabel
          Tag = 1
          Left = 104
          Top = 8
          Width = 31
          Height = 13
          Caption = 'MPTR'
        end
        object lblMPTC02: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 32
          Height = 13
          Caption = 'MPDR'
        end
        object lblMPTC03: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 38
          Height = 13
          Caption = 'TNTDR'
        end
        object lblMPTC04: TLabel
          Tag = 4
          Left = 320
          Top = 8
          Width = 30
          Height = 13
          Caption = 'STDR'
        end
        object lblMPTC05: TLabel
          Tag = 5
          Left = 384
          Top = 8
          Width = 38
          Height = 13
          Caption = 'EPDDR'
        end
        object lblMPTC06: TLabel
          Tag = 6
          Left = 456
          Top = 8
          Width = 42
          Height = 13
          Caption = 'CRFCR0'
        end
        object lblMPTC07: TLabel
          Tag = 7
          Left = 528
          Top = 8
          Width = 42
          Height = 13
          Caption = 'CRFCR1'
        end
        object lblMPTC08: TLabel
          Tag = 8
          Left = 608
          Top = 8
          Width = 23
          Height = 13
          Caption = 'DTR'
        end
        object lblMPTC09: TLabel
          Tag = 9
          Left = 672
          Top = 8
          Width = 33
          Height = 13
          Caption = 'BCWR'
        end
        object lblMPTC10: TLabel
          Tag = 10
          Left = 744
          Top = 8
          Width = 43
          Height = 13
          Caption = 'RFTPCR'
        end
        object lblMPTC11: TLabel
          Tag = 11
          Left = 816
          Top = 8
          Width = 34
          Height = 13
          Caption = 'LTTR0'
        end
        object lblMPTC12: TLabel
          Tag = 12
          Left = 24
          Top = 48
          Width = 34
          Height = 13
          Caption = 'LTTR1'
        end
        object lblMPTC13: TLabel
          Tag = 13
          Left = 96
          Top = 48
          Width = 35
          Height = 13
          Caption = 'TTAR0'
        end
        object lblMPTC14: TLabel
          Tag = 14
          Left = 168
          Top = 48
          Width = 35
          Height = 13
          Caption = 'TTAR1'
        end
        object lblMPTC15: TLabel
          Tag = 15
          Left = 240
          Top = 48
          Width = 35
          Height = 13
          Caption = 'TTAR2'
        end
        object lblMPTC16: TLabel
          Tag = 16
          Left = 312
          Top = 48
          Width = 35
          Height = 13
          Caption = 'TTSCS'
        end
        object lblMPTC17: TLabel
          Tag = 17
          Left = 384
          Top = 48
          Width = 28
          Height = 13
          Caption = 'TTTC'
        end
        object edtMPTC00: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC01: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC02: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC03: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC04: TEdit
          Tag = 4
          Left = 296
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC05: TEdit
          Tag = 5
          Left = 368
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC06: TEdit
          Tag = 6
          Left = 440
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC07: TEdit
          Tag = 7
          Left = 512
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC08: TEdit
          Tag = 8
          Left = 584
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 8
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC09: TEdit
          Tag = 9
          Left = 656
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 9
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC10: TEdit
          Tag = 10
          Left = 728
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 10
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC11: TEdit
          Tag = 11
          Left = 800
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 11
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC12: TEdit
          Tag = 12
          Left = 8
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 12
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC13: TEdit
          Tag = 13
          Left = 80
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 13
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC14: TEdit
          Tag = 14
          Left = 152
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 14
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC15: TEdit
          Tag = 15
          Left = 224
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 15
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC16: TEdit
          Tag = 16
          Left = 296
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 16
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object edtMPTC17: TEdit
          Tag = 17
          Left = 368
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 17
          Text = '0'
          OnExit = edtMPTCCheck
        end
        object cbMPTC00: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 18
        end
        object cbMPTC01: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 19
        end
        object cbMPTC02: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 20
        end
        object cbMPTC03: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 21
        end
        object CheckBox42: TCheckBox
          Left = 296
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 22
        end
        object CheckBox43: TCheckBox
          Left = 368
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 23
        end
        object cbMPTC06: TCheckBox
          Tag = 6
          Left = 440
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 24
        end
        object cbMPTC07: TCheckBox
          Tag = 7
          Left = 512
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 25
        end
        object cbMPTC08: TCheckBox
          Tag = 8
          Left = 584
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 26
        end
        object cbMPTC09: TCheckBox
          Tag = 9
          Left = 656
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 27
        end
        object cbMPTC10: TCheckBox
          Tag = 10
          Left = 728
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 28
        end
        object cbMPTC11: TCheckBox
          Tag = 11
          Left = 800
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 29
        end
        object cbMPTC12: TCheckBox
          Tag = 12
          Left = 8
          Top = 46
          Width = 15
          Height = 17
          TabOrder = 30
        end
        object cbMPTC13: TCheckBox
          Tag = 13
          Left = 80
          Top = 46
          Width = 15
          Height = 17
          TabOrder = 31
        end
        object cbMPTC14: TCheckBox
          Tag = 14
          Left = 152
          Top = 46
          Width = 15
          Height = 17
          TabOrder = 32
        end
        object cbMPTC15: TCheckBox
          Tag = 15
          Left = 224
          Top = 46
          Width = 15
          Height = 17
          TabOrder = 33
        end
        object cbMPTC04: TCheckBox
          Tag = 4
          Left = 296
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 34
        end
        object cbMPTC05: TCheckBox
          Tag = 5
          Left = 368
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 35
        end
        object cbMPTC16: TCheckBox
          Tag = 16
          Left = 296
          Top = 46
          Width = 15
          Height = 17
          TabOrder = 36
        end
        object cbMPTC17: TCheckBox
          Tag = 17
          Left = 368
          Top = 46
          Width = 15
          Height = 17
          TabOrder = 37
        end
      end
      object pnlNC: TPanel
        Left = 0
        Top = 440
        Width = 225
        Height = 25
        BevelOuter = bvLowered
        Caption = 'NVA Control'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 8
        object cbNCHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbNCHeaderClick
        end
      end
      object Panel12: TPanel
        Left = 0
        Top = 464
        Width = 305
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 9
        object lblNC0: TLabel
          Left = 32
          Top = 8
          Width = 22
          Height = 13
          Caption = 'LNR'
        end
        object lblNC1: TLabel
          Tag = 1
          Left = 96
          Top = 8
          Width = 31
          Height = 13
          Caption = 'NRTR'
        end
        object lblNC2: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 31
          Height = 13
          Caption = 'NSUR'
        end
        object lblNC3: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 24
          Height = 13
          Caption = 'TTIC'
        end
        object edtNC0: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtNCCheck
        end
        object edtNC1: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtNCCheck
        end
        object edtNC2: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtNCCheck
        end
        object edtNC3: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtNCCheck
        end
        object cbNC0: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 4
        end
        object cbNC1: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 5
        end
        object cbNC2: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 6
        end
        object cbNC3: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 15
          Height = 17
          Caption = 'cbNC3'
          TabOrder = 7
        end
      end
      object pnlBG: TPanel
        Left = 312
        Top = 440
        Width = 225
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Beacon Generation'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 10
        object cbBGHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbBGHeaderClick
        end
      end
      object Panel14: TPanel
        Left = 312
        Top = 464
        Width = 593
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 11
        object lblBG0: TLabel
          Left = 24
          Top = 8
          Width = 36
          Height = 13
          Caption = 'BGCR0'
        end
        object lblBG1: TLabel
          Tag = 1
          Left = 96
          Top = 8
          Width = 36
          Height = 13
          Caption = 'BGCR1'
        end
        object lblBG2: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 47
          Height = 13
          Caption = 'SWBCCR'
        end
        object lblBG3: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 48
          Height = 13
          Caption = 'SWBCDR'
        end
        object lblBG4: TLabel
          Tag = 4
          Left = 312
          Top = 8
          Width = 38
          Height = 13
          Caption = 'ARRCR'
        end
        object lblBG5: TLabel
          Tag = 5
          Left = 384
          Top = 8
          Width = 36
          Height = 13
          Caption = 'AFRCR'
        end
        object lblBG6: TLabel
          Tag = 6
          Left = 456
          Top = 8
          Width = 35
          Height = 13
          Caption = 'ATFCR'
        end
        object lblBG7: TLabel
          Tag = 7
          Left = 528
          Top = 8
          Width = 36
          Height = 13
          Caption = 'ATBCR'
        end
        object edtBG0: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtBGCheck
        end
        object edtBG1: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtBGCheck
        end
        object edtBG2: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtBGCheck
        end
        object edtBG3: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtBGCheck
        end
        object edtBG4: TEdit
          Tag = 4
          Left = 296
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtBGCheck
        end
        object edtBG5: TEdit
          Tag = 5
          Left = 368
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtBGCheck
        end
        object edtBG6: TEdit
          Tag = 6
          Left = 440
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtBGCheck
        end
        object edtBG7: TEdit
          Tag = 7
          Left = 512
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtBGCheck
        end
        object cbBG0: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 8
        end
        object cbBG1: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 9
        end
        object cbBG2: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 10
        end
        object cbBG3: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 11
        end
        object cbBG4: TCheckBox
          Tag = 4
          Left = 296
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 12
        end
        object cbBG5: TCheckBox
          Tag = 5
          Left = 368
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 13
        end
        object cbBG6: TCheckBox
          Tag = 6
          Left = 440
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 14
        end
        object cbBG7: TCheckBox
          Tag = 7
          Left = 512
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 15
        end
      end
      object btnSYSMACMCRData: TButton
        Tag = 1
        Left = 246
        Top = 2
        Width = 89
        Height = 23
        Caption = 'MCR Data (Hex)'
        TabOrder = 12
        OnClick = btnSYSMACMCRDataClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TX/RX Releated'
      ImageIndex = 1
      object Label41: TLabel
        Left = 328
        Top = 10
        Width = 48
        Height = 13
        Caption = 'Read only'
      end
      object Shape3: TShape
        Left = 312
        Top = 12
        Width = 9
        Height = 9
        Brush.Color = clMaroon
      end
      object Label1: TLabel
        Left = 552
        Top = 8
        Width = 12
        Height = 13
        Caption = '__'
      end
      object Label2: TLabel
        Left = 568
        Top = 10
        Width = 31
        Height = 13
        Caption = '16 bits'
      end
      object Shape4: TShape
        Left = 448
        Top = 12
        Width = 9
        Height = 9
        Brush.Color = clGreen
      end
      object Label3: TLabel
        Left = 464
        Top = 10
        Width = 20
        Height = 13
        Caption = 'R/C'
      end
      object pnlSE: TPanel
        Left = 0
        Top = 8
        Width = 185
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Security Engine'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object cbSEHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbSEHeaderClick
        end
      end
      object Panel16: TPanel
        Left = 0
        Top = 32
        Width = 905
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 1
        object lblSE00: TLabel
          Left = 24
          Top = 8
          Width = 36
          Height = 13
          Caption = 'SKACR'
        end
        object lblSE01: TLabel
          Tag = 1
          Left = 96
          Top = 8
          Width = 43
          Height = 13
          Caption = 'SKADR0'
        end
        object lblSE02: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 43
          Height = 13
          Caption = 'SKADR1'
        end
        object lblSE03: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 43
          Height = 13
          Caption = 'SKADR2'
        end
        object lblSE04: TLabel
          Tag = 4
          Left = 312
          Top = 8
          Width = 43
          Height = 13
          Caption = 'SKADR3'
        end
        object lblSE05: TLabel
          Tag = 5
          Left = 384
          Top = 8
          Width = 43
          Height = 13
          Caption = 'SKADR4'
        end
        object lblSE06: TLabel
          Tag = 6
          Left = 456
          Top = 8
          Width = 43
          Height = 13
          Caption = 'SKADR5'
        end
        object lblSE07: TLabel
          Tag = 7
          Left = 528
          Top = 8
          Width = 35
          Height = 13
          Caption = 'SCPR0'
        end
        object lblSE08: TLabel
          Tag = 8
          Left = 600
          Top = 8
          Width = 35
          Height = 13
          Caption = 'SCPR1'
        end
        object lblSE09: TLabel
          Tag = 9
          Left = 672
          Top = 8
          Width = 43
          Height = 13
          Caption = 'SKADR6'
        end
        object lblSE10: TLabel
          Tag = 10
          Left = 744
          Top = 8
          Width = 43
          Height = 13
          Caption = 'SKADR7'
        end
        object edtSE00: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE01: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE02: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE03: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE04: TEdit
          Tag = 4
          Left = 296
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE05: TEdit
          Tag = 5
          Left = 368
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE06: TEdit
          Tag = 6
          Left = 440
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE07: TEdit
          Tag = 7
          Left = 512
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE08: TEdit
          Tag = 8
          Left = 584
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 8
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE09: TEdit
          Tag = 9
          Left = 656
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 9
          Text = '0'
          OnExit = edtSECheck
        end
        object edtSE10: TEdit
          Tag = 10
          Left = 728
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 10
          Text = '0'
          OnExit = edtSECheck
        end
        object cbSE00: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 11
        end
        object cbSE01: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 12
        end
        object cbSE02: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 13
        end
        object cbSE03: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 14
        end
        object cbSE04: TCheckBox
          Tag = 4
          Left = 296
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 15
        end
        object cbSE05: TCheckBox
          Tag = 5
          Left = 368
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 16
        end
        object cbSE06: TCheckBox
          Tag = 6
          Left = 440
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 17
        end
        object cbSE07: TCheckBox
          Tag = 7
          Left = 512
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 18
        end
        object cbSE08: TCheckBox
          Tag = 8
          Left = 584
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 19
        end
        object cbSE09: TCheckBox
          Tag = 9
          Left = 656
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 20
        end
        object cbSE10: TCheckBox
          Tag = 10
          Left = 728
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 21
        end
      end
      object pnlTC: TPanel
        Left = 0
        Top = 96
        Width = 185
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Transmitter Control'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        object cbTCHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          Caption = 'cbTCHeader'
          TabOrder = 0
          OnClick = cbTCHeaderClick
        end
      end
      object Panel18: TPanel
        Left = 0
        Top = 120
        Width = 905
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 3
        object lblTC00: TLabel
          Left = 24
          Top = 8
          Width = 39
          Height = 13
          Caption = 'ACWLR'
        end
        object lblTC01: TLabel
          Tag = 1
          Left = 96
          Top = 8
          Width = 38
          Height = 13
          Caption = 'MPTCR'
        end
        object lblTC02: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 37
          Height = 13
          Caption = 'NPTCR'
        end
        object lblTC03: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 37
          Height = 13
          Caption = 'NTTCR'
        end
        object lblTC04: TLabel
          Tag = 4
          Left = 302
          Top = 8
          Width = 74
          Height = 13
          Caption = 'TXOPGBNTCR'
        end
        object lblTC05: TLabel
          Tag = 5
          Left = 392
          Top = 8
          Width = 38
          Height = 13
          Caption = 'NDTCR'
        end
        object lblTC06: TLabel
          Tag = 6
          Left = 456
          Top = 8
          Width = 44
          Height = 13
          Caption = 'NCSTCR'
        end
        object lblTC07: TLabel
          Tag = 7
          Left = 518
          Top = 8
          Width = 57
          Height = 13
          Caption = 'ACTXOPR0'
        end
        object lblTC08: TLabel
          Tag = 8
          Left = 592
          Top = 8
          Width = 57
          Height = 13
          Caption = 'ACTXOPR1'
        end
        object lblTC09: TLabel
          Tag = 9
          Left = 670
          Top = 8
          Width = 51
          Height = 13
          Caption = 'TSTGPCR'
        end
        object lblTC10: TLabel
          Tag = 10
          Left = 736
          Top = 8
          Width = 57
          Height = 13
          Caption = 'TSTNTCR0'
        end
        object lblTC11: TLabel
          Tag = 11
          Left = 814
          Top = 8
          Width = 57
          Height = 13
          Caption = 'TSTNTCR1'
        end
        object edtTC00: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC01: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC02: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC03: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC04: TEdit
          Tag = 4
          Left = 296
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC05: TEdit
          Tag = 5
          Left = 368
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC06: TEdit
          Tag = 6
          Left = 440
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC07: TEdit
          Tag = 7
          Left = 512
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC08: TEdit
          Tag = 8
          Left = 584
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 8
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC09: TEdit
          Tag = 9
          Left = 656
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 9
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC10: TEdit
          Tag = 10
          Left = 728
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 10
          Text = '0'
          OnExit = edtTCCheck
        end
        object edtTC11: TEdit
          Tag = 11
          Left = 800
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 11
          Text = '0'
          OnExit = edtTCCheck
        end
        object cbTC00: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 12
        end
        object cbTC11: TCheckBox
          Tag = 11
          Left = 800
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 13
        end
        object cbTC10: TCheckBox
          Tag = 10
          Left = 722
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 14
        end
        object cbTC09: TCheckBox
          Tag = 9
          Left = 656
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 15
        end
        object cbTC08: TCheckBox
          Tag = 8
          Left = 576
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 16
        end
        object cbTC07: TCheckBox
          Tag = 7
          Left = 504
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 17
        end
        object cbTC06: TCheckBox
          Tag = 6
          Left = 440
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 18
        end
        object cbTC05: TCheckBox
          Tag = 5
          Left = 376
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 19
        end
        object cbTC04: TCheckBox
          Tag = 4
          Left = 288
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 20
        end
        object cbTC03: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 21
        end
        object cbTC02: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 22
        end
        object cbTC01: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 23
        end
      end
      object pnlRC: TPanel
        Left = 0
        Top = 184
        Width = 185
        Height = 25
        BevelOuter = bvLowered
        Caption = 'Receiver Control'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        object cbRCHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbRCHeaderClick
        end
      end
      object Panel20: TPanel
        Left = 0
        Top = 208
        Width = 905
        Height = 97
        BevelOuter = bvLowered
        TabOrder = 5
        object lblRC00: TLabel
          Left = 24
          Top = 8
          Width = 31
          Height = 13
          Caption = 'DRCR'
        end
        object lblRC01: TLabel
          Tag = 1
          Left = 96
          Top = 8
          Width = 36
          Height = 13
          Caption = 'RFECR'
        end
        object lblRC02: TLabel
          Tag = 2
          Left = 168
          Top = 8
          Width = 35
          Height = 13
          Caption = 'RFFCR'
        end
        object lblRC03: TLabel
          Tag = 3
          Left = 240
          Top = 8
          Width = 30
          Height = 13
          Caption = 'RPCR'
        end
        object lblRC04: TLabel
          Tag = 4
          Left = 320
          Top = 8
          Width = 25
          Height = 13
          Caption = 'CICR'
        end
        object lblRC05: TLabel
          Tag = 5
          Left = 392
          Top = 8
          Width = 29
          Height = 13
          Caption = 'CACR'
        end
        object lblRC06: TLabel
          Tag = 6
          Left = 464
          Top = 8
          Width = 29
          Height = 13
          Caption = 'CATR'
        end
        object lblRC07: TLabel
          Tag = 7
          Left = 528
          Top = 8
          Width = 36
          Height = 13
          Caption = 'CSACR'
        end
        object lblRC08: TLabel
          Tag = 8
          Left = 600
          Top = 8
          Width = 36
          Height = 13
          Caption = 'RFBCR'
        end
        object lblRC09: TLabel
          Tag = 9
          Left = 672
          Top = 8
          Width = 38
          Height = 13
          Caption = 'OMAR0'
        end
        object lblRC10: TLabel
          Tag = 10
          Left = 744
          Top = 8
          Width = 38
          Height = 13
          Caption = 'OMAR1'
        end
        object lblRC11: TLabel
          Tag = 11
          Left = 816
          Top = 8
          Width = 28
          Height = 13
          Caption = 'CBR0'
        end
        object lblRC12: TLabel
          Tag = 12
          Left = 24
          Top = 48
          Width = 28
          Height = 13
          Caption = 'CBR1'
        end
        object lblRC13: TLabel
          Tag = 13
          Left = 96
          Top = 48
          Width = 37
          Height = 13
          Caption = 'AMAR0'
        end
        object lblRC14: TLabel
          Tag = 14
          Left = 168
          Top = 48
          Width = 37
          Height = 13
          Caption = 'AMAR1'
        end
        object edtRC00: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 0
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC01: TEdit
          Tag = 1
          Left = 80
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC02: TEdit
          Tag = 2
          Left = 152
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC03: TEdit
          Tag = 3
          Left = 224
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC04: TEdit
          Tag = 4
          Left = 296
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC05: TEdit
          Tag = 5
          Left = 368
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC06: TEdit
          Tag = 6
          Left = 440
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC07: TEdit
          Tag = 7
          Left = 512
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC08: TEdit
          Tag = 8
          Left = 584
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 8
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC09: TEdit
          Tag = 9
          Left = 656
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 9
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC10: TEdit
          Tag = 10
          Left = 728
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 10
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC11: TEdit
          Tag = 11
          Left = 800
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 11
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC12: TEdit
          Tag = 12
          Left = 8
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 12
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC13: TEdit
          Tag = 13
          Left = 80
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 13
          Text = '0'
          OnExit = edtRCCheck
        end
        object edtRC14: TEdit
          Tag = 14
          Left = 152
          Top = 64
          Width = 68
          Height = 21
          TabOrder = 14
          Text = '0'
          OnExit = edtRCCheck
        end
        object cbRC00: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 15
        end
        object cbRC01: TCheckBox
          Tag = 1
          Left = 80
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 16
        end
        object cbRC02: TCheckBox
          Tag = 2
          Left = 152
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 17
        end
        object cbRC03: TCheckBox
          Tag = 3
          Left = 224
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 18
        end
        object cbRC04: TCheckBox
          Tag = 4
          Left = 296
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 19
        end
        object cbRC05: TCheckBox
          Tag = 5
          Left = 368
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 20
        end
        object cbRC06: TCheckBox
          Tag = 6
          Left = 440
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 21
        end
        object cbRC07: TCheckBox
          Tag = 7
          Left = 512
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 22
        end
        object cbRC08: TCheckBox
          Tag = 8
          Left = 584
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 23
        end
        object cbRC09: TCheckBox
          Tag = 9
          Left = 656
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 24
        end
        object cbRC10: TCheckBox
          Tag = 10
          Left = 728
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 25
        end
        object cbRC11: TCheckBox
          Tag = 11
          Left = 800
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 26
        end
        object cbRC12: TCheckBox
          Tag = 12
          Left = 8
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbRC12'
          TabOrder = 27
        end
        object cbRC13: TCheckBox
          Tag = 13
          Left = 80
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbRC13'
          TabOrder = 28
        end
        object cbRC14: TCheckBox
          Tag = 14
          Left = 152
          Top = 46
          Width = 15
          Height = 17
          Caption = 'cbRC14'
          TabOrder = 29
        end
      end
      object pnlHIFHeader: TPanel
        Left = 0
        Top = 312
        Width = 185
        Height = 25
        BevelOuter = bvLowered
        Caption = 'HIF_HPI'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        object cbHIFHeader: TCheckBox
          Left = 8
          Top = 4
          Width = 15
          Height = 17
          TabOrder = 0
          OnClick = cbHIFHeaderClick
        end
      end
      object Panel22: TPanel
        Left = 0
        Top = 336
        Width = 905
        Height = 57
        BevelOuter = bvLowered
        TabOrder = 7
        object lblHIF0: TLabel
          Left = 24
          Top = 8
          Width = 60
          Height = 13
          Caption = 'HPI_CHIPID'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clMaroon
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object lblHIF1: TLabel
          Tag = 1
          Left = 140
          Top = 8
          Width = 74
          Height = 13
          Caption = 'HPI_MAC_STS'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object lblHIF2: TLabel
          Tag = 2
          Left = 256
          Top = 8
          Width = 52
          Height = 13
          Caption = 'HPI_CTRL'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object lblHIF3: TLabel
          Tag = 3
          Left = 336
          Top = 8
          Width = 99
          Height = 13
          Caption = 'HPI_POWER_CTRL'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object lblHIF4: TLabel
          Tag = 4
          Left = 456
          Top = 8
          Width = 85
          Height = 13
          Caption = 'TX_DATA_PORT'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object lblHIF5: TLabel
          Tag = 5
          Left = 576
          Top = 8
          Width = 99
          Height = 13
          Caption = 'TX_STATUS_PORT'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object lblHIF6: TLabel
          Tag = 6
          Left = 696
          Top = 8
          Width = 100
          Height = 13
          Caption = 'RX_STATUS_PORT'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object lblHIF7: TLabel
          Tag = 7
          Left = 816
          Top = 8
          Width = 86
          Height = 13
          Caption = 'RX_DATA_PORT'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsUnderline]
          ParentFont = False
        end
        object edtHIF0: TEdit
          Left = 8
          Top = 24
          Width = 68
          Height = 21
          ReadOnly = True
          TabOrder = 0
          Text = '0'
          OnExit = edtHIFCheck
        end
        object edtHIF1: TEdit
          Tag = 1
          Left = 124
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 1
          Text = '0'
          OnExit = edtHIFCheck
        end
        object edtHIF2: TEdit
          Tag = 2
          Left = 241
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 2
          Text = '0'
          OnExit = edtHIFCheck
        end
        object edtHIF3: TEdit
          Tag = 3
          Left = 357
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 3
          Text = '0'
          OnExit = edtHIFCheck
        end
        object edtHIF4: TEdit
          Tag = 4
          Left = 474
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 4
          Text = '0'
          OnExit = edtHIFCheck
        end
        object edtHIF5: TEdit
          Tag = 5
          Left = 590
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 5
          Text = '0'
          OnExit = edtHIFCheck
        end
        object edtHIF6: TEdit
          Tag = 6
          Left = 707
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 6
          Text = '0'
          OnExit = edtHIFCheck
        end
        object edtHIF7: TEdit
          Tag = 7
          Left = 824
          Top = 24
          Width = 68
          Height = 21
          TabOrder = 7
          Text = '0'
          OnExit = edtHIFCheck
        end
        object cbHIF0: TCheckBox
          Left = 8
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 8
        end
        object cbHIF1: TCheckBox
          Tag = 1
          Left = 124
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 9
        end
        object cbHIF2: TCheckBox
          Tag = 2
          Left = 242
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 10
        end
        object cbHIF3: TCheckBox
          Tag = 3
          Left = 322
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 11
        end
        object cbHIF4: TCheckBox
          Tag = 4
          Left = 442
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 12
        end
        object cbHIF5: TCheckBox
          Tag = 5
          Left = 562
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 13
        end
        object cbHIF6: TCheckBox
          Tag = 6
          Left = 680
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 14
        end
        object cbHIF7: TCheckBox
          Tag = 7
          Left = 800
          Top = 6
          Width = 15
          Height = 17
          TabOrder = 15
        end
      end
      object btnTRXMACMCRData: TButton
        Tag = 1
        Left = 206
        Top = 2
        Width = 89
        Height = 23
        Caption = 'MCR Data (Hex)'
        TabOrder = 8
        OnClick = btnTRXMACMCRDataClick
      end
    end
  end
  object btnReadFromRegister: TButton
    Left = 21
    Top = 568
    Width = 100
    Height = 25
    Caption = 'Read from register'
    TabOrder = 1
    OnClick = btnReadFromRegisterClick
  end
  object btnWriteToRegister: TButton
    Left = 129
    Top = 568
    Width = 100
    Height = 25
    Caption = 'Write to register'
    TabOrder = 2
    OnClick = btnWriteToRegisterClick
  end
  object btnLoadFromFile: TButton
    Left = 238
    Top = 568
    Width = 80
    Height = 25
    Caption = 'Load fom file'
    TabOrder = 3
    OnClick = btnLoadFromFileClick
  end
  object btnSaveToFile: TButton
    Left = 324
    Top = 568
    Width = 80
    Height = 25
    Caption = 'Save to file'
    TabOrder = 4
    OnClick = btnSaveToFileClick
  end
  object sbWiFiMCR: TStatusBar
    Left = 0
    Top = 593
    Width = 923
    Height = 34
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
    TabOrder = 6
    Visible = False
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
