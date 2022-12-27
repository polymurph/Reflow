#include "reflowOven.h"
#include "reflowOvenCtrl.h"

typedef void(*tempCtrl_t)();

enum{
    TEMP_CTRL_ON
};

static reflO_enableThreadCB_t _enableThread = 0;
static reflO_disableThreadCB_t _dissableThread = 0;

static float _relativeTempThreshold = 5.0;
static float _temperatreWindow = 1.0;
static float _soakSetTemp = 150.0;

uint8_t _systemStatus = 0;


void reflO_emergencyStop()
{
    _dissableThread();
    reflO_turnOffHeater();
    reflO_turnOffVentilator();
}

void reflO_tempControlThread()
{
    /*
    reflOC_State_t state = reflOC_getState();
    float temp = reflO_getTemperature();

    if(state == state_soak) {
        // only start temperature controller when temperature 
        if(_soakSetTemp > temp - _relativeTempThreshold) {
            _relativeTempThreshold -= _temperatreWindow;
            _systemStatus |= TEMP_CTRL_ON;
        }
    }
    */
}