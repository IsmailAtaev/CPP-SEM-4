#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

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
					throw std::exception(" ����������� ����\n ������� ���������� ����� !!!");
			}
		}
		catch (std::exception& ex) {
			flag = true;
			ex.what();
			system("pause");
			std::cout << " ������� ��������\n ";
		}
		catch (...) {
			flag = true;
			system("pause");
			std::cout << " cto-to poshlo ne tak\n";
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
			if (temp >= INT_MAX || temp <= INT_MIN)
				throw std::overflow_error(" �������� ������� ��������� int 2147483647  ");

			if (!in || in.peek() != '\n')
				throw  std::exception(" ����������� ����\n ������� ������ ����� �����  !!!");

			if (temp < t || temp > k)
				throw std::out_of_range(" �������� ������� ���������  ������� ������ <= ");
		}
		catch (std::overflow_error exz) {
			std::cout << exz.what() << std::endl;
			rewind(stdin);

			in.clear(0);
			system("pause");
			flags = 1;
			std::cout << " ������� ��������\n ";
		}
		catch (std::exception ex) {
			ex.what();
			rewind(stdin);
			in.clear(0);
			system("pause");
			flags = 1;
			std::cout << " ������� ��������\n ";
		}
		catch (std::out_of_range ee) {
			std::cout << ee.what() << k << " ������ >= " << t << std::endl;
			rewind(stdin);
			in.clear(0);
			system("pause");
			flags = 1;
			std::cout << " ������� �������� " << std::endl;
		}
		catch (...) {
			flags = 1;
			rewind(stdin);
			in.clear(0);
			std::cout << " ���-�� ����� �� ��� ������ catch(...) " << std::endl;
		}
	} while (flags);
	system("cls");
	return temp;
}