#include "School.h"

void School :: SetName(String name){
this->name = name;
}

void School::Add(StudyGroup* cl)
{
	classes.push_back(cl);
}

vector<StudyGroup*> School::GetStudyGroups() const
{
	return classes;
}

Type School::GetType() const 
{
	return type;
}
