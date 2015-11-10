#undef UNICODE
#include <windows.h>
#include <cmath>
#include <math.h>
#define FIRST_TIMER 1
int nTimerID;

INT xs = 800, ys = 600;
RECT rect;
PAINTSTRUCT ps;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "�������";

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
		xs,       // ������ ����
		ys,       // ������ ����
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
	HPEN hPen;
	static int x1, x2, y1, y2, k, x, y, i, j, m, n;


	switch (message)
	{

	case WM_CREATE:
		nTimerID = SetTimer(hwnd, FIRST_TIMER, 50, NULL);
		x = rect.left - 100;
		y = rect.bottom - 100;
		k = 0;
		i = 0;
		j = 50;
		m = 0;
		n = 0;
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rect);
		hDC = BeginPaint(hwnd, &ps);

		hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
		SelectObject(hDC, hPen);
		Ellipse(hDC, x - 50, 50 * sin(x * 5) + 250, x + 150, 50 * sin(x * 5) + 450);
		DeleteObject(hPen);

		hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		SelectObject(hDC, hPen);
		Ellipse(hDC, x, 50 * sin(x * 5) + 300, x + 100, 50 * sin(x * 5) + 400);
		MoveToEx(hDC, x + 50, 50 * sin(x * 5) + 350, 0);
		LineTo(hDC, x + i, 50 * sin(x * 5) + 300 + j);
		if (x + 100 >= rect.right)
			k = 1;
		if (x <= rect.left)
			k = 0;
		if (i == 100)
			m = 1;
		if (i == 0)
			m = 0;
		if (j == 100)
			n = 1;
		if (j == 0)
			n = 0;
		DeleteObject(hPen);

		EndPaint(hwnd, &ps);
		break;

	case WM_TIMER:
		if (k == 0)
			x += 5;
		else
			x -= 5;
		if (m == 0)
			i++;
		else
			i--;
		if (n == 0)
			j++;
		else
			j--;
		InvalidateRect(hwnd, &rect, NULL);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}