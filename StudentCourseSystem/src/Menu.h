class Menu
{
public:
	friend char choose(char i);
	friend int inputNumber();
	static string identity;
	static void isBack();          // 返回主菜单
	static void chooseRole();      // 选择角色
	static void studentMenu();     // 学生菜单
	static void systemMenu();      // 管理系统菜单
	static void selectCourseMenu();// 选课菜单
	static void courseInfoSearchMenu();  // 课程信息查询菜单
	static void studentInfoSearchMenu(); // 学生信息查询菜单
	Menu();
	~Menu();
private:
};