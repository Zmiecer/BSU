
// MFCApplication3.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFCApplication3App:
// � ���������� ������� ������ ��. MFCApplication3.cpp
//

class CMFCApplication3App : public CWinApp
{
public:
	CMFCApplication3App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication3App theApp;