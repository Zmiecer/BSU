
// MFCApplication5.h : ������� ���� ��������� ��� ���������� MFCApplication5
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMFCApplication5App:
// � ���������� ������� ������ ��. MFCApplication5.cpp
//

class CMFCApplication5App : public CWinApp
{
public:
	CMFCApplication5App();


// ���������������
public:
	virtual BOOL InitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication5App theApp;
