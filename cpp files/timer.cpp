#include "timer.h"
void timer(int *a,int size,string mode)
{
    
    int h = 0, m = 0, s = 0;
    while (*a > 0) {
        setcolor(6);
        if (m == 59 && s == 60)
        {
            h++;
            s = 0;
            m = 0;
        }
        else if (s == 60)
        {
            s = 0;
            m++;
        }
        for (int i = 46 + size * 8+3; i <= 46 + (size * 8)+3+7 + 4; i++)
        {
            gotoxy(i, 5);//4);
            cout << char(196);
        }
        for (int i = 5; i <= 7; i++)
        {
            gotoxy(46 + size * 8 + 3, i);
                cout << char(179);
        }
        for (int i = 5; i <= 7; i++)
        {
            gotoxy(46 + (size * 8) + 3 + 7 + 4, i);
            cout << char(179);
        }
        for (int i = 46 + size * 8+3; i <= 46 + (size * 8)+3+7 + 4; i++)
        {
            gotoxy(i, 7);
            cout << char(196);
        }
        
        gotoxy(46 + size * 8+3, 5);
        cout << char(218);
        gotoxy(46 + (size * 8)+3, 7);
        cout << char(192);
        gotoxy(46 + (size * 8)+3+7+4, 5);
        cout << char(191);
        gotoxy(46 + (size * 8)+3+7+4, 7);
        cout << char(217);
        gotoxy(46 + (size * 8) + 4+1, 6);
        setcolor(31);
        cout << std::setfill('0') << std::setw(2) << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s++;
        Sleep(1000);
    }
    if (*a == -1)
    {
        ofstream out;
        int timel = s + m * 60 + h * 3600;
        out.open("input.txt");
        out << mode<<" " << size << " " << timel;
        out.close();
        getleaderboard();
    }
    
}