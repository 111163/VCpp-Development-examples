
// �ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc.cpp : C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ĵ���ͼ�ṹʵ�ִ�ӡԤ��.h"
#endif

#include "�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc

IMPLEMENT_DYNCREATE(C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc, CDocument)

BEGIN_MESSAGE_MAP(C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc, CDocument)
END_MESSAGE_MAP()


// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc ����/����

C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::~C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc()
{
}

BOOL C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc ���л�

void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::Serialize(CArchive& ar)
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
void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::SetSearchContent(const CString& value)
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

// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc ���

#ifdef _DEBUG
void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc ����
