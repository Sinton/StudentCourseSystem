#ifndef _SELECT_COURSE_H
#define _SELECT_COURSE_H
#include "header.h"

class SelectCourse
{
public:

	// set属性
	void setRecordId(string recordId){ this->recordId = recordId; }
	void setCourseId(string courseId){ this->courseId = courseId; }
	void setUid(string uid){ this->uid = uid; }
	void setCourseName(string courseName){ this->courseName = courseName; }
	void setCourseCredit(string courseCredit){ this->courseCredit = courseCredit; }

	// get属性
	string getRecordId(){ return recordId; }
	string getCourseId(){ return courseId; }
	string getUid(){ return uid; }
	string getCourseName(){ return courseName; }
	string getCourseCredit(){ return courseCredit; }

	void createRecord(vector<Course> selectCourses);     // 添加选课记录
	void updateRecord();         // 更新选课记录
	void deleteRecord();         // 删除选课记录
	void showAllOptionalCourse();// 获取全部可选课程
	void showAllRecords();       // 获取全部已选课程
	SelectCourse();
	~SelectCourse();
private:
	string recordId;    // 选课记录编号
	string courseId;    // 课程编号
	string uid;         // 选课学生学号
	string courseName;  // 所选课程名称
	string courseCredit;// 所选课程成绩
};

#endif