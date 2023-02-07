#include"Menu.h"
using namespace std;
int** core;
char** front;
void drawbox(int x, int y, int height, int width, int color, string but)
{
	textcolor(color);
	int j = 0;
	for (int iy = y + 1; iy <= y + height - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + width - 1; ix++)
		{
			gotoxy(ix, iy);
			cout << " ";
		}
	}
	gotoxy(x + 7, y + 2);
	cout << but;
	//Add Button
	setcolor(7);
	textcolor(3);//doi chu
	for (int ix = x; ix <= x + width; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + height);
		cout << char(196);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + width, iy);
		cout << char(179);
		j++;
	}
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + width, y);
	cout << char(191);
	gotoxy(x, y + height);
	cout << char(192);
	gotoxy(x + width, y + height);
	cout << char(217);
}
void move1()
{
	PlaySound(TEXT("back.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	char c;
	int counter = 1;
	int index = 5;
	int color[5] = { 7,7,7,7,7 };
	drawbox(55, 12, 4, 30, 78, "Normal Mode");
	drawbox(55, 17, 4, 30, 7, "Advanced Mode");
	drawbox(55, 22, 4, 30, 7, "LeaderBoard");
	drawbox(55, 27, 4, 30, 7, "Game Rules");
	drawbox(55, 32, 4, 30, 7, "Exit");
	for (int i = 0;;)
	{

		c = _getch();

		if (c == 72 && (counter >= 2 && counter <= 5))
		{
			counter--;
		}
		else if (c == 80 && (counter >= 1 && counter <= 4))
		{
			counter++;
		}
		else if (c == '\r')//carriage return
		{
			gotoxy(0, 48);
			if (counter == 1)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				DrawMenu();// if enter is click and highlight is on 1 the program will run the code here
				move2("B");
			}
			if (counter == 2)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				DrawMenu();
				move2("A");
			}
			if (counter == 3)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				DrawMenu();
				move3();
				cout << "Menu 3 is Open";
			}
			if (counter == 4)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				drawrules();
				writerules();
				DrawMenu();
				move1();
			}
			if (counter == 5)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				DrawMenu();
				return;
			}
		}
		else
		{
			continue;
		}
		color[0] = 7;
		color[1] = 7;
		color[2] = 7;
		color[3] = 7;
		color[4] = 7;
		if (counter == 1)
		{
			color[0] = 78;
		}
		if (counter == 2)
		{
			color[1] = 78;
		}
		if (counter == 3)
		{
			color[2] = 78;
		}
		if (counter == 4)
		{
			color[3] = 78;
		}
		if (counter == 5)
		{
			color[4] = 78;
		}
		drawbox(55, 12, 4, 30, color[0], "Normal Mode");
		drawbox(55, 17, 4, 30, color[1], "Advanced Mode");
		drawbox(55, 22, 4, 30, color[2], "LeaderBoard");
		drawbox(55, 27, 4, 30, color[3], "Game Rules");
		drawbox(55, 32, 4, 30, color[4], "Exit");

	}
}
void move2(string mode)
{
	PlaySound(TEXT("back.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	char c;
	int counter = 1;
	int index = 4;
	int color1[4] = { 7,7,7,7 };
	drawbox(55, 12, 4, 30, 78, "4x4 Mode");
	drawbox(55, 17, 4, 30, 7, "6x6 Mode");
	drawbox(55, 22, 4, 30, 7, "8x8 Mode");
	drawbox(55, 27, 4, 30, 7, "Back");
	for (int i = 0;;)
	{

		c = _getch();

		if (c == 72 && (counter >= 2 && counter <= 4))
		{
			counter--;
		}
		else if (c == 80 && (counter >= 1 && counter <= 3))
		{
			counter++;
		}
		else if (c == '\r')//carriage return
		{
			gotoxy(0, 48);
			if (counter == 1)
			{
				int size = 4;
				system("cls");
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (mode == "B")
				{
					int n = 1;
					int* a = (int*)malloc(1 * sizeof(int));
					a = &n;
					Board(core, front, size);
					thread th1(BasicMode, std::ref(core), std::ref(front), size, std::ref(a));
					thread th2(timer, std::ref(a), size, "B");
					th1.join();
					th2.join();
					for (int i = 0; i < size; i++)
					{
						delete[] core[i];
						delete[] front[i];
					};
					delete[] core;
					delete[] front;
					free(a);
				}
				else if (mode == "A")
				{
					int n = 1;
					int* a = (int*)malloc(1 * sizeof(int));
					a = &n;
					Board(core, front, size);
					thread th1(AdvancedMode, std::ref(core), std::ref(front), size, std::ref(a));
					thread th2(timer, std::ref(a), size, "B");
					th1.join();
					th2.join();
					for (int i = 0; i < size; i++)
					{
						delete[] core[i];
						delete[] front[i];
					};
					delete[] core;
					delete[] front;
					free(a);
				}
				else if (mode == "A1")
				{
					read("Advanced4x4.txt");
					char k;
					k = _getch();
					for (int j = 0;;) {
						if (k == '\r')
						{
							system("cls");
							DrawMenu();
							move2("A1");
						}
					}
				}
				else if (mode == "B1")
				{
					read("Basic4x4.txt");
					char k;
					k = _getch();
					for (int j = 0;;) {
						if (k == '\r')
						{
							system("cls");
							DrawMenu();
							move2("B1");
						}
					}
				}

			}
			if (counter == 2)
			{
				int size = 6;
				system("cls");
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (mode == "B")
				{
					int n = 1;
					int* a = (int*)malloc(1 * sizeof(int));
					a = &n;
					Board(core, front, size);
					thread th1(BasicMode, std::ref(core), std::ref(front), size, std::ref(a));
					thread th2(timer, std::ref(a), size, "B");
					th1.join();
					th2.join();
					for (int i = 0; i < size; i++)
					{
						delete[] core[i];
						delete[] front[i];
					};
					delete[] core;
					delete[] front;
					free(a);
				}
				else if (mode == "A")
				{
					int n = 1;
					int* a = (int*)malloc(1 * sizeof(int));
					a = &n;
					Board(core, front, size);
					thread th1(AdvancedMode, std::ref(core), std::ref(front), size, std::ref(a));
					thread th2(timer, std::ref(a), size, "B");
					th1.join();
					th2.join();
					for (int i = 0; i < size; i++)
					{
						delete[] core[i];
						delete[] front[i];
					};
					delete[] core;
					delete[] front;
					free(a);
				}
				else if (mode == "A1")
				{
					read("Advanced6x6.txt");
					char k;
					k = _getch();
					for (int j = 0;;) {
						if (k == '\r')
						{
							system("cls");
							DrawMenu();
							move2("A1");
						}
					}
				}
				else if (mode == "B1")
				{
					read("Basic6x6.txt");
					char k;
					k = _getch();
					for (int j = 0;;) {
						if (k == '\r')
						{
							system("cls");
							DrawMenu();
							move2("B1");
						}
					}
				}
			}
			if (counter == 3)
			{
				int size = 8;
				system("cls");
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (mode == "B")
				{
					int n = 1;
					int* a = (int*)malloc(1 * sizeof(int));
					a = &n;
					Board(core, front, size);
					thread th1(BasicMode, std::ref(core), std::ref(front), size, std::ref(a));
					thread th2(timer, std::ref(a), size, "B");
					th1.join();
					th2.join();
					for (int i = 0; i < size; i++)
					{
						delete[] core[i];
						delete[] front[i];
					};
					delete[] core;
					delete[] front;
					free(a);
				}
				else if (mode == "A")
				{
					int n = 1;
					int* a = (int*)malloc(1 * sizeof(int));
					a = &n;
					Board(core, front, size);
					thread th1(AdvancedMode, std::ref(core), std::ref(front), size, std::ref(a));
					thread th2(timer, std::ref(a), size, "B");
					th1.join();
					th2.join();
					for (int i = 0; i < size; i++)
					{
						delete[] core[i];
						delete[] front[i];
					};
					delete[] core;
					delete[] front;
					free(a);
				}
				else if (mode == "A1")
				{
					read("Advanced8x8.txt");
					char k;
					k = _getch();
					for (int j = 0;;) {
						if (k == '\r')
						{
							system("cls");
							DrawMenu();
							move2("A1");
						}
					}
				}
				else if (mode == "B1")
				{
					read("Basic8x8.txt");
					char k;
					k = _getch();
					for (int j = 0;;) {
						if (k == '\r')
						{
							system("cls");
							DrawMenu();
							move2("B1");
						}
					}
				}
			}
			if (counter == 4)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME);
				cout << "Menu 4 is Open";
				system("cls");
				DrawMenu();
				move1();
			}
		}
		else
		{
			continue;
		}
		color1[0] = 7;
		color1[1] = 7;
		color1[2] = 7;
		color1[3] = 7;
		if (counter == 1)
		{
			color1[0] = 78;
		}
		if (counter == 2)
		{
			color1[1] = 78;
		}
		if (counter == 3)
		{
			color1[2] = 78;
		}
		if (counter == 4)
		{
			color1[3] = 78;
		}
		drawbox(55, 12, 4, 30, color1[0], "4x4 Mode");
		drawbox(55, 17, 4, 30, color1[1], "6x6 Mode");
		drawbox(55, 22, 4, 30, color1[2], "8x8 Mode");
		drawbox(55, 27, 4, 30, color1[3], "Back");
	}
}
void DrawMenu()
{
	setcolor(27);
	gotoxy(3, 3);
	cout << " _______  __   __  _______    __   __  _______  _______  _______  __   __  ___   __    _  _______    _______  _______  __   __  _______ " << endl;
	gotoxy(3, 4);
	cout << "|       ||  | |  ||       |  |  |_|  ||   _   ||       ||       ||  | |  ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |" << endl;
	gotoxy(3, 5);
	cout << "|_     _||  |_|  ||    ___|  |       ||  |_|  ||_     _||       ||  |_|  ||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|" << endl;
	gotoxy(3, 6);
	cout << "  |   |  |       ||   |___   |       ||       |  |   |  |       ||       ||   | |       ||   | __   |   | __ |       ||       ||   |___ " << endl;
	gotoxy(3, 7);
	cout << "  |   |  |       ||    ___|  |       ||       |  |   |  |      _||       ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|" << endl;
	gotoxy(3, 8);
	cout << "  |   |  |   _   ||   |___   | ||_|| ||   _   |  |   |  |     |_ |   _   ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ " << endl;
	gotoxy(3, 9);
	cout << "  |___|  |__| |__||_______|  |_|   |_||__| |__|  |___|  |_______||__| |__||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|" << endl;
	/*gotoxy(20, 15);
	cout << "  o   o  o o-o     o   o o-o- o   o-o o  o | o  o o--O      o-o  o-o-o o o o-o " << endl;
	gotoxy(20, 16);
	cout << "                                                     |                         " << endl;
	gotoxy(20, 17);
	cout << "                                                  o--o                         " << endl;*/
	setcolor(7);
}
void move3()
{
	PlaySound(TEXT("back.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	char c;
	int counter = 1;
	int index = 3;
	int color[3] = { 7,7,7 };
	drawbox(55, 12, 4, 30, 78, "Normal Mode");
	drawbox(55, 17, 4, 30, 7, "Advanced Mode");
	drawbox(55, 22, 4, 30, 7, "Back");
	for (int i = 0;;)
	{

		c = _getch();

		if (c == 72 && (counter >= 2 && counter <= 3))
		{
			counter--;
		}
		else if (c == 80 && (counter >= 1 && counter <= 2))
		{
			counter++;
		}
		else if (c == '\r')//carriage return
		{
			gotoxy(0, 48);
			if (counter == 1)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				DrawMenu();// if enter is click and highlight is on 1 the program will run the code here
				move2("B1");
			}
			if (counter == 2)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				DrawMenu();
				move2("A1");
			}
			if (counter == 3)
			{
				PlaySound(TEXT("Button1.wav"), NULL, SND_FILENAME | SND_ASYNC);
				system("cls");
				DrawMenu();
				move1();
			}
		}
		else
		{
			continue;
		}
		color[0] = 7;
		color[1] = 7;
		color[2] = 7;
		if (counter == 1)
		{
			color[0] = 78;
		}
		if (counter == 2)
		{
			color[1] = 78;
		}
		if (counter == 3)
		{
			color[2] = 78;
		}
		drawbox(55, 12, 4, 30, color[0], "Normal Mode");
		drawbox(55, 17, 4, 30, color[1], "Advanced Mode");
		drawbox(55, 22, 4, 30, color[2], "Back");

	}
}