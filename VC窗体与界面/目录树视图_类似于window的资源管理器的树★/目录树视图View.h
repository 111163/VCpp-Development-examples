
// Ŀ¼����ͼView.h : CĿ¼����ͼView ��Ľӿ�
//

#pragma once
#include "Ŀ¼����ͼDoc.h"
#define LOADDIR 2

class CSortString : public CStringArray  
{
public:
	void Sort()
	{
		BOOL bRet = TRUE;   
		while (bRet)   
		{  
			bRet = FALSE;
			for( int nPos=0; nPos<GetUpperBound(); nPos++ )
				bRet |= CompareString( nPos );   
		}		
	}
private: 
	BOOL CompareString( int nPos )
	{
		CString csSwap;   
		int nFirst = nPos;   
		int nNext = nPos + 1;
		if ( GetAt( nFirst ).CompareNoCase( GetAt( nNext ) ) > 0)   
		{
			csSwap = GetAt( nFirst );      
			SetAt( nFirst, GetAt( nNext ) );
			SetAt( nNext, csSwap );      
			return TRUE;   
		}   
		return FALSE;		
	}
};

class CĿ¼����ͼView : public CTreeView
{
protected: // �������л�����
	CĿ¼����ͼView();
	DECLARE_DYNCREATE(CĿ¼����ͼView)

// ����
public:
	CĿ¼����ͼDoc* GetDocument() const;
	CImageList m_ImageList;		//����ڵ�ͼ��
	CImageList m_StateImages;	//����״̬ͼ���б�	
	HIMAGELIST m_hImage;

// ����
public:


// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	HTREEITEM FindNode(HTREEITEM hParant, LPCTSTR lpszName);
	CString GetFullPath(HTREEITEM hItem);
	void ExpandItem(HTREEITEM hItem, UINT nCode);
	CString ExtractPath(LPCTSTR lpszPath);
	BOOL IsSubDir(LPCTSTR lpszPath);
	HTREEITEM AddItem(HTREEITEM hParent, LPCTSTR lpszPath);
	BOOL LoadSysFileIcon();
	void ShowPath(HTREEITEM hParent, LPCTSTR lpszPath);
	void LoadDiskName();
	virtual ~CĿ¼����ͼView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTvnItemexpanded(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // Ŀ¼����ͼView.cpp �еĵ��԰汾
inline CĿ¼����ͼDoc* CĿ¼����ͼView::GetDocument() const
   { return reinterpret_cast<CĿ¼����ͼDoc*>(m_pDocument); }
#endif

