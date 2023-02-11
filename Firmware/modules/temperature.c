#include "temperature.h"

uint8_t temperature_init(reflowBSL_t *oven_bsl)
{
	print_Usart(oven_bsl->uartChannel, "Temperature Init -> Started\n\r"); 	
	print_Usart(oven_bsl->uartChannel, "Temperature Init -> done\n\r"); 	
	return 1;
}

