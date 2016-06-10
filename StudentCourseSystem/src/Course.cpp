#include "Course.h"
#include "CourseDao.h"
#include "Menu.h"

vector<Course> courses;
vector<Course> Course::courseVector = courses;

void Course::createCourse()
{

}

void Course::updateCourse()
{

}

void Course::deleteCourse()
{

}

void Course::showAllCourses()
{
	CourseDao courseDao;
	Course::courseVector = courseDao.getAllCourses();
	if (courseVector.empty())
	{
		cout << "没有记录课程信息!\n";
		system("pause");
		return;
	}
	cout << "\n课程信息如下：\n" << endl;
	for (vector<Course>::iterator iter = courseVector.begin(); iter != courseVector.end(); iter++)
	{
		cout << "课程编号：" << iter->courseId << '\t'
			<< "课程名称：" << iter->courseName << '\t' << endl
			<< "课程学分：" << iter->courseCredit << '\t'
			<< "课程性质：" << iter->property << '\t' << endl
			<< "授课老师：" << iter->teacher << '\t'
			<< "开课院系：" << iter->courseDepartment << '\t' << endl
			<< "总学时：" << iter->totalPeriod << '\t'
			<< "授课学时：" << iter->classPeriod << '\t' << endl
			<< "实验学时：" << iter->labPeriod << '\t'
			<< "人数上限：" << iter->memberMax << '\t' << endl
			<< "已选人数：" << iter->memberJoin << '\t'
			<< "上课学期" << iter->startTerm << endl
			<< "\n===================================================\n" << endl;
	}
	system("pause");
}

Course::Course()
{

}

Course::~Course()
{

}