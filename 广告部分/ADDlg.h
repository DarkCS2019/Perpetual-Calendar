
// ADDlg.h : ͷ�ļ�
//

#pragma once


// CADDlg �Ի���
class CADDlg : public CDialogEx
{
// ����
public:
	CADDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	CBrush m_brush;

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
