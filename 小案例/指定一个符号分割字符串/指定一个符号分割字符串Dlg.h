
// ָ��һ�����ŷָ��ַ���Dlg.h : ͷ�ļ�
//

#pragma once


// Cָ��һ�����ŷָ��ַ���Dlg �Ի���
class Cָ��һ�����ŷָ��ַ���Dlg : public CDialogEx
{
// ����
public:
	Cָ��һ�����ŷָ��ַ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CString m_strChar;
	CString m_strOut;
	CString m_strSrc;
	afx_msg void OnBnClickedButton1();
};
