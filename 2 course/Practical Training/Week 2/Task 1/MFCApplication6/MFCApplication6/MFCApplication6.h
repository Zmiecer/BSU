
// MFCApplication6.h : главный файл заголовка для приложения MFCApplication6
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMyApp:
// О реализации данного класса см. MFCApplication6.cpp
//

class CMyApp : public CWinApp
{
public:
	CMyApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyApp theApp;
