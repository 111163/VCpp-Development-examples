
// 目录树视图View.cpp : C目录树视图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "目录树视图.h"
#endif

#include "目录树视图Doc.h"
#include "目录树视图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C目录树视图View

IMPLEMENT_DYNCREATE(C目录树视图View, CTreeView)

BEGIN_MESSAGE_MAP(C目录树视图View, CTreeView)
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, &C目录树视图View::OnTvnItemexpanded)
END_MESSAGE_MAP()

// C目录树视图View 构造/析构

C目录树视图View::C目录树视图View()
{
	// TODO: 在此处添加构造代码

}

C目录树视图View::~C目录树视图View()
{
}

BOOL C目录树视图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.style |= TVS_HASLINES|TVS_LINESATROOT|TVS_SHOWSELALWAYS
		|TVS_SINGLEEXPAND|TVS_HASBUTTONS|TVS_NOTOOLTIPS;
	return CTreeView::PreCreateWindow(cs);
}

void C目录树视图View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	LoadDiskName();  // 将树形结构装入视图发生在这里
}


// C目录树视图View 诊断

#ifdef _DEBUG
void C目录树视图View::AssertValid() const
{
	CTreeView::AssertValid();
}

void C目录树视图View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

C目录树视图Doc* C目录树视图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C目录树视图Doc)));
	return (C目录树视图Doc*)m_pDocument;
}
#endif //_DEBUG


// C目录树视图View 消息处理程序


void C目录树视图View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	HTREEITEM hItemInfo = CtlTree.HitTest(point, &m_nFlags);
	nFlags = m_nFlags;
	//TVHT_ONITEMSTATEICON表示用户定义的视图项的图标状态
	if (m_nFlags & TVHT_ONITEMSTATEICON)
	{
		//State: 0无状态 1没有选择 2部分选择 3全部选择
		//12到15位表示视图项的图像状态索引
		UINT nState = CtlTree.GetItemState(hItemInfo, TVIS_STATEIMAGEMASK) >> 12;
		nState = (nState == 3) ? 1 : 3;
		CtlTree.SetItemState(hItemInfo, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
	}
	else
		CTreeView::OnLButtonDown(nFlags, point);
}

void C目录树视图View::LoadDiskName()
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	if (LoadSysFileIcon()==TRUE)									//首先加载系统文件图像列表
	{
		HTREEITEM hRoot = AddItem(TVI_ROOT,  "我的电脑");			//添加根节点
		char  pchDrives[128] = {0};									//定义盘符数组
		char* pchDrive;
		GetLogicalDriveStrings(sizeof(pchDrives), pchDrives) ;				//列举盘符
		pchDrive = pchDrives;
		while(*pchDrive)											//获取每一个盘符
		{
			HTREEITEM hParent = AddItem(hRoot, pchDrive);			//添加节点
			if (IsSubDir(pchDrive))									//判读节点是否是一个目录
				CtlTree.InsertItem("", 0, 0, hParent);							//添加一个空节点，目的是显示加号
			pchDrive += strlen(pchDrive) + 1;							//获取下一个盘符
		}
	}
}

