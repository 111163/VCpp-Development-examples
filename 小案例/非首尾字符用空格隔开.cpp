// 本段程序是用来找出宽字节中大写字母出现的位置
// 但有较大启发的是设置标志加空格这个操作
// 首不会加空格的原因是pos == 0这个判断，尾不会加空格的原因是需要判断符合if(ch>='A'&&ch<='Z')
// 而且pos又充当了是否找到的条件，只要它一次为真，就是找到了，就一直为真
void CGetCapPosDlg::OnGet() 
{
      CString strtxt,tmp,strres;
      int pos=0;
      GetDlgItem(IDC_TEXT)->GetWindowText(strtxt);
      strres="查找结果：";
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
            strres="没有大写字符";
      }
      GetDlgItem(IDC_RESULT)->SetWindowText(strres);
}