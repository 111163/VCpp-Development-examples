
// 文件标准对话框Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "文件标准对话框.h"
#include "文件标准对话框Dlg.h"
#include "afxdialogex.h"
#include <cstdlib>
#include <afxmsg_.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const UINT WM_FINDMESSAGE = ::RegisterWindowMessage(FINDMSGSTRING);


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


// C文件标准对话框Dlg 对话框




C文件标准对话框Dlg::C文件标准对话框Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C文件标准对话框Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strEdit = _T("");
}

void C文件标准对话框Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_strEdit);
	DDX_Control(pDX, IDC_PATH, m_ConSta);
	DDX_Control(pDX, IDC_EDIT, m_ConEdit);
}

BEGIN_MESSAGE_MAP(C文件标准对话框Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C文件标准对话框Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C文件标准对话框Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C文件标准对话框Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C文件标准对话框Dlg::OnBnClickedButton4)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON5, &C文件标准对话框Dlg::OnBnClickedButton5)
	ON_REGISTERED_MESSAGE(WM_FINDMESSAGE, &C文件标准对话框Dlg::OnFindReplace)
	ON_BN_CLICKED(IDC_BUTTON6, &C文件标准对话框Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C文件标准对话框Dlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// C文件标准对话框Dlg 消息处理程序

BOOL C文件标准对话框Dlg::OnInitDialog()
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
	nindex = 0;
	degree = FALSE;

	str[0] = "    弃我去者，昨日之日不可留；乱我心者，";
	str[1] = "今日之日多烦扰。长空万里送秋雁，对此可以";
	str[2] = "酣高楼。蓬莱文章建安骨，中间小谢又青发。";
	str[3] = "具怀逸兴壮思飞，欲上青天揽明月。抽刀断水";
	str[4] = "水更流，举杯消愁愁更愁。人生在世不称意，";
	str[5] = "明朝散发弄扁舟。";

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C文件标准对话框Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C文件标准对话框Dlg::OnPaint()
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
		CDC* pDC = GetDC();
	screenx = pDC->GetDeviceCaps(LOGPIXELSX);
	screeny = pDC->GetDeviceCaps(LOGPIXELSY);
	DrawText(pDC,FALSE);
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C文件标准对话框Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C文件标准对话框Dlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"All Files(*.TXT)|*.TXT||",AfxGetMainWnd()); 
	CString strPsth;
	if (dlg.DoModal() == IDOK)
	{
		strPsth = dlg.GetPathName();
		m_ConSta.SetWindowText(strPsth);
		CFile file(strPsth, CFile::modeRead);
		char *p = new char[(int)file.GetLength()];
		file.Read(p, static_cast<int>(file.GetLength()));
		m_strEdit = p;
		delete[] p;
		file.Close();
	}
	UpdateData(FALSE);
}


void C文件标准对话框Dlg::OnBnClickedButton2()
{
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		"All Files(*.TXT)|*.TXT||",AfxGetMainWnd());
	CString strPath; //声明变量                                                        //声明字符数组
	if(dlg.DoModal() == IDOK)                                                    //判断是否按下“保存”按钮
	{
		strPath = dlg.GetPathName();                                            //获得文件保存路径
		if(strPath.Right(4) != ".TXT")                                           //判断文件扩展名
			strPath += ".TXT";                                              //设置文件扩展名
		m_ConSta.SetWindowText(strPath);  //显示文件路径
		CFile file(strPath,CFile::modeCreate|CFile::modeWrite);  //创建文件
		UpdateData(TRUE);//获得编辑框中内容
		CString write;
		write = m_strEdit;                                                     //将字符串拷贝到字符数组中
		file.Write(write,m_strEdit.GetLength());                                        //向文件中写入数据
		file.Close();                                                        //关闭文件
	}
}


void C文件标准对话框Dlg::OnBnClickedButton3()
{
	CFont* TempFont = m_ConEdit.GetFont();
	LOGFONT LogFont;
	TempFont->GetLogFont(&LogFont);
	CFontDialog dlg(&LogFont);
	if (dlg.DoModal() == IDOK)
	{
		m_Font.Detach();                   //分离字体
		LOGFONT temp;                   //声明LOGFONT结构指针
		dlg.GetCurrentFont(&temp);   //获取当前字体信息
		m_Font.CreateFontIndirect(&temp);      //直接创建字体
		m_ConEdit.SetFont(&m_Font);    //设置字体
	}
	// 这里做了一些关于控件状态的修改,最好在配置文件中做一下保存，下次打开的时候，载入配置文件就可以了
	// 在这个时候就要明白一个道理，简单文本文件是不保存定制的格式化的，是它们的编辑器保存了配置在配置文件中
	// 这也同时说明了配置文件的必要性
}


void C文件标准对话框Dlg::OnBnClickedButton4()
{
	CColorDialog dlg(m_Color);
	if (dlg.DoModal() == IDOK)
	{
		m_Color = dlg.GetColor();
		Invalidate();
	}
}


HBRUSH C文件标准对话框Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetBkColor(m_Color);
	}
	return hbr;
}

