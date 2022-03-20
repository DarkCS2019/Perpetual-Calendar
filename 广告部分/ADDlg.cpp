
// ADDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AD.h"
#include "ADDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <iostream>
#include "locale.h"
#include <string>

#include <sstream>

using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW

#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CADDlg 对话框



CADDlg::CADDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	setlocale(LC_ALL, "chs");
}

void CADDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CADDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CADDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDCANCEL, &CADDlg::OnBnClickedCancel)
	ON_STN_CLICKED(TEXT1, &CADDlg::OnStnClickedText1)
	ON_STN_CLICKED(TEXT2, &CADDlg::OnStnClickedText2)
	ON_STN_CLICKED(TEXT3, &CADDlg::OnStnClickedText3)
	ON_STN_CLICKED(TEXT4, &CADDlg::OnStnClickedText4)
	ON_STN_CLICKED(TEXT5, &CADDlg::OnStnClickedText5)
	ON_STN_CLICKED(TEXT6, &CADDlg::OnStnClickedText6)
	ON_STN_CLICKED(TEXT7, &CADDlg::OnStnClickedText7)
	ON_BN_CLICKED(IDOK, &CADDlg::OnBnClickedOk)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CADDlg 消息处理程序

CString title[7];
CString url[7];
BOOL CADDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	// 额外的代码， 从外部文件中读取内容，放置到界面中
	
	ifstream file;
	file.open("ads.dat");
	m_brush.CreateSolidBrush(RGB(255, 255, 102));

	CFont font;
	font.CreatePointFont(150, _T("宋体"));
	if (!file.is_open())
	{
		// 如果没有打开广告文件，则直接结束应用
		//CDialogEx::OnOK();
	}
	else
	{		
		int i = 0;
		// 显示七条广告

		for (; i < 7 && !file.eof(); i++)
		{
			// 从广告文件中读取信息，存放到数组里
			char tmp1[100];
			char tmp2[100];
			file.getline(tmp1,100);
			title[i] = CString(tmp1);
			file.getline(tmp2, 100);
			url[i] = CString(tmp2);
		}

		// 将读取到的内容放进static中
		GetDlgItem(TEXT1)->SetWindowText(LPCTSTR(title[0]));
		GetDlgItem(TEXT2)->SetWindowText(LPCTSTR(title[1]));
		GetDlgItem(TEXT3)->SetWindowText(LPCTSTR(title[2]));
		GetDlgItem(TEXT4)->SetWindowText(LPCTSTR(title[3]));
		GetDlgItem(TEXT5)->SetWindowText(LPCTSTR(title[4]));
		GetDlgItem(TEXT6)->SetWindowText(LPCTSTR(title[5]));
		GetDlgItem(TEXT7)->SetWindowText(LPCTSTR(title[6]));


	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CADDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CADDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CADDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CADDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CADDlg::OnStnClickedText1()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, LPCTSTR(url[0]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText2()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, LPCTSTR(url[1]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText3()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, LPCTSTR(url[2]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText4()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, LPCTSTR(url[3]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText5()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, LPCTSTR(url[4]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText6()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, LPCTSTR(url[5]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText7()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, LPCTSTR(url[6]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret;
	ret = AfxMessageBox(_T("您确认要狠心关闭广告显示吗？"), MB_ICONQUESTION | MB_YESNOCANCEL);
	if (ret == IDYES)
	{
		// 尽管用户选择了关闭显示，然而不会发生任何改变
		AfxMessageBox(_T("好吧，我们将关闭一段时间的广告显示"), MB_OK);
		CDialogEx::OnOK();
	}
	else if (ret == IDNO)
	{
		// 用户还要再看看广告
	}
	else
	{
		// 什么也没发生
	}
	
}


HBRUSH CADDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd->GetDlgCtrlID() == TEXT1)
	{
		pDC->SetBkColor(RGB(255, 255, 102));
		return m_brush;
	}
	if (pWnd->GetDlgCtrlID() == TEXT2)
	{
		pDC->SetBkColor(RGB(255, 255, 102));
		return m_brush;
	}
	if (pWnd->GetDlgCtrlID() == TEXT3)
	{
		pDC->SetBkColor(RGB(255, 255, 102));
		return m_brush;
	}
	if (pWnd->GetDlgCtrlID() == TEXT4)
	{
		pDC->SetBkColor(RGB(255, 255, 102));
		return m_brush;
	}
	if (pWnd->GetDlgCtrlID() == TEXT5)
	{
		pDC->SetBkColor(RGB(255, 255, 102));
		return m_brush;
	}
	if (pWnd->GetDlgCtrlID() == TEXT6)
	{
		pDC->SetBkColor(RGB(255, 255, 102));
		return m_brush;
	}
	if (pWnd->GetDlgCtrlID() == TEXT7)
	{
		pDC->SetBkColor(RGB(255, 255, 102));
		return m_brush;
	}
	if (pWnd->GetDlgCtrlID() == TEXT8)
	{
		pDC->SetBkColor(RGB(255, 255, 102));
		return m_brush;
	}
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return m_brush;
}
