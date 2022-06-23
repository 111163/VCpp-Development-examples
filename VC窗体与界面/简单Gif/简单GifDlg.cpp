
// 简单GifDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "简单Gif.h"
#include "简单GifDlg.h"
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


// C简单GifDlg 对话框




C简单GifDlg::C简单GifDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C简单GifDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C简单GifDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C简单GifDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C简单GifDlg 消息处理程序

BOOL C简单GifDlg::OnInitDialog()
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

void C简单GifDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C简单GifDlg::OnPaint()
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
		CPaintDC dc(this); // device context for painting

		//TODO: Add your message handler code here
		char buf[512];
		::GetCurrentDirectory(512,buf); // 得到当前程序所在路径
		strcat(buf,"\\test.gif");       // 找到路径下的gif文件
		CFileStatus fstatus;            // CFile::GetStatus方法使用此结构来检索有关文件的状态信息。
		CFile file; 
		IStream *pStm;
		ULONGLONG cb;       
		if(file.Open(buf,CFile::modeRead)&&file.GetStatus(buf,fstatus)&& // 以只读格式打开文件，读取文件状态成功，并且文件不为空
			((cb = fstatus.m_size) != -1)) 
		{ 
			HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb); // 该函数从堆中分配一定数目的字节数
			LPVOID pvData = NULL; 
			if (hGlobal != NULL)  // 分配成功
			{ 
				if ((pvData = GlobalLock(hGlobal)) != NULL) 
				{ 
					file.Read(pvData, cb);  // 将文件读取到pvData指针指向的全局内存位置
					GlobalUnlock(hGlobal);  // 全局资源加锁
					CreateStreamOnHGlobal(hGlobal, TRUE, &pStm); // 将流和内存关联
				} 
			} 
		}
		IPicture *pPic; //CComQIPtr<IPicture> pPic;

		//用OleLoadPicture获得IPicture接口指针
		//得到IPicture COM接口对象后，你就可以进行获得图片信息、显示图片等操作
		if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,false,IID_IPicture,(LPVOID*)&pPic)))
		{
			// 用API OleLoadPicture来加载JPG、GIF格式的图片（注：不支持PNG格式，另外GIF只能加载第一帧，且不支持透明） 
			// OleLoadPicture 函数实际上创建了一个IPicture类型的COM接口对象，然后我们可以通过这个COM接口来操作图片
			//（实际上你也可以用API OleCreatePictureIndirect来加载图片，
			// 不过相比而言OleLoadPicture函数简化了基于流的IPicture对象的创 建）。
			long a,b;
			pPic->get_Width(&a);
			pPic->get_Height(&b);
			CSize sz(a,b);
			CDC *pdc=GetDC();
			pdc->HIMETRICtoDP(&sz);  // 将HIMETRIC大小从OLE转换为像素时，请使用此函数
			CRect rect;              // 得到客户区矩形
			this->GetClientRect(&rect);
			pPic->Render(*pdc,rect.left+1,rect.top+1,sz.cx,sz.cy,0,b,a,-b,&rect); //在指定的DC上绘出图片
		}                                                                         // 从com接口读取内容到DC上
		//Do not call CDialog::OnPaint() for painting messages
		/*CDialogEx::OnPaint();*/
	}
}



//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C简单GifDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

