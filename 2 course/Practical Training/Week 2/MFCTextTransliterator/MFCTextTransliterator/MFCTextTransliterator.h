
// MFCTextTransliterator.h : главный файл заголовка для приложения MFCTextTransliterator
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCTextTransliteratorApp:
// О реализации данного класса см. MFCTextTransliterator.cpp
//

class CMFCTextTransliteratorApp : public CWinApp
{
public:
	CMFCTextTransliteratorApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCTextTransliteratorApp theApp;
