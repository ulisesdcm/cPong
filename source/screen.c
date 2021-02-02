#include <stdio.h>
#include "graphics.h"


void drawStatusBar(int count)
{
    int x,y;
    getWindowSize((int *) &x, (int *) &y);
    gotoxy(0,y-1);
    printf("%-15s %-3d","Current Balls: ",count);
}