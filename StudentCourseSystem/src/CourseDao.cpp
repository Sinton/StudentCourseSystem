#include "Course.h"
#include "CourseDao.h"

int CourseDao::openDB(const char *path)
{
	int res = sqlite3_open(path, &sqliteDb);
	if (res)
	{
		cout << "无法打开数据库: " << sqlite3_errmsg(sqliteDb);
		sqlite3_close(sqliteDb);
		return -1;
	}
	isClose = false;
	return 0;
}

int CourseDao::closeDB()
{
	if (!isClose)
	{
		int res = sqlite3_close(sqliteDb);
		if (res)
		{
			cout << "无法关闭数据库: " << sqlite3_errmsg(sqliteDb);
			return -1;
		}
	}
	return 0;
}

int CourseDao::callBackAllCourses(void *, int elementCount, char **element, char **colName)
{
	Course course;
	course.setCourseId(atoi(element[0]));
	course.setCourseName(element[1]);
	course.setCourseCredit(element[2]);
	course.setProperty(element[3]);
	course.setTeacher(element[4]);
	course.setCourseDepartment(element[5]);
	course.setTotalPeriod(atoi(element[6]));
	course.setClassPeriod(atoi(element[7]));
	course.setLabPeriod(atoi(element[8]));
	course.setMemberMax(atoi(element[9]));
	course.setMemberJoin(atoi(element[10]));
	course.setStartTerm(element[11]);
	Course::courseVector.push_back(course);
	return 0;
}

vector<Course> CourseDao::getAllCourses()
{
	string sql = "select * from t_course";
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackAllCourses, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	return Course::courseVector;
}