#pragma once
class CDesktop
{
public:
	CDesktop(void);
	~CDesktop(void);
public:
	static void HideIcon();			//隐藏桌面图标
	static void ShowIcon();			//显示桌面图标
	static void HideTaskbar();		//隐藏任务栏
	static void ShowTaskbar();		//显示任务栏
};

