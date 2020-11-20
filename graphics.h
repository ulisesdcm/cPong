#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#define SCREEN_REFRESH_TIME_MS  50

void clearScreen(void);
void gotoxy(int x, int y);
void delay(int milliSeconds);
void hideCursor(void);
int getWindowHeight(void);
int getWindowWidth(void);
void getWindowSize(int *ptrX, int *ptrY);
void windowRefresh(void);

#endif