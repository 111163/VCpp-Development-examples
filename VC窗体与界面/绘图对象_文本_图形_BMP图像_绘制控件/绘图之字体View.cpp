
// 绘图之字体View.cpp : C绘图之字体View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "绘图之字体.h"
#endif

#include "绘图之字体Doc.h"
#include "绘图之字体View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C绘图之字体View

IMPLEMENT_DYNCREATE(C绘图之字体View, CView)

BEGIN_MESSAGE_MAP(C绘图之字体View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C绘图之字体View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C绘图之字体View 构造/析构

C绘图之字体View::C绘图之字体View()
{
	// TODO: 在此处添加构造代码
// 	m_hBmp = LoadImage(NULL, "Demo.bmp", IMAGE_BITMAP
// 		, 0, 0, LR_LOADFROMFILE);

	CFile file;
	file.Open("bk.bmp", CFile::modeRead);
	int len = file.GetLength();
	file.Seek(14, CFile::begin);
	m_pBmpData = new char[len - 14];
	file.Read(m_pBmpData, len - 14);
	file.Close();
}

C绘图之字体View::~C绘图之字体View()
{
	delete[] m_pBmpData;
}

BOOL C绘图之字体View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C绘图之字体View 绘制

void C绘图之字体View::OnDraw(CDC* pDC)
{
	C绘图之字体Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

// 	CFont Font;
// 	Font.CreateFont(24,24,0,0,FW_NORMAL,0,TRUE,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
// 		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_ROMAN,"宋体");
// 	CFont *pOldFont = NULL;
// 	pOldFont = pDC->SelectObject(&Font);
// 	pDC->TextOut(10, 10, "同一个世界,同一个梦想");
// 	pDC->SelectObject(pOldFont);
// 	Font.DeleteObject();

/*	pDC->TextOut(0,0,"你好");*/

// 	CRect rc(100, 20, 300, 200);
// 	CString str = "你好，我好，世界好！";
// 	CBrush brush(RGB(0,0,0));
// 	pDC->FrameRect(rc, &brush);
// 	pDC->DrawText(str, rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);
// 	brush.DeleteObject();

// 	int pts[4] = {100, 200, 300, 400};
// 	pDC->SetTextColor(RGB(255, 0, 0));
// 	pDC->TabbedTextOut(0, 20, "\t你\t我\t世\t界", 4, pts, 0);

// 	CFont Font;
// 	Font.CreateFont(12,12,2700,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
// 		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_ROMAN,"黑体");
// 	CFont *oldFont = pDC->SelectObject(&Font);
// 	pDC->SetTextColor(RGB(255, 0, 0));
// 	pDC->TextOut(100, 50, "世界大同");
// 	pDC->SelectObject(oldFont);
// 	Font.DeleteObject();
// 
// 	Font.CreatePointFont(120, "黑体", pDC);
// 	pDC->SetTextColor(COLOR_BTNTEXT);
// 	oldFont = pDC->SelectObject(&Font);
// 	pDC->TextOut(120, 70, "世界大同");
// 	pDC->TextOut(120, 90, "世界大同");
// 	pDC->SelectObject(oldFont);
// 	Font.DeleteObject();

	//CFont mFont;                                                   //定义一个字体对象
	////创建字体
	//VERIFY(mFont.CreateFont(                        
	//	150, 50, 0, 0, FW_HEAVY, TRUE, FALSE, 
	//	0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, 
	//	CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
	//	DEFAULT_PITCH | FF_SWISS, "宋体"));
	//CPen pen(PS_SOLID,2,RGB(255,0,0));                            //定义一个画笔
	//pDC->SelectObject(&pen);                                //选中画笔
	//pDC->BeginPath();                                     //开始一个路径
	//CFont *pOldFont = pDC->SelectObject(&mFont);      //选中创建的字体
	//pDC->SetBkMode(TRANSPARENT);                 //设置画布的背景模式为透明
	//pDC->TextOut(30,30,"嫦娥一号探月卫星");              //输出文本
	//pDC->EndPath();                                       //关闭路径
	//pDC->StrokePath();                                   //用当前的画笔绘制路径
	//mFont.DeleteObject();                                //上述字体对象
	//pDC->SelectObject(pOldFont);                           //选中之前的字体对象

// 	CBitmap bmp;
// 	bmp.LoadBitmap(IDB_BKBITMAP);
// 
// 	BITMAP bInfo;
// 	bmp.GetBitmap(&bInfo);
// 	int width = bInfo.bmWidth;
// 	int height = bInfo.bmHeight;
// 	CDC memDC;
// 	memDC.CreateCompatibleDC(pDC);
// 	memDC.SelectObject(&bmp);
// 
// 	pDC->BitBlt(0,0,width,height,&memDC,0,0,SRCCOPY);
// 	memDC.DeleteDC();
// 	bmp.DeleteObject();
// 
// 	CFont mFont;
// 	VERIFY(mFont.CreateFont(					
// 		24, 20, 0, 0, FW_HEAVY, FALSE, FALSE, 
// 		0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, 
// 		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
// 		DEFAULT_PITCH | FF_SWISS, "宋体"));
// 	CFont *odlFont = pDC->SelectObject(&mFont);
// 	pDC->SetBkMode(TRANSPARENT);
// 	pDC->SetTextColor(RGB(0, 255, 0));
// 	pDC->TextOut(60, 60, "田园生活");
// 	pDC->SelectObject(odlFont);
// 	mFont.DeleteObject();

	//CPen pen(PS_SOLID, 2, RGB(255,0,0));
	//CPen *oldPne = pDC->SelectObject(&pen);

	//pDC->MoveTo(50,30);                               //设置坐标起点
	//pDC->LineTo(240,30);                               //绘制上边框
	//pDC->LineTo(240,120);                             //绘制右边框
	//pDC->LineTo(50,120);                                     //绘制下边框
	//pDC->LineTo(50,30);                                 //绘制左边框
	////绘制多变形
	//pDC->MoveTo(300,50);                             //设置当前坐标
	//pDC->LineTo(400,50);                               //绘制上边框
	//pDC->LineTo(450,100);                             //绘制右斜边框
	//pDC->LineTo(400,150);                             //绘制右斜边框
	//pDC->LineTo(300,150);                                    //绘制底边框
	//pDC->LineTo(250,100);                             //绘制左上边框
	//pDC->LineTo(300,50);                               //绘制左上边框
	////绘制弧线
	//CRect rc(500,50,600,100);                          //定义一个区域对象
	//pDC->Arc(500,50,600,100,520,70,560,30);         //绘制曲线
	//CBrush brush(RGB(255, 0, 0));
	//pDC->FrameRect(rc, &brush);

	//CRect rc1(100, 100, 180, 180);
	//pDC->Rectangle(20,20,80,80);
	//pDC->RoundRect(&rc1, CPoint(20,20));

	//CPoint pot[6] =  {CPoint(300,50),CPoint(400,50),CPoint(450,100),    //定义多边形端点
	//	CPoint(400,150),CPoint(300,150), CPoint(250,100)};
	////pDC->Polygon(pot, 6);

	//pDC->Polyline(pot, 6);

	//brush.DeleteObject();
	//pDC->SelectObject(oldPne);
	//pen.DeleteObject();


	//CRect rc(50,50,120,80);                                                         //定义一个区域对象
	//pDC->DrawFrameControl(rc,DFC_BUTTON,DFCS_BUTTONPUSH);     //绘制按钮
	//CRect CapRC(130,50,160,80);                                                       //定义一个区域对象
	////绘制标题栏关闭按钮
	//pDC->DrawFrameControl(CapRC,DFC_CAPTION,DFCS_CAPTIONHELP);
	//CRect ScrollRC(170,50,200,80);                                              //定义一个区域对象
	////绘制滚动条按钮
	//pDC->DrawFrameControl(ScrollRC,DFC_SCROLL,DFCS_SCROLLCOMBOBOX);


	//CRect rc(30,40,100,120);                                         //定义一个区域对象
	//CBrush brush(RGB(128,128,128));                                   //定义一个颜色画刷
	//pDC->FillRect(rc,&brush);                                       //使用颜色填充区域
	//brush.DeleteObject();                                         //删除画刷对象

	//CBitmap bmp;                                                   //定义一个位图对象
	//bmp.LoadBitmap(IDB_BKBITMAP);                                 //加载位图
	//brush.CreatePatternBrush(&bmp);                             //创建位图画刷
	//CRect bmpRC(110,40,200,120);                         //定义一个区域对象
	//pDC->FillRect(bmpRC,&brush);                         //使用位图填充区域
	//bmp.DeleteObject();                                          //释放位图对象
	//brush.DeleteObject();                                         //释放画刷对象

	//CRect rectrc(210,40,300,120);                                  //定义一个区域对象
	//CRect hrc(280,60,350,140);                               //定义一个区域对象
	//pDC->Rectangle(rectrc);                                    //绘制矩形边框
	//pDC->Rectangle(hrc);                                       //绘制矩形边框
	//HRGN hRect = CreateRectRgn(210,40,300,120);        //创建一个矩形选区
	//HRGN hrgn = CreateRectRgn(280,60,350,140);          //创建一个矩形选区
	//HRGN hret = CreateRectRgn(0,0,0,0);                       //创建选区
	//CombineRgn(hret,hRect,hrgn,RGN_AND);                 //组合选区，获取两个选区的公共部分
	//brush.CreateSolidBrush(RGB(255,0,0));                            //创建一个颜色画刷
	//CRgn rgn;                                                        //定义一个选区对象
	//rgn.Attach(hret);                                               //将选区对象附加一个选区句柄
	//pDC->FillRgn(&rgn,&brush);                                    //填充选区
	//brush.DeleteObject();                                         //释放画刷对象
	//rgn.Detach();                                                    //分离选区句柄
	//DeleteObject(hRect);                                         //释放选区句柄
	//DeleteObject(hrc);                                             //释放选区句柄
	//DeleteObject(hret);                                            //释放选区句柄

	
	//CDC memDC;  //////////////////////////////////////////////////////////////////////////
	//memDC.CreateCompatibleDC(pDC);
	//CBitmap bmp; //////////////////////////////////////////////////////////////////////////
	//bmp.LoadBitmap(IDB_BKBITMAP);
	//memDC.SelectObject(&bmp);
	//pDC->BitBlt(30,20,180,180, &memDC, 0,0, SRCCOPY);

	//CRect rc(30, 20, 180+30, 180+20);
	//CBrush brush(RGB(0,0,0)); //////////////////////////////////////////////////////////////////////////
	//pDC->FrameRect(rc, &brush);

	//rc.OffsetRect(220, 0);
	//BITMAP BitInfo;
	//bmp.GetBitmap(&BitInfo);
	//int x = BitInfo.bmWidth;
	//int y = BitInfo.bmHeight;
	//pDC->StretchBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 
	//	0, 0, x, y, SRCCOPY);
	//pDC->FrameRect(rc, &brush);

	//brush.DeleteObject();
	//bmp.DeleteObject();
	//memDC.DeleteDC();

	
	//CBitmap bmp;
	//bmp.Attach(m_hBmp);
	//CDC memDC;
	//memDC.CreateCompatibleDC(pDC);
	//memDC.SelectObject(&bmp);
	//BITMAP BitInfo;									//定义位图结构
	//bmp.GetBitmap(&BitInfo);								//获取位图信息
	//int x = BitInfo.bmWidth;								//获取位图宽度
	//int y = BitInfo.bmHeight;								//获取位图高度
	//pDC->BitBlt(0,0,x,y,&memDC,0,0,SRCCOPY);
	//bmp.Detach(); // 这里必须要有，因为函数结束类要消失，但是图像不能
	//memDC.DeleteDC();


	OutputStream(m_pBmpData);
}


// C绘图之字体View 打印


void C绘图之字体View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C绘图之字体View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C绘图之字体View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C绘图之字体View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C绘图之字体View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C绘图之字体View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C绘图之字体View 诊断

#ifdef _DEBUG
void C绘图之字体View::AssertValid() const
{
	CView::AssertValid();
}

void C绘图之字体View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C绘图之字体Doc* C绘图之字体View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C绘图之字体Doc)));
	return (C绘图之字体Doc*)m_pDocument;
}
#endif //_DEBUG


// C绘图之字体View 消息处理程序


void C绘图之字体View::OutputStream(char *pStream)
{
	char *pHeader = pStream;
	BITMAPINFO BitInfo;
	memset(&BitInfo, 0, sizeof(BITMAPINFO));
	memcpy(&BitInfo, pHeader, sizeof(BITMAPINFO));
	int x = BitInfo.bmiHeader.biWidth;
	int y = BitInfo.bmiHeader.biHeight;
	pHeader += 40;
	StretchDIBits(GetDC()->m_hDC,0,0,x,y,0,0,x,y,pHeader,&BitInfo,DIB_RGB_COLORS,SRCCOPY);
}
