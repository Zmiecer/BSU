// RightView.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication3.h"
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
	DDX_Control(pDX, IDC_MSFLEXGRID1, grid);
	
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
#endif //_DEBUG


// CRightView message handlers
BEGIN_EVENTSINK_MAP(CRightView, CFormView)
	ON_EVENT(CRightView, IDC_MSFLEXGRID1, DISPID_KEYUP, CRightView::KeyUpMsflexgrid1, VTS_PI2 VTS_I2)
END_EVENTSINK_MAP()


void CRightView::KeyUpMsflexgrid1(short* KeyCode, short Shift)
{
	// TODO: Add your message handler code here

	int x = _ttoi(grid.get_Text());
	if (*KeyCode >= 48 && *KeyCode <= 57)
	{
		x *= 10;
		x += *KeyCode - 48;
	}
	if (*KeyCode == 189 && grid.get_Text() != "")
	{
		x *= -1;
	}
	if (*KeyCode == 8)
	{
		x /= 10;
	}
	CString tmp;
	tmp.Format(_T("%d"), x);
	grid.put_Text(tmp);
	//GetDocument()->arr.insert(std::make_pair(std::make_pair(grid.get_Row(), grid.get_Col()), x));
	GetDocument()->arr[std::make_pair(grid.get_Row(), grid.get_Col())] = x;

	if (*KeyCode == 46)
	{
		CString tmp = _T("");
		grid.put_Text(tmp);

		GetDocument()->arr.erase(std::make_pair(grid.get_Row(), grid.get_Col()));
	}

	GetDocument()->UpdateAllViews(this);
}

CMyDoc* CRightView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}


void CRightView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class

	grid.Clear();
	GetDocument()->UpdateAllViews(0);
}


void CRightView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: Add your specialized code here and/or call the base class

	//grid.Clear();
	if (!GetDocument()->arr.empty())
	{
		//grid.put_Rows(GetDocument()->arr.rbegin()->first.first);
		//grid.put_Cols(GetDocument()->arr.rbegin()->first.second);
		for (std::map<std::pair<int, int>, int>::iterator it = GetDocument()->arr.begin(); it != GetDocument()->arr.end(); ++it)
		{
			it->first.first;
			CString tmp;
			tmp.Format(_T("%d"), it->second);
			grid.put_TextMatrix(it->first.first, it->first.second, tmp);
		}
	}
}
