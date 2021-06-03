#pragma once
#include "File.h"
#include "teacher.h"
#include "party.h"
#include "TeacherParty.h"
#include <deque>
#include <algorithm>

using namespace std;


template<class T>
void Print(typename deque<T>::iterator it_begin, typename deque<T>::iterator it_end)
{
    for (int i = 0; it_begin != it_end; it_begin++, i++) {
        std::cout << i + 1 << *it_begin << std::endl;
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
    my_interface(): flag_file(0), fileName("") { }
	~my_interface() { }
	void menu();
	void my_function();
};