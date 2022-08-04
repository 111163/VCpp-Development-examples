
// TestShowMsgDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestShowMsg.h"
#include "TestShowMsgDlg.h"
#include "afxdialogex.h"
#include "ShowMsg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma  comment(lib, "..\\Debug\\ShowMsg.lib")


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestShowMsgDlg �Ի���




CTestShowMsgDlg::CTestShowMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestShowMsgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestShowMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestShowMsgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTestShowMsgDlg ��Ϣ�������

BOOL CTestShowMsgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	/*
	HMODULE hMod = LoadLibrary("..\\Debug\\ShowMsg.dll");                //���ض�̬���ӿ�

	if (hMod != NULL)                                           //�ж��Ƿ���سɹ�
	{
		//��ȡ��̬���ӿ��е�GetTextDlg����
		typedef void ( *ShMsg)(char*);                       //���庯��ָ������
		typedef int  (WINAPI *ShM)(HWND,LPCSTR,LPCSTR,UINT);     //���庯��ָ������
		ShMsg GetTextDlg = (ShMsg)GetProcAddress(hMod,"ShowMsg");
		ShM ReleaseTextDlg= (ShM)GetProcAddress(hMod,
			"ShowM");//��ȡ��̬���ӿ��е�ReleaseTextDlg ����
		if (GetTextDlg != NULL && ReleaseTextDlg != NULL) //�жϺ���ָ���Ƿ�Ϊ��
		{
			GetTextDlg("�������");
			ReleaseTextDlg(NULL, "���", "����", MB_OKCANCEL);
		}
		FreeLibrary(hMod);                                     //ж�ض�̬���ӿ�
	}
	*/
	ShowM(NULL, "���", "����", MB_OKCANCEL);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestShowMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestShowMsgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestShowMsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