void C目录树视图View::ShowPath(HTREEITEM hParent, LPCTSTR lpszPath)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	CFileFind flFind;								//定义文件查找对象
	CString   csPath = lpszPath;
	BOOL      bFind;
	CSortString strDirArray;
	CSortString strFileArray;
	if (csPath.Right(1) != "\\")
		csPath += "\\";
	csPath += "*.*";
	bFind = flFind.FindFile(csPath);					//开始搜索目录
	while (bFind)
	{
		bFind = flFind.FindNextFile();				//遍历目录和文件
		if (flFind.IsDirectory() && !flFind.IsDots())		//如果是目录
		{
			strDirArray.Add(flFind.GetFilePath());	//将目录添加到strDirArray中
		}
		if (!flFind.IsDirectory())					//如果是文件
			strFileArray.Add(flFind.GetFilePath());	//将文件添加到strFileArray中
	}
	strDirArray.Sort();							//对目录进行排序
	SetRedraw( FALSE );							//禁止更新窗口
	CWaitCursor wait;
	for (int i = 0; i < strDirArray.GetSize(); i++)			//遍历strDirArray
	{
		//向树控件中添加目录节点
		HTREEITEM hItem = AddItem( hParent, strDirArray.GetAt(i) );
		//获取节点的图像状态
		UINT nState = CtlTree.GetItemState(hParent, TVIS_STATEIMAGEMASK) >> 12;
		//设置节点的图像状态
		CtlTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
		if (IsSubDir(strDirArray.GetAt(i)))				//如果目录中包含有文件
		{
			CtlTree.InsertItem("", 0, 0, hItem);				//添加一个空节点，目的是在树控件中显示加号标记
		}
	}
	strFileArray.Sort();							//对文件进行排序
	for ( int i = 0; i < strFileArray.GetSize(); i++ )			//遍历strFileArray
	{
		//向树控件中添加文件节点
		HTREEITEM hItem = AddItem(hParent, strFileArray.GetAt(i) );	
		//获取节点的图像状态
		UINT nState = CtlTree.GetItemState(hParent, TVIS_STATEIMAGEMASK) >> 12;
		//设置节点的图像状态
		CtlTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
	}
	SetRedraw( TRUE );							//更新树控件

}

BOOL C目录树视图View::LoadSysFileIcon()
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	SHFILEINFO shInfo;											//定义文件信息
	memset(&shInfo, 0, sizeof(SHFILEINFO));							//初始化文件信息
	m_hImage = (HIMAGELIST)SHGetFileInfo("c:\\", 0, &shInfo, sizeof(SHFILEINFO),
		SHGFI_SYSICONINDEX|SHGFI_SMALLICON );				//获取系统文件图标
	if (m_hImage != NULL)
	{
		BOOL bRet =	m_ImageList.Attach(m_hImage);				//关联图像列表句柄 
		if (bRet)
		{
			HICON hIcon = NULL;
			hIcon = ExtractIcon(NULL, "explorer.exe", 0);				//提取我的电脑图标
			int nIcon = m_ImageList.Add(hIcon);						//添加我的电脑图标
			//			m_ImageList.SetBkColor(m_clBk);						//设置图像列表中图标的背景颜色
			CtlTree.SetImageList(&m_ImageList, TVSIL_NORMAL);				//设置树控件的图像列表
			CtlTree.SetImageList(&m_StateImages, TVSIL_STATE);				//设置状态图像列表
		}
		return	bRet; 
	}
	return FALSE;

}

HTREEITEM C目录树视图View::AddItem(HTREEITEM hParent, LPCTSTR lpszPath)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	SHFILEINFO shFinfo;											//定义文件信息
	int nIcon, nIconSel;
	CString    csPath = lpszPath;
	if (csPath.Right(1) != '\\')
		csPath += "\\";
	if (hParent ==TVI_ROOT)										//是否为根节点
	{   
		nIcon = nIconSel = m_ImageList.GetImageCount() - 1;				//获取我的电脑图像索引
	}
	else														//如果为子节点
	{
		//获取目录或文件的系统图标索引
		if (!SHGetFileInfo(csPath, 0, &shFinfo, sizeof(shFinfo), SHGFI_ICON|SHGFI_SMALLICON))
		{
			return NULL;
		}
		nIcon = shFinfo.iIcon;
		//获取目录或文件选中时的系统图标索引
		if (!SHGetFileInfo(csPath, 0, &shFinfo, sizeof(shFinfo), 
			SHGFI_ICON|SHGFI_OPENICON|SHGFI_SMALLICON))
		{
			return NULL;
		}
		nIconSel = shFinfo.iIcon;									//设置节点选中时的图像索引
	}
	if (csPath.Right(1) == "\\" )
		csPath.SetAt(csPath.GetLength() - 1, '\0');
	return CtlTree.InsertItem(ExtractPath(csPath), nIcon, nIcon, hParent);				//向树控件中插入节点

}

