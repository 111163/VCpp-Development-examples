#pragma once

#ifdef _WIN32_WCE
#error "Windows CE ��֧�� CHtmlView��"
#endif 

// CMyHtml Html ��ͼ

class CMyHtml : public CHtmlView
{
	DECLARE_DYNCREATE(CMyHtml)

protected:
	CMyHtml();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyHtml();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


