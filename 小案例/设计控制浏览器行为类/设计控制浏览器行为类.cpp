// ��ƿ����������Ϊ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "IEControl.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//���С�Ĳ���ʱ��ע���Ĳ�����װ����

	//CIEControl::SetDefPage("www.12345.com"); // ����Ĭ��ҳ��Ϊwww.12345.com

	//CIEControl::ShowPopMenu(false); // �ı���IE���������ʱ�Ĳ��Ե���������ǰ�˻���������
	//CIEControl::ShowPopMenu(true);  // ����window titile��Ϊwww.12345.com
	CIEControl::SetCaption("www.12345.com");
	return 0;
}

