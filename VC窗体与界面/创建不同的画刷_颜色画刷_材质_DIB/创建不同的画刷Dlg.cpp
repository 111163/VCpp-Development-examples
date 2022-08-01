
// 创建不同的画刷Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "创建不同的画刷.h"
#include "创建不同的画刷Dlg.h"
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


// C创建不同的画刷Dlg 对话框




C创建不同的画刷Dlg::C创建不同的画刷Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C创建不同的画刷Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C创建不同的画刷Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C创建不同的画刷Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C创建不同的画刷Dlg 消息处理程序

BOOL C创建不同的画刷Dlg::OnInitDialog()
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

void C创建不同的画刷Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C创建不同的画刷Dlg::OnPaint()
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
		CPaintDC dc(this);
		dc.SetBkMode(TRANSPARENT);
		CFont font;
		font.CreatePointFont(80,"Courier New");
		dc.SelectObject(&font);

		CBrush br,*oldbr;
		br.CreateSolidBrush(RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(10,10,110,110);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(10,110,"单色刷子");

		br.CreateHatchBrush(HS_CROSS,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(120,10,220,110);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(120,110,"HS_CROSS");

		br.CreateHatchBrush(HS_DIAGCROSS,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(230,10,330,110);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(230,110,"HS_DIAGCROSS");

		br.CreateHatchBrush(HS_FDIAGONAL,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(340,10,440,110);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(340,110,"HS_FDIAGONAL");

		br.CreateHatchBrush(HS_HORIZONTAL,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(10,120,110,220);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(10,220,"HS_HORIZONTAL");

		br.CreateHatchBrush(HS_VERTICAL,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(120,120,220,220);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(120,220,"HS_VERTICAL");

		br.CreateHatchBrush(HS_BDIAGONAL,RGB(255,0,0));
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(230,120,330,220);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(230,220,"HS_BDIAGONAL");

		m_bmp.bmiHeader.biSize=sizeof(m_bmp.bmiHeader);
		m_bmp.bmiHeader.biBitCount=0;
		HBITMAP hbmp=(HBITMAP)LoadImage(::AfxGetResourceHandle(),"mr.bmp",IMAGE_BITMAP,0,
			0,LR_DEFAULTCOLOR|LR_LOADFROMFILE);
		GetDIBits(dc.GetSafeHdc(),hbmp,1,1,NULL,&m_bmp,DIB_RGB_COLORS);

		//压缩的设备无关位图（DIB）指BITMAPINFO及后面的位图象素字节
		m_pbmpheader=(long*)malloc(m_bmp.bmiHeader.biSizeImage+sizeof(BITMAPINFO));
		m_pbmpinfo=(BITMAPINFO*)m_pbmpheader;       // 信息开头
		m_pbmpdata=m_pbmpheader+sizeof(BITMAPINFO); // 数据开头
		memcpy(m_pbmpheader,(const void*)&m_bmp,sizeof(BITMAPINFOHEADER));
		GetDIBits(dc.GetSafeHdc(),hbmp,1,m_pbmpinfo->bmiHeader.biHeight,m_pbmpdata,
			m_pbmpinfo,DIB_RGB_COLORS);				// 读取到信息和数据   -实际上就是将以m_pbmpheader开头的数据区域填充为了信息和数据

		LOGBRUSH logbrush;							// 创建结构，并填写结构
		logbrush.lbColor=DIB_RGB_COLORS;
		logbrush.lbHatch=(LONG)m_pbmpheader;
		logbrush.lbStyle=BS_DIBPATTERNPT;
		br.CreateBrushIndirect(&logbrush);
		oldbr=dc.SelectObject(&br);
		dc.Rectangle(340,120,440,220);
		dc.SelectObject(oldbr);
		br.DeleteObject();
		dc.TextOut(340,220,"LOGBRUSH");

		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C创建不同的画刷Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

