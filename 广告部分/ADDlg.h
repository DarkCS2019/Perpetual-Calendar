
// ADDlg.h : 头文件
//

#pragma once


// CADDlg 对话框
class CADDlg : public CDialogEx
{
// 构造
public:
	CADDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	CBrush m_brush;

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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnStnClickedText1();
	afx_msg void OnStnClickedText2();
	afx_msg void OnStnClickedText3();
	afx_msg void OnStnClickedText4();
	afx_msg void OnStnClickedText5();
	afx_msg void OnStnClickedText6();
	afx_msg void OnStnClickedText7();

	afx_msg void OnBnClickedOk();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
