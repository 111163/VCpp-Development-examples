������㰴ť��û�й�ϵ�ģ��ؼ������ID ��ϵͳԤ�ȶ��õ���һ�µģ���Ȼ��Ҳ��������Ϊ��һ�£��������û��д�������ID �Ŀؼ�����Ϣ��Ӧ�Ļ������ͻ����ID ��������Ϣ�в��ҵĵ������ǵ����ĸ�Ԥ�õ���Ӧ��������Ӧ

Դ��λ�� dlgcore.cpp�ļ���
void CDialog::EndDialog(int nResult)
{
	ASSERT(::IsWindow(m_hWnd));

	if (m_nFlags & (WF_MODALLOOP|WF_CONTINUEMODAL))
		EndModalLoop(nResult);

	::EndDialog(m_hWnd, nResult);
}

void CDialog::OnOK()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, "UpdateData failed during dialog termination.\n");
		// the UpdateData routine will set focus to correct item
		return;
	}
	EndDialog(IDOK);
}

void CDialog::OnCancel()
{
	EndDialog(IDCANCEL);
}


��ô�˽�����������ʲô���أ�����˵���ص���EndDialog�趨��ֵ��������ĳ���ؼ���ID
�������Լ�����EndDialog����һ���㶨�Ƶ�ֵ
ͨ����ͬ��ֵ����֪���˵����ǵ�����Ǹ���ť���µ��˳����Լ�����һ���Ĺ�������ָ��
����Ӧ��֪���ǵײ��װ��::::EndDialog(m_hWnd, nResult);�����ģ̬�Ի����˳���
