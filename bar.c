#include "bar.h"
#include "ball.h"
#include "graphics.h"

static int barListIndex = 0;
sBar barList[BAR_MAX_LIMIT];
int barOldPos[2][BAR_MAX_LIMIT] = {0};

extern sBall ballList[BALL_MAX_LIMIT];

typedef enum
{
    COLLISION_UP,
    COLLISION_DOWN,
    COLLISION_RIGHT,
    COLLISION_LEFT,
    COLLISION_CORNER1,
    COLLISION_CORNER2,
    COLLISION_CORNER3,
    COLLISION_CORNER4,
    NO_COLLISION
}eCollisionBarEvent;

static eCollisionBarEvent checkCollisionEvent(int posX, int posY, int width, int height);

int createBar(int posX, int posY, int width, int height)
{
    if(barListIndex<BAR_MAX_LIMIT)
    {
        barList[barListIndex].id            = barListIndex+1;
        barList[barListIndex].speedX        = BAR_DFLT_SPEEDX;
        barList[barListIndex].speedY        = BAR_DFLT_SPEEDY;
        barList[barListIndex].shape.image   = BAR_DFLT_SHAPE;
        barList[barListIndex].shape.width   = width;
        barList[barListIndex].shape.height  = height;
        barList[barListIndex].shape.posX    = posX;
        barList[barListIndex].shape.posY    = posY;
        barListIndex++;
        return 1;
    }else
    {
        return 0;
    }
    
}

int destroyBar(void)
{
    if(barListIndex>BAR_MAX_LIMIT)
    {
        barListIndex--;
        barList[barListIndex].id            = 0;
        barList[barListIndex].speedX         = 0;
        barList[barListIndex].speedY         = 0;
        barList[barListIndex].shape.image   = 0;
        barList[barListIndex].shape.width   = 0;
        barList[barListIndex].shape.height  = 0;
        barList[barListIndex].shape.posX    =  0;
        barList[barListIndex].shape.posY    =  0;
        return 1;
    }else
    {
        return 0;
    }
    
}

int moveSingleBar(int id, eBARMoveDirection direction)
{
    static int indxBar,newPosX, newPosY, width, height, winX,winY;

    getWindowSize((int *) &winX, (int *) &winY);

    indxBar = id-1;

    if(barList[indxBar].id == 0)
        return 0;

    // Save old position
    barOldPos[0][indxBar] = barList[indxBar].shape.posX;
    barOldPos[1][indxBar] = barList[indxBar].shape.posY;

    width   = barList[indxBar].shape.width;
    height  = barList[indxBar].shape.height;

    // Get new position
    switch(direction)
    {
        case MOVE_UP:
            newPosY = barList[indxBar].shape.posY - barList[indxBar].speedY;
            break;    
        case MOVE_DOWN:
            newPosY = barList[indxBar].shape.posY + barList[indxBar].speedY;
            break;
        case MOVE_LEFT:
            newPosX = barList[indxBar].shape.posX - barList[indxBar].speedX;
            break;
        case MOVE_RIGHT:
            newPosX = barList[indxBar].shape.posX + barList[indxBar].speedX;
            break;
    }

    switch(checkCollisionEvent(newPosX,newPosY,width,height))
    {
        case COLLISION_UP:      newPosY = 0; break;
        case COLLISION_DOWN:    newPosY = winY-1-height; break;
        case COLLISION_LEFT:    newPosX = 0; break;
        case COLLISION_RIGHT:   newPosX = winX-1-width; break;
        case COLLISION_CORNER1: newPosX = 0; newPosY = 0; break;
        case COLLISION_CORNER2: newPosX = winX -1-width; newPosY = 0; break;
        case COLLISION_CORNER3: newPosX = winX-1-width; newPosY=winY-1-height; break;
        case COLLISION_CORNER4: newPosX = 0; newPosY= winY-1-height; break;
    }

    // Set new position
    barList[indxBar].shape.posX = newPosX;
    barList[indxBar].shape.posY = newPosY;
    return 1;

}


static eCollisionBarEvent checkCollisionEvent(int posX, int posY, int width, int height)
{
    static int winX,winY;
    static eCollisionBarEvent retVal;

    retVal = NO_COLLISION;
    getWindowSize((int *) &winX, (int *) &winY );

    if(posX < 0 && posY < 0)                            retVal = COLLISION_CORNER1;
    else if(posX+width > winX && posY < 0)              retVal = COLLISION_CORNER2;
    else if(posX+width > winX && posY+height > winY)    retVal = COLLISION_CORNER3;
    else if(posX < 0 && posY+height > winY)             retVal = COLLISION_CORNER4;
    else if(posX+width > winX-1)                        retVal = COLLISION_RIGHT;
    else if(posX < 0)                                   retVal = COLLISION_LEFT; 
    else if(posY+height > winY-1)                       retVal = COLLISION_DOWN;
    else if(posY < 0)                                   retVal = COLLISION_UP;

    return retVal;       

}
