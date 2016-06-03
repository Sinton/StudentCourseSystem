#ifndef  __INCLUDE_DB_HELPER_H__
#define  __INCLUDE_DB_HELPER_H__

#ifdef _DEBUG
#pragma comment(lib, "lib/sqlite3.lib")
#else
#pragma comment(lib, "lib/sqlite3.lib")
#endif

#include "sqlite3.h"

class DBHelper
{
public:
	DBHelper() { }
	virtual ~DBHelper() { CloseDB(); }
	int OpenDB(const char *path);							// 打开数据库
	int CloseDB();											// 关闭数据库
	int CreateTable(const char *create_table_state);        // 创建一张表
	int DropTable(const char *table_name);                  // 删除一张表
	int Select(const char *select_state);                   // 查询操作
	int Insert(const char *insert_state);                   // 插入操作
	int Delete(const char *delete_state);                   // 删除操作
	int Update(const char *update_state);                   // 更新操作
	int Get(const char *select_state);

private:
	sqlite3 *sqlite_db_;	// 数据库的指针
	char* err_msg_;			// 错误信息
	bool is_close_;			// 关闭数据的标识

	// 主要用在selece操作中的显示数据元素
	static int CallBackFunc(void *NotUsed, int argc, char **argv, char **azColName);
	// 执行sql语句
	int SqlStateExec(const char *sql_state);
};


#endif