BOOL C目录树视图View::IsSubDir(LPCTSTR lpszPath)
{
	CFileFind flFind;
	CString csPath = lpszPath;
	BOOL bFind = FALSE;
	//保证路径以\*.*结尾
	if (_tcslen(lpszPath) == 3)
	{
		if (lpszPath[1] == ':' && lpszPath[2] == '\\')
			csPath += "*.*";
		else
			csPath += "\\*.*";
	}
	else 
	{
		csPath += "\\*.*";
	}
	bFind = flFind.FindFile(csPath);
	while (bFind)
	{
		bFind = flFind.FindNextFile();
		if (!flFind.IsDots())
		{
			return TRUE;
		}
	}
	return FALSE;
}

CString C目录树视图View::ExtractPath(LPCTSTR lpszPath)
{
	CString csPath = "";
	int nPos;
	csPath = lpszPath;
	//除去结尾的"\"
	if (csPath.Right(1) == '\\')
	{
		csPath.SetAt(csPath.GetLength() - 1, '\0');	
	}
	nPos = csPath.ReverseFind('\\');
	if (nPos != -1)
		csPath = csPath.Mid(nPos + 1, csPath.GetLength());
	return (LPCTSTR)csPath;
}

void C目录树视图View::OnTvnItemexpanded(NMHDR *pNMHDR, LRESULT *pResult)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	CString strPath;

	if ( pNMTreeView->itemNew.state & TVIS_EXPANDED )
	{
		ExpandItem( pNMTreeView->itemNew.hItem, TVE_EXPAND );
	}
	else
	{
		if (pNMTreeView->itemNew.hItem != CtlTree.GetRootItem())
		{
			int nData = CtlTree.GetItemData(pNMTreeView->itemNew.hItem);
			if (nData != LOADDIR)
			{
				HTREEITEM hChild = CtlTree.GetChildItem(pNMTreeView->itemNew.hItem);		
				while (hChild) 
				{
					CtlTree.DeleteItem(hChild);
					hChild = CtlTree.GetChildItem(pNMTreeView->itemNew.hItem);
				}
				CtlTree.InsertItem("", pNMTreeView->itemNew.hItem);			
				CtlTree.SetItemData(pNMTreeView->itemNew.hItem, LOADDIR);
			}
		}
	}
	*pResult = 0;
}

