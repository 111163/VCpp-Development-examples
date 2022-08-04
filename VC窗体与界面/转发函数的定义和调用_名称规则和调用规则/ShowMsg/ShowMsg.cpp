// ShowMsg.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#define MATUREAPPROACH_EXPORTS
#include "ShowMsg.h"

void ShowMsg(char* pText)
{
	MessageBox(NULL, pText, "提示", 0);
}
