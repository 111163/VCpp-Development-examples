
// ΪListBox��ӱ���Dlg.h : ͷ�ļ�
//

#pragma once
#include "ListBmp.h"


// CΪListBox��ӱ���Dlg �Ի���
class CΪListBox��ӱ���Dlg : public CDialogEx
{
// ����
public:
	CΪListBox��ӱ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LISTBOX_DIALOG };

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
	CListBox m_List;
};
