
// ΪListBox��ӱ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CΪListBox��ӱ���App:
// �йش����ʵ�֣������ ΪListBox��ӱ���.cpp
//

class CΪListBox��ӱ���App : public CWinApp
{
public:
	CΪListBox��ӱ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CΪListBox��ӱ���App theApp;