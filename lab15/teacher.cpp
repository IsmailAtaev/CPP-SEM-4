#include "teacher.h"

teacher::teacher(std::string Fname, std::string Lname,	int YearOfBirth, 
	std::string position, std::string speciality, int listpapers)
	:person(Fname, Lname, YearOfBirth)
{
	this->position = position;
	this->speciality = speciality;
	this->listpapers = listpapers;
}

teacher::teacher(const teacher& objTeacher) :person(objTeacher)
{
	this->position = objTeacher.position;
	this->speciality = objTeacher.speciality;
	this->listpapers = objTeacher.listpapers;
}

teacher& teacher::operator=(const teacher& obj)
{
	if (this != &obj) {
		this->setLastname(obj.getLastname());
		this->setFirstname(obj.getFirstname());
		this->setYear(obj.getYear());
		this->position = obj.position;
		this->speciality = obj.speciality;
		this->listpapers = obj.listpapers;
	}
	return *this;
}

void teacher::setPosition(const std::string position)
{
	this->position = position;
}

void teacher::setSpeciality(const std::string speciality)
{
	this->speciality = speciality;
}

void teacher::setListpapers(const int listpapers)
{
	this->listpapers = listpapers;
}

std::string teacher::getPosition() const
{
	return this->position;
}

std::string teacher::getSpeciality() const
{
	return this->speciality;
}

int teacher::getListpapers() const
{
	return this->listpapers;
}

bool teacher::operator==(const teacher& obj)
{
	if (this->getLastname() == obj.getLastname() &&
		this->getFirstname() == obj.getFirstname() &&
		this->getYear() == obj.getYear() &&
		this->position == this->position &&
		this->speciality == obj.speciality &&
		this->listpapers == obj.listpapers) {
		return true;
	}
	else {
		return false;
	}
}

bool teacher::operator!=(const teacher& obj)
{
	if (this->getLastname() != obj.getLastname() &&
		this->getFirstname() != obj.getFirstname() &&
		this->getYear() != obj.getYear() &&
		this->position != this->position &&
		this->speciality != obj.speciality &&
		this->listpapers != obj.listpapers) {
		return true;
	}
	else {
		return false;
	}
}

std::istream& operator>>(std::istream& in, teacher& obj)
{
	in >> dynamic_cast<person&>(obj);
	std::cout << " Enter Position: ";
	obj.setPosition(input_Str(in));
	std::cout << " Enter Speciality: ";
	obj.setSpeciality(input_Str(in));
	std::cout << " Enter List papers: ";
	obj.setListpapers(input_INT(in, 0, 500));
	return in;
}

std::ostream& operator<<(std::ostream& out, teacher& obj)
{
	out << dynamic_cast<person&>(obj);
	out << std::setw(18) << std::right << obj.position
		<< std::setw(18) << std::right << obj.speciality
		<< std::setw(17) << std::right << obj.listpapers;
	return out;
}

std::fstream& operator>>(std::fstream& f, teacher& obj)
{
	f >> dynamic_cast<person&>(obj);
	char buf[size]{};

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	obj.position = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	obj.speciality = ss;

	f.read(reinterpret_cast<char*>(&obj.listpapers), sizeof(obj.listpapers));
	return f;
}

std::fstream& operator<<(std::fstream& f, teacher& obj)
{
	f << dynamic_cast<person&>(obj);
	char buf[size];

	strcpy_s(buf, obj.position.length() + 1, obj.position.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, obj.speciality.length() + 1, obj.speciality.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	f.write(reinterpret_cast<char*>(&obj.listpapers), sizeof(obj.listpapers));
	return f;
}

std::ifstream& operator>>(std::ifstream& f, teacher& obj)
{
	f >> dynamic_cast<person&>(obj)
		>> obj.position
		>> obj.speciality
		>> obj.listpapers;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, teacher& obj)
{
	f << dynamic_cast<person&>(obj) 
		<< obj.position << " " 
		<< obj.speciality << " " 
		<< obj.listpapers << std::endl;
	return f;
}
