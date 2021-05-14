#pragma once
#include "person.h"

class party :
    public person
{
private:
    std::string NameParty;
    std::string Biogrophy;
public:
    party(std::string Fname = "", std::string Lname = "", int YearOfBirth = 0,
        std::string NameParty = "", std::string Biogrophy = "");
    party(const party& obj);
    ~party() { }
    party& operator =(const party& obj);
    void setNameParty(const std::string objNameParty);
    void setBiogrophy(const std::string objBiogrophy);

    std::string getNameParty()const;
    std::string getBiogrophy()const;

    bool operator==(party& obj);
    bool operator != (party& obj);

    friend std::istream& operator>>(std::istream& in, party& obj);
    friend std::ostream& operator<<(std::ostream& out, party&);

    friend std::fstream& operator>> (std::fstream& f, party& obj);
    friend std::fstream& operator<< (std::fstream& f, party& obj);

    friend std::ifstream& operator>> (std::ifstream& f, party& obj);
    friend std::ofstream& operator<< (std::ofstream& f, party& obj);
    void get_type_sort()override
    {
        std::cout << "=====<Sort>=====" << std::endl;
        std::cout << " 1  LastName." << std::endl;
        std::cout << " 2. FistName." << std::endl;
        std::cout << " 3. Year." << std::endl;
        std::cout << " 4. NameParty." << std::endl;
        std::cout << " 5. Biogrophy." << std::endl;
      // return  input_INT(std::cin, 1, 6);
    }
};

