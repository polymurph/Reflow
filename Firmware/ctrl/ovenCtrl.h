#ifndef OVENCTRL_H_
#define OVENCTRL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "reflow_oven_bsl.h"


typedef enum {
    ev_start,
    ev_soakTempReaced,
    ev_soakDone,
    ev_peakTempReached,
    ev_dwellTimeOver,
    ev_ovenCooledDown,
    ev_abort
} oven_event_t;

void ovenCtrl_init(reflowBSL_t* bsl);

void ovenCtrl_handleEvent(oven_event_t event);

void ovenCtrl_run();

#ifdef IDEAS
// gives a temperature set value for a given time in [s]
float ovenCtrl_getTempSetValue(float T);

void ovenCtrl_controllLoop();
#endif // IDEAS
#endif // OVENCTRL_H_
