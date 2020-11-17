#include "graphics.h"
#include "ball.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>

void clearScreen(void)
{
    system("cls");
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(int milliSeconds)
{
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds); 
}

void hideCursor(void)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

int getWindowWidth(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getWindowHeight(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void getWindowSize(int *ptrWidth, int *ptrHeight)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *ptrWidth   = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *ptrHeight  = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void windowRefresh(void)
{
    clearScreen();
    // Drawing balls
    for(int i = 0; i<BALL_MAX_LIMIT; i++)
    {
        if(ballList[i].id != 0)
        {
            gotoxy(ballList[i].shape.posX,ballList[i].shape.posY);
            putchar(ballList[i].shape.image);
        }else
        {
            break;
        }
    }
    delay(SCREEN_REFRESH_TIME_MS);
}