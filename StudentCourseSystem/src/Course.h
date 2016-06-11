#include "header.h"

class Course
{
public:
	//记录课程信息
	static vector<Course> courseVector;

	// set属性
	void setCourseId(int courseId){ this->courseId = courseId; }
	void setCourseName(string courseName){ this->courseName = courseName; }
	void setCourseCredit(string courseCredit){ this->courseCredit = courseCredit; }
	void setProperty(string property){ this->property = property; }
	void setTeacher(string teacher){ this->teacher = teacher; }
	void setCourseDepartment(string courseDepartment){ this->courseDepartment = courseDepartment; }
	void setTotalPeriod(int totalPeriod){ this->totalPeriod = totalPeriod; }
	void setClassPeriod(int classPeriod){ this->classPeriod = classPeriod; }
	void setLabPeriod(int labPeriod){ this->labPeriod = labPeriod; }
	void setMemberMax(int memberMax){ this->memberMax = memberMax; }
	void setMemberJoin(int memberJoin){ this->memberJoin = memberMax; }
	void setStartTerm(string startTerm){ this->startTerm = startTerm; }

	// get属性
	int getCourseId(){ return courseId; }
	string getCourseName(){ return courseName; }
	string getCourseCredit(){ return courseCredit; }
	string getProperty(){ return property; }
	string getTeacher(){ return teacher; }
	string getCourseDepartment(){ return courseDepartment; }
	int getTotalPeriod(){ return totalPeriod; }
	int getClassPeriod(){ return classPeriod; }
	int getLabPeriod(){ return labPeriod; }
	int getMemberMax(){ return memberMax; }
	int getMemberJoin(){ return memberJoin; }
	string getStartTerm(){ return startTerm; }

	void createCourse();     // 添加课程
	void updateCourse();     // 更新课程信息
	void deleteCourse();     // 删除课程
	void showAllCourses();   // 显示全部课程
	Course();
	~Course();
private:
	int courseId;           // 课程编号
	string courseName;      // 课程名称
	string courseCredit;    // 课程学分
	string property;        // 课程性质
	string teacher;         // 授课教师
	string courseDepartment;// 开课院系
	int totalPeriod;        // 总课时
	int classPeriod;        // 上课课时
	int labPeriod;          // 实验课时
	int memberMax;          // 人数上限
	int memberJoin;         // 已选人数
	string startTerm;       // 开始授课学期
};