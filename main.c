#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "keyboard.h"
#include "ball.h"
// #include ""
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
    // Creating ball
    int randX,randY;
    for(int i=0; i<100;i++)
    {
        randX = rand() % (200 - 1 +1) + 1;    
        randY = rand() % (50 - 1 +1) + 1;
        createBall(randX,randY);    
    }
    
    while(1)
    {
        usrInput = scanKeyboard();
        windowRefresh();
        moveAllBall();
        switch (gameState)
        {
        case STATE_IDLE:
            break;
        case STATE_START:
            switch (usrInput)
            {
            case GO_UP:
                break;
            case GO_DOWN:
                break;
            case GO_LEFT:
                break;
            case GO_RIGTH:
                break;
            case PAUSE:
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