#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#define KYB_USR_UP      119 // key w
#define KYB_USR_DWN     115 // key s
#define KYB_USR_LFT     97  // key a
#define KYB_USR_RGT     100 // key d
#define KYB_USR_PSE     32  // key SPACE
#define KYB_USR_EXIT     27  // key ESC


typedef enum
{
    IDLE = 0,
    GO_UP,
    GO_DOWN,
    GO_LEFT,
    GO_RIGTH,
    PAUSE,
    ADD,
    REMOVE,
    EXIT
}eCommand;

eCommand scanKeyboard(void);
#endif