#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ovenCtrl.h"


int main()
{
    char input;

    ovenCtrl_init();

    do {
        printf("\nPlease press key: ");
        scanf("%c", &input);
        getchar();  // nach scanf() ist noch ein '\n' im Inputbuffer: auslesen und wegwerfen
        printf("\n");

        switch (input){
            case 's':
                ovenCtrl_handleEvent(ev_start);
                break;

            case 'a':
                ovenCtrl_handleEvent(ev_abort);
                break;

            case '1':
                ovenCtrl_handleEvent(ev_soakTempReaced);
                break;

            case '2':
                ovenCtrl_handleEvent(ev_soakDone);
                break;

            case '3':
                ovenCtrl_handleEvent(ev_peakTempReached);
                break;

            case '4':
                ovenCtrl_handleEvent(ev_dwellTimeOver);
                break;

            case '5':
                ovenCtrl_handleEvent(ev_ovenCooledDown);
                break;

            default:
                break;
        }
    } while(input != 'q');

    return 0;
}

