#include "ball.h"

static int ballListIndx = 0;

int createBall(void)
{
    if(ballListIndx < BALL_MAX_LIMIT)
    {
        ballList[ballListIndx].id             = ballListIndx+1;
        ballList[ballListIndx].speed          = BALL_DFLT_SPEED;
        ballList[ballListIndx].shape.image    = BALL_DFLT_SHAPE;
        ballList[ballListIndx].shape.posX     = BALL_DFLT_POSX;
        ballList[ballListIndx].shape.posY     = BALL_DFLT_POSY;
        ballList[ballListIndx].shape.width    = BALL_DFTL_WDTH;
        ballList[ballListIndx].shape.height   = BALL_DFTL_HGHT;
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
        ballList[ballListIndx].speed    = 0;
        ballList[ballListIndx].shape.image    = 0;
        ballList[ballListIndx].shape.posX     = 0;
        ballList[ballListIndx].shape.posY     = 0;
        ballList[ballListIndx].shape.height   = 0;
        ballList[ballListIndx].shape.width    = 0;
        return 1;
    }
    return 0;
}
