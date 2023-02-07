#include "rules.h"
void setfont1()
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 300;
	fontex.dwFontSize.X = 40;
	fontex.dwFontSize.Y = 25;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}
void drawrules()
{
	setcolor(103);
	gotoxy(25, 3);
	cout << " _______ _______ __   __ _______   ______   __   __ ___     _______ _______ \n";
	gotoxy(25, 4);
	cout << "|       |   _   |  |_|  |       | |    _ | |  | |  |   |   |       |       |\n";
	gotoxy(25, 5);
	cout << "|    ___|  |_|  |       |    ___| |   | || |  | |  |   |   |    ___|  _____|\n";
	gotoxy(25, 6);
	cout << "|   | __|       |       |   |___  |   |_||_|  |_|  |   |   |   |___| |_____ \n";
	gotoxy(25, 7);
	cout << "|   ||  |       |       |    ___| |    __  |       |   |___|    ___|_____  |\n";
	gotoxy(25, 8);
	cout << "|   |_| |   _   | ||_|| |   |___  |   |  | |       |       |   |___ _____| |\n";
	gotoxy(25, 9);
	cout << "|_______|__| |__|_|   |_|_______| |___|  |_|_______|_______|_______|_______|\n";
}
void writerules()
{
	setcolor(248);
	setfont1();
	gotoxy(9, 13);
	cout << "+ Using arrow key to move (left, right, up, down).";
	gotoxy(9, 15);
	cout << "+ To score points you must satisfy one in four type of matching (I, L, U or Z).";
	gotoxy(9, 17);
	cout << "+ Press"; setcolor(244); cout << " TAB "; setcolor(248); cout << "to display suggested pairs (Limits: 4 times).";
	gotoxy(9, 19);
	cout << "+ Press";  setcolor(244); cout << " 1 "; setcolor(248); cout << "to randomize characters in the board (Limits: 1 time).";
	gotoxy(9, 21);
	cout << "+ If there is no matching pair left and you also out of random chance you will lose.";
	gotoxy(20, 25);
	setcolor(78);
	cout << "Press Enter to go back to the menu.";
	char c;
	c = _getch();
	for (int i;;)
	{
		if (c == '\r')
		{
			PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		}
	}
	SetFont();
	setcolor(7);
	system("cls");
}
/*
 _______ _______ __   __ _______   ______   __   __ ___     _______ _______ 
|       |   _   |  |_|  |       | |    _ | |  | |  |   |   |       |       |
|    ___|  |_|  |       |    ___| |   | || |  | |  |   |   |    ___|  _____|
|   | __|       |       |   |___  |   |_||_|  |_|  |   |   |   |___| |_____ 
|   ||  |       |       |    ___| |    __  |       |   |___|    ___|_____  |
|   |_| |   _   | ||_|| |   |___  |   |  | |       |       |   |___ _____| |
|_______|__| |__|_|   |_|_______| |___|  |_|_______|_______|_______|_______|
*/