
// Ŀ¼����ͼView.cpp : CĿ¼����ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ŀ¼����ͼ.h"
#endif

#include "Ŀ¼����ͼDoc.h"
#include "Ŀ¼����ͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CĿ¼����ͼView

IMPLEMENT_DYNCREATE(CĿ¼����ͼView, CTreeView)

BEGIN_MESSAGE_MAP(CĿ¼����ͼView, CTreeView)
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, &CĿ¼����ͼView::OnTvnItemexpanded)
END_MESSAGE_MAP()

// CĿ¼����ͼView ����/����

CĿ¼����ͼView::CĿ¼����ͼView()
{
	// TODO: �ڴ˴���ӹ������

}

CĿ¼����ͼView::~CĿ¼����ͼView()
{
}

BOOL CĿ¼����ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style |= TVS_HASLINES|TVS_LINESATROOT|TVS_SHOWSELALWAYS
		|TVS_SINGLEEXPAND|TVS_HASBUTTONS|TVS_NOTOOLTIPS;
	return CTreeView::PreCreateWindow(cs);
}

void CĿ¼����ͼView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	LoadDiskName();  // �����νṹװ����ͼ����������
}


// CĿ¼����ͼView ���

#ifdef _DEBUG
void CĿ¼����ͼView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CĿ¼����ͼView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CĿ¼����ͼDoc* CĿ¼����ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CĿ¼����ͼDoc)));
	return (CĿ¼����ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// CĿ¼����ͼView ��Ϣ�������


void CĿ¼����ͼView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	HTREEITEM hItemInfo = CtlTree.HitTest(point, &m_nFlags);
	nFlags = m_nFlags;
	//TVHT_ONITEMSTATEICON��ʾ�û��������ͼ���ͼ��״̬
	if (m_nFlags & TVHT_ONITEMSTATEICON)
	{
		//State: 0��״̬ 1û��ѡ�� 2����ѡ�� 3ȫ��ѡ��
		//12��15λ��ʾ��ͼ���ͼ��״̬����
		UINT nState = CtlTree.GetItemState(hItemInfo, TVIS_STATEIMAGEMASK) >> 12;
		nState = (nState == 3) ? 1 : 3;
		CtlTree.SetItemState(hItemInfo, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
	}
	else
		CTreeView::OnLButtonDown(nFlags, point);
}

void CĿ¼����ͼView::LoadDiskName()
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	if (LoadSysFileIcon()==TRUE)									//���ȼ���ϵͳ�ļ�ͼ���б�
	{
		HTREEITEM hRoot = AddItem(TVI_ROOT,  "�ҵĵ���");			//��Ӹ��ڵ�
		char  pchDrives[128] = {0};									//�����̷�����
		char* pchDrive;
		GetLogicalDriveStrings(sizeof(pchDrives), pchDrives) ;				//�о��̷�
		pchDrive = pchDrives;
		while(*pchDrive)											//��ȡÿһ���̷�
		{
			HTREEITEM hParent = AddItem(hRoot, pchDrive);			//��ӽڵ�
			if (IsSubDir(pchDrive))									//�ж��ڵ��Ƿ���һ��Ŀ¼
				CtlTree.InsertItem("", 0, 0, hParent);							//���һ���սڵ㣬Ŀ������ʾ�Ӻ�
			pchDrive += strlen(pchDrive) + 1;							//��ȡ��һ���̷�
		}
	}
}

