#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "keyboard.h"
#include "ball.h"
#include "screen.h"
#include "bar.h"

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
void initSystem(void);

int main(void)
{
    initSystem();
    createBar(10,10,1,5);
    // createBar(20,20,5,2);

    while(1)
    {
        usrInput = scanKeyboard();
        windowRefresh();
        moveAllBall();
        int randX,randY;

        switch (gameState)
        {
        case STATE_IDLE:
            break;
        case STATE_START:
            switch (usrInput)
            {
            case GO_UP:
                // randX = rand() % (200 - 1 +1) + 1;    
                // randY = rand() % (50 - 1 +1) + 1;
                // createBall(randX,randY);
                moveSingleBar(1,MOVE_UP);
                break;
            case GO_DOWN:
                moveSingleBar(1,MOVE_DOWN);
                // destroyBall();
                break;
            case GO_LEFT:
                moveSingleBar(1,MOVE_LEFT);
                break;
            case GO_RIGTH:
                moveSingleBar(1,MOVE_RIGHT);
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

void initSystem(void)
{
    hideCursor();
    clearScreen();
    drawStatusBar(0);

}