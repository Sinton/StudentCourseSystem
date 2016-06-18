#ifndef _COURSE_DAO_H
#define _COURSE_DAO_H
#include <vector>
#include "DBHelper.h"
#include "Course.h"

class CourseDao
{
public:
	int openDB(const char *path);
	int closeDB();
	vector<Course> getAllCourses();
	vector<Course> getCourseByName(string name);
	vector<Course> getCourseByCredit(string credit);
	void addCourse(Course course);
	void removeCourse();
	CourseDao(){ openDB(DB_NAME); }
	~CourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识

	static int callBackGetAllCourses(void *, int argc, char **argv, char **colName);
	static int callBackAddCourse(void *, int argc, char **argv, char **colName);
	static int callBackRemoveCourse(void *, int argc, char **argv, char **colName);
};

#endif