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
LPCSTR szTitle = "Машинка";

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
		xs,       // ширина окна
		ys,       // высота окна
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