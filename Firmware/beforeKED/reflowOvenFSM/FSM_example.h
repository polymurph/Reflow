#ifndef FSM_EXAMPLE_H_INCLUDED
#define FSM_EXAMPLE_H_INCLUDED

#include <stdint.h>

#include <stdbool.h>

// https://www.controleng.com/articles/finite-state-machine-for-embedded-systems/




/*
#define STT_ROW_MAX 1

typedef bool (*F_FSM_EVENT_t)(void);
typedef void (*F_FSM_ACTION_t)(void);

typedef enum {
    IDLE, RAMP_TO_SOAK, SOAK, RAMP_TO_PEAK, DWELL, COOL_DOWN
} E_FSM_STATE_t;

typedef struct {
    E_FSM_STATE_t currentState;
    F_FSM_EVENT_t event1;
    F_FSM_EVENT_t event2;
    F_FSM_ACTION_t action1;
    F_FSM_ACTION_t action2;
    E_FSM_STATE_t nextState;
} S_FSM_ROW_t;

typedef struct {
    E_FSM_STATE_t currentState;
    S_FSM_ROW_t sttRow[STT_ROW_MAX];
} S_FSM_STT_t;

bool FSM_NoEvent();
void FSM_NoAction();
void FSM_sstKernel(S_FSM_STT_t *table);

// events
bool ev_start();
bool ev_soakStartTempReached();
bool ev_soakTimeOver();
bool ev_peakTempReached();
bool ev_dwellTimeOver();
bool ev_ovenCooledDown();
bool ev_abort();

// actions
void at_turnOnHeater();
void at_startRampToSoak();
void at_soak();
void at_rampToPeak();
void at_dwellAtPeak();
void at_coolDown();
void at_turnOffHeater();
*/

#endif // FSM_EXAMPLE_H_INCLUDED
