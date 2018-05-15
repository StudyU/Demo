#include <iostream>
#include <string>
#include <vector>

#include "ajson.hpp"

enum PhoneType

{

	MOBILE = 0,

	HOME = 1,

	WORK = 2

};

struct PhoneNumber

{
	std::string number;

	PhoneType   type = MOBILE;

	PhoneNumber(std::string const& number_ = "", PhoneType type_ = MOBILE)

		:number(number_), type(type_)

	{}

};

struct Person

{

	std::string name;

	int32_t     id;

	std::string mail;

	std::vector<PhoneNumber> phones;

	Person(std::string name_ = "", int32_t id_ = 0, std::string mail_ = "")

		:name(name_), id(id_), mail(mail_)

	{}

};

struct AddressBook

{

	std::vector<Person> peoples;

};

AJSON(PhoneNumber, number, type)

AJSON(Person, name, id, mail, phones)

AJSON(AddressBook, peoples)