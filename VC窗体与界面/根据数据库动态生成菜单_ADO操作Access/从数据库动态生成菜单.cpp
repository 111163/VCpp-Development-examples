
// �����ݿ⶯̬���ɲ˵�.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "�����ݿ⶯̬���ɲ˵�.h"
#include "�����ݿ⶯̬���ɲ˵�Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ݿ⶯̬���ɲ˵�App

BEGIN_MESSAGE_MAP(C�����ݿ⶯̬���ɲ˵�App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// C�����ݿ⶯̬���ɲ˵�App ����

C�����ݿ⶯̬���ɲ˵�App::C�����ݿ⶯̬���ɲ˵�App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� C�����ݿ⶯̬���ɲ˵�App ����

C�����ݿ⶯̬���ɲ˵�App theApp;
_ConnectionPtr m_pCon;
_RecordsetPtr m_pRecord;

// C�����ݿ⶯̬���ɲ˵�App ��ʼ��

BOOL C�����ݿ⶯̬���ɲ˵�App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	::CoInitialize(NULL);
	m_pCon = NULL;
	m_pCon.CreateInstance(__uuidof(Connection));
	m_pRecord = NULL;
	m_pRecord.CreateInstance(__uuidof(Recordset));
	m_pCon->ConnectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Menu.accdb;Persist Security Info=False";
	try 
	{
		m_pCon->Open(L"", L"", L"", -1);
	}
	catch (...)
	{
		AfxMessageBox("���ݿ����Ӵ���");
		exit(0);
	}



	C�����ݿ⶯̬���ɲ˵�Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}



int C�����ݿ⶯̬���ɲ˵�App::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	m_pRecord->Close();
	m_pRecord = NULL;
	m_pCon->Close();
	m_pCon = NULL;
	::CoUninitialize();
	return CWinApp::ExitInstance();
}
