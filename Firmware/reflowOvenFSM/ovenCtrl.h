#ifndef OVENCTRL_H_
#define OVENCTRL_H_

typedef enum {
    ev_start,
    ev_soakTempReaced,
    ev_soakDone,
    ev_peakTempReached,
    ev_dwellTimeOver,
    ev_ovenCooledDown,
    ev_abort
} oven_event_t;

void ovenFSM_init();

void ovenFSM_handleEvent(oven_event_t event);



#endif // OVENCTRL_H_
