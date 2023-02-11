#include "door.h"

uint8_t door_init(reflowBSL_t *oven_bsl)
{
	print_Usart(oven_bsl->uartChannel, "Door Init -> Started\n\r"); 	
	print_Usart(oven_bsl->uartChannel, "Door Init -> done\n\r"); 	
	return 1;
}
