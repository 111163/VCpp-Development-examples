
// �Ի�������ĵ���ͼ(��ӡ)Doc.cpp : C�Ի�������ĵ���ͼ��ӡDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�Ի�������ĵ���ͼ(��ӡ).h"
#endif

#include "�Ի�������ĵ���ͼ(��ӡ)Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�Ի�������ĵ���ͼ��ӡDoc

IMPLEMENT_DYNCREATE(C�Ի�������ĵ���ͼ��ӡDoc, CDocument)

BEGIN_MESSAGE_MAP(C�Ի�������ĵ���ͼ��ӡDoc, CDocument)
END_MESSAGE_MAP()


// C�Ի�������ĵ���ͼ��ӡDoc ����/����

C�Ի�������ĵ���ͼ��ӡDoc::C�Ի�������ĵ���ͼ��ӡDoc()
{
	// TODO: �ڴ����һ���Թ������

}

C�Ի�������ĵ���ͼ��ӡDoc::~C�Ի�������ĵ���ͼ��ӡDoc()
{
}

BOOL C�Ի�������ĵ���ͼ��ӡDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�Ի�������ĵ���ͼ��ӡDoc ���л�

void C�Ի�������ĵ���ͼ��ӡDoc::Serialize(CArchive& ar)
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
void C�Ի�������ĵ���ͼ��ӡDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C�Ի�������ĵ���ͼ��ӡDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�Ի�������ĵ���ͼ��ӡDoc::SetSearchContent(const CString& value)
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

// C�Ի�������ĵ���ͼ��ӡDoc ���

#ifdef _DEBUG
void C�Ի�������ĵ���ͼ��ӡDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�Ի�������ĵ���ͼ��ӡDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�Ի�������ĵ���ͼ��ӡDoc ����
