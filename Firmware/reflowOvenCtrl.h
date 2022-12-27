#ifndef _REFLOW_OVEN_CONTROL_H_
#define _REFLOW_OVEN_CONTROL_H_

/*!< Events*/
typedef enum {
    reflO_evStop,   /*!< Stop*/
    reflO_evStart   /*!< Start*/
} reflOC_Event_t;

/*!< States*/
typedef enum {
    state_idle,  /*!< Idle*/
    state_soak,
    state_rampTempToReflow
} reflOC_State_t;

/**
 * @brief Initializes the reflow ofen finite state machine
 * 
 */
void reflOC_initOvenControl();

/**
 * @brief Changes the state of the finite state machine based on an event
 * 
 * @param e the occured event
 */
void reflOC_processEvent(reflOC_Event_t e);

/**
 * @brief Get the current state of the finite state machine
 * 
 * @return reflO_State_t current state of the finite state machine
 */
reflOC_State_t reflOC_getState();

#endif // _REFLOW_OVEN_CONTROL_H_
