#pragma once
#include "File.h"
#include "teacher.h"
#include "my_algorithm.h"
#include <deque>
#include <algorithm>

template<class T>
inline void Print(deque<T>& obj)
{
    if (!obj.empty()) {
        int i = 0;
        for (typename deque<T>::iterator it = obj.begin(); it != obj.end(); it++, i++)
        {
            std::cout << i + 1 << *it << std::endl;
        }
    }
    else {
        std::cout << " There is nothing " << std::endl;
    }
}

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
        std::cout << " 0. Exit. " << std::endl;
        std::cout << "======================\n\t";
        ch = input_INT(std::cin, 0, 3);
        system("cls");
        switch (ch) {
        case 1: {
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
        std::cout << " 1. Add." << std::endl;
        std::cout << " 2. Print." << std::endl;
        std::cout << " 3. Delete." << std::endl;
        std::cout << " 4. Delete All." << std::endl;
        std::cout << " 5. Searche." << std::endl;
        std::cout << " 6. Edit." << std::endl;
        std::cout << " 7. Sort." << std::endl;
        std::cout << " 8. Read with file." << std::endl;
        std::cout << " 9. Write with file." << std::endl;
        std::cout << " 0  Exit." << std::endl;
        std::cout << "_________________________\t";
        temp = input_INT(std::cin, 0, 9);
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
            Print(ob);
            break;
        }
        case 3: {
            if (!ob.empty())
                ob.pop_front();
            else
                std::cout << " There is nothing " << std::endl;
            break;
        }
        case 4: {
            if (!ob.empty()) {
                ob.clear();
            }
            break;
        }
        case 5: {
            if (!ob.empty()) {
                T value{};
                std::cin >> value;
                typename deque<T>::iterator it = find(ob.begin(), ob.end(), value);
                if (it == ob.end()) {
                    std::cout << " Not elemt in deque " << std::endl;
                }
                else {
                    std::cout << *it << std::endl;
                }
            }
            else { std::cout << " Nothing searh deque empty !!!" << std::endl; }
            break;
        }
        case 6: {
            Print(ob);
            if (!ob.empty()) {
                int coutn = 0;
                std::cout << " Enter number for edit " << std::endl;
                std::cin >> coutn;
                --coutn;
                if (coutn < ob.size()) {
                    auto it = ob.begin();
                    for (int i = 0; i < coutn; i++)
                        it++;

                    (*it).get_type_sort();
                }
            }
            break;
        }
        case 7: {
            if (!ob.empty()) {
                std::cout << " 1. lastName" << std::endl;
                std::cout << " 2. FirstName." << std::endl;
                std::cout << " 3. Year." << std::endl;
                int temp = input_INT(std::cin, 1, 3);
                switch (temp)
                {
                case 1: {
                    std::sort(ob.begin(), ob.end(), [](T obj1, T obj2) -> bool
                        {
                            return obj1.getLastname() < obj2.getLastname();
                        });
                    break;
                }
                case 2: {
                    std::sort(ob.begin(), ob.end(), [](T obj1, T obj2) -> bool
                        {
                            return obj1.getFirstname() < obj2.getFirstname();
                        });
                    break;
                }
                case 3: {
                    std::sort(ob.begin(), ob.end(), [](T obj1, T obj2) -> bool
                        {
                            return obj1.getYear() < obj2.getYear();
                        });
                    break;
                }
                default:
                    break;
                }
            }
            else {
                std::cout << " Nothing sort deque empty !!!" << std::endl;
            }
            break;
        }
        case 8: {
            T data;
            ob.clear();
            if (this->flag_file == 1) {
                FileTXT<T> txt(this->fileName);
                txt.fileTxTOpenIn();
                while (1) {
                    txt.readTxt(data);
                    if (txt.FileTxTeofIn()) {
                        txt.fileTxTCloseIn();
                        break;
                    }
                    ob.push_back(data);
                }
            }
            else if (this->flag_file == 2) {
                FileBin<T> bin(this->fileName);
                while (1) {
                    bin.ReadBin(data);
                    if (bin.EndOfFile())
                        break;
                    ob.push_back(data);
                }
            }
            else {
                std::cout << " error (state file != 1 and 2 ) global error " << std::endl;
            }
            break;
        }
        case 9: {
            if (!ob.empty()) {
                T data{};
                if (this->flag_file == 1) {
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
                else if (this->flag_file == 2) {
                    FileBin<T> bin(this->fileName);
                    while (!ob.empty()) {
                        data = ob.front();
                        bin.WriteBin(data);
                        ob.pop_front();
                    }
                }
                else {
                    std::cout << " error (state file != 1 and 2 ) global error " << std::endl;
                }
            }
            break;
        }
        }
        system("pause");
        system("cls");
    } while (temp);
}