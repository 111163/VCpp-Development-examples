#pragma once
class CDesktop
{
public:
	CDesktop(void);
	~CDesktop(void);
public:
	static void HideIcon();			//��������ͼ��
	static void ShowIcon();			//��ʾ����ͼ��
	static void HideTaskbar();		//����������
	static void ShowTaskbar();		//��ʾ������
};

