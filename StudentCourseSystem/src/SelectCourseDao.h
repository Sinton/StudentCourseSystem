#ifndef _SELECT_COURSE_DAO_H
#define _SELECT_COURSE_DAO_H
#include <vector>
#include "Course.h"
#include "DBHelper.h"

class SelectCourseDao
{
public:
	int openDB(const char *path);
	int closeDB();
	vector<Course> getsOptionalCourses();
	vector<Course> getRecordsByUid(string uid);
	vector<Course> getCourseByCredit(string credit);
	void addRecord(Course course);
	void removeRecord();
	SelectCourseDao(){ openDB(DB_NAME); }
	~SelectCourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识
};

#endif