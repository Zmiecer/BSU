
// MFCTextTransliteratorView.cpp : реализация класса CLeftView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCTextTransliterator.h"
#endif

#include "MFCTextTransliteratorDoc.h"
#include "MFCTextTransliteratorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CFormView)

BEGIN_MESSAGE_MAP(CLeftView, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &CLeftView::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLeftView::OnBnClickedButton1)
END_MESSAGE_MAP()

// создание/уничтожение CLeftView

CLeftView::CLeftView()
	: CFormView(CLeftView::IDD)
{
	// TODO: добавьте код создания

}

CLeftView::~CLeftView()
{
}

void CLeftView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, text);
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CLeftView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// диагностика CLeftView

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCTextTransliteratorDoc* CLeftView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTextTransliteratorDoc)));
	return (CMFCTextTransliteratorDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CLeftView


void CLeftView::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	GetDocument()->text = text;
	GetDocument()->UpdateAllViews(0);
	
}


void CLeftView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	GetDocument()->UpdateAllViews(0);
}
