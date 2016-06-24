#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"
#include "SelectCourse.h"

string Menu::identity = "";

void Menu::adminMenu()
{
	system("cls");
	cout << "\n\t\t\t       系统管理菜单" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.录入课程" << endl;
	cout << "2.录入学生" << endl;
	cout << "3.查询课程" << endl;
	cout << "4.查询学生" << endl;
	cout << "5.返回菜单" << endl;
	cout << "6.退出系统" << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "请选择功能(1~6): ";
	switch (choose('6')) 
	{
	case '1':
	{
		Course course;
		course.createCourse();
		system("pause");
		Menu::adminMenu();
		break;
	}
	case '2':
	{
		Student student;
		student.createStudent();
		system("pause");
		Menu::adminMenu();
		break;
	}
	case '3':
	{
		Menu::courseInfoSearchMenu();
		break;
	}
	case '4':
	{
		Menu::studentInfoSearchMenu();
		break;
	}
	case '5':
	{
		Menu::isBack();
		break;
	}
	default:
		break;
	}
}

void Menu::isBack()
{
	system("cls");
	cout << "\n\t\t\t       返回菜单" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.返回主菜单" << endl;
	cout << "2.返回系统菜单" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "请选择功能(1~2): ";
	char choose = inputChar();
	while (choose != '1' && choose != '2')
	{
		cout << "\n选择错误!重新选择:";
		choose = inputChar();
	}
	switch (choose)
	{
	case '1':
	{
		if (identity == "学生")
			Menu::studentMenu();
		else
			Menu::adminMenu();
	}
	case '2':
	{
		Menu::chooseRole();
	}
	default:
		break;
	}
}

void Menu::chooseRole()
{
	system("cls");
	cout << "\n\t\t\t       欢迎使用学生选课系统" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.学生登录" << endl;
	cout << "2.进入管理系统" << endl;
	cout << "3.退出系统" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "请选择功能(1~3): ";
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
		cout << "请输入管理员密码: ";
		while ("admin" != inputString())
			cout << "密码错误！请重新输入: ";
		identity = "管理员";
		Menu::adminMenu();
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
	cout << endl;
	cout << "1.开始选课" << endl;
	cout << "2.查看个人资料" << endl;
	cout << "3.查询课程" << endl;
	cout << "4.返回菜单" << endl;
	cout << "5.退出系统" << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "请选择功能(1~5): ";
	switch (choose('5'))
	{
	case'1':
	{
		Menu::selectCourseMenu();
		break;
	}
	case'2':
	{
		Student student;
		student.showStudentByUid(Student::loginUid);
		Menu::studentMenu();
		break;
	}
	case'3':
	{
		Menu::courseInfoSearchMenu();
		break;
	}
	case'4':
	{
		Menu::isBack();
		break;
	}
	default:
		break;
	}
}

void Menu::selectCourseMenu()
{
	system("cls");
	cout << "\n\t\t\t       选课菜单" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.浏览全部可选课程" << endl;
	cout << "2.浏览全部已选课程" << endl;
	cout << "3.返回菜单" << endl;
	cout << "4.退出系统" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "\n" << endl;
	cout << "请选择功能(1~4): ";
	switch (choose('4'))
	{
	case '1':
	{
		SelectCourse selectCourse;
		selectCourse.showAllOptionalCourse();
		Menu::selectCourseMenu();
		break;
	}
	case '2':
	{
		SelectCourse selectCourse;
		selectCourse.showAllRecords();
		Menu::selectCourseMenu();
		break;
	}
	case '3':
	{
		Menu::isBack();
		break;
	}
	default:
		break;
	}
}

void Menu::courseInfoSearchMenu()
{
	system("cls");
	cout << "\n\t\t\t       课程信息查询菜单" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.课程学分" << endl;
	cout << "2.课程名称" << endl;
	cout << "3.查看全部课程" << endl;
	cout << "4.返回菜单" << endl;
	cout << "5.退出系统" << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "请选择功能(1~5): ";
	Course course;
	switch (choose('5'))
	{
	case '1':
	{
		cout << "请输入要查找的课程学分：";
		course.showCoursesByCredit(inputString());
		Menu::courseInfoSearchMenu();
		break;
	}
	case '2':
	{
		cout << "请输入要查找的课程名称：";
		course.showCoursesByName(inputString());
		Menu::courseInfoSearchMenu();
		break;
	}
	case '3':
	{
		course.showAllCourses();
		Menu::courseInfoSearchMenu();
	}
	case '4':
	{
		Menu::isBack();
	}
	default:
		break;
	}
}

void Menu::studentInfoSearchMenu()
{
	system("cls");
	cout << "\n\t\t\t       学生信息查询菜单" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.学生学号" << endl;
	cout << "2.学生名字" << endl;
	cout << "3.查看全部学生" << endl;
	cout << "4.返回菜单" << endl;
	cout << "5.退出系统" << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "请选择功能(1~5): ";
	Student student;
	switch (choose('5'))
	{
	case '1':
	{
		cout << "请输入要查找的学生学号: ";
		student.showStudentByUid(inputString());
		Menu::studentInfoSearchMenu();
		break;
	}
	case '2':
	{
		cout << "请输入查找的学生姓名: ";
		student.showStudentByName(inputString());
		Menu::studentInfoSearchMenu();
		break;
	}
	case '3':
	{
		student.showAllStudents();
		Menu::studentInfoSearchMenu();
		break;
	}
	case '4':
	{
		Menu::isBack();
		break;
	}
	default:
		break;
	}
}

Menu::Menu()
{
}

Menu::~Menu()
{
}