//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>
#include "Educational_establishment.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEdit2;
	TRichEdit *RichEdit1;
private:
Educational_establishment* establish;
StudyGroup* obj;
void Output() const;
vector<TRichEdit*> Edits {RichEdit1,RichEdit2};
public:
	__fastcall TForm2(TComponent* Owner,StudyGroup* obj,Educational_establishment* establish);
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
