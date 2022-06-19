��ͷ����ʽ�ĺ���ʽ����-------��Ȼ��Ӧ�Ĳ���Ҳ������
��������һ����ʽ�Ĳ�ͷ������������������������ʽ�ģ�����ô��
����ʽ��ͷת��ʽ��ͷ  ----- ���м����һ��ת����
���ת�������Ǽ�֪����ʽ��׼��ͷ����֪����ʽ��׼��ͷ
���������������࣬��������¶����������ʽ�Ĳ�ͷ������ʽ�Ĳ�ͷ�������������ε�
������
class ������:public ��ʽ��ͷ, private ��ʽ��ͷ

//Adaptee ����������.���е���
//��������ʽ������ŷʽ��������ʽ����
class USOutlet {
public:
    void type() {
        std::cout << "using US outlet !" << std::endl;
    }
};


//Target ����Ŀ����
//�������õĹ�������
class CNOutlet {
public:
    virtual void use_CN_type() = 0;
};


//Adapter ������
//�������Ϊת��ͷ
//������������
class CNOutletAdapter : public CNOutlet, private USOutlet {
public:
    void use_CN_type() override {
        //do something convert
        std::cout << "adapter transfer CN to US outlet" << std::endl;
        type();

    }
};

//���ö���������
//���ý�adaptee��Ϊ���캯�����������Ƶķ�ʽ(��ģ���)����һ���������
//����ѡ���������Լ�������Ķ���,�Ͳ��Է�ʽ����
class CNOutletAdapter_2 : public CNOutlet {
private:
    std::shared_ptr<USOutlet> m_pUSOutlet;
public:
    CNOutletAdapter_2(std::shared_ptr<USOutlet> pUSOutlet)
            : m_pUSOutlet(pUSOutlet) {

    }

    void use_CN_type() override {
        //do something convert
        std::cout << "adapter transfer CN to US outlet" << std::endl;
        m_pUSOutlet->type();
    }
};

//��������������2����adaptee��ͨ������Ϊ��Ա����
//ע��ԱȺ��������������������
class CNOutletAdapter_3 : public CNOutlet {
private:
    USOutlet m_usoutlet;
public:
    void use_CN_type() override {
        //do something convert
        std::cout << "adapter transfer CN to US outlet" << std::endl;
        m_usoutlet.type();

    }
};


int main() {
    //��������
    std::shared_ptr<CNOutlet> pCNOUtlet = std::make_shared<CNOutletAdapter>();
    pCNOUtlet->use_CN_type();
    //���н��
    //adapter transfer CN to US outlet
    //using US outlet !

    //����������
    CNOutletAdapter_2 cnOutletAdapter2(std::make_shared<USOutlet>());
    cnOutletAdapter2.use_CN_type();
    //���н��
    //adapter transfer CN to US outlet
    //using US outlet !

    return 0;
}



// ����ʵ���϶�����������Ǹ��Ӻ�����

