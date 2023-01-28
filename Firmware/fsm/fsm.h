#ifndef _FSM_H_
#define _FSM_H_

typedef void(*fsm_stateContext_t)(void);
typedef void(*fsm_action_t)(void);
typedef void(fsm_mutexTake_t)(void);
typedef void(fsm_mutexGive_t)(void);
typedef void(fsm_eventMutexTake_t)(void);
typedef void(fsm_eventMutexGive_t)(void);

typedef struct {
	fsm_stateContext_t context;
} fsm_state_t;

typedef struct {
	fsm_state_t currentState;
	fsm_state_t nextState;
	fsm_action_t action;
} fsm_event_t;

typedef struct {
	fsm_state_t currentState;
	fsm_mutexTake_t mtxTake;
	fsm_mutexGive_t mtxGive;
	fsm_eventMutexTake_t eventMtxTake;
	fsm_eventMutexGive_t eventMtxGive;	
} fsm_t;

void fsm_init(
		fsm_t *fsm,
		fsm_mutexTake_t mtxTake,
		fsm_mutexGive_t mtxGive);

void fsm_kernel(
		fsm_t *fsm);

void fsm_eventHandler(
		fsm_t *fsm_t,
		fsm_event_t *event);

#endif //_FSM_H_

