// SaftEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��������.h"
#include "SaftEdit.h"


// CSaftEdit

IMPLEMENT_DYNAMIC(CSaftEdit, CEdit)

CSaftEdit::CSaftEdit()
{
	m_bAllowed = FALSE;
}

CSaftEdit::~CSaftEdit()
{
}


BEGIN_MESSAGE_MAP(CSaftEdit, CEdit)
END_MESSAGE_MAP()



// CSaftEdit ��Ϣ�������




LRESULT CSaftEdit::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_GETTEXT || message == EM_GETLINE)
	{
		if (!m_bAllowed)
		{
			return 0;
		}
	}
	return CEdit::DefWindowProc(message, wParam, lParam);
}
