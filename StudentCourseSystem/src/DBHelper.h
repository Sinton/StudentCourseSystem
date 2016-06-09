#ifndef  __INCLUDE_DBHELPER_H__
#define  __INCLUDE_DBHELPER_H__

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
	int createTable(const char *createTableStmt);           // 创建一张表
	int dropTable(const char *tableName);                   // 删除一张表
	int select(const char *selectStmt);                     // 查询操作
	int insert(const char *insertStmt);                     // 插入操作
	int remove(const char *deleteStmt);                     // 删除操作
	int update(const char *updateStmt);                     // 更新操作
	int get(const char *selectStmt);

private:
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识

	// 主要用在selece操作中的显示数据元素
	static int callBackFun(void *NotUsed, int argc, char **argv, char **colName);
	// 执行sql语句
	int sqlExecute(const char *sqlStmt);
};


#endif