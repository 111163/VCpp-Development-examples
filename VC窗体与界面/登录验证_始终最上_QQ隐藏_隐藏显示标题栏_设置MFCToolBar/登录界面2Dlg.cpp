
// ��¼����2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��¼����2.h"
#include "��¼����2Dlg.h"
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


// C��¼����2Dlg �Ի���




C��¼����2Dlg::C��¼����2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��¼����2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��¼����2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SET, m_conSetTop);
	DDX_Control(pDX, IDC_TITLE, m_conTitle);
}

BEGIN_MESSAGE_MAP(C��¼����2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SET, &C��¼����2Dlg::OnBnClickedSet)
	ON_BN_CLICKED(IDC_TITLE, &C��¼����2Dlg::OnBnClickedTitle)
	ON_BN_CLICKED(IDC_BUTTON3, &C��¼����2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C��¼����2Dlg::OnBnClickedButton4)
	ON_COMMAND(ID_BUTTON32771,&C��¼����2Dlg::OnBnClickedBUTTON32771)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C��¼����2Dlg ��Ϣ�������

BOOL C��¼����2Dlg::OnInitDialog()
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

	// ����ToolBar���Ի�����
	if (m_toolB.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, 100))
	{
		m_toolB.SetPaneStyle(m_toolB.GetPaneStyle()
			& ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_ANY));
		m_toolB.LoadToolBar(IDR_TOOLBAR1);

		CSize   sizeToolBar = m_toolB.CalcFixedLayout(FALSE, TRUE);
		m_toolB.SetWindowPos(NULL, 0, 0, sizeToolBar.cx, sizeToolBar.cy,
			SWP_NOACTIVATE | SWP_NOZORDER);

		m_toolB.SetRouteCommandsViaFrame(FALSE);//������Ϣ�ԶԻ���ʽ����
		//m_toolbar.AdjustLayout();
		m_toolB.AdjustSizeImmediate();//���ݰ�ť��С����������
	}


	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	if (dlgLog.DoModal() != IDOK)
	{
		CDialogEx::OnOK(); // ������Ϊ�˺�OnClose()�ر���һ������
	}
	m_topFlg = 0;
	CRect rect;
	GetWindowRect(&rect);
	::SetWindowPos(m_hWnd,HWND_BOTTOM,rect.left,
		rect.top,0,0,SWP_NOMOVE || SWP_NOSIZE);
	m_titleFlg = TRUE;
	SetTimer(1, 100, NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��¼����2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C��¼����2Dlg::OnPaint()
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
HCURSOR C��¼����2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��¼����2Dlg::OnBnClickedSet()
{
	m_topFlg = !m_topFlg;
	CRect rect;
	GetWindowRect(&rect);
	if (m_topFlg)
	{
		m_conSetTop.SetWindowText("�õ�");
		::SetWindowPos(m_hWnd,HWND_TOPMOST,rect.left,
			rect.top,0,0,SWP_NOMOVE || SWP_NOSIZE);
	}
	else
	{
		m_conSetTop.SetWindowText("�ö�");
		::SetWindowPos(m_hWnd,HWND_BOTTOM,rect.left,
			rect.top,0,0,SWP_NOMOVE || SWP_NOSIZE);
	}
}


void C��¼����2Dlg::OnBnClickedTitle()
{
	CWnd *pWB = GetDlgItem(IDC_TITLE);
	m_titleFlg = !m_titleFlg;
	LONG lStyle = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
	if (m_titleFlg)
	{
		pWB->SetWindowText("���ر�����");
		::SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle | WS_CAPTION);
	}
	else
	{
		pWB->SetWindowText("��ʾ������");
		::SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle & ~WS_CAPTION);
	}
	::SetWindowPos(this->m_hWnd, NULL, 0, 0, 0, 0,SWP_NOSIZE 
		| SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
}


void C��¼����2Dlg::OnBnClickedButton3()
{
	LONG lStyle = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
	::SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle & ~WS_MAXIMIZEBOX);
	::SetWindowPos(this->m_hWnd, NULL, 0, 0, 0, 0,SWP_NOSIZE 
	| SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
}


void C��¼����2Dlg::OnBnClickedButton4()
{
	LONG lStyle = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
	::SetWindowLong(this->m_hWnd, GWL_STYLE, lStyle & ~WS_MINIMIZEBOX);
	::SetWindowPos(this->m_hWnd, NULL, 0, 0, 0, 0,SWP_NOSIZE 
		| SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
}


void C��¼����2Dlg::OnBnClickedBUTTON32771()
{
	AfxMessageBox("����˵�һ����ť");
}



void C��¼����2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rc;
	CRect rect;
	GetWindowRect(&rect);
	rc.CopyRect(&rect);
	CPoint pOint;
	GetCursorPos(&pOint);
	if (rect.top < 0 && PtInRect(rect, pOint))
	{
		rect.top = 0;
		MoveWindow(rect.left, rect.top, rc.Width(), rc.Height());
	}
 	else if(rect.top > -3 && rect.top < 3 && !PtInRect(rect,pOint))
 	{
 		rect.top = 3-rect.Height();
 		MoveWindow(rect.left,rect.top,rc.Width(),rc.Height());
 	}
	CDialogEx::OnTimer(nIDEvent);
}
