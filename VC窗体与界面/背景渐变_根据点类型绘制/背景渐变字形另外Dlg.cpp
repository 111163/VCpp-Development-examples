
// 背景渐变字形另外Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "背景渐变字形另外.h"
#include "背景渐变字形另外Dlg.h"
#include "afxdialogex.h"

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


// C背景渐变字形另外Dlg 对话框




C背景渐变字形另外Dlg::C背景渐变字形另外Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C背景渐变字形另外Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C背景渐变字形另外Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C背景渐变字形另外Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C背景渐变字形另外Dlg 消息处理程序

BOOL C背景渐变字形另外Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C背景渐变字形另外Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C背景渐变字形另外Dlg::OnPaint()
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
		CDC *pDC = GetDC();				//获取DC
		CBrush br,*oldbr;
		oldbr=pDC->SelectObject(&br);		//选择画刷
		for(int m=255;m>0;m--)
		{
			int r=(500*m)/255;			//修改颜色值
			br.DeleteObject();
			br.CreateSolidBrush(RGB(255,m,0));	//创建新画刷
			pDC->FillRect(CRect(0,0,r,r),&br);		//填充区域
		}
		CFont font;
		CFont *pOldFont; 
		font.CreatePointFont(500,"宋体");				//创建字体
		pOldFont=pDC->SelectObject(&font);				//选择字体
		pDC->SetBkMode(TRANSPARENT);				//设置文本透明
		CPen pen(PS_SOLID,1,RGB(0, 128, 255));		//创建画笔
		CPen *pOldPen;
		pOldPen=pDC->SelectObject(&pen);				//选择画笔
		// 开始一个路径
		pDC->BeginPath();
		pDC->TextOut(10, 10, "明日科技");				//绘制文本
		pDC->EndPath();		//结束路径
		int num=pDC->GetPath(NULL,NULL,0);		//获取路径点数量
		CPoint*pt=new CPoint[num];					//创建点数组
		BYTE*type=new BYTE[num];					//创建点类型数组
		num=pDC->GetPath(pt,type,num);				//获取路径信息
		CPoint pstart;
		for(int j=0;j<num;j++)						//根据不同点类型绘制线
		{
			switch(type[j])
			{
			case PT_MOVETO:
				pDC->MoveTo(pt[j]);
				pstart=pt[j];
				break;
			case PT_LINETO:
				pDC->LineTo(pt[j]);
				break;
			case PT_BEZIERTO:
				pDC->PolyBezierTo(pt+j,3);
				j=j+2;
				break;
			case PT_BEZIERTO|PT_CLOSEFIGURE:
				pt[j+2]=pstart;
				pDC->PolyBezierTo(pt+j,3);
				j=j+2;
				break;
			case PT_LINETO|PT_CLOSEFIGURE:
				pDC->LineTo(pstart);
				break;
			}
			pDC->CloseFigure();
			//如准备在一个路径里描绘一系列线段，
			//就会有一个打开的图形。调用这个函数的时候，
			//windows会在当前位置和图形的起始处（通常是最后一个
			//MoveToEx操作设置画笔位置的地方）画一条线。
			//图中的这条线和第一条线会连接到一起。
			//注意倘若自己描绘这条线，图形仍会处于打开状态——即使起点与终点相同。
			//这样便造成了与几何画笔的差异。利用CloseFigure，
			//线段会连接到一起——否则它们会用笔尖显示出来。
			//一旦关闭了图形，在路径中画的下一条线就会从一幅新图形开始。
			//打开的图形会被那些用于填充路径的函数自动关闭
		}
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C背景渐变字形另外Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

