#pragma once
class CIEControl
{
public:
	CIEControl(void);
	~CIEControl(void);
public:
	static void SetCaption(const char *pszText); // ����IE���ڱ���
	static void ShowPopMenu(bool bShow); // ���ػ���ʾ����ʽ�˵�
	static void SetDefPage(const char *pszUrl); // ����Ĭ����ҳ
};

