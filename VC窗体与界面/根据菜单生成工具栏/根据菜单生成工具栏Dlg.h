
// ���ݲ˵����ɹ�����Dlg.h : ͷ�ļ�
//

#pragma once


// C���ݲ˵����ɹ�����Dlg �Ի���
class C���ݲ˵����ɹ�����Dlg : public CDialogEx
{
// ����
public:
	C���ݲ˵����ɹ�����Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CMenu m_Menu;
	CToolBarCtrl m_toolbar;
	CImageList m_imagelist;


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
	afx_msg void OnCom(UINT nID);
	DECLARE_MESSAGE_MAP()
};
