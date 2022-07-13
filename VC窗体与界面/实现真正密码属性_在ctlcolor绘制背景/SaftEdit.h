#pragma once


// CSaftEdit

class CSaftEdit : public CEdit
{
	DECLARE_DYNAMIC(CSaftEdit)

public:
	CSaftEdit();
	virtual ~CSaftEdit();
	BOOL m_bAllowed;

protected:
	DECLARE_MESSAGE_MAP()
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	
};


