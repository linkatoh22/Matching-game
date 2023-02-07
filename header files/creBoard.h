#ifndef CREBOARD_H
#define CREBOARD_H
#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include "console.h"
#include "timer.h"
#include <ctime>
#include <Mmsystem.h>
#include<thread>
#include"Menu.h"
#include"bg.h"
using namespace std;
struct point
{
	int x;
	int y;
};
void Board(int**& core, char**& front, int size);
void print(char** front, int size, point posA, point posB);
void BasicMode(int**& core, char**& front, int size,int *a);
void AdvancedMode(int**& core, char**& front, int size,int *a);
void ToTheLeft(int**& core, char**& front, int size, point targetA, point targetB);
void ToTheRight(int**& core, char**& front, int size, point targetA, point targetB);
void ToTheTop(int**& core, char**& front, int size, point targetA, point targetB);
void ToTheBot(int**& core, char**& front, int size, point targetA, point targetB);
bool checkI(int** core, char** front, point targetA, point targetB);
bool checkL1(int** core, point targetA, point targetB);
bool checkL(int** core, char** front, point targetA, point targetB);
bool checkZ1(int** core, char** front, point targetA, point targetB);
bool checkZ(int** core, char** front, point targetA, point targetB);
bool checkU(int** core, char** front, int size, point targetA, point targetB);
void suggestion(int** core, char** front, int size,int*a);
bool checkWin(int** core, char** front, int size);
void randomAgain(int**& core, char**& front, int size);
#endif