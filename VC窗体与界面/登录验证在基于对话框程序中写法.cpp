1.д���������OnInitDialog�����У���������:
     CLogin dlg;              //�����¼���������
      if(dlg.DoModal() != IDOK)   //ģʽ��ʾ��¼����
      {
            OnOK();                  //����ֵ��ΪIDOK�ر�������
      }
      return TRUE;

2.��¼�������ʾҲ��һ��д���������OnInitDialog�����У�Ҳ����д��Ӧ�ó������InitInstance�����У�����������������ʾǰ���������£�
      CShowLoginDlg dlg;
      m_pMainWnd = &dlg;
 
      CLogin dlg;  //�����¼���������
      if(dlg.DoModal() == IDOK)  //ģʽ��ʾ��¼����
      {
            int nResponse = dlg.DoModal();      //��ʾ������
      }


// ��ȷ�Ĵ���һ��IDOK��IDCANCEL   ---��������������ť������֤�͵��ø���CDialog::�����Ӷ��˳