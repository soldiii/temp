#include "Educational_establishment.h"
#include "Class.h"

#define V vector<pair<pair<String,pair<String, String>>, size_t>>
class University : public Educational_establishment {
private:
	Type type = Type::university;
	vector <StudyGroup*> groups;
	map <WeekType,map<String, map<size_t,V>>> count_audiences;
	map<String, AudienceType> audiences;
public:
	void Add(StudyGroup*)override;
	vector <StudyGroup*> GetStudyGroups() const override;
	Type GetType() const override;
	bool AddAudience(const WeekType& , const AudienceType& ,const String& ,const size_t& , const String&,const String& ,const String&) override;
	void AddAudienceType(const AudienceType&, const String&) override;
	map<String, AudienceType> GetAudiences() const override;
	University(const String& name) :Educational_establishment(name) {};
    University(){};
};