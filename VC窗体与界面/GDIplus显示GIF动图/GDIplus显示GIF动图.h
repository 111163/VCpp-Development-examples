
// GDIplus��ʾGIF��ͼ.h : GDIplus��ʾGIF��ͼ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGDIplus��ʾGIF��ͼApp:
// �йش����ʵ�֣������ GDIplus��ʾGIF��ͼ.cpp
//

class CGDIplus��ʾGIF��ͼApp : public CWinAppEx
{
public:
	CGDIplus��ʾGIF��ͼApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGDIplus��ʾGIF��ͼApp theApp;
