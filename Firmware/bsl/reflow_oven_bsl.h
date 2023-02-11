#ifndef REFLOW_OVEN_BSL_H
#define REFLOW_OVEN_BSL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "main.h"
#include "usart.h"
#include "ascii.h"
#include "pin.h"
#include "delay.h"
#include "deviceSetup.h"

typedef struct{
	uint32_t clockSpeed; 
	pinNo_t statusLED;
	pinNo_t resetPin;
	pinNo_t uartRx; 
	pinNo_t uartTx; 
	usartNo_t uartChannel;
	uint32_t baudRate; 
} reflowBSL_t;

void reflowOvenInitHw(reflowBSL_t *oven);

#ifdef __cplusplus
}
#endif

#endif /* REFLOW_OVEN_BSL_H */
