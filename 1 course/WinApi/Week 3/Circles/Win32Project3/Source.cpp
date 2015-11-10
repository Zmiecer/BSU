#undef UNICODE
#include <windows.h>
#include <Winuser.h>
#include <cstdio>
#define _AFXDLL
#define FIRST_TIMER 1
int nTimerID;

INT x = 800, y = 600, j = 12;
INT c = 0;
CHAR s1[100];
CHAR strj[4];
RECT rect;
unsigned int key;

INT kz = 0, temp = 0;
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
	static int k, x1, y1, range;
	SelectObject(ps.hdc, hfont);
	char szText[] = "";

	font.lfHeight = 100;

	hfont = ::CreateFontIndirect(&font);
	SelectObject(ps.hdc, hfont);

	
	
	switch (message)
	{
	case WM_CREATE:
		k = 0;
		x1 = 0;
		y1 = 0;
		range = 30;
		break;
	case WM_PAINT:
		GetClientRect(hwnd, &rect);
		hDC = BeginPaint(hwnd, &ps);
		if (k == 1)
		{
			Ellipse(hDC, x1 - range, y1 - range, x1 + range, y1 + range);
			k = 0;
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		k = 1;
		if ((LOWORD(lParam) >= (x1 + range) && HIWORD(lParam) >= (y1 + range)) || (LOWORD(lParam) <= (x1 - range) && HIWORD(lParam) <= (y1 - range)))
		{
			x1 = LOWORD(lParam);
			y1 = HIWORD(lParam);
			range = 30;
		}
		else range += 10;
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