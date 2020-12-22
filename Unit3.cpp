//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
ComboBox1->Items->Add("Школа");
ComboBox1->Items->Add("Университет");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
if(Edit1->Text == "Название" ||Edit1->Text == "")
{
	ShowMessage("Вы не ввели название учебного учреждения!");
	return ;
}
if(ComboBox1->Text == "Выберите тип..."){
ShowMessage("Вы не выбрали тип учебного учреждения!");
return;
}

String name = Edit1->Text;
switch (ComboBox1->ItemIndex) {
	  case 0:
	  establish = new School(name);
	  Form4 = new TForm4(this,establish);
	  break;
	  case 1:
	   establish = new University(name);
	   Form4 = new TForm4(this,establish);
	  break;
	;
}
Edit1->Enabled = false;
ComboBox1->Enabled = false;
Button1->Enabled = false;
 Form4 -> Show();
}
//---------------------------------------------------------------------------




void __fastcall TForm3::Button2Click(TObject *Sender)
{
//TForm2* Form2 = new TForm2(this,establish);
Form2 -> Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button3Click(TObject *Sender)
{
 Form4 -> Show();
}
//---------------------------------------------------------------------------

