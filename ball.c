#include "ball.h"


sBall ballArr[BALL_MAX_LIMIT];
static int ballArrIndex = 0;

void createBall(sBall *ball)
{
    ball->id = ballArrIndex;
    ballArr[ballArrIndex] = *ball; 
    ballArrIndex++;
}



