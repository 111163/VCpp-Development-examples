#include "stdafx.h"
#include "iostream.h"
 
class Emperor {
private:
      static Emperor *pEmperor;//声明一个Emperor类的引用
      static int count;//实例创建次数
    Emperor() {//将构造方法私有
            count++;
    }
public:
      static Emperor getInstance() {//实例化引用
        if (pEmperor == NULL) {
            pEmperor = new Emperor();
        }
        return *pEmperor;
    }
    void getName() {
        cout << "我是第" << count << "次创建的实例" << endl;
    }
};
 
Emperor * Emperor::pEmperor = NULL;
int Emperor::count = 0;
 
int main(int argc, char* argv[])
{
      cout << "创建1对象：" << endl;
      Emperor emperor1 = Emperor::getInstance();//创建对象
      emperor1.getName();//输出名字
      cout << "创建2对象：" << endl;
      Emperor emperor2 = Emperor::getInstance();//创建对象
      emperor2.getName();//输出名字
      cout << "创建3对象：" << endl;
      Emperor emperor3 = Emperor::getInstance();//创建对象
      emperor3.getName();//输出名字
            
      return 0;
}
心法领悟210：单例模式的应用
使用单例模式的一个好处就是可以限制对象的数量，从而节约资源。例如数据库的连接池就需要使用单例模式创建。另外，对于打印机而言，操作系统在管理时也使用了单例模式。这样就可以防止有多个打印任务时打印内容的混乱。
 