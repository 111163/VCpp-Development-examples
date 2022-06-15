#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


//本段程序中最有启发的是if(i<j)  printf("NOT");这一句值得深刻的思考
int main(int argc, char* argv[])
{
      long  x;
      int i,j,n,d[20];
      //n为x的位数,d数组用来存放每位数,数组长度应设计的大一些
      scanf("%ld",&x);
      n=0;
      do{
            d[n]=x%10;
            //将x的个位数字存放在数组d中
            x=x/10;
            //将x缩小10倍
            n++;
      }while(x!=0);
      for(i=0,j=n-1;i<j;i++,j--)
      //判断数组d下标i和j指向的元素是否相等
      if(d[i]!=d[j])  break;                  
      if(i<j)  printf("NOT");
      else  printf("YES");
}