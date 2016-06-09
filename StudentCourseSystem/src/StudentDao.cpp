#include <iostream>
#include <vector>
#include "StudentDao.h"

using namespace std;

vector<string> studentInfoVector;

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

int StudentDao::callBackSaveStudent(void *, int elementCount, char **element, char **colName)
{
	for (int index = 0; index < elementCount; index++)
	{
		studentInfoVector.push_back(element[index] ? element[index] : "NULL");
		cout << colName[index] << " = " << (element[index] ? element[index] : "NULL") << endl;
	}
	/*vector<string>::iterator iterator;
	for (iterator = studentInfoVector.begin(); iterator != studentInfoVector.end(); iterator++)
		cout << iterator->data() << "=" << endl;*/
	cout << "\n";
	return 0;
}

int StudentDao::getStudentByUid(string uid)
{
	string sql = "select * from t_student where uid = " + string(uid);
	int queryResult = sqlite3_exec(sqliteDb, sql.c_str(), callBackSaveStudent, 0, &errorMsg);
	if (queryResult != SQLITE_OK) {
		printf("%s", errorMsg);
	}
	return 0;
}