#include <iostream>
#include "DBHelper.h"

using namespace std;

class StudentDao
{
public:
	int openDB(const char *path);
	int closeDB();
	int getStudentByUid(string uid);// 获取指定学号的学生对象
	StudentDao(){ openDB(DB_NAME); }
	~StudentDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识

	// sql回调函数
	static int callBackSaveStudent(void *, int argc, char **argv, char **colName);
	// 执行sql语句
	int sqlExecute(const char *sqlStmt);
};
