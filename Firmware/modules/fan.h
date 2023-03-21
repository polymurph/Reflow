
#ifndef FAN_H
#define FAN_H

#include "usart.h"
#include "reflow_oven_bsl.h"

#ifdef __cplusplus
extern "C" {
#endif

uint8_t fan_init(reflowBSL_t *oven_bsl);

void fan_turnOn();

void fan_turnOff();

#ifdef __cplusplus
}
#endif

#endif /* FAN_H */
