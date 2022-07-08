
// 星座物语2View.cpp : C星座物语2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "星座物语2.h"
#endif

#include "星座物语2Doc.h"
#include "星座物语2View.h" 
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C星座物语2View

IMPLEMENT_DYNCREATE(C星座物语2View, CView)

BEGIN_MESSAGE_MAP(C星座物语2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTONSHOW, &C星座物语2View::OnButtonshow)
END_MESSAGE_MAP()

// C星座物语2View 构造/析构

C星座物语2View::C星座物语2View()
{
	// TODO: 在此处添加构造代码
	m_Index = 0;

}

C星座物语2View::~C星座物语2View()
{
}

BOOL C星座物语2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C星座物语2View 绘制

void C星座物语2View::OnDraw(CDC* pDC)
{
	C星座物语2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC memDC;										//定义一个设备上下文
	memDC.CreateCompatibleDC(pDC);					//创建兼容的设备上下文
	CBitmap bmp;										//定义位图对象
	bmp.LoadBitmap(IDB_BKBMP+m_Index);						//加载位图
	memDC.SelectObject(&bmp);							//选中位图对象
	BITMAP BitInfo;									//定义位图结构
	bmp.GetBitmap(&BitInfo);								//获取位图信息
	int x = BitInfo.bmWidth;								//获取位图宽度
	int y = BitInfo.bmHeight;								//获取位图高度
	pDC->BitBlt(0, 0, x, y, &memDC, 0, 0, SRCCOPY);	//绘制位图

}


// C星座物语2View 打印

BOOL C星座物语2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C星座物语2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C星座物语2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C星座物语2View 诊断

#ifdef _DEBUG
void C星座物语2View::AssertValid() const
{
	CView::AssertValid();
}

void C星座物语2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C星座物语2Doc* C星座物语2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C星座物语2Doc)));
	return (C星座物语2Doc*)m_pDocument;
}
#endif //_DEBUG


// C星座物语2View 消息处理程序


void C星座物语2View::OnButtonshow()
{
	CMainFrame* pWnd = (CMainFrame*)AfxGetMainWnd();
	CTime time;
	pWnd->m_Date.GetTime(time);
	switch(time.GetMonth())
	{
	case 1:
		if(time.GetDay() < 20)		//摩羯座
			m_Index = 10;
		else						//水瓶座
			m_Index = 11;
		break;
	case 2:
		if(time.GetDay() < 19)		//水瓶座
			m_Index = 11;
		else						//双鱼座
			m_Index = 12;
		break;
	case 3:
		if(time.GetDay() < 21)		//双鱼座
			m_Index = 12;
		else						//白羊座
			m_Index = 1;
		break;
	case 4:
		if(time.GetDay() < 21)		//白羊座
			m_Index = 1;
		else						//金牛座
			m_Index = 2;
		break;
	case 5:
		if(time.GetDay() < 21)		//金牛座
			m_Index = 2;
		else						//双子座
			m_Index = 3;
		break;
	case 6:
		if(time.GetDay() < 22)		//双子座
			m_Index = 3;
		else						//巨蟹座
			m_Index = 4;
		break;
	case 7:
		if(time.GetDay() < 23)		//巨蟹座
			m_Index = 4;
		else						//狮子座
			m_Index = 5;
		break;
	case 8:
		if(time.GetDay() < 23)		//狮子座
			m_Index = 5;
		else						//处女座
			m_Index = 6;
		break;
	case 9:
		if(time.GetDay() < 23)		//处女座
			m_Index = 6;
		else						//天秤座
			m_Index = 7;
		break;
	case 10:
		if(time.GetDay() < 23)		//天秤座
			m_Index = 7;
		else						//天蝎座
			m_Index = 8;
		break;
	case 11:
		if(time.GetDay() < 22)		//天蝎座
			m_Index = 8;
		else						//射手座
			m_Index = 9;
		break;
	case 12:
		if(time.GetDay() < 22)		//射手座
			m_Index = 9;
		else						//摩羯座
			m_Index = 10;
		break;
	}
	Invalidate();
}
