#include "ovenCtrl.h
#include "oven.h"

typedef enum {
    st_idle,
    st_rampToSoak,
    st_soak,
    st_rampToPeak,
    st_dwell,
    st_coolDown
}state_t;

void ovenFSM_init()
{
    currentState = st_idle;
    oven_init();
}

void ovenFSM_handleEvent(oven_event_t event)
{
    switch(currentState) {
        case st_idle:
            printf("State: st_idle\n");
            if(event == ev_start) {
                oven_turnOnHeater();
                printf("Changing to State: st_rampToSoak\n");
                currentState = st_rampToSoak;
            }
            break;

        case st_rampToSoak:
            printf("State: st_rampToSoak\n");
            if(event == ev_abort) {
                oven_turnOffHeater();
                printf("Process Aborted!\n");
                printf("Changing to State: st_rampToSoak\n");
                currentState = st_coolDown;
                break;
            } else if (event == ev_soakTempReaced) {
                printf("Changing to State: st_Soak\n");
                currentState = st_soak;
                break;
            }
            break;

        case st_soak:
            printf("State: st_soak\n");
            if(event == ev_abort) {
                oven_turnOffHeater();
                printf("Process Aborted!\n");
                printf("Changing to State: st_rampToSoak\n");
                currentState = st_coolDown;
                break;
            }
            break;

        case st_rampToPeak:
            printf("State: st_rampToPeak\n");
            if(event == ev_abort) {
                oven_turnOffHeater();
                printf("Process Aborted!\n");
                printf("Changing to State: st_rampToSoak\n");
                currentState = st_coolDown;
                break;
            }
            break;

        case st_dwell:
            printf("State: st_dwell\n");
            if(event == ev_abort) {
                oven_turnOffHeater();
                printf("Process Aborted!\n");
                printf("Changing to State: st_rampToSoak\n");
                currentState = st_coolDown;
                break;
            }
            break;

        case st_coolDown:
            printf("State: st_coolDown\n");
            break;

        default:
            break;
    }
}



