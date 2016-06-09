#include <iostream>
using namespace std;
class SelectCourse
{
	int recordId;      // 选课记录编号
	string uid;        // 选课学生学号
	string courseName; // 所选课程名称
	string courseGrade;// 所选课程成绩
	string gainCredit; // 获得的学分
public:
	void createRecord();     // 添加选课记录
	void updateRecord();     // 更新选课记录
	void deleteRecord();     // 删除选课记录
	void getAllRecordByUid();// 查看已选课程
	SelectCourse();
	~SelectCourse();
private:
};
