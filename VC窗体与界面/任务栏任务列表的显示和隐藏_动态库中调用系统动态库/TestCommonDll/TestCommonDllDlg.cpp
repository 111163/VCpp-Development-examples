
// TestCommonDllDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestCommonDll.h"
#include "TestCommonDllDlg.h"
#include "afxdialogex.h"
//#include "CommonDll.h" ////////////////////////////////////////////////////////////////////////// ��̬���Ӷ�̬��

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#pragma comment(lib, "..\\Debug\\CommonDll.lib") //////////////////////////////////////////////////////////////////////////

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


// CTestCommonDllDlg �Ի���




CTestCommonDllDlg::CTestCommonDllDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestCommonDllDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	nHwnd = 0;
}

void CTestCommonDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestCommonDllDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CTestCommonDllDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestCommonDllDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestCommonDllDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTestCommonDllDlg ��Ϣ�������

BOOL CTestCommonDllDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestCommonDllDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestCommonDllDlg::OnPaint()
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
HCURSOR CTestCommonDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestCommonDllDlg::OnBnClickedButton2()
{
	if (nHwnd != NULL)
		::ShowWindow(nHwnd,SW_SHOW);
}


void CTestCommonDllDlg::OnBnClickedButton3()
{
	if (nHwnd != NULL)
		::ShowWindow(nHwnd,SW_HIDE);
}


void CTestCommonDllDlg::OnBnClickedButton1()
{
	//////////////////////////////////////////////////////////////////////////
	/*
	nHwnd  = GetTeskmanHwnd();
	*/

	////////////////////////////////////////////////////////////////////////// ��̬��Ķ�̬����
	typedef HWND (* GetTesk)(void);
	HMODULE hModule = LoadLibrary("CommonDll.dll");
	if (hModule)
	{
		GetTesk tesk = (GetTesk)GetProcAddress(hModule, "GetTeskmanHwnd");
		if (tesk != NULL)
			nHwnd = tesk();
	}
	FreeLibrary(hModule);

	CString tmp;
	tmp.Format("0x%x", nHwnd);
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetWindowText(tmp);
}
