#undef UNICODE
#include <windows.h>
#include <string.h>
#include <cstring>
INT x1 = 0, y1 = 0, x2 = 150, y2 = 100, r = 60, g = 0, b = 80;
CHAR s1[7]="Лекция", s2[9]="Практика";

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "Создание окна Windows";

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
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
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
		WS_OVERLAPPEDWINDOW && WS_THICKFRAME, // стиль окна
		300,       // горизонтальная координата окна
		100,       // вертикальная координата окна
		800,       // ширина окна
		600,       // высота окна
		NULL,                // дескриптор родительского окна
		NULL,                // дескриптор меню окна
		hInstance,           // дескриптор экземпляра приложения
		NULL);               // указатель на дополнительные данные окна

	if (!hWnd)    return (FALSE);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);
	return (TRUE);
}
/*LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
switch (message)
{
case WM_DESTROY:
PostQuitMessage(0);
break;
default:
return DefWindowProc(hwnd, message, wParam, lParam);
}
return 0;
}*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);


		HGDIOBJ hpenOld, hbrushOld;
		HBRUSH hbrush;

		SetTextColor(hDC, RGB(255, 255, 255));

		hbrush = CreateSolidBrush(RGB(r, g, b)); 
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
		Rectangle(hDC, x1, y1, x2, y2);
		SetBkColor(hDC, RGB(r, g, b));
		TextOut(hDC, x1 + 10, y1 + 10, s2, 9);
		TextOut(hDC, x1 + 10, y1 + 40, "Ауд. 150", 9);

		//TextOut(hDC, 250, 200, "Обработка сообщения WM_PAINT", 28);
		for (INT i = 0; i < 4; i++) 
		{
			hbrush = CreateSolidBrush(RGB(r += 5, g += 13, b += 10));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Rectangle(hDC, x1 += 150, y1, x2 += 150, y2);
			SetBkColor(hDC, RGB(r, g ,b));
			TextOut(hDC, x1+10, y1+10, s2, 9);
			TextOut(hDC, x1 + 10, y1 + 40, "Ауд. 263", 9);
			Sleep(50);

		}
		
		x1 = 0, y1 = 100, x2 = 150, y2 = 200;
		hbrush = CreateSolidBrush(RGB(r += 5, g += 13, b += 10));
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
		Rectangle(hDC, x1, y1, x2, y2);
		SetBkColor(hDC, RGB(r, g, b));
		TextOut(hDC, x1 + 10, y1 + 10, s1, 7);
		TextOut(hDC, x1 + 10, y1 + 40, "Ауд. 328", 9);
		Sleep(20);
		for (INT i = 0; i < 4; i++)
		{
			hbrush = CreateSolidBrush(RGB(r += 5, g += 13, b += 10));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Rectangle(hDC, x1 += 150, y1, x2 += 150, y2);
			SetBkColor(hDC, RGB(r, g, b));
			TextOut(hDC, x1 + 10, y1 + 10, s1, 7);
			TextOut(hDC, x1 + 10, y1 + 40, "Ауд. 457", 9);
			Sleep(50);

		}

		x1 = 0, y1 = 200, x2 = 150, y2 = 300;
		hbrush = CreateSolidBrush(RGB(r += 10, g += 25, b += 10));
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
		Rectangle(hDC, x1, y1, x2, y2);
		SetBkColor(hDC, RGB(r, g, b));
		TextOut(hDC, x1 + 10, y1 + 10, s1, 7);
		TextOut(hDC, x1 + 10, y1 + 40, "Ауд. 239", 9);
		Sleep(20);
		for (INT i = 0; i < 4; i++)
		{
			hbrush = CreateSolidBrush(RGB(r += 10, g += 25, b += 10));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
			Rectangle(hDC, x1 += 150, y1, x2 += 150, y2);
			SetBkColor(hDC, RGB(r, g, b));
			TextOut(hDC, x1 + 10, y1 + 10, s2, 9);
			TextOut(hDC, x1 + 10, y1 + 40, "Ауд. 346", 9);
			Sleep(50);

		}

		DeleteObject(SelectObject(hDC, hbrush));
		DeleteObject(SelectObject(hDC, hbrushOld));

		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}