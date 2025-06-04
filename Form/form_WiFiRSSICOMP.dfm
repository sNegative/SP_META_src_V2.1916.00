object frmRSSICOMP: TfrmRSSICOMP
  Left = 607
  Top = 233
  Width = 522
  Height = 266
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
  object m_sbRSSICOMP: TStatusBar
    Left = 0
    Top = 207
    Width = 514
    Height = 25
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object GroupBoxRSSIComp: TGroupBox
    Left = 8
    Top = 10
    Width = 489
    Height = 143
    Caption = 'RSSI Compensation(dBm)'
    TabOrder = 1
    object m_cbRSSI_Compensation: TComboBox
      Left = 8
      Top = 20
      Width = 90
      Height = 21
      Style = csDropDownList
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 0
      Text = 'Enable'
      Items.Strings = (
        'Enable'
        'Disable')
    end
    object m_lvRSSI_Compensation: TListView
      Left = 8
      Top = 48
      Width = 465
      Height = 73
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
        480000000200000000000000FFFFFFFFFFFFFFFF010000000000000007324720
        52535349013000000000FFFFFFFFFFFFFFFF0100000000000000073547205253
        53490130FFFFFFFF}
      ReadOnly = True
      RowSelect = True
      TabOrder = 1
      ViewStyle = vsReport
      OnAdvancedCustomDrawSubItem = m_lvRSSI_CompensationAdvancedCustomDrawSubItem
      OnClick = m_lvRSSI_CompensationClick
    end
    object m_cbRSSI_Compensation_Edit: TComboBox
      Left = 373
      Top = 100
      Width = 97
      Height = 21
      ImeName = #20013#25991' ('#31616#20307') - '#35895#27468#25340#38899#36755#20837#27861
      ItemHeight = 13
      TabOrder = 2
      Visible = False
      OnExit = m_cbRSSI_Compensation_EditExit
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
  object m_btnReadFromNVRAM: TButton
    Left = 9
    Top = 170
    Width = 105
    Height = 25
    Caption = 'Read from NVRAM'
    TabOrder = 2
    OnClick = m_btnReadFromNVRAMClick
  end
  object m_btnWriteToNVRAM: TButton
    Left = 144
    Top = 170
    Width = 105
    Height = 25
    Caption = 'Write to NVRAM'
    TabOrder = 3
    OnClick = m_btnWriteToNVRAMClick
  end
end
