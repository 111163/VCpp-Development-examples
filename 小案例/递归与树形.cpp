// 定义一个结构用来存储区域信息，然后定义该结构的数组，并对数组中的区域信息进行初始化。由于在结构中可以指定每个区域在父级编号，这样就可以通过简单的循环将数组中的区域信息按级别显示出来。而最简单的方法就是利用递归调用实现对数组中数据的遍历和提取。
//（1）创建一个基于控制台的应用程序。
//（2）定义用于存储节点的结构Zone，代码如下：
#include "stdafx.h"
#include "iostream.h"
#include "string.h"
 
#define MAX_LEN 128
//定义一个区域结构        
struct Zone                                        // 这种结构与继承链是十分的相似   ---这里可以引申到运行时类识别就是C++的RTTI
{
      int  nID;                       //ID标识
      char szName[MAX_LEN];    //区域名称
      int  nHightID;               //上级区域ID
};
//（3）定义函数ListZone实现节点的输出，代码如下：
void ListZone(Zone Nodes[], int nLen, int nID, int &nLevel)
{
      for(int i=0; i<nLen; i++)
      {
            if (Nodes[i].nHightID == nID)
            {
                  for(int j=0; j<nLevel; j++)  //设置缩进
                  {
                        cout << "   " ;
                  }
                  cout << Nodes[i].szName << endl;
                  nLevel++;                                        //        ---\
                  ListZone(Nodes, nLen, Nodes[i].nID, nLevel);     //            >这里非常有用，值的深刻考虑，下一级比上一级更多，但回到本级后不能变，这就是在循环里面
                  nLevel--;                                        //        ---/ 写了i++,然后又i--的作用
            }
      }
}
//（4）编写main函数实现节点信息的输入与输出，代码如下：
int main(int argc, char* argv[])
{
      char * szName[10]= {"吉林省", "黑龙江省", "长春市", "松原市", "辽源市", "四平市",
                                    "扶余县", "前郭县", "宁江区", "长岭县"};
      Zone  Node[10];
      for(int i=0; i<10; i++)
      {
            Node[i].nID = i;
            strcpy(Node[i].szName, szName[i]);
            Node[i].nHightID = -1;                  //默认设置为-1，表示没有上级ID
      }
      //设置上级ID
      Node[2].nHightID = 0;
      Node[3].nHightID = 0;
      Node[4].nHightID = 0;
      Node[5].nHightID = 0;
      Node[6].nHightID = 3;
      Node[7].nHightID = 3;
      Node[8].nHightID = 3;
      Node[9].nHightID = 3;
 
      int nLevel = 2;                              //缩进
      for(int j=0; j<10; j++)
      {
            if(Node[j].nHightID == -1)
            {
                  cout << "    " << Node[j].szName << endl;
                  ListZone(Node, 10, Node[j].nID, nLevel);
            }
      }
      return 0;
}