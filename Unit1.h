//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TShape *paddle1;
        TShape *ball;
        TTimer *timerPilki;
        TTimer *turnUpPaddle1;
        TTimer *turnDownPaddle1;
        TShape *paddle2;
        TTimer *turnUpPaddle2;
        TTimer *turnDownPaddle2;
        TShape *Shape1;
        TShape *Shape2;
        TLabel *leftPlayerScore;
        TLabel *rightPlayerScore;
        TLabel *Label1;
        TMainMenu *MainMenu1;
        TMenuItem *Gr1;
        TMenuItem *N1;
        TMenuItem *Ustaldlugo1;
        TMenuItem *N5min1;
        TMenuItem *N10min1;
        TMenuItem *N15min1;
        TMenuItem *N30min1;
        TMenuItem *N45min1;
        TMenuItem *Bezograniczeniaczasowego1;
        TMenuItem *Limitpunktw1;
        TMenuItem *N51;
        TMenuItem *N11;
        TMenuItem *N151;
        TMenuItem *Bezograniczenialimitu1;
        TLabel *Label2;
        TTimer *Timer1;
        void __fastcall timerPilkiTimer(TObject *Sender);
        void __fastcall turnUpPaddle1Timer(TObject *Sender);
        void __fastcall turnDownPaddle1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall turnUpPaddle2Timer(TObject *Sender);
        void __fastcall turnDownPaddle2Timer(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall N5min1Click(TObject *Sender);
        void __fastcall N10min1Click(TObject *Sender);
        void __fastcall N15min1Click(TObject *Sender);
        void __fastcall N30min1Click(TObject *Sender);
        void __fastcall N45min1Click(TObject *Sender);
        void __fastcall N51Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N151Click(TObject *Sender);
        void __fastcall Bezograniczeniaczasowego1Click(TObject *Sender);
        void __fastcall Bezograniczenialimitu1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 