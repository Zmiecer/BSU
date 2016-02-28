
// MFCBinaryTree.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCBinaryTreeApp:
// О реализации данного класса см. MFCBinaryTree.cpp
//

class CMFCBinaryTreeApp : public CWinApp
{
public:
	CMFCBinaryTreeApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCBinaryTreeApp theApp;