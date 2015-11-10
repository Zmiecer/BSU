#undef UNICODE
#include <windows.h>
#include <Winuser.h>
#include <cstdio>
#define _AFXDLL
#define FIRST_TIMER 1
int nTimerID;

INT x = 800, y = 600, k = 0, j = 12;
INT c = 0;
CHAR s1[100];
CHAR strj[4];
RECT rect;
unsigned int key;

INT kz=0, temp=0;
BOOL t = 1;
LPARAM lparam;
MSG msg = { 0 };


HFONT hfont;
PAINTSTRUCT ps;
LOGFONT font;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "TIMER";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	/*���� �������� hPrevInstance � Win32 ������ ����� NULL���������� ��������� ��� �������� */
	if (!hPrevInstance)
	{  /* �������������� ���������� -  �������������� ������ ������ ���� � ������������ ��� */
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	/* ��������� �������� ����� ���������� -     ������� ������� ���� ���������� */
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	/* ���� ��������� ��������� */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}

BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS  wc;
	// ��������� ��������� ������ ���� WNDCLASS
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	// ������������ ����� ����
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // ��������� �� ������ ������������������� ����� ������
		szTitle,			 // ��������� �� ������ ��������� ����
		WS_OVERLAPPEDWINDOW, // ����� ����
		300,       // �������������� ���������� ����
		100,       // ������������ ���������� ����
		x,       // ������ ����
		y,       // ������ ����
		NULL,                // ���������� ������������� ����
		NULL,                // ���������� ���� ����
		hInstance,           // ���������� ���������� ����������
		NULL);               // ��������� �� �������������� ������ ����

	if (!hWnd)    return (FALSE);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);
	return (TRUE);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	SelectObject(ps.hdc, hfont);
	char szText[] = "";

	font.lfHeight = 100;

	hfont = ::CreateFontIndirect(&font);
	SelectObject(ps.hdc, hfont);
	
	RegisterHotKey(hwnd, 2, MOD_CONTROL | MOD_NOREPEAT, 83);

	switch (message)
	{
	case WM_CREATE:

		nTimerID = SetTimer(hwnd, FIRST_TIMER, 1000, NULL);
		break;

	
	case WM_PAINT:
		GetClientRect(hwnd, &rect);
		hDC = BeginPaint(hwnd, &ps);
		SelectObject(ps.hdc, hfont);
		sprintf_s(s1, "%d", k);
		TextOut(hDC, rect.right / 2, rect.bottom / 2, s1, 2);
		EndPaint(hwnd, &ps);
		break;

	case WM_HOTKEY:
		k = 0;
		InvalidateRect(hwnd, &rect, NULL);
		break;

	case WM_TIMER:
		k++;
		InvalidateRect(hwnd, &rect, NULL);
		break;

	case WM_KEYDOWN:
		key = wParam;
		
		switch (key)
		{
		/*case 0x53://83://0x11: //Ctrl+S
			k = 0;
			InvalidateRect(hwnd, &rect, NULL);
			break;*/
		/*while (GetMessage(&msg, NULL, 0, 0) != 0)
		{
			if (msg.message == WM_HOTKEY)
			{
				k = 0;
				break;
			}
		}
		*/
		case 0x6B: //+
			nTimerID = SetTimer(hwnd, FIRST_TIMER, 1000, NULL);
			InvalidateRect(hwnd, &rect, NULL);
			break;
		case 0x6D: //-
			KillTimer(hwnd, FIRST_TIMER);
			InvalidateRect(hwnd, &rect, NULL);
			break;
		}
		break;

	case WM_DESTROY:
		KillTimer(hwnd, FIRST_TIMER);
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}