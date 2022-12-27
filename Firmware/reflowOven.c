#include "reflowOven.h"
#include "reflowOvenCtrl.h"

static reflO_enableThreadCB_t _enableThread = 0;
static reflO_disableThreadCB_t _dissableThread = 0;

void reflO_tempControlThread()
{
    reflOC_State_t state = reflOC_getState();

    if(state == state_soak) {
        
    }
}