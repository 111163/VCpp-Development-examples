
// GDIplus显示GIF动图View.cpp : CGDIplus显示GIF动图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GDIplus显示GIF动图.h"
#endif

#include "GDIplus显示GIF动图Doc.h"
#include "GDIplus显示GIF动图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


class CMemDC1 : public CDC                                          //定义一个CmemDC类
{
private:
	CBitmap*    m_bmp;                                                //定义一个位图对象
	CBitmap*    m_oldbmp;                                     //定义一个位图对象
	CDC*         m_pDC;                                         //定义一个设备上下文指针
	CRect         m_Rect;                                         //定义一个区域对象
public:
	CMemDC1(CDC* pDC, const CRect& rect) : CDC()           //定义构造函数
	{
		CreateCompatibleDC(pDC);                          //创建一个兼容的设备上下文
		m_bmp = new CBitmap;                              //为位图对象分配空间
		//创建位图对象
		m_bmp->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
		m_oldbmp = SelectObject(m_bmp);                            //选中创建的位图
		m_pDC = pDC;                                           //设置成员变量
		m_Rect = rect;                                            //设置区域对象
		this->BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
			pDC, m_Rect.left, m_Rect.top,WHITENESS);       //绘制白色背景
	}
	~CMemDC1()                                                    //析构函数
	{
		m_pDC->BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
			this, m_Rect.left, m_Rect.top,SRCCOPY);//绘制图像
		SelectObject(m_oldbmp);                                    //选中原来的位图对象
		if (m_bmp != NULL)                                         //判断位图对象是否为空
			delete m_bmp;                                      //删除位图对象
		DeleteObject(this);                                       //释放设备上下文
	}
};





// CGDIplus显示GIF动图View

IMPLEMENT_DYNCREATE(CGDIplus显示GIF动图View, CView)

BEGIN_MESSAGE_MAP(CGDIplus显示GIF动图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGDIplus显示GIF动图View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CGDIplus显示GIF动图View 构造/析构

CGDIplus显示GIF动图View::CGDIplus显示GIF动图View()
{
	// TODO: 在此处添加构造代码
	GdiplusStartup(&m_pGdiToken,&m_Gdiplus,NULL);
	m_pBmp = Bitmap::FromFile(L"1.gif");                 //加载GIF图像
	m_Count = m_pBmp->GetFrameDimensionsCount();   //获取帧维数
	GUID *pGuids = new GUID[m_Count];                            //定义一个GUID数组
	m_pBmp->GetFrameDimensionsList(pGuids,m_Count);      //获取图像帧的GUID
	m_FrameCount = m_pBmp->GetFrameCount(pGuids);       //获取GIF帧数
	UINT size;                                                 //定义一个整型变量
	m_Count = 0;                                                   //初始化成员变量
	m_pBmp->GetPropertySize(&size,&delay);                 //获取属性大小
	PropertyItem *pItem = NULL;                                   //定义属性指针
	pItem = (PropertyItem*)malloc(size);                                //为属性指针分配合适的空间
	m_pBmp->GetAllPropertyItems(size,delay,pItem);              //获取属性信息
	delay = ((long*)pItem->value)[0];                              //获取第一帧的延时
	free(pItem);                                              //释放属性对象
	delete [] pGuids;                                         //释放GUID
	fcount = 0;                                                //初始化成员变量
}

CGDIplus显示GIF动图View::~CGDIplus显示GIF动图View()
{
	GdiplusShutdown(m_pGdiToken);
}

BOOL CGDIplus显示GIF动图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGDIplus显示GIF动图View 绘制

void CGDIplus显示GIF动图View::OnDraw(CDC* /*pDC*/)
{
	CGDIplus显示GIF动图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CGDIplus显示GIF动图View 打印


void CGDIplus显示GIF动图View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGDIplus显示GIF动图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGDIplus显示GIF动图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGDIplus显示GIF动图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CGDIplus显示GIF动图View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGDIplus显示GIF动图View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGDIplus显示GIF动图View 诊断

#ifdef _DEBUG
void CGDIplus显示GIF动图View::AssertValid() const
{
	CView::AssertValid();
}

void CGDIplus显示GIF动图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIplus显示GIF动图Doc* CGDIplus显示GIF动图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIplus显示GIF动图Doc)));
	return (CGDIplus显示GIF动图Doc*)m_pDocument;
}
#endif //_DEBUG


// CGDIplus显示GIF动图View 消息处理程序


int CGDIplus显示GIF动图View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer(0, delay*10, NULL);

	return 0;
}


void CGDIplus显示GIF动图View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	GUID Guid = FrameDimensionTime;                                 //定义一个GUID
	CDC* pDC = GetDC();                                      //获取视图窗口的设备上下文
	//定义一个内存画布

	CMemDC1 dc(pDC,CRect(0,0,m_pBmp->GetWidth(),m_pBmp->GetHeight()));
	Graphics gh(dc.m_hDC);                                         //定义一个图像对象
	//向设备上下文中绘制图像
	gh.DrawImage(m_pBmp,0,0,m_pBmp->GetWidth(),m_pBmp->GetHeight());
	m_pBmp->SelectActiveFrame(&Guid,fcount++);        //设置下一帧
	if(fcount == m_FrameCount)                                    //判断当前帧是否为尾帧
		fcount = 0;                                                 //将当前帧设置为第一帧

	CView::OnTimer(nIDEvent);
}
