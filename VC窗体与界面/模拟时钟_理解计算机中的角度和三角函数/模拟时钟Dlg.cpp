
// 模拟时钟Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "模拟时钟.h"
#include "模拟时钟Dlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C模拟时钟Dlg 对话框




C模拟时钟Dlg::C模拟时钟Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C模拟时钟Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C模拟时钟Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C模拟时钟Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C模拟时钟Dlg 消息处理程序

BOOL C模拟时钟Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1, 1000, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C模拟时钟Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C模拟时钟Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	//////////////////////////////////////////////////////////////////////////画圆
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	int xStart = rect.right/2;
	int yStart = rect.bottom/2;
	CTime time = CTime::GetCurrentTime();
	CString strDigits;
	int x,y;
	CSize size;
	CPen Pen(PS_SOLID, 5, RGB(0,0,0));
	CPen *oldPne = pDC->SelectObject(&Pen);
	pDC->Ellipse(5, 5, rect.right - 5, rect.bottom - 5); 
	//////////////////////////////////////////////////////////////////////////写小时数字
	double Radians;
	pDC->SetTextColor(RGB(0,0,0));
	for (int i = 1; i<=12; ++i)
	{	
		strDigits.Format("%d",i);
		size = pDC->GetTextExtent(strDigits, strDigits.GetLength());
		Radians = (double)i*2*3.14/12.0;
		x = (int)((double)(xStart-20)*sin(Radians)) +   // 计算机中横着的是x轴
			xStart - (size.cx/2) ;
		y= -(int)((double)(yStart-20)*cos(Radians)) +
			yStart- ( size.cy/2) ;  // con是负值需要先转正
		pDC->TextOut(x, y, strDigits);
	}
	//////////////////////////////////////////////////////////////////////////计算小时的角度
	Radians = (double)time.GetHour()+(double)time.GetMinute()/60.0+
		(double)time.GetSecond()/3600.0;
	Radians *= 2 * 3.14 / 12.0;
	CPen HourPen(PS_SOLID,5,RGB(0,0,0));
	pDC->SelectObject(&HourPen);
	pDC->MoveTo(xStart,yStart);
	pDC->LineTo(xStart+(int)((double)(xStart/3) *sin(Radians)),
		yStart-(int)((double)(yStart/3)*cos(Radians)));
	//////////////////////////////////////////////////////////////////////////计算分钟的角度
	Radians=(double)time.GetMinute()+(double)time.GetSecond()/60.0;
	Radians*= 2 * 3.14 / 60.0;
	CPen MinutePen(PS_SOLID,3,RGB(0,0,0));
	pDC->SelectObject(&MinutePen);
	pDC->MoveTo(xStart,yStart);
	pDC->LineTo(xStart+(int)((double)((xStart*2)/3)*sin(Radians)),
		yStart-(int)((double)((yStart*2)/3)*cos(Radians)));
	//////////////////////////////////////////////////////////////////////////计算秒的角度
	Radians=(double)time.GetSecond();
	Radians*= 2 * 3.14 / 60.0;
	CPen SecondPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(&SecondPen);
	pDC->MoveTo(xStart,yStart);
	pDC->LineTo(xStart+(int)((double)((xStart*4)/5)*sin(Radians)),
		yStart-(int)((double)((yStart*4)/5)*cos(Radians)));

	pDC->SelectObject(oldPne);
	SecondPen.DeleteObject();
	MinutePen.DeleteObject();
	HourPen.DeleteObject();
	Pen.DeleteObject();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C模拟时钟Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C模拟时钟Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate(TRUE);
	UpdateWindow();
	CDialogEx::OnTimer(nIDEvent);
}
