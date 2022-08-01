#pragma once


// CInput 对话框

class CInput : public CDialogEx
{
	DECLARE_DYNAMIC(CInput)

public:
	CInput(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInput();
	CString m_centerX;
	CString m_centerY;
	CString m_radius;
	CString m_startAngle;
	CString m_sweepAngle;

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSet();
};
