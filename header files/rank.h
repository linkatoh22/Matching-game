#pragma once
#include<fstream>
#include<iostream>
#include<iomanip>
#include"console.h"
using namespace std;
static int s = 0;
struct info
{
	string mode;
	int size;
	int time;
};
struct time
{
	string fulltime;
	int seconds;
};
void getleaderboard();
void rankleaderboard(string filename);
void read(string filename);
void draw2();