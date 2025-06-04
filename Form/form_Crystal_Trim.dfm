object frmCrystalTrim: TfrmCrystalTrim
  Left = 517
  Top = 438
  Width = 537
  Height = 239
  Caption = 'Crystal Trim'
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 513
    Height = 121
    Caption = 'Crystal Trim'
    TabOrder = 0
    object m_lvCrystal_Trim: TListView
      Left = 8
      Top = 48
      Width = 489
      Height = 49
      Columns = <
        item
          Width = 180
        end
        item
        end>
      Items.Data = {
        3F0000000100000000000000FFFFFFFFFFFFFFFF01000000000000001D437279
        7374616C205472696D20282D36337E36332C2073746570203129022D31FFFF}
      ReadOnly = True
      RowSelect = True
      ParentShowHint = False
      ShowColumnHeaders = False
      ShowHint = False
      TabOrder = 0
      ViewStyle = vsReport
      OnAdvancedCustomDrawSubItem = m_lvCrystal_TrimAdvancedCustomDrawSubItem
      OnClick = m_lvCrystal_TrimClick
    end
    object m_cbCrystal_Trim: TComboBox
      Left = 8
      Top = 16
      Width = 89
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 1
      Text = 'Enable'
      Items.Strings = (
        'Enable'
        'Disable')
    end
    object m_edtCrystal_Trim: TEdit
      Left = 384
      Top = 100
      Width = 121
      Height = 21
      TabOrder = 2
      Visible = False
      OnExit = m_edtCrystal_TrimExit
    end
  end
  object m_btnCrystal_Trim_Read: TButton
    Left = 8
    Top = 144
    Width = 105
    Height = 25
    Caption = 'Read from NVRAM'
    TabOrder = 1
    OnClick = m_btnCrystal_Trim_ReadClick
  end
  object m_btnCrystal_Trim_Write: TButton
    Left = 128
    Top = 144
    Width = 105
    Height = 25
    Caption = 'Write to NVRAM'
    TabOrder = 2
    OnClick = m_btnCrystal_Trim_WriteClick
  end
  object m_sbCrystallTrim: TStatusBar
    Left = 0
    Top = 180
    Width = 529
    Height = 25
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
end
