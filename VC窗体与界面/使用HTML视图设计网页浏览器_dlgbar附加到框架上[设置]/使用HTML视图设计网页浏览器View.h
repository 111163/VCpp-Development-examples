
// ʹ��HTML��ͼ�����ҳ�����View.h : Cʹ��HTML��ͼ�����ҳ�����View ��Ľӿ�
//

#pragma once


class Cʹ��HTML��ͼ�����ҳ�����View : public CHtmlView
{
protected: // �������л�����
	Cʹ��HTML��ͼ�����ҳ�����View();
	DECLARE_DYNCREATE(Cʹ��HTML��ͼ�����ҳ�����View)

// ����
public:
	Cʹ��HTML��ͼ�����ҳ�����Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	CString m_StrPath;
	virtual ~Cʹ��HTML��ͼ�����ҳ�����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtback();
	afx_msg void OnBnClickedBtforward();
	afx_msg void OnBnClickedBtstop();
	afx_msg void OnBnClickedBtrefresh();
	afx_msg void OnBnClickedBtgoto();
	afx_msg void OnEnChangeEdaddress();
};

#ifndef _DEBUG  // ʹ��HTML��ͼ�����ҳ�����View.cpp �еĵ��԰汾
inline Cʹ��HTML��ͼ�����ҳ�����Doc* Cʹ��HTML��ͼ�����ҳ�����View::GetDocument() const
   { return reinterpret_cast<Cʹ��HTML��ͼ�����ҳ�����Doc*>(m_pDocument); }
#endif

