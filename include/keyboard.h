#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#define KYB_USR_UP      'w'
#define KYB_USR_DWN     's'
#define KYB_USR_LFT     'a'
#define KYB_USR_RGT     'd'
#define KYB_USR_PSE     ' '
#define KYB_USR_EXIT     27
#define KYB_USR_ADD     'z'
#define KYB_USR_RMV     'x'

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