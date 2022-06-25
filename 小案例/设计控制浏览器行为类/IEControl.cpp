#include "StdAfx.h"
#include "IEControl.h"


CIEControl::CIEControl(void)
{
}


CIEControl::~CIEControl(void)
{
}

void CIEControl::SetCaption(const char *pszText) // 设置IE窗口标题
{
	// 现在微软已经放弃ini文件存储配置的方式了，主要用注册表存储配置消息
	// 这里也是通过写注册表来达到修改配置的目的
	char *szKey = "Software\\Microsoft\\Internet Explorer\\Main";
	HKEY hKey;
	::RegCreateKey(HKEY_CURRENT_USER, szKey, &hKey);
	::RegSetKeyValue(hKey, "Window Titile", NULL, REG_SZ, (BYTE*)pszText, strlen(pszText));
	::RegCloseKey(hKey);
}
void CIEControl::ShowPopMenu(bool bShow) // 隐藏或显示弹出式菜单
{
	HKEY hKey;
	DWORD dwSize;
	DWORD dwValue = 1;
	if (bShow)
		dwValue = 0;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = true;
	sa.lpSecurityDescriptor = NULL;

	char *szKey = "Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions";
	::RegCreateKeyEx(HKEY_CURRENT_USER, szKey, 0L, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, &sa, &hKey, &dwSize);
	::RegSetValueEx(hKey, "NoBrowserContextMenu", NULL, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));
	::RegCloseKey(hKey);
}
void CIEControl::SetDefPage(const char *pszUrl) // 设置默认主页
{
	char * szKey = "Software\\Microsoft\\Internet Explorer\\Main";
	HKEY hKey;
	::RegCreateKey(HKEY_CURRENT_USER, szKey, &hKey);
	::RegSetValueEx(hKey, "Start Page", NULL, REG_SZ, (BYTE*)pszUrl, strlen(pszUrl));
	::RegCloseKey(hKey);
}
