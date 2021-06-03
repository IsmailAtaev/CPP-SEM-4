#include "my_interface.h"

template<class T>
void my_interface<T>::menu()
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
        case 2:
        {
            std::string filenameP;
            if (state == 1)
                filenameP = "party.txt";
            else if (state == 2)
                filenameP = "partyBin.txt";
            else
                break;

            my_interface<party> objParty(filenameP, state);
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

            my_interface<TeacherParty> objTeacher_Party(filenameTP, state);
            objTeacher_Party.my_function();
            break;
        }
        default:
            ch = 0;
            break;
        }
    } while (ch != 0);
}

template<class T>
void my_interface<T>::my_function()
{
    deque<T> ob;
    int temp = 0;
    do {
        system("cls");
        std::cout << " ---===[ Menu selection ]===---" << std::endl;
        std::cout << " 1. Add." << std::endl;
        std::cout << " 2. Print." << std::endl;
        std::cout << " 3. Delete." << std::endl;
        std::cout << " 4. Searche." << std::endl;
        std::cout << " 5. Edit." << std::endl;
        std::cout << " 6. Sort." << std::endl;
        std::cout << " 7. Read with file." << std::endl;
        std::cout << " 8. Write with file." << std::endl;
        std::cout << " 0  Exit." << std::endl;
        std::cout << " Enter number \t";
        temp = input_INT(std::cin, 0, 8);
        system("cls");
        switch (temp)
        {
        case 1:
        {
            T value{};
            rewind stdin;
            std::cin >> value;
            ob.push_back(value);
            break;
        }
        case 2:
        {
            if (!ob.empty()) {
                T::title();
                Print<T>(ob.begin(), ob.end());
            }
            else
                std::cout << " Nothing elements  for view " << std::endl;

            break;
        }
        case 3:
        {
            if (!ob.empty())
            {
                std::cout << " 1. Delete pop_front." << std::endl;
                std::cout << " 2. Delete All." << std::endl;
                std::cout << " 3. Delete remove earase(remove())." << std::endl;
                std::cout << " 4. Delete from and to." << std::endl;
                std::cout << " 0. Exit " << std::endl;
                std::cout << " Enter number " << std::endl;
                switch (input_INT(std::cin, 0, 4))
                {
                case 1:
                {
                    ob.pop_front();
                    break;
                }
                case 2: 
                {
                    ob.clear();
                    break;
                }
                case 3: 
                {
                    Print<T>(ob.begin(), ob.end());
                    std::cout << " Enter number for delete " << std::endl;
                    int elem = input_INT(std::cin, 1, ob.size()) - 1;
                    T temp = ob.at(elem);
                    ob.erase(remove(ob.begin(), ob.end(), temp), ob.end());
                    break;
                }
                case 4: 
                {
                    T::title();
                    Print<T>(ob.begin(), ob.end());
                    std::cout << " Enter number for delete  from \t" << std::endl;
                    int elem = input_INT(std::cin, 1, ob.size()) - 1;
                   
                    std::cout << " Enter number for delete  to \t" << std::endl;
                    int elem2 = input_INT(std::cin, 1, ob.size());

                    if (elem2 < elem){
                        std::cout << "enter > please  " << elem << std::endl;
                        break;
                    }

                    int m = ob.size() - elem2;
                    ob.erase(ob.begin() + elem, ob.begin() + elem2);
                    //ob.erase(ob.begin() + elem, ob.end() - m);
                }
                default:
                    break;
                }
            }
            else {
                std::cout << " There is nothing " << std::endl;
            }
            break;
        }
        case 4:
        {
            if (!ob.empty()) {
                T value{};
                value.Search();
                auto it = find(ob.begin(), ob.end(), value);
                T::title();
                if (it == ob.end()) {
                    system("cls");
                    std::cout << " Not elemt in deque " << std::endl;
                }
                else {
                    std::cout << *it << std::endl;
                }
            }
            else {
                std::cout << " Nothing searh deque empty !!!" << std::endl;
            }
            break;
        }
        case 5:        {
            if (!ob.empty())
            {
                Print<T>(ob.begin(), ob.end());
                std::cout << " Enter number for edit " << std::endl;
                int coutn = input_INT(std::cin, 1, ob.size()) - 1;
                ob[coutn].Edit();
            }
            break;
        }

        case 6:
        {
            if (!ob.empty()) {
                std::cout << " 1. lastName" << std::endl;
                std::cout << " 2. FirstName." << std::endl;
                std::cout << " 3. Year." << std::endl;
                std::cout << " Enter number " << std::endl;
                int temp = input_INT(std::cin, 1, 3);
                switch (temp)
                {
                case 1: {
                    std::sort(ob.begin(), ob.end(), [](T obj1, T obj2) -> bool {return obj1.getLastname() < obj2.getLastname(); });
                    break;
                }
                case 2: {
                    std::sort(ob.begin(), ob.end(), [](T obj1, T obj2) -> bool {return obj1.getFirstname() < obj2.getFirstname(); });
                    break;
                }
                case 3: {std::sort(ob.begin(), ob.end(), [](T obj1, T obj2) -> bool {return obj1.getYear() < obj2.getYear(); });
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
        case 7:
        {
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
        case 8:
        {
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
        default: { break; }
        }
        system("pause");
        system("cls");
    } while (temp);
}