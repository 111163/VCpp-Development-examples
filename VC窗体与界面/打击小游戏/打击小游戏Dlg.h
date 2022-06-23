
// 打击小游戏Dlg.h : 头文件
//

#pragma once

enum GameState{GS_BEGIN, GS_END, GS_NONE}; // 游戏状态

// C打击小游戏Dlg 对话框
class C打击小游戏Dlg : public CDialogEx
{
// 构造
public:
	C打击小游戏Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	UINT m_DeathCount;
	UINT m_Grade;
	UINT m_nLevel;
	UINT m_MisCount;
	UINT m_EscCount;
protected:
	CPoint m_ptOrg;                  //表格原点坐标
	int m_nCellWidth;                 //单元格宽度
	int m_nCellHeight;                //单元格高度
	int m_nPerson;                     //人物出现的索引
	CRect m_GridRC;                //表格区域
	CRect m_PersonRC;             //人物出现的区域
	BOOL   m_bStart;                //游戏是否开始
	GameState m_State;             //游戏状态
	BOOL m_bHit;                     //是否击中人物
	int m_nLevels[100];              //游戏级别
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void NextLevel(void);
	void OnStart(void);
	void OnEndgame(void);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedEndgame();
};
