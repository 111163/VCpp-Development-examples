1.����Ҫ�˵��Ŀ�ܻ�Ի�������ӱ���
CMenu m_Menu;

2.�ڳ�ʼ�������У��Բ˵��������������� ��������
m_Menu.CreateMenu(); // �˵�
CMenu m_PopMenu;
m_PopMenu.CreatePopupMenu();  // ��������˼��(�������������)
m_Menu.AppendMenu(MF_POPUP, (UINT)m_PopMenu.m_hMenu, "����"); // �������˵��Ͳ˵���
m_PopMenu.AppendMenu(MF_STRING, ID_MENUCAT, "è");    // �������ǵ����˵�����
m_PopMenu.AppendMenu(MF_STRING, ID_MENUDOG, "��");
m_PopMenu.AppendMenu(MF_STRING, ID_MENUMONKEY, "����");
m_Menu.AppendMenu(MF_POPUP, -1, "ֲ��");
m_PopMenu.Detach(); // ��Ϊ�����˵����Ǹ��ֲ���������Ҫ������ֲ����;������
SetMenu(&m_Menu);


// ��Ȼ֮ǰҪ��ID���úã�������������ȷ������ID��������ܵõ���ȷ�Ĵ���
����Դͷ�ļ���Resource.h�����ڸ��ļ��ж�������ID���������¡�
#define ID_MENUCAT                                     1001                                          //����˵�����ID
#define ID_MENUDOG                            1002                                          //����˵�����ID
#define ID_MENUMONKEY                             1003                                          //����˵�����ID
