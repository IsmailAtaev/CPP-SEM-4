#pragma once
#include "person.h"

class teacher : public person
{
private:
	std::string position; // ���������
	std::string speciality; // �������������
	int listpapers; // ������ ������� ������
public:
	teacher(std::string Fname = "", std::string Lname = "", int YearOfBirth = 0, std::string position = "", std::string speciality = "", int listpapers = 0);
	teacher(const teacher& objTeacher);
	teacher& operator=(const teacher& obj);

	void setPosition(const std::string position);
	void setSpeciality(const std::string speciality);
	void setListpapers(const int listpapers);

	std::string getPosition()const;
	std::string getSpeciality()const;
	int getListpapers()const;

	static void title();

	bool operator ==(teacher& obj);
	bool operator != (teacher& obj);
	friend bool operator > (teacher& obj1, teacher& obj2);

	friend std::istream& operator>>(std::istream& in, teacher&);
	friend std::ostream& operator<<(std::ostream& out, teacher&);

	friend std::fstream& operator>> (std::fstream& f, teacher& objT);
	friend std::fstream& operator<< (std::fstream& f, teacher& objT);

	friend std::ifstream& operator>> (std::ifstream& f, teacher& objT);
	friend std::ofstream& operator<< (std::ofstream& f, teacher& objT);
	~teacher() { }
};

