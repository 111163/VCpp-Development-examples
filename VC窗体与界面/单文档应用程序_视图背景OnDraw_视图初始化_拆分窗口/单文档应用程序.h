
// ���ĵ�Ӧ�ó���.h : ���ĵ�Ӧ�ó��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C���ĵ�Ӧ�ó���App:
// �йش����ʵ�֣������ ���ĵ�Ӧ�ó���.cpp
//

class C���ĵ�Ӧ�ó���App : public CWinAppEx
{
public:
	C���ĵ�Ӧ�ó���App();


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

extern C���ĵ�Ӧ�ó���App theApp;
