// ini�ļ���д��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "IniFile.h"
#include <iostream>
using namespace std;

// ע��������������������ȷ��Ӧ�����ں��������˵����ʱ�����˽�
int _tmain(int argc, _TCHAR* argv[])
{
	CIniFile::WriteData("c:\\user.ini", "�û���Ϣ", "�û�����", "����");
	CIniFile::WriteData("c:\\user.ini", "�û���Ϣ", "�û�����", "111111");

	char szUserName[128] = {0};
	char szPassword[128] = {0};

	CIniFile::ReadData("c:\\user.ini", "�û���Ϣ", "�û�����", szUserName);
	CIniFile::ReadData("c:\\user.ini", "�û���Ϣ", "�û�����", szPassword);

	cout << szUserName << endl;
	cout << szPassword << endl;
	return 0;
}

