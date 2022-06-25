#include "StdAfx.h"
#include "IEControl.h"


CIEControl::CIEControl(void)
{
}


CIEControl::~CIEControl(void)
{
}

void CIEControl::SetCaption(const char *pszText) // ����IE���ڱ���
{
	// ����΢���Ѿ�����ini�ļ��洢���õķ�ʽ�ˣ���Ҫ��ע���洢������Ϣ
	// ����Ҳ��ͨ��дע������ﵽ�޸����õ�Ŀ��
	char *szKey = "Software\\Microsoft\\Internet Explorer\\Main";
	HKEY hKey;
	::RegCreateKey(HKEY_CURRENT_USER, szKey, &hKey);
	::RegSetKeyValue(hKey, "Window Titile", NULL, REG_SZ, (BYTE*)pszText, strlen(pszText));
	::RegCloseKey(hKey);
}
void CIEControl::ShowPopMenu(bool bShow) // ���ػ���ʾ����ʽ�˵�
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
void CIEControl::SetDefPage(const char *pszUrl) // ����Ĭ����ҳ
{
	char * szKey = "Software\\Microsoft\\Internet Explorer\\Main";
	HKEY hKey;
	::RegCreateKey(HKEY_CURRENT_USER, szKey, &hKey);
	::RegSetValueEx(hKey, "Start Page", NULL, REG_SZ, (BYTE*)pszUrl, strlen(pszUrl));
	::RegCloseKey(hKey);
}
