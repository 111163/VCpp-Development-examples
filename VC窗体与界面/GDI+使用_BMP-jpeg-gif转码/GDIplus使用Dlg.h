
// GDIplusʹ��Dlg.h : ͷ�ļ�
//

#pragma once

#include <GdiPlus.h>
using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

// CGDIplusʹ��Dlg �Ի���
class CGDIplusʹ��Dlg : public CDialogEx
{
// ����
public:
	CGDIplusʹ��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

	GdiplusStartupInput m_Gdiplus;          //�����ʼ����
	ULONG_PTR m_pGdiToken;                     //����GDI����
	CString m_FileName;                          //��¼�ļ�����


// �Ի�������
	enum { IDD = IDD_GDIPLUS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedConvert();
	CEdit m_ImageName;
	int m_nCheck;
	afx_msg void OnBnClickedBmp();
	afx_msg void OnBnClickedJpeg();
	afx_msg void OnBnClickedGif();
};
