C++语言允许在一个类中定义另一个类，这被称之为嵌套类，也被称为内置类。当一个类只想被另外一个单独的类所使用时就可以将这个类定义为嵌套类。本实例实现了嵌套类的定义，程序运行结果如图1所示。
对于内部的嵌套类来说，只允许其在外围的类域中使用，在其他类域或者作用域中是不可以见的。所以嵌套类提高了类本身被访问的安全条件，但也减少了修改的机会。所以嵌套类适用于私有数据，并且是不再被修改的类。
（1）创建一个基于控制台的应用程序。
（2）主要程序代码如下：
#include "stdafx.h"
#include "string.h"
#include "ioStream.h"
 
#define MAXLEN 128                                             //定义一个宏
class CList                                                       //定义CList类
{
public:                                                             //嵌套类为公有的
      class CNode                                                     //定义嵌套类CNode
      {
            friend class CList;                                       //将CList类作为自己的友元类
      private:
            int m_Tag;                                           //定义私有成员
      public:
            char m_Name[MAXLEN];                                  //定义共有数据成员
      };                                                             //CNode类定义结束
public:
      CNode m_Node;                                        //定义一个CNode类型数据成员
      void SetNodeName(const char *pchData)                   //定义成员函数
      {
            if (pchData != NULL)                                  //判断指针是否为空
            {
                  strcpy(m_Node.m_Name,pchData);        //访问CNode类的共有数据
            }
      }
      void SetNodeTag(int tag)                                   //定义成员函数
      {
            m_Node.m_Tag = tag;                          //访问CNode类的私有数据
      }
      void Display()
      {
            cout << "节点名称：" << m_Node.m_Name << endl;
            cout << "标记：" << m_Node.m_Tag << endl;
      }
};
 
 
int main(int argc, char* argv[])
{
      CList list;
      list.SetNodeName("节点");
      list.SetNodeTag(10);
      list.Display();
      return 0;
}
心法领悟223：嵌套类的使用范围
嵌套类一般定义在一个类的内部，所以嵌套类的作用范围也只就在其所定义的类的内部有效。如果想在其类中使用这个类，就必须重新定义这个类。



// 本例中应该注意到的是子类中使用了friend class CList;声明，这里很重要的一个细节