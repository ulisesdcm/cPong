#ifndef __BAR_H
#define __BAR_H

#include "figure.h"

#define BAR_MAX_LIMIT   2
#define BAR_DFLT_SHAPE  219
#define BAR_DFLT_SPEED  1
#define BAR_DFLT_LNGTH  5
#define BAR_DFLT_WDTH   2

typedef enum
{
    BAR_HORIZONTAL,
    BAR_VERTICAL
}eBarType;

typedef struct 
{
    int id;
    int speed;
    sFigure shape;
    eBarType type;
}sBar;

int createBar(eBarType type, int posX, int posY);
int destroyBar(void);


#endif