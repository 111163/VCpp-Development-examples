
// �Ի�������ĵ���ͼ(��ӡ)View.h : C�Ի�������ĵ���ͼ��ӡView ��Ľӿ�
//

#pragma once


class C�Ի�������ĵ���ͼ��ӡView : public CView
{
protected: // �������л�����
	C�Ի�������ĵ���ͼ��ӡView();
	DECLARE_DYNCREATE(C�Ի�������ĵ���ͼ��ӡView)

// ����
public:
	C�Ի�������ĵ���ͼ��ӡDoc* GetDocument() const;

	CFont font; // ����
	int screenx, screeny; // ��ȡ����ÿӢ��������
	int printx, printy; // ��ȡ��ӡ��ÿӢ��������
	double ratex, ratey; // ��ӡ������Ļ�����ر���

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�Ի�������ĵ���ͼ��ӡView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
};

#ifndef _DEBUG  // �Ի�������ĵ���ͼ(��ӡ)View.cpp �еĵ��԰汾
inline C�Ի�������ĵ���ͼ��ӡDoc* C�Ի�������ĵ���ͼ��ӡView::GetDocument() const
   { return reinterpret_cast<C�Ի�������ĵ���ͼ��ӡDoc*>(m_pDocument); }
#endif

