void CEditChar::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nChar == 8 || nChar == ' ')
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
		return;
	}
	if ((nChar < 'a' || nChar > 'z')&&(nChar < 'A' || nChar > 'Z') )
	{
		nChar = 0;
	}
	else
		CEdit::OnChar(nChar, nRepCnt, nFlags);
}

// ��ʵ��д���кö��֣������Ժ��ֻ�������淶
// ��ȻҲ������PreTranslateMessage��������