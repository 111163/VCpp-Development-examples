
// ����ini�ļ���̬���ɲ˵�Dlg.h : ͷ�ļ�
//

#pragma once


// C����ini�ļ���̬���ɲ˵�Dlg �Ի���
class C����ini�ļ���̬���ɲ˵�Dlg : public CDialogEx
{
// ����
public:
	C����ini�ļ���̬���ɲ˵�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_INI_DIALOG };

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
	CMenu m_cMenu;
	void CreateMenuFromFile(void);
	void LoadSubMenu(CMenu* m_menu,CString str);
	BOOL IsHaveSubMenu(CString strSubMenu);
};
