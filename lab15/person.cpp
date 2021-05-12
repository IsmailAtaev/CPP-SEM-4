#include "person.h"

person::person(std::string lastName, std::string firstName, int year)
{
	this->lastName = lastName;
	this->firstName = firstName;
	this->year = year;
}

person::person(const person& obj)
{
	this->lastName = obj.lastName;
	this->firstName = obj.firstName;
	this->year = obj.year;
}

void person::setLastname(std::string lastName)
{
	this->lastName = lastName;
}

void person::setFirstname(std::string firstName)
{
	this->firstName = firstName;
}

void person::setYear(const int year)
{
	this->year = year;
}

std::string person::getLastname() const
{
	return this->lastName;
}

std::string person::getFirstname() const
{
	return this->firstName;
}

int person::getYear() const
{
	return this->year;
}


std::istream& operator>>(std::istream& in, person& obj)
{
	std::cout << " Enter LastName: ";
	obj.setLastname(input_Str(in));
	std::cout << " Enter FirstName: ";
	obj.setFirstname(input_Str(in));
	std::cout << " Enter Year: ";
	obj.setYear(input_INT(in, 1910, 2022));
	return in;
}

std::ostream& operator<<(std::ostream& out, person& obj)
{
	out << std::setw(15) << std::right << obj.lastName
		<< std::setw(13) << std::right << obj.firstName
		<< std::setw(14) << std::right << obj.year;
	return out;
}

std::fstream& operator>>(std::fstream& f, person& obj)
{
	char buf[size]{};

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	obj.lastName = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	obj.firstName = ss;

	f.read(reinterpret_cast<char*>(&obj.year), sizeof(obj.year));
	return f;
}

std::fstream& operator<<(std::fstream& f, person& obj)
{
	char buf[size];

	strcpy_s(buf, obj.lastName.length() + 1, obj.lastName.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, obj.firstName.length() + 1, obj.firstName.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	f.write(reinterpret_cast<char*>(&obj.year), sizeof(obj.year));

	return f;
}


std::ifstream& operator>>(std::ifstream& f, person& obj)
{
	f >> obj.lastName >> obj.firstName >> obj.year;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, person& obj)
{
	f << obj.lastName<< " " << obj.firstName<< " " << obj.year << " ";
	return f;
}
