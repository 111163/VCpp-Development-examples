
// �ļ���׼�Ի���Dlg.h : ͷ�ļ�
//

#pragma once


// C�ļ���׼�Ի���Dlg �Ի���
class C�ļ���׼�Ի���Dlg : public CDialogEx
{
// ����
public:
	C�ļ���׼�Ի���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CString m_strEdit;
	afx_msg void OnBnClickedButton1();
	CStatic m_ConSta;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CEdit m_ConEdit;
	CFont m_Font;
	afx_msg void OnBnClickedButton4();
	COLORREF m_Color;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton5();
	CFindReplaceDialog* dlg;
	int nindex;					//�洢�����ַ�������ʼλ��
	int rindex;					//�滻�ַ����Ĵ�С
	BOOL degree;				//�ж��Ƿ�Ϊ��һ���滻�ı���
	BOOL find;				//�ж��Ƿ���в��ҵı���
	afx_msg	long OnFindReplace(WPARAM wParam,LPARAM lParam);
	afx_msg void OnBnClickedButton6();
	CString str[6];			
	CFont font;				//����
	int screenx,screeny;	//��ȡ����ÿӢ��������
	int printx,printy;		//��ȡ��ӡ��ÿӢ��������
	double ratex,ratey;		//��ӡ������Ļ�����ر���
	void DrawText(CDC *pDC, BOOL isprinted);
	afx_msg void OnBnClickedButton7();
};
