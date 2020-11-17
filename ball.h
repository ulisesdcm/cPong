#ifndef __BALL_H
#define __BALL_H

#include "figure.h"

#define BALL_MAX_LIMIT  50
#define BALL_DFLT_SHAPE '@'
#define BALL_DFLT_SPEED 1
#define BALL_DFLT_POSX  10
#define BALL_DFLT_POSY  10
#define BALL_DFTL_WDTH  1
#define BALL_DFTL_HGHT  1

typedef struct  
{
    unsigned char   id;
    unsigned int    speed;
    sFigure         shape;              
}sBall;

 
sBall ballList[BALL_MAX_LIMIT];

int createBall(void);
int destroyBall(void);

#endif