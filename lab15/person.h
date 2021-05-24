#pragma once
#include "Header.h"
#include <deque>

class person
{
private:
	std::string lastName;
	std::string firstName;
	int year;
public:
	person(std::string lastName = "", std::string firstname = "", int year = 0);
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

	friend std::fstream& operator>> (std::fstream& f, person& obj);
	friend std::fstream& operator<< (std::fstream& f, person& obj);

	friend std::ifstream& operator>> (std::ifstream& f, person& obj);
	friend std::ofstream& operator<< (std::ofstream& f, person& obj);
};