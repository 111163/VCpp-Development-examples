#pragma once

#ifndef _AFXEXT
#define IDD_DIALOG1 9000
#else
#include "resource.h"
#endif

#ifdef calculations_EXPORTS
#define CALCULATIONS_API __declspec(dllexport)
#else
#define CALCULATIONS_API __declspec(dllimport)
#endif

// CMyDlg �Ի���

class CALCULATIONS_API CMyDlg : public CDialogEx    //AFX_EXT_CLASS���������ĺ��ж�(���жϽ����˱�����������)
{
	DECLARE_DYNAMIC(CMyDlg)

public:
	CMyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlg();

	// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
