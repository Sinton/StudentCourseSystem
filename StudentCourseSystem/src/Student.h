#ifndef _STUDENT_H
#define _STUDENT_H
#include "header.h"

class Student
{
public:
	static string loginUid;  // 登录用户
	static string profile[]; // 学生个人资料标头

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

	void login();                            // 登录
	void createStudent();                    // 添加学生信息
	void updateStudent();                    // 更新学生信息
	void deleteStudent();                    // 删除学生信息
	void showStudentByUid(string uid);       // 根据学号显示学生信息
	void showStudentByName(string name);     // 根据姓名显示学生信息
	void showAllStudents();					 // 获取全部学生
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

#endif