
// �ĵ���ͼ�ṹʵ�ִ�ӡԤ��View.h : C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View ��Ľӿ�
//

#pragma once


class C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View : public CView
{
protected: // �������л�����
	C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View();
	DECLARE_DYNCREATE(C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View)

// ����
public:
	C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc* GetDocument() const;
	int screenx,screeny; //��ȡ����ÿӢ��������
	int printx,printy; //��ȡ��ӡ��ÿӢ��������
	double ratex,ratey; //��ӡ������Ļ�����ر���

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
	virtual ~C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View();
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

#ifndef _DEBUG  // �ĵ���ͼ�ṹʵ�ִ�ӡԤ��View.cpp �еĵ��԰汾
inline C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc* C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��View::GetDocument() const
   { return reinterpret_cast<C�ĵ���ͼ�ṹʵ�ִ�ӡԤ��Doc*>(m_pDocument); }
#endif

