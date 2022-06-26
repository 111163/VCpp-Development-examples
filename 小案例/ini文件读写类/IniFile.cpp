#include "StdAfx.h"
#include "IniFile.h"


CIniFile::CIniFile(void)
{
}


CIniFile::~CIniFile(void)
{
}
// 对windows系统API的封装和使用
bool CIniFile::WriteData(char *pszFileName, char* pApp, char *pszKey, char *pValue)		//写入数据
{
	return WritePrivateProfileString(pApp,pszKey,pValue,pszFileName);
}
unsigned int CIniFile::ReadData(char *pszFileName, char* pApp, char *pszKey, char *pValue)//读取数据
{
	return GetPrivateProfileString(pApp,pszKey,NULL,pValue,128,pszFileName);
}
