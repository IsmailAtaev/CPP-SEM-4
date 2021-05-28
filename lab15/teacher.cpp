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

void teacher::title()
{
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << std::endl;
	std::cout << "| N |   Surname     |  Lastname |     Year      |    Position   |    Speciality   |      Listpapers     |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+" << std::endl;
}

bool teacher::operator==(const teacher& obj)
{
	if ((this->getLastname() == obj.getLastname() || obj.getLastname() == "") &&
		(this->getFirstname() == obj.getFirstname() || obj.getFirstname() == "") &&
		(this->getYear() == obj.getYear() || obj.getYear() == 0) &&
		(this->position == obj.getPosition() || obj.getPosition() == "") &&
		(this->speciality == obj.getSpeciality()|| obj.getSpeciality() == "") &&
		(this->listpapers == obj.getListpapers() || obj.getListpapers() == 0)) {
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

void teacher::Edit()
{
	std::cout << "=====<Edit>=====" << std::endl;
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

void teacher::Search()
{
	std::cout << "=====< Search >=====" << std::endl;
	std::cout << " 1  LastName." << std::endl;
	std::cout << " 2. FistName." << std::endl;
	std::cout << " 3. Year." << std::endl;
	std::cout << " 4. position." << std::endl;
	std::cout << " 5. speciality." << std::endl;
	std::cout << " 6. listpapers." << std::endl;
	std::cout << " Enter number for Search " << std::endl;
	int count = input_INT(std::cin, 1, 6);
	switch (count)
	{
	case 1: {
		std::cout << " Enter LastName ";
		this->setLastname(input_Str(std::cin));
		break;
	}
	case 2: {
		std::cout << " Enter FistName " ;
		this->setFirstname(input_Str(std::cin));
		break;
	}
	case 3: {
		std::cout << " Enter Year ";
		this->setYear(input_INT(std::cin, 1910, 2022));
		break;
	}
	case 4: {
		std::cout << " Enter Position ";
		this->position = input_Str(std::cin);
		break;
	}
	case 5: {
		std::cout << " Enter Speciality ";
		this->speciality = input_Str(std::cin);
		break;
	}
	case 6: {
		std::cout << " Enter List papers ";
		this->listpapers = input_INT(std::cin, 0, 500);
		break;
	}
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
