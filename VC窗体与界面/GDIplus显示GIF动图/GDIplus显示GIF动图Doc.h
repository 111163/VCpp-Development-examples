
// GDIplus��ʾGIF��ͼDoc.h : CGDIplus��ʾGIF��ͼDoc ��Ľӿ�
//


#pragma once


class CGDIplus��ʾGIF��ͼDoc : public CDocument
{
protected: // �������л�����
	CGDIplus��ʾGIF��ͼDoc();
	DECLARE_DYNCREATE(CGDIplus��ʾGIF��ͼDoc)

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
	virtual ~CGDIplus��ʾGIF��ͼDoc();
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
