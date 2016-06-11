#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"

string Menu::identity = "";

void Menu::systemMenu()
{
	system("cls");
	cout << "\n\t\t\t       系统管理菜单" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.录入课程\t5.录入学生" << endl;
	cout << "2.查询课程\t6.查询学生" << endl;
	cout << "3.删除课程\t7.删除学生" << endl;
	cout << "4.修改课程\t8.退出系统" << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "请选择功能：(1~8)" << endl;
	switch (choose('8'))
	{
	case '1':
	{
		Course course;
		course.createCourse();
		break;
	}
	case '2':
	{
		break;
	}
	case '3':
	{
		break;
	}
	case '4':
	{
		break;
	}
	case '5':
	{
		Student student;
		student.createStudent();
		break;
	}
	case '6':
	{
		break;
	}
	case '7':
	{
		break;
	}
	case '8':
	{
		break;
	}
	}
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
	cout << endl;
	cout << "1.学生登录" << endl;
	cout << "2.进入管理系统" << endl;
	cout << "3.退出系统\n" << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "请选择功能：(1~3)" << endl;
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
		systemMenu();
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
	cout << endl << "请选择功能：(1~5):";
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
{
}

Menu::~Menu()
{
}