
// ��ѡ��ͳ����ϢDlg.h : ͷ�ļ�
//

#pragma once


// C��ѡ��ͳ����ϢDlg �Ի���
class C��ѡ��ͳ����ϢDlg : public CDialogEx
{
// ����
public:
	C��ѡ��ͳ����ϢDlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CButton m_ConChi;
	CButton m_ConEng;
	CButton m_ConF;
	CButton m_ConG;
	CButton m_ConHua;
	CButton m_ConJnp;
	CButton m_ConMat;
	CButton m_ConPhy;
	afx_msg void OnBnClickedButton1();
};
