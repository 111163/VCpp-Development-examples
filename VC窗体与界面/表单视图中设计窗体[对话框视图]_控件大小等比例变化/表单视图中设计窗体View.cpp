
// ����ͼ����ƴ���View.cpp : C����ͼ����ƴ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ͼ����ƴ���.h"
#endif

#include "����ͼ����ƴ���Doc.h"
#include "����ͼ����ƴ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ͼ����ƴ���View

IMPLEMENT_DYNCREATE(C����ͼ����ƴ���View, CFormView)

BEGIN_MESSAGE_MAP(C����ͼ����ƴ���View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &C����ͼ����ƴ���View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &C����ͼ����ƴ���View::OnBnClickedButton1)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// C����ͼ����ƴ���View ����/����

C����ͼ����ƴ���View::C����ͼ����ƴ���View()
	: CFormView(C����ͼ����ƴ���View::IDD)
{
	// TODO: �ڴ˴���ӹ������

}

C����ͼ����ƴ���View::~C����ͼ����ƴ���View()
{
}

void C����ͼ����ƴ���View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL C����ͼ����ƴ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void C����ͼ����ƴ���View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CRect rect;
	GetWindowRect(&rect);
	m_listRect.AddTail(rect);//�Ի��������   ---- �����ȡ������Ļ�����ֵ

	CWnd* pWnd = GetTopWindow();//��ȡ�Ӵ��� GetWindow(GW_CHILD)
	while(pWnd)
	{
		pWnd->GetWindowRect(rect);//�Ӵ��������
		m_listRect.AddTail(rect); //CList<CRect,CRect> m_listRect��Ա����
		pWnd = pWnd->GetNextWindow();//ȡ��һ���Ӵ���
	}
	
}


// C����ͼ����ƴ���View ���

#ifdef _DEBUG
void C����ͼ����ƴ���View::AssertValid() const
{
	CFormView::AssertValid();
}

void C����ͼ����ƴ���View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C����ͼ����ƴ���Doc* C����ͼ����ƴ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ͼ����ƴ���Doc)));
	return (C����ͼ����ƴ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ͼ����ƴ���View ��Ϣ�������


void C����ͼ����ƴ���View::OnBnClickedButton2()
{
	MessageBox("�����ȡ����ť");
}


void C����ͼ����ƴ���View::OnBnClickedButton1()
{
	MessageBox("����˵�¼��ť");
}


void C����ͼ����ƴ���View::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	if (m_listRect.GetCount() > 0)
	{
		CRect dlgNow;
		GetWindowRect(&dlgNow);   // һ��ʹ���������С���������ı�ߴ�Ĳ�����dlgNow�ͻᷢ���˱仯
								// GetWindowRect��õ�����Ļ����

		POSITION pos = m_listRect.GetHeadPosition();// ��һ���������(ԭ��)�Ի����Rect  �����õ���ͷ����λ��
		CRect dlgSaved;
		dlgSaved = m_listRect.GetNext(pos); // ����õ��ľ���ԭ�ȵĶԻ����Rect		

		double x = dlgNow.Width() * 1.0 / dlgSaved.Width();//���ݵ�ǰ��֮ǰ����ĶԻ���Ŀ�������
		double y = dlgNow.Height()  * 1.0/ dlgSaved.Height();  


		CRect childSaved;  // ע�������������ֻ��һ����ʱ����
						// ���Ļ�ȡ������һ��m_listRect.GetNext(pos)���������ص���const&�������ǵ�childSaved,��һ���������������˵childSaved��õ���һ��ֵ����
						
						// �ؼ��������㣺���ȣ���Ҫ����һ��const���ã����Ժ������û���Ӧ���ܹ�����ԭʼ�����������Ϊʲô�㲻�ܽ��������õĽ�����䵽�������õ�ԭ��;�������ò��ᱣ�����صĳ������ʲ������޸ı�����
						// ��Σ����㽫һ��const ref�����κ�ref����ֵ��һ�����棨��ref������ʱ��ʵ���ϻ�õ�һ������������������Щ����������������������������Ҫ�ö����const������
						// ���Ҫ�޸Ķ�����ֻ���޸ĸ�����������ԭʼ����ĳ���������Ҫ��
		CWnd* pWnd = GetWindow(GW_CHILD);
		while(pWnd)                 // �������ǹ�ע��ֻ�пؼ���λ��
		{
			childSaved = m_listRect.GetNext(pos);//���λ�ȡ�Ӵ����Rect    
			childSaved.left = static_cast<int>(dlgNow.left + (childSaved.left - dlgSaved.left) * x);//���ݱ��������ؼ��������Ҿ���Ի���ľ���  ---���Գ��ȵı�����ͬ
			childSaved.right = static_cast<int>(dlgNow.right + (childSaved.right - dlgSaved.right) * x);
			childSaved.top = static_cast<int>(dlgNow.top + (childSaved.top - dlgSaved.top) * y);
			childSaved.bottom = static_cast<int>(dlgNow.bottom + (childSaved.bottom - dlgSaved.bottom) * y);
			ScreenToClient(childSaved);    // �ؼ��ƶ��Ļ���Ӧ���ǻ��ڸ����ڵĿͻ������꣬��������Ӧ���Ƚ���Ļ����ת��Ϊ�ͻ�������
			pWnd->MoveWindow(childSaved);
			pWnd = pWnd->GetNextWindow();
		}
	}

}
