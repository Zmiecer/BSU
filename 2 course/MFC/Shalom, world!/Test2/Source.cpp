#include <afxwin.h>

class MyWin : public CFrameWnd
{
public:
	MyWin(char*);
};

MyWin::MyWin(char* title)
{
	Create(NULL, title);
}

class MyApp :CWinApp
{
public:
	BOOL InitInstance();
};

BOOL MyApp::InitInstance()
{
	m_pMainWnd = new MyWin("Shalom, world!");
	m_pMainWnd->ShowWindow(SW_NORMAL);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

MyApp app;