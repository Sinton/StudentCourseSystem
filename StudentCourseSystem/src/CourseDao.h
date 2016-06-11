#include <iostream>
#include <vector>
#include "DBHelper.h"

using namespace std;

class CourseDao
{
public:
	int openDB(const char *path);
	int closeDB();
	vector<Course> getAllCourses();
	void addCourse(Course course);
	void removeCourse();
	CourseDao(){ openDB(DB_NAME); }
	~CourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识

	static int callBackAllCourses(void *, int argc, char **argv, char **colName);
	static int callBackAddCourse(void *, int argc, char **argv, char **colName);
	static int callBackRemoveCourse(void *, int argc, char **argv, char **colName);
};