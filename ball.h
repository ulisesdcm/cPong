#ifndef __BALL_H
#define __BALL_H

#define BALL_MAX_LIMIT  50
#define BALL_DFLT_SHAPE '@'
#define BALL_DFLT_SPEED 1
#define BALL_DFLT_POSX  10
#define BALL_DFLT_POSY  10


typedef struct  
{
    unsigned char   id;
    unsigned char   shape;        //ASCII value
    unsigned int    speed;              
    unsigned int    posX;
    unsigned int    posY;
}sBall;

 
sBall ballList[BALL_MAX_LIMIT];

int createBall(void);
int destroyBall(void);

#endif