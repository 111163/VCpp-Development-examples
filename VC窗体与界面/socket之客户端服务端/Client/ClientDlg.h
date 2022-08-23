
// ClientDlg.h : ͷ�ļ�
//

#pragma once

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#define CM_RECEIVE WM_USER+10


// CClientDlg �Ի���
class CClientDlg : public CDialogEx
{
// ����
public:
	CClientDlg(CWnd* pParent = NULL);	// ��׼���캯��
	SOCKET m_SockClient;
	UINT m_Port;
	CString m_IP;

// �Ի�������
	enum { IDD = IDD_CLIENT_DIALOG };

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
	afx_msg LRESULT  ReceiveInfo(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_MsgList;
	CEdit m_ServerIP;
	CEdit m_ServerPort;
	CEdit m_NickName;
	CEdit m_SendData;
	afx_msg void OnBnClickedLogin();
	afx_msg void OnBnClickedSend();
};
