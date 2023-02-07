#include "creBoard.h"

void Board(int**& core, char**& front, int size)
{
    srand((int)time(0));

    core = new int* [size];
    front = new char* [size];
    int cnt = size * size, m, n, img;
    point k, h;
    for (int i = 0; i < size; i++)
    {
        core[i] = new int[size];
        front[i] = new char[size];
        for (int j = 0; j < size; j++)
            core[i][j] = 0;
    }


    while (cnt > 0)
    {
        m = rand() % (size * size);
        n = rand() % (size * size);
        k.x = m / size;
        k.y = m % size;

        h.x = n / size;
        h.y = n % size;

        if (m == n || core[k.x][k.y] != 0 || core[h.x][h.y] != 0)
            continue;
        else
        {
            img = 65 + rand() % 26;
            front[k.x][k.y] = char(img);
            front[h.x][h.y] = front[k.x][k.y];

            core[k.x][k.y] = 1;
            core[h.x][h.y] = 1;

            cnt -= 2;
        };

    };
};

void print(char** front, int size, point posA, point posB)
{
    setcolor(7);
    int k = 0;
    if (size == 8)
    {
        draw();
    }
    else if (size == 6)
    {
        draw6();
    }
    else if (size == 4)
    {
        draw4();
    }

    setcolor(11);
    
    for (int i = 0; i <size; i++)
    {
        for (int j = 0; j <size; j++)
        {
            if (front[i][j] != ' ')
            {
                for (int y = 5 + 4 * (i); y < 5 + (4 * (i + 1)); y++)
                {
                    gotoxy(46 + j * 8, y);
                    std::cout << "|";
                }
                for (int k = 46 + ((j ) * 8); k < 46 + (j+1) * 8; k++)
                {
                    gotoxy(k, 5 + 4 * i);
                    std::cout << "+";
                }
                for (int k = 46 + ((j ) * 8); k < 46 + (j+1) * 8; k++)
                {
                    gotoxy(k, 5 + 4 * (i + 1));
                    std::cout << "+";
                }
                for (int y = 5 + 4 * (i ); y < 5 + (4 * (1+i)); y++)
                {
                    gotoxy(46 + (j + 1) * 8, y);
                    std::cout << "|";
                }
            }
        }
    }
    if (front[0][0] != ' ')
    {
        gotoxy(46, 5);
        std::cout << char(218);
    }
    if (front[0][size - 1] != ' ')
    {
        gotoxy(46+size*8, 5);
        std::cout << char(191);
    }
    if (front[size - 1][0] != ' ')
    {
        gotoxy(46, 5 + size*4);
        std::cout << char(192);
    }
    if (front[size - 1][size - 1] != ' ')
    {
        gotoxy(46 + size * 8, 5 + size * 4);
        std::cout << char(217);
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == posA.x && j == posA.y)
            {
                setcolor(94);
                for (int iy = (7 + 4 * i) - 1; iy <= (7 + 4 * i) + 1; iy++) {
                    for (int ix = (50 + 8 * j) - 3; ix < (50 + 8 * j) + 4; ix++)
                    {
                        gotoxy(ix, iy);
                        std::cout << " ";
                    }
                }
                gotoxy(50 + 8 * j, 7 + 4 * i);
                std::cout << front[i][j];
            }
            else if (i == posB.x && j == posB.y)
            {
                setcolor(94);
                for (int iy = (7 + 4 * i) - 1; iy <= (7 + 4 * i) + 1; iy++) {
                    for (int ix = (50 + 8 * j) - 3; ix < (50 + 8 * j) + 4; ix++)
                    {
                        gotoxy(ix, iy);
                        std::cout << " ";
                    }
                }
                gotoxy(50 + 8 * j, 7 + 4 * i);
                std::cout << front[i][j];
            }
            else
            {
                setcolor(7);
                if (front[i][j] == ' ')
                {
                    for (int iy = (7 + 4 * i) - 1; iy <= (7 + 4 * i) + 1; iy++) {
                        for (int ix = (50 + 8 * j) - 3 + 1; ix < (50 + 8 * j) + 4 + 1; ix++)
                        {
                            gotoxy(ix, iy);
                            std::cout << "\b \b";

                        }
                    }
                }
                else
                { 
                    for (int iy = (7 + 4 * i) - 1; iy <= (7 + 4 * i) + 1; iy++) {
                        for (int ix = (50 + 8 * j) - 3 + 1; ix < (50 + 8 * j) + 4 + 1; ix++)
                        {
                            gotoxy(ix, iy);
                            std::cout << "\b \b";

                        }
                    }
                    gotoxy(50 + 8 * j, 7 + 4 * i);
                    std::cout << front[i][j];
                }
                
               
            };
            
        };
        
        std::cout << endl << endl;
    };
};

