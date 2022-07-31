
// GDIplus使用Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GDIplus使用.h"
#include "GDIplus使用Dlg.h"
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


// CGDIplus使用Dlg 对话框




CGDIplus使用Dlg::CGDIplus使用Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDIplus使用Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nCheck = 1;
}

void CGDIplus使用Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGENAME, m_ImageName);
	DDX_Radio(pDX, IDC_BMP, m_nCheck);
}

BEGIN_MESSAGE_MAP(CGDIplus使用Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGDIplus使用Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_QUIT, &CGDIplus使用Dlg::OnBnClickedQuit)
	ON_BN_CLICKED(IDC_CONVERT, &CGDIplus使用Dlg::OnBnClickedConvert)
	/*ON_CONTROL_RANGE(IDC_BMP, IDC_GIF,  &CGDIplus使用Dlg::OnBnClickedBmp)*/
	ON_BN_CLICKED(IDC_BMP, &CGDIplus使用Dlg::OnBnClickedBmp)
	ON_BN_CLICKED(IDC_JPEG, &CGDIplus使用Dlg::OnBnClickedJpeg)
	ON_BN_CLICKED(IDC_GIF, &CGDIplus使用Dlg::OnBnClickedGif)
END_MESSAGE_MAP()


// CGDIplus使用Dlg 消息处理程序

BOOL CGDIplus使用Dlg::OnInitDialog()
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
	GdiplusStartup(&m_pGdiToken,&m_Gdiplus,NULL);	


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGDIplus使用Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGDIplus使用Dlg::OnPaint()
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
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGDIplus使用Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGDIplus使用Dlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	GdiplusShutdown(m_pGdiToken);
	CDialogEx::OnCancel();
}


void CGDIplus使用Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog flDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"图像文件|*.bmp;*.jpeg;*.gif|所有文件|*.*||", this);
	if (flDlg.DoModal() == IDOK)
	{
		m_FileName = flDlg.GetPathName();
		m_ImageName.SetWindowText(m_FileName);
	}
	/*CDialogEx::OnOK();*/
}


void CGDIplus使用Dlg::OnBnClickedQuit()
{
	OnCancel();
}

int GetCodecClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;		//记录图像编码的数量
	UINT  size = 0;		//记录编码数组大小
	ImageCodecInfo* pImageCodecInfo = NULL;	//定义图像编码信息
	GetImageEncodersSize(&num, &size);		//获取图像编码的数量和编码数组大小
	if(size == 0)
		return -1; 
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;  
	GetImageEncoders(num, size, pImageCodecInfo);	//获取图像编码
	for(UINT j = 0; j < num; ++j)					//匹配图像格式,
	{
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		{
			*pClsid = pImageCodecInfo[j].Clsid;

			return j;  
		}    
	} 
	return -1; 
}


void CGDIplus使用Dlg::OnBnClickedConvert()
{
	// TODO: 在此添加控件通知处理程序代码
	switch(m_nCheck)
	{
	case 0:
		{
			CFileDialog flDlg(FALSE,"bmp","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"所有文件|*.*||",this);
			if (flDlg.DoModal()==IDOK)
			{
				CString svname = flDlg.GetPathName();
				Bitmap bmp(m_FileName.AllocSysString());
				CLSID clsid ;
				GetCodecClsid(L"image/bmp", &clsid);
				bmp.Save(svname.AllocSysString(),&clsid);	
			}
		}
		break;
	case 1:
		{
			CFileDialog flDlg(FALSE,"jpeg","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"所有文件|*.*||",this);
			if (flDlg.DoModal()==IDOK)
			{
				CString svname = flDlg.GetPathName();
				Bitmap bmp(m_FileName.AllocSysString());
				CLSID clsid;
				GetCodecClsid(L"image/jpeg", &clsid);
				bmp.Save(svname.AllocSysString(),&clsid);
			}
		}
		break;
	case 2:
		{
			CFileDialog flDlg(FALSE,"gif","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,"所有文件|*.*||",this);
			if (flDlg.DoModal()==IDOK)
			{
				CString svname = flDlg.GetPathName();
				Bitmap bmp(m_FileName.AllocSysString());
				CLSID clsid = ImageFormatGIF;
				GetCodecClsid(L"image/gif", &clsid);
				bmp.Save(svname.AllocSysString(),&clsid);	
			}
		}
		break;
	}	
}


void CGDIplus使用Dlg::OnBnClickedBmp()
{
	m_nCheck = 0;
}


void CGDIplus使用Dlg::OnBnClickedJpeg()
{
	m_nCheck = 1;
}


void CGDIplus使用Dlg::OnBnClickedGif()
{
	m_nCheck = 2;
}
