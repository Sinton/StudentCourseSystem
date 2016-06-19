#ifndef _COURSE_DAO_H
#define _COURSE_DAO_H
#include <vector>
#include "DBHelper.h"
#include "Course.h"

class CourseDao
{
public:
	static string memberJoin;

	int openDB(const char *path);
	int closeDB();
	vector<Course> getAllCourses();			// 获取所有课程
	vector<Course> getCourseByName(string name);
	vector<Course> getCourseByCredit(string credit);
	void addCourse(Course course);          // 添加课程
	void removeCourse();                    // 删除课程
	void updateMemberJoin(string courseId); // 更新课程选课人数
	void getMemberJoin(string courseId);    // 获取课程选课人数
	CourseDao(){ openDB(DB_NAME); }
	~CourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识

	static int callBackGetAllCourses(void *, int argc, char **argv, char **colName);
	static int callBackAddCourse(void *, int argc, char **argv, char **colName);
	static int callBackRemoveCourse(void *, int argc, char **argv, char **colName);
	static int callBackGetMemberJoin(void *, int argc, char **argv, char **colName);
};

#endif