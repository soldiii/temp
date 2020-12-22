//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Unit4.h"
#include "School.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *Edit15;
	TEdit *Edit16;
	TEdit *Edit17;
	TEdit *Edit18;
	TEdit *Edit19;
	TEdit *Edit20;
	TEdit *Edit21;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TPanel *Panel7;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TPanel *Panel8;
	TPanel *Panel9;
	TPanel *Panel10;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TComboBox *ComboBox5;
	TComboBox *ComboBox6;
	TComboBox *ComboBox7;
	TPanel *Panel11;
	TComboBox *ComboBox8;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall ComboBox8Change(TObject *Sender);
private:
Educational_establishment* establish;
StudyGroup* obj;
String day;
String name;
void UnButtonsGet(const size_t& n);
void SchButtonsGet(const size_t& n);
vector<TButton*> Buttons{Button1,Button2,Button3,Button4,Button5,Button6,Button7};
vector<TComboBox*> Boxes{ComboBox1,ComboBox2,ComboBox3,ComboBox4,ComboBox5,ComboBox6,ComboBox7};
vector<TEdit*> Edits{Edit1,Edit2,Edit3,Edit4,Edit5,Edit6,Edit7,Edit8,Edit9,Edit10,Edit11,Edit12,Edit13,Edit14,Edit15,Edit16,Edit17,Edit18,Edit19,Edit20,Edit21};
void Avoid();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	__fastcall TForm1(TComponent* Owner, Educational_establishment* establish,StudyGroup* obj, String day,String name,bool flag);
	__fastcall TForm1(TComponent* Owner, Educational_establishment* establish,StudyGroup* obj, String day,String name);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
