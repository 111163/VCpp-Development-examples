// ���ǿ���Ҫ���˵���ʲôʱ����Find��ʲôʱ����++ֱ�ӱȽ��أ�
// ������ҵ����ַ��Ļ�������==ֱ�ӱȽ�
// �������ȷ��Ҫ���ҵĵ����Ǽ����ַ��Ļ���Find�����ȽϺ�(��ȻFind���ڲ�ʵ�ֻ���++�Ƚ�)

void CGetStringLastPosDlg::OnGet() 
{
      CString strtxt,strchar,strres;
      GetDlgItem(IDC_TEXT)->GetWindowText(strtxt);
      GetDlgItem(IDC_CHAR)->GetWindowText(strchar);
      int pos=strtxt.Find(strchar);
      int leftpos=0,tmp;
      if(pos<0)
      {
            MessageBox("û���ҵ�ָ���ַ�");
            return;
      }
      while(pos>=0)
      {
            if(IsDBCSLeadByte(strtxt.GetAt(pos)))
            {
                  strtxt=strtxt.Right(strtxt.GetLength()-pos-2);
                  leftpos+=(pos+2);
                  tmp=leftpos-2;
            }
            else
            {
                  strtxt=strtxt.Right(strtxt.GetLength()-pos-1);  // ����ȡ�ұߣ����ǲ��ҵ��Ĵ����ұ�
                  leftpos+=(pos+1);				  // �������������һ�ο�ʼ��λ��
                  tmp=leftpos-1;				  // ��������ǳ���Ҫ����Ŀ��Ŀ�ʼλ��
            }               					  // �����tmp������������ҪĿ������п�ʼλ��
            pos=strtxt.Find(strchar);
            if(pos<0)
            {
                  strres.Format("���һ�γ��ֵ�λ�ã�%d",tmp);
                  MessageBox(strres,"���",MB_OK);
            }
      }
}

