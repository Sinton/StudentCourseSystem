#include "Student.h"
#include "StudentDao.h"
#include "Menu.h"

vector<Student> stu_vec;
vector<Student> Student::vStudents = stu_vec;
vector<Student>::iterator Student::iterStudent = vStudents.begin();
string Student::loginUid = "";

void Student::login()
{
	
	cout << "请输入学号: ";
	loginUid = inputString();
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByUid(loginUid);
	if (studentDao.checkUidExits(loginUid))
		Menu::studentMenu();
	else
	{
		cout << "学号错误!" << endl;
		this->login();
	}
}

void Student::createStudent()
{
	Student student;
	cout << "请输入学号：" << endl;
	student.setUid(inputString());
	cout << "请输入姓名：" << endl;
	student.setName(inputString());
	cout << "请输入性别：" << endl;
	student.setSex(inputString());
	cout << "请输入绩点：" << endl;
	student.setCredit(inputString());
	cout << "请输入年级：" << endl;
	student.setGrade(inputString());
	cout << "请输入专业：" << endl;
	student.setMajor(inputString());
	cout << "请输入院系：" << endl;
	student.setDepartment(inputString());
	StudentDao studentDao;
	studentDao.addStudent(student);
}

void Student::updateStudent()
{

}

void Student::deleteStudent()
{

}

void Student::showStudentByUid(string uid)
{
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByUid(uid);
	vector<string>::iterator iterator;
	// 打印获取到的学生信息
	for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
		cout << iterator->data() << endl;
	system("pause");
}

void Student::showStudentByName(string name)
{
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByName(name);
	vector<string>::iterator iterator;
	// 打印获取到的学生信息
	for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
		cout << iterator->data() << endl;
	system("pause");
}

void Student::showAllStudents()
{
	StudentDao studentDao;
	vector<Student> students = studentDao.getAllStudents();
	if (students.empty())
	{
		cout << "没有记录课程信息!\n";
		system("pause");
		return;
	}
	cout << "\n课程信息如下：\n" << endl;
	for (vector<Student>::iterator iter = students.begin(); iter != students.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "学号：" << iter->getUid() << endl
			<< "姓名：" << iter->getName() << endl
			<< "性别：" << iter->getSex() << endl
			<< "绩点：" << iter->getCredit() << endl
			<< "年级：" << iter->getGrade() << endl
			<< "专业：" << iter->getMajor() << endl
			<< "院系：" << iter->getDepartment() << endl << endl;
	}
	system("pause");
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