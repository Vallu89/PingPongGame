//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <cstdlib>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int y ;
int x ;
int paddley ;
bool miss; // <-- lewy - true, prawy false;
int leftScore, rightScore;
unsigned int matchScore, matchTime;
int intervalInSecond;

void whoMiss(bool miss, TLabel *Label1,TLabel *leftPlayerScore, TLabel *rightPlayerScore, TTimer *timerPilki)
{
        if ( miss )
        {
                Label1->Caption = "Punkt dla gracza prawego >";
                Label1->Visible = true;
                Application->ProcessMessages(); Sleep(2000);
                Label1->Visible = false;
                x = 8;
                y = 8;
                rightPlayerScore->Caption = ++rightScore;
                if (rightScore == matchScore)
                {
                        Label1->Caption = "KONIEC GRY!";
                        Label1->Visible = true;
                        timerPilki->Enabled = false;
                }

        }
        else
        {

                Label1->Caption = "< Punkt dla gracza lewego";
                Label1->Visible = true;
                Application->ProcessMessages(); Sleep(2000);
                Label1->Visible = false;
                x = 8;
                y = 8;
                leftPlayerScore->Caption = ++leftScore;
                if (leftScore == matchScore)
                {
                        Label1->Caption = "KONIEC GRY!";
                        Label1->Visible = true;
                        timerPilki->Enabled = false;
                }
        }
}
void moveMechanic( TShape *ball, TShape *background,TShape *paddle1,TShape *paddle2, TShape *Shape1, TLabel *Label1, TTimer *timerPilki,TLabel *leftPlayerScore, TLabel *rightPlayerScore)
{
        if (ball->Top + ball->Height - Shape1->Height > background->Height )
                y = -y;
        else if ( ball->Top < background->Top )
                y = -y;
        else if ( ( (ball->Top + ball->Height/2) >= paddle1->Top && //<- odbicie pi³eczki od paletki lewej
                    (ball->Top + ball->Height/2) <= (paddle1->Top + paddle1->Height)) &&
                    ball->Left <= paddle1->Left + paddle1->Width )
                    {
                       if (x>0)
                        ++x;
                       else
                        --x;
                       if (y>0)
                        ++y;
                       else
                        --y;
                       x = -x;

                    }

        else if ( ( (ball->Top + ball->Height/2) >= paddle2->Top && //<- odbicie pi³eczki od paletki prawej
                    (ball->Top + ball->Height/2) <= (paddle2->Top + paddle2->Height)) &&
                    ball->Left + ball->Width >= paddle2->Left    )
                    {
                        if (x>0)
                        ++x;
                       else
                        --x;
                       if (y>0)
                        ++y;
                       else
                        --y;
                        x = -x;

                    }

        else if ( ball->Left >= background->Width)
                {
                        //timerPilki->Enabled = false;
                        miss = false;
                        whoMiss(miss,Label1,leftPlayerScore,rightPlayerScore,timerPilki);
                        ball->Top = 280;
                        ball->Left = 630;
                        //timerPilki->Enabled = true;
                }
        else if ( ball->Left <= 0)
                {
                        //timerPilki->Enabled = false;
                        miss = true;
                        whoMiss(miss,Label1,leftPlayerScore,rightPlayerScore,timerPilki);
                        ball->Top = 280;
                        ball->Left = 630;
                        //timerPilki->Enabled = true;
                }

}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerPilkiTimer(TObject *Sender)
{
        ball->Top +=y;
        ball->Left +=x;

        moveMechanic(ball,background,paddle1,paddle2,Shape1,Label1,timerPilki,leftPlayerScore,rightPlayerScore);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::turnUpPaddle1Timer(TObject *Sender)
{
        if(paddle1->Top - Shape1->Height -12 > 10)
                paddle1->Top += -paddley;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::turnDownPaddle1Timer(TObject *Sender)
{
        if(paddle1->Top + paddle1->Height < background->Height + Shape1->Height -14)
                paddle1->Top += paddley;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if ( Key == 0x57)
                turnUpPaddle1->Enabled = true;
        else if ( Key == 0x53)
                turnDownPaddle1->Enabled = true;

        if ( Key == VK_UP )
             turnUpPaddle2->Enabled = true;
        else if ( Key == VK_DOWN )
                turnDownPaddle2->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if ( Key == 0x57)
                turnUpPaddle1->Enabled = false;
        else if ( Key == 0x53)
                turnDownPaddle1->Enabled = false;

        if ( Key == VK_UP )
             turnUpPaddle2->Enabled = false;
        else if ( Key == VK_DOWN )
                turnDownPaddle2->Enabled = false;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::turnUpPaddle2Timer(TObject *Sender)
{
        if(paddle2->Top - Shape1->Height -12 > 10)
                paddle2->Top += -paddley;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::turnDownPaddle2Timer(TObject *Sender)
{
        if(paddle2->Top + paddle2->Height < background->Height+ Shape1->Height -20)
                paddle2->Top += paddley;

}
//---------------------------------------------------------------------------








void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        int hour, minute, second,timeToStop;
        AnsiString hr, min, sec;

        intervalInSecond++;

        timeToStop = intervalInSecond % matchTime;

        hour = intervalInSecond / 3600;
        if (hour <10)
                hr = "0" + IntToStr( hour );
        else
                hr = IntToStr( hour );

        minute = (intervalInSecond - 3600 * hour ) /60;
        if ( minute < 10 )
                min = "0" + IntToStr( minute );
        else
                min = IntToStr( minute );

        second = intervalInSecond - (3600 * hour) - (60 * minute);
        if ( second < 10 )
                sec = "0"+IntToStr( second );
        else
                sec = IntToStr( second );

        if ( timeToStop == 0 )
        {
                Label1->Caption = "KONIEC GRY!";
                Label1->Visible = true;
                Timer1->Enabled = false;
                timerPilki->Enabled = false;
        }


        Label2->Caption = min+":"+sec;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5min1Click(TObject *Sender)
{
        N5min1->Checked = true;
        Timer1->Enabled = true;
        intervalInSecond = 0;
        matchTime = 300;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10min1Click(TObject *Sender)
{
        N10min1->Checked = true;
        Timer1->Enabled = true;
        intervalInSecond = 0;
        matchTime = 600;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N15min1Click(TObject *Sender)
{
        N15min1->Checked = true;
        Timer1->Enabled = true;
        intervalInSecond = 0;
        matchTime = 900;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N30min1Click(TObject *Sender)
{
        N30min1->Checked = true;
        Timer1->Enabled = true;
        intervalInSecond = 0;
        matchTime = 1800;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N45min1Click(TObject *Sender)
{
        N45min1->Checked = true;
        Timer1->Enabled = true;
        intervalInSecond = 0;
        matchTime = 2700;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N51Click(TObject *Sender)
{
        leftScore = 0;
        rightScore = 0;
        N51->Checked = true;
        matchScore = 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
        leftScore = 0;
        rightScore = 0;
        N11->Checked = true;
        matchScore = 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N151Click(TObject *Sender)
{
        leftScore = 0;
        rightScore = 0;
        N151->Checked = true;
        matchScore = 15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Bezograniczeniaczasowego1Click(TObject *Sender)
{
        Bezograniczeniaczasowego1->Checked = true;
        Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Bezograniczenialimitu1Click(TObject *Sender)
{
        leftScore = 0;
        rightScore = 0;
        Bezograniczenialimitu1->Checked = true;
        matchScore = 1000000;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{       timerPilki->Enabled = false;
        Application->MessageBoxA("Witaj w grze PingPong.\n\n"
                                "Lewy gracz steruje wciskajac klawisze W i S.\n"
                                "Prawy gracz steruje wciskajac strza³ki do góry i w dó³.\n\n"
                                "W pocjach rozgrywki mo¿liwe jest ustawienie czasu gry oraz\n"
                                "ilosc punktów potrzebnych do zwyciêstwa\n"
                                "Po nacisnieciu opcji Nowa Gra, mamy mo¿liwosc rozpoczecia od pocz¹tku\n"
                                "Im d³u¿ej odbijasz, tym pi³ka szybciej przemieszcza sie\n"
                                "Kiedy odbijesz pi³kê, ona przyspieszy\n"
                                "Mo¿esz dowolnie modyfikowac pole gry","PingPong",MB_OK);
        Label1->Visible = false;
        paddle1->Top = 261;
        paddle2->Top = 261;
        ball->Top = 353;
        ball->Left = 654;
        leftScore = 0;
        leftPlayerScore->Caption = leftScore;
        rightScore = 0;
        rightPlayerScore->Caption = leftScore;
        matchScore = 1000000;
        Bezograniczenialimitu1->Checked = true;
        Bezograniczeniaczasowego1->Checked = true;
        Timer1->Enabled = false;
        x = 8;
        y = 8;
        paddley= 20;
        timerPilki->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
        Form1->FormCreate(MainMenu1);
        Label1->Visible = true;
        Label1->Caption = "3";
        Application->ProcessMessages(); Sleep(1000);
        Label1->Caption = "2";
        Application->ProcessMessages(); Sleep(1000);
        Label1->Caption = "1";
        Application->ProcessMessages(); Sleep(1000);
        Label1->Visible = false;

}
//---------------------------------------------------------------------------

