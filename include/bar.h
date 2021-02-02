#ifndef __BAR_H
#define __BAR_H

#include "figure.h"

#define BAR_MAX_LIMIT   2
#define BAR_DFLT_SHAPE  219
#define BAR_DFLT_SPEEDX  1
#define BAR_DFLT_SPEEDY  1
#define BAR_DFLT_LNGTH  5
#define BAR_DFLT_WDTH   2

typedef struct 
{
    int id;
    int speedX;
    int speedY;
    sFigure shape;
}sBar;

typedef enum
{
    MOVE_RIGHT,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_DOWN
}eBARMoveDirection;

int createBar(int posX, int posY, int width, int height);
int destroyBar(void);

int moveSingleBar(int id, eBARMoveDirection direction);

#endif