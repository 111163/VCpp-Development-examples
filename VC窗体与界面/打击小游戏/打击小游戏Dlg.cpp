
// 打击小游戏Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "打击小游戏.h"
#include "打击小游戏Dlg.h"
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


// C打击小游戏Dlg 对话框




C打击小游戏Dlg::C打击小游戏Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C打击小游戏Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_DeathCount = 0;
	m_Grade = 0;
	m_nLevel = 0;
	m_MisCount = 0;
	m_EscCount = 0;

	m_ptOrg.x = m_ptOrg.y = 15;       //设置坐标原点
	m_nCellHeight = 39;                   //设置单元格高度
	m_nCellWidth = 37;                    //设置单元格宽度
	m_nPerson = -1;
	for(int i=0; i<100; i++)                //设置游戏级别分数段
	{
		m_nLevels[i] = 1200 - i*100;
	}
	m_bHit = FALSE;
	m_State = GS_NONE;                //初始化游戏状态
}

void C打击小游戏Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DEATHCOUNT, m_DeathCount);
	DDX_Text(pDX, IDC_GRADE, m_Grade);
	DDX_Text(pDX, IDC_LEVEL, m_nLevel);
	DDX_Text(pDX, IDC_MISPLAY, m_MisCount);
	DDX_Text(pDX, IDC_ESCCOUNT, m_EscCount);
}

BEGIN_MESSAGE_MAP(C打击小游戏Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_START, &C打击小游戏Dlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_ENDGAME, &C打击小游戏Dlg::OnBnClickedEndgame)
END_MESSAGE_MAP()


// C打击小游戏Dlg 消息处理程序

BOOL C打击小游戏Dlg::OnInitDialog()
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
	srand((unsigned)time(NULL));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C打击小游戏Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C打击小游戏Dlg::OnPaint()
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
		// 这里要先调用父类的OnPaint方法，先将默认处理做完后，再绘制我们的图形图像---这里一定要注意
		CDialogEx::OnPaint();

		m_GridRC.left = m_ptOrg.x;                         //设置表格区域
		m_GridRC.top = m_ptOrg.y;
		m_GridRC.right = m_ptOrg.x + 9*m_nCellWidth;
		m_GridRC.bottom = m_ptOrg.y + 9*m_nCellHeight;
		//绘制表格
		CDC* pDC  = GetDC();                                //获取窗口设备上下文
		pDC->FillRect(m_GridRC, NULL);                      //填充区域
		for(int i=0; i<=9; i++)                             //绘制列
		{    
			pDC->MoveTo(m_ptOrg.x, m_ptOrg.y + i*m_nCellHeight);
			pDC->LineTo(m_ptOrg.x + 9*m_nCellWidth ,m_ptOrg.y + i*m_nCellHeight);
		}
		for(int j=0; j<=9; j++)                            //绘制行
		{ 

			pDC->MoveTo(m_ptOrg.x + j*m_nCellWidth, m_ptOrg.y);
			pDC->LineTo(m_ptOrg.x + j*m_nCellWidth, m_ptOrg.y + 9*m_nCellHeight);
		}
		if (m_nPerson > 0)                                   //绘制人物
		{
			CBitmap bmp;                                     //定义位图对象
			bmp.LoadBitmap(IDB_PERSON);                      //加载位图
			CDC memDC;
			memDC.CreateCompatibleDC(pDC);                   //创建兼容的设备上下文
			memDC.SelectObject(&bmp);                        //选中位图
			pDC->StretchBlt(m_PersonRC.left, m_PersonRC.top, m_PersonRC.Width(), 
				m_PersonRC.Height(), &memDC, 0, 0, m_PersonRC.Width()-1, 
				m_PersonRC.Height()-1, SRCCOPY);      //绘制任务
			bmp.DeleteObject();                                           //释放位图对象
			memDC.DeleteDC();                                          //释放内存设备上下文
		}
		ReleaseDC(pDC);	
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C打击小游戏Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C打击小游戏Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nPerson = rand() % 73;    //产生一个随机数
	if (m_nPerson == 0)
		m_nPerson = 1;

	int nX = m_nPerson % 9;            //计算人物出现的位置
	int nY = m_nPerson / 9;
	if(nX == 0)
	{
		nX = 9;
	}
	else 
	{
		nY++;
	}
	//确定小人出现的区域   
	m_PersonRC.left = m_ptOrg.x + (nX-1)*m_nCellWidth;
	m_PersonRC.right = m_PersonRC.left + m_nCellWidth;
	m_PersonRC.top = m_ptOrg.y + (nY-1)*m_nCellHeight;
	m_PersonRC.bottom = m_PersonRC.top + m_nCellHeight;

	InvalidateRect(m_PersonRC);      //更新任务区域
	if (m_bHit == FALSE)          //人物没有被击中
	{
		m_EscCount++;             //增加逃逸数量
		UpdateData(FALSE);
	}
	m_bHit = FALSE;
	if (m_nLevel <= 100)
	{
		if (m_Grade >= m_nLevel*50*15)
		{
			m_nLevel++;
			UpdateData(FALSE);
			NextLevel();            //下一关
		}
	}
	else       //
	{
		OnEndgame();               //结束游戏
	}
	CDialogEx::OnTimer(nIDEvent);
}