bool checkI(int** core, char** front, point targetA, point targetB)
{
    int A, B;

    if (targetA.x != targetB.x && targetA.y != targetB.y)
        return false;
    if (front[targetA.x][targetA.y] != front[targetB.x][targetB.y])
        return false;

    // y bằng nhau
    if (targetA.x > targetB.x)
    {
        A = targetB.x;
        B = targetA.x;
    }
    else
    {
        A = targetA.x;
        B = targetB.x;
    };

    for (int i = A + 1; i < B; i++)
        if (core[i][targetA.y] == 1)
            return false;

    // x bằng nhau
    if (targetA.y > targetB.y)
    {
        A = targetB.y;
        B = targetA.y;
    }
    else
    {
        A = targetA.y;
        B = targetB.y;
    };

    for (int i = A + 1; i < B; i++)
        if (core[targetA.x][i] == 1)
            return false;

    return true;
};

bool checkL1(int** core, point targetA, point targetB) //check I nhưng không quan tâm biểu tượng
{
    int A, B;

    if (targetA.x != targetB.x && targetA.y != targetB.y)
        return false;

    // y bằng nhau
    if (targetA.x > targetB.x)
    {
        A = targetB.x;
        B = targetA.x;
    }
    else
    {
        A = targetA.x;
        B = targetB.x;
    };

    for (int i = A + 1; i < B; i++)
        if (core[i][targetA.y] == 1)
            return false;

    // x bằng nhau
    if (targetA.y > targetB.y)
    {
        A = targetB.y;
        B = targetA.y;
    }
    else
    {
        A = targetA.y;
        B = targetB.y;
    };

    for (int i = A + 1; i < B; i++)
        if (core[targetA.x][i] == 1)
            return false;

    return true;
};

bool checkL(int** core, char** front, point targetA, point targetB)
{
    point corner1, corner2;

    corner1.x = targetB.x;
    corner1.y = targetA.y;

    corner2.x = targetA.x;
    corner2.y = targetB.y;

    if (targetA.x == targetB.x || targetA.y == targetB.y)
    {
        if (!checkI(core, front, targetA, targetB))
            return false;
    };

    if (front[targetA.x][targetA.y] != front[targetB.x][targetB.y])
        return false;

    if (core[corner1.x][corner1.y] == 1 && core[corner2.x][corner2.y] == 1)
        return false;


    if (core[corner1.x][corner1.y] == 0)
    {
        if (checkL1(core, targetA, corner1) && checkL1(core, targetB, corner1))
            return true;
    }
    else if (core[corner2.x][corner2.y] == 0)
    {
        if (checkL1(core, targetA, corner2) && checkL1(core, targetB, corner2))
            return true;
        else
            return false;
    }
    else
        return false;
};

bool checkZ1(int** core, char** front, point targetA, point targetB)// check L nhưng không quan tâm biểu tượng
{
    point corner1, corner2;

    corner1.x = targetB.x;
    corner1.y = targetA.y;

    corner2.x = targetA.x;
    corner2.y = targetB.y;

    if (targetA.x == targetB.x || targetA.y == targetB.y)
    {
        if (!checkI(core, front, targetA, targetB))
            return false;
    };

    if (core[corner1.x][corner1.y] == 1 && core[corner2.x][corner2.y] == 1)
        return false;

    if (core[corner1.x][corner1.y] == 0)
    {
        if (checkL1(core, targetA, corner1) && checkL1(core, targetB, corner1))
            return true;
    }
    else if (core[corner2.x][corner2.y] == 0)
    {
        if (checkL1(core, targetA, corner2) && checkL1(core, targetB, corner2))
            return true;
        else
            return false;
    }
    else
        return false;
};

