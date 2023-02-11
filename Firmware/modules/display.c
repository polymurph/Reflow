#include "display.h"

uint8_t display_init(reflowBSL_t *oven_bsl)
{
	print_Usart(oven_bsl->uartChannel, "Display Init -> Started\n\r"); 	
	print_Usart(oven_bsl->uartChannel, "Display Init -> done\n\r"); 	
	return 1;
}

