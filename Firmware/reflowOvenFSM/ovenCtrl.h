#ifndef OVENCTRL_H_
#define OVENCTRL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
    ev_start,
    ev_soakTempReaced,
    ev_soakDone,
    ev_peakTempReached,
    ev_dwellTimeOver,
    ev_ovenCooledDown,
    ev_abort
} oven_event_t;

void ovenCtrl_init();

void ovenCtrl_handleEvent(oven_event_t event);

// gives a temperature set value for a given time in [s]
float ovenCtrl_getTempSetValue(float T);

#endif // OVENCTRL_H_
