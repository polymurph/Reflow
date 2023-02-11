#include "user_io.h"

uint8_t userIO_init(reflowBSL_t *oven_bsl)
{
	print_Usart(oven_bsl->uartChannel, "User IO Init -> Started\n\r"); 	
	print_Usart(oven_bsl->uartChannel, "User IO Init -> done\n\r"); 	
	return 1;
}

