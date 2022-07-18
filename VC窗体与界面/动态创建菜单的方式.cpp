1.在需要菜单的框架或对话框中添加变量
CMenu m_Menu;

2.在初始化函数中，对菜单做建立，关联， 插入子项
m_Menu.CreateMenu(); // 菜单
CMenu m_PopMenu;
m_PopMenu.CreatePopupMenu();  // 面向对象的思想(类操作创立窗口)
m_Menu.AppendMenu(MF_POPUP, (UINT)m_PopMenu.m_hMenu, "动物"); // 将弹出菜单和菜单绑定
m_PopMenu.AppendMenu(MF_STRING, ID_MENUCAT, "猫");    // 这三个是弹出菜单的项
m_PopMenu.AppendMenu(MF_STRING, ID_MENUDOG, "狗");
m_PopMenu.AppendMenu(MF_STRING, ID_MENUMONKEY, "猴子");
m_Menu.AppendMenu(MF_POPUP, -1, "植物");
m_PopMenu.Detach(); // 因为弹出菜单类是个局部量，所以要将这个局部量和句柄分离
SetMenu(&m_Menu);


// 当然之前要将ID设置好，这样才能有正确的命令ID，命令才能得到正确的处理
打开资源头文件（Resource.h），在该文件中定义命令ID，代码如下。
#define ID_MENUCAT                                     1001                                          //定义菜单命令ID
#define ID_MENUDOG                            1002                                          //定义菜单命令ID
#define ID_MENUMONKEY                             1003                                          //定义菜单命令ID
