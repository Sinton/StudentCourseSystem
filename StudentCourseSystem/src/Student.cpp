#include <iostream>
#include "header.h"
#include "Student.h"
#include "Menu.h"
#include "StudentDao.h"

using namespace std;

vector<Student> stu_vec;
vector<Student> Student::vStu = stu_vec;
vector<Student>::iterator Student::itCurr = vStu.begin();

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
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t       学生登录" << endl;
		for (int i = 0; i < 80; i++)
			cout << "*";
		cout << "请输入学号：";
		string uid = inputString();
		StudentDao studentDao;
		vector<string> studentInfo = studentDao.getStudentByUid(uid);
		vector<string>::iterator iterator;
		// 打印获取到的学生信息
		for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
			cout << iterator->data() << "=" << endl;
		if (!studentInfo.empty())
		{
			Menu::studentMenu();
		}
		else
		{
			system("cls");
			cout << "\t\t\t学号错误!请重新输入!" << endl;
			cout << "\t\t\t该系统还未记录学生信息" << endl;
			system("pause");
		}
	}
}