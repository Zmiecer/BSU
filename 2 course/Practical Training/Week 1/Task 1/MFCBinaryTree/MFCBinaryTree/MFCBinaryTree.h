
// MFCBinaryTree.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFCBinaryTreeApp:
// � ���������� ������� ������ ��. MFCBinaryTree.cpp
//

class CMFCBinaryTreeApp : public CWinApp
{
public:
	CMFCBinaryTreeApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFCBinaryTreeApp theApp;