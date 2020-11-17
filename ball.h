#ifndef __BALL_H
#define __BALL_H

#define BALL_MAX_LIMIT  50
#define BALL_DFLT_SHAPE '@'
#define BALL_DFLT_SPEED 10
#define BALL_DFLT_POSX  50
#define BALL_DFLT_POSY  50


typedef struct  
{
    unsigned char   id;
    unsigned char   shape;        //ASCII value
    unsigned int    speed;              
    unsigned int    posX;
    unsigned int    posY;
}sBall;

 

int createBall(void);
int destroyBall(void);
void drawSingleBall(unsigned char id);
void drawAllBall(void);

//Set funtions
void setBallPositionX(sBall *ball, unsigned int PosX);
void setBallPositionY(sBall *ball, unsigned int PosY);
void setBallSpeed(sBall *ball, unsigned char speed);
void setBallShape(sBall *ball, unsigned );

#endif