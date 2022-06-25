#include "StdAfx.h"
#include "FileOpt.h"

CFileOpt::CFileOpt() // 注意这里的构造函数
{
	m_pFile = NULL;
	memset(m_szFileName, 0, 128);
}
CFileOpt::~CFileOpt() // 注意在这里释放文件指针
{
	fclose(m_pFile);
}

bool CFileOpt::OpenFile(const char *pszFileName, int nFlag)
{
	strcpy(m_szFileName, pszFileName);
	if (nFlag == 0)
		m_pFile = fopen(m_szFileName, "w+"); // 追加写
	else
		m_pFile = fopen(m_szFileName, "r+"); // 覆盖写
	if (m_pFile)
		return FALSE;
	else
		return TRUE;
}
int CFileOpt::RradFile(char *pBuffer, int nLen)
{
	return fread(pBuffer, sizeof(char), nLen, m_pFile);
}
int CFileOpt::WriteFile(char *pBuffe, int nLen)
{
	return fwrite(pBuffe,sizeof(char), nLen, m_pFile);
}

