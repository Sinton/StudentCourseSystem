#include <iostream>
#include "header.h"
#include "Student.h"
#include "Menu.h"
#include "StudentDao.h"

using namespace std;

Student::Student()
{
	uid = "";
	name = "";
	sex = "";
	credit = 0;
	grade = "";
	major = "";
	department = "";
}

Student::~Student()
{

}

int Student::login()
{
	system("cls");	
	//while (vStu.empty())
	//{
	//	cout << "该系统还未记录学生信息!不能登入，请录入你的信息!\n";
	//	system("pause");
	//	//StuPutin();
	//}
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t       学生登录" << endl;
		for (int i = 0; i < 80; i++)
			cout << "*";
		cout << "\t请输入学号:";
		string uid = inputString();
		StudentDao studentDao;
		studentDao.getStudentByUid(uid);
		system("pause");
		if (uid == "111")
		{
			cout << "\t\t\t\t登录成功!\n\n";
			system("pause");
			system("cls");
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n";
			cout << "\t\t\t学号错误!请重新输入!\n";
			system("pause");
		}
	}
}