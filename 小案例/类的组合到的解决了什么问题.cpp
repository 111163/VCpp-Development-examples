C++����������һ�����ж�����һ���࣬�ⱻ��֮ΪǶ���࣬Ҳ����Ϊ�����ࡣ��һ����ֻ�뱻����һ������������ʹ��ʱ�Ϳ��Խ�����ඨ��ΪǶ���ࡣ��ʵ��ʵ����Ƕ����Ķ��壬�������н����ͼ1��ʾ��
�����ڲ���Ƕ������˵��ֻ����������Χ��������ʹ�ã�����������������������ǲ����Լ��ġ�����Ƕ����������౾�����ʵİ�ȫ��������Ҳ�������޸ĵĻ��ᡣ����Ƕ����������˽�����ݣ������ǲ��ٱ��޸ĵ��ࡣ
��1������һ�����ڿ���̨��Ӧ�ó���
��2����Ҫ����������£�
#include "stdafx.h"
#include "string.h"
#include "ioStream.h"
 
#define MAXLEN 128                                             //����һ����
class CList                                                       //����CList��
{
public:                                                             //Ƕ����Ϊ���е�
      class CNode                                                     //����Ƕ����CNode
      {
            friend class CList;                                       //��CList����Ϊ�Լ�����Ԫ��
      private:
            int m_Tag;                                           //����˽�г�Ա
      public:
            char m_Name[MAXLEN];                                  //���干�����ݳ�Ա
      };                                                             //CNode�ඨ�����
public:
      CNode m_Node;                                        //����һ��CNode�������ݳ�Ա
      void SetNodeName(const char *pchData)                   //�����Ա����
      {
            if (pchData != NULL)                                  //�ж�ָ���Ƿ�Ϊ��
            {
                  strcpy(m_Node.m_Name,pchData);        //����CNode��Ĺ�������
            }
      }
      void SetNodeTag(int tag)                                   //�����Ա����
      {
            m_Node.m_Tag = tag;                          //����CNode���˽������
      }
      void Display()
      {
            cout << "�ڵ����ƣ�" << m_Node.m_Name << endl;
            cout << "��ǣ�" << m_Node.m_Tag << endl;
      }
};
 
 
int main(int argc, char* argv[])
{
      CList list;
      list.SetNodeName("�ڵ�");
      list.SetNodeTag(10);
      list.Display();
      return 0;
}
�ķ�����223��Ƕ�����ʹ�÷�Χ
Ƕ����һ�㶨����һ������ڲ�������Ƕ��������÷�ΧҲֻ�����������������ڲ���Ч���������������ʹ������࣬�ͱ������¶�������ࡣ



// ������Ӧ��ע�⵽����������ʹ����friend class CList;�������������Ҫ��һ��ϸ��