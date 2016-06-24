#ifndef _COURSE_DAO_H
#define _COURSE_DAO_H
#include <vector>
#include "DBHelper.h"
#include "Course.h"

class CourseDao : public DBHelper
{
public:
	static string memberJoin;

	vector<Course> getAllCourses();                 // 获取所有课程
	vector<Course> getCourseByName(string name);    // 获取相似课程名称下的全部课程
	vector<Course> getCourseByCredit(string credit);// 获取指定学分下的全部课程
	void addCourse(Course course);                  // 添加课程
	void removeCourse();                            // 删除课程
	void updateMemberJoin(string courseId);         // 更新课程选课人数
	void getMemberJoin(string courseId);            // 获取课程选课人数
	CourseDao(){ openDB(DB_NAME); }
	~CourseDao(){ }

private:
	static int callBackGetAllCourses(void *, int argc, char **argv, char **colName);
	static int callBackAddCourse(void *, int argc, char **argv, char **colName);
	static int callBackRemoveCourse(void *, int argc, char **argv, char **colName);
	static int callBackGetMemberJoin(void *, int argc, char **argv, char **colName);
};

#endif