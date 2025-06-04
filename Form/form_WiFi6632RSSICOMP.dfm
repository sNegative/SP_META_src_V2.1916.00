object frm6632RSSICOMP: Tfrm6632RSSICOMP
  Left = 558
  Top = 143
  Width = 589
  Height = 688
  Caption = 'RSSI COMP.'
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
  object GroupBox6632RSSIComp: TGroupBox
    Left = 8
    Top = 10
    Width = 545
    Height = 567
    Caption = 'RSSI Compensation(dBm)'
    TabOrder = 0
    object GroupBox2GWF0: TGroupBox
      Left = 8
      Top = 24
      Width = 513
      Height = 121
      Caption = '2G WF0 RSSI'
      TabOrder = 0
      object m_lv2GWF0RSSI: TListView
        Left = 8
        Top = 48
        Width = 465
        Height = 65
        Columns = <
          item
            Caption = 'BAND'
            Width = 150
          end
          item
            Caption = 'offset(dBm)'
            Width = 200
          end>
        Items.Data = {
          2C0000000100000000000000FFFFFFFFFFFFFFFF01000000000000000B324720
          57463020525353490130FFFF}
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnAdvancedCustomDrawSubItem = m_lv2GWF0RSSIAdvancedCustomDrawSubItem
        OnClick = m_lv2GWF0RSSIClick
      end
      object m_edt2GWF0RSSI: TComboBox
        Left = 365
        Top = 92
        Width = 97
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 1
        Visible = False
        OnExit = m_edt2GWF0RSSIExit
        Items.Strings = (
          '-4'
          '-3.5'
          '-3'
          '-2.5'
          '-2'
          '-1.5'
          '-1'
          '-0.5'
          '0'
          '0.5'
          '1'
          '1.5'
          '2'
          '2.5'
          '3'
          '3.5')
      end
    end
    object m_cb2GWF0RSSI: TComboBox
      Left = 16
      Top = 44
      Width = 90
      Height = 21
      Style = csDropDownList
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 1
      Text = 'Enable'
      Items.Strings = (
        'Enable'
        'Disable')
    end
    object GroupBox5GWF0: TGroupBox
      Left = 8
      Top = 160
      Width = 513
      Height = 121
      Caption = '5G WF0 RSSI'
      TabOrder = 2
      object m_lv5GWF0RSSI: TListView
        Left = 8
        Top = 48
        Width = 465
        Height = 65
        Columns = <
          item
            Caption = 'BAND'
            Width = 150
          end
          item
            Caption = 'offset(dBm)'
            Width = 200
          end>
        Items.Data = {
          2C0000000100000000000000FFFFFFFFFFFFFFFF01000000000000000B354720
          57463020525353490130FFFF}
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnAdvancedCustomDrawSubItem = m_lv5GWF0RSSIAdvancedCustomDrawSubItem
        OnClick = m_lv5GWF0RSSIClick
      end
      object m_edt5GWF0RSSI: TComboBox
        Left = 365
        Top = 92
        Width = 97
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 1
        Visible = False
        OnExit = m_edt5GWF0RSSIExit
        Items.Strings = (
          '-4'
          '-3.5'
          '-3'
          '-2.5'
          '-2'
          '-1.5'
          '-1'
          '-0.5'
          '0'
          '0.5'
          '1'
          '1.5'
          '2'
          '2.5'
          '3'
          '3.5')
      end
      object m_cb5GWF0RSSI: TComboBox
        Left = 8
        Top = 20
        Width = 90
        Height = 21
        Style = csDropDownList
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        ItemIndex = 0
        TabOrder = 2
        Text = 'Enable'
        Items.Strings = (
          'Enable'
          'Disable')
      end
    end
    object GroupBox2GWF1: TGroupBox
      Left = 8
      Top = 296
      Width = 513
      Height = 121
      Caption = '2G WF1 RSSI'
      TabOrder = 3
      object m_lv2GWF1RSSI: TListView
        Left = 8
        Top = 48
        Width = 465
        Height = 65
        Columns = <
          item
            Caption = 'BAND'
            Width = 150
          end
          item
            Caption = 'offset(dBm)'
            Width = 200
          end>
        Items.Data = {
          2C0000000100000000000000FFFFFFFFFFFFFFFF01000000000000000B324720
          57463120525353490130FFFF}
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnAdvancedCustomDrawSubItem = m_lv2GWF1RSSIAdvancedCustomDrawSubItem
        OnClick = m_lv2GWF1RSSIClick
      end
      object m_edt2GWF1RSSI: TComboBox
        Left = 365
        Top = 92
        Width = 97
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 1
        Visible = False
        OnExit = m_edt2GWF1RSSIExit
        Items.Strings = (
          '-4'
          '-3.5'
          '-3'
          '-2.5'
          '-2'
          '-1.5'
          '-1'
          '-0.5'
          '0'
          '0.5'
          '1'
          '1.5'
          '2'
          '2.5'
          '3'
          '3.5')
      end
      object m_cb2GWF1RSSI: TComboBox
        Left = 8
        Top = 20
        Width = 90
        Height = 21
        Style = csDropDownList
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        ItemIndex = 0
        TabOrder = 2
        Text = 'Enable'
        Items.Strings = (
          'Enable'
          'Disable')
      end
    end
    object GroupBox5GWF1: TGroupBox
      Left = 8
      Top = 432
      Width = 513
      Height = 121
      Caption = '5G WF1 RSSI'
      TabOrder = 4
      object m_lv5GWF1RSSI: TListView
        Left = 8
        Top = 48
        Width = 465
        Height = 65
        Columns = <
          item
            Caption = 'BAND'
            Width = 150
          end
          item
            Caption = 'offset(dBm)'
            Width = 200
          end>
        Items.Data = {
          2C0000000100000000000000FFFFFFFFFFFFFFFF01000000000000000B354720
          57463120525353490130FFFF}
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnAdvancedCustomDrawSubItem = m_lv5GWF1RSSIAdvancedCustomDrawSubItem
        OnClick = m_lv5GWF1RSSIClick
      end
      object m_edt5GWF1RSSI: TComboBox
        Left = 365
        Top = 92
        Width = 97
        Height = 21
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        TabOrder = 1
        Visible = False
        OnExit = m_edt5GWF1RSSIExit
        Items.Strings = (
          '-4'
          '-3.5'
          '-3'
          '-2.5'
          '-2'
          '-1.5'
          '-1'
          '-0.5'
          '0'
          '0.5'
          '1'
          '1.5'
          '2'
          '2.5'
          '3'
          '3.5')
      end
      object m_cb5GWF1RSSI: TComboBox
        Left = 8
        Top = 20
        Width = 90
        Height = 21
        Style = csDropDownList
        ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
        ItemHeight = 13
        ItemIndex = 0
        TabOrder = 2
        Text = 'Enable'
        Items.Strings = (
          'Enable'
          'Disable')
      end
    end
  end
  object m_btnReadFromNVRAM: TButton
    Left = 9
    Top = 586
    Width = 105
    Height = 25
    Caption = 'Read from NVRAM'
    TabOrder = 1
    OnClick = m_btnReadFromNVRAMClick
  end
  object m_btnWriteToNVRAM: TButton
    Left = 136
    Top = 586
    Width = 105
    Height = 25
    Caption = 'Write to NVRAM'
    TabOrder = 2
    OnClick = m_btnWriteToNVRAMClick
  end
  object m_sb6632RSSICOMP: TStatusBar
    Left = 0
    Top = 625
    Width = 573
    Height = 25
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
end
