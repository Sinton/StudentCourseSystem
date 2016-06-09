#include <iostream>
#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"
#define MAX_ITEM 5

using namespace std;

void Menu::systemMenu()
{
}

void Menu::chooseRole()
{
	cout << "\n\t\t\t       欢迎使用学生选课系统" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "请选择你的身份：" << endl;
	cout << "\t1.学生" << endl;
	cout << "\t2.管理员" << endl;
	cout << "\t3.退出系统" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "请选择（1-3）进行操作" << endl;
	switch (choose('3'))
	{
		case '1':
		{
			Student student;
			student.login();
			break;
		}
		case '2':
		{
			cout << "===";
			break;
		}
		default:
			break;
	}
}

Menu::Menu()
{}

Menu::~Menu()
{}