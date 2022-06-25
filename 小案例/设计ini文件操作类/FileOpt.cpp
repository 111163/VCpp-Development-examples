#include "StdAfx.h"
#include "FileOpt.h"

CFileOpt::CFileOpt() // ע������Ĺ��캯��
{
	m_pFile = NULL;
	memset(m_szFileName, 0, 128);
}
CFileOpt::~CFileOpt() // ע���������ͷ��ļ�ָ��
{
	fclose(m_pFile);
}

bool CFileOpt::OpenFile(const char *pszFileName, int nFlag)
{
	strcpy(m_szFileName, pszFileName);
	if (nFlag == 0)
		m_pFile = fopen(m_szFileName, "w+"); // ׷��д
	else
		m_pFile = fopen(m_szFileName, "r+"); // ����д
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

