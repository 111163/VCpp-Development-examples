
// ʹ����Ͽ��оٴ���Ŀ¼Dlg.h : ͷ�ļ�
//

#pragma once


// Cʹ����Ͽ��оٴ���Ŀ¼Dlg �Ի���
class Cʹ����Ͽ��оٴ���Ŀ¼Dlg : public CDialogEx
{
// ����
public:
	Cʹ����Ͽ��оٴ���Ŀ¼Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

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
public:
	CComboBoxEx m_ComboEx;
	CImageList 	m_ImageList;				//����ͼ���б�
	void LoadSysDisk(void);
};
