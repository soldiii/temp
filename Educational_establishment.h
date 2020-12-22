
#include "Class.h"
#pragma once;


class Educational_establishment {
private:
	String name;
public:
	virtual void Add(StudyGroup*) = 0;
	void SetName(String name);
    virtual vector <StudyGroup*> GetStudyGroups() const = 0;
	String GetName() const;
	virtual Type GetType() const = 0;
	virtual bool AddAudience(const WeekType&, const AudienceType& , const String& ,const  size_t& ,const  String&,const String&,const String& ) = 0;
	virtual void AddAudienceType(const AudienceType&, const String&) = 0;
	virtual map<String, AudienceType> GetAudiences()const = 0;
	Educational_establishment(String name);
	Educational_establishment(){};
};
