
// �༭������ʱ�б��Ҳ��ʾDlg.h : ͷ�ļ�
//

#pragma once


// C�༭������ʱ�б��Ҳ��ʾDlg �Ի���
class C�༭������ʱ�б��Ҳ��ʾDlg : public CDialogEx
{
// ����
public:
	C�༭������ʱ�б��Ҳ��ʾDlg(CWnd* pParent = NULL);	// ��׼���캯��
	_ConnectionPtr m_pConnection; // ���Ӷ���ָ��
	_RecordsetPtr  m_pRecordset;  // �������ָ��
	CString xm,xb,csrq,gzdw,yddh,gddh ;
	bool IsShowing;

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
	CListCtrl m_ConList;
	CEdit m_ConEdit;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeEdit1();
	void AutoPostion();
	void SetDataBase(CString sql);
	afx_msg void OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
