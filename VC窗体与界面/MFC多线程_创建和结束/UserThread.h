#pragma once



// CUserThread

class CUserThread : public CWinThread
{
	DECLARE_DYNCREATE(CUserThread)

protected:
	CUserThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CUserThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


