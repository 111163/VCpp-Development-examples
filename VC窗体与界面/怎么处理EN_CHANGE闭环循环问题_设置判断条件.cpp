���������༭��ؼ���EN_CHANGE�¼����������¡�
void CChangeEditDlg::OnChangeEdit1() 
{
      CString str1,str2;
      m_Edit1.GetWindowText(str1);                                 //��ñ༭��1�е�����
      m_Edit2.GetWindowText(str2);                                 //��ñ༭��2�е�����
      if(str1 == str2)                                                         //��������ؼ���������ͬ
            return;
      else                                                                         //�������ͬ
            m_Edit2.SetWindowText(str1);                           //����õ���������Ϊ�༭��2����ʾ����
}
 
void CChangeEditDlg::OnChangeEdit2() 
{
      CString str1,str2;
      m_Edit1.GetWindowText(str1);                                 //��ñ༭��1�е�����
      m_Edit2.GetWindowText(str2);                                 //��ñ༭��2�е�����
      if(str1 == str2)                                                         //��������ؼ���������ͬ
            return;
      else                                                                         //�������ͬ
            m_Edit1.SetWindowText(str2);                           //����õ���������Ϊ�༭��1����ʾ����
}


// ����֪���������EN_CHANGE�������ж������Ļ����ͻ��γ�EN_CHANGE�ջ����������޵���
// ֻ������������������Ͽ����ܱ����������