#include "bar.h"

static int barListIndex = 0;
sBar barList[BAR_MAX_LIMIT];

int createBar(eBarType type, int posX, int posY)
{
    if(barListIndex<BAR_MAX_LIMIT)
    {
        barList[barListIndex].id            = barListIndex+1;
        barList[barListIndex].speed         = BAR_DFLT_SPEED;
        barList[barListIndex].shape.image   = BAR_DFLT_SHAPE;
        barList[barListIndex].shape.width   = BAR_DFLT_WDTH;
        barList[barListIndex].shape.height  = BAR_DFLT_LNGTH;
        barList[barListIndex].shape.posX    =  posX;
        barList[barListIndex].shape.posY    =  posY;
        barList[barListIndex].type          =  type;
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
        barList[barListIndex].speed         = 0;
        barList[barListIndex].shape.image   = 0;
        barList[barListIndex].shape.width   = 0;
        barList[barListIndex].shape.height  = 0;
        barList[barListIndex].shape.posX    =  0;
        barList[barListIndex].shape.posY    =  0;
        barList[barListIndex].type          =  0;
        return 1;
    }else
    {
        return 0;
    }
    
}

