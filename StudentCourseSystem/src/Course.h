#ifndef _COURSE_H
#define _COURSE_H
#include "header.h"

class Course
{
public:
	//记录课程信息
	static vector<Course> courseVector;

	// set属性
	void setCourseId(string courseId){ this->courseId = courseId; }
	void setCourseName(string courseName){ this->courseName = courseName; }
	void setCourseCredit(string courseCredit){ this->courseCredit = courseCredit; }
	void setProperty(string property){ this->property = property; }
	void setTeacher(string teacher){ this->teacher = teacher; }
	void setCourseDepartment(string courseDepartment){ this->courseDepartment = courseDepartment; }
	void setTotalPeriod(string totalPeriod){ this->totalPeriod = totalPeriod; }
	void setClassPeriod(string classPeriod){ this->classPeriod = classPeriod; }
	void setLabPeriod(string labPeriod){ this->labPeriod = labPeriod; }
	void setMemberMax(string memberMax){ this->memberMax = memberMax; }
	void setMemberJoin(string memberJoin){ this->memberJoin = memberJoin; }
	void setStartTerm(string startTerm){ this->startTerm = startTerm; }

	// get属性
	string getCourseId(){ return courseId; }
	string getCourseName(){ return courseName; }
	string getCourseCredit(){ return courseCredit; }
	string getProperty(){ return property; }
	string getTeacher(){ return teacher; }
	string getCourseDepartment(){ return courseDepartment; }
	string getTotalPeriod(){ return totalPeriod; }
	string getClassPeriod(){ return classPeriod; }
	string getLabPeriod(){ return labPeriod; }
	string getMemberMax(){ return memberMax; }
	string getMemberJoin(){ return memberJoin; }
	string getStartTerm(){ return startTerm; }

	void createCourse();     // 添加课程
	void updateCourse();     // 更新课程信息
	void modifyMemberJoin(string courseId); // 更新课程信息
	void deleteCourse();     // 删除课程
	void showAllCourses();   // 显示全部课程
	void showCoursesByName(string name);    // 按照课程名称查找课程
	void showCoursesByCredit(string credit);// 按照课程学分查找课程
	Course();
	~Course();
private:
	string courseId;           // 课程编号
	string courseName;         // 课程名称
	string courseCredit;       // 课程学分
	string property;           // 课程性质
	string teacher;            // 授课教师
	string courseDepartment;   // 开课院系
	string totalPeriod;        // 总课时
	string classPeriod;        // 上课课时
	string labPeriod;          // 实验课时
	string memberMax;          // 人数上限
	string memberJoin;         // 已选人数
	string startTerm;          // 开始授课学期
};

#endif