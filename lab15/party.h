#pragma once
#include "person.h"

class party :virtual   public person
{
protected:
    std::string NameParty;
    std::string Biogrophy;
public:
    party(std::string Lname = "", std::string Fname = "", int YearOfBirth = 0,
        std::string NameParty = "", std::string Biogrophy = "");
    party(const party& obj);
    ~party() { }
    party& operator =(const party& obj);
    void setNameParty(const std::string objNameParty);
    void setBiogrophy(const std::string objBiogrophy);

    std::string getNameParty()const;
    std::string getBiogrophy()const;
    bool operator==(const party& obj);
    bool operator != (party& obj);

    friend std::istream& operator>>(std::istream& in, party& obj);
    friend std::ostream& operator<<(std::ostream& out, party&);

    friend std::fstream& operator>> (std::fstream& f, party& obj);
    friend std::fstream& operator<< (std::fstream& f, party& obj);

    friend std::ifstream& operator>> (std::ifstream& f, party& obj);
    friend std::ofstream& operator<< (std::ofstream& f, party& obj);
    static void title();
    void Search();
    void Edit();
};