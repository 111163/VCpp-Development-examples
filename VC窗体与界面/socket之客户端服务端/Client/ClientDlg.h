
// ClientDlg.h : 头文件
//

#pragma once

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#define CM_RECEIVE WM_USER+10


// CClientDlg 对话框
class CClientDlg : public CDialogEx
{
// 构造
public:
	CClientDlg(CWnd* pParent = NULL);	// 标准构造函数
	SOCKET m_SockClient;
	UINT m_Port;
	CString m_IP;

// 对话框数据
	enum { IDD = IDD_CLIENT_DIALOG };

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
