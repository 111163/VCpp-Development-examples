
// �����ݿ⶯̬���ɲ˵�Dlg.h : ͷ�ļ�
//

#pragma once


// C�����ݿ⶯̬���ɲ˵�Dlg �Ի���
class C�����ݿ⶯̬���ɲ˵�Dlg : public CDialogEx
{
// ����
public:
	C�����ݿ⶯̬���ɲ˵�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CMenu m_menu;
	void LoadMenuFromDatabase(void);
	void LoadSubMenu(CMenu* m_menu, CString str);
	BOOL IsHaveSubMenu(CString str);
};
