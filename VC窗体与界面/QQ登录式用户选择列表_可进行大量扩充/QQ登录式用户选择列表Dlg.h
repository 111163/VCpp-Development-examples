
// QQ��¼ʽ�û�ѡ���б�Dlg.h : ͷ�ļ�
//

#pragma once


// CQQ��¼ʽ�û�ѡ���б�Dlg �Ի���
class CQQ��¼ʽ�û�ѡ���б�Dlg : public CDialogEx
{
// ����
public:
	CQQ��¼ʽ�û�ѡ���б�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_QQ_DIALOG };

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
	CEdit m_ConPw; // ����������������֤��
	CButton m_ConLog;  // ������Լ���һ��ͼƬ��Ҳ���Ժ����Ի��������һ����ť
	CButton m_ConCel;
	CImageList m_ImageList;  // ͼ���б�����������ݺ��ڿ������ɴ����ݿ��ж�ȡ
	CComboBoxEx m_ConUserNme; // ����ע����Ex
	// ������ť��ʹ�ð�ť������֤��Ϣ(�����ݿ��ж�ȡ�ȶ�)��Щ���涼���Լ���
};
