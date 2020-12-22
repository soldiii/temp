//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

void TForm2 :: Output()const{
 RichEdit1->Clear();
 RichEdit2->Clear();
 if(establish->GetType() == university){
  RichEdit1->Clear();
 RichEdit2->Clear();
RichEdit1->Lines->Add("Четная неделя");
RichEdit1->Lines->Add("------------------------------------------------------------");
RichEdit1->Lines->Add("\r");
RichEdit2->Lines->Add("Нечетная неделя");
RichEdit2->Lines->Add("------------------------------------------------------------");
RichEdit2->Lines->Add("\r");
RichEdit1->Font->Size = 10;
RichEdit2->Font->Size = 10;

 size_t n = 0;
for(auto i : obj->GetSchedule()){

 switch(i.first){
  case even:
  n = 0;
  break;
  case odd:
  n = 1;
  break;
 }

 for(auto j : i.second){

 Edits[n]->Lines->Add(j.first);
 Edits[n]->Lines->Add("------------------------------------------------------------");
  for(auto item : j.second){
  String str;
  str = UIntToStr(item.first) + " пара:" ;
  Edits[n]->Lines->Add(str);
  str = item.second.first + " / " + item.second.second.first + " / " + item.second.second.second;
  Edits[n]->Lines->Add(str);
  }
 }
 }
}

}

__fastcall TForm2::TForm2(TComponent* Owner,StudyGroup* obj, Educational_establishment* establish)
	: TForm(Owner)
   {
	this->obj = obj;
	this->establish = establish;
	Output();
	RichEdit1->ReadOnly = true;
    RichEdit2->ReadOnly = true;
   }
