
// �б�����ݽ���Dlg.h : ͷ�ļ�
//

#pragma once


// C�б�����ݽ���Dlg �Ի���
class C�б�����ݽ���Dlg : public CDialogEx
{
// ����
public:
	C�б�����ݽ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_ConBr;
	CButton m_ConBl;
	CButton m_ConBla;
	CButton m_ConBra;
	CListBox m_ConLl;
	CListBox m_ConLr;
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRightall();
	afx_msg void OnBnClickedLeftall();
};
