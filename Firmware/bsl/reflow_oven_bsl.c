#include "reflow_oven_bsl.h"
#include "modules.h"

void reflowOvenInitHw(reflowBSL_t *oven)
{
	delayInitMs(oven->clockSpeed, 1000); // Clock Freq and Divider for ARM library 
	
	pinConfig(oven->statusLED, output, pushPull, def_res, def_speed);
	pinConfig(oven->resetPin, input, def_stage, pullDown, def_speed);	
	
	usartInit(	oven->uartChannel, 
				oven->uartTx, 
				oven->uartRx, 
				oven->baudRate,
				eight, 
				NO_PARITY_CTRL,
				noFlowControl); 
	
	setupInit(); // This is the sescond call of System init the assebly start code is calling it before the main.	
	
	print_Usart(oven->uartChannel, ASCII_clear); 
	
	display_init(oven);
	door_init(oven);
	fan_init(oven);
	heater_init(oven);
	temperature_init(oven);
	userIO_init(oven);
	
	print_Usart(oven->uartChannel, "Reflow oven init successful\n\r"); 	
}
