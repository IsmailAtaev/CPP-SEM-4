#include "person.h"

person::person(std::string lastName, std::string firstName)
{
	this->lastName = lastName;
	this->firstName = firstName;
	//this->year = year;
}

person::person(const person& obj)
{
	this->lastName = obj.lastName;
	this->firstName = obj.firstName;
	//this->year = year;
}

void person::setLastname(std::string lastName)
{
	this->lastName = lastName;
}

void person::setFirstname(std::string firstName)
{
	this->firstName = firstName;
}

//void person::setYear(const int year)
//{
//	this->year = year;
//}

std::string person::getLastname() const
{
	return this->lastName;
}

std::string person::getFirstname() const
{
	return this->firstName;
}

//int person::getYear() const
//{
//	return this->year;
//}

std::istream& operator>>(std::istream& in, person& obj)
{
	std::cout << " ¬ведите фамилию: ";
	std::cin >> 	obj.lastName;
	std::cout << " ¬ведите  им€: ";
	std::cin >> obj.firstName;
	//std::cout << " ¬ведите год рождени€: ";
	//std::cin >> obj.year;
	return in;
}

std::ostream& operator<<(std::ostream& out, person& obj)
{
	out << std::setw(15) << std::right << obj.lastName
		<< std::setw(13) << std::right << obj.firstName;
		//<< std::setw(14) << std::right << obj.year;
	return out;
}

std::fstream& operator>>(std::fstream& f, person& obj)
{
	int size_obj = 0;
	f.read(reinterpret_cast<char*>(&size_obj), sizeof(size_obj));
	f.read(reinterpret_cast<char*>(&obj),size_obj);
	return f;
}

std::fstream& operator<<(std::fstream& f, person& obj)
{
	int size_obj = sizeof(obj);
	f.write(reinterpret_cast<char*>(&size_obj), sizeof(size_obj));
	f.write(reinterpret_cast<char*>(&obj), sizeof(obj));
	return f;
}