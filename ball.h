#ifndef __BALL_H
#define __BALL_H

#include "figure.h"

#define BALL_MAX_LIMIT  250
#define BALL_DFLT_SHAPE 254     //Look ascii table
// #define BALL_DFLT_SHAPE '#'     //Look ascii table
#define BALL_DFLT_SPEEDX 1
#define BALL_DFLT_SPEEDY 1
#define BALL_DFLT_POSX  10
#define BALL_DFLT_POSY  10
#define BALL_DFTL_WDTH  1
#define BALL_DFTL_HGHT  1

typedef struct  
{
    unsigned char   id;
    int             speedX;
    int             speedY;
    sFigure         shape;              
}sBall;

int createBall(int initPosX, int initPosY);
int destroyBall(void);

int moveSingleBall(int id);
int moveAllBall(void);

void getBallPosition(int id, int *posX, int *posY);
void setBallPosition(int id, int newPosX, int newPosY);

void setBallSpeed(int id, int newSpeedX, int newSpeedY);
void getBallSpeed(int id, int *speedX, int *speedY);


#endif