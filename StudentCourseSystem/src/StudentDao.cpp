#include "StudentDao.h"

vector<string> studentInfo;

int StudentDao::openDB(const char *path)
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

int StudentDao::closeDB()
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

int StudentDao::callBackGetStudent(void *, int elementCount, char **element, char **colName)
{
	studentInfo.clear();
	for (int index = 0; index < elementCount; index++)
		studentInfo.push_back(element[index] ? element[index] : "NULL");
	return 0;
}

vector<string> StudentDao::getStudentByUid(string uid)
{
	string sql = "SELECT * FROM t_student WHERE uid = " + string(uid);
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackGetStudent, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	return studentInfo;
}

vector<string> StudentDao::getStudentByName(string name)
{
	string sql = "SELECT * FROM t_student WHERE name = " + string(name);
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackGetStudent, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	return studentInfo;
}

bool StudentDao::checkUidExits(string uid)
{
	string sql = "SELECT * FROM t_student WHERE uid = " + string(uid);
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackGetStudent, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	if (!studentInfo.empty())
		return true;
	else
		return false;
}

void StudentDao::addStudent(Student student)
{
	string sql = "INSERT INTO `t_student` (`uid`, `name`, `sex`, `credit`, `grade`, `major`, `department`) VALUES ("
				+ string(student.getUid()) + ", '"
				+ string(student.getName()) + "', '"
				+ string(student.getSex()) + "', "
				+ string(student.getCredit())+ ", '"
				+ string(student.getGrade()) + "', '"
				+ string(student.getMajor()) + "', '"
				+ string(student.getDepartment()) + "')";
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), 0, 0, &errorMsg);
	if (queryResult != SQLITE_OK)
		cout << errorMsg;
	else
		cout << "==================学生信息录入成功==================" << endl;
}