void CĿ¼����ͼView::ShowPath(HTREEITEM hParent, LPCTSTR lpszPath)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	CFileFind flFind;								//�����ļ����Ҷ���
	CString   csPath = lpszPath;
	BOOL      bFind;
	CSortString strDirArray;
	CSortString strFileArray;
	if (csPath.Right(1) != "\\")
		csPath += "\\";
	csPath += "*.*";
	bFind = flFind.FindFile(csPath);					//��ʼ����Ŀ¼
	while (bFind)
	{
		bFind = flFind.FindNextFile();				//����Ŀ¼���ļ�
		if (flFind.IsDirectory() && !flFind.IsDots())		//�����Ŀ¼
		{
			strDirArray.Add(flFind.GetFilePath());	//��Ŀ¼��ӵ�strDirArray��
		}
		if (!flFind.IsDirectory())					//������ļ�
			strFileArray.Add(flFind.GetFilePath());	//���ļ���ӵ�strFileArray��
	}
	strDirArray.Sort();							//��Ŀ¼��������
	SetRedraw( FALSE );							//��ֹ���´���
	CWaitCursor wait;
	for (int i = 0; i < strDirArray.GetSize(); i++)			//����strDirArray
	{
		//�����ؼ������Ŀ¼�ڵ�
		HTREEITEM hItem = AddItem( hParent, strDirArray.GetAt(i) );
		//��ȡ�ڵ��ͼ��״̬
		UINT nState = CtlTree.GetItemState(hParent, TVIS_STATEIMAGEMASK) >> 12;
		//���ýڵ��ͼ��״̬
		CtlTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
		if (IsSubDir(strDirArray.GetAt(i)))				//���Ŀ¼�а������ļ�
		{
			CtlTree.InsertItem("", 0, 0, hItem);				//���һ���սڵ㣬Ŀ���������ؼ�����ʾ�Ӻű��
		}
	}
	strFileArray.Sort();							//���ļ���������
	for ( int i = 0; i < strFileArray.GetSize(); i++ )			//����strFileArray
	{
		//�����ؼ�������ļ��ڵ�
		HTREEITEM hItem = AddItem(hParent, strFileArray.GetAt(i) );	
		//��ȡ�ڵ��ͼ��״̬
		UINT nState = CtlTree.GetItemState(hParent, TVIS_STATEIMAGEMASK) >> 12;
		//���ýڵ��ͼ��״̬
		CtlTree.SetItemState(hItem, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
	}
	SetRedraw( TRUE );							//�������ؼ�

}

BOOL CĿ¼����ͼView::LoadSysFileIcon()
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	SHFILEINFO shInfo;											//�����ļ���Ϣ
	memset(&shInfo, 0, sizeof(SHFILEINFO));							//��ʼ���ļ���Ϣ
	m_hImage = (HIMAGELIST)SHGetFileInfo("c:\\", 0, &shInfo, sizeof(SHFILEINFO),
		SHGFI_SYSICONINDEX|SHGFI_SMALLICON );				//��ȡϵͳ�ļ�ͼ��
	if (m_hImage != NULL)
	{
		BOOL bRet =	m_ImageList.Attach(m_hImage);				//����ͼ���б��� 
		if (bRet)
		{
			HICON hIcon = NULL;
			hIcon = ExtractIcon(NULL, "explorer.exe", 0);				//��ȡ�ҵĵ���ͼ��
			int nIcon = m_ImageList.Add(hIcon);						//����ҵĵ���ͼ��
			//			m_ImageList.SetBkColor(m_clBk);						//����ͼ���б���ͼ��ı�����ɫ
			CtlTree.SetImageList(&m_ImageList, TVSIL_NORMAL);				//�������ؼ���ͼ���б�
			CtlTree.SetImageList(&m_StateImages, TVSIL_STATE);				//����״̬ͼ���б�
		}
		return	bRet; 
	}
	return FALSE;

}

HTREEITEM CĿ¼����ͼView::AddItem(HTREEITEM hParent, LPCTSTR lpszPath)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	SHFILEINFO shFinfo;											//�����ļ���Ϣ
	int nIcon, nIconSel;
	CString    csPath = lpszPath;
	if (csPath.Right(1) != '\\')
		csPath += "\\";
	if (hParent ==TVI_ROOT)										//�Ƿ�Ϊ���ڵ�
	{   
		nIcon = nIconSel = m_ImageList.GetImageCount() - 1;				//��ȡ�ҵĵ���ͼ������
	}
	else														//���Ϊ�ӽڵ�
	{
		//��ȡĿ¼���ļ���ϵͳͼ������
		if (!SHGetFileInfo(csPath, 0, &shFinfo, sizeof(shFinfo), SHGFI_ICON|SHGFI_SMALLICON))
		{
			return NULL;
		}
		nIcon = shFinfo.iIcon;
		//��ȡĿ¼���ļ�ѡ��ʱ��ϵͳͼ������
		if (!SHGetFileInfo(csPath, 0, &shFinfo, sizeof(shFinfo), 
			SHGFI_ICON|SHGFI_OPENICON|SHGFI_SMALLICON))
		{
			return NULL;
		}
		nIconSel = shFinfo.iIcon;									//���ýڵ�ѡ��ʱ��ͼ������
	}
	if (csPath.Right(1) == "\\" )
		csPath.SetAt(csPath.GetLength() - 1, '\0');
	return CtlTree.InsertItem(ExtractPath(csPath), nIcon, nIcon, hParent);				//�����ؼ��в���ڵ�

}

