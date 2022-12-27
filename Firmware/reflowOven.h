#ifndef _REFLOW_OVEN_H_
#define _REFLOW_OVEN_H_

typedef void(*reflO_enableThreadCB_t)(void);
typedef void(*reflO_disableThreadCB_t)(void);

/**
 * @brief Initialize the reflow oven hardware
 * 
 */
void reflO_init();

void reflO_turnOnHeater();

void reflO_turnOffHeater();

void reflO_turnOnVentilator();

void reflO_turnOffVentilator();

void reflO_registerThreadCallbacks(
    reflO_enableThreadCB_t eth,
    reflO_disableThreadCB_t edth);

void reflO_tempControlThread();






#endif // _REFLOW_OVEN_H_