bool checkZ(int** core, char** front, point targetA, point targetB) {
    if (targetA.x == targetB.x || targetA.y == targetB.y)
    {
        if (!checkI(core, front, targetA, targetB))
            return false;
    };

    if (front[targetA.x][targetA.y] != front[targetB.x][targetB.y])
        return false;

    point A, B;

    if (targetA.y > targetB.y)// tìm điểm có tung độ nhỏ hơn
    {
        A = targetB;
        B = targetA;
    }
    else
    {
        A = targetA;
        B = targetB;
    };

    //Check hình chữ Z ngang
    point C, D;

    D.x = B.x;
    D.y = B.y - 1;


    for (int i = A.y + 1; i < B.y; i++)
    {
        C.x = A.x;
        C.y = i;

        if (core[D.x][D.y] == 1 || core[C.x][C.y] == 1)
            break;

        if (checkZ1(core, front, C, D))
            return true;
    };

    //Check hình chữ Z dựng đứng
    if (A.x < B.x)
    {
        D.y = B.y;
        D.x = B.x - 1;
        for (int i = A.x + 1; i < B.x; i++)
        {
            C.x = i;
            C.y = A.y;

            if (core[D.x][D.y] == 1 || core[C.x][C.y] == 1)
                break;

            if (checkZ1(core, front, C, D))
                return true;
        };
    };

    if (A.x > B.x)
    {
        D.y = B.y;
        D.x = B.x + 1;

        for (int i = A.x - 1; i > B.x; i--)
        {
            C.x = i;
            C.y = A.y;

            if (core[D.x][D.y] == 1 || core[C.x][C.y] == 1)
                break;

            if (checkZ1(core, front, C, D))
                return true;
        };
    };

    return false;
};

bool checkU(int** core, char** front, int size, point targetA, point targetB)
{
    if (front[targetA.x][targetA.y] != front[targetB.x][targetB.y])
        return false;

    point A, B;

    // Điểm biên

    if (targetA.x == 0 && targetB.x == 0)
        return true;

    if (targetA.x == size - 1 && targetB.x == size - 1)
        return true;

    if (targetA.y == 0 && targetB.y == 0)
        return true;

    if (targetA.y == size - 1 && targetB.y == size - 1)
        return true;

    // Tiến lên trên

    if (targetA.x > targetB.x)
    {
        A = targetA;
        targetA = targetB;
        targetB = A;
    };


    A.y = targetA.y;
    B.y = targetB.y;

    if (targetA.x == 0)
    {
        B.x = 0;
        if (checkL1(core, B, targetB) && core[B.x][B.y] == 0)
            return true;
    };

    for (int i = targetA.x - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            B.x = 0;
            if (checkL1(core, B, targetB) && core[B.x][B.y] == 0 && core[A.x][A.y] == 0)
                return true;
        }
        else
        {
            A.x = i;
            B.x = i;

            if (checkL1(core, B, targetB) && checkL1(core, A, B) && core[A.x][A.y] == 0 && core[B.x][B.y] == 0)
                return true;
            else
                continue;
        };
    };
    // Tiến xuống dưới

    if (targetA.x < targetB.x)
    {
        A = targetA;
        targetA = targetB;
        targetB = A;
    };

    A.y = targetA.y;
    B.y = targetB.y;

    if (targetA.x == size - 1)
    {
        B.x = size - 1;
        if (checkL1(core, B, targetB) && core[B.x][B.y] == 0)
            return true;
    };

    for (int i = targetA.x + 1; i < size; i++)
    {
        if (i == size - 1)
        {
            B.x = size - 1;
            if (checkL1(core, B, targetB) && core[B.x][B.y] == 0 && core[A.x][A.y] == 0)
                return true;
        }
        else
        {
            A.x = i;
            B.x = i;

            if (checkL1(core, B, targetB) && checkL1(core, A, B) && core[A.x][A.y] == 0 && core[B.x][B.y] == 0)
                return true;
            else
                continue;
        };
    };

    // Tiến về bên trái

    if (targetA.y > targetB.y)
    {
        A = targetA;
        targetA = targetB;
        targetB = A;
    };

    A.x = targetA.x;
    B.x = targetB.x;

    if (targetA.y == 0)
    {
        B.y = 0;
        if (checkL1(core, B, targetB) && core[B.x][B.y] == 0)
            return true;
    };

    for (int i = targetA.y - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            B.y = 0;
            if (checkL1(core, B, targetB) && core[B.x][B.y] == 0 && core[A.x][A.y] == 0)
                return true;
        }
        else
        {
            A.y = i;
            B.y = i;
            if (checkL1(core, B, targetB) && checkL1(core, A, B) && core[A.x][A.y] == 0 && core[B.x][B.y] == 0)
                return true;
            else
                continue;
        };
    };

    // Tiền về bên phải
    if (targetA.y < targetB.y)
    {
        A = targetA;
        targetA = targetB;
        targetB = A;
    };

    A.x = targetA.x;
    B.x = targetB.x;

    if (targetA.y == size - 1)
    {
        B.y = size - 1;
        if (checkL1(core, B, targetB) && core[B.x][B.y] == 0)
            return true;
    };

    for (int i = targetA.y + 1; i < size; i++)
    {
        if (i == size - 1)
        {
            B.y = size - 1;
            if (checkL1(core, B, targetB) && core[B.x][B.y] == 0 && core[A.x][A.y] == 0)
                return true;
        }
        else
        {
            A.y = i;
            B.y = i;

            if (checkL1(core, B, targetB) && checkL1(core, A, B) && core[A.x][A.y] == 0 && core[B.x][B.y] == 0)
                return true;
            else
                continue;
        };
    };

    return false;
};

