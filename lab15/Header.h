#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <deque>
#include <limits>

constexpr auto size = 40;

inline std::string input_Str(std::istream& in)
{
	std::string ss;
	bool flag = false;
	do {
		try {
			flag = false;
			rewind(stdin);
			std::getline(in, ss, '\n');

			for (int i = 0; i < ss.length(); i++) {
				if ((ss[i] < 'a' || ss[i] > 'z') && (ss[i] < 'A' || ss[i] > 'Z'))
					throw std::exception(" Inappropriate input \n Please enter English letters !!!");
			}
		}
		catch (std::exception& ex) {
			flag = true;
			ex.what();
			system("pause");
			std::cout << " Try again\n ";
		}
		catch (...) {
			flag = true;
			system("pause");
			std::cout << " Something went wrong\t(try|catch(...))\n";
		}
	} while (flag);
	system("cls");
	return ss;
}

inline int input_INT(std::istream& in, int t, int k)
{
	int flags = 0;
	int temp = 0;
	do {
		try {
			flags = 0;
			in >> temp;
			if (temp < t || temp > k)
				throw std::out_of_range(" The range of values ​​exceeds Enter less<= ");

			if (temp >= INT_MAX || temp <= INT_MIN)
				throw std::overflow_error(" The range of values ​​exceeds int 2147483647 ");

			if (!in || in.peek() != '\n')
				throw  std::exception(" Incorrect input \n Please enter only whole numbers  !!!");

			
		}
		catch (std::overflow_error exz) {
			std::cout << exz.what() << std::endl;
			rewind(stdin);

			in.clear(0);
			system("pause");
			flags = 1;
			std::cout << " Try again\n ";
		}
		catch (std::out_of_range ee) {
			std::cout << ee.what() << k << " larger >= " << t << std::endl;
			rewind(stdin);
			in.clear(0);
			system("pause");
			flags = 1;
			std::cout << " Try again " << std::endl;
		}
		catch (std::exception ex) {
			ex.what();
			rewind(stdin);
			in.clear(0);
			system("pause");
			flags = 1;
			std::cout << " Try again\n ";
		}
		
		catch (...) {
			flags = 1;
			rewind(stdin);
			in.clear(0);
			std::cout << " Something went wrong\t(try|catch(...))\n";
		}
	} while (flags);
	system("cls");
	return temp;
}
