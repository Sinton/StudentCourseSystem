#include <iostream>
using namespace std;
class Student
{
	string uid;       // 学生学号
	string name;      // 学生姓名
	string sex;       // 学生性别
	double credit;    // 绩点
	string grade;     // 年级
	string major;     // 专业
	string department;// 院系
public:
	static vector<Student>::iterator itCurr; //当前学生序号
	static vector<Student> vStu;             //记录学生信息

	int login();                             // 登录
	void createStudent();                    // 添加学生信息
	void updateStudent();                    // 更新学生信息
	void deleteStudent();                    // 删除学生信息
	void showStudent();                      // 显示学生信息
	Student();
	~Student();
};