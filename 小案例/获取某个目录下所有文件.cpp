// 这里用的标准C++的库函数

（1）在工程中引用“io.h”、“string.h”和“iostream.h”头文件。
#include <io.h>
#include <string.h>
#include <iostream.h>
（2）在全局区域定义两个全局对象。
const int MAXLEN = 1024;                        //定义最大目录长度
unsigned long FILECOUNT = 0;          //记录文件数量
（3）编写一个递归函数，实现指定目录的遍历。
void ListDir(const char* pchData,const char * pFileName,bool *pBool)
{
      _finddata_t   fdata;                   //定义文件查找结构对象
      long   done;    
      char tempdir[MAXLEN]={0};              //定义一个临时字符数组，存储目录
      strcat(tempdir, pchData);                     //连接字符串
      strcat(tempdir, "\\*.*");                 //连接字符串
      done   =  _findfirst(tempdir, &fdata);   //开始查找文件
      if (done != -1)                              //是否查找成功
      {
            int ret = 0;
            while  (ret != -1)               //定义一个循环
            {
                  if (fdata.attrib != _A_SUBDIR) //判断文件属性
                  {
                        if (strcmp(fdata.name,"...") != 0 &&
                              strcmp(fdata.name,"..") != 0 &&
                              strcmp(fdata.name,".") != 0)      //过滤.
                        {
                              char dir[MAXLEN]={0};           //定义字符数组
                              strcat(dir,pchData);                   //连接字符串
                              strcat(dir,"\\");                   //连接字符串
                              strcat(dir,fdata.name);        //连接字符串
                              cout << dir << endl;                  //输出查找的文件
                              FILECOUNT++;                //累加文件
                              if (strcmp(fdata.name,pFileName) == 0)
                                    break;
                        }
                  }
                  ret = _findnext(done, &fdata);                             ////查找下一个文件
                  if (fdata.attrib == _A_SUBDIR && ret != -1)  //判断文件属性，如果是目录，则递归调用
                  {
                        if (strcmp(fdata.name,"...") != 0 &&
                              strcmp(fdata.name,"..") != 0 &&
                              strcmp(fdata.name,".") != 0)             //过滤.
                        {
                              char pdir[MAXLEN]= {0};               //定义字符数组
                              strcat(pdir,pchData);                        //连接字符串
                              strcat(pdir , "\\");                       //连接字符串
                              strcat(pdir,fdata.name);                     //连接字符串
                              ListDir(pdir,pFileName,pBool);                               //递归调用
                              if (*pBool)
                                    break;
                        }
                  }
            }
      }
}
（4）在main函数中提供一个目录，调用ListDir函数遍历目录。
int main(int argc, char* argv[])
{
      while (true)                                                //设计一个循环
      {
            FILECOUNT = 0;
            char  szFileDir[128] = {0};                         //定义一个字符数组，存储目录
            char  szFileName[128] = {0};
            bool isFind = false;
            cin >> szFileDir;
            cin >> szFileName;
            if (strcmp(szFileDir, "e") == 0)                                   //退出系统
            {
                  break;
            }
            ListDir(szFileDir,szFileName,&isFind);                                             //调用ListDir函数遍历目录
            cout << "共计" << FILECOUNT << "个文件" << endl; //统计文件数量
      }
      return 0; 
}