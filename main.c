#include <stdio.h>
#include "graphics.h"
#include "keyboard.h"
#include "ball.h"

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
    createBall();
    createBall();
    while(1)
    {
        usrInput = scanKeyboard();
        moveBall(1);
        moveBall(2);
        windowRefresh();
        switch (gameState)
        {
        case STATE_IDLE:
            break;
        case STATE_START:
            switch (usrInput)
            {
            case GO_UP:
                // ballList[0].posY--;//= ballList[0].speed;
                break;
            case GO_DOWN:
                // ballList[0].posY++;//= ballList[0].speed;
                break;
            case GO_LEFT:
                // createBall();
                // ballList[0].posX--;//= ballList[0].speed;
                break;
            case GO_RIGTH:
                // destroyBall();
                // ballList[0].posX++;//= ballList[0].speed;
                break;
            case PAUSE:
                // createBall();
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