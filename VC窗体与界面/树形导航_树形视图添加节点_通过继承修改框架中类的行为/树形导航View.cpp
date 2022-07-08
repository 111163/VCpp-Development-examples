
// 树形导航View.cpp : C树形导航View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "树形导航.h"
#endif

#include "树形导航Doc.h"
#include "树形导航View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C树形导航View

IMPLEMENT_DYNCREATE(C树形导航View, CTreeView)

BEGIN_MESSAGE_MAP(C树形导航View, CTreeView)
	//ON_NOTIFY_REFLECT(NM_CLICK, &C树形导航View::OnNMClick)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &C树形导航View::OnNMDblclk)
END_MESSAGE_MAP()

// C树形导航View 构造/析构

C树形导航View::C树形导航View()
{
	// TODO: 在此处添加构造代码

}

C树形导航View::~C树形导航View()
{
}

BOOL C树形导航View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CTreeView::PreCreateWindow(cs);
}

void C树形导航View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();


	ImgTree.Create(16,16,ILC_COLOR24|ILC_MASK, 5, 5); // 创建图标列表
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_CK));              //0仓库管理图标
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_BASE_INFO));    //1:基本信息管理图标   
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_INPUT));          //2:入库管理图标
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_STORE));         //3:库存管理图标   
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_FIND_INFO));    //4:查询图标
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_ITEM));           //5:叶子图标 

	CTreeCtrl&  CtlTree= (CTreeCtrl&)GetTreeCtrl();
	CtlTree.SetBkColor(RGB(155,200,255));
	CtlTree.SetImageList(&ImgTree, TVSIL_NORMAL);

	int i = 0;                                                                              //图标索引
	TV_INSERTSTRUCT tvRoot;                                               //树根
	TV_INSERTSTRUCT tvSecond;                                            //树枝
	TV_INSERTSTRUCT tvThree;                                              //树叶     

	//添树根       -------------------------整体上都是先设计好属性，在执行插入操作
	tvRoot.hParent       =  NULL; 
	tvRoot.item.pszText  =  "仓库管理";
	tvRoot.item.mask     =  TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE ;   
	tvRoot.item.iImage   =  i;                          
	tvRoot.item.iSelectedImage = i;

	HTREEITEM  item_root =  CtlTree.InsertItem(&tvRoot);

	//添树枝和树叶
	int ii;  //每个树枝的叶子
	CString strSecond[4] = {"基本信息管理", "入库管理", "库存管理", "查询管理"};
	CString strThree[4][5] = 
	{
		{"操作员管理", "商品信息管理", "库存信息管理", "供应商信息管理"}, 
		{"商品入库", "入库退货"}, 
		{"库存商品打印", "库存盘点", "库存调拨", "商品出库", "库存上下限管理"},
		{"商品入库查询", "入库退货查询", "报损|报益查询"}
	};
	//循环设置树节点
	for (i=1; i<5; i++)
	{
		tvSecond.hParent       =  item_root;                                                                              //设置父节点
		tvSecond.item.pszText  = (LPTSTR)(LPCTSTR)strSecond[i-1];            //显示文本
		tvSecond.item.mask     =  TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE; //设置标记
		tvSecond.item.iImage   =  i;                                                                                            //显示图像
		tvSecond.item.iSelectedImage = i;                                                                                       //热点图像
		HTREEITEM  item_second =  CtlTree.InsertItem(&tvSecond);        //插入节点

		switch(i) // 由2级节点的序号，找到3级节点的数量switch的妙用
		{
		case 1:
			ii = 4;
			break;
		case 2:
			ii = 2;
			break;
		case 3:
			ii = 5;
			break;
		case 4:
			ii = 3;
			break;
		default:
			break;
		}

		//设计三级节点
		for (int j=0; j<ii; j++)
		{
			tvThree.hParent       =  item_second;                     
			tvThree.item.pszText  =  (LPTSTR)(LPCTSTR)strThree[i-1][j];
			tvThree.item.mask     =  TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
			tvThree.item.iImage   =  5;
			tvThree.item.iSelectedImage = 5;
			CtlTree.InsertItem(&tvThree);
		}
	}
}


// C树形导航View 诊断

#ifdef _DEBUG
void C树形导航View::AssertValid() const
{
	CTreeView::AssertValid();
}

void C树形导航View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

C树形导航Doc* C树形导航View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C树形导航Doc)));
	return (C树形导航Doc*)m_pDocument;
}
#endif //_DEBUG


// C树形导航View 消息处理程序


void C树形导航View::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}



void C树形导航View::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	HTREEITEM select_item = CtlTree.GetSelectedItem();
	CString str = CtlTree.GetItemText(select_item);
	//MessageBox(str);
	*pResult = 0;
}
