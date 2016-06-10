class Menu
{
public:
	friend char choose(char i);
	friend int inputNumber();
	static string identity;
	static void systemMenu();      // 主菜单
	static void isBack();          // 返回主菜单
	static void chooseRole();      // 选择角色
	static void studentMenu();     // 学生菜单
	static void ManagerMenu();     // 管理员菜单
	static void selectCourseMenu();// 选课菜单
	static void courseInfoMenu();  // 课程信息查询
	static void studentInfoMenu(); // 学生信息查询
	Menu();
	~Menu();
private:
};