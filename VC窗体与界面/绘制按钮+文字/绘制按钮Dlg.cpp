
// 绘制按钮Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "绘制按钮.h"
#include "绘制按钮Dlg.h"
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


// C绘制按钮Dlg 对话框




C绘制按钮Dlg::C绘制按钮Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C绘制按钮Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C绘制按钮Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C绘制按钮Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C绘制按钮Dlg 消息处理程序

BOOL C绘制按钮Dlg::OnInitDialog()
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

void C绘制按钮Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C绘制按钮Dlg::OnPaint()
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
		//////////////////////////////////////////////////////////////////////////绘制圆角按钮
		//CRect rect(10,10,200,100);
		//CPaintDC dc(this);
		//dc.SetBkMode(TRANSPARENT);
		//CBrush m_Brush;
		//m_Brush.CreateSolidBrush(RGB(50, 130, 200));
		//CBrush* oldBrush = dc.SelectObject(&m_Brush);
		//CPen m_Pan(PS_SOLID, 2, RGB(200, 100, 198));
		//CPen* oldPan = dc.SelectObject(&m_Pan);
		//dc.RoundRect(20, 20, rect.right,rect.bottom, 30, 30);

		//dc.SetTextColor(RGB(0,0,0));
		//CString str = "按钮标题";
		//dc.DrawText(str, CRect(20, 20, rect.right, rect.bottom),
		//	DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		//
		//dc.SelectObject(oldBrush);
		//dc.SelectObject(oldPan);
		//m_Brush.DeleteObject();
		//m_Pan.DeleteObject();

		//////////////////////////////////////////////////////////////////////////绘制经典按钮
		//CPaintDC dc(this); 
		//CRect rect(10,10,80,40);
		//dc.DrawFrameControl(&rect,DFC_BUTTON,DFCS_BUTTONPUSH);
		//CString str = "按钮标题";
		////绘制按钮文本
		//dc.SetBkMode(TRANSPARENT);
		//dc.DrawText(str,CRect(10,10,rect.right,rect.bottom), 
		//	DT_CENTER|DT_VCENTER|DT_SINGLELINE); 

		//////////////////////////////////////////////////////////////////////////绘制三角形并填充+绘制区域边框
		//CPaintDC dc(this);
		//dc.BeginPath();
		//	int x = 10;
		//	int y = 100;
		//	dc.MoveTo(x, y);
		//	x += 50;
		//	y = 30;
		//	dc.LineTo(x, y);
		//	x += 50;
		//	y = 100;
		//	dc.LineTo(x, y);
		//	x = 10;
		//	y = 100;
		//	dc.LineTo(x, y);
		//dc.EndPath();
		//CRgn rgn;
		//rgn.CreateFromPath(&dc);
		//CBrush brush(RGB(200, 100, 0));
		//dc.FillRgn(&rgn, &brush);
		//CBrush fbrush(RGB(0,0,0));
		//dc.FrameRgn(&rgn,&fbrush,2,2);

		//fbrush.DeleteObject();
		//rgn.DeleteObject();
		//brush.DeleteObject();


		////////////////////////////////////////////////////////////////////////// 文字+边框+背景+字体+文字颜色
		CDC *pDC = GetDC();         //获取DC
		CFont font,*pOldfont;          //定义字体
		CPoint ptStart;                     //定义位置
		ptStart.x=10;                       //设置位置
		ptStart.y=10;
		int iOffset=12;                     //偏移大小
		font.CreatePointFont(500 ,"宋体");               //创建字体
		pOldfont=pDC->SelectObject(&font);                  //选中字体
		CSize size=pDC->GetTextExtent("明日科技");             //获取文本大小
		//CGdiObject*object = pDC->SelectStockObject(NULL_BRUSH);         //透明
		CBrush brush(NULL_BRUSH);//RGB(200, 100, 100)
		pDC->SelectObject(&brush);
		pDC->Rectangle(ptStart.x,ptStart.y,size.cx+iOffset,size.cy+iOffset);   //绘制矩形
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,0,0));
		pDC->TextOut(ptStart.x,ptStart.y,"明日科技");           //在指定位置输出文本
		font.DeleteObject();  
		pDC->SelectObject(pOldfont);
		//pDC->SelectObject(object);
		brush.DeleteObject();

		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C绘制按钮Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

