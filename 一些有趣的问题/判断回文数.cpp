#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


//���γ�����������������if(i<j)  printf("NOT");��һ��ֵ����̵�˼��
int main(int argc, char* argv[])
{
      long  x;
      int i,j,n,d[20];
      //nΪx��λ��,d�����������ÿλ��,���鳤��Ӧ��ƵĴ�һЩ
      scanf("%ld",&x);
      n=0;
      do{
            d[n]=x%10;
            //��x�ĸ�λ���ִ��������d��
            x=x/10;
            //��x��С10��
            n++;
      }while(x!=0);
      for(i=0,j=n-1;i<j;i++,j--)
      //�ж�����d�±�i��jָ���Ԫ���Ƿ����
      if(d[i]!=d[j])  break;                  
      if(i<j)  printf("NOT");
      else  printf("YES");
}