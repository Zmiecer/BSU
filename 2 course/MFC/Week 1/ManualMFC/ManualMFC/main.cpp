#include <afxwin.h>
#include <afxdlgs.h>
#include <afxcolordialog.h>
#include <math.h>
#include "resource.h"
#include "Dialog.h"






class CMyWin : public CFrameWnd
{
	int a;
public:
	CMyWin();
	void OnPaint();
	void OnRButtonDown(UINT,CPoint);
	void OnLButtonDown(UINT, CPoint);
	void OnTimer(UINT);
	COLORREF color = RGB(255, 255, 255);
	COLORREF initcolor = RGB(255, 255, 255);
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMyWin,CFrameWnd)
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

CMyWin::CMyWin()
{
	Create(NULL,TEXT("Рамочка"));
	a=100;
	SetTimer(13, 1000, NULL);
};

void CMyWin::OnPaint()
{
	double f = a;
	CPaintDC dc(this);
	CRect Rect;
	GetClientRect(&Rect);
	int minimum;
	minimum = min(Rect.bottom, Rect.right);
	int n = minimum - a;
	
	for (int i = 0; i <= n; i+=a)
	{
		CBrush myBrush(color);
		dc.SelectObject(myBrush);
		dc.Rectangle(0 + 10, i + 10, a + 10, a + i + 10);
		dc.Rectangle(i + 10, 0 + 10, a + i + 10, a + 10);

		f = ((n / a) + 1)*a;
		dc.Rectangle(i + 10, f - a + 10, a + i + 10, f + 10);
		dc.Rectangle(f - a + 10, i + 10, f + 10, a + i + 10);


		char str[100];
		//ltoa(a, str, 10);
		sprintf_s(str, "Длина стороны квадрата (a): %d", a);
		//dc.TextOutW(900, 100, "Длина стороны квадрата (a): ");
		dc.TextOutW(Rect.right - 300, 100, str);
	}
};

void CMyWin::OnRButtonDown(UINT,CPoint)
{
	CMyDialog dlg;
	dlg.a=a;
	if (dlg.DoModal()==IDOK)
	{
		a=dlg.a;
		InvalidateRect(NULL);
	};
};

void CMyWin::OnLButtonDown(UINT, CPoint)
{
	/*CColorDialog clrdlg;
	clrdlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	clrdlg.m_cc.rgbResult = initcolor;
	if (clrdlg.DoModal() == IDOK)
	{
		color = clrdlg.GetColor();
		initcolor = clrdlg.GetColor();
		InvalidateRect(NULL);
	};*/

	CMFCColorDialog clrdlg1;
	clrdlg1.SetCurrentColor(color);
	if (clrdlg1.DoModal() == IDOK)
	{
		color = clrdlg1.GetColor();
		InvalidateRect(NULL);
	};
};


void CMyWin::OnTimer(UINT)
{
	int r, g, b;
	r = GetRValue(color);
	g = GetGValue(color);
	b = GetBValue(color);

	if (r <= 245)
		r += 10;
	if (g <= 245)
		g += 10;
	if (b <= 245)
		b += 10;

	color = RGB(r, g, b);
	InvalidateRect(NULL);
};

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

BOOL CMyApp::InitInstance()
{
	
	m_pMainWnd = new CMyWin();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
};

CMyApp MyApp;