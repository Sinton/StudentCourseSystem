#include <iostream>
#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"

using namespace std;

char choose(char i)
{
	char operate;
	cin >> operate;
	cin.ignore(100, '\n');
	while (operate < '1' || operate > i)
	{
		cout << "输入错误!\t重新输入: ";
		cin >> operate;
		cin.ignore(100, '\n');
	}
	while (operate == i)
	{
		Student student;
		Course course;
		exit(0);
	}
	return operate;
}

//int inputNumber()
//{
//	int number, numberTemp;
//	numberTemp = scanf("%d", &number);
//	cin.ignore(100, '\n');
//	while (numberTemp == 0)
//	{
//		cout << "输入错误!需输入数字!\n重新输入: ";
//		cin.ignore(100, '\n');
//		numberTemp = scanf("%d", &number);
//	}
//	return number;
//}

char inputChar()
{
	char c = cin.get();
	cin.ignore(100, '\n');
	return c;
}

string inputString()
{
	string str;
	getline(cin, str);
	return str;
}

int main()
{
	Menu menu;
	menu.chooseRole();
	return 0;
}