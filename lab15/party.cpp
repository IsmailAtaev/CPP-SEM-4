#include "party.h"

party::party(std::string Lname, std::string Fname, int YearOfBirth,
	std::string NameParty, std::string Biogrophy)
	:person(Lname,Fname,YearOfBirth)
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
	if (this->getLastname() == obj.getLastname() &&
		this->getFirstname() == obj.getFirstname() &&
		this->getYear() == obj.getYear() &&
		this->NameParty == obj.NameParty && 
		this->Biogrophy == obj.Biogrophy) {
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

std::istream& operator>>(std::istream& in, party& obj)
{
	in >> dynamic_cast<person&>(obj);
	obj.setNameParty(input_Str(in));
	obj.setBiogrophy(input_Str(in));
	return in;
}

std::ostream& operator<<(std::ostream& out, party& obj)
{
	out << dynamic_cast<person&>(obj)
		<< obj.NameParty
		<< obj.Biogrophy;
	return out;
}
