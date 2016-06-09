#include <iostream>
using namespace std;
class Course
{
	int courseId;           // 课程编号
	string courseName;      // 课程名称
	string courseCredit;    // 课程学分
	string categoryId;      // 课程所属类别
	string teacher;         // 授课教师
	string courseDepartment;// 开课院系
	string totalPeriod;     // 总课时
	string classPeriod;     // 上课课时
	string labPeriod;       // 实验课时
	int memberMax;          // 人数上限
	int memberJoin;         // 已选人数
	string startTerm;       // 开始授课学期
public:
	void createCourse();    // 添加课程
	void updateCourse();    // 更新课程信息
	void deleteCourse();    // 删除课程
	void getAllCourse();    // 获取全部课程
	Course(){}
	~Course(){}
private:
};