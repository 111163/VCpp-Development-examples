#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

// ��main�����е���GetLogicalDriveStrings������ȡϵͳ�̷��ַ�����Ȼ������whileѭ�����ֽ��ַ�����
	int main(int argc, char* argv[])
{
	DWORD dwLen = GetLogicalDriveStrings(0, nullptr);        //��ȡϵͳ�̷��ַ�������
	char *pszDriver = new char[dwLen];                                //�����ַ�����
	GetLogicalDriveStrings(dwLen, pszDriver);                //��ȡϵͳ�̷��ַ���
	char* pDriver = pszDriver;                                        //����һ����ʱָ��
	while (*pDriver != '\0')                                      //�����ַ���
	{
		cout << pDriver << endl;                                    //���ϵͳ�̷�
		pDriver += strlen(pDriver) + 1;                                   //��λ����һ���ַ�������1��Ϊ������\0�ַ�
	}
	delete [] pszDriver;                                            //�ͷ��ַ�����
	return 0;
}