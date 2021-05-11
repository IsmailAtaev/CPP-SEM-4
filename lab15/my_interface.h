#pragma once
#include "File.h"
#include "person.h"
#include "teacher.h"
#include <deque>

template<class T>
class my_interface
{
private:
	int flag_file;
	T obj;
	std::string fileName;
public:
	my_interface(std::string fileName,int flag_file) : fileName(fileName), flag_file(flag_file) { }
	my_interface() { }
	~my_interface() { }
	void menu();
	void my_function();
};

template<class T>
inline void my_interface<T>::menu()
{
    int state = 0;
    int ch = 0;
    do {
        std::cout << " =================" << std::endl;
        std::cout << " Work with FILE." << std::endl;
        std::cout << " 1. TXT." << std::endl;
        std::cout << " 2. Binary." << std::endl;
        std::cout << " 0. Exit." << std::endl;
        std::cout << " =================" << std::endl;
        state = input_INT(std::cin, 0, 2);
        if (state == 0)
            break;

        system("cls");
        std::cout << "======================" << std::endl;
        std::cout << " 1. Teacher." << std::endl;
        std::cout << " 2. Party." << std::endl;
        std::cout << " 3. Teacher_Party. " << std::endl;
        std::cout << " 0. Exit. ";
        std::cout << "======================" << std::endl;
        ch = input_INT(std::cin, 0, 3);
        system("cls");
        switch (ch)
        {
        case 1:
        {
            std::string filenameT;
            if (state == 1)
                filenameT = "teacher.txt";
            else if (state == 2)
                filenameT = "teacherBin.txt";
            else
                break;

            my_interface<teacher> objTeacher(filenameT, state);
            objTeacher.my_function();
            break;
        }
        /*   case 2:
           {
               std::string filenameP;
               if (state == 1)
                   filenameP = "party.txt";
               else if (state == 2)
                   filenameP = "partyBin.txt";

               my_interface<Party> objParty(filenameP, state);
               objParty.my_function();
               break;
           }
           case 3:
           {
               std::string filenameTP;
               if (state == 1)
                   filenameTP = "teacher_party.txt";
               else if (state == 2)
                   filenameTP = "teacher_partyBin.txt";

               my_interface<Teacher_Party> objTeacher_Party(filenameTP, state);
               objTeacher_Party.my_function();
               break;
           }*/
        default:
            ch = 0;
            break;
        }
    } while (ch != 0);
}

template<class T>
inline void my_interface<T>::my_function()
{
    deque<T> ob;
    int temp = 0;
    do {
        system("cls");
        std::cout << " ---===[ Menu selection ]===---" << std::endl;
        std::cout << " 1.  Add." << std::endl;
        std::cout << " 2.  Print." << std::endl;
        std::cout << " 3.  Delete." << std::endl;
        std::cout << " 4.  Delete All." << std::endl;
        std::cout << " 6.  Searche." << std::endl;
        std::cout << " 7.  Edit." << std::endl;
        std::cout << " 8.  Сортировать по Фамили." << std::endl;
        std::cout << " 9.  Read with file." << std::endl;
        std::cout << " 10. Write with file." << std::endl;
        std::cout << " 11. iterator.begin(); " << std::endl;
        std::cout << " 12. iterator.end(); " << std::endl;
        std::cout << " 13. for(iterator) ." << std::endl;
        std::cout << " 14. for(iterator.reverse) ." << std::endl;
        std::cout << " 0   Exit.\t  ";
        temp = input_INT(std::cin, 0, 15);
        system("cls");
        switch (temp) {
        case 1: {
            T value{};
            rewind stdin;
            std::cin >> value;
            ob.push_back(value);
            break;
        }
        case 2: {
            if (!ob.empty()) {
                for (auto it = ob.begin(); it != ob.end(); it++)
                    std::cout << *it << std::endl;
            }
            else {
                std::cout << " There is nothing " << std::endl;
            }
            break;
        }
        case 3: {
            if (!ob.empty()) {
                ob.pop_front();
            }
            else {
                std::cout << " There is nothing " << std::endl;
            }
            break;
        }
        case 4: {
            if (!ob.empty()) {
                ob.clear();
            }
            break;
        }
        case 10: {
            if (!ob.empty())
            {
                T data{};
                if (this->flag_file == 1) 
                {
                    FileTXT<T> txt(this->fileName);
                    txt.fileTxTOpenOut();
                    while (!ob.empty())
                    {
                        data = ob.front();
                        txt.writeTxt(data);
                        ob.pop_front();
                    }
                    txt.fileTxTCloseOut();
                }
                else if (this->flag_file == 2)
                {
                    FileBin<T> bin(this->fileName);
                    while (!ob.empty())
                    {
                        data = ob.front();
                        bin.WriteBin(data);
                        ob.pop_front();
                    }
                }
            }
            else {
                std::cout << " Nothing write to file" << std::endl;
            }
            break;
        }
        case 0: temp = 0; break;
            
        }
        system("pause");
        system("cls");
    } while (temp);



}

