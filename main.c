#include <stdio.h>
#include "graphics.h"

typedef enum
{
    STATE_IDLE,
    STATE_START,
    STATE_END,
    STATE_PAUSE,
}egameState;

int main(void)
{
    while(1)
    {
        
    }

    for(int j =0; j<3; j++)
    {
        for(int i= 0; i<100; i++)
        {
            clearScreen();
            gotoxy(i+20,10);
            putchar('x');
            delay(10);
        }
    }
    return 1;
}