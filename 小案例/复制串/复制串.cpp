#include <stdio>

bool cpystr(char *pdst, const char *psrc)
{
	char *pch = pdst;                                //定义一个字符指针

	if (pdst==NULL || psrc == NULL)               //验证参数
		return false;

	while ((*pdst++ = *psrc++) != '\0')                    //遍历源字符串和目标字符串，将源字符串没一个字符赋值给目标字符串
		;
	return true;
}
int main(int argc, char* argv[])
{
	char data[30];
	if (cpystr(data,"One world,one dream!"))
		printf("%s\n",data);                       //输出结果
	return 0;
}