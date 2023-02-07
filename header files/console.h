#pragma once
#ifndef __CONSOLE_H__
#define __CONSOLE_H__
#include <windows.h>
#define CO_THEME 7
#define WIDTH 1400
#define HEIGHT 750
#include<conio.h>
void ShowCur(bool CursorVisibility);
void createconsole();
void console();
void gotoxy(int x, int y);
void setcolor(int color);
void SetFont();
void textcolor(int x);
void Nocursortype();
#endif