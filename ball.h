#ifndef __BALL_H
#define __BALL_H

#include "figure.h"

#define BALL_MAX_LIMIT  50
#define BALL_DFLT_SHAPE 254     //Look ascii table
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

sBall ballList[BALL_MAX_LIMIT];

int createBall(void);
int destroyBall(void);

int moveBall(int id);
// void setDirection
#endif