// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SHOWDLG_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SHOWDLG_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SHOWDLG_EXPORTS
#define SHOWDLG_API __declspec(dllexport)
#else
#define SHOWDLG_API __declspec(dllimport)
#endif

// �����Ǵ� ShowDlg.dll ������
class SHOWDLG_API CShowDlg {
public:
	CShowDlg(void);
	// TODO: �ڴ�������ķ�����
};

extern SHOWDLG_API int nShowDlg;

SHOWDLG_API int fnShowDlg(void);
