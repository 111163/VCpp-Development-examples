// ���ini�ļ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "FileOpt.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char *pszStudent = "����:��ĳ\n����:28\nѧ��:����\n";
	CFileOpt file;
	file.OpenFile("./user.ini");
	file.WriteFile(pszStudent, strlen(pszStudent));
	getchar();
	return 0;
}

