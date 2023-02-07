#include "console.h"
#include"timer.h"
#include <Mmsystem.h>
#include<thread>
#include"bg.h"
#include"Menu.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    system("title The Matching Game");
    Nocursortype();
    SetFont();
    createconsole();
    console();
    DrawMenu();
    move1();

    return 0;
}