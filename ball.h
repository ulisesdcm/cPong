#ifndef __BALL_H
#define __BALL_H


struct sBall 
{
    unsigned char   id;
    unsigned char   shape;        //ASCII value
    unsigned int    speed;              
    unsigned int    posX;
    unsigned int    posY;
    unsigned int    status;
};

void createBall(sBall *ball);
void destroyBall(sBall *ball);

//Set funtions
void setBallPositionX(sBall *ball, unsigned int PosX);
void setBallPositionY(sBall *ball, unsigned int PosY);
void setBallSpeed(sBall *ball, unsigned char speed);
void setBallShape(sBall *ball, unsigned );

#endif