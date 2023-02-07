#pragma once
#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<Windows.h>
#include"console.h"
#include"creBoard.h"
#include"timer.h"
#include <Mmsystem.h>
#include<thread>
#include"bg.h"
#include"rank.h"
#include"rules.h"
void drawbox(int x, int y, int height, int width, int color, string but);
void move1();
void move2(string mode);
void move3();
void DrawMenu();
#endif