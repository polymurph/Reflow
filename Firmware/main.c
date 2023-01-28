#include "main.h"
#include "delay.h"
#include "deviceSetup.h"
#include "usart.h"
#include "ascii.h"

int main(int argc, char *argv[])
{
	uint8_t i = 0;
	
	delayInitMs(8000000, 1000); // Clock Freq and Divider for ARM library 
	
	pinConfig(pinB3, output, pushPull, def_res, def_speed);
	pinConfig(pinA0, input, def_stage, pullDown, def_speed);	
	
	setupInit(); // This is the sescond call of System init the assebly start code is calling it before the main.	
	
	usartInit(	usart2, 
				pinA2, 
				pinA15,
				115200,
				eight, 
				NO_PARITY_CTRL,
				noFlowControl); 

	//clears screen and send the wellcome messgae
	print_Usart(usart2, ASCII_clear); 
	print_Usart(usart2, "Hello to our KED project\n\r"); 
	

	//blinks 10 times to indicate the sicsessfull init if the device
	for(i = 0 ; i < 2 ; i++) {
		delayMs(100); 
		pinToggle(pinB3);
		delayMs(100); 
	}

	pinWrite(pinB3,0);

	print_Usart(usart2, "\n\r"); 
	
	print_Usart(usart2, "\n\r"); 
	print_Usart(usart2, "\n\r"); 
	print_Usart(usart2, "All is working fine\n\r"); 
	
	while(1)
	{
		delayMs(100); 
		pinToggle(pinB3);
		delayMs(100); 
	}
	
	return 1;
}

