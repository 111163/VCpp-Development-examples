
// ͼ�굼��.h : ͼ�굼�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cͼ�굼��App:
// �йش����ʵ�֣������ ͼ�굼��.cpp
//

class Cͼ�굼��App : public CWinApp
{
public:
	Cͼ�굼��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cͼ�굼��App theApp;
