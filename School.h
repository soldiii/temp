
#include "Educational_establishment.h"

#pragma once ;

class School : public Educational_establishment {
private: 
	Type type = Type::school;
	vector <StudyGroup*> classes;
	String name;
public:
	bool AddAudience(const WeekType&, const AudienceType& , const String& , const size_t& ,const  String& ,const String&,const String&){};
	void AddAudienceType(const AudienceType&, const String&){};
	map<String, AudienceType> GetAudiences()const {};
	void SetName(String);
	void Add(StudyGroup*) override;
	vector <StudyGroup*> GetStudyGroups()const override;
	Type GetType() const override;
	School(const String& name) :Educational_establishment(name) {};
	School(){};
};