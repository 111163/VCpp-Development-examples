#pragma once


// CEmployee �Ի���

class CEmployee : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployee)

public:
	CEmployee(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEmployee();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