long C文件标准对话框Dlg::OnFindReplace(WPARAM wParam, LPARAM lParam)
{
	UpdateData(TRUE);
	CString strStr,repText;							//声明字符串变量
	strStr = dlg->GetFindString();						//获得查找字符串
	CString str;										//声明字符串变量
	str = m_strEdit;						//获得编辑框中是文本
	if(dlg->ReplaceCurrent())							//判断是否进行替换
		find = FALSE;									//进行替换
	else
		find = TRUE;									//进行查找
	int len;											//声明整型变量
	if(dlg->ReplaceAll())							//判断是否全部替换
	{
		repText = dlg->GetReplaceString();			//获得替换字符串v
		len    = repText.GetLength();				//获得替换字符串长度
		str.Replace(strStr,repText);				//使用替换字符串替换查找字符串
		m_ConEdit.SetWindowText(str);					//将替换后的字符串显示在编辑框中
	}
	if(find)											//判断是查找还是替换
	{
		len = strStr.GetLength();						//获得要查找字符串的长度
	}
	else
	{
		CString left,right;							//声明字符串变量
		int num   = strStr.GetLength();			//获得查找字符串的长度
		int strnum = str.GetLength();				//获得编辑框中文本长度
		int index;									//声明整型变量
		int ret = str.Find(strStr,0);          // 整个串里面是否能够找到匹配项
		if(ret < 0)							// 整个串里面都没有匹配
			return 1;
		if(!degree)									//判断是否为第一次替换
			index = str.Find(strStr,nindex);		//获得查找字符串在编辑框文本中的位置
 		else if(nindex-rindex >= 0)					//判断起始查找位置是否小于0
 			index = str.Find(strStr,nindex-rindex);//获得查找字符串在编辑框文本中的位置
   		else
   		{
   			nindex = rindex;						//设置起始查找位置
   			return 1;
   		}
		degree = TRUE;
		left = str.Left(index);						//获得替换字符串左侧的字符串
		right = str.Right(strnum-index-num);		//获得替换字符串右侧的字符串
		repText = dlg->GetReplaceString();			//获得替换字符串
		len = repText.GetLength();					//获得替换字符串长度
		rindex = len;
		str = left + repText + right;				//组合成新的字符串
		m_ConEdit.SetWindowText(str);					//在编辑框中显示新的字符串
	}
	int index = str.Find(strStr,nindex);				//获得查找字符串在编辑框文本中的位置  这个语句导致了最后一次查找(或替换后)为-1之后+len就要小于len了
	m_ConEdit.SetSel(index,index+len);						//选中查找或替换的字符串
	nindex = index+len;									//设置起始查找位置★  ----- ★★★★★注意这里越过了一个查找到的元素★★★★★
	m_ConEdit.SetFocus();									//编辑框获得焦点

	return 0;
}


void C文件标准对话框Dlg::OnBnClickedButton5()
{
	dlg = new CFindReplaceDialog;
	dlg->Create(FALSE, NULL);
	dlg->ShowWindow(SW_SHOW);
}


void C文件标准对话框Dlg::OnBnClickedButton6()
{
	DWORD dwflags=PD_ALLPAGES | PD_NOPAGENUMS | PD_USEDEVMODECOPIES
		| PD_SELECTION | PD_HIDEPRINTTOFILE; 
	CPrintDialog dlg(FALSE, dwflags);
	if (dlg.DoModal() == IDOK)
	{
		CDC dc;
		dc.Attach(dlg.GetPrinterDC());
		printx = dc.GetDeviceCaps(LOGPIXELSX);
		printy = dc.GetDeviceCaps(LOGPIXELSY);
		ratex = (double)(printx)/screenx;
		ratey = (double)(printy)/screeny;
		DrawText(&dc, TRUE);
	}
}

void C文件标准对话框Dlg::DrawText(CDC *pDC, BOOL isprinted)
{
	CFont font;
	if(!isprinted) //预览
	{
		ratex = 1;
		ratey = 1;
	}
	else //打印
	{
		pDC->StartDoc("printinformation");
	}
	font.CreatePointFont(120,"宋体",pDC);

	for(int i=0;i<6;i++)
	{
		pDC->SelectObject(&font);
		pDC->TextOut(int(50*ratex),int((50+i*30)*ratey),str[i]);
	}
	if(isprinted)
	{
		pDC->EndDoc();
	}
}



void C文件标准对话框Dlg::OnBnClickedButton7()
{
	CString ReturnPach;
	TCHAR szPath[_MAX_PATH];                       //保存路径变量
	BROWSEINFO bi;                                  // BROWSEINFO结构变量
	bi.hwndOwner    = NULL;                          //HWND句柄
	bi.pidlRoot       = NULL;                          //默认值为NULL
	bi.lpszTitle       = _T("文件浏览对话框");          //对话框标题
	bi.pszDisplayName = szPath;                          //选择文件夹路径
	bi.ulFlags        = BIF_RETURNONLYFSDIRS;       //标记
	bi.lpfn           = NULL;                          //默认值为NULL
	bi.lParam         = NULL;                          //回调消息
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);  //显示文件浏览对话框
	if(pItemIDList)
	{
		if(SHGetPathFromIDList(pItemIDList,szPath)) //判断是否获得文件夹路径
			ReturnPach = szPath;	
	}
	else
	{
		ReturnPach = ""; //文件夹路径为空
	}
	m_ConSta.SetWindowText(ReturnPach);
}
