// RightView.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTextTransliterator.h"
#include "RightView.h"


// CRightView

IMPLEMENT_DYNCREATE(CRightView, CFormView)

CRightView::CRightView()
	: CFormView(CRightView::IDD)
{

}

CRightView::~CRightView()
{
}

void CRightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, text);
	DDX_Control(pDX, IDC_EDIT1, edit);
}

BEGIN_MESSAGE_MAP(CRightView, CFormView)
END_MESSAGE_MAP()


// CRightView diagnostics

#ifdef _DEBUG
void CRightView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CRightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif

CMFCTextTransliteratorDoc* CRightView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTextTransliteratorDoc)));
	return (CMFCTextTransliteratorDoc*)m_pDocument;
}

#endif //_DEBUG


// CRightView message handlers


void CRightView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: Add your specialized code here and/or call the base class
	edit.SetWindowText(text);
	text = GetDocument()->text;
}
