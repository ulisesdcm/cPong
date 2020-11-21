
#include "ball.h"
#include "graphics.h"
#include <stdio.h>

typedef enum
{
    COLLISION_UP,
    COLLISION_DOWN,
    COLLISION_LEFT,
    COLLISION_RIGHT,
    COLLISION_CORNER1,
    COLLISION_CORNER2,
    COLLISION_CORNER3,
    COLLISION_CORNER4,
    NO_COLLISION
}eCOLLISIONBALL;

sBall ballList[BALL_MAX_LIMIT];
int oldPostBall[2][BALL_MAX_LIMIT] = {0};

static int ballListIndx = 0;
static eCOLLISIONBALL checkCollisionEvent(int posX, int posY);

int createBall(int initPosX, int initPosY)
{
    if(ballListIndx < BALL_MAX_LIMIT)
    {
        ballList[ballListIndx].id               = ballListIndx+1;
        ballList[ballListIndx].speedX           = BALL_DFLT_SPEEDX;
        ballList[ballListIndx].speedY           = BALL_DFLT_SPEEDY;
        ballList[ballListIndx].shape.image      = BALL_DFLT_SHAPE;
        ballList[ballListIndx].shape.posX       = initPosX;
        ballList[ballListIndx].shape.posY       = initPosY;
        ballList[ballListIndx].shape.width      = BALL_DFTL_WDTH;
        ballList[ballListIndx].shape.height     = BALL_DFTL_HGHT;
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
        ballList[ballListIndx].id               = 0;
        ballList[ballListIndx].speedX           = 0;
        ballList[ballListIndx].speedY           = 0;
        ballList[ballListIndx].shape.image      = 0;
        ballList[ballListIndx].shape.posX       = 0;
        ballList[ballListIndx].shape.posY       = 0;
        ballList[ballListIndx].shape.height     = 0;
        ballList[ballListIndx].shape.width      = 0;
        return 1;
    }
    return 0;
}


int moveSingleBall(int id)
{
    int indxBall = id-1;
    // Check ball ID 
    if(ballList[indxBall].id == 0)
        return 0;

    // Save old position
    oldPostBall[0][indxBall] = ballList[indxBall].shape.posX;
    oldPostBall[1][indxBall] = ballList[indxBall].shape.posY;
    
    //Get new position
    int newPosX = ballList[indxBall].shape.posX + ballList[indxBall].speedX;
    int newPosY = ballList[indxBall].shape.posY + ballList[indxBall].speedY;

    switch(checkCollisionEvent(newPosX, newPosY))
    {
        case(COLLISION_RIGHT):
            ballList[indxBall].speedX *= -1;
            newPosX = ballList[indxBall].shape.posX + ballList[indxBall].speedX;
            break;

        case(COLLISION_LEFT):
            ballList[indxBall].speedX *= -1;
            newPosX = 0;
            break;

        case(COLLISION_UP):
            newPosY = 0;
            ballList[indxBall].speedY *= -1;
            break;

        case(COLLISION_DOWN):
            ballList[indxBall].speedY *= -1;
            newPosY = ballList[indxBall].shape.posY + ballList[indxBall].speedY;
            break;


        case(COLLISION_CORNER1):
        case(COLLISION_CORNER2):
        case(COLLISION_CORNER3):
        case(COLLISION_CORNER4):
            ballList[indxBall].speedX *= -1;
            ballList[indxBall].speedY *= -1;
            break;
    }
      
    ballList[indxBall].shape.posX = newPosX;
    ballList[indxBall].shape.posY = newPosY;
    return 1;                        
}

void getBallPosition(int id, int *posX, int *posY)
{
    *posX = ballList[id-1].shape.posX;
    *posY = ballList[id-1].shape.posY;
}

void setBallPosition(int id, int newPosX, int newPosY)
{
    ballList[id-1].shape.posX = newPosX;
    ballList[id-1].shape.posY = newPosY;
}

void setBallSpeed(int id, int newSpeedX, int newSpeedY)
{
    ballList[id-1].speedX = newSpeedX;
    ballList[id-1].speedY = newSpeedY;
}

void getBallSpeed(int id, int *speedX, int *speedY)
{
    *speedX = ballList[id-1].speedX;
    *speedY = ballList[id-1].speedY;
}

int moveAllBall(void)
{
    int count = 0;

    for(count; count<sizeof(ballList);count++)
    {
        if(!moveSingleBall(count+1))
            break;
    }
    return count;
}

static eCOLLISIONBALL checkCollisionEvent(int posX, int posY)
{
    eCOLLISIONBALL retColl = NO_COLLISION;
    int winX,winY;
    getWindowSize((int *) &winX, (int *) &winY);
    
    //Check collision corner
    if(posX <= 0 && posY <= 0)              retColl = COLLISION_CORNER1;
    else if(posX >= winX && posY <= 0 )     retColl = COLLISION_CORNER2;
    else if(posX >= winX && posY >= winY-1)   retColl = COLLISION_CORNER3;
    else if(posX <= 0 && posY >= winY-1)      retColl = COLLISION_CORNER4;
    if(posX >= winX)                   retColl = COLLISION_RIGHT;
    else if(posX <= 0)                      retColl = COLLISION_LEFT;
    else if(posY >= winY-1)                   retColl = COLLISION_DOWN;
    else if(posY <= 0)                      retColl = COLLISION_UP;

    return retColl;
}

