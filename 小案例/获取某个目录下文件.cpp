//�ڳ������ļ���������������Ҫ�Դ���Ŀ¼���б�����Ȼ���ڱ��������жԲ��ҵ����ļ����в���������ʵ�����ڿ���̨Ӧ�ó����ж�ָ���Ĵ���Ŀ¼���б����Ĳ��������н����ͼ1��ʾ��
//���ڴ���Ŀ¼�ı�����Ҫ����������_findfirst��_findnext��_findclose�������������ֱ��ʾ�˵�һ�β��ҡ�������һ���͹رն��ļ��Ĳ��ҡ�����һ����������û�гɹ�ʱ�Ͳ���Ҫ����_findnext�����ٽ�����һ�εĲ����ˣ�����ͱ������_findnext����ֱ�����ҽ����������ҽ�������Ҫ����_findclose�����ر��ļ���Ŀ¼����ʱ��ʹ�õ���Դ��
//��1������һ������̨Ӧ�ó��򣬹�������Ϊ��ListDir����
//��2���ڹ��������á�io.h������string.h���͡�iostream.h��ͷ�ļ���
#include <io.h>
#include <string.h>
#include <iostream.h>
//��3����ȫ������������ȫ�ֶ���
const int MAXLEN = 1024;                 //�������Ŀ¼����
unsigned long FILECOUNT = 0;        //��¼�ļ�����
//��4����дһ���ݹ麯����ʵ��ָ��Ŀ¼�ı�����
void ListDir(const char* pchData)
{
      _finddata_t   fdata;                   //�����ļ����ҽṹ����
      long   done;    
      char tempdir[MAXLEN]={0};              //����һ����ʱ�ַ����飬�洢Ŀ¼
      strcat(tempdir, pchData);                     //�����ַ���
      strcat(tempdir, "\\*.*");                 //�����ַ���
      done   =  _findfirst(tempdir, &fdata);   //��ʼ�����ļ�
      if (done != -1)                              //�Ƿ���ҳɹ�
      {
            int ret = 0;
            while  (ret != -1)               //����һ��ѭ��
            {
                  if (fdata.attrib != _A_SUBDIR) //�ж��ļ�����
                  {
                        if (strcmp(fdata.name,"...") != 0 &&
                              strcmp(fdata.name,"..") != 0 &&
                              strcmp(fdata.name,".") != 0)      //����.
                        {
                              char dir[MAXLEN]={0};           //�����ַ�����
                              strcat(dir,pchData);                   //�����ַ���
                              strcat(dir,"\\");                   //�����ַ���
                              strcat(dir,fdata.name);        //�����ַ���
                              cout << dir << endl;                  //������ҵ��ļ�
                              FILECOUNT++;                //�ۼ��ļ�
                        }
                  }
                  ret = _findnext(done, &fdata);                             ////������һ���ļ�
                  if (fdata.attrib == _A_SUBDIR && ret != -1)  //�ж��ļ����ԣ������Ŀ¼����ݹ����
                  {
                        if (strcmp(fdata.name,"...") != 0 &&
                              strcmp(fdata.name,"..") != 0 &&
                              strcmp(fdata.name,".") != 0)             //����.
                        {
                              char pdir[MAXLEN]= {0};               //�����ַ�����
                              strcat(pdir,pchData);                        //�����ַ���
                              strcat(pdir , "\\");                       //�����ַ���
                              strcat(pdir,fdata.name);                     //�����ַ���
                              ListDir(pdir);                            //�ݹ����
                        }
                  }
            }
      }
}
//��5����main�������ṩһ��Ŀ¼������ListDir��������Ŀ¼��
int main(void)   
{   
      while (true)                                                //���һ��ѭ��
      {
            FILECOUNT = 0;
            char  szFileDir[128] = {0};                         //����һ���ַ����飬�洢Ŀ¼
            cin >> szFileDir;
            if (strcmp(szFileDir, "e") == 0)                                   //�˳�ϵͳ
            {
                  break;
            }
            ListDir(szFileDir);                                       //����ListDir��������Ŀ¼
            cout << "����" << FILECOUNT << "���ļ�" << endl; //ͳ���ļ�����
      }
      return 0; 
}