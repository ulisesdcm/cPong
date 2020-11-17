#ifndef __BAR_H
#define __BAR_H

#define BAR_MAX_LIMIT   2
#define BAR_DFLT_SHAPE  219
#define BAR_DFLT_SPEED  1
#define BAR_DFLT_LNGTH  5
#define BAR_DFLT_WDTH   1

typedef struct 
{
    unsigned char id;
    unsigned char shape;
    unsigned char speed;
    unsigned char posX;
    unsigned char posY;
    unsigned char length;
    unsigned char width;
}sBar;

sBar barList[BAR_MAX_LIMIT];

int createBar(void);
int destroyBar(void);


#endif