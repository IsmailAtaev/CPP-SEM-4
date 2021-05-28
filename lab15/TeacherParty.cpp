#include "TeacherParty.h"

TeacherParty::TeacherParty(std::string Lname, std::string Fname, int Year,
	std::string position, std::string speciality, int listpapers,
	std::string NameParty, std::string Biogrophy, std::string Rol_In_Party) :teacher(Lname, Fname, Year, position, speciality, listpapers),
	party(Lname, Fname, Year, NameParty, Biogrophy) {
	this->Rol_In_Party = Rol_In_Party;
}

void TeacherParty::setRol_In_Party(std::string Rol_In_Party)
{
	this->Rol_In_Party = Rol_In_Party;
}

std::string TeacherParty::getRol_In_Party() const
{
	return this->Rol_In_Party;
}

TeacherParty& TeacherParty::operator=(const TeacherParty& obj)
{
	if (this != &obj) {
		this->setLastname(obj.getLastname());
		this->setFirstname(obj.getFirstname());
		this->setYear(obj.getYear());
		this->setPosition(obj.getPosition());
		this->setSpeciality(obj.getSpeciality());
		this->setListpapers(obj.getListpapers());
		this->setNameParty(obj.getNameParty());
		this->setBiogrophy(obj.getBiogrophy());
		this->Rol_In_Party = obj.Rol_In_Party;
	}
	return *this;
}

bool TeacherParty::operator==(const TeacherParty& obj)
{
	if ((this->getLastname() == obj.getLastname() || obj.getLastname() == "") &&
		(this->getFirstname() == obj.getFirstname() || obj.getFirstname() == "") &&
		(this->getYear() == obj.getYear() || obj.getYear() == 0) &&
		(this->getPosition() == obj.getPosition() || obj.getPosition() == "") &&
		(this->getSpeciality() == obj.getSpeciality() || obj.getSpeciality() == "") &&
		(this->getListpapers() == obj.getListpapers() || obj.getListpapers() == 0) &&
		(this->getNameParty() == obj.getNameParty() || obj.getNameParty() == "") &&
		(this->getBiogrophy() == obj.getBiogrophy() || obj.getBiogrophy() == "") &&
		(this->getRol_In_Party() == obj.getRol_In_Party() || obj.getRol_In_Party() == "")) {
		return true;
	}
	return false;
}

bool TeacherParty::operator!=(const TeacherParty& obj)
{
	if (this->getFirstname() != obj.getFirstname() &&
		this->getLastname() != obj.getLastname() &&
		this->getYear() != obj.getYear() &&
		this->getPosition() != obj.getPosition() &&
		this->getSpeciality() != obj.getSpeciality() &&
		this->getListpapers() != obj.getListpapers() &&
		this->NameParty != obj.NameParty &&
		this->Biogrophy != obj.Biogrophy &&
		this->Rol_In_Party != obj.Rol_In_Party)
		return true;
	else
		return false;
}

void TeacherParty::title()
{
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+---------------+---------------------------+---------------------+" << std::endl;
	std::cout << "| ¹ |   Lastname    |  Fistname |      Year     |   Position    |   speciality    |      listpapers     |    NameParty  |         Biogrophy         |     Rol_In_Party    |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+-----------------+---------------------+---------------+---------------------------+---------------------+" << std::endl;
}

void TeacherParty::Edit()
{
	std::cout << "=====<Edit>=====" << std::endl;
	std::cout << " 1  LastName." << std::endl;
	std::cout << " 2. FistName." << std::endl;
	std::cout << " 3. Year." << std::endl;
	std::cout << " 4. position." << std::endl;
	std::cout << " 5. speciality." << std::endl;
	std::cout << " 6. listpapers." << std::endl; 
	std::cout << " 7. NameParty." << std::endl;
	std::cout << " 8. Biogrophy." << std::endl;
	std::cout << " 9. Rol in party." << std::endl;
	std::cout << " Enter number ." << std::endl;

	int count = input_INT(std::cin, 1, 9);
	switch (count)
	{
	case 1: this->setLastname(input_Str(std::cin));	break;
	case 2: this->setFirstname(input_Str(std::cin)); break;
	case 3: this->setYear(input_INT(std::cin, 1910, 2022)); break;
	case 4: this->setPosition(input_Str(std::cin)); break;
	case 5: this->setSpeciality(input_Str(std::cin)); break;
	case 6: this->setListpapers(input_INT(std::cin, 0, 500)); break;
	case 7: this->NameParty = input_Str(std::cin); break;
	case 8: this->Biogrophy = input_Str(std::cin); break;
	case 9: this->Rol_In_Party = input_Str(std::cin); break;
	}
}

