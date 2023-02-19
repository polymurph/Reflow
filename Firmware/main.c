#include "main.h"
#include "reflow_oven_bsl.h"
#include "ovenCtrl.h"

int main(int argc, char *argv[])
{
	uint8_t i = 0;
	
	reflowBSL_t oven; 

	oven.clockSpeed=8000000; 
	oven.statusLED=pinB3; 
	oven.resetPin=pinA0;
	oven.uartTx=pinA2;
	oven.uartRx=pinA15;
	oven.uartChannel=usart2; 
	oven.baudRate=115200;

	// init reflow oven controller
	ovenCtrl_init(&oven);
	
	// run reflow oven  controller
	ovenCtrl_run();	

	while(1);
	
	/*
	//blinks 10 times to indicate the sicsessfull init if the device
	for(i = 0 ; i < 2 ; i++) {
		delayMs(100); 
		pinToggle(pinB3);
		delayMs(100); 
	}
	while(1)
	{
		delayMs(100); 
		pinToggle(pinB3);
		delayMs(100); 
	}
	*/
	return 1;
}

/*	
	
	setupInit(); // This is the sescond call of System init the assebly start code is calling it before the main.	
*/
	
	
	

