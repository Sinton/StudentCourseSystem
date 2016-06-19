#ifndef _SELECT_COURSE_DAO_H
#define _SELECT_COURSE_DAO_H
#include <vector>
#include "Course.h"
#include "SelectCourse.h"
#include "DBHelper.h"

class SelectCourseDao
{
public:
	int openDB(const char *path);
	int closeDB();
	vector<Course> getOptionalCourses(string uid);      // 获取可选课程
	vector<Course> getRecords(string uid);    // 获取选课记录
	void addRecord(SelectCourse selectCourse);// 添加选课记录
	void removeRecord();					  // 删除选课记录
	SelectCourseDao(){ openDB(DB_NAME); }
	~SelectCourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识

	static int callBackGetRecords(void *, int elementCount, char **element, char **colName);
	static int callBackGetOptionalCourses(void *, int elementCount, char **element, char **colName);
};

#endif