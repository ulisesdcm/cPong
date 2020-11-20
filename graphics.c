#include <windows.h>
#include <time.h>
#include <stdio.h>
#include "graphics.h"
#include "ball.h"
#include "screen.h"
#include "bar.h"

extern sBall ballList[BALL_MAX_LIMIT];
extern sBar barList[BAR_MAX_LIMIT];
extern int oldPostBall[2][BALL_MAX_LIMIT];

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
    int ballCount;
    
    // Drawing balls
    for(ballCount = 0; ballCount<BALL_MAX_LIMIT; ballCount++)
    {
        gotoxy(oldPostBall[0][ballCount],oldPostBall[1][ballCount]);
        putchar(' ');
        if(ballList[ballCount].id != 0)
        {
            gotoxy(ballList[ballCount].shape.posX,ballList[ballCount].shape.posY);
            putchar(ballList[ballCount].shape.image);
        }else
        {
            break;
        }
    }

    // Drawing bars
    for(int i=0; i<BAR_MAX_LIMIT; i++)
    {
        if(barList[i].id !=0)
        {
            int limit1,limit2,tmpPosx,tmpPosy,tmpImage;

            if(barList[i].type == BAR_HORIZONTAL)
            {
                limit1 = barList[i].shape.width;
                limit2 = barList[i].shape.height;
            }else
            {
                limit1 = barList[i].shape.height;
                limit2 = barList[i].shape.width;
            }
            tmpPosx     = barList[i].shape.posX;
            tmpPosy     = barList[i].shape.posY;
            tmpImage    = barList[i].shape.image;

            for(int j=0; j<limit1; j++)
            {
                for(int k=0; k<limit2; k++)
                {
                    gotoxy(tmpPosx+j,tmpPosy+k);
                    putchar(tmpImage);
                }
            }
        }else
        {
            break;
        }
    }   

    // Draw status bar count
    drawStatusBar(ballCount);

    delay(SCREEN_REFRESH_TIME_MS);
}