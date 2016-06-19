#include "Course.h"
#include "Student.h"
#include "SelectCourse.h"
#include "SelectCourseDao.h"
#include "Menu.h"

void SelectCourse::createRecord(vector<Course> selectCourses)
{
	SelectCourse selectCourse;
	cout << "请输入课程编号进行选课: ";
	string cid = inputString();
	for (vector<Course>::iterator iter = selectCourses.begin(); iter != selectCourses.end(); iter++)
	{
		if (iter->getCourseId() == cid)
		{
			selectCourse.courseId = iter->getCourseId();
			selectCourse.uid = Student::loginUid;
			selectCourse.courseName = iter->getCourseName();
			selectCourse.courseCredit = iter->getCourseCredit();
		}
	}
	SelectCourseDao selectCourseDao;
	selectCourseDao.addRecord(selectCourse);
	// 更新课程选课人数
	system("pause");
}

void SelectCourse::updateRecord()
{

}

void SelectCourse::deleteRecord()
{

}

void SelectCourse::showAllOptionalCourse()
{
	SelectCourseDao selectCourseDao;
	vector<Course> selectCourses = selectCourseDao.getOptionalCourses(Student::loginUid);
	if (selectCourses.empty())
	{
		cout << "没有记录课程信息!\n";
		system("pause");
		return;
	}
	cout << "\n课程信息如下：\n" << endl;
	for (vector<Course>::iterator iter = selectCourses.begin(); iter != selectCourses.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "课程编号：" << iter->getCourseId() << "\t\t"
			<< "课程名称：" << iter->getCourseName() << endl
			<< "课程学分：" << iter->getCourseCredit() << "\t\t"
			<< "课程性质：" << iter->getProperty() << endl
			<< "授课老师：" << iter->getTeacher() << "　\t"
			<< "开课院系：" << iter->getCourseDepartment() << endl
			<< "总学时：" << iter->getTotalPeriod() << "\t\t"
			<< "授课学时：" << iter->getClassPeriod() << endl
			<< "实验学时：" << iter->getLabPeriod() << "\t\t"
			<< "人数上限：" << iter->getMemberMax() << endl
			<< "已选人数：" << iter->getMemberJoin() << "\t\t"
			<< "上课学期：" << iter->getStartTerm() << endl << endl;
	}
	cout << "是否要进行选课 (y / n): ";
	if ("y" == inputString())
		SelectCourse::createRecord(selectCourses);
}

void SelectCourse::showAllRecords()
{
	SelectCourseDao selectCourseDao;
	vector<Course> selectCourses = selectCourseDao.getRecords(Student::loginUid);
	if (selectCourses.empty())
	{
		cout << "没有记录课程信息!\n";
		system("pause");
		return;
	}
	cout << "\n课程信息如下：\n" << endl;
	for (vector<Course>::iterator iter = selectCourses.begin(); iter != selectCourses.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "课程编号：" << iter->getCourseId() << "\t\t"
			<< "课程名称：" << iter->getCourseName() << endl
			<< "课程学分：" << iter->getCourseCredit() << endl << endl;
	}
	system("pause");
}

SelectCourse::SelectCourse()
{
}

SelectCourse::~SelectCourse()
{
}