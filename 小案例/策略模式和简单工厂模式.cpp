对于策略模式而言，需要定义一个抽象类来表示各种策略的抽象。这样就可以使用多态来让虚拟机选择不同的实现类。然后让每一种具体的策略来实现这个抽象类，并为其中定义的方法提供具体的实现。由于在选择适当的策略上有些不方便，需要不断的判断需要的类型，因此用简单工厂方法来实现判断过程。
（1）创建一个基于控制台的应用程序。
（2）编写接口ImageSaver，在该接口中定义了save()方法，代码如下：
//抽象类
class ImageSaver {
public:
    virtual void save() = 0;//定义save()方法
};
（3）编写类GIFSaver和JPEGSaver类，这两个类实现了ImageSaver接口。在实现save()方法时将图片保存成了GIF和JPEG格式。代码如下：
class GIFSaver :public ImageSaver {
public:
      virtual void save() {//实现save()方法
        cout << "将图片保存成GIF格式" << endl;
    }
};
 
class JPEGSaver :public ImageSaver {
public:
      virtual void save() {//实现save()方法
        cout << "将图片保存成GIF格式" << endl;
    }
};
（4）编写类TypChooser，该类根据用户提供的图片类型来选择合适的图片存储方式。代码如下：
class TypeChooser {
public:
      static ImageSaver* getSaver(int type) {
        if (type == GIF) {//使用if else语句来判断图片的类型
            return new GIFSaver();
        } else if (type == JPEG) {
            return new JPEGSaver();
        }else {
            return NULL;
        }
    }
};
（5）编写main方法，代码如下：
int main(int argc, char* argv[])
{
      cout << "用户选择了GIF格式：" << endl;
      ImageSaver *saver = TypeChooser::getSaver(GIF);//获得保存图片为GIF类型的对象
      saver->save();
      cout << "用户选择了JPEG格式：" << endl;//获得保存图片为JPEG类型的对象
      saver = TypeChooser::getSaver(JPEG);
      saver->save();
 
      return 0;
}


策略模式的简单应用
策略模式主要用于有很多不同的方式来解决同一个问题的情景。例如保存文件，可以保存成txt，也可以保存成xml，这就需要提供两种策略来实现具体的保存方法。压缩文件、商场的促销策略等都是类似的。可以说策略模式在日常生活中的应用非常广泛。