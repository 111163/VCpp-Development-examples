
// ʹ��HTML��ͼ�����ҳ�����View.cpp : Cʹ��HTML��ͼ�����ҳ�����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ʹ��HTML��ͼ�����ҳ�����.h"
#endif

#include "ʹ��HTML��ͼ�����ҳ�����Doc.h"
#include "ʹ��HTML��ͼ�����ҳ�����View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cʹ��HTML��ͼ�����ҳ�����View

IMPLEMENT_DYNCREATE(Cʹ��HTML��ͼ�����ҳ�����View, CHtmlView)

BEGIN_MESSAGE_MAP(Cʹ��HTML��ͼ�����ҳ�����View, CHtmlView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_BN_CLICKED(IDC_BTBACK, &Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtback)
	ON_BN_CLICKED(IDC_BTFORWARD, &Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtforward)
	ON_BN_CLICKED(IDC_BTSTOP, &Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtstop)
	ON_BN_CLICKED(IDC_BTREFRESH, &Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtrefresh)
	ON_BN_CLICKED(IDC_BTGOTO, &Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtgoto)
	ON_EN_CHANGE(IDC_EDADDRESS, &Cʹ��HTML��ͼ�����ҳ�����View::OnEnChangeEdaddress)
END_MESSAGE_MAP()

// Cʹ��HTML��ͼ�����ҳ�����View ����/����

Cʹ��HTML��ͼ�����ҳ�����View::Cʹ��HTML��ͼ�����ҳ�����View()
{
	// TODO: �ڴ˴���ӹ������

}

Cʹ��HTML��ͼ�����ҳ�����View::~Cʹ��HTML��ͼ�����ҳ�����View()
{
}

BOOL Cʹ��HTML��ͼ�����ҳ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void Cʹ��HTML��ͼ�����ҳ�����View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("https://gitee.com/may_you_marry_in_red_admin/dashboard/projects"),NULL,NULL);
}


// Cʹ��HTML��ͼ�����ҳ�����View ��ӡ



// Cʹ��HTML��ͼ�����ҳ�����View ���

#ifdef _DEBUG
void Cʹ��HTML��ͼ�����ҳ�����View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void Cʹ��HTML��ͼ�����ҳ�����View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

Cʹ��HTML��ͼ�����ҳ�����Doc* Cʹ��HTML��ͼ�����ҳ�����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cʹ��HTML��ͼ�����ҳ�����Doc)));
	return (Cʹ��HTML��ͼ�����ҳ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// Cʹ��HTML��ͼ�����ҳ�����View ��Ϣ�������


void Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtback()
{
	GoBack();
}


void Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtforward()
{
	GoForward();
}


void Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtstop()
{
	Stop();
}


void Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtrefresh()
{
	Refresh();
}


void Cʹ��HTML��ͼ�����ҳ�����View::OnBnClickedBtgoto()
{
	Navigate2(m_StrPath, NULL, NULL);
	Invalidate(FALSE);
}


void Cʹ��HTML��ͼ�����ҳ�����View::OnEnChangeEdaddress()
{
	CMainFrame *pw = (CMainFrame*)AfxGetMainWnd();
	CDialogBar *pd = &(pw->m_wndDlgBar);
	pd->GetDlgItemText(IDC_EDADDRESS, m_StrPath);
}
