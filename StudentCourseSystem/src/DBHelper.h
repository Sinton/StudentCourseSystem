#ifndef  __DBHELPER_H__
#define  __DBHELPER_H__

#ifdef _DEBUG
#pragma comment(lib, "lib/sqlite3.lib")
#else
#pragma comment(lib, "lib/sqlite3.lib")
#endif

#include "sqlite3.h"

const char DB_NAME[] = "db/StudentCourse.db";

class DBHelper
{
public:
	DBHelper() { openDB(DB_NAME); }
	virtual ~DBHelper() { closeDB(); }
	int openDB(const char *path);							// 打开数据库
	int closeDB();											// 关闭数据库
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识
private:
	
};

#endif