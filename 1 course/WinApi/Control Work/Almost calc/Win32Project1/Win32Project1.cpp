// Win32Project1.cpp : Defines the entry point for the application.
//
#undef UNICODE

#include "stdafx.h"
#include "Win32Project1.h"
#include <fstream>
#include <sstream>
#include <cmath>

DWORD dwBytes;
#define MAX_LOADSTRING 100

RECT rect;

char str[10];
static int c = 0, f = 0, s = 0;

std::ofstream file;

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
	LoadString(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT1);
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
	HANDLE hFile = CreateFile("out.txt", GENERIC_READ | GENERIC_WRITE,  FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	switch (message)
	{
	case WM_CREATE:
		file.open("out1.txt");
		break;

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			InvalidateRect(hWnd, &rect, 0);
			break;
		case IDM_EXIT:
			//file << "Hello world!";
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		GetClientRect(hWnd, &rect);
		hdc = BeginPaint(hWnd, &ps);
		sprintf_s(str, "%d", s, "          ");
		if (c == 1) TextOut(hdc, 100, 100, str, 10);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		file.close();
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
	
	static int a, b;
	static int k, m, n;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		k = 0;
		c = 0;
		f = 0;
		//CheckRadioButton(hDlg, IDC_RADIO1, IDC_RADIO3, IDC_RADIO1);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_RADIO1:
			k = 1;
			break;

		case IDC_RADIO2:
			k = 2;
			break;

		case IDC_RADIO3:
			k = 3;
			break;

		case IDC_BUTTON1:
			a = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 1);
			b = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 1);
			switch (k)
			{
			case 1:
				s = a + b;
				break;
			case 2:
				s = a - b;
				break;
			case 3:
				s = a * b;
				break;
			}
			sprintf_s(str, "%d", s, "           ");
			SetWindowText(GetDlgItem(hDlg, IDC_EDIT3), str);
			break;

		case IDC_BUTTON2:
			SendDlgItemMessage(hDlg, IDC_EDIT1, EM_SETSEL, 0, 10);
			SendDlgItemMessage(hDlg, IDC_EDIT1, WM_CLEAR, 0, 0);
			SendDlgItemMessage(hDlg, IDC_EDIT2, EM_SETSEL, 0, 10);
			SendDlgItemMessage(hDlg, IDC_EDIT2, WM_CLEAR, 0, 0);
			SendDlgItemMessage(hDlg, IDC_EDIT3, EM_SETSEL, 0, 10);
			SendDlgItemMessage(hDlg, IDC_EDIT3, WM_CLEAR, 0, 0);
			CheckRadioButton(hDlg, IDC_RADIO1, IDC_RADIO3, NULL);
			break;

		case IDC_CHECK1:
			if (c == 0) c = 1;
			else c = 0;
			break;

		case IDC_CHECK2:
			if (f == 0) f = 1;
			else f = 0;
			break;
		}

		if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, LOWORD(wParam));
			if (f == 1)
			{
				file << str;
			}
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
