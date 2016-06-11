#include <iostream>
#include <vector>
#include "DBHelper.h"

using namespace std;

class StudentDao
{
public:
	int openDB(const char *path);
	int closeDB();
	bool checkUidExits(string uid);              // 检查学生学号是否存在
	void addStudent(Student student);            // 添加学生
	void removeStudent();                        // 删除学生
	vector<string> getStudentByUid(string uid);  // 获取指定学号的学生对象
	vector<string> getStudentByName(string name);// 获取指定学号的学生对象
	StudentDao(){ openDB(DB_NAME); }
	~StudentDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // 数据库的指针
	char* errorMsg;			// 错误信息
	bool isClose;			// 关闭数据的标识

	static int callBackGetStudentByUid(void *, int elementCount, char **element, char **colName);
	static int callBackGetStudentByName(void *, int elementCount, char **element, char **colName);
};