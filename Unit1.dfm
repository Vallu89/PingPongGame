object Form1: TForm1
  Left = 245
  Top = 139
  Width = 1359
  Height = 760
  Caption = 'Form1'
  Color = clBtnFace
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  DesignSize = (
    1343
    702)
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 0
    Top = 0
    Width = 1343
    Height = 105
    Align = alTop
    Brush.Color = clTeal
  end
  object background: TShape
    Left = 0
    Top = 105
    Width = 1343
    Height = 597
    Align = alClient
    Brush.Color = clSilver
  end
  object Shape2: TShape
    Left = 663
    Top = 104
    Width = 20
    Height = 598
    Anchors = [akTop, akBottom]
  end
  object paddle1: TShape
    Left = 31
    Top = 261
    Width = 20
    Height = 200
    Anchors = [akBottom]
    Brush.Color = clGreen
    Shape = stRoundRect
  end
  object ball: TShape
    Left = 654
    Top = 353
    Width = 40
    Height = 40
    Anchors = [akBottom]
    Brush.Color = clTeal
    Shape = stCircle
  end
  object paddle2: TShape
    Left = 1277
    Top = 261
    Width = 20
    Height = 200
    Anchors = [akBottom]
    Brush.Color = clGreen
    Shape = stRoundRect
  end
  object leftPlayerScore: TLabel
    Left = 32
    Top = 48
    Width = 20
    Height = 37
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object rightPlayerScore: TLabel
    Left = 1279
    Top = 48
    Width = 20
    Height = 37
    Anchors = [akTop]
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object Label1: TLabel
    Left = 432
    Top = 200
    Width = 481
    Height = 49
    Alignment = taCenter
    Anchors = [akTop]
    AutoSize = False
    Caption = 'KONIEC GRY !'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object Label2: TLabel
    Left = 584
    Top = 48
    Width = 177
    Height = 57
    Alignment = taCenter
    Anchors = [akTop]
    AutoSize = False
    Caption = '00:00'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
    Layout = tlCenter
  end
  object timerPilki: TTimer
    Interval = 1
    OnTimer = timerPilkiTimer
    Left = 296
    Top = 8
  end
  object turnUpPaddle1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = turnUpPaddle1Timer
    Left = 24
    Top = 128
  end
  object turnDownPaddle1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = turnDownPaddle1Timer
    Left = 24
    Top = 168
  end
  object turnUpPaddle2: TTimer
    Enabled = False
    Interval = 1
    OnTimer = turnUpPaddle2Timer
    Left = 1248
    Top = 160
  end
  object turnDownPaddle2: TTimer
    Enabled = False
    Interval = 1
    OnTimer = turnDownPaddle2Timer
    Left = 1248
    Top = 200
  end
  object MainMenu1: TMainMenu
    Left = 128
    Top = 56
    object Gr1: TMenuItem
      Caption = 'Rozgrywka'
      object N1: TMenuItem
        Caption = 'Nowa gra'
        OnClick = N1Click
      end
      object Ustaldlugo1: TMenuItem
        Caption = 'Czas rozgrywki'
        object N5min1: TMenuItem
          Caption = '5 min'
          RadioItem = True
          OnClick = N5min1Click
        end
        object N10min1: TMenuItem
          Caption = '10 min'
          RadioItem = True
          OnClick = N10min1Click
        end
        object N15min1: TMenuItem
          Caption = '15 min'
          RadioItem = True
          OnClick = N15min1Click
        end
        object N30min1: TMenuItem
          Caption = '30 min'
          RadioItem = True
          OnClick = N30min1Click
        end
        object N45min1: TMenuItem
          Caption = '45 min'
          RadioItem = True
          OnClick = N45min1Click
        end
        object Bezograniczeniaczasowego1: TMenuItem
          Caption = 'Bez ograniczenia czasowego'
          Checked = True
          RadioItem = True
          OnClick = Bezograniczeniaczasowego1Click
        end
      end
      object Limitpunktw1: TMenuItem
        Caption = 'Limit punkt'#243'w'
        object N51: TMenuItem
          Caption = '5'
          RadioItem = True
          OnClick = N51Click
        end
        object N11: TMenuItem
          Caption = '10'
          RadioItem = True
          OnClick = N11Click
        end
        object N151: TMenuItem
          Caption = '15'
          RadioItem = True
          OnClick = N151Click
        end
        object Bezograniczenialimitu1: TMenuItem
          Caption = 'Bez ogranicze'#324
          Checked = True
          RadioItem = True
          OnClick = Bezograniczenialimitu1Click
        end
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 640
    Top = 24
  end
end
