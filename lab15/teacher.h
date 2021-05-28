#pragma once
#include "person.h"

class teacher : virtual public person
{
private:
	std::string position; // ƒолжность
	std::string speciality; // специальность
	int listpapers; // список научных трудов
public:
	teacher(std::string Fname = "", std::string Lname = "",
		int YearOfBirth = 0, std::string position = "", 
		std::string speciality = "", int listpapers = 0);

	teacher(const teacher& objTeacher);
	~teacher() { }
	teacher& operator=(const teacher& obj);

	void setPosition(const std::string position);
	void setSpeciality(const std::string speciality);
	void setListpapers(const int listpapers);

	std::string getPosition()const;
	std::string getSpeciality()const;
	int getListpapers()const;

	static void title();

	bool operator ==(const teacher& obj);
	bool operator != (const teacher& obj);

	friend std::istream& operator>>(std::istream& in, teacher&);
	friend std::ostream& operator<<(std::ostream& out, teacher&);

	friend std::fstream& operator>> (std::fstream& f, teacher& objT);
	friend std::fstream& operator<< (std::fstream& f, teacher& objT);

	friend std::ifstream& operator>> (std::ifstream& f, teacher& objT);
	friend std::ofstream& operator<< (std::ofstream& f, teacher& objT);
	
	void Edit();
	void Search();
};