void C打击小游戏Dlg::NextLevel(void)
{
	KillTimer(1);                  //结束计时器
	m_State = GS_BEGIN;
	m_bHit = TRUE;
	SetTimer(1, m_nLevels[m_nLevel-1], NULL);      //重新开始计时器
}


void C打击小游戏Dlg::OnStart(void)
{
	if (m_State != GS_BEGIN)
	{
		m_State = GS_BEGIN;
		m_bHit = TRUE;
		SetTimer(1, m_nLevels[m_nLevel-1], NULL);       //创建一个计时器，开始新的游戏
	}
}


void C打击小游戏Dlg::OnEndgame(void)
{
	if (m_State == GS_BEGIN)                  //游戏已开始
	{
		m_State = GS_END;                     //设置游戏状态
		KillTimer(1);                                 //结束计时器
		m_Grade = 0;                               //初始化数据
		m_EscCount = 0;
		m_DeathCount = 0;
		m_MisCount = 0;
		m_nLevel = 1;
		UpdateData(FALSE);
		m_nPerson = -1;

		InvalidateRect(m_PersonRC);         //更新任务区域

	}
}


void C打击小游戏Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_State == GS_BEGIN)
	{
		if (m_PersonRC.PtInRect(point))           //击中目标
		{
			CDC *pDC = GetDC();                   //获取窗口设备上下文
			CBitmap bmp;
			bmp.LoadBitmap(IDB_HITPERSON);         //加载位图
			CDC memDC;
			memDC.CreateCompatibleDC(pDC);         //创建内存设备上下文
			memDC.SelectObject(&bmp);              //选中位图

			pDC->StretchBlt(m_PersonRC.left, m_PersonRC.top, m_PersonRC.Width(), 
				m_PersonRC.Height(), &memDC, 0, 0, m_PersonRC.Width()-1, 
				m_PersonRC.Height()-1, SRCCOPY);       //绘制位图

			bmp.DeleteObject();                        //释放位图对象
			memDC.DeleteDC();
			ReleaseDC(pDC);

			m_DeathCount++;                                               
			m_Grade = m_DeathCount*50;                 //设置积分
		}
		else                                            //未击中目标 
		{
			m_MisCount++;                               //累加未击中次数
		}
		UpdateData(FALSE);

	}
	if (m_GridRC.PtInRect(point))
	{
		//设置鼠标指针新的形状
		SetCursor(LoadCursor(AfxGetResourceHandle(), MAKEINTRESOURCE(IDC_CURSOR2)));
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void C打击小游戏Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_bHit = TRUE;
	if (m_GridRC.PtInRect(point))             //如果指针位于表格区域
	{
		//设置新的鼠标指针形状
		SetCursor(LoadCursor(AfxGetResourceHandle(), MAKEINTRESOURCE(IDC_CURSOR1)));

	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void C打击小游戏Dlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	OnStart();
}


void C打击小游戏Dlg::OnBnClickedEndgame()
{
	// TODO: 在此添加控件通知处理程序代码
	OnEndgame();
}
