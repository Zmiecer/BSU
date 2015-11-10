// Win32Project2.cpp : Defines the entry point for the application.
//
//#undef UNICODE
#include "stdafx.h"
#include "Win32Project2.h"
#define FIRST_TIMER 1
int nTimerID;

INT x = 800, y = 600;
RECT rect;
PAINTSTRUCT ps;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT2);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hBrush;
	HPEN hPen;
	COLORREF col;
	static int x11, x12, x21, x22, x31, x32, y11, y12, y21, y22, y31, y32, a, b, c, u, v, k, l, m;
	static char click;


	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{

		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		case ID_MIG_1:
			if (k == 0)
				k = 1;
			else k = 0;
			InvalidateRect(hWnd, &rect, 0);
			break;

		case ID_MIG_2:
			if (l == 0)
				l = 1;
			else l = 0;
			InvalidateRect(hWnd, &rect, 0);
			break;

		case ID_MIG_3:
			if (m == 0)
				m = 1;
			else m = 0;
			InvalidateRect(hWnd, &rect, 0);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_CREATE:
		nTimerID = SetTimer(hWnd, FIRST_TIMER, 300, NULL);
		x11 = 50;
		x12 = 200;
		y11 = 100;
		y12 = 250;

		x21 = 300;
		x22 = 450;
		y21 = 100;
		y22 = 250;

		x31 = 550;
		x32 = 700;
		y31 = 100;
		y32 = 250;


		a = 0;
		b = 0;
		c = 0;

		u = 0;
		v = 0;

		k = 0;
		l = 0;
		m = 0;
		break;


	case WM_PAINT:
		GetClientRect(hWnd, &rect);
		hdc = BeginPaint(hWnd, &ps);


		col = GetPixel(hdc, u, v);
		if (col == RGB(255, 0, 0))
		{
			if (click == 'l')
				k = 1;
			else k = 0;
		}
		if (col == RGB(0, 255, 0))
		{
			if (click == 'l')
				l = 1;
			else l = 0;
		}
		if (col == RGB(0, 0, 255))
		{
			if (click == 'l')
				m = 1;
			else m = 0;
		}



		if (a == 0)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			SelectObject(hdc, hPen);
			Ellipse(hdc, x11 - 50, y11 - 50, x12 + 50, y12 + 50);
			DeleteObject(hBrush);
			DeleteObject(hPen);

			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			SelectObject(hdc, hPen);
			Ellipse(hdc, x11, y11, x12, y12);
			DeleteObject(hBrush);
			DeleteObject(hPen);
		}
		else
		{
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);
			Ellipse(hdc, x11 - 50, y11 - 50, x12 + 50, y12 + 50);
			DeleteObject(hBrush);
		}


		if (b == 0)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			SelectObject(hdc, hPen);
			Ellipse(hdc, x21 - 50, y21 - 50, x22 + 50, y22 + 50);
			DeleteObject(hBrush);
			DeleteObject(hPen);

			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			SelectObject(hdc, hPen);
			Ellipse(hdc, x21, y21, x22, y22);
			DeleteObject(hBrush);
			DeleteObject(hPen);
		}
		else
		{
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hBrush);
			Ellipse(hdc, x21 - 50, y21 - 50, x22 + 50, y22 + 50);
			DeleteObject(hBrush);
		}

		if (c == 0)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			SelectObject(hdc, hPen);
			Ellipse(hdc, x31 - 50, y31 - 50, x32 + 50, y32 + 50);
			DeleteObject(hBrush);
			DeleteObject(hPen);

			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			SelectObject(hdc, hPen);
			Ellipse(hdc, x31, y31, x32, y32);
			DeleteObject(hBrush);
			DeleteObject(hPen);
		}
		else
		{
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hBrush);
			Ellipse(hdc, x31 - 50, y31 - 50, x32 + 50, y32 + 50);
			DeleteObject(hBrush);
		}
		EndPaint(hWnd, &ps);
		break;


	case WM_TIMER:
		if (k == 1)
		{
			if (a == 1)
			{
				a = 0;
			}
			else a = 1;
		}

		if (l == 1)
		{
			if (b == 1)
			{
				b = 0;
			}
			else b = 1;
		}

		if (m == 1)
		{
			if (c == 1)
			{
				c = 0;
			}
			else c = 1;
		}
		InvalidateRect(hWnd, &rect, NULL);
		break;

	case WM_LBUTTONDOWN:
		u = LOWORD(lParam);
		v = HIWORD(lParam);
		click = 'l';
		InvalidateRect(hWnd, &rect, NULL);
		break;

	case WM_RBUTTONDOWN:
		u = LOWORD(lParam);
		v = HIWORD(lParam);
		click = 'r';
		InvalidateRect(hWnd, &rect, NULL);
		break;

	case WM_DESTROY:
		KillTimer(hWnd, FIRST_TIMER);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}
