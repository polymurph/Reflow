#incldue "FSM_Example.h"


/*
bool FSM_NoEvent()
{
    return true;
}

void FSM_NoAction()
{

}

void FSM_sstKernel(S_FSM_STT_t *table)
{
    int row;
    bool events;

    for(row = 0; row < STT_ROW_MAX; row++) {
        // search through table for a state change
        if(table->sttRow[row].presenState == table->currentState) {

            events = table->sttRow[row].event1() && table->sttRow[row].event2();

            if(events) {
                printf("State transitioned from [%d] to", table->currentState);
                // execute actions
                table->sttRow[row].action1();
                table->sttRow[row].action2();
                // update state
                table->currentState = table->sttRow[row].nextState;
                printf(" [%d]\n", table->currentState);
                break;
            }
        }
    }
}

// events

bool ev_start()
{
    char input = 0;

    printf("Do you want to start the reflow process?\n");
    printf("Press y for YES and any other key for NO\n");
    scanf("%d",&input);
    if(input == "y") return true;
    return false;
}

bool ev_soakStartTempReached()
{
    bool status = false;
    return stat;
}

bool ev_soakTimeOver()
{
    bool status = false;
    return stat;
}

bool ev_peakTempReached()
{
    bool status = false;
    return stat;
}

bool ev_dwellTimeOver()
{
    bool status = false;
    return stat;
}

bool ev_ovenCooledDown()
{
    bool status = false;
    return stat;
}

bool ev_abort()
{
    bool status = false;
    return stat;
}

// actions

void at_turnOnHeater()
{
    printf("ACTION: Turned heater on.\n");
}

void at_turnOffHeater()
{
    printf("ACTION: Turned heater off.\n");
}

void at_startRampToSoak()
{
    printf("ACTION: Ramping to soak.\n");
}

void at_soak()
{
    printf("ACTION: Soaking.\n");
}

void at_rampToPeak()
{
    printf("ACTION: Ramping to peak.\n");
}

void at_dwellAtPeak()
{
    printf("ACTION: Dwelling at peak temperature.\n");
}

void at_coolDown()
{
    printf("ACTION: Cooling oven down.\n");
}
*/
