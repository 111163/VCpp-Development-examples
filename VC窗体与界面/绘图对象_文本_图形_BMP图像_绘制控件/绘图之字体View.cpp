
// ��ͼ֮����View.cpp : C��ͼ֮����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ͼ֮����.h"
#endif

#include "��ͼ֮����Doc.h"
#include "��ͼ֮����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ͼ֮����View

IMPLEMENT_DYNCREATE(C��ͼ֮����View, CView)

BEGIN_MESSAGE_MAP(C��ͼ֮����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C��ͼ֮����View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C��ͼ֮����View ����/����

C��ͼ֮����View::C��ͼ֮����View()
{
	// TODO: �ڴ˴���ӹ������
// 	m_hBmp = LoadImage(NULL, "Demo.bmp", IMAGE_BITMAP
// 		, 0, 0, LR_LOADFROMFILE);

	CFile file;
	file.Open("bk.bmp", CFile::modeRead);
	int len = file.GetLength();
	file.Seek(14, CFile::begin);
	m_pBmpData = new char[len - 14];
	file.Read(m_pBmpData, len - 14);
	file.Close();
}

C��ͼ֮����View::~C��ͼ֮����View()
{
	delete[] m_pBmpData;
}

BOOL C��ͼ֮����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ͼ֮����View ����

void C��ͼ֮����View::OnDraw(CDC* pDC)
{
	C��ͼ֮����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

// 	CFont Font;
// 	Font.CreateFont(24,24,0,0,FW_NORMAL,0,TRUE,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
// 		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_ROMAN,"����");
// 	CFont *pOldFont = NULL;
// 	pOldFont = pDC->SelectObject(&Font);
// 	pDC->TextOut(10, 10, "ͬһ������,ͬһ������");
// 	pDC->SelectObject(pOldFont);
// 	Font.DeleteObject();

/*	pDC->TextOut(0,0,"���");*/

// 	CRect rc(100, 20, 300, 200);
// 	CString str = "��ã��Һã�����ã�";
// 	CBrush brush(RGB(0,0,0));
// 	pDC->FrameRect(rc, &brush);
// 	pDC->DrawText(str, rc, DT_CENTER|DT_SINGLELINE|DT_VCENTER);
// 	brush.DeleteObject();

// 	int pts[4] = {100, 200, 300, 400};
// 	pDC->SetTextColor(RGB(255, 0, 0));
// 	pDC->TabbedTextOut(0, 20, "\t��\t��\t��\t��", 4, pts, 0);

// 	CFont Font;
// 	Font.CreateFont(12,12,2700,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
// 		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_ROMAN,"����");
// 	CFont *oldFont = pDC->SelectObject(&Font);
// 	pDC->SetTextColor(RGB(255, 0, 0));
// 	pDC->TextOut(100, 50, "�����ͬ");
// 	pDC->SelectObject(oldFont);
// 	Font.DeleteObject();
// 
// 	Font.CreatePointFont(120, "����", pDC);
// 	pDC->SetTextColor(COLOR_BTNTEXT);
// 	oldFont = pDC->SelectObject(&Font);
// 	pDC->TextOut(120, 70, "�����ͬ");
// 	pDC->TextOut(120, 90, "�����ͬ");
// 	pDC->SelectObject(oldFont);
// 	Font.DeleteObject();

	//CFont mFont;                                                   //����һ���������
	////��������
	//VERIFY(mFont.CreateFont(                        
	//	150, 50, 0, 0, FW_HEAVY, TRUE, FALSE, 
	//	0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, 
	//	CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
	//	DEFAULT_PITCH | FF_SWISS, "����"));
	//CPen pen(PS_SOLID,2,RGB(255,0,0));                            //����һ������
	//pDC->SelectObject(&pen);                                //ѡ�л���
	//pDC->BeginPath();                                     //��ʼһ��·��
	//CFont *pOldFont = pDC->SelectObject(&mFont);      //ѡ�д���������
	//pDC->SetBkMode(TRANSPARENT);                 //���û����ı���ģʽΪ͸��
	//pDC->TextOut(30,30,"�϶�һ��̽������");              //����ı�
	//pDC->EndPath();                                       //�ر�·��
	//pDC->StrokePath();                                   //�õ�ǰ�Ļ��ʻ���·��
	//mFont.DeleteObject();                                //�����������
	//pDC->SelectObject(pOldFont);                           //ѡ��֮ǰ���������

// 	CBitmap bmp;
// 	bmp.LoadBitmap(IDB_BKBITMAP);
// 
// 	BITMAP bInfo;
// 	bmp.GetBitmap(&bInfo);
// 	int width = bInfo.bmWidth;
// 	int height = bInfo.bmHeight;
// 	CDC memDC;
// 	memDC.CreateCompatibleDC(pDC);
// 	memDC.SelectObject(&bmp);
// 
// 	pDC->BitBlt(0,0,width,height,&memDC,0,0,SRCCOPY);
// 	memDC.DeleteDC();
// 	bmp.DeleteObject();
// 
// 	CFont mFont;
// 	VERIFY(mFont.CreateFont(					
// 		24, 20, 0, 0, FW_HEAVY, FALSE, FALSE, 
// 		0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, 
// 		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
// 		DEFAULT_PITCH | FF_SWISS, "����"));
// 	CFont *odlFont = pDC->SelectObject(&mFont);
// 	pDC->SetBkMode(TRANSPARENT);
// 	pDC->SetTextColor(RGB(0, 255, 0));
// 	pDC->TextOut(60, 60, "��԰����");
// 	pDC->SelectObject(odlFont);
// 	mFont.DeleteObject();

	//CPen pen(PS_SOLID, 2, RGB(255,0,0));
	//CPen *oldPne = pDC->SelectObject(&pen);

	//pDC->MoveTo(50,30);                               //�����������
	//pDC->LineTo(240,30);                               //�����ϱ߿�
	//pDC->LineTo(240,120);                             //�����ұ߿�
	//pDC->LineTo(50,120);                                     //�����±߿�
	//pDC->LineTo(50,30);                                 //������߿�
	////���ƶ����
	//pDC->MoveTo(300,50);                             //���õ�ǰ����
	//pDC->LineTo(400,50);                               //�����ϱ߿�
	//pDC->LineTo(450,100);                             //������б�߿�
	//pDC->LineTo(400,150);                             //������б�߿�
	//pDC->LineTo(300,150);                                    //���Ƶױ߿�
	//pDC->LineTo(250,100);                             //�������ϱ߿�
	//pDC->LineTo(300,50);                               //�������ϱ߿�
	////���ƻ���
	//CRect rc(500,50,600,100);                          //����һ���������
	//pDC->Arc(500,50,600,100,520,70,560,30);         //��������
	//CBrush brush(RGB(255, 0, 0));
	//pDC->FrameRect(rc, &brush);

	//CRect rc1(100, 100, 180, 180);
	//pDC->Rectangle(20,20,80,80);
	//pDC->RoundRect(&rc1, CPoint(20,20));

	//CPoint pot[6] =  {CPoint(300,50),CPoint(400,50),CPoint(450,100),    //�������ζ˵�
	//	CPoint(400,150),CPoint(300,150), CPoint(250,100)};
	////pDC->Polygon(pot, 6);

	//pDC->Polyline(pot, 6);

	//brush.DeleteObject();
	//pDC->SelectObject(oldPne);
	//pen.DeleteObject();


	//CRect rc(50,50,120,80);                                                         //����һ���������
	//pDC->DrawFrameControl(rc,DFC_BUTTON,DFCS_BUTTONPUSH);     //���ư�ť
	//CRect CapRC(130,50,160,80);                                                       //����һ���������
	////���Ʊ������رհ�ť
	//pDC->DrawFrameControl(CapRC,DFC_CAPTION,DFCS_CAPTIONHELP);
	//CRect ScrollRC(170,50,200,80);                                              //����һ���������
	////���ƹ�������ť
	//pDC->DrawFrameControl(ScrollRC,DFC_SCROLL,DFCS_SCROLLCOMBOBOX);


	//CRect rc(30,40,100,120);                                         //����һ���������
	//CBrush brush(RGB(128,128,128));                                   //����һ����ɫ��ˢ
	//pDC->FillRect(rc,&brush);                                       //ʹ����ɫ�������
	//brush.DeleteObject();                                         //ɾ����ˢ����

	//CBitmap bmp;                                                   //����һ��λͼ����
	//bmp.LoadBitmap(IDB_BKBITMAP);                                 //����λͼ
	//brush.CreatePatternBrush(&bmp);                             //����λͼ��ˢ
	//CRect bmpRC(110,40,200,120);                         //����һ���������
	//pDC->FillRect(bmpRC,&brush);                         //ʹ��λͼ�������
	//bmp.DeleteObject();                                          //�ͷ�λͼ����
	//brush.DeleteObject();                                         //�ͷŻ�ˢ����

	//CRect rectrc(210,40,300,120);                                  //����һ���������
	//CRect hrc(280,60,350,140);                               //����һ���������
	//pDC->Rectangle(rectrc);                                    //���ƾ��α߿�
	//pDC->Rectangle(hrc);                                       //���ƾ��α߿�
	//HRGN hRect = CreateRectRgn(210,40,300,120);        //����һ������ѡ��
	//HRGN hrgn = CreateRectRgn(280,60,350,140);          //����һ������ѡ��
	//HRGN hret = CreateRectRgn(0,0,0,0);                       //����ѡ��
	//CombineRgn(hret,hRect,hrgn,RGN_AND);                 //���ѡ������ȡ����ѡ���Ĺ�������
	//brush.CreateSolidBrush(RGB(255,0,0));                            //����һ����ɫ��ˢ
	//CRgn rgn;                                                        //����һ��ѡ������
	//rgn.Attach(hret);                                               //��ѡ�����󸽼�һ��ѡ�����
	//pDC->FillRgn(&rgn,&brush);                                    //���ѡ��
	//brush.DeleteObject();                                         //�ͷŻ�ˢ����
	//rgn.Detach();                                                    //����ѡ�����
	//DeleteObject(hRect);                                         //�ͷ�ѡ�����
	//DeleteObject(hrc);                                             //�ͷ�ѡ�����
	//DeleteObject(hret);                                            //�ͷ�ѡ�����

	
	//CDC memDC;  //////////////////////////////////////////////////////////////////////////
	//memDC.CreateCompatibleDC(pDC);
	//CBitmap bmp; //////////////////////////////////////////////////////////////////////////
	//bmp.LoadBitmap(IDB_BKBITMAP);
	//memDC.SelectObject(&bmp);
	//pDC->BitBlt(30,20,180,180, &memDC, 0,0, SRCCOPY);

	//CRect rc(30, 20, 180+30, 180+20);
	//CBrush brush(RGB(0,0,0)); //////////////////////////////////////////////////////////////////////////
	//pDC->FrameRect(rc, &brush);

	//rc.OffsetRect(220, 0);
	//BITMAP BitInfo;
	//bmp.GetBitmap(&BitInfo);
	//int x = BitInfo.bmWidth;
	//int y = BitInfo.bmHeight;
	//pDC->StretchBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 
	//	0, 0, x, y, SRCCOPY);
	//pDC->FrameRect(rc, &brush);

	//brush.DeleteObject();
	//bmp.DeleteObject();
	//memDC.DeleteDC();

	
	//CBitmap bmp;
	//bmp.Attach(m_hBmp);
	//CDC memDC;
	//memDC.CreateCompatibleDC(pDC);
	//memDC.SelectObject(&bmp);
	//BITMAP BitInfo;									//����λͼ�ṹ
	//bmp.GetBitmap(&BitInfo);								//��ȡλͼ��Ϣ
	//int x = BitInfo.bmWidth;								//��ȡλͼ���
	//int y = BitInfo.bmHeight;								//��ȡλͼ�߶�
	//pDC->BitBlt(0,0,x,y,&memDC,0,0,SRCCOPY);
	//bmp.Detach(); // �������Ҫ�У���Ϊ����������Ҫ��ʧ������ͼ����
	//memDC.DeleteDC();


	OutputStream(m_pBmpData);
}


// C��ͼ֮����View ��ӡ


void C��ͼ֮����View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C��ͼ֮����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ͼ֮����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ͼ֮����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C��ͼ֮����View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C��ͼ֮����View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C��ͼ֮����View ���

#ifdef _DEBUG
void C��ͼ֮����View::AssertValid() const
{
	CView::AssertValid();
}

void C��ͼ֮����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ͼ֮����Doc* C��ͼ֮����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ͼ֮����Doc)));
	return (C��ͼ֮����Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ͼ֮����View ��Ϣ�������


void C��ͼ֮����View::OutputStream(char *pStream)
{
	char *pHeader = pStream;
	BITMAPINFO BitInfo;
	memset(&BitInfo, 0, sizeof(BITMAPINFO));
	memcpy(&BitInfo, pHeader, sizeof(BITMAPINFO));
	int x = BitInfo.bmiHeader.biWidth;
	int y = BitInfo.bmiHeader.biHeight;
	pHeader += 40;
	StretchDIBits(GetDC()->m_hDC,0,0,x,y,0,0,x,y,pHeader,&BitInfo,DIB_RGB_COLORS,SRCCOPY);
}
