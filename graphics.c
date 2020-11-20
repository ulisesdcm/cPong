#include "graphics.h"
#include "ball.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include "screen.h"

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

void getWindowSize(int *ptrX, int *ptrY)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *ptrX   = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *ptrY  = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void windowRefresh(void)
{    
    clearScreen();
    int ballCount;

    // Drawing balls
    for(ballCount = 0; ballCount<BALL_MAX_LIMIT; ballCount++)
    {
        if(ballList[ballCount].id != 0)
        {
            gotoxy(ballList[ballCount].shape.posX,ballList[ballCount].shape.posY);
            putchar(ballList[ballCount].shape.image);
        }else
        {
            break;
        }
    }
    
    // Draw status bar count
    drawStatusBar(ballCount);

    delay(SCREEN_REFRESH_TIME_MS);
}