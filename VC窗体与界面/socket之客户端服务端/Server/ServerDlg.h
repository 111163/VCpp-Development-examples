
// ServerDlg.h : ͷ�ļ�
//

#pragma once
#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")
#define MAXNUM 10


// CServerDlg �Ի���
class CServerDlg : public CDialogEx
{
// ����
public:
	CServerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	SOCKET m_SockServer, m_SockClient;
	SOCKET m_Clients[MAXNUM];
	int m_ConnectNum;
	CString m_IP;
	UINT m_Port;


// �Ի�������
	enum { IDD = IDD_SERVER_DIALOG };

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
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedButton2();
	afx_msg LRESULT TranslateData(WPARAM, LPARAM);
	CEdit m_ServerIP;
	CEdit m_ServerPort;
};
