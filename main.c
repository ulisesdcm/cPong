#include <stdio.h>
#include "graphics.h"
#include "keyboard.h"

typedef enum
{
    STATE_IDLE,
    STATE_START,
    STATE_END,
    STATE_PAUSE,
}egameState;

egameState gameState = STATE_START;
eCommand    usrInput = IDLE;

int main(void)
{
    hideCursor();
    int countX = 20;
    int countY = 20;

    while(1)
    {
        clearScreen();
        usrInput = scanKeyboard();
        gotoxy(countX,countY);
        putchar('x');            
        delay(10);
        switch (gameState)
        {
        case STATE_IDLE:
            break;
        case STATE_START:
            switch (usrInput)
            {
            case GO_UP:
                countY--;
                break;
            case GO_DOWN:
                countY++;
                break;
            case GO_LEFT:
                countX--;
                break;
            case GO_RIGTH:
                countX++;
                break;
            case EXIT:
                return 0;
            }
            break;
        case STATE_END:
            break;
        case STATE_PAUSE:
            break;
        }
    }
    return 1;
}