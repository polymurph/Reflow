#include "user_io.h"
#include "pin.h"
#include "delay.h"

static reflowBSL_t* _bsl = 0;

uint8_t userIO_init(reflowBSL_t *oven_bsl)
{
    _bsl = oven_bsl;
	print_Usart(oven_bsl->uartChannel, "User IO Init -> Started\n\r"); 	
	print_Usart(oven_bsl->uartChannel, "User IO Init -> done\n\r"); 	
	return 1;
}

void userIO_doInitStatusBlinki()
{
	uint8_t i = 0;

	for(i = 0; i < 4; i++) {
		delayMS(100);
		pinToggle(_bsl->statusLED);				
		delayMS(100);
	}
}
