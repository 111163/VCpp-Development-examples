// TextDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "TextDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CTextDllApp

BEGIN_MESSAGE_MAP(CTextDllApp, CWinApp)
END_MESSAGE_MAP()


// CTextDllApp ����

CTextDllApp::CTextDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTextDllApp ����

CTextDllApp theApp;


// CTextDllApp ��ʼ��

BOOL CTextDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

int AddInt(int var1, int var2)
{
	return var1+var2;
}


int SUBInt(int var1, int var2)
{
	return var1-var2;
}
