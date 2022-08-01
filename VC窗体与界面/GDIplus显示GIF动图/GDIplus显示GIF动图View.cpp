
// GDIplus��ʾGIF��ͼView.cpp : CGDIplus��ʾGIF��ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "GDIplus��ʾGIF��ͼ.h"
#endif

#include "GDIplus��ʾGIF��ͼDoc.h"
#include "GDIplus��ʾGIF��ͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


class CMemDC1 : public CDC                                          //����һ��CmemDC��
{
private:
	CBitmap*    m_bmp;                                                //����һ��λͼ����
	CBitmap*    m_oldbmp;                                     //����һ��λͼ����
	CDC*         m_pDC;                                         //����һ���豸������ָ��
	CRect         m_Rect;                                         //����һ���������
public:
	CMemDC1(CDC* pDC, const CRect& rect) : CDC()           //���幹�캯��
	{
		CreateCompatibleDC(pDC);                          //����һ�����ݵ��豸������
		m_bmp = new CBitmap;                              //Ϊλͼ�������ռ�
		//����λͼ����
		m_bmp->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
		m_oldbmp = SelectObject(m_bmp);                            //ѡ�д�����λͼ
		m_pDC = pDC;                                           //���ó�Ա����
		m_Rect = rect;                                            //�����������
		this->BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
			pDC, m_Rect.left, m_Rect.top,WHITENESS);       //���ư�ɫ����
	}
	~CMemDC1()                                                    //��������
	{
		m_pDC->BitBlt(m_Rect.left, m_Rect.top, m_Rect.Width(), m_Rect.Height(), 
			this, m_Rect.left, m_Rect.top,SRCCOPY);//����ͼ��
		SelectObject(m_oldbmp);                                    //ѡ��ԭ����λͼ����
		if (m_bmp != NULL)                                         //�ж�λͼ�����Ƿ�Ϊ��
			delete m_bmp;                                      //ɾ��λͼ����
		DeleteObject(this);                                       //�ͷ��豸������
	}
};





// CGDIplus��ʾGIF��ͼView

IMPLEMENT_DYNCREATE(CGDIplus��ʾGIF��ͼView, CView)

BEGIN_MESSAGE_MAP(CGDIplus��ʾGIF��ͼView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGDIplus��ʾGIF��ͼView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CGDIplus��ʾGIF��ͼView ����/����

CGDIplus��ʾGIF��ͼView::CGDIplus��ʾGIF��ͼView()
{
	// TODO: �ڴ˴���ӹ������
	GdiplusStartup(&m_pGdiToken,&m_Gdiplus,NULL);
	m_pBmp = Bitmap::FromFile(L"1.gif");                 //����GIFͼ��
	m_Count = m_pBmp->GetFrameDimensionsCount();   //��ȡ֡ά��
	GUID *pGuids = new GUID[m_Count];                            //����һ��GUID����
	m_pBmp->GetFrameDimensionsList(pGuids,m_Count);      //��ȡͼ��֡��GUID
	m_FrameCount = m_pBmp->GetFrameCount(pGuids);       //��ȡGIF֡��
	UINT size;                                                 //����һ�����ͱ���
	m_Count = 0;                                                   //��ʼ����Ա����
	m_pBmp->GetPropertySize(&size,&delay);                 //��ȡ���Դ�С
	PropertyItem *pItem = NULL;                                   //��������ָ��
	pItem = (PropertyItem*)malloc(size);                                //Ϊ����ָ�������ʵĿռ�
	m_pBmp->GetAllPropertyItems(size,delay,pItem);              //��ȡ������Ϣ
	delay = ((long*)pItem->value)[0];                              //��ȡ��һ֡����ʱ
	free(pItem);                                              //�ͷ����Զ���
	delete [] pGuids;                                         //�ͷ�GUID
	fcount = 0;                                                //��ʼ����Ա����
}

CGDIplus��ʾGIF��ͼView::~CGDIplus��ʾGIF��ͼView()
{
	GdiplusShutdown(m_pGdiToken);
}

BOOL CGDIplus��ʾGIF��ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGDIplus��ʾGIF��ͼView ����

void CGDIplus��ʾGIF��ͼView::OnDraw(CDC* /*pDC*/)
{
	CGDIplus��ʾGIF��ͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CGDIplus��ʾGIF��ͼView ��ӡ


void CGDIplus��ʾGIF��ͼView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGDIplus��ʾGIF��ͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGDIplus��ʾGIF��ͼView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGDIplus��ʾGIF��ͼView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CGDIplus��ʾGIF��ͼView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGDIplus��ʾGIF��ͼView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGDIplus��ʾGIF��ͼView ���

#ifdef _DEBUG
void CGDIplus��ʾGIF��ͼView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIplus��ʾGIF��ͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIplus��ʾGIF��ͼDoc* CGDIplus��ʾGIF��ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIplus��ʾGIF��ͼDoc)));
	return (CGDIplus��ʾGIF��ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIplus��ʾGIF��ͼView ��Ϣ�������


int CGDIplus��ʾGIF��ͼView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetTimer(0, delay*10, NULL);

	return 0;
}


void CGDIplus��ʾGIF��ͼView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GUID Guid = FrameDimensionTime;                                 //����һ��GUID
	CDC* pDC = GetDC();                                      //��ȡ��ͼ���ڵ��豸������
	//����һ���ڴ滭��

	CMemDC1 dc(pDC,CRect(0,0,m_pBmp->GetWidth(),m_pBmp->GetHeight()));
	Graphics gh(dc.m_hDC);                                         //����һ��ͼ�����
	//���豸�������л���ͼ��
	gh.DrawImage(m_pBmp,0,0,m_pBmp->GetWidth(),m_pBmp->GetHeight());
	m_pBmp->SelectActiveFrame(&Guid,fcount++);        //������һ֡
	if(fcount == m_FrameCount)                                    //�жϵ�ǰ֡�Ƿ�Ϊβ֡
		fcount = 0;                                                 //����ǰ֡����Ϊ��һ֡

	CView::OnTimer(nIDEvent);
}
