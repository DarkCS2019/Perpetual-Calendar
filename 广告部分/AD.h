
// AD.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CADApp: 
// �йش����ʵ�֣������ AD.cpp
//

class CADApp : public CWinApp
{
public:
	CADApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CADApp theApp;