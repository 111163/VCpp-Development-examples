
// ListBox�Ĳ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListBox�Ĳ���.h"
#include "ListBox�Ĳ���Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CListBox�Ĳ���Dlg �Ի���




CListBox�Ĳ���Dlg::CListBox�Ĳ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListBox�Ĳ���Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strEdit = _T("");
}

void CListBox�Ĳ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_strEdit);
	DDX_Control(pDX, IDC_LIST, m_conList);
}

BEGIN_MESSAGE_MAP(CListBox�Ĳ���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CListBox�Ĳ���Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CListBox�Ĳ���Dlg ��Ϣ�������

BOOL CListBox�Ĳ���Dlg::OnInitDialog()
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

	CString str;
	for (int i=0;i < 10;i++)
	{
		str.Format(_T("item string %d"), i);
		m_conList.AddString(str);
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CListBox�Ĳ���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListBox�Ĳ���Dlg::OnPaint()
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
HCURSOR CListBox�Ĳ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListBox�Ĳ���Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	char buf[1024];
	/* 
	// ����ע��ʹ��SendMessage(m_conList.GetSafeHwnd(),LB_FINDSTRINGEXACT,-1,(LPARAM)(LPCTSTR)m_strEdit)
	// = m_conList.FindString(-1,(LPCTSTR)m_strEdit)
	CString strres;
	int index=::SendMessage(m_conList.GetSafeHwnd(),LB_FINDSTRINGEXACT,-1,
		(LPARAM)(LPCTSTR)m_strEdit);
	if(index>=0)
	{
		strres.Format("�ַ���������%d",index);
		MessageBox(strres);
	}
	else
	{
		MessageBox("û���ҵ�");
	}
	*/
	CString strres;
	int index = m_conList.FindString(-1,(LPCTSTR)m_strEdit);
	if(index>=0)
	{
		strres.Format("�ַ���������%d",index);
		MessageBox(strres);
	}
	else
	{
		MessageBox("û���ҵ�");
	}
}
