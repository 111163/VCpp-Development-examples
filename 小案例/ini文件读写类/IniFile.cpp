#include "StdAfx.h"
#include "IniFile.h"


CIniFile::CIniFile(void)
{
}


CIniFile::~CIniFile(void)
{
}
// ��windowsϵͳAPI�ķ�װ��ʹ��
bool CIniFile::WriteData(char *pszFileName, char* pApp, char *pszKey, char *pValue)		//д������
{
	return WritePrivateProfileString(pApp,pszKey,pValue,pszFileName);
}
unsigned int CIniFile::ReadData(char *pszFileName, char* pApp, char *pszKey, char *pValue)//��ȡ����
{
	return GetPrivateProfileString(pApp,pszKey,NULL,pValue,128,pszFileName);
}
