#include <stdio.h>
#include "graphics.h"
#include <conio.h>

typedef enum
{
    STATE_IDLE,
    STATE_START,
    STATE_END,
    STATE_PAUSE,
}egameState;

egameState gameState = STATE_START;

int main(void)
{
    int input = 0;
    while(1)
    {
        if(!kbhit())
        {
            input = getch();
            printf("Key pressed: %d \n",input);
            if(input == 27)
                return 0;
        }

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