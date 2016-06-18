#ifndef _SELECT_COURSE_H
#define _SELECT_COURSE_H
#include "header.h"

class SelectCourse
{
public:

	// set属性
	void setRecordId(string recordId){ this->recordId; }
	void setUid(string uid){ this->uid; }
	void setCourseName(string courseName){ this->courseName; }
	void setCourseGrade(string courseGrade){ this->courseGrade; }
	void setGainCredit(string gainCredit){ this->gainCredit; }

	// get属性
	string getRecordId(){ return recordId; }
	string getUid(){ return uid; }
	string getCourseName(){ return courseName; }
	string getCourseGrade(){ return courseGrade; }
	string getGainCredit(){ return gainCredit; }

	void createRecord();     // 添加选课记录
	void updateRecord();     // 更新选课记录
	void deleteRecord();     // 删除选课记录
	void showAllOptionalCourse();// 获取全部可选课程
	void showAllRecordByUid();   // 获取全部已选课程
	SelectCourse();
	~SelectCourse();
private:
	string recordId;   // 选课记录编号
	string uid;        // 选课学生学号
	string courseName; // 所选课程名称
	string courseGrade;// 所选课程成绩
	string gainCredit; // 获得的学分
};

#endif