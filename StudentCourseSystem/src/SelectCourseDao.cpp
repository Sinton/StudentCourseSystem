#include "SelectCourseDao.h"

vector<Course> selectCourses;

int SelectCourseDao::callBackGetOptionalCourses(void *, int elementCount, char **element, char **colName)
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
	selectCourses.push_back(course);
	return 0;
}

vector<Course> SelectCourseDao::getOptionalCourses(string uid)
{
	selectCourses.clear();
	string sql = "SELECT * FROM t_course WHERE member_join < member_max AND course_id NOT IN (SELECT course_id FROM t_record WHERE uid = " + uid + ")";
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackGetOptionalCourses, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	return selectCourses;
}

int SelectCourseDao::callBackGetRecords(void *, int elementCount, char **element, char **colName)
{
	Course course;
	course.setCourseId(element[0]);
	course.setCourseName(element[1]);
	course.setCourseCredit(element[2]);
	selectCourses.push_back(course);
	return 0;
}

vector<Course> SelectCourseDao::getRecords(string uid)
{
	selectCourses.clear();
	string sql = "SELECT course_id, course_name, course_credit FROM t_record WHERE uid = " + uid;
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackGetRecords, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	return selectCourses;
}

void SelectCourseDao::addRecord(SelectCourse selectCourse)
{
	string sql = "INSERT INTO `t_record` (`course_id`, `uid`, `course_name`, `course_credit`) VALUES ("
		+ string(selectCourse.getCourseId()) + ", '"
		+ string(selectCourse.getUid()) + "', '"
		+ string(selectCourse.getCourseName()) + "', '"
		+ string(selectCourse.getCourseCredit()) + "')";
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), 0, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	else
		cout << "==================学生选课信息录入成功==================" << endl;
}