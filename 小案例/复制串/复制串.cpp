#include <stdio>

bool cpystr(char *pdst, const char *psrc)
{
	char *pch = pdst;                                //����һ���ַ�ָ��

	if (pdst==NULL || psrc == NULL)               //��֤����
		return false;

	while ((*pdst++ = *psrc++) != '\0')                    //����Դ�ַ�����Ŀ���ַ�������Դ�ַ���ûһ���ַ���ֵ��Ŀ���ַ���
		;
	return true;
}
int main(int argc, char* argv[])
{
	char data[30];
	if (cpystr(data,"One world,one dream!"))
		printf("%s\n",data);                       //������
	return 0;
}