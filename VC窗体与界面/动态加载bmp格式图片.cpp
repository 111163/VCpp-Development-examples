void CSmartLoadBmpDlg::OnLoadbmp() 
{
      CFileDialog flDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
     "λͼ|*.bmp||");                                                                 //�����ļ��򿪶Ի���
      if (flDlg.DoModal()==IDOK)
      {
            CString szBmpName;                                                       //�����ַ�������
            szBmpName = flDlg.GetPathName();                                         //��ȡλͼ�ļ���
            HBITMAP hOldBmp = m_Bmp.SetBitmap((HBITMAP)LoadImage(NULL,
                 szBmpName, IMAGE_BITMAP,0, 0, LR_LOADFROMFILE));     		     //���ز���ʾλͼ
            DeleteObject(hOldBmp);                                                   //�ͷ�֮ǰ��λͼ��Դ
      }
}