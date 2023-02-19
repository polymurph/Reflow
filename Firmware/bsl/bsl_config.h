#ifndef _BSL_CONFIG_H_
#define _BSL_CONFIG_H_

#include "reflow_oven_bsl.h"

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

#endif // _BSL_CONFIG_H_
