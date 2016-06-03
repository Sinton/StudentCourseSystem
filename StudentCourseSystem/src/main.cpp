#include <iostream>
#include "db_helper.h"

using namespace std;

DBHelper db_helper;

const char DB_NAME[] = "db/StudentCourse.db";

int main()
{
	int res = db_helper.OpenDB(DB_NAME);
	char sql[] = "select * from t_student";
	db_helper.Select(sql);
	return 0;
}