// ����һ���ṹ�����洢������Ϣ��Ȼ����ýṹ�����飬���������е�������Ϣ���г�ʼ���������ڽṹ�п���ָ��ÿ�������ڸ�����ţ������Ϳ���ͨ���򵥵�ѭ���������е�������Ϣ��������ʾ����������򵥵ķ����������õݹ����ʵ�ֶ����������ݵı�������ȡ��
//��1������һ�����ڿ���̨��Ӧ�ó���
//��2���������ڴ洢�ڵ�ĽṹZone���������£�
#include "stdafx.h"
#include "iostream.h"
#include "string.h"
 
#define MAX_LEN 128
//����һ������ṹ        
struct Zone                                        // ���ֽṹ��̳�����ʮ�ֵ�����   ---����������굽����ʱ��ʶ�����C++��RTTI
{
      int  nID;                       //ID��ʶ
      char szName[MAX_LEN];    //��������
      int  nHightID;               //�ϼ�����ID
};
//��3�����庯��ListZoneʵ�ֽڵ��������������£�
void ListZone(Zone Nodes[], int nLen, int nID, int &nLevel)
{
      for(int i=0; i<nLen; i++)
      {
            if (Nodes[i].nHightID == nID)
            {
                  for(int j=0; j<nLevel; j++)  //��������
                  {
                        cout << "   " ;
                  }
                  cout << Nodes[i].szName << endl;
                  nLevel++;                                        //        ---\
                  ListZone(Nodes, nLen, Nodes[i].nID, nLevel);     //            >����ǳ����ã�ֵ����̿��ǣ���һ������һ�����࣬���ص��������ܱ䣬�������ѭ������
                  nLevel--;                                        //        ---/ д��i++,Ȼ����i--������
            }
      }
}
//��4����дmain����ʵ�ֽڵ���Ϣ��������������������£�
int main(int argc, char* argv[])
{
      char * szName[10]= {"����ʡ", "������ʡ", "������", "��ԭ��", "��Դ��", "��ƽ��",
                                    "������", "ǰ����", "������", "������"};
      Zone  Node[10];
      for(int i=0; i<10; i++)
      {
            Node[i].nID = i;
            strcpy(Node[i].szName, szName[i]);
            Node[i].nHightID = -1;                  //Ĭ������Ϊ-1����ʾû���ϼ�ID
      }
      //�����ϼ�ID
      Node[2].nHightID = 0;
      Node[3].nHightID = 0;
      Node[4].nHightID = 0;
      Node[5].nHightID = 0;
      Node[6].nHightID = 3;
      Node[7].nHightID = 3;
      Node[8].nHightID = 3;
      Node[9].nHightID = 3;
 
      int nLevel = 2;                              //����
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