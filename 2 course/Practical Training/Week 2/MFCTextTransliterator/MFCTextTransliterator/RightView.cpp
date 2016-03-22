// RightView.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTextTransliterator.h"
#include "RightView.h"
#include <fstream>
#include <map>

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
using namespace std;

void CRightView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: Add your specialized code here and/or call the base class
	
	ifstream fin;
	fin.open("rules.txt");
	//map<int, int> mp;
	int itmp, stmp;
	while (fin)
	{
		fin >> itmp >> stmp;
		mp[itmp] = stmp;
	}
	fin.close();

	//CString str = GetDocument()->text;
	CString tmp = transliterate(GetDocument()->text);
	
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT1, tmp);
	GetDocument()->SetModifiedFlag(true);
}

CString CRightView::transliterate(CString str)
{
	CString tmp = _T("");
	for (int i = 0; i < str.GetLength(); i++)
	{
		if (str[i] >= 1072 && str[i] <= 1103)
			tmp.Insert(i, mp[str[i]]);
		else
			if (str[i] >= 1040 && str[i] <= 1071)
				tmp.Insert(i, (mp[str[i] + 32] - 32));
			else
				tmp.Insert(i, str[i]);
	}
	return tmp;
}

void CRightView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	GetDocument()->SetModifiedFlag(false);
}
