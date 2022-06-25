// 设计控制浏览器行为类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "IEControl.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//这个小的测试时对注册表的操作封装成类

	//CIEControl::SetDefPage("www.12345.com"); // 设置默认页面为www.12345.com

	//CIEControl::ShowPopMenu(false); // 改变了IE浏览器出现时的策略到的是在最前端还是在最后端
	//CIEControl::ShowPopMenu(true);  // 设置window titile项为www.12345.com
	CIEControl::SetCaption("www.12345.com");
	return 0;
}

