
// �Զ����ӡԤ��������Doc.h : C�Զ����ӡԤ��������Doc ��Ľӿ�
//


#pragma once


class C�Զ����ӡԤ��������Doc : public CDocument
{
protected: // �������л�����
	C�Զ����ӡԤ��������Doc();
	DECLARE_DYNCREATE(C�Զ����ӡԤ��������Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C�Զ����ӡԤ��������Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
