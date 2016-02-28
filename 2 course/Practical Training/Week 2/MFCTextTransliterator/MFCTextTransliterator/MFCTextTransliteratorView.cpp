
// MFCTextTransliteratorView.cpp : ���������� ������ CLeftView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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

// ��������/����������� CLeftView

CLeftView::CLeftView()
	: CFormView(CLeftView::IDD)
{
	// TODO: �������� ��� ��������

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
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CLeftView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// ����������� CLeftView

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFCTextTransliteratorDoc* CLeftView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTextTransliteratorDoc)));
	return (CMFCTextTransliteratorDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CLeftView


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
