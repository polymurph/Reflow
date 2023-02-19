#include "ovenCtrl.h"
#include "oven.h"
#include "modules.h"
#include "deviceSetup.h"

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
static float T_base = 0.0;
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

void _abort()
{
    print_Usart(oven_bsl->uartChannel, "Process Aborted!\n");
    oven_turnOffHeater();
    print_Usart(oven_bsl->uartChannel, "Changing to State: st_rampToSoak\n");
    currentState = st_coolDown;
}

void ovenCtrl_init(reflowBSL_t* bsl)
{
    currentState = st_idle;
	// init board suport layer (BSL)
	reflowOvenInitHw(bsl);
	// init reflow oven (ui, timer, etc.)
    
    //oven_init();
    reflowTimer = 0.0;

    setupInit();

    // init done!indicate by toggling LED
	userIO_doInitStatusBlinki();
}

void ovenCtrl_handleEvent(oven_event_t event)
{
    switch(currentState) {
        case st_idle:
            print_Usart(oven_bsl->uartChannel, "State: st_idle\n");
            if(event == ev_start) {
                oven_turnOnHeater();
                print_Usart(oven_bsl->uartChannel, "Changing to State: st_rampToSoak\n");
                currentState = st_rampToSoak;
            }
            break;

        case st_rampToSoak:
            print_Usart(oven_bsl->uartChannel, "State: st_rampToSoak\n");
            if(event == ev_abort) {
                _abort();
                break;
            } else if (event == ev_soakTempReaced) {
                print_Usart(oven_bsl->uartChannel, "Changing to State: st_Soak\n");
                currentState = st_soak;
                break;
            }
            break;

        case st_soak:
            print_Usart(oven_bsl->uartChannel, "State: st_soak\n");
            if(event == ev_abort) {
                _abort();
                break;
            } else if (event == ev_soakDone) {
                print_Usart(oven_bsl->uartChannel, "Changing to State: st_rampToPeak\n");
                currentState = st_rampToPeak;
            }
            break;

        case st_rampToPeak:
            print_Usart(oven_bsl->uartChannel, "State: st_rampToPeak\n");
            if(event == ev_abort) {
                _abort();
                break;
            } else if (event == ev_peakTempReached) {
                print_Usart(oven_bsl->uartChannel, "Changing to State: st_dwell\n");
                currentState = st_dwell;
            }
            break;

        case st_dwell:
            print_Usart(oven_bsl->uartChannel, "State: st_dwell\n");
            if(event == ev_abort) {
                _abort();
                break;
            } else if (event == ev_dwellTimeOver) {
                print_Usart(oven_bsl->uartChannel, "Changing to State: st_coolDown\n");
                currentState = st_coolDown;
            }
            break;

        case st_coolDown:
            print_Usart(oven_bsl->uartChannel, "State: st_coolDown\n");
            if(event == ev_ovenCooledDown) {
                print_Usart(oven_bsl->uartChannel, "Changing to State: st_idle\n");
                oven_turnOffHeater();
                currentState = st_idle;
            }
            break;

        default:
            print_Usart(oven_bsl->uartChannel, "Illegal state!\n");
            break;
    }
}

void ovenCtrl_run()
{
	while(1) {
	
	}
}


#ifdef IDEAS

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
            if(reflowTimer > t_dwell) {
                ovenCtrl_handleEvent(ev_dwellTimeOver);
                reflowTimer = 0.0;
                return T_peak;
            }
            setTemp = T_peak;
            break;

        case st_coolDown:
            if(T < T_base) {
                ovenCtrl_handleEvent(ev_dwellTimeOver);
                reflowTimer = 0.0;
                return T_base;
            }
            setTemp = m_coolDown * reflowTimer + T_peak;
            break;

        default:
            break;
    }
    // count time
    reflowTimer += timerPeriode;
    return setTemp;
}


void ovenCtrl_controllLoop()
{
    float T_error;
    float T_set;
    float T_measured;
    float u;
    // read temp
    // set set temperature according to ovenCtrl_getTempSetValue()

    // calculate error
    error = T_set - T_measured;

    // run PI controller

    oven_setDutycycle(u);
}
#endif // IDEAS

