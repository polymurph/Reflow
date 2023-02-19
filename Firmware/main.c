#include "main.h"
#include "reflow_oven_bsl.h"
#include "ovenCtrl.h"

int main(int argc, char *argv[])
{
	uint8_t i = 0;

	// creating ovenBSL object
	reflowBSL_t ovenBSL; 

	// init of ovenBSL object
	ovenBSL.clockSpeed=8000000; 
	ovenBSL.statusLED=pinB3; 
	ovenBSL.resetPin=pinA0;
	ovenBSL.uartTx=pinA2;
	ovenBSL.uartRx=pinA15;
	ovenBSL.uartChannel=usart2; 
	ovenBSL.baudRate=115200;

	// init reflow oven controller
	ovenCtrl_init(&ovenBSL);
	
	// run reflow oven  controller
	ovenCtrl_run();	

	while(1);

	return 1;
}

