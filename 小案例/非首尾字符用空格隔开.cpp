// ���γ����������ҳ����ֽ��д�д��ĸ���ֵ�λ��
// ���нϴ������������ñ�־�ӿո��������
// �ײ���ӿո��ԭ����pos == 0����жϣ�β����ӿո��ԭ������Ҫ�жϷ���if(ch>='A'&&ch<='Z')
// ����pos�ֳ䵱���Ƿ��ҵ���������ֻҪ��һ��Ϊ�棬�����ҵ��ˣ���һֱΪ��
void CGetCapPosDlg::OnGet() 
{
      CString strtxt,tmp,strres;
      int pos=0;
      GetDlgItem(IDC_TEXT)->GetWindowText(strtxt);
      strres="���ҽ����";
      for(int i=0;i<strtxt.GetLength();i++)
      {
            char ch=strtxt.GetAt(i);
            if(IsDBCSLeadByte(ch))
                  i++;
            if(ch>='A'&&ch<='Z')
            {
                  tmp.Format("%d",i);
                  if(pos==0)
                  {
                        pos=1;
                  }
                  else
                        strres+=" ";
                  strres+=tmp;
            }
      }
      if(pos==0)
      {
            strres="û�д�д�ַ�";
      }
      GetDlgItem(IDC_RESULT)->SetWindowText(strres);
}