
// MFCApplication3.h : ������� ���� ��������� ��� ���������� MFCApplication3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMyApp:
// � ���������� ������� ������ ��. MFCApplication3.cpp
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
