
// ����ͼ����ƴ���.h : ����ͼ����ƴ��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C����ͼ����ƴ���App:
// �йش����ʵ�֣������ ����ͼ����ƴ���.cpp
//

class C����ͼ����ƴ���App : public CWinApp
{
public:
	C����ͼ����ƴ���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C����ͼ����ƴ���App theApp;
