#include "University.h"

void University::Add(StudyGroup* cl)
{
	groups.push_back(cl);
}

vector<StudyGroup*> University::GetStudyGroups() const
{
	return groups;
}

Type University::GetType() const
{
	return type;
}

bool University::AddAudience(const WeekType& wtype, const AudienceType& atype, const String& day,const size_t& lesson,const  String& cab,const String& teach,const String& subj)
{
	size_t n = 0;
	switch (atype) {
	case cabinet:
		for (auto i : count_audiences[wtype][day][lesson]) {
			if (i.first.first == cab && i.second == 1) {
				ShowMessage("Кабинет занят");
				return 0;
			}
		}
		count_audiences[wtype][day][lesson].push_back({ {cab,{teach,subj}},1 });
		break;

	case smallstream:

		for (auto& i : count_audiences[wtype][day][lesson]) {
		if (i.first.first == cab) {
				 if (i.first.second.second != subj) {
					ShowMessage("За данной лекцией закреплен другой учебный предмет");
					return 0;
				}
				if (i.first.second.first != teach) {
					ShowMessage("За данной лекцией закреплен другой преподаватель");
					return 0;
				}
				n = i.second;
				if (i.second == 4) {
						ShowMessage("Малая поточка заполнена");
					return 0;
				}
				else {
					++i.second;
					return 1;
				}
			}
		}

		if (n == 0) {
			count_audiences[wtype][day][lesson].push_back({ {cab,{teach,subj}},1 });
		}
		break;

	case bigstream:

		for (auto& i : count_audiences[wtype][day][lesson]) {
			if (i.first.first == cab) {
				 if (i.first.second.second != subj) {
					ShowMessage("За данной лекцией закреплен другой учебный предмет");
					return 0;
				}
				if (i.first.second.first != teach) {
						ShowMessage("За данной лекцией закреплен другой преподаватель");
					return 0;
				}
				n = i.second;
				if (i.second == 10) {
						ShowMessage("Большая поточка заполнена");
					return 0;
				}
				else {
					++i.second;
					return 1;
				}
			}
		}

		if (n == 0) {
			count_audiences[wtype][day][lesson].push_back({ {cab,{teach,subj}},1 });
		}
		break;
	}

   return 1;
}

void University::AddAudienceType(const AudienceType& type, const String& aud)
{
	audiences[aud] = type;
}

map<String, AudienceType> University :: GetAudiences()const {
return audiences;
}
