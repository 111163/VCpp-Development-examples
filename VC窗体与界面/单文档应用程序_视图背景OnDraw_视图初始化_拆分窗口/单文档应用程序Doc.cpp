
// ���ĵ�Ӧ�ó���Doc.cpp : C���ĵ�Ӧ�ó���Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���ĵ�Ӧ�ó���.h"
#endif

#include "���ĵ�Ӧ�ó���Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C���ĵ�Ӧ�ó���Doc

IMPLEMENT_DYNCREATE(C���ĵ�Ӧ�ó���Doc, CDocument)

BEGIN_MESSAGE_MAP(C���ĵ�Ӧ�ó���Doc, CDocument)
END_MESSAGE_MAP()


// C���ĵ�Ӧ�ó���Doc ����/����

C���ĵ�Ӧ�ó���Doc::C���ĵ�Ӧ�ó���Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C���ĵ�Ӧ�ó���Doc::~C���ĵ�Ӧ�ó���Doc()
{
}

BOOL C���ĵ�Ӧ�ó���Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C���ĵ�Ӧ�ó���Doc ���л�

void C���ĵ�Ӧ�ó���Doc::Serialize(CArchive& ar)
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
void C���ĵ�Ӧ�ó���Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C���ĵ�Ӧ�ó���Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C���ĵ�Ӧ�ó���Doc::SetSearchContent(const CString& value)
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

// C���ĵ�Ӧ�ó���Doc ���

#ifdef _DEBUG
void C���ĵ�Ӧ�ó���Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C���ĵ�Ӧ�ó���Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C���ĵ�Ӧ�ó���Doc ����
