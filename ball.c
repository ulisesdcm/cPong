#include "ball.h"

static int ballListIndx = 0;

int createBall(void)
{
    if(ballListIndx < BALL_MAX_LIMIT)
    {
        ballList[ballListIndx].id       = ballListIndx+1;
        ballList[ballListIndx].shape    = BALL_DFLT_SHAPE;
        ballList[ballListIndx].speed    = BALL_DFLT_SPEED;
        ballList[ballListIndx].posX     = BALL_DFLT_POSX;
        ballList[ballListIndx].posY     = BALL_DFLT_POSY;
        ballListIndx++;
        return 1;
    }
    return 0;
}

int destroyBall(void)
{
    if(ballListIndx >0 )
    {
        ballListIndx--;
        ballList[ballListIndx].id       = 0;
        ballList[ballListIndx].shape    = 0;
        ballList[ballListIndx].speed    = 0;
        ballList[ballListIndx].posX     = 0;
        ballList[ballListIndx].posY     = 0;
        return 1;
    }
    return 0;
}
