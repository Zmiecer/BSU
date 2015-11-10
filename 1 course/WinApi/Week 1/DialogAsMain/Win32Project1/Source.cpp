#undef UNICODE
#include <windows.h>
#include <cstdio>
//#include <sstream>
char str[50];//="olo";
int x = 5;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	sprintf_s(str, "%d", x);
	MessageBox(NULL, str, "Caption", MB_OKCANCEL);
	//системное диалоговое окно для вывода сообщений
	return 0;
}