
// ServerDlg.h : 头文件
//

#pragma once
#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")
#define MAXNUM 10


// CServerDlg 对话框
class CServerDlg : public CDialogEx
{
// 构造
public:
	CServerDlg(CWnd* pParent = NULL);	// 标准构造函数
	SOCKET m_SockServer, m_SockClient;
	SOCKET m_Clients[MAXNUM];
	int m_ConnectNum;
	CString m_IP;
	UINT m_Port;


// 对话框数据
	enum { IDD = IDD_SERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
