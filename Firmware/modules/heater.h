#ifndef HEATER_H
#define HEATER_H

#include "usart.h"
#include "reflow_oven_bsl.h"

#ifdef __cplusplus
extern "C" {
#endif

uint8_t heater_init(reflowBSL_t *oven_bsl);

void heater_enable();

void heater_dissable();

/**
 * @brief Set the heater power
 * 
 * @param power 0.0 ... 1.0 which correlates to 0 to 100% power output
 */
void heater_setPower(float power);

#ifdef __cplusplus
}
#endif

#endif /* HEATER_H */
