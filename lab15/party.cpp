#include "party.h"

party::party(std::string Lname, std::string Fname, int YearOfBirth,
	std::string NameParty, std::string Biogrophy) :person(Lname,Fname,YearOfBirth)
{
	this->NameParty = NameParty;
	this->Biogrophy = Biogrophy;
}

party::party(const party& obj) :person(obj)
{
	this->NameParty = obj.NameParty;
	this->Biogrophy = obj.Biogrophy;
}

party& party::operator=(const party& obj)
{
	if (this != &obj) {
		this->setLastname(obj.getLastname());
		this->setFirstname(obj.getFirstname());
		this->setYear(obj.getYear());
		this->NameParty = obj.NameParty;
		this->Biogrophy = obj.Biogrophy;
	}
	return *this;
}

void party::setNameParty(const std::string objNameParty)
{
	this->NameParty = objNameParty;
}

void party::setBiogrophy(const std::string objBiogrophy)
{
	this->Biogrophy = objBiogrophy;
}

std::string party::getNameParty() const
{
	return this->NameParty;
}

std::string party::getBiogrophy() const
{
	return this->Biogrophy;
}

bool party::operator==(const party& obj)
{
	if ((this->getLastname() == obj.getLastname() || obj.getLastname() == "") &&
		(this->getFirstname() == obj.getFirstname() || obj.getFirstname() == "") &&
		(this->getYear() == obj.getYear() || obj.getYear() == 0) && 
		(this->NameParty == obj.NameParty || obj.NameParty == "") && 
		(this->Biogrophy == obj.Biogrophy || obj.Biogrophy == "")) {
		return true;
	}
	else {
		return false;
	}
}

bool party::operator!=(party& obj)
{
	if (this->getLastname() != obj.getLastname() &&
		this->getFirstname() != obj.getFirstname() &&
		this->getYear() != obj.getYear() &&
		this->NameParty != obj.NameParty &&
		this->Biogrophy != obj.Biogrophy) {
		return true;
	}
	else {
		return false;
	}
}

void party::title()
{
	std::cout << "+---+---------------+-----------+---------------+---------------+----------------------------+" << std::endl;
	std::cout << "| N |   Lastname    | Fistname  |     Year      |      Party    |          Biogrophy         |" << std::endl;
	std::cout << "+---+---------------+-----------+---------------+---------------+----------------------------+" << std::endl;
}


void party::Search()
{
	std::cout << "=====< Search >=====" << std::endl;
	std::cout << " 1  LastName." << std::endl;
	std::cout << " 2. FistName." << std::endl;
	std::cout << " 3. Year." << std::endl;
	std::cout << " 4. NameParty." << std::endl;
	std::cout << " 5. Biogrophy." << std::endl;
	std::cout << " 0  Exit " << std::endl;
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
		std::cout << " Enter NameParty ";
		this->NameParty = input_Str(std::cin);
		break;
	}
	case 5: {
		std::cout << " Enter Biogrophy ";
		this->Biogrophy = input_Str(std::cin);
		break;
	}
	case 0: break;
	}
}

void party::Edit()
{
	std::cout << "=====<Edit>=====" << std::endl;
	std::cout << " 1  LastName." << std::endl;
	std::cout << " 2. FistName." << std::endl;
	std::cout << " 3. Year." << std::endl;
	std::cout << " 4. NameParty." << std::endl;
	std::cout << " 5. Biogrophy." << std::endl;
	int count = input_INT(std::cin, 1, 5);
	switch (count)
	{
	case 1: this->setLastname(input_Str(std::cin));	break;
	case 2: this->setFirstname(input_Str(std::cin)); break;
	case 3: this->setYear(input_INT(std::cin, 1910, 2022)); break;
	case 4: this->NameParty = input_Str(std::cin); break;
	case 5: this->Biogrophy = input_Str(std::cin); break;
	}
}
std::istream& operator>>(std::istream& in, party& obj)
{
	in >> dynamic_cast<person&>(obj);
	std::cout << " Enter NameParty ";
	obj.setNameParty(input_Str(in));
	std::cout << " Enter Biogrophy ";
	obj.setBiogrophy(input_Str(in));
	return in;
}

std::ostream& operator<<(std::ostream& out, party& obj)
{
	out << dynamic_cast<person&>(obj)
		<< std::setw(17) << std::right << obj.NameParty
		<< std::setw(25) << std::right << obj.Biogrophy;
	return out;
}

std::fstream& operator>>(std::fstream& f, party& obj)
{
	f >> dynamic_cast<person&>(obj);
	char buf[size]{};
	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	obj.NameParty = ss;
	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	obj.Biogrophy = ss;
	return f;
}

std::fstream& operator<<(std::fstream& f, party& obj)
{
	f << dynamic_cast<person&>(obj);
	char buf[size];
	strcpy_s(buf, obj.NameParty.length() + 1, obj.NameParty.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));
	strcpy_s(buf, obj.Biogrophy.length() + 1, obj.Biogrophy.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));
	return f;
}

std::ifstream& operator>>(std::ifstream& f, party& obj)
{
	f >> dynamic_cast<person&>(obj) >> obj.NameParty >> obj.Biogrophy;
	return f;
}

std::ofstream& operator<<(std::ofstream& f, party& obj)
{
	f << dynamic_cast<person&>(obj) << obj.NameParty << " " << obj.Biogrophy << std::endl;
	return f;
} 