void TeacherParty::Search()
{
	std::cout << "=====< Search >=====" << std::endl;
	std::cout << " 1  LastName." << std::endl;
	std::cout << " 2. FistName." << std::endl;
	std::cout << " 3. Year." << std::endl;
	std::cout << " 4. position." << std::endl;
	std::cout << " 5. speciality." << std::endl;
	std::cout << " 6. listpapers." << std::endl;
	std::cout << " 7. NameParty." << std::endl;
	std::cout << " 8. Biogrophy." << std::endl;
	std::cout << " 9. Rol in party." << std::endl;
	std::cout << " Enter number for Search " << std::endl;
	int count = input_INT(std::cin, 1, 9);
	switch (count)
	{
	case 1: {
		std::cout << " Enter LastName ";
		this->setLastname(input_Str(std::cin));
		break;
	}
	case 2: {
		std::cout << " Enter FistName ";
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
		this->setPosition(input_Str(std::cin));
		break;
	}
	case 5: {
		std::cout << " Enter Speciality ";
		this->setSpeciality ( input_Str(std::cin));
		break;
	}
	case 6: {
		std::cout << " Enter List papers ";
		this->setListpapers( input_INT(std::cin, 0, 500));
		break;
	}	
	case 7: 
		std::cout << " Enter NameParty";
		this->NameParty = input_Str(std::cin); break;
	case 8: std::cout << " Enter Biogrophy";
		this->Biogrophy = input_Str(std::cin); break;
	case 9: 
		std::cout << " Enter Rol In Party"; 
		this->Rol_In_Party = input_Str(std::cin); break;
	}

}

std::istream& operator>>(std::istream& in, TeacherParty& obj)
{
	in >> dynamic_cast<teacher&>(obj);
	std::cout << " Enter Name Party. ";
	obj.setNameParty(input_Str(in));
	std::cout << " Enter Biography. ";
	obj.setBiogrophy(input_Str(in));
	std::cout << " Enter rol in party. ";
	obj.setRol_In_Party(input_Str(in));
	return in;
}

std::ostream& operator<<(std::ostream& out, TeacherParty& obj)
{
	out << dynamic_cast<teacher&>(obj)
		<< std::setw(20) << std::right << obj.getNameParty()
		<< std::setw(25) << std::right << obj.getBiogrophy()
		<< std::setw(23) << std::right << obj.Rol_In_Party << std::endl;
	return out;
}

std::fstream& operator>>(std::fstream& f, TeacherParty& obj)
{
	f >> dynamic_cast<teacher&>(obj);
	char buf[size]{};


	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	obj.NameParty = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	obj.Biogrophy = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	obj.Rol_In_Party = ss;
	return f;


}

std::fstream& operator<<(std::fstream& f, TeacherParty& obj)
{
	f << dynamic_cast<teacher&>(obj);

	char buf[size];

	strcpy_s(buf, obj.NameParty.length() + 1, obj.NameParty.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, obj.Biogrophy.length() + 1, obj.Biogrophy.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, obj.Rol_In_Party.length() + 1, obj.Rol_In_Party.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	return f;
}

std::ifstream& operator>>(std::ifstream& f, TeacherParty& obj)
{
	f >> dynamic_cast<teacher&>(obj)
		>> obj.NameParty >> obj.Biogrophy >> obj.Rol_In_Party;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, TeacherParty& obj)
{
	f << dynamic_cast<person&>(obj)
		<< obj.getPosition() << " "
		<< obj.getSpeciality() << " "
		<< obj.getListpapers() << " "
		<< obj.NameParty << " "
		<< obj.Biogrophy << " "
		<< obj.Rol_In_Party << std::endl;
	return f;
}


