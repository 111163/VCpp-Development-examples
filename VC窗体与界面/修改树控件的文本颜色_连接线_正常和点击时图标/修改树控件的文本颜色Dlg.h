
// �޸����ؼ����ı���ɫDlg.h : ͷ�ļ�
//

#pragma once


// C�޸����ؼ����ı���ɫDlg �Ի���
class C�޸����ؼ����ı���ɫDlg : public CDialogEx
{
// ����
public:
	C�޸����ؼ����ı���ɫDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CTreeCtrl m_TreeCtrl;
	CImageList m_ImageList;

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
};