void BasicMode(int**& core, char**& front, int size,int *a)
{
    while (!checkWin(core, front, size))
        Board(core, front, size);
    int s = 0;
    int r = 0;
    int check = 0;
    char keyPress;
    point now, prev, targetA, targetB;
    now.x = 0;
    now.y = 0;
    print(front, size, now, now);

    while (true)
    {
        switch (check)
        {
        case 0:
        {
            prev = now;
            break;
        };
        case 1:
        {
            prev = targetA;
            break;
        };
        };

        keyPress = _getch();

        switch (keyPress)
        {
        case 72://up
        {
            if (now.x == 0)
                continue;
            else
            {
                now.x--;
                if (check == 0)
                    print(front, size, now, now);
                else
                    print(front, size, now, prev);
            };
            break;
        };
        case 80://down
        {
            if (now.x == size - 1)
                continue;
            else
            {
                now.x++;
                if (check == 0)
                    print(front, size, now, now);
                else
                    print(front, size, now, prev);
            };
            break;
        };
        case 75://left
        {
            if (now.y == 0)
                continue;
            else
            {
                now.y--;
                if (check == 0)
                    print(front, size, now, now);
                else
                    print(front, size, now, prev);
            };
            break;
        };
        case 77://right
        {
            if (now.y == size - 1)
                continue;
            else
            {
                now.y++;
                if (check == 0)
                    print(front, size, now, now);
                else
                    print(front, size, now, prev);
            };
            break;
        };
        case 13: case 32:// enter or space
        {
            PlaySound(TEXT("chon1.wav"), NULL, SND_FILENAME | SND_ASYNC);
            if (core[now.x][now.y] == 1 && check == 0)
            {
                core[now.x][now.y] = 2;
                targetA = now;
                print(front, size, targetA, now);
                check = 1;
                break;
            };

            if (core[now.x][now.y] == 1 && check == 1) // chọn hai cặp và bắt đầu kiểm tra
            {
                targetB = now;
                print(front, size, targetA, targetB);
                if (checkI(core, front, targetA, targetB) || checkL(core, front, targetA, targetB) || checkZ(core, front, targetA, targetB) || checkU(core, front, size, targetA, targetB))
                {
                    PlaySound(TEXT("match.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    front[targetA.x][targetA.y] = ' ';
                    front[targetB.x][targetB.y] = ' ';

                    core[targetA.x][targetA.y] = 0;
                    core[targetB.x][targetB.y] = 0;

                    now.x = 0;
                    now.y = 0;

                    targetA = now;
                    targetB = now;

                    int check = 0;
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            if (core[i][j] == 1)
                            {
                                check = 1;
                                break;
                            }
                        };

                        if (check == 1)
                            break;
                    }

                    if (check == 1)
                        print(front, size, now, now);
                    else
                    {
                        *a-=2;
                        setcolor(7);
                        system("cls");
                        gotoxy(40, 15);
                        setcolor(103);
                        std::cout << "You win!";
                        setcolor(78);
                        gotoxy(40, 17);
                        cout << "Press Enter to go to the MENU.";
                        PlaySound(TEXT("back.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                        char E;
                        E = _getch();
                        for (int f = 0;;) {
                            if (E == '\r')
                            {
                                setcolor(7);
                                system("cls");
                                DrawMenu();
                                move1();
                            }
                        }
                        
                    };

                }
                else // fail
                {
                    PlaySound(TEXT("wrong.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    now.x = 0;
                    now.y = 0;

                    core[targetA.x][targetA.y] = 1;
                    core[targetB.x][targetB.y] = 1;

                    targetA = now;
                    targetB = now;

                    print(front, size, now, now);
                };

                check = 0;
            };

            if (core[now.x][now.y] == 2 && check == 1) // Cancel cặp đã chọn
            {
                core[now.x][now.y] = 1;

                now.x = 0;
                now.y = 0;

                targetA = now;
                print(front, size, now, now);
                check = 0;

            };

            break;

        };
        case 9: // tab for suggestion
        {
            if (s < 4)
            {
                gotoxy(46 + size * 8-10, 4);
                setcolor(13);
                suggestion(core, front, size,a);
                s++;
                cout << "Suggestion chance: " << s << "/" << "4";
                setcolor(7);
            }
            
            break;
        };
        case 49: // phím 1 để random lần nữa
        {
            if (r < 1)
            {
                gotoxy(46 + size * 8-10, 3);
                setcolor(13);
                randomAgain(core, front, size);
                r++;
                cout << "Random chance: " << r << "/" << "1";
                setcolor(7);
            }
            
            break;
        };
        default:
        {
            continue;
            break;
        };

        };
    };
};

void AdvancedMode(int**& core, char**& front, int size,int*a)
{
    while (!checkWin(core, front, size))
        Board(core, front, size);
    int s = 0;
    int r = 0;
    int check = 0, direction = 0;
    char keyPress;
    point now, prev, targetA, targetB;
    now.x = 0;
    now.y = 0;
    print(front, size, now, now);

    direction = 1 + rand() % 4; // Lựa chọn ngẫu nhiên 1 trong 4 kiểu hard mode: 1-> dồn sang trái, 2 -> phải, 3 -> lên, 4 -> xuống 
    while (true)
    {
        switch (check)
        {
        case 0:
        {
            prev = now;
            break;
        };
        case 1:
        {
            prev = targetA;
            break;
        };
        };

        keyPress = _getch();

        switch (keyPress)
        {
        case 72://up
        {
            if (now.x == 0)
                continue;
            else
            {
                now.x--;
                if (check == 0)
                    print(front, size, now, now);
                else
                    print(front, size, now, prev);
            };
            break;
        };
        case 80://down
        {
            if (now.x == size - 1)
                continue;
            else
            {
                now.x++;
                if (check == 0)
                    print(front, size, now, now);
                else
                    print(front, size, now, prev);
            };
            break;
        };
        case 75://left
        {
            if (now.y == 0)
                continue;
            else
            {
                now.y--;
                if (check == 0)
                    print(front, size, now, now);
                else
                    print(front, size, now, prev);
            };
            break;
        };
        case 77://right
        {
            if (now.y == size - 1)
                continue;
            else
            {
                now.y++;
                if (check == 0)
                    print(front, size, now, now);
                else
                    print(front, size, now, prev);
            };
            break;
        };
        case 13: case 32:// enter or space
        {
            if (core[now.x][now.y] == 1 && check == 0)
            {
                core[now.x][now.y] = 2;
                targetA = now;
                print(front, size, targetA, now);
                check = 1;
                break;
            };

            if (core[now.x][now.y] == 1 && check == 1) // ch?n ???c hai c?p và b?t ??u ki?m tra
            {
                targetB = now;
                print(front, size, targetA, targetB);
                if (checkI(core, front, targetA, targetB) || checkL(core, front, targetA, targetB) || checkZ(core, front, targetA, targetB) || checkU(core, front, size, targetA, targetB)) // Ghi ?i?m
                {
                    front[targetA.x][targetA.y] = ' ';
                    front[targetB.x][targetB.y] = ' ';

                    core[targetA.x][targetA.y] = 0;
                    core[targetB.x][targetB.y] = 0;

                    now.x = 0;
                    now.y = 0;

                    targetA = now;
                    targetB = now;

                    int check = 0;
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            if (core[i][j] == 1)
                            {
                                check = 1;
                                break;
                            }
                        };

                        if (check == 1)
                            break;
                    }

                    if (check == 1)
                    {
                        switch (direction)
                        {
                        case 1:
                        {
                            ToTheLeft(core, front, size, targetA, targetB);
                            break;
                        }
                        case 2:
                        {
                            ToTheRight(core, front, size, targetA, targetB);
                            break;
                        }
                        case 3:
                        {
                            ToTheTop(core, front, size, targetA, targetB);
                            break;
                        }
                        case 4:
                        {
                            ToTheBot(core, front, size, targetA, targetB);
                            break;
                        }
                        };

                        print(front, size, now, now);
                    }
                    else
                    {
                        *a -= 2;
                        setcolor(7);
                        system("cls");
                        gotoxy(40, 15);
                        setcolor(103);
                        std::cout << "You win!";
                        PlaySound(TEXT("back.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
                        setcolor(78);
                        gotoxy(40, 17);
                        cout << "Press Enter to go to the MENU.";
                        char E;
                        E = _getch();
                        for (int f = 0;;) {
                            if (E == '\r')
                            {
                                setcolor(7);
                                system("cls");
                                DrawMenu();
                                move1();
                            }
                        }
                        setcolor(7);
                 
                    };

                }
                else // Hai c?p fail
                {
                    PlaySound(TEXT("wrong.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    now.x = 0;
                    now.y = 0;

                    core[targetA.x][targetA.y] = 1;
                    core[targetB.x][targetB.y] = 1;

                    targetA = now;
                    targetB = now;

                    print(front, size, now, now);
                };

                check = 0;
            };

            if (core[now.x][now.y] == 2 && check == 1) // Cancel c?p ?ã ch?n
            {
                core[now.x][now.y] = 1;

                now.x = 0;
                now.y = 0;

                targetA = now;
                print(front, size, now, now);
                check = 0;

            };

            break;

        };
        case 9: // tab for suggestion
        {
            
            if (s < 4)
            {
                gotoxy(46 + size * 8 - 10, 4);
                setcolor(13);
                suggestion(core, front, size,a);
                s++;
                cout << "Suggestion chance: " << s << "/" << "4";
                setcolor(7);
            }
            break;
        };
        case 49: // phím 1 ?? ??o l?i
        {
            
            if (r < 1)
            {
                gotoxy(46 + size * 8 - 10, 3);
                setcolor(13);
                randomAgain(core, front, size);
                r++;
                cout << "Random chance: " << r << "/" << "1";
                setcolor(7);
            }
            break;
        };
        default:
        {
            continue;
            break;
        };
        };
    };
};

void ToTheLeft(int**& core, char**& front, int size, point targetA, point targetB)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (core[i][j] == 0)
            {
                if (j == size - 1)
                    break;
                else
                {
                    for (int k = j; k < size; k++)
                        if (core[i][k] == 1) // đổi chỗ
                        {
                            front[i][j] = front[i][k];
                            front[i][k] = ' ';
                            core[i][j] = 1;
                            core[i][k] = 0;
                            break;
                        }
                };
            };
        };
};

void ToTheRight(int**& core, char**& front, int size, point targetA, point targetB)
{
    for (int i = size - 1; i >= 0; i--)
        for (int j = size - 1; j >= 0; j--)
        {
            if (core[i][j] == 0)
            {
                if (j == 0)
                    break;
                else
                {
                    for (int k = j; k >= 0; k--)
                        if (core[i][k] == 1) // đổi chỗ
                        {
                            front[i][j] = front[i][k];
                            front[i][k] = ' ';
                            core[i][j] = 1;
                            core[i][k] = 0;
                            break;
                        }
                };
            };
        };
};

void ToTheTop(int**& core, char**& front, int size, point targetA, point targetB)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (core[j][i] == 0)
            {
                if (j == size - 1)
                    break;
                else
                {
                    for (int k = j; k < size; k++)
                        if (core[k][i] == 1) // đổi chỗ
                        {
                            front[j][i] = front[k][i];
                            front[k][i] = ' ';
                            core[j][i] = 1;
                            core[k][i] = 0;
                            break;
                        }
                };
            };
        };
};

void ToTheBot(int**& core, char**& front, int size, point targetA, point targetB)
{
    for (int i = size - 1; i >= 0; i--)
        for (int j = size - 1; j >= 0; j--)
        {
            if (core[j][i] == 0)
            {
                if (j == 0)
                    break;
                else
                {
                    for (int k = j; k >= 0; k--)
                        if (core[k][i] == 1) // đổi chỗ
                        {
                            front[j][i] = front[k][i];
                            front[k][i] = ' ';
                            core[j][i] = 1;
                            core[k][i] = 0;
                            break;
                        }
                };
            };
        };
};

void suggestion(int** core, char** front, int size,int * a)
{
    int check = 0;
    point targetA, targetB;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            targetA.x = i;
            targetA.y = j;

            if (core[i][j] == 1 || core[i][j] == 2) // kiểm tra xem có bằng nhau không
            {
                for (int k = i; k < size; k++)
                {
                    for (int h = 0; h < size; h++)
                    {
                        if (k == i && h == j)
                            continue;

                        if (front[i][j] == front[k][h])
                        {
                            targetB.x = k;
                            targetB.y = h;
                            if (checkI(core, front, targetA, targetB) || checkL(core, front, targetA, targetB) || checkZ(core, front, targetA, targetB) || checkU(core, front, size, targetA, targetB))
                            {
                                print(front, size, targetA, targetB);
                                check = 1;
                            }
                        }
                        else
                            continue;

                        if (check == 1)
                            break;
                    };

                    if (check == 1)
                        break;
                };
            }
            else
                continue;

            if (check == 1)
                break;
        };

        if (check == 1)
            break;
    };

    if (check == 0)
    {
        *a = -2;
        system("cls");
        gotoxy(80, 15);
        std::cout << "You lose !";
        setcolor(78);
        gotoxy(80, 17);
        cout << "Press Enter to go to the MENU.";
        PlaySound(TEXT("lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
        char E;
        E = _getch();
        for (int f = 0;;) {
            if (E == '\r')
            {
                system("cls");
                DrawMenu();
                move1();
            }
        }
    };
}

bool checkWin(int** core, char** front, int size) 
{
    int check = 0;
    point targetA, targetB;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            targetA.x = i;
            targetA.y = j;

            if (core[i][j] == 1 || core[i][j] == 2) 
            {
                for (int k = i; k < size; k++)
                {
                    for (int h = 0; h < size; h++)
                    {
                        if (k == i && h == j)
                            continue;

                        if (front[i][j] == front[k][h])
                        {
                            targetB.x = k;
                            targetB.y = h;
                            if (checkI(core, front, targetA, targetB) || checkL(core, front, targetA, targetB) || checkZ(core, front, targetA, targetB) || checkU(core, front, size, targetA, targetB))
                                return true;
                        }
                        else
                            continue;

                        if (check == 1)
                            break;
                    };

                    if (check == 1)
                        break;
                };
            }
            else
                continue;

            if (check == 1)
                break;
        };

        if (check == 1)
            break;
    };

    if (check == 0)
        return false;
};

void randomAgain(int**& core, char**& front, int size) // random các kí tự trong bảng lại một lần nữa
{
    srand((int)time(0));

    point k, h;
    char tmp;

    for (int i = 0; i < size * size; i++)
    {
        k.x = rand() % size;
        k.y = rand() % size;

        h.x = rand() % size;
        h.y = rand() % size;

        tmp = front[k.x][k.y];
        front[k.x][k.y] = front[h.x][h.y];
        front[h.x][h.y] = tmp;

        swap(core[k.x][k.y], core[h.x][h.y]);
    };

    k.x = 0;
    k.y = 0;
    print(front, size, k, k);
}
