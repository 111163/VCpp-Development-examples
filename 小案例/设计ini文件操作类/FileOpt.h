#pragma once
//	#ifndef __FILEOPT_H__
//	#define  __FILEOPT_H__
//	#endif  // __FILEOPT_H__

#include "stdafx.h"
#include <iostream>
#include <string>



class CFileOpt
{
private:
	char m_szFileName[128]; // �ļ�����
	FILE *m_pFile;          // �ļ�ָ��
public:
	CFileOpt();
	~CFileOpt();
public:
	bool OpenFile(const char *pszFileName, int nFlag=0);// ���ļ�
	int RradFile(char *pBuffer, int nLen); // ��ȡ�ļ�
	int WriteFile(char *pBuffe, int nLen); // д���ļ�
	// �����Ҫ���и������Ķ�д��Ҫ��һ���ķ�װ�������CloseFile(),�����ļ�ָ����ƶ�����дȨ�޵��趨��
};