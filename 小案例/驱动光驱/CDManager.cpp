#include "StdAfx.h"
#include <MMSystem.h> // windows��ý�弰������ص�Ӳ��֧������������õ�
#include "CDManager.h"


#pragma comment(lib, "Winmm.lib")


CCDManager::CCDManager(void)
{
}


CCDManager::~CCDManager(void)
{
}

void CCDManager::PopCDRom(void)
{
	mciSendString("set cdauio door open", 0, 0, NULL); 

	// mciSendString������MCI�豸���������ַ�����
	// ����͵����豸�������ַ�����ָ����

	// MCIȫ����Media control interface����ý����ƽӿڡ�˵���׵���ǳ������ý�������ͨѶ��һ�����档
	// ����������ӿ�����Ӳ�����ʲ����ñ��صķ���MCI���Ķ�ý�������������ɶԶ�ý��Ļط�¼������ơ�
}


void CCDManager::BackCDRom(void)
{
	mciSendString("set cdaudio door closed",0, 0, NULL);
}
