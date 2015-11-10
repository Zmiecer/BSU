
// MFCApplication5.h : главный файл заголовка для приложения MFCApplication5
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCApplication5App:
// О реализации данного класса см. MFCApplication5.cpp
//

class CMFCApplication5App : public CWinApp
{
public:
	CMFCApplication5App();


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication5App theApp;
