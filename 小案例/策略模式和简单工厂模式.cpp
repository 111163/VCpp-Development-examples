���ڲ���ģʽ���ԣ���Ҫ����һ������������ʾ���ֲ��Եĳ��������Ϳ���ʹ�ö�̬���������ѡ��ͬ��ʵ���ࡣȻ����ÿһ�־���Ĳ�����ʵ����������࣬��Ϊ���ж���ķ����ṩ�����ʵ�֡�������ѡ���ʵ��Ĳ�������Щ�����㣬��Ҫ���ϵ��ж���Ҫ�����ͣ�����ü򵥹���������ʵ���жϹ��̡�
��1������һ�����ڿ���̨��Ӧ�ó���
��2����д�ӿ�ImageSaver���ڸýӿ��ж�����save()�������������£�
//������
class ImageSaver {
public:
    virtual void save() = 0;//����save()����
};
��3����д��GIFSaver��JPEGSaver�࣬��������ʵ����ImageSaver�ӿڡ���ʵ��save()����ʱ��ͼƬ�������GIF��JPEG��ʽ���������£�
class GIFSaver :public ImageSaver {
public:
      virtual void save() {//ʵ��save()����
        cout << "��ͼƬ�����GIF��ʽ" << endl;
    }
};
 
class JPEGSaver :public ImageSaver {
public:
      virtual void save() {//ʵ��save()����
        cout << "��ͼƬ�����GIF��ʽ" << endl;
    }
};
��4����д��TypChooser����������û��ṩ��ͼƬ������ѡ����ʵ�ͼƬ�洢��ʽ���������£�
class TypeChooser {
public:
      static ImageSaver* getSaver(int type) {
        if (type == GIF) {//ʹ��if else������ж�ͼƬ������
            return new GIFSaver();
        } else if (type == JPEG) {
            return new JPEGSaver();
        }else {
            return NULL;
        }
    }
};
��5����дmain�������������£�
int main(int argc, char* argv[])
{
      cout << "�û�ѡ����GIF��ʽ��" << endl;
      ImageSaver *saver = TypeChooser::getSaver(GIF);//��ñ���ͼƬΪGIF���͵Ķ���
      saver->save();
      cout << "�û�ѡ����JPEG��ʽ��" << endl;//��ñ���ͼƬΪJPEG���͵Ķ���
      saver = TypeChooser::getSaver(JPEG);
      saver->save();
 
      return 0;
}


����ģʽ�ļ�Ӧ��
����ģʽ��Ҫ�����кܶ಻ͬ�ķ�ʽ�����ͬһ��������龰�����籣���ļ������Ա����txt��Ҳ���Ա����xml�������Ҫ�ṩ���ֲ�����ʵ�־���ı��淽����ѹ���ļ����̳��Ĵ������Եȶ������Ƶġ�����˵����ģʽ���ճ������е�Ӧ�÷ǳ��㷺��