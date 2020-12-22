#include "Class.h"


String StudyGroup::GetName() const
{
	return name;
}

map<WeekType,map<String, Lessons>> StudyGroup::GetSchedule() const
{
	return schedule;
}

StudyGroup::StudyGroup(String name)
{
	this->name = name;
}

void StudyGroup::Add(const WeekType& type,const String& day,const size_t& number,const String& cab, const String& sub, const String& teacher)
{
	schedule[type][day].insert({ number,{cab,{sub,teacher}} });
}


