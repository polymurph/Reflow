#include "ovenCtrl.h"
#include "oven.h"



typedef enum {
    st_idle,
    st_rampToSoak,
    st_soak,
    st_rampToPeak,
    st_dwell,
    st_coolDown
}state_t;

static state_t currentState = st_idle;


// reflow parameters
static float T_base = 0.0
static float t_rampToSoak = 0;
static float T_soakStart = 0.0;
static float t_soak = 0;
static float T_soakEnd = 0.0;
static float t_rampToPeak = 0;
static float T_peak = 0.0;
static float t_dwell = 0;
static float t_coolDown = 0;

// precalculated parameters
static float m_rampToSoak = 0.0;
static float m_soak = 0.0;
static float m_rampToPeak = 0.0;
static float m_coolDown = 0.0;


//
static float reflowTimer = 0.0;
static float timerPeriode = 0.0;







void ovenCtrl_init()
{
    currentState = st_idle;
    oven_init();
    reflowTimer = 0.0;
}s

void ovenCtrl_handleEvent(oven_event_t event)
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
            } else if (event == ev_soakDone) {
                printf("Changing to State: st_rampToPeak\n");
                currentState = st_rampToPeak;
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
            } else if (event == ev_peakTempReached) {
                printf("Changing to State: st_dwell\n");
                currentState = st_dwell;
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
            } else if (event == ev_dwellTimeOver) {
                printf("Changing to State: st_coolDown\n");
                currentState = st_coolDown;
            }
            break;

        case st_coolDown:
            printf("State: st_coolDown\n");
            if(event == ev_ovenCooledDown) {
                printf("Changing to State: st_idle\n");
                currentState = st_idle;
            }
            break;

        default:
            printf("Illegal state!\n");
            break;
    }
}


float ovenCtrl_getTempSetValue(float T)
{
    float setTemp;

    switch(currentState) {

        case st_rampToSoak:
            if(T >= T_soakStart) {
                ovenCtrl_handleEvent(ev_soakTempReaced);
                reflowTimer = 0.0;
                return T_soakStart;
            }
            // wait until base temperature is reached
            if(T < T_base) {
                return T_base;
            }
            setTemp =  m_rampToSoak * reflowTimer + T_base;
            break;

        case st_soak:
            if(T >= T_soakEnd) {
                ovenCtrl_handleEvent(ev_soakDone);
                reflowTimer = 0.0;
                return T_soakEnd;
            }
            setTemp = m_soak * reflowTimer + T_soakStart;
            break;

        case st_rampToPeak:
            if(T >= T_soakEnd) {
                ovenCtrl_handleEvent(ev_soakDone);
                reflowTimer = 0.0;
                return T_peak;
            }
            setTemp = m_rampToPeak * reflowTimer + T_soakEnd;
            break;

        case st_dwell:

            break;

        case st_coolDown:

            break;

        default:
            break;
    }
    // count time
    reflowTimer += timerPeriode;
    return setTemp;

}




