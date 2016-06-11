#include "header.h"

class Student
{
public:
	//static vector<Student>::iterator itCurr; //当前学生序号
	//static vector<Student> vStu;             //记录学生信息

	// set属性
	void setUid(string uid){ this->uid = uid; }
	void setName(string name){ this->name = name; }
	void setSex(string sex){ this->sex = sex; }
	void setCredit(string credit){ this->credit = credit; }
	void setGrade(string grade){ this->grade = grade; }
	void setMajor(string major){ this->major = major; }
	void setDepartment(string department){ this->department = department; }

	// get属性
	string getUid(){ return uid; }
	string getName(){ return name; }
	string getSex(){ return sex; }
	string getCredit(){ return credit; }
	string getGrade(){ return grade; }
	string getMajor(){ return major; }
	string getDepartment(){ return department; }

	int login();                             // 登录
	void createStudent();                    // 添加学生信息
	void updateStudent();                    // 更新学生信息
	void deleteStudent();                    // 删除学生信息
	void showStudent(string uid);            // 显示学生信息
	Student();
	~Student();

private:
	string uid;       // 学号
	string name;      // 姓名
	string sex;       // 性别
	string credit;    // 绩点
	string grade;     // 年级
	string major;     // 专业
	string department;// 院系
};