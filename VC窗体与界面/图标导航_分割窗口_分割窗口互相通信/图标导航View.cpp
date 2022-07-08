
// ͼ�굼��View.cpp : Cͼ�굼��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ͼ�굼��.h"
#endif

#include "ͼ�굼��Doc.h"
#include "ͼ�굼��View.h"
#include "MainFrm.h"
#include "MyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cͼ�굼��View

IMPLEMENT_DYNCREATE(Cͼ�굼��View, CListView)

BEGIN_MESSAGE_MAP(Cͼ�굼��View, CListView)
	ON_NOTIFY_REFLECT(NM_CLICK, &Cͼ�굼��View::OnNMClick)
END_MESSAGE_MAP()

// Cͼ�굼��View ����/����

Cͼ�굼��View::Cͼ�굼��View()
{
	// TODO: �ڴ˴���ӹ������

}

Cͼ�굼��View::~Cͼ�굼��View()
{
}

BOOL Cͼ�굼��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CListView::PreCreateWindow(cs);
}

void Cͼ�굼��View::OnInitialUpdate()
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
	pListCtr->InsertItem(0, "�ֿ����", 0);
	pListCtr->InsertItem(1, "�����ֿ���Ϣ", 1);
	pListCtr->InsertItem(2, "������", 2);
	pListCtr->InsertItem(3, "������", 3);
	// TODO: ���� GetListCtrl() ֱ�ӷ��� ListView ���б�ؼ���
	//  �Ӷ������������ ListView��
}


// Cͼ�굼��View ���

#ifdef _DEBUG
void Cͼ�굼��View::AssertValid() const
{
	CListView::AssertValid();
}

void Cͼ�굼��View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

Cͼ�굼��Doc* Cͼ�굼��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cͼ�굼��Doc)));
	return (Cͼ�굼��Doc*)m_pDocument;
}
#endif //_DEBUG


// Cͼ�굼��View ��Ϣ�������


void Cͼ�굼��View::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CListCtrl *pListCtl = &GetListCtrl(); // ��ȡ���б���ͼ��������ת�����б�ؼ�
	int pos = pListCtl->GetSelectionMark(); // ��ȡ��ѡ����
	CString str = pListCtl->GetItemText(pos,0); // �õ��ڵ������ GetItemText(�У���)
	//MessageBox(str);
	
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd(); // �õ������ڵĶ���ָ��
	CMyView* FindView = (CMyView*)pMain->m_wndSplitter.GetPane(0,1);  // ����ָʾ����(��,��)�Ķ���ָ�룬ͨ���������ж�������ͨ��
	FindView->m_Index = pos + 1;
	FindView->Invalidate(); // ����ִ�и���ͼ���Ĳ�������OnDraw����

	*pResult = 0;
}