BOOL CĿ¼����ͼView::IsSubDir(LPCTSTR lpszPath)
{
	CFileFind flFind;
	CString csPath = lpszPath;
	BOOL bFind = FALSE;
	//��֤·����\*.*��β
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

CString CĿ¼����ͼView::ExtractPath(LPCTSTR lpszPath)
{
	CString csPath = "";
	int nPos;
	csPath = lpszPath;
	//��ȥ��β��"\"
	if (csPath.Right(1) == '\\')
	{
		csPath.SetAt(csPath.GetLength() - 1, '\0');	
	}
	nPos = csPath.ReverseFind('\\');
	if (nPos != -1)
		csPath = csPath.Mid(nPos + 1, csPath.GetLength());
	return (LPCTSTR)csPath;
}

void CĿ¼����ͼView::OnTvnItemexpanded(NMHDR *pNMHDR, LRESULT *pResult)
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

void CĿ¼����ͼView::ExpandItem(HTREEITEM hItem, UINT nCode)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	CString strPath;
	if ( nCode == TVE_EXPAND )
	{
		if (hItem != CtlTree.GetRootItem())
		{
			int nData = CtlTree.GetItemData(hItem);
			if (nData != LOADDIR)				//δ������Ŀ¼����ʼ������Ŀ¼
			{
				HTREEITEM hChild = CtlTree.GetChildItem(hItem);
				CtlTree.DeleteItem(hChild);	
				strPath = GetFullPath(hItem);
				ShowPath(hItem, strPath);
				CtlTree.SetItemData(hItem, LOADDIR);	//�Ѽ���Ŀ¼
			}
			else								//�Ѽ���Ŀ¼���ж��Ƿ����µ�Ŀ¼���ļ���Ҫ����
			{
				CString csPath = "";
				csPath = GetFullPath(hItem);
				char chDir[MAX_PATH] = {0};
				strcpy(chDir,csPath);
				//��ȡ�µ�Ŀ¼��Ϣ
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
				//��ȡ��ǰ�ڵ��µ���Ŀ¼
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
				//�����̵�Ŀ¼��Ϣ��ڵ���Ϣ����ƥ�䣬���Ҳ���Ŀ¼�����ڵ���û����ʾ���µĴ���Ŀ¼��ӵ��ڵ���
				//���ڵ����д���Ŀ¼�����Ľڵ�Ŀ¼ɾ��
				for(int i=0; i<strDirArray.GetSize(); i++)
				{
					BOOL bExist = FALSE;
					for(int j=0; j<nSize; j++)
					{
						CString csDisk = ExtractPath(strDirArray.GetAt(i));
						CString csNode = csNodeArray.GetAt(j);
						if(csDisk == csNode)	//�ڵ���Ŀ¼����ƥ��
						{
							bExist = TRUE;
							pArray[nCount] = j;	//��¼ƥ���Ԫ��
							nCount++;
							break;
						}
					}
					if (!bExist)				//Ŀ¼������,�ڽ�β���Ŀ¼
					{

						HTREEITEM hNode = AddItem(hItem, strDirArray.GetAt(i));
						//��ȡ���ڵ��״̬
						UINT nState = CtlTree.GetItemState(hItem, TVIS_STATEIMAGEMASK) >> 12;
						nState = (nState == 2) ? 3 : nState;
						CtlTree.SetItemState(hNode, INDEXTOSTATEIMAGEMASK(nState), TVIS_STATEIMAGEMASK);
					}
				}
				//��csNodeArray�в��Ҳ����ڵ�Ŀ¼
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
				if (nMatchCounter>0)	//ɾ���ڵ��в����ڵ�Ŀ¼��Ϣ
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

CString CĿ¼����ͼView::GetFullPath(HTREEITEM hItem)
{
	CTreeCtrl& CtlTree = (CTreeCtrl&)GetTreeCtrl();
	CString csRet;	//��¼Ŀ¼
	CString csCurDir;
	HTREEITEM hParent = hItem;
	csRet = "";
	//�������ڵ�
	HTREEITEM hRoot = CtlTree.GetRootItem();
	while (hParent != hRoot)
	{
		csCurDir  = CtlTree.GetItemText(hParent);
		csCurDir += "\\";
		csRet = csCurDir + csRet;
		hParent = CtlTree.GetParentItem( hParent );
	}
	//��ȥ��β��"\"����
	if ( csRet.Right(1) == '\\' )
		csRet.SetAt( csRet.GetLength() - 1, '\0' );
	return csRet;
}

HTREEITEM CĿ¼����ͼView::FindNode(HTREEITEM hParant, LPCTSTR lpszName)
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
