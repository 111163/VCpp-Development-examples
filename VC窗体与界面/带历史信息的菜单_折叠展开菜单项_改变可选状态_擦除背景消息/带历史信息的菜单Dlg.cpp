
// ����ʷ��Ϣ�Ĳ˵�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʷ��Ϣ�Ĳ˵�.h"
#include "����ʷ��Ϣ�Ĳ˵�Dlg.h"
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


// C����ʷ��Ϣ�Ĳ˵�Dlg �Ի���




C����ʷ��Ϣ�Ĳ˵�Dlg::C����ʷ��Ϣ�Ĳ˵�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C����ʷ��Ϣ�Ĳ˵�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����ʷ��Ϣ�Ĳ˵�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C����ʷ��Ϣ�Ĳ˵�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &C����ʷ��Ϣ�Ĳ˵�Dlg::On32771)
	ON_COMMAND(ID_OOPEN, &C����ʷ��Ϣ�Ĳ˵�Dlg::OnOopen)
	ON_COMMAND(ID_CCL, &C����ʷ��Ϣ�Ĳ˵�Dlg::OnCcl)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// C����ʷ��Ϣ�Ĳ˵�Dlg ��Ϣ�������

BOOL C����ʷ��Ϣ�Ĳ˵�Dlg::OnInitDialog()
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
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);

	num = 32772;

	CMenu* pMenu = m_Menu.GetSubMenu(1);
	pMenu->EnableMenuItem(ID_CCL, 1);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����ʷ��Ϣ�Ĳ˵�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C����ʷ��Ϣ�Ĳ˵�Dlg::OnPaint()
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
HCURSOR C����ʷ��Ϣ�Ĳ˵�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C����ʷ��Ϣ�Ĳ˵�Dlg::On32771()
{
	CString strText;
	CFileDialog m_File(TRUE, NULL, NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, 
		"All Files(*.*)|*.*|", AfxGetMainWnd());
	if (m_File.DoModal() == IDOK)
	{
		strText = m_File.GetPathName();
		CMenu* m_pMenu = m_Menu.GetSubMenu(0);
		m_pMenu->InsertMenu(2, MF_BYPOSITION, num, strText);
		//SetMenu(&m_Menu);
		num++;
	}
	else
		return;

}


void C����ʷ��Ϣ�Ĳ˵�Dlg::OnOopen()
{
	CMenu* pMenu = m_Menu.GetSubMenu(1);
	//pMenu->AppendMenu(MF_STRING,10001, "�ı�1");
	//pMenu->AppendMenu(MF_STRING,10002, "�ı�2");
	//pMenu->AppendMenu(MF_STRING,10003, "�ı�3");
	pMenu->InsertMenu(1, MF_BYPOSITION, 10001, "�ı�1");
	pMenu->InsertMenu(1, MF_BYPOSITION, 10002, "�ı�1");
	pMenu->InsertMenu(1, MF_BYPOSITION, 10003, "�ı�1");

	pMenu->EnableMenuItem(ID_OOPEN, MF_GRAYED); // �÷����������ò˵�����Ч����Ч����
	pMenu->EnableMenuItem(ID_CCL, MF_ENABLED);
	
}


void C����ʷ��Ϣ�Ĳ˵�Dlg::OnCcl()
{
	CMenu* pMenu = m_Menu.GetSubMenu(1);
	pMenu->RemoveMenu(10001,MF_BYCOMMAND);
	pMenu->RemoveMenu(10002,MF_BYCOMMAND);
	pMenu->RemoveMenu(10003,MF_BYCOMMAND);

	pMenu->EnableMenuItem(ID_CCL, MF_GRAYED);
	pMenu->EnableMenuItem(ID_OOPEN, MF_ENABLED);
}


BOOL C����ʷ��Ϣ�Ĳ˵�Dlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetWindowRect(&rect);
	CDC memDC;
	CBitmap bitmap;
	CBitmap* bmp = NULL;
	bitmap.LoadBitmap(IDB_BITMAP1);
	memDC.CreateCompatibleDC(pDC);
	bmp = memDC.SelectObject(&bitmap);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
	if (bmp) memDC.SelectObject(bmp);
	return TRUE;
	// return CDialogEx::OnEraseBkgnd(pDC);
}
