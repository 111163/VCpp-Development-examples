#include "StdAfx.h"
#include <MMSystem.h> // windows多媒体及与它相关的硬件支持命令操作调用等
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

	// mciSendString函数向MCI设备发送命令字符串。
	// 命令发送到的设备在命令字符串中指定。

	// MCI全称是Media control interface即多媒体控制接口。说明白点就是程序与多媒体解码器通讯的一个界面。
	// 可利用这个接口跳过硬件访问并调用本地的符合MCI规格的多媒体解码驱动。完成对多媒体的回放录制与控制。
}


void CCDManager::BackCDRom(void)
{
	mciSendString("set cdaudio door closed",0, 0, NULL);
}
