
// GDIplus��ʾGIF��ͼDoc.cpp : CGDIplus��ʾGIF��ͼDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "GDIplus��ʾGIF��ͼ.h"
#endif

#include "GDIplus��ʾGIF��ͼDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGDIplus��ʾGIF��ͼDoc

IMPLEMENT_DYNCREATE(CGDIplus��ʾGIF��ͼDoc, CDocument)

BEGIN_MESSAGE_MAP(CGDIplus��ʾGIF��ͼDoc, CDocument)
END_MESSAGE_MAP()


// CGDIplus��ʾGIF��ͼDoc ����/����

CGDIplus��ʾGIF��ͼDoc::CGDIplus��ʾGIF��ͼDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CGDIplus��ʾGIF��ͼDoc::~CGDIplus��ʾGIF��ͼDoc()
{
}

BOOL CGDIplus��ʾGIF��ͼDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CGDIplus��ʾGIF��ͼDoc ���л�

void CGDIplus��ʾGIF��ͼDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CGDIplus��ʾGIF��ͼDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CGDIplus��ʾGIF��ͼDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CGDIplus��ʾGIF��ͼDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CGDIplus��ʾGIF��ͼDoc ���

#ifdef _DEBUG
void CGDIplus��ʾGIF��ͼDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGDIplus��ʾGIF��ͼDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGDIplus��ʾGIF��ͼDoc ����
