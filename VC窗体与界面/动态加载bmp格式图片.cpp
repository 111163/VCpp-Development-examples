void CSmartLoadBmpDlg::OnLoadbmp() 
{
      CFileDialog flDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
     "位图|*.bmp||");                                                                 //定义文件打开对话框
      if (flDlg.DoModal()==IDOK)
      {
            CString szBmpName;                                                       //定义字符串变量
            szBmpName = flDlg.GetPathName();                                         //获取位图文件名
            HBITMAP hOldBmp = m_Bmp.SetBitmap((HBITMAP)LoadImage(NULL,
                 szBmpName, IMAGE_BITMAP,0, 0, LR_LOADFROMFILE));     		     //加载并显示位图
            DeleteObject(hOldBmp);                                                   //释放之前的位图资源
      }
}