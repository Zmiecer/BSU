
// MFCTextTransliterator.h : ������� ���� ��������� ��� ���������� MFCTextTransliterator
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMFCTextTransliteratorApp:
// � ���������� ������� ������ ��. MFCTextTransliterator.cpp
//

class CMFCTextTransliteratorApp : public CWinApp
{
public:
	CMFCTextTransliteratorApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCTextTransliteratorApp theApp;
