#ifndef __GRAPHICS_H
#define __GRAPHICS_H


void clearScreen(void);
void gotoxy(int x, int y);
void delay(int milliSeconds);
void hideCursor(void);
int getWindowHeight(void);
int getWindowWidth(void);
void getWindowSize(int *ptrWidth, int *ptrHeight);

#endif