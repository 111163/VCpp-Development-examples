// ���ini�ļ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "FileOpt.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//char *pszStudent = "����:��ĳ\n����:28\nѧ��:����\n";
	char str[128];
	memset(str, 0, 128);
	CFileOpt file;
	file.OpenFile("./user.ini", 1); // WriteFile("./user.ini");
	int a = file.RradFile(str, 128);// WriteFile(pszStudent, strlen(pszStudent)) RradFile(str, strlen(str))������ôд�Ļ�strlen(str)=>0
	cout << str ;      //
	cout << a << endl; //
	getchar();
	return 0;
}

