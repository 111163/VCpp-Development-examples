
// 表单视图中设计窗体View.cpp : C表单视图中设计窗体View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "表单视图中设计窗体.h"
#endif

#include "表单视图中设计窗体Doc.h"
#include "表单视图中设计窗体View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C表单视图中设计窗体View

IMPLEMENT_DYNCREATE(C表单视图中设计窗体View, CFormView)

BEGIN_MESSAGE_MAP(C表单视图中设计窗体View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &C表单视图中设计窗体View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &C表单视图中设计窗体View::OnBnClickedButton1)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// C表单视图中设计窗体View 构造/析构

C表单视图中设计窗体View::C表单视图中设计窗体View()
	: CFormView(C表单视图中设计窗体View::IDD)
{
	// TODO: 在此处添加构造代码

}

C表单视图中设计窗体View::~C表单视图中设计窗体View()
{
}

void C表单视图中设计窗体View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL C表单视图中设计窗体View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void C表单视图中设计窗体View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CRect rect;
	GetWindowRect(&rect);
	m_listRect.AddTail(rect);//对话框的区域   ---- 这里获取的是屏幕坐标的值

	CWnd* pWnd = GetTopWindow();//获取子窗体 GetWindow(GW_CHILD)
	while(pWnd)
	{
		pWnd->GetWindowRect(rect);//子窗体的区域
		m_listRect.AddTail(rect); //CList<CRect,CRect> m_listRect成员变量
		pWnd = pWnd->GetNextWindow();//取下一个子窗体
	}
	
}


// C表单视图中设计窗体View 诊断

#ifdef _DEBUG
void C表单视图中设计窗体View::AssertValid() const
{
	CFormView::AssertValid();
}

void C表单视图中设计窗体View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C表单视图中设计窗体Doc* C表单视图中设计窗体View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C表单视图中设计窗体Doc)));
	return (C表单视图中设计窗体Doc*)m_pDocument;
}
#endif //_DEBUG


// C表单视图中设计窗体View 消息处理程序


void C表单视图中设计窗体View::OnBnClickedButton2()
{
	MessageBox("点击了取消按钮");
}


void C表单视图中设计窗体View::OnBnClickedButton1()
{
	MessageBox("点击了登录按钮");
}


void C表单视图中设计窗体View::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	if (m_listRect.GetCount() > 0)
	{
		CRect dlgNow;
		GetWindowRect(&dlgNow);   // 一旦使用了最大最小，或其他改变尺寸的操作，dlgNow就会发生了变化
								// GetWindowRect获得的是屏幕坐标

		POSITION pos = m_listRect.GetHeadPosition();// 第一个保存的是(原来)对话框的Rect  这里获得的是头结点的位置
		CRect dlgSaved;
		dlgSaved = m_listRect.GetNext(pos); // 这里得到的就是原先的对话框的Rect		

		double x = dlgNow.Width() * 1.0 / dlgSaved.Width();//根据当前和之前保存的对话框的宽高求比例
		double y = dlgNow.Height()  * 1.0/ dlgSaved.Height();  


		CRect childSaved;  // 注意这个变量，它只是一个零时变量
						// 它的获取是来自一个m_listRect.GetNext(pos)，函数返回的是const&，但我们的childSaved,是一个常规变量，就是说childSaved获得的是一个值拷贝
						
						// 关键点有两点：首先，您要返回一个const引用，所以函数的用户不应该能够更改原始变量。这就是为什么你不能将函数调用的结果分配到常规引用的原因;常规引用不会保护返回的常量性质并允许修改变量。
						// 其次，当你将一个const ref（或任何ref）赋值给一个常规（非ref）变量时，实际上会得到一个副本。由于您在这些情况下正在制作副本，因此您不需要该对象的const副本。
						// 如果要修改对象，则只会修改副本，并保留原始对象的常量，这是要求。
		CWnd* pWnd = GetWindow(GW_CHILD);
		while(pWnd)                 // 这里我们关注的只有控件的位置
		{
			childSaved = m_listRect.GetNext(pos);//依次获取子窗体的Rect    
			childSaved.left = static_cast<int>(dlgNow.left + (childSaved.left - dlgSaved.left) * x);//根据比例调整控件上下左右距离对话框的距离  ---绝对长度的比率相同
			childSaved.right = static_cast<int>(dlgNow.right + (childSaved.right - dlgSaved.right) * x);
			childSaved.top = static_cast<int>(dlgNow.top + (childSaved.top - dlgSaved.top) * y);
			childSaved.bottom = static_cast<int>(dlgNow.bottom + (childSaved.bottom - dlgSaved.bottom) * y);
			ScreenToClient(childSaved);    // 控件移动的话，应该是基于父窗口的客户区坐标，所以这里应该先将屏幕坐标转换为客户区坐标
			pWnd->MoveWindow(childSaved);
			pWnd = pWnd->GetNextWindow();
		}
	}

}
