#undef UNICODE
#include <windows.h>
INT x = 10, y = 10;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "�������� ���� Windows";

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
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
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
		800,       // ������ ����
		600,       // ������ ����
		NULL,                // ���������� ������������� ����
		NULL,                // ���������� ���� ����
		hInstance,           // ���������� ���������� ����������
		NULL);               // ��������� �� �������������� ������ ����

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

		x = 800;
		y = 600;

		MoveToEx(hDC, x / 2, 0, 0); // ��������
		LineTo(hDC, x / 2, y);
		MoveToEx(hDC, 0, y / 2, 0);
		LineTo(hDC, x, y / 2);


		HGDIOBJ hpenOld, hbrushOld;
		HBRUSH hbrush;

		hbrush = CreateSolidBrush(RGB(150, 0, 150)); //������
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
		Ellipse(hDC, x / 10, y / 10, x / 10 + 250, y / 10 + 200);

		hbrush = CreateSolidBrush(RGB(150, 150, 150)); //�������������
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
		Rectangle(hDC, x / 10 * 7, y / 10, x / 10 * 7 + 100, y / 10 + 200);

		hbrush = CreateSolidBrush(RGB(255, 255, 0)); //������
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);
		Pie(hDC, x / 2 + 100, y / 8 * 5, x / 2 + 300, y / 8 * 5 + 200, 550, 100, 100, 200);

		MoveToEx(hDC, x / 4, y / 10 * 5.5, 0); // ����
		LineTo(hDC, x / 4 + 50, y / 10 * 5.5 + 100);
		LineTo(hDC, x / 4, y / 10 * 5.5 + 200);
		LineTo(hDC, x / 4 - 50, y / 10 * 5.5 + 100);
		LineTo(hDC, x / 4, y / 10 * 5.5);

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