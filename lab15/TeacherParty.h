#pragma once
#include "teacher.h"
#include "party.h"


class TeacherParty : public teacher , public party
{
private: 
	std::string Rol_In_Party;
public:
	TeacherParty(std::string Lname = "", std::string Fname = "", int Year = 0,
		std::string position = "", std::string speciality = "", int listpapers = 0,
		std::string NameParty = "", std::string Biogrophy = "", std::string Rol_In_Party = "");

	void setRol_In_Party(std::string Rol_In_Party);
	std::string getRol_In_Party()const;
	TeacherParty& operator =(const TeacherParty& obj);

	friend std::istream& operator>>(std::istream& in, TeacherParty& obj);
	friend std::ostream& operator<<(std::ostream& out, TeacherParty& obj);

	friend std::fstream& operator>> (std::fstream& f, TeacherParty& obj);
	friend std::fstream& operator<< (std::fstream& f, TeacherParty& obj);

	friend std::ifstream& operator>> (std::ifstream& f, TeacherParty& obj);
	friend std::ofstream& operator<< (std::ofstream& f, TeacherParty& obj);

	
	bool operator ==(const TeacherParty& obj);
	bool operator != (const TeacherParty& obj);
	static void title();
	void Edit();
	void Search();
	~TeacherParty() { }
};

