#include <iostream>
#include "person.h"
#include "File.h"
#include "File.cpp"
#include <list>

using namespace std;

int main()
{
    std::list<person> ob;

    bool flag = true;
    do {
        int count;
        cout << " 1 Add \n 2 delete \n 3 read \n 4 write \n  5 show \n 0 exit\n\t" << endl;
        cout << "enter count \n\t"; cin >> count;

        switch (count)
        {
        case 1: {

            person pp;
            cin >> pp;
            ob.push_front(pp);
            break;

        }
        case 3: {
            person data;

            FileBin<person> file("person.txt");
            while (1)
            {
                file.ReadBin(data);
                if (file.EndOfFile())
                    break;
                ob.push_back(data);
            }

            break;
        }
        case 4: {
            person data;

            FileBin<person> file("person.txt");
            while (!ob.empty())
            {
                data = ob.front();
                file.WriteBin(data);
                ob.pop_front();
            }
            break;
        }
        case  5: {

            list<person>::iterator it;
            for (it = ob.begin(); it != ob.end(); it++)
                cout << (*it) << endl;
            break;

        }
        case 0: {
            flag = false;
            break;

        }
        default:
            break;
        }

    } while (flag);

}
