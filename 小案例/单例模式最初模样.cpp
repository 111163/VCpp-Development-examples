#include "stdafx.h"
#include "iostream.h"
 
class Emperor {
private:
      static Emperor *pEmperor;//����һ��Emperor�������
      static int count;//ʵ����������
    Emperor() {//�����췽��˽��
            count++;
    }
public:
      static Emperor getInstance() {//ʵ��������
        if (pEmperor == NULL) {
            pEmperor = new Emperor();
        }
        return *pEmperor;
    }
    void getName() {
        cout << "���ǵ�" << count << "�δ�����ʵ��" << endl;
    }
};
 
Emperor * Emperor::pEmperor = NULL;
int Emperor::count = 0;
 
int main(int argc, char* argv[])
{
      cout << "����1����" << endl;
      Emperor emperor1 = Emperor::getInstance();//��������
      emperor1.getName();//�������
      cout << "����2����" << endl;
      Emperor emperor2 = Emperor::getInstance();//��������
      emperor2.getName();//�������
      cout << "����3����" << endl;
      Emperor emperor3 = Emperor::getInstance();//��������
      emperor3.getName();//�������
            
      return 0;
}
�ķ�����210������ģʽ��Ӧ��
ʹ�õ���ģʽ��һ���ô����ǿ������ƶ�����������Ӷ���Լ��Դ���������ݿ�����ӳؾ���Ҫʹ�õ���ģʽ���������⣬���ڴ�ӡ�����ԣ�����ϵͳ�ڹ���ʱҲʹ���˵���ģʽ�������Ϳ��Է�ֹ�ж����ӡ����ʱ��ӡ���ݵĻ��ҡ�
 