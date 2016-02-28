
// MFCTextTransliteratorView.h : интерфейс класса CLeftView
//

#pragma once

#include "resource.h"

class CMFCTextTransliteratorDoc;
class CLeftView : public CFormView
{
protected: // создать только из сериализации
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

public:
	enum{ IDD = IDD_MFCTEXTTRANSLITERATOR_FORM };

// Атрибуты
public:
	CMFCTextTransliteratorDoc* GetDocument() const;
	CString text;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // отладочная версия в MFCTextTransliteratorView.cpp
inline CMFCTextTransliteratorDoc* CLeftView::GetDocument() const
   { return reinterpret_cast<CMFCTextTransliteratorDoc*>(m_pDocument); }
#endif

