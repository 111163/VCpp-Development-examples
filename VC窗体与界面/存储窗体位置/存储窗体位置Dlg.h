
// �洢����λ��Dlg.h : ͷ�ļ�
//

#pragma once

typedef struct _Configinfo
{
	int height;
	int width;
	int left;
	int top;
}ConfigInfo;

// C�洢����λ��Dlg �Ի���
class C�洢����λ��Dlg : public CDialogEx
{
// ����
public:
	C�洢����λ��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CEdit m_ConCaption;
protected:
	CString m_strConfigPath;
public:
	afx_msg void OnDestroy();
};
