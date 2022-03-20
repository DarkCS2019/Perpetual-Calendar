
// ADDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CADDlg �Ի���



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


// CADDlg ��Ϣ�������

CString title[7];
CString url[7];
BOOL CADDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	// ����Ĵ��룬 ���ⲿ�ļ��ж�ȡ���ݣ����õ�������
	
	ifstream file;
	file.open("ads.dat");
	m_brush.CreateSolidBrush(RGB(255, 255, 102));

	CFont font;
	font.CreatePointFont(150, _T("����"));
	if (!file.is_open())
	{
		// ���û�д򿪹���ļ�����ֱ�ӽ���Ӧ��
		//CDialogEx::OnOK();
	}
	else
	{		
		int i = 0;
		// ��ʾ�������

		for (; i < 7 && !file.eof(); i++)
		{
			// �ӹ���ļ��ж�ȡ��Ϣ����ŵ�������
			char tmp1[100];
			char tmp2[100];
			file.getline(tmp1,100);
			title[i] = CString(tmp1);
			file.getline(tmp2, 100);
			url[i] = CString(tmp2);
		}

		// ����ȡ�������ݷŽ�static��
		GetDlgItem(TEXT1)->SetWindowText(LPCTSTR(title[0]));
		GetDlgItem(TEXT2)->SetWindowText(LPCTSTR(title[1]));
		GetDlgItem(TEXT3)->SetWindowText(LPCTSTR(title[2]));
		GetDlgItem(TEXT4)->SetWindowText(LPCTSTR(title[3]));
		GetDlgItem(TEXT5)->SetWindowText(LPCTSTR(title[4]));
		GetDlgItem(TEXT6)->SetWindowText(LPCTSTR(title[5]));
		GetDlgItem(TEXT7)->SetWindowText(LPCTSTR(title[6]));


	}
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CADDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CADDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CADDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CADDlg::OnStnClickedText1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(0, NULL, LPCTSTR(url[0]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(0, NULL, LPCTSTR(url[1]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(0, NULL, LPCTSTR(url[2]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(0, NULL, LPCTSTR(url[3]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(0, NULL, LPCTSTR(url[4]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(0, NULL, LPCTSTR(url[5]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnStnClickedText7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(0, NULL, LPCTSTR(url[6]), NULL, NULL, SW_NORMAL);
}


void CADDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ret;
	ret = AfxMessageBox(_T("��ȷ��Ҫ���Ĺرչ����ʾ��"), MB_ICONQUESTION | MB_YESNOCANCEL);
	if (ret == IDYES)
	{
		// �����û�ѡ���˹ر���ʾ��Ȼ�����ᷢ���κθı�
		AfxMessageBox(_T("�ðɣ����ǽ��ر�һ��ʱ��Ĺ����ʾ"), MB_OK);
		CDialogEx::OnOK();
	}
	else if (ret == IDNO)
	{
		// �û���Ҫ�ٿ������
	}
	else
	{
		// ʲôҲû����
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
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return m_brush;
}
