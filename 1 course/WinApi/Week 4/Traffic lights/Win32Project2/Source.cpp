#undef UNICODE
#include <windows.h>
#include <Winuser.h>
#include <cstdio>
#define _AFXDLL
#define FIRST_TIMER 1
int nTimerID;

INT x = 800, y = 600, j = 12;

RECT rect;
unsigned int key;


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
	static int k, x1, y1, rot;
	//bool rot = 0;
	SelectObject(ps.hdc, hfont);
	char szText[] = "";
	HGDIOBJ hpenOld, hbrushOld;
	HBRUSH hbrush;

	font.lfHeight = 100;

	hfont = ::CreateFontIndirect(&font);
	SelectObject(ps.hdc, hfont);



	switch (message)
	{

	case WM_CREATE:
		x1 = 300;
		y1 = 100;
		k = 0;
		rot = 0;
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rect);
		hDC = BeginPaint(hwnd, &ps);
		
		hbrush = CreateSolidBrush(RGB(150, 150, 150));
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
		Rectangle(hDC, x1, y1, x1 + 100, y1 + 300);
		SelectObject(hDC, hbrushOld);
		DeleteObject(hbrush);

		if (k == 0)
		{
			hbrush = CreateSolidBrush(RGB(255, 0, 0));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Ellipse(hDC, x1, y1, x1 + 100, y1 + 100);
			SelectObject(hDC, hbrushOld);
			DeleteObject(hbrush);
		}
		else
		{
			hbrush = CreateSolidBrush(RGB(0, 0, 0));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Ellipse(hDC, x1, y1, x1 + 100, y1 + 100);
			SelectObject(hDC, hbrushOld);
			DeleteObject(hbrush);
		}

		if (k == 1)
		{
			hbrush = CreateSolidBrush(RGB(255, 255, 0));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Ellipse(hDC, x1, y1 + 100, x1 + 100, y1 + 200);
			SelectObject(hDC, hbrushOld);
			DeleteObject(hbrush);
		}
		else
		{
			hbrush = CreateSolidBrush(RGB(0, 0, 0));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Ellipse(hDC, x1, y1 + 100, x1 + 100, y1 + 200);
			SelectObject(hDC, hbrushOld);
			DeleteObject(hbrush);
		}


		if (k == 2)
		{
			hbrush = CreateSolidBrush(RGB(0, 255, 0));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Ellipse(hDC, x1, y1 + 200, x1 + 100, y1 + 300);
			SelectObject(hDC, hbrushOld);
			DeleteObject(hbrush);
		}
		else
		{
			hbrush = CreateSolidBrush(RGB(0, 0, 0));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Ellipse(hDC, x1, y1 + 200, x1 + 100, y1 + 300);
			SelectObject(hDC, hbrushOld);
			DeleteObject(hbrush);
		}


		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		if (k >= 0 && k <= 2)
		{
			if (rot == 0)
			{
				k++;
				if (k == 2)
					rot = 1;
			}
			else
			{
				k--;
				if (k == 0)
					rot = 0;
			}
		}
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