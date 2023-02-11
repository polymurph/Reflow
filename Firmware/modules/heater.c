#include "heater.h"

uint8_t heater_init(reflowBSL_t *oven_bsl)
{
	print_Usart(oven_bsl->uartChannel, "Heater Init -> Started\n\r"); 	
	print_Usart(oven_bsl->uartChannel, "Heater Init -> done\n\r"); 	
	return 1;
}

