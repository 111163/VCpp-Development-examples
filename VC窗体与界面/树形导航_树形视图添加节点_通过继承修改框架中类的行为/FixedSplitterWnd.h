#pragma once
#include "afxext.h"
class CFixedSplitterWnd :public CSplitterWnd
{
public:
	CFixedSplitterWnd(void);
	~CFixedSplitterWnd(void);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

