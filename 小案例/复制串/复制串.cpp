#include <stdio.h>

bool cpystr(char *pdst, const char *psrc)
{
	char *pch = pdst;                                //����һ���ַ�ָ��

	if (pdst==NULL || psrc == NULL)               //��֤����
		return false;

	while ((*pdst++ = *psrc++));                 //   ����Դ�ַ�����Ŀ���ַ�������Դ�ַ���ûһ���ַ���ֵ��Ŀ���ַ���
	return true;
}
int main(int argc, char* argv[])
{
	char data[30];
	if (cpystr(data,"One world,one dream!"))
		printf("%s\n",data);                       //������
	//getchar();
	return 0;
}