// 在许多语言中都有对事件的定义，事件的作用是可以在类外实现一个事件，然后在类中调用这个事件。这样在设计类时就可以不必实现某些功能，而这些功能可以交给外部函数来处理，这样更增加了程序的灵活性。本实例实现了如何在类中实现事件。
// 在C++语言中实现事件可以使用函数回调的方法，而函数回庙就是使用函数指针来实现的。注意这里针对的是普通的函数，不包括完全依赖于不同语法和语义规则的类成员函数。声明函数指针回调函数是一个程序员不能显式调用的函数，通过将回调函数的地址传给调用者从而实现调用。要实现回调，必须首先定义函数指针。尽管定义的语法有点不可思议，但如果你熟悉函数声明的一般方法，便会发现函数指针的声明与函数声明非常类似。请看下面的例子：
// void f()；// 函数原型
// 上面的语句声明了一个函数，没有输入参数并返回void。那么函数指针的声明方法如下：
// void (*f) ();
//（1）创建一个基于控制台的应用程序。
//（2）主要程序代码如下：
#include "stdafx.h"
#include "ioStream.h"
#include "string.h"
 
class CLoad;
typedef void (*TEvent)(CLoad * e);//事件指针
 
class CLoad
{
private:
      char filename[10];//文件名
public:
      TEvent OnLoad;//载入事件
      void Load(char *FileName)
      {
            strcpy(filename,FileName);
            cout << "执行内部载入操作" << endl;
            if (OnLoad != NULL)//是否存在事件
                  OnLoad(this);//执行事件
      }
      char * GetFileName()
      {
            return filename;
      }
};
 
void OnLoad(CLoad* e)//定义外部事件
{
      cout << "执行外部事件加载文件：" << e->GetFileName() << endl;
}
 
int main(int argc, char* argv[])
{
      CLoad ld;
      ld.OnLoad = OnLoad;//添加事件
      ld.Load("c:\\123.txt");
      return 0;
}

// 一定是指针调用回调函数
// 那么到底什么是回调函数呢？已有的东西，通过指针来使用现在的功能代码(现在的这个，或这些符合这个函数指针的规范的都是回调函数)
// 千万要正确理解，回调是一个过程，是一个通过函数指针来调用函数的过程  ---也就是说这个函数指针是用来客观是实现多种功能的
// 如果直接调用某个函数，你在设计的时，就已经是明确要执行某个功能了，而不是多种功能