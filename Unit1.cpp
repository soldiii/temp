//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}

__fastcall TForm1 :: TForm1(TComponent* Owner, Educational_establishment* establish,StudyGroup* obj, String day, String name): TForm(Owner){

  this->establish = establish;
  this->obj = obj;
  this->day = day;
  this->name = name;

  if(establish->GetType() == university){
  for(auto i : Boxes){
i->Items->Add("Кабинет");
i->Items->Add("Малая поточка");
i->Items->Add("Большая поточка");
}
 ComboBox8->Text = ("Тип недели...");
 ComboBox8->Items->Add("Четная");
 ComboBox8->Items->Add("Нечетная");
 }
 else{
  for(auto i : Boxes){
  i->Enabled = false;
  }
  ComboBox8->Text = ("Тип смены...");
  ComboBox8->Items->Add("Первая");
 ComboBox8->Items->Add("Вторая");
 }
}

void TForm1::SchButtonsGet(const size_t& n){
if(Buttons[n]->Caption == "Успешно"){
  ShowMessage("Урок уже добавлен");
  return;
}
 if(Edits[2*n + n]->Text == "" || Edits[1 + 2*n + n]->Text == "" || Edits[2 + 2*n + n]->Text == ""){
ShowMessage("Присутствуют пустые поля");
return;
}

if(ComboBox8->Text == "Тип смены..."){
 ShowMessage("Не выбран тип смены");
 return;
}

for(auto i : establish->GetStudyGroups()){
 if(i->GetName() != name){
	for (auto item : i->GetSchedule()) {
	if(item.first == WeekType::even){
	for(auto index : item.second){
	if(index.first == day){
	for(auto j : index.second){
	if (j.first == n + 1 && j.second.first == Edits[2*n + n]->Text) {
			ShowMessage("В данное время кабинет занят");
			return;
		}
	if (j.first == n + 1 && j.second.second.second == Edits[2+ 2*n + n]->Text) {
			ShowMessage("В данное время преподаватель ведет у другого класса");
			return;
		}
		}
	}
	}
	}
	}
	}

}
obj->Add(WeekType::even,day,n+1,Edits[2*n + n]->Text,Edits[1 + 2*n + n]->Text,Edits[2 + 2*n + n]->Text);
 Buttons[n]->Caption = "Успешно";
  Edits[2*n + n]->ReadOnly = true;
   Edits[1 + 2*n + n]->ReadOnly = true;
   Edits[2 + 2*n + n]->ReadOnly = true;
}
void TForm1::UnButtonsGet(const size_t& n){
if(Buttons[n]->Caption == "Успешно"){
  ShowMessage("Пара уже добавлена");
  return;
}
if((Boxes[n]->Enabled == true && Boxes[n]->Text=="")|| Edits[2*n + n]->Text == "" || Edits[1 + 2*n + n]->Text == "" || Edits[2 + 2*n + n]->Text == ""){
ShowMessage("Присутствуют пустые поля");
return;
}
if(ComboBox8->Text == "Тип недели..."){
 ShowMessage("Не выбран тип недели");
 return;
}
 WeekType type1;

   switch(ComboBox8->ItemIndex){
   case 0:
	type1 = even;
   break;
   case 1:
   type1 = odd;
   break;
   }

	switch (Boxes[n]->ItemIndex){
	 case 0:
	 for(auto i : establish->GetAudiences()){
	 if (i.first == Edits[2*n + n]->Text && i.second != AudienceType::cabinet) {
	  ShowMessage("Эта аудитория другого типа");
	  return;
	 }
	 if (i.first == Edits[2*n + n]->Text && i.second == AudienceType::cabinet) {
	  break;
	 }
	 }
	 establish->AddAudienceType(AudienceType:: cabinet,Edits[2*n + n]->Text);
	 break;
	 case 1:
	 for(auto i : establish->GetAudiences()){
	 if (i.first == Edits[2*n + n]->Text && i.second != AudienceType::smallstream) {
	  ShowMessage("Эта аудитория другого типа");
	  return;
	 }
	 if (i.first == Edits[2*n + n]->Text && i.second == AudienceType::smallstream) {
	  break;
	 }
	 }
	 if(!establish->AddAudience(type1,AudienceType:: smallstream, day, n + 1,Edits[2*n + n]->Text,Edits[2 + 2*n + n]->Text,Edits[1 + 2*n + n]->Text))
	 return;
	 establish->AddAudienceType(AudienceType:: smallstream,Edits[2*n + n]->Text);
	 break;
	 case 2:
     for(auto i : establish->GetAudiences()){
	 if (i.first == Edits[2*n + n]->Text && i.second != AudienceType::bigstream) {
	  ShowMessage("Эта аудитория другого типа");
	  return;
	 }
	 if (i.first == Edits[2*n + n]->Text && i.second == AudienceType::bigstream) {
	  break;
	 }
	 }
	 if(!establish->AddAudience(type1,AudienceType:: bigstream, day, n + 1,Edits[2*n + n]->Text,Edits[2 + 2*n + n]->Text,Edits[1 + 2*n + n]->Text))
	 return;
	 establish->AddAudienceType(AudienceType:: bigstream,Edits[2*n + n]->Text);
	 break;
	}



 for(auto i : establish->GetStudyGroups()){
 if(i->GetName() != name){
	for (auto item : i->GetSchedule()) {
	if(item.first == type1){
	for(auto index : item.second){
	if(index.first == day){
	for(auto j : index.second){
	if (j.first == n + 1 && j.second.first == Edits[2*n + n]->Text && establish->GetAudiences()[Edits[2*n + n]->Text] == AudienceType :: cabinet) {
			ShowMessage("В данное время кабинет(аудитория) занят (занята)");
			return;
		}
	if (j.first == n + 1 && j.second.second.second == Edits[2+ 2*n + n]->Text && establish->GetAudiences()[Edits[2*n + n]->Text] == AudienceType :: cabinet) {
			ShowMessage("В данное время преподаватель ведет у другой группы ");
			return;
		}
		}
	}
	}
	}
	}
	}


 obj->Add(type1,day,n+1,Edits[2*n + n]->Text,Edits[1 + 2*n + n]->Text,Edits[2 + 2*n + n]->Text);
 Buttons[n]->Caption = "Успешно";
  Edits[2*n + n]->ReadOnly = true;
   Edits[1 + 2*n + n]->ReadOnly = true;
   Edits[2 + 2*n + n]->ReadOnly = true;
}
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
switch(establish->GetType()){
case (university):
UnButtonsGet(0);
break;
case (school):
SchButtonsGet(0);
break;
}
}


