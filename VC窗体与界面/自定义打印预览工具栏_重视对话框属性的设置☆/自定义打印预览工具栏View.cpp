
// �Զ����ӡԤ��������View.cpp : C�Զ����ӡԤ��������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�Զ����ӡԤ��������.h"
#endif

#include "�Զ����ӡԤ��������Doc.h"
#include "�Զ����ӡԤ��������View.h"
#include "PreView.h"
//#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�Զ����ӡԤ��������View

IMPLEMENT_DYNCREATE(C�Զ����ӡԤ��������View, CView)

BEGIN_MESSAGE_MAP(C�Զ����ӡԤ��������View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
END_MESSAGE_MAP()

// C�Զ����ӡԤ��������View ����/����

C�Զ����ӡԤ��������View::C�Զ����ӡԤ��������View()
{
	// TODO: �ڴ˴���ӹ������

}

C�Զ����ӡԤ��������View::~C�Զ����ӡԤ��������View()
{
}

BOOL C�Զ����ӡԤ��������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�Զ����ӡԤ��������View ����

void C�Զ����ӡԤ��������View::OnDraw(CDC* /*pDC*/)
{
	C�Զ����ӡԤ��������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�Զ����ӡԤ��������View ��ӡ

BOOL C�Զ����ӡԤ��������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	//pInfo->SetMaxPage(3);
	return DoPreparePrinting(pInfo);
}

void C�Զ����ӡԤ��������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�Զ����ӡԤ��������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�Զ����ӡԤ��������View ���

#ifdef _DEBUG
void C�Զ����ӡԤ��������View::AssertValid() const
{
	CView::AssertValid();
}

void C�Զ����ӡԤ��������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�Զ����ӡԤ��������Doc* C�Զ����ӡԤ��������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�Զ����ӡԤ��������Doc)));
	return (C�Զ����ӡԤ��������Doc*)m_pDocument;
}
#endif //_DEBUG


// C�Զ����ӡԤ��������View ��Ϣ�������
void C�Զ����ӡԤ��������View::OnFilePrintPreview()
{
	CPrintPreviewState* pState = new CPrintPreviewState;
	if(!DoPrintPreview(IDD_TOOLBARDIALOG, this, RUNTIME_CLASS(CPreView), pState))//AFX_IDD_PREVIEW_TOOLBAR
	{
		TRACE0("Error: DoPrintPreview failed.\n");
		AfxMessageBox(AFX_IDP_COMMAND_FAILURE);
		delete pState;    
	}
}
