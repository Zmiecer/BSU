
// MFCApplication6.h : ������� ���� ��������� ��� ���������� MFCApplication6
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMyApp:
// � ���������� ������� ������ ��. MFCApplication6.cpp
//

class CMyApp : public CWinApp
{
public:
	CMyApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyApp theApp;
