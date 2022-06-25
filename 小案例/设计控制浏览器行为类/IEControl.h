#pragma once
class CIEControl
{
public:
	CIEControl(void);
	~CIEControl(void);
public:
	static void SetCaption(const char *pszText); // 设置IE窗口标题
	static void ShowPopMenu(bool bShow); // 隐藏或显示弹出式菜单
	static void SetDefPage(const char *pszUrl); // 设置默认主页
};

