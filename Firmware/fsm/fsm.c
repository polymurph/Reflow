#include "fsm.h"

void fsm_kernel(
		fsm_t *fsm)
{
	// block FSM kernel so that no event can interrupt the state context
	fsm->mtxTake();

	// run state context
	fsm->currentState->context();	
	
	// free FSM kernel
	fsm-mtxGive();
}

void fsm_eventHandler(
		fsm_t *fsm,
		fsm_event_t *event)
{
	// block FSM event handler
	fsm->eventMtxTake();
	
	// check if event is valid
	if(fsm->currentState != event->currentState) {
		fsm->eventMtxGive();
		return;
	}
	
	// block FSM kernel to be able to be able to change the state
	fsm->mtxTake();
	
	// execute state transition action
	event->action();
	
	// switch state
	fsm->currentState = event->nextState;
	
	// free FSM kernel
	fsm->mtxGive();

	// free FSM event handler
	fsm->eventMtxGive();
}
