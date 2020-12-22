#include <iostream>
#include <String>
#include <vector>
#include <map>
#include <set>

#define  Lessons set<pair<size_t,pair<String,pair<String, String>>>>

 #pragma once;

using namespace std;


enum Type {
	school,
	university
};

enum WeekType {
	even,
	odd
};

enum AudienceType {
	bigstream,
	smallstream,
	cabinet
};

class StudyGroup {
private:
	String name;
	map<WeekType, map<String, Lessons>> schedule;
public:

	String GetName() const ;

	map < WeekType, map < String, Lessons>> GetSchedule() const ;


	StudyGroup(String name);
	StudyGroup(){};

	void Add( const WeekType&,const String&,const size_t&,const String&, const String&, const String&);

};
