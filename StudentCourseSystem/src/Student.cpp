#include "Student.h"
#include "StudentDao.h"
#include "Menu.h"

vector<Student> stu_vec;
//vector<Student> Student::vStu = stu_vec;
//vector<Student>::iterator Student::itCurr = vStu.begin();

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
		if (studentDao.checkUidExits(uid))
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

void Student::createStudent()
{
	Student student;
	cout << "请输入学号：" << endl;
	student.uid = inputString();
	cout << "请输入姓名：" << endl;
	student.name = inputString();
	cout << "请输入性别：" << endl;
	student.sex = inputString();
	cout << "请输入绩点：" << endl;
	student.credit = inputString();
	cout << "请输入年级：" << endl;
	student.grade = inputString();
	cout << "请输入专业：" << endl;
	student.major = inputString();
	cout << "请输入院系：" << endl;
	student.department = inputString();
	StudentDao studentDao;
	studentDao.addStudent(student);
}

void Student::updateStudent()
{

}

void Student::deleteStudent()
{

}

void Student::showStudent(string uid)
{
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByUid(uid);
	vector<string>::iterator iterator;
	// 打印获取到的学生信息
	for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
		cout << iterator->data() << "=" << endl;
}

Student::Student()
{
	uid = "";
	name = "";
	sex = "";
	credit = "";
	grade = "";
	major = "";
	department = "";
}

Student::~Student()
{

}