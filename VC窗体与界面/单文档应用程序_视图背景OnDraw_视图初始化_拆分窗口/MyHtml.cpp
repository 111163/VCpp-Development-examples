// MyHtml.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ĵ�Ӧ�ó���.h"
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


// CMyHtml ���

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


// CMyHtml ��Ϣ�������


void CMyHtml::OnInitialUpdate() // View����������ø��£���ʼ����ͼ
{
	CHtmlView::OnInitialUpdate();

	CString m_StrPath = "https://www.baidu.com";
	Navigate2(m_StrPath,NULL,NULL);
	Invalidate(FALSE);
}
