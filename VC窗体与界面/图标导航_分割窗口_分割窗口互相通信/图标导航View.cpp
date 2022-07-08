
// 图标导航View.cpp : C图标导航View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "图标导航.h"
#endif

#include "图标导航Doc.h"
#include "图标导航View.h"
#include "MainFrm.h"
#include "MyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C图标导航View

IMPLEMENT_DYNCREATE(C图标导航View, CListView)

BEGIN_MESSAGE_MAP(C图标导航View, CListView)
	ON_NOTIFY_REFLECT(NM_CLICK, &C图标导航View::OnNMClick)
END_MESSAGE_MAP()

// C图标导航View 构造/析构

C图标导航View::C图标导航View()
{
	// TODO: 在此处添加构造代码

}

C图标导航View::~C图标导航View()
{
}

BOOL C图标导航View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void C图标导航View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	CListCtrl* pListCtr = &GetListCtrl();
	pListCtr->DeleteAllItems();
	pListCtr->ModifyStyle(0L, LVS_ICON|LVS_ALIGNLEFT);
	m_ImageList.Create(32,32, ILC_COLOR24|ILC_MASK, 5, 5);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_CK));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_BASE_INFO));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_INPUT));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_STORE));
	pListCtr->SetImageList(&m_ImageList, LVSIL_NORMAL);
	pListCtr->InsertItem(0, "仓库管理", 0);
	pListCtr->InsertItem(1, "基本仓库信息", 1);
	pListCtr->InsertItem(2, "入库管理", 2);
	pListCtr->InsertItem(3, "库存管理", 3);
	// TODO: 调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
}


// C图标导航View 诊断

#ifdef _DEBUG
void C图标导航View::AssertValid() const
{
	CListView::AssertValid();
}

void C图标导航View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

C图标导航Doc* C图标导航View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C图标导航Doc)));
	return (C图标导航Doc*)m_pDocument;
}
#endif //_DEBUG


// C图标导航View 消息处理程序


void C图标导航View::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CListCtrl *pListCtl = &GetListCtrl(); // 获取到列表视图，并将其转换到列表控件
	int pos = pListCtl->GetSelectionMark(); // 获取到选择标记
	CString str = pListCtl->GetItemText(pos,0); // 得到节点的数据 GetItemText(行，列)
	//MessageBox(str);
	
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd(); // 得到主窗口的对象指针
	CMyView* FindView = (CMyView*)pMain->m_wndSplitter.GetPane(0,1);  // 返回指示窗格(行,列)的对象指针，通常用来进行多个窗格的通信
	FindView->m_Index = pos + 1;
	FindView->Invalidate(); // 立刻执行更新图案的操作就是OnDraw函数

	*pResult = 0;
}
