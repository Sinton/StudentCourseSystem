#ifndef _SELECT_COURSE_DAO_H
#define _SELECT_COURSE_DAO_H
#include <vector>
#include "Course.h"
#include "SelectCourse.h"
#include "DBHelper.h"

class SelectCourseDao : public DBHelper
{
public:
	vector<Course> getOptionalCourses(string uid);      // 获取可选课程
	vector<Course> getRecords(string uid);              // 获取选课记录
	void addRecord(SelectCourse selectCourse);          // 添加选课记录
	void removeRecord();					            // 删除选课记录
	SelectCourseDao(){ openDB(DB_NAME); }
	~SelectCourseDao(){ }

private:
	static int callBackGetRecords(void *, int elementCount, char **element, char **colName);
	static int callBackGetOptionalCourses(void *, int elementCount, char **element, char **colName);
};

#endif