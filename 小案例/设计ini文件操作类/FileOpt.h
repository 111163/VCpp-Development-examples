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
	char m_szFileName[128]; // 文件名称
	FILE *m_pFile;          // 文件指针
public:
	CFileOpt();
	~CFileOpt();
public:
	bool OpenFile(const char *pszFileName, int nFlag=0);// 打开文件
	int RradFile(char *pBuffer, int nLen); // 读取文件
	int WriteFile(char *pBuffe, int nLen); // 写入文件
};