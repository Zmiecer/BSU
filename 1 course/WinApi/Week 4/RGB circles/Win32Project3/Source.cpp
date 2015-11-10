#undef UNICODE
#include <windows.h>
#include <cmath>
#include <math.h>
#define FIRST_TIMER 1
int nTimerID;


INT x = 800, y = 600;
RECT rect;
PAINTSTRUCT ps;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "Круги";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	/*хотя параметр hPrevInstance в Win32 всегда равно NULLпродолжаем проверять его значение */
	if (!hPrevInstance)
	{  /* инициализируем приложение -  подготавливаем данные класса окна и регистрируем его */
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	/* завершаем создание копии приложения -     создаем главное окно приложения */
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	/* Цикл обработки сообщений */
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
	// Заполняем структуру класса окна WNDCLASS
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
	// Регистрируем класс окна
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // указатель на строку зарегистрированного имени класса
		szTitle,			 // указатель на строку заголовка окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		300,       // горизонтальная координата окна
		100,       // вертикальная координата окна
		x,       // ширина окна
		y,       // высота окна
		NULL,                // дескриптор родительского окна
		NULL,                // дескриптор меню окна
		hInstance,           // дескриптор экземпляра приложения
		NULL);               // указатель на дополнительные данные окна

	if (!hWnd)    return (FALSE);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);
	return (TRUE);
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	HBRUSH hBrush;
	HPEN hPen;
	COLORREF col;
	static int x11, x12, x21, x22, x31, x32, y11, y12, y21, y22, y31, y32,		a, b, c,		u, v,		k, l, m;
	static char click;
	

	switch (message)
	{

	case WM_CREATE:
		nTimerID = SetTimer(hwnd, FIRST_TIMER, 500, NULL);
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
		GetClientRect(hwnd, &rect);
		hDC = BeginPaint(hwnd, &ps);


		col = GetPixel(hDC, u, v);
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
			SelectObject(hDC, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			SelectObject(hDC, hPen);
			Ellipse(hDC, x11 - 50, y11 - 50, x12 + 50, y12 + 50);
			DeleteObject(hBrush);
			DeleteObject(hPen);

			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hDC, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			SelectObject(hDC, hPen);
			Ellipse(hDC, x11, y11, x12, y12);
			DeleteObject(hBrush);
			DeleteObject(hPen);
		}
		else
		{
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hDC, hBrush);
			Ellipse(hDC, x11 - 50, y11 - 50, x12 + 50, y12 + 50);
			DeleteObject(hBrush);
		}


		if (b == 0)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hDC, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			SelectObject(hDC, hPen);
			Ellipse(hDC, x21 - 50, y21 - 50, x22 + 50, y22 + 50);
			DeleteObject(hBrush);
			DeleteObject(hPen);

			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hDC, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			SelectObject(hDC, hPen);
			Ellipse(hDC, x21, y21, x22, y22);
			DeleteObject(hBrush);
			DeleteObject(hPen);
		}
		else
		{
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hDC, hBrush);
			Ellipse(hDC, x21 - 50, y21 - 50, x22 + 50, y22 + 50);
			DeleteObject(hBrush);
		}
		
		if (c == 0)
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hDC, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			SelectObject(hDC, hPen);
			Ellipse(hDC, x31 - 50, y31 - 50, x32 + 50, y32 + 50);
			DeleteObject(hBrush);
			DeleteObject(hPen);

			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hDC, hBrush);
			hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			SelectObject(hDC, hPen);
			Ellipse(hDC, x31, y31, x32, y32);
			DeleteObject(hBrush);
			DeleteObject(hPen);
		}
		else
		{
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hDC, hBrush);
			Ellipse(hDC, x31 - 50, y31 - 50, x32 + 50, y32 + 50);
			DeleteObject(hBrush);
		}
		EndPaint(hwnd, &ps);
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
		InvalidateRect(hwnd, &rect, NULL);
		break;

	case WM_LBUTTONDOWN:
		u = LOWORD(lParam);
		v = HIWORD(lParam);
		click = 'l';
		InvalidateRect(hwnd, &rect, NULL);
		break;

	case WM_RBUTTONDOWN:
		u = LOWORD(lParam);
		v = HIWORD(lParam);
		click = 'r';
		InvalidateRect(hwnd, &rect, NULL);
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