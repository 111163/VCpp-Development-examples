// TextDll2.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "TextDll2.h"
#define TEXT_DLL

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

// CTextDll2App

BEGIN_MESSAGE_MAP(CTextDll2App, CWinApp)
END_MESSAGE_MAP()


// CTextDll2App ����

CTextDll2App::CTextDll2App()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTextDll2App ����

CTextDll2App theApp;


// CTextDll2App ��ʼ��

BOOL CTextDll2App::InitInstance()
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
