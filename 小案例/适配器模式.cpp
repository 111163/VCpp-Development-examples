插头有中式的和西式两种-------当然对应的插座也有两种
我现在有一个中式的插头，但我人在西方，插座是西式的，我怎么办
将中式插头转西式插头  ----- 这中间就有一个转换器
这个转换器就是既知道中式标准插头，又知道西式标准插头
它基础自这两个类，但是它暴露出来的是西式的插头，而中式的插头在它看来是隐蔽的
所以有
class 适配器:public 西式插头, private 中式插头

//Adaptee 被适配者类.现有的类
//比如有美式插座、欧式插座、日式插座
class USOutlet {
public:
    void type() {
        std::cout << "using US outlet !" << std::endl;
    }
};


//Target 抽象目标类
//我们想用的国标类型
class CNOutlet {
public:
    virtual void use_CN_type() = 0;
};


//Adapter 适配类
//可以理解为转接头
//采用类适配器
class CNOutletAdapter : public CNOutlet, private USOutlet {
public:
    void use_CN_type() override {
        //do something convert
        std::cout << "adapter transfer CN to US outlet" << std::endl;
        type();

    }
};

//采用对象适配器
//采用将adaptee作为构造函数参数，类似的方式(如模板等)具有一定的灵活性
//可以选择性适配自己想适配的对象,和策略方式类似
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

//对象适配器方法2，将adaptee普通对象作为成员变量
//注意对比和上面对象适配器的区别
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
    //类适配器
    std::shared_ptr<CNOutlet> pCNOUtlet = std::make_shared<CNOutletAdapter>();
    pCNOUtlet->use_CN_type();
    //运行结果
    //adapter transfer CN to US outlet
    //using US outlet !

    //对象适配器
    CNOutletAdapter_2 cnOutletAdapter2(std::make_shared<USOutlet>());
    cnOutletAdapter2.use_CN_type();
    //运行结果
    //adapter transfer CN to US outlet
    //using US outlet !

    return 0;
}



// 这里实际上对象的适配器是更加好理解的

