#include "fan.h"

uint8_t fan_init(reflowBSL_t *oven_bsl)
{
	print_Usart(oven_bsl->uartChannel, "Fan Init -> Started\n\r"); 	
	print_Usart(oven_bsl->uartChannel, "Fan Init -> done\n\r"); 	
	return 1;
}
