#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "usart.h"
#include "reflow_oven_bsl.h"

#ifdef __cplusplus
extern "C" {
#endif

uint8_t temperature_init(reflowBSL_t *oven_bsl);

float temperature_getTempCelsius();


#ifdef __cplusplus
}
#endif

#endif /* TEMPERATURE_H */

