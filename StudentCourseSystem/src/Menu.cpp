#include <iostream>
#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"

using namespace std;

string Menu::identity = "";

void Menu::systemMenu()
{

}

void Menu::isBack()
{
	cout << "\n\n\t是否返回主菜单？\n\n\t 1.是\n\n\t 2.退出系统\n\n请选择:";
	char choose = inputChar();
	while (choose != '1' && choose != '2')
	{
		cout << "\n选择错误!重新选择:";
		choose = inputChar();
	}
	if (choose == '1')
	{
		if (identity == "学生")
			studentMenu();
	}
}

void Menu::chooseRole()
{
	cout << "\n\t\t\t       欢迎使用学生选课系统" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "1.学生登录" << endl;
	cout << "2.管理员登录" << endl;
	cout << "3.退出系统\n" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "请选择（1-3）进行操作" << endl;
	switch (choose('3'))
	{
	case '1':
	{
		identity = "学生";
		Student student;
		student.login();
		break;
	}
	case '2':
	{
		identity = "管理员";
		ManagerMenu();
		break;
	}
	default:
		break;
	}
}

void Menu::studentMenu()
{
	system("cls");
	cout << "\n\t\t\t       学生菜单" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "\n1.开始选课" << endl;
	cout << "2.浏览课程信息" << endl;
	cout << "3.查询课程" << endl;
	cout << "4.修改资料" << endl;
	cout << "5.退出系统\n" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "\n请选择功能(1~5):";
	switch (choose('5'))
	{
		case'1':
		{
			selectCourseMenu();
			break;
		}
		case'2':
		{
			Course course;
			course.showAllCourses();
			break;
		}
		case'3':
		{
			break;
		}
		case'4':
		{
			break;
		}
	}
}

void Menu::ManagerMenu()
{

}

void Menu::selectCourseMenu()
{
	system("cls");

}

void Menu::courseInfoMenu()
{

}

void Menu::studentInfoMenu()
{

}

Menu::Menu()
{}

Menu::~Menu()
{}