
// ����XML�ļ���̬���ɲ˵�Dlg.h : ͷ�ļ�
//

#pragma once
#import "C:\\WINDOWS\\system32\\msxml6.dll" 
using namespace MSXML2;



// C����XML�ļ���̬���ɲ˵�Dlg �Ի���
class C����XML�ļ���̬���ɲ˵�Dlg : public CDialogEx
{
	
// ����
public:
	C����XML�ļ���̬���ɲ˵�Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	void CreateMenuFromFile();
	void LoadSubMenu(CMenu* m_menu,CString str);
	BOOL IsHaveSubMenu(CString);
	MSXML2::IXMLDOMElementPtr m_pCurNode; // _com_ptr_t<IXMLDOMElement>
	CMenu m_cMenu;

	MSXML2::IXMLDOMDocumentPtr m_pXMLDoc; // _com_ptr_t<IXMLDOMDocument>

// �Ի�������
	enum { IDD = IDD_XML_DIALOG };

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
};
