#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "FSM_example.h"


/*
S_FSM_ROW_t rowIdle = {IDLE, ev_start, FSM_NoEvent, at_turnOnHeater, at_startRampToSoak, RAMP_TO_SOAK};
S_FSM_ROW_t rowRampToSoak = {RAMP_TO_SOAK, ev_soakStartTempReached, FSM_NoEvent, at_soak, FSM_NoAction, SOAK};
S_FSM_ROW_t rowSoak = {SOAK, ev_soakTimeOver, FSM_NoEvent, at_startRampToSoak, FSM_NoAction, RAMP_TO_PEAK};
S_FSM_ROW_t rowRampToPeak = {RAMP_TO_PEAK, ev_peakTempReached, FSM_NoEvent, at_dwellAtPeak, FSM_NoAction, DWELL};
S_FSM_ROW_t rowDwell = {DWELL, ev_dwellTimeOver, FSM_NoEvent, at_coolDown, at_turnOffHeater, COOL_DOWN};
S_FSM_ROW_t rowCoolDown = {COOL_DOWN, ev_ovenCooledDown, FSM_NoEvent, FSM_NoAction, FSM_NoAction, IDLE};

// abort cases
S_FSM_ROW_t rowRampToSoakAbort = {RAMP_TO_SOAK, ev_abort, FSM_NoEvent, at_turnOffHeater, FSM_NoAction, COOL_DOWN};
S_FSM_ROW_t rowSoakAbort = {SOAK, ev_abort, FSM_NoEvent, at_turnOffHeater, FSM_NoAction, COOL_DOWN};
S_FSM_ROW_t rowRampToPeakAbort = {RAMP_TO_PEAK, ev_abort, FSM_NoEvent, at_turnOffHeater, FSM_NoAction, COOL_DOWN};
S_FSM_ROW_t rowDwellAbort = {DWELL, ev_abort, FSM_NoEvent, at_turnOffHeater, FSM_NoAction, COOL_DOWN};

S_FSM_ROW_t rows[] = {
    rowIdle,
    rowRampToSoak,
    rowSoak,
    rowRampToPeak,
    rowDwell,
    rowCoolDown,
    rowRampToSoakAbort,
    rowSoakAbort,
    rowRampToPeakAbort,
    rowDwellAbort
};


S_FSM_STT_t stateTrasnitionTable ={
    IDLE,{rowIdle}
};

int main()
{
    while(1) {
        FSM_sstKernel(&stateTrasnitionTable);
    }

    return 0;
}
*/

typedef void* (*stateContext_t)(void);


 void FSM_engine(stateContext_t initalContext)
 {
     void *newState = 0;
     stateContext_t currentState = initalContext;
     while(1) {
        // run current state
        newState = currentState();
        // check if the function pointer is not 0
        if(newState != 0) {
            // update state context
            currentState = (stateContext_t)newState;
        }
     }
 }

void* s1();
void* s2();

int main()
{

    while(1) {
        FSM_engine(s1);
    }

    return 0;
}

 void* s1()
 {
    char input;
    do {
        printf("state 1\n");
        printf("Do you want to transition to state 2 ? yes -> [y]/ no -> [any other key]\n");
        //scanf(" %c",&input);
        //fflush(stdin);
    }while(input != 'y');
    return s2;
 }

 void* s2()
 {
    char input;
    do {
        printf("state 2\n");
        printf("Do you want to transition to state 1 ? yes -> [y]/ no -> [any other key]\n");
        //scanf(" %c",&input);
        //fflush(stdin);
    }while(input != 'y');
     return s1;
 }
