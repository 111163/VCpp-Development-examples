
// 目录树视图View.h : C目录树视图View 类的接口
//

#pragma once
#include "目录树视图Doc.h"
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

class C目录树视图View : public CTreeView
{
protected: // 仅从序列化创建
	C目录树视图View();
	DECLARE_DYNCREATE(C目录树视图View)

// 特性
public:
	C目录树视图Doc* GetDocument() const;
	CImageList m_ImageList;		//定义节点图像
	CImageList m_StateImages;	//定义状态图像列表	
	HIMAGELIST m_hImage;

// 操作
public:


// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
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
	virtual ~C目录树视图View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTvnItemexpanded(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // 目录树视图View.cpp 中的调试版本
inline C目录树视图Doc* C目录树视图View::GetDocument() const
   { return reinterpret_cast<C目录树视图Doc*>(m_pDocument); }
#endif

