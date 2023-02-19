#include "temperature.h"

static reflowBSL_t *_bsl = 0;

uint8_t temperature_init(reflowBSL_t *oven_bsl)
{
	_bsl = oven_bsl;
	print_Usart(oven_bsl->uartChannel, "Temperature Init -> Started\n\r"); 	
	print_Usart(oven_bsl->uartChannel, "Temperature Init -> done\n\r"); 	
	return 1;
}

float temperature_getTempCelsius()
{
	return 0.0;	
}
