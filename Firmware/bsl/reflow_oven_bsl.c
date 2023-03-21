#include "reflow_oven_bsl.h"
#include "modules.h"

void reflowOvenInitHw(reflowBSL_t *oven_bsl)
{
	delayInitMs(oven_bsl->clockSpeed, 1000); // Clock Freq and Divider for ARM library 
	
	// Reset pin
	pinConfig(oven_bsl->resetPin, input, def_stage, pullDown, def_speed);

	// init uart	
	usartInit(	oven_bsl->uartChannel, 
				oven_bsl->uartTx, 
				oven_bsl->uartRx, 
				oven_bsl->baudRate,
				eight, 
				NO_PARITY_CTRL,
				noFlowControl);

	setupInit(); // This is the sescond call of System init the assebly start code is calling it before the main.	
	
	print_Usart(oven_bsl->uartChannel, ASCII_clear); 

	// Init modules here
	display_init(oven_bsl);
	door_init(oven_bsl);
	fan_init(oven_bsl);
	heater_init(oven_bsl);
	temperature_init(oven_bsl);
	userIO_init(oven_bsl);
	
	print_Usart(oven_bsl->uartChannel, "Reflow oven init successful\n\r"); 	
}
