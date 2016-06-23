#include <iostream>
#include "DBHelper.h"

/**
 *  打开数据连接
 *  @return
 */
int DBHelper::openDB(const char *path)
{
	int res = sqlite3_open(path, &sqliteDb);
	if (res)
	{
		std::cout << "无法打开数据库: " << sqlite3_errmsg(sqliteDb);
		sqlite3_close(sqliteDb);
		return -1;
	}
	isClose = false;
	return 0;
}

/**
 *  关闭数据库连接
 *  @return
 */
int DBHelper::closeDB()
{
	if (!isClose)
	{
		int res = sqlite3_close(sqliteDb);
		if (res)
		{
			std::cout << "无法关闭数据库: " << sqlite3_errmsg(sqliteDb);
			return -1;
		}
	}
	return 0;
}