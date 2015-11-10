
// MFCApplication5View.cpp : реализаци€ класса CMFCApplication5View
//

#include "stdafx.h"

#include "Dialog.h"
#include <vector>
using namespace std;
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позвол€ет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

COLORREF color = RGB(100, 0, 0);

// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CView)
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// создание/уничтожение CMFCApplication5View

CMFCApplication5View::CMFCApplication5View()
{
	// TODO: добавьте код создани€

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменени€
	//  CREATESTRUCT cs
	//ID_VIEW_TOOLBAR
	
	return CView::PreCreateWindow(cs);
}

// рисование CMFCApplication5View

void CMFCApplication5View::OnDraw(CDC* pDC)
{
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки дл€ собственных данных
	CRect rect;
	GetClientRect(rect);
	/*if (b >= rect.bottom)
	b = rect.bottom;
	if (a >= rect.right)
	a = rect.right;
	pDC->Rectangle(0, 0, a, b);*/

	int x;

	//int start = 0;
	if (pDoc->v.size() != 0)
	{
		x = rect.right / pDoc->v.size();
		/*for (int startx = 0, endx = x; endx <= pDoc->n*x; startx += x, endx += x)
		{
		pDC->Rectangle(startx, 0, endx, rect.bottom);
		}*/
		int startx = 0, endx = x;

		for (vector<int>::iterator it = pDoc->v.begin(); it != pDoc->v.end(); ++it)
		{
			CBrush myBrush(color);
			pDC->SelectObject(myBrush);
			pDC->Rectangle(startx, rect.bottom - (*it), endx, rect.bottom);
			startx += x;
			endx += x;
			int r, g, b;
			r = GetRValue(color);
			g = GetGValue(color);
			b = GetBValue(color);
			r += 20;
			g += 50;
			b += 10;
			color = RGB(r, g, b);

		}
	}
}

void CMFCApplication5View::OnRButtonUp(UINT /* nFlags */, CPoint /*point*/)
{
	CMFCApplication5Doc* pDoc = GetDocument();
	//ClientToScreen(&point);
	//OnContextMenu(this, point);

	CMyDialog dlg;
	dlg.a = 100;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->v.push_back(dlg.a);
		pDoc->UpdateAllViews(NULL);
		pDoc->SetModifiedFlag(1);
		//InvalidateRect(NULL);
	}
}

// диагностика CMFCApplication5View

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // встроена неотлаженна€ верси€
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMFCApplication5View
