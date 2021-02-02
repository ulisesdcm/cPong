#include "keyboard.h"
#include "conio.h"
#include <stdio.h>

eCommand scanKeyboard(void)
{
    int tmpInput = 0;
    eCommand rtCommand  = IDLE;
    if(kbhit())
    {
        tmpInput = getch();
        // printf("Key pressed %d \n",tmpInput);
        switch (tmpInput)
        {
        case KYB_USR_UP:
            rtCommand = GO_UP;    
            break;
        case KYB_USR_DWN:
            rtCommand = GO_DOWN;
            break;
        case KYB_USR_LFT:
            rtCommand = GO_LEFT;
            break;
        case KYB_USR_RGT:
            rtCommand = GO_RIGTH;
            break;
        case KYB_USR_PSE:
            rtCommand = PAUSE;
            break;
        case KYB_USR_EXIT:
            rtCommand = EXIT;
            break;
        default:
            rtCommand   = IDLE;
            break;
        }
    }
    // printf("Command return %d\n",rtCommand);
    return rtCommand;   
}