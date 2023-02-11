#include "reflow_oven_bsl.h"

void reflowOvenInitHw(reflowBSL_t *oven)
{
	delayInitMs(8000000, 1000); // Clock Freq and Divider for ARM library 
	
	pinConfig(pinB3, output, pushPull, def_res, def_speed);
	pinConfig(pinA0, input, def_stage, pullDown, def_speed);	
	
	usartInit(	usart2, 
				pinA2, 
				pinA15,
				115200,
				eight, 
				NO_PARITY_CTRL,
				noFlowControl); 
	
	setupInit(); // This is the sescond call of System init the assebly start code is calling it before the main.	
	
	print_Usart(usart2, "Reflow oven init sucsessfuluadasda\n\r"); 	
}
