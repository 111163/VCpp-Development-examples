
// ʹ��HTML��ͼ�����ҳ�����.h : ʹ��HTML��ͼ�����ҳ����� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cʹ��HTML��ͼ�����ҳ�����App:
// �йش����ʵ�֣������ ʹ��HTML��ͼ�����ҳ�����.cpp
//

class Cʹ��HTML��ͼ�����ҳ�����App : public CWinApp
{
public:
	Cʹ��HTML��ͼ�����ҳ�����App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cʹ��HTML��ͼ�����ҳ�����App theApp;
