
// ���ε���View.cpp : C���ε���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���ε���.h"
#endif

#include "���ε���Doc.h"
#include "���ε���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���ε���View

IMPLEMENT_DYNCREATE(C���ε���View, CTreeView)

BEGIN_MESSAGE_MAP(C���ε���View, CTreeView)
	//ON_NOTIFY_REFLECT(NM_CLICK, &C���ε���View::OnNMClick)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &C���ε���View::OnNMDblclk)
END_MESSAGE_MAP()

// C���ε���View ����/����

C���ε���View::C���ε���View()
{
	// TODO: �ڴ˴���ӹ������

}

C���ε���View::~C���ε���View()
{
}

BOOL C���ε���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CTreeView::PreCreateWindow(cs);
}

void C���ε���View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();


	ImgTree.Create(16,16,ILC_COLOR24|ILC_MASK, 5, 5); // ����ͼ���б�
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_CK));              //0�ֿ����ͼ��
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_BASE_INFO));    //1:������Ϣ����ͼ��   
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_INPUT));          //2:������ͼ��
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_STORE));         //3:������ͼ��   
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_FIND_INFO));    //4:��ѯͼ��
	ImgTree.Add(AfxGetApp()->LoadIcon(IDI_ITEM));           //5:Ҷ��ͼ�� 

	CTreeCtrl&  CtlTree= (CTreeCtrl&)GetTreeCtrl();
	CtlTree.SetBkColor(RGB(155,200,255));
	CtlTree.SetImageList(&ImgTree, TVSIL_NORMAL);

	int i = 0;                                                                              //ͼ������
	TV_INSERTSTRUCT tvRoot;                                               //����
	TV_INSERTSTRUCT tvSecond;                                            //��֦
	TV_INSERTSTRUCT tvThree;                                              //��Ҷ     

	//������       -------------------------�����϶�������ƺ����ԣ���ִ�в������
	tvRoot.hParent       =  NULL; 
	tvRoot.item.pszText  =  "�ֿ����";
	tvRoot.item.mask     =  TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE ;   
	tvRoot.item.iImage   =  i;                          
	tvRoot.item.iSelectedImage = i;

	HTREEITEM  item_root =  CtlTree.InsertItem(&tvRoot);

	//����֦����Ҷ
	int ii;  //ÿ����֦��Ҷ��
	CString strSecond[4] = {"������Ϣ����", "������", "������", "��ѯ����"};
	CString strThree[4][5] = 
	{
		{"����Ա����", "��Ʒ��Ϣ����", "�����Ϣ����", "��Ӧ����Ϣ����"}, 
		{"��Ʒ���", "����˻�"}, 
		{"�����Ʒ��ӡ", "����̵�", "������", "��Ʒ����", "��������޹���"},
		{"��Ʒ����ѯ", "����˻���ѯ", "����|�����ѯ"}
	};
	//ѭ���������ڵ�
	for (i=1; i<5; i++)
	{
		tvSecond.hParent       =  item_root;                                                                              //���ø��ڵ�
		tvSecond.item.pszText  = (LPTSTR)(LPCTSTR)strSecond[i-1];            //��ʾ�ı�
		tvSecond.item.mask     =  TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE; //���ñ��
		tvSecond.item.iImage   =  i;                                                                                            //��ʾͼ��
		tvSecond.item.iSelectedImage = i;                                                                                       //�ȵ�ͼ��
		HTREEITEM  item_second =  CtlTree.InsertItem(&tvSecond);        //����ڵ�

		switch(i) // ��2���ڵ����ţ��ҵ�3���ڵ������switch������
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

		//��������ڵ�
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


// C���ε���View ���

#ifdef _DEBUG
void C���ε���View::AssertValid() const
{
	CTreeView::AssertValid();
}

void C���ε���View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

C���ε���Doc* C���ε���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���ε���Doc)));
	return (C���ε���Doc*)m_pDocument;
}
#endif //_DEBUG


// C���ε���View ��Ϣ�������


void C���ε���View::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}



void C���ε���View::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	HTREEITEM select_item = CtlTree.GetSelectedItem();
	CString str = CtlTree.GetItemText(select_item);
	//MessageBox(str);
	*pResult = 0;
}
