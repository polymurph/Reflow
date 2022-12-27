#ifndef _REFLOW_OVEN_H_
#define _REFLOW_OVEN_H_

typedef void(*reflO_enableThreadCB_t)(void);
typedef void(*reflO_disableThreadCB_t)(void);

/**
 * @brief Initialize the reflow oven hardware
 * 
 * @param P PI-controller P parameter
 * @param I PI-controller I parameter
 */
void reflO_init(float P, float I);

void reflO_turnOnHeater();

void reflO_turnOffHeater();

void reflO_turnOnVentilator();

void reflO_turnOffVentilator();

void reflO_registerThreadCallbacks(
    reflO_enableThreadCB_t eth,
    reflO_disableThreadCB_t edth);

/*
this function must be called in a thread (e.g. Interrupt service routine, RTOS thred, etc.) at only one place in a stable periodic intervall.
the intervall time must also be known as it is needed to for the controll loop parameters.
*/
void reflO_tempControlThread();






#endif // _REFLOW_OVEN_H_
