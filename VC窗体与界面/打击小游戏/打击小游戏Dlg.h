
// ���С��ϷDlg.h : ͷ�ļ�
//

#pragma once

enum GameState{GS_BEGIN, GS_END, GS_NONE}; // ��Ϸ״̬

// C���С��ϷDlg �Ի���
class C���С��ϷDlg : public CDialogEx
{
// ����
public:
	C���С��ϷDlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	UINT m_DeathCount;
	UINT m_Grade;
	UINT m_nLevel;
	UINT m_MisCount;
	UINT m_EscCount;
protected:
	CPoint m_ptOrg;                  //���ԭ������
	int m_nCellWidth;                 //��Ԫ����
	int m_nCellHeight;                //��Ԫ��߶�
	int m_nPerson;                     //������ֵ�����
	CRect m_GridRC;                //�������
	CRect m_PersonRC;             //������ֵ�����
	BOOL   m_bStart;                //��Ϸ�Ƿ�ʼ
	GameState m_State;             //��Ϸ״̬
	BOOL m_bHit;                     //�Ƿ��������
	int m_nLevels[100];              //��Ϸ����
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void NextLevel(void);
	void OnStart(void);
	void OnEndgame(void);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedEndgame();
};
