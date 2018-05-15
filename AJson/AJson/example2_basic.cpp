#include <iostream>
#include <string>
#include <vector>

#include "ajson.hpp"

using namespace std;
using namespace ajson;

struct Education
{
	string	School;
	double	GPA;

	Education() :GPA(0.0) {}

	Education(const string& school, double gpa)
		:School(school), GPA(gpa)
	{
	}
};

struct Person
{
	string	Name;
	int			Age;
	vector<Education> Educations;
	//map<int, Education> mapEducations;
};

AJSON(Education, School, GPA)
AJSON(Person, Name, Age, Educations)
//AJSON(Person, Name, Age, mapEducations)

int main(int argc, char * argv[])
{
	Person person;
	person.Name = "Bob";
	person.Age = 28;
	person.Educations.push_back(Education("MIT", 600));
	//person.mapEducations.insert(std::make_pair<int, Education>(1,Education("MIT", 600)));
	//person.mapEducations.insert(std::make_pair<int, Education>(2, Education("MITxz", 6020)));
	//person.mapEducations.insert(std::make_pair<int, Education>(3, Education("MIsT", 6030)));
	string_stream ss;
	save_to(ss, person);
	std::cout << ss.str() << std::endl;
	cin.get();
	return 0;
}
