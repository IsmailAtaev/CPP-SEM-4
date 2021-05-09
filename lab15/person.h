#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
constexpr auto size = 40;

class person
{
private:
	char name[40];

	std::string lastName;
	std::string firstName;
	//int year;
public:
	person(char* ptr) {
		strcpy_s(this->name,strlen(ptr),ptr);
	}
	person(std::string lastName = "", std::string firstname = "" /*int year = 0*/);
	person(const person& obj);

	~person() { }

	void setLastname(std::string lastName);
	void setFirstname(std::string firstName);
	void setYear(const int year);

	std::string getLastname()const; 
	std::string getFirstname()const;
	int getYear()const;

	friend std::istream& operator >> (std::istream& in, person&);
	friend std::ostream& operator << (std::ostream& out, person&);

	friend std::fstream& operator>> (std::fstream& f, person& objP);
	friend std::fstream& operator<< (std::fstream& f, person& objP);

};