void __fastcall TForm1::Button2Click(TObject *Sender)
{
switch(establish->GetType()){
case (university):
UnButtonsGet(1);
break;
case (school):
 SchButtonsGet(1);
break;
}
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
switch(establish->GetType()){
case (university):
UnButtonsGet(2);
break;
case (school):
 SchButtonsGet(2);
break;
}
}


void __fastcall TForm1::Button4Click(TObject *Sender)
{
switch(establish->GetType()){
case (university):
UnButtonsGet(3);
break;
case (school):
 SchButtonsGet(3);
break;
}
 }

void __fastcall TForm1::Button5Click(TObject *Sender)
{
switch(establish->GetType()){
case (university):
UnButtonsGet(4);
break;
case (school):
SchButtonsGet(4);
break;
}
 }

void __fastcall TForm1::Button6Click(TObject *Sender)
{
switch(establish->GetType()){
case (university):
UnButtonsGet(5);
break;
case (school):
 SchButtonsGet(5);
break;
}
 }

void __fastcall TForm1::Button7Click(TObject *Sender)
{
switch(establish->GetType()){
case (university):
UnButtonsGet(6);
break;
case (school):
 SchButtonsGet(6);
break;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
delete Form1;
	Close();
}
//---------------------------------------------------------------------------


void TForm1 :: Avoid(){
 for(size_t i = 0;i< Buttons.size();++i){
 Buttons[i]->Caption = "Внести";
 Boxes[i] ->Text = "";
 for(size_t j = 3*i; j < 3*i + 3;++j){
  Edits[j]->ReadOnly = false;
  Edits[j]->Text = "";
 }
}
}

void __fastcall TForm1::ComboBox8Change(TObject *Sender)
{
WeekType type;
switch(ComboBox8->ItemIndex){
   case 0:
	type = even;
   break;
   case 1:
   type = odd;
   break;
   }
if(obj->GetSchedule()[type][day].size() == 0){
Avoid();
}

else{
Avoid();
	for(auto i : obj->GetSchedule()){
	if(i.first == type){
	for(auto index : i.second){
	if(index.first == day){
	for(auto j : index.second){
	Buttons[j.first - 1]->Caption = "Успешно" ;
	Edits[3*(j.first - 1)] ->Text = j.second.first;
	Edits[3*(j.first - 1) + 1] ->Text = j.second.second.first;
	Edits[3*(j.first - 1) + 2] ->Text = j.second.second.second;
	Edits[3*(j.first - 1)] ->ReadOnly = true;
	Edits[3*(j.first - 1) + 1] ->ReadOnly = true;
	Edits[3*(j.first - 1) + 2] ->ReadOnly = true;
	switch (establish->GetAudiences().at(j.second.first)) {
	   case cabinet:
	   Boxes[j.first - 1]->Text = "Кабинет";
	   break;
	   case smallstream:
	   Boxes[j.first - 1]->Text = "Малая поточка";
	   break;
	   case bigstream:
	   Boxes[j.first - 1]->Text = "Большая поточка";
	   break;
	 }
	}
	}
	}
	}
	}
	}
	}

//---------------------------------------------------------------------------

