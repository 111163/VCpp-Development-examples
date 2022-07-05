// MyHtml.cpp : 实现文件
//

#include "stdafx.h"
#include "单文档应用程序.h"
#include "MyHtml.h"


// CMyHtml

IMPLEMENT_DYNCREATE(CMyHtml, CHtmlView)

CMyHtml::CMyHtml()
{

}

CMyHtml::~CMyHtml()
{
}

void CMyHtml::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyHtml, CHtmlView)
END_MESSAGE_MAP()


// CMyHtml 诊断

#ifdef _DEBUG
void CMyHtml::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMyHtml::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// CMyHtml 消息处理程序


void CMyHtml::OnInitialUpdate() // View类在这里调用更新，初始化视图
{
	CHtmlView::OnInitialUpdate();

	CString m_StrPath = "https://www.baidu.com";
	Navigate2(m_StrPath,NULL,NULL);
	Invalidate(FALSE);
}
