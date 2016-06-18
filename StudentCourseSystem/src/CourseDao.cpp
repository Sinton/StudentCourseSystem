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

int CourseDao::callBackGetAllCourses(void *, int elementCount, char **element, char **colName)
{
	Course course;
	course.setCourseId(element[0]);
	course.setCourseName(element[1]);
	course.setCourseCredit(element[2]);
	course.setProperty(element[3]);
	course.setTeacher(element[4]);
	course.setCourseDepartment(element[5]);
	course.setTotalPeriod(element[6]);
	course.setClassPeriod(element[7]);
	course.setLabPeriod(element[8]);
	course.setMemberMax(element[9]);
	course.setMemberJoin(element[10]);
	course.setStartTerm(element[11]);
	Course::courseVector.push_back(course);
	return 0;
}

vector<Course> CourseDao::getAllCourses()
{
	string sql = "SELECT * FROM t_course";
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackGetAllCourses, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	return Course::courseVector;
}

vector<Course> CourseDao::getCourseByName(string name)
{
	Course::courseVector.clear();
	string sql = "SELECT * FROM t_course WHERE course_name LIKE '%" + name + "%' OR "
		+ "course_name LIKE '%" + name + "' OR "
		+ "course_name LIKE '" + name + "%'";
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackGetAllCourses, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	return Course::courseVector; 
}

vector<Course> CourseDao::getCourseByCredit(string credit)
{
	Course::courseVector.clear();
	string sql = "SELECT * FROM t_course WHERE course_credit = " + credit;
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackGetAllCourses, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	return Course::courseVector;
}

void CourseDao::addCourse(Course course)
{
	string sql = "INSERT INTO `t_course` (`course_name`,`course_credit`,`property`,`teacher`,`course_department`,`total_period`,`class_period`,`lab_period`,`member_max`,`member_join`,`start_term`) VALUES ('"
		+ string(course.getCourseName()) + "', "
		+ string(course.getCourseCredit()) + +", '"
		+ string(course.getProperty()) + "', '"
		+ string(course.getTeacher()) + "', '"
		+ string(course.getCourseDepartment()) + "', "
		+ string(course.getTotalPeriod()) + ", "
		+ string(course.getClassPeriod()) + ", "
		+ string(course.getLabPeriod()) + ", "
		+ string(course.getMemberMax()) + ", "
		+ string(course.getMemberJoin()) + ", '"
		+ string(course.getStartTerm()) + "')";
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), 0, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	else
		cout << "==================课程信息录入成功==================" << endl;
}