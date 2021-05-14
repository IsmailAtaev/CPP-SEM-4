#pragma once
#include "person.h"

class teacher : public person
{
private:
	std::string position; // ���������
	std::string speciality; // �������������
	int listpapers; // ������ ������� ������
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

	//static void title();

	bool operator ==(const teacher& obj);
	bool operator != (const teacher& obj);

	friend std::istream& operator>>(std::istream& in, teacher&);
	friend std::ostream& operator<<(std::ostream& out, teacher&);

	friend std::fstream& operator>> (std::fstream& f, teacher& objT);
	friend std::fstream& operator<< (std::fstream& f, teacher& objT);

	friend std::ifstream& operator>> (std::ifstream& f, teacher& objT);
	friend std::ofstream& operator<< (std::ofstream& f, teacher& objT);
	
	
	void get_type_sort()override 
	{
		std::cout << "=====<Sort>=====" << std::endl;
		std::cout << " 1  LastName." << std::endl;
		std::cout << " 2. FistName." << std::endl;
		std::cout << " 3. Year." << std::endl;
		std::cout << " 4. position." << std::endl;
		std::cout << " 5. speciality." << std::endl;
		std::cout << " 6. listpapers." << std::endl;
		int count = input_INT(std::cin, 1, 6);
		switch (count)
		{
		case 1: this->setLastname(input_Str(std::cin));	break;
		case 2: this->setFirstname(input_Str(std::cin)); break;
		case 3: this->setYear(input_INT(std::cin, 1910, 2022)); break;
		case 4: this->position = input_Str(std::cin); break;
		case 5: this->speciality = input_Str(std::cin); break;
		case 6: this->listpapers = input_INT(std::cin, 0, 500); break;
		}
	}
};

