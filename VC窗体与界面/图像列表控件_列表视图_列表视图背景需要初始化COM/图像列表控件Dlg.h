
// ͼ���б�ؼ�Dlg.h : ͷ�ļ�
//

#pragma once


// Cͼ���б�ؼ�Dlg �Ի���
class Cͼ���б�ؼ�Dlg : public CDialogEx
{
// ����
public:
	Cͼ���б�ؼ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��
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
