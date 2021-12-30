#include "../Headers/Window_Settings.h"
#include "../Headers/globalFuncs.h"
int backColor = 0, textColor = 15;
using namespace std;
void SetWindowSize(int getX_window, int getY_window) {
	HWND window_header = GetConsoleWindow();
	const int x_screen = GetSystemMetrics(SM_CXSCREEN), y_screen = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(window_header, HWND_TOP, (x_screen - getX_window) / 2, (y_screen - getY_window) / 2, getX_window, getY_window, NULL);
}

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void ChangeStyle()
{
	std::cout << "Выберите стиль консоли:\n"
		"1. Чёрно белая консоль.\n"
		"2. Серо чёрная консоль.\n"
		"3. Чёрно жёлтая консоль.\n"
		"Ваш выбор: ";
	int style = checkForInt();
	switch (style)
	{
	case 1: 
	{
		SetColor(15, 0);
		system("cls");
		break;
	}
	case 2:
	{
		SetColor(0, 7);
		system("cls");
		break;
	}
	case 3:
	{
		SetColor(14, 0);
		system("cls");
		break;
	}
	}
}
