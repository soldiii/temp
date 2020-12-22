//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4 :: TForm4(TComponent* Owner): TForm(Owner)
{

}

__fastcall TForm4 :: TForm4(TComponent* Owner, Educational_establishment* establish): TForm(Owner)
{
  this->establish = establish;
}

//---------------------------------------------------------------------------


void __fastcall TForm4::Button8Click(TObject *Sender)
{
if(Edit1->Text == "" ||Edit1->Text == "Класс или Группа"){
ShowMessage("Вы не ввели класс/группу");
return;
}
name = Edit1->Text;
ComboBox1->Items->Add(name);
obj = new StudyGroup(name);
for(auto i:establish->GetStudyGroups()){
if( name == i->GetName()){
 ShowMessage("Такой класс уже существует");
return;
}
}
establish->Add(obj);
Edit1->ReadOnly = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button9Click(TObject *Sender)
{
  Edit1->ReadOnly = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button1Click(TObject *Sender)
{
 Form1 = new TForm1(this,establish,obj,"Понедельник", name);
 Form1 -> Show();
 Button1->Enabled = false;
}

void __fastcall TForm4::Button2Click(TObject *Sender)
{
 Form1 = new TForm1(this,establish,obj,"Вторник", name);
 Form1 -> Show();
 Button2->Enabled = false;
}

void __fastcall TForm4::Button3Click(TObject *Sender)
{
 Form1 = new TForm1(this,establish,obj,"Среда", name);
 Form1 -> Show();
 Button3->Enabled = false;
}

void __fastcall TForm4::Button4Click(TObject *Sender)
{
 Form1 = new TForm1(this,establish,obj,"Четверг", name);
 Form1 -> Show();
 Button4->Enabled = false;
}

void __fastcall TForm4::Button5Click(TObject *Sender)
{
 Form1 = new TForm1(this,establish,obj,"Пятница", name);
 Form1 -> Show();
 Button5->Enabled = false;
}

void __fastcall TForm4::Button6Click(TObject *Sender)
{
 Form1 = new TForm1(this,establish,obj,"Суббота", name);
 Form1 -> Show();
 Button6->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button7Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------







void __fastcall TForm4::Button11Click(TObject *Sender)
{
for(auto i:establish->GetStudyGroups()){
for(auto j:ComboBox1->Items){
if(i->GetName() == j){
 Form2 = new TForm2(this,i,establish);
 Form2->Show();
 }
 }
 }
}
//---------------------------------------------------------------------------

