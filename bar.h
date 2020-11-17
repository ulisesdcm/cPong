#ifndef __BAR_H
#define __BAR_H

typedef struct 
{
    unsigned char id;
    unsigned char shape;
    unsigned char speed;
    unsigned char posX;
    unsigned char posY;
    unsigned char status;
    unsigned char length;
    unsigned char width;
}sBar;

void createBar(sBar *bar);
void destroyBar(sBar *bar);



#endif