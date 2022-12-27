#include "reflowOvenCtrl.h"
#include "reflowOven.h"

/*!< The current state of the finite state machine. It is initalized by default at "state_idle"*/
static reflOC_State_t currentState = state_idle;

void reflOC_initOvenControl()
{

}

void reflOC_processEvent(reflO_Event_t e)
{
    switch(currentState) {
        case state_idle:
            if(e == )
            // actions
            // state transition
            break;

        default:
            break;
    }
}