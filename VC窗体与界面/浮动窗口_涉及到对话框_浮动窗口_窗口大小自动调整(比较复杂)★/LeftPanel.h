#pragma once
#include "Resource.h"

// CLeftPanel �Ի���

class CLeftPanel : public CDialog
{
	DECLARE_DYNAMIC(CLeftPanel)

public:
	CLeftPanel(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLeftPanel();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