void C目录树视图View::ExpandItem(HTREEITEM hItem, UINT nCode)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	CString strPath;
	if ( nCode == TVE_EXPAND )
	{
		if (hItem != CtlTree.GetRootItem())
		{
			int nData = CtlTree.GetItemData(hItem);
			if (nData != LOADDIR)				//未加载子目录，开始加载子目录
			{
				HTREEITEM hChild = CtlTree.GetChildItem(hItem);
				CtlTree.DeleteItem(hChild);	
				strPath = GetFullPath(hItem);
				ShowPath(hItem, strPath);
				CtlTree.SetItemData(hItem, LOADDIR);	//已加载目录
			}
			else								//已加载目录，判断是否有新的目录或文件需要加载
			{
				CString csPath = "";
				csPath = GetFullPath(hItem);
				char chDir[MAX_PATH] = {0};
				strcpy(chDir,csPath);
				//获取新的目录信息
				CFileFind flFind;
				BOOL      bFind;
				CSortString strDirArray;
				strcat(chDir,"\\*.*");

				bFind = flFind.FindFile(chDir);
				while (bFind)
				{
					bFind = flFind.FindNextFile();
					if ( !flFind.IsDots())
					{		
						strDirArray.Add(flFind.GetFilePath());
					}
				}
				strDirArray.Sort();
				//获取当前节点下的子目录
				CSortString csNodeArray;
				HTREEITEM hChild = CtlTree.GetChildItem(hItem);
				while(hChild)
				{
					csNodeArray.Add(CtlTree.GetItemText(hChild));
					hChild = CtlTree.GetNextItem(hChild, TVGN_NEXT);
				}
				csNodeArray.Sort();
				int nSize = csNodeArray.GetSize();
				int *pArray = new int [nSize];
				memset(pArray, -1, nSize);
				int nCount = 0;
				//将磁盘的目录信息与节点信息进行匹配，查找差异目录，将节点中没有显示的新的磁盘目录添加到节点中
				//将节点中有磁盘目录不符的节点目录删除
				for(int i=0; i<strDirArray.GetSize(); i++)
				{
					BOOL bExist = FALSE;
					for(int j=0; j<nSize; j++)
					{
						CString csDisk = ExtractPath(strDirArray.GetAt(i));
						CString csNode = csNodeArray.GetAt(j);
						if(csDisk == csNode)	//节点与目录进行匹配
						{
							bExist = TRUE;
							pArray[nCount] = j;	//记录匹配的元素
							nCount++;
							break;
						}
					}
					if (!bExist)				//目录不存在,在结尾添加目录
					{

						HTREEITEM hNode = AddItem(hItem, strDirArray.GetAt(i));
						//获取父节点的状态
						UINT nState = CtlTree.GetItemState(hItem, TVIS_STATEIMAGEMASK) >> 12;
						nState = (nState == 2) ? 3 : nState;
						CtlTree.SetItemState(hNode, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
					}
				}
				//在csNodeArray中查找不存在的目录
				int *pNoMatch = new int [nSize];
				memset(pNoMatch, -1, nSize);
				int nMatchCounter = 0;
				for (int nIndex=0; nIndex<nSize; nIndex++)
				{
					BOOL bMatched = FALSE;
					for(int nID=0; nID<nCount; nID++)
					{
						if (nIndex==pArray[nID])
						{
							bMatched = TRUE;
							break;
						}
					}
					if (!bMatched)
					{
						pNoMatch[nMatchCounter] = nIndex;
						nMatchCounter++;	
					}
				}
				if (nMatchCounter>0)	//删除节点中不存在的目录信息
				{
					for(int i=0; i<nMatchCounter; i++)
					{
						HTREEITEM hChildItem = FindNode(hItem, csNodeArray.GetAt(pNoMatch[i]));
						if (hChildItem)
						{

							UINT nState = CtlTree.GetItemState(hChildItem, TVIS_STATEIMAGEMASK) >> 12;
							nState = (nState == 3) ? 1 : 3;
							CtlTree.DeleteItem(hChildItem);
							CtlTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
						}
					}
				}
				delete [] pArray;
				delete [] pNoMatch;
			}
		}
	}
}

CString C目录树视图View::GetFullPath(HTREEITEM hItem)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	CString csRet;	//记录目录
	CString csCurDir;
	HTREEITEM hParent = hItem;
	csRet = "";
	//遍历父节点
	HTREEITEM hRoot = CtlTree.GetRootItem();
	while (hParent != hRoot)
	{
		csCurDir  = CtlTree.GetItemText(hParent);
		csCurDir += "\\";
		csRet = csCurDir + csRet;
		hParent = CtlTree.GetParentItem( hParent );
	}
	//除去结尾的"\"符号
	if ( csRet.Right(1) == '\\' )
		csRet.SetAt( csRet.GetLength() - 1, '\0' );
	return csRet;
}

HTREEITEM C目录树视图View::FindNode(HTREEITEM hParant, LPCTSTR lpszName)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	HTREEITEM hChild = CtlTree.GetChildItem(hParant);
	CString csText = CtlTree.GetItemText(hChild);
	if (lpszName == csText)
	{
		return hChild;
	}
	while(hChild)
	{
		hChild = CtlTree.GetNextItem(hChild, TVGN_NEXT);
		csText = CtlTree.GetItemText(hChild);
		if (lpszName == csText)
		{
			return hChild;
		}
	}
	return NULL;
}
